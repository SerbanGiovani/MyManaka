"""Extract the repository wrapper and locate original IL2CPP GetSalt code.

Standard-library-only, read-only analysis of input files. No game code executes.
The metadata layout below is explicitly restricted to this game's version 31.
"""

import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def extract(repository, original, output):
    tracked = "BepInEx/interop/IKA9nt.Encrypter.dll"
    commit = subprocess.check_output(
        ["git", "-C", str(repository), "rev-parse", "HEAD"], text=True
    ).strip()
    wrapper = subprocess.check_output(
        ["git", "-C", str(repository), "show", f"{commit}:{tracked}"]
    )
    if wrapper != (original / tracked).read_bytes():
        raise ValueError("Repository wrapper differs from the original-directory wrapper")

    metadata_path = original / "SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat"
    metadata = metadata_path.read_bytes()
    header = struct.unpack_from("<64I", metadata)
    if header[:2] != (0xFAB11BAF, 31):
        raise ValueError("Only the verified IL2CPP metadata version 31 is supported")
    strings_start, strings_size = header[6:8]
    methods_start, methods_size = header[12:14]
    if methods_size % 36 or methods_start + methods_size > len(metadata):
        raise ValueError("Invalid version-31 method-definition table")
    strings = metadata[strings_start:strings_start + strings_size]

    def string_at(index):
        end = strings.index(b"\0", index)
        return strings[index:end].decode("utf-8")

    matches = []
    for offset in range(methods_start, methods_start + methods_size, 36):
        name, declaring_type, return_type, return_parameter, parameter_start, generic, token = struct.unpack_from(
            "<7I", metadata, offset
        )
        if string_at(name) == "GetSalt":
            matches.append({"file_offset": offset, "declaring_type_index": declaring_type,
                            "token": token, "parameter_start": parameter_start})
    if len(matches) != 1:
        raise ValueError(f"Expected one GetSalt method, found {len(matches)}")
    method = matches[0]
    if method["token"] >> 24 != 6:
        raise ValueError("GetSalt is not a MethodDef token")

    native_path = original / "GameAssembly.dll"
    native = native_path.read_bytes()
    pe = struct.unpack_from("<I", native, 0x3C)[0]
    if native[pe:pe + 4] != b"PE\0\0":
        raise ValueError("Invalid PE signature")
    optional = pe + 24
    if struct.unpack_from("<H", native, optional)[0] != 0x20B:
        raise ValueError("Expected a PE32+ native DLL")
    image_base = struct.unpack_from("<Q", native, optional + 24)[0]
    section_start = optional + struct.unpack_from("<H", native, pe + 20)[0]
    sections = []
    for index in range(struct.unpack_from("<H", native, pe + 6)[0]):
        offset = section_start + index * 40
        virtual_size, rva, raw_size, raw_offset = struct.unpack_from("<4I", native, offset + 8)
        sections.append((rva, raw_size, raw_offset))

    def va_to_offset(va):
        for rva, size, raw in sections:
            if image_base + rva <= va < image_base + rva + size:
                return raw + va - image_base - rva
        raise ValueError(f"VA {va:#x} has no file-backed section")

    def offset_to_va(offset):
        for rva, size, raw in sections:
            if raw <= offset < raw + size:
                return image_base + rva + offset - raw
        raise ValueError(f"Offset {offset:#x} has no file-backed section")

    name = b"IKA9nt.Encrypter.dll\0"
    name_offset = native.find(name)
    if name_offset < 0 or native.find(name, name_offset + 1) >= 0:
        raise ValueError("Expected one native module-name string")
    name_pointer = struct.pack("<Q", offset_to_va(name_offset))
    modules = []
    position = 0
    method_index = (method["token"] & 0xFFFFFF) - 1
    while True:
        position = native.find(name_pointer, position)
        if position < 0:
            break
        if position % 8 == 0 and position + 24 <= len(native):
            count = struct.unpack_from("<I", native, position + 8)[0]
            table_va = struct.unpack_from("<Q", native, position + 16)[0]
            if method_index < count < 100000:
                try:
                    table_offset = va_to_offset(table_va)
                    va = struct.unpack_from("<Q", native, table_offset + method_index * 8)[0]
                    code_offset = va_to_offset(va)
                    modules.append((position, count, table_va, va, code_offset, table_offset))
                except (ValueError, struct.error):
                    pass
        position += 1
    if len(modules) != 1:
        raise ValueError(f"Expected one valid codegen module, found {len(modules)}")
    module_offset, count, table_va, va, code_offset, table_offset = modules[0]
    pointers = struct.unpack_from(f"<{count}Q", native, table_offset)
    # This is a bounded byte window, not a claim about the exact function extent.
    next_va = min(pointer for pointer in pointers if pointer > va)
    window_size = min(next_va - va, 4096)
    code = native[code_offset:code_offset + window_size]

    output.mkdir(parents=True, exist_ok=True)
    (output / "IKA9nt.Encrypter.from-git.dll").write_bytes(wrapper)
    (output / "GetSalt.native-window.bin").write_bytes(code)
    manifest = {
        "repository": str(repository), "commit": commit, "tracked_wrapper": tracked,
        "wrapper_sha256": sha256(wrapper), "original_directory": str(original),
        "native_sha256": sha256(native), "metadata_sha256": sha256(metadata),
        "metadata_version": 31, "method": {**method, "token": hex(method["token"]),
            "name": "IKA9nt.Encrypter.EncrypterCore.GetSalt", "module_method_index": method_index},
        "native": {"image_base": hex(image_base), "module_file_offset": hex(module_offset),
            "module_method_count": count, "method_pointer_table_va": hex(table_va),
            "method_va": hex(va), "method_file_offset": hex(code_offset),
            "byte_window_length": len(code), "byte_window_sha256": sha256(code)},
        "limitations": [
            "The tracked wrapper delegates to native IL2CPP code; it does not contain the original GetSalt implementation.",
            "A method address and byte window alone do not establish a salt value or derivation algorithm.",
            "Codegen-module layout and metadata parsing are restricted to this supplied game build.",
            "No target code was loaded or executed."
        ]
    }
    (output / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(manifest, indent=2))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repository", type=Path, required=True)
    parser.add_argument("--original-directory", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    extract(args.repository.resolve(), args.original_directory.resolve(), args.output.resolve())
