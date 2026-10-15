"""Validate the recorded salt bytes and reproduce the supplied PBKDF2 baseline."""

import argparse
import hashlib
import json
from pathlib import Path
import re


def derive(path):
    baseline = json.loads(path.read_text(encoding="utf-8"))
    salt = baseline["salt"]["text"].encode(baseline["salt"]["encoding"])
    expected_salt = bytes.fromhex(baseline["salt"]["hex"])
    if salt != expected_salt:
        raise ValueError("Salt text and recorded hex do not match")
    if not re.fullmatch(r"[0-9a-f]{32}", baseline["keydata_guid"]):
        raise ValueError("Invalid recorded KeyData GUID")
    if baseline["password_normalization"] != "none":
        raise ValueError("This baseline must preserve the exact password code points")
    password = baseline["password"].encode(baseline["password_encoding"])
    kdf = baseline["key_derivation"]
    if kdf["algorithm"] != "PBKDF2-HMAC-SHA1":
        raise ValueError("Unsupported baseline KDF")
    if kdf["key_length_bytes"] * 8 != baseline["cipher"]["key_bits"]:
        raise ValueError("KDF key length and cipher key size disagree")
    key = hashlib.pbkdf2_hmac(
        "sha1", password, salt, kdf["iterations"], dklen=kdf["key_length_bytes"]
    )
    return {
        "baseline_file": str(path.resolve()),
        "baseline_sha256": hashlib.sha256(path.read_bytes()).hexdigest(),
        "salt_text": baseline["salt"]["text"],
        "salt_hex": salt.hex(" ").upper(),
        "salt_length_bytes": len(salt),
        "keydata_guid": baseline["keydata_guid"],
        "password_code_points": len(baseline["password"]),
        "password_utf8_length_bytes": len(password),
        "password_utf8_sha256": hashlib.sha256(password).hexdigest(),
        "key_derivation": kdf,
        "derived_key_hex": key.hex(),
        "status": "recorded-salt-and-local-kdf-consistent",
        "asset_decryption_verified": False,
        "cipher_mode_iv_padding": "unknown"
    }


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--baseline", type=Path, default=Path(__file__).with_name("baseline.json"))
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    result = json.dumps(derive(args.baseline), ensure_ascii=False, indent=2) + "\n"
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(result, encoding="utf-8")
    print(result, end="")
