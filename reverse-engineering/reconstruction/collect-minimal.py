"""Archive actual independent-player runs and pin their local build inputs/outputs."""
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


def pin(path, relative=True):
    return dict(path=path.relative_to(HERE).as_posix() if relative else str(path.resolve()), bytes=path.stat().st_size, sha256=sha(path))


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
    parser.add_argument('--build-run', default='minimal-20261031-3')
    parser.add_argument('--run-name', default='minimal-acceptance-20261031-2')
    args = parser.parse_args()
    cache, output = HERE / '.cache', HERE / 'minimal-acceptance'
    if output.exists():
        raise ValueError('Acceptance archive exists; preserve it and choose a new archive in the collector before replacing')
    build = cache / (args.build_run + '-build')
    record = cache / (args.build_run + '-build-record')
    first, second = [read(cache / (args.run_name + '-' + phase) / 'proof.json') for phase in ['phase1', 'phase2']]
    assert first['passed'] and second['passed'] and first['screenshotValidated'] and second['screenshotValidated']
    assert first['titleScreenshotValidated'] and second['titleScreenshotValidated']
    assert read(build / 'build-proof.json')['result'] == 'Succeeded'
    for phase in ['phase1', 'phase2']:
        archive(cache / (args.run_name + '-' + phase), output / phase)
    shutil.copyfile(cache / (args.run_name + '-profile') / 'save.v1.json', output / 'save.v1.json')
    archive(record, output / 'build')
    shutil.copyfile(build / 'build-proof.json', output / 'build/build-proof.json')
    diagnostics = output / 'diagnostics'
    for name in ['minimal-acceptance-20261031-1-phase1', 'minimal-acceptance-20261031-1-phase2', 'minimal-visual-20261031-1-phase2']:
        archive(cache / name, diagnostics / name)
    old_record = cache / 'minimal-20261031-1-build-record'
    archive(old_record, diagnostics / 'first-build')
    shutil.copytree(old_record / 'Assets', diagnostics / 'first-build/Assets')
    shutil.copyfile(cache / 'minimal-20261031-1-build/build-proof.json', diagnostics / 'first-build/build-proof.json')
    shutil.copyfile(cache / 'minimal-20261031-2-build-record/orchestration-failure.json', diagnostics / 'orchestration-failure.json')
    outputs = [pin(path) for path in sorted(output.rglob('*')) if path.is_file()]
    for item in outputs:
        if item['path'].endswith('.gz'):
            raw = gzip.decompress((HERE / item['path']).read_bytes())
            item.update(uncompressed_bytes=len(raw), uncompressed_sha256=hashlib.sha256(raw).hexdigest())
    paths = list((HERE / 'minimal-project/Assets').rglob('*.cs'))
    paths += [HERE / name for name in ['build-minimal.ps1', 'run-minimal.ps1', 'collect-minimal.py', 'verify-minimal.py']]
    sources = [pin(path) for path in sorted(paths)]
    dependencies = [pin(HERE / name) for name in ['asset-compat/manifest.json', 'asset-bridge/export-manifest.json', 'asset-bridge/inventory.json', 'save-bridge/seed-manifest.json']]
    files = [path for path in sorted(build.rglob('*')) if path.is_file()]
    assert not any(path.name.lower() == 'gameassembly.dll' or 'bepinex' in [part.lower() for part in path.parts] for path in files)
    inputs = read(record / 'start.json')['inputs']
    for item in inputs:
        assert sha(Path(item['path'])) == item['sha256']
    managed = [read(path) for path in sorted((HERE / 'asset-compat').glob('managed-inspection*-complete.json'))]
    report = dict(schema_version=1, status='bounded-independent-loop-verified', engine='Tuanjie 2022.3.62t7',
                  sources=sources, dependencies=dependencies, outputs=outputs,
                  build=dict(run=args.build_run, project=read(record / 'start.json')['project'], editor=pin(Path(read(record / 'start.json')['editor']), False), executable=str(build / 'ReconstructedManaka.exe'), receipt=read(build / 'build-proof.json'), process_exit=read(record / 'exit.json'), files=[pin(path, False) for path in files], no_original_gameassembly_or_bepinex_in_package=True),
                  packaged_inputs=inputs, managed_inspections=[dict(evidence_id=item['evidence_id'], path=item['subject']['local_path'], sha256=item['subject']['digest']['sha256']) for item in managed],
                  acceptance=dict(run=args.run_name, phase1=first, phase2=second, save_sha256=sha(output / 'save.v1.json')),
                  diagnostics=dict(batch_logic_passed=True, batch_screenshot_valid=False, batch_screenshot='minimal-acceptance/diagnostics/minimal-acceptance-20261031-1-phase2/readback.png', visible_original_build_confirmation=True, pre_editor_resource_copy_failure_preserved=True),
                  limitations=['Minimum room/movement/save loop only; original GameAssembly and game behaviours are not used.', 'Original build scenes require a partial geometry bridge; five builtin mesh references remain unresolved.', 'Player uses four selected original renderers and eleven Standard material replacements; original Animator/gameplay/appearance fidelity is not implemented.', 'Movement acceptance uses simulated input through the same CharacterController motor as keyboard input; hardware input was not tested.', 'Original shader errors and missing-script warnings remain in retained logs; callback error counts are not a claim of complete resource compatibility.', 'Original ES3 is read offline into a bounded seed; subsequent saves use a separate version1 JSON profile.'])
    (HERE / 'minimal-runtime.json').write_bytes((json.dumps(report, indent=2, ensure_ascii=False) + '\n').encode('utf8'))
    print(json.dumps(dict(status=report['status'], build_files=len(files), archived_outputs=len(outputs), executable=report['build']['executable'])))


if __name__ == '__main__':
    main()
