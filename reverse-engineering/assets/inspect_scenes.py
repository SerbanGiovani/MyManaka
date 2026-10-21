"""Read this player's scene table and selected serialized entry components.

Inputs are read only. No game assembly is loaded for execution. Reuses the
local UnityFS/SerializedFile reader and reads wrapper enum declarations through
the existing Mono.Cecil metadata parser in an isolated PowerShell process.
"""
import sys
sys.dont_write_bytecode = True

import argparse
import bisect
import hashlib
import json
from pathlib import Path
import struct
import subprocess

from inspect_resources import Bundle, Reader, serialized_metadata, monoscript_fields

HERE = Path(__file__).resolve().parent
COMPONENT_CLASSES = {
    "TitleSceneView", "InGameManager", "StageController", "SpringboardLoadEmpty",
    "SystemManager", "AssetReferencer", "InGameReferencer", "UiPlayerController",
    "StageTransController", "StageTransitionController", "IntroAnimationController",
}
SERIALIZED_DECLARATIONS = {
    "ExposureUnnoticed2.Object3D.IngameManager.AssetReferencer",
    "ExposureUnnoticed2.Master.Stage.MStage", "ExposureUnnoticed2.Master.Stage.MStageRecord",
    "ExposureUnnoticed2.ObjectUI.FadeOutPanel.FadePanelView", "UnityEngine.UI.Button",
    "UnityEngine.UI.Selectable", "UnityEngine.UI.Navigation", "UnityEngine.UI.ColorBlock",
    "UnityEngine.UI.SpriteState", "UnityEngine.UI.AnimationTriggers",
    "UnityEngine.Events.PersistentCall", "UnityEngine.Events.ArgumentCache",
}


def fingerprint(path):
    with path.open("rb") as source:
        digest = hashlib.file_digest(source, "sha256").hexdigest()
    return {"path": str(path), "size": path.stat().st_size, "sha256": digest}


def wrapper_stage_enum(root):
    assembly = root / "BepInEx/interop/Assembly-CSharp.dll"
    cecil = root / "BepInEx/core/Mono.Cecil.dll"
    quote = lambda value: "'" + str(value).replace("'", "''") + "'"
    source = "$ErrorActionPreference='Stop'\n"
    source += "Add-Type -LiteralPath " + quote(cecil) + "\n"
    source += "$m=[Mono.Cecil.ModuleDefinition]::ReadModule(" + quote(assembly) + ")\n"
    source += """
try {
 $t=$m.Types | Where-Object {$_.FullName -eq 'ExposureUnnoticed2.Master.Stage.StageType'}
 [ordered]@{type=$t.FullName;is_enum=$t.IsEnum;values=@($t.Fields | Where-Object {$_.HasConstant} | ForEach-Object {
  [ordered]@{name=$_.Name;value=$_.Constant;wrapper_field_token=('0x{0:x8}' -f $_.MetadataToken.ToUInt32())}
 })} | ConvertTo-Json -Depth 5 -Compress
} finally {$m.Dispose()}
"""
    result = subprocess.run(["pwsh", "-NoLogo", "-NoProfile", "-NonInteractive", "-Command", source],
                            text=True, encoding="utf-8", capture_output=True, check=True)
    value = json.loads(result.stdout)
    if not value["is_enum"] or len(value["values"]) != 16:
        raise ValueError("Unexpected StageType wrapper declaration")
    return {"source": fingerprint(assembly), "parser": fingerprint(cecil), "declaration": value,
            "limitation": "Tokens belong to the generated wrapper, not original IL2CPP MethodDef/FieldDef tables."}


def wrapper_serialization_declarations(root):
    paths = [root / "BepInEx/interop" / name for name in
             ("Assembly-CSharp.dll", "UnityEngine.UI.dll", "UnityEngine.CoreModule.dll")]
    cecil = root / "BepInEx/core/Mono.Cecil.dll"
    quote = lambda value: "'" + str(value).replace("'", "''") + "'"
    source = "$ErrorActionPreference='Stop'\nAdd-Type -LiteralPath " + quote(cecil) + "\n"
    source += "$paths=@(" + ",".join(quote(path) for path in paths) + ")\n"
    source += "$names=@(" + ",".join(quote(name) for name in sorted(SERIALIZED_DECLARATIONS | {
        "UnityEngine.Events.PersistentListenerMode", "UnityEngine.Events.UnityEventCallState"})) + ")\n"
    source += """
$rows=@(foreach($path in $paths) {
 $m=[Mono.Cecil.ModuleDefinition]::ReadModule($path)
 try {foreach($t in $m.Types) {if($names -contains $t.FullName) {
  [ordered]@{type=$t.FullName;assembly=$m.Assembly.Name.Name;base_type=$t.BaseType.FullName;is_enum=$t.IsEnum;
   properties=@($t.Properties | ForEach-Object {[ordered]@{name=$_.Name;type=$_.PropertyType.FullName;wrapper_token=('0x{0:x8}' -f $_.MetadataToken.ToUInt32())}});
   constants=@($t.Fields | Where-Object {$_.HasConstant} | ForEach-Object {[ordered]@{name=$_.Name;value=$_.Constant;wrapper_token=('0x{0:x8}' -f $_.MetadataToken.ToUInt32())}})}
 }}} finally {$m.Dispose()}
})
ConvertTo-Json -InputObject $rows -Depth 8 -Compress
"""
    result = subprocess.run(["pwsh", "-NoLogo", "-NoProfile", "-NonInteractive", "-Command", source],
                            text=True, encoding="utf-8", capture_output=True, check=True)
    return {"sources": [fingerprint(path) for path in paths], "parser": fingerprint(cecil),
            "types": json.loads(result.stdout),
            "limitation": "Generated interop property types and enum constants corroborate declarations; they do not independently supply Unity serialized offsets. Wrapper tokens are not original metadata tokens."}


class SceneInvestigation:
    def __init__(self, root):
        self.root = root
        self.bundle = Bundle(root / "SecretFlasherManaka_Data/data.unity3d")
        self.nodes = {node["name"]: node for node in self.bundle.nodes}
        self.metadata_cache = {}
        self.script_cache = {}

    def metadata(self, name):
        if name not in self.metadata_cache:
            self.metadata_cache[name] = serialized_metadata(self.bundle, self.nodes[name])
        return self.metadata_cache[name]

    def raw(self, node, obj):
        return self.bundle.read(self.nodes[node]["offset"] + obj["offset"], obj["size"])

    def identity(self, node, obj, raw=None):
        raw = self.raw(node, obj) if raw is None else raw
        offset = self.nodes[node]["offset"] + obj["offset"]
        first = bisect.bisect_right(self.bundle.starts, offset) - 1
        last = bisect.bisect_right(self.bundle.starts, offset + len(raw) - 1) - 1
        return {"node": node, "object": obj, "uncompressed_stream_offset": offset,
                "sha256": hashlib.sha256(raw).hexdigest(),
                "compressed_source_blocks": self.bundle.blocks[first:last + 1]}

    def object(self, node, path_id):
        return next(obj for obj in self.metadata(node)["objects"] if obj["path_id"] == path_id)

    def pointer(self, node, file_id, path_id):
        if path_id == 0:
            return None
        if file_id:
            name = self.metadata(node)["external_references"][file_id - 1]["path"]
            if name not in self.nodes:
                return {"unresolved_external": name, "path_id": path_id}
            node = name
        return {"node": node, "object": self.object(node, path_id)}

    def script(self, node, typ):
        index = typ["script_type_index"]
        if index < 0:
            return None
        ref = self.metadata(node)["script_references"][index]
        target = self.pointer(node, ref["local_file_index"], ref["local_identifier"])
        if target is None or "unresolved_external" in target:
            return target
        key = (target["node"], target["object"]["path_id"])
        if key not in self.script_cache:
            raw = self.raw(target["node"], target["object"])
            if target["object"]["class_id"] != 115:
                raise ValueError("Script reference is not a MonoScript")
            fields = monoscript_fields(raw)
            self.script_cache[key] = {"source": self.identity(target["node"], target["object"], raw),
                                      "fields": fields}
        result = self.script_cache[key]
        if result["fields"]["properties_hash"] != typ["old_type_hash"]:
            raise ValueError("MonoScript/type properties hash mismatch")
        return result

    def gameobject(self, node, obj):
        if obj["class_id"] != 1:
            raise ValueError("Expected GameObject")
        raw = self.raw(node, obj)
        reader = Reader(raw)
        count = reader.number("i")
        if not 0 <= count < 65536:
            raise ValueError("Unexpected GameObject component count")
        components = [{"file_id": reader.number("i"), "path_id": reader.number("q")} for _ in range(count)]
        layer, name = reader.number("I"), reader.aligned_string()
        tag, active = reader.number("H"), reader.number("?")
        if reader.position != len(raw):
            raise ValueError("GameObject supported schema did not consume the object")
        return {"source": self.identity(node, obj, raw), "name": name, "layer": layer,
                "tag": tag, "active_self_serialized": active, "components": components,
                "raw_hex": raw.hex(" "), "bytes_consumed": reader.position}

    def hierarchy(self, node, gameobject):
        entries, visited = [], set()
        current = {"node": node, "object": gameobject}
        for _ in range(64):
            key = (current["node"], current["object"]["path_id"])
            if key in visited:
                return {"entries": entries, "unresolved": "cycle"}
            visited.add(key)
            go = self.gameobject(current["node"], current["object"])
            transforms = []
            for pointer in go["components"]:
                candidate = self.pointer(current["node"], pointer["file_id"], pointer["path_id"])
                if candidate and "object" in candidate and candidate["object"]["class_id"] in (4, 224):
                    transforms.append(candidate)
            if len(transforms) != 1:
                return {"entries": entries + [{"gameobject": go}], "unresolved": "transform count != 1"}
            transform = transforms[0]
            raw = self.raw(transform["node"], transform["object"])
            reader = Reader(raw)
            owner = (reader.number("i"), reader.number("q"))
            reader.take(40)  # Quaternion, local position, local scale.
            children = reader.number("i")
            if not 0 <= children <= 1_000_000:
                raise ValueError("Invalid transform child count")
            reader.take(children * 12)
            father_offset = reader.position
            father = (reader.number("i"), reader.number("q"))
            expected_tail = 40 if transform["object"]["class_id"] == 224 else 0
            if reader.position + expected_tail != len(raw):
                raise ValueError("Unexpected Transform/RectTransform common-prefix extent")
            resolved_owner = self.pointer(transform["node"], *owner)
            if resolved_owner["node"] != current["node"] or resolved_owner["object"] != current["object"]:
                raise ValueError("Transform owner mismatch")
            entries.append({"gameobject": go, "transform": self.identity(transform["node"], transform["object"], raw),
                            "transform_class_id": transform["object"]["class_id"], "child_count": children,
                            "father_serialized_offset": father_offset,
                            "father_raw_hex": raw[father_offset:father_offset + 12].hex(" "),
                            "father_pointer": {"file_id": father[0], "path_id": father[1]}})
            if father[1] == 0:
                return {"entries": entries, "root_reached": True,
                        "all_ancestors_active_self_serialized": all(x["gameobject"]["active_self_serialized"] for x in entries)}
            parent = self.pointer(transform["node"], *father)
            if parent is None or "unresolved_external" in parent:
                return {"entries": entries, "unresolved": parent}
            parent_raw = self.raw(parent["node"], parent["object"])
            current = self.pointer(parent["node"], *struct.unpack_from("<iq", parent_raw))
        return {"entries": entries, "unresolved": "depth limit"}


def metadata_declarations(root):
    path = root / "SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat"
    raw = path.read_bytes()
    header = struct.unpack_from("<64I", raw)
    if header[:2] != (0xFAB11BAF, 31):
        raise ValueError("Unsupported IL2CPP metadata version")
    strings = raw[header[6]:header[6] + header[7]]
    string = lambda i: strings[i:strings.index(0, i)].decode("utf-8")
    types = list(struct.iter_unpack("<16i8H2I", raw[header[40]:header[40] + header[41]]))
    fields = list(struct.iter_unpack("<iii", raw[header[24]:header[24] + header[25]]))
    methods = list(struct.iter_unpack("<6iI4H", raw[header[12]:header[12] + header[13]]))
    selected = []
    for tid, typ in enumerate(types):
        full_name = ".".join(filter(None, (string(typ[1]), string(typ[0]))))
        if string(typ[0]) not in COMPONENT_CLASSES and full_name not in SERIALIZED_DECLARATIONS:
            continue
        selected.append({"type_id": tid, "name": string(typ[0]), "namespace": string(typ[1]),
                         "type_record_file_offset": header[40] + tid * 88,
                         "fields": [{"field_id": fid, "name": string(fields[fid][0]),
                                     "runtime_type_index": fields[fid][1], "token": hex(fields[fid][2] & 0xffffffff),
                                     "field_record_file_offset": header[24] + fid * 12}
                                    for fid in range(typ[8], typ[8] + typ[18])],
                         "declared_entry_methods": [{"method_id": mid, "name": string(methods[mid][0]),
                             "token": hex(methods[mid][6]), "method_record_file_offset": header[12] + mid * 36}
                             for mid in range(typ[9], typ[9] + typ[16])
                             if string(methods[mid][0]) in {"Awake", "Start", "OnEnable", "Initialize", "OnPureBlack", "OnExitAnim", "OnEndFadeOut"}
                             or string(methods[mid][0]).startswith("OnClick")]})
    return {"source": fingerprint(path), "metadata_version": 31, "selected_types": selected,
            "limitation": "Field declaration order/type indexes are not native offsets or a complete Unity serialization schema."}


def mono_prefix(raw):
    reader = Reader(raw)
    reader.position = 28
    name = reader.aligned_string()
    return reader, name


def read_value(reader, kind):
    offset = reader.position
    if kind == "PPtr":
        value = {"file_id": reader.number("i"), "path_id": reader.number("q")}
    elif kind == "string":
        value = reader.aligned_string()
    elif kind == "bool":
        value = reader.number("?")
        reader.align()
    else:
        value = reader.number(kind)
    return {"serialized_offset": offset, "serialized_end": reader.position, "value": value,
            "raw_hex": reader.data[offset:reader.position].hex(" ")}


def resolve_value(investigation, node, pointer):
    return investigation.pointer(node, pointer["value"]["file_id"], pointer["value"]["path_id"])


def script_of(investigation, target):
    return investigation.script(target["node"], investigation.metadata(target["node"])["types"][target["object"]["type_index"]])


def resource_system_manager(investigation):
    node = "globalgamemanagers"
    manager = next(obj for obj in investigation.metadata(node)["objects"] if obj["class_id"] == 147)
    raw = investigation.raw(node, manager)
    reader = Reader(raw)
    count = read_value(reader, "i")
    assert 0 < count["value"] < 4096
    entries = [{"key": read_value(reader, "string"), "pointer": read_value(reader, "PPtr")}
               for _ in range(count["value"])]
    matches = [entry for entry in entries if entry["key"]["value"] == "systemmanager"]
    assert len(matches) == 1
    entry = matches[0]
    root = resolve_value(investigation, node, entry["pointer"])
    root_go = investigation.gameobject(root["node"], root["object"])
    assert root_go["name"] == "SystemManager"
    components = []
    for typ in investigation.metadata(root["node"])["types"]:
        if typ["class_id"] != 114:
            continue
        script = investigation.script(root["node"], typ)
        if not script or "fields" not in script or script["fields"]["class_name"] not in {"SystemManager", "AssetReferencer"}:
            continue
        for obj in investigation.metadata(root["node"])["objects"]:
            if obj["type_index"] != typ["index"]:
                continue
            payload = investigation.raw(root["node"], obj)
            owner = investigation.pointer(root["node"], *struct.unpack_from("<iq", payload))
            hierarchy = investigation.hierarchy(owner["node"], owner["object"])
            last = hierarchy["entries"][-1]["gameobject"]["source"]
            if (last["node"], last["object"]["path_id"]) != (root["node"], root["object"]["path_id"]):
                continue
            fields, name = mono_prefix(payload)
            components.append({"class": ".".join(filter(None, (script["fields"]["namespace"], script["fields"]["class_name"]))),
                "source": investigation.identity(root["node"], obj, payload), "script_identity": script,
                "serialized_enabled": bool(payload[12]), "serialized_name": name,
                "custom_payload_start": fields.position, "hierarchy": hierarchy, "raw_hex": payload.hex(" ")})
    assert len(components) == 2
    return {"resource_manager_source": investigation.identity(node, manager, raw),
            "leading_container_count": count, "leading_container_entries": entries,
            "decoded_prefix_end": reader.position, "unparsed_tail_bytes": len(raw) - reader.position,
            "selected_container_entry": entry, "prefab_root": root_go, "selected_components": components,
            "execution_order_observations": [{"class": c["class"], "MonoScript_execution_order": c["script_identity"]["fields"]["execution_order"]} for c in components],
            "schema_boundary": "Only ResourceManager class147's leading count plus aligned-string/PPtr map is decoded; its large dependent-assets tail is not interpreted. The systemmanager key resolves through the actual external-reference table to this root GameObject.",
            "runtime_boundary": "Resources.Load query spelling SystemManager is corroborated by separate native evidence. Serialized prefab membership and MonoScript execution_order=0 do not prove Awake ordering, singleton selection, or which instance survives."}


def stage_configuration(investigation, scenes, declarations, enum_names):
    asset_ref = next(t for t in declarations["selected_types"] if t["name"] == "AssetReferencer")
    record_decl = next(t for t in declarations["selected_types"] if t["name"] == "MStageRecord")
    stage_decl = next(t for t in declarations["selected_types"] if t["name"] == "MStage")
    assert asset_ref["fields"][0]["name"] == "MStage"
    assert stage_decl["fields"][0]["name"] == "stages"
    assert [f["name"] for f in record_decl["fields"][:3]] == ["StageType", "SceneName", "StageNameKey"]
    bindings, tables, seen = [], [], set()
    for scene in scenes:
        for component in scene["selected_entry_components"]:
            if not component["class"].endswith(".AssetReferencer"):
                continue
            node, obj = component["source"]["node"], component["source"]["object"]
            reader, _ = mono_prefix(investigation.raw(node, obj))
            pointer = read_value(reader, "PPtr")
            target = resolve_value(investigation, node, pointer)
            bindings.append({"build_index": scene["build_index"], "asset_referencer_source": component["source"],
                             "field_declaration": asset_ref["fields"][0], "serialized_MStage": pointer,
                             "resolved_target": target})
            if not target or "object" not in target:
                continue
            key = (target["node"], target["object"]["path_id"])
            if key in seen:
                continue
            seen.add(key)
            script = script_of(investigation, target)
            assert script["fields"]["class_name"] == "MStage"
            raw = investigation.raw(target["node"], target["object"])
            reader, name = mono_prefix(raw)
            count = read_value(reader, "i")
            assert 0 <= count["value"] <= 256
            records = []
            for index in range(count["value"]):
                pointer = read_value(reader, "PPtr")
                item = resolve_value(investigation, target["node"], pointer)
                item_script = script_of(investigation, item)
                assert item_script["fields"]["class_name"] == "MStageRecord"
                payload = investigation.raw(item["node"], item["object"])
                fields, item_name = mono_prefix(payload)
                stage, scene_name, label = read_value(fields, "i"), read_value(fields, "string"), read_value(fields, "string")
                matching = [scene for scene in scenes if scene.get("scene_name") == scene_name["value"]]
                assert len(matching) == 1
                matching = matching[0]
                controllers = [c["stage_prefix_observation"]["int32_value"] for c in matching["selected_entry_components"] if "stage_prefix_observation" in c]
                assert controllers == [stage["value"]]
                records.append({"array_index": index, "serialized_pointer": pointer,
                    "source": investigation.identity(item["node"], item["object"], payload),
                    "script_identity": item_script, "serialized_name": item_name,
                    "StageType": {**stage, "enum_name": enum_names[stage["value"]]},
                    "SceneName": scene_name, "StageNameKey": label,
                    "decoded_prefix_end": fields.position, "unparsed_tail_hex": payload[fields.position:].hex(" "),
                    "raw_hex": payload.hex(" "),
                    "matching_build_scene": {"build_index": matching["build_index"], "path": matching["path"],
                                             "stage_controller_raw_prefix_values": controllers}})
            assert reader.position == len(raw)
            tables.append({"source": investigation.identity(target["node"], target["object"], raw),
                           "script_identity": script, "serialized_name": name, "stages_count": count,
                           "records": records, "bytes_consumed": reader.position, "raw_hex": raw.hex(" ")})
    return {"evidence_type": "Serialized PPtr resolution and structural parsing with original metadata/wrapper declaration consistency",
            "asset_referencer_bindings": bindings, "MStage_tables": tables,
            "schema_boundary": "AssetReferencer first custom PPtr; MStage leading stages vector fully consumes this object; MStageRecord first three declared fields only. Other MStageRecord fields are opaque. Serialized PPtr widths are 12 bytes; these offsets are not native field offsets.",
            "runtime_boundary": "The scene-to-level convention and matching SceneName/StageController prefix are corroboration; this static configuration does not establish which save-state value is selected at runtime."}


def title_buttons(investigation, wrappers):
    enums = {t["type"]: {v["value"]: v["name"] for v in t["constants"]}
             for t in wrappers["types"] if t["is_enum"]}
    results, node = [], "level0"
    for typ in investigation.metadata(node)["types"]:
        if typ["class_id"] != 114:
            continue
        script = investigation.script(node, typ)
        if not script or "fields" not in script or (script["fields"]["namespace"], script["fields"]["class_name"]) != ("UnityEngine.UI", "Button"):
            continue
        for obj in investigation.metadata(node)["objects"]:
            if obj["type_index"] != typ["index"]:
                continue
            raw = investigation.raw(node, obj)
            reader, name = mono_prefix(raw)
            navigation = {"mode": read_value(reader, "i"), "wrap_around": read_value(reader, "bool")}
            navigation["selection_pointers"] = {key: read_value(reader, "PPtr") for key in ("up", "down", "left", "right")}
            transition = read_value(reader, "i")
            colors = {key: [read_value(reader, "f") for _ in range(4)] for key in ("normal", "highlighted", "pressed", "selected", "disabled")}
            colors.update(multiplier=read_value(reader, "f"), fade_duration=read_value(reader, "f"))
            sprites = {key: read_value(reader, "PPtr") for key in ("highlighted", "pressed", "selected", "disabled")}
            triggers = {key: read_value(reader, "string") for key in ("normal", "highlighted", "pressed", "selected", "disabled")}
            interactable, graphic, count = read_value(reader, "bool"), read_value(reader, "PPtr"), read_value(reader, "i")
            assert 0 <= count["value"] <= 100
            calls = []
            for _ in range(count["value"]):
                pointer, assembly, method, mode = read_value(reader, "PPtr"), read_value(reader, "string"), read_value(reader, "string"), read_value(reader, "i")
                arguments = {key: read_value(reader, kind) for key, kind in (
                    ("object_argument", "PPtr"), ("object_argument_assembly_type_name", "string"),
                    ("int_argument", "i"), ("float_argument", "f"), ("string_argument", "string"), ("bool_argument", "bool"))}
                state = read_value(reader, "i")
                target = resolve_value(investigation, node, pointer)
                calls.append({"target": pointer, "resolved_target": target,
                              "target_script_identity": script_of(investigation, target),
                              "target_assembly_type_name": assembly, "method_name": method,
                              "mode": {**mode, "enum_name": enums["UnityEngine.Events.PersistentListenerMode"][mode["value"]]},
                              "arguments": arguments,
                              "call_state": {**state, "enum_name": enums["UnityEngine.Events.UnityEventCallState"][state["value"]]}})
            assert reader.position == len(raw)
            owner = investigation.pointer(node, *struct.unpack_from("<iq", raw))
            results.append({"source": investigation.identity(node, obj, raw), "script_identity": script,
                            "serialized_name": name, "hierarchy": investigation.hierarchy(owner["node"], owner["object"]),
                            "selectable": {"navigation": navigation, "transition": transition, "colors": colors,
                                           "sprites": sprites, "animation_triggers": triggers, "interactable": interactable, "target_graphic": graphic},
                            "on_click_persistent_call_count": count, "on_click_persistent_calls": calls,
                            "raw_hex": raw.hex(" "), "bytes_consumed": reader.position})
    return {"evidence_type": "Complete structural parse of these serialized Button objects, with original metadata field names and interop enum constants",
            "buttons": results,
            "schema": "MonoBehaviour prefix; Selectable Navigation(mode,bool+align,4 PPtrs), transition Int32, ColorBlock(22 floats), SpriteState(4 PPtrs), AnimationTriggers(5 strings), interactable bool+align, targetGraphic PPtr; Button.onClick PersistentCall vector; each call follows target/assembly/method/mode/ArgumentCache/callState declaration order. All supported objects consume exactly EOF.",
            "limitation": "Serialized persistent bindings establish configured targets/method names and listener modes; they do not prove a click occurred or the timing of runtime transitions."}


def animator_and_event_evidence(investigation, scenes, declarations, prefab, wrappers):
    title = scenes[0]
    intro = next(c for c in title["selected_entry_components"] if c["class"].endswith(".IntroAnimationController"))
    asset_decl = next(t for t in declarations["selected_types"] if t["name"] == "AssetReferencer")
    assert asset_decl["fields"][27]["name"] == "FadePanel"
    properties = next(t["properties"] for t in wrappers["types"] if t["type"].endswith(".AssetReferencer"))
    assert [p["name"] for p in properties[:28]] == [f["name"] for f in asset_decl["fields"][:28]]
    assert all(p["type"].startswith("ExposureUnnoticed2.Master.") for p in properties[:27])
    assert properties[27]["type"] == "UnityEngine.GameObject"
    fades = []
    all_components = [c for s in scenes for c in s["selected_entry_components"]] + prefab["selected_components"]
    for component in all_components:
        if not component["class"].endswith(".AssetReferencer"):
            continue
        node, obj = component["source"]["node"], component["source"]["object"]
        raw = investigation.raw(node, obj)
        reader, _ = mono_prefix(raw)
        leading = []
        for field, prop in zip(asset_decl["fields"][:27], properties[:27]):
            value = read_value(reader, "PPtr")
            reference = resolve_value(investigation, node, value)
            if reference is not None:
                assert reference["object"]["class_id"] == 114
            leading.append({"field_name": field["name"], "wrapper_type": prop["type"],
                            "serialized_pointer": value, "resolved_target": reference})
        pointer = read_value(reader, "PPtr")
        target = resolve_value(investigation, node, pointer)
        if target is not None:
            assert target["object"]["class_id"] == 1
        fades.append({"asset_referencer_source": component["source"], "field_declaration": asset_decl["fields"][27],
                      "preceding_reference_fields": leading,
                      "serialized_FadePanel": pointer, "resolved_gameobject": target})
    gameobjects = [("title_intro", intro["hierarchy"]["entries"][0]["gameobject"]["source"])]
    for fade in fades:
        target = fade["resolved_gameobject"]
        if target:
            gameobjects.append(("asset_referencer_fade_panel", target))
    animators, mono_components, seen = [], [], set()
    for purpose, target in gameobjects:
        key = (target["node"], target["object"]["path_id"])
        if key in seen:
            continue
        seen.add(key)
        go = investigation.gameobject(target["node"], target["object"])
        for pointer in go["components"]:
            component = investigation.pointer(target["node"], pointer["file_id"], pointer["path_id"])
            raw = investigation.raw(component["node"], component["object"])
            if component["object"]["class_id"] == 114:
                script = script_of(investigation, component)
                mono_components.append({"purpose": purpose, "source": investigation.identity(component["node"], component["object"], raw),
                                        "script_identity": script, "raw_hex": raw.hex(" "), "custom_payload_schema_decoded": False})
            if component["object"]["class_id"] != 95:
                continue
            assert len(raw) >= 40
            reader = Reader(raw)
            owner = read_value(reader, "PPtr")
            enabled = read_value(reader, "bool")
            avatar, controller = read_value(reader, "PPtr"), read_value(reader, "PPtr")
            resolved = resolve_value(investigation, component["node"], controller)
            assert resolved and resolved["object"]["class_id"] == 91
            controller_raw = investigation.raw(resolved["node"], resolved["object"])
            name_reader = Reader(controller_raw)
            controller_name = read_value(name_reader, "string")
            animators.append({"purpose": purpose, "gameobject": go,
                             "animator_source": investigation.identity(component["node"], component["object"], raw),
                             "animator_prefix": {"m_GameObject": owner, "m_Enabled": enabled, "m_Avatar": avatar, "m_Controller": controller},
                             "animator_raw_hex": raw.hex(" "), "animator_unparsed_tail_offset": reader.position,
                             "controller_source": investigation.identity(resolved["node"], resolved["object"], controller_raw),
                             "controller_name": controller_name, "controller_raw_hex": controller_raw.hex(" "),
                             "controller_unparsed_tail_offset": name_reader.position,
                             "controller_to_clip_table_decoded": False})
    clips, node = [], "sharedassets0.assets"
    for obj in investigation.metadata(node)["objects"]:
        if obj["class_id"] != 74:
            continue
        raw = investigation.raw(node, obj)
        name = read_value(Reader(raw), "string")
        observations = []
        for method in ("OnEndFadeOut", "OnExitAnim", "OnPureBlack"):
            value = method.encode("utf-8")
            start = raw.find(value)
            while start >= 0:
                observations.append({"string": method, "serialized_byte_offset": start,
                    "raw_hex": raw[max(0, start - 4):start + len(value)].hex(" "),
                    "preceding_int32": struct.unpack_from("<i", raw, start - 4)[0] if start >= 4 else None,
                    "is_decoded_AnimationEvent": False})
                start = raw.find(value, start + 1)
        clips.append({"source": investigation.identity(node, obj, raw), "name": name,
                      "raw_hex": raw.hex(" "), "unparsed_tail_offset": name["serialized_end"],
                      "bounded_function_string_observations": observations,
                      "events_schema_decoded": False})
    return {"FadePanel_bindings": fades, "animators": animators, "attached_monobehaviours": mono_components,
            "same_node_animation_clip_inventory": clips,
            "schema_boundary": "AssetReferencer.FadePanel is a PPtr after 27 leading reference fields, corroborated by original declaration order and generated property types. Animator class95 parses only owner/enabled/avatar/controller through byte40. AnimatorController class91 and AnimationClip class74 parse only NamedObject aligned name; remaining blobs are preserved opaque.",
            "event_evidence_boundary": "Function-name byte occurrences are bounded observations inside specific clip objects, not AnimationEvent parsing. No event count/time/function dispatch or controller-to-clip association is established. A reliable AnimationClip/AnimatorController schema for this build (2022.3.62f2) or runtime trace remains required to prove fade-completion event wiring."}


def build(root):
    investigation = SceneInvestigation(root)
    node = "globalgamemanagers"
    managers = investigation.metadata(node)
    settings = next(obj for obj in managers["objects"] if obj["class_id"] == 141)
    raw = investigation.raw(node, settings)
    reader = Reader(raw)
    count = reader.number("i")
    if not 0 < count < 256:
        raise ValueError("Invalid BuildSettings scene count")
    paths = []
    for index in range(count):
        offset = reader.position
        path = reader.aligned_string()
        if not path.startswith("Assets/") or not path.endswith(".unity"):
            raise ValueError("Unexpected BuildSettings scene path")
        paths.append({"build_index": index, "path": path, "scene_name": Path(path).stem,
                      "length_prefix_offset_in_object": offset, "end_in_object": reader.position})
    prefix_end = reader.position
    enums = wrapper_stage_enum(root)
    wrappers = wrapper_serialization_declarations(root)
    enum_names = {item["value"]: item["name"] for item in enums["declaration"]["values"]}
    declarations = metadata_declarations(root)
    stage = next(typ for typ in declarations["selected_types"] if typ["name"] == "StageController")
    if stage["fields"][0]["name"] != "<StageType>k__BackingField":
        raise ValueError("Unexpected first declared StageController field")
    scenes = []
    for index, scene in enumerate(paths):
        level = f"level{index}"
        metadata = investigation.metadata(level)
        components, class_names = [], []
        for typ in metadata["types"]:
            if typ["class_id"] != 114:
                continue
            script = investigation.script(level, typ)
            if not script or "fields" not in script:
                continue
            fields = script["fields"]
            full_name = ".".join(filter(None, (fields["namespace"], fields["class_name"])))
            class_names.append(full_name)
            if fields["class_name"] not in COMPONENT_CLASSES:
                continue
            for obj in metadata["objects"]:
                if obj["type_index"] != typ["index"]:
                    continue
                payload = investigation.raw(level, obj)
                owner = struct.unpack_from("<iq", payload)
                script_pointer = struct.unpack_from("<iq", payload, 16)
                reference = metadata["script_references"][typ["script_type_index"]]
                if script_pointer != (reference["local_file_index"], reference["local_identifier"]):
                    raise ValueError("MonoBehaviour script pointer differs from type reference")
                names = Reader(payload)
                names.position = 28
                object_name = names.aligned_string()
                go = investigation.pointer(level, *owner)
                component = {"class": full_name, "source": investigation.identity(level, obj, payload),
                             "serialized_enabled": bool(payload[12]), "serialized_name": object_name,
                             "custom_payload_start": names.position, "custom_payload_bytes": len(payload) - names.position,
                             "gameobject_pointer": {"file_id": owner[0], "path_id": owner[1]},
                             "script_pointer": {"file_id": script_pointer[0], "path_id": script_pointer[1]},
                             "script_identity": script, "raw_hex": payload.hex(" "),
                             "hierarchy": investigation.hierarchy(go["node"], go["object"])}
                if fields["class_name"] == "StageController":
                    value = struct.unpack_from("<i", payload, names.position)[0]
                    if value not in enum_names:
                        raise ValueError("Observed stage prefix does not match a declared enum value")
                    component["stage_prefix_observation"] = {
                        "serialized_offset": names.position, "raw_hex": payload[names.position:names.position + 4].hex(" "),
                        "int32_value": value, "matching_StageType_enum_name": enum_names.get(value),
                        "corroboration": "First declared metadata field is <StageType>k__BackingField; generated wrapper declares StageType enum. The observed serialized prefix has a declared StageType enum value.",
                        "limitation": "The complete StageController serialization schema was not decoded; raw first-payload value and declaration consistency are retained separately."}
                components.append(component)
        scenes.append({**scene, "level_node": investigation.nodes[level],
                       "index_to_level_basis": "BuildSettings scene order paired with the player's levelN convention; endpoint controller identities corroborate Title/empty-scene association.",
                       "serialized_metadata": {key: metadata[key] for key in ("format", "endian", "engine_version", "metadata_size", "metadata_sha256", "has_type_tree", "external_references")},
                       "object_count": len(metadata["objects"]), "type_count": len(metadata["types"]),
                       "class_1660057539_scene_roots_object_count": sum(obj["class_id"] == 1660057539 for obj in metadata["objects"]),
                       "resolved_monobehaviour_class_names": class_names, "selected_entry_components": components})
    prefab = resource_system_manager(investigation)
    stages = stage_configuration(investigation, scenes + [{"build_index": None, "selected_entry_components": prefab["selected_components"]}], declarations, enum_names)
    buttons = title_buttons(investigation, wrappers)
    animations = animator_and_event_evidence(investigation, scenes, declarations, prefab, wrappers)
    return {"schema_version": 2, "kind": "offline-player-scene-resource-inventory",
            "source": fingerprint(investigation.bundle.path), "reused_parser": fingerprint(HERE / "inspect_resources.py"),
            "inventory_parser": fingerprint(Path(__file__).resolve()), "engine_version": investigation.bundle.engine_version,
            "build_settings": {"source": investigation.identity(node, settings, raw), "class_id": 141,
                               "raw_hex": raw.hex(" "), "scene_count": count, "decoded_scene_prefix_end": prefix_end,
                               "unparsed_tail_offset": prefix_end, "unparsed_tail_hex": raw[prefix_end:].hex(" "),
                               "schema_boundary": "Only the leading Int32 scene count and aligned length-prefixed UTF-8 scene paths of this class141 BuildSettings object are interpreted."},
            "stage_enum": enums, "serialization_wrapper_declarations": wrappers,
            "original_component_declarations": declarations, "scenes": scenes,
            "resource_SystemManager_prefab": prefab, "stage_configuration": stages,
            "title_button_bindings": buttons, "animation_reference_and_event_boundary": animations,
            "limitations": ["No game execution or REA session was opened; this is static serialized-resource evidence.",
                "BuildSettings has ten ordered scene paths; correspondence with levelN uses the standard player layout and observed component identities, not an extra explicit mapping table.",
                "The BuildSettings tail and most custom component payloads are preserved but not fully schema-decoded; the supported MStage table, MStageRecord prefix and Button objects have explicit per-section decode boundaries.",
                "Serialized enabled/active values and resolved parent chains do not establish actual runtime Awake/Start execution or later scene lifetime.",
                "StageController raw prefix values, metadata field order, and wrapper enum declaration are distinct corroborating observations; scene filenames alone do not determine StageType.",
                "This component-name selection is not a claim to enumerate all initialization behavior, dynamically created objects, scene unloads, or save-data-dependent branches."]}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--original-directory", type=Path, default=Path(r"E:\SecretFlasherManakaREA"))
    parser.add_argument("--output", type=Path, default=HERE / "scene-inventory.json")
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    result = build(args.original_directory)
    if args.check:
        if result != json.loads(args.output.read_text(encoding="utf-8-sig")):
            raise ValueError("Saved scene inventory differs from original inputs")
    else:
        args.output.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"scenes": len(result["scenes"]),
                      "entry_components": sum(len(scene["selected_entry_components"]) for scene in result["scenes"]),
                      "output": str(args.output)}, ensure_ascii=False))
