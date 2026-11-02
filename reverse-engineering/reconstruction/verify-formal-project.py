"""Read-only structure and serialized-reference checks for the maintained Unity project.

This checks files already on disk; it does not open Unity, import assets, repair
metadata, or promote a file check into a successful build/runtime claim.
"""
import argparse
import hashlib
import json
import re
from pathlib import Path

HERE = Path(__file__).resolve().parent
PROJECT = HERE / 'UnityProject'
GUID = re.compile(r'\bguid:\s*([0-9a-fA-F]{32})\b')
BUILTIN_GUIDS = {
    '00000000000000000000000000000000',
    '0000000000000000d000000000000000',
    '0000000000000000e000000000000000',
    '0000000000000000f000000000000000',
}


def require(condition, message):
    if not condition:
        raise ValueError(message)


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def fingerprint(path, project):
    return dict(path=path.relative_to(project).as_posix(), bytes=path.stat().st_size, sha256=sha(path))


def snapshot_project(project=PROJECT):
    """Snapshot maintained inputs; omit local caches and external model bytes only.

    The external models bundle remains a separately verified prepared input. Its
    .meta is included, so Unity references keep a stable identity after Prepare.
    """
    project = Path(project).resolve()
    paths = []
    for directory in ['Assets', 'Packages', 'ProjectSettings']:
        root = project / directory
        require(root.is_dir(), 'Missing formal project directory: ' + str(root))
        paths += [path for path in root.rglob('*') if path.is_file() and path.name != 'models.unity3d']
    return [fingerprint(path, project) for path in sorted(paths)]


def scan_project(project=PROJECT, inputs=False):
    project = Path(project).resolve()
    for folder in ['Assets', 'Packages', 'ProjectSettings']:
        require((project / folder).is_dir(), 'Missing formal project directory: ' + folder)
    for name in ['manifest.json', 'packages-lock.json']:
        require((project / 'Packages' / name).is_file(), 'Missing locked package configuration: ' + name)
    version = (project / 'ProjectSettings/ProjectVersion.txt').read_text('utf-8-sig')
    require(re.search(r'^m_EditorVersion: 6000\.6\.7f1\s*$', version, re.M), 'Formal project uses a different editor version')
    player = (project / 'ProjectSettings/ProjectSettings.asset').read_text('utf-8-sig')
    require(re.findall(r'^\s*activeInputHandler:\s*(\d+)\s*$', player, re.M) == ['0'], 'Formal project must preserve Legacy Input Manager')
    graphics = (project / 'ProjectSettings/GraphicsSettings.asset').read_text('utf-8-sig')
    require(re.search(r'^\s*m_CustomRenderPipeline:\s*\{fileID:\s*0\}\s*$', graphics, re.M), 'Formal project must preserve Built-in rendering')
    editor = (project / 'ProjectSettings/EditorSettings.asset').read_text('utf-8-sig')
    require(re.search(r'^\s*m_SerializationMode:\s*2\s*$', editor, re.M), 'Editable scenes and prefabs require Force Text serialization')

    assets = project / 'Assets'
    metas = sorted(assets.rglob('*.meta'))
    require(metas, 'Unity has not generated formal project metadata')
    guid_paths = {}
    for meta in metas:
        identifiers = GUID.findall(meta.read_text('utf-8-sig'))
        require(len(identifiers) == 1, 'Asset metadata must contain exactly one GUID: ' + str(meta))
        guid = identifiers[0].lower()
        require(guid not in BUILTIN_GUIDS, 'Project asset illegally claims a built-in GUID: ' + str(meta))
        require(guid not in guid_paths, 'Duplicate asset GUID: ' + str(meta))
        guid_paths[guid] = Path(str(meta)[:-5])
    for path in assets.rglob('*'):
        if path.suffix == '.meta':
            continue
        require(Path(str(path) + '.meta').is_file(), 'Unversionable asset identity; missing metadata: ' + str(path))

    # Serialized Unity files use GUID references for external assets and numeric
    # fileIDs for local objects. Preserve integers as text; never narrow pathIDs.
    references, scanned = set(), []
    for path in sorted(assets.rglob('*')):
        if not path.is_file() or path.suffix == '.meta':
            continue
        with path.open('rb') as stream:
            prefix = stream.read(16)
        if not prefix.startswith(b'%YAML'):
            continue
        text = path.read_text('utf-8-sig')
        found = {guid.lower() for guid in GUID.findall(text)}
        for guid in found:
            require(guid in BUILTIN_GUIDS or guid in guid_paths, 'Unresolved local serialized GUID in ' + path.relative_to(project).as_posix() + ': ' + guid)
            if guid not in BUILTIN_GUIDS:
                require(guid_paths[guid].exists(), 'Serialized reference resolves to an absent asset: ' + str(guid_paths[guid]))
        references.update(found - BUILTIN_GUIDS)
        scanned.append(path.relative_to(project).as_posix())

    settings = (project / 'ProjectSettings/EditorBuildSettings.asset').read_text('utf-8-sig')
    scene_rows = re.findall(r'- enabled:\s*(\d+)\s+path:\s*([^\r\n]+)\s+guid:\s*([a-fA-F0-9]{32})', settings)
    scenes = []
    for enabled, path, guid in scene_rows:
        scene_path = project / path.strip()
        require(scene_path.is_file(), 'Build configuration references an absent scene: ' + path)
        require(guid_paths.get(guid.lower()) == scene_path, 'Build scene GUID and asset metadata disagree: ' + path)
        scenes.append(dict(path=path.strip(), enabled=enabled == '1'))
    enabled_scenes = {row['path'] for row in scenes if row['enabled']}
    require({'Assets/Scenes/Title.unity', 'Assets/Scenes/Apartment.unity'} <= enabled_scenes, 'Both maintained scenes must be enabled for builds')
    require(scenes and scenes[0] == dict(path='Assets/Scenes/Title.unity', enabled=True), 'Title must be the first enabled startup scene')
    if inputs:
        model = assets / 'StreamingAssets/Original/models.unity3d'
        require(model.stat().st_size == 223101993 and sha(model) == '98621b2c4fa4f9de80f355fae5776ab17efc016bcc81c581bcd0917af4308367', 'Prepared original models bundle fingerprint differs')
    return dict(
        status='formal-unity-project-structure-and-text-references-consistent',
        editor_version='6000.6.7f1',
        project=str(project),
        maintained_input_files=len(snapshot_project(project)),
        asset_meta_guids=len(guid_paths),
        text_serialized_assets=len(scanned),
        referenced_local_guids=len(references),
        build_scenes=scenes,
        prepared_models_verified=inputs,
        scope='Disk structure and text GUID closure only; binary asset contents, Unity persistent references, build preservation and runtime behavior require their separate actual receipts.',
    )


def build(inputs=False):
    return scan_project(inputs=inputs)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--project', type=Path, default=PROJECT)
    parser.add_argument('--inputs', action='store_true')
    args = parser.parse_args()
    print(json.dumps(scan_project(args.project, args.inputs), ensure_ascii=False, indent=2))
