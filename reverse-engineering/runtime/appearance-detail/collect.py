"""Retain only the complete final passive capture and protect previous snapshots."""
import gzip,json,hashlib
from pathlib import Path
from analyze import HERE,read,sha,projection
def dump(p,v):p.write_text(json.dumps(v,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
def main():
    b=read(HERE/'baseline.json');out=Path(b['output_root']);game=Path(b['game_root']);ids=['ev_fe5ff3ed8540297660c74a1c2f8e39c604ad8fa393c3eb51c0e3eb6687f3df61','ev_534232a825d88d2a4892bd0695cef9daee8c98cbc69374558f360eeaab3a5a46'];records=[r for r in read(HERE/'.cache/rea-full.json')['records'] if r['evidence_id'] in ids];assert len(records)==2;dump(HERE/'rea-runtime.json',dict(records=records));dump(HERE/'saved-files.json',dict(files=[projection(p) for p in sorted((out/'captures').glob('*.sd'))]))
    for n in ['managed.jsonl','paths.jsonl','engine.log']:
        if not (HERE/(n+'.gz')).exists():(HERE/(n+'.gz')).write_bytes(gzip.compress((out/n).read_bytes(),mtime=0))
    post=dict(game_root=str(game),process=read(HERE/'close-receipt.json'),frida_closed=True,frida_close_final_state='unknown',profile=[],preserved_test_profile=[],inputs=[],plugins=[])
    for key in ['profile','preserved_test_profile']:
        for x in b[key]:
            after=sha(x['path']);post[key].append(dict(path=x['path'],before=x['sha256'],after=after,unchanged=after==x['sha256']))
    for x in b['inputs']:post['inputs'].append(dict(path=x['path'],original_path=x['original_path'],sha256=sha(x['path']),unchanged=sha(x['path'])==x['sha256']==sha(x['original_path'])))
    for x in b['plugins']:post['plugins'].append(dict(path=x['path'],sha256=sha(x['path']),unchanged=sha(x['path'])==x['sha256']))
    post['plugins_restored']=all(x['unchanged'] for x in post['plugins']) and not list((game/'BepInEx/plugins').glob('*AppearanceDetailProbe*.dll'));dump(HERE/'post-state.json',post)
    manifest=dict(schema_version=1,natural_only=False,authority='controlled-original-save-load-initialize-callback',sessions=[dict(session_id='fbe1931e-fd5d-4f6f-a8f0-05d55cf3651c',pid=69516,state='running',closed_by_operator=True)],evidence_ids=ids,plugin=dict(archived_path=str(out/'AppearanceDetailProbe-completed.dll'),sha256=sha(out/'AppearanceDetailProbe-completed.dll')),sources=[],outputs=[],scope='17 saved color/face/body fields, native reference/disturb/recovery and nonunit bone targets; not all custom-field equivalence.')
    for n in ['Probe.cs','build.ps1','observe.js','run_cases.py','analyze.py','collect.py','test_analysis.py','shape-indices.json']:manifest['sources'].append(dict(path=n,sha256=sha(HERE/n)))
    for n in ['managed.jsonl.gz','paths.jsonl.gz','engine.log.gz']:
        raw=gzip.decompress((HERE/n).read_bytes());manifest['outputs'].append(dict(path=n,sha256=sha(HERE/n),uncompressed_bytes=len(raw),uncompressed_sha256=hashlib.sha256(raw).hexdigest()))
    dump(HERE/'manifest.json',manifest)
if __name__=='__main__':main()
