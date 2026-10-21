"""Audit saved reconstruction evidence and optionally hash the original inputs."""
import argparse
from datetime import datetime, timezone
import hashlib
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
    asset = read(ROOT / "assets/resources-keydata.json")
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
            check(subject_hash in allowed_subjects, f"Unexpected evidence subject in {path}")
            canonical = json.dumps(record, sort_keys=True, ensure_ascii=False)
            if key in observations:
                check(observations[key]["canonical"] == canonical, f"Conflicting copies of {key}")
            else:
                observations[key] = {"canonical": canonical, "operation": record["operation"], "subject_sha256": subject_hash}
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
        for supplement in supplements:
            source_records.extend(supplement.get("sources", []))
            if supplement.get("parser_source"):
                source_records.append(supplement["parser_source"])
        abi = supplements[-1]["iced_dispatch_abi_observations"]
        source_records.append({"path": abi["decoder_path"], "sha256": abi["decoder_sha256"]})
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
              "scope": "File integrity and declared evidence consistency, not global source equivalence or runtime verification"}
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
