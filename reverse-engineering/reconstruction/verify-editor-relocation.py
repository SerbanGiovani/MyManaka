"""Verify the explicit relocation of the byte-identical Unity Editor executable.

This does not infer activation, a working installation, or build success from an
executable fingerprint. Unknown missing paths are never redirected or skipped.
"""
import argparse
import hashlib
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
MANIFEST = HERE / 'editor-relocation.json'
STATUS = 'unity-editor-executable-relocation-verified'


def read(path):
    return json.loads(Path(path).read_text('utf-8-sig'))


def sha(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def require(condition, message):
    if not condition:
        raise ValueError(message)


def declarations():
    record = read(MANIFEST)
    require(record['schema_version'] == 1 and record['status'] == STATUS, 'Editor relocation record is incomplete')
    require(record['editor_version'] == '6000.6.7f1' and record['bytes'] == 279976, 'Unexpected editor relocation identity')
    require(record['sha256'] == '13c0162a848689b760be7cb4aaa9391d085d56e3f6e20a12f8736f63b3bd0540', 'Editor relocation hash differs from the observed binary')
    require(Path(record['original_path']) == Path('C:/Program Files/Unity/Hub/Editor/6000.6.7f1/Editor/Unity.exe'), 'Only the explicitly observed old editor path can relocate')
    require(Path(record['actual_path']) == Path('H:/Unity Editor/6000.6.7f1/Editor/Unity.exe'), 'Only the user-selected new editor path can substitute')
    require(record['original_absent_when_recorded'] is True and record['new_editor_build_inferred'] is False, 'Relocation was promoted to an Editor build')
    verifier = HERE / record['verifier']['path']
    require(verifier.stat().st_size == record['verifier']['bytes'] and sha(verifier) == record['verifier']['sha256'], 'Editor relocation verifier differs')
    require(len(record['historical_references']) == 2, 'Editor relocation must bind both recorded historical identities')
    for reference in record['historical_references']:
        path = HERE / reference['path']
        require(path.name in {'unity-editor-runtime.json', 'formal-project-runtime.json'}, 'Unexpected historical editor authority')
        require(path.stat().st_size == reference['bytes'] and sha(path) == reference['sha256'], 'Historical editor authority changed')
        editor = read(path)['editor']
        require(Path(editor['path']) == Path(record['original_path']) and editor['bytes'] == record['bytes'] and editor['sha256'] == record['sha256'], 'Historical editor identities do not match the relocation')
    return record


def resolve_input(path, expected_sha):
    """Return an existing original path or the one exact, rehashed relocation.

    The caller still hashes the returned path against its requested identity.
    An ordinary missing path raises; no directory or substring substitution is
    performed. When the old executable exists it remains the input to verify.
    """
    original = Path(path)
    if original.is_file():
        return original
    record = declarations()
    if original != Path(record['original_path']) or expected_sha != record['sha256']:
        raise FileNotFoundError('Missing input has no declared exact relocation: ' + str(original))
    require(not original.exists(), 'The declared old editor path is not absent')
    actual = Path(record['actual_path'])
    require(actual.is_file() and actual.stat().st_size == record['bytes'] and sha(actual) == expected_sha, 'Relocated editor bytes do not match the historical expected input')
    return actual


def build(inputs=False):
    record = declarations()
    if inputs:
        require(not Path(record['original_path']).exists(), 'The recorded old editor is no longer absent; verify that original path directly rather than claiming relocation')
        require(resolve_input(record['original_path'], record['sha256']) == Path(record['actual_path']), 'Editor relocation did not resolve to the declared actual path')
    return dict(status=STATUS, original_path=record['original_path'], actual_path=record['actual_path'], bytes=record['bytes'], sha256=record['sha256'], live_relocated_binary_verified=inputs, new_editor_build_inferred=False,
                scope='Only the explicitly declared old executable path is substituted, after exact size/SHA verification. Installation/license/build evidence remains separate.')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--inputs', action='store_true')
    args = parser.parse_args()
    print(json.dumps(build(args.inputs), ensure_ascii=False, indent=2))
