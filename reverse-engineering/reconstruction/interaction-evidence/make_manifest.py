"""Verify original input identities and hash this finite static evidence output."""
import argparse
import hashlib
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
RE = HERE.parents[1]


def fingerprint(path):
    with path.open('rb') as stream:
        sha = hashlib.file_digest(stream, 'sha256').hexdigest()
    return {'path': str(path), 'bytes': path.stat().st_size, 'sha256': sha}


def build():
    expected = [
        (Path('E:/SecretFlasherManakaREA/GameAssembly.dll'), '6003033049ac32e8712dc4101382534e21d65b97100c167ebec6bbca1462c18d'),
        (Path('E:/SecretFlasherManakaREA/SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat'), '457203754abe77b346fd98086a5c787bd41088d808cc81b1d4e2cae5b85c72c8'),
        (Path('E:/SecretFlasherManakaREA/SecretFlasherManaka_Data/data.unity3d'), '20781befb4cc42f898b65fe03f3d16c0a77b53aecac6ddc388460cfb710ae93a'),
        (RE / 'salt/.cache/decrypted/models.unity3d', '98621b2c4fa4f9de80f355fae5776ab17efc016bcc81c581bcd0917af4308367'),
    ]
    inputs = []
    for path, sha in expected:
        row = fingerprint(path)
        assert row['sha256'] == sha, 'Original input differs: ' + str(path)
        inputs.append(row)
    runs = []
    for name in ['native', 'native-key-callback']:
        run = json.loads((HERE / name / 'run.json').read_text(encoding='utf-8'))
        assert run['success'] and not any(run.get(k) for k in ['error', 'close_error', 'transport_close_error'])
        runs.append({'path': name + '/run.json', 'success': True, 'closed': True,
                     'observations': len(run['functions']), 'started_at_utc': run['started_at_utc'],
                     'finished_at_utc': run['finished_at_utc']})
    output = []
    for path in sorted(HERE.rglob('*')):
        if not path.is_file() or path == HERE / 'manifest.json' or '__pycache__' in path.parts:
            continue
        row = fingerprint(path)
        row['path'] = path.relative_to(HERE).as_posix()
        output.append(row)
    frozen = [row for row in output if row['path'] in ['interactions.json', 'original-interaction.json']]
    assert len(frozen) == 2
    acceptance = json.loads((HERE / 'original-interaction.json').read_text(encoding='utf-8'))
    bypath = {row['path']: row for row in output}
    for source in acceptance['sources']:
        assert bypath[source['path']]['sha256'] == source['sha256']
    return {'schema_version': 1, 'authority': 'Static shipped-artifact evidence; no original game execution',
            'inputs': inputs, 'outputs': output, 'frozen_inputs': frozen, 'native_runs': runs,
            'query_summary': {'total': 6, 'nonempty_pseudocode': 5, 'empty_assembly_listing': 1,
                              'newly_decompiled_procedures': 1, 'rechecked_existing_procedures': 4},
            'fixture_placement': acceptance['fixturePlacement'],
            'limitations': ['Empty native Listing is not instruction-level corroboration.',
                            'The independent Apartment fixture is not a fixed original scene key.',
                            'Original natural input, animation and drop availability were not observed.']}


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--check', action='store_true')
    args = parser.parse_args()
    result = build()
    target = HERE / 'manifest.json'
    if args.check:
        assert json.loads(target.read_text(encoding='utf-8')) == result, 'Evidence manifest differs'
    else:
        target.write_text(json.dumps(result, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({'status': 'consistent' if args.check else 'written', 'outputs': len(result['outputs']),
                      'closed_native_runs': len(result['native_runs']), 'frozen_inputs': 2}))
