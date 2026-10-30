"""Archive frozen preset observations; defer shared plugin checks unless explicitly finalized."""
import argparse,gzip,hashlib,json
from pathlib import Path
from analyze import HERE,SESSION,IDS,read,sha,projection
def dump(path,value):path.write_text(json.dumps(value,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
def freeze(path,data):
    if path.exists():assert path.read_bytes()==data,'Frozen observation changed: '+str(path)
    else:path.write_bytes(data)
def collect(finalize_plugins=False):
    baseline=read(HERE/'baseline.json');out=Path(baseline['output_root']);game=Path(baseline['game_root']);raw=(out/'rea-runtime-full.json').read_bytes();bundle=json.loads(raw);records=[r for r in bundle['records'] if r['evidence_id'] in IDS]
    assert len(records)==2 and {r['evidence_id'] for r in records}==set(IDS)
    dump(HERE/'rea-runtime.json',dict(records=records));saved=dict(files=[projection(p) for p in sorted((out/'captures').glob('*.sd'))],baseline=projection(out/'baseline.sd'));dump(HERE/'saved-files.json',saved)
    (HERE/'raw').mkdir(exist_ok=True);freeze(HERE/'raw/rea-runtime-full.json.gz',gzip.compress(raw,mtime=0))
    for name in ['managed.jsonl','paths.jsonl','engine.log']:freeze(HERE/(name+'.gz'),gzip.compress((out/name).read_bytes(),mtime=0))
    # This child emitted this exact build with csc before installation; frozen Probe/build were not subsequently edited.
    archived=out/'SkinPresetProbe-completed.dll';emitted=HERE/'.cache/SkinPresetProbe.dll';expected='62452548d2d1ad7dfb4ccb5217e4908bf3e236ad9465b0c10eb5aa780d707910'
    assert sha(archived)==sha(emitted)==expected,'Completed DLL differs from the observed EmitOnly build'
    compile_receipt=dict(command='pwsh -NoProfile -File build.ps1 -EmitOnly',exit_code=0,emission_only=True,plugin=dict(path=str(emitted),sha256=expected),sources=[dict(path=n,sha256=sha(HERE/n)) for n in ['Probe.cs','build.ps1']])
    if (HERE/'compile-only.json').exists():assert read(HERE/'compile-only.json')==compile_receipt,'Frozen compile receipt changed'
    else:dump(HERE/'compile-only.json',compile_receipt)
    post=dict(game_root=str(game),process=read(HERE/'close-receipt.json'),frida_closed=True,frida_detached_reported=True,frida_close_final_state='unknown; last exported status running, subsequent detach confirmed by operator',profile=[],preserved_test_profile=[],inputs=[],plugins=[],plugins_finalized=finalize_plugins,plugins_restored=None)
    for key in ['profile','preserved_test_profile']:
        for item in baseline[key]:
            current=sha(item['path']);post[key].append(dict(path=item['path'],before=item['sha256'],after=current,unchanged=current==item['sha256']))
    for item in baseline['inputs']:
        current=sha(item['path']);original=sha(item['original_path']);post['inputs'].append(dict(path=item['path'],original_path=item['original_path'],sha256=current,unchanged=current==original==item['sha256']))
    for item in baseline['plugins']:
        current=sha(item['path']) if finalize_plugins else None;post['plugins'].append(dict(path=item['path'],before=item['sha256'],sha256=current,unchanged=current==item['sha256'] if finalize_plugins else None))
    if finalize_plugins:
        known={str(Path(x['path']).resolve()).casefold() for x in baseline['plugins']};post['extra_plugin_dlls']=[str(p) for p in (game/'BepInEx/plugins').rglob('*') if p.is_file() and p.suffix.lower()=='.dll' and str(p.resolve()).casefold() not in known];post['plugins_restored']=all(x['unchanged'] for x in post['plugins']) and not post['extra_plugin_dlls'];assert post['plugins_restored'],'Original plugins not restored; keep the batch deferred until final cleanup'
    dump(HERE/'post-state.json',post)
    manifest=dict(schema_version=1,natural_only=False,authority='controlled-original-save-load-skin-preset-consumers',sessions=[dict(session_id=SESSION,pid=21048,state='running',closed_by_operator=True,detached_reported=True)],evidence_ids=IDS,plugin=dict(archived_path=str(archived),sha256=sha(archived)),sources=[],outputs=[],scope='Only free=false skin presets0 and1, original master RGBA, free=true disturbance, native Load before explicit original broadcast, renderer-bound colors and recorded cleanup. Hidden window could not close normally; exact PID was stopped after cleanup and detach. No natural UI/cold reconstruction/physics claim.')
    for name in ['Probe.cs','build.ps1','observe.js','run_cases.py','analyze.py','collect.py','test_analysis.py','skin-preset-runtime.md']:manifest['sources'].append(dict(path=name,sha256=sha(HERE/name)))
    for name in ['managed.jsonl.gz','paths.jsonl.gz','engine.log.gz','raw/rea-runtime-full.json.gz']:
        data=gzip.decompress((HERE/name).read_bytes());manifest['outputs'].append(dict(path=name,sha256=sha(HERE/name),uncompressed_bytes=len(data),uncompressed_sha256=hashlib.sha256(data).hexdigest()))
    for name in ['baseline.json','close-receipt.json','compile-only.json','rea-runtime.json','saved-files.json','post-state.json']:manifest['outputs'].append(dict(path=name,sha256=sha(HERE/name)))
    manifest['raw_inputs']=[dict(path=str(out/'rea-runtime-full.json'),sha256=sha(out/'rea-runtime-full.json'))]+[dict(path=f['path'],sha256=f['sha256']) for f in saved['files']+[saved['baseline']]]
    manifest['reused_static']=[dict(path='../../salt/evidence/state-restore-tail/14602-06000cc1-procedure_pseudo_code.pseudocode.c',sha256=sha(HERE/'../../salt/evidence/state-restore-tail/14602-06000cc1-procedure_pseudo_code.pseudocode.c'))]
    dump(HERE/'manifest.json',manifest)
    return dict(captured_records=2,encrypted_files=2,baseline_independently_decoded=True,plugins_finalized=finalize_plugins,protected_inputs_unchanged=all(x['unchanged'] for key in ['profile','preserved_test_profile','inputs'] for x in post[key]))
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--finalize-plugins',action='store_true');a=p.parse_args();print(json.dumps(collect(a.finalize_plugins)))
