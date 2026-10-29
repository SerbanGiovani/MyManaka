"""Freeze the closed natural title round without retaining game plaintext."""
import gzip
import json
from pathlib import Path
from analyze import HERE,read,sha,projection

def dump(p,v):p.write_text(json.dumps(v,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
def compress(source,destination):
    data=Path(source).read_bytes();(HERE/destination).write_bytes(gzip.compress(data,mtime=0))

def main():
    baseline=read(HERE/'baseline.json');out=Path(baseline['output_root']);profile=Path(baseline['profile_root']);game=Path(baseline['game_root'])
    bundle=read(HERE/'.cache/full-rea.json');ids={'ev_06a36b7fbb27a6a89daf34587f31da1d3759ec10a5da4a87185349e2f7068db4','ev_296597d5063ca4e2ba419a26cf96a23d1d23d61e473fa71c21016a413f03e969'}
    records=[r for r in bundle['records'] if r['evidence_id'] in ids];assert len(records)==2
    dump(HERE/'rea-runtime.json',dict(records=records))
    compress(out/'natural-title-state.jsonl','state.jsonl.gz');compress(out/'natural-title-natural.jsonl','paths.jsonl.gz')
    # BepInEx opens a fresh process log itself. The analyst never truncates it.
    compress(game/'BepInEx/LogOutput.log','engine.log.gz')
    post=dict(process=read(HERE/'close-receipt.json'),frida_closed=True,frida_final_state='unknown',profile=[],inputs=[],disposable_profile=[],plugin={})
    for r in baseline['profile']:
        after=sha(r['path']);post['profile'].append(dict(path=r['path'],before=r['sha256'],after=after,unchanged=after==r['sha256']))
    for r in baseline['inputs']:
        after=sha(r['path']);post['inputs'].append(dict(path=r['path'],original_path=r['original_path'],sha256=after,unchanged=after==r['sha256']==sha(r['original_path'])))
    for p in sorted(profile.rglob('*.sd')):post['disposable_profile'].append(dict(path=str(p),bytes=p.stat().st_size,sha256=sha(p)))
    restored=sha(game/'BepInEx/plugins/NaturalLoadObserver.dll');assert restored==baseline['prior_plugin']['sha256']
    post['plugin']=dict(installed_for_round_sha256=sha(HERE/'.cache/NaturalLoadObserver.dll'),restored_previous_sha256=restored,previous_plugin_restored=True)
    assert all(r['unchanged'] for r in post['profile']+post['inputs']) and post['process']['process_absent']
    assert projection((HERE/'.cache/natural-main-1.sd').read_bytes())==read(HERE/'saved-main.json')
    dump(HERE/'post-state.json',post)
    manifest=dict(schema_version=1,observation_complete=True,natural_only=True,passive_only=True,user_input_driven=True,
        input_boundary='Only slot1 is selected: initially absent main file; original NewGame then PC main save then title Continue. Controlled-origin slot0 exists in the directory but is never loaded.',
        sessions=[dict(session_id='31b7857c-f690-4b31-b674-c3fa568bcd8f',pid=4276,state='running',closed_by_operator=True)],
        evidence_ids=sorted(ids),sources=[],outputs=[])
    for name in ['Observe.cs','build.ps1','observe.js','analyze.py','collect.py','test_analysis.py']:
        manifest['sources'].append(dict(path=name,sha256=sha(HERE/name)))
    import hashlib
    for name in ['state.jsonl.gz','paths.jsonl.gz','engine.log.gz']:
        raw=gzip.decompress((HERE/name).read_bytes());manifest['outputs'].append(dict(path=name,sha256=sha(HERE/name),uncompressed_bytes=len(raw),uncompressed_sha256=hashlib.sha256(raw).hexdigest()))
    dump(HERE/'manifest.json',manifest)
    print(json.dumps(dict(records=len(records),user_files=len(post['profile']),inputs=len(post['inputs']),plugin_restored=True)))

if __name__=='__main__':main()
