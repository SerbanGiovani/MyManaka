"""Bind FPS pseudocode, assembly availability, original instruction bytes and timing."""
import argparse
import hashlib
import json
import re
import struct
from pathlib import Path

from metadata import DEFAULT_ROOT, HERE, PE
from scene_evidence import build as bind, read
from npc_fps_timing import examples


def build():
    result = bind(batch_prefix="npc-fps-", reuse_method_ids={15404, 15405, 15350, 15358, 15524, 15590, 17304,
        15518, 15359, 15403}, extra_type_names=("NpcAnimatorFpsController", "AnimatorFPSController", "CullingData",
        "DelayTimeModel", "TemporaryInGameState", "InGameManager", "NpcManager", "NpcController",
        "NpcStateModel", "NpcComponentAccessor", "NpcAvatarComponent", "PlayerController"), dispatch_targets=[],
        resource_boundary="FPS control arithmetic and static argument setup are distinct from UnityPlayer evaluation/event delivery. No game execution was performed.")
    result["dependencies"] = []
    for name in ("assets/npc-animation-events.json", "assets/npc-model-wiring.json", "assets/animator-wiring.json", "assets/bareta-config.json"):
        result["dependencies"].append({"path": name, "sha256": hashlib.sha256((HERE.parent / name).read_bytes()).hexdigest()})
    assembly = []
    for path in sorted((HERE / "evidence").glob("npc-fps-*/run.json")):
        run = read(path)
        assert run["success"] and not run.get("close_error") and not run.get("transport_close_error")
        for fn in run["functions"]:
            if fn["operation"] != "procedure_assembly":
                continue
            ep = path.parent / (fn["file_stem"] + "-procedure_assembly.json")
            ev = read(ep)
            assert ev["subject"]["digest"]["sha256"] == result["native_sha256"] and ev["evidence_id"] == fn["evidence_id"]
            assert any(m["method_id"] == fn["metadata_id"] and m["va"] == fn["va"] for m in result["methods"])
            assembly.append({"method_id": fn["metadata_id"], "va": fn["va"], "evidence_id": ev["evidence_id"],
                "path": ep.relative_to(HERE.parent).as_posix(), "nonempty": bool(ev["normalized_result"].strip())})
    result["rea_assembly_observations"] = assembly
    result["new_pseudocode_observations"] = result["new_observations"]
    result["new_observations"] += len(assembly)
    result["new_nonempty_observations"] = result["new_pseudocode_observations"] + sum(a["nonempty"] for a in assembly)
    result["new_unique_pseudocode_evidence_ids"] = result["new_unique_evidence_ids"]
    result["new_unique_evidence_ids"] = len({m["evidence_id"] for m in result["methods"] if m["new_this_round"]} | {a["evidence_id"] for a in assembly})
    result["new_unique_procedure_addresses"] = len({m["va"] for m in result["methods"] if m["new_this_round"]} | {a["va"] for a in assembly})
    result["assembly_boundary"] = "Empty REA Listing results are retained as unavailable and supply no instruction evidence. Supplemental Iced decoding below supplies the missing static ABI bytes."
    native = (DEFAULT_ROOT / "GameAssembly.dll").read_bytes()
    pe = PE(native)
    decoded_path = HERE / "symbols/npc-fps-instructions.json"
    decoded = read(decoded_path)
    assert decoded["native"]["sha256"] == hashlib.sha256(native).hexdigest() == result["native_sha256"]
    for source in (decoded["decoder"], decoded["parser"], decoded["preparer"]):
        assert hashlib.sha256(Path(source["path"]).read_bytes()).hexdigest() == source["sha256"]
    instructions = {}
    for region in decoded["ranges"]:
        off = region["pdata_file_offset"]
        assert native[off:off + 12].hex() == region["pdata_raw_hex"]
        a, b, u = struct.unpack_from("<III", native, off)
        assert hex(pe.base + a) == region["begin"] and hex(pe.base + b) == region["end_exclusive"]
        for chain in region["unwind_chain"]:
            raw = bytes.fromhex(chain["raw_hex"])
            assert native[chain["file_offset"]:chain["file_offset"] + len(raw)] == raw
            assert pe.offset(pe.base + int(chain["record"][2], 16)) == chain["file_offset"]
        position = pe.base + a
        for row in region["instructions"]:
            raw = bytes.fromhex(row["raw_hex"])
            assert int(row["va"], 16) == position and row["file_offset"] == pe.offset(position, len(raw))
            assert len(raw) == row["length"] and native[row["file_offset"]:row["file_offset"] + len(raw)] == raw
            instructions[position] = row
            position += len(raw)
        assert position == pe.base + b
    def window(begin, end):
        return [instructions[va] for va in sorted(instructions) if begin <= va < end]
    for va, text in ((0x18041ee21, "movss xmm7,dword ptr [rbx+24h]"), (0x18041ee49, "movaps xmm6,xmm0"),
                     (0x18041ee51, "addss xmm6,xmm7"), (0x18041ee90, "movaps xmm1,xmm6"),
                     (0x18041ee96, "call rax"), (0x18041ee98, "mov dword ptr [rbx+24h],0"),
                     (0x18057e634, "movaps xmm1,xmm6"), (0x18057e63a, "call rax"),
                     (0x1804b5111, "subss xmm6,xmm0"), (0x1803d46d5, "sqrtpd xmm0,xmm1")):
        assert instructions[va]["text"] == text, (hex(va), instructions[va])
    result["instruction_dependency"] = {"path": decoded_path.relative_to(HERE.parent).as_posix(),
        "sha256": hashlib.sha256(decoded_path.read_bytes()).hexdigest(), "ranges": len(decoded["ranges"]),
        "instruction_count": len(instructions)}
    result["abi_windows"] = [
        {"claim": "NPC manual Update forwards accumulated admitted delta in XMM1, then clears skippedTime", "instructions": window(0x18041ee03, 0x18041ee9f)},
        {"claim": "Common helper uses the same XMM1 argument setup", "instructions": window(0x18057e5b3, 0x18057e648)},
        {"claim": "Receiver sends float32 0.6 to DelayScaledTime", "instructions": window(0x18041a793, 0x18041a7a6)},
        {"claim": "Distance callee squares components then takes sqrt", "instructions": window(0x1803d4686, 0x1803d46eb)},
        {"claim": "DelayTimeModel conditional decrement and expiry outside the pause gate", "instructions": window(0x1804b50a6, 0x1804b514a)}]
    assert instructions[0x18042a9f7]["text"] == "xorps xmm1,xmm1"
    assert instructions[0x18042a7b0]["text"] == "movss xmm1,dword ptr [rbx+74h]"
    result["abi_windows"].extend([
        {"claim": "Time-stop branch passes float zero to Animator.set_speed", "instructions": window(0x18042a9cf, 0x18042aa08)},
        {"claim": "Resume branch restores the saved animator speed", "instructions": window(0x18042a7a8, 0x18042a7c0)}])
    literals = []
    for va in (0x1824aa840, 0x1824bcca0, 0x1824ba950):
        off = pe.offset(va)
        end = native.index(b"\0", off)
        literals.append({"va": hex(va), "file_offset": off, "raw_hex": native[off:end + 1].hex(), "value": native[off:end].decode("ascii")})
    assert literals[0]["value"] == "UnityEngine.Animator::Update(System.Single)"
    off = pe.offset(0x182a941a4, 4)
    assert native[off:off + 4].hex() == "9a99193f"
    result["abi_literals"] = literals
    result["notification_delay_constant"] = {"va": "0x182a941a4", "file_offset": off,
        "raw_hex": native[off:off + 4].hex(), "float32": struct.unpack_from("<f", native, off)[0]}
    initial = next(m for m in result["methods"] if m["method_id"] == 15404)
    body = read(HERE.parent / initial["path"])["normalized_result"]
    stores = re.findall(r"\*\(undefined4 \*\)\(uVar6 \+ (0x[0-9a-f]+|[0-9]+)\) = (0x[0-9a-f]+|[0-9]+);", body)
    assert len(stores) == 16
    culling = next(t for t in result["named_types"] if t["name"].endswith("CullingData"))
    names = {f["offset"]: f["name"] for f in culling["fields"]}
    result["distance_configurations"] = [{"stage_numeric": stage, "source_evidence_id": initial["evidence_id"],
        "fields": [{"offset": int(o, 0), "name": names[int(o, 0)], "value": int(v, 0)} for o, v in stores[start:start + 8]]}
        for stage, start in ((11, 0), ("other", 8))]
    result["timing_examples"] = examples()
    result["primary_references"] = [
        "https://learn.microsoft.com/en-us/cpp/build/x64-calling-convention?view=msvc-170",
        "https://docs.unity3d.com/2022.3/Documentation/ScriptReference/Animator.Update.html",
        "https://docs.unity3d.com/2022.3/Documentation/ScriptReference/Animator-fireEvents.html",
        "https://docs.unity3d.com/2022.3/Documentation/Manual/profiler-markers.html#animation"]
    result["scope"] = "Selected distance FPS gates, manual evaluation ABI, upper caller admission and discovery notification clock/pause"
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    result = build()
    path = HERE / "evidence/npc-fps-chain.json"
    if args.check:
        assert read(path) == result, "NPC FPS evidence differs; regenerate and review"
    else:
        path.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"status": "consistent" if args.check else "written", "queries": result["new_observations"],
        "nonempty": result["new_nonempty_observations"], "instructions": result["instruction_dependency"]["instruction_count"]}))


if __name__ == "__main__":
    main()
