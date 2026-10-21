"""Bind scene-entry REA observations to original metadata, usages and field offsets.

Reads files only. Decompiler references are not an exhaustive call graph. Raw
E8 matches are explicitly byte-pattern corroboration, not a second disassembler.
"""
import argparse
from collections import defaultdict
import hashlib
import json
from pathlib import Path
import re
import sqlite3
import struct

from metadata import DEFAULT_ROOT, HERE, Metadata, PE


def read(path):
    return json.loads(path.read_text(encoding="utf-8-sig"))


def build(batch_prefix="scene-", reuse_method_ids=None, extra_type_names=(), dispatch_targets=None,
          resource_boundary=None):
    identity = read(HERE / "evidence/artifact-identity.json")
    native = (DEFAULT_ROOT / "GameAssembly.dll").read_bytes()
    raw = (DEFAULT_ROOT / "SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat").read_bytes()
    assert hashlib.sha256(native).hexdigest() == identity["native_sha256"]
    assert hashlib.sha256(raw).hexdigest() == identity["metadata_sha256"]
    pe, md = PE(native), Metadata(raw)
    types, definitions = md.records(40, "<16i8H2I"), md.records(12, "<6iI4H")
    fields, literals = md.records(24, "<iiI"), md.records(2, "<II")
    parameters = md.records(22, "<iIi")
    names = {i: ".".join(filter(None, (md.string(t[1]), md.string(t[0])))) for i, t in enumerate(types)}
    byval = {t[2]: i for i, t in enumerate(types)}
    connection = sqlite3.connect((HERE / ".cache/methods.sqlite").as_uri() + "?mode=ro", uri=True)
    connection.row_factory = sqlite3.Row
    assert all(dict(connection.execute("SELECT * FROM identity"))[k] == identity[k] for k in ("native_sha256", "metadata_sha256"))
    methods = {r["id"]: dict(r) for r in connection.execute("SELECT * FROM methods")}
    connection.close()
    aliases = defaultdict(list)
    for m in methods.values():
        if m["va"]:
            aliases[m["va"]].append(m)

    layout = read(HERE / "symbols/field-offsets.json")
    registration = layout["registration"]
    roff = registration["file_offset"]
    assert native[roff:roff + 128] == bytes.fromhex(registration["raw_hex"])
    rows = {row["type_id"]: row for row in layout["all_type_field_offset_rows"]}
    runtime_table = registration["pointer_tables"]["runtime_types"]

    def runtime_type(index):
        assert 0 <= index < runtime_table["count"]
        pointer_offset = runtime_table["file_offset"] + index * 8
        va = struct.unpack_from("<Q", native, pointer_offset)[0]
        offset = pe.offset(va, 12)
        data, bits = struct.unpack_from("<QI", native, offset)
        result = {"index": index, "pointer_file_offset": pointer_offset, "va": hex(va),
                  "file_offset": offset, "raw_hex": native[offset:offset + 12].hex(),
                  "data": data, "attrs": bits & 0xffff, "type_enum": (bits >> 16) & 255}
        if result["type_enum"] in (0x11, 0x12) and data in names:
            result.update(type_id=data, type_name=names[data])
        return result

    def generic_inst(index):
        if index == -1:
            return None
        assert 0 <= index < registration["fields"]["genericInstsCount"]["value"]
        pointer_offset = pe.offset(registration["fields"]["genericInsts"]["value"] + 8 * index, 8)
        pointer = struct.unpack_from("<Q", native, pointer_offset)[0]
        offset = pe.offset(pointer, 16)
        count, argv = struct.unpack_from("<Q Q", native, offset)
        assert count <= 32
        args = []
        for i in range(count):
            poff = pe.offset(argv + i * 8, 8)
            typ = struct.unpack_from("<Q", native, poff)[0]
            toff = pe.offset(typ, 12)
            data, bits = struct.unpack_from("<QI", native, toff)
            arg = {"pointer_file_offset": poff, "type_va": hex(typ), "type_file_offset": toff,
                   "raw_hex": native[toff:toff + 12].hex(), "data": data, "type_enum": (bits >> 16) & 255}
            if arg["type_enum"] in (0x11, 0x12) and data in names:
                arg.update(type_id=data, type_name=names[data])
            args.append(arg)
        return {"index": index, "pointer_file_offset": pointer_offset, "va": hex(pointer), "file_offset": offset,
                "raw_hex": native[offset:offset + 16].hex(), "arguments": args}

    def usage(va):
        offset = pe.offset(va, 8)
        value = struct.unpack_from("<Q", native, offset)[0]
        if value >> 32 or not value & 1 or not 1 <= value >> 29 <= 6:
            return None
        tag, index = value >> 29, (value & 0x1fffffff) >> 1
        result = {"va": hex(va), "file_offset": offset, "raw_hex": native[offset:offset + 8].hex(),
                  "encoded": hex(value), "tag": tag, "index": index}
        if tag == 5:
            size, start = literals[index]
            result.update(value=md.region(4)[start:start + size].decode("utf-8"),
                          literal_definition_file_offset=md.header[2] + 8 * index,
                          literal_data_file_offset=md.header[4] + start)
        elif tag in (1, 2):
            result["runtime_type"] = runtime_type(index)
            if index in byval:
                result.update(type_id=byval[index], type_name=names[byval[index]])
        elif tag == 3:
            result.update(method_id=index, method_name=methods[index]["qualified_name"], method_va=methods[index]["va"])
        elif tag == 6:
            assert index < registration["fields"]["methodSpecsCount"]["value"]
            off = pe.offset(registration["fields"]["methodSpecs"]["value"] + index * 12, 12)
            mid, class_inst, method_inst = struct.unpack_from("<iii", native, off)
            result["method_spec"] = {"file_offset": off, "raw_hex": native[off:off + 12].hex(),
                "method_id": mid, "method_name": methods[mid]["qualified_name"],
                "class_instantiation": generic_inst(class_inst), "method_instantiation": generic_inst(method_inst)}
        return result

    optional = struct.unpack_from("<I", native, 0x3c)[0] + 24
    exception_rva, exception_size = struct.unpack_from("<II", native, optional + 112 + 3 * 8)
    exception_offset = pe.offset(pe.base + exception_rva, exception_size)
    unwind = [(pe.base + a, pe.base + b, exception_offset + i * 12)
              for i, (a, b, _) in enumerate(struct.iter_unpack("<III", native[exception_offset:exception_offset + exception_size]))]

    reused_ids = {16362, 16366, 16369, 16370, 16402, 16403, 16862} if reuse_method_ids is None else set(reuse_method_ids)
    observations, batches, usages = [], [], {}
    named_type_ids = set()
    for path in sorted((HERE / "evidence").glob("*/run.json")):
        new = path.parent.name.startswith(batch_prefix)
        run = read(path)
        entries = run["functions"] if new else [f for f in run["functions"] if f["metadata_id"] in reused_ids]
        if not entries:
            continue
        assert run["success"] and not run.get("close_error") and not run.get("transport_close_error")
        batches.append({"name": path.parent.name, "new_this_round": new, "queries_used": len(entries),
                        "elapsed_seconds": run["elapsed_seconds"]})
        plan = read(HERE / "symbols" / Path(run["plan"]).name)
        seed_path = HERE / "symbols" / Path(plan["seed_file"]).name
        assert hashlib.sha256(seed_path.read_bytes()).hexdigest() == run["seed_sha256"] == plan["seed_sha256"]
        seed_names = {parts[2]: parts[0] for line in seed_path.read_text(encoding="utf-8").splitlines()
                      if not line.startswith("#") and len(parts := line.split("\t")) == 3}
        for f in entries:
            assert f["operation"] == "procedure_pseudo_code"
            m = methods[f["metadata_id"]] if f["metadata_id"] is not None else {
                "id": None, "qualified_name": f["qualified_name"], "va": f["va"],
                "token": 0, "file_offset": f["file_offset"], "type_id": None}
            assert m["va"] == f["va"] and m["token"] == int(f["token"], 16)
            definition_size = struct.calcsize("<6iI4H")
            definition_offset = md.header[12] + m["id"] * definition_size if m["id"] is not None else None
            if m["id"] is not None:
                assert definitions[m["id"]][6] == m["token"]
                assert definitions[m["id"]][1] == m["type_id"]
                assert md.string(definitions[m["id"]][0]) == m["name"]
            assert m["file_offset"] == pe.offset(int(m["va"], 16), executable=True)
            ep = path.parent / (f["file_stem"] + "-procedure_pseudo_code.json")
            record = read(ep)
            assert record["evidence_id"] == f["evidence_id"]
            assert record["subject"]["digest"]["sha256"] == identity["native_sha256"]
            text = record["normalized_result"]
            assert text.strip()
            used = []
            for value in sorted(set(re.findall(r"(?:0x|[Rr]am[0-9]*|DAT_|UNK_)(182d[0-9a-f]{5})\b", text))):
                va = int(value, 16)
                u = usage(va)
                if u:
                    usages[u["va"]] = u
                    used.append(u["va"])
                    if "type_id" in u and types[u["type_id"]][4] >= 0:
                        named_type_ids.add(u["type_id"])
            targets = {"0x" + a for a in re.findall(r"FUN_([0-9a-f]+)\s*\(", text)}
            called_names = set(re.findall(r"\b([A-Za-z_][A-Za-z0-9_]*)\s*\(", text))
            targets.update(seed_names[name] for name in called_names & seed_names.keys())
            targets.discard(m["va"])
            references = []
            for target in sorted(targets):
                aa = aliases.get(target, [])
                if not any(a["image"] == 1 or 49900 <= a["id"] < 50000 for a in aa):
                    continue
                references.append({"va": target, "aliases": [{"id": a["id"], "name": a["qualified_name"]} for a in aa]})
            ranges = [(a, b, off) for a, b, off in unwind if a <= int(m["va"], 16) < b]
            patterns = []
            for begin, end, _ in ranges:
                start = pe.offset(begin, end - begin)
                for delta in range(end - begin - 4):
                    if native[start + delta] == 0xe8:
                        target = begin + delta + 5 + struct.unpack_from("<i", native, start + delta + 1)[0]
                        if hex(target) in targets and hex(target) in aliases:
                            patterns.append({"call_va": hex(begin + delta), "target_va": hex(target),
                                             "file_offset": start + delta, "raw_hex": native[start + delta:start + delta + 5].hex()})
            if m["type_id"] is not None:
                named_type_ids.add(m["type_id"])
            observations.append({"method_id": m["id"], "name": m["qualified_name"], "type_id": m["type_id"],
                "va": m["va"], "token": hex(m["token"]), "file_offset": m["file_offset"],
                "metadata_definition_file_offset": definition_offset,
                "metadata_definition_raw_hex": raw[definition_offset:definition_offset + definition_size].hex() if definition_offset is not None else None,
                "new_this_round": new, "evidence_id": record["evidence_id"], "path": ep.relative_to(HERE.parent).as_posix(),
                "signature": {"return_type": runtime_type(definitions[m["id"]][2]),
                    "flags": definitions[m["id"]][7], "slot": definitions[m["id"]][9],
                    "parameters": [{"name": md.string(parameters[pid][0]), "type": runtime_type(parameters[pid][2]),
                        "metadata_file_offset": md.header[22] + pid * 12,
                        "raw_hex": raw[md.header[22] + pid * 12:md.header[22] + pid * 12 + 12].hex()}
                        for pid in range(definitions[m["id"]][4], definitions[m["id"]][4] + definitions[m["id"]][10])]}
                    if m["id"] is not None else None,
                "usage_vas": used, "pseudocode_method_references": references,
                "containing_unwind_ranges": [{"begin": hex(a), "end_exclusive": hex(b), "pdata_file_offset": off,
                    "raw_hex": native[off:off + 12].hex()} for a, b, off in ranges], "raw_e8_pattern_corroboration": patterns})

    # Persistent state/scene fields also used through shared getter and native helper bodies.
    selected_names = ["SystemManager", "GlobalData", "GameStateData", "InGameReferencer", "MStageRecord", "StageType", "OptionData", "SaveDataType",
                      "SystemStateData", "SystemData", "TempGameState", "SaveCategory", "InGameManager", "IsLoadDataEvent"]
    selected_names.extend(extra_type_names)
    for i, name in names.items():
        if name.rsplit(".", 1)[-1] in selected_names:
            named_type_ids.add(i)
    named = []
    for tid in sorted(named_type_ids):
        t, row = types[tid], rows[tid]
        # Keep game/selected scene types; generic library types would obscure the evidence.
        if not (names[tid].startswith(("ExposureUnnoticed2.", "HadakaCoat.")) or names[tid].startswith("<>")
                or names[tid] == "SaveDataType" or names[tid].rsplit(".", 1)[-1] in extra_type_names):
            continue
        pointer_offset = row["offset_row_pointer_file_offset"]
        pointer = struct.unpack_from("<Q", native, pointer_offset)[0]
        assert pointer == int(row["offset_row_va"], 16)
        if row["field_count"]:
            assert list(struct.unpack_from(f"<{row['field_count']}i", native, pe.offset(pointer))) == row["raw_offsets"]
        ff = []
        for index in range(t[18]):
            fid = t[8] + index
            field = fields[fid]
            rt = runtime_type(field[1])
            offset = row["raw_offsets"][index]
            foff = md.header[24] + fid * 12
            ff.append({"field_id": fid, "name": md.string(field[0]), "token": hex(field[2]),
                       "offset": offset, "offset_hex": hex(offset), "is_static": bool(rt["attrs"] & 0x10),
                       "is_literal": bool(rt["attrs"] & 0x40), "runtime_type": rt,
                       "field_definition_file_offset": foff, "field_definition_raw_hex": raw[foff:foff + 12].hex(),
                       "offset_file_offset": pe.offset(pointer) + index * 4,
                       "offset_raw_hex": struct.pack("<i", offset).hex()})
        named.append({"type_id": tid, "name": names[tid], "fields": ff})
    interface_offsets, vtable = md.records(38, "<ii"), md.records(36, "<I")
    dispatch = []
    selected_dispatch = [(2596, 2599, 16864), (2596, 2592, 16865),
                         (methods[14757]["type_id"], 2599, 14757), (2869, 2863, 18344)] if dispatch_targets is None else dispatch_targets
    for class_id, interface_id, expected_method in selected_dispatch:
        cls, iface = types[class_id], types[interface_id]
        interface_method = iface[9]
        assert iface[16] == 1
        slot = definitions[interface_method][9]
        matches = [(i, interface_offsets[i]) for i in range(cls[15], cls[15] + cls[23])
                   if interface_offsets[i][0] == iface[2]]
        assert len(matches) == 1
        entry_id, (_, base_slot) = matches[0]
        class_slot = base_slot + slot
        assert class_slot < cls[21]
        vtable_index = cls[14] + class_slot
        encoded = vtable[vtable_index][0]
        target = (encoded & 0x1fffffff) >> 1
        assert encoded >> 29 == 3 and target == expected_method
        io_offset, vt_offset = md.header[38] + 8 * entry_id, md.header[36] + 4 * vtable_index
        dispatch.append({"class_type_id": class_id, "class_name": names[class_id], "interface_type_id": interface_id,
            "interface_name": names[interface_id], "interface_method_id": interface_method, "interface_slot": slot,
            "interface_base_slot": base_slot, "class_slot": class_slot,
            "interface_offset_file_offset": io_offset, "interface_offset_raw_hex": raw[io_offset:io_offset + 8].hex(),
            "vtable_file_offset": vt_offset, "vtable_raw_hex": raw[vt_offset:vt_offset + 4].hex(),
            "target_method_id": target, "target_name": methods[target]["qualified_name"], "target_va": methods[target]["va"]})
    return {"schema_version": 1, "evidence_type": "static REA observations bound to original IL2CPP v31 bytes",
            "native_sha256": identity["native_sha256"], "metadata_sha256": identity["metadata_sha256"],
            "batches": batches, "new_observations": sum(o["new_this_round"] for o in observations),
            "new_unique_evidence_ids": len({o["evidence_id"] for o in observations if o["new_this_round"]}),
            "new_unique_procedure_addresses": len({o["va"] for o in observations if o["new_this_round"]}),
            "reused_observations": sum(not o["new_this_round"] for o in observations),
            "methods": observations, "usages": list(sorted(usages.values(), key=lambda u: u["va"])), "named_types": named,
            "interface_dispatch": dispatch,
            "limitations": ["No game execution or runtime callback order observation.",
                "Decompiler text can include inlined callees and followed tail calls; references are not all direct caller edges.",
                "A shared native address retains all metadata aliases; a seed label alone does not prove the receiver type.",
                "Raw E8 patterns only corroborate decompiler targets within the selected PE unwind range; instruction boundaries are not independently decoded here.",
                "TypeInfo usage tags and registered fields give static identity/layout, not current runtime values.",
                resource_boundary or "Scene assets, persistent button calls and Animator controller pointers are separately recorded in assets/scene-inventory.json; animation event payloads remain unresolved."]}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    result = build()
    path = HERE / "evidence/scene-chain.json"
    if args.check:
        assert read(path) == result, "Scene evidence differs; regenerate and review it"
    else:
        path.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"status": "consistent" if args.check else "written", "new_observations": result["new_observations"],
        "reused_observations": result["reused_observations"], "usages": len(result["usages"]), "named_types": len(result["named_types"])}))


if __name__ == "__main__":
    main()
