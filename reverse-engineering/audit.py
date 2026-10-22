"""Audit saved reconstruction evidence and optionally hash the original inputs."""
import argparse
from datetime import datetime, timezone
import hashlib
import gzip
import runpy
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent


def read(path):
    return json.loads(path.read_text(encoding="utf-8-sig"))


def digest(path):
    value = hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(4 * 1024 * 1024), b""):
            value.update(chunk)
    return value.hexdigest()


def check(condition, message):
    if not condition:
        raise ValueError(message)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--inputs", action="store_true", help="Also verify original files and the materialized plaintext")
    parser.add_argument("--write-index", action="store_true", help="Write the current verified artifact fingerprint index")
    args = parser.parse_args()
    identity = read(ROOT / "salt/evidence/artifact-identity.json")
    runtime_dir = ROOT / "runtime/npc-event-timing"
    runtime = read(runtime_dir / "manifest.json")
    check(runtime["trials"] == 60 and runtime["session_closed"] and runtime["target_exited"], "Runtime matrix or cleanup incomplete")
    for source in runtime["sources"]:
        check(digest(runtime_dir / source["path"]) == source["sha256"], "Runtime instrument source differs")
    for output in runtime["outputs"]:
        path = runtime_dir / output["path"]
        check(digest(path) == output["sha256"], "Runtime compressed log differs")
        payload = gzip.decompress(path.read_bytes())
        check(len(payload) == output["uncompressed_bytes"] and hashlib.sha256(payload).hexdigest() == output["uncompressed_sha256"], "Runtime raw log differs")
    runtime_inputs = {r["relative_path"]: r["sha256"] for r in runtime["inputs"]}
    check(runtime_inputs["GameAssembly.dll"] == identity["native_sha256"] and
          runtime_inputs["SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat"] == identity["metadata_sha256"], "Runtime build identity differs")
    runtime_analysis = runpy.run_path(str(runtime_dir / "analyze.py"))
    measured = runtime_analysis["analyze"](runtime_analysis["read_log"](runtime_dir / "fixture.jsonl.gz"), read(runtime_dir / "rea-runtime.json"))
    saved = read(runtime_dir / "results.json")
    measured_inputs = saved.pop("inputs")
    check(measured == saved, "Runtime measurement summary differs")
    check(all(digest(runtime_dir / name) == fingerprint for name, fingerprint in measured_inputs.items()), "Runtime measurement input differs")
    producer_dir = ROOT / "runtime/time-stop-producer"
    producer_runtime = read(producer_dir / "manifest.json")
    check(producer_runtime["trials"] == 32 and producer_runtime["session_closed"] and producer_runtime["target_exited"], "Producer runtime matrix/cleanup incomplete")
    for source in producer_runtime["sources"]:
        check(digest(producer_dir / source["path"]) == source["sha256"], "Producer instrument source differs")
    for output in producer_runtime["outputs"]:
        path = producer_dir / output["path"]
        check(digest(path) == output["sha256"], "Producer compressed log differs")
        payload = gzip.decompress(path.read_bytes())
        check(len(payload) == output["uncompressed_bytes"] and hashlib.sha256(payload).hexdigest() == output["uncompressed_sha256"], "Producer raw log differs")
    producer_analysis = runpy.run_path(str(producer_dir / "analyze.py"))
    saved_producer = read(producer_dir / "results.json")
    producer_measurement_inputs = saved_producer.pop("input_sha256")
    check(producer_analysis["analyze"]() == saved_producer, "Producer measurements differ")
    check(all(digest(producer_dir / name) == fingerprint for name, fingerprint in producer_measurement_inputs.items()), "Producer measurement input differs")
    check(producer_runtime["inputs"][:4] == [{**entry, "fixture_path": str(Path(producer_runtime["fixture_root"]) / entry["relative_path"])} for entry in runtime["inputs"][:4]], "Producer native inputs differ from prior pinned build")
    runtime_records = {runtime_dir / "rea-runtime.json": runtime, producer_dir / "rea-runtime.json": producer_runtime}
    natural_dir = ROOT / "runtime/natural-time-stop"
    natural_runtime = read(natural_dir / "manifest.json")
    for source in natural_runtime["sources"]:
        check(digest(ROOT / source["path"]) == source["sha256"], "Natural checkpoint source differs")
    for output in natural_runtime["outputs"]:
        source = natural_dir / output["path"]
        check(digest(source) == output["sha256"], "Natural checkpoint log differs")
        raw = gzip.decompress(source.read_bytes())
        check(len(raw) == output["uncompressed_bytes"] and hashlib.sha256(raw).hexdigest() == output["uncompressed_sha256"], "Natural checkpoint raw log differs")
    natural_analysis = runpy.run_path(str(natural_dir / "analyze.py"))
    check(natural_analysis["analyze"]() == read(natural_dir / "results.json"), "Natural checkpoint measurements differ")
    check(natural_runtime["natural_validation_complete"] == read(natural_dir / "results.json")["natural_validation_complete"], "Natural coverage flag differs from measurements")
    natural_sessions = {s["session_id"]: s for s in natural_runtime["sessions"]}
    notification_dir = ROOT / "runtime/natural-notification"
    notification_runtime = read(notification_dir / "manifest.json")
    for source in notification_runtime["sources"]:
        check(digest(ROOT / source["path"]) == source["sha256"], "Notification source differs")
    for output in notification_runtime["outputs"]:
        path = notification_dir / output["path"]
        check(digest(path) == output["sha256"], "Notification log differs")
        payload = gzip.decompress(path.read_bytes())
        check(len(payload) == output["uncompressed_bytes"] and hashlib.sha256(payload).hexdigest() == output["uncompressed_sha256"], "Notification raw log differs")
    notification_analysis = runpy.run_path(str(notification_dir / "analyze.py"))
    check(notification_analysis["analyze"]() == read(notification_dir / "results.json"), "Notification measurements differ")
    dependency = notification_runtime["previous_checkpoint"]
    check(digest(ROOT / dependency["path"]) == dependency["sha256"], "Previous natural checkpoint differs")
    generation_dir = ROOT / "runtime/natural-event-generation"
    generation_runtime = read(generation_dir / "manifest.json")
    for source in generation_runtime["sources"]:
        check(digest(ROOT / source["path"]) == source["sha256"], "Generation source differs")
    for output in generation_runtime["outputs"]:
        path = generation_dir / output["path"]
        check(digest(path) == output["sha256"], "Generation log differs")
        payload = gzip.decompress(path.read_bytes())
        check(len(payload) == output["uncompressed_bytes"] and hashlib.sha256(payload).hexdigest() == output["uncompressed_sha256"], "Generation raw log differs")
        bounds = output["selection"]
        check(all(bounds["min_frame"] <= json.loads(line)["frame"] <= bounds["max_frame"] for line in payload.splitlines()), "Generation log window differs")
    generation_analysis = runpy.run_path(str(generation_dir / "analyze.py"))
    check(generation_analysis["analyze"]() == read(generation_dir / "results.json"), "Generation measurements differ")
    dependency = generation_runtime["previous_checkpoint"]
    check(digest(ROOT / dependency["path"]) == dependency["sha256"], "Previous notification checkpoint differs")
    if args.inputs:
        abi = read(generation_dir / "abi.json")
        check(digest(Path(abi["source_path"])) == abi["source_sha256"], "Animator binding ABI source differs")
    observed_runtime_records = {natural_dir / "rea-runtime.json": natural_runtime, notification_dir / "rea-runtime.json": notification_runtime,
                               generation_dir / "rea-runtime.json": generation_runtime}
    coverage_dir = ROOT / "runtime/natural-event-coverage"
    coverage_runtime = read(coverage_dir / "manifest.json")
    for source in coverage_runtime["sources"]:
        check(digest(ROOT / source["path"]) == source["sha256"], "Coverage source differs")
    for output in coverage_runtime["outputs"]:
        path = coverage_dir / output["path"]
        check(digest(path) == output["sha256"], "Coverage log differs")
        payload = gzip.decompress(path.read_bytes())
        check(len(payload) == output["uncompressed_bytes"] and hashlib.sha256(payload).hexdigest() == output["uncompressed_sha256"], "Coverage raw log differs")
        bounds = output["selection"]
        check(all(bounds["min_frame"] <= json.loads(line)["frame"] <= bounds["max_frame"] for line in payload.splitlines()), "Coverage window differs")
    coverage_result = runpy.run_path(str(coverage_dir / "analyze.py"))["analyze"]()
    check(coverage_result == read(coverage_dir / "results.json"), "Coverage measurements differ")
    check(coverage_result["all_sources_finished"] and coverage_runtime["observation_complete"] and coverage_runtime["natural_only"], "Coverage tail incomplete")
    check(not coverage_result["errors"] and not coverage_result["native_script_errors"], "Coverage probe errors")
    check(all(s["closed_by_operator"] for s in coverage_runtime["sessions"]), "Coverage session not closed")
    for key in ["previous_checkpoint", "algorithm_dependency"]:
        dependency = coverage_runtime[key]
        check(digest(ROOT / dependency["path"]) == dependency["sha256"], "Coverage dependency differs")
    observed_runtime_records[coverage_dir / "rea-runtime.json"] = coverage_runtime
    asset = read(ROOT / "assets/resources-keydata.json")
    check(runtime_inputs["SecretFlasherManaka_Data/data.unity3d"] == asset["source_sha256"], "Runtime resources differ")
    recovered = read(ROOT / "salt/evidence/recovered-crypto.json")
    decryption = read(ROOT / "salt/evidence/decryption.json")
    verification = read(ROOT / "salt/evidence/decryption-verification.json")
    summary = read(ROOT / "salt/symbols/index-summary.json")
    object_record = asset["guid_object"]
    check(hashlib.sha256(bytes.fromhex(object_record["raw_hex"])).hexdigest() == object_record["sha256"], "KeyData raw-byte fingerprint mismatch")
    fields = object_record["parsed_fields"]
    check(fields["bytes_consumed"] == object_record["size"] == fields["object_size"], "KeyData schema did not consume the complete object")
    check(fields["keydataGUID"] == recovered["keydata_guid"], "Recovered GUID differs from original resource fields")
    check(str(fields["_values"][0]["hash"]) == recovered["salt_text"], "Recovered salt differs from original resource hash")
    check(all(recovered["matches_user_baseline"].values()), "Independent reconstruction differs from supplied baseline")
    check(summary["native_sha256"] == recovered["native_sha256"] == identity["native_sha256"], "Native identity disagreement")
    check(summary["metadata_sha256"] == recovered["metadata_sha256"] == identity["metadata_sha256"], "Metadata identity disagreement")
    check(sum(summary["mapping_status"].values()) == summary["methods"], "Metadata coverage counts disagree")
    check(verification["source_ciphertext_sha256"] == decryption["source_sha256"], "Ciphertext verification identity mismatch")
    check(verification["plaintext_sha256"] == decryption["plaintext"]["sha256"], "Plaintext verification identity mismatch")
    check(verification["verified_blocks"] == decryption["block_count"], "Not every bundle block was verified")
    check(verification["verified_node_ranges"] == len(decryption["nodes"]), "Not every node range was verified")

    artifacts, observations = [], {}
    allowed_subjects = {identity["native_sha256"], identity["wrapper_sha256"]}
    for path in sorted(ROOT.rglob("*")):
        if not path.is_file() or any(part in (".cache", "__pycache__") for part in path.relative_to(ROOT).parts):
            continue
        if path.name == "evidence-index.json" or path.name.endswith((".stderr.log", ".pending.json")):
            continue
        artifacts.append({"path": path.relative_to(ROOT).as_posix(), "bytes": path.stat().st_size, "sha256": digest(path)})
        if path.suffix != ".json":
            continue
        value = read(path)
        records = value.get("records", []) if isinstance(value, dict) else []
        if isinstance(value, dict) and value.get("evidence_id"):
            records = [value]
        for record in records:
            if not isinstance(record, dict) or not record.get("evidence_id"):
                continue
            key = record["evidence_id"]
            subject = record.get("subject") or {}
            subject_hash = (subject.get("digest") or {}).get("sha256")
            if path in observed_runtime_records:
                selected_observation = observed_runtime_records[path]
                selected_sessions = {s["session_id"]: s for s in selected_observation["sessions"]}
                check(subject_hash is None and record["provider"]["id"] == "frida" and record["predicate_type"] == "rea.frida.instrumentation-observation", "Unexpected natural runtime provider")
                check(key in selected_observation["evidence_ids"] and record["parameters"]["session_id"] in selected_sessions, "Unexpected natural runtime session")
                result = record["normalized_result"]
                check(not result["messages_truncated"] or (path == coverage_dir / "rea-runtime.json" and coverage_result["capture_joins"]), "Natural checkpoint Evidence truncated without verified overlap")
                if record["operation"] == "load_frida_script":
                    source = Path(result["source_path"])
                    check(digest(source) == result["source_sha256"], "Natural Frida source differs")
                else:
                    session = selected_sessions[record["parameters"]["session_id"]]
                    check(record["operation"] == "frida_session_status" and result["pid"] == session["pid"] and result["state"] == session["state"], "Natural checkpoint process/session differs")
            elif path in runtime_records:
                selected_runtime = runtime_records[path]
                check(subject_hash is None and record["provider"]["id"] == "frida" and
                      record["predicate_type"] == "rea.frida.instrumentation-observation", "Unexpected runtime Evidence provider/identity")
                check(key in selected_runtime["evidence_ids"] and record["parameters"]["session_id"] == selected_runtime["frida_session_id"], "Unexpected runtime session")
                result = record["normalized_result"]
                check(not result["messages_truncated"], "Runtime Evidence truncated")
                if record["operation"] == "load_frida_script":
                    check(digest(path.parent / Path(result["source_path"]).name) == result["source_sha256"], "Frida source fingerprint differs")
                else:
                    check(record["operation"] == "frida_session_status" and result["pid"] == selected_runtime["pid"] and result["state"] == "detached", "Runtime target/status differs")
                    ready = next(m["payload"] for m in result["messages"] if m.get("payload", {}).get("kind") == "observer_ready")
                    check(Path(ready["path"]) == Path(selected_runtime["fixture_root"]) / "GameAssembly.dll", "Observed native module path differs")
            else:
                check(subject_hash in allowed_subjects, f"Unexpected evidence subject in {path}")
            canonical = json.dumps(record, sort_keys=True, ensure_ascii=False)
            if key in observations:
                check(observations[key]["canonical"] == canonical, f"Conflicting copies of {key}")
            else:
                observations[key] = {"canonical": canonical, "operation": record["operation"], "subject_sha256": subject_hash}
    check(all(key in observations for selected in runtime_records.values() for key in selected["evidence_ids"]), "Missing runtime observations")
    for key in ("password_map_initializer_evidence", "password_map_constructor_evidence", "password_decoder_evidence"):
        check(recovered[key] in observations, f"Missing password reconstruction evidence: {key}")
    run_paths = sorted((ROOT / "salt/evidence").glob("*/run.json"))
    runs = [read(path) for path in run_paths]
    for run in runs:
        check(run["success"] and not run.get("close_error") and not run.get("transport_close_error"), "A required REA batch did not complete cleanly")
        check(all(item["evidence_id"] in observations for item in run["functions"]), "Batch references missing evidence")
    loading = read(ROOT / "salt/evidence/loading-chain.json")
    declarations = read(ROOT / "salt/symbols/loading-declarations.json")
    check(loading["native_sha256"] == identity["native_sha256"] and loading["metadata_sha256"] == identity["metadata_sha256"], "Loading chain identity mismatch")
    check(all(m["evidence_id"] in observations for m in loading["methods"]), "Loading chain references missing native evidence")
    check(all(m["evidence_id"] in observations for m in loading["native_only_procedures"]), "Loading chain references missing native-only evidence")
    check(len(loading["title_asset_requests"]) == 25 and all(r["label"] == "models" for r in loading["title_asset_requests"]), "Title resource requests differ")
    prefab = declarations["original_resource_prefab"]
    for name in ("gameobject", "encrypter_core_instance"):
        record = prefab[name]
        check(hashlib.sha256(bytes.fromhex(record["raw_hex"])).hexdigest() == record["sha256"], "Prefab raw-byte fingerprint mismatch")
    check(prefab["encrypter_core_instance"]["fields"]["keyData"]["pointer"] == {"file_id": 0, "path_id": 61594}, "Prefab KeyData reference differs")
    check(prefab["source_sha256"] == asset["source_sha256"], "Prefab bundle identity mismatch")
    followup = read(ROOT / "salt/evidence/asset-followup.json")
    check(followup["native_sha256"] == identity["native_sha256"] and followup["metadata_sha256"] == identity["metadata_sha256"], "Asset followup identity mismatch")
    check(len(followup["requests"]) == 25, "Incomplete title callback map")
    check(all(r["evidence_id"] in observations for r in followup["rea_observations"]), "Asset followup references missing native observations")
    check(all(r["callback_evidence_id"] in observations and r["verified_consumer_methods"] for r in followup["requests"]), "Callback or consumer evidence missing")
    check(all(c["evidence_id"] in observations for r in followup["requests"] for c in r["verified_consumer_methods"]), "Consumer references missing observations")
    check(followup["interface_dispatch"]["method_id"] == 76228 and followup["request_get_result_dispatch"]["method_id"] == 78749, "Unexpected interface dispatch target")
    scenes = read(ROOT / "salt/evidence/scene-chain.json")
    scene_assets = read(ROOT / "assets/scene-inventory.json")
    check(scenes["native_sha256"] == identity["native_sha256"] and scenes["metadata_sha256"] == identity["metadata_sha256"], "Scene chain identity mismatch")
    check(all(m["evidence_id"] in observations for m in scenes["methods"]), "Scene chain references missing native observations")
    check(sum(m["new_this_round"] for m in scenes["methods"]) == scenes["new_observations"], "Scene observation count differs")
    check(scene_assets["source"]["sha256"] == asset["source_sha256"], "Scene asset bundle differs")
    build_settings = scene_assets["build_settings"]
    check(hashlib.sha256(bytes.fromhex(build_settings["raw_hex"])).hexdigest() == build_settings["source"]["sha256"], "BuildSettings bytes differ")
    check(build_settings["scene_count"] == 10, "Unexpected scene configuration")
    player = read(ROOT / "salt/evidence/player-chain.json")
    player_assets = read(ROOT / "assets/player-config.json")
    check(digest(ROOT / player["configuration_dependency"]["path"]) == player["configuration_dependency"]["sha256"], "Player configuration dependency differs")
    check(player["native_sha256"] == identity["native_sha256"] and player["metadata_sha256"] == identity["metadata_sha256"], "Player chain identity mismatch")
    check(all(m["evidence_id"] in observations for m in player["methods"]), "Player chain references missing native evidence")
    check(sum(m["new_this_round"] for m in player["methods"]) == player["new_observations"], "Player observation count differs")
    check(player_assets["source_bundle"]["sha256"] == asset["source_sha256"], "Player asset bundle differs")
    check(player_assets["decrypted_models_source"]["sha256"] == decryption["plaintext"]["sha256"], "Player prefab source differs")
    for source in [player_assets["parser"], *player_assets["reused_parsers"]]:
        check(digest(Path(source["path"])) == source["sha256"], "Player parser fingerprint differs")
    check(len(player["direct_input_flag_assignments"]) >= 15, "Player input assignment map incomplete")
    check(player["jump_input_boundary"]["observed_store_expressions"] == ["0"], "Jump input boundary differs")
    bareta = read(ROOT / "salt/evidence/bareta-chain.json")
    bareta_assets = read(ROOT / "assets/bareta-config.json")
    check(bareta["native_sha256"] == identity["native_sha256"] and bareta["metadata_sha256"] == identity["metadata_sha256"], "Bareta chain identity mismatch")
    check(all(m["evidence_id"] in observations for m in bareta["methods"]), "Bareta chain references missing native evidence")
    check(sum(m["new_this_round"] for m in bareta["methods"]) == bareta["new_observations"], "Bareta observation count differs")
    for key in ("configuration_dependency", "state_configuration_dependency", "producer_and_animation_dependency"):
        dependency = bareta[key]
        check(digest(ROOT / dependency["path"]) == dependency["sha256"], "Bareta configuration dependency differs")
    check(bareta_assets["source_bundle"]["sha256"] == asset["source_sha256"], "Bareta asset bundle differs")
    for source in [bareta_assets["parser"], *bareta_assets["reused_parsers"]]:
        check(digest(Path(source["path"])) == source["sha256"], "Bareta parser fingerprint differs")
    for table in bareta_assets["tables"].values():
        check(table["end_of_object_verified"] and all(e["record"]["end_of_object_verified"] for e in table["entries"]), "Bareta configuration schema boundary differs")
    check({c["requested_player_state"] for c in bareta["literal_state_change_calls"]} == {0, 1, 2}, "Bareta selected transition excerpts differ")
    producer = read(ROOT / bareta["producer_and_animation_dependency"]["path"])
    check(producer["method"]["id"] == 15358 and producer["static_event_field"]["raw_offset"] == 40, "Unexpected discovery producer identity")
    check(producer["sad_animation_event"]["models_source"]["sha256"] == decryption["plaintext"]["sha256"], "Sad clip source differs")
    check(producer["bounded_animation_inventory"]["all_objects_consumed_to_eof"], "Clip event inventory is incomplete")
    animator = read(ROOT / "salt/evidence/animator-chain.json")
    wiring = read(ROOT / "assets/animator-wiring.json")
    npc_animation = read(ROOT / "assets/npc-animation-events.json")
    check(animator["native_sha256"] == identity["native_sha256"] and animator["metadata_sha256"] == identity["metadata_sha256"], "Animator native identity differs")
    check(all(m["evidence_id"] in observations for m in animator["methods"]), "Animator chain references missing native evidence")
    check(sum(m["new_this_round"] for m in animator["methods"]) == animator["new_observations"], "Animator observation count differs")
    for dependency in animator["asset_dependencies"]:
        check(digest(ROOT / dependency["path"]) == dependency["sha256"], "Animator asset dependency differs")
    for dependency in [*wiring["parser_sources"], *npc_animation["parser_sources"], wiring["npc_event_dependency"], wiring["sad_event_dependency"]]:
        check(digest(Path(dependency["path"])) == dependency["sha256"], "Animator parser/dependency fingerprint differs")
    check(wiring["sources"][0]["sha256"] == npc_animation["original_bundle"]["sha256"] == asset["source_sha256"], "Animator original bundle differs")
    check(wiring["sources"][1]["sha256"] == npc_animation["decrypted_models_source"]["sha256"] == decryption["plaintext"]["sha256"], "Animator models source differs")
    check(npc_animation["animation_clip_count"] == 357 and npc_animation["all_clip_objects_consumed_to_eof"], "Original clip inventory differs")
    check(len(npc_animation["target_clips"]) == 4 and len(npc_animation["linked_animators"]) == 10, "NPC serialized wiring differs")
    check(len(wiring["player_animators"]) == 6 and len(animator["native_parameter_hash_links"]) == 81, "Player wiring/hash link count differs")
    for controller in wiring["controllers"]:
        check(hashlib.sha256(bytes.fromhex(controller["raw_hex"])).hexdigest() == controller["source"]["sha256"], "Controller original bytes differ")
        check(controller["decoded"]["end_of_object_verified"] and controller["decoded"]["bytes_consumed"] == controller["source"]["object"]["size"], "Controller schema did not consume object")
    npc_model = read(ROOT / "salt/evidence/npc-model-chain.json")
    model_assets = read(ROOT / "assets/npc-model-wiring.json")
    check(npc_model["native_sha256"] == identity["native_sha256"] and npc_model["metadata_sha256"] == identity["metadata_sha256"], "NPC model native identity differs")
    check(all(m["evidence_id"] in observations for m in npc_model["methods"]), "NPC model chain references missing native evidence")
    check(sum(m["new_this_round"] for m in npc_model["methods"]) == npc_model["new_observations"], "NPC model observation count differs")
    for dependency in [*npc_model["asset_dependencies"], npc_model["component_registration_inventory"]["registration_dependency"]]:
        check(digest(ROOT / dependency["path"]) == dependency["sha256"], "NPC model dependency differs")
    for dependency in [*model_assets["parser_sources"], model_assets["npc_event_dependency"]]:
        check(digest(Path(dependency["path"])) == dependency["sha256"], "NPC model parser fingerprint differs")
    check(model_assets["original_bundle"]["sha256"] == asset["source_sha256"] and model_assets["models_bundle"]["sha256"] == decryption["plaintext"]["sha256"], "NPC model asset sources differ")
    check(len(model_assets["selected_nine_model_wiring"]) == 9 and not model_assets["casual1"]["in_selected_npc_component_model_fields"], "NPC model candidate set differs")
    check(model_assets["npc_manager"]["end_of_object_verified"] and model_assets["npc_component"]["end_of_object_verified"], "NPC model component schemas did not consume objects")
    component_inventory = npc_model["component_registration_inventory"]
    check(component_inventory["method_spec_count_scanned"] == 113283 and len(component_inventory["add_component_specs"]) == 61 and component_inventory["receiver_concrete_instantiation_count"] == 0, "Bounded AddComponent inventory differs")
    npc_fps = read(ROOT / "salt/evidence/npc-fps-chain.json")
    check(npc_fps["native_sha256"] == identity["native_sha256"] and npc_fps["metadata_sha256"] == identity["metadata_sha256"], "NPC FPS native identity differs")
    check(all(m["evidence_id"] in observations for m in npc_fps["methods"]), "NPC FPS references missing pseudocode")
    check(all(a["evidence_id"] in observations for a in npc_fps["rea_assembly_observations"]), "NPC FPS references missing assembly responses")
    check(sum(m["new_this_round"] for m in npc_fps["methods"]) == npc_fps["new_pseudocode_observations"], "NPC FPS pseudocode count differs")
    check(npc_fps["new_observations"] == npc_fps["new_pseudocode_observations"] + len(npc_fps["rea_assembly_observations"]), "NPC FPS total query count differs")
    check(npc_fps["new_nonempty_observations"] == npc_fps["new_pseudocode_observations"] + sum(a["nonempty"] for a in npc_fps["rea_assembly_observations"]), "NPC FPS nonempty response count differs")
    for dependency in [*npc_fps["dependencies"], npc_fps["instruction_dependency"]]:
        check(digest(ROOT / dependency["path"]) == dependency["sha256"], "NPC FPS dependency differs")
    fps_instructions = read(ROOT / npc_fps["instruction_dependency"]["path"])
    for source in (fps_instructions["decoder"], fps_instructions["parser"], fps_instructions["preparer"]):
        check(digest(Path(source["path"])) == source["sha256"], "NPC FPS instruction source fingerprint differs")
    check(fps_instructions["native"]["sha256"] == identity["native_sha256"], "NPC FPS instruction native source differs")
    check(npc_fps["notification_delay_constant"]["raw_hex"] == "9a99193f", "NPC discovery delay constant differs")
    time_stop = read(ROOT / "salt/evidence/time-stop-chain.json")
    natural_chain = read(ROOT / "salt/evidence/natural-chain.json")
    notification_chain = read(ROOT / "salt/evidence/notification-chain.json")
    check(notification_chain["native_sha256"] == identity["native_sha256"] and notification_chain["metadata_sha256"] == identity["metadata_sha256"], "Notification static identity differs")
    check(notification_chain["new_observations"] == 10 and all(m["evidence_id"] in observations for m in notification_chain["methods"]), "Notification static observations missing")
    check(natural_chain["native_sha256"] == identity["native_sha256"] and natural_chain["metadata_sha256"] == identity["metadata_sha256"], "Natural static identity differs")
    check(natural_chain["new_observations"] == 24 and all(m["evidence_id"] in observations for m in natural_chain["methods"]), "Natural static observations missing")
    check(time_stop["native_sha256"] == identity["native_sha256"] and time_stop["metadata_sha256"] == identity["metadata_sha256"], "TimeStop native identity differs")
    check(time_stop["new_observations"] == 16 and all(m["evidence_id"] in observations for m in time_stop["methods"]), "Missing TimeStop native observations")
    for name in ("xref_scan_dependency", "player_controller_dependency"):
        dependency = time_stop[name]
        check(digest(ROOT / dependency["path"]) == dependency["sha256"], "TimeStop dependency differs")
    stop_scan = read(ROOT / time_stop["xref_scan_dependency"]["path"])
    check(stop_scan["scan"]["unwind_ranges"] == 139898 and len(stop_scan["scan"]["candidates"]) == 9, "TimeStop candidate scan differs")
    check(digest(Path(stop_scan["parser"]["path"])) == stop_scan["parser"]["sha256"], "TimeStop scanner source differs")
    checked_inputs = []
    if args.inputs:
        original = Path(identity["original_directory"])
        paths = [(original / "GameAssembly.dll", identity["native_sha256"]),
                 (original / "SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat", identity["metadata_sha256"]),
                 (original / "BepInEx/interop/IKA9nt.Encrypter.dll", identity["wrapper_sha256"]),
                 (original / "SecretFlasherManaka_Data/data.unity3d", asset["source_sha256"]),
                 (Path(decryption["source"]), decryption["source_sha256"]),
                 (Path(decryption["plaintext"]["path"]), decryption["plaintext"]["sha256"])]
        known = {str(path).casefold() for path, _ in paths}
        supplements = [read(ROOT / "salt/symbols" / name) for name in
                      ("dispatch-metadata.json", "field-offsets.json", "instantiation-generics.json")]
        source_records = list(declarations["sources"])
        source_records.extend([scene_assets["stage_enum"]["source"], scene_assets["stage_enum"]["parser"]])
        source_records.extend(player_assets["wrapper_declarations"]["sources"])
        source_records.extend(bareta_assets["wrapper_declarations"]["sources"])
        source_records.extend(producer["sources"])
        source_records.extend(model_assets["wrapper_declarations"]["sources"])
        source_records.extend([model_assets["wrapper_attribute_observations"]["parser"], model_assets["wrapper_attribute_observations"]["source"]])
        for supplement in supplements:
            source_records.extend(supplement.get("sources", []))
            if supplement.get("parser_source"):
                source_records.append(supplement["parser_source"])
        abi = supplements[-1]["iced_dispatch_abi_observations"]
        source_records.append({"path": abi["decoder_path"], "sha256": abi["decoder_sha256"]})
        for entry in runtime["inputs"]:
            for name in ("original_path", "fixture_path"):
                source_records.append({"path": str(Path(entry[name])), "sha256": entry["sha256"]})
        source_records.append({"path": str(Path(runtime["fixture_root"]) / "BepInEx/plugins/NpcEventFixture.dll"), "sha256": runtime["plugin_dll_sha256"]})
        for entry in producer_runtime["inputs"]:
            for name in ("original_path", "fixture_path"):
                if name in entry:
                    source_records.append({"path": str(Path(entry[name])), "sha256": entry["sha256"]})
        source_records.append({"path": str(Path(producer_runtime["fixture_root"]) / "BepInEx/plugins/TimeStopProducerFixture.dll"), "sha256": producer_runtime["plugin_dll_sha256"]})
        for entry in natural_runtime["inputs"]:
            for name in ("original_path", "runtime_path"):
                source_records.append({"path": entry[name], "sha256": entry["sha256"]})
        source_records.append({"path": str(Path(natural_runtime["game_root"]) / "BepInEx/plugins/NaturalObserver.dll"), "sha256": natural_runtime["current_plugin_sha256"]})
        generation_abi = read(generation_dir / "abi.json")
        source_records.append({"path": generation_abi["source_path"], "sha256": generation_abi["source_sha256"]})
        for source in source_records:
            # Derived SQLite byte identity is not portable after rebuilding it;
            # reconstruction scripts validate its build identity and coordinates.
            if ".cache" in Path(source["path"]).parts:
                continue
            if source["path"].casefold() not in known:
                paths.append((Path(source["path"]), source["sha256"]))
                known.add(source["path"].casefold())
        for path, expected in paths:
            actual = digest(path)
            check(actual == expected, f"Input fingerprint differs: {path}")
            checked_inputs.append({"path": str(path), "sha256": actual})
    result = {"schema_version": 1, "generated_at_utc": datetime.now(timezone.utc).isoformat(),
              "status": "consistent", "canonical_rea_observations": len(observations),
              "rea_queries_completed": sum(len(run["functions"]) for run in runs),
              "artifacts": artifacts, "inputs_checked": checked_inputs,
              "observations": [{"evidence_id": key, "operation": item["operation"], "subject_sha256": item["subject_sha256"]}
                               for key, item in sorted(observations.items())],
              "scope": "File integrity, declared evidence and bounded controlled runtime log consistency; not global source equivalence or natural gameplay verification"}
    if args.write_index:
        (ROOT / "evidence-index.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    else:
        index = read(ROOT / "evidence-index.json")
        expected = {entry["path"]: entry["sha256"] for entry in index["artifacts"]}
        actual = {entry["path"]: entry["sha256"] for entry in artifacts}
        check(actual == expected, "Artifact files differ from evidence-index.json; inspect changes before regenerating")
    print(json.dumps({"status": "consistent", "artifacts": len(artifacts), "canonical_rea_observations": len(observations),
                      "rea_queries_completed": result["rea_queries_completed"], "inputs_checked": len(checked_inputs)}, indent=2))


if __name__ == "__main__":
    main()
