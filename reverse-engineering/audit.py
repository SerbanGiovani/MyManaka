"""Audit saved reconstruction evidence and optionally hash the original inputs."""
import argparse
from datetime import datetime, timezone
import hashlib
import gzip
import runpy
import sys
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent


def read(path):
    if path.suffix == ".gz":
        return json.loads(gzip.decompress(path.read_bytes()).decode("utf-8-sig"))
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


def verify_runtime_manifest(directory, manifest, label):
    for source in manifest["sources"] + manifest.get("dependencies", []):
        check(digest(directory / source["path"]) == source["sha256"], f"{label} source differs: {source['path']}")
    for output in manifest["outputs"]:
        path = directory / output["path"]
        check(digest(path) == output["sha256"], f"{label} capture differs: {output['path']}")
        if "uncompressed_sha256" in output:
            check(path.suffix == ".gz", f"{label} compressed output extension differs")
            raw = gzip.decompress(path.read_bytes())
            check(len(raw) == output["uncompressed_bytes"] and hashlib.sha256(raw).hexdigest() == output["uncompressed_sha256"], f"{label} decompressed capture differs")


def observed_frida_source(record, directory, manifest):
    result = record["normalized_result"]
    source = Path(result["source_path"])
    archives = manifest.get("archived_frida_sources", [])
    check(len({item["evidence_id"] for item in archives}) == len(archives), "Duplicate archived Frida source declaration")
    check(all(item["evidence_id"] in manifest["evidence_ids"] for item in archives), "Archived Frida source refers to undeclared Evidence")
    selected = [item for item in archives if item["evidence_id"] == record["evidence_id"]]
    if selected:
        item = selected[0]
        check(item["original_path"] == result["source_path"] and item["sha256"] == result["source_sha256"], "Archived Frida source does not match original Evidence")
        relative = Path(item["path"])
        check(not relative.is_absolute() and ".." not in relative.parts, "Archived Frida source must remain in its runtime directory")
        source = directory / relative
    check(digest(source) == result["source_sha256"], "Observed Frida source differs")
    return source


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
    cancellation_dir = ROOT / "runtime/natural-cancellation"
    cancellation_runtime = read(cancellation_dir / "manifest.json")
    for source in cancellation_runtime["sources"]:
        check(digest(ROOT / source["path"]) == source["sha256"], "Cancellation source differs")
    for output in cancellation_runtime["outputs"]:
        path = cancellation_dir / output["path"]
        check(digest(path) == output["sha256"], "Cancellation log differs")
        payload = gzip.decompress(path.read_bytes())
        check(len(payload) == output["uncompressed_bytes"] and hashlib.sha256(payload).hexdigest() == output["uncompressed_sha256"], "Cancellation raw log differs")
        bounds = output["selection"]
        check(output["original_start_offset"] > 0 and all(bounds["min_frame"] <= json.loads(line)["frame"] <= bounds["max_frame"] for line in payload.splitlines()), "Cancellation run/window differs")
    cancellation_result = runpy.run_path(str(cancellation_dir / "analyze.py"))["analyze"]()
    check(cancellation_result == read(cancellation_dir / "results.json"), "Cancellation measurements differ")
    check(cancellation_result["all_sources_finished"] and cancellation_runtime["observation_complete"] and cancellation_runtime["natural_only"], "Cancellation tail incomplete")
    check(not cancellation_result["errors"] and not cancellation_result["native_script_errors"] and not cancellation_result["guard_errors"], "Cancellation probe errors")
    check(all(s["closed_by_operator"] for s in cancellation_runtime["sessions"]), "Cancellation session not closed")
    for key in ["previous_checkpoint", "algorithm_dependency", "static_guard_queries"]:
        dependency = cancellation_runtime[key]
        check(digest(ROOT / dependency["path"]) == dependency["sha256"], "Cancellation dependency differs")
    save_baseline = cancellation_runtime["source_save_baseline"]
    check(digest(cancellation_dir / save_baseline["path"]) == save_baseline["sha256"], "Cancellation save baseline differs")
    if args.inputs:
        for entry in read(cancellation_dir / save_baseline["path"])["files"]:
            check(digest(Path(entry["path"])) == entry["sha256"], "Source save/binding file changed during cancellation trial")
    observed_runtime_records[cancellation_dir / "rea-runtime.json"] = cancellation_runtime
    noise_dir = ROOT / "runtime/noise-cancellation"
    noise_runtime = read(noise_dir / "manifest.json")
    for source in noise_runtime["sources"]:
        check(digest(ROOT / source["path"]) == source["sha256"], "Noise source differs")
    for output in noise_runtime["outputs"]:
        path = noise_dir / output["path"]
        check(digest(path) == output["sha256"], "Noise compressed log differs")
        payload = gzip.decompress(path.read_bytes())
        check(len(payload) == output["uncompressed_bytes"] and hashlib.sha256(payload).hexdigest() == output["uncompressed_sha256"], "Noise raw log differs")
        bounds = output["selection"]
        check(output["original_start_offset"] > 0 and all(bounds["min_frame"] <= json.loads(line)["frame"] <= bounds["max_frame"] for line in payload.splitlines()), "Noise run/window differs")
    noise_result = runpy.run_path(str(noise_dir / "analyze.py"))["analyze"]()
    check(noise_result == read(noise_dir / "results.json"), "Noise measurements differ")
    check(noise_result["all_sources_finished"] and noise_runtime["observation_complete"] and not noise_runtime["natural_only"], "Noise capture tail/authority differs")
    check(noise_runtime["inputs"] == natural_runtime["inputs"] and noise_runtime["current_plugin_sha256"] == natural_runtime["current_plugin_sha256"], "Noise build/probe identity differs")
    for section in ["natural", "replay", "replay_additional"]:
        measured = noise_result[section]
        check(not measured["errors"] and not measured["native_script_errors"], "Noise probe errors")
        if section == "natural":
            check(not measured["noise_decode_errors"] and all(e["delivery_balanced"] for e in measured["events"]), "Natural noise delivery/decode error")
        else:
            check(all(t["complete"] and t["event_callback_counts_match"] and t["cleanup"]["verified_listed_fields_and_position"] for t in measured["trials"]), "Controlled noise capture/cleanup incomplete")
    check(all(s["closed_by_operator"] for s in noise_runtime["sessions"]), "Noise session not closed")
    for dependency in noise_runtime["dependencies"]:
        check(digest(ROOT / dependency["path"]) == dependency["sha256"], "Noise dependency differs")
    save_baseline = noise_runtime["source_save_baseline"]
    check(digest(noise_dir / save_baseline["path"]) == save_baseline["sha256"], "Noise save baseline differs")
    if args.inputs:
        for entry in read(noise_dir / save_baseline["path"])["files"]:
            check(digest(Path(entry["path"])) == entry["sha256"], "Source save/binding file changed during noise capture")
        pe = runpy.run_path(str(ROOT / "salt/metadata.py"))["PE"]
        native = (Path(noise_runtime["game_root"]) / "GameAssembly.dll").read_bytes()
        image = pe(native)
        for record in read(noise_dir / "rea-runtime.json")["records"]:
            for message in record["normalized_result"]["messages"]:
                p = message.get("payload", {})
                if p.get("kind") != "noise_decoded_file_window":continue
                for row in p["data"]["rows"]:
                    pos = image.offset(0x180000000 + int(row["rva"], 16), executable=True)
                    check(native[pos:pos+row["size"]] == bytes(row["bytes"]), "Noise original instruction bytes differ")
    for name, sid in noise_runtime["session_files"].items():
        check(all(r["parameters"]["session_id"] == sid for r in read(noise_dir / name)["records"]), "Noise natural/replay session contamination")
        observed_runtime_records[noise_dir / name] = noise_runtime
    callsite_dir = ROOT / "runtime/noise-callsite"
    callsite_runtime = read(callsite_dir / "manifest.json")
    for source in callsite_runtime["sources"]:
        check(digest(ROOT / source["path"]) == source["sha256"], "Callsite source differs")
    for output in callsite_runtime["outputs"]:
        path = callsite_dir / output["path"]
        check(digest(path) == output["sha256"], "Callsite compressed log differs")
        payload = gzip.decompress(path.read_bytes())
        check(len(payload) == output["uncompressed_bytes"] and hashlib.sha256(payload).hexdigest() == output["uncompressed_sha256"], "Callsite raw log differs")
        bounds = output["selection"]
        check(output["original_start_offset"] > 0 and all(bounds["min_frame"] <= json.loads(line)["frame"] <= bounds["max_frame"] for line in payload.splitlines()), "Callsite log run/window differs")
    callsite_result = runpy.run_path(str(callsite_dir / "analyze.py"))["analyze"]()
    check(callsite_result == read(callsite_dir / "results.json"), "Callsite measurements differ")
    check(callsite_result["all_sources_finished"] and callsite_runtime["observation_complete"] and not callsite_runtime["natural_only"], "Callsite capture/authority differs")
    check(callsite_runtime["inputs"] == natural_runtime["inputs"] and callsite_runtime["current_plugin_sha256"] == natural_runtime["current_plugin_sha256"], "Callsite build/probe identity differs")
    check(all(s["closed_by_operator"] for s in callsite_runtime["sessions"]), "Callsite session not closed")
    for dependency in callsite_runtime["dependencies"]:
        check(digest(ROOT / dependency["path"]) == dependency["sha256"], "Callsite dependency differs")
    for section in ["natural", "replay"]:
        measured_callsite = callsite_result[section]
        check(not measured_callsite["errors"] and not measured_callsite["native_script_errors"], "Callsite script errors")
    check(not callsite_result["natural"]["eligibility_errors"] and all(e["delivery_balanced"] for e in callsite_result["natural"]["events"]), "Natural callsite delivery/eligibility errors")
    check(all(t["complete"] and t["native_scope_chain_valid"] and t["end_counts_match"] and t["all_four_counts_equal"] and t["cleanup"]["verified_listed_fields_and_position"] for t in callsite_result["replay"]["trials"]), "Deferred native scope/delivery/cleanup incomplete")
    save_baseline = callsite_runtime["source_save_baseline"]
    check(digest(callsite_dir / save_baseline["path"]) == save_baseline["sha256"], "Callsite save baseline differs")
    window_entry = callsite_runtime["static_window"]
    check(digest(callsite_dir / window_entry["path"]) == window_entry["sha256"], "Callsite instruction window differs")
    window = read(callsite_dir / window_entry["path"])
    parent = next(r for r in read(ROOT / window["parent_path"])["records"] if r["evidence_id"] == window["parent_evidence"])
    original_rows = next(m["payload"]["data"]["rows"] for m in parent["normalized_result"]["messages"] if m.get("payload", {}).get("kind") == "noise_decoded_file_window")
    check(all(row in original_rows for row in window["rows"]) and len(window["rows"]) == window_entry["instructions_verified"], "Callsite rows differ from original REA Evidence")
    check(window["source_sha256"] == identity["native_sha256"] and any(row["rva"] == window["call_rva"] and row["relativeCallTarget"] == window["target_rva"] for row in window["rows"]), "Callsite static target differs")
    if args.inputs:
        for entry in read(callsite_dir / save_baseline["path"])["files"]:
            check(digest(Path(entry["path"])) == entry["sha256"], "Source save/binding changed during deferred replay")
        native = Path(window["source"]).read_bytes()
        image = runpy.run_path(str(ROOT / "salt/metadata.py"))["PE"](native)
        for row in window["rows"]:
            pos = image.offset(0x180000000 + int(row["rva"], 16), executable=True)
            check(native[pos:pos+row["size"]] == bytes(row["bytes"]), "Callsite original machine code differs")
    for name, sid in callsite_runtime["session_files"].items():
        check(all(r["parameters"]["session_id"] == sid for r in read(callsite_dir / name)["records"]), "Callsite natural/replay contamination")
        observed_runtime_records[callsite_dir / name] = callsite_runtime
    asset = read(ROOT / "assets/resources-keydata.json")
    check(runtime_inputs["SecretFlasherManaka_Data/data.unity3d"] == asset["source_sha256"], "Runtime resources differ")
    recovered = read(ROOT / "salt/evidence/recovered-crypto.json")
    decryption = read(ROOT / "salt/evidence/decryption.json")
    return_dir = ROOT / "runtime/noise-return"
    return_runtime = read(return_dir / "manifest.json")
    for item in return_runtime["sources"] + return_runtime["dependencies"]:
        check(digest(ROOT / item["path"]) == item["sha256"], "Noise return source/dependency differs")
    return_result = runpy.run_path(str(return_dir / "analyze.py"))["analyze"]()
    check(return_result == read(return_dir / "results.json"), "Noise return measurements differ")
    check(return_result["finished"] and return_runtime["observation_complete"] and return_runtime["natural_only"], "Noise return capture incomplete/mixed")
    check(not return_result["script_errors"] and not return_result["natural"]["errors"], "Noise return script errors")
    check(return_result["native_pairing"]["valid_calls"] == 458 and not return_result["native_pairing"]["invalid_calls"], "Noise return selected call pairing differs")
    pre_return = [c["native_pre_event"] for c in return_result["natural"]["cases"]]
    check(sum(c["calls"] for c in pre_return) == sum(c["decrement_pairs"] for c in pre_return) == sum(c["within_call_count_increases"] for c in pre_return) == 54, "Noise return pre-event decrement/reset pairs differ")
    check(len(return_result["natural"]["cases"]) == 4 and all(return_result["counts"][k] == 4 for k in ["coverage_animation", "coverage_model", "coverage_callback", "coverage_listener"]), "Noise return natural event counts differ")
    counters = return_result["counter_finishes"][0]["data"]
    check(counters["entry"] == counters["leave"] == counters["continuation"] == 378432, "Noise return aggregate counters differ")
    check(return_runtime["inputs"] == natural_runtime["inputs"] and return_runtime["current_plugin_sha256"] == natural_runtime["current_plugin_sha256"], "Noise return native/bootstrap identity differs")
    check(all(s["closed_by_operator"] for s in return_runtime["sessions"]), "Noise return session not closed")
    baseline = return_runtime["source_save_baseline"]
    check(digest(return_dir / baseline["path"]) == baseline["sha256"], "Noise return baseline differs")
    for output in return_runtime["outputs"]:
        p = return_dir / output["path"]
        check(digest(p) == output["sha256"], "Noise return compressed log differs")
        payload = gzip.decompress(p.read_bytes())
        check(len(payload) == output["uncompressed_bytes"] and hashlib.sha256(payload).hexdigest() == output["uncompressed_sha256"], "Noise return raw log differs")
        bounds = output["selection"]
        check(all(bounds["min_frame"] <= json.loads(line)["frame"] <= bounds["max_frame"] for line in payload.splitlines()), "Noise return log window differs")
    return_raw = read(return_dir / "rea-runtime.json")
    return_status = next(r for r in return_raw["records"] if r["operation"] == "frida_session_status")
    decode = next(m["payload"]["data"] for m in return_status["normalized_result"]["messages"] if m.get("payload", {}).get("kind") == "return_decode")
    check(len(decode["rows"]) == 8 and return_runtime["static_continuation"]["source_sha256"] == identity["native_sha256"], "Noise return instruction source differs")
    native_data = (Path(identity["original_directory"]) / "GameAssembly.dll").read_bytes()
    image = runpy.run_path(str(ROOT / "salt/metadata.py"))["PE"](native_data)
    for row in decode["rows"]:
        offset = image.offset(0x180000000 + int(row["rva"], 16), executable=True)
        check(native_data[offset:offset+row["size"]] == bytes(row["bytes"]), "Noise return original instruction bytes differ")
    observed_runtime_records[return_dir / "rea-runtime.json"] = return_runtime
    restore_dir = ROOT / "runtime/state-restore"
    restore_runtime = read(restore_dir / "manifest.json")
    check(restore_runtime["observation_complete"] and not restore_runtime["natural_only"], "Restore replay authority differs")
    for source in restore_runtime["sources"]:
        check(digest(restore_dir / source["path"]) == source["sha256"], "Restore probe/analyzer source differs")
    for output in restore_runtime["outputs"]:
        path = restore_dir / output["path"]
        raw = gzip.decompress(path.read_bytes())
        check(digest(path) == output["sha256"] and len(raw) == output["uncompressed_bytes"] and
              hashlib.sha256(raw).hexdigest() == output["uncompressed_sha256"], "Restore capture differs")
    restore_analysis = runpy.run_path(str(restore_dir / "analyze.py"))
    check(restore_analysis["build"](inputs=args.inputs) == read(restore_dir / "results.json"), "Restore object/file joins differ")
    restore_post = read(restore_dir / "post-state.json")
    check(restore_post["process"]["exited"] and restore_post["frida"]["closed_by_operator"] and
          restore_post["temporary_plugin"]["removed_from_plugin_directory"], "Restore instrumentation cleanup incomplete")
    if args.inputs:
        for row in restore_post["profile"]:
            check(digest(Path(row["path"])) == row["before"] == row["after"], "Restore clone profile differs")
        for row in restore_post["inputs"]:
            check(digest(Path(row["path"])) == digest(Path(row["original_path"])) == row["before"], "Restore engine/assets differ")
    observed_runtime_records[restore_dir / "rea-runtime.json"] = restore_runtime
    load_dir = ROOT / "runtime/natural-load"
    load_runtime = read(load_dir / "manifest.json")
    check(load_runtime["observation_complete"] and load_runtime["passive_only"] and load_runtime["user_input_driven"] and
          not load_runtime["natural_only"], "Natural-load capture/input authority differs")
    for source in load_runtime["sources"]:
        check(digest(load_dir / source["path"]) == source["sha256"], "Natural-load source differs")
    for output in load_runtime["outputs"]:
        path = load_dir / output["path"]
        raw = gzip.decompress(path.read_bytes())
        check(digest(path) == output["sha256"] and len(raw) == output["uncompressed_bytes"] and
              hashlib.sha256(raw).hexdigest() == output["uncompressed_sha256"], "Natural-load capture differs")
    load_analysis = runpy.run_path(str(load_dir / "analyze.py"))
    check(load_analysis["build"](inputs=args.inputs) == read(load_dir / "results.json"), "Natural-load result joins differ")
    load_bindings = runpy.run_path(str(ROOT / "salt/natural_load_evidence.py"))
    check(load_bindings["build"]() == read(ROOT / "salt/evidence/natural-load-chain.json"), "Natural-load static bindings differ")
    load_scan = read(load_dir / "guard-scan.json")
    load_selection = runpy.run_path(str(load_dir / "prepare_guard_scan.py"))["build"]()
    check(load_selection["methods"] == load_scan["methods"] and load_selection["npc_ranges"] == load_scan["npc_ranges"], "Natural-load nested-type scan selection differs")
    load_post = read(load_dir / "post-state.json")
    check(load_post["process"]["status"] == "suspended" and load_post["process"]["ntstatus"] == 0 and
          load_post["frida_closed"], "Requested natural-load suspension receipt missing")
    check(not load_post["process"]["present_at_final_check"] and not load_post["process"]["in_memory_resume_available"] and
          load_runtime["resume_requires_relaunch"], "Natural-load final process state differs")
    observed_runtime_records[load_dir / "rea-runtime.json"] = load_runtime
    title_dir = ROOT / "runtime/natural-title"
    title_runtime = read(title_dir / "manifest.json")
    check(title_runtime["observation_complete"] and title_runtime["natural_only"] and
          title_runtime["passive_only"] and title_runtime["user_input_driven"], "Natural-title authority differs")
    for source in title_runtime["sources"]:
        check(digest(title_dir / source["path"]) == source["sha256"], "Natural-title source differs")
    for output in title_runtime["outputs"]:
        path = title_dir / output["path"]
        raw = gzip.decompress(path.read_bytes())
        check(digest(path) == output["sha256"] and len(raw) == output["uncompressed_bytes"] and
              hashlib.sha256(raw).hexdigest() == output["uncompressed_sha256"], "Natural-title capture differs")
    title_analysis = runpy.run_path(str(title_dir / "analyze.py"))
    check(title_analysis["build"](inputs=args.inputs) == read(title_dir / "results.json"), "Natural-title file/load/Warp joins differ")
    title_bindings = runpy.run_path(str(ROOT / "salt/natural_title_evidence.py"))
    check(title_bindings["build"]() == read(ROOT / "salt/evidence/natural-title-chain.json"), "Natural-title static bindings differ")
    observed_runtime_records[title_dir / "rea-runtime.json"] = title_runtime
    npc_filter_dir = ROOT / "runtime/npc-restore-filter"
    npc_filter_runtime = read(npc_filter_dir / "manifest.json")
    check(npc_filter_runtime["observation_complete"] and not npc_filter_runtime["natural_only"] and
          npc_filter_runtime["authority"] == "controlled-native-entry-replay", "NPC filter authority differs")
    for source in npc_filter_runtime["sources"]:
        check(digest(npc_filter_dir / source["path"]) == source["sha256"], "NPC filter source differs")
    for output in npc_filter_runtime["outputs"]:
        path = npc_filter_dir / output["path"]
        raw = gzip.decompress(path.read_bytes())
        check(digest(path) == output["sha256"] and len(raw) == output["uncompressed_bytes"] and
              hashlib.sha256(raw).hexdigest() == output["uncompressed_sha256"], "NPC filter capture differs")
    npc_filter_analysis = runpy.run_path(str(npc_filter_dir / "analyze.py"))
    check(npc_filter_analysis["build"](inputs=args.inputs) == read(npc_filter_dir / "results.json"), "NPC filter file/queue/callback/object joins differ")
    npc_filter_bindings = runpy.run_path(str(ROOT / "salt/npc_restore_filter_evidence.py"))
    check(npc_filter_bindings["build"]() == read(ROOT / "salt/evidence/npc-restore-filter-chain.json"), "NPC filter static binding differs")
    observed_runtime_records[npc_filter_dir / "rea-runtime.json"] = npc_filter_runtime
    cold_dir = ROOT / "runtime/drop-cold-cache"
    cold_runtime = read(cold_dir / "manifest.json")
    check(cold_runtime["observation_complete"] and not cold_runtime["natural_only"], "Cold-cache authority differs")
    for source in cold_runtime["sources"]:
        check(digest(cold_dir / source["path"]) == source["sha256"], "Cold-cache source differs")
    for output in cold_runtime["outputs"]:
        path = cold_dir / output["path"]
        raw = gzip.decompress(path.read_bytes())
        check(digest(path) == output["sha256"] and len(raw) == output["uncompressed_bytes"] and
              hashlib.sha256(raw).hexdigest() == output["uncompressed_sha256"], "Cold-cache output differs")
    cold_analysis = runpy.run_path(str(cold_dir / "analyze.py"))
    check(cold_analysis["build"](inputs=args.inputs) == read(cold_dir / "results.json"), "Cold-cache object joins differ")
    cold_bindings = runpy.run_path(str(ROOT / "salt/drop_cache_evidence.py"))
    check(cold_bindings["build"]() == read(ROOT / "salt/evidence/drop-cache-chain.json"), "Cold-cache static bindings differ")
    observed_runtime_records[cold_dir / "rea-runtime.json"] = cold_runtime
    interruption_dir = ROOT / "runtime/restore-interruption"
    interruption_runtime = read(interruption_dir / "manifest.json")
    for source in interruption_runtime["sources"]:
        check(digest(interruption_dir / source["path"]) == source["sha256"], "Interruption source differs")
    for output in interruption_runtime["outputs"]:
        path = interruption_dir / output["path"]
        raw = gzip.decompress(path.read_bytes())
        check(digest(path) == output["sha256"] and len(raw) == output["uncompressed_bytes"] and hashlib.sha256(raw).hexdigest() == output["uncompressed_sha256"], "Interruption log differs")
    check(runpy.run_path(str(interruption_dir / "analyze.py"))["build"](inputs=args.inputs) == read(interruption_dir / "results.json"), "Interruption queue joins differ")
    check(runpy.run_path(str(ROOT / "salt/restore_interruption_evidence.py"))["build"]() == read(ROOT / "salt/evidence/restore-interruption-chain.json"), "Interruption static bindings differ")
    observed_runtime_records[interruption_dir / "rea-runtime.json"] = interruption_runtime
    full_save_dir = ROOT / "runtime/full-save-restore"
    full_save_runtime = read(full_save_dir / "manifest.json")
    for source in full_save_runtime["sources"]:
        check(digest(full_save_dir / source["path"]) == source["sha256"], "Full-save source differs")
    for output in full_save_runtime["outputs"]:
        path = full_save_dir / output["path"]
        raw = gzip.decompress(path.read_bytes())
        check(digest(path) == output["sha256"] and len(raw) == output["uncompressed_bytes"] and hashlib.sha256(raw).hexdigest() == output["uncompressed_sha256"], "Full-save log differs")
    sys.path.insert(0, str(full_save_dir))
    try:
        check(runpy.run_path(str(full_save_dir / "analyze.py"))["build"](inputs=args.inputs) == read(full_save_dir / "results.json"), "Full-save observations differ")
    finally:
        sys.path.remove(str(full_save_dir))
    observed_runtime_records[full_save_dir / "rea-runtime.json"] = full_save_runtime
    recovery_dir = ROOT / "runtime/full-save-recovery"
    recovery_runtime = read(recovery_dir / "manifest.json")
    for source in recovery_runtime["sources"]:
        check(digest(recovery_dir / source["path"]) == source["sha256"], "Recovery source differs")
    for output in recovery_runtime["outputs"]:
        path = recovery_dir / output["path"]
        raw = gzip.decompress(path.read_bytes())
        check(digest(path) == output["sha256"] and len(raw) == output["uncompressed_bytes"] and hashlib.sha256(raw).hexdigest() == output["uncompressed_sha256"], "Recovery log differs")
    sys.path.insert(0, str(recovery_dir))
    try:
        check(runpy.run_path(str(recovery_dir / "analyze_recovery.py"))["build"](inputs=args.inputs) == read(recovery_dir / "results.json"), "Recovery observations differ")
    finally:
        sys.path.remove(str(recovery_dir))
    observed_runtime_records[recovery_dir / "rea-runtime.json"] = recovery_runtime
    appearance_dir = ROOT / "runtime/appearance-restore"
    appearance_runtime = read(appearance_dir / "manifest.json")
    for source in appearance_runtime["sources"]:
        check(digest(appearance_dir / source["path"]) == source["sha256"], "Appearance source differs")
    for output in appearance_runtime["outputs"]:
        path = appearance_dir / output["path"]
        raw = gzip.decompress(path.read_bytes())
        check(digest(path) == output["sha256"] and len(raw) == output["uncompressed_bytes"] and hashlib.sha256(raw).hexdigest() == output["uncompressed_sha256"], "Appearance log differs")
    check(runpy.run_path(str(appearance_dir / "analyze.py"))["build"](inputs=args.inputs) == read(appearance_dir / "results.json"), "Appearance scale/callback joins differ")
    observed_runtime_records[appearance_dir / "rea-runtime.json"] = appearance_runtime
    appearance_detail_dir = ROOT / "runtime/appearance-detail"
    appearance_detail_runtime = read(appearance_detail_dir / "manifest.json")
    check(not appearance_detail_runtime["natural_only"], "Appearance detail authority differs")
    for source in appearance_detail_runtime["sources"]:
        check(digest(appearance_detail_dir / source["path"]) == source["sha256"], "Appearance detail source differs")
    for output in appearance_detail_runtime["outputs"]:
        path = appearance_detail_dir / output["path"]
        raw = gzip.decompress(path.read_bytes())
        check(digest(path) == output["sha256"] and len(raw) == output["uncompressed_bytes"] and hashlib.sha256(raw).hexdigest() == output["uncompressed_sha256"], "Appearance detail capture differs")
    check(runpy.run_path(str(appearance_detail_dir / "analyze.py"))["build"](inputs=args.inputs) == read(appearance_detail_dir / "results.json"), "Appearance material/face/nonunit-bone joins differ")
    check(runpy.run_path(str(ROOT / "salt/appearance_detail_evidence.py"))["build"]() == read(ROOT / "salt/evidence/appearance-detail-chain.json"), "Appearance detail static binding differs")
    observed_runtime_records[appearance_detail_dir / "rea-runtime.json"] = appearance_detail_runtime
    appearance_hair_dir = ROOT / "runtime/appearance-hair"
    appearance_hair_runtime = read(appearance_hair_dir / "manifest.json")
    check(not appearance_hair_runtime["natural_only"], "Hair restore authority differs")
    for source in appearance_hair_runtime["sources"]:
        check(digest(appearance_hair_dir / source["path"]) == source["sha256"], "Hair restore source differs")
    for output in appearance_hair_runtime["outputs"]:
        path = appearance_hair_dir / output["path"]
        raw = gzip.decompress(path.read_bytes())
        check(digest(path) == output["sha256"] and len(raw) == output["uncompressed_bytes"] and hashlib.sha256(raw).hexdigest() == output["uncompressed_sha256"], "Hair restore capture differs")
    check(runpy.run_path(str(appearance_hair_dir / "analyze.py"))["build"](inputs=args.inputs) == read(appearance_hair_dir / "results.json"), "Hair data/material/model joins differ")
    check(runpy.run_path(str(ROOT / "salt/appearance_hair_evidence.py"))["build"]() == read(ROOT / "salt/evidence/appearance-hair-chain.json"), "Hair restore static binding differs")
    observed_runtime_records[appearance_hair_dir / "rea-runtime.json"] = appearance_hair_runtime
    consumers_dir = ROOT / "runtime/state-consumers"
    consumers_runtime = read(consumers_dir / "manifest.json")
    check(not consumers_runtime["natural_only"], "Consumer replay authority differs")
    for source in consumers_runtime["sources"]:
        check(digest(consumers_dir / source["path"]) == source["sha256"], "Consumer source differs")
    for output in consumers_runtime["outputs"]:
        path = consumers_dir / output["path"]
        raw = gzip.decompress(path.read_bytes())
        check(digest(path) == output["sha256"] and len(raw) == output["uncompressed_bytes"] and hashlib.sha256(raw).hexdigest() == output["uncompressed_sha256"], "Consumer capture differs")
    check(runpy.run_path(str(consumers_dir / "analyze.py"))["build"](inputs=args.inputs) == read(consumers_dir / "results.json"), "Inventory/skill consumer joins differ")
    check(runpy.run_path(str(ROOT / "salt/state_consumers_evidence.py"))["build"]() == read(ROOT / "salt/evidence/state-consumers-chain.json"), "Consumer static binding differs")
    observed_runtime_records[consumers_dir / "rea-runtime.json"] = consumers_runtime
    mission_consumers_dir = ROOT / "runtime/mission-consumers"
    mission_consumers_runtime = read(mission_consumers_dir / "manifest.json")
    check(not mission_consumers_runtime["natural_only"], "Mission consumer authority differs")
    for source in mission_consumers_runtime["sources"]:
        check(digest(mission_consumers_dir / source["path"]) == source["sha256"], "Mission consumer source differs")
    for output in mission_consumers_runtime["outputs"]:
        path = mission_consumers_dir / output["path"]
        raw = gzip.decompress(path.read_bytes())
        check(digest(path) == output["sha256"] and len(raw) == output["uncompressed_bytes"] and hashlib.sha256(raw).hexdigest() == output["uncompressed_sha256"], "Mission consumer capture differs")
    check(runpy.run_path(str(mission_consumers_dir / "analyze.py"))["build"](inputs=args.inputs) == read(mission_consumers_dir / "results.json"), "Mission progress/reward/settlement joins differ")
    check(runpy.run_path(str(ROOT / "salt/mission_consumers_evidence.py"))["build"]() == read(ROOT / "salt/evidence/mission-consumers-chain.json"), "Mission consumer static binding differs")
    observed_runtime_records[mission_consumers_dir / "rea-runtime.json"] = mission_consumers_runtime
    natural_mission_dir = ROOT / "runtime/natural-mission"
    natural_mission_runtime = read(natural_mission_dir / "manifest.json")
    check(natural_mission_runtime["natural_only"] and natural_mission_runtime["passive_only"] and natural_mission_runtime["user_input_driven"] and not natural_mission_runtime["observation_complete"], "Natural mission authority/capture boundary differs")
    verify_runtime_manifest(natural_mission_dir, natural_mission_runtime, "Natural mission")
    natural_mission_post = read(natural_mission_dir / "post-state.json")
    check(natural_mission_post["plugin_verification"]["checked"] and natural_mission_post["plugin_verification"]["restored"], "Natural mission plugin finalization incomplete")
    check(runpy.run_path(str(natural_mission_dir / "analyze.py"))["build"](inputs=args.inputs) == read(natural_mission_dir / "results.json"), "Natural mission progress/settlement joins differ")
    observed_runtime_records[natural_mission_dir / "rea-runtime.json"] = natural_mission_runtime
    appearance_boundary_dir = ROOT / "runtime/appearance-boundary"
    appearance_boundary_runtime = read(appearance_boundary_dir / "manifest.json")
    check(not appearance_boundary_runtime["natural_only"], "Persistent paint authority differs")
    verify_runtime_manifest(appearance_boundary_dir, appearance_boundary_runtime, "Persistent paint")
    check(runpy.run_path(str(appearance_boundary_dir / "analyze.py"))["build"](inputs=args.inputs, require_finalized_plugins=True) == read(appearance_boundary_dir / "results.json"), "Persistent paint material joins differ")
    check(runpy.run_path(str(ROOT / "salt/appearance-boundary-evidence.py"))["build"]() == read(ROOT / "salt/evidence/appearance-boundary-chain.json"), "Persistent/timed paint static binding differs")
    observed_runtime_records[appearance_boundary_dir / "rea-runtime.json"] = appearance_boundary_runtime
    paid_skill_dir = ROOT / "runtime/paid-skill-boundary"
    paid_skill_runtime = read(paid_skill_dir / "manifest.json")
    check(not paid_skill_runtime["natural_only"], "Paid learning authority differs")
    verify_runtime_manifest(paid_skill_dir, paid_skill_runtime, "Paid learning")
    check(runpy.run_path(str(paid_skill_dir / "analyze.py"))["build"](inputs=args.inputs, require_finalized_plugins=True) == read(paid_skill_dir / "results.json"), "Paid learning guards/consumer joins differ")
    check(runpy.run_path(str(ROOT / "salt/paid-skill-boundary-evidence.py"))["build"]() == read(ROOT / "salt/evidence/paid-skill-boundary-chain.json"), "Paid learning static binding differs")
    observed_runtime_records[paid_skill_dir / "rea-runtime.json"] = paid_skill_runtime
    paid_skill_diagnostic = paid_skill_runtime["diagnostic_observation"]
    check(paid_skill_diagnostic["success"] is False and not set(paid_skill_diagnostic["evidence_ids"]) & set(paid_skill_runtime["evidence_ids"]), "Failed paid setup Evidence merged with formal success")
    observed_runtime_records[paid_skill_dir / "diagnostics-rea.json"] = paid_skill_diagnostic
    skin_preset_dir = ROOT / "runtime/skin-preset"
    skin_preset_runtime = read(skin_preset_dir / "manifest.json")
    check(not skin_preset_runtime["natural_only"], "Skin preset authority differs")
    verify_runtime_manifest(skin_preset_dir, skin_preset_runtime, "Skin preset")
    check(runpy.run_path(str(skin_preset_dir / "analyze.py"))["build"](inputs=args.inputs, require_finalized_plugins=True) == read(skin_preset_dir / "results.json"), "Skin preset data/material joins differ")
    observed_runtime_records[skin_preset_dir / "rea-runtime.json"] = skin_preset_runtime
    timed_paint_dir = ROOT / "runtime/timed-body-paint"
    timed_paint_runtime = read(timed_paint_dir / "manifest.json")
    check(not timed_paint_runtime["natural_only"], "Timed paint controlled authority differs")
    verify_runtime_manifest(timed_paint_dir, timed_paint_runtime, "Timed paint")
    check(runpy.run_path(str(timed_paint_dir / "analyze.py"))["build"](inputs=args.inputs, require_finalized_plugins=True) == read(timed_paint_dir / "results.json"), "Timed paint countdown/wash/load material joins differ")
    check(runpy.run_path(str(ROOT / "salt/timed_body_paint_evidence.py"))["build"]() == read(ROOT / "salt/evidence/timed-body-paint-chain.json"), "Timed paint static binding differs")
    observed_runtime_records[timed_paint_dir / "rea-runtime.json"] = timed_paint_runtime
    timed_paint_diagnostic = timed_paint_runtime["diagnostic_observation"]
    check(timed_paint_diagnostic["success"] is False and not set(timed_paint_diagnostic["evidence_ids"]) & set(timed_paint_runtime["evidence_ids"]), "Failed timed paint setup merged with formal success")
    observed_runtime_records[timed_paint_dir / "diagnostics-rea.json"] = timed_paint_diagnostic
    natural_paint_dir = ROOT / "runtime/natural-paint"
    natural_paint_runtime = read(natural_paint_dir / "manifest.json")
    check(natural_paint_runtime["natural_only"] and natural_paint_runtime["passive_only"] and natural_paint_runtime["user_input_driven"], "Natural paint observation authority differs")
    verify_runtime_manifest(natural_paint_dir, natural_paint_runtime, "Natural paint")
    check(runpy.run_path(str(natural_paint_dir / "analyze.py"))["build"](inputs=args.inputs, require_finalized_plugins=True) == read(natural_paint_dir / "results.json"), "Natural paint item/deadline/title/cold-load joins differ")
    check(runpy.run_path(str(ROOT / "salt/natural_paint_evidence.py"))["build"]() == read(ROOT / "salt/evidence/natural-paint-chain.json"), "Natural paint producer/UI/cold static binding differs")
    check(runpy.run_path(str(ROOT / "natural-paint-assets.py"))["build"]() == read(ROOT / "natural-paint-assets.json"), "Natural paint item/localization asset binding differs")
    observed_runtime_records[natural_paint_dir / "rea-runtime.json.gz"] = natural_paint_runtime
    natural_paint_diagnostic = natural_paint_runtime["diagnostic_observation"]
    check(natural_paint_diagnostic["success"] is False and natural_paint_diagnostic["capture_complete"] is False and not set(natural_paint_diagnostic["evidence_ids"]) & set(natural_paint_runtime["evidence_ids"]), "Incompatible natural save merged with formal success")
    natural_paint_diagnostic_records = read(natural_paint_dir / "diagnostics-rea.json.gz")["records"]
    natural_paint_truncated = {r["evidence_id"] for r in natural_paint_diagnostic_records if r["normalized_result"]["messages_truncated"]}
    check(natural_paint_truncated == set(natural_paint_diagnostic["truncated_evidence_ids"]) and natural_paint_truncated <= set(natural_paint_diagnostic["evidence_ids"]), "Natural paint diagnostic truncation declaration differs")
    observed_runtime_records[natural_paint_dir / "diagnostics-rea.json.gz"] = natural_paint_diagnostic
    toolchain_dir = ROOT / "reconstruction"
    toolchain = read(toolchain_dir / "editor-toolchain.json")
    check(toolchain["status"] == "editor-build-and-player-smoke-verified" and toolchain["compilation_verified"] and toolchain["build_verified"] and toolchain["player_startup_verified"], "Editor smoke did not succeed")
    check(toolchain["build_receipt"]["result"] == "Succeeded" and toolchain["build_receipt"]["errors"] == 0 and toolchain["runtime_proof"]["passed"] and toolchain["runtime_proof"]["frames"] == 5, "Editor build/player receipts differ")
    check(all(r["exit_code"] == 0 and r["process_exited"] for r in toolchain["process_receipts"].values()), "Editor smoke process failed")
    for source in toolchain["sources"]:
        check(digest(toolchain_dir / source["path"]) == source["sha256"], "Editor smoke source differs")
    minimal_check = runpy.run_path(str(toolchain_dir / "verify-minimal.py"))["build"](inputs=args.inputs)
    minimal_runtime = read(toolchain_dir / "minimal-runtime.json")
    check(minimal_check["formal_gpu_acceptance"] and minimal_check["original_resource_compatibility"] == "partial", "Minimum independent loop or compatibility scope differs")
    minimal_save_check = runpy.run_path(str(toolchain_dir / "save-bridge/verify_roundtrip.py"))["build"](inputs=args.inputs)
    check(minimal_save_check == read(toolchain_dir / "save-bridge/acceptance.json"), "Independent actual-pose save/new-process restoration differs")
    locomotion_check = runpy.run_path(str(toolchain_dir / "verify-locomotion-runtime.py"))["build"](inputs=args.inputs)
    locomotion_runtime = read(toolchain_dir / "locomotion-runtime.json")
    locomotion_acceptance_dir = toolchain_dir / "locomotion-acceptance-tools"
    locomotion_acceptance = runpy.run_path(str(locomotion_acceptance_dir / "verify_locomotion.py"))["build"](locomotion_acceptance_dir / "acceptance-inputs.json", verify_inputs=args.inputs)
    check(locomotion_acceptance == read(locomotion_acceptance_dir / "acceptance.json"), "Physical-user keyboard/original Animator/save/restart joins differ")
    interaction_check = runpy.run_path(str(toolchain_dir / "verify-interaction-runtime.py"))["build"](inputs=args.inputs)
    interaction_runtime = read(toolchain_dir / "interaction-runtime.json")
    check(interaction_check["status"] == "original-action-event-physical-recovery-save-restart-verified" and interaction_check["cold_pose_readback"] and interaction_check["saved_inventory_10000"] == 2, "Independent interaction/cold pose save scope differs")
    interaction_acceptance_dir = toolchain_dir / "interaction-acceptance-tools"
    interaction_analyzer = runpy.run_path(str(interaction_acceptance_dir / "verify_interaction.py"))
    # Keep actual keyboard recovery and controlled lock input in separate
    # processes. The physical run did not apply a direction during CanMove=false.
    for filename in ("acceptance-inputs.json", "controlled-inputs.json"):
        config = read(interaction_acceptance_dir / filename)
        for key in ("events", "identity", "start", "exit", "proof", "input_receipt", "controlled_config", "save", "save_backup", "cold_events", "cold_proof", "cold_start", "cold_exit"):
            if key in config:
                check(".cache" not in (interaction_acceptance_dir / config[key]).resolve().parts, "Interaction acceptance config depends on mutable cache evidence")
        for source in config.get("runtime_sources", []):
            check(".cache" not in (interaction_acceptance_dir / source["path"]).resolve().parts, "Interaction acceptance source depends on mutable cache")
    interaction_acceptance = interaction_analyzer["build"](interaction_acceptance_dir / "acceptance-inputs.json", verify_inputs=args.inputs, scoped=True)
    interaction_controlled = interaction_analyzer["build"](interaction_acceptance_dir / "controlled-inputs.json", verify_inputs=args.inputs, controlled=True)
    def interaction_semantics(value):
        # --inputs changes only whether optional live binaries were rehashed in
        # this audit invocation. Keep all recorded behavioral claims exact.
        if isinstance(value, dict):
            return {key: interaction_semantics(item) for key, item in value.items() if key != "actual_launched_binaries_rehashed"}
        if isinstance(value, list):
            return [interaction_semantics(item) for item in value]
        return value
    check(interaction_semantics(interaction_acceptance) == interaction_semantics(read(interaction_acceptance_dir / "acceptance.json")), "Scoped physical interaction/original event/recovery joins differ")
    check(interaction_semantics(interaction_controlled) == interaction_semantics(read(interaction_acceptance_dir / "controlled-diagnostic.json")), "Controlled original action lock/recovery joins differ")
    interaction_strict = interaction_analyzer["strict_rejection"](interaction_acceptance_dir / "acceptance-inputs.json", verify_inputs=args.inputs)
    check(interaction_semantics(interaction_strict) == interaction_semantics(read(interaction_acceptance_dir / "strict-natural-rejection.json")), "Strict natural lock-input rejection differs")
    check(not interaction_strict["passed"] and not interaction_strict["accepted"] and not interaction_strict["full_chain_accepted"] and interaction_strict["reason"] == "Insufficient movement input while original CanMove blocked", "Natural interaction strict gate was bypassed")
    check(interaction_acceptance["scoped_natural_chain_accepted"] and interaction_acceptance["actual_unity_f_accepted"] and not interaction_acceptance["controlled_subchain_only"] and not interaction_acceptance["passed"] and not interaction_acceptance["full_chain_accepted"], "Incomplete natural lock coverage was promoted to a full-chain pass")
    interaction_unmet = interaction_acceptance["unmet_single_process_requirements"]
    check(len(interaction_unmet) == 1 and interaction_unmet[0]["gate"] == "movement-input-during-CanMove-lock" and interaction_unmet[0]["observed_samples"] == 0 and interaction_unmet[0]["required_samples"] == 3, "Natural interaction lock-input gap differs")
    check(interaction_controlled["passed"] and interaction_controlled["controlled_subchain_only"] and not interaction_controlled["actual_unity_f_accepted"] and not interaction_controlled["full_chain_accepted"], "Simulated control was promoted to actual Unity F acceptance")
    check(interaction_acceptance["input_origin"]["human_physical_attestation"] and not interaction_acceptance["input_origin"]["physical_keyboard_measured"] and not interaction_controlled["input_origin"]["human_physical_attestation"] and not interaction_controlled["input_origin"]["physical_keyboard_measured"], "User attestation or simulated input was promoted to measured physical hardware")
    interaction_save, interaction_cold = interaction_acceptance["save_verification"], interaction_acceptance["cold_readback"]
    check(interaction_save["saved_revision"] == 2 and interaction_save["persisted_item_id"] == 10000 and interaction_save["persisted_item_quantity"] == 2 and interaction_cold["same_saved_bytes_verified"] and interaction_cold["component_exact_pose_before_physics"] and interaction_cold["save_sha256"] == interaction_save["saved_sha256"] and interaction_cold["pid"] == interaction_runtime["runtime"]["phase2"]["processId"] and not interaction_cold["cold_in_memory_inventory_quantity_observed"], "Cold pose/retained inventory file scope differs")
    interaction_composite = interaction_acceptance["scoped_composite_acceptance"]
    check(interaction_composite["accepted"] and not interaction_composite["single_process_full_chain_accepted"] and interaction_composite["natural_pid"] == interaction_runtime["runtime"]["interaction"]["processId"] and interaction_composite["controlled_pid"] == interaction_runtime["runtime"]["controlled"]["processId"] and interaction_composite["natural_guid"] != interaction_composite["controlled_guid"], "Distinct interaction input origins were merged")
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
    allowed_subjects = {identity["native_sha256"], identity["wrapper_sha256"], *minimal_check["managed_subjects"], *locomotion_check["managed_subjects"], *interaction_check["managed_subjects"]}
    for path in sorted(ROOT.rglob("*")):
        if not path.is_file() or any(part in (".cache", "__pycache__") for part in path.relative_to(ROOT).parts):
            continue
        if path.name == "evidence-index.json" or path.name.endswith((".stderr.log", ".pending.json")):
            continue
        artifacts.append({"path": path.relative_to(ROOT).as_posix(), "bytes": path.stat().st_size, "sha256": digest(path)})
        if path.suffix != ".json" and path not in observed_runtime_records:
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
                incompatible_paint_capture = path == natural_paint_dir / "diagnostics-rea.json.gz" and key in natural_paint_truncated
                check(not result["messages_truncated"] or (path == coverage_dir / "rea-runtime.json" and coverage_result["capture_joins"]) or incompatible_paint_capture, "Natural checkpoint Evidence truncated without verified overlap or explicit failed diagnostic scope")
                if record["operation"] == "load_frida_script":
                    observed_frida_source(record, path.parent, selected_observation)
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
    check(all(key in observations for selected in observed_runtime_records.values() for key in selected["evidence_ids"]), "Missing observed runtime records")
    for key in ("password_map_initializer_evidence", "password_map_constructor_evidence", "password_decoder_evidence"):
        check(recovered[key] in observations, f"Missing password reconstruction evidence: {key}")
    run_paths = sorted((ROOT / "salt/evidence").glob("*/run.json"))
    run_paths.extend(toolchain_dir / "locomotion-evidence" / directory / "run.json" for directory in ("native", "native-decoded-code"))
    run_paths.extend(toolchain_dir / "interaction-evidence" / directory / "run.json" for directory in ("native", "native-key-callback"))
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
    paid_skill_assets = read(ROOT / "paid-skill-boundary-assets.json")
    check(paid_skill_assets["source_bundle"]["sha256"] == asset["source_sha256"], "Paid skill tier source bundle differs")
    check(digest(Path(paid_skill_assets["parser"]["path"])) == paid_skill_assets["parser"]["sha256"], "Paid skill tier parser differs")
    check(set(paid_skill_assets["tables"]) == {"MSkillMaxAccessoryNum", "MSkillSlow"} and len(paid_skill_assets["bindings"]) == 2, "Paid skill tier master selection differs")
    for table in paid_skill_assets["tables"].values():
        check(table["end_of_object_verified"] and all(e["record"]["end_of_object_verified"] for e in table["entries"]), "Paid skill tier schema did not consume EOF")
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
    priority = read(ROOT / "salt/evidence/priority-chain.json")
    check(priority["native_sha256"] == identity["native_sha256"] and priority["metadata_sha256"] == identity["metadata_sha256"], "Priority native identity differs")
    check(priority["new_observations"] == priority["new_unique_procedure_addresses"] == priority["new_unique_evidence_ids"] == 171, "Priority query count differs")
    check(all(m["evidence_id"] in observations for m in priority["methods"]), "Priority observations missing")
    check(len(priority["priority_groups"]) == 6 and len(priority["requested_methods"]) == 165, "Priority checklist differs")
    check(all(r["evidence_ids"] and all(e in observations for e in r["evidence_ids"]) for r in priority["requested_methods"]), "Priority declaration has no bound query")
    check(len(priority["shared_virtual_declarations"]) == 6, "Priority shared aliases differ")
    for dep in priority["dependencies"]:
        check(digest(ROOT / dep["path"]) == dep["sha256"], "Priority source/dependency differs")
    for batch in priority["batches"]:
        if batch["new_this_round"]:
            run = read(ROOT / "salt/evidence" / batch["name"] / "run.json")
            check(run["success"] and not run.get("close_error") and not run.get("transport_close_error"), "Priority REA session not closed successfully")
    core_plan = read(ROOT / "salt/symbols/priority-core.plan.json")
    check(core_plan["preparer_sha256"] == digest(ROOT / "salt/prepare_priority.py"), "Priority preparer fingerprint differs")
    check(all(a["priority"] <= b["priority"] for a,b in zip(core_plan["functions"], core_plan["functions"][1:])), "Priority order differs")
    guard = priority["npc_fixed_guard"]
    check(guard["instructions_verified"] == 50 and [c["float32"] for c in guard["constants"]] == [20.0, 30.0], "NPC fixed distance guard differs")
    check(digest(ROOT / guard["path"]) == guard["sha256"], "Priority instructions differ")
    guard_input = read(ROOT / guard["path"])
    for source in (guard_input["decoder"], guard_input["preparer"], guard_input["parser"]):
        check(digest(Path(source["path"])) == source["sha256"], "Priority instruction tool differs")
    condition_targets = [s for t in priority["mission_virtual_dispatch"] for s in t["slots"] if s.get("method_name") == "IsInCondition" and not s.get("declaring_type", "").endswith("MissionBase")]
    check(len(condition_targets) == 34 and all(s["queried"] for s in condition_targets), "Concrete mission condition queries missing")
    save_schema = read(ROOT / "salt/evidence/save-schema-chain.json")
    check(save_schema["native_sha256"] == identity["native_sha256"] and save_schema["metadata_sha256"] == identity["metadata_sha256"], "Save schema native identity differs")
    check(save_schema["new_observations"] == save_schema["new_unique_evidence_ids"] == save_schema["new_unique_procedure_addresses"] == 71, "Save schema query count differs")
    check(all(m["evidence_id"] in observations for m in save_schema["methods"]), "Save schema observations missing")
    for dependency in save_schema["dependencies"]:
        check(digest(ROOT / dependency["path"]) == dependency["sha256"], "Save schema dependency differs")
    for batch in save_schema["batches"]:
        if batch["new_this_round"]:
            run = read(ROOT / "salt/evidence" / batch["name"] / "run.json")
            check(run["success"] and not run.get("close_error") and not run.get("transport_close_error"), "Save schema REA session not closed successfully")
    save_declarations = read(ROOT / "salt/symbols/save-declarations.json")
    save_generics = read(ROOT / "salt/symbols/save-generic-methods.json")
    save_layouts = read(ROOT / "salt/symbols/save-parser-layouts.json")
    for item in (save_declarations, save_generics):
        check(item["native_sha256"] == identity["native_sha256"] and item["metadata_sha256"] == identity["metadata_sha256"], "Save declaration/registration identity differs")
        for source in item["sources"]:
            check(digest(ROOT / source["path"]) == source["sha256"], "Save declaration/registration source differs")
    for source in save_layouts["sources"]:
        check(digest(Path(source["path"])) == source["sha256"], "Save layout declaration source differs")
    roots = [t for t in save_declarations["types"] if t["type_id"] in save_declarations["root_type_ids"]]
    check(len(roots) == 4 and sum(len(t["fields"]) for t in roots) == 256, "Save root declarations differ")
    check(all(any(c["parameter_count"] == 0 for c in t["constructors"]) for t in roots), "Save root default constructor differs")
    check(all('ES3Serializable' in f["custom_attributes"]["constructor_types"] for t in roots for f in t["fields"]), "Explicit save root attributes differ")
    check(len(save_declarations["types"]) == 27 and len(save_declarations["runtime_types"]) == 100 and not any(t.get("unresolved") for t in save_declarations["runtime_types"]), "Save declared type closure differs")
    no_default = [t for t in save_declarations["types"] if t["type_id"] in (2453, 2472, 2582)]
    check(len(no_default) == 3 and all(t["constructors"] and all(c["parameter_count"] > 0 for c in t["constructors"]) for t in no_default), "Save no-default-constructor branch differs")
    private = save_schema["private_customize_fields"]
    check(private["count"] == 65 and private["all_nonpublic"] and private["all_explicit_es3_serializable"], "Save private customize fields differ")
    check(len(save_generics["selected_instantiations"]) == 220 and len(save_generics["unique_native_addresses"]) == 57, "Save closed generic registration differs")
    check(len(save_schema["generic_body_links"]) == 13 and all(r["evidence_id"] in observations for r in save_schema["generic_body_links"]), "Save generic body observations missing")
    check(all(r["representative"] in save_generics["selected_instantiations"] and r["representative"]["native_va"] == r["va"] for r in save_schema["generic_body_links"]), "Save shared generic identity differs")
    save_codec = read(ROOT / "salt/evidence/save-codec-chain.json")
    save_settings = read(ROOT / "assets/save-settings.json")
    save_validation = read(ROOT / "salt/evidence/save-codec-validation.json")
    check(save_codec["native_sha256"] == identity["native_sha256"] and save_codec["metadata_sha256"] == identity["metadata_sha256"], "Save codec native identity differs")
    check(save_codec["new_observations"] == save_codec["new_unique_evidence_ids"] == save_codec["new_unique_procedure_addresses"] == 56, "Save codec queries differ")
    check(all(m["evidence_id"] in observations for m in save_codec["methods"]), "Save codec observations missing")
    for source in save_codec["sources"] + save_validation["sources"]:
        check(digest(ROOT / source["path"]) == source["sha256"], "Save codec source differs")
    for source in save_settings["sources"]:
        check(digest(Path(source["path"])) == source["sha256"], "Save settings parser differs")
    for batch in save_codec["batches"]:
        if batch["new_this_round"]:
            run = read(ROOT / "salt/evidence" / batch["name"] / "run.json")
            check(run["success"] and not run.get("close_error") and not run.get("transport_close_error"), "Save codec REA session not closed successfully")
    settings = save_settings["defaults_object"]
    check(settings["end_of_object_verified"] and settings["bytes_consumed"] == 576, "Save default resource extent differs")
    check(settings["settings"]["encryptionType"]["enum_name"] == "AES" and settings["settings"]["compressionType"]["enum_name"] == "None" and settings["settings"]["format"]["enum_name"] == "JSON", "Save effective serialized modes differ")
    check(save_validation["summary"] == dict(samples=8, root_entries=37, numeric_dictionary_keys=12895, reencryption_matches=8, roots_with_all_declared_fields=16), "Save sample coverage differs")
    check(all(r["encrypted_sha256"] == r["sample"]["captured_sha256"] and r["sample"]["source_unchanged_during_capture"] and r["reencryption_matches_original"] for r in save_validation["samples"]), "Save captured envelope validation differs")
    save_roots = [k for r in save_validation["samples"] for k in r["keys"] if "declared_type_id" in k]
    check(len(save_roots) == 16 and all(k["stored_type_matches_declaration"] and k["all_declared_fields_present"] and not k["missing_fields"] and not k["additional_fields"] for k in save_roots), "Stored save root schema differs")
    restore = read(ROOT / "salt/evidence/state-restore-chain.json")
    restore_inputs = read(ROOT / "salt/evidence/state-restore-inputs.json")
    check(restore["native_sha256"] == identity["native_sha256"] and restore["metadata_sha256"] == identity["metadata_sha256"], "Restore native identity differs")
    check(restore["new_observations"] == restore["new_unique_evidence_ids"] == restore["new_unique_procedure_addresses"] == 50, "Restore queries differ")
    check(all(m["evidence_id"] in observations for m in restore["methods"]), "Restore observations missing")
    for dependency in restore["dependencies"] + restore_inputs["sources"]:
        check(digest(ROOT / dependency["path"]) == dependency["sha256"], "Restore source/input differs")
    for batch in restore["batches"]:
        if batch["new_this_round"]:
            run = read(ROOT / "salt/evidence" / batch["name"] / "run.json")
            check(run["success"] and not run.get("close_error") and not run.get("transport_close_error"), "Restore REA session not closed successfully")
    body_event = restore["body_restore_event"]
    check(body_event["static_event_field"]["offset"] == 0x60 and len(body_event["listeners"]) == 5, "Restore body event binding differs")
    check(body_event["listener_method_spec"]["method_spec"]["method_instantiation"]["arguments"][0]["type_id"] == 2687, "Restore typed listener differs")
    check(restore["npc_restore_delegate"]["delegate_usage"]["method_id"] == 15605 and restore["npc_repop_delegate"]["delegate_usage"]["method_id"] == 15603, "Restore NPC callback differs")
    check(restore["npc_restore_delegate"]["arguments"]["isRandomPathSpawn"] is False and restore["npc_repop_delegate"]["arguments"]["isRandomPathSpawn"] is True, "Restore/repop argument distinction differs")
    restore_abi = restore["restore_delay_abi"]
    check(restore_abi["instructions_verified"] == 557 and len(restore_abi["sites"]) == 2, "Restore float argument evidence differs")
    for source in restore_abi["instruction_sources"]:
        check(digest(Path(source["path"])) == source["sha256"], "Restore instruction tool differs")
    check(restore_inputs["summary"] == dict(game_snapshots=7,npc_records=0,reserve_records=0,
        drop_activation_guards=dict(records=196,not_dropped_untouched=193,current_stage_drop_calls=0,other_stage_hide_calls=3),
        all_loadout_lists_have21=True), "Restore stored coverage differs")
    if args.inputs:
        sys.path.insert(0, str(ROOT / "salt"))
        try:
            save_analyzer = runpy.run_path(str(ROOT / "salt/validate_saves.py"))
            measured_save = save_analyzer["build"]([r["sample"] for r in save_validation["samples"]])
            check(measured_save == save_validation, "Independent save decoding differs")
            restore_analyzer = runpy.run_path(str(ROOT / "salt/restore_inputs.py"))
            check(restore_analyzer["build"]() == restore_inputs, "Stored restore input projection differs")
        finally:
            sys.path.pop(0)
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
        for sample in save_validation["samples"]:
            path = Path(sample["sample"]["snapshot_path"])
            if str(path).casefold() not in known:
                paths.append((path, sample["encrypted_sha256"]))
                known.add(str(path).casefold())
        supplements = [read(ROOT / "salt/symbols" / name) for name in
                      ("dispatch-metadata.json", "field-offsets.json", "instantiation-generics.json")]
        source_records = list(declarations["sources"])
        source_records.extend(save_layouts["sources"])
        source_records.extend(save_settings["wrapper_declarations"]["sources"])
        source_records.append(save_settings["wrapper_declarations"]["parser"])
        source_records.extend([scene_assets["stage_enum"]["source"], scene_assets["stage_enum"]["parser"]])
        source_records.extend(player_assets["wrapper_declarations"]["sources"])
        source_records.extend(bareta_assets["wrapper_declarations"]["sources"])
        source_records.extend(paid_skill_assets["wrapper_declarations"]["sources"])
        source_records.append(paid_skill_assets["wrapper_declarations"]["parser"])
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
        for entry in restore_post["inputs"]:
            for name in ("path", "original_path"):
                source_records.append({"path": entry[name], "sha256": entry["before"]})
        source_records.append({"path": restore_post["temporary_plugin"]["archived_path"], "sha256": restore_runtime["plugin"]["sha256"]})
        for entry in load_post["inputs"]:
            for name in ("path", "original_path"):
                source_records.append({"path": entry[name], "sha256": entry["sha256"]})
        source_records.append({"path": load_post["plugin"]["path"], "sha256": load_post["plugin"]["sha256"]})
        source_records.append(load_scan["decoder"])
        source_records.append({"path": npc_filter_runtime["plugin"]["archived_path"], "sha256": npc_filter_runtime["plugin"]["sha256"]})
        source_records.append({"path": cold_runtime["plugin"]["archived_path"], "sha256": cold_runtime["plugin"]["sha256"]})
        source_records.extend({"path": p["archived_path"], "sha256": p["sha256"]} for p in interruption_runtime["plugins"])
        source_records.append({"path": full_save_runtime["plugin"]["archived_path"], "sha256": full_save_runtime["plugin"]["sha256"]})
        source_records.extend({"path": p["archived_path"], "sha256": p["sha256"]} for p in recovery_runtime["plugins"])
        source_records.append({"path": appearance_runtime["plugin"]["archived_path"], "sha256": appearance_runtime["plugin"]["sha256"]})
        source_records.append({"path": appearance_detail_runtime["plugin"]["archived_path"], "sha256": appearance_detail_runtime["plugin"]["sha256"]})
        source_records.append({"path": appearance_hair_runtime["plugin"]["archived_path"], "sha256": appearance_hair_runtime["plugin"]["sha256"]})
        source_records.append({"path": consumers_runtime["plugin"]["archived_path"], "sha256": consumers_runtime["plugin"]["sha256"]})
        source_records.append({"path": mission_consumers_runtime["plugin"]["archived_path"], "sha256": mission_consumers_runtime["plugin"]["sha256"]})
        for selected in [natural_mission_runtime, appearance_boundary_runtime, paid_skill_runtime, skin_preset_runtime, timed_paint_runtime, natural_paint_runtime]:
            source_records.append({"path": selected["plugin"]["archived_path"], "sha256": selected["plugin"]["sha256"]})
        source_records.extend({"path": item["archived_path"], "sha256": item["sha256"]} for item in paid_skill_diagnostic["plugins"])
        source_records.extend({"path": item["archived_path"], "sha256": item["sha256"]} for item in timed_paint_diagnostic["plugins"])
        source_records.extend({"path": item["archived_path"], "sha256": item["sha256"]} for item in natural_paint_diagnostic["plugins"])
        source_records.extend({**output, "verify_cache_output": True} for output in toolchain["build_outputs"])
        source_records.append({"path": toolchain["editor_path"], "sha256": toolchain["editor_sha256"]})
        for source in source_records:
            # Derived SQLite byte identity is not portable after rebuilding it;
            # reconstruction scripts validate its build identity and coordinates.
            if ".cache" in Path(source["path"]).parts and not source.get("verify_cache_output"):
                continue
            if source["path"].casefold() not in known:
                paths.append((Path(source["path"]), source["sha256"]))
                known.add(source["path"].casefold())
        for path, expected in paths:
            actual = digest(path)
            check(actual == expected, f"Input fingerprint differs: {path}")
            checked_inputs.append({"path": str(path), "sha256": actual})
        # verify-minimal already hashed these package/editor files and admitted
        # managed inspection subjects; retain their identities in the global index.
        for item in minimal_runtime["build"]["files"] + minimal_runtime["packaged_inputs"] + [minimal_runtime["build"]["editor"]] + locomotion_runtime["build"]["files"] + locomotion_runtime["packaged_inputs"] + interaction_runtime["build"]["files"] + interaction_runtime["packaged_inputs"]:
            if item["path"].casefold() not in known:
                checked_inputs.append({"path": item["path"], "sha256": item["sha256"]})
                known.add(item["path"].casefold())
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
