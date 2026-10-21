"""Prepare a metadata-bound REA batch for the Windows bundle loading chain."""
import argparse
import hashlib
import json
from pathlib import Path
import sqlite3

from prepare_batch import DISABLED, HERE, label
from metadata import PE

CORE_TOKENS = [0x1e, 0x6b, 0x6e, 0x70, 0x71, 0x72, 0x74, 0x77,
               0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x80, 0x84,
               0x87, 0xae, 0xaf, 0xb4, 0xb7, 0xbf, 0xc0, 0xc4, 0xd1]
HELPER_TYPES = ["UnityEngine.AssetBundle", "UnityEngine.Resources", "UnityEngine.Application",
                "System.IO.File", "System.IO.FileStream", "System.IO.MemoryStream",
                "System.IO.Path", "System.Int64", "System.String"]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--name", default="loading")
    parser.add_argument("--method-id", type=int, action="append")
    parser.add_argument("--native-va", action="append", help="Explicit native-only callee address from prior evidence")
    args = parser.parse_args()
    import re
    if not re.fullmatch(r"[a-z][a-z0-9-]{0,40}", args.name):
        parser.error("name must be a lowercase slug")
    connection = sqlite3.connect((HERE / ".cache/methods.sqlite").as_uri() + "?mode=ro", uri=True)
    connection.row_factory = sqlite3.Row
    rows = [dict(r) for r in connection.execute("""SELECT m.*,i.name AS assembly,t.full_name AS owner FROM methods m
        JOIN images i ON i.id=m.image JOIN types t ON t.id=m.type_id WHERE m.status='mapped' ORDER BY m.id""")]
    selected = [r for r in rows if r["id"] in (args.method_id or [])] if args.method_id or args.native_va else [
        r for r in rows if r["assembly"] == "IKA9nt.Encrypter.dll" and (r["token"] & 0xffffff) in CORE_TOKENS]
    expected = args.method_id or ([] if args.native_va else CORE_TOKENS)
    if len(selected) != len(set(expected)):
        raise ValueError("One or more selected methods is missing or unmapped")
    identity = json.loads((HERE / "evidence/artifact-identity.json").read_text(encoding="utf-8"))
    database_identity = dict(connection.execute("SELECT * FROM identity"))
    connection.close()
    if any(database_identity[k] != identity[k] for k in ("native_sha256", "metadata_sha256")):
        raise ValueError("Method index belongs to a different build")
    native_path = Path(identity["original_directory"]) / "GameAssembly.dll"
    native = native_path.read_bytes()
    if hashlib.sha256(native).hexdigest() != identity["native_sha256"]:
        raise ValueError("Native input differs from recorded build")
    pe = PE(native)
    for address in dict.fromkeys(args.native_va or []):
        va = int(address, 0)
        selected.append({"id": None, "qualified_name": f"native_only_{va:x}", "token": 0,
                         "va": hex(va), "file_offset": pe.offset(va, executable=True), "assembly": None})
    seeds = {r["va"]: r for r in selected}
    for r in rows:
        if r["assembly"] == "IKA9nt.Encrypter.dll" or r["owner"] in HELPER_TYPES:
            seeds.setdefault(r["va"], r)
    seed_path = HERE / f"symbols/{args.name}.seeds.tsv"
    seed_path.write_text("# Metadata-derived assertions; first alias displayed, all aliases retained in SQLite.\n" +
                         "".join(f"{r['va']}\tfunction\t{label(r)}\n" for r in sorted(seeds.values(), key=lambda r: int(r["va"], 16))), encoding="utf-8")
    plan = {"schema_version": 1, "name": args.name, "target": str(Path(identity["original_directory"]) / "GameAssembly.dll"),
            "native_sha256": identity["native_sha256"], "metadata_sha256": identity["metadata_sha256"],
            "seed_file": str(seed_path), "seed_sha256": hashlib.sha256(seed_path.read_bytes()).hexdigest(),
            "disabled_analyzers": DISABLED, "timeout_ms": 600000,
            "output_directory": str(HERE / f"evidence/{args.name}"), "seed_count": len(seeds),
            "functions": [{"metadata_id": r["id"], "qualified_name": r["qualified_name"], "assembly": r["assembly"],
                "token": hex(r["token"]), "va": r["va"], "file_offset": r["file_offset"], "label": label(r),
                "file_stem": f"{r['id']}-{r['token']:08x}" if r['id'] is not None else f"native-{r['va']}",
                "operations": ["procedure_pseudo_code"]} for r in selected],
            "limitations": ["Static observations; no game execution.", "Seeds are metadata assertions, not recovered source.",
                            "Disabled whole-library discovery leaves indirect calls and generic bodies incomplete."]}
    path = HERE / f"symbols/{args.name}.plan.json"
    path.write_text(json.dumps(plan, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"plan": str(path), "functions": len(selected), "seeds": len(seeds)}, indent=2))


if __name__ == "__main__":
    main()
