"""Freeze a Unity6 build and separately labelled controlled/cold runtime evidence."""
import argparse
import gzip
import hashlib
import json
import re
import runpy
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


def write(path, value):
    path.write_bytes((json.dumps(value, ensure_ascii=False, indent=2) + '\n').encode('utf8'))


def archive_runtime(source, destination):
    destination.mkdir(parents=True, exist_ok=False)
    for path in sorted(source.iterdir()):
        if not path.is_file() or path.suffix not in ['.json', '.jsonl', '.log', '.png']:
            continue
        raw = path.read_bytes()
        compressed = path.suffix in ['.jsonl', '.log']
        (destination / (path.name + '.gz' if compressed else path.name)).write_bytes(gzip.compress(raw, mtime=0) if compressed else raw)


def private_logs(cache, project_run, record):
    candidates = [cache / (project_run + suffix) for suffix in ['-create.log', '-stdout.log', '-stderr.log']]
    candidates += [record / name for name in ['editor.log', 'stdout.log', 'stderr.log']]
    return [pin(path, True) for path in candidates if path.is_file()]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--project-run', default='unity6-20261103-2')
    parser.add_argument('--build-run', default='unity6-20261103-3')
    parser.add_argument('--run-name', default='unity6-controlled-20261103-3')
    parser.add_argument('--diagnostic-project-run', default='unity6-20261103-1')
    parser.add_argument('--diagnostic-build-run', default='unity6-20261103-2')
    args = parser.parse_args()
    for value in [args.project_run, args.build_run, args.run_name, args.diagnostic_project_run, args.diagnostic_build_run]:
        if not re.fullmatch(r'unity6-[a-z0-9-]+', value):
            raise ValueError('Use simple unity6- prefixed run names')
    cache, destination = HERE / '.cache', HERE / 'unity-editor-runtime'
    if destination.exists() or (HERE / 'unity-editor-runtime.json').exists():
        raise ValueError('Preserve previous evidence; this collector never replaces an archive or manifest')
    created = read(cache / (args.project_run + '-start.json'))
    creation_exit = read(cache / (args.project_run + '-exit.json'))
    assert creation_exit['process_exited'] and creation_exit['exit_code'] == 0 and creation_exit['project_version_generated'], 'Formal creation lacks a zero OS exit code'
    project = Path(created['project'])
    build, record = cache / (args.build_run + '-build'), cache / (args.build_run + '-build-record')
    build_start, build_exit = read(record / 'start.json'), read(record / 'exit.json')
    receipt = read(build / 'build-proof.json')
    assert build_exit['process_exited'] and build_exit['exit_code'] == 0 and receipt['result'] == 'Succeeded' and receipt['errors'] == 0
    phases = dict(controlled=cache / (args.run_name + '-interaction-controlled'), phase2=cache / (args.run_name + '-phase2'))
    proofs = {name: read(path / 'proof.json') for name, path in phases.items()}
    assert all(proof['passed'] and proof['completed'] and proof['screenshotValidated'] and proof['unityVersion'] == '6000.6.7f1' for proof in proofs.values()), 'Unity6 runtime did not complete'
    destination.mkdir()
    for name, path in phases.items():
        archive_runtime(path, destination / name)
    creation = destination / 'creation'
    creation.mkdir()
    for suffix, name in [('-start.json', 'start.json'), ('-exit.json', 'exit.json')]:
        shutil.copyfile(cache / (args.project_run + suffix), creation / name)
    shutil.copyfile(project / 'ProjectSettings/ProjectVersion.txt', creation / 'ProjectVersion.txt')
    build_archive = destination / 'build'
    build_archive.mkdir()
    for name in ['start.json', 'exit.json', 'input-settings.json']:
        shutil.copyfile(record / name, build_archive / name)
    shutil.copytree(record / 'Assets', build_archive / 'Assets')
    shutil.copyfile(build / 'build-proof.json', build_archive / 'build-proof.json')
    project_files = [project / name for name in ['ProjectSettings/ProjectVersion.txt', 'ProjectSettings/ProjectSettings.asset', 'ProjectSettings/GraphicsSettings.asset']]
    settings_text = project_files[1].read_text(encoding='utf-8-sig')
    handlers = re.findall(r'^\s*activeInputHandler:\s*(\d+)\s*$', settings_text, re.M)
    assert handlers == ['0'], 'Unity legacy input is not enabled exclusively'
    graphics = project_files[2].read_text(encoding='utf-8-sig')
    assert re.search(r'^\s*m_CustomRenderPipeline:\s*\{fileID:\s*0\}\s*$', graphics, re.M), 'This migration requires the Built-in render pipeline'
    project_configuration = dict(editor_version='6000.6.7f1', active_input_handler=0, render_pipeline='Built-in', files=[pin(path, True) for path in project_files])
    write(build_archive / 'project-configuration.json', project_configuration)
    profile = cache / (args.run_name + '-profile')
    for name in ['save.v1.json', 'save.v1.json.bak']:
        if (profile / name).is_file():
            shutil.copyfile(profile / name, destination / name)
    logs = private_logs(cache, args.project_run, record)
    diagnostics = []
    old_start, old_exit = cache / (args.diagnostic_project_run + '-start.json'), cache / (args.diagnostic_project_run + '-exit.json')
    if old_start.exists() and old_exit.exists() and args.diagnostic_project_run != args.project_run:
        old_destination = destination / 'diagnostics' / args.diagnostic_project_run
        old_destination.mkdir(parents=True)
        shutil.copyfile(old_start, old_destination / 'start.json')
        shutil.copyfile(old_exit, old_destination / 'exit.json')
        old = read(old_exit)
        diagnostics.append(dict(kind='creation-exit-unavailable', run=args.diagnostic_project_run, process_exit=old, formal_acceptance=False, scope='Earlier startup diagnostic; a missing OS exit code remains unavailable even if the private engine log reports successful shutdown.'))
        logs += private_logs(cache, args.diagnostic_project_run, cache / (args.diagnostic_project_run + '-build-record'))
    failed_record = cache / (args.diagnostic_build_run + '-build-record')
    if args.diagnostic_build_run != args.build_run and (failed_record / 'exit.json').exists():
        failed_exit = read(failed_record / 'exit.json')
        assert failed_exit['process_exited'] and failed_exit['exit_code'] == 1 and failed_exit['executable_exists'] is False, 'Expected preserved failed Unity6 compiler attempt'
        failed_destination = destination / 'diagnostics' / ('build-' + args.diagnostic_build_run)
        failed_destination.mkdir(parents=True)
        for name in ['start.json', 'exit.json', 'input-settings.json']:
            shutil.copyfile(failed_record / name, failed_destination / name)
        shutil.copytree(failed_record / 'Assets', failed_destination / 'Assets')
        failed_log = (failed_record / 'editor.log').read_text(encoding='utf-8-sig', errors='replace')
        assert 'GetInstanceID' in failed_log and 'error CS0619' in failed_log, 'Compiler failure reason is not the retained GetInstanceID rejection'
        diagnostics.append(dict(kind='compiler-failed-before-migration', run=args.diagnostic_build_run, process_exit=failed_exit, formal_acceptance=False, compiler_error='CS0619', rejected_api='UnityEngine.Object.GetInstanceID()', scope='This unsuccessful pre-migration build is a separate diagnostic and supplies no accepted executable or runtime evidence.'))
        logs += private_logs(cache, args.project_run, failed_record)
    logs = list({row['path'].casefold(): row for row in logs}.values())
    runtime_sources = []
    for path in sorted((build_archive / 'Assets').rglob('*.cs')):
        runtime_sources.append(dict(path=path.relative_to(destination).as_posix(), sha256=sha(path)))
    config = dict(schema_version=1, scope='New Unity6 controlled-input diagnostic only; no physical keyboard or old Tuanjie acceptance is promoted.', events='controlled/events.jsonl.gz', identity='../interaction-evidence/original-interaction.json', start='controlled/process-start.json', exit='controlled/process-exit.json', proof='controlled/proof.json', runtime_sources=runtime_sources)
    write(destination / 'controlled-inputs.json', config)
    analyzer = runpy.run_path(str(HERE / 'interaction-acceptance-tools/verify_interaction.py'))
    analysis = analyzer['build'](destination / 'controlled-inputs.json', controlled=True)
    write(destination / 'controlled-acceptance.json', analysis)
    configuration = read(HERE / 'editor-settings.json')
    sources = list((HERE / configuration['runtime_template']).glob('*.cs'))
    sources += list((HERE / 'interaction-project/Assets/Runtime').glob('*.cs'))
    sources += [HERE / name for name in ['editor-settings.json', 'unity-editor.ps1', configuration['editor_template'], 'unity-project/runtime-migration.json', 'collect-unity-editor.py', 'verify-unity-editor.py', 'run-interaction.ps1']]
    outputs = [pin(path) for path in sorted(destination.rglob('*')) if path.is_file()]
    for row in outputs:
        if row['path'].endswith('.gz'):
            raw = gzip.decompress((HERE / row['path']).read_bytes())
            row.update(uncompressed_bytes=len(raw), uncompressed_sha256=hashlib.sha256(raw).hexdigest())
    build_files = [path for path in sorted(build.rglob('*')) if path.is_file()]
    assert not any(path.name.lower() in ['gameassembly.dll', 'tuanjieplayer.dll'] or any(part.lower() == 'bepinex' for part in path.parts) for path in build_files)
    dependencies = ['interaction-evidence/manifest.json', 'interaction-evidence/original-interaction.json', 'interaction-evidence/interactions.json', 'locomotion-evidence/original-controller.json', 'save-bridge/seed-manifest.json', 'interaction-acceptance-tools/verify_interaction.py', 'interaction-runtime.json']
    manifest = dict(schema_version=1, status='unity6-original-resource-controlled-action-save-restart-verified', editor=pin(Path(created['editor']), True), editor_version='6000.6.7f1', sources=[pin(path) for path in sorted(sources)], dependencies=[pin(HERE / name) for name in dependencies], outputs=outputs, private_logs=logs, creation=dict(run=args.project_run, process_exit=creation_exit), build=dict(run=args.build_run, receipt=receipt, process_exit=build_exit, project=str(project), executable=str(build / 'ManakaInteraction.exe'), files=[pin(path, True) for path in build_files]), packaged_inputs=build_start['inputs'], runtime=dict(run=args.run_name, **proofs), diagnostics=diagnostics, limitations=['This is a new Unity6 controlled run. It does not establish real keyboard reception or revalidate the earlier physical Tuanjie run under Unity6.', 'The original Apartment geometry bridge and original key prefab fixture are bounded reconstruction inputs; complete gameplay and natural world-drop persistence remain absent.', 'Only original Locomotion and Action layers are enabled; original shader/material, missing-script and builtin-mesh limitations are re-observed rather than assumed fixed.', 'The saved inventory quantity is independently parsed from JSON. The cold trace proves reading the same bytes and exact pose, but emits no second in-memory inventory-count snapshot.', 'Raw editor, license and standard-stream logs remain private in .cache; only identities and safe process/build receipts are published.'])
    manifest['limitations'].append('Historical instanceId field names now carry complete unsigned 64-bit Unity6 EntityId values. They are runtime-local identities, not old 32-bit InstanceID values or cross-process object keys.')
    write(HERE / 'unity-editor-runtime.json', manifest)
    print(json.dumps(dict(status=manifest['status'], build_files=len(build_files), archive_files=len(outputs), controlled_only=True)))


if __name__ == '__main__':
    main()
