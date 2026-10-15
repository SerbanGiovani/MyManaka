"""Audit saved reconstruction evidence and optionally hash the original inputs."""
import argparse
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent


def read(path):
    return json.loads(path.read_text(encoding="utf-8-sig"))


def digest(path):
    value = hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(4 * 1024 * 1024), b""):
            value.update(chunk)
    return value.hexdigest()


def check(condition, message):
    if not condition:
        raise ValueError(message)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--inputs", action="store_true", help="Also verify original files and the materialized plaintext")
    parser.add_argument("--write-index", action="store_true", help="Write the current verified artifact fingerprint index")
    args = parser.parse_args()
    identity = read(ROOT / "salt/evidence/artifact-identity.json")
    asset = read(ROOT / "assets/resources-keydata.json")
    recovered = read(ROOT / "salt/evidence/recovered-crypto.json")
    decryption = read(ROOT / "salt/evidence/decryption.json")
    verification = read(ROOT / "salt/evidence/decryption-verification.json")
    summary = read(ROOT / "salt/symbols/index-summary.json")
    object_record = asset["guid_object"]
    check(hashlib.sha256(bytes.fromhex(object_record["raw_hex"])).hexdigest() == object_record["sha256"], "KeyData raw-byte fingerprint mismatch")
    fields = object_record["parsed_fields"]
    check(fields["bytes_consumed"] == object_record["size"] == fields["object_size"], "KeyData schema did not consume the complete object")
    check(fields["keydataGUID"] == recovered["keydata_guid"], "Recovered GUID differs from original resource fields")
    check(str(fields["_values"][0]["hash"]) == recovered["salt_text"], "Recovered salt differs from original resource hash")
    check(all(recovered["matches_user_baseline"].values()), "Independent reconstruction differs from supplied baseline")
    check(summary["native_sha256"] == recovered["native_sha256"] == identity["native_sha256"], "Native identity disagreement")
    check(summary["metadata_sha256"] == recovered["metadata_sha256"] == identity["metadata_sha256"], "Metadata identity disagreement")
    check(sum(summary["mapping_status"].values()) == summary["methods"], "Metadata coverage counts disagree")
    check(verification["source_ciphertext_sha256"] == decryption["source_sha256"], "Ciphertext verification identity mismatch")
    check(verification["plaintext_sha256"] == decryption["plaintext"]["sha256"], "Plaintext verification identity mismatch")
    check(verification["verified_blocks"] == decryption["block_count"], "Not every bundle block was verified")
    check(verification["verified_node_ranges"] == len(decryption["nodes"]), "Not every node range was verified")

    artifacts, observations = [], {}
    allowed_subjects = {identity["native_sha256"], identity["wrapper_sha256"]}
    for path in sorted(ROOT.rglob("*")):
        if not path.is_file() or any(part in (".cache", "__pycache__") for part in path.relative_to(ROOT).parts):
            continue
        if path.name == "evidence-index.json" or path.name.endswith((".stderr.log", ".pending.json")):
            continue
        artifacts.append({"path": path.relative_to(ROOT).as_posix(), "bytes": path.stat().st_size, "sha256": digest(path)})
        if path.suffix != ".json":
            continue
        value = read(path)
        records = value.get("records", []) if isinstance(value, dict) else []
        if isinstance(value, dict) and value.get("evidence_id"):
            records = [value]
        for record in records:
            if not isinstance(record, dict) or not record.get("evidence_id"):
                continue
            key = record["evidence_id"]
            subject = record.get("subject") or {}
            subject_hash = (subject.get("digest") or {}).get("sha256")
            check(subject_hash in allowed_subjects, f"Unexpected evidence subject in {path}")
            canonical = json.dumps(record, sort_keys=True, ensure_ascii=False)
            if key in observations:
                check(observations[key]["canonical"] == canonical, f"Conflicting copies of {key}")
            else:
                observations[key] = {"canonical": canonical, "operation": record["operation"], "subject_sha256": subject_hash}
    for key in ("password_map_initializer_evidence", "password_map_constructor_evidence", "password_decoder_evidence"):
        check(recovered[key] in observations, f"Missing password reconstruction evidence: {key}")
    runs = [read(ROOT / "salt/evidence" / directory / "run.json") for directory in ("crypto-batch", "crypto-batch-helpers")]
    for run in runs:
        check(run["success"] and not run.get("close_error"), "A required REA batch did not complete cleanly")
        check(all(item["evidence_id"] in observations for item in run["functions"]), "Batch references missing evidence")
    checked_inputs = []
    if args.inputs:
        original = Path(identity["original_directory"])
        paths = [(original / "GameAssembly.dll", identity["native_sha256"]),
                 (original / "SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat", identity["metadata_sha256"]),
                 (original / "BepInEx/interop/IKA9nt.Encrypter.dll", identity["wrapper_sha256"]),
                 (original / "SecretFlasherManaka_Data/data.unity3d", asset["source_sha256"]),
                 (Path(decryption["source"]), decryption["source_sha256"]),
                 (Path(decryption["plaintext"]["path"]), decryption["plaintext"]["sha256"])]
        for path, expected in paths:
            actual = digest(path)
            check(actual == expected, f"Input fingerprint differs: {path}")
            checked_inputs.append({"path": str(path), "sha256": actual})
    result = {"schema_version": 1, "generated_at_utc": datetime.now(timezone.utc).isoformat(),
              "status": "consistent", "canonical_rea_observations": len(observations),
              "rea_queries_completed": sum(len(run["functions"]) for run in runs),
              "artifacts": artifacts, "inputs_checked": checked_inputs,
              "observations": [{"evidence_id": key, "operation": item["operation"], "subject_sha256": item["subject_sha256"]}
                               for key, item in sorted(observations.items())],
              "scope": "File integrity and declared evidence consistency, not global source equivalence or runtime verification"}
    if args.write_index:
        (ROOT / "evidence-index.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    else:
        index = read(ROOT / "evidence-index.json")
        expected = {entry["path"]: entry["sha256"] for entry in index["artifacts"]}
        actual = {entry["path"]: entry["sha256"] for entry in artifacts}
        check(actual == expected, "Artifact files differ from evidence-index.json; inspect changes before regenerating")
    print(json.dumps({"status": "consistent", "artifacts": len(artifacts), "canonical_rea_observations": len(observations),
                      "rea_queries_completed": result["rea_queries_completed"], "inputs_checked": len(checked_inputs)}, indent=2))


if __name__ == "__main__":
    main()
