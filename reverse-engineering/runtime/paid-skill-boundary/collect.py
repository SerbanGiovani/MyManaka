"""Offline collection of formal v3; failed setup runs remain separate diagnostics."""
import argparse,collections,gzip,hashlib,json
from pathlib import Path
from analyze import HERE,LOAD_ID,STATUS_ID,read,sha,rows,projection
def dump(path,value):path.write_text(json.dumps(value,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
def collect(finalize_plugins=False):
 baseline=read(HERE/'baseline.json');out=Path(baseline['output_root']);game=Path(baseline['game_root']);raw=read(out/'rea-runtime-full.json')['records']
 formal=[r for r in raw if r['evidence_id'] in [LOAD_ID,STATUS_ID]];assert len(formal)==2
 dump(HERE/'rea-runtime.json',dict(records=formal));captures=sorted((out/'captures').glob('*.sd'));assert len(captures)==14
 dump(HERE/'saved-files.json',dict(files=[projection(p) for p in captures]))
 for name in ['managed.jsonl','paths.jsonl','engine.log']:
  data=gzip.compress((out/name).read_bytes(),mtime=0);path=HERE/(name+'.gz')
  if path.exists():assert path.read_bytes()==data,'Frozen formal log changed: '+name
  else:path.write_bytes(data)
 source=HERE.parents[1];assets=read(source/'paid-skill-boundary-assets.json');metadata=read(source/'paid-skill-boundary-metadata.json');enum={r['name']:r['value'] for r in metadata['enum_values']};records={}
 for r in metadata['selected_master_records']['records']:
  if r['Type'] in ['Slow','NpcDirect','AutoSlow','MaxAccessoryNum','TimeStop']:records[str(enum[r['Type']])]={**r,'ReleaseOrderTargetId':enum.get(r['ReleaseOrderTarget'],-1)}
 tiers={str(i):[{f['name']:f['value'] for f in item['record']['fields']} for item in assets['tables'][table]['entries']] for i,table in [(6,'MSkillSlow'),(11,'MSkillMaxAccessoryNum')]}
 dump(HERE/'asset-tiers.json',dict(authority='offline-shipped-tier-assets-plus-separately-labeled-historical-master-records',tier_source_sha256=sha(source/'paid-skill-boundary-assets.json'),record_source_sha256=sha(source/'paid-skill-boundary-metadata.json'),tier_authority=assets['authority'],master_record_authority=metadata['selected_master_records']['authority'],tiers=tiers,records=records,limits='Capacity/Slow use real tier NextLevelUpRp, not generic InitRp. Other selected master records are historical observations, corroborated here by actual v3 prices/masks and native spend arguments.'))
 diagnostic_statuses=['ev_71afe23175d9951b3f201da8920300b2de983dac7be81f29ade3ea1a4783f180','ev_958f7e92fd2a63dfa9d784016ef13cae3a2947b15fb0b3b020f8440ba865e28d'];statuses=[r for r in raw if r['evidence_id'] in diagnostic_statuses];sessions={r['normalized_result']['session_id'] for r in statuses};diagnostic=[r for r in raw if r['evidence_id'] in diagnostic_statuses or r['operation']=='load_frida_script' and r['parameters']['session_id'] in sessions];assert len(diagnostic)==4
 dump(HERE/'diagnostics-rea.json',dict(records=diagnostic))
 diagnostics=[]
 for name,run,pid in [('bootstrap','20261030-1',24096),('invalid-fixture','20261030-2',46532)]:
  folder=HERE/'diagnostics'/name;managed=rows(folder/'managed.jsonl.gz');engine=gzip.decompress((folder/'engine.log.gz').read_bytes()).decode('utf8',errors='replace');status=next(r for r in statuses if r['normalized_result']['pid']==pid);n=status['normalized_result'];diagnostics.append(dict(name=name,run=run,pid=pid,success=False,runner_errors=[r['data'] for r in managed if r['kind']=='runner_error'],cleanup=[r['data'] for r in managed if r['kind']=='cleanup'],engine_error_lines=sum('[Error' in l for l in engine.splitlines()),rea_evidence_id=status['evidence_id'],rea_native_messages=len(n['messages']),rea_engine_errors=sum(m.get('payload',{}).get('kind')=='engine_error' for m in n['messages']),messages_truncated=n['messages_truncated'],shutdown='Normal exit reported by operator. v2 Frida close returned late/no final response; process exit, not a returned close result, bounds capture.'))
 dump(HERE/'diagnostics.json',dict(formal_success_run='20261030-3',separate_failed_setup_runs=diagnostics))
 post=dict(game_root=str(game),process=read(HERE/'close-receipt.json'),frida_closed=True,frida_close_final_state='unknown; process exit recorded, closure reported by operator',profile=[],preserved_test_profile=[],inputs=[],plugins=[],plugins_finalized=finalize_plugins,plugins_restored=None)
 for key in ['profile','preserved_test_profile']:
  for p in baseline[key]:
   current=sha(p['path']);post[key].append(dict(path=p['path'],before=p['sha256'],after=current,unchanged=current==p['sha256']))
 for p in baseline['inputs']:
  current=sha(p['path']);original=sha(p['original_path']);post['inputs'].append(dict(path=p['path'],original_path=p['original_path'],sha256=current,unchanged=current==original==p['sha256']))
 for p in baseline['plugins']:
  current=sha(p['path']) if finalize_plugins else None;post['plugins'].append(dict(path=p['path'],before=p['sha256'],sha256=current,unchanged=current==p['sha256'] if finalize_plugins else None))
 if finalize_plugins:
  known={str(Path(p['path']).resolve()).casefold() for p in baseline['plugins']};extra=[str(p) for p in (game/'BepInEx/plugins').rglob('*') if p.is_file() and p.suffix.lower()=='.dll' and str(p.resolve()).casefold() not in known];post['extra_plugin_dlls']=extra;post['plugins_restored']=all(p['unchanged'] for p in post['plugins']) and not extra
  assert post['plugins_restored'],'Do not finalize while another runtime probe is installed'
 dump(HERE/'post-state.json',post)
 manifest=dict(schema_version=1,natural_only=False,authority='controlled-active-original-skill-ui-and-runtime-consumers',successful_run='20261030-3',sessions=[dict(session_id='dfe861aa-0082-4de9-be89-7e8e006e1b71',pid=72824,state='running',closed_by_operator=True)],evidence_ids=[LOAD_ID,STATUS_ID],plugin=dict(archived_path=str(out/'PaidSkillBoundaryProbe-completed.dll'),sha256=sha(out/'PaidSkillBoundaryProbe-completed.dll')),sources=[],outputs=[],dependencies=[],raw_inputs=[dict(path=str(out/'rea-runtime-full.json'),sha256=sha(out/'rea-runtime-full.json'))]+[dict(path=str(p),sha256=sha(p)) for p in captures],scope='Seven controlled active UI callback cases, actual capacity/buff consumers and14 independent before/after decryptions. Failed bootstrap and invalid disturbance runs excluded from success. No natural mouse or successful rank unlock claim.')
 manifest['diagnostic_observation']=dict(success=False,sessions=[dict(session_id=r['normalized_result']['session_id'],pid=r['normalized_result']['pid'],state=r['normalized_result']['state'],closed_by_operator=True) for r in statuses],evidence_ids=[r['evidence_id'] for r in diagnostic],scope='Separate failed bootstrap/invalid-fixture runs; engine errors are retained diagnostics, not successful gameplay evidence.')
 manifest['diagnostic_observation']['plugins']=[dict(archived_path=str(out.parent/run/filename),sha256=sha(out.parent/run/filename)) for run,filename in [('20261030-1','PaidSkillBoundaryProbe-bootstrap.dll'),('20261030-2','PaidSkillBoundaryProbe-invalid-fixture.dll')]]
 for record in diagnostic:
  if record['operation']=='load_frida_script':assert record['normalized_result']['source_sha256']==sha(HERE/'observe.js'),'Diagnostic observer source differs; archive the exact old script before collection'
 for name in ['Probe.cs','build.ps1','observe.js','run_cases.py','analyze.py','collect.py','test_analysis.py','paid-skill-boundary-runtime.md']:
  manifest['sources'].append(dict(path=name,sha256=sha(HERE/name)))
 for name in ['managed.jsonl.gz','paths.jsonl.gz','engine.log.gz']:
  data=gzip.decompress((HERE/name).read_bytes());manifest['outputs'].append(dict(path=name,sha256=sha(HERE/name),uncompressed_bytes=len(data),uncompressed_sha256=hashlib.sha256(data).hexdigest()))
 for name in ['baseline.json','close-receipt.json','rea-runtime.json','saved-files.json','asset-tiers.json','diagnostics.json','diagnostics-rea.json','post-state.json']:
  manifest['outputs'].append(dict(path=name,sha256=sha(HERE/name)))
 for p in sorted((HERE/'diagnostics').rglob('*')):
  if p.is_file():manifest['outputs'].append(dict(path=p.relative_to(HERE).as_posix(),sha256=sha(p)))
 for name in ['paid-skill-boundary-assets.json','paid-skill-boundary-metadata.json']:
  manifest['dependencies'].append(dict(path='../../'+name,sha256=sha(source/name)))
 dump(HERE/'manifest.json',manifest)
 return dict(formal_records=len(formal),encrypted_files=len(captures),diagnostic_records=len(diagnostic),plugins_finalized=finalize_plugins,protected_inputs_unchanged=all(p['unchanged'] for k in ['profile','preserved_test_profile','inputs'] for p in post[k]))
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--finalize-plugins',action='store_true');a=p.parse_args();print(json.dumps(collect(a.finalize_plugins)))
