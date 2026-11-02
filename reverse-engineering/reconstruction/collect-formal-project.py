"""Freeze a maintained-project build and separately scoped controlled/cold evidence."""
import argparse
import gzip
import hashlib
import json
import re
import runpy
import shutil
from pathlib import Path

HERE = Path(__file__).resolve().parent
DESTINATION = HERE / 'formal-project-runtime'
STATUS = 'formal-unity-project-authored-apartment-build-controlled-save-restart-verified'


def read(path):
    return json.loads(path.read_text('utf-8-sig'))


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def pin(path, absolute=False):
    return dict(path=str(path.resolve()) if absolute else path.relative_to(HERE).as_posix(), bytes=path.stat().st_size, sha256=sha(path))


def write(path, value):
    path.write_bytes((json.dumps(value, ensure_ascii=False, indent=2) + '\n').encode('utf8'))


def require(condition, message):
    if not condition:
        raise ValueError(message)


def copy_files(source, destination, names):
    destination.mkdir(parents=True, exist_ok=False)
    for name in names:
        shutil.copyfile(source / name, destination / name)


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
    parser.add_argument('--build-run', default='formal-20261103-1')
    parser.add_argument('--run-name', default='formal-controlled-20261103-1')
    parser.add_argument('--authoring-run', default='formal-authoring-20261103-4')
    parser.add_argument('--validation-run', default='formal-validation-20261103-2')
    parser.add_argument('--diagnostic-authoring-run', action='append', default=None)
    parser.add_argument('--diagnostic-validation-run', default='formal-validation-20261103-1')
    args = parser.parse_args()
    diagnostic_runs = args.diagnostic_authoring_run or ['formal-authoring-20261103-1', 'formal-authoring-20261103-2']
    for name in [args.build_run, args.run_name, args.authoring_run, args.validation_run, args.diagnostic_validation_run] + diagnostic_runs:
        require(re.fullmatch(r'formal-[a-z0-9-]+', name), 'Use simple formal- prefixed run names')
    require(not DESTINATION.exists() and not (HERE / 'formal-project-runtime.json').exists(), 'Preserve earlier archives; destination already exists')
    cache, project = HERE / '.cache', HERE / 'UnityProject'
    build, record = cache / (args.build_run + '-build'), cache / (args.build_run + '-build-record')
    authoring, validation = cache / args.authoring_run, cache / args.validation_run
    build_start, build_exit = read(record / 'start.json'), read(record / 'exit.json')
    before, after = read(record / 'sources-before.json'), read(record / 'sources-after.json')
    receipt = read(build / 'build-proof.json')
    require(build_exit['exit_code'] == 0 and build_exit['process_exited'] and build_exit['exit_code_observed'] and build_exit['sources_unchanged'] and not build_exit['source_differences'], 'Formal build or source preservation failed')
    require(before['files'] == after['files'] and receipt['result'] == 'Succeeded' and receipt['errors'] == 0, 'Build source snapshot or result differs')
    require(receipt['scenes'][0] == 'Assets/Scenes/Title.unity' and 'Assets/Scenes/Apartment.unity' in receipt['scenes'], 'Build did not include authored scenes')
    authored, validated = read(authoring / 'assetization.json'), read(validation / 'assetization.json')
    for directory in [authoring, validation]:
        end = read(directory / 'exit.json')
        require(end['process_exited'] and end['exit_code_observed'] and end['exit_code'] == 0, 'Editor authoring/validation did not exit successfully')
    require(authored['status'] == 'apartment-native-assets-created' and validated['status'] == 'apartment-saved-scene-validated', 'Apartment authoring or reload validation is incomplete')
    phases = dict(controlled=cache / (args.run_name + '-interaction-controlled'), phase2=cache / (args.run_name + '-phase2'))
    proofs = {name: read(path / 'proof.json') for name, path in phases.items()}
    require(all(value['passed'] and value['completed'] and value['screenshotValidated'] for value in proofs.values()), 'Runtime did not complete successfully')
    DESTINATION.mkdir()
    for name, path in phases.items():
        archive_runtime(path, DESTINATION / name)
    copy_files(record, DESTINATION / 'build', ['start.json', 'exit.json', 'sources-before.json', 'sources-after.json'])
    shutil.copyfile(build / 'build-proof.json', DESTINATION / 'build/build-proof.json')
    for name, directory in [('authoring', authoring), ('validation', validation)]:
        copy_files(directory, DESTINATION / name, ['start.json', 'exit.json', 'assetization.json'])
    # Archive build-time C# sources without duplicating the native room assets.
    # The complete historical input snapshot remains in sources-before/after.
    runtime_sources = []
    for row in before['files']:
        path = project / row['path']
        if path.suffix != '.cs':
            continue
        require(path.stat().st_size == row['bytes'] and sha(path) == row['sha256'], 'Current source no longer matches this build: ' + row['path'])
        target = DESTINATION / 'build' / row['path']
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(path, target)
        if path.parent.name == 'Runtime':
            runtime_sources.append(dict(path=target.relative_to(DESTINATION).as_posix(), sha256=row['sha256']))
    profile = Path(read(phases['controlled'] / 'process-start.json')['profile_root'])
    for name in ['save.v1.json', 'save.v1.json.bak']:
        if (profile / name).is_file():
            shutil.copyfile(profile / name, DESTINATION / name)
    config = dict(schema_version=1, scope='Controlled input only; no physical-keyboard or complete-gameplay acceptance.', events='controlled/events.jsonl.gz', identity='../interaction-evidence/original-interaction.json', start='controlled/process-start.json', exit='controlled/process-exit.json', proof='controlled/proof.json', runtime_sources=runtime_sources)
    write(DESTINATION / 'controlled-inputs.json', config)
    analyzer = runpy.run_path(str(HERE / 'interaction-acceptance-tools/verify_interaction.py'))
    analysis = analyzer['build'](DESTINATION / 'controlled-inputs.json', controlled=True)
    write(DESTINATION / 'controlled-acceptance.json', analysis)
    private_logs, diagnostics = [], []
    for directory in [record, authoring, validation, cache / args.diagnostic_validation_run] + [cache / name for name in diagnostic_runs]:
        for name in ['editor.log', 'stdout.log', 'stderr.log']:
            if (directory / name).is_file():
                private_logs.append(pin(directory / name, True))
    for name in diagnostic_runs:
        directory = cache / name
        require(name not in {args.authoring_run, args.validation_run} and (directory / 'exit.json').is_file(), 'Missing distinct diagnostic authoring run: ' + name)
        end = read(directory / 'exit.json')
        require(end['process_exited'] and end['exit_code'] != 0, 'Earlier diagnostic was promoted from a successful run')
        copy_files(directory, DESTINATION / 'diagnostics' / name, ['start.json', 'exit.json'])
        text = (directory / 'editor.log').read_text('utf-8-sig', errors='replace')
        if 'error CS0266' in text:
            kind, summary = 'compiler-failed-before-authoring', 'ProjectBuild receipt errors/warnings were declared uint although the BuildReport values were int (CS0266); receipt fields were corrected to int before successful authoring.'
        elif 'untitled' in text.lower() or 'NewScene' in text:
            kind, summary = 'initial-scene-context-rejected', 'The initial untitled scene prevented additive scene creation; partial outputs were retained privately and a saved-scene precondition was added before retry.'
        else:
            kind, summary = 'earlier-authoring-failure', 'An earlier authoring attempt exited unsuccessfully; the raw engine log remains private.'
        diagnostics.append(dict(run=name, kind=kind, process_exit=end, formal_acceptance=False, summary=summary))
    directory = cache / args.diagnostic_validation_run
    end = read(directory / 'exit.json')
    require(args.diagnostic_validation_run != args.validation_run and end['process_exited'] and end['exit_code'] != 0, 'Earlier failed scene validation was promoted to success')
    copy_files(directory, DESTINATION / 'diagnostics' / args.diagnostic_validation_run, ['start.json', 'exit.json'])
    diagnostics.append(dict(run=args.diagnostic_validation_run, kind='saved-material-reference-validation-failed', process_exit=end, formal_acceptance=False, associated_authoring_run='formal-authoring-20261103-3', summary='Import3 exited successfully and saved native textures, but reload validation found 258 material texture references null because textures[i] was not assigned. The importer assignment was corrected and fresh Import4 assets passed Validate2.'))
    packages = []
    for directory in sorted({str(Path(read(path / 'process-start.json')['executable']).parent) for path in phases.values()}):
        package = Path(directory)
        packages.append(dict(directory=directory, files=[pin(path, True) for path in sorted(package.rglob('*')) if path.is_file()]))
    outputs = [pin(path) for path in sorted(DESTINATION.rglob('*')) if path.is_file()]
    for row in outputs:
        if row['path'].endswith('.gz'):
            raw = gzip.decompress((HERE / row['path']).read_bytes())
            row.update(uncompressed_bytes=len(raw), uncompressed_sha256=hashlib.sha256(raw).hexdigest())
    source_names = ['unity-project.ps1', 'assetize-apartment.ps1', 'formal-editor-settings.json', 'run-formal-project.ps1', 'collect-formal-project.py', 'verify-formal-runtime.py', 'verify-formal-project.py']
    dependencies = ['interaction-acceptance-tools/verify_interaction.py', 'interaction-evidence/original-interaction.json', 'interaction-evidence/interactions.json', 'interaction-evidence/manifest.json', 'locomotion-evidence/original-controller.json', 'save-bridge/seed-manifest.json', 'asset-bridge/export-manifest.json', 'verify-unity-editor.py']
    manifest = dict(schema_version=1, status=STATUS, editor_version='6000.6.7f1', editor=build_start['editor_identity'], project=str(project), sources=[pin(HERE / name) for name in source_names], dependencies=[pin(HERE / name) for name in dependencies], outputs=outputs, project_inputs=before['files'], private_logs=private_logs, authoring=dict(run=args.authoring_run, receipt=authored, process_exit=read(authoring / 'exit.json')), validation=dict(run=args.validation_run, receipt=validated, process_exit=read(validation / 'exit.json')), build=dict(run=args.build_run, receipt=receipt, process_exit=build_exit, executable=str(build / 'ManakaInteraction.exe'), sources_unchanged=True, source_file_count=before['file_count'], files=[pin(path, True) for path in sorted(build.rglob('*')) if path.is_file()]), runtime=dict(run=args.run_name, **proofs, packages=packages), diagnostics=diagnostics, limitations=['The room is assetized from the already partial geometry bridge. Original shaders, full lighting, five unresolved builtin meshes and omitted original physics/gameplay remain outside this result.', 'Player and the key fixture still load from the verified original model bundle; missing original scripts are not recreated by assetizing the room.', 'The controlled process proves a simulated input/action/event/movement/save chain. It does not establish physical keyboard reception under Unity6.', 'The key fixture is recreated per process and is not natural world-drop persistence. Cold inventory is independently parsed from the save; no second in-memory inventory count is inferred.', 'Raw editor/license/standard-stream logs remain private; safe process receipts and their log hashes are published.', 'The maintained UnityProject may be edited after this historical run. Default verification uses archived build-time source and receipt contracts; --inputs additionally requires current local inputs to still match this run.'])
    write(HERE / 'formal-project-runtime.json', manifest)
    print(json.dumps(dict(status=STATUS, archive_files=len(outputs), maintained_inputs=len(before['files']), build_files=len(manifest['build']['files']), controlled_only=True), ensure_ascii=False))


if __name__ == '__main__':
    main()
