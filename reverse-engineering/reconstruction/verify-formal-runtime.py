"""Verify the immutable maintained-project authoring/build/runtime evidence archive."""
import argparse
import gzip
import hashlib
import json
import runpy
from pathlib import Path

HERE = Path(__file__).resolve().parent
STATUS = 'formal-unity-project-authored-apartment-build-controlled-save-restart-verified'


def read(path):
    return json.loads(path.read_text('utf-8-sig'))


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def require(condition, message):
    if not condition:
        raise ValueError(message)


def files(rows, base=HERE):
    for row in rows:
        path = base / row['path']
        require(path.stat().st_size == row['bytes'] and sha(path) == row['sha256'], 'Formal evidence fingerprint differs: ' + str(path))
        if 'uncompressed_sha256' in row:
            raw = gzip.decompress(path.read_bytes())
            require(len(raw) == row['uncompressed_bytes'] and hashlib.sha256(raw).hexdigest() == row['uncompressed_sha256'], 'Compressed formal record differs')


def events(path):
    return [json.loads(line) for line in gzip.decompress(path.read_bytes()).decode('utf-8-sig').splitlines() if line.strip()]


def one(rows, kind):
    matches = [row for row in rows if row['kind'] == kind]
    require(len(matches) == 1, 'Missing or duplicate formal runtime event: ' + kind)
    return matches[0]


def contract_rows(rows):
    return {row['path']: (row['bytes'], row['sha256']) for row in rows}


def build(inputs=False):
    manifest = read(HERE / 'formal-project-runtime.json')
    require(manifest['schema_version'] == 1 and manifest['status'] == STATUS and manifest['editor_version'] == '6000.6.7f1', 'Formal project evidence is incomplete')
    files(manifest['sources'] + manifest['dependencies'] + manifest['outputs'])
    structure = runpy.run_path(str(HERE / 'verify-formal-project.py'))['scan_project'](HERE / 'UnityProject', inputs)
    root = HERE / 'formal-project-runtime'
    before, after = read(root / 'build/sources-before.json'), read(root / 'build/sources-after.json')
    start, end, receipt = read(root / 'build/start.json'), read(root / 'build/exit.json'), read(root / 'build/build-proof.json')
    require(before['files'] == after['files'] == manifest['project_inputs'] and before['file_count'] == after['file_count'] == len(before['files']) == manifest['build']['source_file_count'], 'Maintained project content was not preserved across build')
    require(len(contract_rows(before['files'])) == len(before['files']), 'Duplicate maintained input paths')
    require(start['pid'] == end['pid'] and end == manifest['build']['process_exit'] and end['process_exited'] and end['exit_code_observed'] and end['exit_code'] == 0 and end['sources_unchanged'] and not end['source_differences'], 'Formal build did not preserve sources or exit cleanly')
    require(receipt == manifest['build']['receipt'] and receipt['result'] == 'Succeeded' and receipt['errors'] == 0 and receipt['unityVersion'] == '6000.6.7f1', 'Formal build result differs')
    require(receipt['scenes'][0] == 'Assets/Scenes/Title.unity' and 'Assets/Scenes/Apartment.unity' in receipt['scenes'], 'Both authored scenes were not built')
    require(all(receipt[key] is False for key in ['createsScenes', 'savesScenes', 'copiesSources', 'rewritesSettings']), 'Formal build receipt records source or scene rewriting')
    require(Path(start['project']) == Path(manifest['project']) and start['editor_identity'] == manifest['editor'], 'Formal project/editor identity differs')
    snapshot = contract_rows(before['files'])
    archived_sources = sorted((root / 'build/Assets').rglob('*.cs'))
    require({path.relative_to(root / 'build').as_posix() for path in archived_sources} == {row['path'] for row in before['files'] if row['path'].endswith('.cs')}, 'Build-time C# source archive is incomplete')
    for path in archived_sources:
        relative = path.relative_to(root / 'build').as_posix()
        require(snapshot.get(relative) == (path.stat().st_size, sha(path)), 'Archived build-time source differs from snapshot')
    for name, status in [('authoring', 'apartment-native-assets-created'), ('validation', 'apartment-saved-scene-validated')]:
        stage = manifest[name]
        proof, begin, finish = (read(root / name / item) for item in ['assetization.json', 'start.json', 'exit.json'])
        require(proof == stage['receipt'] and proof['status'] == status and finish == stage['process_exit'], 'Apartment authoring/validation receipt differs')
        require(begin['pid'] == finish['pid'] and finish['process_exited'] and finish['exit_code_observed'] and finish['exit_code'] == 0, 'Apartment authoring/validation did not exit cleanly')
        require((proof['nodes'], proof['meshAssets'], proof['materialAssets'], proof['drawCount'], proof['colliderCount'], proof['textureAssets'], proof['unresolvedBuiltins']) == (760, 302, 302, 269, 33, 90, 5), 'Apartment saved asset coverage differs')
        require(proof['buildInvoked'] is proof['existingAssetsReplaced'] is proof['originalGameplayCopied'] is False, 'Assetization claimed replacing existing assets or original gameplay')
        require(len(proof['textures']) == 90 and all(row['rawSha256'] == row['persistedRawSha256'] for row in proof['textures']), 'Native compressed texture bytes were not preserved')
        require(proof['scenePath'] == 'Assets/Scenes/Apartment.unity' and proof['prefabPath'] == 'Assets/Apartment/Environment.prefab', 'Authored scene or prefab path differs')
        require(all(snapshot.get(row['path']) == (row['bytes'], row['sha256']) for row in proof['outputs']), 'Saved Apartment assets differ from actual build input snapshot')
    require(contract_rows(manifest['authoring']['receipt']['outputs']) == contract_rows(manifest['validation']['receipt']['outputs']), 'Fresh editor reload changed saved room assets')
    require(manifest['authoring']['process_exit']['pid'] != manifest['validation']['process_exit']['pid'], 'Scene validation did not use a distinct editor process')
    require(any(row['kind'] == 'saved-material-reference-validation-failed' for row in manifest['diagnostics']), 'Earlier material-reference validation failure was omitted')
    for diagnostic in manifest['diagnostics']:
        finish = read(root / 'diagnostics' / diagnostic['run'] / 'exit.json')
        require(diagnostic['formal_acceptance'] is False and finish == diagnostic['process_exit'] and finish['process_exited'] and finish['exit_code'] != 0, 'Earlier authoring failure was promoted to success')
        if diagnostic['kind'] == 'saved-material-reference-validation-failed':
            require(diagnostic.get('associated_authoring_run') and diagnostic['run'] != manifest['validation']['run'], 'Earlier failed material validation was conflated with accepted reload validation')
    build_files = manifest['build']['files']
    require(not any(Path(row['path']).name.lower() in {'gameassembly.dll', 'tuanjieplayer.dll'} or any(part.lower() == 'bepinex' for part in Path(row['path']).parts) for row in build_files), 'Original game runtime entered the formal package')
    assemblies = [row for row in build_files if Path(row['path']).name == 'Assembly-CSharp.dll']
    executables = [row for row in build_files if Path(row['path']).name == 'ManakaInteraction.exe']
    require(len(assemblies) == len(executables) == 1, 'Ambiguous formal runtime binary identities')
    runtime_rows = {}
    for phase in ['controlled', 'phase2']:
        proof = read(root / phase / 'proof.json')
        begin, finish = read(root / phase / 'process-start.json'), read(root / phase / 'process-exit.json')
        rows = runtime_rows[phase] = events(root / phase / 'events.jsonl.gz')
        require(proof == manifest['runtime'][phase] and proof['passed'] and proof['completed'] and proof['screenshotValidated'] and proof['unityVersion'] == '6000.6.7f1' and proof['unexpectedEngineErrors'] == 0, 'Formal runtime did not complete')
        require(begin['pid'] == finish['pid'] == proof['processId'] and finish['process_exited'] and finish['exit_code_observed'] and finish['exit_code'] == 0, 'Formal runtime OS lifetime differs')
        require(begin['assembly_sha256'] == assemblies[0]['sha256'] and begin['executable_sha256'] == executables[0]['sha256'], 'Launched standalone copy differs from formal build')
        authored = one(rows, 'authored_scene_loaded')['data']
        ready = one(rows, 'assets_ready')['data']
        require(authored['scenePath'] == 'Assets/Scenes/Apartment.unity' and authored['geometryCreatedAtRuntime'] is False and authored['mappedNodes'] == 760 and (authored['meshes'], authored['colliders'], authored['textures']) == (269, 33, 90), 'Runtime did not load the authored room')
        require((ready['meshes'], ready['colliders'], ready['texturesLoaded']) == (269, 33, 90) and ready['gameBehavioursCopied'] == 0, 'Runtime room asset count differs')
        require(authored['geometrySha256'] == manifest['authoring']['receipt']['geometrySha256'] and authored['sourceSha256'] == manifest['authoring']['receipt']['sourceSha256'], 'Runtime room provenance differs')
        require(proof['originalAnimatorController'] and proof['originalAnimatorAvatar'] and proof['animatorInitialized'] and (proof['animatorControllerName'], proof['animatorAvatarName']) == ('Player', 'ManustiaAvatar'), 'Original player controller/avatar was not retained')
        for field in ['screenshotPath'] + (['titleScreenshotPath'] if phase == 'phase2' else []):
            require(sha(root / phase / Path(proof[field]).name) == proof[field.replace('Path', 'Sha256')], 'Runtime screenshot digest differs')
    analyzer = runpy.run_path(str(HERE / 'interaction-acceptance-tools/verify_interaction.py'))
    # Keep deterministic public analysis identical in both modes; --inputs below
    # separately hashes the actual launched packages and their executable bytes.
    config = read(root / 'controlled-inputs.json')
    expected_runtime_sources = {path.relative_to(root).as_posix(): sha(path) for path in archived_sources if path.parent.name == 'Runtime'}
    require({row['path']: row['sha256'] for row in config['runtime_sources']} == expected_runtime_sources, 'Controlled analyzer source binding is incomplete')
    analysis = analyzer['build'](root / 'controlled-inputs.json', controlled=True)
    require(analysis == read(root / 'controlled-acceptance.json') and analysis['passed'] and analysis['controlled_subchain_only'] and not analysis['full_chain_accepted'] and not analysis['actual_unity_f_accepted'] and not analysis['input_origin']['physical_keyboard_measured'], 'Controlled result was changed or inflated to real keyboard acceptance')
    helper = runpy.run_path(str(HERE / 'verify-unity-editor.py'))
    saved_path = root / 'save.v1.json'
    saved, saved_sha = read(saved_path), sha(saved_path)
    save = helper['controlled_save'](runtime_rows['controlled'], manifest['runtime']['controlled'], analysis, saved, saved_sha, analyzer)
    cold = analyzer['check_cold'](runtime_rows['phase2'], manifest['runtime']['phase2'], read(root / 'phase2/process-start.json'), read(root / 'phase2/process-exit.json'), dict(analysis, save_verification=save), saved, saved_sha, inputs)
    require(cold['same_saved_bytes_verified'] and cold['component_exact_pose_before_physics'] and manifest['runtime']['controlled']['processGuid'] != manifest['runtime']['phase2']['processGuid'], 'Cold readback was not a fresh process with exact saved pose')
    if inputs:
        files(manifest['project_inputs'], HERE / 'UnityProject')
        files(build_files + [manifest['editor']] + manifest['private_logs'], Path())
        for row in manifest['authoring']['receipt']['inputs']:
            files([row], Path())
        for package in manifest['runtime']['packages']:
            files(package['files'], Path())
    return dict(status=STATUS, editor_version='6000.6.7f1', saved_scene_native_assets_verified=True, maintained_inputs=len(before['files']), source_and_scene_bytes_preserved=True, source_preservation_scope='The archived build-time input snapshot is immutable; current editable project equality is additionally required only by --inputs.', structure=structure, build_files=len(build_files), controlled_original_action=True, actual_keyboard_verified=False, full_chain_accepted=False, save=save, cold_readback=cold, known_unresolved_builtins=5, asset_degradation=analysis['asset_degradation'], new_native_queries=0)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--inputs', action='store_true')
    args = parser.parse_args()
    print(json.dumps(build(args.inputs), ensure_ascii=False, indent=2))
