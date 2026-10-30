"""Read-only provenance and cross-process save checks for the interaction reconstruction."""
import argparse
import gzip
import hashlib
import json
import struct
from pathlib import Path

HERE = Path(__file__).resolve().parent


def read(path):
    return json.loads(path.read_text(encoding='utf-8-sig'))


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def require(condition, message):
    if not condition:
        raise ValueError(message)


def files(rows, directory=HERE):
    for row in rows:
        path = directory / row['path']
        require(path.stat().st_size == row['bytes'] and sha(path) == row['sha256'], 'Interaction fingerprint differs: ' + str(path))
        if 'uncompressed_sha256' in row:
            raw = gzip.decompress(path.read_bytes())
            require(hashlib.sha256(raw).hexdigest() == row['uncompressed_sha256'] and len(raw) == row['uncompressed_bytes'], 'Interaction compressed record differs')


def events(directory):
    return [json.loads(line) for line in gzip.decompress((directory / 'events.jsonl.gz').read_bytes()).decode('utf-8-sig').splitlines() if line.strip()]


def bits(value):
    return struct.pack('<f', value)


def build(inputs=False):
    manifest = read(HERE / 'interaction-runtime.json')
    require(manifest['status'] == 'original-action-event-physical-recovery-save-restart-verified', 'Interaction reconstruction is incomplete')
    files(manifest['sources'] + manifest['dependencies'] + manifest['outputs'])
    evidence_root = HERE / 'interaction-evidence'
    evidence = read(evidence_root / 'manifest.json')
    files(evidence['outputs'], evidence_root)
    native = read(evidence_root / 'native-contract.json')
    require(sum(run['observations'] for run in native['runs']) == 6 and all(run['success'] and run['closed'] for run in native['runs']), 'REA native runs are incomplete')
    require(len(native['observations']) == 6, 'REA query count differs')
    root = HERE / 'interaction-runtime'
    runtime = manifest['runtime']
    managed = {item['sha256'] for item in manifest['managed_inspections']}
    require(len(managed) == 1, 'Managed inspections differ')
    for phase in ['interaction', 'phase2', 'controlled']:
        proof = read(root / phase / 'proof.json')
        require(proof == runtime[phase], 'Archived proof differs')
        require(proof['passed'] and proof['completed'] and proof['screenshotValidated'] and proof['unexpectedEngineErrors'] == 0, 'Runtime phase failed')
        if phase != 'controlled':
            require(proof['titleScreenshotValidated'], 'Physical/cold title screenshot failed')
        require(proof['originalAnimatorController'] and proof['originalAnimatorAvatar'] and proof['animatorInitialized'], 'Original Animator is absent')
        require((proof['animatorControllerName'], proof['animatorAvatarName'], proof['animatorPath']) == ('Player', 'ManustiaAvatar', 'Manustia'), 'Original Animator references differ')
        require((proof['geometryMeshes'], proof['geometryColliders'], proof['geometryTextures']) == (269, 33, 90), 'Original room resources differ')
        require(proof['degradedAssetCompatibility'] and not proof['originalShaderCompatibilityVerified'] and proof['copiedGameBehaviours'] == 0, 'Compatibility scope differs')
        start, end = read(root / phase / 'process-start.json'), read(root / phase / 'process-exit.json')
        require(start['pid'] == proof['processId'] and end['exit_code'] == 0 and start['assembly_sha256'] in managed, 'Process/build identity differs')
        for field in ['screenshotPath', 'titleScreenshotPath']:
            if phase == 'controlled' and field == 'titleScreenshotPath':
                continue  # This diagnostic bypasses the title, explicitly.
            image = root / phase / Path(proof[field]).name
            require(sha(image) == proof[field.replace('Path', 'Sha256')], 'Screenshot digest differs')
    physical, cold = runtime['interaction'], runtime['phase2']
    require(not physical['controlledInput'] and physical['simulatedAxisFrames'] == 0 and physical['keyboardSaveCommands'] == 1 and physical['keyboardSaveQuitCommands'] == 1, 'Physical run/save scope differs')
    require(physical['saveRevision'] == cold['saveRevision'] == 2 and physical['processGuid'] != cold['processGuid'] and cold['loadedSavedProcessGuid'] == physical['processGuid'], 'Cold readback lacks a different writer process')
    require(physical['saveSha256'] == cold['saveSha256'] == sha(root / 'save.v1.json'), 'Save changed during cold readback')
    saved, backup = read(root / 'save.v1.json'), read(root / 'save.v1.json.bak')
    require(saved['revision'] == 2 and backup['revision'] == 1 and saved['savedProcessGuid'] == physical['processGuid'], 'Save revisions differ')
    require(next(item['count'] for item in saved['inventory'] if item['id'] == 10000) == 2, 'Collected key was not persisted')
    require(saved['inventory'] == backup['inventory'], 'Inventory changed between F5 and F6')
    cold_events = events(root / 'phase2')
    readback = [item for item in cold_events if item['kind'] == 'readback_verified_before_physics']
    require(len(readback) == 1 and readback[0]['data']['previousProcess'] and readback[0]['data']['exactAppliedPosition'] and readback[0]['data']['exactAppliedRotation'], 'Pose not verified before physics')
    for field in ['position', 'rotation']:
        for key, value in saved[field].items():
            require(bits(value) == bits(readback[0]['data'][field][key]), 'Cold pose float32 bits differ')
    # The cold process identifies the same complete save bytes. Inventory=2 is
    # independently checked in that file; this trace does not expose a second
    # in-memory inventory snapshot, so do not claim that additional observation.
    loaded = [item for item in cold_events if item['kind'] == 'saved_state_read']
    require(len(loaded) == 1, 'Cold save load event missing')
    require(loaded[0]['data']['revision'] == 2, 'Runtime save revision differs')
    receipt = manifest['build']['receipt']
    require(receipt['result'] == 'Succeeded' and receipt['errors'] == 0 and manifest['build']['process_exit']['exit_code'] == 0, 'Player build failed')
    build_start = read(root / 'build/start.json')
    for source in build_start['sources']:
        original = Path(source['path'])
        parts = original.parts
        relative = Path(*parts[parts.index('Assets'):])
        archived = root / 'build' / relative
        current = HERE / 'interaction-project' / relative
        require(sha(archived) == sha(current) == source['sha256'], 'Build-time source snapshot differs from archived/current source')
    build_files = manifest['build']['files']
    assemblies = [item for item in build_files if Path(item['path']).name == 'Assembly-CSharp.dll']
    require(len(assemblies) == 1 and assemblies[0]['sha256'] in managed, 'Build manifest does not bind inspected runtime assembly')
    require(not any(Path(item['path']).name.lower() == 'gameassembly.dll' or 'bepinex' in item['path'].lower() for item in build_files), 'Original native dependency entered package')
    if inputs:
        files(build_files + manifest['packaged_inputs'], Path())
        files(evidence['inputs'], Path())
        for inspection in manifest['managed_inspections']:
            require(sha(Path(inspection['path'])) == inspection['sha256'], 'Inspected assembly changed')
    return dict(status=manifest['status'], managed_subjects=sorted(managed), new_native_queries=6, action_lock_scope='separate controlled process', cold_pose_readback=True, saved_inventory_10000=2, cold_inventory_scope='same save bytes loaded; no second in-memory count snapshot', build_files=len(build_files))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--inputs', action='store_true')
    args = parser.parse_args()
    print(json.dumps(build(args.inputs), indent=2))
