"""Read-only independent analysis of keyboard -> CC -> original Animator evidence.

Synthetic tests exercise rejection paths. This module never produces input or
launches the player, and never imports the historical verifier (which has
stage-specific assumptions). Only an explicit --output can write a report.
"""
from __future__ import annotations

import argparse
import gzip
import hashlib
import json
import math
import struct
from datetime import datetime
from pathlib import Path

FLOAT_POLICY = "Normalize only IEEE-754 negative zero to positive zero before JSON serialization; every nonzero float bit and every canonical zero bit must survive exactly. Raw negative-zero sign bits are not preserved."
FLOAT_COMPONENTS = {"position.x", "position.y", "position.z", "rotation.x", "rotation.y", "rotation.z", "rotation.w", "bodyPaintRemaining"}


class Rejected(ValueError):
    pass


def require(condition, message):
    if not condition:
        raise Rejected(message)


def read(path):
    path = Path(path)
    opener = gzip.open if path.suffix == ".gz" else open
    with opener(path, "rt", encoding="utf-8-sig") as stream:
        return json.load(stream)


def events(path):
    path = Path(path)
    opener = gzip.open if path.suffix == ".gz" else open
    with opener(path, "rt", encoding="utf-8-sig") as stream:
        return [json.loads(line) for line in stream if line.strip()]


def sha(path):
    with Path(path).open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def number(value):
    require(type(value) in (int, float) and math.isfinite(value), "Nonfinite/non-numeric evidence value")
    return value


def bits(value):
    return struct.pack("<f", number(value))


def bit_int(value):
    return struct.unpack("<i", bits(value))[0]


def validate_bit_map(value):
    require(isinstance(value, dict) and set(value) == FLOAT_COMPONENTS, "Saved float bit component schema differs")
    for component in value.values():
        require(type(component) is int and -(2**31) <= component < 2**31, "Saved float bits must be signed int32")
        require(math.isfinite(struct.unpack("<f", struct.pack("<i", component))[0]), "Saved float bits encode a nonfinite value")
    return value


def numeric_pose_matches(bit_map, position, rotation, raw_zero_sign_unobservable=False):
    vector(position)
    vector(rotation, "xyzw")
    for group, value in (("position", position), ("rotation", rotation)):
        for axis, scalar in value.items():
            actual, observed = bit_map[group + "." + axis], bit_int(scalar)
            if raw_zero_sign_unobservable and scalar == 0 and actual in (0, -(2**31)):
                continue
            if actual != observed:
                return False
    return True


def vector(value, names="xyz"):
    require(isinstance(value, dict) and set(value) == set(names), "Vector component schema differs")
    return tuple(number(value[key]) for key in names)


def exact(a, b, names="xyz"):
    vector(a, names)
    vector(b, names)
    return all(bits(a[key]) == bits(b[key]) for key in names)


def horizontal(a, b):
    vector(a)
    vector(b)
    return math.hypot(a["x"] - b["x"], a["z"] - b["z"])


def rotation_error(a, b):
    a, b = vector(a, "xyzw"), vector(b, "xyzw")
    na, nb = math.sqrt(sum(x*x for x in a)), math.sqrt(sum(x*x for x in b))
    require(abs(na - 1) < .01 and abs(nb - 1) < .01, "Quaternion is not near unit length")
    dot = abs(sum(x*y for x, y in zip(a, b))) / (na * nb)
    return math.degrees(2 * math.acos(min(1, max(0, dot))))


def one(rows, kind):
    selected = [row for row in rows if row["kind"] == kind]
    require(len(selected) == 1, "Missing/duplicate event: " + kind)
    return selected[0]


def instant(value):
    return datetime.fromisoformat(value.replace("Z", "+00:00"))


def event_stream(rows, proof):
    require(rows and all(row["processGuid"] == proof["processGuid"] for row in rows), "Event process identity differs")
    require(all(type(row["frame"]) is int and number(row["real"]) >= 0 for row in rows), "Invalid event clock")
    require(all(a["frame"] <= b["frame"] and a["real"] <= b["real"] for a, b in zip(rows, rows[1:])), "Event clock runs backwards")
    require(not any(row["kind"] == "loop_failure" for row in rows), "Player reported loop failure")
    require(proof["completed"] is True and proof["passed"] is True, "Player acceptance incomplete/failed")
    require(one(rows, "acceptance_complete")["data"]["passed"] is True, "Acceptance did not succeed")
    require(one(rows, "process_quit")["data"]["passed"] is True, "Player quit did not succeed")
    errors = [row for row in rows if row["kind"] == "engine_error"]
    unexpected = [row for row in errors if row["data"].get("classification") != "known-original-shader-constant-buffer" or row["data"].get("message", "").strip() != "Struct '_MainTex' is not in any constant buffer."]
    require(not unexpected and proof["unexpectedEngineErrors"] == 0, "Unexpected engine errors")
    require(proof["engineErrorCount"] == len(errors), "Engine error count differs from event stream")
    warnings = [row for row in rows if row["kind"] == "engine_message" and row["data"].get("type") == "Warning"]
    missing = [row for row in warnings if "referenced script" in row["data"].get("message", "").lower() and "missing" in row["data"].get("message", "").lower()]
    require(proof["engineWarningCount"] == len(warnings) and proof["missingScriptWarnings"] == len(missing), "Engine warning counts differ from event stream")
    degraded = bool(errors or missing or proof["playerShaderFallbacks"] or proof["unresolvedBuiltinMeshes"] or proof["geometryTextures"] < proof["declaredTextures"])
    require(not degraded or proof["degradedAssetCompatibility"] is True, "Original asset degradation was concealed")
    require(proof["originalShaderCompatibilityVerified"] is False, "This stage does not establish original shader parity")


def proof_counts(proof, rows, analyzed):
    observed = [row for row in rows if row["kind"] == "locomotion_sample"]
    commands = [row for row in rows if row["kind"] == "keyboard_command"]
    for name, count in {
        "locomotionFrames": len(observed), "unityKeyboardFrames": len(observed), "simulatedAxisFrames": 0,
        "movingKeyboardFrames": sum(bool(row["data"]["axes"]["x"] or row["data"]["axes"]["y"]) for row in observed),
        "keyboardSaveCommands": sum(row["data"]["key"].upper() == "F5" for row in commands),
        "keyboardSaveQuitCommands": sum(row["data"]["key"].upper() == "F6" for row in commands),
        "animatorStateChanges": sum(row["kind"] == "animator_state_changed" for row in rows),
    }.items():
        require(proof[name] == count, "Runtime proof counter differs from events: " + name)
    require(abs(number(proof["keyboardTravelledDistance"]) - analyzed["horizontal_travel"]) < max(.001, analyzed["horizontal_travel"] * .0001), "Proof keyboard travel differs from CC samples")
    require(proof["physicalKeyboardVerified"] is False, "Runtime cannot measure physical keyboard origin")
    require(proof["originalAnimatorController"] is True and proof["originalAnimatorAvatar"] is True and proof["animatorInitialized"] is True and proof["animatorBonesChanged"] is True, "Proof contradicts Animator evidence")
    canonical = [row["data"] for row in rows if row["kind"] == "save_pose_canonicalized"]
    require(canonical and proof["saveZeroSignNormalizations"] == sum(data["zeroSignNormalizations"] for data in canonical) and proof["lastSaveZeroSignNormalizations"] == canonical[-1]["zeroSignNormalizations"], "Proof signed-zero counts differ from save events")
    require(proof["saveEqualityPolicy"] == FLOAT_POLICY, "Proof canonical float policy differs")


def sample(row):
    """Normalize the runtime's nested input/animator observation, not its proof flags."""
    data = row["data"]
    inp = data.get("input", data)
    anim = data["animator"]
    layers = anim.get("layers")
    if layers is None:
        layers = [anim]
    base = layers[0]
    return dict(row=row, input=inp, animator=anim, layer=base,
                before=data.get("positionBefore", data.get("positionBeforeStep")),
                after=data.get("positionAfter", data.get("positionAfterStep")),
                dt=data.get("dt", data.get("deltaTime")),
                rotation=data.get("rotation"),
                collision=data.get("collisionFlags"),
                bones=anim.get("bones", data.get("bones", [])))


def bone_map(value):
    require(isinstance(value, list) and len(value) >= 3, "Too few local bone observations")
    result = {}
    for bone in value:
        path = bone["path"]
        require(path and "/" in path and path not in result, "Missing/duplicate/non-skeletal bone path")
        vector(bone["localPosition"])
        vector(bone["localRotation"], "xyzw")
        result[path] = bone
    return result


def bone_change(a, b):
    a, b = bone_map(a), bone_map(b)
    require(set(a) == set(b), "Bone observation set changed")
    return max(max(math.dist(vector(a[key]["localPosition"]), vector(b[key]["localPosition"])),
                   rotation_error(a[key]["localRotation"], b[key]["localRotation"]) / 180)
               for key in a)


def state_hash(layer):
    return layer.get("fullPathHash", layer.get("stateFullPathHash"))


def check_identity(bound, expected):
    """Expected fields come from the separate original-asset evidence manifest."""
    require(isinstance(expected, dict) and expected, "Independent original Animator identity is required")
    fields = expected.get("acceptance_identity", expected.get("identity", {}))
    require(fields, "Original controller acceptance identity is incomplete")
    require(bound.get("playerSource") == fields["bundleSha256"] + ":" + fields["playerAsset"], "Original Animator identity differs: bundle/prefab source")
    for kind in ("controller", "avatar"):
        observed = bound[kind]
        require(observed["name"] == fields[kind + "Name"], "Original Animator identity differs: " + kind + " name")
        require(observed["sourceInstanceId"] == observed["instanceId"] and observed["sameReference"] is True,
                "Original Animator identity differs: " + kind + " object reference")
        require(type(observed["instanceId"]) is int and observed["instanceId"] != 0, "Missing Animator object instance identity")
    require(bound["avatar"]["valid"] is True and bound["avatar"]["human"] is True, "Original humanoid avatar is invalid")
    expected_path = fields["animatorPath"].split("/", 1)[-1]
    require(bound["animatorPath"] == expected_path, "Original Animator identity differs: prefab hierarchy path")
    require(bound["gameBehavioursCopied"] == 0, "Original game scripts were copied into independent runtime")
    locomotion = expected.get("locomotion")
    require(isinstance(locomotion, dict) and type(locomotion.get("stateFullPathHash")) is int, "Original blend state identity is incomplete")
    clips = locomotion.get("clips", {})
    require(set(clips) >= {"Idle", "Walk", "Run"}, "Original blend clip inventory is incomplete")
    require([clips[key]["threshold"] for key in ("Idle", "Walk", "Run")] == [0, 1, 2], "Original Speed blend thresholds differ")
    require(len({clips[key]["name"] for key in ("Idle", "Walk", "Run")}) == 3, "Original blend clip names are not distinct")
    observed_clips = {clip["name"]: clip for clip in bound["clips"]}
    for label in ("Idle", "Walk", "Run"):
        name = clips[label]["name"]
        require(name in observed_clips and number(observed_clips[name]["length"]) > 0 and observed_clips[name]["instanceId"] != 0,
                "Original controller clip inventory is incomplete: " + name)
    return locomotion


def parameters(anim):
    value = anim["parameters"]
    if isinstance(value, list):
        return {item["name"]: item.get("value", item.get("floatValue")) for item in value}
    return value


def blend_label(value, locomotion):
    """The original Idle/Walk/Jog are children of ONE locomotion blend state."""
    layer = value["layer"]
    if layer.get("inTransition", False) or state_hash(layer) != locomotion["stateFullPathHash"]:
        return None
    params = parameters(value["animator"])
    speed = number(params["Speed"])
    clips = layer.get("clips", value["animator"].get("clips", []))
    require(isinstance(clips, list), "Missing observed current Animator clips")
    for label, expected in locomotion["clips"].items():
        if label not in {"Idle", "Walk", "Run"}:
            continue
        weight = sum(number(item["weight"]) for item in clips if item["name"] == expected["name"])
        if abs(speed - expected["threshold"]) <= .075 and weight >= .9:
            return label
    return None


def state_windows(samples, locomotion, minimum=3):
    """Find stable contiguous playback, not a proof-level list of state labels."""
    windows, current, label = [], [], None
    for value in samples:
        name = blend_label(value, locomotion)
        if name != label or (current and value["row"]["frame"] != current[-1]["row"]["frame"] + 1):
            if len(current) >= minimum:
                windows.append((label, current))
            current, label = [], name
        if name:
            current.append(value)
    if len(current) >= minimum:
        windows.append((label, current))
    return windows


def intervals(samples):
    result, current = [], []
    for value in samples:
        if current and value["row"]["frame"] != current[-1]["row"]["frame"] + 1:
            result.append(current)
            current = []
        current.append(value)
    if current:
        result.append(current)
    return [dict(first_frame=values[0]["row"]["frame"], last_frame=values[-1]["row"]["frame"],
                 first_utc=values[0]["row"]["utc"], last_utc=values[-1]["row"]["utc"], samples=len(values)) for values in result]


def analyze_samples(rows, expected):
    bound = one(rows, "animator_bound")["data"]
    locomotion = check_identity(bound, expected)
    original_clip_ids = {clip["name"]: clip["instanceId"] for clip in bound["clips"]}
    samples = [sample(row) for row in rows if row["kind"] == "locomotion_sample"]
    require(len(samples) >= 12, "Insufficient per-frame input/motor/animation evidence")
    require(all(a["row"]["frame"] < b["row"]["frame"] for a, b in zip(samples, samples[1:])), "Duplicate/out-of-order locomotion samples")
    travelled, collision_frames = 0., 0
    for index, value in enumerate(samples):
        inp, anim, layer = value["input"], value["animator"], value["layer"]
        require(inp["inputSource"] == "unity-legacy" and inp["simulated"] is False, "Simulated axes cannot satisfy keyboard acceptance")
        require(type(inp["focused"]) is bool, "Focus observation is not boolean")
        require(inp.get("inputProvenance") in {"undeclared_keyboard_device", "externally_declared_os_injection", "physical-user-attested", "externally_declared_physical_keyboard_unverified"}, "Unknown input provenance")
        vector(inp["axes"], "xy")
        require(exact(inp["axes"], inp["unityAxes"], "xy"), "Motor axes differ from observed Unity input")
        for field in ("keys", "keyDown", "keyUp"):
            require(set(inp[field]) >= {"w", "a", "s", "d", "shift", "f5", "f6"} and all(type(x) is bool for x in inp[field].values()), "Missing actual keyboard read fields")
        require(anim["enabled"] is True and anim["active"] is True and anim["isInitialized"] is True and number(anim["speed"]) > 0, "Animator was not running")
        require(anim.get("applyRootMotion") is False, "Actor movement is not isolated to CharacterController")
        for ancillary in anim.get("layers", [])[1:]:
            require(number(ancillary["layerWeight"]) == 0, "Ancillary Animator layer is outside isolated locomotion scope")
        require(abs(number(parameters(anim)["LocomotionMotionSpeed"]) - 1) < .00001, "Original locomotion speed multiplier is not 1")
        for observed_clip in layer.get("clips", []):
            require(observed_clip["name"] in original_clip_ids and observed_clip["instanceId"] == original_clip_ids[observed_clip["name"]], "Playing clip is not the bound original controller clip instance")
        require(number(value["dt"]) > 0 and value["dt"] <= .051, "Invalid motor delta time")
        distance = horizontal(value["before"], value["after"])
        if not inp["focused"]:
            require(not any(inp["axes"].values()) and not any(inp["unityAxes"].values()) and not any(any(inp[field].values()) for field in ("keys", "keyDown", "keyUp")), "Unfocused positive input cannot count as keyboard evidence")
            require(distance == 0 and blend_label(value, locomotion) == "Idle", "Unfocused observation is not pure idle waiting")
        require(distance <= 12 * value["dt"] + .025, "Implausible CC displacement/possible teleport")
        travelled += distance
        require(type(value["collision"]) is int and 0 <= value["collision"] <= 7, "Missing CharacterController collision flags")
        collision_frames += bool(value["collision"] & 4)
        bone_map(value["bones"])
        number(layer["normalizedTime"])
        if index and value["row"]["frame"] == samples[index-1]["row"]["frame"] + 1:
            require(exact(samples[index-1]["after"], value["before"]), "Actor pose changed outside observed CC step")
    require(travelled >= .1 and collision_frames > 0, "Actual CC movement/ground collision was not observed")
    observed_samples = samples
    excluded = [value for value in samples if not value["input"]["focused"]]
    samples = [value for value in samples if value["input"]["focused"]]
    require(len(samples) >= 12, "Insufficient focused operation evidence")
    windows = state_windows(samples, locomotion)
    selected, cursor = [], -1
    for wanted in ("Idle", "Walk", "Run", "Idle"):
        candidates = [(idx, seq) for idx, (name, seq) in enumerate(windows) if idx > cursor and name == wanted]
        require(candidates, "Missing ordered stable state: " + wanted)
        cursor, sequence = candidates[0]
        first, last = sequence[0], sequence[-1]
        require(number(last["layer"]["normalizedTime"]) > number(first["layer"]["normalizedTime"]) + .00001, "Animator time did not advance in " + wanted)
        change = max(bone_change(first["bones"], item["bones"]) for item in sequence[1:])
        require(change > .000001, "Local skeleton did not animate in " + wanted)
        if wanted in ("Walk", "Run"):
            require(any(horizontal(x["before"], x["after"]) > .00001 for x in sequence), "Animated locomotion did not move CC: " + wanted)
            require(any(x["input"]["axes"]["x"] or x["input"]["axes"]["y"] for x in sequence), "Locomotion has no Unity axes: " + wanted)
            require(any(x["input"]["keys"]["w"] or x["input"]["keys"]["a"] or x["input"]["keys"]["s"] or x["input"]["keys"]["d"] for x in sequence), "Locomotion has no actual key held: " + wanted)
            require(any(x["input"]["keys"]["shift"] is (wanted == "Run") for x in sequence), "Sprint key does not match " + wanted)
        selected.append(dict(state=wanted, first_frame=first["row"]["frame"], last_frame=last["row"]["frame"], first_utc=first["row"]["utc"], last_utc=last["row"]["utc"],
                             samples=len(sequence), local_bone_change=change, normalized_time_start=first["layer"]["normalizedTime"], normalized_time_end=last["layer"]["normalizedTime"],
                             horizontal_travel=sum(horizontal(value["before"], value["after"]) for value in sequence)))
    first_walk, last_run, release_idle = selected[1]["first_frame"], selected[2]["last_frame"], selected[3]["first_frame"]
    require(any(value["row"]["frame"] <= first_walk and any(value["input"]["keyDown"][key] for key in "wasd") for value in samples), "No movement-key down observed before Walk")
    require(any(value["row"]["frame"] <= last_run and value["input"]["keyDown"]["shift"] for value in samples), "No Shift down observed before Run")
    require(any(value["row"]["frame"] <= release_idle and value["row"]["frame"] >= selected[2]["first_frame"] and any(value["input"]["keyUp"][key] for key in "wasd") for value in samples), "No movement-key release observed before final Idle")
    final_idle = [value for value in samples if release_idle <= value["row"]["frame"] <= selected[3]["last_frame"]]
    require(all(not any(value["input"]["keys"][key] for key in "wasd") and vector(value["input"]["axes"], "xy") == (0, 0) for value in final_idle), "Final Idle is not after released movement input")
    return dict(samples=len(samples), observed_samples_total=len(observed_samples), excluded_unfocused_idle_samples=len(excluded),
                focused_operation_intervals=intervals(samples), excluded_unfocused_idle_intervals=intervals(excluded),
                horizontal_travel=travelled, below_collision_frames=sum(bool(value["collision"] & 4) for value in samples), observed_below_collision_frames=collision_frames, ordered_states=selected,
                input_provenance=sorted({x["input"]["inputProvenance"] for x in samples}), unity_input_path_observed=True,
                physical_keyboard_measured=False, samples_private=samples)


def canonical_save(rows, command, completed, samples):
    frame = completed["frame"]
    canonical = [row for row in rows if row["kind"] == "save_pose_canonicalized" and row["frame"] == frame]
    verified = [row for row in rows if row["kind"] == "save_roundtrip_verified" and row["frame"] == frame]
    require(len(canonical) == len(verified) == 1, "Missing/duplicate same-frame canonical save evidence")
    source, checked, stored = canonical[0]["data"], verified[0]["data"], completed["data"]
    observed = [value for value in samples if value["row"]["frame"] == frame]
    require(len(observed) == 1, "Save has no unique same-frame focused Transform sample")
    require(source["actorTransformModified"] is False, "Saving altered the actual actor Transform")
    before = validate_bit_map(source["sourcePoseBits"])
    after = validate_bit_map(source["canonicalPoseBits"])
    expected = {key: 0 if value == -(2**31) else value for key, value in before.items()}
    changes = sum(value == -(2**31) for value in before.values())
    require(after == expected, "Canonicalization changed a nonzero bit or did more than negative-zero to positive-zero")
    require(numeric_pose_matches(before, observed[0]["after"], observed[0]["rotation"], True) and numeric_pose_matches(before, source["sourcePosition"], source["sourceRotation"], True), "Raw source bit evidence differs from same-frame actual Transform")
    if command is not None:
        require(command["frame"] == frame and numeric_pose_matches(before, command["data"]["position"], command["data"]["rotation"], True), "Raw source bit evidence differs from actual command pose")
    require(numeric_pose_matches(after, source["canonicalPosition"], source["canonicalRotation"]), "Canonical numeric pose differs from canonical float bits")
    for value in (source, checked, stored):
        require(value["sourcePoseBits"] == before and value["canonicalPoseBits"] == after, "Save stages disagree on source/canonical float bits")
        require(value["zeroSignNormalizations"] == changes and value["equalityPolicy"] == FLOAT_POLICY, "Signed-zero normalization count/policy differs")
    disk = validate_bit_map(checked["diskPoseBits"])
    require(disk == after == stored["diskPoseBits"], "Canonical/disk float bits are not exactly equal")
    require(checked["exactCanonicalFloatBits"] is True and checked["sameSceneAndWriter"] is True and checked["mismatches"] == "", "Runtime canonical save roundtrip did not succeed")
    require(stored["exactPosition"] is True and stored["exactRotation"] is True, "Canonical pose roundtrip flags are not exact")
    require(numeric_pose_matches(disk, stored["position"], stored["rotation"]), "Completed save numeric pose differs from disk bits")
    require(canonical[0]["real"] <= verified[0]["real"] <= completed["real"], "Canonical save stages are out of order")
    return dict(frame=frame, key=command["data"]["key"] if command is not None else None,
                attribution="unity-keyboard-command" if command is not None else "unattributed-no-keyboard-command", revision=stored["revision"], zero_sign_normalizations=changes,
                normalized_components=[key for key in sorted(before) if before[key] == -(2**31)], source_bits=before, canonical_bits=after, disk_bits=disk,
                nonzero_source_bits_preserved=True, canonical_float_bits_exact=True, actor_transform_modified=False,
                raw_source_float_bits_exact=before == disk, raw_negative_zero_sign_preservation_tested=changes > 0, raw_negative_zero_sign_preserved=False)


def check_commands(rows, samples):
    commands = [row for row in rows if row["kind"] == "keyboard_command"]
    saves = [row for row in rows if row["kind"] == "save_completed"]
    by_frame = {}
    for key in ("f5", "f6"):
        selected = [row for row in commands if row["data"]["key"].lower() == key]
        require(selected, "Missing keyboard command " + key.upper())
        for row in selected:
            data = row["data"]
            require(data.get("inputSource") == "unity-legacy" and data.get("simulated") is False and data.get("GetKeyDown") is True, "Command was not dispatched by observed Unity key down: " + key)
            matching = [item for item in samples if item["row"]["frame"] == row["frame"] and item["input"]["keyDown"][key]]
            require(matching, "No same-frame actual key edge for command: " + key)
            require(any(exact(item["after"], data["position"]) and exact(item["rotation"], data["rotation"], "xyzw") for item in matching), "Saved command pose is not the same-frame actual CC Transform: " + key)
            completed = [item for item in saves if item["frame"] == row["frame"]]
            require(len(completed) == 1, "Keyboard command did not synchronously save actual pose exactly once: " + key)
            require(row["frame"] not in by_frame, "Multiple keyboard save commands share one frame")
            by_frame[row["frame"]] = row
    require(len(saves) >= 2 and saves[-1]["data"]["revision"] > saves[0]["data"]["revision"], "F5/F6 did not produce successive saves")
    require(all(a["frame"] < b["frame"] and b["data"]["revision"] == a["data"]["revision"] + 1 for a, b in zip(saves, saves[1:])), "Save event revisions/frames are not successive")
    require(saves[-1]["frame"] in by_frame and by_frame[saves[-1]["frame"]]["data"]["key"].upper() == "F6", "Final saved revision is not the keyboard F6 save-and-quit")
    canonicalizations = [canonical_save(rows, by_frame.get(value["frame"]), value, samples) for value in saves]
    return dict(saves[-1]["data"], _save_analysis=dict(equality_policy=FLOAT_POLICY, saves=canonicalizations, zero_sign_normalizations=sum(value["zero_sign_normalizations"] for value in canonicalizations),
                                                    keyboard_command_saves=sum(value["attribution"] == "unity-keyboard-command" for value in canonicalizations), unattributed_saves=sum(value["attribution"] != "unity-keyboard-command" for value in canonicalizations),
                                                    raw_negative_zero_sign_bits_preserved=False, every_nonzero_source_bit_preserved=True, every_canonical_bit_preserved=True))


def check_save(seed, saved, first, second, stored, second_rows):
    require(saved["schemaVersion"] == 1 and saved["fileKind"] == "ReconstructedManakaSave" and saved["sceneKey"] == "Apartment", "Own JSON compatibility schema differs")
    require(saved["revision"] >= 1 and saved["savedProcessGuid"] == first["processGuid"] == second["loadedSavedProcessGuid"], "Save writer identity did not cross process boundary")
    require(saved["revision"] == stored["revision"] == first["saveRevision"] == second["saveRevision"], "Save revision differs between write/read proofs")
    require(first["processGuid"] != second["processGuid"], "Reader is not a new runtime process")
    require(instant(second["startedUtc"]) > instant(first["finishedUtc"]), "Reader started before writer finished")
    for name in ("position", "rotation"):
        names = "xyz" if name == "position" else "xyzw"
        require(exact(saved[name], stored[name], names) and exact(saved[name], second["loaded" + name.title()], names), "Saved/read float32 " + name + " differs")
        require(exact(saved[name], first["saved" + name.title()], names) and exact(saved[name], second["saved" + name.title()], names), "Saved pose differs from proof")
    applied = one(second_rows, "pose_applied_before_physics")["data"]
    require(exact(saved["position"], applied["position"]) and rotation_error(saved["rotation"], applied["rotation"]) <= .001, "Saved pose not applied before physics")
    require(exact(second["appliedPosition"], applied["position"]) and exact(second["appliedRotation"], applied["rotation"], "xyzw"), "Proof applied pose differs from before-physics event")
    require(second["exactAppliedPosition"] is exact(saved["position"], applied["position"]) and second["exactAppliedRotation"] is exact(saved["rotation"], applied["rotation"], "xyzw"), "Applied pose exactness flags differ from float32 comparison")
    readback = one(second_rows, "readback_verified_before_physics")["data"]
    require(readback["previousProcess"] is True and readback["writerProcessGuid"] == first["processGuid"] and readback["readerProcessGuid"] == second["processGuid"], "Readback event has wrong writer/reader")
    loaded = one(second_rows, "saved_state_read")["data"]
    require(exact(saved["position"], loaded["position"]) and exact(saved["rotation"], loaded["rotation"], "xyzw") and loaded["revision"] == saved["revision"], "Readback load event differs from saved bytes")
    require(saved["sourceSaveSha256"] == seed["sourceSaveSha256"], "Original save provenance changed")
    for name in ("inventory", "customization"):
        expected = seed.get(name)
        if expected is None:
            digest = hashlib.sha256(json.dumps(saved[name], ensure_ascii=False, sort_keys=True, separators=(",", ":")).encode()).hexdigest()
            require(digest == seed[name + "_sha256"], "Retained original field differs: " + name)
        else:
            require(saved[name] == expected, "Retained original field differs: " + name)
    require(bits(saved["bodyPaintRemaining"]) == bits(seed["bodyPaintRemaining"]) and saved["bodyPaintReusable"] is seed["bodyPaintReusable"], "Retained paint fields changed")
    require(validate_bit_map(stored["diskPoseBits"])["bodyPaintRemaining"] == bit_int(saved["bodyPaintRemaining"]), "Saved body paint bits differ from disk bit evidence")
    return dict(revision=saved["revision"], saved_position=saved["position"], saved_rotation=saved["rotation"], independent_json_v1_schema_preserved=True, original_nonpose_fields_preserved=True, fresh_process_readback=True,
                applied_position_bit_exact=exact(saved["position"], applied["position"]), applied_rotation_bit_exact=exact(saved["rotation"], applied["rotation"], "xyzw"), applied_rotation_error_degrees=rotation_error(saved["rotation"], applied["rotation"]))


def screenshot(path, proof, rows, title=False):
    from PIL import Image
    prefix = "titleScreenshot" if title else "screenshot"
    digest = sha(path)
    require(proof[prefix + "Validated"] is True and proof[prefix + "Sha256"] == digest, "Screenshot fingerprint/validation differs")
    matches = [row["data"] for row in rows if row["kind"] == "screenshot_validation" and row["data"]["sha256"] == digest]
    require(len(matches) == 1, "Missing/duplicate screenshot validation event")
    observed = matches[0]
    with Image.open(path) as image:
        require(image.format == "PNG", "Screenshot is not PNG")
        image = image.convert("RGB")
        width, height = image.size
        first = image.getpixel((0, height - 1))
        pixels = list(image.getdata())
        nonblack = sum(pixel != (0, 0, 0) for pixel in pixels)
        different = sum(pixel != first for pixel in pixels)
    require(nonblack > width*height/100 and different > width*height/200, "Screenshot is black/uniform")
    require((observed["width"], observed["height"], observed["pixels"], observed["nonBlackPixels"], observed["differentFromFirstPixel"]) == (width, height, width*height, nonblack, different), "Independent PNG pixel statistics differ")
    require(observed["validated"] is True and observed["cameraActive"] is True and observed["cameraEnabled"] is True and observed["afterReadyFrames"] >= 2, "Screenshot has no active ready camera")
    return dict(path=str(path), sha256=digest, width=width, height=height, nonblack_pixels=nonblack, different_pixels=different, original_visual_fidelity_verified=False)


def origin_scope(receipt, process_id, rows=None):
    if receipt is None:
        return dict(source="undeclared", os_injection_declared=False, os_injection_observed=False, physical_keyboard_attested=False, physical_keyboard_measured=False)
    require(receipt.get("target_pid") == process_id, "External input receipt targets another process")
    source = receipt.get("source")
    require(source in {"os-sendinput", "cua-sendinput", "physical-user", "undeclared"}, "Unknown external input source")
    physical = source == "physical-user"
    require(not physical or receipt.get("user_attestation") is True, "Physical-user receipt lacks user attestation")
    require(receipt.get("all_keys_released") is True, "External input receipt does not confirm key release")
    injected = source in {"os-sendinput", "cua-sendinput"}
    result = dict(source=source, os_injection_declared=injected, os_injection_observed=False,
                  physical_keyboard_attested=physical, physical_keyboard_measured=False)
    actions = receipt.get("actions")
    if not injected or not actions or rows is None:
        result["receipt_validation"] = "Source declaration/attestation only; no independently correlated OS action intervals"
        return result
    require(receipt.get("backend"), "OS input receipt has no backend identity")
    aliases = {"leftshift": "shift", "shift_l": "shift", "lshift": "shift"}
    matched = set()
    observed = [sample(row) for row in rows if row["kind"] == "locomotion_sample"]
    for action in actions:
        key = aliases.get(action["key"].lower(), action["key"].lower())
        edge = action["edge"].lower()
        require(edge in {"down", "up"}, "OS input receipt has an unknown edge")
        requested, sent = action["requested_inputs"], action["sent_inputs"]
        require(type(requested) is int and requested > 0 and requested == sent, "OS input API did not send all requested inputs")
        begin, end = instant(action["started_utc"]), instant(action["finished_utc"])
        require(begin <= end, "OS input interval runs backwards")
        for value in observed:
            elapsed_before = (instant(value["row"]["utc"]) - begin).total_seconds()
            elapsed_after = (instant(value["row"]["utc"]) - end).total_seconds()
            if -.1 <= elapsed_before and elapsed_after <= 1 and value["input"]["keyDown" if edge == "down" else "keyUp"].get(key):
                matched.add((key, edge))
                break
    required = {("shift", "down"), ("shift", "up"), ("f5", "down"), ("f6", "down")}
    movement_edges = any((key, "down") in matched and (key, "up") in matched for key in "wasd")
    require(matched >= required and movement_edges, "OS input action intervals do not correlate with the complete Unity keyboard sequence")
    result.update(os_injection_observed=True, backend=receipt["backend"], correlated_key_edges=[dict(key=key, edge=edge) for key, edge in sorted(matched)],
                  receipt_validation="Successful external OS input API counts and UTC intervals correlate with actual Unity key edges; this does not establish hardware origin")
    return result


def runtime_code_identity(first, second):
    require(first["executable_sha256"] == second["executable_sha256"], "Reader uses a different executable")
    for value in (first, second):
        require(value.get("assembly_path") and isinstance(value.get("assembly_sha256"), str) and len(value["assembly_sha256"]) == 64, "Process receipt has no managed runtime assembly identity")
    require(first["assembly_sha256"] == second["assembly_sha256"], "Reader uses a different Assembly-CSharp runtime implementation")
    return first["assembly_sha256"]


def build(config_path, verify_inputs=False):
    config_path = Path(config_path).resolve()
    config = read(config_path)
    def path(value):
        value = Path(value)
        return value.resolve() if value.is_absolute() else (config_path.parent / value).resolve()
    source_paths = [config_path]
    def load(value, lines=False):
        source = path(value)
        source_paths.append(source)
        return events(source) if lines else read(source)
    phases = []
    screenshots = []
    player_logs = []
    for name in ("phase1", "phase2"):
        inputs = config[name]
        proof, rows = load(inputs["proof"]), load(inputs["events"], True)
        event_stream(rows, proof)
        started, exited = load(inputs["start"]), load(inputs["exit"])
        require(started["pid"] == exited["pid"] == proof["processId"] and exited["process_exited"] is True and exited["exit_code"] == 0, "OS process lifecycle did not complete cleanly")
        require("-batchmode" not in started["arguments"], "Formal visual acceptance requires a visible player")
        require(Path(started["profile_root"]).resolve() == Path(proof["profileRoot"]).resolve(), "Runtime used another profile")
        require(started.get("assembly_path") and isinstance(started.get("assembly_sha256"), str) and len(started["assembly_sha256"]) == 64, "Process receipt has no managed runtime assembly identity")
        for title in (True, False):
            field = "titleScreenshotPath" if title else "screenshotPath"
            image_path = path(inputs.get("title_screenshot" if title else "screenshot", proof[field]))
            source_paths.append(image_path)
            screenshots.append(screenshot(image_path, proof, rows, title))
        if inputs.get("player_log"):
            log_path = path(inputs["player_log"])
            source_paths.append(log_path)
            opener = gzip.open if log_path.suffix == ".gz" else open
            with opener(log_path, "rt", encoding="utf-8-sig", errors="replace") as stream:
                shader_errors = [line.strip() for line in stream if "ERROR: Shader" in line]
            player_logs.append(dict(path=str(log_path), raw_shader_error_count=len(shader_errors), raw_shader_errors=shader_errors))
        phases.append((proof, rows, started))
    first, second = phases[0][0], phases[1][0]
    assembly_digest = runtime_code_identity(phases[0][2], phases[1][2])
    identity = load(config["animator_identity"])
    if verify_inputs:
        for _, _, started in phases:
            require(sha(started["executable"]) == started["executable_sha256"], "Runtime executable fingerprint changed")
            require(sha(started["assembly_path"]) == started["assembly_sha256"], "Runtime Assembly-CSharp fingerprint changed")
        for source in [identity["models"], identity["source_evidence"]] + identity.get("parser_sources", []):
            require(sha(source["path"]) == source["sha256"], "Original identity input fingerprint changed: " + source["path"])
        for source in config.get("runtime_sources", []):
            require(sha(path(source["path"])) == source["sha256"], "Runtime source fingerprint changed: " + source["path"])
    result = analyze_samples(phases[0][1], identity)
    proof_counts(first, phases[0][1], result)
    stored = check_commands(phases[0][1], result.pop("samples_private"))
    result["save_canonicalization"] = stored.pop("_save_analysis")
    saved = load(config["save"])
    seed = load(config["seed_manifest"])["selected_summary"]
    imported = one(phases[0][1], "seed_imported")["data"]
    require(exact(imported["position"], seed["position"]) and exact(imported["rotation"], seed["rotation"], "xyzw") and imported["sourceSaveSha256"] == seed["sourceSaveSha256"] and imported["revision"] == 0, "First process seed import differs from offline original projection")
    result.update(check_save(seed, saved, first, second, stored, phases[1][1]))
    result["old_save_bridge_code_identical"] = False
    result["save_bridge_code_changed"] = None
    result["legacy_own_save_file_loaded_in_this_run"] = False
    if config.get("save_bridge_sources"):
        old_bridge = path(config["save_bridge_sources"]["old"])
        new_bridge = path(config["save_bridge_sources"]["new"])
        source_paths.extend([old_bridge, new_bridge])
        old_digest, new_digest = sha(old_bridge), sha(new_bridge)
        result["old_save_bridge_code_identical"] = old_digest == new_digest
        result["save_bridge_code_changed"] = old_digest != new_digest
        result["save_bridge_code_sha256"] = dict(old=old_digest, new=new_digest)
    result["legacy_own_save_read_tested"] = False
    if config.get("save_fix_probe"):
        inputs = config["save_fix_probe"]
        probe, probe_start, probe_exit = load(inputs["result"]), load(inputs["start"]), load(inputs["exit"])
        probe_source = path(inputs["source"])
        old_save, failed_save = path(inputs["old_save"]), path(inputs["failed_save"])
        source_paths.extend([probe_source, old_save, failed_save])
        require(probe_exit["process_exited"] is True and probe_exit["exit_code"] == 0 and probe_exit["pid"] == probe_start["pid"], "Save fix Editor probe did not exit cleanly")
        require(sha(probe_source) == probe_start["source_sha256"], "Save fix probe source fingerprint differs")
        require(config.get("save_bridge_sources") and probe_start["store_sha256"] == result["save_bridge_code_sha256"]["new"], "Save fix probe did not use the final new SaveStore source")
        arguments = probe_start["arguments"]
        for flag, input_path in (("-oldSave", old_save), ("-failedSave", failed_save)):
            require(flag in arguments, "Save fix probe has no legacy input argument: " + flag)
            original_input = Path(arguments[arguments.index(flag)+1].strip('"')).resolve()
            require(original_input == input_path or original_input.is_file() and sha(original_input) == sha(input_path), "Archived legacy input differs from the file actually read by the save fix probe: " + flag)
        require(probe["exception"] == "" and probe["policy"] == FLOAT_POLICY and probe["oldMinimumRead"] is True and probe["failedRoundRead"] is True and probe["allWritesReadExact"] is True and probe["allNumericValuesUnchanged"] is True, "Save fix probe failed a legacy-read or exact canonical roundtrip gate")
        require(probe["cases"] >= 362 and probe["negativeZeroCases"] > 0 and probe["normalizedComponents"] >= probe["negativeZeroCases"], "Save fix probe has insufficient signed-zero regression coverage")
        for input_path in (old_save, failed_save):
            legacy = read(input_path)
            require(legacy["schemaVersion"] == 1 and legacy["fileKind"] == "ReconstructedManakaSave", "Legacy compatibility probe input is not own JSON version 1")
        result["legacy_own_save_read_tested"] = True
        result["legacy_own_save_read_evidence"] = dict(scope="Actual final-source Editor SaveStore.TryRead/validation for the frozen old minimum JSON and failed-round JSON; this is not a separate player scene-restore or per-field value-comparison claim.",
                                                       cases=probe["cases"], negative_zero_cases=probe["negativeZeroCases"], normalized_components=probe["normalizedComponents"],
                                                       old_minimum_save_sha256=sha(old_save), failed_round_save_sha256=sha(failed_save), final_store_sha256=probe_start["store_sha256"])
    require(sha(path(config["save"])) == first["saveSha256"] == second["saveSha256"] == stored["saveSha256"], "Writer/reader do not bind the same save bytes")
    f5_revisions = [value["revision"] for value in result["save_canonicalization"]["saves"] if value["key"] == "F5"]
    retained_f5_revisions = []
    result["f5_save_bytes_independently_verified"] = False
    if config.get("save_backup"):
        backup = load(config["save_backup"])
        saves = [row["data"] for row in phases[0][1] if row["kind"] == "save_completed"]
        prior = saves[-2]
        require(sha(path(config["save_backup"])) == prior["saveSha256"] and backup["revision"] == prior["revision"] == saved["revision"] - 1 and exact(backup["position"], prior["position"]) and exact(backup["rotation"], prior["rotation"], "xyzw"), "Adjacent prior-revision backup bytes differ from runtime save event")
        attribution = next(value for value in result["save_canonicalization"]["saves"] if value["revision"] == prior["revision"])
        result["adjacent_revision_backup"] = dict(revision=backup["revision"], next_revision=saved["revision"], sha256=sha(path(config["save_backup"])), independently_rehashed=True, attribution=attribution["attribution"], key=attribution["key"])
        if attribution["key"] == "F5":
            retained_f5_revisions.append(backup["revision"])
    result["f5_revisions"] = f5_revisions
    result["f5_revisions_with_independently_rehashed_bytes"] = retained_f5_revisions
    result["f5_save_bytes_independently_verified"] = bool(f5_revisions) and set(f5_revisions) <= set(retained_f5_revisions)
    receipt = load(config["input_receipt"]) if config.get("input_receipt") else None
    result["input_origin"] = origin_scope(receipt, first["processId"], phases[0][1])
    result.update(schema_version=1, passed=True, scope="Unity legacy keyboard path, CharacterController movement, original Animator state/skeleton playback, independent save and new-process readback; physical origin remains separately scoped.",
                  first_process_guid=first["processGuid"], second_process_guid=second["processGuid"], pid_reused=first["processId"] == second["processId"],
                  first_process_id=first["processId"], second_process_id=second["processId"], both_processes_exited_cleanly=True,
                  managed_runtime_assembly_sha256=assembly_digest, managed_runtime_assembly_same_across_processes=True,
                  original_controller_identity_basis="Static original bundle/PPtr inventory mapped to runtime exact bundle SHA, prefab/hierarchy path, controller/avatar names, original-reference equality and playing clip instance IDs; Unity public API does not expose original object path IDs or serialized-object hashes.",
                  screenshots=screenshots, player_logs=player_logs,
                  compatibility=[dict(process_guid=proof["processGuid"], engine_errors=proof["engineErrorCount"], missing_script_warnings=proof["missingScriptWarnings"],
                                      player_shader_fallbacks=proof["playerShaderFallbacks"], unresolved_builtin_meshes=proof["unresolvedBuiltinMeshes"], degraded_asset_compatibility=proof["degradedAssetCompatibility"]) for proof, _, _ in phases],
                  original_shader_compatibility_verified=False, complete_visual_or_gameplay_parity_verified=False,
                  inputs=[dict(path=str(item), sha256=sha(item)) for item in source_paths])
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--config", type=Path, required=True)
    parser.add_argument("--output", type=Path)
    parser.add_argument("--check", action="store_true")
    parser.add_argument("--inputs", action="store_true", help="Also rehash original-identity source artifacts, player executable and declared runtime sources")
    args = parser.parse_args()
    result = build(args.config, args.inputs)
    if args.output:
        protected = {Path(item["path"]).resolve() for item in result["inputs"]}
        require(args.output.resolve() not in protected, "Output must not replace any input")
        if args.check:
            require(read(args.output) == result, "Saved acceptance result differs")
        else:
            args.output.parent.mkdir(parents=True, exist_ok=True)
            args.output.write_text(json.dumps(result, ensure_ascii=False, indent=2, allow_nan=False) + "\n", encoding="utf-8")
    else:
        require(not args.check, "--check requires --output")
    print(json.dumps(result, ensure_ascii=False, indent=2, allow_nan=False))


if __name__ == "__main__":
    main()
