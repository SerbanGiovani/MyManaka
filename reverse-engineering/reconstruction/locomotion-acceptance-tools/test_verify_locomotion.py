"""Synthetic adversarial fixtures; these are NOT evidence of a player run."""
import copy
import math
import unittest

from verify_locomotion import FLOAT_POLICY, Rejected, analyze_samples, bit_int, check_commands, check_save, origin_scope, runtime_code_identity


IDENTITY = {
    "acceptance_identity": {"bundleSha256": "a" * 64, "controllerObjectSha256": "b" * 64,
                            "controllerPathId": "-1824587515900773540", "controllerName": "Player",
                            "avatarName": "ManustiaAvatar", "playerAsset": "assets/player.prefab", "animatorPath": "Player/Manustia"},
    "locomotion": {"stateFullPathHash": 686120411, "clips": {
        "Idle": {"name": "Female_Idle_Base", "threshold": 0},
        "Walk": {"name": "Female_Walk_Forward", "threshold": 1},
        "Run": {"name": "Female_Jog_Forward", "threshold": 2}}}}


def position(x=0):
    return {"x": x, "y": .025, "z": 0}


def rotation(angle=0):
    return {"x": math.sin(angle/2), "y": 0, "z": 0, "w": math.cos(angle/2)}


def float_map(pose, paint=12.25):
    result = {group + "." + axis: bit_int(value) for group in ("position", "rotation") for axis, value in pose[group].items()}
    result["bodyPaintRemaining"] = bit_int(paint)
    return result


def row(kind, data, frame=0):
    return {"kind": kind, "data": data, "frame": frame, "real": frame/60,
            "processGuid": "11111111111111111111111111111111", "utc": "2026-10-31T00:00:00Z"}


def fixture():
    bound = {"playerSource": "a" * 64 + ":assets/player.prefab", "animatorPath": "Manustia", "gameBehavioursCopied": 0,
             "controller": {"name": "Player", "instanceId": 11, "sourceInstanceId": 11, "sameReference": True},
             "avatar": {"name": "ManustiaAvatar", "instanceId": 12, "sourceInstanceId": 12, "sameReference": True, "valid": True, "human": True},
             "clips": [{"name": value["name"], "instanceId": index+20, "length": 1} for index, value in enumerate(IDENTITY["locomotion"]["clips"].values())]}
    rows = [row("animator_bound", bound)]
    current = 0.
    for frame in range(20):
        label = ("Idle", "Walk", "Run", "Idle")[frame // 5]
        moving = label in ("Walk", "Run")
        speed = IDENTITY["locomotion"]["clips"][label]["threshold"]
        keys = {key: False for key in ("w", "a", "s", "d", "shift", "c", "f5", "f6")}
        down, up = keys.copy(), keys.copy()
        keys["w"], keys["shift"] = moving, label == "Run"
        if frame == 5:
            down["w"] = True
        if frame == 10:
            down["shift"] = True
        if frame == 15:
            up["w"] = up["shift"] = True
        if frame in (18, 19):
            key = "f5" if frame == 18 else "f6"
            keys[key] = down[key] = True
        before = position(current)
        current += speed / 60
        after = position(current)
        bones = [{"path": "Armature/Hips/" + name, "localPosition": {"x": 0, "y": 1, "z": 0},
                  "localRotation": rotation(.1 * math.sin(frame * .5 + index))}
                 for index, name in enumerate(("LeftLeg", "RightLeg", "LeftFoot"))]
        data = {"input": {"inputSource": "unity-legacy", "inputProvenance": "externally_declared_os_injection",
                          "simulated": False, "focused": True, "axes": {"x": 0, "y": int(moving)},
                          "unityAxes": {"x": 0, "y": int(moving)}, "keys": keys, "keyDown": down, "keyUp": up},
                "positionBefore": before, "positionAfter": after, "rotation": rotation(), "dt": 1/60, "collisionFlags": 4,
                "animator": {"enabled": True, "active": True, "isInitialized": True, "speed": 1, "applyRootMotion": False,
                             "parameters": {"Speed": speed, "LocomotionMotionSpeed": 1},
                             "layers": [{"fullPathHash": 686120411, "normalizedTime": frame/60, "inTransition": False,
                                         "clips": [{"name": IDENTITY["locomotion"]["clips"][label]["name"], "instanceId": 20 + ("Idle", "Walk", "Run").index(label), "weight": 1}]}], "bones": bones}}
        rows.append(row("locomotion_sample", data, frame))
    for frame, key, revision in ((18, "F5", 1), (19, "F6", 2)):
        pose = {"position": position(current), "rotation": rotation()}
        bit_map = float_map(pose)
        common = dict(sourcePoseBits=bit_map.copy(), canonicalPoseBits=bit_map.copy(), zeroSignNormalizations=0, equalityPolicy=FLOAT_POLICY)
        rows += [row("keyboard_command", dict(pose, key=key, inputSource="unity-legacy", simulated=False, GetKeyDown=True), frame),
                 row("save_pose_canonicalized", dict(common, sourcePosition=pose["position"], sourceRotation=pose["rotation"], canonicalPosition=pose["position"], canonicalRotation=pose["rotation"], actorTransformModified=False), frame),
                 row("save_roundtrip_verified", dict(common, diskPoseBits=bit_map.copy(), exactCanonicalFloatBits=True, sameSceneAndWriter=True, mismatches=""), frame),
                 row("save_completed", dict(pose, **common, diskPoseBits=bit_map.copy(), revision=revision, exactPosition=True, exactRotation=True), frame)]
    return rows


def mutate_samples(rows, function):
    for value in rows:
        if value["kind"] == "locomotion_sample":
            function(value["data"])


def save_fixture():
    seed = {"position": position(), "rotation": rotation(), "sourceSaveSha256": "d"*64,
            "inventory": [{"id": 5, "count": 3}], "customization": {"hair": 1}, "bodyPaintRemaining": 12.25, "bodyPaintReusable": True}
    writer, reader = "1"*32, "2"*32
    saved = dict(copy.deepcopy(seed), schemaVersion=1, fileKind="ReconstructedManakaSave", sceneKey="Apartment", revision=2, savedProcessGuid=writer, position=position(.5))
    first = {"processGuid": writer, "finishedUtc": "2026-10-31T00:00:05Z", "saveRevision": 2,
             "savedPosition": saved["position"], "savedRotation": saved["rotation"]}
    second = {"processGuid": reader, "startedUtc": "2026-10-31T00:00:06Z", "saveRevision": 2, "loadedSavedProcessGuid": writer,
              "loadedPosition": saved["position"], "loadedRotation": saved["rotation"], "savedPosition": saved["position"], "savedRotation": saved["rotation"],
              "appliedPosition": saved["position"], "appliedRotation": saved["rotation"], "exactAppliedPosition": True, "exactAppliedRotation": True}
    rows = [row("pose_applied_before_physics", {"position": saved["position"], "rotation": saved["rotation"]}),
            row("saved_state_read", {"position": saved["position"], "rotation": saved["rotation"], "revision": 2}),
            row("readback_verified_before_physics", {"previousProcess": True, "writerProcessGuid": writer, "readerProcessGuid": reader})]
    stored = dict(copy.deepcopy(saved), diskPoseBits=float_map(saved))
    return seed, saved, first, second, stored, rows


class RejectionTests(unittest.TestCase):
    def test_real_path_fixture_accepts_without_hardware_claim(self):
        result = analyze_samples(fixture(), IDENTITY)
        self.assertEqual([x["state"] for x in result["ordered_states"]], ["Idle", "Walk", "Run", "Idle"])
        self.assertFalse(result["physical_keyboard_measured"])
        self.assertGreater(result["horizontal_travel"], .1)

    def test_injected_axes_cannot_be_relabelled_keyboard(self):
        rows = fixture()
        mutate_samples(rows, lambda d: d["input"].update(simulated=True))
        with self.assertRaisesRegex(Rejected, "Simulated"):
            analyze_samples(rows, IDENTITY)

    def test_root_motion_without_local_animation_rejected(self):
        rows = fixture()
        bones = copy.deepcopy(rows[1]["data"]["animator"]["bones"])
        mutate_samples(rows, lambda d: d["animator"].update(bones=bones))
        with self.assertRaisesRegex(Rejected, "Local skeleton"):
            analyze_samples(rows, IDENTITY)

    def test_static_clip_label_without_time_progress_rejected(self):
        rows = fixture()
        mutate_samples(rows, lambda d: d["animator"]["layers"][0].update(normalizedTime=.2))
        with self.assertRaisesRegex(Rejected, "time did not advance"):
            analyze_samples(rows, IDENTITY)

    def test_walk_name_on_wrong_original_state_rejected(self):
        rows = fixture()
        mutate_samples(rows, lambda d: d["animator"]["layers"][0].update(fullPathHash=123))
        with self.assertRaisesRegex(Rejected, "Missing ordered stable state"):
            analyze_samples(rows, IDENTITY)

    def test_same_name_replacement_controller_rejected(self):
        rows = fixture()
        rows[0]["data"]["controller"]["sourceInstanceId"] = 999
        with self.assertRaisesRegex(Rejected, "identity differs"):
            analyze_samples(rows, IDENTITY)

    def test_wrong_dominant_blend_clip_rejected(self):
        rows = fixture()
        mutate_samples(rows, lambda d: d["animator"]["layers"][0]["clips"][0].update(name="Female_Idle_Base", instanceId=20))
        with self.assertRaisesRegex(Rejected, "Missing ordered stable state: Walk"):
            analyze_samples(rows, IDENTITY)

    def test_unity_axes_must_equal_motor_axes(self):
        rows = fixture()
        rows[7]["data"]["input"]["unityAxes"]["y"] = 0
        with self.assertRaisesRegex(Rejected, "Motor axes differ"):
            analyze_samples(rows, IDENTITY)

    def test_key_release_is_required(self):
        rows = fixture()
        mutate_samples(rows, lambda d: d["input"]["keyUp"].update(w=False))
        with self.assertRaisesRegex(Rejected, "release observed"):
            analyze_samples(rows, IDENTITY)

    def test_teleport_between_motor_steps_rejected(self):
        rows = fixture()
        rows[8]["data"]["positionBefore"]["x"] += .1
        rows[8]["data"]["positionAfter"]["x"] += .1
        with self.assertRaisesRegex(Rejected, "outside observed CC"):
            analyze_samples(rows, IDENTITY)

    def test_proof_boolean_cannot_replace_samples(self):
        rows = [value for value in fixture() if value["kind"] != "locomotion_sample"]
        rows.append(row("claimed_hardware_keyboard_passed", {"passed": True}))
        with self.assertRaisesRegex(Rejected, "Insufficient per-frame"):
            analyze_samples(rows, IDENTITY)

    def test_animator_disabled_is_not_playback(self):
        rows = fixture()
        mutate_samples(rows, lambda d: d["animator"].update(enabled=False))
        with self.assertRaisesRegex(Rejected, "Animator was not running"):
            analyze_samples(rows, IDENTITY)

    def test_nonfinite_evidence_rejected(self):
        rows = fixture()
        rows[5]["data"]["positionAfter"]["x"] = float("nan")
        with self.assertRaisesRegex(Rejected, "Nonfinite"):
            analyze_samples(rows, IDENTITY)

    def test_commands_need_same_frame_actual_keydown(self):
        rows = fixture()
        result = analyze_samples(rows, IDENTITY)
        self.assertEqual(check_commands(rows, result["samples_private"])["revision"], 2)
        [value for value in rows if value["kind"] == "keyboard_command"][-1]["data"]["GetKeyDown"] = False
        with self.assertRaisesRegex(Rejected, "observed Unity key down"):
            check_commands(rows, result["samples_private"])

    def test_command_and_save_agreeing_on_wrong_pose_rejected(self):
        rows = fixture()
        result = analyze_samples(rows, IDENTITY)
        [value for value in rows if value["kind"] == "keyboard_command"][-1]["data"]["position"] = position()
        rows[-1]["data"]["position"] = position()
        with self.assertRaisesRegex(Rejected, "same-frame actual CC Transform"):
            check_commands(rows, result["samples_private"])

    def test_only_recorded_negative_zero_becomes_positive_zero(self):
        rows = fixture()
        for value in rows:
            if value["frame"] == 19 and value["kind"] in {"save_pose_canonicalized", "save_roundtrip_verified", "save_completed"}:
                value["data"]["sourcePoseBits"]["rotation.z"] = -(2**31)
                value["data"]["zeroSignNormalizations"] = 1
        result = analyze_samples(rows, IDENTITY)
        saved = check_commands(rows, result["samples_private"])
        self.assertEqual(saved["_save_analysis"]["zero_sign_normalizations"], 1)
        self.assertFalse(saved["_save_analysis"]["raw_negative_zero_sign_bits_preserved"])

    def test_nonzero_one_ulp_canonicalization_is_rejected(self):
        rows = fixture()
        canonical = [value for value in rows if value["kind"] == "save_pose_canonicalized"][-1]
        canonical["data"]["canonicalPoseBits"]["position.x"] += 1
        result = analyze_samples(rows, IDENTITY)
        with self.assertRaisesRegex(Rejected, "changed a nonzero bit"):
            check_commands(rows, result["samples_private"])

    def test_disk_one_ulp_difference_is_rejected(self):
        rows = fixture()
        verified = [value for value in rows if value["kind"] == "save_roundtrip_verified"][-1]
        verified["data"]["diskPoseBits"]["position.x"] += 1
        result = analyze_samples(rows, IDENTITY)
        with self.assertRaisesRegex(Rejected, "not exactly equal"):
            check_commands(rows, result["samples_private"])

    def test_false_zero_normalization_count_is_rejected(self):
        rows = fixture()
        canonical = [value for value in rows if value["kind"] == "save_pose_canonicalized"][-1]
        canonical["data"]["zeroSignNormalizations"] = 1
        result = analyze_samples(rows, IDENTITY)
        with self.assertRaisesRegex(Rejected, "normalization count/policy differs"):
            check_commands(rows, result["samples_private"])

    def test_save_must_not_modify_actor_to_canonicalize_zero(self):
        rows = fixture()
        canonical = [value for value in rows if value["kind"] == "save_pose_canonicalized"][-1]
        canonical["data"]["actorTransformModified"] = True
        result = analyze_samples(rows, IDENTITY)
        with self.assertRaisesRegex(Rejected, "altered the actual actor"):
            check_commands(rows, result["samples_private"])

    def test_extra_save_without_command_is_never_called_keyboard(self):
        rows = fixture()
        save_kinds = {"save_pose_canonicalized", "save_roundtrip_verified", "save_completed"}
        extra = copy.deepcopy([value for value in rows if value["frame"] == 18 and value["kind"] in save_kinds])
        for value in extra:
            value["frame"], value["real"] = 17, 17/60
        for value in rows:
            if value["kind"] == "save_completed":
                value["data"]["revision"] += 1
        insertion = next(index for index, value in enumerate(rows) if value["kind"] == "keyboard_command")
        rows[insertion:insertion] = extra
        analyzed = analyze_samples(rows, IDENTITY)
        result = check_commands(rows, analyzed["samples_private"])["_save_analysis"]
        self.assertEqual(result["keyboard_command_saves"], 2)
        self.assertEqual(result["unattributed_saves"], 1)
        self.assertEqual(result["saves"][0]["attribution"], "unattributed-no-keyboard-command")
        self.assertIsNone(result["saves"][0]["key"])
        self.assertEqual(result["saves"][0]["revision"], 1)

    def test_unfocused_pure_idle_is_audited_and_excluded(self):
        rows = fixture()
        for value in rows:
            if value["kind"] == "locomotion_sample" and value["frame"] < 2:
                value["data"]["input"]["focused"] = False
        result = analyze_samples(rows, IDENTITY)
        self.assertEqual(result["observed_samples_total"], 20)
        self.assertEqual(result["samples"], 18)
        self.assertEqual(result["excluded_unfocused_idle_samples"], 2)
        self.assertEqual(result["ordered_states"][0]["first_frame"], 2)

    def test_any_unfocused_positive_input_is_rejected(self):
        rows = fixture()
        rows[7]["data"]["input"]["focused"] = False
        with self.assertRaisesRegex(Rejected, "Unfocused positive input"):
            analyze_samples(rows, IDENTITY)

    def test_focus_gaps_do_not_merge_short_playback_windows(self):
        rows = fixture()
        [value for value in rows if value["kind"] == "locomotion_sample" and value["frame"] == 2][0]["data"]["input"]["focused"] = False
        with self.assertRaises(Rejected):
            analyze_samples(rows, IDENTITY)

    def test_os_injection_never_claims_physical_keyboard(self):
        result = origin_scope({"source": "os-sendinput", "target_pid": 42, "all_keys_released": True}, 42)
        self.assertTrue(result["os_injection_declared"])
        self.assertFalse(result["os_injection_observed"])
        self.assertFalse(result["physical_keyboard_attested"])
        self.assertFalse(result["physical_keyboard_measured"])

    def test_os_injection_requires_successful_correlated_api_intervals(self):
        actions = [{"key": key, "edge": edge, "requested_inputs": 1, "sent_inputs": 1,
                    "started_utc": "2026-10-31T00:00:00Z", "finished_utc": "2026-10-31T00:00:00Z"}
                   for key, edge in (("w", "down"), ("w", "up"), ("shift", "down"), ("shift", "up"), ("f5", "down"), ("f6", "down"))]
        receipt = {"source": "os-sendinput", "backend": "Win32.SendInput", "target_pid": 42, "all_keys_released": True, "actions": actions}
        self.assertTrue(origin_scope(receipt, 42, fixture())["os_injection_observed"])
        receipt["actions"][0]["sent_inputs"] = 0
        with self.assertRaisesRegex(Rejected, "did not send all"):
            origin_scope(receipt, 42, fixture())

    def test_no_receipt_means_unspecified_not_physical(self):
        result = origin_scope(None, 42)
        self.assertEqual(result["source"], "undeclared")
        self.assertFalse(result["physical_keyboard_attested"])

    def test_physical_origin_requires_explicit_user_attestation(self):
        with self.assertRaisesRegex(Rejected, "lacks user attestation"):
            origin_scope({"source": "physical-user", "target_pid": 42, "all_keys_released": True}, 42)

    def test_receipt_must_target_actual_process(self):
        with self.assertRaisesRegex(Rejected, "another process"):
            origin_scope({"source": "os-sendinput", "target_pid": 4, "all_keys_released": True}, 42)

    def test_common_unity_launcher_does_not_prove_same_runtime(self):
        first = {"executable_sha256": "a"*64, "assembly_path": "build1/Assembly-CSharp.dll", "assembly_sha256": "b"*64}
        second = {"executable_sha256": "a"*64, "assembly_path": "build2/Assembly-CSharp.dll", "assembly_sha256": "c"*64}
        with self.assertRaisesRegex(Rejected, "different Assembly-CSharp"):
            runtime_code_identity(first, second)
        second["assembly_sha256"] = first["assembly_sha256"]
        self.assertEqual(runtime_code_identity(first, second), "b"*64)

    def test_independent_v1_save_survives_new_process(self):
        result = check_save(*save_fixture())
        self.assertTrue(result["fresh_process_readback"])
        self.assertTrue(result["applied_position_bit_exact"])

    def test_old_json_nonpose_data_cannot_disappear(self):
        values = list(save_fixture())
        values[1]["inventory"] = []
        with self.assertRaisesRegex(Rejected, "Retained original field differs: inventory"):
            check_save(*values)

    def test_saved_actual_pose_cannot_be_replaced_by_seed_pose(self):
        values = list(save_fixture())
        values[4]["position"]["x"] = 0
        with self.assertRaisesRegex(Rejected, "Saved/read float32 position differs"):
            check_save(*values)

    def test_restart_must_have_new_runtime_identity(self):
        values = list(save_fixture())
        values[3]["processGuid"] = values[2]["processGuid"]
        with self.assertRaisesRegex(Rejected, "not a new runtime process"):
            check_save(*values)

    def test_readback_exact_flags_are_recomputed(self):
        values = list(save_fixture())
        values[3]["exactAppliedPosition"] = False
        with self.assertRaisesRegex(Rejected, "exactness flags differ"):
            check_save(*values)


if __name__ == "__main__":
    unittest.main(verbosity=2)
