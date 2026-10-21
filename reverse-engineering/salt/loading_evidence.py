"""Bind saved REA loading observations to original metadata usages and call bytes.

Does not disassemble: E8 sites are corroborating byte candidates only. The saved
Ghidra pseudocode establishes the displayed calls; indirect/vtable targets remain
separate from direct calls. No game or original DLL is executed.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import sqlite3
import struct
import sys

from metadata import DEFAULT_ROOT, HERE, Metadata, PE
from prepare_batch import label
sys.path.insert(0, str(HERE.parent / "assets"))
from inspect_resources import Bundle, serialized_metadata

BATCHES = ("loading", "loading-game", "loading-guards", "loading-thunks")


def build():
    identity = json.loads((HERE / "evidence/artifact-identity.json").read_text(encoding="utf-8"))
    native = (DEFAULT_ROOT / "GameAssembly.dll").read_bytes()
    raw = (DEFAULT_ROOT / "SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat").read_bytes()
    assert hashlib.sha256(native).hexdigest() == identity["native_sha256"]
    assert hashlib.sha256(raw).hexdigest() == identity["metadata_sha256"]
    pe, metadata = PE(native), Metadata(raw)
    literals, heap = metadata.records(2, "<II"), metadata.region(4)
    connection = sqlite3.connect((HERE / ".cache/methods.sqlite").as_uri() + "?mode=ro", uri=True)
    connection.row_factory = sqlite3.Row
    methods = {r["id"]: dict(r) for r in connection.execute("SELECT * FROM methods")}
    database_identity = dict(connection.execute("SELECT * FROM identity"))
    connection.close()
    assert all(database_identity[k] == identity[k] for k in ("native_sha256", "metadata_sha256"))
    type_indices = {}
    for type_id, t in enumerate(metadata.records(40, "<16i8H2I")):
        type_indices[t[2]] = {"type_id": type_id, "qualified_name": ".".join(filter(None, (metadata.string(t[1]), metadata.string(t[0]))))}
    observations, native_observations, runs = {}, [], []
    for batch in BATCHES:
        directory = HERE / "evidence" / batch
        run = json.loads((directory / "run.json").read_text(encoding="utf-8"))
        assert run["success"] and not run.get("close_error") and not run.get("transport_close_error")
        runs.append({"directory": f"salt/evidence/{batch}", "observations": len(run["functions"]),
                     "elapsed_seconds": run["elapsed_seconds"]})
        for entry in run["functions"]:
            path = directory / f"{entry['file_stem']}-{entry['operation']}.json"
            evidence = json.loads(path.read_text(encoding="utf-8"))
            assert evidence["subject"]["digest"]["sha256"] == identity["native_sha256"]
            assert evidence["evidence_id"] == entry["evidence_id"]
            if entry["metadata_id"] is None:
                native_observations.append({"va": entry["va"], "text": evidence["normalized_result"],
                    "evidence_id": evidence["evidence_id"], "path": path.relative_to(HERE.parent).as_posix()})
                continue
            method = methods[entry["metadata_id"]]
            assert method["va"] == entry["va"] and method["token"] == int(entry["token"], 16)
            observations[method["id"]] = {"method": method, "text": evidence["normalized_result"],
                "evidence_id": evidence["evidence_id"], "path": path.relative_to(HERE.parent).as_posix()}

    def usage(va):
        try:
            offset = pe.offset(va, 8)
        except ValueError:
            return None  # BSS runtime globals have no original encoded usage bytes.
        encoded = struct.unpack_from("<Q", native, offset)[0]
        if encoded >> 32 or not encoded & 1:
            return None
        tag, index = encoded >> 29, (encoded & 0x1fffffff) >> 1
        common = {"usage_va": hex(va), "native_file_offset": offset,
                  "raw_hex": native[offset:offset + 8].hex(), "encoded_usage": hex(encoded), "tag": tag}
        if tag == 5:
            length, start = literals[index]
            value = heap[start:start + length]
            assert len(value) == length
            return {**common, "kind": "string-literal", "literal_id": index,
                    "metadata_file_offset": metadata.header[4] + start, "byte_length": length,
                    "value": value.decode("utf-8")}
        if tag == 3 and index in methods:
            m = methods[index]
            return {**common, "kind": "method-definition", "metadata_id": index,
                    "qualified_name": m["qualified_name"], "token": hex(m["token"]), "va": m["va"]}
        if tag == 1 and index in type_indices:
            return {**common, "kind": "type-info", "runtime_type_index": index, **type_indices[index]}
        return None

    usages = {}
    for mid, obs in list(observations.items()) + [("native:" + item["va"], item) for item in native_observations]:
        for match in re.finditer(r"(?:uRam|plRam|lRam|DAT_)0*([0-9a-f]{9,16})", obs["text"]):
            address = int(match[1], 16)
            value = usage(address)
            if value is not None:
                if address not in usages:
                    usages[address] = {**value, "referenced_by": []}
                if mid not in usages[address]["referenced_by"]:
                    usages[address]["referenced_by"].append(mid)
    callback = observations[16376]
    matches = list(re.finditer(r"IKA9nt_Encrypter_EncrypterCore__LoadAssetAsync__06000084\s*"
        r"\(uRam0*([0-9a-f]+),uRam0*([0-9a-f]+),", callback["text"]))
    assert len(matches) == 25, "Unexpected title asset request count"
    asset_requests = []
    for match in matches:
        bundle, asset = usage(int(match[1], 16)), usage(int(match[2], 16))
        assert bundle["value"] == "models"
        asset_requests.append({"label": bundle["value"], "name": asset["value"],
                               "label_usage_va": bundle["usage_va"], "asset_usage_va": asset["usage_va"],
                               "evidence_id": callback["evidence_id"]})
    # These are deliberately selected caller/callee hypotheses, checked against
    # displayed Ghidra calls and original relative-call bytes, not a global graph.
    pairs = [(16362, 76290), (16376, 76301)] + [
        (source, target) for source in (76288, 76290, 76292, 76294)
        for target in (76304, 76349, 76337)] + [
        (76288, 76342), (76290, 76342), (76292, 76342), (76279, 76282),
        (76294, 76177), (76294, 76247), (76257, 76250)]
    starts = sorted({int(m["va"], 16) for m in methods.values() if m["va"]})
    edges = []
    for source, target in pairs:
        obs, dest = observations[source], methods[target]
        target_label = label(dest)
        if not re.search(r"\b" + re.escape(target_label) + r"\s*\(", obs["text"]):
            continue  # Inlining or unresolved targets do not create a displayed edge.
        start = int(obs["method"]["va"], 16)
        end = next((a for a in starts if a > start), start)
        begin = pe.offset(start, executable=True)
        block = native[begin:begin + end - start]
        sites = []
        for pos in range(max(0, len(block) - 4)):
            if block[pos] == 0xe8 and start + pos + 5 + struct.unpack_from("<i", block, pos + 1)[0] == int(dest["va"], 16):
                sites.append({"va": hex(start + pos), "file_offset": begin + pos, "bytes": block[pos:pos + 5].hex()})
        edges.append({"source_metadata_id": source, "target_metadata_id": target,
                      "target_name": dest["qualified_name"], "target_va": dest["va"],
                      "evidence_id": obs["evidence_id"], "displayed_call": target_label,
                      "corroborating_e8_sites": sites})
    assert len(next(e for e in edges if e["source_metadata_id"] == 16376)["corroborating_e8_sites"]) == 25
    assert next(e for e in edges if e["source_metadata_id"] == 16362)["corroborating_e8_sites"][0]["va"] == "0x18046f08e"
    declarations = json.loads((HERE / "symbols/loading-declarations.json").read_text(encoding="utf-8"))
    prefab = declarations["original_resource_prefab"]
    assert prefab["source_sha256"] == json.loads((HERE.parent / "assets/resources-keydata.json").read_text(encoding="utf-8"))["source_sha256"]
    bundle = Bundle(Path(prefab["source"]))
    try:
        nodes = {n["name"]: n for n in bundle.nodes}
        for name in ("gameobject", "encrypter_core_instance"):
            record = prefab[name]
            obj = record["object"]
            original = bundle.read(nodes[record["node"]]["offset"] + obj["offset"], obj["size"])
            assert original == bytes.fromhex(record["raw_hex"])
            assert hashlib.sha256(original).hexdigest() == record["sha256"]
        rm = prefab["resource_manager"]
        obj = rm["object"]
        raw_rm = bundle.read(rm["node"]["offset"] + obj["offset"], obj["size"])
        assert hashlib.sha256(raw_rm).hexdigest() == rm["sha256"]
        position = rm["entry"]["key_offset_in_object"]
        length = struct.unpack_from("<I", raw_rm, position)[0]
        assert raw_rm[position + 4:position + 4 + length].decode("utf-8") == rm["entry"]["name"]
        pointer_position = (position + 4 + length + 3) & ~3
        assert struct.unpack_from("<iq", raw_rm, pointer_position) == (3, 3629)
        global_meta = serialized_metadata(bundle, nodes["globalgamemanagers"])
        assert global_meta["external_references"][2]["path"] == "resources.assets"
        core = bytes.fromhex(prefab["encrypter_core_instance"]["raw_hex"])
        assert struct.unpack_from("<iq", core, 32) == (0, 61594)
        assert struct.unpack_from("<2i", core, 44) == (256, 0)
    finally:
        bundle.file.close()
    return {"schema_version": 1, "kind": "static-loading-chain-bindings", "native_sha256": identity["native_sha256"],
            "metadata_sha256": identity["metadata_sha256"], "batches": runs,
            "methods": [{"metadata_id": mid, "qualified_name": obs["method"]["qualified_name"],
                         "va": obs["method"]["va"], "token": hex(obs["method"]["token"]),
                         "evidence_id": obs["evidence_id"], "path": obs["path"]} for mid, obs in sorted(observations.items())],
            "native_only_procedures": [{k: v for k, v in obs.items() if k != "text"} for obs in native_observations],
            "metadata_usages": [usages[a] for a in sorted(usages)], "title_asset_requests": asset_requests,
            "selected_displayed_call_edges": edges,
            "original_prefab_verified": {"resource_path": rm["entry"]["name"], "resource_manager_path_id": 13,
                "gameobject_path_id": 3629, "core_path_id": 63738, "keydata_path_id": 61594,
                "load_buffer_size": 256, "load_speed_on_memory_load_async": 0,
                "coordinate_kind": "serialized object fields, not native object offsets"},
            "limitations": ["REA pseudocode is a static observation, not original source or runtime execution.",
                "E8 bytes are not an independent instruction decoder; candidate sites are bounded by adjacent mapped method starts and corroborate displayed calls only.",
                "Method-definition usages identify delegate targets but do not prove callbacks executed.",
                "Generic method-reference usages (tag 6), vtable calls and Unity engine implementation remain unresolved here."]}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    result = build()
    path = HERE / "evidence/loading-chain.json"
    if args.check:
        assert result == json.loads(path.read_text(encoding="utf-8")), "Saved chain bindings differ"
    else:
        path.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"methods": len(result["methods"]), "metadata_usages": len(result["metadata_usages"]),
                      "asset_requests": len(result["title_asset_requests"]),
                      "displayed_call_edges": len(result["selected_displayed_call_edges"])}, indent=2))
