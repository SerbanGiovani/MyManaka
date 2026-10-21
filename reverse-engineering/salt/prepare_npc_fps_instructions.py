"""Select original PE unwind fragments, following explicit CHAININFO links."""
import hashlib
import json
import sqlite3
import struct

from metadata import HERE, DEFAULT_ROOT, PE


def prepare():
    native_path = DEFAULT_ROOT / "GameAssembly.dll"
    native = native_path.read_bytes()
    identity = json.loads((HERE / "evidence/artifact-identity.json").read_text(encoding="utf-8"))
    assert hashlib.sha256(native).hexdigest() == identity["native_sha256"]
    pe = PE(native)
    optional = struct.unpack_from("<I", native, 0x3c)[0] + 24
    rva, size = struct.unpack_from("<II", native, optional + 136)
    offset = pe.offset(pe.base + rva, size)
    rows = list(struct.iter_unpack("<III", native[offset:offset + size]))
    by_record = {r: i for i, r in enumerate(rows)}
    roots, paths = {}, {}

    def root(record, seen=()):
        if record in roots:
            return roots[record]
        assert record not in seen
        pos = pe.offset(pe.base + record[2], 4)
        version_flags, _, count, _ = struct.unpack_from("<4B", native, pos)
        assert version_flags & 7 in (1, 2)
        length = 4 + ((count * 2 + 3) // 4) * 4
        chain = None
        if version_flags >> 3 & 4:
            chain = struct.unpack_from("<III", native, pos + length)
            assert chain in by_record
            length += 12
        part = {"record": [hex(v) for v in record], "version": version_flags & 7, "file_offset": pos,
                "raw_hex": native[pos:pos + length].hex(), "chain": [hex(v) for v in chain] if chain else None}
        roots[record] = root(chain, (*seen, record)) if chain else record
        paths[record] = [part, *paths[chain]] if chain else [part]
        return roots[record]

    for row in rows:
        root(row)
    connection = sqlite3.connect((HERE / ".cache/methods.sqlite").as_uri() + "?mode=ro", uri=True)
    assert dict(connection.execute("select * from identity"))["native_sha256"] == identity["native_sha256"]
    targets = [(mid, int(connection.execute("select va from methods where id=?", (mid,)).fetchone()[0], 16))
               for mid in (15404, 15405, 19028, 15350, 17302, 17308, 17309, 17263, 15536)]
    connection.close()
    targets.append((None, 0x1803d4630))  # Saved REA DistSqrt body names this native callee.
    selected = []
    for mid, va in targets:
        containing = [r for r in rows if pe.base + r[0] <= va < pe.base + r[1]]
        assert len(containing) == 1
        anchor = root(containing[0])
        for row in rows:
            if root(row) != anchor:
                continue
            a, b, _ = row
            i = by_record[row]
            selected.append({"method_id": mid, "requested_va": hex(va), "begin": hex(pe.base + a),
                "end_exclusive": hex(pe.base + b), "file_offset": pe.offset(pe.base + a, b - a), "size": b - a,
                "pdata_file_offset": offset + i * 12, "pdata_raw_hex": native[offset + i * 12:offset + i * 12 + 12].hex(),
                "unwind_chain": paths[row]})
    decoder = DEFAULT_ROOT / "BepInEx/core/Iced.dll"
    result = {"native": {"path": str(native_path), "sha256": identity["native_sha256"]},
        "decoder": {"path": str(decoder), "sha256": hashlib.sha256(decoder.read_bytes()).hexdigest()},
        "preparer": {"path": str(HERE / "prepare_npc_fps_instructions.py"),
                     "sha256": hashlib.sha256((HERE / "prepare_npc_fps_instructions.py").read_bytes()).hexdigest()},
        "ranges": selected}
    (HERE / ".cache/npc-fps-decoder-input.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"methods": len(targets), "unwind_fragments": len(selected)}))


if __name__ == "__main__":
    prepare()
