"""Reproduce bounded NPC template/model/receiver evidence without running game code.

No NPC MonoBehaviour donor tree exists in models. Selected original component
fields are bound to metadata declarations, wrapper types and full EOF checks.
Casual1 raw PPtr matches remain candidates except known component owner fields.
"""
import sys
sys.dont_write_bytecode = True

import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess

import inspect_player as player
from inspect_resources import Reader, monoscript_fields
from inspect_scenes import SceneInvestigation, fingerprint, read_value

HERE = Path(__file__).resolve().parent
NPC = "ExposureUnnoticed2.Object3D.NPC.Script."
AVATAR_FIELDS = ["MeshParent", "Head", "Eye", "HandL", "HandR", "MeshBodys", "MeshHairs", "MeshFaces",
                 "MeshGlasses", "PoliceBody", "ConbiniBody", "Headset", "ConbiniScanner", "MeshChipo", "MeshChipoSex",
                 "MeshChinpoSexRenderers", "previousMaleBodyRenderers", "Peeticle", "HairTransformParents", "SpermColliders",
                 "longHairSpermCollider", "policeCap", "PeeParticleSystem", "bodyIndex", "hairIndex"]
ARRAY_FIELDS = {"PrefabOjis", "PrefabObas", "npcPrefabs", "MeshBodys", "MeshHairs", "MeshFaces",
                "MeshChinpoSexRenderers", "previousMaleBodyRenderers", "HairTransformParents", "SpermColliders"}


def declarations(root):
    old = player.SELECTED_TYPES, player.ENUM_NAMES, player.SERIALIZED_TYPES
    try:
        player.SELECTED_TYPES = {NPC + n for n in ("NpcComponent", "NpcAvatarComponent", "NpcAvatarSelector",
                                                    "NpcManager", "NpcAnimationEventReceiver")}
        player.ENUM_NAMES = {NPC + "NpcAvatarComponent/AvatarType"}
        player.SERIALIZED_TYPES = set()
        wrapper = player.wrappers(root)
        original = player.original_metadata(root, wrapper)
    finally:
        player.SELECTED_TYPES, player.ENUM_NAMES, player.SERIALIZED_TYPES = old
    return wrapper, original


def wrapper_attributes(root):
    cecil = root / "BepInEx/core/Mono.Cecil.dll"
    assembly = root / "BepInEx/interop/Assembly-CSharp.dll"
    quote = lambda p: "'" + str(p).replace("'", "''") + "'"
    script = "$ErrorActionPreference='Stop'\nAdd-Type -LiteralPath " + quote(cecil) + "\n"
    script += "$m=[Mono.Cecil.ModuleDefinition]::ReadModule(" + quote(assembly) + ")\n"
    script += """
try {
 $rows=@(foreach($t in $m.Types | Where-Object {$_.Name -in @('NpcComponent','NpcManager','NpcAvatarComponent')}) {
  [ordered]@{type=$t.FullName;properties=@(foreach($p in $t.Properties) {
   [ordered]@{name=$p.Name;wrapper_token=('0x{0:x8}' -f $p.MetadataToken.ToUInt32());
    attributes=@(foreach($a in $p.CustomAttributes){$a.AttributeType.FullName})}});
   native_field_info_attributes=@(foreach($f in $t.Fields | Where-Object {$_.Name.StartsWith('NativeFieldInfoPtr_')}) {
    [ordered]@{name=$f.Name;wrapper_token=('0x{0:x8}' -f $f.MetadataToken.ToUInt32());
     attributes=@(foreach($a in $f.CustomAttributes){$a.AttributeType.FullName})}})}
 })
 ConvertTo-Json -InputObject $rows -Depth 8 -Compress
} finally {$m.Dispose()}
"""
    result = subprocess.run(["pwsh", "-NoLogo", "-NoProfile", "-NonInteractive", "-Command", script],
                            capture_output=True, encoding="utf-8", check=True)
    return {"parser": fingerprint(cecil), "source": fingerprint(assembly), "declarations": json.loads(result.stdout),
            "boundary": "Generated wrapper members expose no Unity SerializeField attribute here. Original custom-attribute data blobs have not been decoded; wrapper absence is not original absence."}


def selected_component(source, node, obj, names, declaration):
    raw = source.raw(node, obj)
    reader = Reader(raw)
    owner = read_value(reader, "PPtr")
    enabled = read_value(reader, "bool")
    script = read_value(reader, "PPtr")
    name = read_value(reader, "string")
    prefix = {"gameobject": owner["value"], "gameobject_field": owner, "enabled": enabled,
              "script": script, "name": name, "custom_fields_start": reader.position}
    assert reader.position == 32
    script_identity = source.script(node, source.metadata(node)["types"][obj["type_index"]])
    script_target = source.pointer(node, **script["value"])
    assert script_target["node"] == script_identity["source"]["node"]
    assert script_target["object"] == script_identity["source"]["object"]
    script_fields = script_identity["fields"]
    assert ".".join(filter(None, (script_fields["namespace"], script_fields["class_name"]))) == declaration["full_name"]
    by_name = {f["name"]: f for f in declaration["fields"]}
    fields = []
    for name in names:
        start = reader.position
        if name in ARRAY_FIELDS:
            count = read_value(reader, "i")
            assert 0 <= count["value"] <= 4096
            entry = {"name": name, "array_count": count,
                     "elements": [read_value(reader, "PPtr") for _ in range(count["value"])]}
        else:
            entry = {"name": name, **read_value(reader, "i" if name in ("id", "bodyIndex", "hairIndex") else "PPtr")}
        entry.update(serialized_offset=start, serialized_end=reader.position,
                     raw_hex=raw[start:reader.position].hex(), original_field=by_name[name])
        pointers = entry.get("elements", [entry])
        for pointer in pointers:
            if isinstance(pointer.get("value"), dict):
                pointer["resolved_target"] = source.pointer(node, **pointer["value"])
        fields.append(entry)
    assert reader.position == len(raw), (obj["path_id"], reader.position, len(raw))
    return {"source": source.identity(node, obj, raw), "script_identity": script_identity, "prefix": prefix, "fields": fields,
            "bytes_consumed": reader.position, "end_of_object_verified": True,
            "schema_boundary": "Selected primitive/PPtr/PPtr-array fields in original declaration order; wrapper types and complete object EOF corroborate this layout. Unsupported runtime dictionaries, ordinary helper objects and unselected private fields are not silently assigned serialized offsets."}


def source_nodes(source):
    return [n for n in source.nodes if n.endswith(".assets") or re.fullmatch(r"level\d+", n)
            or n in ("globalgamemanagers", "Resources/unity_builtin_extra")]


def build(root, models_path):
    wrapper, original_declarations = declarations(root)
    declaration = {t["full_name"]: t for t in original_declarations["types"]}
    source = SceneInvestigation(root)
    node = "resources.assets"
    original = source.metadata(node)
    selected = player.find_script_objects(source, [node], {"NpcComponent", "NpcAvatarComponent", "NpcManager", "NpcAnimationEventReceiver"})
    script_objects = {}
    for record in selected:
        script_objects.setdefault(record["script_identity"]["fields"]["class_name"], []).append(record)
    assert len(script_objects["NpcComponent"]) == len(script_objects["NpcManager"]) == 1
    component = selected_component(source, node, source.object(node, 64590),
        ["DokinAudioSource", "CeilingPlayerBlocker", "PrefabFemale", "PrefabMale", "PrefabPreviousFemale", "PrefabPreviousMale",
         "PrefabOjis", "PrefabObas", "Smartphone", "SmartphoneLight", "Book", "AvatarParent", "InteractArea", "id"],
        declaration[NPC + "NpcComponent"])
    manager = selected_component(source, node, source.object(node, 79105), ["npcPrefabs", "sightAreaParent", "sightAreaPrefab"],
                                 declaration[NPC + "NpcManager"])
    avatars = [selected_component(source, node, row["source"]["object"], AVATAR_FIELDS,
                                  declaration[NPC + "NpcAvatarComponent"]) for row in script_objects["NpcAvatarComponent"]]
    avatar_by_owner = {}
    for avatar in avatars:
        owner = avatar["prefix"]["gameobject"]
        avatar_by_owner[(node, owner["path_id"])] = avatar

    event_path = HERE / "npc-animation-events.json"
    event_data = json.loads(event_path.read_text(encoding="utf-8"))
    wiring_by_go = {(a["gameobject"]["source"]["node"], a["gameobject"]["source"]["object"]["path_id"]): a
                    for a in event_data["linked_animators"]}
    model_fields = [f for f in component["fields"] if f["name"].startswith("Prefab")]
    model_wiring = []
    for field in model_fields:
        for index, pointer in enumerate(field.get("elements", [field])):
            target = pointer["resolved_target"]
            key = target["node"], target["object"]["path_id"]
            assert key in wiring_by_go and key in avatar_by_owner
            wiring = wiring_by_go[key]
            receiver = next(s for s in wiring["same_gameobject_scripts"] if s["script_identity"]["fields"]["class_name"] == "NpcAnimationEventReceiver")
            assert hashlib.sha256(source.raw(wiring["source"]["node"], wiring["source"]["object"])).hexdigest() == wiring["source"]["sha256"]
            assert source.gameobject(target["node"], target["object"]) == wiring["gameobject"]
            assert next(f for f in wiring["parsed"]["fields"] if f["name"] == "m_Controller")["value"] == {"file_id": 0, "path_id": 1995}
            model_wiring.append({"npc_component_field": field["name"], "array_index": index if "elements" in field else None,
                                 "pointer": pointer, "gameobject_animator_receiver_wiring": wiring,
                                 "receiver_component": selected_component(source, receiver["component"]["node"],
                                      receiver["component"]["object"], [], declaration[NPC + "NpcAnimationEventReceiver"]),
                                 "avatar_component": avatar_by_owner[key]})
    assert len(model_wiring) == 9
    casual = wiring_by_go[(node, 17757)]
    assert not any(s["script_identity"]["fields"]["class_name"] == "NpcAnimationEventReceiver" for s in casual["same_gameobject_scripts"])
    template = source.gameobject(node, source.pointer(node, **component["prefix"]["gameobject"])["object"])
    prefab = next(f for f in manager["fields"] if f["name"] == "npcPrefabs")
    assert len(prefab["elements"]) == 1 and prefab["elements"][0]["resolved_target"]["object"] == template["source"]["object"]
    parent = next(f for f in component["fields"] if f["name"] == "AvatarParent")["resolved_target"]
    assert parent["object"]["class_id"] == 4
    parent_reader = Reader(source.raw(parent["node"], parent["object"]))
    parent_owner = read_value(parent_reader, "PPtr")
    parent_go = source.pointer(parent["node"], **parent_owner["value"])
    parent_hierarchy = source.hierarchy(parent_go["node"], parent_go["object"])
    assert parent_hierarchy["root_reached"] and parent_hierarchy["entries"][-1]["gameobject"]["source"]["object"] == template["source"]["object"]

    # Bounded original bytes search. Matches do not establish a serialized field.
    candidate_classes = {1, 4, 91, 95, 114, 142, 147, 1001}
    counts, byte_count, candidates, same_name = Counter(), 0, [], []
    needle = struct.pack("<q", 17757)
    for srcnode in source_nodes(source):
        md = source.metadata(srcnode)
        for obj in md["objects"]:
            if obj["class_id"] not in candidate_classes:
                continue
            counts[obj["class_id"]] += 1
            raw = source.raw(srcnode, obj)
            byte_count += len(raw)
            if obj["class_id"] == 1:
                r = Reader(raw)
                r.take(r.number("i") * 12 + 4)
                if r.aligned_string() == "Casual1":
                    same_name.append(source.gameobject(srcnode, obj))
            position = 0
            while True:
                position = raw.find(needle, position)
                if position < 0:
                    break
                if position >= 4 and (position - 4) % 4 == 0:
                    offset = position - 4
                    fid = struct.unpack_from("<i", raw, offset)[0]
                    try:
                        target = source.pointer(srcnode, fid, 17757)
                    except (IndexError, StopIteration):
                        target = None
                    if target and target.get("node") == node and target.get("object", {}).get("path_id") == 17757:
                        script = source.script(srcnode, md["types"][obj["type_index"]]) if obj["class_id"] == 114 else None
                        candidates.append({"source": source.identity(srcnode, obj, raw), "script_identity": script,
                                           "serialized_offset": offset, "raw_hex": raw[offset:offset + 12].hex(),
                                           "candidate_file_id": fid, "candidate_path_id": 17757,
                                           "known_component_owner_field": offset == 0 and obj["class_id"] in (4, 95, 114),
                                           "boundary": "Raw aligned PPtr-shaped bytes resolving by this file's external table; non-owner matches are not typed-field evidence."})
                position += 1

    models = player.models_investigation(models_path)
    model_node = next(n for n in models.nodes if not n.endswith((".resS", ".resource")))
    md = models.metadata(model_node)
    script_counts, null_scripts, monobehaviours, go_count, model_same_name, npc_scripts = Counter(), 0, 0, 0, [], []
    script_cache = {}
    for obj in md["objects"]:
        if obj["class_id"] not in (1, 114):
            continue
        raw = models.raw(model_node, obj)
        if obj["class_id"] == 1:
            go_count += 1
            reader = Reader(raw)
            reader.take(reader.number("i") * 12 + 4)
            if reader.aligned_string() == "Casual1":
                model_same_name.append(models.gameobject(model_node, obj))
            continue
        monobehaviours += 1
        fid, pid = struct.unpack_from("<iq", raw, 16)
        if not pid:
            null_scripts += 1
            continue
        key = fid, pid
        if key not in script_cache:
            target = models.pointer(model_node, fid, pid)
            assert target and "object" in target and target["object"]["class_id"] == 115
            script_cache[key] = {"source": models.identity(target["node"], target["object"]),
                                 "fields": monoscript_fields(models.raw(target["node"], target["object"]))}
        script = script_cache[key]
        script_counts[script["fields"]["class_name"]] += 1
        if script["fields"]["class_name"] in ("NpcAnimationEventReceiver", "NpcComponent", "NpcAvatarComponent"):
            npc_scripts.append({"source": models.identity(model_node, obj, raw), "script_identity": script})

    return {"schema_version": 1, "evidence_type": "Bounded original NPC template and model references with declaration/EOF corroboration",
            "original_bundle": fingerprint(source.bundle.path), "models_bundle": fingerprint(models_path),
            "parser_sources": [fingerprint(HERE / name) for name in ("inspect_npc_models.py", "inspect_player.py", "inspect_scenes.py", "inspect_resources.py")]
                              + [fingerprint(HERE.parent / "salt/metadata.py")],
            "wrapper_declarations": wrapper, "original_declarations": original_declarations,
            "wrapper_attribute_observations": wrapper_attributes(root),
            "source_script_identities": {k: [{"source": r["source"], "script_identity": r["script_identity"]} for r in rows]
                                         for k, rows in sorted(script_objects.items())},
            "npc_manager": manager, "npc_component": component,
            "npc_template_owner": template,
            "avatar_parent_owner_field": parent_owner, "avatar_parent_hierarchy": parent_hierarchy,
            "selected_nine_model_wiring": model_wiring,
            "casual1": {"gameobject_animator_wiring": casual, "avatar_component": avatar_by_owner[(node, 17757)],
                        "in_selected_npc_component_model_fields": False,
                        "boundary": "Casual1 is excluded from these nine serialized template fields. Actual runtime factory selection is established separately by native evidence; no global unused-asset claim."},
            "casual1_reference_candidates": {"classes_in_scope": sorted(candidate_classes),
                "object_counts_by_class": {str(k): v for k, v in sorted(counts.items())}, "bytes_checked": byte_count,
                "matches": candidates, "same_name_original_gameobjects": same_name,
                "boundary": "Opaque meshes/textures/audio and other classes were not searched. ResourceManager/ES3ReferenceMgr byte matches are not interpreted as active model selection."},
            "models_script_inventory": {"node": model_node, "metadata_sha256": md["metadata_sha256"],
                "gameobjects_checked": go_count, "same_name_gameobjects": model_same_name,
                "monobehaviours_checked": monobehaviours, "null_script_pointer_objects": null_scripts,
                "resolved_script_object_count": len(script_cache), "resolved_script_class_counts": dict(sorted(script_counts.items())),
                "npc_script_objects": npc_scripts,
                "boundary": "All class1 names and every class114 m_Script PPtr in this models SerializedFile were checked. Null script PPtrs remain missing identities; runtime AddComponent/overrides and other bundles are outside this negative result."},
            "npc_event_dependency": fingerprint(event_path),
            "limits": ["Original component files lack embedded type trees. Their selected field names/types/order come from original metadata plus generated wrapper declarations, with full serialized EOF checks; visibility is not a SerializeField attribute decoder.",
                       "Original Unity SerializeField/custom-attribute blobs remain undecoded. The interop wrapper's empty custom-attribute lists cannot prove the original fields lack attributes.",
                       "NpcAvatarSelector is an ordinary runtime object with nca, not a serialized prefab selector component. AvaterObject and NpcController private backing fields are not assigned serialized offsets.",
                       "Serialized prefab availability and reference caches do not prove actual runtime spawn, effective saved options, activation or event delivery."]}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--original-directory", type=Path, default=Path(r"E:\SecretFlasherManakaREA"))
    parser.add_argument("--models", type=Path, default=HERE.parent / "salt/.cache/decrypted/models.unity3d")
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    result = build(args.original_directory, args.models)
    output = HERE / "npc-model-wiring.json"
    if args.check:
        assert json.loads(output.read_text(encoding="utf-8")) == result, "NPC model wiring differs"
    else:
        output.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"status": "consistent" if args.check else "written", "selected_models": len(result["selected_nine_model_wiring"]),
                      "casual1_pointer_candidates": len(result["casual1_reference_candidates"]["matches"]),
                      "models_npc_scripts": len(result["models_script_inventory"]["npc_script_objects"])}))


if __name__ == "__main__":
    main()
