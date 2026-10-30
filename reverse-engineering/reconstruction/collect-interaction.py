"""Freeze distinct physical, controlled and cold-readback interaction evidence."""
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
    destination.mkdir(parents=True, exist_ok=False)
    for path in sorted(source.iterdir()):
        if not path.is_file() or path.suffix not in ['.json', '.jsonl', '.log', '.png']:
            continue
        raw = path.read_bytes()
        compressed = path.suffix in ['.jsonl', '.log']
        (destination / (path.name + '.gz' if compressed else path.name)).write_bytes(gzip.compress(raw, mtime=0) if compressed else raw)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build-run', default='interaction-20261031-1')
    parser.add_argument('--run-name', default='interaction-natural-20261031-1')
    parser.add_argument('--controlled-run', default='interaction-controlled-20261031-1')
    args = parser.parse_args()
    cache, destination = HERE / '.cache', HERE / 'interaction-runtime'
    if destination.exists():
        raise ValueError('Keep previous archives immutable; select a fresh destination for another investigation')
    phases = dict(interaction=cache / (args.run_name + '-interaction'), phase2=cache / (args.run_name + '-phase2'), controlled=cache / (args.controlled_run + '-interaction-controlled'))
    proofs = {name: read(path / 'proof.json') for name, path in phases.items()}
    assert all(proof['passed'] and proof['completed'] and proof['screenshotValidated'] for proof in proofs.values())
    for name, path in phases.items():
        archive(path, destination / name)
    profile = cache / (args.run_name + '-profile')
    for name in ['save.v1.json', 'save.v1.json.bak']:
        shutil.copyfile(profile / name, destination / name)
    build, record = cache / (args.build_run + '-build'), cache / (args.build_run + '-build-record')
    archive(record, destination / 'build')
    shutil.copytree(record / 'Assets', destination / 'build/Assets')
    shutil.copyfile(build / 'build-proof.json', destination / 'build/build-proof.json')
    sources = list((HERE / 'interaction-project/Assets').rglob('*.cs'))
    sources += [HERE / name for name in ['build-interaction.ps1', 'run-interaction.ps1', 'collect-interaction.py', 'verify-interaction-runtime.py']]
    outputs = [pin(path) for path in sorted(destination.rglob('*')) if path.is_file()]
    for output in outputs:
        if output['path'].endswith('.gz'):
            raw = gzip.decompress((HERE / output['path']).read_bytes())
            output.update(uncompressed_bytes=len(raw), uncompressed_sha256=hashlib.sha256(raw).hexdigest())
    files = [path for path in sorted(build.rglob('*')) if path.is_file()]
    assert not any(path.name.lower() == 'gameassembly.dll' or 'bepinex' in path.parts for path in files)
    inspections = [read(HERE / name) for name in ['interaction-managed-summary.json', 'interaction-managed-complete.json']]
    manifest = dict(schema_version=1, status='original-action-event-physical-recovery-save-restart-verified',
                    sources=[pin(path) for path in sorted(sources)], outputs=outputs,
                    dependencies=[pin(HERE / name) for name in ['interaction-evidence/manifest.json', 'interaction-evidence/interactions.json', 'interaction-evidence/original-interaction.json', 'locomotion-evidence/original-controller.json', 'save-bridge/seed-manifest.json', 'interaction-managed-summary.json', 'interaction-managed-complete.json']],
                    build=dict(run=args.build_run, receipt=read(build / 'build-proof.json'), process_exit=read(record / 'exit.json'), project=read(record / 'start.json')['project'], executable=str(build / 'ManakaInteraction.exe'), files=[pin(path, True) for path in files]),
                    packaged_inputs=read(record / 'start.json')['inputs'],
                    managed_inspections=[dict(evidence_id=item['evidence_id'], path=item['subject']['local_path'], sha256=item['subject']['digest']['sha256']) for item in inspections],
                    runtime=dict(run=args.run_name, controlled_run=args.controlled_run, **proofs),
                    limitations=['Physical run confirms F, original event, same-frame None, later movement, save and cold readback. It does not include nonzero movement input during the action lock; that condition is separately controlled.', 'Original Apartment has only PC, bed and closet UI interaction areas. The genuine original key prefab is an explicitly placed reconstruction fixture, recreated per process; natural drop spawning/persistence is not implemented.', 'Only original Locomotion and Action layers are enabled; ten ancillary layers remain zero. Handclothes, non-Idle, ecstasy and global-manager conditions are neutral rather than fully reconstructed.', 'The reconstruction adapter directly starts PlayerAction before motor update; the original callback stages TransAction for PlayerAction.OnUpdate. Exact original intra-frame update order is not claimed.', 'Original scripts and GameAssembly are absent. Shader/material fallback, missing scripts and five unresolved builtin meshes remain.', 'IEEE-754 negative zero is canonicalized; all nonzero pose bits remain exact. Hardware provenance requires the separate user receipt.'])
    (HERE / 'interaction-runtime.json').write_bytes((json.dumps(manifest, ensure_ascii=False, indent=2) + '\n').encode('utf8'))
    print(json.dumps(dict(status=manifest['status'], files=len(files), archive_files=len(outputs))))


if __name__ == '__main__':
    main()
