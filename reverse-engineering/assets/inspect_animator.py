"""Decode the selected Player/Npc ControllerConstant graphs from pinned assets."""
import sys
sys.dont_write_bytecode = True

import argparse
import json
from pathlib import Path

from animator_tree import TreeDecoder
from inspect_player import models_investigation, type_tree_spans
from inspect_scenes import SceneInvestigation, fingerprint
from inspect_resources import Reader

HERE = Path(__file__).resolve().parent
CONDITION_MODES = {1: "If", 2: "IfNot", 3: "Greater", 4: "Less", 6: "Equals", 7: "NotEqual"}
REFERENCE = "https://github.com/Unity-Technologies/UnityCsReference/blob/2022.3/Editor/Mono/StateMachine.bindings.cs"


def graph(value):
    tos = {row["first"]: row["second"] for row in value["m_TOS"]}
    assert len(tos) == len(value["m_TOS"])
    constant = value["m_Controller"]

    def transition(t):
        conditions = []
        for c in t["m_ConditionConstantArray"]:
            assert c["m_ConditionMode"] in CONDITION_MODES
            conditions.append({**c, "mode_name": CONDITION_MODES[c["m_ConditionMode"]],
                               "parameter_name": tos.get(c["m_EventID"])})
        return {**t, "conditions": conditions, "name": tos.get(t.get("m_ID")),
                "destination_raw": t.get("m_DestinationState", t.get("m_Destination"))}

    machines = []
    for smi, machine in enumerate(constant["m_StateMachineArray"]):
        states = []
        for i, s in enumerate(machine["m_StateConstantArray"]):
            clips = sorted({node["m_ClipID"] for tree in s["m_BlendTreeConstantArray"] for node in tree["m_NodeArray"]
                            if node["m_ClipID"] != 0xffffffff})
            assert all(c < len(value["m_AnimationClips"]) for c in clips)
            states.append({"index": i, "name": tos.get(s["m_NameID"]), "path": tos.get(s["m_FullPathID"]),
                "name_id": s["m_NameID"], "full_path_id": s["m_FullPathID"], "speed": s["m_Speed"],
                "speed_parameter": tos.get(s["m_SpeedParamID"]), "loop": s["m_Loop"],
                "clip_indices": clips, "outgoing": [transition(t) for t in s["m_TransitionConstantArray"]]})
        machines.append({"index": smi, "default_state_raw": machine["m_DefaultState"], "states": states,
            "any_state_transitions": [transition(t) for t in machine["m_AnyStateTransitionConstantArray"]],
            "selectors": [{**s, "name": tos.get(s["m_FullPathID"]),
                           "transitions": [transition(t) for t in s["m_TransitionConstantArray"]]}
                          for s in machine["m_SelectorStateConstantArray"]]})
    return {"layers": [{"index": i, "name": tos.get(l["m_Binding"]), **l}
                       for i, l in enumerate(constant["m_LayerArray"])],
            "parameters": [{**p, "name": tos.get(p["m_ID"])} for p in constant["m_Values"]["m_ValueArray"]],
            "machines": machines,
            "boundary": "Raw controller destinations and selectors are retained; selected direct indices are mapped within each state machine. Blend-node clip IDs are dereferenced against this controller's shipped clip table. This is not an engine execution model."}


def build(root, models_path):
    models = models_investigation(models_path)
    node = next(n for n in models.nodes if not n.endswith((".resS", ".resource")))
    metadata = models.metadata(node)
    source = SceneInvestigation(root)
    donor = next(o for o in metadata["objects"] if o["class_id"] == 91)
    donor_type = metadata["types"][donor["type_index"]]
    decoder = TreeDecoder(donor_type["tree"])
    schema = type_tree_spans(models, node, donor["type_index"])
    selected = [(models, node, -1824587515900773540), (source, "resources.assets", 1995)]
    controllers = []
    for investigation, srcnode, pid in selected:
        md = investigation.metadata(srcnode)
        obj = investigation.object(srcnode, pid)
        typ = md["types"][obj["type_index"]]
        assert typ["class_id"] == 91 and typ["old_type_hash"] == donor_type["old_type_hash"]
        assert md["engine_version"] == metadata["engine_version"] == "2022.3.62f2"
        raw = investigation.raw(srcnode, obj)
        decoded = decoder.decode(raw)
        value = decoded["value"]
        index = {p["path"]: p for p in decoded["spans"]}
        clips = []
        for ci, ptr in enumerate(value["m_AnimationClips"]):
            target = investigation.pointer(srcnode, ptr["m_FileID"], ptr["m_PathID"])
            name = None
            if target and "object" in target:
                assert target["object"]["class_id"] == 74
                name = Reader(investigation.raw(target["node"], target["object"])).aligned_string()
            clips.append({"index": ci, "pointer": ptr, "span": index[f"root/m_AnimationClips/Array[{ci}]"],
                          "target": target, "name": name})
        controllers.append({"name": value["m_Name"], "source": investigation.identity(srcnode, obj, raw),
            "raw_hex": raw.hex(), "source_has_type_tree": md["has_type_tree"],
            "schema_match": {"class_id": 91, "old_type_hash": typ["old_type_hash"], "engine_version": md["engine_version"],
                             "rule": "Same engine, class and old_type_hash as the shipped donor; full object consumed to EOF."},
            "decoded": decoded, "graph": graph(value), "clips": clips})

    # Bind the actual Player prefab Animator to the controller and same-object receiver.
    animators = []
    animator_obj = next(o for o in metadata["objects"] if o["class_id"] == 95)
    animator_tree = metadata["types"][animator_obj["type_index"]]["tree"]
    for obj in metadata["objects"]:
        if obj["class_id"] != 95:
            continue
        parsed = TreeDecoder(animator_tree).decode(models.raw(node, obj))
        controller = parsed["value"]["m_Controller"]
        if controller != {"m_FileID": 0, "m_PathID": selected[0][2]}:
            continue
        owner = parsed["value"]["m_GameObject"]
        go = models.pointer(node, owner["m_FileID"], owner["m_PathID"])
        gameobject = models.gameobject(go["node"], go["object"])
        scripts = []
        for pointer in gameobject["components"]:
            component = models.pointer(go["node"], **pointer)
            if component and "object" in component and component["object"]["class_id"] == 114:
                typ = metadata["types"][component["object"]["type_index"]]
                scripts.append({"component": component, "script_identity": models.script(component["node"], typ)})
        animators.append({"source": models.identity(node, obj), "decoded": parsed, "gameobject": gameobject,
                          "same_gameobject_scripts": scripts})
    assert animators
    return {"schema_version": 1, "evidence_type": "Selected full shipped ControllerConstant type-tree decoding and serialized PPtr wiring",
        "sources": [fingerprint(source.bundle.path), fingerprint(models_path)],
        "parser_sources": [fingerprint(HERE / f) for f in ("inspect_animator.py", "animator_tree.py", "inspect_player.py", "inspect_scenes.py", "inspect_resources.py")],
        "controller_schema": {"donor_source": models.identity(node, donor), "schema": schema,
                              "old_type_hash": donor_type["old_type_hash"]},
        "controllers": controllers, "player_animators": animators,
        "npc_event_dependency": fingerprint(HERE / "npc-animation-events.json"),
        "sad_event_dependency": fingerprint(HERE.parent / "salt/symbols/bareta-producer-candidates.json"),
        "condition_mode_reference": {"url": REFERENCE, "branch": "2022.3", "enum": {str(k): v for k, v in CONDITION_MODES.items()},
                                     "boundary": "Official public enum names only; binary field layout comes from the shipped donor schema, not this reference."},
        "limits": ["Static references and transition conditions do not observe playback, competing transition evaluation or event delivery.",
                   "Full selected Player/Npc controller objects are decoded, not every controller or possible runtime override.",
                   "Controller arrays, native field offsets and source SerializedFile offsets have different coordinate systems.",
                   "State motion speed, global Animator speed, layer weights, culling and runtime parameter values can affect whether/when an event fires."]}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    result = build(Path(r"E:\SecretFlasherManakaREA"), HERE.parent / "salt/.cache/decrypted/models.unity3d")
    path = HERE / "animator-wiring.json"
    if args.check:
        assert json.loads(path.read_text(encoding="utf-8")) == result, "Animator evidence differs"
    else:
        path.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"status": "consistent" if args.check else "written", "controllers": len(result["controllers"]),
                      "player_animators": len(result["player_animators"])}))


if __name__ == "__main__":
    main()
