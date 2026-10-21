"""Bind NPC avatar selection/component initialization to retained REA and inputs."""
import argparse
import hashlib
import json
import re
import struct

from metadata import HERE, DEFAULT_ROOT, Metadata, PE
from scene_evidence import build as bind, read


def registration_inventory():
    native = (DEFAULT_ROOT / "GameAssembly.dll").read_bytes()
    pe = PE(native)
    md = Metadata((DEFAULT_ROOT / "SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat").read_bytes())
    types = md.records(40, "<16i8H2I")
    definitions = md.records(12, "<6iI4H")
    names = {i: ".".join(filter(None, (md.string(t[1]), md.string(t[0])))) for i, t in enumerate(types)}
    method_definitions = []
    for mid in (49150, 49151):
        definition = definitions[mid]
        assert md.string(definition[0]) == "AddComponent" and names[definition[1]] == "UnityEngine.GameObject"
        offset = md.header[12] + mid * struct.calcsize("<6iI4H")
        method_definitions.append({"id": mid, "type_name": names[definition[1]], "name": md.string(definition[0]),
                                   "file_offset": offset, "raw_hex": md.data[offset:offset + struct.calcsize("<6iI4H")].hex()})
    layout = read(HERE / "symbols/field-offsets.json")
    fields = layout["registration"]["fields"]
    count = fields["methodSpecsCount"]["value"]
    start = pe.offset(fields["methodSpecs"]["value"], count * 12)
    specs = []
    for i in range(count):
        offset = start + 12 * i
        mid, ci, mi = struct.unpack_from("<iii", native, offset)
        if mid not in (49150, 49151):
            continue
        assert mi >= 0
        pointer_offset = pe.offset(fields["genericInsts"]["value"] + mi * 8, 8)
        va = struct.unpack_from("<Q", native, pointer_offset)[0]
        inst_offset = pe.offset(va, 16)
        argc, argv = struct.unpack_from("<QQ", native, inst_offset)
        assert argc == 1
        args = []
        for j in range(argc):
            arg_pointer_offset = pe.offset(argv + j * 8, 8)
            tv = struct.unpack_from("<Q", native, arg_pointer_offset)[0]
            type_offset = pe.offset(tv, 12)
            data, bits = struct.unpack_from("<QI", native, type_offset)
            enum = (bits >> 16) & 255
            args.append({"pointer_file_offset": arg_pointer_offset, "va": hex(tv), "file_offset": type_offset,
                         "raw_hex": native[type_offset:type_offset + 12].hex(), "data": data,
                         "type_enum": enum, "type_name": names.get(data) if enum in (17, 18) else None})
        specs.append({"index": i, "file_offset": offset, "raw_hex": native[offset:offset + 12].hex(),
                      "method_definition_id": mid, "class_instantiation_index": ci, "method_instantiation_index": mi,
                      "instantiation": {"pointer_file_offset": pointer_offset, "va": hex(va), "file_offset": inst_offset,
                                        "raw_hex": native[inst_offset:inst_offset + 16].hex(), "arguments": args}})
    literal_inventory = []
    for prefix in ("UnityEngine.Animator::set_runtimeAnimatorController", "UnityEngine.Animator::set_avatar",
                   "UnityEngine.GameObject::Internal_AddComponentWithType"):
        needle, positions, offset = prefix.encode("ascii"), [], 0
        while (offset := native.find(needle, offset)) >= 0:
            positions.append({"file_offset": offset, "va": hex(pe.address(offset)), "raw_hex": needle.hex()})
            offset += len(needle)
        literal_inventory.append({"ascii_prefix": prefix, "occurrences": positions})
    receiver_count = sum(a["type_name"] == "ExposureUnnoticed2.Object3D.NPC.Script.NpcAnimationEventReceiver"
                         for s in specs for a in s["instantiation"]["arguments"])
    return {"registration_dependency": {"path": "salt/symbols/field-offsets.json",
            "sha256": hashlib.sha256((HERE / "symbols/field-offsets.json").read_bytes()).hexdigest()},
            "method_spec_count_scanned": count, "method_spec_table_file_offset": start,
            "registered_fields": {k: fields[k] for k in ("methodSpecsCount", "methodSpecs", "genericInstsCount", "genericInsts")},
            "add_component_method_definitions": method_definitions, "add_component_specs": specs,
            "receiver_concrete_instantiation_count": receiver_count, "ascii_icall_prefix_inventory": literal_inventory,
            "boundary": "All registered MethodSpec entries for these two metadata method definitions, plus exact ASCII prefix searches over the pinned native file. Generic variables, System.Object, non-generic Type calls, reflection, dynamic construction and external/Mod code remain possible. Missing concrete receiver instantiation or ICall text is not a global proof of no runtime addition/replacement."}


def build():
    result = bind(batch_prefix="npc-model-", reuse_method_ids={15488, 15489, 15518, 15359, 15403,
        15350, 15358, 15382, 15526, 15528, 15548, 15549, 15550},
        extra_type_names=("NpcAvatarSelector", "NpcAvatarComponent", "NpcComponent", "NpcComponentAccessor",
            "NpcController", "NpcStateModel", "NpcManager", "NpcAnimationEventReceiver", "NpcAnimationManager",
            "NpcAnimatorFpsController", "InGameReferencer", "AssetReferencer", "GameStateData", "OptionData"),
        dispatch_targets=[], resource_boundary="NPC model serialized sources and selected prefab/component references are separately bound in assets/npc-model-wiring.json. Decompiled branches are not observed runtime model choices.")
    result["asset_dependencies"] = []
    for name in ("assets/npc-model-wiring.json", "assets/npc-animation-events.json", "assets/animator-wiring.json"):
        path = HERE.parent / name
        result["asset_dependencies"].append({"path": name, "sha256": hashlib.sha256(path.read_bytes()).hexdigest()})
    usages = {u["va"]: u for u in result["usages"]}
    operations = []
    for method in result["methods"]:
        body = read(HERE.parent / method["path"])["normalized_result"]
        generic = [usages[va] for va in method["usage_vas"] if va in usages and "method_spec" in usages[va]]
        icalls = []
        for match in re.finditer(r'FUN_1802cf0c0\(\s*"([^"]+)"', body):
            icalls.append({"name": match[1], "pseudocode_line": body.count("\n", 0, match.start()) + 1,
                           "source_excerpt": match[0]})
        operations.append({"method_id": method["method_id"], "evidence_id": method["evidence_id"],
                           "icall_resolutions": icalls, "generic_method_usages": generic})
    result["selected_operation_inventory"] = operations
    result["component_registration_inventory"] = registration_inventory()
    result["operation_inventory_boundary"] = "ICall resolution sites and encoded MethodSpec usages in selected saved bodies. A usage can be initialization metadata rather than an executed call; arguments/branches require the full body. Absence is not a global negative search."
    result["scope"] = "Selected NPC factory, avatar choice, animation receiver addition/initialization and controller replacement paths"
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    result = build()
    path = HERE / "evidence/npc-model-chain.json"
    if args.check:
        assert read(path) == result, "NPC model evidence differs; regenerate and review"
    else:
        path.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"status": "consistent" if args.check else "written", "queries": result["new_observations"],
                      "reused": result["reused_observations"], "usages": len(result["usages"])}))


if __name__ == "__main__":
    main()
