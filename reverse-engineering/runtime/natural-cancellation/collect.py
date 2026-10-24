"""Keep a new immutable natural checkpoint, with an explicit stopped-probe tail."""
import argparse,gzip,hashlib,json,sys,runpy
from datetime import datetime,timezone
from pathlib import Path
HERE=Path(__file__).resolve().parent;ROOT=HERE.parent.parent
def digest(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return json.loads(p.read_text(encoding='utf-8-sig'))
def collect(export,game,sid,closed,interim):
    records=[];statuses=[]
    for r in read(export)['records']:
        if r['parameters'].get('session_id')!=sid:continue
        if r['operation']=='load_frida_script':records.append(r)
        elif r['operation']=='frida_session_status':statuses.append(r)
    def lastframe(r):return max(m.get('payload',{}).get('frame',-1) for m in r['normalized_result']['messages'])
    latest=max(statuses,key=lastframe)
    base=max((r for r in statuses if not r['normalized_result']['messages_truncated']),key=lastframe)
    records.append(base)
    if latest['evidence_id']!=base['evidence_id']:records.append(latest)
    assert latest['normalized_result']['pid']==46272
    sources={}
    for r in records:
        if r['operation']=='load_frida_script':
            n=r['normalized_result'];p=Path(n['source_path']);assert digest(p)==n['source_sha256']
            sources[p.relative_to(ROOT).as_posix()]=digest(p)
    sys.path.insert(0,str(HERE));from analyze import analyze,core
    merge_statuses=core['merge_statuses']
    retained,joins=merge_statuses(records)
    pe_type=runpy.run_path(str(ROOT/'salt/metadata.py'))['PE']
    native=(game/'GameAssembly.dll').read_bytes()
    pe=pe_type(native);verified_instructions=[]
    for m in retained:
        p=m.get('payload',{})
        if p.get('kind')!='guard_decoded':continue
        d=p['data'];count=0
        for row in d['rows']:
            va=0x180000000+int(row['rva'],16);pos=pe.offset(va,executable=True)
            assert native[pos:pos+row['size']]==bytes(row['bytes']),'Live instruction bytes differ from pinned artifact'
            count+=1
        verified_instructions.append(dict(name=d['name'],instructions=count,start=d['start'],end=d['end']))
    (HERE/'rea-runtime.json').write_text(json.dumps(dict(schema_version=1,export_sha256=digest(export),selection='unchanged loads, last full prefix and final bounded status; verified exact message overlap',records=records),ensure_ascii=False,separators=(',',':'))+'\n',encoding='utf8')
    payloads=[m['payload'] for m in retained if m.get('payload',{}).get('frame') is not None]
    lo=min(p['frame'] for p in payloads);hi=max(p['frame'] for p in payloads)
    markers=[p['real'] for p in payloads if p['kind'] in ['coverage_enter','coverage_end','coverage_animation','coverage_stop_producer']]
    run_start=read(game/'cancellation-start-20261024.json');offset=run_start['natural_log_offset']
    raw=(game/'natural.jsonl').read_bytes()[offset:];raw=raw[:raw.rfind(b'\n')+1];selected=[];last=-1e30
    for line in raw.splitlines(keepends=True):
        p=json.loads(line)
        if not lo<=p.get('frame',-1)<=hi:continue
        when=p.get('real',0)
        if p['kind']!='snapshot' or when-last>=15 or any(abs(when-t)<=2 for t in markers):
            selected.append(line)
            if p['kind']=='snapshot':last=when
    data=b''.join(selected);dest=HERE/'natural-window.jsonl.gz';dest.write_bytes(gzip.compress(data,mtime=0))
    outputs=[dict(path=dest.name,sha256=digest(dest),uncompressed_bytes=len(data),uncompressed_sha256=hashlib.sha256(data).hexdigest(),
      original_path=str(game/'natural.jsonl'),original_snapshot_sha256=hashlib.sha256(raw).hexdigest(),original_snapshot_bytes=len(raw),original_start_offset=offset,
      selection=dict(min_frame=lo,max_frame=hi,snapshot_cadence_real_seconds=15,marker_window_seconds=2,marker_real_times=markers,retained_lines=len(selected),complete_original_lines=True))]
    baseline=read(HERE.parent/'natural-time-stop/manifest.json')
    for i in baseline['inputs']:
        for k in ['original_path','runtime_path']:assert digest(Path(i[k]))==i['sha256']
    assert digest(game/'BepInEx/plugins/NaturalObserver.dll')==baseline['current_plugin_sha256']
    saves=run_start['source_save_hashes']
    for s in saves:assert digest(Path(s['path']))==s['sha256'].lower()
    save_baseline=HERE/'source-save-baseline.json'
    save_baseline.write_text(json.dumps(dict(files=saves,original_log_offset=offset),indent=2)+'\n',encoding='utf8')
    for name in ['analyze.py','collect.py','test_analysis.py']:sources[(HERE/name).relative_to(ROOT).as_posix()]=digest(HERE/name)
    result=analyze()
    if not interim:assert result['all_sources_finished'],'Final capture needs each source finish marker before checkpoint/detach'
    (HERE/'results.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    manifest=dict(schema_version=1,captured_utc=datetime.now(timezone.utc).isoformat(),game_root=str(game),
      evidence_ids=[r['evidence_id'] for r in records],sources=[dict(path=p,sha256=h) for p,h in sorted(sources.items())],outputs=outputs,
      sessions=[dict(session_id=sid,pid=46272,state=latest['normalized_result']['state'],closed_by_operator=closed)],inputs=baseline['inputs'],current_plugin_sha256=baseline['current_plugin_sha256'],source_save_files_unchanged=len(saves),
      previous_checkpoint=dict(path='runtime/natural-event-coverage/manifest.json',sha256=digest(HERE.parent/'natural-event-coverage/manifest.json')),
      algorithm_dependency=dict(path='runtime/natural-event-coverage/analyze.py',sha256=digest(HERE.parent/'natural-event-coverage/analyze.py')),
      observation_complete=result['all_sources_finished'],capture_joins=joins,natural_only=True,limits=result['limits'],
      source_save_baseline=dict(path=save_baseline.name,sha256=digest(save_baseline)),
      decoded_instruction_verification=verified_instructions,
      static_guard_queries=dict(path='salt/evidence/natural-cancel-guards/run.json',sha256=digest(ROOT/'salt/evidence/natural-cancel-guards/run.json')))
    (HERE/'manifest.json').write_text(json.dumps(manifest,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps({k:result[k] for k in ['status','total_events','total_callbacks','business_exit_counts','stop_guard_actual_rejections','all_sources_finished']}))
if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--export',type=Path,required=True);p.add_argument('--game',type=Path,required=True);p.add_argument('--session-id',required=True);p.add_argument('--closed',action='store_true');p.add_argument('--interim',action='store_true');a=p.parse_args();collect(a.export,a.game,a.session_id,a.closed,a.interim)
