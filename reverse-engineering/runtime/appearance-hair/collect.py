"""Retain only the complete final passive capture and protect previous snapshots."""
import gzip,json,hashlib
from pathlib import Path
from analyze import HERE,read,sha,projection
def dump(p,v):p.write_text(json.dumps(v,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
def main():
    b=read(HERE/'baseline.json');out=Path(b['output_root']);game=Path(b['game_root']);ids=['ev_dc31f0e398854cfe790631166f138858b9ab35e508661f180c024753a8fba70a','ev_517cda307fd48f07be7b05bc8fa10e055ce1ccbe50165a7b3423f724e76a8993'];records=[r for r in read(HERE/'.cache/rea-full.json')['records'] if r['evidence_id'] in ids];assert len(records)==2;dump(HERE/'rea-runtime.json',dict(records=records));dump(HERE/'saved-files.json',dict(files=[projection(p,[0,1]) for p in sorted((out/'captures').glob('*.sd'))]))
    for n in ['managed.jsonl','paths.jsonl','engine.log']:
        if not (HERE/(n+'.gz')).exists():(HERE/(n+'.gz')).write_bytes(gzip.compress((out/n).read_bytes(),mtime=0))
    post=dict(game_root=str(game),process=read(HERE/'close-receipt.json'),frida_closed=True,frida_close_final_state='unknown',profile=[],preserved_test_profile=[],inputs=[],plugins=[])
    for key in ['profile','preserved_test_profile']:
        for x in b[key]:
            after=sha(x['path']);post[key].append(dict(path=x['path'],before=x['sha256'],after=after,unchanged=after==x['sha256']))
    for x in b['inputs']:post['inputs'].append(dict(path=x['path'],original_path=x['original_path'],sha256=sha(x['path']),unchanged=sha(x['path'])==x['sha256']==sha(x['original_path'])))
    for x in b['plugins']:post['plugins'].append(dict(path=x['path'],sha256=sha(x['path']),unchanged=sha(x['path'])==x['sha256']))
    post['plugins_restored']=all(x['unchanged'] for x in post['plugins']) and not list((game/'BepInEx/plugins').glob('*AppearanceHairProbe*.dll'));dump(HERE/'post-state.json',post)
    manifest=dict(schema_version=1,natural_only=False,authority='controlled-original-save-load-initialize-callback',sessions=[dict(session_id='d3d33481-07d0-4568-9520-a61398a1a5ce',pid=48184,state='running',closed_by_operator=True)],evidence_ids=ids,plugin=dict(archived_path=str(out/'AppearanceHairProbe-completed.dll'),sha256=sha(out/'AppearanceHairProbe-completed.dll')),sources=[],outputs=[],scope='Hair types0/1, texture/color/shade, direct warm-initialization boundary and explicitly reconciled switching; not a natural title-load defect.')
    for n in ['Probe.cs','build.ps1','observe.js','run_cases.py','analyze.py','collect.py','test_analysis.py']:manifest['sources'].append(dict(path=n,sha256=sha(HERE/n)))
    for n in ['managed.jsonl.gz','paths.jsonl.gz','engine.log.gz']:
        raw=gzip.decompress((HERE/n).read_bytes());manifest['outputs'].append(dict(path=n,sha256=sha(HERE/n),uncompressed_bytes=len(raw),uncompressed_sha256=hashlib.sha256(raw).hexdigest()))
    dump(HERE/'manifest.json',manifest)
if __name__=='__main__':main()
