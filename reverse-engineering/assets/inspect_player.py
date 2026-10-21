"""Reproduce static player input/configuration evidence without executing game code.

Reads the original player data/metadata, generated interop declarations through
the installed Mono.Cecil parser, and the already decrypted models bundle. No
decryption, extraction, game launch, REA session or Git operation is performed.
"""
import sys
sys.dont_write_bytecode = True

import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess

from inspect_resources import Bundle, Reader
from inspect_scenes import SceneInvestigation, fingerprint, mono_prefix, read_value, resolve_value

HERE = Path(__file__).resolve().parent
SALT = HERE.parent / "salt"
GAME = "ExposureUnnoticed2.Object3D.Player.Scripts."
INPUT = "UnityEngine.InputSystem."
SELECTED_TYPES = {
    GAME + n for n in ("InputData", "InputResolver", "PlayerAction", "PlayerController",
        "PlayerClassAccessor", "PlayerLocomotion", "PlayerStateModel", "PlayerAvatarObjectReferencer",
        "Other.PlayerMoveCalculator")
} | {"ExposureUnnoticed2.Scripts.Base.InputManager", "ExposureUnnoticed2.Scripts.Base.InputRebindSaveManager"}
SELECTED_TYPES |= {"ExposureUnnoticed2.Master.Common.MCommon", "ExposureUnnoticed2.Master.Action.MAction",
                   "ExposureUnnoticed2.Master.Action.MActionRecord", "ExposureUnnoticed2.Object3D.IngameManager.AssetReferencer"}
ENUM_NAMES = {
    "ExposureUnnoticed2.Scripts.Base.InputManager/InputType", "ExposureUnnoticed2.Scripts.Base.InteractType",
    GAME + "PlayerStateModel/PlayerState",
    GAME + "PlayerStateModel/ClothesState", GAME + "PlayerStateModel/CoatActionType",
    GAME + "PlayerStateModel/CoatStateMove", GAME + "PlayerAnimationManager/Layer",
    GAME + "LookAtController/LookAtLayer", "ExposureUnnoticed2.Master.Action.ActionType",
    INPUT + "InputActionType", INPUT + "InputBinding/Flags", INPUT + "InputAction/ActionFlags",
    INPUT + "InputControlScheme/DeviceRequirement/Flags", INPUT + "PlayerNotifications",
}
SERIALIZED_TYPES = {INPUT + n for n in ("InputActionAsset", "InputActionMap", "InputAction",
    "InputBinding", "InputControlScheme", "InputControlScheme/DeviceRequirement", "PlayerInput")}


def wrappers(root):
    assemblies = [root / "BepInEx/interop" / name for name in
                  ("Assembly-CSharp.dll", "Unity.InputSystem.dll", "UnityEngine.PhysicsModule.dll")]
    cecil = root / "BepInEx/core/Mono.Cecil.dll"
    quote = lambda text: "'" + str(text).replace("'", "''") + "'"
    names = SELECTED_TYPES | ENUM_NAMES | SERIALIZED_TYPES | {"UnityEngine.CharacterController"}
    source = "$ErrorActionPreference='Stop'\nAdd-Type -LiteralPath " + quote(cecil) + "\n"
    source += "$paths=@(" + ",".join(quote(p) for p in assemblies) + ")\n"
    source += "$names=@(" + ",".join(quote(n) for n in sorted(names)) + ")\n"
    source += """
function flat($t) {$t;foreach($n in $t.NestedTypes){flat $n}}
$rows=@(foreach($path in $paths) {
 $m=[Mono.Cecil.ModuleDefinition]::ReadModule($path)
 try {foreach($top in $m.Types) {foreach($t in (flat $top)) {if($names -contains $t.FullName) {
  [ordered]@{type=$t.FullName;base_type=$t.BaseType.FullName;is_enum=$t.IsEnum;
   wrapper_token=('0x{0:x8}' -f $t.MetadataToken.ToUInt32());
   properties=@($t.Properties | ForEach-Object {[ordered]@{name=$_.Name;type=$_.PropertyType.FullName;wrapper_token=('0x{0:x8}' -f $_.MetadataToken.ToUInt32())}});
   constants=@($t.Fields | Where-Object {$_.HasConstant} | ForEach-Object {[ordered]@{name=$_.Name;value=$_.Constant;wrapper_token=('0x{0:x8}' -f $_.MetadataToken.ToUInt32())}})}
 }}}} finally {$m.Dispose()}
})
ConvertTo-Json -InputObject $rows -Depth 8 -Compress
"""
    result = subprocess.run(["pwsh", "-NoLogo", "-NoProfile", "-NonInteractive", "-Command", source],
                            text=True, encoding="utf-8", capture_output=True, check=True)
    return {"sources": [fingerprint(p) for p in assemblies], "parser": fingerprint(cecil),
            "types": json.loads(result.stdout),
            "limitation": "Interop properties/constants are generated declarations, not executable original source; wrapper tokens differ from original metadata tokens."}


def compressed_int32(raw, offset):
    start = offset
    first = raw[offset]
    offset += 1
    if first < 0x80:
        value = first
    elif first < 0xc0:
        value = ((first & 0x3f) << 8) | raw[offset]
        offset += 1
    elif first < 0xe0:
        value = ((first & 0x1f) << 24) | int.from_bytes(raw[offset:offset + 3], "big")
        offset += 3
    elif first == 0xf0:
        value = int.from_bytes(raw[offset:offset + 4], "little")
        offset += 4
    elif first == 0xfe:
        value = 0xfffffffe
    elif first == 0xff:
        value = 0xffffffff
    else:
        raise ValueError("Unsupported compressed metadata integer")
    signed = -(value >> 1) - 1 if value & 1 else value >> 1
    return {"metadata_file_offset": start, "raw_hex": raw[start:offset].hex(" "), "decoded_int32": signed}


def original_metadata(root, wrapper):
    sys.path.insert(0, str(SALT))
    from metadata import PE
    path = root / "SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat"
    raw = path.read_bytes()
    native_path = root / "GameAssembly.dll"
    native = native_path.read_bytes()
    pe = PE(native)
    h = struct.unpack_from("<64I", raw)
    assert h[:2] == (0xFAB11BAF, 31)
    strings = raw[h[6]:h[6] + h[7]]
    string = lambda i: strings[i:strings.index(0, i)].decode("utf-8")
    types = list(struct.iter_unpack("<16i8H2I", raw[h[40]:h[40] + h[41]]))
    fields = list(struct.iter_unpack("<iiI", raw[h[24]:h[24] + h[25]]))
    methods = list(struct.iter_unpack("<6iI4H", raw[h[12]:h[12] + h[13]]))
    defaults = {v[0]: (i, v) for i, v in enumerate(struct.iter_unpack("<iii", raw[h[16]:h[16] + h[17]]))}
    byval = {t[2]: i for i, t in enumerate(types)}
    def full_name(tid):
        t = types[tid]
        if t[3] >= 0:
            return full_name(byval[t[3]]) + "/" + string(t[0])
        return ".".join(filter(None, (string(t[1]), string(t[0]))))
    names = {i: full_name(i) for i in range(len(types))}
    offsets_path = SALT / "symbols/field-offsets.json"
    offsets = json.loads(offsets_path.read_text(encoding="utf-8"))
    registration = offsets["registration"]
    assert native[registration["file_offset"]:registration["file_offset"] + 128] == bytes.fromhex(registration["raw_hex"])
    table = registration["pointer_tables"]["runtime_types"]
    rows = {r["type_id"]: r for r in offsets["all_type_field_offset_rows"]}
    def runtime(index):
        poff = table["file_offset"] + index * 8
        va = struct.unpack_from("<Q", native, poff)[0]
        off = pe.offset(va, 12)
        data, bits = struct.unpack_from("<QI", native, off)
        result = {"runtime_type_index": index, "pointer_file_offset": poff, "type_va": hex(va),
                  "type_file_offset": off, "type_raw_hex": native[off:off + 12].hex(" "),
                  "data": data, "attrs": bits & 0xffff, "type_enum": (bits >> 16) & 255}
        if result["type_enum"] in (0x11, 0x12):
            result.update(type_id=data, type_name=names[data])
        return result
    declarations, enums = [], []
    wrapper_enums = {t["type"]: t for t in wrapper["types"] if t["is_enum"]}
    for tid, t in enumerate(types):
        name = names[tid]
        if name not in SELECTED_TYPES | ENUM_NAMES | SERIALIZED_TYPES:
            continue
        row = rows[tid]
        assert struct.unpack_from("<Q", native, row["offset_row_pointer_file_offset"])[0] == int(row["offset_row_va"], 16)
        assert list(struct.unpack_from(f"<{t[18]}i", native, row["offset_row_file_offset"])) == row["raw_offsets"]
        ff, ee = [], []
        for index, fid in enumerate(range(t[8], t[8] + t[18])):
            field = fields[fid]
            rt = runtime(field[1])
            item = {"field_id": fid, "name": string(field[0]), "token": hex(field[2]),
                    "metadata_file_offset": h[24] + fid * 12, "raw_hex": raw[h[24] + fid * 12:h[24] + fid * 12 + 12].hex(" "),
                    "runtime_type": rt, "is_static": bool(rt["attrs"] & 0x10), "is_literal": bool(rt["attrs"] & 0x40),
                    "registered_offset": row["raw_offsets"][index],
                    "offset_entry_file_offset": row["offset_row_file_offset"] + index * 4}
            if name in ENUM_NAMES and item["is_literal"]:
                default_id, (field_id, type_index, data_index) = defaults[fid]
                assert field_id == fid and data_index >= 0
                value = compressed_int32(raw, h[18] + data_index)
                match = next(v for v in wrapper_enums[name]["constants"] if v["name"] == item["name"])
                assert value["decoded_int32"] == match["value"]
                item["default_value"] = {"default_record_id": default_id,
                    "default_record_file_offset": h[16] + default_id * 12,
                    "default_record_raw_hex": raw[h[16] + default_id * 12:h[16] + default_id * 12 + 12].hex(" "),
                    "default_type_index": type_index, **value, "wrapper_consistency": True}
                ee.append({"name": item["name"], "value": value["decoded_int32"], "field_id": fid,
                           "source": item["default_value"]})
            ff.append(item)
        declarations.append({"type_id": tid, "full_name": name, "metadata_file_offset": h[40] + tid * 88,
            "type_raw_hex": raw[h[40] + tid * 88:h[40] + tid * 88 + 88].hex(" "), "fields": ff,
            "registered_sizes": row["type_sizes"], "methods": [
                {"method_id": mid, "name": string(methods[mid][0]), "token": hex(methods[mid][6]),
                 "metadata_file_offset": h[12] + mid * 36}
                for mid in range(t[9], t[9] + t[16])]})
        if ee:
            enums.append({"type_id": tid, "full_name": name, "values": ee})
    return {"source": fingerprint(path), "native_source": fingerprint(native_path),
        "registration_source": fingerprint(offsets_path), "types": declarations, "enums": enums,
        "integer_rule": "v31 Int32 field defaults use compressed unsigned 1/2/4-byte prefixes (or f0+LE32), then signed zigzag decoding. Each selected enum value is independently compared with its interop constant.",
        "requested_names_without_original_type": [n for n in ("PlayerActionType", "LocomotionState") if not any(string(t[0]) == n for t in types)],
        "limitation": "Registered offsets are native instance/static storage coordinates. Enum literal offset=0 is not an instance field. These are separate from serialized object offsets; declaration order alone is not a Unity schema."}


def find_script_objects(investigation, nodes, class_names):
    results = []
    for node in nodes:
        metadata = investigation.metadata(node)
        for typ in metadata["types"]:
            if typ["class_id"] != 114:
                continue
            script = investigation.script(node, typ)
            if not script or "fields" not in script or script["fields"]["class_name"] not in class_names:
                continue
            for obj in metadata["objects"]:
                if obj["type_index"] == typ["index"]:
                    raw = investigation.raw(node, obj)
                    results.append({"source": investigation.identity(node, obj, raw), "script_identity": script,
                                    "raw_hex": raw.hex(" ")})
    return results


def parse_action_asset(investigation, record, enum_maps):
    node, obj = record["source"]["node"], record["source"]["object"]
    raw = investigation.raw(node, obj)
    reader, name = mono_prefix(raw)
    count, maps = read_value(reader, "i"), []
    for _ in range(count["value"]):
        amap = {"name": read_value(reader, "string"), "id": read_value(reader, "string"), "asset": read_value(reader, "PPtr")}
        target = resolve_value(investigation, node, amap["asset"])
        assert target["object"] == obj and target["node"] == node
        actions, action_count = [], read_value(reader, "i")
        for _ in range(action_count["value"]):
            start = reader.position
            action = {"name": read_value(reader, "string"), "type": read_value(reader, "i")}
            for field in ("expected_control_type", "id", "processors", "interactions"):
                action[field] = read_value(reader, "string")
            singleton_count = read_value(reader, "i")
            assert singleton_count["value"] == 0
            action.update(singleton_binding_count=singleton_count, flags=read_value(reader, "i"), serialized_start=start, serialized_end=reader.position)
            action["type"]["enum_name"] = enum_maps[INPUT + "InputActionType"][action["type"]["value"]]
            actions.append(action)
        bindings, binding_count = [], read_value(reader, "i")
        for index in range(binding_count["value"]):
            start = reader.position
            binding = {field: read_value(reader, "string") for field in
                       ("name", "id", "path", "interactions", "processors", "groups", "action")}
            binding.update(flags=read_value(reader, "i"), index=index, serialized_start=start, serialized_end=reader.position)
            binding["is_composite"] = bool(binding["flags"]["value"] & 4)
            binding["is_part_of_composite"] = bool(binding["flags"]["value"] & 8)
            assert binding["action"]["value"] in {a["name"]["value"] for a in actions}
            bindings.append(binding)
        maps.append({**amap, "action_count": action_count, "actions": actions, "binding_count": binding_count, "bindings": bindings})
    scheme_count, schemes = read_value(reader, "i"), []
    for _ in range(scheme_count["value"]):
        scheme = {"name": read_value(reader, "string"), "binding_group": read_value(reader, "string")}
        device_count = read_value(reader, "i")
        scheme.update(device_requirement_count=device_count, device_requirements=[
            {"control_path": read_value(reader, "string"), "flags": read_value(reader, "i")} for _ in range(device_count["value"])])
        schemes.append(scheme)
    project_wide = read_value(reader, "bool")
    assert reader.position == len(raw)
    return {**record, "serialized_name": name, "map_count": count, "maps": maps,
            "control_scheme_count": scheme_count, "control_schemes": schemes,
            "is_project_wide": project_wide, "bytes_consumed": reader.position, "end_of_object_verified": True,
            "schema_boundary": "Complete supported InputActionAsset schema: action-map vector(name,id,asset PPtr,actions,bindings), control-scheme vector, project-wide bool+align. Actions have zero singleton binding arrays here. Original metadata and interop fields corroborate each record's order/types; offsets are recorded for every primitive/string."}


def input_components(investigation, enum_maps):
    nodes = ["resources.assets", "level0", "level1"]
    records = find_script_objects(investigation, nodes, {"InputManager", "PlayerInput", "InputRebindSaveManager"})
    for record in records:
        node, obj = record["source"]["node"], record["source"]["object"]
        raw = investigation.raw(node, obj)
        reader, _ = mono_prefix(raw)
        name = record["script_identity"]["fields"]["class_name"]
        owner = investigation.pointer(node, *struct.unpack_from("<iq", raw))
        record["hierarchy"] = investigation.hierarchy(owner["node"], owner["object"])
        if name == "PlayerInput":
            parsed = {"m_Actions": read_value(reader, "PPtr"), "m_NotificationBehavior": read_value(reader, "i"),
                      "m_UIInputModule": read_value(reader, "PPtr")}
            for event in ("m_DeviceLostEvent", "m_DeviceRegainedEvent", "m_ControlsChangedEvent", "m_ActionEvents"):
                parsed[event + "_count"] = read_value(reader, "i")
                assert parsed[event + "_count"]["value"] == 0
            parsed.update(m_NeverAutoSwitchControlSchemes=read_value(reader, "bool"),
                m_DefaultControlScheme=read_value(reader, "string"), m_DefaultActionMap=read_value(reader, "string"),
                m_SplitScreenIndex=read_value(reader, "i"), m_Camera=read_value(reader, "PPtr"))
            parsed["m_NotificationBehavior"]["enum_name"] = enum_maps[INPUT + "PlayerNotifications"][parsed["m_NotificationBehavior"]["value"]]
            record["resolved_action_asset"] = resolve_value(investigation, node, parsed["m_Actions"])
            record["parsed"] = parsed
        elif name == "InputRebindSaveManager":
            parsed = {"_actionAsset": read_value(reader, "PPtr"), "_savePath": read_value(reader, "string")}
            record.update(parsed=parsed, resolved_action_asset=resolve_value(investigation, node, parsed["_actionAsset"]))
        assert reader.position == len(raw)
        record.update(bytes_consumed=reader.position, end_of_object_verified=True)
    return {"objects": records,
            "schema_boundary": "InputManager has no custom serialized bytes. PlayerInput supports the observed zero-count UnityEvents/action-events, then auto-switch bool, default strings, screen index and camera PPtr. RebindSaveManager has one asset PPtr and aligned string, consuming EOF.",
            "runtime_boundary": "These are shipped defaults. The configured InputActionOverrides.json path does not establish saved user overrides or effective runtime controls. No persistent user directory is inspected. InputManager/PlayerInput membership and execution-order values do not establish Awake order or singleton survival."}


def movement_configuration(investigation, declarations, wrapper, enum_maps):
    node = "resources.assets"
    records = find_script_objects(investigation, [node], {"MCommon", "MAction", "AssetReferencer"})
    names = {t["full_name"]: t for t in declarations["types"]}
    properties = {t["type"]: {p["name"]: p for p in t["properties"]} for t in wrapper["types"]}
    common_decl = names["ExposureUnnoticed2.Master.Common.MCommon"]
    asset_ref_fields = names["ExposureUnnoticed2.Object3D.IngameManager.AssetReferencer"]["fields"]
    assert [f["name"] for f in asset_ref_fields[:7]] == ["MStage", "MCommon", "MCustomizeColor", "MClothes", "MSkill", "MSex", "MAction"]
    common_props = properties[common_decl["full_name"]]
    common = next(r for r in records if r["script_identity"]["fields"]["class_name"] == "MCommon")
    raw = investigation.raw(node, common["source"]["object"])
    reader, label = mono_prefix(raw)
    values = []
    for field in common_decl["fields"][:24]:
        kind = common_props[field["name"]]["type"]
        assert not field["is_static"] and kind in {"System.Single", "UnityEngine.Color"}
        if kind == "System.Single":
            item = read_value(reader, "f")
        else:
            start = reader.position
            color = [reader.number("f") for _ in range(4)]
            item = {"serialized_offset": start, "serialized_end": reader.position, "value": color,
                    "raw_hex": raw[start:reader.position].hex(" ")}
        values.append({"field_id": field["field_id"], "name": field["name"],
                       "native_registered_offset": field["registered_offset"], "wrapper_type": kind, **item})
    common.update(serialized_name=label, parsed_prefix=values, decoded_prefix_end=reader.position,
                  unparsed_tail_hex=raw[reader.position:].hex(" "), end_of_object_verified=False,
                  schema_boundary="First24 instance fields only, supported by original declaration order, registered field types and interop properties. The Color occupies16B and scalar fields4B. This source has no embedded type tree; the remaining DynamicBoneData/configuration schema is not decoded.")
    action = next(r for r in records if r["script_identity"]["fields"]["class_name"] == "MAction")
    raw = investigation.raw(node, action["source"]["object"])
    reader, label = mono_prefix(raw)
    count, actions = read_value(reader, "i"), []
    decl = names["ExposureUnnoticed2.Master.Action.MActionRecord"]
    assert [f["name"] for f in decl["fields"][:6]] == ["type", "canMove", "CantCancelDash", "IsMoveOnlyForwardWithStrafe", "IsMoveToCancel", "HandcuffsWeight"]
    for _ in range(count["value"]):
        ptr = read_value(reader, "PPtr")
        target = resolve_value(investigation, node, ptr)
        payload = investigation.raw(target["node"], target["object"])
        script = investigation.script(target["node"], investigation.metadata(target["node"])["types"][target["object"]["type_index"]])
        assert script["fields"]["class_name"] == "MActionRecord"
        field_reader, record_name = mono_prefix(payload)
        decoded = []
        for field, kind in zip(decl["fields"][:6], ("i", "bool", "bool", "bool", "bool", "f")):
            item = read_value(field_reader, kind)
            if kind == "bool":
                span = bytes.fromhex(item["raw_hex"])
                assert span[0] in (0, 1) and span[1:] == bytes(len(span) - 1)
            decoded.append({"field_id": field["field_id"], "name": field["name"],
                            "native_registered_offset": field["registered_offset"], **item})
        action_type = decoded[0]["value"]
        assert action_type in enum_maps["ExposureUnnoticed2.Master.Action.ActionType"]
        actions.append({"source": investigation.identity(target["node"], target["object"], payload),
                       "script_identity": script, "serialized_pointer": ptr, "serialized_name": record_name,
                       "ActionType": enum_maps["ExposureUnnoticed2.Master.Action.ActionType"][action_type],
                       "parsed_prefix": decoded, "decoded_prefix_end": field_reader.position,
                       "unparsed_tail_hex": payload[field_reader.position:].hex(" "), "raw_hex": payload.hex(" "),
                       "end_of_object_verified": False})
    assert reader.position == len(raw)
    action.update(serialized_name=label, action_count=count, records=actions,
                  bytes_consumed=reader.position, end_of_object_verified=True,
                  schema_boundary="MAction actions PPtr vector consumes EOF. SexActionBias is a native static literal and dict is nonserialized in this interpretation. Each MActionRecord only decodes its first6 fields; boolean values align to4 and remaining bytes stay opaque.",
                  runtime_boundary="Stored canMove is configuration, not the computed MActionRecord.CanMove property's full behavior. Native action/state conditions may override whether movement or cancellation actually occurs.")
    bindings = []
    for record in records:
        if record["script_identity"]["fields"]["class_name"] != "AssetReferencer":
            continue
        payload = investigation.raw(node, record["source"]["object"])
        reader, _ = mono_prefix(payload)
        for index in range(7):
            ptr = read_value(reader, "PPtr")
            if index not in (1, 6):
                continue
            target = resolve_value(investigation, node, ptr)
            bindings.append({"asset_referencer_source": record["source"], "field_name": "MCommon" if index == 1 else "MAction",
                             "original_field_id": asset_ref_fields[index]["field_id"],
                             "serialized_pointer": ptr, "resolved_target": target})
    return {"MCommon": common, "MAction": action, "resource_AssetReferencer_bindings": bindings,
            "runtime_boundary": "These resources provide shipped parameters and action flags, not observed effective values. PlayerLocomotion is allocated at runtime; its constructor supplies gravity/jump parameters and native code combines state/configuration multipliers."}


def models_investigation(path):
    investigation = object.__new__(SceneInvestigation)
    investigation.bundle = Bundle(path)
    investigation.nodes = {n["name"]: n for n in investigation.bundle.nodes}
    investigation.metadata_cache, investigation.script_cache = {}, {}
    return investigation


def type_tree_spans(investigation, node, type_index):
    metadata = investigation.metadata(node)
    block = investigation.bundle.read(investigation.nodes[node]["offset"] + 48, metadata["metadata_size"])
    r = Reader(block)
    r.string(); r.number("i")
    assert r.number("?")
    for index in range(r.number("i")):
        type_start = r.position
        class_id = r.number("i"); r.take(3)
        if class_id == 114:
            r.take(16)
        r.take(16)
        header_offset = r.position
        count, strings_size = r.number("i"), r.number("i")
        nodes_offset = r.position
        raw_nodes = r.take(count * 32)
        strings_offset = r.position
        strings = r.take(strings_size)
        dependencies = r.number("i"); r.take(4 * dependencies)
        if index == type_index:
            return {"type_record_offset_in_metadata": type_start,
                    "tree_header_offset_in_metadata": header_offset,
                    "tree_nodes_offset_in_metadata": nodes_offset,
                    "tree_nodes_uncompressed_stream_offset": investigation.nodes[node]["offset"] + 48 + nodes_offset,
                    "raw_nodes_hex": raw_nodes.hex(" "), "local_strings_offset_in_metadata": strings_offset,
                    "local_strings_hex": strings.hex(" "), "node_count": count,
                    "nodes": metadata["types"][index]["tree"],
                    "rule": "Each type-tree node is <HBBIIiiiQ,32B; level gives nesting and meta_flags&0x4000 aligns the completed value to4. Common-buffer string offsets remain explicitly identified; local field names come from the included string bytes."}
    raise ValueError("Type not found")


def tree_flat_prefix(investigation, node, obj):
    raw = investigation.raw(node, obj)
    tree = investigation.metadata(node)["types"][obj["type_index"]]["tree"]
    reader, values = Reader(raw), []
    top = [(i, t) for i, t in enumerate(tree) if t["level"] == 1]
    for i, t in top:
        typename, size = t["type"], t["byte_size"]
        start = reader.position
        if typename == "$common:840":
            value = reader.aligned_string()
        elif size == 12 and i + 2 < len(tree) and tree[i + 1]["name"] == "m_FileID" and tree[i + 2]["name"] == "m_PathID":
            value = {"file_id": reader.number("i"), "path_id": reader.number("q")}
        elif typename == "$common:161":
            value = reader.number("f")
        elif size == 1:
            value = reader.number("B")
        elif size == 4:
            value = reader.number("i")
        elif typename == "$common:997" and size == 12:
            value = [reader.number("f") for _ in range(3)]
        else:
            return {"fields": values, "bytes_consumed": reader.position, "end_of_object_verified": False,
                    "first_unsupported_tree_node": {"tree_index": i, **t}, "raw_hex": raw.hex(" ")}
        if t["meta_flags"] & 0x4000:
            reader.align()
        item = {"tree_index": i, "name": t["name"], "type": typename,
                "serialized_offset": start, "serialized_end": reader.position,
                "value": value, "raw_hex": raw[start:reader.position].hex(" ")}
        if isinstance(value, dict) and "path_id" in value:
            item["resolved_target"] = investigation.pointer(node, value["file_id"], value["path_id"])
        values.append(item)
    assert reader.position == len(raw)
    return {"fields": values, "bytes_consumed": reader.position, "end_of_object_verified": True, "raw_hex": raw.hex(" ")}


def player_prefab(models):
    node = next(n for n in models.nodes if not n.endswith((".resS", ".resource")))
    metadata = models.metadata(node)
    assert metadata["has_type_tree"]
    bundle_obj = next(o for o in metadata["objects"] if o["class_id"] == 142)
    raw = models.raw(node, bundle_obj)
    reader = Reader(raw)
    bundle_name = read_value(reader, "string")
    preload_count = read_value(reader, "i")
    preload_start = reader.position
    reader.take(12 * preload_count["value"])
    count = read_value(reader, "i")
    selected = []
    for _ in range(count["value"]):
        start = reader.position
        key, index, size, ptr = read_value(reader, "string"), read_value(reader, "i"), read_value(reader, "i"), read_value(reader, "PPtr")
        if key["value"] == "assets/zzz-externalencryptasset/player.prefab":
            selected.append({"key": key, "preload_index": index, "preload_size": size,
                             "pointer": ptr, "serialized_start": start, "serialized_end": reader.position})
    assert len(selected) == 1
    entry = selected[0]
    target = resolve_value(models, node, entry["pointer"])
    go = models.gameobject(node, target["object"])
    components, avatar = [], None
    for pointer in go["components"]:
        component = models.pointer(node, pointer["file_id"], pointer["path_id"])
        obj = component["object"]
        script = models.script(node, metadata["types"][obj["type_index"]]) if obj["class_id"] == 114 else None
        item = {"source": models.identity(node, obj), "script_identity": script}
        if obj["class_id"] == 143 or script and script["fields"]["class_name"] == "PlayerController":
            item.update(tree_schema=type_tree_spans(models, node, obj["type_index"]), parsed=tree_flat_prefix(models, node, obj))
            assert item["parsed"]["end_of_object_verified"]
            if script:
                ref = next(v for v in item["parsed"]["fields"] if v["name"] == "PlayerAvatarObjectReferencer")
                avatar = ref["resolved_target"]
        components.append(item)
    assert avatar
    avatar_obj = avatar["object"]
    avatar_data = {"source": models.identity(node, avatar_obj),
                   "script_identity": models.script(node, metadata["types"][avatar_obj["type_index"]]),
                   "tree_schema": type_tree_spans(models, node, avatar_obj["type_index"]),
                   "parsed_prefix": tree_flat_prefix(models, node, avatar_obj)}
    return {"serialized_metadata": {k: metadata[k] for k in ("format", "engine_version", "metadata_sha256", "has_type_tree", "external_references")},
            "assetbundle_container": {"source": models.identity(node, bundle_obj, raw), "name": bundle_name,
                "preload_count": preload_count, "preload_table_serialized_offset": preload_start,
                "container_count": count, "selected_entry": entry, "decoded_prefix_end": reader.position,
                "unparsed_tail_hex": raw[reader.position:].hex(" ")},
            "root_gameobject": go, "components": components, "avatar_referencer": avatar_data,
            "limitation": "Actual Player container key, root components and shipped type trees are structural evidence. PlayerLocomotion is a runtime object, not a serialized component in this prefab; gravity/speed/jump initialization and effective state require the native chain. The avatar referencer parser stops explicitly at unsupported variable fields."}


def build(root, models_path):
    wrapper = wrappers(root)
    declarations = original_metadata(root, wrapper)
    enum_maps = {e["full_name"]: {v["value"]: v["name"] for v in e["values"]} for e in declarations["enums"]}
    investigation = SceneInvestigation(root)
    assets = [parse_action_asset(investigation, r, enum_maps) for r in find_script_objects(
        investigation, ["resources.assets", "sharedassets0.assets"], {"InputActionAsset"})]
    active = next(a for a in assets if a["serialized_name"] == "PlayerAction")
    enum_values = enum_maps["ExposureUnnoticed2.Scripts.Base.InputManager/InputType"]
    enum_by_name = {name: value for value, name in enum_values.items()}
    summaries = []
    for amap in active["maps"]:
        for action in amap["actions"]:
            name = action["name"]["value"]
            bindings = [b for b in amap["bindings"] if b["action"]["value"] == name]
            summaries.append({"name": name, "action_id": action["id"]["value"], "InputType_name_match": enum_by_name.get(name),
                "type": action["type"]["enum_name"], "bindings": [{k: b[k]["value"] for k in
                    ("name", "path", "groups", "processors", "interactions", "flags")} for b in bindings]})
    missing_enum = sorted(a["name"] for a in summaries if a["InputType_name_match"] is None)
    missing_asset = sorted(set(enum_by_name) - {a["name"] for a in summaries})
    models = models_investigation(models_path)
    models_source = fingerprint(models_path)
    decryption = json.loads((SALT / "evidence/decryption.json").read_text(encoding="utf-8"))
    assert models_source["sha256"] == decryption["plaintext"]["sha256"]
    assert models_source["size"] == decryption["plaintext"]["bytes"]
    return {"schema_version": 1, "kind": "offline-player-input-and-prefab-configuration",
            "source_directory": str(root), "source_bundle": fingerprint(investigation.bundle.path),
            "decrypted_models_source": models_source, "decryption_manifest": fingerprint(SALT / "evidence/decryption.json"),
            "parser": fingerprint(Path(__file__).resolve()), "reused_parsers": [fingerprint(HERE / n) for n in ("inspect_scenes.py", "inspect_resources.py")],
            "wrapper_declarations": wrapper, "original_metadata": declarations, "input_action_assets": assets,
            "input_components": input_components(investigation, enum_maps), "default_binding_summary": summaries,
            "movement_configuration": movement_configuration(investigation, declarations, wrapper, enum_maps),
            "name_consistency": {"action_names_without_InputType": missing_enum, "InputType_names_without_action": missing_asset,
                "Jump_in_game_input_asset": any(a["name"] == "Jump" for a in summaries),
                "Jump_in_InputType_enum": "Jump" in enum_by_name,
                "boundary": "Only exact name correspondence is established here. Array position is not the InputType value; native InputManager table construction and input gating are analyzed separately."},
            "player_prefab": player_prefab(models),
            "limitations": ["Static evidence only; no game code execution or new REA session.",
                "Bindings are shipped defaults, not observed effective controls. Saved rebinding overrides, device matching, processors and native input gating can change runtime behavior.",
                "InputAction/InputType, action-type enums and player-state enums are distinct concepts; missing requested enum names are not invented.",
                "Original metadata offsets, native field offsets and SerializedFile byte offsets use different coordinate systems and remain labeled.",
                "Only selected prefab structures are decoded. Complete Animator/controller/animation event reconstruction and a runnable game are outside this inventory."]}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--original-directory", type=Path, default=Path(r"E:\SecretFlasherManakaREA"))
    parser.add_argument("--models", type=Path, default=SALT / ".cache/decrypted/models.unity3d")
    parser.add_argument("--output", type=Path, default=HERE / "player-config.json")
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    result = build(args.original_directory, args.models)
    if args.check:
        assert result == json.loads(args.output.read_text(encoding="utf-8-sig")), "Player evidence differs from its inputs"
    else:
        args.output.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"status": "consistent" if args.check else "written", "enums": len(result["original_metadata"]["enums"]),
        "input_assets": len(result["input_action_assets"]), "game_actions": len(result["default_binding_summary"]), "output": str(args.output)}, ensure_ascii=False))
