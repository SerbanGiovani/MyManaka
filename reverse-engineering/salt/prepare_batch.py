"""Select metadata-backed function coordinates for a resource-crypto REA batch."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import sqlite3

HERE = Path(__file__).resolve().parent
DISABLED = ["Disassemble Entry Points", "Function Start Search", "Subroutine References",
            "Reference", "Data Reference", "Create Address Tables",
            "Non-Returning Functions - Discovered", "Decompiler Switch Analysis"]
WANTED = [
    ("IKA9nt.Encrypter.EncrypterCore", "GetStream", 4),
    ("IKA9nt.Encrypter.EncrypterCore", "GetPasswordFromMap", 2),
    ("IKA9nt.Encrypter.EncrypterCore", "GetPasswordFromAdditionalMap", 1),
    ("IKA9nt.Encrypter.EncrypterCore", "PasswordCharacterSubstring", 1),
    ("PasswordMap", ".ctor", 0), ("PasswordMap", "Substring", 1),
    ("SeekableAesAssetBundle.Scripts.SeekableAesStream", ".ctor", 6),
    ("SeekableAesAssetBundle.Scripts.SeekableAesStream", "Cipher", 4),
    ("SeekableAesAssetBundle.Scripts.SeekableAesStream", "Read", 3),
    ("SeekableAesAssetBundle.Scripts.SeekableAesStream", "Read", 4),
]
HELPERS = ["System.Security.Cryptography.Rfc2898DeriveBytes",
           "System.Security.Cryptography.AesManaged", "System.Security.Cryptography.SymmetricAlgorithm",
           "System.Security.Cryptography.Aes", "System.Int64", "System.Text.Encoding"]


def label(row):
    return re.sub(r"[^A-Za-z0-9_]", "_", row["qualified_name"]) + f"__{row['token']:08x}"


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--phase", choices=("chain", "helpers"), default="chain")
    parser.add_argument("--method-id", type=int, action="append", help="Build a custom batch from metadata.py find IDs")
    parser.add_argument("--name", help="Custom plan slug")
    args = parser.parse_args()
    wanted = WANTED if args.phase == "chain" else [
        ("PasswordMap", ".cctor", 0),
        ("System.Security.Cryptography.Rfc2898DeriveBytes", ".ctor", 3),
        ("System.String", "TrimWhiteSpaceHelper", 1)]
    suffix = "" if args.phase == "chain" else "-helpers"
    if args.method_id:
        slug = args.name or "custom"
        if not re.fullmatch(r"[a-z][a-z0-9-]{0,40}", slug):
            parser.error("name must be a lowercase plan slug, at most 41 characters")
        suffix = "-" + slug
    connection = sqlite3.connect((HERE / ".cache/methods.sqlite").as_uri() + "?mode=ro", uri=True)
    connection.row_factory = sqlite3.Row
    selected = []
    for owner, method, count in ([] if args.method_id else wanted):
        rows = connection.execute("""SELECT m.* FROM methods m JOIN types t ON t.id=m.type_id
            JOIN images i ON i.id=m.image WHERE t.full_name=? AND m.name=? AND m.parameter_count=? AND m.status='mapped'""",
                                  (owner, method, count)).fetchall()
        if len(rows) != 1:
            raise ValueError(f"Ambiguous or missing selected method: {owner}::{method}/{count}")
        selected.append(dict(rows[0]))
    for method_id in dict.fromkeys(args.method_id or []):
        row = connection.execute("SELECT * FROM methods WHERE id=? AND status='mapped'", (method_id,)).fetchone()
        if row is None:
            raise ValueError(f"Method ID {method_id} has no mapped native body")
        selected.append(dict(row))
    seeds = {row["va"]: row for row in selected}
    helper_rows = connection.execute("""SELECT m.* FROM methods m JOIN types t ON t.id=m.type_id
        WHERE t.full_name IN (%s) AND m.status='mapped' AND
        (m.name IN ('.ctor','GetBytes','ToString','get_UTF8','get_Default','Create','CreateEncryptor','CreateDecryptor')
        OR m.name LIKE 'set_%%') ORDER BY m.token""" % ",".join("?" for _ in HELPERS), HELPERS).fetchall()
    for row in helper_rows:
        seeds.setdefault(row["va"], dict(row))
    output = HERE / "symbols"
    seed_path = output / f"crypto{suffix}.seeds.tsv"
    lines = ["# Names are metadata-derived caller assertions; shared addresses retain one displayed alias."]
    for row in sorted(seeds.values(), key=lambda r: int(r["va"], 16)):
        lines.append(f"{row['va']}\tfunction\t{label(row)}")
    seed_path.write_text("\n".join(lines) + "\n", encoding="utf-8")
    identity = json.loads((HERE / "evidence/artifact-identity.json").read_text(encoding="utf-8"))
    plan = {"schema_version": 1, "name": "resource-crypto" + suffix, "target": str(Path(r"E:\SecretFlasherManakaREA\GameAssembly.dll")),
            "native_sha256": identity["native_sha256"], "metadata_sha256": identity["metadata_sha256"],
            "seed_file": str(seed_path), "seed_sha256": hashlib.sha256(seed_path.read_bytes()).hexdigest(),
            "disabled_analyzers": DISABLED, "timeout_ms": 600000,
            "output_directory": str(HERE / f"evidence/crypto-batch{suffix}"),
            "seed_count": len(seeds), "functions": [{
                "metadata_id": row["id"], "qualified_name": row["qualified_name"], "token": hex(row["token"]),
                "va": row["va"], "file_offset": row["file_offset"], "label": label(row),
                "operations": ["procedure_pseudo_code"] + (["analyze_function"] if row["name"] in ("GetStream", "Cipher") else [])
            } for row in selected],
            "limitations": ["One displayed seed alias per address; full alias sets remain in methods.sqlite.",
                            "Disabled discovery passes limit cross-function and indirect-call coverage.",
                            "Names and addresses are static metadata-derived coordinates, not execution observations."]}
    plan_path = output / f"crypto{suffix}.plan.json"
    plan_path.write_text(json.dumps(plan, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"plan": str(plan_path), "functions": len(selected), "seeds": len(seeds)}, indent=2))


if __name__ == "__main__":
    main()
