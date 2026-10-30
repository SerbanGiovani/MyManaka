"""Archive both natural rounds without dropping failed callbacks or publishing save plaintext."""
import argparse,gzip,hashlib,json
from pathlib import Path
from analyze import HERE,ROUND_IDS,read,sha,projection
def dump(p,v):p.write_text(json.dumps(v,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
def main(finalize_plugins=False):
    b=read(HERE/'baseline.json');out=Path(b['output_root']);game=Path(b['game_root']);ids={x for pair in ROUND_IDS for x in pair};seen={}
    for n in ['rea-round1.json','rea-round2.json']:
        raw=(out/n).read_bytes();p=HERE/'raw';p.mkdir(exist_ok=True);(p/(n+'.gz')).write_bytes(gzip.compress(raw,mtime=0))
        for record in json.loads(raw)['records']:
            key=record['evidence_id']
            if key in seen:assert seen[key]==record,'Repeated Evidence identity changed'
            seen[key]=record
    records=[seen[x] for pair in ROUND_IDS for x in pair];assert len(records)==4;dump(HERE/'rea-runtime.json',dict(records=records));dump(HERE/'saved-files.json',dict(files=[projection(p) for p in sorted((out/'captures').glob('*.sd'))]))
    for n in ['managed.jsonl','paths.jsonl','engine.log']:(HERE/(n+'.gz')).write_bytes(gzip.compress((out/n).read_bytes(),mtime=0))
    post=dict(process=read(HERE/'close-receipt.json'),frida_closed_reported=True,frida_close_final_state='unknown',profile=[],preserved_test_profile=[],inputs=[],plugin_verification=dict(checked=finalize_plugins,restored=None,reason=None if finalize_plugins else 'Deferred until the independently running appearance batch restores the same original plugin paths.'))
    for key in ['profile','preserved_test_profile']:
        for x in b[key]:
            value=sha(x['path']);post[key].append(dict(path=x['path'],before=x['sha256'],after=value,unchanged=value==x['sha256']))
    for x in b['inputs']:post['inputs'].append(dict(path=x['path'],original_path=x['original_path'],sha256=sha(x['path']),unchanged=sha(x['path'])==x['sha256']==sha(x['original_path'])))
    if finalize_plugins:
        checks=[dict(path=x['path'],expected=x['sha256'],actual=sha(x['path'])) for x in b['plugins']];restored=all(x['expected']==x['actual'] for x in checks) and not list((game/'BepInEx/plugins').glob('*NaturalMissionObserver*.dll'));post['plugin_verification'].update(restored=restored,files=checks);assert restored,'Original plugin fingerprints not restored'
    dump(HERE/'post-state.json',post)
    manifest=dict(schema_version=1,natural_only=True,passive_only=True,user_input_driven=True,authority='passive-original-user-input-in-isolated-save-root',observation_complete=False,sessions=[dict(session_id=sid,pid=79816,state='running',closed_by_operator=True) for sid in ['a5c08cb5-1349-450c-a7a9-39bf85289fdc','6b9c9eca-58ae-45a1-bd34-a87069dd080d']],evidence_ids=[x for pair in ROUND_IDS for x in pair],plugin=dict(archived_path=str(out/'NaturalMissionObserver-completed.dll'),sha256=sha(out/'NaturalMissionObserver-completed.dll')),sources=[],outputs=[],scope='Round1 ten failed onLeave callbacks retained; round2 clean. The second route had incomplete positive progress, not an always-unmet condition. Initial slot0 was copied and never loaded.')
    first=next(r for r in records if r['evidence_id']==ROUND_IDS[0][0]);source=first['normalized_result'];assert source['source_sha256']==sha(HERE/'observe-round1.js')=='8dae018527b8660809ad33919a589f0aae0d24f02d1c484ab119b07dd728335e'
    manifest['archived_frida_sources']=[dict(evidence_id=first['evidence_id'],original_path=source['source_path'],path='observe-round1.js',sha256=source['source_sha256'])]
    for n in ['Observe.cs','build.ps1','observe-initial.js','observe-round1.js','observe.js','analyze.py','collect.py','test_analysis.py']:manifest['sources'].append(dict(path=n,sha256=sha(HERE/n)))
    for n in ['baseline.json','close-receipt.json','rea-runtime.json','saved-files.json','post-state.json']:manifest['outputs'].append(dict(path=n,sha256=sha(HERE/n)))
    manifest['ciphertexts']=[dict(path=f['path'],sha256=f['sha256'],bytes=f['bytes'],plaintext_sha256=f['plaintext_sha256'],typed_tree_sha256=f['typed_tree_sha256']) for f in read(HERE/'saved-files.json')['files']]
    for p in [HERE/(n+'.gz') for n in ['managed.jsonl','paths.jsonl','engine.log']]+sorted((HERE/'raw').glob('*.gz')):
        raw=gzip.decompress(p.read_bytes());manifest['outputs'].append(dict(path=p.relative_to(HERE).as_posix(),sha256=sha(p),uncompressed_bytes=len(raw),uncompressed_sha256=hashlib.sha256(raw).hexdigest()))
    dump(HERE/'manifest.json',manifest)
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--finalize-plugins',action='store_true');a=p.parse_args();main(a.finalize_plugins)
