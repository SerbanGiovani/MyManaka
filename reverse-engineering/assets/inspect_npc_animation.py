"""Bound original NPC animation events using matching shipped donor type trees.

Original data.unity3d has no embedded trees. Each decoded object's class,
old_type_hash and engine version must match the already decrypted models donor.
ControllerConstant is traversed only to skip it; no controller graph is inferred.
No game execution, decryption, REA session or Git operation.
"""
import sys
sys.dont_write_bytecode = True

import argparse
from collections import Counter
import json
from pathlib import Path
import re
import struct

from inspect_resources import Reader
from inspect_scenes import SceneInvestigation, fingerprint, read_value
from inspect_player import models_investigation, type_tree_spans, tree_flat_prefix

HERE = Path(__file__).resolve().parent
SALT = HERE.parent / "salt"
TARGET = "OnAnimBaretaSound"


class Cursor:
    def __init__(self, raw, tree):
        self.raw, self.tree, self.reader = raw, tree, Reader(raw)
        self.watched = {}
        self.children, stack = {i: [] for i in range(len(tree))}, []
        for i, entry in enumerate(tree):
            while stack and tree[stack[-1]]["level"] >= entry["level"]:
                stack.pop()
            if stack:
                self.children[stack[-1]].append(i)
            stack.append(i)

    def skip(self, index):
        entry, reader = self.tree[index], self.reader
        start = reader.position
        if entry["type"] == "$common:840":
            reader.aligned_string()
        elif entry["byte_size"] >= 0:
            reader.take(entry["byte_size"])
        elif entry["type_flags"] & 1:
            count = reader.number("i")
            assert 0 <= count <= 10_000_000 and len(self.children[index]) == 2
            element = self.children[index][1]
            schema = self.tree[element]
            if schema["byte_size"] >= 0 and not schema["meta_flags"] & 0x4000:
                reader.take(schema["byte_size"] * count)
            else:
                for _ in range(count):
                    self.skip(element)
        else:
            for child in self.children[index]:
                self.skip(child)
        if entry["meta_flags"] & 0x4000:
            reader.align()
        if entry["name"] in ("m_StartTime", "m_StopTime", "m_CycleOffset", "m_LoopTime", "m_LoopBlend"):
            assert entry["byte_size"] in (1, 4)
            fmt = "?" if entry["byte_size"] == 1 else "f"
            self.watched[entry["name"]] = {"tree_index": index, "serialized_offset": start,
                                          "serialized_end": reader.position,
                                          "value": struct.unpack_from("<" + fmt, self.raw, start)[0],
                                          "raw_hex": self.raw[start:reader.position].hex()}

    def eof(self):
        assert self.reader.position == len(self.raw), (self.reader.position, len(self.raw))
        return {"bytes_consumed": self.reader.position, "end_of_object_verified": True}


def parse_clip(raw, tree):
    cursor = Cursor(raw, tree)
    reader, events = cursor.reader, []
    for index in cursor.children[0]:
        if tree[index]["name"] != "m_Events":
            cursor.skip(index)
            continue
        assert index == 510 and len(tree) == 529
        assert [tree[i]["name"] for i in cursor.children[513]] == [
            "time", "functionName", "$common:106", "objectReferenceParameter",
            "floatParameter", "intParameter", "messageOptions"]
        count_offset = reader.position
        count = reader.number("i")
        assert 0 <= count <= 100_000
        for _ in range(count):
            start = reader.position
            fields = {}
            for name, kind in (("time", "f"), ("functionName", "string"),
                               ("stringParameter", "string"), ("objectReferenceParameter", "PPtr"),
                               ("floatParameter", "f"), ("intParameter", "i"), ("messageOptions", "i")):
                fields[name] = read_value(reader, kind)
            events.append({"serialized_offset": start, "serialized_end": reader.position,
                           "raw_hex": raw[start:reader.position].hex(), "fields": fields})
        reader.align()
    assert set(cursor.watched) == {"m_StartTime", "m_StopTime", "m_CycleOffset", "m_LoopTime", "m_LoopBlend"}
    start_time = cursor.watched["m_StartTime"]["value"]
    stop_time = cursor.watched["m_StopTime"]["value"]
    relations = [{"event_index": i, "time": event["fields"]["time"]["value"],
                  "within_start_stop": start_time <= event["fields"]["time"]["value"] <= stop_time,
                  "stop_minus_event": stop_time - event["fields"]["time"]["value"]}
                 for i, event in enumerate(events)]
    return {"name": Reader(raw).aligned_string(), "events_count_offset": count_offset,
            "event_count": count, "events": events, "clip_timing": cursor.watched,
            "event_timing_relations": relations, **cursor.eof()}


def parse_controller_references(raw, tree):
    cursor = Cursor(raw, tree)
    reader, clips = cursor.reader, []
    spans = []
    for index in cursor.children[0]:
        start = reader.position
        if tree[index]["name"] == "m_AnimationClips":
            assert index == 253
            count = reader.number("i")
            assert 0 <= count <= 100_000
            for _ in range(count):
                clips.append(read_value(reader, "PPtr"))
            if tree[index]["meta_flags"] & 0x4000:
                reader.align()
        else:
            cursor.skip(index)
        spans.append({"tree_index": index, "name": tree[index]["name"],
                      "serialized_offset": start, "serialized_end": reader.position})
    return {"name": Reader(raw).aligned_string(), "clips": clips,
            "top_level_spans": spans, **cursor.eof()}


def build(root, models_path):
    original, models = SceneInvestigation(root), models_investigation(models_path)
    donor_node = next(n for n in models.nodes if not n.endswith((".resS", ".resource")))
    donor_metadata = models.metadata(donor_node)
    donors = {t["class_id"]: t for t in donor_metadata["types"] if t["class_id"] in (74, 91, 95)}
    assert len(donors) == 3 and donor_metadata["has_type_tree"]
    schemas = {str(cid): {"class_id": cid, "old_type_hash": typ["old_type_hash"],
                         "donor_node": donor_node, "donor_type_index": typ["index"],
                         "engine_version": donor_metadata["engine_version"],
                         "type_tree": type_tree_spans(models, donor_node, typ["index"])}
               for cid, typ in donors.items()}
    node_inventory, clips, controllers, animators, target_keys = [], [], [], [], set()
    original_type_records = {}

    def matched(node, obj):
        metadata = original.metadata(node)
        typ = metadata["types"][obj["type_index"]]
        donor = donors[obj["class_id"]]
        assert not metadata["has_type_tree"]
        assert metadata["engine_version"] == donor_metadata["engine_version"]
        assert typ["old_type_hash"] == donor["old_type_hash"]
        return {"source_has_type_tree": False, "matching_old_type_hash": typ["old_type_hash"],
                "donor_schema_class_id": obj["class_id"], "original_type_index": obj["type_index"],
                "original_type_record": original_type_records[node][obj["type_index"]]}

    nodes = [n for n in original.nodes if n.endswith(".assets") or re.fullmatch(r"level\d+", n)
             or n in ("globalgamemanagers", "Resources/unity_builtin_extra")]
    for node in nodes:
        metadata = original.metadata(node)
        assert not metadata["has_type_tree"]
        metadata_raw = original.bundle.read(original.nodes[node]["offset"] + 48, metadata["metadata_size"])
        type_reader = Reader(metadata_raw)
        type_reader.string(); type_reader.number("i")
        assert not type_reader.number("?")
        assert type_reader.number("i") == len(metadata["types"])
        original_type_records[node] = {}
        for typ in metadata["types"]:
            start = type_reader.position
            assert type_reader.number("i") == typ["class_id"]
            type_reader.take(3)
            if typ["class_id"] == 114:
                type_reader.take(16)
            assert type_reader.take(16).hex() == typ["old_type_hash"]
            original_type_records[node][typ["index"]] = {
                "offset_in_metadata": start, "serialized_file_offset": 48 + start,
                "uncompressed_stream_offset": original.nodes[node]["offset"] + 48 + start,
                "raw_hex": metadata_raw[start:type_reader.position].hex()}
        selected = [o for o in metadata["objects"] if o["class_id"] in donors]
        node_inventory.append({"node": node, "engine_version": metadata["engine_version"],
                               "source_has_type_tree": metadata["has_type_tree"],
                               "metadata_sha256": metadata["metadata_sha256"],
                               "selected_class_counts": {str(k): v for k, v in sorted(Counter(o["class_id"] for o in selected).items())},
                               "external_references": metadata["external_references"]})
        for obj in selected:
            proof = matched(node, obj)
            raw = original.raw(node, obj)
            base = {"source": original.identity(node, obj, raw), "schema_match": proof}
            if obj["class_id"] == 74:
                parsed = parse_clip(raw, donors[74]["tree"])
                entry = {**base, **parsed}
                clips.append(entry)
                if any(e["fields"]["functionName"]["value"] == TARGET for e in parsed["events"]):
                    target_keys.add((node, obj["path_id"]))
            elif obj["class_id"] == 91:
                controllers.append({**base, **parse_controller_references(raw, donors[91]["tree"])})
            else:
                # tree_flat_prefix consults the target metadata; temporarily provide
                # this verified matching donor tree in memory only.
                typ = metadata["types"][obj["type_index"]]
                typ["tree"] = donors[95]["tree"]
                try:
                    parsed = tree_flat_prefix(original, node, obj)
                finally:
                    typ.pop("tree", None)
                assert parsed["end_of_object_verified"]
                animators.append({**base, "parsed": parsed})

    controller_keys, linked_controllers = set(), []
    for entry in controllers:
        node = entry["source"]["node"]
        matches = []
        for index, pointer in enumerate(entry["clips"]):
            target = original.pointer(node, **pointer["value"])
            if target and "object" in target and (target["node"], target["object"]["path_id"]) in target_keys:
                matches.append({"clip_index": index, "pointer": pointer, "resolved_target": target})
        if matches:
            controller_keys.add((node, entry["source"]["object"]["path_id"]))
            linked_controllers.append({**entry, "target_clip_references": matches})

    linked_animators = []
    for entry in animators:
        fields = entry["parsed"]["fields"]
        controller = next(f for f in fields if f["name"] == "m_Controller")["resolved_target"]
        if not controller or "object" not in controller:
            continue
        if (controller["node"], controller["object"]["path_id"]) not in controller_keys:
            continue
        go = next(f for f in fields if f["name"] == "$common:374")["resolved_target"]
        gameobject = original.gameobject(go["node"], go["object"])
        scripts = []
        for pointer in gameobject["components"]:
            component = original.pointer(go["node"], **pointer)
            if component and "object" in component and component["object"]["class_id"] == 114:
                typ = original.metadata(component["node"])["types"][component["object"]["type_index"]]
                script = original.script(component["node"], typ)
                scripts.append({"component": component, "script_identity": script})
        linked_animators.append({**entry, "gameobject": gameobject,
                                 "owner_to_root": original.hierarchy(go["node"], go["object"]),
                                 "same_gameobject_scripts": scripts})

    sad_object = models.object(donor_node, -4167274116460597170)
    sad_raw = models.raw(donor_node, sad_object)
    assert donor_metadata["types"][sad_object["type_index"]]["old_type_hash"] == donors[74]["old_type_hash"]
    sad = parse_clip(sad_raw, donors[74]["tree"])
    assert sad["name"] == "Sad" and all(e["within_start_stop"] for e in sad["event_timing_relations"])
    for clip in clips:
        if (clip["source"]["node"], clip["source"]["object"]["path_id"]) in target_keys:
            assert all(e["within_start_stop"] for e in clip["event_timing_relations"])

    return {"schema_version": 1, "evidence_type": "Original objects parsed with class/hash/engine-matched shipped donor schemas and EOF validation",
            "parser_sources": [fingerprint(HERE / name) for name in ("inspect_npc_animation.py", "inspect_player.py", "inspect_scenes.py", "inspect_resources.py")],
            "original_bundle": fingerprint(root / "SecretFlasherManaka_Data/data.unity3d"),
            "decrypted_models_source": fingerprint(models_path), "donor_schemas": schemas,
            "node_inventory": node_inventory, "animation_clip_count": len(clips),
            "all_clip_objects_consumed_to_eof": all(c["end_of_object_verified"] for c in clips),
            "target_event": TARGET,
            "target_clips": [c for c in clips if (c["source"]["node"], c["source"]["object"]["path_id"]) in target_keys],
            "clip_inventory": [{k: c[k] for k in ("source", "schema_match", "name", "events_count_offset", "event_count", "bytes_consumed", "end_of_object_verified")}
                               for c in clips],
            "controller_objects_checked": len(controllers), "animator_objects_checked": len(animators),
            "linked_controllers": linked_controllers, "linked_animators": linked_animators,
            "cross_source_clip_timing": [{"source": models.identity(donor_node, sad_object, sad_raw),
                                           "source_has_type_tree": True, "donor_schema_class_id": 74, **sad}],
            "limits": ["Original data.unity3d SerializedFile objects have no embedded type trees; the models donor and cross-source Sad clip have them. Donor schema reuse requires matching class, old_type_hash, engine version and a cursor consuming every object to EOF.",
                       "ControllerConstant was traversed only to locate the external clip reference table. State/blend/transition/clip-index semantics are owned by the separate controller investigation.",
                       "Static PPtr wiring establishes serialized references, not actual Animator playback, event delivery, activation or runtime object selection.",
                       "Only class74/91/95 objects in the enumerated original SerializedFile nodes were checked; opaque GI/resource stream nodes were excluded.",
                       "Clip start/stop/event times and loop flags are serialized clip-domain values. They do not establish wall-clock callback timing, culling, active layers or transition interruption."]}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--original-directory", type=Path, default=Path(r"E:\SecretFlasherManakaREA"))
    parser.add_argument("--models", type=Path, default=SALT / ".cache/decrypted/models.unity3d")
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    result = build(args.original_directory, args.models)
    output = HERE / "npc-animation-events.json"
    if args.check:
        assert json.loads(output.read_text(encoding="utf-8")) == result
    else:
        output.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"status": "consistent" if args.check else "written", "clips": result["animation_clip_count"],
                      "target_clips": len(result["target_clips"]), "linked_controllers": len(result["linked_controllers"]),
                      "linked_animators": len(result["linked_animators"])}))


if __name__ == "__main__":
    main()
