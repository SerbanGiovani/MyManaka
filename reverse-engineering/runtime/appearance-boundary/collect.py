"""Collect the frozen appearance run; finalize plugin fingerprints only after all runs stop."""
import argparse,gzip,hashlib,json
from pathlib import Path
from analyze import HERE,read,sha,projection

IDS=['ev_fe8dabd9375d80b33db473ad9fbf1fc38043228b26951d52e564ce681c9f582e','ev_2f8c36470678ff7d0dbd0d637a36613458d773440aae7f6ad4a3ef903980ea01']
def dump(path,value):path.write_text(json.dumps(value,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
def collect(finalize_plugins=False):
    baseline=read(HERE/'baseline.json');out=Path(baseline['output_root']);game=Path(baseline['game_root'])
    records=[r for r in read(out/'rea-runtime-full.json')['records'] if r['evidence_id'] in IDS]
    assert len(records)==2 and {r['evidence_id'] for r in records}==set(IDS)
    dump(HERE/'rea-runtime.json',dict(records=records));dump(HERE/'saved-files.json',dict(files=[projection(p) for p in sorted((out/'captures').glob('*.sd'))]))
    for name in ['managed.jsonl','paths.jsonl','engine.log']:
        data=gzip.compress((out/name).read_bytes(),mtime=0);path=HERE/(name+'.gz')
        if path.exists():assert path.read_bytes()==data,'Frozen appearance log changed: '+name
        else:path.write_bytes(data)
    post=dict(game_root=str(game),process=read(HERE/'close-receipt.json'),frida_closed=True,frida_close_final_state='unknown',profile=[],preserved_test_profile=[],inputs=[],plugins=[],plugins_finalized=finalize_plugins,plugins_restored=None)
    for key in ['profile','preserved_test_profile']:
        for p in baseline[key]:
            after=sha(p['path']);post[key].append(dict(path=p['path'],before=p['sha256'],after=after,unchanged=after==p['sha256']))
    for p in baseline['inputs']:
        current=sha(p['path']);original=sha(p['original_path']);post['inputs'].append(dict(path=p['path'],original_path=p['original_path'],sha256=current,unchanged=current==original==p['sha256']))
    for p in baseline['plugins']:
        post['plugins'].append(dict(path=p['path'],before=p['sha256'],sha256=sha(p['path']) if finalize_plugins else None,unchanged=sha(p['path'])==p['sha256'] if finalize_plugins else None))
    if finalize_plugins:
        known={str(Path(p['path']).resolve()).casefold() for p in baseline['plugins']}
        extra=[str(p) for p in (game/'BepInEx/plugins').rglob('*') if p.is_file() and p.suffix.lower()=='.dll' and str(p.resolve()).casefold() not in known]
        post['extra_plugin_dlls']=extra;post['plugins_restored']=all(p['unchanged'] for p in post['plugins']) and not extra
        assert post['plugins_restored'],'Plugins not finalized; do not claim appearance cleanup while another probe is installed'
    dump(HERE/'post-state.json',post)
    manifest=dict(schema_version=1,natural_only=False,authority='controlled-original-save-load-body-material-consumers',sessions=[dict(session_id='2f47ca4b-64dc-4bfc-a5ee-6f2b957df81e',pid=61804,state='running',closed_by_operator=True)],evidence_ids=IDS,plugin=dict(archived_path=str(out/'AppearanceBoundaryProbe-completed.dll'),sha256=sha(out/'AppearanceBoundaryProbe-completed.dll')),sources=[],outputs=[],scope='Selected persistent TattooDark2/BodyOil8 actual renderer materials. Shader/texture/colors/order restored by explicit original callback; no complete material graph, natural UI, timed paint or physics claim.')
    for name in ['Probe.cs','build.ps1','observe.js','run_cases.py','analyze.py','collect.py','test_analysis.py','appearance-boundary-runtime.md']:
        manifest['sources'].append(dict(path=name,sha256=sha(HERE/name)))
    for name in ['managed.jsonl.gz','paths.jsonl.gz','engine.log.gz']:
        data=gzip.decompress((HERE/name).read_bytes());manifest['outputs'].append(dict(path=name,sha256=sha(HERE/name),uncompressed_bytes=len(data),uncompressed_sha256=hashlib.sha256(data).hexdigest()))
    for name in ['baseline.json','compile-only.json','close-receipt.json','rea-runtime.json','saved-files.json','post-state.json']:
        manifest['outputs'].append(dict(path=name,sha256=sha(HERE/name)))
    manifest['raw_inputs']=[dict(path=str(out/'rea-runtime-full.json'),sha256=sha(out/'rea-runtime-full.json'))]+[dict(path=f['path'],sha256=f['sha256']) for f in read(HERE/'saved-files.json')['files']]
    dump(HERE/'manifest.json',manifest)
    return dict(captured_records=2,encrypted_files=3,plugins_finalized=finalize_plugins,protected_inputs_unchanged=all(p['unchanged'] for key in ['profile','preserved_test_profile','inputs'] for p in post[key]))
if __name__=='__main__':
    parser=argparse.ArgumentParser();parser.add_argument('--finalize-plugins',action='store_true');args=parser.parse_args();print(json.dumps(collect(args.finalize_plugins)))
