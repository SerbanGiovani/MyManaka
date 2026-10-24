"""Freeze separate natural and controlled REA sessions, never relabel a replay."""
import gzip,hashlib,json,runpy
from datetime import datetime,timezone
from pathlib import Path
HERE=Path(__file__).resolve().parent;ROOT=HERE.parent.parent
GAME=Path('E:/ManakaREA-NaturalGameplay')
NATURAL='d914503b-8a84-41ee-99a6-32237c1c0eef'
REPLAY='f141a81a-dbe1-4977-a75e-4ab198c2db3e'
ADDITIONAL='503ab689-8cea-46e5-b3d8-57b54e84a302'
def read(p):return json.loads(p.read_text(encoding='utf-8-sig'))
def digest(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def select(export,sid,dest):
    rows=[r for r in read(export)['records'] if r['parameters'].get('session_id')==sid]
    statuses=[r for r in rows if r['operation']=='frida_session_status']
    final=max(statuses,key=lambda r:max(m.get('payload',{}).get('frame',-1) for m in r['normalized_result']['messages']))
    assert not final['normalized_result']['messages_truncated']
    assert final['normalized_result']['pid']==46272
    records=[r for r in rows if r['operation']=='load_frida_script']+[final]
    (HERE/dest).write_text(json.dumps(dict(schema_version=1,export_sha256=digest(export),selection='unchanged script loads plus final untruncated status captured before detach',records=records),ensure_ascii=False,separators=(',',':'))+'\n',encoding='utf8')
    return records,final['normalized_result']['messages']
def collect():
    nr,nm=select(GAME/'rea-noise-natural-final-20261024.json',NATURAL,'rea-runtime.json')
    rr,rm=select(GAME/'rea-noise-replay-final-20261024.json',REPLAY,'replay-runtime.json')
    vr,vm=select(GAME/'rea-noise-v3-final-20261024.json',ADDITIONAL,'v3-runtime.json')
    sources={}
    for r in nr+rr+vr:
        if r['operation']!='load_frida_script':continue
        n=r['normalized_result'];p=Path(n['source_path']);assert digest(p)==n['source_sha256']
        sources[p.relative_to(ROOT).as_posix()]=digest(p)
    pe=runpy.run_path(str(ROOT/'salt/metadata.py'))['PE']((GAME/'GameAssembly.dll').read_bytes())
    native=(GAME/'GameAssembly.dll').read_bytes();verified=[]
    for m in nm:
        p=m.get('payload',{})
        if p.get('kind')!='noise_decoded_file_window':continue
        d=p['data']
        for row in d['rows']:
            pos=pe.offset(0x180000000+int(row['rva'],16),executable=True)
            assert native[pos:pos+row['size']]==bytes(row['bytes'])
        verified.append(dict(start=d.get('start'),end=d.get('end'),instructions=len(d['rows'])))
    start=read(GAME/'noise-start-20261024.json');offset=start['natural_log_offset']
    raw=(GAME/'natural.jsonl').read_bytes()[offset:];raw=raw[:raw.rfind(b'\n')+1]
    outputs=[]
    for messages,dest in [(nm,'natural-window.jsonl.gz'),(rm,'replay-window.jsonl.gz'),(vm,'v3-window.jsonl.gz')]:
        ps=[m['payload'] for m in messages if m.get('payload',{}).get('frame') is not None]
        lo=min(p['frame'] for p in ps);hi=max(p['frame'] for p in ps)
        markers=[p['real'] for p in ps if p['kind'] in ['coverage_enter','coverage_end','coverage_animation','noise_control_trigger']]
        selected=[];last=-1e30
        for line in raw.splitlines(keepends=True):
            p=json.loads(line);when=p.get('real',0)
            if not lo<=p.get('frame',-1)<=hi:continue
            if p['kind']!='snapshot' or when-last>=15 or any(abs(when-t)<=2 for t in markers):
                selected.append(line)
                if p['kind']=='snapshot':last=when
        data=b''.join(selected);path=HERE/dest;path.write_bytes(gzip.compress(data,mtime=0))
        outputs.append(dict(path=dest,sha256=digest(path),uncompressed_bytes=len(data),uncompressed_sha256=hashlib.sha256(data).hexdigest(),original_path=str(GAME/'natural.jsonl'),original_start_offset=offset,original_snapshot_bytes=len(raw),original_snapshot_sha256=hashlib.sha256(raw).hexdigest(),selection=dict(min_frame=lo,max_frame=hi,snapshot_cadence_real_seconds=15,marker_window_seconds=2,marker_real_times=markers,retained_lines=len(selected),complete_original_lines=True)))
    baseline=read(HERE.parent/'natural-time-stop/manifest.json')
    for i in baseline['inputs']:
        for k in ['original_path','runtime_path']:assert digest(Path(i[k]))==i['sha256']
    assert digest(GAME/'BepInEx/plugins/NaturalObserver.dll')==baseline['current_plugin_sha256']
    for s in start['source_save_hashes']:assert digest(Path(s['path']))==s['sha256'].lower()
    save=HERE/'source-save-baseline.json';save.write_text(json.dumps(dict(files=start['source_save_hashes'],original_log_offset=offset),indent=2)+'\n',encoding='utf8')
    for name in ['analyze.py','collect.py','test_analysis.py']:sources[(HERE/name).relative_to(ROOT).as_posix()]=digest(HERE/name)
    result=runpy.run_path(str(HERE/'analyze.py'))['analyze']()
    assert result['all_sources_finished'],'Every source must finish before final capture'
    (HERE/'results.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    deps=['runtime/natural-event-coverage/analyze.py','runtime/natural-event-generation/analyze.py','runtime/natural-cancellation/manifest.json','salt/evidence/noise-cancel/run.json','salt/evidence/noise-value-guard/run.json']
    manifest=dict(schema_version=1,captured_utc=datetime.now(timezone.utc).isoformat(),game_root=str(GAME),evidence_ids=[r['evidence_id'] for r in nr+rr+vr],sources=[dict(path=p,sha256=h) for p,h in sorted(sources.items())],outputs=outputs,
      sessions=[dict(session_id=sid,pid=46272,state='running',closed_by_operator=True,authority=authority) for sid,authority in [(NATURAL,'natural-input-passive'),(REPLAY,'controlled-receiver-replay'),(ADDITIONAL,'controlled-receiver-replay-native-hook-attempt-not-captured')]],natural_only=False,session_files={'rea-runtime.json':NATURAL,'replay-runtime.json':REPLAY,'v3-runtime.json':ADDITIONAL},
      observation_complete=result['all_sources_finished'],inputs=baseline['inputs'],current_plugin_sha256=baseline['current_plugin_sha256'],source_save_files_unchanged=len(start['source_save_hashes']),source_save_baseline=dict(path=save.name,sha256=digest(save)),dependencies=[dict(path=p,sha256=digest(ROOT/p)) for p in deps],decoded_instruction_verification=verified,
      limits=['Natural and artificial receiver replay are separate sessions and result sections.','Cleanup verifies the named scalar fields, prior business state, Found bool and player position; it does not roll back the whole game world.','Frida reports provider authority external-service; local manifest adds analyst context without rewriting Evidence.'])
    (HERE/'manifest.json').write_text(json.dumps(manifest,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(complete=result['all_sources_finished'],natural_records=len(nm),controlled_records=len(rm),verified_instructions=verified)))
if __name__=='__main__':collect()
