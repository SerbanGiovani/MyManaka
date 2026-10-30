"""Read an original encrypted save into a bounded independent-runtime seed, without game execution."""
import argparse,hashlib,json,math,struct,sys
from pathlib import Path
HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[1]
sys.dont_write_bytecode=True
sys.path.insert(0,str(ROOT/'salt'))
import save_codec
DEFAULT_SOURCE=Path('E:/ManakaREA-NaturalGameplay/NaturalPaint/20261031-2/working-profile/SaveData/1.sd')
DEFAULT_SHA='c71c2bf5861903ccae6700dbfe6df5783804334df8582d13d7f2de5921ba3fa7'
def sha(path):
    with Path(path).open('rb') as f:return hashlib.file_digest(f,'sha256').hexdigest()
def value_sha(value):return hashlib.sha256(json.dumps(value,ensure_ascii=False,sort_keys=True,separators=(',',':')).encode('utf8')).hexdigest()
def dump(path,value):
    path.parent.mkdir(parents=True,exist_ok=True);path.write_bytes((json.dumps(value,ensure_ascii=False,indent=2,allow_nan=False)+'\n').encode('utf8'))
def f32(value):
    if type(value) not in [int,float] or not math.isfinite(value):raise ValueError('Nonfinite/non-numeric saved field')
    return struct.unpack('<f',struct.pack('<f',value))[0]
def vector(value,names):
    raw=value.strings()
    if set(raw)!=set(names):raise ValueError('Pose component schema differs')
    return {key:f32(raw[key]) for key in names}
def validate_destinations(source,output,manifest):
    source=Path(source).resolve();output=Path(output).resolve();manifest=Path(manifest).resolve()
    for target in [output,manifest]:
        if target==source or target.exists() and target.samefile(source):raise ValueError('Generated files must not replace the original cipher')
    if output==manifest or output.exists() and manifest.exists() and output.samefile(manifest):raise ValueError('Seed and manifest need separate output paths')
    return output,manifest
def project(source=DEFAULT_SOURCE,expected_sha=DEFAULT_SHA):
    source=Path(source).resolve();original=sha(source)
    if expected_sha and original!=expected_sha:raise ValueError('Original source cipher fingerprint differs')
    data=source.read_bytes();plain,tree,reader=save_codec.read(data,'unReRU821Drq83');roots=tree.strings();s=roots['GameStateData'].strings()['value'].strings();c=roots['PlayerCustomData'].strings()['value'].strings()
    if s['CurrentStageType']!=0:raise ValueError('Minimum bridge only supports original stage0 Apartment')
    position=vector(s['PlayerPosition'],['x','y','z']);rotation=vector(s['PlayerRotation'],['x','y','z','w'])
    if abs(sum(v*v for v in rotation.values())-1)>0.01:raise ValueError('Original saved rotation is not a Quaternion near unit length')
    inventory=[];seen=set()
    for item,count in s['ItemDict'].entries:
        if type(item) is not int or type(count) is not int or item<0 or count<0 or item in seen:raise ValueError('Original inventory key/count schema differs')
        seen.add(item);inventory.append(dict(id=item,count=count))
    custom=dict(height=c['CustomizeHeight'],hair=c['CurrentHair'],skinFree=c['CustomIsSkinColorFree'],skinPreset=c['CustomizeSkinColor'],skinR=c['CustomizeSkinColorR'],skinG=c['CustomizeSkinColorG'],skinB=c['CustomizeSkinColorB'])
    if type(s['IsActiveBodyPaintReusable']) is not bool or type(custom['skinFree']) is not bool:raise ValueError('Original boolean field schema differs')
    seed=dict(schemaVersion=1,fileKind='ReconstructedManakaSeed',sceneKey='Apartment',position=position,rotation=rotation,bodyPaintRemaining=f32(s['PlayerRemainBodyPaintTime']),bodyPaintReusable=s['IsActiveBodyPaintReusable'],inventory=sorted(inventory,key=lambda x:x['id']),customization=custom,sourceSaveSha256=original,savedProcessGuid='',revision=0,savedAtUtc='')
    if seed['bodyPaintRemaining']<0:raise ValueError('Negative original paint remainder')
    if sha(source)!=original:raise ValueError('Source changed during read-only projection')
    detail=dict(source_path=str(source),source_sha256=original,source_bytes=len(data),plaintext_sha256=hashlib.sha256(plain).hexdigest(),numeric_key_count=reader.numeric_key_count,slot=roots['SaveDataSlotIndex'].strings()['value'],source_stage=s['CurrentStageType'],stored_position=s['PlayerPosition'].strings(),stored_rotation=s['PlayerRotation'].strings(),runtime_position=position,runtime_rotation=rotation,inventory_entries=len(inventory),custom_fields_selected=list(custom),source_game_fields=len(s),source_custom_fields=len(c))
    return seed,detail
def main():
    p=argparse.ArgumentParser();p.add_argument('--source',type=Path,default=DEFAULT_SOURCE);p.add_argument('--expected-sha',default=DEFAULT_SHA);p.add_argument('--output',type=Path,default=HERE/'.cache/seed.json');p.add_argument('--manifest',type=Path,default=HERE/'seed-manifest.json');a=p.parse_args();a.output,a.manifest=validate_destinations(a.source,a.output,a.manifest);seed,detail=project(a.source,a.expected_sha)
    dump(a.output,seed)
    sources=[Path(__file__),ROOT/'salt/save_codec.py',ROOT/'reconstruction/minimal-project/Assets/Runtime/SaveBridge.cs']
    summary=dict(sceneKey=seed['sceneKey'],position=seed['position'],rotation=seed['rotation'],sourceSaveSha256=seed['sourceSaveSha256'],bodyPaintRemaining=seed['bodyPaintRemaining'],bodyPaintReusable=seed['bodyPaintReusable'],inventory_sha256=value_sha(seed['inventory']),customization_sha256=value_sha(seed['customization']),inventory_entries=len(seed['inventory']))
    manifest=dict(schema_version=1,authority='read-only-original-ES3-to-selected-independent-runtime-seed',codec=dict(envelope='AES-128-CBC',kdf='PBKDF2-HMAC-SHA1',iterations=100,iv_is_salt=True,payload='Bounded ES3 typed text grammar including numeric dictionary keys; no original object construction'),source=detail,selected_summary=summary,seed=dict(path=str(a.output.resolve()),sha256=sha(a.output),bytes=a.output.stat().st_size),sources=[dict(path=str(x.resolve()),sha256=sha(x)) for x in sources],source_unchanged=sha(a.source)==detail['source_sha256'],scope='Original read is offline only. Independent runtime writes version1 JSON to a separate profile. Apartment pose, quaternion, complete saved inventory and selected appearance/paint data are retained; original full-state/object restoration, visuals, physics and gameplay equivalence are not claimed.')
    dump(a.manifest,manifest);print(json.dumps(dict(seed=manifest['seed'],source_sha256=detail['source_sha256'],source_unchanged=manifest['source_unchanged'],scene=seed['sceneKey'])))
if __name__=='__main__':main()
