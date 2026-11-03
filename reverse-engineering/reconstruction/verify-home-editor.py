"""Verify a fresh Unity Editor build and the home-menu lifecycle/cold matrix.

The reusable lifecycle analyzer checks observed events only. A package descriptor
points to the fresh build's bytes; no archived-host replacement receipt is used.
"""
import argparse
import json
import runpy
from pathlib import Path

HERE = Path(__file__).resolve().parent
STATUS = 'home-unity-editor-build-lifecycle-cold-readback-verified'
COMMON = runpy.run_path(str(HERE / 'verify-home-runtime.py'))
LIFECYCLE = runpy.run_path(str(HERE / 'verify-home-lifecycle.py'))
require, read, sha, verify_files = (COMMON[name] for name in ['require', 'read', 'sha', 'verify_files'])


def archive_input(row):
    return row['path'].startswith('ProjectSettings/') or Path(row['path']).suffix in {'.cs', '.json', '.unity', '.prefab'}


def verify_manifest(manifest, inputs=False):
    require(manifest['schema_version'] == 1 and manifest['status'] == STATUS, 'Fresh Editor record is incomplete')
    require(manifest['unity_editor_build_performed'] is True and manifest['formal_unity_build_pending'] is False, 'Editor build scope was not explicitly declared')
    verify_files(manifest['sources'] + manifest['dependencies'] + manifest['outputs'])
    root = HERE / 'home-editor-runtime'
    before, after = (read(root / 'build' / name) for name in ['sources-before.json', 'sources-after.json'])
    require(before['files'] == after['files'] == manifest['project_inputs'], 'Fresh build changed authored input bytes')
    require(before['file_count'] == after['file_count'] == len(before['files']), 'Maintained source count differs')
    snapshot = {row['path']: (row['bytes'], row['sha256']) for row in before['files']}
    require(len(snapshot) == len(before['files']), 'Duplicate maintained input paths')
    start, end, receipt = (read(root / 'build' / name) for name in ['start.json', 'exit.json', 'build-proof.json'])
    require(start == manifest['build']['start'] and end == manifest['build']['process_exit'] and receipt == manifest['build']['receipt'], 'Actual Editor receipts differ from the manifest')
    require(start['pid'] == end['pid'] and start['process_handle_retained'] is True and end['process_exited'] and end['exit_code_observed'] and end['exit_code'] == 0, 'Editor build lacks a verified zero OS exit')
    require('-executeMethod' in start['arguments'] and 'ReconstructedManaka.Editor.ProjectBuild.Build' in start['arguments'], 'The fresh Editor process did not execute the non-overwriting project build entry')
    require(end['executable_exists'] and end['sources_unchanged'] and not end['source_differences'], 'Editor build did not preserve source/scene inputs')
    require(receipt['result'] == 'Succeeded' and receipt['errors'] == 0 and receipt['unityVersion'] == '6000.6.7f1', 'Unity BuildReport failed or uses another version')
    require(receipt['editor'] == 'Unity' and receipt['scriptingBackend'] == 'Mono2x' and receipt['renderPipeline'] == 'Built-in' and receipt['inputHandler'] == 0, 'Formal build backend/render/input differs')
    require(receipt['scenes'][0] == 'Assets/Scenes/Title.unity' and 'Assets/Scenes/Apartment.unity' in receipt['scenes'], 'Fresh build did not include the authored Title and Apartment')
    require(all(receipt[name] is False for name in ['createsScenes', 'savesScenes', 'copiesSources', 'rewritesSettings']), 'Build reports rewriting authored content')
    editor = manifest['editor']
    require(editor == start['editor_identity'] and Path(start['editor']) == Path(editor['path']), 'Editor executable identity is not the actually launched one')
    require(Path(editor['path']) == Path('H:/Unity Editor/6000.6.7f1/Editor/Unity.exe'), 'This receipt did not use the newly selected H: editor')
    require(Path(start['project']) == Path(manifest['project']) == Path(before['project']) == Path(after['project']), 'Editor input/project identities differ')
    version = (root / 'build/ProjectSettings/ProjectVersion.txt').read_text('utf-8-sig')
    require('m_EditorVersion: 6000.6.7f1' in version, 'Archived maintained project version differs')
    archived = [path for name in ['Assets', 'Packages', 'ProjectSettings'] for path in (root / 'build' / name).rglob('*') if path.is_file()]
    require({path.relative_to(root / 'build').as_posix() for path in archived} == {row['path'] for row in before['files'] if archive_input(row)}, 'Fresh build source/scene/settings archive is incomplete')
    for path in archived:
        require(snapshot[path.relative_to(root / 'build').as_posix()] == (path.stat().st_size, sha(path)), 'Archived source is not the source actually built')
    build_files = manifest['build']['files']
    base = Path(start['output'])
    package_rows = []
    for row in build_files:
        relative = Path(row['path']).relative_to(base).as_posix()
        package_rows.append(dict(row, relative_path=relative))
    require(len({row['relative_path'] for row in package_rows}) == len(package_rows), 'Duplicate fresh build file paths')
    require(not any(Path(row['path']).name.lower() in {'gameassembly.dll', 'tuanjieplayer.dll'} or any(part.lower() == 'bepinex' for part in Path(row['path']).parts) for row in build_files), 'Original game/native gameplay entered the fresh build')
    require(len([row for row in package_rows if row['relative_path'] == 'ManakaInteraction_Data/Managed/Assembly-CSharp.dll']) == 1, 'Fresh build managed assembly is ambiguous')
    models = [row for row in package_rows if row['relative_path'] == 'ManakaInteraction_Data/StreamingAssets/Original/models.unity3d']
    require(len(models) == 1 and models[0]['bytes'] == start['model']['bytes'] == 223101993 and models[0]['sha256'] == start['model']['sha256'] == '98621b2c4fa4f9de80f355fae5776ab17efc016bcc81c581bcd0917af4308367', 'Fresh build original model input differs')
    runtime_dirs = {str(Path(read(root / phase / 'process-start.json')['executable']).parent) for phase in ['controlled', 'resume']}
    require(len(runtime_dirs) == 1, 'Runtime phases did not use one exact fresh package')
    actual_package = Path(next(iter(runtime_dirs)))
    records = manifest['runtime']['packages']
    require(len(records) == 1 and Path(records[0]['directory']) == actual_package, 'Runtime package snapshot differs')
    launched = {Path(row['path']).relative_to(actual_package).as_posix(): (row['bytes'], row['sha256']) for row in records[0]['files']}
    built = {row['relative_path']: (row['bytes'], row['sha256']) for row in package_rows}
    require(launched == built, 'Launched package was replaced or differs from the actual fresh build')
    package = dict(files=package_rows, package=str(actual_package))
    result = LIFECYCLE['analyze_runtime'](root, package, manifest['runtime']['proofs'], read(HERE / 'home-interaction-evidence/contract.json'))
    if inputs:
        verify_files(manifest['project_inputs'], HERE / 'UnityProject')
        verify_files(build_files + [editor] + manifest['private_logs'], Path())
        verify_files(records[0]['files'], Path())
    return dict(status=STATUS, unity_editor_build_performed=True, formal_unity_build_pending=False, editor_path=editor['path'], editor_version='6000.6.7f1', build_exit_code=0, build_errors=receipt['errors'], build_warnings=receipt['warnings'], sources_and_scenes_preserved=True, maintained_inputs=len(before['files']), build_files=len(build_files), managed_replacement_used=False, controlled_runtime=result)


def build(inputs=False):
    return verify_manifest(read(HERE / 'home-editor-runtime.json'), inputs)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--inputs', action='store_true')
    args = parser.parse_args()
    print(json.dumps(build(args.inputs), ensure_ascii=False, indent=2))
