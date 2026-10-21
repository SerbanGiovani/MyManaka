"""Read original state declarations and selected Bareta-related resource tables.

No native or game interop code executes. The existing Mono.Cecil parser reads
generated declarations; original metadata/native registration bytes corroborate
types, constants and field coordinates. Resource presence is not code-use proof.
"""
import sys
sys.dont_write_bytecode = True

import argparse
import json
from pathlib import Path

import inspect_player as player
from inspect_scenes import SceneInvestigation, fingerprint, mono_prefix, read_value, resolve_value

HERE = Path(__file__).resolve().parent
PLAYER = "ExposureUnnoticed2.Object3D.Player.Scripts."
NPC = "ExposureUnnoticed2.Object3D.NPC.Script."
GAME = "ExposureUnnoticed2.Scripts.InGame."
BASE = "ExposureUnnoticed2.Scripts.Base."
MASTER = "ExposureUnnoticed2.Master."
TYPE_NAMES = {
    PLAYER + name for name in ("PlayerBaretaState", "PlayerBaretaEscapeState", "MentalManager", "PlayerClassAccessor", "PlayerStateModel")
} | {
    NPC + name for name in ("NpcFoundStrangerState", "NpcStateModel", "NpcManager")
} | {
    GAME + name for name in ("GameStateData", "TemporaryInGameState", "GameOverController")
} | {BASE + "FoundStrangerEvent", "ExposureUnnoticed2.ObjectUI.OptionMenu.OptionData",
    "ExposureUnnoticed2.Object3D.IngameManager.AssetReferencer",
    MASTER + "Common.MCommon", MASTER + "Skill.SkillMental.MSkillMental", MASTER + "Skill.SkillMental.RSkillMental",
    MASTER + "Rank.MRank", MASTER + "Rank.MRankRecord", MASTER + "Stage.MStage", MASTER + "Stage.MStageRecord"}
ENUM_NAMES = {PLAYER + "PlayerStateModel/PlayerState", PLAYER + "LookAtController/LookAtLayer",
    NPC + "NpcStateModel/State", GAME + "GameOverController/GameOverStagingState",
    "ExposureUnnoticed2.ObjectUI.SelectDifficultyPanel.DifficultType", MASTER + "Skill.SkillType", MASTER + "Stage.StageType"}


def declarations(root):
    # Customize a pure-reader helper in this process; no source or cache is edited.
    original = player.SELECTED_TYPES, player.ENUM_NAMES, player.SERIALIZED_TYPES
    try:
        player.SELECTED_TYPES, player.ENUM_NAMES, player.SERIALIZED_TYPES = TYPE_NAMES, ENUM_NAMES, set()
        wrapper = player.wrappers(root)
        wrapper["types"] = [t for t in wrapper["types"] if t["type"] in TYPE_NAMES | ENUM_NAMES]
        metadata = player.original_metadata(root, wrapper)
    finally:
        player.SELECTED_TYPES, player.ENUM_NAMES, player.SERIALIZED_TYPES = original
    return wrapper, metadata


def type_name(script):
    f = script["fields"]
    return ".".join(filter(None, (f["namespace"], f["class_name"])))


def record(investigation, node, obj):
    raw = investigation.raw(node, obj)
    typ = investigation.metadata(node)["types"][obj["type_index"]]
    script = investigation.script(node, typ)
    return {"source": investigation.identity(node, obj, raw), "script_identity": script, "raw_hex": raw.hex(" ")}


def scalar(reader, field_type, enums):
    primitive = {"System.Int32": "i", "System.Single": "f", "System.Boolean": "bool", "System.String": "string"}
    if field_type in primitive:
        return read_value(reader, primitive[field_type])
    if field_type in enums:
        value = read_value(reader, "i")
        assert value["value"] in enums[field_type]
        return {**value, "enum_name": enums[field_type][value["value"]]}
    if field_type in {"UnityEngine.Color", "UnityEngine.Vector3"}:
        start = reader.position
        value = [reader.number("f") for _ in range(4 if field_type.endswith("Color") else 3)]
        return {"serialized_offset": start, "serialized_end": reader.position,
                "value": value, "raw_hex": reader.data[start:reader.position].hex(" ")}
    raise ValueError("Unsupported selected scalar field: " + field_type)


def scalar_record(investigation, node, obj, original, properties, enums, prefix_count=None):
    result = record(investigation, node, obj)
    name = type_name(result["script_identity"])
    raw = investigation.raw(node, obj)
    reader, label = mono_prefix(raw)
    fields = [f for f in original[name]["fields"] if not f["is_static"]]
    if prefix_count is not None:
        fields = fields[:prefix_count]
    decoded = []
    for field in fields:
        kind = properties[name][field["name"]]["type"]
        value = scalar(reader, kind, enums)
        if kind == "System.Boolean":
            raw_bool = bytes.fromhex(value["raw_hex"])
            assert raw_bool[0] in (0, 1) and raw_bool[1:] == bytes(len(raw_bool) - 1)
        decoded.append({"name": field["name"], "field_id": field["field_id"], "wrapper_type": kind,
                        "native_registered_offset": field["registered_offset"], **value})
    full = prefix_count is None
    if full:
        assert reader.position == len(raw)
    return {**result, "serialized_name": label, "fields": decoded, "bytes_consumed": reader.position,
            "end_of_object_verified": full, "unparsed_tail_hex": raw[reader.position:].hex(" "),
            "schema_boundary": "All declared instance fields of this selected simple record consume EOF; layout is structurally corroborated by original metadata and generated field-property types, with no embedded source type tree." if full else
                "Only the first24 declared instance fields of MCommon are decoded (scalar fields and one Color). The later DynamicBoneData and other configuration remains opaque; this is not a full-object schema."}


def table(investigation, item, record_class, original, properties, enums):
    node, obj = item["source"]["node"], item["source"]["object"]
    raw = investigation.raw(node, obj)
    reader, label = mono_prefix(raw)
    count = read_value(reader, "i")
    assert 0 <= count["value"] <= 256
    entries = []
    for index in range(count["value"]):
        pointer = read_value(reader, "PPtr")
        target = resolve_value(investigation, node, pointer)
        child = scalar_record(investigation, target["node"], target["object"], original, properties, enums)
        assert child["script_identity"]["fields"]["class_name"] == record_class
        entries.append({"array_index": index,
                        "pointer_origin": {"node": node, "path_id": obj["path_id"]},
                        "serialized_pointer": pointer, "record": child})
    assert reader.position == len(raw)
    return {**item, "serialized_name": label, "record_count": count, "entries": entries,
            "bytes_consumed": reader.position, "end_of_object_verified": True,
            "schema_boundary": "The leading record/stages PPtr vector fully consumes this table. Native static/literal and Dictionary/list fields have no serialized bytes in this supported interpretation."}


def build(root):
    wrapper, metadata = declarations(root)
    original = {t["full_name"]: t for t in metadata["types"]}
    properties = {t["type"]: {p["name"]: p for p in t["properties"]} for t in wrapper["types"]}
    enums = {t["full_name"]: {v["value"]: v["name"] for v in t["values"]} for t in metadata["enums"]}
    investigation = SceneInvestigation(root)
    selected = player.find_script_objects(investigation, ["resources.assets"], {"MSkillMental", "MRank", "MStage", "MCommon", "AssetReferencer"})
    by_class = {}
    for value in selected:
        by_class.setdefault(value["script_identity"]["fields"]["class_name"], []).append(value)
    assert all(len(by_class[n]) == 1 for n in ("MSkillMental", "MRank", "MStage", "MCommon", "AssetReferencer"))
    tables = {}
    for name, child in (("MSkillMental", "RSkillMental"), ("MRank", "MRankRecord"), ("MStage", "MStageRecord")):
        tables[name] = table(investigation, by_class[name][0], child, original, properties, enums)
    common_obj = by_class["MCommon"][0]["source"]["object"]
    common = scalar_record(investigation, "resources.assets", common_obj, original, properties, enums, 24)
    mental_names = {"pulseMentalReduce", "dotMentalExpose", "dotMentalWatched"}
    common["selected_mental_parameters"] = [v for v in common["fields"] if v["name"] in mental_names]
    asset_ref = by_class["AssetReferencer"][0]
    raw = investigation.raw("resources.assets", asset_ref["source"]["object"])
    reader, _ = mono_prefix(raw)
    asset_fields = original["ExposureUnnoticed2.Object3D.IngameManager.AssetReferencer"]["fields"]
    bindings = []
    for field in asset_fields[:27]:
        ptr = read_value(reader, "PPtr")
        if field["name"] not in {"MCommon", "MSkillMental", "MRank", "MStage"}:
            continue
        target = resolve_value(investigation, "resources.assets", ptr)
        expected = common if field["name"] == "MCommon" else tables[field["name"]]
        assert target["node"] == expected["source"]["node"] and target["object"] == expected["source"]["object"]
        bindings.append({"origin_source": asset_ref["source"], "field_id": field["field_id"], "field_name": field["name"],
                         "native_registered_offset": field["registered_offset"], "serialized_pointer": ptr,
                         "resolved_target": target})
    assert len(bindings) == 4
    def simplified(table_name, names):
        rows = []
        for entry in tables[table_name]["entries"]:
            values = {f["name"]: f["value"] for f in entry["record"]["fields"]}
            rows.append({"path_id": entry["record"]["source"]["object"]["path_id"],
                         **{name: values[name] for name in names}})
        return rows
    return {"schema_version": 1, "kind": "offline-Bareta-state-and-selected-configuration-inventory",
            "source_directory": str(root), "source_bundle": fingerprint(investigation.bundle.path),
            "parser": fingerprint(Path(__file__).resolve()),
            "reused_parsers": [fingerprint(HERE / n) for n in ("inspect_player.py", "inspect_scenes.py", "inspect_resources.py")],
            "wrapper_declarations": wrapper, "original_metadata": metadata,
            "resource_AssetReferencer_bindings": bindings, "tables": tables, "MCommon_prefix": common,
            "parameter_summary": {
                "mental_levels": simplified("MSkillMental", ("Level", "NextLevelUpRp", "MaxMental")),
                "rank_parameters": simplified("MRank", ("Rank", "NameKey", "NeedRp", "DokidokiBoostScale", "NeedFearUpRp", "FearLevelBias", "LostRpByGameOver")),
                "stage_parameters": simplified("MStage", ("StageType", "SceneName", "FearLevelPenalty"))},
            "evidence_boundaries": [
                "PlayerBaretaState and PlayerBaretaEscapeState are ordinary managed classes by generated base declaration and native storage layout, not serialized MonoBehaviours in these resource tables.",
                "Presence of an MSkillMental/MRank/MStage/MCommon parameter does not prove any particular Bareta, escape or failure code path consumes it. Native call/field-use evidence is recorded separately.",
                "The selected tables and scalar child records fully consume their objects, but no embedded type tree is present in these source objects. Original metadata/wrapper consistency and structural bounds are distinct corroboration.",
                "MCommon is only prefix-decoded; later perception/noise fields, animations, prefab lifecycle ordering and runtime state values remain unresolved here.",
                "OptionData/GameStateData/TemporaryInGameState fields are declarations and registered coordinates. Runtime constructor defaults, save-data contents and effective options are not serialized settings recovered by this inventory.",
                "Native instance/static field offsets, metadata file offsets and SerializedFile object offsets use separate coordinate systems. Table entry PPtr offsets refer to pointer_origin; record field offsets refer to record.source.",
                "No game code execution, REA session, new decryption or Git operation is performed. This inventory does not establish complete behavior or a runnable reconstruction."]}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--original-directory", type=Path, default=Path(r"E:\SecretFlasherManakaREA"))
    parser.add_argument("--output", type=Path, default=HERE / "bareta-config.json")
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    result = build(args.original_directory)
    if args.check:
        assert result == json.loads(args.output.read_text(encoding="utf-8-sig")), "Bareta inventory differs from input bytes"
    else:
        args.output.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"status": "consistent" if args.check else "written", "enum_types": len(result["original_metadata"]["enums"]),
                      "types": len(result["original_metadata"]["types"]),
                      "table_records": {k: v["record_count"]["value"] for k, v in result["tables"].items()},
                      "output": str(args.output)}, ensure_ascii=False))
