"""Bind selected controller/event wiring to retained REA and original IL2CPP bytes."""
import argparse
import hashlib
import json
import re

from metadata import HERE
from scene_evidence import build as bind, read


def build():
    result = bind(batch_prefix="animator-", reuse_method_ids={14504, 14536, 14537, 14542, 14543, 14714,
        14570, 14571, 14572, 14765, 15347, 15350, 15358, 15526, 15528, 15548, 15549, 15550, 16685},
        extra_type_names=("PlayerAnimationManager", "NpcAnimationManager", "NpcComponentAccessor",
                          "NpcController", "NpcAvatarComponent", "NpcAnimationEventReceiver",
                          "PlayerAnimationReceiver", "PlayerClassAccessor", "NpcStateModel"),
        dispatch_targets=[], resource_boundary="Selected full ControllerConstant graphs and actual clip events are in assets/animator-wiring.json and assets/npc-animation-events.json. Static conditions do not establish playback or event delivery.")
    result["asset_dependencies"] = []
    for name in ("assets/animator-wiring.json", "assets/npc-animation-events.json",
                 "salt/symbols/bareta-producer-candidates.json"):
        path = HERE.parent / name
        result["asset_dependencies"].append({"path": name, "sha256": hashlib.sha256(path.read_bytes()).hexdigest()})
    wiring = read(HERE.parent / "assets/animator-wiring.json")
    usages = {u["va"]: u for u in result["usages"]}
    links = []
    for mid, typename, pointer, controller in ((14553, "PlayerAnimationManager", "lRam0000000182d6f340", "Player"),
                                            (15400, "NpcAnimationManager", "DAT_182d59ea8", "Npc")):
        method = next(m for m in result["methods"] if m["method_id"] == mid)
        body = read(HERE.parent / method["path"])["normalized_result"]
        fields = {f["offset"]: f for t in result["named_types"] if t["name"].endswith("." + typename)
                  for f in t["fields"] if f["is_static"] and not f["is_literal"]}
        tos = {r["second"]: r["first"] for c in wiring["controllers"] if c["name"] == controller
               for r in c["decoded"]["value"]["m_TOS"]}
        # Uniform retained cctor pattern: literal load -> StringToHash -> field store.
        pattern = re.compile(r"uVar3 = uRam[0-9]*(182d[0-9a-f]{5});(.*?)(?=uVar3 = uRam|return;)", re.S)
        for match in pattern.finditer(body):
            chunk = match[0]
            if "uVar1 = (*pcRam0000000182ebf318)(uVar3);" not in chunk:
                continue
            base = re.escape(pointer) + r" \+ 0xb8"
            store = re.search(r"\*\(undefined4 \*\)\(\*\(longlong \*\)\(" + base + r"\) \+ (0x[0-9a-f]+|[0-9]+)\) = uVar1;", chunk)
            zero = re.search(r"\*\*\(undefined4 \*\*\)\(" + base + r"\) = uVar1;", chunk)
            assert store or zero, (mid, chunk)
            offset = int(store[1], 0) if store else 0
            usage = usages[hex(int(match[1], 16))]
            assert usage["tag"] == 5 and offset in fields
            links.append({"method_id": mid, "evidence_id": method["evidence_id"], "controller": controller,
                "field": fields[offset], "literal_usage": usage, "controller_tos_hash": tos.get(usage["value"]),
                "pseudocode_line": body.count("\n", 0, match.start()) + 1, "source_excerpt": chunk})
    assert len(links) >= 60
    for controller, literal in (("Player", "ActionId"), ("Player", "TransAction"), ("Player", "BaretaEscape"),
                               ("Npc", "IsFoundStranger"), ("Npc", "IsFemale"), ("Npc", "IsSit")):
        assert any(l["controller"] == controller and l["literal_usage"]["value"] == literal and
                   l["controller_tos_hash"] is not None for l in links), (controller, literal)
    result["native_parameter_hash_links"] = links
    result["hash_link_boundary"] = "Literal -> StringToHash ICall -> registered static field is decompiled evidence. Hash numbers are independently serialized controller TOS values for the same names, not observed ICall returns. Null TOS values are preserved."
    result["scope"] = "NPC discovery and Player Sad/BaretaEscape Animator parameters, transitions, clip events and receiver initialization"
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    result = build()
    path = HERE / "evidence/animator-chain.json"
    if args.check:
        assert read(path) == result, "Animator evidence differs; regenerate and review"
    else:
        path.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"status": "consistent" if args.check else "written", "queries": result["new_observations"],
                      "reused": result["reused_observations"], "hash_links": len(result["native_parameter_hash_links"])}))


if __name__ == "__main__":
    main()
