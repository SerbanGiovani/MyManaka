"""Keep native deferred replay and passive natural evidence in separate sessions."""
import argparse,gzip,hashlib,json,runpy
from datetime import datetime,timezone
from pathlib import Path
HERE=Path(__file__).resolve().parent;ROOT=HERE.parent.parent;GAME=Path('E:/ManakaREA-NaturalGameplay')
def read(p):return json.loads(p.read_text(encoding='utf-8-sig'))
def digest(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def select(export,sid,dest):
    rows=[r for r in read(export)['records'] if r['parameters'].get('session_id')==sid]
    statuses=[r for r in rows if r['operation']=='frida_session_status']
    final=max(statuses,key=lambda r:max(m.get('payload',{}).get('frame',-1) for m in r['normalized_result']['messages']))
    assert not final['normalized_result']['messages_truncated']
    assert final['normalized_result']['pid']==46272
    records=[r for r in rows if r['operation']=='load_frida_script']+[final]
    (HERE/dest).write_text(json.dumps(dict(schema_version=1,export_sha256=digest(export),selection='unchanged loads and final untruncated pre-detach status',records=records),ensure_ascii=False,separators=(',',':'))+'\n',encoding='utf8')
    return records,final['normalized_result']['messages']
def collect(natural,replay):
    nr,nm=select(GAME/'rea-callsite-natural-final-20261025.json',natural,'rea-runtime.json')
    rr,rm=select(GAME/'rea-callsite-replay-final-20261025.json',replay,'replay-runtime.json')
    sources={}
    for r in nr+rr:
        if r['operation']!='load_frida_script':continue
        n=r['normalized_result'];p=Path(n['source_path']);assert digest(p)==n['source_sha256']
        sources[p.relative_to(ROOT).as_posix()]=digest(p)
    start=read(GAME/'noise-callsite-start-20261025.json');offset=start['natural_log_offset']
    with (GAME/'natural.jsonl').open('rb') as f:f.seek(offset);raw=f.read()
    raw=raw[:raw.rfind(b'\n')+1];outputs=[]
    for messages,name in [(nm,'natural-window.jsonl.gz'),(rm,'replay-window.jsonl.gz')]:
        ps=[m['payload'] for m in messages if m.get('payload',{}).get('frame') is not None]
        lo=min(p['frame'] for p in ps);hi=max(p['frame'] for p in ps)
        markers=[p['real'] for p in ps if p['kind'] in ['coverage_enter','coverage_end','coverage_animation','noise_control_native_begin','noise_control_trigger']]
        selected=[];last=-1e30
        for line in raw.splitlines(keepends=True):
            p=json.loads(line);when=p.get('real',0)
            if not lo<=p.get('frame',-1)<=hi:continue
            if p['kind']!='snapshot' or when-last>=15 or any(abs(when-t)<=2 for t in markers):
                selected.append(line)
                if p['kind']=='snapshot':last=when
        data=b''.join(selected);path=HERE/name;path.write_bytes(gzip.compress(data,mtime=0))
        outputs.append(dict(path=name,sha256=digest(path),uncompressed_bytes=len(data),uncompressed_sha256=hashlib.sha256(data).hexdigest(),original_path=str(GAME/'natural.jsonl'),original_start_offset=offset,original_snapshot_bytes=len(raw),original_snapshot_sha256=hashlib.sha256(raw).hexdigest(),selection=dict(min_frame=lo,max_frame=hi,snapshot_cadence_real_seconds=15,marker_window_seconds=2,marker_real_times=markers,retained_lines=len(selected),complete_original_lines=True)))
    baseline=read(HERE.parent/'natural-time-stop/manifest.json')
    for i in baseline['inputs']:
        for k in ['original_path','runtime_path']:assert digest(Path(i[k]))==i['sha256']
    assert digest(GAME/'BepInEx/plugins/NaturalObserver.dll')==baseline['current_plugin_sha256']
    window=read(HERE/'callsite-window.json');native=Path(window['source']).read_bytes()
    assert hashlib.sha256(native).hexdigest()==window['source_sha256']
    image=runpy.run_path(str(ROOT/'salt/metadata.py'))['PE'](native)
    for row in window['rows']:
        pos=image.offset(0x180000000+int(row['rva'],16),executable=True)
        assert native[pos:pos+row['size']]==bytes(row['bytes'])
    for s in start['source_save_hashes']:assert digest(Path(s['path']))==s['sha256'].lower()
    save=HERE/'source-save-baseline.json';save.write_text(json.dumps(dict(files=start['source_save_hashes'],original_log_offset=offset),indent=2)+'\n',encoding='utf8')
    for name in ['analyze.py','collect.py','test_analysis.py']:sources[(HERE/name).relative_to(ROOT).as_posix()]=digest(HERE/name)
    result=runpy.run_path(str(HERE/'analyze.py'))['analyze']();assert result['all_sources_finished']
    (HERE/'results.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    deps=['runtime/noise-cancellation/analyze.py','runtime/noise-cancellation/manifest.json','runtime/noise-cancellation/rea-runtime.json','runtime/natural-event-coverage/analyze.py','runtime/natural-event-generation/analyze.py','salt/evidence/noise-cancel/run.json','salt/evidence/noise-value-guard/run.json']
    manifest=dict(schema_version=1,captured_utc=datetime.now(timezone.utc).isoformat(),game_root=str(GAME),evidence_ids=[r['evidence_id'] for r in nr+rr],sources=[dict(path=p,sha256=h) for p,h in sorted(sources.items())],outputs=outputs,
      sessions=[dict(session_id=sid,pid=46272,state='running',closed_by_operator=True,authority=authority) for sid,authority in [(natural,'passive-natural'),(replay,'controlled-deferred-original-body')]],natural_only=False,session_files={'rea-runtime.json':natural,'replay-runtime.json':replay},observation_complete=result['all_sources_finished'],inputs=baseline['inputs'],current_plugin_sha256=baseline['current_plugin_sha256'],source_save_files_unchanged=len(start['source_save_hashes']),source_save_baseline=dict(path=save.name,sha256=digest(save)),dependencies=[dict(path=p,sha256=digest(ROOT/p)) for p in deps],static_window=dict(path='callsite-window.json',sha256=digest(HERE/'callsite-window.json'),instructions_verified=len(window['rows'])),
      limits=['Natural and artificial deferred replay are separate sessions and result sections.','Original noise body executes after its entry callback returns; no nested NativeFunction noise OnUpdate call is made.','Cleanup verifies enumerated fields and position, not the whole game world.'])
    (HERE/'manifest.json').write_text(json.dumps(manifest,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(complete=result['all_sources_finished'],natural_messages=len(nm),replay_messages=len(rm))))
if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--natural-session',required=True);p.add_argument('--replay-session',required=True);a=p.parse_args();collect(a.natural_session,a.replay_session)
