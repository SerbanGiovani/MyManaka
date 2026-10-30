"""Read-only provenance checks for the original-Animator keyboard reconstruction."""
import argparse
import gzip
import hashlib
import json
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
        require(sha(path) == row['sha256'], 'Locomotion fingerprint differs: ' + str(path))
        if 'uncompressed_sha256' in row:
            raw = gzip.decompress(path.read_bytes())
            require(hashlib.sha256(raw).hexdigest() == row['uncompressed_sha256'] and len(raw) == row['uncompressed_bytes'], 'Locomotion compressed record differs')


def build(inputs=False):
    manifest = read(HERE / 'locomotion-runtime.json')
    require(manifest['status'] == 'keyboard-original-animator-save-restart-verified', 'Keyboard/animation loop is incomplete')
    files(manifest['sources'] + manifest['dependencies'] + manifest['outputs'])
    native = read(HERE / 'locomotion-evidence/native-contract.json')
    require(sum(run['queries'] for run in native['runs']) == 23 and all(run['closed_without_error'] for run in native['runs']), 'Native REA sessions are incomplete')
    for observation in native['new_observations']:
        require(sha(Path(observation['evidence_path'])) == observation['evidence_file_sha256'], 'Native REA observation changed')
    identity = read(HERE / 'locomotion-evidence/original-controller.json')
    require(identity['controller']['state_machine_behaviours'] == [], 'Unexpected original state-machine behaviour dependency')
    probes = HERE / 'locomotion-runtime/probes'
    signed = read(probes / 'save-roundtrip-probe-20261031-2/result.json')
    stepped = read(probes / 'save-roundtrip-probe-20261031-3/result.json')
    fixed = read(probes / 'save-fix-probe-20261031-1/result.json')
    require(signed['randomCases'] == 9975 and signed['nativeLongFailures'] == 1 and signed['examples'][0]['bits'] == '80000000', 'Signed-zero serialization diagnosis differs')
    require(stepped['steppedYawCases'] == 360 and stepped['steppedYawBitMismatches'] == 65, 'Controlled turn/save failure reproduction differs')
    require(fixed['cases'] == 362 and fixed['negativeZeroCases'] == 66 and fixed['allWritesReadExact'] and fixed['allNumericValuesUnchanged'] and fixed['oldMinimumRead'] and fixed['failedRoundRead'] and not fixed['exception'], 'Exact canonical save regression failed')
    runtime = manifest['runtime']
    for name, phase in [('keyboard', 'keyboard'), ('restart', 'phase2')]:
        proof = runtime[name]
        require(proof == read(HERE / 'locomotion-runtime' / phase / 'proof.json'), 'Archived runtime/proof differs')
        require(proof['passed'] and proof['completed'] and proof['originalAnimatorController'] and proof['animatorInitialized'], 'Original Animator did not run')
        require(proof['animatorControllerName'] == 'Player' and proof['animatorAvatarName'] == 'ManustiaAvatar' and proof['animatorPath'] == 'Manustia', 'Original Animator references differ')
        require(proof['geometryMeshes'] == 269 and proof['geometryColliders'] == 33 and proof['geometryTextures'] == 90, 'Original room resources differ')
        require(proof['degradedAssetCompatibility'] and not proof['originalShaderCompatibilityVerified'], 'Original resource limitations were hidden')
    receipt = manifest['build']['receipt']
    require(receipt['result'] == 'Succeeded' and receipt['errors'] == 0 and manifest['build']['process_exit']['exit_code'] == 0, 'New player build failed')
    build_files = manifest['build']['files']
    require(not any(Path(item['path']).name.lower() == 'gameassembly.dll' or 'bepinex' in item['path'].lower() for item in build_files), 'Original native game dependency entered package')
    subjects = []
    for inspection in manifest['managed_inspections']:
        require(inspection['sha256'], 'Missing inspected managed identity')
        subjects.append(inspection['sha256'])
        if inputs:
            require(sha(Path(inspection['path'])) == inspection['sha256'], 'Inspected player assembly changed')
    if inputs:
        files(build_files + manifest['packaged_inputs'], Path())
        for item in [native['native'], native['metadata'], identity['models']]:
            require(sha(Path(item['path'])) == item['sha256'], 'Original locomotion evidence input changed')
    return dict(status=manifest['status'], managed_subjects=subjects, new_native_queries=23, formal_original_animator=True, signed_zero_regression_cases=fixed['cases'], build_files=len(build_files))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--inputs', action='store_true')
    args = parser.parse_args()
    print(json.dumps(build(args.inputs), indent=2))
