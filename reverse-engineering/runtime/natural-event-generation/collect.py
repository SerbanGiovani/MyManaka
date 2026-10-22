"""Select unchanged REA records and a bounded original observer-log window."""
import argparse,gzip,hashlib,json,sys
from datetime import datetime,timezone
from pathlib import Path
HERE=Path(__file__).resolve().parent
ROOT=HERE.parent.parent
def digest(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return json.loads(p.read_text(encoding='utf-8-sig'))
def collect(export,game,sids,closed):
    bundle=read(export);records=[];latest={}
    for r in bundle['records']:
        sid=r['parameters'].get('session_id')
        if sid not in sids:continue
        if r['operation']=='load_frida_script':records.append(r)
        if r['operation']=='frida_session_status':
            if sid not in latest or len(r['normalized_result']['messages'])>=len(latest[sid]['normalized_result']['messages']):latest[sid]=r
    assert set(latest)==set(sids) and all(not r['normalized_result']['messages_truncated'] for r in latest.values())
    records+=list(latest.values());sources=[]
    for r in records:
        n=r['normalized_result']
        if r['operation']=='load_frida_script':
            p=Path(n['source_path']);assert digest(p)==n['source_sha256']
            sources.append(dict(path=p.relative_to(ROOT).as_posix(),sha256=digest(p)))
    (HERE/'rea-runtime.json').write_text(json.dumps(dict(schema_version=1,export_sha256=digest(export),selection='unchanged REA loads and most complete untruncated session status',records=records),ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    frames=[m['payload']['frame'] for r in latest.values() for m in r['normalized_result']['messages'] if m.get('payload',{}).get('frame') is not None]
    lo,hi=min(frames),max(frames);raw=(game/'natural.jsonl').read_bytes();raw=raw[:raw.rfind(b'\n')+1]
    markers=[m['payload']['real'] for r in latest.values() for m in r['normalized_result']['messages']
      if m.get('payload',{}).get('real') is not None and m['payload'].get('kind') in ['generation_animation','generation_enter','generation_end','generation_control_begin','generation_control_end']]
    retained=[];last_snapshot=-1e30
    for line in raw.splitlines(keepends=True):
        row=json.loads(line)
        if not lo<=row.get('frame',-1)<=hi:continue
        when=row.get('real',0)
        if row.get('kind')!='snapshot' or when-last_snapshot>=15 or any(abs(when-t)<=2 for t in markers):
            retained.append(line)
            if row.get('kind')=='snapshot':last_snapshot=when
    selected=b''.join(retained)
    dest=HERE/'natural-window.jsonl.gz';dest.write_bytes(gzip.compress(selected,mtime=0))
    output=dict(path=dest.name,sha256=digest(dest),uncompressed_bytes=len(selected),uncompressed_sha256=hashlib.sha256(selected).hexdigest(),
        original_path=str(game/'natural.jsonl'),original_snapshot_sha256=hashlib.sha256(raw).hexdigest(),original_snapshot_bytes=len(raw),selection=dict(min_frame=lo,max_frame=hi,complete_original_lines=True,snapshot_cadence_real_seconds=15,snapshot_marker_window_seconds=2,marker_real_times=markers,retained_lines=len(retained)))
    previous=read(HERE.parent/'natural-notification/manifest.json');baseline=read(HERE.parent/'natural-time-stop/manifest.json')
    for i in baseline['inputs']:
        for key in ['original_path','runtime_path']:assert digest(Path(i[key]))==i['sha256']
    assert digest(game/'BepInEx/plugins/NaturalObserver.dll')==baseline['current_plugin_sha256']
    saves=read(game/'source-save-hashes.json')
    for s in saves:assert digest(Path(s['path']))==s['sha256'].lower()
    abi=read(HERE/'abi.json');assert digest(Path(abi['source_path']))==abi['source_sha256']
    for p in [HERE/'collect.py',HERE/'analyze.py',HERE/'test_analysis.py',HERE/'abi.json']:
        sources.append(dict(path=p.relative_to(ROOT).as_posix(),sha256=digest(p)))
    sys.path.insert(0,str(HERE))
    from analyze import analyze
    result=analyze();(HERE/'results.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    manifest=dict(schema_version=1,captured_utc=datetime.now(timezone.utc).isoformat(),game_root=str(game),
      sessions=[dict(session_id=sid,pid=45864,state=r['normalized_result']['state'],closed_by_operator=sid in closed) for sid,r in latest.items()],
      evidence_ids=[r['evidence_id'] for r in records],sources=sources,outputs=[output],inputs=baseline['inputs'],
      current_plugin_sha256=baseline['current_plugin_sha256'],source_save_files_unchanged=len(saves),
      previous_checkpoint=dict(path='runtime/natural-notification/manifest.json',sha256=digest(HERE.parent/'natural-notification/manifest.json')),
      authority='Natural session and explicitly controlled parameter-source session are separated in results; all events come from Unity, no direct OnAnim invocation.',
      limits=result['limitations'])
    (HERE/'manifest.json').write_text(json.dumps(manifest,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(cases=len(result['trials']),counts=result['counts'],events=result['total_animation_entries'],callbacks=result['total_callbacks'],errors=len(result['errors']))))
if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--export',type=Path,required=True);p.add_argument('--game',type=Path,required=True);p.add_argument('--session-id',action='append',required=True);p.add_argument('--closed-session',action='append',default=[]);a=p.parse_args();collect(a.export,a.game,a.session_id,a.closed_session)
