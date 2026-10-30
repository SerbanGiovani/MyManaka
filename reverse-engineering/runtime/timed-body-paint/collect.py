"""Archive a complete timed-paint run and retain both earlier diagnostic boundaries."""
import argparse,collections,gzip,hashlib,json
from pathlib import Path
from analyze import HERE,read,sha,projection,snapshot_diff
def dump(p,v):p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes((json.dumps(v,ensure_ascii=False,indent=2)+'\n').encode('utf8'))
def compress(source,target):
    data=gzip.compress(source.read_bytes(),mtime=0);target.parent.mkdir(parents=True,exist_ok=True)
    if target.exists():assert target.read_bytes()==data,'Frozen capture changed: '+str(source)
    else:target.write_bytes(data)
def collect(finalize_plugins=False):
    baseline=read(HERE/'baseline.json');session=read(HERE/'session.json');out=Path(baseline['output_root']);game=Path(baseline['game_root']);records=read(out/'rea-runtime-full.json')['records'];selected=[r for r in records if r['evidence_id'] in session['evidence_ids']];assert len(selected)==2
    dump(HERE/'rea-runtime.json',dict(records=selected));compress(out/'rea-runtime-full.json',HERE/'raw/rea-runtime-full.json.gz')
    for name in ['managed.jsonl','paths.jsonl','engine.log']:compress(out/name,HERE/(name+'.gz'))
    captures=sorted((out/'captures').glob('*.sd'));assert len(captures)==17;dump(HERE/'saved-files.json',dict(files=[projection(p) for p in captures],baseline=projection(out/'baseline.sd')))
    diagnostic_records=[];diagnostic_runs=[];diagnostic_observation=dict(success=False,sessions=[],evidence_ids=[],plugins=[],archived_frida_sources=[])
    for name in ['first-run','second-run']:
        diagnostic=HERE/'diagnostics'/name;receipt=read(diagnostic/'receipt.json');old=Path(receipt['raw_root']);raw=read(old/'rea-runtime-full.json')['records'];diagrecords=[r for r in raw if r['evidence_id'] in receipt['evidence_ids']];assert len(diagrecords)==2;diagnostic_records.extend(diagrecords)
        compress(old/'rea-runtime-full.json',diagnostic/'rea-runtime-full.json.gz')
        for filename in ['managed.jsonl','paths.jsonl','engine.log']:compress(old/filename,diagnostic/(filename+'.gz'))
        managed=list(map(json.loads,(old/'managed.jsonl').read_text(encoding='utf8').splitlines()));status=next(r for r in diagrecords if r['operation']=='frida_session_status');messages=status['normalized_result']['messages'];cleanup=[r['data'] for r in managed if r['kind']=='cleanup'];errors=[m for m in messages if m.get('payload',{}).get('kind')=='engine_error'];assert len(cleanup)==1
        diagnostic_runs.append(dict(success=False,run=old.name,native_messages=len(messages),messages_truncated=status['normalized_result']['messages_truncated'],engine_errors=len(errors),engine_error_examples=[e['payload']['data']['message'] for e in errors[:2]],reported_results=sum(r['kind']=='result' for r in managed),runner_errors=[r['data'] for r in managed if r['kind']=='runner_error'],cleanup=cleanup,observed_snapshot_differences=snapshot_diff(cleanup[0]['original'],cleanup[0]['restored']),close=read(diagnostic/'close-receipt.json'),ciphertexts=[dict(path=str(p),sha256=sha(p),bytes=p.stat().st_size) for p in sorted((old/'captures').glob('*.sd'))],scope='First run: observer errors plus unconfirmed declared-property restoration; no fine-grained root-cause evidence.' if name=='first-run' else 'Second run: no errors and declared-property checks pass, but full public snapshot differs in Tweak presence/value. Excluded from complete success.'))
        oldload=next(r for r in diagrecords if r['operation']=='load_frida_script');source=oldload['normalized_result'];assert sha(diagnostic/'observe.js')==source['source_sha256'];diagnostic_observation['sessions'].append(dict(session_id=receipt['session_id'],pid=receipt['pid'],state='running',closed_by_operator=True));diagnostic_observation['evidence_ids'].extend(receipt['evidence_ids']);diagnostic_observation['plugins'].append(dict(archived_path=receipt['dll']['path'],sha256=receipt['dll']['sha256']));diagnostic_observation['archived_frida_sources'].append(dict(evidence_id=oldload['evidence_id'],original_path=source['source_path'],path='diagnostics/'+name+'/observe.js',sha256=source['source_sha256']))
    dump(HERE/'diagnostics-rea.json',dict(records=diagnostic_records));dump(HERE/'diagnostics.json',dict(success=False,runs=diagnostic_runs))
    assert session['frida_detached_reported'] is True,'Operator detach confirmation required'
    post=dict(game_root=str(game),process=read(HERE/'close-receipt.json'),frida_detached_reported=session['frida_detached_reported'],profile=[],preserved_test_profile=[],inputs=[],plugins=[],plugins_finalized=finalize_plugins,plugins_restored=None)
    for key in ['profile','preserved_test_profile']:
        for p in baseline[key]:
            actual=sha(p['path']);post[key].append(dict(path=p['path'],before=p['sha256'],after=actual,unchanged=actual==p['sha256']))
    for p in baseline['inputs']:
        actual=sha(p['path']);post['inputs'].append(dict(path=p['path'],original_path=p['original_path'],sha256=actual,unchanged=actual==sha(p['original_path'])==p['sha256']))
    for p in baseline['plugins']:
        actual=sha(p['path']) if finalize_plugins else None;post['plugins'].append(dict(path=p['path'],before=p['sha256'],sha256=actual,unchanged=actual==p['sha256'] if finalize_plugins else None))
    if finalize_plugins:
        expected={str(Path(p['path']).resolve()).casefold() for p in baseline['plugins']};extra=[str(p) for p in (game/'BepInEx/plugins').rglob('*.dll') if str(p.resolve()).casefold() not in expected];post['extra_plugin_dlls']=extra;post['plugins_restored']=all(p['unchanged'] for p in post['plugins']) and not extra;assert post['plugins_restored'],'Finalize only after all probes close and original DLLs return'
    dump(HERE/'post-state.json',post)
    manifest=dict(schema_version=1,natural_only=False,authority='controlled-unregistered-native-body-paint-clone',sessions=[dict(session_id=session['session_id'],pid=session['pid'],state='running',closed_by_operator=True)],evidence_ids=session['evidence_ids'],plugin=session['plugin'],sources=[],outputs=[],raw_inputs=[dict(path=str(out/'rea-runtime-full.json'),sha256=sha(out/'rea-runtime-full.json'))]+[dict(path=str(p),sha256=sha(p)) for p in captures+[out/'baseline.sd']],diagnostic_observation=diagnostic_observation,scope='21 controlled native-clone cases and17 independently decoded saves; two earlier diagnostic runs excluded from complete success. Original controller stays registered, parked; natural producers and UI unverified.')
    for name in ['Probe.cs','build.ps1','observe.js','run_cases.py','analyze.py','collect.py','test_analysis.py','timed-body-paint-runtime.md']:
        manifest['sources'].append(dict(path=name,sha256=sha(HERE/name)))
    for name in ['baseline.json','session.json','compile-only.json','close-receipt.json','rea-runtime.json','diagnostics-rea.json','diagnostics.json','saved-files.json','post-state.json']:
        manifest['outputs'].append(dict(path=name,sha256=sha(HERE/name)))
    manifest['dependencies']=[dict(path='../../'+name,sha256=sha(HERE.parents[1]/name)) for name in ['salt/evidence/timed-body-paint-chain.json','timed-body-paint-static.md']]
    for p in [HERE/(n+'.gz') for n in ['managed.jsonl','paths.jsonl','engine.log']]+list((HERE/'raw').rglob('*.gz'))+list((HERE/'diagnostics').rglob('*')):
        if not p.is_file():continue
        entry=dict(path=p.relative_to(HERE).as_posix(),sha256=sha(p))
        if p.suffix=='.gz':
            data=gzip.decompress(p.read_bytes());entry.update(uncompressed_bytes=len(data),uncompressed_sha256=hashlib.sha256(data).hexdigest())
        manifest['outputs'].append(entry)
    dump(HERE/'manifest.json',manifest)
    return dict(formal_records=2,ciphertexts=17,diagnostic_records=4,plugins_finalized=finalize_plugins)
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--finalize-plugins',action='store_true');a=p.parse_args();print(json.dumps(collect(a.finalize_plugins)))
