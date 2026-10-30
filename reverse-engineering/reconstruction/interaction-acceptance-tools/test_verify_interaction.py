"""Synthetic adversarial analyzer tests. No fixture is a Unity runtime result."""
import copy
from datetime import datetime, timedelta, timezone
import gzip
import hashlib
import json
import math
from pathlib import Path
import tempfile
import unittest

from verify_interaction import Rejected, analyze_events, build, origin_scope


IDENTITY = {
    "acceptance_identity": {"bundleSha256": "a" * 64, "playerAsset": "assets/player.prefab", "animatorPath": "Player/Manustia", "controllerName": "Player", "avatarName": "ManustiaAvatar"},
    "interaction": {
        "id": 7, "noneId": -1, "name": "SyntheticFiniteInteraction",
        "target": {"sourceBundleSha256": "b" * 64, "sourceScene": "SyntheticScene", "sourcePath": "Root/TestBin", "sourcePathId": "1234", "originalComponent": "TestInteraction", "trigger": {"isTrigger": True, "shape": "BoxCollider", "center": {"x": 0, "y": 1, "z": 0}, "size": {"x": 2, "y": 2, "z": 2}}},
        "layer": {"index": 3, "name": "Action", "stateName": "Action.Synthetic", "stateFullPathHash": 123, "clipName": "SyntheticFiniteClip", "clipLength": .2},
        "end": {"mechanism": "AnimationEvent", "function": "CommonOnEndAnim", "intParameter": 0, "time": .15, "frameDelay": 2},
        "locomotion": {"layerIndex": 0, "stateFullPathHash": 686120411, "movingClips": ["Female_Walk_Forward"]},
        "worldFallPerSecond": 10, "animationFallPerSecond": 5,
        "effects": {"collectItemId": 12345, "countDelta": 1, "targetInactive": True},
    },
    "native_system_limitations": ["Synthetic test fixture; no native system is validated."],
}


def row(kind, data, frame):
    stamp = datetime(2026, 10, 31, tzinfo=timezone.utc) + timedelta(seconds=frame / 60)
    return {"kind": kind, "data": data, "frame": frame, "real": frame / 60, "processGuid": "1" * 32, "utc": stamp.isoformat()}


def position(x=0):
    return {"x": x, "y": .025, "z": 0}


def fixture():
    spec = IDENTITY["interaction"]
    target = dict(copy.deepcopy(spec["target"]), targetId="source-bin", triggerId="source-bin-trigger", triggerInstanceId=44, originalSource=True)
    rows = [row("animator_bound", {"playerSource": "a" * 64 + ":assets/player.prefab", "animatorPath": "Manustia", "controller": {"name": "Player", "instanceId": 11, "sourceInstanceId": 11, "sameReference": True}, "avatar": {"name": "ManustiaAvatar", "instanceId": 12, "sourceInstanceId": 12, "sameReference": True, "valid": True, "human": True}, "gameBehavioursCopied": 0, "fireEvents": True, "clips": [{"name": "SyntheticFiniteClip", "instanceId": 20, "length": .2}], "movementConfiguration": {"worldFallPerSecond": 10, "animationFallPerSecond": 5}}, 0),
            row("interaction_target_registered", target, 0),
            row("interaction_trigger", {"phase": "enter", "via": "OnTriggerEnter", "actualOverlap": True, "targetId": "source-bin", "triggerId": "source-bin-trigger", "triggerInstanceId": 44, "otherColliderInstanceId": 33, "otherIsPlayerController": True, "enterSerial": 1}, 1),
            row("interaction_attempt", {"GetKeyDown": True, "inputSource": "unity-legacy", "simulated": False, "focused": True, "beforeActionId": -1, "canMoveBefore": True, "targetId": "source-bin", "accepted": True, "reason": "accepted", "sequence": 1}, 2),
            row("player_action_changed", {"previousId": -1, "actionId": 7, "source": "F-interaction", "sequence": 1, "canMove": False}, 2),
            row("action_animation_started", {"id": 7, "sequence": 1, "originalController": True, "sameReference": True, "layer": 3, "stateFullPathHash": 123}, 2),
            row("action_animation_event", {"function": "CommonOnEndAnim", "intParameter": 0, "eventTime": .15, "originalClip": True, "via": "Unity.AnimationEvent", "clipName": "SyntheticFiniteClip", "clipInstanceId": 20, "actionLayer": 3, "stateFullPathHash": 123, "normalizedTime": .75, "sequence": 1, "accepted": True}, 11),
            row("interaction_target_collected", {"targetId": "source-bin", "sequence": 1, "itemId": 12345, "countDelta": 1, "active": False, "source": "original-animation-event"}, 11),
            row("interaction_inventory_changed", {"itemId": 12345, "before": 4, "delta": 1, "after": 5, "source": "original-animation-event"}, 11),
            row("action_end_deferred", {"sequence": 1, "source": "original-animation-event", "eventFrame": 11, "earliestNoneFrame": 13}, 11),
            row("player_action_changed", {"previousId": 7, "actionId": -1, "source": "deferred-original-animation-event", "eventFrame": 11, "sequence": 1, "canMove": True}, 13)]
    x = speed = 0.
    for frame in range(20):
        active = 2 <= frame < 13
        before = position(x)
        if frame >= 13:
            speed = min(1.1, speed + 10 / 60)
        x += speed / 60
        moving_input = frame >= 3
        action = {"id": 7 if active else -1, "name": "SyntheticFiniteInteraction" if active else "None", "canMove": not active, "active": active, "sequence": 1}
        bones = [{"path": "Armature/Hips/" + name, "localPosition": position(), "localRotation": {"x": math.sin(frame / 20 + i / 10), "y": 0, "z": 0, "w": math.cos(frame / 20 + i / 10)}} for i, name in enumerate(("LeftLeg", "RightLeg", "LeftFoot"))]
        action_layer = {"layer": 3, "layerName": "Action", "layerWeight": 1, "stateName": "Action.Synthetic", "fullPathHash": 123 if active else 0, "normalizedTime": frame / 15, "inTransition": False, "clips": [{"name": "SyntheticFiniteClip", "instanceId": 20, "weight": 1, "length": 1}] if active else []}
        base_layer = {"layer": 0, "layerName": "Locomotion", "layerWeight": 1, "fullPathHash": 686120411, "normalizedTime": frame / 60, "clips": [{"name": "Female_Walk_Forward" if frame >= 13 else "Female_Idle_Base", "weight": 1, "instanceId": 21}]}
        rows.append(row("interaction_sample", {"inputSource": "unity-legacy", "inputProvenance": "external_origin_unspecified", "simulated": False, "focused": True, "fDown": frame == 2, "fHeld": 2 <= frame <= 4, "fUp": frame == 5, "inputEnabled": True, "candidates": [{"targetId": "source-bin", "sourcePathId": "1234", "sourcePath": "Root/TestBin", "enterSerial": 1, "overlapping": True}], "selectedTargetId": "source-bin", "playerAction": action, "guard": {"accepted": frame == 2, "reason": "accepted" if frame == 2 else "no-F-edge"}, "positionBefore": before, "positionAfter": position(x), "rotation": {"x": 0, "y": 0, "z": 0, "w": 1}, "axes": {"x": 0, "y": int(moving_input)}, "unityAxes": {"x": 0, "y": int(moving_input)}, "resolvedAxes": {"x": 0, "y": int(moving_input)}, "dt": 1 / 60, "currentSpeed": speed, "targetSpeed": 1.1 if frame >= 13 else 0, "animationSpeed": speed, "targetAnimationSpeed": 1 if frame >= 13 else 0, "controllerMoveCalled": True, "collisionFlags": 4, "animator": {"enabled": True, "active": True, "isInitialized": True, "speed": 1, "applyRootMotion": False, "layers": [base_layer, action_layer], "bones": bones}}, frame))
    return sorted(rows, key=lambda value: value["frame"])


def selected(rows, kind):
    return [value for value in rows if value["kind"] == kind]


def samples(rows):
    return selected(rows, "interaction_sample")


def parameter_fixture():
    rows, identity = fixture(), copy.deepcopy(IDENTITY)
    writes = [{"name": "OldActionId", "type": "Int", "valueSource": "previousActionId"}, {"name": "ActionId", "type": "Int", "valueSource": "actionId"}, {"name": "TransAction", "type": "Trigger"}]
    identity["interaction"].update(enterParameters=copy.deepcopy(writes), exitParameters=copy.deepcopy(writes))
    selected(rows, "action_animation_started")[0]["data"]["parameters"] = copy.deepcopy(writes)
    end = selected(rows, "player_action_changed")[-1]
    rows.insert(rows.index(end), row("action_animation_none_requested", {"sequence": 1, "parameters": copy.deepcopy(writes)}, 13))
    for value in samples(rows):
        value["data"]["animator"]["parameters"] = {"ActionId": 7 if 2 <= value["frame"] < 13 else -1, "OldActionId": -1 if value["frame"] < 13 else 7}
    return rows, identity


def controlled_fixture():
    rows = fixture()
    for value in samples(rows):
        value["data"].update(inputSource="simulated-axes", inputProvenance="internal_acceptance_axes", simulated=True, focused=False)
    for value in selected(rows, "interaction_attempt"):
        value["data"].update(inputSource="simulated-keys", inputProvenance="internal_controlled_F", simulated=True, GetKeyDown=False, focused=False)
    return rows


class RejectionTests(unittest.TestCase):
    def reject(self, rows, message):
        with self.assertRaisesRegex(Rejected, message):
            analyze_events(rows, IDENTITY)

    def test_valid_synthetic_fixture_is_analysis_only(self):
        result = analyze_events(fixture(), IDENTITY)
        self.assertEqual(result["cycles"][0]["original_frame_delay"], 2)
        self.assertFalse(result["physical_keyboard_measured"])
        self.assertEqual(result["accepted_f_attempts"], 1)

    def test_fake_target_identity_rejected(self):
        rows = fixture()
        selected(rows, "interaction_target_registered")[0]["data"]["sourcePathId"] = "999"
        self.reject(rows, "target identity differs")

    def test_synthetic_same_name_target_rejected(self):
        rows = fixture()
        selected(rows, "interaction_target_registered")[0]["data"]["originalSource"] = False
        self.reject(rows, "Synthetic target")

    def test_json_float32_decimal_spellings_keep_original_geometry(self):
        rows = fixture()
        identity = copy.deepcopy(IDENTITY)
        identity["interaction"]["target"]["trigger"]["center"]["y"] = .44999998807907104
        selected(rows, "interaction_target_registered")[0]["data"]["trigger"]["center"]["y"] = .45
        self.assertTrue(analyze_events(rows, identity)["passed"])

    def test_changed_float32_trigger_geometry_rejected(self):
        rows = fixture()
        selected(rows, "interaction_target_registered")[0]["data"]["trigger"]["center"]["y"] += .01
        self.reject(rows, "trigger geometry differs")

    def test_jsonutility_empty_string_keeps_explicit_absent_original_scene(self):
        rows, identity = fixture(), copy.deepcopy(IDENTITY)
        identity["interaction"]["target"]["sourceScene"] = None
        selected(rows, "interaction_target_registered")[0]["data"]["sourceScene"] = ""
        self.assertTrue(analyze_events(rows, identity)["passed"])

    def test_fixture_cannot_claim_original_apartment_placement(self):
        rows, identity = fixture(), copy.deepcopy(IDENTITY)
        identity["interaction"]["target"]["sourceScene"] = None
        selected(rows, "interaction_target_registered")[0]["data"]["sourceScene"] = "Apartment"
        with self.assertRaisesRegex(Rejected, "target identity differs: sourceScene"):
            analyze_events(rows, identity)

    def test_proximity_without_real_trigger_entry_rejected(self):
        rows = [value for value in fixture() if value["kind"] != "interaction_trigger"]
        self.reject(rows, "No actual trigger entry")

    def test_fake_manual_trigger_entry_rejected(self):
        rows = fixture()
        selected(rows, "interaction_trigger")[0]["data"]["via"] = "distance-poll"
        self.reject(rows, "manually substituted")

    def test_stale_candidate_after_exit_rejected(self):
        rows = fixture()
        event = copy.deepcopy(selected(rows, "interaction_trigger")[0])
        event["data"]["phase"] = "exit"
        rows.insert(rows.index(selected(rows, "interaction_trigger")[0]) + 1, event)
        self.reject(rows, "No actual trigger entry")

    def test_wrong_player_collider_rejected(self):
        rows = fixture()
        selected(rows, "interaction_trigger")[0]["data"]["otherIsPlayerController"] = False
        self.reject(rows, "not the player CharacterController")

    def test_accepted_busy_action_rejected(self):
        rows = fixture()
        selected(rows, "interaction_attempt")[0]["data"]["beforeActionId"] = 7
        self.reject(rows, "bypassed original idle")

    def test_original_crouch_guard_accepts_neutral_standing_input(self):
        rows, identity = fixture(), copy.deepcopy(IDENTITY)
        identity["interaction"]["guards"] = {"reject_crouch": True}
        selected(rows, "interaction_target_registered")[0]["data"]["rejectCrouch"] = True
        selected(rows, "interaction_attempt")[0]["data"]["crouch"] = False
        self.assertTrue(analyze_events(rows, identity)["passed"])

    def test_crouch_cannot_pass_original_pickup_guard(self):
        rows, identity = fixture(), copy.deepcopy(IDENTITY)
        identity["interaction"]["guards"] = {"reject_crouch": True}
        selected(rows, "interaction_target_registered")[0]["data"]["rejectCrouch"] = True
        selected(rows, "interaction_attempt")[0]["data"]["crouch"] = True
        with self.assertRaisesRegex(Rejected, "bypassed original crouch"):
            analyze_events(rows, identity)

    def test_missing_original_crouch_guard_rejected(self):
        rows, identity = fixture(), copy.deepcopy(IDENTITY)
        identity["interaction"]["guards"] = {"reject_crouch": True}
        selected(rows, "interaction_attempt")[0]["data"]["crouch"] = False
        with self.assertRaisesRegex(Rejected, "crouch guard was omitted"):
            analyze_events(rows, identity)

    def test_simulated_axis_history_not_upgraded(self):
        rows = fixture()
        for value in samples(rows):
            value["data"]["simulated"] = True
        self.reject(rows, "Simulated input")

    def test_unfocused_f_cannot_establish_interaction(self):
        rows = fixture()
        samples(rows)[2]["data"]["focused"] = False
        self.reject(rows, "Unfocused positive")

    def test_unfocused_other_key_cannot_hide_in_idle_exclusion(self):
        rows = fixture()
        samples(rows)[0]["data"].update(focused=False, keys={"f": False, "f5": True})
        self.reject(rows, "Unfocused positive")

    def test_separate_unity_f_reads_must_agree(self):
        rows = fixture()
        samples(rows)[2]["data"]["keyDown"] = {"f": False}
        self.reject(rows, "Separate Unity F reads disagree")

    def test_missing_actual_f_down_rejected(self):
        rows = fixture()
        samples(rows)[2]["data"]["fDown"] = False
        self.reject(rows, "GetKeyDown and interaction attempts differ")

    def test_held_f_cannot_create_repeated_edges(self):
        rows = fixture()
        samples(rows)[3]["data"]["fDown"] = True
        self.reject(rows, "Held F was reported as repeated")

    def test_missing_f_release_rejected(self):
        rows = fixture()
        samples(rows)[5]["data"]["fUp"] = False
        self.reject(rows, "F release")

    def test_repeated_f_busy_guard_is_accepted(self):
        rows = fixture()
        value = samples(rows)[7]["data"]
        value.update(fDown=True, fHeld=True, guard={"accepted": False, "reason": "busy"})
        samples(rows)[8]["data"]["fUp"] = True
        rows.append(row("interaction_attempt", {"GetKeyDown": True, "inputSource": "unity-legacy", "simulated": False, "focused": True, "beforeActionId": 7, "canMoveBefore": False, "targetId": "source-bin", "accepted": False, "reason": "busy", "sequence": 1}, 7))
        rows.sort(key=lambda value: value["frame"])
        self.assertEqual(analyze_events(rows, IDENTITY)["rejected_f_attempts"], 1)

    def test_repeated_f_cannot_restart_action(self):
        rows = fixture()
        duplicate = copy.deepcopy(selected(rows, "player_action_changed")[0])
        rows.insert(rows.index(selected(rows, "player_action_changed")[0]), duplicate)
        self.reject(rows, "counts differ")

    def test_forced_timeout_cannot_replace_end(self):
        rows = fixture()
        selected(rows, "player_action_changed")[-1]["data"]["source"] = "forced-timeout-complete"
        self.reject(rows, "Forced/timeout completion")

    def test_no_original_end_event_rejected(self):
        rows = [value for value in fixture() if value["kind"] != "action_animation_event"]
        self.reject(rows, "Missing/duplicate accepted original end")

    def test_manual_end_call_rejected(self):
        rows = fixture()
        selected(rows, "action_animation_event")[0]["data"]["via"] = "manual-test-callback"
        self.reject(rows, "not dispatched by actual Unity")

    def test_wrong_original_end_function_rejected(self):
        rows = fixture()
        selected(rows, "action_animation_event")[0]["data"]["function"] = "OnEndSitDown"
        self.reject(rows, "Wrong original end event")

    def test_wrong_layer_rejected(self):
        rows = fixture()
        for value in samples(rows):
            value["data"]["animator"]["layers"][1]["layerName"] = "ClothActionArm"
        self.reject(rows, "Missing stable original Action")

    def test_wrong_clip_instance_rejected(self):
        rows = fixture()
        for value in samples(rows):
            for clip in value["data"]["animator"]["layers"][1]["clips"]:
                clip["instanceId"] = 999
        self.reject(rows, "Missing stable original Action")

    def test_wrong_clip_event_rejected(self):
        rows = fixture()
        selected(rows, "action_animation_event")[0]["data"]["clipName"] = "OtherClip"
        self.reject(rows, "wrong Action clip")

    def test_wrong_original_delay_rejected(self):
        rows = fixture()
        identity = copy.deepcopy(IDENTITY)
        identity["interaction"]["end"]["frameDelay"] = 1
        with self.assertRaisesRegex(Rejected, "original frame delay"):
            analyze_events(rows, identity)

    def test_immediate_original_end_preserves_same_frame_none(self):
        rows = fixture()
        identity = copy.deepcopy(IDENTITY)
        identity["interaction"]["end"]["frameDelay"] = 0
        rows = [value for value in rows if value["kind"] != "action_end_deferred"]
        callback = selected(rows, "action_animation_event")[0]
        callback.update(frame=13, real=13 / 60, utc=samples(rows)[13]["utc"])
        for kind in ("interaction_target_collected", "interaction_inventory_changed"):
            selected(rows, kind)[0].update(frame=13, real=13 / 60, utc=samples(rows)[13]["utc"])
        end = selected(rows, "player_action_changed")[-1]
        end["data"].update(source="original-animation-event", eventFrame=13)
        rows.sort(key=lambda value: value["frame"])
        self.assertEqual(analyze_events(rows, identity)["cycles"][0]["original_frame_delay"], 0)

    def test_early_manual_callback_cannot_use_original_event_label(self):
        rows = fixture()
        selected(rows, "action_animation_event")[0]["data"]["normalizedTime"] = .01
        self.reject(rows, "wrong clip time")

    def test_original_pickup_must_hide_target(self):
        rows = fixture()
        selected(rows, "interaction_target_collected")[0]["data"]["active"] = True
        self.reject(rows, "target side effect differs")

    def test_original_pickup_item_id_cannot_be_substituted(self):
        rows = fixture()
        selected(rows, "interaction_inventory_changed")[0]["data"]["itemId"] = 999
        self.reject(rows, "inventory delta differs")

    def test_original_pickup_count_delta_cannot_be_duplicated(self):
        rows = fixture()
        selected(rows, "interaction_inventory_changed")[0]["data"].update(delta=2, after=6)
        self.reject(rows, "inventory delta differs")

    def test_pickup_cannot_precede_original_end_callback(self):
        rows = fixture()
        event = selected(rows, "action_animation_event")[0]
        rows.remove(event)
        rows.insert(rows.index(selected(rows, "action_end_deferred")[0]), event)
        self.reject(rows, "callback order differs")

    def test_early_recovery_cannot_unlock_before_none(self):
        rows = fixture()
        samples(rows)[10]["data"]["playerAction"]["canMove"] = True
        self.reject(rows, "lock ended before original None")

    def test_receipt_cannot_claim_none_one_frame_before_observation(self):
        rows = fixture()
        samples(rows)[13]["data"]["playerAction"].update(id=7, canMove=False)
        samples(rows)[13]["data"].update(targetSpeed=0, targetAnimationSpeed=0, currentSpeed=0, animationSpeed=0, positionAfter=position())
        for value in samples(rows)[14:]:
            value["data"]["positionBefore"]["x"] -= 1 / 360
            value["data"]["positionAfter"]["x"] -= 1 / 360
        self.reject(rows, "completion frame")

    def test_global_input_disable_cannot_substitute_action_guard(self):
        rows = fixture()
        samples(rows)[7]["data"]["inputEnabled"] = False
        self.reject(rows, "lock ended before original None")

    def test_movement_target_bypass_before_end_rejected(self):
        rows = fixture()
        samples(rows)[10]["data"]["targetSpeed"] = 1.1
        self.reject(rows, "bypassed CanMove")

    def test_early_horizontal_teleport_rejected(self):
        rows = fixture()
        samples(rows)[10]["data"]["positionAfter"]["x"] += .1
        self.reject(rows, "exceeds actual CC speed")

    def test_inertia_cannot_grow_while_locked(self):
        rows = fixture()
        samples(rows)[10]["data"]["currentSpeed"] = .05
        self.reject(rows, "original deceleration")

    def test_original_inertia_may_decay_during_locked_action(self):
        rows = fixture()
        x = 0.
        for value in samples(rows):
            frame, data = value["frame"], value["data"]
            data["positionBefore"] = position(x)
            if frame < 13:
                data["currentSpeed"] = max(0, .5 - (frame - 1) * 10 / 60)
                data["animationSpeed"] = max(0, .5 - (frame - 1) * 5 / 60)
            x += data["currentSpeed"] / 60
            data["positionAfter"] = position(x)
        result = analyze_events(rows, IDENTITY)
        self.assertTrue(result["passed"])

    def test_micro_move_after_inertia_zero_rejected(self):
        rows = fixture()
        samples(rows)[10]["data"]["positionAfter"]["x"] += .001
        self.reject(rows, "inertia reached zero")

    def test_missing_frame_cannot_hide_early_unlock(self):
        rows = fixture()
        rows.remove(samples(rows)[10])
        self.reject(rows, "Missing consecutive")

    def test_action_name_without_advancing_time_rejected(self):
        rows = fixture()
        for value in samples(rows):
            value["data"]["animator"]["layers"][1]["normalizedTime"] = .1
        self.reject(rows, "time did not advance")

    def test_root_translation_is_not_skeletal_animation(self):
        rows = fixture()
        bones = copy.deepcopy(samples(rows)[0]["data"]["animator"]["bones"])
        for value in samples(rows):
            value["data"]["animator"]["bones"] = bones
        self.reject(rows, "Local skeleton did not animate")

    def test_no_movement_input_during_lock_is_insufficient(self):
        rows = fixture()
        for value in samples(rows)[3:13]:
            for name in ("axes", "unityAxes", "resolvedAxes"):
                value["data"][name]["y"] = 0
        self.reject(rows, "movement input while original CanMove blocked")

    def test_none_without_input_cc_recovery_is_insufficient(self):
        rows = fixture()
        for value in samples(rows)[13:]:
            value["data"].update(positionBefore=position(), positionAfter=position())
        self.reject(rows, "No consecutive input -> CC movement")

    def test_same_name_controller_replacement_rejected(self):
        rows = fixture()
        selected(rows, "animator_bound")[0]["data"]["controller"]["sourceInstanceId"] = 999
        self.reject(rows, "controller instance differs")

    def test_original_parameter_writes_and_actual_values_accept(self):
        rows, identity = parameter_fixture()
        self.assertTrue(analyze_events(rows, identity)["passed"])

    def test_forced_play_without_original_trigger_write_rejected(self):
        rows, identity = parameter_fixture()
        selected(rows, "action_animation_started")[0]["data"]["parameters"].pop()
        with self.assertRaisesRegex(Rejected, "parameter write count differs"):
            analyze_events(rows, identity)

    def test_actual_action_parameter_must_match_original_id(self):
        rows, identity = parameter_fixture()
        samples(rows)[7]["data"]["animator"]["parameters"]["ActionId"] = 999
        with self.assertRaisesRegex(Rejected, "parameters differ during pickup"):
            analyze_events(rows, identity)

    def test_exit_parameter_request_must_use_original_writes(self):
        rows, identity = parameter_fixture()
        selected(rows, "action_animation_none_requested")[0]["data"]["parameters"][0]["valueSource"] = "actionId"
        with self.assertRaisesRegex(Rejected, "parameter writes differ"):
            analyze_events(rows, identity)

    def test_none_animator_parameters_must_preserve_old_action(self):
        rows, identity = parameter_fixture()
        samples(rows)[13]["data"]["animator"]["parameters"]["OldActionId"] = -1
        with self.assertRaisesRegex(Rejected, "None parameters differ"):
            analyze_events(rows, identity)

    def test_origin_undeclared_stays_undeclared(self):
        self.assertEqual(origin_scope(None, 12, fixture())["classification"], "undeclared")

    def test_physical_claim_needs_user_attestation(self):
        receipt = {"source": "physical-user", "target_pid": 12, "all_keys_released": True}
        with self.assertRaisesRegex(Rejected, "explicit user attestation"):
            origin_scope(receipt, 12, fixture())

    def test_attestation_is_human_evidence_not_device_measurement(self):
        receipt = {"source": "physical-user", "target_pid": 12, "all_keys_released": True, "user_attestation": True, "user_reply": "I completed the keys."}
        result = origin_scope(receipt, 12, fixture())
        self.assertTrue(result["human_physical_attestation"])
        self.assertFalse(result["physical_keyboard_measured"])

    def test_os_injection_is_never_promoted_to_physical(self):
        receipt = {"source": "os-sendinput", "target_pid": 12, "all_keys_released": True, "backend": "SendInput", "commands": [{"key": "F", "successful": True, "sent": 2, "requested": 2, "down_utc": "2026-10-31T00:00:00Z", "up_utc": "2026-10-31T00:00:01Z"}]}
        result = origin_scope(receipt, 12, fixture())
        self.assertEqual(result["classification"], "os-injected-keyboard-observed-by-unity")
        self.assertFalse(result["human_physical_attestation"])

    def test_os_receipt_for_unrelated_key_does_not_attribute_f(self):
        receipt = {"source": "os-sendinput", "target_pid": 12, "all_keys_released": True, "backend": "SendInput", "commands": [{"key": "W", "successful": True, "sent": 2, "requested": 2, "down_utc": "2026-10-31T00:00:00Z", "up_utc": "2026-10-31T00:00:01Z"}]}
        with self.assertRaisesRegex(Rejected, "do not cover actual Unity F"):
            origin_scope(receipt, 12, fixture())

    def test_os_receipt_for_old_interval_does_not_attribute_f(self):
        receipt = {"source": "os-sendinput", "target_pid": 12, "all_keys_released": True, "backend": "SendInput", "commands": [{"key": "F", "successful": True, "sent": 2, "requested": 2, "down_utc": "2026-10-30T00:00:00Z", "up_utc": "2026-10-30T00:00:01Z"}]}
        with self.assertRaisesRegex(Rejected, "do not cover actual Unity F"):
            origin_scope(receipt, 12, fixture())


class FileBindingTests(unittest.TestCase):
    """Temporary synthetic files test stale-archive/binary rejection only."""

    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.assembly = self.root / "Assembly-CSharp.dll"
        self.executable = self.root / "Synthetic.exe"
        self.source = self.root / "Synthetic.cs"
        self.assembly.write_bytes(b"SYNTHETIC fixture, not a managed executable")
        self.executable.write_bytes(b"SYNTHETIC fixture, never executed")
        self.source.write_text("// SYNTHETIC fixture", encoding="utf-8")
        with gzip.open(self.root / "events.jsonl.gz", "wt", encoding="utf-8") as stream:
            for value in fixture():
                stream.write(json.dumps(value) + "\n")
        self.write("identity.json", IDENTITY)
        self.write("start.json", {"pid": 12, "started_utc": "2026-10-30T23:59:59Z", "assembly_path": str(self.assembly), "assembly_sha256": self.digest(self.assembly), "executable": str(self.executable), "executable_sha256": self.digest(self.executable)})
        self.write("exit.json", {"pid": 12, "process_exited": True, "exit_code": 0, "exited_utc": "2026-10-31T00:00:02Z"})
        self.write("proof.json", {"processId": 12, "processGuid": "1" * 32, "passed": True, "completed": True})
        self.config = {"events": "events.jsonl.gz", "identity": "identity.json", "start": "start.json", "exit": "exit.json", "proof": "proof.json", "runtime_sources": [{"path": "Synthetic.cs", "sha256": self.digest(self.source)}]}
        self.write("config.json", self.config)

    def digest(self, path):
        return hashlib.sha256(path.read_bytes()).hexdigest()

    def write(self, path, value):
        (self.root / path).write_text(json.dumps(value), encoding="utf-8")

    def test_compressed_synthetic_archive_binds_every_file(self):
        result = build(self.root / "config.json", True)
        self.assertTrue(result["lifecycle"]["actual_launched_binaries_rehashed"])
        self.assertEqual(result["artifacts"]["events"]["sha256"], self.digest(self.root / "events.jsonl.gz"))
        self.assertEqual(result["input_origin"]["classification"], "undeclared")

    def test_binary_identity_cannot_use_equal_launcher_only(self):
        self.assembly.write_bytes(b"different managed implementation")
        with self.assertRaisesRegex(Rejected, "Managed runtime assembly differs"):
            build(self.root / "config.json", True)

    def test_runtime_source_change_cannot_reuse_old_report(self):
        self.source.write_text("// changed", encoding="utf-8")
        with self.assertRaisesRegex(Rejected, "Runtime source hash differs"):
            build(self.root / "config.json", True)

    def test_input_receipt_from_old_process_rejected(self):
        self.write("receipt.json", {"source": "physical-user", "target_pid": 11, "all_keys_released": True, "user_attestation": True, "user_reply": "done"})
        self.config["input_receipt"] = "receipt.json"
        self.write("config.json", self.config)
        with self.assertRaisesRegex(Rejected, "another process"):
            build(self.root / "config.json", True)

    def test_runtime_proof_from_old_guid_rejected(self):
        self.write("proof.json", {"processId": 12, "processGuid": "2" * 32, "passed": True, "completed": True})
        with self.assertRaisesRegex(Rejected, "another process"):
            build(self.root / "config.json", True)

    def test_static_identity_cannot_bind_changed_raw_source(self):
        raw = self.root / "raw-static-evidence.json"
        raw.write_text("{}", encoding="utf-8")
        identity = copy.deepcopy(IDENTITY)
        identity["sources"] = [{"path": raw.name, "sha256": self.digest(raw)}]
        self.write("identity.json", identity)
        raw.write_text('{"changed":true}', encoding="utf-8")
        with self.assertRaisesRegex(Rejected, "Independent identity source hash differs"):
            build(self.root / "config.json", True)


class ControlledScopeTests(unittest.TestCase):
    def test_controlled_subchain_never_accepts_actual_unity_keyboard(self):
        result = analyze_events(controlled_fixture(), IDENTITY, controlled=True)
        self.assertTrue(result["passed"])
        self.assertFalse(result["full_chain_accepted"])
        self.assertFalse(result["actual_unity_f_accepted"])
        self.assertTrue(result["controlled_subchain_only"])

    def test_controlled_runtime_remains_rejected_by_formal_mode(self):
        with self.assertRaisesRegex(Rejected, "Simulated input"):
            analyze_events(controlled_fixture(), IDENTITY)

    def test_controlled_mode_cannot_launder_actual_getkeydown_claim(self):
        rows = controlled_fixture()
        selected(rows, "interaction_attempt")[0]["data"]["GetKeyDown"] = True
        with self.assertRaisesRegex(Rejected, "must not claim actual Unity"):
            analyze_events(rows, IDENTITY, controlled=True)

    def test_controlled_timeout_still_cannot_replace_original_event(self):
        rows = controlled_fixture()
        selected(rows, "player_action_changed")[-1]["data"]["source"] = "forced-timeout"
        with self.assertRaisesRegex(Rejected, "Forced/timeout"):
            analyze_events(rows, IDENTITY, controlled=True)

    def test_controlled_mode_does_not_hide_unattributed_teleport(self):
        rows = controlled_fixture()
        for value in samples(rows)[1:]:
            value["data"]["positionBefore"]["x"] += .5
            value["data"]["positionAfter"]["x"] += .5
        with self.assertRaisesRegex(Rejected, "outside observed CC steps"):
            analyze_events(rows, IDENTITY, controlled=True)

    def test_controlled_setup_after_previous_motor_sample_is_explicitly_excluded(self):
        rows = controlled_fixture()
        for value in samples(rows)[1:]:
            value["data"]["positionBefore"]["x"] += .5
            value["data"]["positionAfter"]["x"] += .5
        rows.append(row("controlled_fixture_setup", {"position": position(.5), "originalLevelPlacement": False, "method": "explicit synthetic test setup"}, 0))
        rows.sort(key=lambda value: value["frame"])
        result = analyze_events(rows, IDENTITY, controlled=True)
        self.assertEqual(result["controlled_setup_excluded_frames"], [0])
        self.assertFalse(result["full_chain_accepted"])

if __name__ == "__main__":
    unittest.main()
