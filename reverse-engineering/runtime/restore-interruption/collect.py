"""Package successful controlled observations separately from the partial crash run."""
import gzip
import hashlib
import json
from pathlib import Path
from analyze import HERE,read,sha,require
def dump(p,v):p.write_text(json.dumps(v,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
def main():
    b=read(HERE/'baseline.json');game=Path(b['game_root']);out1=Path(b['output_root']);out2=Path(read(HERE/'second-run.json')['output_root']);out3=Path(read(HERE/'third-run.json')['output_root'])
    for source,name in [(out3/'title-managed.jsonl','managed.jsonl.gz'),(out3/'paths.jsonl','paths.jsonl.gz'),(game/'BepInEx/LogOutput.log','engine.log.gz')]:
        if not (HERE/name).exists():(HERE/name).write_bytes(gzip.compress(source.read_bytes(),mtime=0))
    ids={'ev_b4937701a555ce52ad767fb825cf503725231850452b7729f9e93a2d68de060a','ev_f1a0895852019c620c73d3a109f137c5c1073a43891475f5d227143e057a4ed3','ev_d98d20c2674f5ee4296239a5e042923325719e01c487548823102ad6426283b8','ev_9d8af919c575638107269e3450e3389e42cfcfe7603c9888b6e9f50865c8a94e','ev_7f31a255a57634290c87f37a289257cc9f4bebdbd8495e01511397d7402edcb0','ev_e9d997f1c423fcb2bb1ff7e5396fa7e72d89f33a50e19956323e942f3757189d','ev_abe7db29a0e8d2901cc09291dc59e79f5c8997816b841a26442bf9ff82a6cbf7'}
    selected=[r for r in read(HERE/'.cache/rea-title.json')['records'] if r['evidence_id'] in ids];require(len(selected)==7,'Missing canonical REA records');dump(HERE/'rea-runtime.json',dict(records=selected))
    post=dict(game_root=b['game_root'],clean_processes=[read(HERE/n) for n in ['close-receipt.json','title-close-receipt.json']],frida_closed=True,frida_close_final_state='unknown',profile=[],preserved_test_profile=[],inputs=[],plugins=[])
    for key in ['profile','preserved_test_profile']:
        for r in b[key]:
            after=sha(r['path']);post[key].append(dict(path=r['path'],before=r['sha256'],after=after,unchanged=after==r['sha256']))
    for r in b['inputs']:
        after=sha(r['path']);post['inputs'].append(dict(path=r['path'],original_path=r['original_path'],sha256=after,unchanged=after==r['sha256']==sha(r['original_path'])))
    for r in b['plugins']:post['plugins'].append(dict(path=r['path'],sha256=sha(r['path']),unchanged=sha(r['path'])==r['sha256']))
    post['plugins_restored']=all(r['unchanged'] for r in post['plugins']) and not list((game/'BepInEx/plugins').glob('*InterruptionProbe*.dll'))
    archives=[out1/'InterruptionProbe-v1.dll',out2/'InterruptionProbe-completed.dll',out3/'InterruptionProbe-completed.dll'];post['temporary_plugins']=[dict(archived_path=str(p),sha256=sha(p)) for p in archives];dump(HERE/'post-state.json',post)
    sessions=[dict(session_id=s,pid=p,state=state,closed_by_operator=True,authority=authority) for s,p,state,authority in [('8287aa0f-989b-491e-99a2-c1ceeddf1b08',59580,'detached','partial-crash-diagnostic'),('5666d254-8985-4689-82fb-365acb0008fc',74160,'running','controlled-temporary-owner'),('3193486b-af59-4423-981b-8c309b60be17',10064,'running','controlled-original-owner-title-exit')]]
    manifest=dict(schema_version=1,sessions=sessions,evidence_ids=sorted(ids),plugins=post['temporary_plugins'],sources=[],outputs=[],natural_only=False,authority='controlled-original-method-replay',diagnostic_boundary='PID59580 crashed with e06d7363 after four partial observations; cause unassigned, not counted as clean cases.',process_subject_boundary='REA subject null; PID/module paths and disk fingerprints supplement but do not attest process memory.')
    for name in ['Probe.cs','Probe-v1.cs','Probe-v2.cs','build.ps1','observe.js','observe-v2.js','observe-v3.js','observe-v4.js','analyze.py','collect.py','test_analysis.py']:
        manifest['sources'].append(dict(path=name,sha256=sha(HERE/name)))
    for prefix in ['','diagnostic-','clean-v3-']:
        for stem in ['managed.jsonl','paths.jsonl','engine.log']:
            name=prefix+stem+'.gz';raw=gzip.decompress((HERE/name).read_bytes());manifest['outputs'].append(dict(path=name,sha256=sha(HERE/name),uncompressed_bytes=len(raw),uncompressed_sha256=hashlib.sha256(raw).hexdigest()))
    dump(HERE/'manifest.json',manifest);print(json.dumps(dict(records=len(selected),plugins_restored=post['plugins_restored'])))
if __name__=='__main__':main()
