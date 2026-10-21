"""Recheck player movement/input/action observations using the shared byte binder."""
import argparse
import hashlib
import json
import re

from metadata import HERE
from scene_evidence import build as bind, read


def build():
    result = bind(batch_prefix="player-", reuse_method_ids={14756, 14757, 16734, 16736, 16737, 16738},
                  extra_type_names=("PlayerController", "PlayerObjectReferencer", "PlayerStateModel", "PlayerState",
                                    "InputData", "InputResolver", "InputType", "ActionType", "InteractType",
                                    "InteractModel", "InputManager", "PlayerLocomotion", "PlayerAction", "PlayerClassAccessor",
                                    "PlayerCollisionCorrecter", "MActionRecord", "MCommon", "StaminaManager"),
                  dispatch_targets=[(2215, 2599, 14757)],
                  resource_boundary="Input declarations/bindings and selected prefab configuration are separately recorded in assets/player-config.json; no runtime input or physics was observed.")
    # Keep the already byte-verified frame entry dispatch as an explicit dependency.
    scene = read(HERE / "evidence/scene-chain.json")
    assert scene["native_sha256"] == result["native_sha256"] and scene["metadata_sha256"] == result["metadata_sha256"]
    result["inherited_frame_dispatch"] = [r for r in scene["interface_dispatch"] if r["target_method_id"] in (14757, 16864, 16865)]
    config_path = HERE.parent / "assets/player-config.json"
    config = read(config_path)
    assert config["original_metadata"]["source"]["sha256"] == result["metadata_sha256"]
    assert config["original_metadata"]["native_source"]["sha256"] == result["native_sha256"]
    inputs = next(e for e in config["original_metadata"]["enums"] if e["full_name"].endswith("InputManager/InputType"))
    input_names = {v["value"]: v["name"] for v in inputs["values"]}
    result["configuration_dependency"] = {"path": "assets/player-config.json", "sha256": hashlib.sha256(config_path.read_bytes()).hexdigest(),
        "boundary": "Separately decoded original asset configuration and metadata enum values; default bindings do not establish runtime overrides."}
    selected = {m["method_id"]: m for m in result["methods"] if m["method_id"] is not None}
    if 14421 in selected:
        observation = selected[14421]
        text = read(HERE.parent / observation["path"])["normalized_result"]
        input_type = next(t for t in result["named_types"] if t["name"].endswith(".InputData"))
        fields = {f["offset"]: f for f in input_type["fields"]}
        pattern = (r"(uVar\d+) = ExposureUnnoticed2_Scripts_Base_InputManager__(IsDownFrame|IsDown|GetLongDown)__[0-9a-f]+"
                   r"\s*\(([^;]+?)\)\s*;\s*\*\(undefined1 \*\)\(lVar2 \+ (0x[0-9a-f]+)\) = \1;")
        assignments = []
        for match in re.finditer(pattern, text):
            arguments = [int(a.strip(), 0) for a in match[3].split(",")]
            offset = int(match[4], 16)
            field = fields[offset]
            assignments.append({"input_type_value": arguments[0], "input_type_name": input_names[arguments[0]],
                "reader": match[2], "arguments_including_methodinfo": arguments,
                "input_data_field": field["name"], "field_offset": field["offset_hex"], "field_id": field["field_id"],
                "pseudocode_line": text.count("\n", 0, match.start()) + 1, "source_excerpt": match[0],
                "evidence_id": observation["evidence_id"]})
        result["direct_input_flag_assignments"] = assignments
        assert len(assignments) >= 15
        # Bounded negative result: only stores to this exact Jump field in Resolve.
        jump_writes = re.findall(r"\*\(undefined1 \*\)\(lVar2 \+ 0x24\) = ([^;]+);", text)
        assert jump_writes == ["0"]
        result["jump_input_boundary"] = {"method_id": 14421, "evidence_id": observation["evidence_id"],
            "field_id": fields[0x24]["field_id"], "offset": "0x24", "observed_store_expressions": jump_writes,
            "scope": "Exact lVar2 InputData.Jump stores in this saved Resolve body; not a global no-write proof for all native code or runtime modifications."}
    result["scope"] = "PlayerController to input resolution, locomotion, actions and selected interaction paths in the pinned build"
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    result = build()
    path = HERE / "evidence/player-chain.json"
    if args.check:
        assert read(path) == result, "Player evidence differs; regenerate and review"
    else:
        path.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"status": "consistent" if args.check else "written", "queries": result["new_observations"],
        "unique_addresses": result["new_unique_procedure_addresses"], "reused": result["reused_observations"],
        "usages": len(result["usages"]), "named_types": len(result["named_types"])}))


if __name__ == "__main__":
    main()
