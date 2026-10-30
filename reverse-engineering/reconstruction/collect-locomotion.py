"""Freeze a visible keyboard/Animator/save/restart run without replacing history."""
import argparse
import gzip
import hashlib
import json
import shutil
from pathlib import Path

HERE = Path(__file__).resolve().parent


def read(path):
    return json.loads(path.read_text(encoding='utf-8-sig'))


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def pin(path, absolute=False):
    return dict(path=str(path.resolve()) if absolute else path.relative_to(HERE).as_posix(), bytes=path.stat().st_size, sha256=sha(path))


def archive(source, destination):
    destination.mkdir(parents=True, exist_ok=True)
    for path in source.iterdir():
        if not path.is_file() or path.suffix not in ['.json', '.jsonl', '.log', '.png']:
            continue
        raw = path.read_bytes()
        compressed = path.suffix in ['.jsonl', '.log']
        (destination / (path.name + '.gz' if compressed else path.name)).write_bytes(gzip.compress(raw, mtime=0) if compressed else raw)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build-run', default='locomotion-20261031-3')
    parser.add_argument('--run-name', default='keyboard-natural-20261031-2')
    args = parser.parse_args()
    cache, archive_root = HERE / '.cache', HERE / 'locomotion-runtime'
    if archive_root.exists():
        raise ValueError('Preserve the preceding archive; use a new destination for another investigation')
    phases = ['keyboard', 'phase2']
    proofs = [read(cache / (args.run_name + '-' + phase) / 'proof.json') for phase in phases]
    assert all(proof['passed'] and proof['completed'] and proof['screenshotValidated'] for proof in proofs)
    for phase in phases:
        archive(cache / (args.run_name + '-' + phase), archive_root / phase)
    profile = cache / (args.run_name + '-profile')
    for name in ['save.v1.json', 'save.v1.json.bak']:
        shutil.copyfile(profile / name, archive_root / name)
    build = cache / (args.build_run + '-build')
    record = cache / (args.build_run + '-build-record')
    archive(record, archive_root / 'build')
    shutil.copyfile(build / 'build-proof.json', archive_root / 'build/build-proof.json')
    diagnostics = archive_root / 'diagnostics'
    for name in ['locomotion-diagnostic-20261031-1-phase1', 'keyboard-diagnostic-20261031-1-keyboard', 'keyboard-natural-20261031-1-keyboard']:
        archive(cache / name, diagnostics / name)
    for number in [1, 2]:
        old_record = cache / ('locomotion-20261031-' + str(number) + '-build-record')
        destination = diagnostics / ('build-' + str(number))
        archive(old_record, destination)
        shutil.copytree(old_record / 'Assets', destination / 'Assets')
        shutil.copyfile(cache / ('locomotion-20261031-' + str(number) + '-build/build-proof.json'), destination / 'build-proof.json')
    shutil.copyfile(cache / 'keyboard-natural-20261031-1-profile/save.v1.json', diagnostics / 'f5-failed-round-save.v1.json')
    for name in ['animator-probe-20261031-1', 'save-roundtrip-probe-20261031-1', 'save-roundtrip-probe-20261031-2', 'save-roundtrip-probe-20261031-3', 'save-fix-probe-20261031-1']:
        archive(cache / name, archive_root / 'probes' / name)
    sources = list((HERE / 'locomotion-project/Assets').rglob('*.cs'))
    sources += list((HERE / 'animator-probe/Assets').rglob('*.cs'))
    sources += [HERE / name for name in ['build-locomotion.ps1', 'run-locomotion.ps1', 'collect-locomotion.py', 'verify-locomotion-runtime.py']]
    outputs = [pin(path) for path in sorted(archive_root.rglob('*')) if path.is_file()]
    for output in outputs:
        if output['path'].endswith('.gz'):
            raw = gzip.decompress((HERE / output['path']).read_bytes())
            output.update(uncompressed_bytes=len(raw), uncompressed_sha256=hashlib.sha256(raw).hexdigest())
    files = [path for path in sorted(build.rglob('*')) if path.is_file()]
    assert not any(path.name.lower() == 'gameassembly.dll' or 'bepinex' in path.parts for path in files)
    inspections = [read(path) for path in sorted((HERE / 'animator-probe').glob('managed-*-complete.json'))]
    manifest = dict(schema_version=1, status='keyboard-original-animator-save-restart-verified',
                    sources=[pin(path) for path in sorted(sources)], outputs=outputs,
                    dependencies=[pin(HERE / name) for name in ['locomotion-evidence/original-controller.json', 'locomotion-evidence/native-contract.json', 'locomotion-evidence/abi-windows.json', 'save-bridge/seed-manifest.json']],
                    build=dict(run=args.build_run, receipt=read(build / 'build-proof.json'), process_exit=read(record / 'exit.json'), project=read(record / 'start.json')['project'], executable=str(build / 'ManakaLocomotion.exe'), files=[pin(path, True) for path in files]),
                    packaged_inputs=read(record / 'start.json')['inputs'],
                    managed_inspections=[dict(evidence_id=item['evidence_id'], path=item['subject']['local_path'], sha256=item['subject']['digest']['sha256']) for item in inspections],
                    runtime=dict(run=args.run_name, keyboard=proofs[0], restart=proofs[1]),
                    limitations=['Only original locomotion layer is enabled; ancillary action/clothing/arm/face layers remain at weight zero.', 'Turning, gravity and Update integration are reconstruction choices; original full gameplay is not implemented.', 'Original shader/missing-script/builtin-mesh limitations remain.', 'Signed zero is canonicalized before saving; every nonzero float bit is still checked exactly. The failed first physical run did not record raw zero-sign bits, so its precise affected component cannot be recovered.', 'Input origin requires separate operator evidence; Unity cannot identify physical hardware by itself.'])
    (HERE / 'locomotion-runtime.json').write_bytes((json.dumps(manifest, ensure_ascii=False, indent=2) + '\n').encode('utf8'))
    print(json.dumps(dict(status=manifest['status'], files=len(files), archive_files=len(outputs))))


if __name__ == '__main__':
    main()
