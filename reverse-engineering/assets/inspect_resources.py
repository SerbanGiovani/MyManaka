"""Read only UnityFS v8 / SerializedFile v22 evidence from the supplied build.

No Unity code executes. Only directory info, resource metadata, and selected
object/block ranges are decompressed; the large bundle is never extracted.
"""
import argparse
import bisect
import hashlib
import json
from pathlib import Path
import struct


def lz4_block(data, expected):
    output = bytearray()
    position = 0

    def length(value):
        nonlocal position
        if value == 15:
            while True:
                part = data[position]
                position += 1
                value += part
                if part != 255:
                    break
        return value

    while position < len(data):
        token = data[position]
        position += 1
        count = length(token >> 4)
        if position + count > len(data):
            raise ValueError("LZ4 literal exceeds compressed block")
        output.extend(data[position:position + count])
        position += count
        if position == len(data):
            break
        distance = int.from_bytes(data[position:position + 2], "little")
        position += 2
        count = length(token & 15) + 4
        if not 0 < distance <= len(output) or len(output) + count > expected:
            raise ValueError("Invalid LZ4 match")
        for _ in range(count):
            output.append(output[-distance])
    if len(output) != expected:
        raise ValueError("Unexpected LZ4 output length")
    return bytes(output)


class Reader:
    def __init__(self, data, endian="<"):
        self.data, self.position, self.endian = data, 0, endian

    def take(self, count):
        start = self.position
        self.position += count
        if self.position > len(self.data):
            raise ValueError("Read exceeds metadata")
        return self.data[start:self.position]

    def number(self, fmt):
        return struct.unpack(self.endian + fmt, self.take(struct.calcsize(fmt)))[0]

    def string(self):
        end = self.data.index(0, self.position)
        return self.take(end - self.position + 1)[:-1].decode("utf-8")

    def align(self, size=4):
        self.take((-self.position) % size)

    def aligned_string(self):
        size = self.number("i")
        if size < 0:
            raise ValueError("Negative string size")
        value = self.take(size).decode("utf-8")
        self.align()
        return value


class Bundle:
    def __init__(self, path):
        self.path, self.file, self.cache = path, path.open("rb"), {}
        head = Reader(self.file.read(256), ">")
        if head.string() != "UnityFS" or head.number("I") != 8:
            raise ValueError("Only verified UnityFS v8 is supported")
        self.player_version, self.engine_version = head.string(), head.string()
        self.size = head.number("Q")
        compressed, uncompressed, flags = (head.number("I") for _ in range(3))
        if self.size != path.stat().st_size or flags != 0x243:
            raise ValueError("Unsupported bundle size / info flags")
        info_start = (head.position + 15) & ~15
        self.file.seek(info_start)
        info_bytes = lz4_block(self.file.read(compressed), uncompressed)
        info = Reader(info_bytes, ">")
        self.info_hash = info.take(16).hex()
        count = info.number("I")
        file_offset, stream_offset = info_start + compressed, 0
        if flags & 0x200:
            file_offset = (file_offset + 15) & ~15
        self.blocks = []
        for index in range(count):
            size, packed, block_flags = info.number("I"), info.number("I"), info.number("H")
            self.blocks.append({"index": index, "file_offset": file_offset,
                                "stream_offset": stream_offset, "size": size,
                                "compressed_size": packed, "flags": block_flags})
            file_offset += packed
            stream_offset += size
        self.nodes = []
        for _ in range(info.number("I")):
            self.nodes.append({"offset": info.number("q"), "size": info.number("q"),
                               "flags": info.number("I"), "name": info.string()})
        if info.position != len(info_bytes) or file_offset != self.size:
            raise ValueError("Bundle directory / block extent mismatch")
        self.starts = [block["stream_offset"] for block in self.blocks]

    def read(self, offset, size):
        result = bytearray()
        while size:
            index = bisect.bisect_right(self.starts, offset) - 1
            block = self.blocks[index]
            if index not in self.cache:
                self.file.seek(block["file_offset"])
                raw = self.file.read(block["compressed_size"])
                mode = block["flags"] & 63
                if mode in (2, 3):
                    raw = lz4_block(raw, block["size"])
                elif mode != 0 or len(raw) != block["size"]:
                    raise ValueError("Unsupported block compression")
                if len(self.cache) > 32:
                    self.cache.clear()
                self.cache[index] = raw
            relative = offset - block["stream_offset"]
            take = min(size, block["size"] - relative)
            if take <= 0:
                raise ValueError("Read exceeds bundle")
            result.extend(self.cache[index][relative:relative + take])
            offset += take
            size -= take
        return bytes(result)


def serialized_metadata(bundle, node):
    header = bundle.read(node["offset"], 48)
    if struct.unpack_from(">I", header, 8)[0] != 22 or header[16] != 0:
        raise ValueError("Only little-endian SerializedFile v22 supported")
    metadata_size, file_size, data_offset, unknown = struct.unpack_from(">Iqqq", header, 20)
    if file_size != node["size"]:
        raise ValueError("SerializedFile size differs from bundle node")
    metadata = bundle.read(node["offset"] + 48, metadata_size)
    reader = Reader(metadata)
    version, platform, has_tree = reader.string(), reader.number("i"), reader.number("?")
    types = []
    for index in range(reader.number("i")):
        entry = {"index": index, "class_id": reader.number("i"),
                 "stripped": reader.number("?"), "script_type_index": reader.number("h")}
        if entry["class_id"] == 114:
            entry["script_id"] = reader.take(16).hex()
        entry["old_type_hash"] = reader.take(16).hex()
        if has_tree:
            count, strings_size = reader.number("i"), reader.number("i")
            tree = []
            for _ in range(count):
                values = struct.unpack("<HBBIIiiiQ", reader.take(32))
                tree.append(dict(zip(("version", "level", "type_flags", "type_offset", "name_offset",
                                      "byte_size", "index", "meta_flags", "ref_type_hash"), values)))
            strings = reader.take(strings_size)
            def name_at(offset):
                if offset & 0x80000000:
                    return "$common:" + str(offset & 0x7fffffff)
                end = strings.index(0, offset)
                return strings[offset:end].decode("utf-8")
            for field in tree:
                field["type"], field["name"] = name_at(field["type_offset"]), name_at(field["name_offset"])
            entry["tree"] = tree
            dependencies = reader.number("i")
            entry["dependencies"] = [reader.number("i") for _ in range(dependencies)]
        types.append(entry)
    objects = []
    for _ in range(reader.number("i")):
        reader.align()
        path_id, start, size, type_index = reader.number("q"), reader.number("q"), reader.number("I"), reader.number("i")
        if start < 0 or start + size + data_offset > file_size or not 0 <= type_index < len(types):
            raise ValueError("Object table range/type validation failed")
        objects.append({"path_id": path_id, "offset": data_offset + start,
                        "size": size, "type_index": type_index, "class_id": types[type_index]["class_id"]})
    object_table_end = reader.position
    scripts = []
    for _ in range(reader.number("i")):
        local_file = reader.number("i")
        reader.align()
        scripts.append({"local_file_index": local_file, "local_identifier": reader.number("q")})
    externals = []
    for _ in range(reader.number("i")):
        externals.append({"empty_string": reader.string(), "guid": reader.take(16).hex(),
                          "type": reader.number("i"), "path": reader.string()})
    return {"format": 22, "endian": "little", "metadata_size": metadata_size,
            "data_offset": data_offset, "file_size": file_size, "engine_version": version,
            "platform": platform, "has_type_tree": has_tree,
            "object_table_end_metadata_offset": object_table_end,
            "script_references": scripts, "external_references": externals,
            "metadata_sha256": hashlib.sha256(metadata).hexdigest(), "types": types, "objects": objects}


def field_metadata(root):
    path = root / "SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat"
    data = path.read_bytes()
    header = struct.unpack_from("<64I", data)
    if header[:2] != (0xFAB11BAF, 31):
        raise ValueError("Only observed IL2CPP metadata v31 is supported")
    strings = data[header[6]:header[6] + header[7]]
    def string_at(index):
        return strings[index:strings.index(0, index)].decode("utf-8")
    types = list(struct.iter_unpack("<16i8H2I", data[header[40]:header[40] + header[41]]))
    fields = list(struct.iter_unpack("<iii", data[header[24]:header[24] + header[25]]))
    selected = []
    expected = {"EncrypterKeyData": ["keydataGUID", "fileName", "reference", "_keys", "_values", "allBundleList_Key", "allBundleList"],
                "EncrypterKeyReference": ["assetPath", "hash"],
                "PasswordMap": ["passCharacter", "map", "additionalMap"]}
    for index, record in enumerate(types):
        name = string_at(record[0])
        if name not in expected:
            continue
        result = {"type_id": index, "name": name, "namespace": string_at(record[1]),
                  "token": hex(record[-1]), "record_file_offset": header[40] + index * 88, "fields": []}
        for field_id in range(record[8], record[8] + record[18]):
            name_index, type_index, token = fields[field_id]
            result["fields"].append({"field_id": field_id, "record_file_offset": header[24] + field_id * 12,
                                     "name": string_at(name_index), "runtime_type_index": type_index,
                                     "token": hex(token & 0xffffffff)})
        if [field["name"] for field in result["fields"]] != expected[name]:
            raise ValueError("Observed metadata fields differ from proposed serialization schema")
        selected.append(result)
    if len(selected) != 3:
        raise ValueError("Expected exactly the three relevant metadata types")
    return {"source": str(path), "source_sha256": hashlib.sha256(data).hexdigest(),
            "metadata_version": 31, "type_record_layout": "<16i8H2I (88 bytes)",
            "field_record_layout": "<iii (12 bytes)", "types": selected,
            "limitation": "runtime_type_index identifies an IL2CPP type; it is not a native field offset."}


def keydata_fields(raw):
    reader = Reader(raw)
    reader.position = 48
    spans = []
    def value(name, kind):
        start = reader.position
        result = reader.aligned_string() if kind == "string" else reader.number(kind)
        spans.append({"field": name, "offset": start, "end": reader.position, "encoding": kind, "value": result})
        return result
    guid = value("keydataGUID", "string")
    file_name = value("fileName", "i")
    keys = [value(f"_keys[{i}]", "string") for i in range(value("_keys.Count", "i"))]
    references = [{"assetPath": value(f"_values[{i}].assetPath", "string"),
                   "hash": value(f"_values[{i}].hash", "q")} for i in range(value("_values.Count", "i"))]
    bundles = [value(f"allBundleList_Key[{i}]", "string") for i in range(value("allBundleList_Key.Count", "i"))]
    if reader.position != len(raw) or len(keys) != len(references):
        raise ValueError("KeyData proposed schema did not consume object exactly")
    return {"basis": "structural decoding + original IL2CPP field-order consistency; type declarations corroborated by managed interop",
            "keydataGUID": guid, "fileName": file_name, "_keys": keys, "_values": references,
            "allBundleList_Key": bundles, "spans": spans, "bytes_consumed": reader.position,
            "object_size": len(raw), "end_of_object_verified": True,
            "nonserialized_fields": ["reference", "allBundleList"],
            "limitation": "Dictionary fields have no serialized bytes in this supported interpretation; runtime dictionary construction was not executed."}


def monoscript_fields(raw):
    reader = Reader(raw)
    result = {"name": reader.aligned_string(), "execution_order": reader.number("i"),
              "properties_hash": reader.take(16).hex(), "class_name": reader.aligned_string(),
              "namespace": reader.aligned_string(), "assembly_name": reader.aligned_string()}
    if reader.position != len(raw):
        raise ValueError("MonoScript schema did not consume object exactly")
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--original-directory", type=Path, default=Path(r"E:\SecretFlasherManakaREA"))
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    bundle = Bundle(args.original_directory / "SecretFlasherManaka_Data/data.unity3d")
    node = next(node for node in bundle.nodes if node["name"] == "resources.assets")
    metadata = serialized_metadata(bundle, node)
    guid_offset = 252089348
    selected = [obj for obj in metadata["objects"] if obj["offset"] <= guid_offset < obj["offset"] + obj["size"]]
    if len(selected) != 1:
        raise ValueError("Expected exactly one object containing the observed GUID")
    with bundle.path.open("rb") as source_file:
        source_sha256 = hashlib.file_digest(source_file, "sha256").hexdigest()
    evidence = {"source": str(bundle.path), "source_size": bundle.size, "source_sha256": source_sha256,
                "bundle": {"format": 8, "engine_version": bundle.engine_version,
                           "block_count": len(bundle.blocks), "node_count": len(bundle.nodes), "nodes": bundle.nodes},
                "serialized_file": {k: v for k, v in metadata.items() if k not in ("types", "objects")},
                "object_count": len(metadata["objects"]), "type_count": len(metadata["types"]),
                "guid_object": selected[0], "guid_type": metadata["types"][selected[0]["type_index"]],
                "guid": "add7ae9ef7e0477e9d0aeb6d43949b7a", "guid_resources_assets_offset": guid_offset,
                "limitations": ["Read-only offline parsing; no target code executed.",
                    "GUID offset was obtained from a bounded search of original source bytes and a validated LZ4 block.",
                    "This parser deliberately supports only observed UnityFS v8 flags 0x243 and SerializedFile v22 little endian.",
                    "Type-tree common strings are preserved as numeric references; field semantics require further validation."]}
    obj = selected[0]
    raw = bundle.read(node["offset"] + obj["offset"], obj["size"])
    if raw[guid_offset - obj["offset"]:guid_offset - obj["offset"] + 32] != evidence["guid"].encode():
        raise ValueError("Observed GUID offset does not match source")
    evidence["guid_object"]["sha256"] = hashlib.sha256(raw).hexdigest()
    evidence["original_field_metadata"] = field_metadata(args.original_directory)
    evidence["guid_object"]["parsed_fields"] = keydata_fields(raw)
    evidence["guid_object"]["raw_hex"] = raw.hex(" ") if len(raw) <= 16384 else None
    external_id, script_id = struct.unpack_from("<iq", raw, 16)
    evidence["guid_object"]["script_pointer"] = {"file_id": external_id, "path_id": script_id}
    evidence["guid_block"] = bundle.blocks[bisect.bisect_right(bundle.starts, node["offset"] + guid_offset) - 1]
    values = Reader(raw)
    values.position = 28
    evidence["guid_object"]["name"] = values.aligned_string()
    sequence = []
    for kind in ("string", "i", "i", "string", "i", "string", "q", "i", "string"):
        position = values.position
        value = values.aligned_string() if kind == "string" else values.number(kind)
        sequence.append({"offset_in_object": position, "encoding": kind, "value": value})
    evidence["guid_object"]["unlabeled_value_sequence"] = sequence
    evidence["guid_object"]["unlabeled_value_sequence_end"] = values.position
    evidence["limitations"].extend([
        "resources.assets has enableTypeTree=false; no field names are present in its serialized type metadata.",
        "The unlabeled value sequence is retained for raw byte review; parsed_fields is corroborated by original metadata field order and managed type declarations.",
        "The selected KeyData object contains no supplied password string; a password mapping requires code or another resource."])
    if 1 <= external_id <= len(metadata["external_references"]):
        external = metadata["external_references"][external_id - 1]
        target_name = external["path"].split("/")[-1]
        target = next((item for item in bundle.nodes if item["name"] == target_name), None)
        if target:
            target_metadata = serialized_metadata(bundle, target)
            script_object = next(item for item in target_metadata["objects"] if item["path_id"] == script_id)
            script_data = bundle.read(target["offset"] + script_object["offset"], script_object["size"])
            evidence["script_object"] = {"node": target, "object": script_object,
                "raw_hex": script_data.hex(" "), "sha256": hashlib.sha256(script_data).hexdigest()}
            script_fields = monoscript_fields(script_data)
            if script_fields["properties_hash"] != evidence["guid_type"]["old_type_hash"]:
                raise ValueError("MonoScript extent / type hash mismatch")
            evidence["script_object"]["fields"] = script_fields
            script_matches = []
            script_count = 0
            for candidate in target_metadata["objects"]:
                if candidate["class_id"] != 115:
                    continue
                script_count += 1
                candidate_raw = bundle.read(target["offset"] + candidate["offset"], candidate["size"])
                fields = monoscript_fields(candidate_raw)
                if fields["assembly_name"] == "IKA9nt.Encrypter":
                    script_matches.append({"object": candidate, "fields": fields,
                                           "sha256": hashlib.sha256(candidate_raw).hexdigest()})
            password_scripts = [item for item in script_matches if item["fields"]["class_name"] == "PasswordMap"]
            password_ids = {item["object"]["path_id"] for item in password_scripts}
            matching_references = [dict(index=i, **item) for i, item in enumerate(metadata["script_references"])
                                   if item["local_file_index"] == external_id and item["local_identifier"] in password_ids]
            matching_indices = {item["index"] for item in matching_references}
            matching_types = [item for item in metadata["types"] if item.get("script_type_index") in matching_indices]
            unresolved = []
            for candidate in metadata["objects"]:
                typ = metadata["types"][candidate["type_index"]]
                if candidate["class_id"] == 114 and typ.get("script_type_index") == -1:
                    prefix = bundle.read(node["offset"] + candidate["offset"], min(candidate["size"], 28))
                    unresolved.append({"object": candidate, "script_pointer": list(struct.unpack_from("<iq", prefix, 16))})
            evidence["passwordmap_resource_search"] = {
                "scope": [target["name"] + " class115 objects", node["name"] + " script references / typed objects"],
                "monoscript_count": script_count, "encrypter_scripts": script_matches,
                "passwordmap_scripts": password_scripts,
                "resources_script_reference_count": len(metadata["script_references"]),
                "matching_script_references": matching_references, "matching_types": matching_types,
                "unresolved_script_type_objects": unresolved,
                "conclusion": "PasswordMap MonoScript identity exists; no associated resources.assets instance type/reference was found in this bounded search.",
                "unknown": "Static passCharacter/map/additionalMap initialization and password lookup require native code evidence."}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(evidence, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"output": str(args.output), "object_count": evidence["object_count"],
                      "type_count": evidence["type_count"], "guid_object": evidence["guid_object"],
                      "guid_type": evidence["guid_type"]}, ensure_ascii=False))


if __name__ == "__main__":
    main()
