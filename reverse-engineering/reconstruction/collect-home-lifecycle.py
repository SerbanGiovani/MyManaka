"""Archive the home-menu close lifecycle test on a frozen native player host."""
import argparse
import gzip
import hashlib
import json
import re
import runpy
import shutil
from pathlib import Path

HERE = Path(__file__).resolve().parent
STATUS = 'home-archived-host-lifecycle-runtime-verified'


def read(path):
    return json.loads(path.read_text('utf-8-sig'))


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def require(value, message):
    if not value:
        raise ValueError(message)


def pin(path, absolute=False):
    return dict(path=str(path.resolve()) if absolute else path.relative_to(HERE).as_posix(), bytes=path.stat().st_size, sha256=sha(path))


def write(path, value):
    path.write_bytes((json.dumps(value, ensure_ascii=False, indent=2) + '\n').encode('utf8'))


def archive_runtime(source, destination):
    destination.mkdir(parents=True, exist_ok=False)
    for path in sorted(source.iterdir()):
        if not path.is_file() or path.suffix not in {'.json', '.jsonl', '.log', '.png'}:
            continue
        raw = path.read_bytes(); compressed = path.suffix in {'.jsonl', '.log'}
        (destination / (path.name + '.gz' if compressed else path.name)).write_bytes(gzip.compress(raw, mtime=0) if compressed else raw)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--host-run', default='formal-home-host-20261103-3')
    parser.add_argument('--run-name', default='home-host-20261103-3')
    parser.add_argument('--failed-host-run', default='formal-home-host-20261103-1')
    parser.add_argument('--failed-run-name', default='home-host-20261103-1')
    parser.add_argument('--license-diagnostic-run', default='formal-home-20261103-1')
    args = parser.parse_args()
    for name in vars(args).values():
        require(re.fullmatch(r'[a-z0-9][a-z0-9-]*', name), 'Use simple local run names')
    destination, top = HERE / 'home-lifecycle-runtime', HERE / 'home-lifecycle-runtime.json'
    require(not destination.exists() and not top.exists(), 'Preserve earlier host archives')
    cache = HERE / '.cache'; record = cache / (args.host_run + '-record')
    host = read(record / 'host.json')
    require(host['unity_editor_build_performed'] is False and host['compile_exit_code'] == 0, 'Host compilation scope/result differs')
    phases = {name: cache / (args.run_name + '-' + phase) for name, phase in [('controlled', 'home-controlled'), ('resume', 'home-resume')]}
    proofs = {}
    for name, directory in phases.items():
        proof, start, end = (read(directory / item) for item in ['proof.json', 'process-start.json', 'process-exit.json'])
        require(start['pid'] == end['pid'] == proof['processId'] and end['process_exited'] and end['exit_code_observed'] and end['exit_code'] == 0 and proof['passed'] and proof['completed'] and proof['screenshotValidated'], 'Host runtime did not complete: ' + name)
        proofs[name] = proof
    for row in host['sources'] + host['replacement_inputs']:
        source = Path(row['path'])
        require(source.stat().st_size == row['bytes'] and sha(source) == row['sha256'], 'Compiled source changed before collection')
    destination.mkdir(); archive_host = destination / 'host'; archive_host.mkdir(); (archive_host / 'sources').mkdir()
    for name in ['host.json', 'runtime.rsp', 'compiler.stdout.txt', 'compiler.stderr.txt']:
        shutil.copyfile(record / name, archive_host / name)
    for row in host['sources']:
        shutil.copyfile(row['path'], archive_host / 'sources' / Path(row['path']).name)
    shutil.copyfile(host['replacement_inputs'][0]['path'], archive_host / 'interactions.json')
    for name, directory in phases.items():
        archive_runtime(directory, destination / name)
    profile = Path(read(phases['controlled'] / 'process-start.json')['profile_root'])
    for name in ['save.v1.json', 'save.v1.json.bak']:
        if (profile / name).is_file():
            shutil.copyfile(profile / name, destination / name)
    dependencies = destination / 'dependencies'; dependencies.mkdir()
    for source, name in [(HERE.parent / 'runtime/skin-preset/results.json', 'skin-preset-results.json'), (HERE.parent / 'runtime/skin-preset/skin-preset-runtime.md', 'skin-preset-runtime.md')]:
        shutil.copyfile(source, dependencies / name)
    diagnostic = destination / 'diagnostics'; diagnostic.mkdir()
    failed = cache / (args.failed_run_name + '-home-controlled')
    archive_runtime(failed, diagnostic / 'host1')
    shutil.copyfile(cache / (args.failed_host_run + '-record/host.json'), diagnostic / 'host1-prepared.json')
    license_record = cache / (args.license_diagnostic_run + '-build-record')
    (diagnostic / 'editor-license').mkdir()
    for name in ['start.json', 'exit.json']:
        shutil.copyfile(license_record / name, diagnostic / 'editor-license' / name)
    private_logs = [pin(path, True) for path in [license_record / 'editor.log', license_record / 'stdout.log', license_record / 'stderr.log'] if path.is_file()]
    outputs = [pin(path) for path in sorted(destination.rglob('*')) if path.is_file()]
    for row in outputs:
        if row['path'].endswith('.gz'):
            raw = gzip.decompress((HERE / row['path']).read_bytes())
            row.update(uncompressed_bytes=len(raw), uncompressed_sha256=hashlib.sha256(raw).hexdigest())
    source_names = ['collect-home-lifecycle.py', 'verify-home-lifecycle.py', 'verify-home-runtime.py', 'prepare-home-host.py', 'run-home-runtime.ps1']
    dependency_names = ['formal-project-runtime.json', 'home-interaction-evidence/contract.json', 'home-host-runtime.json']
    manifest = dict(schema_version=1, status=STATUS, unity_editor_build_performed=False, formal_unity_build_pending=True, host=host, sources=[pin(HERE / name) for name in source_names], dependencies=[pin(HERE / name) for name in dependency_names], outputs=outputs, private_logs=private_logs, runtime=dict(run=args.run_name, proofs=proofs), diagnostics=[dict(kind='original-node-transform-collapsed-by-empty-visual-default', accepted=False, scope='The earlier own managed attempt treated JsonUtility empty visual defaults as a fixture and reset home-node transforms. It exited unsuccessfully; the real-source isFixture guard was corrected and the new host excludes the deliberate key fixture in normal/home phases.'), dict(kind='unity-editor-license-failure', accepted=False, exit_code=198, scope='The fresh Unity Editor build did not produce an executable. The configured editor installation subsequently became unavailable. This host runtime is separate and does not satisfy a fresh Editor build.')], scope='Archived Unity6 player/native assets with only own managed Assembly-CSharp.dll and source-backed interactions JSON replaced. Adds an outstanding closet-close cancellation/disable/re-enable case to the selected PC/closet observations; not a fresh Unity Editor build, physical keyboard proof, native original gameplay or complete UI reconstruction.')
    verifier = runpy.run_path(str(HERE / 'verify-home-lifecycle.py'))
    analysis = verifier['verify_manifest'](manifest, inputs=False)
    write(destination / 'analysis.json', analysis); manifest['outputs'].append(pin(destination / 'analysis.json')); write(top, manifest)
    print(json.dumps(dict(status=STATUS, unity_editor_build_performed=False, formal_unity_build_pending=True, archive_files=len(manifest['outputs']), host_files=len(host['files'])), ensure_ascii=False))


if __name__ == '__main__':
    main()
