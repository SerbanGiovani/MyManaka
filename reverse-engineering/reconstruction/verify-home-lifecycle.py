"""Verify outstanding-close cancellation and recovery on an archived native host."""
import argparse
import json
import runpy
from pathlib import Path

HERE = Path(__file__).resolve().parent
STATUS = 'home-archived-host-lifecycle-runtime-verified'
COMMON = runpy.run_path(str(HERE / 'verify-home-runtime.py'))
require, read, sha = (COMMON[key] for key in ['require', 'read', 'sha'])
events, one, select, vector, same_floats = (COMMON[key] for key in ['events', 'one', 'select', 'vector', 'same_floats'])
verify_files = COMMON['verify_files']
ALLOWED_CHANGES = {'ManakaInteraction_Data/Managed/Assembly-CSharp.dll', 'ManakaInteraction_Data/StreamingAssets/Original/interactions.json'}


def rows_by_relative(rows):
    result = {row['relative_path']: row for row in rows}
    require(len(result) == len(rows), 'Duplicate archived-host file paths')
    return result


def analyze_runtime(root, host, proofs, contract):
    package = rows_by_relative(host['files'])
    assembly = package['ManakaInteraction_Data/Managed/Assembly-CSharp.dll']
    exe = package['ManakaInteraction.exe']
    traces = {}
    targets = [dict(target, kind=target['key']) for target in contract['targets']]
    targets_by_id = {target['id']: target for target in targets}
    for phase in ['controlled', 'resume']:
        begin, finish, proof = (read(root / phase / name) for name in ['process-start.json', 'process-exit.json', 'proof.json'])
        require(proof == proofs[phase] and proof['passed'] and proof['completed'] and proof['screenshotValidated'] and proof['unexpectedEngineErrors'] == 0, 'Archived-host runtime proof failed')
        require(begin['pid'] == finish['pid'] == proof['processId'] and finish['process_exited'] and finish['exit_code_observed'] and finish['exit_code'] == 0, 'Archived-host runtime lifetime differs')
        require(begin['assembly_sha256'] == assembly['sha256'] and begin['executable_sha256'] == exe['sha256'] and Path(begin['working_directory']) == Path(host['package']), 'Executed host/module identity differs')
        require(begin['declared_input_origin'] == 'controlled-unity-input' and proof['physicalKeyboardVerified'] is False, 'Simulated host input was promoted to physical keyboard proof')
        traces[phase] = events(root / phase / 'events.jsonl.gz')
        require(all(row['processGuid'] == proof['processGuid'] for row in traces[phase]), 'Runtime log merged process identities')
        require(one(traces[phase], 'process_start')['data']['processId'] == begin['pid'], 'Event/runtime PID differs')
        authored = one(traces[phase], 'authored_scene_loaded')['data']
        require(authored['scenePath'] == 'Assets/Scenes/Apartment.unity' and authored['geometryCreatedAtRuntime'] is False, 'Runtime did not use the unchanged native Apartment')
        require(sha(root / phase / Path(proof['screenshotPath']).name) == proof['screenshotSha256'], 'Runtime screenshot differs')
        registrations = select(traces[phase], 'interaction_target_registered')
        require({row['data']['targetId'] for row in registrations} == set(targets_by_id) and len(registrations) == len(targets), 'Natural home phase retained a fixture or omitted a source target')
        registered = {}
        for row in registrations:
            data = row['data']; target = targets_by_id[data['targetId']]; registered[data['targetId']] = data
            require(data['sourcePathId'] == target['sourcePathId'] and data['sourcePath'] == target['sourcePath'] and data['sourceScene'] == 'Apartment' and data['originalSource'] is True, 'Registered source node identity differs')
            require(data['fixtureRecreatedThisProcess'] is False and data['gameBehavioursCopied'] == 0, 'Native home node was replaced by a fixture')
            require(data['trigger']['shape'] == 'Sphere' and data['trigger']['isTrigger'] is True and abs(data['trigger']['radius'] - target['trigger']['radius']) <= 1e-6 and same_floats(data['trigger']['center'], target['trigger']['center'], 'xyz'), 'Reconstructed home trigger differs from source')
        pc, closet = registered['apartment-pc'], registered['apartment-closet']
        require(all(abs(value - .63) < 2e-6 for value in vector(pc['scale'])), 'PC source scale was lost to an empty visual fixture')
        require(COMMON['distance'](pc['position'], closet['position']) > 1, 'Distinct native PC/closet positions collapsed')
        bed_target = targets_by_id['apartment-bed']; bed = one(traces[phase], 'home_bed_availability')['data']
        require(bed_target['serializedActiveSelf'] is False or bed_target['allAncestorsActiveSelfSerialized'] is False, 'Inactive serialized bed boundary differs')
        require(bed['targetId'] == 'apartment-bed' and bed['activeInHierarchy'] is False and bed['hasSleepConsumer'] is False, 'Bed was enabled or a sleep consumer invented')
    menu_analysis = COMMON['analyze_menus'](traces['controlled'], targets)
    require(len(menu_analysis['cycles']) == 5, 'Lifecycle test did not include the extra cancellation menu cycle')
    cancelled = one(traces['controlled'], 'home_menu_close_cancelled')
    confirmed = one(traces['controlled'], 'home_cancel_verified')
    cancellation, confirmation = cancelled['data'], confirmed['data']
    require(cancellation['kind'] == 'closet' and cancellation['reason'] == 'component-disabled' and cancellation['serial'] == confirmation['serial'], 'Outstanding closet close was not cancelled by disabling its component')
    require(confirmation['waitedFrames'] == 7 and confirmed['frame'] - cancelled['frame'] == 7, 'Cancellation wait did not span the measured seven frames')
    require(cancellation['revision'] == confirmation['revisionBefore'] == confirmation['revisionAfter'], 'Cancelling an outstanding close changed the saved revision')
    cancel_cycle = [cycle for cycle in menu_analysis['cycles'] if cycle['serial'] == cancellation['serial']]
    require(len(cancel_cycle) == 1 and cancel_cycle[0]['kind'] == 'closet' and cancel_cycle[0]['closed_frame'] == cancelled['frame'] and cancel_cycle[0]['resumed_samples'] > 0, 'Cancelled menu did not close and restore actual CC movement')
    cancelled_closes = [row for row in select(traces['controlled'], 'home_menu_closed') if row['data']['serial'] == cancellation['serial']]
    require(len(cancelled_closes) == 1 and cancelled_closes[0]['data']['reason'] == 'component-disabled', 'Cancelled close completion reason differs')
    require(not any(row['data'].get('serial') == cancellation['serial'] for name in ['home_closet_autosave', 'home_menu_operation_started', 'home_menu_operation_completed', 'home_menu_operation_failed'] for row in select(traces['controlled'], name)), 'Cancelled close cycle produced an operation or deferred save')
    require(not any(cancelled['frame'] <= row['frame'] <= confirmed['frame'] for name in ['save_completed', 'save_failed', 'save_pose_canonicalized', 'save_roundtrip_verified', 'home_closet_autosave', 'home_menu_operation_started', 'home_menu_operation_completed', 'home_menu_operation_failed'] for row in select(traces['controlled'], name)), 'A save or operation ran during the disabled-menu observation window')
    autosaves = select(traces['controlled'], 'home_closet_autosave')
    closet_cycles = [cycle for cycle in menu_analysis['cycles'] if cycle['kind'] == 'closet' and cycle['serial'] != cancellation['serial']]
    require(len(autosaves) == len(closet_cycles) == 2, 'Closet five-frame saves are incomplete')
    require(all(cycle['f_frame'] > confirmed['frame'] for cycle in closet_cycles), 'Normal closet actions did not demonstrate reopening after the cancellation window')
    for cycle in closet_cycles:
        matching = [row for row in autosaves if row['data']['serial'] == cycle['serial']]
        require(len(matching) == 1, 'Duplicate/missing closet deferred save')
        row = matching[0]; data = row['data']
        require(data['delayFrames'] == 5 and data['actualFrame'] == row['frame'] == cycle['closed_frame'] and data['actualFrame'] - data['requestedFrame'] == 5 and data['success'] is True, 'Closet save did not execute exactly five frames later before closing')
        real_saves = [entry for entry in select(traces['controlled'], 'save_completed') if entry['frame'] == row['frame']]
        require(len(real_saves) == 1 and real_saves[0]['data']['revision'] == data['revision'], 'Deferred closet operation lacks actual save consumer/revision')
        requested = [entry for entry in select(traces['controlled'], 'home_menu_operation_completed') if entry['data']['serial'] == cycle['serial'] and entry['data']['operation'] == 'closet' and entry['data']['success']]
        require(len(requested) == 1 and requested[0]['frame'] == data['requestedFrame'], 'Deferred closet save is not bound to the selected menu action')
    saved_file = root / 'save.v1.json'; saved, saved_sha = read(saved_file), sha(saved_file)
    writer, reader = proofs['controlled'], proofs['resume']
    require(writer['processGuid'] != reader['processGuid'] and saved['savedProcessGuid'] == writer['processGuid'], 'Cold readback reused the writer')
    last_save = select(traces['controlled'], 'save_completed')[-1]
    require(last_save['data']['saveSha256'] == saved_sha and last_save['data']['revision'] == saved['revision'] == reader['saveRevision'] and saved['revision'] >= 4 and reader['saveSha256'] == saved_sha, 'Cold process did not read the final save bytes')
    require(any(row['frame'] == last_save['frame'] and row['data']['kind'] == 'pc' and row['data']['operation'] == 'save' and row['data']['success'] for row in select(traces['controlled'], 'home_menu_operation_completed')), 'Final save bypassed the PC menu')
    loaded, applied = one(traces['resume'], 'saved_state_read')['data'], one(traces['resume'], 'pose_applied_before_physics')['data']
    for field, axes in [('position', 'xyz'), ('rotation', 'xyzw')]:
        require(same_floats(saved[field], loaded[field], axes) and same_floats(saved[field], applied[field], axes), 'Cold pose differs at float32 precision')
    require(reader['exactAppliedPosition'] and reader['exactAppliedRotation'] and reader['loadedSavedProcessGuid'] == writer['processGuid'], 'Cold exact-pose/identity flags differ')
    skin = read(root / 'dependencies/skin-preset-results.json')
    require(skin == read(HERE.parent / 'runtime/skin-preset/results.json') and skin['authority'] == 'controlled-original-save-load-skin-preset-consumers', 'Original skin master expectation differs')
    expected = {case['saved_fields']['CustomizeSkinColor']: case['expected_primary'] for case in skin['cases']}
    require(set(expected) == {0, 1}, 'Original skin preset scope differs')
    warm = [row for row in select(traces['controlled'], 'home_appearance_applied') if row['data']['reason'] != 'loaded-state']
    cold = [row for row in select(traces['resume'], 'home_appearance_applied') if row['data']['reason'] == 'loaded-state']
    require({row['data']['skinPreset'] for row in warm} == {0, 1} and len(cold) == 1, 'Warm presets or cold application are incomplete')
    for row in warm:
        require(any(operation['frame'] == row['frame'] and operation['data']['operation'] == 'closet' and operation['data']['success'] for operation in select(traces['controlled'], 'home_menu_operation_completed')), 'Appearance bypassed the closet menu')
    for row in warm + cold:
        data = row['data']; preset = data['skinPreset']
        require(data['skinFree'] is False and preset in expected and (data['bodySlot'], data['faceSlot']) == (1, 2), 'Preset/actual renderer-slot scope differs')
        require(data['bodyShader'] == data['faceShader'] == 'Standard' and data['originalSecondaryShadeApplied'] is False, 'Partial primary colors were promoted to original shader/shade reconstruction')
        for field in ['expectedPrimary', 'actualBodyPrimary', 'actualFacePrimary']:
            rgba = vector(data[field], 'rgba')
            require(all(abs(value - reference) <= 1e-6 for value, reference in zip(rgba, expected[preset])), 'Actual primary RGBA differs from independent original master')
    state_readback = one(traces['resume'], 'home_state_readback')['data']
    require(saved['customization']['skinFree'] is False and saved['customization']['skinPreset'] == 1 and state_readback['skinFree'] is False and state_readback['skinPreset'] == cold[0]['data']['skinPreset'] == 1, 'Preset1 did not survive file/state/material cold initialization')
    return dict(menu_analysis=menu_analysis, pending_close_cancellation=dict(serial=cancellation['serial'], cancelled_frame=cancelled['frame'], checked_frame=confirmed['frame'], observed_disabled_frames=7, revision_before=confirmation['revisionBefore'], revision_after=confirmation['revisionAfter'], no_late_save_or_operation=True, actual_movement_restored=True, request_to_disable_frames_independently_measured=False), closet_five_frame_saves=[dict(serial=row['data']['serial'], requested_frame=row['data']['requestedFrame'], actual_frame=row['frame'], revision=row['data']['revision']) for row in autosaves], saved_revision=saved['revision'], saved_sha256=saved_sha, exact_float32_cold_pose=True, cold_primary_materials_match_original_master=True, inactive_bed_preserved=True, fixture_excluded=True, physical_keyboard_verified=False, original_shader_equivalence=False)


def verify_manifest(manifest, inputs=False):
    require(manifest['status'] == STATUS and manifest['unity_editor_build_performed'] is False and manifest['formal_unity_build_pending'] is True, 'Host result was promoted to a fresh Unity build')
    verify_files(manifest['sources'] + manifest['dependencies'] + manifest['outputs'])
    root = HERE / 'home-lifecycle-runtime'; host = read(root / 'host/host.json')
    require(host == manifest['host'] and host['status'] == 'archived-player-host-own-managed-module-prepared' and host['unity_editor_build_performed'] is False and host['compile_exit_code'] == 0, 'Managed compilation/host scope differs')
    baseline = read(HERE / 'formal-project-runtime.json')
    require(sha(HERE / 'formal-project-runtime.json') == host['baseline_manifest']['sha256'], 'Frozen native host identity differs')
    base, package = rows_by_relative(host['base_files']), rows_by_relative(host['files'])
    expected_base = {Path(row['path']).relative_to(Path(host['base'])).as_posix(): (row['bytes'], row['sha256']) for row in baseline['build']['files']}
    require({path: (row['bytes'], row['sha256']) for path, row in base.items()} == expected_base and set(base) == set(package) and len(base) == 256, 'Archived native host file closure differs')
    changes = {path for path in base if (base[path]['bytes'], base[path]['sha256']) != (package[path]['bytes'], package[path]['sha256'])}
    require(changes == set(host['changed_paths']) == ALLOWED_CHANGES, 'A native player/scene or undeclared package file was replaced')
    require(not any(Path(path).name.lower() == 'gameassembly.dll' for path in package), 'Original game native gameplay was copied into the host')
    for row in host['references']:
        path = Path(row['path']).relative_to(Path(host['base'])).as_posix()
        require(path in base and path.startswith('ManakaInteraction_Data/Managed/') and (row['bytes'], row['sha256']) == (base[path]['bytes'], base[path]['sha256']), 'Managed compiler reference is not from the frozen host')
    for row in host['sources']:
        archived = root / 'host/sources' / Path(row['path']).name
        require(archived.stat().st_size == row['bytes'] and sha(archived) == row['sha256'], 'Executed managed source snapshot differs')
    replacement = host['replacement_inputs']
    require(len(replacement) == 1 and replacement[0]['sha256'] == package['ManakaInteraction_Data/StreamingAssets/Original/interactions.json']['sha256'] == sha(root / 'host/interactions.json'), 'Packaged interaction contract differs from the replacement source')
    diagnostic = read(root / 'diagnostics/editor-license/exit.json')
    require(diagnostic['exit_code_observed'] and diagnostic['process_exited'] and diagnostic['exit_code'] == 198 and diagnostic['executable_exists'] is False, 'Failed licensed Editor build was promoted to success')
    failed = read(root / 'diagnostics/host1/process-exit.json')
    require(failed['process_exited'] and failed['exit_code'] != 0, 'Earlier failed managed-host attempt was omitted/promoted')
    result = analyze_runtime(root, host, manifest['runtime']['proofs'], read(HERE / 'home-interaction-evidence/contract.json'))
    if inputs:
        verify_files(host['sources'] + host['references'] + host['replacement_inputs'] + [host['compiler'], host['dotnet'], host['compiler_stdout'], host['compiler_stderr']] + host['base_files'] + host['files'] + manifest['private_logs'], Path())
    return dict(status=STATUS, unity_editor_build_performed=False, formal_unity_build_pending=True, compiler_exit_code_recorded=0, native_player_and_assets_unchanged=True, host_files=len(package), changed_paths=sorted(changes), controlled_runtime=result)


def build(inputs=False):
    return verify_manifest(read(HERE / 'home-lifecycle-runtime.json'), inputs)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--inputs', action='store_true')
    args = parser.parse_args()
    print(json.dumps(build(args.inputs), ensure_ascii=False, indent=2))
