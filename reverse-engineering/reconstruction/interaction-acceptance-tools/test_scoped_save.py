"""Synthetic tests for preserving scope and exact save/cold-read evidence."""
import copy
import unittest

from test_verify_interaction import IDENTITY, controlled_fixture, fixture, row, samples, selected
from verify_interaction import Rejected, analyze_events, check_cold, check_saves, composite_scope, pose_bits


class CompositeScopeTests(unittest.TestCase):
    def pair(self):
        natural_rows = fixture()
        for value in samples(natural_rows)[3:13]:
            for field in ("axes", "unityAxes", "resolvedAxes"):
                value["data"][field] = {"x": 0, "y": 0}
        natural = analyze_events(natural_rows, IDENTITY, scoped=True)
        control_rows = controlled_fixture()
        for value in control_rows:
            value["processGuid"] = "2" * 32
        control = analyze_events(control_rows, IDENTITY, controlled=True)
        for result, pid, origin in ((natural, 12, "physical-user-attestation"), (control, 13, "simulated-controlled")):
            result.update(lifecycle={"pid": pid, "assembly_sha256": "a" * 64}, input_origin={"classification": origin}, artifacts={"identity": {"sha256": "b" * 64}, "config": {"path": "synthetic.json", "sha256": "c" * 64}})
        return natural, control

    def test_composite_preserves_failed_single_process_gate(self):
        natural, control = self.pair()
        result = composite_scope(natural, control)
        self.assertTrue(result["accepted"])
        self.assertFalse(result["single_process_full_chain_accepted"])
        self.assertFalse(natural["passed"])
        self.assertEqual(natural["unmet_single_process_requirements"][0]["observed_samples"], 0)

    def test_composite_cannot_join_different_managed_code(self):
        natural, control = self.pair()
        control["lifecycle"]["assembly_sha256"] = "d" * 64
        with self.assertRaisesRegex(Rejected, "different managed implementations"):
            composite_scope(natural, control)

    def test_composite_cannot_join_different_original_contract(self):
        natural, control = self.pair()
        control["artifacts"]["identity"]["sha256"] = "d" * 64
        with self.assertRaisesRegex(Rejected, "different original identity"):
            composite_scope(natural, control)

    def test_composite_cannot_launder_controlled_f_to_actual(self):
        natural, control = self.pair()
        control["actual_unity_f_accepted"] = True
        with self.assertRaisesRegex(Rejected, "honestly scoped"):
            composite_scope(natural, control)

    def test_composite_cannot_excuse_another_failed_gate(self):
        natural, control = self.pair()
        natural["unmet_single_process_requirements"].append({"gate": "wrong-original-event"})
        with self.assertRaisesRegex(Rejected, "cannot excuse another"):
            composite_scope(natural, control)


class SaveColdTests(unittest.TestCase):
    def setup_evidence(self):
        rows = fixture()
        saved = None
        for frame, key, revision in ((18, "F5", 1), (19, "F6", 2)):
            data = samples(rows)[frame]["data"]
            data["keyDown"] = {"f": False, key.lower(): True}
            pose = {"position": copy.deepcopy(data["positionAfter"]), "rotation": copy.deepcopy(data["rotation"])}
            bit_map = dict(pose_bits(pose), bodyPaintRemaining=1065353216)
            common = {"sourcePoseBits": bit_map.copy(), "canonicalPoseBits": bit_map.copy(), "zeroSignNormalizations": 0}
            rows.extend([row("keyboard_command", dict(pose, key=key, GetKeyDown=True, inputSource="unity-legacy", simulated=False, focused=True), frame), row("save_pose_canonicalized", dict(common, actorTransformModified=False), frame), row("save_roundtrip_verified", dict(common, diskPoseBits=bit_map.copy(), exactCanonicalFloatBits=True, sameSceneAndWriter=True, mismatches=""), frame), row("save_completed", dict(pose, **common, diskPoseBits=bit_map.copy(), revision=revision, saveSha256=str(revision) * 64, processGuid="1" * 32, sceneKey="SyntheticScene"), frame)])
            saved = dict(pose, revision=revision, savedProcessGuid="1" * 32, schemaVersion=1, fileKind="ReconstructedManakaSave", sceneKey="SyntheticScene", inventory=[{"id": 12345, "count": 5}], sourceSaveSha256="d" * 64)
        rows.sort(key=lambda value: value["frame"])
        result = analyze_events(rows, IDENTITY)
        result["lifecycle"] = {"pid": 12, "assembly_sha256": "a" * 64}
        result["save_verification"] = check_saves(rows, result, saved, "2" * 64)
        cold = [row("saved_state_read", dict(position=saved["position"], rotation=saved["rotation"], revision=2, savedProcessGuid="1" * 32, sourceSaveSha256="d" * 64, sceneKey="SyntheticScene"), 0), row("pose_applied_before_physics", dict(position=saved["position"], rotation=saved["rotation"], sceneKey="SyntheticScene"), 1), row("readback_verified_before_physics", dict(position=saved["position"], rotation=saved["rotation"], saveSha256="2" * 64, sceneKey="SyntheticScene", previousProcess=True, writerProcessGuid="1" * 32, readerProcessGuid="2" * 32, exactAppliedPosition=True, exactAppliedRotation=True), 1)]
        cold = copy.deepcopy(cold)
        for value in cold:
            value["processGuid"] = "2" * 32
        proof = {"processGuid": "2" * 32, "processId": 13, "completed": True, "passed": True, "saveSha256": "2" * 64, "unexpectedEngineErrors": 0}
        start = {"pid": 13, "assembly_sha256": "a" * 64, "started_utc": "2026-10-30T23:59:59Z"}
        end = {"pid": 13, "process_exited": True, "exit_code": 0, "exited_utc": "2026-10-31T00:00:01Z"}
        return rows, result, saved, cold, proof, start, end

    def test_save_bytes_and_cold_pose_do_not_claim_unobserved_inventory(self):
        _, result, saved, cold, proof, start, end = self.setup_evidence()
        verified = check_cold(cold, proof, start, end, result, saved, "2" * 64)
        self.assertTrue(verified["same_saved_bytes_verified"])
        self.assertFalse(verified["cold_in_memory_inventory_quantity_observed"])

    def test_saved_inventory_must_include_exact_pickup_delta(self):
        rows, result, saved, *_ = self.setup_evidence()
        saved["inventory"][0]["count"] = 6
        with self.assertRaisesRegex(Rejected, "Persisted pickup inventory"):
            check_saves(rows, result, saved, "2" * 64)

    def test_saved_pose_cannot_change_a_nonzero_bit(self):
        rows, result, saved, *_ = self.setup_evidence()
        selected(rows, "save_pose_canonicalized")[0]["data"]["canonicalPoseBits"]["position.x"] += 1
        with self.assertRaisesRegex(Rejected, "changed a nonzero float"):
            check_saves(rows, result, saved, "2" * 64)

    def test_save_command_cannot_replace_actual_key_edge(self):
        rows, result, saved, *_ = self.setup_evidence()
        samples(rows)[18]["data"]["keyDown"]["f5"] = False
        with self.assertRaisesRegex(Rejected, "Unity edge differ"):
            check_saves(rows, result, saved, "2" * 64)

    def test_cold_read_must_bind_same_saved_bytes(self):
        _, result, saved, cold, proof, start, end = self.setup_evidence()
        proof["saveSha256"] = "f" * 64
        with self.assertRaisesRegex(Rejected, "same saved bytes"):
            check_cold(cold, proof, start, end, result, saved, "2" * 64)

    def test_cold_pose_must_be_component_exact(self):
        _, result, saved, cold, proof, start, end = self.setup_evidence()
        selected(cold, "pose_applied_before_physics")[0]["data"]["position"]["x"] += .01
        with self.assertRaisesRegex(Rejected, "component-exact"):
            check_cold(cold, proof, start, end, result, saved, "2" * 64)


if __name__ == "__main__":
    unittest.main()
