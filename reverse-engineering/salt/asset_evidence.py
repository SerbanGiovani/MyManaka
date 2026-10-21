"""Recheck native dispatch metadata and bind all 25 callbacks to named cache fields.

Uses original bytes and saved REA observations; never loads game code. Empty
REA listing responses are retained as unavailable, not instruction evidence.
"""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import re
import sqlite3
import struct

from metadata import DEFAULT_ROOT, HERE, Metadata, PE


def read(path):
    return json.loads(path.read_text(encoding="utf-8-sig"))


def build():
    identity = read(HERE / "evidence/artifact-identity.json")
    data = (DEFAULT_ROOT / "GameAssembly.dll").read_bytes()
    raw = (DEFAULT_ROOT / "SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat").read_bytes()
    assert hashlib.sha256(data).hexdigest() == identity["native_sha256"]
    assert hashlib.sha256(raw).hexdigest() == identity["metadata_sha256"]
    pe, metadata = PE(data), Metadata(raw)
    types, method_defs = metadata.records(40, "<16i8H2I"), metadata.records(12, "<6iI4H")
    field_defs, literals, heap = metadata.records(24, "<iiI"), metadata.records(2, "<II"), metadata.region(4)
    type_names = {i: ".".join(filter(None, (metadata.string(t[1]), metadata.string(t[0])))) for i, t in enumerate(types)}
    byval = {t[2]: i for i, t in enumerate(types)}
    connection = sqlite3.connect((HERE / ".cache/methods.sqlite").as_uri() + "?mode=ro", uri=True)
    connection.row_factory = sqlite3.Row
    methods = {r["id"]: dict(r) for r in connection.execute("SELECT * FROM methods")}
    assert all(dict(connection.execute("SELECT * FROM identity"))[k] == identity[k] for k in ("native_sha256", "metadata_sha256"))
    connection.close()
    records, batches = [], []
    for path in sorted((HERE / "evidence").glob("asset-*/run.json")):
        run = read(path)
        assert run["success"] and not run.get("close_error") and not run.get("transport_close_error")
        batches.append({"name": path.parent.name, "queries": len(run["functions"]), "elapsed_seconds": run["elapsed_seconds"]})
        for entry in run["functions"]:
            evidence_path = path.parent / f"{entry['file_stem']}-{entry['operation']}.json"
            record = read(evidence_path)
            assert record["evidence_id"] == entry["evidence_id"]
            assert record["subject"]["digest"]["sha256"] == identity["native_sha256"]
            if entry["metadata_id"] is not None:
                m = methods[entry["metadata_id"]]
                assert m["va"] == entry["va"] and m["token"] == int(entry["token"], 16)
            records.append({"metadata_id": entry["metadata_id"], "va": entry["va"], "operation": entry["operation"],
                            "evidence_id": record["evidence_id"], "path": evidence_path.relative_to(HERE.parent).as_posix(),
                            "text": record["normalized_result"]})
    pseudo = {r["metadata_id"]: r for r in records if r["operation"] == "procedure_pseudo_code" and r["metadata_id"] is not None}
    unavailable = [{k: v for k, v in r.items() if k != "text"} for r in records if not r["text"].strip()]

    def usage(address):
        va = int(address, 0) if isinstance(address, str) else address
        offset = pe.offset(va, 8)
        value = struct.unpack_from("<Q", data, offset)[0]
        assert not value >> 32 and value & 1
        tag, index = value >> 29, (value & 0x1fffffff) >> 1
        result = {"va": hex(va), "file_offset": offset, "encoded": hex(value), "raw_hex": data[offset:offset + 8].hex(), "tag": tag, "index": index}
        if tag == 5:
            size, start = literals[index]
            result["value"] = heap[start:start + size].decode("utf-8")
        elif tag in (1, 2) and index in byval:
            result.update(type_id=byval[index], type_name=type_names[byval[index]])
        elif tag == 3:
            result.update(method_id=index, method_name=methods[index]["qualified_name"], method_va=methods[index]["va"])
        return result

    dispatch = read(HERE / "symbols/dispatch-metadata.json")
    offsets = read(HERE / "symbols/field-offsets.json")
    registration = offsets["registration"]
    assert data[registration["file_offset"]:registration["file_offset"] + 128] == bytes.fromhex(registration["raw_hex"])
    rows = offsets["all_type_field_offset_rows"]
    assert len(rows) == len(types) == 10508
    for row in rows:
        t = types[row["type_id"]]
        assert row["first_field_id"] == t[8] and row["field_count"] == t[18]
        pointer = struct.unpack_from("<Q", data, row["offset_row_pointer_file_offset"])[0]
        assert hex(pointer) == row["offset_row_va"]
        count = row["field_count"]
        if count:
            start = pe.offset(pointer, count * 4)
            assert start == row["offset_row_file_offset"]
            assert list(struct.unpack_from(f"<{count}i", data, start)) == row["raw_offsets"]
        sizes = struct.unpack_from("<IiII", data, row["type_size_file_offset"])
        assert sizes == tuple(row["type_sizes"][k] for k in ("instance_size", "native_size", "static_fields_size", "thread_static_fields_size"))
    named = {t["full_name"]: t for t in offsets["named_types"]}
    for t in named.values():
        for field in t["fields"]:
            definition = field_defs[field["field_id"]]
            assert metadata.string(definition[0]) == field["name"] and hex(definition[2]) == field["token"]
            assert struct.unpack_from("<i", data, field["field_offset_entry_file_offset"])[0] == field["raw_offset"]
    bridge = next(t for t in dispatch["original_types"] if t["type_id"] == 9778)
    interface = types[9783]
    assert interface[7] & 0x20 and method_defs[76264][9] == 2
    interface_pairs = metadata.records(38, "<ii")
    actual_pairs = interface_pairs[types[9778][15]:types[9778][15] + types[9778][23]]
    assert (interface[2], 4) in actual_pairs
    implementations = [i for i, t in enumerate(types) if any(p[0] == interface[2] for p in interface_pairs[t[15]:t[15] + t[23]])]
    assert implementations == [9778]
    proof = dispatch["slot2_dispatch_proof"]
    entry = proof["vtable_entry"]
    encoded = struct.unpack_from("<I", raw, entry["metadata_file_offset"])[0]
    assert encoded == 0x60025389 and ((encoded & 0x1fffffff) >> 1) == 76228
    assert entry["class_slot"] == 6 and proof["interface_offset"] == 4
    assert entry["metadata_file_offset"] == metadata.header[36] + (types[9778][14] + 6) * 4
    assert method_defs[76228][9] == 6 and methods[76228]["va"] == "0x181433c90"
    request = named["UnityEngine.AssetBundleRequest"]
    getter_entry = next(e for e in request["vtable"] if e["class_slot"] == 4)
    assert getter_entry["metadata_file_offset"] == metadata.header[36] + (types[request["type_id"]][14] + 4) * 4
    encoded_getter = struct.unpack_from("<I", raw, getter_entry["metadata_file_offset"])[0]
    assert ((encoded_getter & 0x1fffffff) >> 1) == 78749
    allocated = usage(0x182d64c98)
    assert allocated["type_id"] == 9778
    load_type = usage(0x182d561c0)
    assert load_type["type_name"] == "UnityEngine.Object"

    asset_fields = {f["raw_offset"]: f for f in named["ExposureUnnoticed2.Object3D.IngameManager.AssetReferencer"]["fields"] if not f["is_static"]}
    title_field = next(f for f in named["ExposureUnnoticed2.Scripts.UI.TitleSceneView"]["fields"] if f["name"] == "IsEndLoadCount")
    assert title_field["raw_offset"] == 0xb4
    title = read(HERE / "evidence/loading-game/16376-060013af-procedure_pseudo_code.json")
    call_matches = list(re.finditer(r"FUN_180665bb0\(uVar1,param_1,uRam0*([0-9a-f]+),0\);.*?"
        r"IKA9nt_Encrypter_EncrypterCore__LoadAssetAsync__06000084\s*\(uRam0*([0-9a-f]+),uRam0*([0-9a-f]+),", title["normalized_result"], re.S))
    assert len(call_matches) == 25
    requests = []
    for ordinal, match in enumerate(call_matches):
        delegate, bundle, resource = (usage(int(match[i], 16)) for i in (1, 2, 3))
        mid = delegate["method_id"]
        assert mid == 16377 + ordinal and bundle["value"] == "models" and ">" not in resource["value"]
        obs, index = pseudo[mid], None
        text = obs["text"]
        assert "*(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + 1;" in text
        if ordinal < 5:
            offset = 0x328 if ordinal < 2 else 0x320
            assert f"+ {hex(offset)}" in text or f"+ {offset}" in text
            store = re.search(r"\(lVar3 \+ (0x[0-9a-f]+|\d+)\) = plVar6;", text)
            assert store
            index = (int(store[1], 0) - 0x20) // 8
            result_type = "UnityEngine.GameObject"
        else:
            stores = {int(value, 0) for value in re.findall(r"\(lVar2 \+ (0x[0-9a-f]+|\d+)\) = (?:0|param_2|plVar\d+);", text)}
            assert len(stores) == 1
            offset = stores.pop()
            f = asset_fields[offset]
            result_type = type_names[f["runtime_type"]["data"]]
        field = asset_fields[offset]
        requests.append({"ordinal": ordinal + 1, "label": bundle["value"], "asset_name": resource["value"],
            "engine_name_after_lowercase": resource["value"].lower(), "engine_api": "UnityEngine.AssetBundle.LoadAssetAsync_Internal(System.String,System.Type)",
            "callback_method_id": mid, "callback_name": methods[mid]["qualified_name"], "callback_va": methods[mid]["va"],
            "callback_usage": delegate, "asset_usage": resource, "callback_evidence_id": obs["evidence_id"],
            "callback_path": obs["path"], "result_type": result_type, "cache_owner": "AssetReferencer.instance",
            "cache_field": field["name"], "cache_field_offset": hex(offset), "array_index": index,
            "increments_counter_before_cast_and_store": True, "instantiates_in_callback": False})
    assert [r["array_index"] for r in requests[:5]] == [0, 1, 0, 5, 6]
    generics = read(HERE / "symbols/instantiation-generics.json")

    def validate_coordinate_bytes(value):
        if isinstance(value, dict):
            for offset_key, bytes_key, source in [("file_offset", "raw_hex", data),
                    ("metadata_file_offset", "raw_hex", raw), ("usage_file_offset", "usage_raw_bytes", data),
                    ("field_definition_file_offset", "field_definition_raw_hex", raw),
                    ("field_offset_entry_file_offset", "field_offset_raw_hex", data)]:
                if isinstance(value.get(offset_key), int) and isinstance(value.get(bytes_key), str):
                    start, expected = value[offset_key], bytes.fromhex(value[bytes_key])
                    assert source[start:start + len(expected)] == expected, (offset_key, start)
            for item in value.values():
                validate_coordinate_bytes(item)
        elif isinstance(value, list):
            for item in value:
                validate_coordinate_bytes(item)
    validate_coordinate_bytes(generics)
    consumers = {"MultipleDroppedPrefabs": [16710], "DroppedPrefabs": [16710], "Player": [16862], "UiPlayer": [13846],
        "SweatBody": [14624], "ClothesPaint": [14624], "Inmon": [14623], "Rakugaki": [14623],
        **{field: [14623] for field in ["TattooDark", "TattooFlower1", "TattooFlower2", "TattooLotus", "TattooSatanism", "TattooSlave"]},
        "RubberSuit": [14623, 14624], "FutanariPaint": [15066], "FutanariMaterial": [15066], "FutanariRubberMaterial": [15066],
        "RubberSuitBlack": [14627], "RubberSuitWhite": [14627], "MCustomizeColor": [16265], "MHair": [16087]}
    for request_record in requests:
        ids = consumers[request_record["cache_field"]]
        offset = int(request_record["cache_field_offset"], 16)
        for mid in ids:
            assert re.search(r"\+\s*(?:" + re.escape(hex(offset)) + "|" + str(offset) + r")\b", pseudo[mid]["text"])
        request_record["verified_consumer_methods"] = [{"metadata_id": mid, "name": methods[mid]["qualified_name"],
            "evidence_id": pseudo[mid]["evidence_id"], "path": pseudo[mid]["path"]} for mid in ids]
    assert "LoadAssetAsync__0600000f" in pseudo[76228]["text"]
    assert "UnityEngine.AssetBundle::LoadAssetAsync_Internal(System.String,System.Type)" in pseudo[78735]["text"]
    assert "UnityEngine.AssetBundleRequest::GetResult()" in pseudo[78749]["text"]
    assert "Internal_CloneSingleWithParent" in pseudo[49275]["text"]
    assert "GameObject::GetComponentFastPath" in pseudo[49122]["text"]
    return {"schema_version": 1, "kind": "static-asset-dispatch-and-callback-bindings", "native_sha256": identity["native_sha256"],
        "metadata_sha256": identity["metadata_sha256"], "batches": batches,
        "rea_observations": [{k: v for k, v in r.items() if k != "text"} for r in records],
        "nonempty_observations": sum(bool(r["text"].strip()) for r in records), "unavailable_listing_observations": unavailable,
        "validated_field_offset_rows": len(rows), "actual_bridge_allocation": allocated,
        "load_asset_type_parameter": load_type, "interface_dispatch": {"interface_method_id": 76264, "interface_slot": 2,
            "interface_offset": 4, "class_vtable_slot": 6, "method_id": 76228, "va": methods[76228]["va"],
            "raw_entry": hex(encoded), "metadata_file_offset": entry["metadata_file_offset"]},
        "request_get_result_dispatch": {"class_vtable_slot": 4, "method_id": 78749, "va": methods[78749]["va"],
            "metadata_file_offset": getter_entry["metadata_file_offset"], "raw_entry": hex(encoded_getter)},
        "title_request_evidence_id": title["evidence_id"], "result_types": dict(Counter(r["result_type"] for r in requests)),
        "instantiation_generic_usages": [{"usage_va": g["usage_va"], "method_spec_index": g["decoded_method_spec_index"],
            "method_id": g["method_definition"]["method_id"], "method_name": g["method_definition"]["name"]} for g in generics["selected_usages"]],
        "requests": requests, "limitations": ["Static control/data flow, not runtime execution or success of all loads.",
            "The completion counter increments before type validation and cache stores; it is not a success assertion.",
            "All 25 names select the ordinary asset branch; subasset '>' selection was inspected but is not used by these requests.",
            "Empty REA procedure_assembly results prove no instructions; supplemental Iced records supply static instruction observations.",
            "No original pseudocode or seed aliases were edited; actual allocated type comes from original TypeInfo and registration tables."]}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    result = build()
    path = HERE / "evidence/asset-followup.json"
    if args.check:
        assert result == read(path), "Saved asset bindings differ"
    else:
        path.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"requests": len(result["requests"]), "result_types": result["result_types"],
        "nonempty_observations": result["nonempty_observations"], "empty_listing_results": len(result["unavailable_listing_observations"]),
        "validated_field_offset_rows": result["validated_field_offset_rows"]}, indent=2))
