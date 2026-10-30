"""Validate exported files and emit the minimal runtime's relative-path manifest."""
import argparse
import hashlib
import json
import math
from pathlib import Path

HERE=Path(__file__).resolve().parent

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()

def validate(folder):
    geometry=folder/'Apartment.geometry.json';d=json.loads(geometry.read_text(encoding='utf8'));p=json.loads((folder/'Apartment.geometry-proof.json').read_text(encoding='utf8'))
    assert d['schemaVersion']==1 and d['sceneKey']=='Apartment' and d['sourceSha256']==p['source']['sha256']
    nodes=d['nodes'];meshes=d['meshes'];textures=d['textures'];outputs=[]
    for i,n in enumerate(nodes):
        assert -1<=n['parent']<len(nodes) and n['parent']!=i and -1<=n['mesh']<len(meshes)
        seen=set();j=i
        while j>=0:assert j not in seen;seen.add(j);j=nodes[j]['parent']
        assert type(n['active']) is bool and type(n['collider']) is bool and type(n['rendererEnabled']) is bool
        for name,keys in [('position','xyz'),('rotation','xyzw'),('scale','xyz')]:
            assert set(n[name])==set(keys) and all(type(x) in (int,float) and math.isfinite(x) for x in n[name].values())
        assert abs(sum(n['rotation'][k]**2 for k in 'xyzw')-1)<1e-4
    for m in meshes:
        assert len(m['triangles'])%3==0 and m['triangles'] and min(m['triangles'])>=0 and max(m['triangles'])<len(m['vertices'])
        for field,keys in [('vertices','xyz'),('normals','xyz'),('uv','xy')]:
            assert field=='vertices' or not m[field] or len(m[field])==len(m['vertices'])
            assert all(set(v)==set(keys) and all(math.isfinite(x) for x in v.values()) for v in m[field])
        assert -1<=m.get('texture',-1)<len(textures)
    for t in textures:
        file=Path(t['file']);assert not file.is_absolute() and '..' not in file.parts
        path=folder/file;assert path.stat().st_size==t['byteLength'] and sha(path)==t['sha256']
        assert t['width']>0 and t['height']>0 and t['mipCount']>0 and t['format'] in (10,12)
        outputs.append(dict(file=t['file'],bytes=path.stat().st_size,sha256=t['sha256']))
    assert p['renderersExported']==sum(n['rendererEnabled'] and n['mesh']>=0 for n in nodes)
    assert p['meshCollidersExported']+p['boxCollidersExported']==sum(n['collider'] and n['mesh']>=0 for n in nodes)
    assert p['albedoTexturesExported']==len(textures)
    assert p['triangles']==sum(len(m['triangles'])//3 for m in meshes)
    assert p['vertices']==sum(len(m['vertices']) for m in meshes)
    for file in ('Apartment.geometry.json','Apartment.geometry-proof.json'):
        path=folder/file;outputs.append(dict(file=file,bytes=path.stat().st_size,sha256=sha(path)))
    return d,p,outputs

def build(folder):
    d,p,outputs=validate(folder)
    runtime=dict(schemaVersion=1,scene=dict(key='Apartment',kind='geometry',geometry='Apartment.geometry.json',original=True,geometry_only=True,materials_approximate=True,sourceSha256=d['sourceSha256'],geometrySha256=sha(folder/'Apartment.geometry.json'),spawnPosition=dict(x=.33,y=-.00046,z=1.219),spawnRotation=dict(x=0,y=0,z=0,w=1)),player=dict(bundle='models.unity3d',asset='assets/zzz-externalencryptasset/player.prefab',kind='prefab',scale=1,sha256=p['modelsSchemaSource']['sha256']),scope='Original player resource plus an explicitly partial geometry reconstruction of the original Apartment. No original GameAssembly, gameplay scripts or complete-game equivalence.')
    manifest=dict(schemaVersion=1,parser=dict(path=str(HERE/'bridge_assets.py'),sha256=sha(HERE/'bridge_assets.py')),manifestBuilder=dict(path=str(Path(__file__)),sha256=sha(Path(__file__))),sources=[p['source'],p['modelsSchemaSource']],outputs=outputs,runtimeManifest=runtime,unresolvedBuiltinMeshReferences=len(p['builtinMeshReferences']),geometryScope=p['scope'],counts={k:p[k] for k in ('parsed3dTransforms','renderersExported','meshCollidersExported','boxCollidersExported','meshEntries','triangles','vertices','albedoTexturesExported','albedoRawBytes')},spawnBasis='Original Apartment position provided by the parent runtime investigation; no save patch. Identity heading is a reconstruction choice. Collider support must additionally be checked in the consuming runtime.')
    return runtime,manifest

if __name__=='__main__':
    a=argparse.ArgumentParser();a.add_argument('--folder',type=Path,default=HERE/'.cache');a.add_argument('--check',action='store_true');args=a.parse_args();runtime,manifest=build(args.folder)
    for path,value in ((args.folder/'roombridge.json',runtime),(HERE/'export-manifest.json',manifest)):
        if args.check:assert json.loads(path.read_text(encoding='utf8'))==value
        else:path.write_text(json.dumps(value,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(manifest['counts']))
