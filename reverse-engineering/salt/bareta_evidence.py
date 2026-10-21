"""Bind the discovered/escape state investigation to saved REA and original bytes."""
import argparse
import hashlib
import json
import re

from metadata import HERE
from scene_evidence import build as bind, read


def build():
    result = bind(batch_prefix="bareta-", reuse_method_ids={14714, 14756, 14757, 14758, 14759, 14762, 14894,
                                                         14900, 14964, 17074, 16862, 16864},
                  extra_type_names=("PlayerBaretaState", "PlayerBaretaEscapeState", "PlayerClassAccessor",
                                    "PlayerStateModel", "PlayerController", "PlayerAnimationManager",
                                    "PlayerFacade", "NpcController", "NpcManager", "NpcComponentAccessor",
                                    "NpcStateModel", "PlayerSearcher", "PlayerSearcherChild", "MCommon",
                                    "NpcFoundStrangerState", "NpcState", "NpcSubState", "LookAtLayer",
                                    "NpcStrangenessManager", "PlayerStrangenessController", "MentalManager",
                                    "GameOverController", "TemporaryInGameState", "PortalController", "PortalManager",
                                    "MRankRecord", "RSkillMental", "FoundStrangerEvent", "StrangenessValueManager",
                                    "NpcAnimationEventReceiver", "Events", "MissionFailedPanelView"),
                  dispatch_targets=[],
                  resource_boundary="Selected defaults and state enums are in assets/player-config.json; static paths do not establish runtime detection, escape success or actual animation events.")
    scene = read(HERE / "evidence/scene-chain.json")
    assert scene["native_sha256"] == result["native_sha256"] and scene["metadata_sha256"] == result["metadata_sha256"]
    result["inherited_frame_dispatch"] = [d for d in scene["interface_dispatch"] if d["target_method_id"] == 14757]
    config_path = HERE.parent / "assets/player-config.json"
    config = read(config_path)
    assert config["original_metadata"]["source"]["sha256"] == result["metadata_sha256"]
    states = next(e for e in config["original_metadata"]["enums"] if e["full_name"].endswith("PlayerStateModel/PlayerState"))
    result["player_state_values"] = states
    result["configuration_dependency"] = {"path": "assets/player-config.json",
        "sha256": hashlib.sha256(config_path.read_bytes()).hexdigest(),
        "boundary": "Previously byte-verified original configuration and enum values; not runtime state."}
    extra_path = HERE.parent / "assets/bareta-config.json"
    extra = read(extra_path)
    assert extra["original_metadata"]["source"]["sha256"] == result["metadata_sha256"]
    assert extra["original_metadata"]["native_source"]["sha256"] == result["native_sha256"]
    result["state_configuration_dependency"] = {"path": "assets/bareta-config.json",
        "sha256": hashlib.sha256(extra_path.read_bytes()).hexdigest(),
        "boundary": "Selected original enums and resource parameters; a field's existence is not proof of use by a particular path."}
    producer_path = HERE / "symbols/bareta-producer-candidates.json"
    producer = read(producer_path)
    result["producer_and_animation_dependency"] = {"path": "salt/symbols/bareta-producer-candidates.json",
        "sha256": hashlib.sha256(producer_path.read_bytes()).hexdigest(),
        "native_producer_method_id": producer["method"]["id"],
        "boundary": "The candidate producer is separately corroborated by the saved REA bodies 15350/15358. AnimationClip events are actual serialized records; Animator selection and runtime firing are not established."}
    calls = []
    pattern = re.compile(r"(?:ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController__ChangeState__[0-9a-f]+|FUN_180645070)\s*\(([^;]+?)\)")
    for method in result["methods"]:
        body = read(HERE.parent / method["path"])["normalized_result"]
        for match in pattern.finditer(body):
            args = [arg.strip() for arg in match[1].split(",")]
            if len(args) == 3 and args[1] in ("0", "1", "2"):
                calls.append({"source_method_id": method["method_id"], "source_va": method["va"],
                    "evidence_id": method["evidence_id"], "target_method_id": 14759,
                    "requested_player_state": int(args[1]), "arguments_including_methodinfo": args,
                    "pseudocode_line": body.count("\n", 0, match.start()) + 1, "source_excerpt": match[0]})
    result["literal_state_change_calls"] = calls
    result["state_change_call_boundary"] = "Literal arguments at selected decompiled ChangeState references; may be inlined callees. Conditions remain in the full saved body; absence does not prove no global/runtime transition."
    result["scope"] = "Selected NPC discovery to Player Bareta/BaretaEscape entry, update, exit and recovery paths"
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    result = build()
    path = HERE / "evidence/bareta-chain.json"
    if args.check:
        assert read(path) == result, "Bareta evidence differs; regenerate and review"
    else:
        path.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"status": "consistent" if args.check else "written", "queries": result["new_observations"],
        "unique_addresses": result["new_unique_procedure_addresses"], "reused": result["reused_observations"],
        "usages": len(result["usages"]), "named_types": len(result["named_types"])}))


if __name__ == "__main__":
    main()
