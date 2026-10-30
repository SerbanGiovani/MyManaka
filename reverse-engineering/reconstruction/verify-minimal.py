"""Read-only integrity and scope checks for the independently built minimum loop."""
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


def require(value, message):
    if not value:
        raise ValueError(message)


def verify_files(directory, rows):
    for row in rows:
        path = directory / row['path']
        require(sha(path) == row['sha256'], 'Fingerprint differs: ' + str(path))
        if 'uncompressed_sha256' in row:
            raw = gzip.decompress(path.read_bytes())
            require(len(raw) == row['uncompressed_bytes'] and hashlib.sha256(raw).hexdigest() == row['uncompressed_sha256'], 'Compressed evidence differs: ' + str(path))


def build(inputs=False):
    report = read(HERE / 'minimal-runtime.json')
    require(report['status'] == 'bounded-independent-loop-verified', 'Independent loop is incomplete')
    verify_files(HERE, report['sources'] + report['dependencies'] + report['outputs'])
    compatibility = read(HERE / 'asset-compat/manifest.json')
    verify_files(HERE / 'asset-compat', compatibility['sources'] + compatibility['outputs'])
    require(compatibility['status'] == 'partial-original-resource-compatibility', 'Compatibility scope was broadened')
    require(compatibility['summary']['missing_mono_slots'] == 596 and not compatibility['summary']['original_build_data_load'], 'Original asset limitations differ')
    archive = HERE / 'minimal-acceptance'
    for phase in ['phase1', 'phase2']:
        proof = read(archive / phase / 'proof.json')
        require(proof == report['acceptance'][phase], 'Archived/runtime proof differs')
        require(proof['passed'] and proof['completed'] and proof['screenshotValidated'] and proof['titleScreenshotValidated'], 'Minimum loop or actual pixels failed')
        require(proof['geometryMeshes'] == 269 and proof['geometryColliders'] == 33 and proof['geometryTextures'] == proof['declaredTextures'] == 90, 'Original geometry/texture acceptance differs')
        require(proof['unresolvedBuiltinMeshes'] == 5 and proof['visualRenderers'] == 4 and proof['playerShaderFallbacks'] == 11 and proof['copiedGameBehaviours'] == 0, 'Explicit reconstruction scope differs')
        require(proof['degradedAssetCompatibility'] and not proof['originalShaderCompatibilityVerified'], 'Degraded compatibility was hidden')
    receipt, exited = report['build']['receipt'], report['build']['process_exit']
    require(receipt['result'] == 'Succeeded' and receipt['errors'] == 0 and exited['process_exited'] and exited['exit_code'] == 0, 'Independent player build failed')
    files = report['build']['files']
    require(any(Path(row['path']).name == 'TuanjiePlayer.dll' for row in files), 'Independent engine player is absent')
    require(not any(Path(row['path']).name.lower() == 'gameassembly.dll' or 'bepinex' in row['path'].lower() for row in files), 'Original native game dependency entered the package')
    subjects = []
    for item in report['managed_inspections']:
        records = [read(path) for path in (HERE / 'asset-compat').glob('managed-inspection*-complete.json')]
        record = next(row for row in records if row['evidence_id'] == item['evidence_id'])
        require(record['subject']['digest']['sha256'] == item['sha256'], 'Inspected independent assembly identity differs')
        result = record['normalized_result']
        require(result['classification']['runtime_family'] == 'unity-mono' and result['classification']['implementation'] == 'cil' and result['coverage']['state'] == 'complete', 'Independent assembly admission failed')
        require(all(row['name'] == 'netstandard' or row['name'].startswith('UnityEngine.') for row in result['references']), 'Independent assembly references unexpected original game code')
        subjects.append(item['sha256'])
    if inputs:
        verify_files(Path(), files + report['packaged_inputs'] + [report['build']['editor']])
        for directory, rows in [(Path(), compatibility['inputs']), (Path(), read(HERE / 'asset-bridge/export-manifest.json')['sources'])]:
            verify_files(directory, rows)
        for item in report['managed_inspections']:
            require(sha(Path(item['path'])) == item['sha256'], 'Inspected assembly file changed')
    return dict(status=report['status'], managed_subjects=subjects, build_files=len(files), archived_outputs=len(report['outputs']), original_resource_compatibility='partial', formal_gpu_acceptance=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--inputs', action='store_true')
    args = parser.parse_args()
    print(json.dumps(build(inputs=args.inputs), indent=2))
