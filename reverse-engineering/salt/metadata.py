"""Index this build's IL2CPP v31 metadata and file-backed native method pointers.

Derived static coordinates, not original source or proof of executed behavior.
The v31 layouts match the shipped LibCpp2IL.Metadata record declarations.
"""
import argparse
import csv
import hashlib
import json
from pathlib import Path
import sqlite3
import struct

HERE = Path(__file__).resolve().parent
DEFAULT_ROOT = Path(r"E:\SecretFlasherManakaREA")
DEFAULT_DB = HERE / ".cache/methods.sqlite"


class Metadata:
    def __init__(self, data):
        self.data = data
        self.header = struct.unpack_from("<64I", data)
        if self.header[:2] != (0xFAB11BAF, 31):
            raise ValueError("Only the verified version-31 layout is supported")
        self.strings = self.region(6)

    def region(self, word):
        offset, size = self.header[word:word + 2]
        if offset + size > len(self.data):
            raise ValueError("Metadata region exceeds source bytes")
        return self.data[offset:offset + size]

    def records(self, word, layout):
        data = self.region(word)
        size = struct.calcsize(layout)
        if len(data) % size:
            raise ValueError(f"Metadata region {word} does not fit {layout}")
        return list(struct.iter_unpack(layout, data))

    def string(self, index):
        if not 0 <= index < len(self.strings):
            raise ValueError("Invalid string-heap index")
        return self.strings[index:self.strings.index(b"\0", index)].decode("utf-8")


class PE:
    def __init__(self, data):
        self.data = data
        pe = struct.unpack_from("<I", data, 0x3C)[0]
        if data[:2] != b"MZ" or data[pe:pe + 4] != b"PE\0\0":
            raise ValueError("Invalid PE image")
        optional = pe + 24
        if struct.unpack_from("<H", data, pe + 4)[0] != 0x8664 or struct.unpack_from("<H", data, optional)[0] != 0x20B:
            raise ValueError("Expected the recorded x64 PE32+ image")
        self.base = struct.unpack_from("<Q", data, optional + 24)[0]
        section_start = optional + struct.unpack_from("<H", data, pe + 20)[0]
        self.sections = []
        for i in range(struct.unpack_from("<H", data, pe + 6)[0]):
            offset = section_start + 40 * i
            virtual_size, rva, raw_size, raw = struct.unpack_from("<4I", data, offset + 8)
            flags = struct.unpack_from("<I", data, offset + 36)[0]
            if raw + raw_size > len(data):
                raise ValueError("PE section exceeds input")
            self.sections.append((rva, raw_size, raw, bool(flags & 0x20000000)))

    def offset(self, va, size=1, executable=False):
        for rva, raw_size, raw, execute in self.sections:
            relative = va - self.base - rva
            if 0 <= relative and relative + size <= raw_size and (execute or not executable):
                return raw + relative
        raise ValueError(f"VA {va:#x} has no suitable file-backed section")

    def address(self, offset):
        for rva, size, raw, execute in self.sections:
            if raw <= offset < raw + size:
                return self.base + rva + offset - raw
        raise ValueError("Offset is outside file-backed sections")

    def module(self, name, expected_count):
        candidates = []
        position = 0
        literal = name.encode() + b"\0"
        while True:
            position = self.data.find(literal, position)
            if position < 0:
                break
            try:
                pointer = struct.pack("<Q", self.address(position))
            except ValueError:
                position += 1
                continue
            reference = 0
            while True:
                reference = self.data.find(pointer, reference)
                if reference < 0:
                    break
                if reference % 8 == 0 and reference + 24 <= len(self.data):
                    count = struct.unpack_from("<I", self.data, reference + 8)[0]
                    table = struct.unpack_from("<Q", self.data, reference + 16)[0]
                    if count == expected_count and count:
                        try:
                            start = self.offset(table, 8 * count)
                            pointers = struct.unpack_from(f"<{count}Q", self.data, start)
                            for value in pointers:
                                if value:
                                    self.offset(value, executable=True)
                            candidates.append((reference, table, pointers))
                        except (ValueError, struct.error):
                            pass
                reference += 1
            position += 1
        candidates = list({item[0]: item for item in candidates}.values())
        return candidates


def index(root, database):
    identity = json.loads((HERE / "evidence/artifact-identity.json").read_text(encoding="utf-8"))
    native_path = root / "GameAssembly.dll"
    metadata_path = root / "SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat"
    native = native_path.read_bytes()
    raw = metadata_path.read_bytes()
    native_hash, metadata_hash = hashlib.sha256(native).hexdigest(), hashlib.sha256(raw).hexdigest()
    if native_hash != identity["native_sha256"] or metadata_hash != identity["metadata_sha256"]:
        raise ValueError("Inputs differ from the recorded build")
    metadata, pe = Metadata(raw), PE(native)
    images = metadata.records(42, "<iiiIiIiIii")
    types = metadata.records(40, "<16i8H2I")
    methods = metadata.records(12, "<6iI4H")
    parameters = metadata.records(22, "<iIi")
    owners = {}
    for image_index, image in enumerate(images):
        for type_index in range(image[2], image[2] + image[3]):
            if type_index in owners or not 0 <= type_index < len(types):
                raise ValueError("Overlapping or out-of-bounds image type ownership")
            owners[type_index] = image_index
    if len(owners) != len(types):
        raise ValueError("Not every type has exactly one image owner")
    expected = [0] * len(images)
    for method in methods:
        image_index = owners[method[1]]
        if method[6] >> 24 != 6:
            raise ValueError("Invalid MethodDef token")
        expected[image_index] = max(expected[image_index], method[6] & 0xFFFFFF)
    modules = {}
    image_rows = []
    for i, image in enumerate(images):
        name = metadata.string(image[0])
        candidates = pe.module(name, expected[i]) if expected[i] else []
        status = "mapped" if len(candidates) == 1 else "ambiguous" if candidates else "no-module"
        if len(candidates) == 1:
            modules[i] = candidates[0][2]
        image_rows.append((i, name, image[2], image[3], expected[i], status,
                           hex(pe.address(candidates[0][0])) if len(candidates) == 1 else None))
    database.parent.mkdir(parents=True, exist_ok=True)
    pending = database.with_suffix(".pending.sqlite")
    if pending.exists():
        raise ValueError(f"Remove or inspect the prior incomplete index first: {pending}")
    connection = sqlite3.connect(pending)
    try:
        connection.executescript("""
        CREATE TABLE identity(key TEXT PRIMARY KEY, value TEXT NOT NULL);
        CREATE TABLE images(id INTEGER PRIMARY KEY,name TEXT,first_type INTEGER,type_count INTEGER,
          method_slots INTEGER,status TEXT,module_va TEXT);
        CREATE TABLE types(id INTEGER PRIMARY KEY,image INTEGER,name TEXT,namespace TEXT,
          full_name TEXT,token INTEGER,flags INTEGER);
        CREATE TABLE methods(id INTEGER PRIMARY KEY,image INTEGER,type_id INTEGER,name TEXT,
          qualified_name TEXT,token INTEGER,parameter_count INTEGER,generic_container INTEGER,
          va TEXT,file_offset INTEGER,status TEXT);
        CREATE TABLE parameters(method_id INTEGER,ordinal INTEGER,name TEXT,type_index INTEGER,token INTEGER);
        CREATE TABLE literals(id INTEGER PRIMARY KEY,file_offset INTEGER,byte_length INTEGER,text TEXT,raw_hex TEXT);
        CREATE INDEX methods_name ON methods(name); CREATE INDEX methods_va ON methods(va);
        CREATE INDEX methods_type ON methods(type_id); CREATE INDEX types_name ON types(full_name);
        """)
        connection.executemany("INSERT INTO identity VALUES (?,?)", [
            ("native_sha256", native_hash), ("metadata_sha256", metadata_hash),
            ("metadata_version", "31"), ("native_path", str(native_path)),
            ("metadata_path", str(metadata_path)), ("schema_version", "1")])
        connection.executemany("INSERT INTO images VALUES (?,?,?,?,?,?,?)", image_rows)
        for i, t in enumerate(types):
            name, namespace = metadata.string(t[0]), metadata.string(t[1])
            full_name = f"{namespace}.{name}" if namespace else name
            connection.execute("INSERT INTO types VALUES (?,?,?,?,?,?,?)",
                               (i, owners[i], name, namespace, full_name, t[-1], t[7] & 0xFFFFFFFF))
            for method_index in range(t[9], t[9] + t[16]):
                if not 0 <= method_index < len(methods) or methods[method_index][1] != i:
                    raise ValueError("Type method span does not match the declared owner")
        for i, m in enumerate(methods):
            image_index, name = owners[m[1]], metadata.string(m[0])
            t = types[m[1]]
            namespace, owner_name = metadata.string(t[1]), metadata.string(t[0])
            qualified = (f"{namespace}." if namespace else "") + owner_name + "::" + name
            slot, va, offset = (m[6] & 0xFFFFFF) - 1, None, None
            status = "no-module"
            if image_index in modules:
                pointer = modules[image_index][slot]
                if pointer:
                    va, offset, status = hex(pointer), pe.offset(pointer, executable=True), "mapped"
                else:
                    status = "generic-or-unresolved" if m[5] >= 0 else "null-pointer"
            connection.execute("INSERT INTO methods VALUES (?,?,?,?,?,?,?,?,?,?,?)",
                               (i, image_index, m[1], name, qualified, m[6], m[-1], m[5], va, offset, status))
            if m[-1] and (m[4] < 0 or m[4] + m[-1] > len(parameters)):
                raise ValueError("Method parameter span exceeds the metadata table")
            for ordinal in range(m[-1]):
                p = parameters[m[4] + ordinal]
                connection.execute("INSERT INTO parameters VALUES (?,?,?,?,?)",
                                   (i, ordinal, metadata.string(p[0]), p[2], p[1]))
        data_start = metadata.header[4]
        literal_data = metadata.region(4)
        for i, (length, offset) in enumerate(metadata.records(2, "<II")):
            value = literal_data[offset:offset + length]
            if len(value) != length:
                raise ValueError("Invalid literal byte range")
            try:
                text = value.decode("utf-8")
            except UnicodeDecodeError:
                text = None
            connection.execute("INSERT INTO literals VALUES (?,?,?,?,?)", (i, data_start + offset, length, text, value.hex()))
        connection.commit()
        status_counts = dict(connection.execute("SELECT status,COUNT(*) FROM methods GROUP BY status"))
        shared = connection.execute("SELECT COUNT(*) FROM (SELECT va FROM methods WHERE va IS NOT NULL GROUP BY va HAVING COUNT(*)>1)").fetchone()[0]
        summary = {"schema_version": 1, "source_kind": "derived-static-IL2CPP-v31-index",
                   "native_sha256": native_hash, "metadata_sha256": metadata_hash,
                   "database": str(database), "images": len(images), "types": len(types), "methods": len(methods),
                   "parameters": len(parameters), "literals": len(metadata.records(2, '<II')),
                   "mapping_status": status_counts, "shared_native_addresses": shared,
                   "image_mapping": [dict(zip(["id","name","first_type","type_count","method_slots","status","module_va"], r)) for r in image_rows],
                   "limitations": ["Only the pinned build and v31 layouts are supported.",
                       "Generic methods with null pointers remain unresolved; runtime generic contexts are not reconstructed.",
                       "Duplicate native addresses preserve all metadata aliases and do not identify a unique runtime method.",
                       "Type names do not reconstruct nested-type ownership or C++/C# signatures.",
                       "Parameter and return type indices refer to runtime Il2CppType data, not decoded source types.",
                       "No original code was loaded or executed; metadata names and tokens are build-local coordinates."]}
        output = HERE / "symbols"
        output.mkdir(exist_ok=True)
        (output / "index-summary.json").write_text(json.dumps(summary, indent=2) + "\n", encoding="utf-8")
        rows = connection.execute("""SELECT images.name,types.full_name,methods.name,printf('0x%08x',methods.token),
          methods.parameter_count,methods.va,printf('0x%x',methods.file_offset),methods.status FROM methods
          JOIN images ON images.id=methods.image JOIN types ON types.id=methods.type_id
          WHERE images.name='IKA9nt.Encrypter.dll' ORDER BY methods.token""")
        with (output / "encrypter.methods.tsv").open("w", encoding="utf-8", newline="") as f:
            writer = csv.writer(f, delimiter="\t")
            writer.writerow(["assembly","type","method","token","parameter_count","va","file_offset","status"])
            writer.writerows(rows)
    finally:
        connection.close()
    pending.replace(database)
    print(json.dumps({k: summary[k] for k in ["database","images","types","methods","mapping_status","shared_native_addresses"]}, indent=2))


def find(database, assembly, owner, method, limit):
    connection = sqlite3.connect(database.resolve().as_uri() + "?mode=ro", uri=True)
    connection.row_factory = sqlite3.Row
    clauses, values = [], []
    for field, term in [("images.name", assembly), ("types.full_name", owner), ("methods.name", method)]:
        if term:
            clauses.append(f"{field} LIKE ?")
            values.append(f"%{term}%")
    where = " AND ".join(clauses) or "1"
    rows = connection.execute(f"""SELECT methods.*,images.name AS assembly,types.full_name AS type FROM methods
        JOIN images ON images.id=methods.image JOIN types ON types.id=methods.type_id
        WHERE {where} ORDER BY images.id,methods.token LIMIT ?""", [*values, limit]).fetchall()
    result = [dict(row) for row in rows]
    for row in result:
        row["token"] = hex(row["token"])
    connection.close()
    print(json.dumps(result, ensure_ascii=True, indent=2))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest="command", required=True)
    build = sub.add_parser("index")
    build.add_argument("--root", type=Path, default=DEFAULT_ROOT)
    build.add_argument("--database", type=Path, default=DEFAULT_DB)
    query = sub.add_parser("find")
    query.add_argument("--database", type=Path, default=DEFAULT_DB)
    query.add_argument("--assembly")
    query.add_argument("--type", dest="owner")
    query.add_argument("--method")
    query.add_argument("--limit", type=int, default=30)
    args = parser.parse_args()
    if args.command == "index":
        index(args.root.resolve(), args.database.resolve())
    else:
        if not 1 <= args.limit <= 500:
            parser.error("limit must be 1..500")
        find(args.database, args.assembly, args.owner, args.method, args.limit)
