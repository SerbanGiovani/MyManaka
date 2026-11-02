"""Read-only Unity6 editor, build, controlled action and cold-save provenance checks."""
import argparse
import gzip
import hashlib
import json
import re
import runpy
import struct
from pathlib import Path

HERE = Path(__file__).resolve().parent
STATUS = 'unity6-original-resource-controlled-action-save-restart-verified'


def read(path):
    return json.loads(path.read_text(encoding='utf-8-sig'))


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def require(condition, message):
    if not condition:
        raise ValueError(message)


def files(rows, base=HERE):
    for row in rows:
        path = base / row['path']
        require(path.stat().st_size == row['bytes'] and sha(path) == row['sha256'], 'Unity migration fingerprint differs: ' + str(path))
        if 'uncompressed_sha256' in row:
            raw = gzip.decompress(path.read_bytes())
            require(len(raw) == row['uncompressed_bytes'] and hashlib.sha256(raw).hexdigest() == row['uncompressed_sha256'], 'Unity migration compressed record differs')


def events(directory):
    return [json.loads(line) for line in gzip.decompress((directory / 'events.jsonl.gz').read_bytes()).decode('utf-8-sig').splitlines() if line.strip()]


def float_bits(value):
    return struct.unpack('<i', struct.pack('<f', value))[0]


def runtime_migration(configuration):
    contract = read(HERE / 'unity-project/runtime-migration.json')
    require(contract['schema_version'] == 1 and len(contract['sources']) == 9, 'Unity6 Runtime migration inventory differs')
    require(contract['id_width_bits'] == 64 and contract['legacy_schema_field_names_retained'] is True and contract['id_api'] == 'UnityEngine.Object.GetEntityId -> UnityEngine.EntityId.ToULong', 'Unity6 identity migration narrows or mislabels EntityId')
    old_directory = HERE / 'interaction-project/Assets/Runtime'
    new_directory = HERE / configuration['runtime_template']
    covered, destination_files, replacements = set(), {}, 0
    for row in contract['sources']:
        old_path, new_path = HERE / row['source'], HERE / row['destination']
        require(old_path.parent == old_directory and new_path.name == old_path.name and (new_directory / new_path.name).resolve() == new_path.resolve(), 'Migration source/destination is not the selected Runtime template')
        old, new = old_path.read_bytes(), new_path.read_bytes()
        require(len(old) == row['source_bytes'] and len(new) == row['destination_bytes'] and hashlib.sha256(old).hexdigest() == row['source_sha256'] and hashlib.sha256(new).hexdigest() == row['destination_sha256'], 'Runtime migration source fingerprint differs')
        count = old.count(b'.GetInstanceID()')
        require(count == row['get_instance_id_replacements'], 'Runtime identity replacement count differs')
        expected = old.replace(b'.GetInstanceID()', b'.EvidenceId()')
        split = bool(row['scene_identity_field_split'])
        require(split == (old_path.name == 'SceneAssets.cs'), 'Only SceneAssets identity fields may be widened')
        if split:
            before = b'        public int sourceAnimators, animatorControllerInstanceId, animatorAvatarInstanceId;'
            require(expected.count(before) == 1, 'Original SceneAssets identity declaration differs')
            following = expected.split(before, 1)[1]
            require(following.startswith((b'\r\n', b'\n')), 'Original SceneAssets declaration line ending differs')
            newline = b'\r\n' if following.startswith(b'\r\n') else b'\n'
            after = b'        public int sourceAnimators;' + newline + b'        public ulong animatorControllerInstanceId, animatorAvatarInstanceId;'
            expected = expected.replace(before, after)
        require(expected == new, 'Runtime migration changed more than the exact identity API/field substitutions')
        require(old_path.name not in covered, 'Duplicate migration source')
        covered.add(old_path.name)
        replacements += count
        destination_files[new_path.name] = row['destination_sha256']
    require(covered == {path.name for path in old_directory.glob('*.cs')}, 'Runtime migration omitted an old source')
    helper = contract['helper']
    helper_path = HERE / helper['path']
    require(helper_path.parent == new_directory and helper_path.name == 'UnityObjectIdentity.cs' and helper_path.stat().st_size == helper['bytes'] and sha(helper_path) == helper['sha256'], 'Entity identity helper differs')
    helper_text = helper_path.read_text(encoding='utf-8-sig')
    require('public static ulong EvidenceId(' in helper_text and 'UnityEngine.EntityId.ToULong(value.GetEntityId())' in helper_text and 'GetInstanceID' not in helper_text, 'Identity helper must preserve the complete unsigned EntityId')
    destination_files[helper_path.name] = helper['sha256']
    require({path.name for path in new_directory.glob('*.cs')} == set(destination_files), 'Selected Unity6 Runtime contains uncontracted sources')
    return dict(files=destination_files, identity_replacements=replacements, preserved_entity_id_bits=64)


def controlled_save(rows, proof, analysis, saved, saved_sha, analyzer):
    def one(kind):
        matches = [row for row in rows if row['kind'] == kind]
        require(len(matches) == 1, 'Missing/duplicate controlled save event: ' + kind)
        return matches[0]
    canonical, roundtrip, done = (one(kind) for kind in ['save_pose_canonicalized', 'save_roundtrip_verified', 'save_completed'])
    require(canonical['frame'] == roundtrip['frame'] == done['frame'] and done['frame'] > analysis['cycles'][-1]['movement_restored_frames'][0], 'Controlled save occurred before original event/CC recovery')
    canonical, roundtrip, done = canonical['data'], roundtrip['data'], done['data']
    source, disk = canonical['sourcePoseBits'], canonical['canonicalPoseBits']
    wanted = analyzer['pose_bits'](saved)
    wanted['bodyPaintRemaining'] = float_bits(saved['bodyPaintRemaining'])
    require(set(source) == set(disk) == set(wanted), 'Controlled save component schema differs')
    for field, axes in [('Position', 'xyz'), ('Rotation', 'xyzw')]:
        for axis in axes:
            key = field.lower() + '.' + axis
            require(source[key] == float_bits(canonical['source' + field][axis]) and disk[key] == float_bits(canonical['canonical' + field][axis]), 'Controlled save source/canonical pose fields differ from declared bits')
    normalized = [key for key in source if source[key] != disk[key]]
    require(all(source[key] == -(2**31) and disk[key] == 0 for key in normalized) and canonical['zeroSignNormalizations'] == len(normalized) and canonical['actorTransformModified'] is False, 'Controlled save changed nonzero bits or actor pose')
    require(roundtrip['sourcePoseBits'] == source and roundtrip['canonicalPoseBits'] == roundtrip['diskPoseBits'] == disk == wanted and roundtrip['exactCanonicalFloatBits'] and roundtrip['sameSceneAndWriter'] and not roundtrip['mismatches'], 'Controlled save float32 roundtrip failed')
    require(done['sourcePoseBits'] == source and done['canonicalPoseBits'] == done['diskPoseBits'] == disk and all(done['diskPoseBits'][key] == value for key, value in analyzer['pose_bits'](done).items()), 'Completed controlled save does not match its canonical pose')
    require(saved.get('schemaVersion') == 1 and saved.get('fileKind') == 'ReconstructedManakaSave' and saved['savedProcessGuid'] == done['processGuid'] == analysis['process_guid'] and saved['sceneKey'] == done['sceneKey'] and saved['revision'] == proof['saveRevision'] == done['revision'] == 1, 'Controlled save schema/writer/revision differs')
    require(saved_sha == proof['saveSha256'] == done['saveSha256'], 'Controlled save file digest differs')
    effect = analysis['cycles'][-1]['pickup_effects']
    items = [item for item in saved['inventory'] if item['id'] == effect['item_id']]
    require(effect == dict(item_id=10000, before=1, after=2, delta=1, target_inactive=True) and len(items) == 1 and items[0]['count'] == 2, 'Controlled pickup was not saved exactly once')
    return dict(saved_revision=1, saved_sha256=saved_sha, persisted_item_id=10000, persisted_item_quantity=2, keyboard_save_claim=False, source='automatic controlled-test save', normalized_zero_components=normalized)


def build(inputs=False):
    manifest = read(HERE / 'unity-editor-runtime.json')
    require(manifest['status'] == STATUS and manifest['editor_version'] == '6000.6.7f1', 'Unity migration is incomplete')
    files(manifest['sources'] + manifest['dependencies'] + manifest['outputs'])
    root = HERE / 'unity-editor-runtime'
    configuration = read(HERE / 'editor-settings.json')
    require(configuration['product'] == 'Unity' and configuration['editor_version'] == '6000.6.7f1' and Path(configuration['editor_path']) == Path(manifest['editor']['path']) and configuration['active_input_handler'] == 0 and configuration['render_pipeline'] == 'Built-in' and configuration['scripting_backend'] == 'Mono2x', 'Default editor/configuration does not select verified Unity6')
    migration = runtime_migration(configuration)
    created, creation_exit = read(root / 'creation/start.json'), read(root / 'creation/exit.json')
    require(creation_exit == manifest['creation']['process_exit'] and creation_exit['process_exited'] and creation_exit['exit_code'] == 0 and creation_exit['project_version_generated'] and created['pid'] == creation_exit['pid'], 'Formal Unity project creation failed')
    require(Path(created['editor']) == Path(manifest['editor']['path']) and created['product_version'].startswith('6000.6.7f1_'), 'Creation used a different editor')
    project_version = (root / 'creation/ProjectVersion.txt').read_text(encoding='utf-8-sig')
    require(re.search(r'^m_EditorVersion: 6000\.6\.7f1\s*$', project_version, re.M), 'Isolated project is not Unity6')
    build_start, build_exit = read(root / 'build/start.json'), read(root / 'build/exit.json')
    receipt = read(root / 'build/build-proof.json')
    require(receipt == manifest['build']['receipt'] and receipt['result'] == 'Succeeded' and receipt['errors'] == 0 and build_exit == manifest['build']['process_exit'] and build_exit['exit_code'] == 0 and build_exit['process_exited'] and build_exit['pid'] == build_start['pid'], 'Unity6 build did not exit successfully')
    require(Path(build_start['editor']) == Path(created['editor']) and Path(build_start['project']) == Path(created['project']) == Path(manifest['build']['project']) and build_start['product_version'].startswith('6000.6.7f1_'), 'Unity build/creation identity differs')
    if 'editor_identity' in build_start:
        require(build_start['editor_identity'] == manifest['editor'], 'Selected editor bytes differ from build receipt')
    require(build_start['settings']['sha256'] == sha(HERE / 'editor-settings.json'), 'Build did not use the current selected editor settings')
    require(build_start['runtime_migration']['sha256'] == sha(HERE / 'unity-project/runtime-migration.json'), 'Build did not snapshot the exact Runtime migration contract')
    input_settings = read(root / 'build/input-settings.json')
    project_configuration = read(root / 'build/project-configuration.json')
    require(input_settings['setting'] == 'activeInputHandler' and input_settings['after_value'] == 0 and project_configuration['active_input_handler'] == 0 and project_configuration['render_pipeline'] == 'Built-in' and project_configuration['editor_version'] == '6000.6.7f1', 'Legacy input/render-pipeline configuration differs')
    runtime_sources = set()
    editor_sources = set()
    for source in build_start['sources']:
        parts = Path(source['path']).parts
        relative = Path(*parts[parts.index('Assets'):])
        if relative.parts[1] == 'Runtime':
            current = HERE / configuration['runtime_template'] / relative.name
            require(relative.name in migration['files'] and source['sha256'] == migration['files'][relative.name], 'Unity6 build does not use the exact identity migration')
            runtime_sources.add(relative.name)
        else:
            require(relative.parts[1] == 'Editor' and relative.name == 'BuildMinimal.cs', 'Unexpected Unity build source')
            current = HERE / configuration['editor_template']
            editor_sources.add(relative.name)
        require(sha(root / 'build' / relative) == sha(current) == source['sha256'], 'Unity build-time source differs from archived/current source')
        if inputs:
            require(sha(Path(build_start['project']) / relative) == source['sha256'], 'Unity project imported source was updated after its snapshot')
    require(runtime_sources == set(migration['files']) and editor_sources == {'BuildMinimal.cs'} and len(build_start['sources']) == 11, 'Unity6 compiled source inventory differs')
    build_files = manifest['build']['files']
    require(not any(Path(item['path']).name.lower() in ['gameassembly.dll', 'tuanjieplayer.dll'] or any(part.lower() == 'bepinex' for part in Path(item['path']).parts) for item in build_files), 'Original game/Tuanjie dependency entered Unity6 package')
    require(any(Path(item['path']).name == 'UnityPlayer.dll' for item in build_files), 'Unity6 player library is absent')
    assemblies = [item for item in build_files if Path(item['path']).name == 'Assembly-CSharp.dll']
    require(len(assemblies) == 1, 'Ambiguous Unity6 gameplay assembly')
    old = read(HERE / 'interaction-runtime.json')
    require(assemblies[0]['sha256'] not in {item['sha256'] for item in old['managed_inspections']}, 'Old Tuanjie binary was substituted for a new Unity6 build')
    for phase in ['controlled', 'phase2']:
        proof = read(root / phase / 'proof.json')
        require(proof == manifest['runtime'][phase] and proof['unityVersion'] == '6000.6.7f1' and proof['passed'] and proof['completed'] and proof['screenshotValidated'] and proof['unexpectedEngineErrors'] == 0, 'Unity6 runtime phase did not pass')
        require(proof['originalAnimatorController'] and proof['originalAnimatorAvatar'] and proof['animatorInitialized'] and (proof['animatorControllerName'], proof['animatorAvatarName'], proof['animatorPath']) == ('Player', 'ManustiaAvatar', 'Manustia'), 'Original Animator/Avatar identity differs under Unity6')
        require((proof['geometryMeshes'], proof['geometryColliders'], proof['geometryTextures']) == (269, 33, 90) and proof['copiedGameBehaviours'] == 0 and not proof['originalShaderCompatibilityVerified'], 'Unity6 original-resource scope differs')
        start, end = read(root / phase / 'process-start.json'), read(root / phase / 'process-exit.json')
        require(start['pid'] == end['pid'] == proof['processId'] and end['process_exited'] and end['exit_code'] == 0 and start['assembly_sha256'] == assemblies[0]['sha256'], 'Unity6 process/build identity differs')
        executable = [item for item in build_files if Path(item['path']) == Path(start['executable'])]
        require(len(executable) == 1 and executable[0]['sha256'] == start['executable_sha256'], 'Unity6 executable receipt differs from package')
        for field in ['screenshotPath'] + (['titleScreenshotPath'] if phase == 'phase2' else []):
            require(sha(root / phase / Path(proof[field]).name) == proof[field.replace('Path', 'Sha256')], 'Unity6 screenshot digest differs')
    analyzer = runpy.run_path(str(HERE / 'interaction-acceptance-tools/verify_interaction.py'))
    control_config = read(root / 'controlled-inputs.json')
    require(all('.cache' not in (root / control_config[key]).resolve().parts for key in ['events', 'identity', 'start', 'exit', 'proof']), 'Unity6 controlled config depends on mutable cache records')
    # The deterministic analysis stage does not separately rehash live binaries;
    # --inputs below hashes the complete package and binds each receipt to it.
    analysis = analyzer['build'](root / 'controlled-inputs.json', controlled=True)
    require(analysis == read(root / 'controlled-acceptance.json') and analysis['passed'] and analysis['controlled_subchain_only'] and not analysis['actual_unity_f_accepted'] and not analysis['full_chain_accepted'] and not analysis['input_origin']['human_physical_attestation'] and not analysis['input_origin']['physical_keyboard_measured'], 'Unity6 controlled evidence was inflated or changed')
    controlled_proof = manifest['runtime']['controlled']
    require(controlled_proof['controlledInput'] and controlled_proof['keyboardSaveCommands'] == controlled_proof['keyboardSaveQuitCommands'] == 0, 'Controlled Unity6 run was promoted to actual keyboard saving')
    saved_path = root / 'save.v1.json'
    saved, saved_sha = read(saved_path), sha(saved_path)
    save = controlled_save(events(root / 'controlled'), controlled_proof, analysis, saved, saved_sha, analyzer)
    analysis_for_cold = dict(analysis, save_verification=save)
    cold = analyzer['check_cold'](events(root / 'phase2'), manifest['runtime']['phase2'], read(root / 'phase2/process-start.json'), read(root / 'phase2/process-exit.json'), analysis_for_cold, saved, saved_sha)
    require(cold['same_saved_bytes_verified'] and cold['component_exact_pose_before_physics'] and cold['cold_in_memory_inventory_quantity_observed'] is False and cold['persisted_item_quantity_in_independent_json'] == 2, 'Unity6 cold readback/persisted inventory scope differs')
    for diagnostic in manifest['diagnostics']:
        require(diagnostic['formal_acceptance'] is False, 'Earlier unavailable exit code was promoted to formal acceptance')
        failed_build = diagnostic['kind'] == 'compiler-failed-before-migration'
        directory = root / 'diagnostics' / (('build-' if failed_build else '') + diagnostic['run'])
        archived = read(directory / 'exit.json')
        require(archived == diagnostic['process_exit'], 'Earlier Unity startup diagnostic differs')
        if failed_build:
            require(archived['exit_code'] == 1 and archived['process_exited'] and archived['executable_exists'] is False and diagnostic['compiler_error'] == 'CS0619' and diagnostic['rejected_api'] == 'UnityEngine.Object.GetInstanceID()', 'Compiler failure was promoted to a successful migration')
            failed_start = read(directory / 'start.json')
            require(failed_start['pid'] == archived['pid'], 'Failed compiler lifecycle PID differs')
            for source in failed_start['sources']:
                parts = Path(source['path']).parts
                relative = Path(*parts[parts.index('Assets'):])
                require(sha(directory / relative) == source['sha256'], 'Failed compiler source snapshot differs')
        else:
            require(diagnostic['kind'] == 'creation-exit-unavailable' and archived['exit_code'] is None, 'Unavailable OS exit code was overwritten')
    if inputs:
        files(build_files + manifest['packaged_inputs'] + [manifest['editor']] + manifest['private_logs'], Path())
        for file in project_configuration['files']:
            files([file], Path())
    return dict(status=STATUS, editor_path=manifest['editor']['path'], editor_version='6000.6.7f1', build_files=len(build_files), runtime_migration=migration, controlled_original_action=True, actual_keyboard_verified=False, full_chain_accepted=False, save=save, cold_readback=cold, asset_degradation=analysis['asset_degradation'], new_native_queries=0, managed_subjects=[])


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--inputs', action='store_true')
    args = parser.parse_args()
    print(json.dumps(build(args.inputs), ensure_ascii=False, indent=2))
