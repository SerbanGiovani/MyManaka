"""Freeze a new home-interaction build and its controlled/cold runtime evidence.

No historical project receipts are rewritten. Editor logs remain private; player
events/logs are compressed deterministically for independent verification.
"""
import argparse
import gzip
import hashlib
import json
import re
import runpy
import shutil
from pathlib import Path

HERE = Path(__file__).resolve().parent
STATUS = 'home-interaction-controlled-save-cold-readback-verified'


def read(path):
    return json.loads(path.read_text('utf-8-sig'))


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def pin(path, absolute=False):
    return dict(path=str(path.resolve()) if absolute else path.relative_to(HERE).as_posix(), bytes=path.stat().st_size, sha256=sha(path))


def require(value, message):
    if not value:
        raise ValueError(message)


def write(path, value):
    path.write_bytes((json.dumps(value, ensure_ascii=False, indent=2) + '\n').encode('utf8'))


def archive_runtime(source, destination):
    destination.mkdir(parents=True, exist_ok=False)
    for path in sorted(source.iterdir()):
        if not path.is_file() or path.suffix not in {'.json', '.jsonl', '.log', '.png'}:
            continue
        raw = path.read_bytes()
        compressed = path.suffix in {'.jsonl', '.log'}
        (destination / (path.name + '.gz' if compressed else path.name)).write_bytes(gzip.compress(raw, mtime=0) if compressed else raw)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build-run', required=True)
    parser.add_argument('--run-name', required=True)
    parser.add_argument('--controlled-phase', default='home-controlled')
    parser.add_argument('--resume-phase', default='home-resume')
    args = parser.parse_args()
    for name in [args.build_run, args.run_name, args.controlled_phase, args.resume_phase]:
        require(re.fullmatch(r'[a-z0-9][a-z0-9-]*', name), 'Use local simple run/phase names')
    destination, manifest_path = HERE / 'home-interaction-runtime', HERE / 'home-interaction-runtime.json'
    require(not destination.exists() and not manifest_path.exists(), 'Preserve prior evidence; select a new collector/archive for a later round')
    cache, project = HERE / '.cache', HERE / 'UnityProject'
    build, record = cache / (args.build_run + '-build'), cache / (args.build_run + '-build-record')
    before, after = (read(record / name) for name in ['sources-before.json', 'sources-after.json'])
    build_start, build_exit = read(record / 'start.json'), read(record / 'exit.json')
    receipt = read(build / 'build-proof.json')
    require(before['files'] == after['files'] and build_exit['sources_unchanged'] and not build_exit['source_differences'], 'Build changed maintained input bytes')
    require(build_exit['process_exited'] and build_exit['exit_code_observed'] and build_exit['exit_code'] == 0 and receipt['result'] == 'Succeeded' and receipt['errors'] == 0, 'Build failed or no actual zero OS exit code was observed')
    phases = {'controlled': cache / (args.run_name + '-' + args.controlled_phase), 'resume': cache / (args.run_name + '-' + args.resume_phase)}
    proofs = {}
    for name, directory in phases.items():
        begin, end, proof = (read(directory / item) for item in ['process-start.json', 'process-exit.json', 'proof.json'])
        require(begin['pid'] == end['pid'] == proof['processId'] and end['process_exited'] and end['exit_code_observed'] and end['exit_code'] == 0, 'Runtime process lifetime was not verified: ' + name)
        require(proof['passed'] and proof['completed'] and proof['screenshotValidated'] and proof['unexpectedEngineErrors'] == 0, 'Runtime proof did not complete: ' + name)
        proofs[name] = proof
    require(proofs['controlled']['processGuid'] != proofs['resume']['processGuid'], 'Cold readback reused the writing process')
    # Validate all source bytes before creating the immutable output directory.
    archive_rows = []
    for row in before['files']:
        path = project / row['path']
        if path.suffix not in {'.cs', '.json', '.unity', '.prefab'}:
            continue
        require(path.stat().st_size == row['bytes'] and sha(path) == row['sha256'], 'Current source no longer matches this build: ' + row['path'])
        archive_rows.append((row, path))
    destination.mkdir()
    for name, directory in phases.items():
        archive_runtime(directory, destination / name)
    archive_build = destination / 'build'
    archive_build.mkdir()
    for name in ['start.json', 'exit.json', 'sources-before.json', 'sources-after.json']:
        shutil.copyfile(record / name, archive_build / name)
    shutil.copyfile(build / 'build-proof.json', archive_build / 'build-proof.json')
    for row, path in archive_rows:
        target = archive_build / row['path']
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(path, target)
    profile = Path(read(phases['controlled'] / 'process-start.json')['profile_root'])
    for name in ['save.v1.json', 'save.v1.json.bak']:
        if (profile / name).is_file():
            shutil.copyfile(profile / name, destination / name)
    (destination / 'dependencies').mkdir()
    skin_dependencies = []
    for name in ['results.json', 'skin-preset-runtime.md']:
        path = HERE.parent / 'runtime/skin-preset' / name
        shutil.copyfile(path, destination / 'dependencies' / name)
        skin_dependencies.append(dict(path='../runtime/skin-preset/' + name, bytes=path.stat().st_size, sha256=sha(path)))
    packages = []
    for directory in sorted({str(Path(read(path / 'process-start.json')['executable']).parent) for path in phases.values()}):
        packages.append(dict(directory=directory, files=[pin(path, True) for path in sorted(Path(directory).rglob('*')) if path.is_file()]))
    outputs = [pin(path) for path in sorted(destination.rglob('*')) if path.is_file()]
    for row in outputs:
        if row['path'].endswith('.gz'):
            raw = gzip.decompress((HERE / row['path']).read_bytes())
            row.update(uncompressed_bytes=len(raw), uncompressed_sha256=hashlib.sha256(raw).hexdigest())
    source_names = ['collect-home-runtime.py', 'verify-home-runtime.py', 'run-home-runtime.ps1']
    dependencies = ['home-interaction-evidence/contract.json', 'verify-formal-project.py']
    manifest = dict(schema_version=1, status=STATUS, project=str(project), editor=build_start['editor_identity'], sources=[pin(HERE / path) for path in source_names], dependencies=[pin(HERE / path) for path in dependencies] + skin_dependencies, outputs=outputs, project_inputs=before['files'], build=dict(run=args.build_run, receipt=receipt, start=build_start, process_exit=build_exit, files=[pin(path, True) for path in sorted(build.rglob('*')) if path.is_file()]), runtime=dict(run=args.run_name, controlled_phase=args.controlled_phase, resume_phase=args.resume_phase, proofs=proofs, packages=packages), private_logs=[pin(path, True) for path in [record / 'editor.log', record / 'stdout.log', record / 'stderr.log'] if path.is_file()], scope='Controlled simulated F and movement input at active source-backed PC/closet targets; inactive bed remains unavailable. Selected preset primary colors and PC-save/cold readback are checked. No physical keyboard, complete original UI, full sleep/customization system or original .sd compatibility is inferred.')
    # The verifier is deliberately invoked before publishing the top-level
    # manifest; failed collection stays a diagnostic, never a successful record.
    verifier = runpy.run_path(str(HERE / 'verify-home-runtime.py'))
    analysis = verifier['verify_manifest'](manifest, inputs=False)
    write(destination / 'analysis.json', analysis)
    manifest['outputs'].append(pin(destination / 'analysis.json'))
    write(manifest_path, manifest)
    print(json.dumps(dict(status=STATUS, archive_files=len(manifest['outputs']), maintained_inputs=len(before['files']), build_files=len(manifest['build']['files']), controlled_only=True), ensure_ascii=False))


if __name__ == '__main__':
    main()
