"""Archive exact passive-session checkpoints; retain the incompatible-profile diagnostic."""
import argparse,gzip,hashlib,json,shutil
from pathlib import Path
from analyze import HERE,read,sha,projection
USE=dict(name='use',raw_root='E:/ManakaREA-NaturalGameplay/NaturalPaint/20261031-2',session_id='023e144b-89eb-4503-9fb6-ae684c2dc3f4',pid=85172,load_evidence_id='ev_932b09effc0e609f0e87197128f14d5ad27bcf21297611a42d86f701515b29b5',final_status_evidence_id='ev_7b8e88bd6126709a6638defd364b8c8fd035043817c73ff8323be6b37d901531',raw_evidence_file='rea-runtime-full.json')
def dump(p,v):p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes((json.dumps(v,ensure_ascii=False,indent=2)+'\n').encode('utf8'))
def unpacked_hash(p):
    with gzip.open(p,'rb') as f:return hashlib.file_digest(f,'sha256').hexdigest()
def compress(source,target):
    target.parent.mkdir(parents=True,exist_ok=True)
    if target.exists():assert unpacked_hash(target)==sha(source),'Frozen full capture changed: '+str(source)
    else:
        with source.open('rb') as src,target.open('wb') as dst:
            with gzip.GzipFile(filename='',mode='wb',fileobj=dst,mtime=0) as gz:shutil.copyfileobj(src,gz,1024*1024)
def archive_run(meta):
    out=Path(meta['raw_root']);folder=HERE/'runs'/meta['name'];raw=read(out/meta.get('raw_evidence_file','rea-runtime-full.json'));wanted=[meta['load_evidence_id'],meta['final_status_evidence_id']];by={r['evidence_id']:r for r in raw['records']};selected=[by[k] for k in wanted];assert all(r['parameters']['session_id']==meta['session_id'] for r in selected)
    canonical=HERE/'.cache'/('rea-runtime-'+meta['name']+'.json');dump(canonical,dict(records=selected));compress(canonical,folder/'rea-runtime.json.gz');compress(out/meta.get('raw_evidence_file','rea-runtime-full.json'),folder/'rea-runtime-full.json.gz')
    for n in ['managed.jsonl','paths.jsonl','engine.log']:compress(out/n,folder/(n+'.gz'))
    with (out/'managed.jsonl').open(encoding='utf8') as f:managed=[json.loads(x) for x in f]
    captures={x['data']['target']:dict(x['data'],frame=x['frame'],real=x['real']) for x in managed if x['kind']=='file_capture'};files=[]
    for p in sorted((out/'captures').glob('*.sd')):
        row=projection(p);row['capture']=captures[str(p)];assert row['sha256']==row['capture']['sha256'];files.append(row)
    dump(folder/'saved-files.json',dict(files=files));dump(folder/'close-receipt.json',read(out/'close-receipt.json'))
    if (out/'close-receipt-observed.json').exists():dump(folder/'close-receipt-observed.json',read(out/'close-receipt-observed.json'))
    return selected
def archive_diagnostic():
    folder=HERE/'diagnostics/incompatible-profile';meta=read(folder/'receipt.json');out=Path(meta['raw_root']);raw=read(out/'diagnostic-full-evidence.json');by={r['evidence_id']:r for r in raw['records']};selected=[by[k] for k in meta['evidence_ids']];assert len(selected)==3
    canonical=HERE/'.cache/diagnostics-rea.json';dump(canonical,dict(records=selected));compress(canonical,HERE/'diagnostics-rea.json.gz');compress(out/'diagnostic-full-evidence.json',folder/'diagnostic-full-evidence.json.gz')
    for n in ['managed.jsonl','paths.jsonl','engine.log']:compress(out/n,folder/(n+'.gz'))
    statuses=[r for r in selected if r['operation']=='frida_session_status'];summaries=[]
    for r in statuses:
        n=r['normalized_result'];summaries.append(dict(evidence_id=r['evidence_id'],retained_messages=len(n['messages']),messages_truncated=n['messages_truncated'],retained_engine_error_events=sum(m.get('payload',{}).get('kind')=='engine_error' for m in n['messages']),retained_script_errors=sum(m['type']=='error' for m in n['messages'])))
    lines=[];first=None
    with (out/'engine.log').open(encoding='utf8',errors='replace') as f:
        for number,line in enumerate(f,1):
            if first is None and ('IndexOutOfRangeException:' in line or ('RCosplay' in line and 'Get' in line)):first=number
            if first is not None and number<=first+65:lines.append(line.rstrip('\n'))
            if first is not None and number>first+65:break
    dump(HERE/'diagnostics.json',dict(success=False,capture_complete=False,reason='Source slot0 active RCosplay category7 part indices8..13 exceed original length8; original initialization aborted. Historical receipt uses coarse costume wording; original stack/asset category check supersede that interpretation.',sessions=summaries,engine_initial_exception_start_line=first,engine_initial_exception_excerpt=lines,full_engine_bytes=(out/'engine.log').stat().st_size,full_engine_sha256=sha(out/'engine.log'),frida_detach_confirmed=meta['frida_detach_confirmed'],limits=['Provider-retained native history is truncated; complete exported retained records do not recover earlier discarded messages.','Inline MCP response-size/resource constraints are distinct from provider capture truncation.','No complete natural-use, action-return or player-initialization coverage is claimed for this failed diagnostic.']))
    return selected
def collect(finalize_plugins=False):
    plan=read(HERE/'session-plan.json');baseline=read(HERE/'baseline.json');game=Path(baseline['game_root']);records=[]
    for meta in plan['runs']:records.extend(archive_run(meta))
    canonical=HERE/'.cache/rea-runtime.json';dump(canonical,dict(records=records));compress(canonical,HERE/'rea-runtime.json.gz');diag=archive_diagnostic();post=dict(profile=[],preserved_test_profile=[],inputs=[],plugins=[],plugins_finalized=finalize_plugins,plugins_restored=None,processes=[read(HERE/'runs'/r['name']/'close-receipt.json') for r in plan['runs']])
    for key in ['profile','preserved_test_profile']:
        for p in baseline[key]:
            actual=sha(p['path']);post[key].append(dict(path=p['path'],before=p['sha256'],after=actual,unchanged=actual==p['sha256']))
    for p in baseline['inputs']:
        actual=sha(p['path']);post['inputs'].append(dict(path=p['path'],original_path=p['original_path'],sha256=actual,unchanged=actual==sha(p['original_path'])==p['sha256']))
    for p in baseline['plugins']:
        actual=sha(p['path']) if finalize_plugins else None;post['plugins'].append(dict(path=p['path'],before=p['sha256'],sha256=actual,unchanged=actual==p['sha256'] if finalize_plugins else None))
    if finalize_plugins:
        known={str(Path(x['path']).resolve()).casefold() for x in baseline['plugins']};post['extra_plugin_dlls']=[str(p) for p in (game/'BepInEx/plugins').rglob('*.dll') if str(p.resolve()).casefold() not in known];post['plugins_restored']=all(p['unchanged'] for p in post['plugins']) and not post['extra_plugin_dlls'];assert post['plugins_restored'],'Finalize only after the observer exits and both original plugins return'
    dump(HERE/'post-state.json',post);old=read(HERE/'diagnostics/incompatible-profile/receipt.json');load=next(r for r in diag if r['operation']=='load_frida_script');src=load['normalized_result'];assert src['source_sha256']==sha(HERE/'diagnostics/incompatible-profile/observe.js')
    diagnostic=dict(success=False,capture_complete=False,sessions=[dict(session_id=old['session_id'],pid=old['pid'],state='running',closed_by_operator=True)],evidence_ids=old['evidence_ids'],plugins=[dict(archived_path=str(Path(old['raw_root'])/'NaturalPaintObserver-diagnostic.dll'),sha256=sha(Path(old['raw_root'])/'NaturalPaintObserver-diagnostic.dll'))],truncated_evidence_ids=[r['evidence_id'] for r in diag if r['normalized_result']['messages_truncated']],archived_frida_sources=[dict(evidence_id=load['evidence_id'],original_path=src['source_path'],path='diagnostics/incompatible-profile/observe.js',sha256=src['source_sha256'])])
    manifest=dict(schema_version=1,natural_only=True,passive_only=True,user_input_driven=True,authority='passive-original-user-input-and-true-process-restart-in-isolated-save-root',sessions=[dict(session_id=r['session_id'],pid=r['pid'],state='running',closed_by_operator=True) for r in plan['runs']],evidence_ids=[r['evidence_id'] for r in records],plugin=plan['plugin'],sources=[],outputs=[],dependencies=[],raw_inputs=[],diagnostic_observation=diagnostic,scope='Natural UI types5/8/9 and original delayed effects; warm title reconstruction separated from fresh process restart. Failed incompatible profile is partial evidence only.')
    for n in ['Observe.cs','build.ps1','observe.js','profile-inventory.json','analyze.py','collect.py','test_analysis.py','natural-paint-runtime.md']:manifest['sources'].append(dict(path=n,sha256=sha(HERE/n)))
    for n in ['baseline.json','cold-baseline.json','cold-start-receipt.json','compile-only.json','session-plan.json','post-state.json','rea-runtime.json.gz','diagnostics-rea.json.gz','diagnostics.json']:
        entry=dict(path=n,sha256=sha(HERE/n))
        if n.endswith('.gz'):
            with gzip.open(HERE/n,'rb') as f:
                h=hashlib.sha256();length=0
                for chunk in iter(lambda:f.read(1024*1024),b''):length+=len(chunk);h.update(chunk)
            entry.update(uncompressed_bytes=length,uncompressed_sha256=h.hexdigest())
        manifest['outputs'].append(entry)
    for p in list((HERE/'runs').rglob('*'))+list((HERE/'diagnostics').rglob('*')):
        if not p.is_file():continue
        entry=dict(path=p.relative_to(HERE).as_posix(),sha256=sha(p))
        if p.suffix=='.gz':
            with gzip.open(p,'rb') as f:
                h=hashlib.sha256();length=0
                for chunk in iter(lambda:f.read(1024*1024),b''):length+=len(chunk);h.update(chunk)
            entry.update(uncompressed_bytes=length,uncompressed_sha256=h.hexdigest())
        manifest['outputs'].append(entry)
    for n in ['natural-paint-assets.json','natural-paint-static.md','salt/evidence/natural-paint-chain.json']:
        manifest['dependencies'].append(dict(path='../../'+n,sha256=sha(HERE.parents[1]/n)))
    manifest['dependencies'].append(dict(path='../timed-body-paint/analyze.py',sha256=sha(HERE.parent/'timed-body-paint/analyze.py')))
    for r in plan['runs']:
        out=Path(r['raw_root']);manifest['raw_inputs'].append(dict(path=str(out/r.get('raw_evidence_file','rea-runtime-full.json')),sha256=sha(out/r.get('raw_evidence_file','rea-runtime-full.json'))));manifest['raw_inputs'].extend(dict(path=str(p),sha256=sha(p)) for p in sorted((out/'captures').glob('*.sd')))
    dump(HERE/'manifest.json',manifest);return dict(formal_records=len(records),diagnostic_records=len(diag),plugins_finalized=finalize_plugins)
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--archive-only',action='store_true');p.add_argument('--finalize-plugins',action='store_true');a=p.parse_args()
    if a.archive_only:archive_run(USE);archive_diagnostic();print('Archived frozen natural-use run and incompatible-profile diagnostic; no success result or final manifest generated')
    else:print(json.dumps(collect(a.finalize_plugins)))
