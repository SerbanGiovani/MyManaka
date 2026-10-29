"""Retain only the complete final passive capture and protect previous snapshots."""
import gzip,json,hashlib
from pathlib import Path
from analyze import HERE,read,sha,projection
def dump(p,v):p.write_text(json.dumps(v,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
def main():
    b=read(HERE/'baseline.json');out=Path(b['output_root']);game=Path(b['game_root']);ids=['ev_cbc145c04ebb49c93edca2a681d95353651e7dd1d90d1a9484709099b2c1b7ce','ev_72545f6c857e03ae8b92f1dfe24f7604321dfe33a9b81dea5a07a86361d071f3'];records=[r for r in read(HERE/'.cache/rea-full.json')['records'] if r['evidence_id'] in ids];assert len(records)==2;dump(HERE/'rea-runtime.json',dict(records=records));dump(HERE/'saved-files.json',dict(files=[projection(p) for p in sorted((out/'captures').glob('*.sd'))]))
    for n in ['managed.jsonl','paths.jsonl','engine.log']:
        if not (HERE/(n+'.gz')).exists():(HERE/(n+'.gz')).write_bytes(gzip.compress((out/n).read_bytes(),mtime=0))
    post=dict(game_root=str(game),process=read(HERE/'close-receipt.json'),frida_closed=True,frida_close_final_state='unknown',profile=[],preserved_test_profile=[],inputs=[],plugins=[])
    for key in ['profile','preserved_test_profile']:
        for x in b[key]:
            after=sha(x['path']);post[key].append(dict(path=x['path'],before=x['sha256'],after=after,unchanged=after==x['sha256']))
    for x in b['inputs']:post['inputs'].append(dict(path=x['path'],original_path=x['original_path'],sha256=sha(x['path']),unchanged=sha(x['path'])==x['sha256']==sha(x['original_path'])))
    for x in b['plugins']:post['plugins'].append(dict(path=x['path'],sha256=sha(x['path']),unchanged=sha(x['path'])==x['sha256']))
    post['plugins_restored']=all(x['unchanged'] for x in post['plugins']) and not list((game/'BepInEx/plugins').glob('*StateConsumersProbe*.dll'));dump(HERE/'post-state.json',post)
    manifest=dict(schema_version=1,natural_only=False,authority='controlled-native-inventory-callback-and-skill-input',sessions=[dict(session_id='52ab9776-c9ce-43ea-94ec-a5d70b411133',pid=51012,state='running',closed_by_operator=True)],evidence_ids=ids,plugin=dict(archived_path=str(out/'StateConsumersProbe-completed.dll'),sha256=sha(out/'StateConsumersProbe-completed.dll')),sources=[],outputs=[],scope='Inactive inventory view callbacks and controlled skill17 input after original Save/Load. Natural clicks, paid learning and mission runtime not tested.')
    for n in ['Probe.cs','build.ps1','observe.js','run_cases.py','analyze.py','collect.py','test_analysis.py','observe-bootstrap.js','diagnostics.json']:manifest['sources'].append(dict(path=n,sha256=sha(HERE/n)))
    for n in ['managed.jsonl.gz','paths.jsonl.gz','engine.log.gz']:
        raw=gzip.decompress((HERE/n).read_bytes());manifest['outputs'].append(dict(path=n,sha256=sha(HERE/n),uncompressed_bytes=len(raw),uncompressed_sha256=hashlib.sha256(raw).hexdigest()))
    dump(HERE/'manifest.json',manifest)
if __name__=='__main__':main()
