"""Independently verify source-backed home menu dispatch, locks and cold state.

Reads captured evidence only. Test warps and simulated F/axes are explicitly
controlled setup; successful observations do not prove physical keyboard input.
"""
import argparse
import gzip
import hashlib
import json
import math
import runpy
import struct
from pathlib import Path

HERE = Path(__file__).resolve().parent
STATUS = 'home-interaction-controlled-save-cold-readback-verified'
KINDS = {'pc', 'closet'}


def require(condition, message):
    if not condition:
        raise ValueError(message)


def read(path):
    return json.loads(path.read_text('utf-8-sig'))


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def verify_files(rows, base=HERE):
    for row in rows:
        path = base / row['path']
        require(path.stat().st_size == row['bytes'] and sha(path) == row['sha256'], 'Home evidence fingerprint differs: ' + str(path))
        if 'uncompressed_sha256' in row:
            raw = gzip.decompress(path.read_bytes())
            require(len(raw) == row['uncompressed_bytes'] and hashlib.sha256(raw).hexdigest() == row['uncompressed_sha256'], 'Home compressed record differs')


def events(path):
    return [json.loads(line) for line in gzip.decompress(path.read_bytes()).decode('utf-8-sig').splitlines() if line.strip()]


def select(rows, kind):
    return [row for row in rows if row['kind'] == kind]


def one(rows, kind):
    found = select(rows, kind)
    require(len(found) == 1, 'Missing/duplicate event: ' + kind)
    return found[0]


def vector(value, names='xyz'):
    require(isinstance(value, dict) and all(key in value for key in names), 'Invalid vector')
    result = [value[key] for key in names]
    require(all(type(item) in {int, float} and math.isfinite(item) for item in result), 'Nonfinite vector')
    return result


def nonzero_axes(value):
    return math.hypot(*vector(value, 'xy')) > 1e-5


def distance(a, b):
    a, b = vector(a), vector(b)
    return math.hypot(a[0] - b[0], a[2] - b[2])


def same_floats(a, b, names):
    a, b = vector(a, names), vector(b, names)
    return all(struct.pack('<f', left) == struct.pack('<f', right) for left, right in zip(a, b))


def analyze_menus(rows, targets):
    """Require actual physics selection and menu-specific lock/recovery cycles."""
    by_id = {target['id']: target for target in targets}
    require(len(by_id) == len(targets) and {target['kind'] for target in targets} == KINDS | {'bed'}, 'Home target contract must identify PC, bed and closet')
    opens, closes = select(rows, 'home_menu_opened'), select(rows, 'home_menu_closed')
    require(opens and {row['data']['kind'] for row in opens} == KINDS, 'Not all home menus were actually opened')
    require(len({row['data']['serial'] for row in opens}) == len(opens), 'Duplicate menu serial')
    dispatches = [row for row in select(rows, 'home_interaction_dispatched') if row['data']['menuOpened']]
    require(len(dispatches) == len(opens), 'Dispatch/open counts differ')
    cycles = []
    for opened in opens:
        data = opened['data']; kind, serial = data['kind'], data['serial']
        require(data['inputEnabledBefore'] is True and data['inputEnabledAfter'] is False, 'Menu did not acquire the input lock')
        matches = [row for row in dispatches if row['frame'] == opened['frame'] and row['data']['kind'] == kind]
        require(len(matches) == 1, 'Menu opening lacks one matching same-frame F dispatch')
        dispatched = matches[0]; target_id = dispatched['data']['targetId']
        require(target_id in by_id and by_id[target_id]['kind'] == kind, 'Dispatch targets an unproven home object')
        require(dispatched['data']['sourcePathId'] == by_id[target_id]['sourcePathId'] and dispatched['data']['simulated'] is True, 'Source identity or controlled input provenance differs')
        attempts = [row for row in select(rows, 'interaction_attempt') if row['frame'] == opened['frame'] and row['data']['selectedTargetId'] == target_id and row['data']['accepted']]
        require(len(attempts) == 1 and attempts[0]['data']['fDown'] and attempts[0]['data']['simulated'], 'Menu did not use the shared controlled F edge path')
        entering = [row for row in select(rows, 'interaction_trigger') if row['frame'] <= opened['frame'] and row['data']['targetId'] == target_id]
        require(entering and entering[-1]['data']['phase'] == 'enter' and entering[-1]['data']['actualOverlap'] and entering[-1]['data']['otherIsPlayerController'], 'F dispatch lacks a live actual player CharacterController trigger enter')
        require(entering[-1]['data']['via'] == 'OnTriggerEnter', 'Candidate was not selected by a Unity trigger callback')
        endings = [row for row in closes if row['data']['serial'] == serial]
        require(len(endings) == 1, 'Missing/duplicate menu close')
        closed = endings[0]
        require(closed['data']['kind'] == kind and closed['frame'] >= opened['frame'] and closed['data']['inputEnabledAfter'] is True, 'Menu close did not restore the previously enabled input state')
        locks = [row for row in select(rows, 'home_lock_sample') if row['data']['sequence'] == serial and row['data']['kind'] == kind and opened['frame'] < row['frame'] < closed['frame']]
        require(locks and any(nonzero_axes(row['data']['axes']) for row in locks), 'Menu has no measured nonzero direction input while locked')
        for lock in locks:
            value = lock['data']
            require(value['inputEnabled'] is False and value['controllerMoveCalled'] is False and same_floats(value['positionBefore'], value['positionAfter'], 'xyz'), 'Menu input lock allowed controller movement')
        restored = [row for row in select(rows, 'home_movement_restored') if row['data']['sequence'] == serial and row['data']['kind'] == kind and row['frame'] > closed['frame']]
        post_save_pose_hold = False
        if not restored:
            # The final PC save deliberately freezes the saved pose for the cold
            # readback. It proves the close restored input, but contributes no
            # post-close movement claim; the preceding PC cycle must prove that.
            final = one(rows, 'home_controlled_verified')
            post_save_pose_hold = kind == 'pc' and serial == max(row['data']['serial'] for row in opens) and final['data']['finalMenuSerial'] == serial and closed['data'].get('reason') == 'controlled-finished'
            require(post_save_pose_hold, 'Closing the menu did not produce actual CC movement under input')
        else:
            require(any(row['data']['inputEnabled'] is True and row['data']['controllerMoveCalled'] is True and nonzero_axes(row['data']['axes']) and distance(row['data']['positionBefore'], row['data']['positionAfter']) > 1e-5 for row in restored), 'Closing the menu did not produce actual CC movement under input')
        cycles.append(dict(kind=kind, serial=serial, target_id=target_id, source_path_id=by_id[target_id]['sourcePathId'], trigger_frame=entering[-1]['frame'], f_frame=opened['frame'], closed_frame=closed['frame'], locked_samples=len(locks), resumed_samples=len(restored), final_saved_pose_held=post_save_pose_hold))
    require(len(closes) == len(opens), 'An unmatched home menu close was recorded')
    require({cycle['kind'] for cycle in cycles if cycle['resumed_samples'] > 0} == KINDS, 'Each active home menu kind needs actual post-close movement evidence')
    saves = [row for row in select(rows, 'home_menu_operation_completed') if row['data']['kind'] == 'pc' and row['data']['operation'] == 'save' and row['data']['success']]
    require(len(saves) >= 2, 'PC menu did not complete both initial and final successful saves')
    for completion in saves:
        serial = completion['data']['serial']
        beginning = [row for row in select(rows, 'home_menu_operation_started') if row['data']['serial'] == serial and row['data']['operation'] == 'save' and row['frame'] == completion['frame']]
        require(len(beginning) == 1 and len([row for row in select(rows, 'save_completed') if row['frame'] == completion['frame']]) == 1, 'PC operation is not bound to the actual save consumer')
    return dict(cycles=cycles, pc_menu_saves=len(saves), controlled_only=True, physical_keyboard_verified=False)


def verify_manifest(manifest, inputs=False):
    require(manifest['schema_version'] == 1 and manifest['status'] == STATUS, 'Home runtime record is incomplete')
    verify_files(manifest['sources'] + manifest['dependencies'] + manifest['outputs'])
    root = HERE / 'home-interaction-runtime'
    before, after = (read(root / 'build' / item) for item in ['sources-before.json', 'sources-after.json'])
    require(before['files'] == after['files'] == manifest['project_inputs'], 'Home build changed maintained inputs')
    snapshot = {row['path']: (row['bytes'], row['sha256']) for row in before['files']}
    require(len(snapshot) == len(before['files']), 'Duplicate build source paths')
    start, end, receipt = (read(root / 'build' / item) for item in ['start.json', 'exit.json', 'build-proof.json'])
    require(start == manifest['build']['start'] and end == manifest['build']['process_exit'] and receipt == manifest['build']['receipt'], 'Build archive and manifest disagree')
    require(start['pid'] == end['pid'] and end['process_exited'] and end['exit_code_observed'] and end['exit_code'] == 0 and end['sources_unchanged'] and not end['source_differences'], 'Home build lifetime/source preservation failed')
    require(receipt['result'] == 'Succeeded' and receipt['errors'] == 0 and receipt['unityVersion'] == '6000.6.7f1' and receipt['scenes'][0] == 'Assets/Scenes/Title.unity' and 'Assets/Scenes/Apartment.unity' in receipt['scenes'], 'Home build scene or engine contract differs')
    archived = [path for name in ['Assets', 'Packages', 'ProjectSettings'] for path in (root / 'build' / name).rglob('*') if path.is_file()]
    require({path.relative_to(root / 'build').as_posix() for path in archived} == {row['path'] for row in before['files'] if Path(row['path']).suffix in {'.cs', '.json', '.unity', '.prefab'}}, 'Source/scene archive is incomplete')
    for path in archived:
        require(snapshot[path.relative_to(root / 'build').as_posix()] == (path.stat().st_size, sha(path)), 'Archived source no longer matches the executed build')
    binary = [row for row in manifest['build']['files'] if Path(row['path']).name == 'Assembly-CSharp.dll']
    executable = [row for row in manifest['build']['files'] if Path(row['path']).name == 'ManakaInteraction.exe']
    require(len(binary) == len(executable) == 1, 'Ambiguous home package binaries')
    traces = {}
    for phase in ['controlled', 'resume']:
        begin, finish, proof = (read(root / phase / item) for item in ['process-start.json', 'process-exit.json', 'proof.json'])
        require(begin['pid'] == finish['pid'] == proof['processId'] and finish['process_exited'] and finish['exit_code_observed'] and finish['exit_code'] == 0, 'Home runtime lifecycle differs')
        require(proof == manifest['runtime']['proofs'][phase] and proof['completed'] and proof['passed'] and proof['screenshotValidated'] and proof['unexpectedEngineErrors'] == 0, 'Home runtime proof failed')
        require(begin['assembly_sha256'] == binary[0]['sha256'] and begin['executable_sha256'] == executable[0]['sha256'], 'Launched runtime binary differs from build')
        require(begin['declared_input_origin'] == 'controlled-unity-input' and proof['physicalKeyboardVerified'] is False, 'Controlled home run was promoted to physical keyboard proof')
        traces[phase] = events(root / phase / 'events.jsonl.gz')
        require(traces[phase] and all(row['processGuid'] == proof['processGuid'] for row in traces[phase]), 'Event stream merged multiple process identities')
        require(one(traces[phase], 'process_start')['data']['processId'] == begin['pid'], 'Runtime event process identity differs')
        authored = one(traces[phase], 'authored_scene_loaded')['data']
        require(authored['scenePath'] == 'Assets/Scenes/Apartment.unity' and authored['geometryCreatedAtRuntime'] is False, 'Home run did not load the authored scene')
        require(sha(root / phase / Path(proof['screenshotPath']).name) == proof['screenshotSha256'], 'Home screenshot fingerprint differs')
    contract = read(HERE / 'home-interaction-evidence/contract.json')
    targets = [dict(target, kind=target['key']) for target in contract['targets']]
    menus = analyze_menus(traces['controlled'], targets)
    bed_target = [target for target in targets if target['kind'] == 'bed']
    require(len(bed_target) == 1 and (bed_target[0]['serializedActiveSelf'] is False or bed_target[0]['allAncestorsActiveSelfSerialized'] is False), 'Inactive bed source boundary was lost')
    for phase in ['controlled', 'resume']:
        bed = one(traces[phase], 'home_bed_availability')['data']
        require(bed['targetId'] == bed_target[0]['id'] and bed['activeInHierarchy'] is False and bed['hasSleepConsumer'] is False, 'Bed was enabled or a sleep consumer invented')
    saved_path = root / 'save.v1.json'; saved = read(saved_path); saved_sha = sha(saved_path)
    require(saved['revision'] >= 2, 'Final saved state did not include the second PC save')
    writer = manifest['runtime']['proofs']['controlled']; reader = manifest['runtime']['proofs']['resume']
    require(writer['processGuid'] != reader['processGuid'] and saved['savedProcessGuid'] == writer['processGuid'], 'Cold readback reused the writing process')
    saves = select(traces['controlled'], 'save_completed')
    require(saves and saves[-1]['data']['saveSha256'] == saved_sha and saves[-1]['data']['revision'] == saved['revision'] == reader['saveRevision'] and reader['saveSha256'] == saved_sha, 'Cold process did not read the bytes from the last menu save')
    require(any(row['frame'] == saves[-1]['frame'] and row['data']['kind'] == 'pc' and row['data']['operation'] == 'save' and row['data']['success'] for row in select(traces['controlled'], 'home_menu_operation_completed')), 'Final saved state did not come through the PC menu')
    loaded = one(traces['resume'], 'saved_state_read')['data']; applied = one(traces['resume'], 'pose_applied_before_physics')['data']
    for name, axes in [('position', 'xyz'), ('rotation', 'xyzw')]:
        require(same_floats(saved[name], loaded[name], axes) and same_floats(saved[name], applied[name], axes), 'Cold pose did not survive exact float32 application')
    require(reader['exactAppliedPosition'] and reader['exactAppliedRotation'] and reader['loadedSavedProcessGuid'] == writer['processGuid'], 'Cold readback identity or exact-pose proof differs')
    skin_results = read(root / 'dependencies/results.json')
    require(skin_results == read(HERE.parent / 'runtime/skin-preset/results.json') and skin_results['authority'] == 'controlled-original-save-load-skin-preset-consumers', 'Independent original skin-master expectation differs')
    expected = {case['saved_fields']['CustomizeSkinColor']: case['expected_primary'] for case in skin_results['cases']}
    require(set(expected) == {0, 1}, 'Independent original master presets are incomplete')
    warm_appearance = [row for row in select(traces['controlled'], 'home_appearance_applied') if row['data']['reason'] != 'loaded-state']
    require({row['data']['skinPreset'] for row in warm_appearance} == {0, 1}, 'Both closet preset consumers were not exercised')
    for row in warm_appearance:
        require(any(operation['frame'] == row['frame'] and operation['data']['kind'] == 'closet' and operation['data']['operation'] == 'closet' and operation['data']['success'] for operation in select(traces['controlled'], 'home_menu_operation_completed')), 'Appearance was not produced by a successful closet menu consumer')
    cold_appearance = [row for row in select(traces['resume'], 'home_appearance_applied') if row['data']['reason'] == 'loaded-state']
    require(len(cold_appearance) == 1, 'Cold loaded state did not produce one actual appearance application')
    for row in warm_appearance + cold_appearance:
        data = row['data']; preset = data['skinPreset']
        require(data['skinFree'] is False and preset in expected and data['bodySlot'] == 1 and data['faceSlot'] == 2, 'Appearance consumer preset/renderer-slot contract differs')
        require(data['bodyShader'] == 'Standard' and data['faceShader'] == 'Standard' and data['originalSecondaryShadeApplied'] is False, 'Partial Standard material consumer was promoted to original shader equivalence')
        for field in ['expectedPrimary', 'actualBodyPrimary', 'actualFacePrimary']:
            value = data[field]
            rgba = vector(value, 'rgba') if isinstance(value, dict) else value
            require(isinstance(rgba, list) and len(rgba) == 4 and all(type(component) in {int, float} and math.isfinite(component) and abs(component - reference) <= 1e-6 for component, reference in zip(rgba, expected[preset])), 'Actual material primary RGBA differs from independent original master: ' + field)
    saved_custom = saved['customization']; state_readback = one(traces['resume'], 'home_state_readback')['data']
    require(saved_custom['skinFree'] is False and saved_custom['skinPreset'] == 1 and state_readback['skinFree'] is False and state_readback['skinPreset'] == 1 and cold_appearance[0]['data']['skinPreset'] == 1, 'Saved preset1/free=false did not survive cold state and material initialization')
    if inputs:
        verify_files(manifest['project_inputs'], HERE / 'UnityProject')
        verify_files(manifest['build']['files'] + [manifest['editor']] + manifest['private_logs'], Path())
        for package in manifest['runtime']['packages']:
            verify_files(package['files'], Path())
    return dict(status=STATUS, build_sources_unchanged=True, maintained_inputs=len(before['files']), menu_observations=menus, inactive_bed_preserved=True, fresh_process_readback=True, saved_revision=saved['revision'], saved_sha256=saved_sha, exact_float32_pose=True, closet_presets=[0, 1], cold_preset=1, actual_primary_colors_bound_to_original_master=True, original_secondary_shade_applied=False, controlled_only=True, physical_keyboard_verified=False, scope='Active PC/closet source trigger selection, menu locks and recovery, actual preset0/1 primary colors, PC-save and cold preset/pose/material readback. Serialized inactive bed remains unavailable; no sleep semantics, original shader/shade equivalence or physical keyboard reception is inferred.')


def build(inputs=False):
    return verify_manifest(read(HERE / 'home-interaction-runtime.json'), inputs)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--inputs', action='store_true')
    args = parser.parse_args()
    print(json.dumps(build(args.inputs), ensure_ascii=False, indent=2))
