"""Retain only the complete final passive capture and protect previous snapshots."""
import gzip,json,hashlib
from pathlib import Path
from analyze import HERE,read,sha,projection
def dump(p,v):p.write_text(json.dumps(v,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
def main():
    b=read(HERE/'baseline.json');out=Path(b['output_root']);game=Path(b['game_root']);ids=['ev_5e3f3a27fb9da50ed8de0fd3ec8991b4ea74a261483333be6dce9ac1ddf4ebcb','ev_1b75b4499445bacf6e2e126c5c0ceba80ff9035b703dd03b2111417f702cb2aa'];records=[r for r in read(HERE/'.cache/rea-full.json')['records'] if r['evidence_id'] in ids];assert len(records)==2;dump(HERE/'rea-runtime.json',dict(records=records));dump(HERE/'saved-files.json',dict(files=[projection(p) for p in sorted((out/'captures').glob('*.sd'))]))
    for n in ['managed.jsonl','paths.jsonl','engine.log']:
        if not (HERE/(n+'.gz')).exists():(HERE/(n+'.gz')).write_bytes(gzip.compress((out/n).read_bytes(),mtime=0))
    post=dict(game_root=str(game),process=read(HERE/'close-receipt.json'),frida_closed=True,frida_close_final_state='unknown',profile=[],preserved_test_profile=[],inputs=[],plugins=[])
    for key in ['profile','preserved_test_profile']:
        for x in b[key]:
            after=sha(x['path']);post[key].append(dict(path=x['path'],before=x['sha256'],after=after,unchanged=after==x['sha256']))
    for x in b['inputs']:post['inputs'].append(dict(path=x['path'],original_path=x['original_path'],sha256=sha(x['path']),unchanged=sha(x['path'])==x['sha256']==sha(x['original_path'])))
    for x in b['plugins']:post['plugins'].append(dict(path=x['path'],sha256=sha(x['path']),unchanged=sha(x['path'])==x['sha256']))
    post['plugins_restored']=all(x['unchanged'] for x in post['plugins']) and not list((game/'BepInEx/plugins').glob('*MissionConsumersProbe*.dll'));dump(HERE/'post-state.json',post)
    manifest=dict(schema_version=1,natural_only=False,authority='controlled-original-mission-consumers-and-result-settlement',sessions=[dict(session_id='588dd000-6ec3-427a-81bb-2d0d275ecff0',pid=75008,state='running',closed_by_operator=True)],evidence_ids=ids,plugin=dict(archived_path=str(out/'MissionConsumersProbe-completed.dll'),sha256=sha(out/'MissionConsumersProbe-completed.dll')),sources=[],outputs=[],scope='Four controlled mission eligibility/progress/recreated-completion conditions plus native settlement; cloned required mask and temporary stage/stop coordination explicit; no natural mission/scene claim.')
    for n in ['Probe.cs','build.ps1','observe.js','run_cases.py','analyze.py','collect.py','test_analysis.py','diagnostics.json']:manifest['sources'].append(dict(path=n,sha256=sha(HERE/n)))
    for n in ['managed.jsonl.gz','paths.jsonl.gz','engine.log.gz']+[str(p.relative_to(HERE)).replace('\\','/') for p in sorted((HERE/'diagnostics').rglob('*.gz'))]:
        raw=gzip.decompress((HERE/n).read_bytes());manifest['outputs'].append(dict(path=n,sha256=sha(HERE/n),uncompressed_bytes=len(raw),uncompressed_sha256=hashlib.sha256(raw).hexdigest()))
    dump(HERE/'manifest.json',manifest)
if __name__=='__main__':main()
