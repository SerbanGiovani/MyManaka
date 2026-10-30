"""Read-only acceptance of F -> original Action clip -> original end -> movement.

The synthetic fixtures in test_verify_interaction.py are analyzer tests, never
runtime evidence. This module does not launch Unity, inject input, or complete
an action. Only an explicit --output writes a new analysis report.
"""
from __future__ import annotations

import argparse
from datetime import datetime
import gzip
import hashlib
import json
import math
from pathlib import Path
import struct


class Rejected(ValueError):
    pass


def require(condition, message):
    if not condition:
        raise Rejected(message)


def number(value):
    require(type(value) in (int, float) and math.isfinite(value), "Nonfinite/non-numeric evidence")
    return value


def vector(value, axes="xyz"):
    require(isinstance(value, dict) and set(value) == set(axes), "Vector schema differs")
    return tuple(number(value[key]) for key in axes)


def horizontal(a, b):
    a, b = vector(a), vector(b)
    return math.hypot(a[0] - b[0], a[2] - b[2])


def magnitude(value):
    return math.hypot(*vector(value, "xy"))


def instant(value):
    result = datetime.fromisoformat(value.replace("Z", "+00:00"))
    require(result.tzinfo is not None, "UTC timestamp lacks timezone")
    return result


def read(path, jsonl=False):
    path = Path(path)
    opener = gzip.open if path.suffix == ".gz" else open
    with opener(path, "rt", encoding="utf-8-sig") as stream:
        return [json.loads(line) for line in stream if line.strip()] if jsonl else json.load(stream)


def sha(path):
    with Path(path).open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def select(rows, kind):
    return [row for row in rows if row["kind"] == kind]


def one(rows, kind):
    matches = select(rows, kind)
    require(len(matches) == 1, "Missing/duplicate event: " + kind)
    return matches[0]


def close(a, b, epsilon=1e-5):
    return abs(number(a) - number(b)) <= epsilon


def same_float32(a, b):
    a, b = number(a), number(b)
    return (a == 0 and b == 0) or struct.pack("<f", a) == struct.pack("<f", b)


def check_writes(actual, expected):
    require(isinstance(actual, list) and len(actual) == len(expected), "Original action parameter write count differs")
    def normalized(value):
        return (value["name"], value["type"], value.get("valueSource") or None,
                value.get("intValue", 0), value.get("floatValue", 0), value.get("boolValue", False))
    require([normalized(value) for value in actual] == [normalized(value) for value in expected], "Original action parameter writes differ")


def validate_stream(rows):
    require(rows, "No runtime events")
    guid = rows[0].get("processGuid")
    require(isinstance(guid, str) and len(guid) >= 16, "Missing runtime process Guid")
    for row in rows:
        require(row.get("processGuid") == guid, "Event process identity differs")
        require(type(row.get("frame")) is int and row["frame"] >= 0, "Invalid event frame")
        require(number(row.get("real")) >= 0, "Invalid runtime clock")
        instant(row["utc"])
        require(isinstance(row.get("kind"), str) and isinstance(row.get("data"), dict), "Invalid event schema")
        require(row["kind"] not in {"loop_failure", "interaction_failure"}, "Runtime reported failure")
        if row["kind"] in {"player_action_changed", "action_end_deferred", "action_animation_event", "action_completed"}:
            origin = " ".join(str(row["data"].get(key, "")) for key in ("source", "reason", "completionSource", "via")).lower()
            require(not any(word in origin for word in ("timeout", "synthetic", "forced", "manual-complete")), "Forced/timeout completion is not an original animation end")
    for a, b in zip(rows, rows[1:]):
        require(a["frame"] <= b["frame"] and a["real"] <= b["real"] and instant(a["utc"]) <= instant(b["utc"]), "Event clock runs backwards")
    return guid


def check_controller(rows, expected):
    bound = one(rows, "animator_bound")["data"]
    identity = expected["acceptance_identity"]
    require(bound.get("playerSource") == identity["bundleSha256"] + ":" + identity["playerAsset"], "Original controller bundle/prefab identity differs")
    require(bound.get("animatorPath") == identity["animatorPath"].split("/", 1)[-1], "Original Animator hierarchy differs")
    for kind in ("controller", "avatar"):
        value = bound[kind]
        require(value["name"] == identity[kind + "Name"] and value.get("sameReference") is True, "Original " + kind + " reference differs")
        require(type(value.get("instanceId")) is int and value["instanceId"] != 0 and value["instanceId"] == value.get("sourceInstanceId"), "Original " + kind + " instance differs")
    require(bound["avatar"].get("valid") is True and bound["avatar"].get("human") is True, "Original humanoid avatar invalid")
    require(bound.get("gameBehavioursCopied") == 0, "Original game behaviours copied into reconstruction")
    require(bound.get("fireEvents") is True, "Original clip events are disabled")
    clips = {clip["name"]: clip for clip in bound["clips"]}
    original = expected["interaction"]["layer"]
    require(original["clipName"] in clips, "Action clip absent from original controller")
    clip = clips[original["clipName"]]
    require(type(clip.get("instanceId")) is int and clip["instanceId"] != 0, "Action clip instance identity absent")
    require(close(clip["length"], original["clipLength"], .002), "Original Action clip length differs")
    return bound, clip


def check_target(rows, spec):
    registered = one(rows, "interaction_target_registered")["data"]
    target = spec["target"]
    require(registered.get("originalSource") is True, "Synthetic target cannot establish original interaction")
    for field in ("sourceBundleSha256", "sourceScene", "sourcePath", "sourcePathId", "originalComponent"):
        absent_scene = field == "sourceScene" and target[field] is None and registered.get(field) in (None, "")
        require(field in registered and (absent_scene or str(registered[field]) == str(target[field])), "Original target identity differs: " + field)
    for field in ("targetId", "triggerId", "triggerInstanceId"):
        require(registered.get(field) not in (None, "", 0), "Missing runtime target/trigger identity: " + field)
    trigger = registered["trigger"]
    require(trigger.get("isTrigger") is True and trigger["shape"] == target["trigger"]["shape"], "Original trigger shape/flag differs")
    for field in ("center", "size", "radius", "height", "direction"):
        if field in target["trigger"]:
            actual, original = trigger.get(field), target["trigger"][field]
            if field in ("center", "size"):
                require(isinstance(actual, dict) and all(same_float32(a, b) for a, b in zip(vector(actual), vector(original))), "Original trigger geometry differs: " + field)
            elif field == "direction":
                require(actual == original, "Original trigger geometry differs: " + field)
            else:
                require(same_float32(actual, original), "Original trigger geometry differs: " + field)
    return registered


def local_bones(bones):
    require(isinstance(bones, list) and len(bones) >= 3, "Too few local skeletal observations")
    result = {}
    for bone in bones:
        path = bone["path"]
        require(isinstance(path, str) and "/" in path and path not in result, "Invalid local bone path")
        rotation = vector(bone["localRotation"], "xyzw")
        require(abs(math.sqrt(sum(value * value for value in rotation)) - 1) < .01, "Local bone rotation is not a unit quaternion")
        result[path] = vector(bone["localPosition"]) + rotation
    return result


def bones_changed(samples):
    maps = [local_bones(row["data"]["animator"]["bones"]) for row in samples]
    require(all(set(value) == set(maps[0]) for value in maps), "Local bone set changed")
    return any(math.dist(a[name], b[name]) > 1e-5 for a, b in zip(maps, maps[1:]) for name in a)


def layer_of(sample, index):
    matches = [layer for layer in sample["data"]["animator"]["layers"] if layer["layer"] == index]
    require(len(matches) == 1, "Missing/duplicate Animator layer")
    return matches[0]


def validate_samples(rows, spec, bound, controlled=False):
    samples = select(rows, "interaction_sample")
    require(len(samples) >= 6, "Insufficient per-frame interaction samples")
    require(len({row["frame"] for row in samples}) == len(samples), "Duplicate per-frame interaction sample")
    require(all(b["frame"] == a["frame"] + 1 for a, b in zip(samples, samples[1:])), "Missing consecutive runtime interaction sample")
    excluded = []
    movement = bound.get("movementConfiguration", {})
    fall = number(spec.get("worldFallPerSecond", movement.get("worldFallPerSecond", 10)))
    animation_fall = number(spec.get("animationFallPerSecond", movement.get("animationFallPerSecond", 5)))
    previous = None
    for row in samples:
        value = row["data"]
        if controlled:
            require(value.get("inputSource") == "simulated-axes" and value.get("simulated") is True and value.get("inputProvenance") == "internal_acceptance_axes", "Controlled diagnostic requires honestly labelled simulated axes")
        else:
            require(value.get("inputSource") == "unity-legacy" and value.get("simulated") is False, "Simulated input cannot establish actual Unity F reception")
        require(isinstance(value.get("inputProvenance"), str) and value["inputProvenance"], "Input provenance absent")
        for field in ("focused", "fDown", "fHeld", "fUp", "inputEnabled", "controllerMoveCalled"):
            require(type(value.get(field)) is bool, "Missing actual input/motor observation: " + field)
        keys_positive = False
        for field, f_field in (("keys", "fHeld"), ("keyDown", "fDown"), ("keyUp", "fUp")):
            if field in value:
                require(isinstance(value[field], dict) and all(type(item) is bool for item in value[field].values()), "Keyboard observation schema differs")
                keys_positive |= any(value[field].values())
                if not controlled:
                    require(value[field].get("f") == value[f_field], "Separate Unity F reads disagree")
        positive = value["fDown"] or value["fHeld"] or value["fUp"] or magnitude(value["axes"]) > 1e-6 or keys_positive
        require(controlled or value["focused"] or not positive, "Unfocused positive input cannot establish interaction")
        if not controlled and not value["focused"]:
            require(horizontal(value["positionBefore"], value["positionAfter"]) < 1e-5, "Unfocused residual movement")
            excluded.append(row["frame"])
        require(not value["fDown"] or value["fHeld"], "F GetKeyDown without held F")
        require(not (value["fDown"] and value["fUp"]), "F down/up combined in one runtime sample")
        if "unityAxes" in value and not controlled:
            require(vector(value["axes"], "xy") == vector(value["unityAxes"], "xy"), "Motor input axes differ from Unity axes")
        resolved = vector(value["resolvedAxes"], "xy")
        source = vector(value["axes"], "xy")
        length = math.hypot(*source)
        wanted = tuple(x / length for x in source) if length * length >= .5 else source
        require(math.dist(resolved, wanted) <= 1e-5, "Resolved input differs from original Resolve normalization")
        dt = number(value["dt"])
        require(0 <= dt <= .051, "Motor delta time invalid")
        speed = number(value["currentSpeed"])
        require(speed >= 0 and number(value["targetSpeed"]) >= 0, "Negative speed")
        distance = horizontal(value["positionBefore"], value["positionAfter"])
        require(distance <= speed * dt + .002, "Horizontal movement exceeds actual CC speed/dt")
        if speed <= 1e-6:
            require(distance < .0001, "Actor moved after original locked inertia reached zero")
        if distance > 1e-5:
            require(value["controllerMoveCalled"], "Movement occurred without CharacterController.Move")
        anim = value["animator"]
        require(anim.get("enabled") is True and anim.get("active") is True and anim.get("isInitialized") is True and close(anim.get("speed"), 1), "Animator not actively evaluating at original speed")
        require(anim.get("applyRootMotion") is False, "Root motion can bypass observed motor guard")
        local_bones(anim["bones"])
        action = value["playerAction"]
        require(type(action.get("id")) is int and type(action.get("canMove")) is bool, "Missing PlayerAction observations")
        if not action["canMove"]:
            require(close(value["targetSpeed"], 0) and close(value["targetAnimationSpeed"], 0), "Movement target bypassed CanMove before natural recovery")
            if previous and row["frame"] == previous["frame"] + 1:
                before = previous["data"]
                require(close(speed, max(0, before["currentSpeed"] - fall * dt), .002), "Locked motor speed did not follow original deceleration")
                require(close(value["animationSpeed"], max(0, before["animationSpeed"] - animation_fall * dt), .002), "Locked animation speed did not follow original deceleration")
        if previous and row["frame"] == previous["frame"] + 1:
            setup = controlled and any(item["kind"] == "controlled_fixture_setup" and previous["frame"] <= item["frame"] <= row["frame"] and item["data"].get("originalLevelPlacement") is False and horizontal(item["data"]["position"], value["positionBefore"]) < .002 for item in rows)
            require(setup or horizontal(previous["data"]["positionAfter"], value["positionBefore"]) < .002, "Actor moved outside observed CC steps")
            if previous["data"]["fHeld"] and value["fHeld"]:
                require(not value["fDown"], "Held F was reported as repeated GetKeyDown")
        previous = row
    return samples, excluded


def consecutive_windows(samples, predicate, minimum=3):
    windows, current = [], []
    for row in samples:
        if predicate(row):
            if current and row["frame"] != current[-1]["frame"] + 1:
                if len(current) >= minimum:
                    windows.append(current)
                current = []
            current.append(row)
        else:
            if len(current) >= minimum:
                windows.append(current)
            current = []
    if len(current) >= minimum:
        windows.append(current)
    return windows


def action_clip_matches(row, layer_spec, clip, controlled=False):
    layer = layer_of(row, layer_spec["index"])
    return ((controlled or row["data"]["focused"]) and layer["layerName"] == layer_spec["name"]
            and layer["fullPathHash"] == layer_spec["stateFullPathHash"]
            and number(layer["layerWeight"]) >= .9 and not layer.get("inTransition", False)
            and any(c["name"] == layer_spec["clipName"] and c.get("instanceId") == clip["instanceId"]
                    and number(c["weight"]) >= .9 for c in layer["clips"]))


def analyze_events(rows, expected, controlled=False, scoped=False):
    require(not (controlled and scoped), "Controlled diagnostics and scoped natural analysis must remain separate")
    unmet = []
    guid = validate_stream(rows)
    spec = expected["interaction"]
    require(type(spec["id"]) is int and type(spec["noneId"]) is int and spec["id"] != spec["noneId"], "Independent action/None ids incomplete")
    bound, clip = check_controller(rows, expected)
    target = check_target(rows, spec)
    if spec.get("guards", {}).get("reject_crouch"):
        require(target.get("rejectCrouch") is True, "Original crouch guard was omitted from target")
    placement = expected.get("fixturePlacement")
    if placement:
        require(target.get("fixturePlacement") == placement["placementProvenance"], "Authored fixture placement provenance differs")
        for field, observed, axes in (("worldPosition", "position", "xyz"), ("worldRotation", "rotation", "xyzw"), ("worldScale", "scale", "xyz")):
            require(all(same_float32(a, b) for a, b in zip(vector(target[observed], axes), vector(placement[field], axes))), "Authored fixture placement differs: " + field)
    samples, excluded = validate_samples(rows, spec, bound, controlled)
    by_frame = {row["frame"]: row for row in samples}
    attempts = select(rows, "interaction_attempt")
    require(attempts, "No actual F interaction attempt")
    down_frames = {row["frame"] for row in samples if row["data"]["fDown"]}
    require(len(attempts) == len({row["frame"] for row in attempts}) and {row["frame"] for row in attempts} == down_frames, "F GetKeyDown and interaction attempts differ")
    accepted = []
    for attempt in attempts:
        data = attempt["data"]
        sample = by_frame[attempt["frame"]]["data"]
        if controlled:
            require(data.get("GetKeyDown") is False and data.get("inputSource") == "simulated-keys" and data.get("simulated") is True and data.get("inputProvenance") == "internal_controlled_F", "Controlled diagnostic must not claim actual Unity F reception")
        else:
            require(data.get("GetKeyDown") is True and data.get("inputSource") == "unity-legacy" and data.get("simulated") is False and data.get("focused") is True, "Attempt lacks actual focused Unity GetKeyDown(F)")
        require(data.get("accepted") == sample["guard"]["accepted"] and data.get("reason") == sample["guard"]["reason"], "Attempt and per-frame guard disagree")
        if not data["accepted"]:
            require(data.get("reason") not in (None, "", "accepted"), "Rejected F lacks guard reason")
            require(not any(row["frame"] == attempt["frame"] and row["data"].get("actionId") == spec["id"] for row in select(rows, "player_action_changed")), "Rejected/repeated F restarted action")
            continue
        require(data.get("beforeActionId") == spec["noneId"] and data.get("canMoveBefore") is True, "Accepted F bypassed original idle/CanMove guard")
        require(sample["inputEnabled"] is True, "Accepted F while motor input disabled")
        if spec.get("guards", {}).get("reject_crouch"):
            require(data.get("crouch") is False, "Accepted F bypassed original crouch guard")
        require(data.get("targetId") == target["targetId"] and sample.get("selectedTargetId") == target["targetId"], "F selected fake/wrong target")
        candidates = [value for value in sample["candidates"] if value.get("targetId") == target["targetId"]]
        require(len(candidates) == 1 and candidates[0].get("overlapping") is True, "Accepted F lacks actual overlapping candidate")
        candidate = candidates[0]
        require(str(candidate.get("sourcePathId")) == str(spec["target"]["sourcePathId"]) and candidate.get("sourcePath") == spec["target"]["sourcePath"], "Candidate original target identity differs")
        triggers = [row for row in select(rows, "interaction_trigger") if row["frame"] <= attempt["frame"] and row["data"].get("targetId") == target["targetId"]]
        require(triggers and triggers[-1]["data"].get("phase") == "enter", "No actual trigger entry before F")
        entry = triggers[-1]["data"]
        require(entry.get("via") == "OnTriggerEnter" and entry.get("actualOverlap") is True, "Target proximity was manually substituted for trigger entry")
        require(entry.get("triggerId") == target["triggerId"] and entry.get("triggerInstanceId") == target["triggerInstanceId"], "Wrong runtime trigger entered")
        require(entry.get("otherColliderInstanceId") not in (None, 0) and entry.get("otherIsPlayerController") is True, "Trigger entry is not the player CharacterController")
        require(entry.get("enterSerial") == candidate.get("enterSerial") and type(entry.get("enterSerial")) is int, "Stale trigger candidate serial")
        accepted.append(attempt)
    require(accepted, "No accepted original F interaction")
    changes = select(rows, "player_action_changed")
    starts = [row for row in changes if row["data"].get("actionId") == spec["id"]]
    endings = [row for row in changes if row["data"].get("actionId") == spec["noneId"] and row["data"].get("previousId") == spec["id"]]
    require(len(starts) == len(endings) == len(accepted), "Accepted F/action start/natural None counts differ")
    sequences = [row["data"].get("sequence") for row in starts]
    require(all(type(sequence) is int and sequence > 0 for sequence in sequences) and len(set(sequences)) == len(sequences), "Action sequence missing/reused")
    cycles = []
    for attempt, start in zip(accepted, starts):
        sequence = start["data"]["sequence"]
        require(start["frame"] == attempt["frame"] and start["data"].get("previousId") == spec["noneId"] and start["data"].get("source") == "F-interaction", "PlayerAction not caused by accepted F")
        require(start["data"].get("canMove") is False, "Action start did not lock original CanMove")
        end_rows = [row for row in endings if row["data"].get("sequence") == sequence]
        require(len(end_rows) == 1, "Missing/duplicate natural None for sequence")
        end = end_rows[0]
        event_rows = [row for row in select(rows, "action_animation_event") if row["data"].get("sequence") == sequence and row["data"].get("accepted") is True]
        require(len(event_rows) == 1, "Missing/duplicate accepted original end AnimationEvent")
        event = event_rows[0]
        callback = event["data"]
        original_end = spec["end"]
        require(original_end["mechanism"] == "AnimationEvent", "Unsupported independent end mechanism")
        require(callback.get("function") == original_end["function"] and callback.get("intParameter") == original_end["intParameter"] and close(callback["eventTime"], original_end["time"], .002), "Wrong original end event")
        require(callback.get("via") == "Unity.AnimationEvent" and callback.get("originalClip") is True, "End was not dispatched by actual Unity AnimationEvent")
        require(callback.get("clipName") == spec["layer"]["clipName"] and callback.get("clipInstanceId") == clip["instanceId"], "End event came from wrong Action clip")
        require(callback.get("actionLayer") == spec["layer"]["index"] and callback.get("stateFullPathHash") == spec["layer"]["stateFullPathHash"], "End event came from wrong layer/state")
        require(start["frame"] < event["frame"] <= end["frame"], "Original action/end order differs")
        require(end["frame"] - event["frame"] == original_end["frameDelay"], "Natural None did not preserve original frame delay")
        end_source = "deferred-original-animation-event" if original_end["frameDelay"] else "original-animation-event"
        require(end["data"].get("source") == end_source and end["data"].get("eventFrame") == event["frame"] and end["data"].get("canMove") is True, "None restoration bypassed original end mechanism")
        require(end["frame"] in by_frame and by_frame[end["frame"]]["data"]["playerAction"]["id"] == spec["noneId"] and by_frame[end["frame"]]["data"]["playerAction"]["canMove"] is True, "Per-frame None did not preserve original completion frame")
        expected_time = original_end["time"] / spec["layer"]["clipLength"]
        require(abs(number(callback["normalizedTime"]) - expected_time) < .08, "Original end callback occurred at wrong clip time")
        require(event["real"] - start["real"] >= original_end["time"] - .1, "End callback occurred before original clip event time")
        if original_end["frameDelay"]:
            deferred = [row for row in select(rows, "action_end_deferred") if row["data"].get("sequence") == sequence]
            require(len(deferred) == 1 and deferred[0]["frame"] == event["frame"] and deferred[0]["data"].get("eventFrame") == event["frame"] and deferred[0]["data"].get("earliestNoneFrame") == end["frame"] and deferred[0]["data"].get("source") == "original-animation-event", "Original deferred end receipt differs")
        animation_start = [row for row in select(rows, "action_animation_started") if row["data"].get("sequence") == sequence]
        require(len(animation_start) == 1 and animation_start[0]["data"].get("originalController") is True and animation_start[0]["data"].get("sameReference") is True, "Action did not start on original controller reference")
        started = animation_start[0]
        require(started["frame"] >= start["frame"] and started["frame"] < event["frame"] and started["data"].get("id") == spec["id"] and started["data"].get("layer") == spec["layer"]["index"] and started["data"].get("stateFullPathHash") == spec["layer"]["stateFullPathHash"], "Action animation start identity/order differs")
        if spec.get("enterParameters"):
            check_writes(started["data"].get("parameters"), spec["enterParameters"])
        if spec.get("exitParameters"):
            requests = [row for row in select(rows, "action_animation_none_requested") if row["data"].get("sequence") == sequence]
            require(len(requests) == 1 and requests[0]["frame"] == end["frame"], "Missing original None animation parameter request")
            check_writes(requests[0]["data"].get("parameters"), spec["exitParameters"])
        observed = [row for row in samples if start["frame"] <= row["frame"] < end["frame"]]
        require(observed and all(row["data"]["inputEnabled"] is True and row["data"]["playerAction"]["id"] == spec["id"] and row["data"]["playerAction"]["canMove"] is False and row["data"]["playerAction"].get("sequence") == sequence for row in observed), "Action lock ended before original None")
        if spec.get("enterParameters"):
            require(all(row["data"]["animator"]["parameters"].get("ActionId") == spec["id"] and row["data"]["animator"]["parameters"].get("OldActionId") == spec["noneId"] for row in observed), "Observed original Animator action parameters differ during pickup")
        if spec.get("exitParameters"):
            restored_parameters = by_frame[end["frame"]]["data"]["animator"]["parameters"]
            require(restored_parameters.get("ActionId") == spec["noneId"] and restored_parameters.get("OldActionId") == spec["id"], "Observed original Animator None parameters differ")
        locked_input = [row for row in observed if (controlled or row["data"]["focused"]) and magnitude(row["data"]["axes"]) > .1]
        if len(locked_input) < 3 and scoped:
            unmet.append({"sequence": sequence, "gate": "movement-input-during-CanMove-lock", "required_samples": 3, "observed_samples": len(locked_input)})
        else:
            require(len(locked_input) >= 3, "Insufficient movement input while original CanMove blocked")
        playback = consecutive_windows(observed, lambda row: action_clip_matches(row, spec["layer"], clip, controlled))
        require(playback, "Missing stable original Action layer/state/clip playback")
        window = max(playback, key=len)
        times = [number(layer_of(row, spec["layer"]["index"])["normalizedTime"]) for row in window]
        require(all(a < b for a, b in zip(times, times[1:])), "Action normalized time did not advance")
        require(bones_changed(window), "Local skeleton did not animate during original action")
        next_start = min([row["frame"] for row in starts if row["frame"] > start["frame"]] or [10**18])
        after = [row for row in samples if end["frame"] <= row["frame"] < next_start]
        recovered = consecutive_windows(after, lambda row: (controlled or row["data"]["focused"]) and row["data"]["playerAction"]["id"] == spec["noneId"] and row["data"]["playerAction"]["canMove"] is True and magnitude(row["data"]["axes"]) > .1 and row["data"]["targetSpeed"] > .1 and row["data"]["controllerMoveCalled"] is True and horizontal(row["data"]["positionBefore"], row["data"]["positionAfter"]) > 1e-5)
        require(recovered, "No consecutive input -> CC movement after natural None")
        recovery = recovered[0]
        locomotion = spec.get("locomotion")
        if locomotion:
            require(any(layer_of(row, locomotion["layerIndex"])["fullPathHash"] == locomotion["stateFullPathHash"] and any(c["name"] in locomotion["movingClips"] and c["weight"] > .5 for c in layer_of(row, locomotion["layerIndex"])["clips"]) for row in recovery), "Recovered CC motion lacks original locomotion clip")
        require(any(row["data"]["fUp"] and row["frame"] > attempt["frame"] for row in samples), "F release was not observed")
        effects = {}
        if spec.get("effects"):
            effect_spec = spec["effects"]
            collected = [row for row in select(rows, "interaction_target_collected") if row["data"].get("sequence") == sequence]
            require(len(collected) == 1, "Original pickup did not collect exactly one target")
            collection = collected[0]
            require(collection["frame"] == event["frame"] and collection["data"].get("source") == "original-animation-event" and collection["data"].get("targetId") == target["targetId"] and collection["data"].get("itemId") == effect_spec["collectItemId"] and collection["data"].get("countDelta") == effect_spec["countDelta"] and collection["data"].get("active") is (not effect_spec["targetInactive"]), "Pickup target side effect differs from original callback")
            inventory = [row for row in select(rows, "interaction_inventory_changed") if row["frame"] == event["frame"]]
            require(len(inventory) == 1, "Missing/duplicate inventory change at original pickup event")
            item = inventory[0]["data"]
            require(item.get("source") == "original-animation-event" and item.get("itemId") == effect_spec["collectItemId"] and item.get("delta") == effect_spec["countDelta"] and type(item.get("before")) is int and type(item.get("after")) is int and item["before"] >= 0 and item["after"] == item["before"] + item["delta"], "Original pickup inventory delta differs")
            require(rows.index(event) < rows.index(collection) < rows.index(inventory[0]) < rows.index(end), "Original pickup/end callback order differs")
            effects = {"item_id": item["itemId"], "before": item["before"], "after": item["after"], "delta": item["delta"], "target_inactive": not collection["data"]["active"]}
        cycles.append({"sequence": sequence, "action_id": spec["id"], "none_id": spec["noneId"], "target_id": target["targetId"], "f_frame": attempt["frame"], "action_frame": start["frame"], "end_event_frame": event["frame"], "none_frame": end["frame"], "original_frame_delay": original_end["frameDelay"], "stable_action_frames": [window[0]["frame"], window[-1]["frame"]], "blocked_input_samples": len(locked_input), "movement_restored_frames": [recovery[0]["frame"], recovery[-1]["frame"]], "restored_horizontal_distance": sum(horizontal(row["data"]["positionBefore"], row["data"]["positionAfter"]) for row in recovery), "pickup_effects": effects})
    scope = "Controlled simulated F/axes diagnostic verifies the original target/action/end/CC subchain only; actual Unity GetKeyDown(F), focused keyboard operation and physical input are not accepted." if controlled else "Selected finite non-sexual interaction only. Original game scripts, complete original gameplay, all native systems, visual/shader parity and physical keyboard device identity are not established."
    if unmet:
        scope = "Scoped natural chain: actual Unity F, original target/Action/end, same-frame None and later actual-input CC recovery are verified. This process did not exercise movement input during the action lock; its single-process full-chain gate remains failed."
    return {"passed": not unmet, "full_chain_accepted": not controlled and not unmet, "scoped_natural_chain_accepted": scoped, "unmet_single_process_requirements": unmet, "actual_unity_f_accepted": not controlled, "controlled_subchain_only": controlled, "controlled_setup_excluded_frames": [row["frame"] for row in rows if controlled and row["kind"] == "controlled_fixture_setup"], "process_guid": guid, "sample_count": len(samples), "accepted_f_attempts": len(accepted), "rejected_f_attempts": len(attempts) - len(accepted), "unfocused_idle_excluded_frames": excluded, "cycles": cycles, "original_guard_scope": spec.get("guards"), "physical_keyboard_measured": False, "identity_basis": "Independent original source bundle/prefab/target PPtr inventory plus runtime same-reference controller/avatar and matching original controller clip instance. Runtime does not expose serialized PPtr IDs.", "scope": scope}


def origin_scope(receipt, pid, rows):
    result = {"classification": "undeclared", "unity_key_observed": True, "physical_keyboard_measured": False, "human_physical_attestation": False}
    if not receipt:
        return result
    require(receipt.get("target_pid") == pid, "Input receipt belongs to another process")
    source = receipt.get("source")
    require(source in {"physical-user", "os-sendinput", "cua-sendinput", "controlled-unity-input", "undeclared"}, "Unknown external input receipt source")
    require(receipt.get("all_keys_released") is True, "External input receipt leaves held keys")
    if source == "physical-user":
        require(receipt.get("user_attestation") is True and receipt.get("user_reply"), "Physical-keyboard claim lacks explicit user attestation")
        result.update(classification="user-physical-attestation-and-unity-reception", human_physical_attestation=True, attestation=receipt["user_reply"])
    elif source in {"os-sendinput", "cua-sendinput"}:
        commands = receipt.get("commands", [])
        require(commands and all(command.get("successful") is True and command.get("sent") == command.get("requested") and command.get("requested", 0) > 0 for command in commands), "OS input receipt lacks successful API counts")
        require(isinstance(receipt.get("backend"), str) and receipt["backend"], "OS input backend absent")
        for command in commands:
            require(instant(command["down_utc"]) <= instant(command["up_utc"]), "Invalid external key interval")
        f_commands = [command for command in commands if str(command.get("key", "")).upper() == "F" or "F" in [str(key).upper() for key in command.get("keys", [])]]
        f_edges = [row for row in rows if row["kind"] == "interaction_sample" and row["data"].get("fDown")]
        require(f_commands and f_edges and all(any(instant(command["down_utc"]).timestamp() - .05 <= instant(edge["utc"]).timestamp() <= instant(command["up_utc"]).timestamp() + .1 for command in f_commands) for edge in f_edges), "OS F injection intervals do not cover actual Unity F edges")
        result.update(classification="os-injected-keyboard-observed-by-unity", backend=receipt.get("backend"))
    elif source == "controlled-unity-input":
        require(receipt.get("controlled") is True, "Controlled input receipt missing classification")
        result.update(classification="automated-controlled-unity-reception")
    return result


def composite_scope(natural, control):
    require(natural.get("scoped_natural_chain_accepted") is True and natural.get("actual_unity_f_accepted") is True and natural.get("controlled_subchain_only") is False, "Composite natural side lacks actual scoped Unity F/end/CC chain")
    require(control.get("passed") is True and control.get("controlled_subchain_only") is True and control.get("full_chain_accepted") is False and control.get("actual_unity_f_accepted") is False, "Composite control side lacks honestly scoped original callback/lock/recovery diagnostic")
    require(natural["lifecycle"]["assembly_sha256"] == control["lifecycle"]["assembly_sha256"], "Composite processes use different managed implementations")
    require(natural["artifacts"]["identity"]["sha256"] == control["artifacts"]["identity"]["sha256"], "Composite processes use different original identity contracts")
    require(natural["process_guid"] != control["process_guid"], "Composite origins must remain separate runtime processes")
    require(all(value["gate"] == "movement-input-during-CanMove-lock" for value in natural["unmet_single_process_requirements"]), "Composite cannot excuse another failed natural gate")
    return {"accepted": True, "single_process_full_chain_accepted": natural["full_chain_accepted"], "natural_pid": natural["lifecycle"]["pid"], "natural_guid": natural["process_guid"], "natural_input_origin": natural["input_origin"], "controlled_pid": control["lifecycle"]["pid"], "controlled_guid": control["process_guid"], "controlled_input_origin": control["input_origin"], "controlled_cycles": control["cycles"], "controlled_config": control["artifacts"]["config"], "claim": "The natural process proves actual Unity F -> original target/Action/AnimationEvent -> immediate None -> later actual-input CC movement. The separate controlled process proves movement input is blocked during CanMove=false and resumes after its original event. The natural process did not exercise input during its lock; these observations do not form a single-process full-chain pass."}


def pose_bits(value):
    result = {}
    for field, axes in (("position", "xyz"), ("rotation", "xyzw")):
        for axis, scalar in zip(axes, vector(value[field], axes)):
            result[field + "." + axis] = struct.unpack("<i", struct.pack("<f", scalar))[0]
    return result


def check_saves(rows, result, saved, saved_sha, backup=None, backup_sha=None):
    commands = select(rows, "keyboard_command")
    require({row["data"].get("key") for row in commands} >= {"F5", "F6"}, "Natural save chain lacks actual F5/F6")
    samples = {row["frame"]: row["data"] for row in select(rows, "interaction_sample")}
    completed = select(rows, "save_completed")
    observed = []
    for command in commands:
        data = command["data"]
        require(data.get("GetKeyDown") is True and data.get("inputSource") == "unity-legacy" and data.get("simulated") is False and data.get("focused") is True, "Save command lacks actual focused Unity key")
        require(command["frame"] in samples and samples[command["frame"]]["keyDown"].get(data["key"].lower()) is True, "Save key command and Unity edge differ")
        require(samples[command["frame"]]["playerAction"]["id"] == -1 and command["frame"] > result["cycles"][-1]["movement_restored_frames"][0], "Save occurred before natural action/movement recovery")
        events = {}
        for kind in ("save_pose_canonicalized", "save_roundtrip_verified", "save_completed"):
            matches = [row for row in select(rows, kind) if row["frame"] == command["frame"]]
            require(len(matches) == 1, "Missing/duplicate save event for keyboard command")
            events[kind] = matches[0]["data"]
        canonical = events["save_pose_canonicalized"]
        roundtrip = events["save_roundtrip_verified"]
        done = events["save_completed"]
        source, disk = canonical["sourcePoseBits"], canonical["canonicalPoseBits"]
        require(set(source) == set(disk) == set(pose_bits(data)) | {"bodyPaintRemaining"}, "Save bit component schema differs")
        normalizations = [key for key in source if source[key] != disk[key]]
        require(all(source[key] == -(2**31) and disk[key] == 0 for key in normalizations) and canonical["zeroSignNormalizations"] == len(normalizations), "Save changed a nonzero float or concealed zero normalization")
        require(canonical.get("actorTransformModified") is False and all(source[key] == value for key, value in pose_bits(data).items()), "Save does not reflect actual keyboard command pose")
        require(roundtrip["sourcePoseBits"] == source and roundtrip["canonicalPoseBits"] == disk and roundtrip["diskPoseBits"] == disk and roundtrip.get("exactCanonicalFloatBits") is True and roundtrip.get("sameSceneAndWriter") is True and not roundtrip.get("mismatches"), "Save runtime roundtrip differs")
        require(done["sourcePoseBits"] == source and done["canonicalPoseBits"] == disk and done["diskPoseBits"] == disk and all(disk[key] == value for key, value in pose_bits(done).items()) and done["processGuid"] == result["process_guid"], "Completed save pose/writer differs")
        observed.append({"key": data["key"], "frame": command["frame"], "revision": done["revision"], "sha256": done["saveSha256"], "normalized_zero_components": normalizations})
    require(all(a["revision"] < b["revision"] for a, b in zip(observed, observed[1:])), "Save revisions did not increase")
    last = completed[-1]["data"]
    require(saved_sha == last["saveSha256"] and saved["revision"] == last["revision"] and saved["savedProcessGuid"] == result["process_guid"], "Independent saved bytes/revision/writer differ")
    require(saved.get("schemaVersion") == 1 and saved.get("fileKind") == "ReconstructedManakaSave" and saved["sceneKey"] == last["sceneKey"] and all(last["diskPoseBits"][key] == value for key, value in pose_bits(saved).items()), "Independent disk pose/schema differs")
    effect = result["cycles"][-1]["pickup_effects"]
    items = [value for value in saved["inventory"] if value["id"] == effect["item_id"]]
    require(len(items) == 1 and items[0]["count"] == effect["after"], "Persisted pickup inventory quantity differs")
    retained = []
    if backup is not None:
        matches = [row for row in completed if row["data"]["revision"] == backup["revision"] and row["data"]["saveSha256"] == backup_sha]
        require(len(matches) == 1 and backup["savedProcessGuid"] == result["process_guid"], "Retained backup does not match an observed save")
        retained = [backup["revision"]]
    return {"keyboard_saves": observed, "saved_revision": saved["revision"], "saved_sha256": saved_sha, "persisted_item_id": effect["item_id"], "persisted_item_quantity": items[0]["count"], "independently_retained_backup_revisions": retained}


def check_cold(rows, proof, start, exit_receipt, natural, saved, saved_sha, verify_inputs=False):
    guid = validate_stream(rows)
    require(guid != natural["process_guid"] and proof["processGuid"] == guid and proof["processId"] == start["pid"] == exit_receipt["pid"], "Cold process identity differs or reuses natural Guid")
    require(proof.get("completed") is True and proof.get("passed") is True and exit_receipt.get("process_exited") is True and exit_receipt.get("exit_code") == 0, "Cold process did not complete cleanly")
    require(instant(start["started_utc"]) <= instant(rows[0]["utc"]) <= instant(rows[-1]["utc"]) <= instant(exit_receipt["exited_utc"]), "Cold events outside OS lifecycle")
    require(start["assembly_sha256"] == natural["lifecycle"]["assembly_sha256"], "Cold process uses different managed implementation")
    if verify_inputs:
        require(sha(start["assembly_path"]) == start["assembly_sha256"] and sha(start["executable"]) == start["executable_sha256"], "Cold actual launched binaries differ")
    loaded = one(rows, "saved_state_read")["data"]
    applied = one(rows, "pose_applied_before_physics")["data"]
    verified = one(rows, "readback_verified_before_physics")["data"]
    require(loaded["revision"] == saved["revision"] and loaded["savedProcessGuid"] == natural["process_guid"] and loaded["sourceSaveSha256"] == saved["sourceSaveSha256"], "Cold read revision/writer/source differ")
    require(proof["saveSha256"] == verified["saveSha256"] == saved_sha and verified.get("previousProcess") is True and verified["writerProcessGuid"] == natural["process_guid"] and verified["readerProcessGuid"] == guid, "Cold process did not verify same saved bytes")
    wanted = pose_bits(saved)
    require(pose_bits(loaded) == pose_bits(applied) == pose_bits(verified) == wanted and loaded["sceneKey"] == applied["sceneKey"] == verified["sceneKey"] == saved["sceneKey"], "Cold pose was not component-exact before physics")
    require(verified.get("exactAppliedPosition") is True and verified.get("exactAppliedRotation") is True and not select(rows, "player_action_changed"), "Cold readback altered action or failed exact pose")
    require(not any(row["kind"] == "engine_error" for row in rows) and proof.get("unexpectedEngineErrors") == 0, "Cold process has unexpected engine errors")
    return {"pid": start["pid"], "process_guid": guid, "save_revision": saved["revision"], "save_sha256": saved_sha, "same_saved_bytes_verified": True, "component_exact_pose_before_physics": True, "persisted_item_quantity_in_independent_json": natural["save_verification"]["persisted_item_quantity"], "cold_in_memory_inventory_quantity_observed": False, "inventory_scope": "Independent saved JSON contains item10000 quantity2 and the cold trace verifies reading those exact bytes. The cold runtime emitted no second in-memory inventory count; no such observation is claimed."}


def build(config_path, verify_inputs=False, controlled=False, scoped=False):
    config_path = Path(config_path).resolve()
    config = read(config_path)
    base = config_path.parent
    artifacts = {"config": {"path": str(config_path), "sha256": sha(config_path)}}
    def path(key):
        value = (base / config[key]).resolve()
        artifacts[key] = {"path": str(value), "sha256": sha(value)}
        return value
    rows = read(path("events"), jsonl=True)
    identity_path = path("identity")
    expected = read(identity_path)
    identity_sources = []
    for source in expected.get("sources", []):
        source_path = (identity_path.parent / source["path"]).resolve()
        require(sha(source_path) == source["sha256"], "Independent identity source hash differs: " + str(source_path))
        identity_sources.append({"path": str(source_path), "sha256": source["sha256"]})
    start, end, proof = (read(path(key)) for key in ("start", "exit", "proof"))
    result = analyze_events(rows, expected, controlled, scoped)
    require(start["pid"] == end["pid"] == proof["processId"], "External lifecycle/runtime PID differs")
    require(proof["processGuid"] == result["process_guid"] and proof.get("completed") is True and proof.get("passed") is True, "Runtime proof incomplete or from another process")
    require(end.get("process_exited") is True and end.get("exit_code") == 0, "Runtime process did not exit cleanly")
    require(instant(start["started_utc"]) <= instant(rows[0]["utc"]) <= instant(rows[-1]["utc"]) <= instant(end["exited_utc"]), "Event UTC outside OS process lifetime")
    require(len(start.get("assembly_sha256", "")) == 64 and len(start.get("executable_sha256", "")) == 64, "Missing executable/managed assembly identity")
    if verify_inputs:
        require(sha(start["assembly_path"]) == start["assembly_sha256"], "Managed runtime assembly differs from actual launched receipt")
        require(sha(start["executable"]) == start["executable_sha256"], "Runtime executable differs from launched receipt")
    source_hashes = []
    for source in config.get("runtime_sources", []):
        source_path = (base / source["path"]).resolve()
        actual = sha(source_path)
        require(actual == source["sha256"], "Runtime source hash differs: " + str(source_path))
        source_hashes.append({"path": str(source_path), "sha256": actual})
    errors = [row for row in rows if row["kind"] == "engine_error"]
    known = [row for row in errors if row["data"].get("classification") == "known-original-shader-constant-buffer" and row["data"].get("message", "").strip() == "Struct '_MainTex' is not in any constant buffer."]
    require(len(errors) == len(known) and proof.get("unexpectedEngineErrors", 0) == 0, "Unexpected engine errors")
    warnings = [row for row in rows if row["kind"] == "engine_message" and row["data"].get("type") == "Warning"]
    missing = [row for row in warnings if "referenced script" in row["data"].get("message", "").lower() and "missing" in row["data"].get("message", "").lower()]
    for key, count in (("engineErrorCount", len(errors)), ("engineWarningCount", len(warnings)), ("missingScriptWarnings", len(missing))):
        if key in proof:
            require(proof[key] == count, "Runtime proof diagnostic counts differ: " + key)
    require(proof.get("originalShaderCompatibilityVerified", False) is False, "Interaction evidence cannot establish original shader parity")
    if errors or missing or proof.get("playerShaderFallbacks", 0):
        require(proof.get("degradedAssetCompatibility") is True, "Known original asset degradation was concealed")
    degradation = {"engine_warnings": len(warnings), "missing_script_warnings": len(missing), "known_shader_errors": len(known), "player_shader_fallbacks": proof.get("playerShaderFallbacks"), "original_shader_compatibility_verified": False, "full_visual_parity_verified": False}
    receipt = read(path("input_receipt")) if config.get("input_receipt") else None
    origin = {"classification": "automated-simulated-controlled-diagnostic", "unity_key_observed": False, "physical_keyboard_measured": False, "human_physical_attestation": False} if controlled else origin_scope(receipt, start["pid"], rows)
    result.update(schema_version=1, evidence_kind="controlled-subchain-diagnostic" if controlled else "new-runtime-analysis", input_origin=origin, lifecycle={"pid": start["pid"], "exit_code": end["exit_code"], "assembly_sha256": start["assembly_sha256"], "executable_sha256": start["executable_sha256"], "actual_launched_binaries_rehashed": verify_inputs}, known_shader_error_count=len(known), asset_degradation=degradation, native_system_limitations=expected.get("native_system_limitations", expected.get("limitations", [])), fixture_placement=expected.get("fixturePlacement"), artifacts=artifacts, identity_sources=identity_sources, runtime_sources=source_hashes)
    if config.get("save"):
        save_path = path("save")
        saved = read(save_path)
        backup_path = path("save_backup") if config.get("save_backup") else None
        result["save_verification"] = check_saves(rows, result, saved, sha(save_path), read(backup_path) if backup_path else None, sha(backup_path) if backup_path else None)
        if config.get("cold_events"):
            cold_rows = read(path("cold_events"), jsonl=True)
            cold_proof = read(path("cold_proof"))
            cold_start, cold_exit = read(path("cold_start")), read(path("cold_exit"))
            result["cold_readback"] = check_cold(cold_rows, cold_proof, cold_start, cold_exit, result, saved, sha(save_path), verify_inputs)
    if scoped:
        require(not controlled and config.get("controlled_config"), "Scoped composite requires a separate controlled config")
        control = build(path("controlled_config"), verify_inputs, controlled=True)
        result["evidence_kind"] = "scoped-composite-runtime-analysis"
        result["scoped_composite_acceptance"] = composite_scope(result, control)
    return result


def strict_rejection(config_path, verify_inputs=False):
    try:
        build(config_path, verify_inputs)
    except Rejected as error:
        require(str(error) == "Insufficient movement input while original CanMove blocked", "Strict run failed for a different reason: " + str(error))
        scoped = build(config_path, verify_inputs, scoped=True)
        return {"schema_version": 1, "evidence_kind": "strict-natural-rejection", "passed": False, "accepted": False, "full_chain_accepted": False, "reason": str(error), "unmet_single_process_requirements": scoped["unmet_single_process_requirements"], "lifecycle": scoped["lifecycle"], "process_guid": scoped["process_guid"], "input_origin": scoped["input_origin"], "cycles": scoped["cycles"], "artifacts": scoped["artifacts"], "scope": "The unchanged strict single-process gate was executed and rejected this natural process. Separate composite evidence does not turn this result into a strict pass."}
    raise Rejected("Expected strict lock-input rejection did not occur")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--config", required=True)
    parser.add_argument("--output", required=True)
    parser.add_argument("--inputs", action="store_true", help="Also rehash launched executable/managed assembly")
    parser.add_argument("--check", action="store_true", help="Read-only compare against existing report")
    parser.add_argument("--controlled", action="store_true", help="Diagnostic only: preserve simulated input labels; never accept the complete Unity keyboard chain")
    parser.add_argument("--scoped-composite", action="store_true", help="Preserve a failed natural lock-input gate and verify its separate controlled-process evidence")
    parser.add_argument("--strict-rejection", action="store_true", help="Record the expected strict natural lock-input failure without changing that gate")
    args = parser.parse_args()
    try:
        require(sum((args.controlled, args.scoped_composite, args.strict_rejection)) <= 1, "Analysis scopes are mutually exclusive")
        result = strict_rejection(args.config, args.inputs) if args.strict_rejection else build(args.config, args.inputs, args.controlled, args.scoped_composite)
        if args.check:
            require(read(args.output) == result, "Report differs from reproducible current analysis")
        else:
            Path(args.output).write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    except (Rejected, KeyError, TypeError, OSError, ValueError, OverflowError) as error:
        print("REJECTED:", error)
        return 1
    print("EXPECTED STRICT REJECTION: natural lock-input gate remains failed" if args.strict_rejection else "SCOPED COMPOSITE ACCEPTED: separate natural/controlled processes; single-process full-chain gate is preserved" if args.scoped_composite else "PASS: controlled original action/end/CC subchain only; actual Unity F is NOT accepted" if args.controlled else "PASS: original F/target/Action/end/CC evidence; physical device identity is not measured")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
