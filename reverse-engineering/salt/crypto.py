"""Recover this build's resource password and inspect/decrypt its asset bundle.

Reads original artifacts and REA static evidence. Never executes game code.
Requires the already installed cryptography package only for AES.
"""
import argparse
from array import array
import hashlib
import json
from pathlib import Path
import re
import sqlite3
import struct
import sys

from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from metadata import Metadata, PE, HERE, DEFAULT_ROOT
sys.path.insert(0, str(HERE.parent / "assets"))
from inspect_resources import Bundle, serialized_metadata, keydata_fields


def load(path):
    return json.loads(path.read_text(encoding="utf-8"))


def file_hash(path):
    digest = hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(4 * 1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def recover(root):
    identity = load(HERE / "evidence/artifact-identity.json")
    data = (root / "GameAssembly.dll").read_bytes()
    raw = (root / "SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat").read_bytes()
    if hashlib.sha256(data).hexdigest() != identity["native_sha256"] or hashlib.sha256(raw).hexdigest() != identity["metadata_sha256"]:
        raise ValueError("Original inputs differ from the recorded build")
    metadata, pe = Metadata(raw), PE(data)
    literals = metadata.records(2, "<II")
    strings = metadata.region(4)

    def literal(address):
        encoded = struct.unpack_from("<Q", data, pe.offset(address, 8))[0]
        if encoded >> 32 or encoded >> 29 != 5 or not encoded & 1:
            raise ValueError("Expected a static IL2CPP string-literal usage")
        index = (encoded & 0x1FFFFFFF) >> 1
        length, offset = literals[index]
        value = strings[offset:offset + length]
        if len(value) != length:
            raise ValueError("Literal extends past its recorded heap")
        return {"usage_va": hex(address), "encoded_usage": hex(encoded), "literal_id": index,
                "metadata_file_offset": metadata.header[4] + offset,
                "byte_length": length, "value": value.decode("utf-8")}

    constructor = load(HERE / "evidence/crypto-batch/0x6000001-procedure_pseudo_code.json")
    initializer = load(HERE / "evidence/crypto-batch-helpers/0x6000003-procedure_pseudo_code.json")
    for evidence in (constructor, initializer):
        if evidence["subject"]["digest"]["sha256"] != identity["native_sha256"]:
            raise ValueError("REA function evidence belongs to a different input")
    indices = [int(value, 0) for value in re.findall(
        r"PasswordMap__Substring__06000002\(param_1,(0x[0-9a-f]+|[0-9]+),0\)",
        constructor["normalized_result"])]
    if len(indices) != 26:
        raise ValueError("Password constructor is not the verified 26-character layout")
    pool_candidates = []
    for address in set(int(value, 16) for value in re.findall(r"uRam0*([0-9a-f]{9,16})", initializer["normalized_result"])):
        try:
            candidate = literal(address)
            if len(candidate["value"]) >= 100:
                pool_candidates.append(candidate)
        except (ValueError, IndexError, UnicodeDecodeError):
            pass
    if len(pool_candidates) != 1:
        raise ValueError("Static initializer does not bind one unambiguous character pool")
    pool_evidence, mapping_key = pool_candidates[0], literal(0x182D5BF78)
    pool = pool_evidence["value"]
    if any(ord(character) > 0xFFFF or 0xD800 <= ord(character) <= 0xDFFF for character in pool):
        raise ValueError("This decoder supports the recorded BMP-only UTF-16 character pool")
    assets = load(HERE.parent / "assets/resources-keydata.json")
    if file_hash(root / "SecretFlasherManaka_Data/data.unity3d") != assets["source_sha256"]:
        raise ValueError("Unity source differs from the recorded KeyData object evidence")
    resource_bundle = Bundle(root / "SecretFlasherManaka_Data/data.unity3d")
    try:
        resource_node = next(node for node in resource_bundle.nodes if node["name"] == "resources.assets")
        object_bytes = resource_bundle.read(resource_node["offset"] + assets["guid_object"]["offset"], assets["guid_object"]["size"])
        if hashlib.sha256(object_bytes).hexdigest() != assets["guid_object"]["sha256"]:
            raise ValueError("Original KeyData object differs from its evidence record")
        fields = keydata_fields(object_bytes)
        if fields != assets["guid_object"]["parsed_fields"]:
            raise ValueError("Reparsed KeyData fields differ from the recorded structure")
    finally:
        resource_bundle.file.close()
    label = mapping_key["value"]
    position = fields["_keys"].index(label)
    reference = fields["_values"][position]
    guid = fields["keydataGUID"]
    if not re.fullmatch(r"[0-9a-f]{32}", guid) or len(indices) > len(guid):
        raise ValueError("Invalid GUID/password mapping span")
    encoded, decoded = [], []
    for position, index in enumerate(indices):
        if index >= len(pool):
            index -= len(pool)
        if not 0 <= index < len(pool):
            raise ValueError("Constructor character index is outside the supported single-wrap range")
        encoded.append(pool[index])
        index -= int(guid[position], 16)
        if index < 0:
            index += len(pool)
        decoded.append(pool[index])
    password = "".join(decoded)
    # The native constructor trims whitespace. The pinned recovered password has none.
    if password.strip() != password:
        raise ValueError("Unexpected edge whitespace; establish exact native trim semantics first")
    salt = str(reference["hash"])
    while len(salt) < 8:
        salt += "0"
    key = hashlib.pbkdf2_hmac("sha1", password.encode("utf-8"), salt.encode("utf-8"), 1000, 32)
    baseline = load(HERE / "baseline.json")
    result = {"schema_version": 1, "source_kind": "static-native-and-serialized-resource-reconstruction",
        "native_sha256": identity["native_sha256"], "metadata_sha256": identity["metadata_sha256"],
        "unity_source_sha256": assets["source_sha256"], "keydata_object_sha256": assets["guid_object"]["sha256"],
        "label": label, "asset_path": reference["assetPath"], "keydata_guid": guid,
        "password_map_initializer_evidence": initializer["evidence_id"],
        "password_map_constructor_evidence": constructor["evidence_id"],
        "password_decoder_evidence": load(HERE / "evidence/crypto-batch/0x60000a8-procedure_pseudo_code.json")["evidence_id"],
        "character_pool": pool_evidence, "constructor_indices": indices,
        "encoded_map_value": "".join(encoded), "password": password, "password_encoding": "utf-8",
        "salt_text": salt, "salt_hex": salt.encode().hex(" "),
        "kdf": {"algorithm": "PBKDF2-HMAC-SHA1", "iterations": 1000, "key_bytes": 32},
        "derived_key_hex": key.hex(), "aes_block_bytes": 16,
        "aes_primitive": "AES-256-ECB encryption, no padding", "primitive_iv_hex": bytes(16).hex(),
        "stream_transform": "XOR with AES-ECB(LE64(floor(file_offset/16)+1) || 8 zero bytes)",
        "counter_start": 1, "counter_byte_order": "little", "counter_width_bits": 64,
        "matches_user_baseline": {"password": password == baseline["password"],
            "salt": salt == baseline["salt"]["text"], "guid": guid == baseline["keydata_guid"]},
        "limitations": ["Specific to the pinned original build and models label.",
            "Primitive zero IV is assigned by the constructor; ECB does not use it as a changing counter IV.",
            "This custom little-endian counter stream is not the default big-endian AES-CTR API convention.",
            "Successful structured decoding is offline evidence; the game was not executed.",
            "The stream has no authentication tag; format checks do not establish cryptographic authenticity."]}
    return result


class DecryptReader:
    def __init__(self, path, key):
        self.source, self.key, self.position = path.open("rb"), key, 0
        self.size = path.stat().st_size

    def seek(self, offset, whence=0):
        target = offset if whence == 0 else self.position + offset if whence == 1 else self.size + offset
        if target < 0 or whence not in (0, 1, 2):
            raise ValueError("Invalid stream seek")
        self.position = target
        return target

    def read(self, size=-1):
        size = max(0, self.size - self.position) if size < 0 else min(size, max(0, self.size - self.position))
        if not size:
            return b""
        self.source.seek(self.position)
        ciphertext = self.source.read(size)
        first, skip = self.position // 16 + 1, self.position % 16
        count = (skip + len(ciphertext) + 15) // 16
        counters = array("Q", [0]) * (count * 2)
        counters[0::2] = array("Q", range(first, first + count))
        if sys.byteorder != "little":
            counters.byteswap()
        encryptor = Cipher(algorithms.AES(self.key), modes.ECB()).encryptor()
        keystream = encryptor.update(counters.tobytes()) + encryptor.finalize()
        keystream = keystream[skip:skip + len(ciphertext)]
        plaintext = (int.from_bytes(ciphertext, "little") ^ int.from_bytes(keystream, "little")).to_bytes(len(ciphertext), "little")
        self.position += len(ciphertext)
        return plaintext

    def close(self):
        self.source.close()


class DecryptedPath:
    def __init__(self, path, key):
        self.path, self.key = path, key

    def open(self, mode):
        if mode != "rb":
            raise ValueError("Only read-only access is supported")
        return DecryptReader(self.path, self.key)

    def stat(self):
        return self.path.stat()


def inspect(path, profile):
    bundle = Bundle(DecryptedPath(path, bytes.fromhex(profile["derived_key_hex"])))
    try:
        # Verify unaligned seeks agree with one contiguous decrypted read.
        bundle.file.seek(0)
        prefix = bundle.file.read(257)
        for offset, size in [(1, 31), (7, 63), (15, 65), (16, 65), (17, 127)]:
            bundle.file.seek(offset)
            if bundle.file.read(size) != prefix[offset:offset + size]:
                raise ValueError("Unaligned decryption differs from the contiguous prefix")
        samples = []
        for i in sorted({0, len(bundle.blocks) // 2, len(bundle.blocks) - 1}):
            block = bundle.blocks[i]
            value = bundle.read(block["stream_offset"], block["size"])
            samples.append({"index": i, "stream_offset": block["stream_offset"], "size": len(value),
                            "sha256": hashlib.sha256(value).hexdigest()})
        nodes = []
        for node in bundle.nodes:
            item = dict(node)
            header = bundle.read(node["offset"], min(48, node["size"]))
            if len(header) >= 48 and struct.unpack_from(">I", header, 8)[0] == 22:
                value = serialized_metadata(bundle, node)
                counts = {}
                for obj in value["objects"]:
                    key = str(obj["class_id"])
                    counts[key] = counts.get(key, 0) + 1
                item["serialized_file"] = {"version": value["format"], "engine_version": value["engine_version"],
                    "type_count": len(value["types"]), "object_count": len(value["objects"]),
                    "class_id_counts": counts, "has_type_tree": value["has_type_tree"]}
            nodes.append(item)
        return {"source": str(path), "source_size": path.stat().st_size, "source_sha256": file_hash(path),
            "status": "decrypted-header-directory-and-sampled-blocks-validated",
            "format": "UnityFS", "format_version": 8, "engine_version": bundle.engine_version,
            "declared_size_matches_source": True, "block_count": len(bundle.blocks), "nodes": nodes,
            "unaligned_seek_checks": 5, "sampled_blocks": samples,
            "validation_scope": "Complete directory, first/middle/last decompressed blocks, serialized metadata tables; not every object payload."}
    finally:
        bundle.file.close()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("action", choices=("recover", "inspect", "decrypt", "verify"))
    parser.add_argument("--root", type=Path, default=DEFAULT_ROOT)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    if args.action == "verify":
        prior = load(HERE / "evidence/decryption.json")
        path = Path(prior["plaintext"]["path"])
        digest = file_hash(path)
        if digest != prior["plaintext"]["sha256"]:
            raise ValueError("Materialized plaintext fingerprint differs")
        bundle = Bundle(path)
        full_hash, total = hashlib.sha256(), 0
        try:
            for block in bundle.blocks:
                value = bundle.read(block["stream_offset"], block["size"])
                full_hash.update(value)
                total += len(value)
            for node in bundle.nodes:
                if node["offset"] < 0 or node["size"] < 0 or node["offset"] + node["size"] > total:
                    raise ValueError("Node exceeds the verified uncompressed stream")
            report = {"source_ciphertext_sha256": prior["source_sha256"], "plaintext": str(path),
                      "plaintext_sha256": digest, "verified_blocks": len(bundle.blocks),
                      "uncompressed_bytes": total, "uncompressed_sha256": full_hash.hexdigest(),
                      "verified_node_ranges": len(bundle.nodes), "status": "all-bundle-blocks-decoded-and-ranges-validated",
                      "scope": "Every compressed block and node byte range, not every Unity object semantic or runtime behavior."}
        finally:
            bundle.file.close()
        (HERE / "evidence/decryption-verification.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
        print(json.dumps(report, indent=2))
        return
    profile = recover(args.root.resolve())
    (HERE / "evidence/recovered-crypto.json").write_text(json.dumps(profile, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    path = args.root / "SecretFlasherManaka_Data/StreamingAssets/StandaloneWindows64" / str(
        load(HERE.parent / "assets/resources-keydata.json")["guid_object"]["parsed_fields"]["_values"][0]["hash"])
    if args.action == "recover":
        print(json.dumps({"label": profile["label"], "baseline_matches": profile["matches_user_baseline"]}))
        return
    report = inspect(path, profile)
    if args.action == "decrypt":
        output = (args.output or HERE / ".cache/decrypted/models.unity3d").resolve()
        if output == path.resolve() or output.exists():
            raise ValueError("Decryption destination must be new and distinct from the original")
        output.parent.mkdir(parents=True, exist_ok=True)
        reader = DecryptReader(path, bytes.fromhex(profile["derived_key_hex"]))
        digest = hashlib.sha256()
        try:
            with output.open("xb") as f:
                while chunk := reader.read(4 * 1024 * 1024):
                    digest.update(chunk)
                    f.write(chunk)
        finally:
            reader.close()
        # Parse the complete plaintext directory again through a normal file handle.
        plain = Bundle(output)
        try:
            expected_nodes = [{key: node[key] for key in ("offset", "size", "flags", "name")} for node in report["nodes"]]
            if plain.nodes != expected_nodes:
                raise ValueError("Plaintext materialization changed the bundle directory")
        finally:
            plain.file.close()
        report["plaintext"] = {"path": str(output), "bytes": output.stat().st_size, "sha256": digest.hexdigest()}
    destination = HERE / "evidence/decryption.json"
    destination.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"status": report["status"], "blocks": report["block_count"], "nodes": len(report["nodes"]),
                      "plaintext": report.get("plaintext")}, indent=2))


if __name__ == "__main__":
    main()
