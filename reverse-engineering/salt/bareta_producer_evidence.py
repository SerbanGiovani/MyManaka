"""Verify bounded producer instructions and parse the shipped Sad AnimationEvent.

Reads original metadata/native bytes and the already decrypted models bundle.
Does not run game code or open REA. Iced text records are observations; this
verifier checks their source bytes, not a second disassembler implementation.
"""
import sys
sys.dont_write_bytecode = True

import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import struct

from metadata import DEFAULT_ROOT, HERE, PE, Metadata

sys.path.insert(0, str(HERE.parent / "assets"))
from inspect_player import models_investigation, type_tree_spans
from inspect_resources import Reader

OUTPUT = HERE / "symbols/bareta-producer-candidates.json"


def build():
    result = json.loads(OUTPUT.read_text(encoding="utf-8"))
    native = (DEFAULT_ROOT / "GameAssembly.dll").read_bytes()
    md = Metadata((DEFAULT_ROOT / "SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat").read_bytes())
    pe = PE(native)
    for source in result["sources"]:
        assert hashlib.sha256(Path(source["path"]).read_bytes()).hexdigest() == source["sha256"]
    definition = result["method_definition"]
    assert definition["file_offset"] == md.header[12] + 36 * result["method"]["id"]
    assert md.data[definition["file_offset"]:definition["file_offset"] + 36].hex() == definition["raw_hex"]
    for row in result["instructions"]:
        size = len(bytes.fromhex(row["raw_hex"]))
        assert row["file_offset"] == pe.offset(int(row["va"], 16), size)
        assert native[row["file_offset"]:row["file_offset"] + size].hex() == row["raw_hex"]
    assert 0x18041a977 + struct.unpack_from("<i", native, pe.offset(0x18041a973))[0] == 0x1804b1f70
    usage = result["events_usage"]
    assert native[usage["file_offset"]:usage["file_offset"] + 8].hex() == usage["raw_hex"]
    assert struct.unpack_from("<Q", native, usage["file_offset"])[0] == 0x20007bff
    assert struct.unpack_from("<Q", native, usage["runtime_type_pointer_file_offset"])[0] == int(usage["runtime_type_va"], 16)
    type_offset = pe.offset(int(usage["runtime_type_va"], 16), 12)
    assert type_offset == usage["runtime_type_file_offset"]
    assert native[type_offset:type_offset + 12].hex() == usage["runtime_type_raw_hex"]
    type_data, type_bits = struct.unpack_from("<QI", native, type_offset)
    assert type_data == 2663 and (type_bits >> 16) & 255 == 18
    registration = json.loads((HERE / "symbols/field-offsets.json").read_text(encoding="utf-8"))["registration"]["fields"]
    specs_offset = pe.offset(registration["methodSpecs"]["value"])
    specs_count = registration["methodSpecsCount"]["value"]
    assert specs_count == result["method_spec_boundary"]["method_specs_count"]
    assert not any(struct.unpack_from("<i", native, specs_offset + 12 * i)[0] == 17247 for i in range(specs_count))
    field = result["static_event_field"]
    assert md.data[field["metadata"]["metadata_file_offset"]:field["metadata"]["metadata_file_offset"] + 12].hex(" ") == field["metadata"]["raw_hex"]
    assert struct.unpack_from("<i", native, field["field_offset_entry_file_offset"])[0] == 0x28

    models_path = HERE / ".cache/decrypted/models.unity3d"
    models = models_investigation(models_path)
    node = next(n for n in models.nodes if not n.endswith((".resS", ".resource")))
    metadata = models.metadata(node)
    clips = [o for o in metadata["objects"] if o["class_id"] == 74]
    selected = [(o, models.raw(node, o)) for o in clips if o["path_id"] == -4167274116460597170]
    assert len(selected) == 1
    obj, raw = selected[0]
    tree = metadata["types"][obj["type_index"]]["tree"]
    children, stack = {i: [] for i in range(len(tree))}, []
    for i, entry in enumerate(tree):
        while stack and tree[stack[-1]]["level"] >= entry["level"]:
            stack.pop()
        if stack:
            children[stack[-1]].append(i)
        stack.append(i)
    reader = Reader(raw)

    def skip(index):
        entry = tree[index]
        if entry["type"] == "$common:840":
            reader.aligned_string()
        elif entry["byte_size"] >= 0:
            reader.take(entry["byte_size"])
        elif entry["type_flags"] & 1:
            count = reader.number("i")
            assert 0 <= count <= 10_000_000 and len(children[index]) == 2
            element = children[index][1]
            schema = tree[element]
            if schema["byte_size"] >= 0 and not schema["meta_flags"] & 0x4000:
                reader.take(schema["byte_size"] * count)
            else:
                for _ in range(count):
                    skip(element)
        else:
            for child in children[index]:
                skip(child)
        if entry["meta_flags"] & 0x4000:
            reader.align()

    for index in children[0]:
        if tree[index]["name"] == "m_Events":
            break
        skip(index)
    else:
        raise AssertionError("No embedded m_Events schema")
    assert index == 510 and reader.position == 30832
    count_offset = reader.position
    events = []
    for _ in range(reader.number("i")):
        start = reader.position
        event = {"time": reader.number("f"), "functionName": reader.aligned_string(),
                 "stringParameter": reader.aligned_string(),
                 "objectReferenceParameter": {"file_id": reader.number("i"), "path_id": reader.number("q")},
                 "floatParameter": reader.number("f"), "intParameter": reader.number("i"),
                 "messageOptions": reader.number("i")}
        events.append({"serialized_offset": start, "serialized_end": reader.position,
                       "raw_hex": raw[start:reader.position].hex(), "value": event})
    reader.align()
    assert reader.position == len(raw) == 30880
    assert len(events) == 1 and events[0]["value"]["functionName"] == "OnEndSad"
    result["sad_animation_event"] = {
        "evidence_type": "Full embedded type-tree cursor traversal plus actual AnimationEvent decoding to EOF",
        "models_source": {"path": str(models_path.resolve()), "size": models_path.stat().st_size,
                          "sha256": hashlib.sha256(models_path.read_bytes()).hexdigest()},
        "source": models.identity(node, obj, raw), "clip_name": Reader(raw).aligned_string(),
        "schema": type_tree_spans(models, node, obj["type_index"]),
        "events_count_serialized_offset": count_offset, "events": events,
        "bytes_consumed": reader.position, "end_of_object_verified": True,
        "boundary": "Proves a shipped Sad clip has this event. Actual Animator assignment, playback/completion and delivery to a component are not runtime observations."}
    inventory, function_counts = [], Counter()
    for clip in clips:
        assert clip["type_index"] == obj["type_index"], "A new clip schema needs independent review"
        clip_raw = models.raw(node, clip)
        reader = Reader(clip_raw)
        for index in children[0]:
            if tree[index]["name"] == "m_Events":
                break
            skip(index)
        events_offset = reader.position
        count = reader.number("i")
        assert 0 <= count <= 100_000
        event_functions = []
        for _ in range(count):
            reader.number("f")
            function = reader.aligned_string()
            event_functions.append(function)
            function_counts[function] += 1
            reader.aligned_string()
            reader.number("i"); reader.number("q")
            reader.number("f"); reader.number("i"); reader.number("i")
        reader.align()
        assert reader.position == len(clip_raw), (clip["path_id"], reader.position, len(clip_raw))
        inventory.append({"path_id": clip["path_id"], "serialized_file_offset": clip["offset"],
                          "size": clip["size"], "sha256": hashlib.sha256(clip_raw).hexdigest(),
                          "name": Reader(clip_raw).aligned_string(), "events_count_offset": events_offset,
                          "event_count": count, "event_function_names": event_functions,
                          "bytes_consumed": reader.position, "end_of_object_verified": True})
    result["bounded_animation_inventory"] = {
        "node": node, "clip_count": len(clips), "total_object_bytes": sum(o["size"] for o in clips),
        "schema_type_index": obj["type_index"], "all_objects_consumed_to_eof": True,
        "function_counts": dict(sorted(function_counts.items())),
        "OnAnimBaretaSound_count": function_counts["OnAnimBaretaSound"], "clips": inventory,
        "boundary": "All260 class74 objects in this already decrypted models bundle only; absence here does not exclude original data.unity3d, other bundles, controller behavior or runtime-created events."}
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    result = build()
    if args.check:
        assert json.loads(OUTPUT.read_text(encoding="utf-8")) == result
    else:
        OUTPUT.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"status": "consistent" if args.check else "written", "instructions": len(result["instructions"]),
                      "animation_events": len(result["sad_animation_event"]["events"])}))


if __name__ == "__main__":
    main()
