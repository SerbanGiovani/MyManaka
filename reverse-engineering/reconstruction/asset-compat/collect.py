"""Preserve the two real Tuanjie compatibility probes, including their failures."""
import gzip
import hashlib
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
CACHE = HERE.parent / '.cache'


def digest(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def read(path):
    return json.loads(path.read_text(encoding='utf-8-sig'))


def main():
    sources = [HERE / 'Assets/Editor/CompatibilityProbe.cs', HERE / 'diagnostics/first-probe/CompatibilityProbe.cs', Path(__file__)]
    outputs, probes = [], []
    for number, target in [(1, HERE / 'diagnostics/first-probe'), (2, HERE / 'accepted-assets')]:
        directory = CACHE / ('compatibility-20261031-' + str(number))
        target.mkdir(parents=True, exist_ok=True)
        result, exited = read(directory / 'result.json'), read(directory / 'exit.json')
        assert exited['exit_code'] == 0 and exited['exited']
        assert result['modelsLoaded'] and result['playerLoaded'] and result['playerInstantiated'] and result['textureReadback']
        for name in ['result.json', 'start.json', 'exit.json', 'original-player.png', 'original-texture.png', 'editor.log']:
            raw = (directory / name).read_bytes()
            output = target / (name + '.gz' if name.endswith('.log') else name)
            output.write_bytes(gzip.compress(raw, mtime=0) if name.endswith('.log') else raw)
            record = dict(path=output.relative_to(HERE).as_posix(), bytes=output.stat().st_size, sha256=digest(output))
            if name.endswith('.log'):
                record.update(uncompressed_bytes=len(raw), uncompressed_sha256=hashlib.sha256(raw).hexdigest())
            outputs.append(record)
        probes.append(dict(run=number, result_path=(target / 'result.json').relative_to(HERE).as_posix(), exit_path=(target / 'exit.json').relative_to(HERE).as_posix(), source=sources[1 if number == 1 else 0].relative_to(HERE).as_posix()))
    first, second = [read(HERE / item['result_path']) for item in probes]
    assert not first['buildDataLoaded'] and any('Expected version: 2022.3.62t7' in e or '2022.3.62f2' in e for e in first['errors'])
    assert second['playerRenderReadback'] and second['renderDifferentPixels'] > 1000
    manifest = dict(schema_version=1, status='partial-original-resource-compatibility', editor_version=second['editorVersion'], probes=probes,
                    sources=[dict(path=p.relative_to(HERE).as_posix(), sha256=digest(p)) for p in sources], outputs=outputs,
                    inputs=[dict(path=first['modelsPath'], sha256=first['modelsSha256']), dict(path=first['buildDataPath'], sha256=first['buildDataSha256'])],
                    summary=dict(asset_names=second['assetNames'], transforms=second['playerTransforms'], skinned_renderers=second['skinnedRenderers'], mesh_renderers=second['meshRenderers'], missing_mono_slots=second['missingMonoSlots'], unsupported_material_shaders=second['unsupportedShaders'], texture_gpu_readback=second['textureReadback'], player_gpu_readback=second['playerRenderReadback'], original_build_data_load=False),
                    limitations=['Original behaviour scripts are missing; instantiated prefab is not a working original player.', 'Two original shader constant-buffer errors are preserved in each probe.', 'Original build data is not a directly loadable scene AssetBundle in this engine; original scene geometry needs a separate bridge.', 'First image had only 199 non-background pixels; second probe deliberately reframed the player and yielded 51037.'])
    (HERE / 'manifest.json').write_bytes((json.dumps(manifest, indent=2) + '\n').encode('utf8'))
    print(json.dumps(manifest['summary']))


if __name__ == '__main__':
    main()
