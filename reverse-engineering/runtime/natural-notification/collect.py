"""Retain this natural timing window without changing earlier checkpoints."""
import argparse
from datetime import datetime,timezone
import gzip,hashlib,json
from pathlib import Path

HERE=Path(__file__).resolve().parent
ROOT=HERE.parent.parent
def digest(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return json.loads(p.read_text(encoding='utf-8-sig'))

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--export',type=Path,required=True);p.add_argument('--game',type=Path,required=True)
    p.add_argument('--session-id',action='append',required=True);p.add_argument('--closed-session',action='append',default=[])
    a=p.parse_args();bundle=read(a.export);latest={};records=[];sources={}
    for r in bundle['records']:
        sid=r['parameters'].get('session_id')
        if sid not in a.session_id:continue
        if r['operation'] in ['load_frida_script','unload_frida_script']:records.append(r)
        elif r['operation']=='frida_session_status':
            if sid not in latest or len(r['normalized_result']['messages'])>len(latest[sid]['normalized_result']['messages']):latest[sid]=r
    assert set(latest)==set(a.session_id)
    records+=list(latest.values())
    for r in records:
        n=r['normalized_result']
        if r['operation']=='load_frida_script':
            assert n['source_kind']=='file' and not n['messages_truncated']
            src=Path(n['source_path']).resolve();assert digest(src)==n['source_sha256'];sources[src.relative_to(ROOT).as_posix()]=digest(src)
        elif r['operation']=='frida_session_status':assert not n['messages_truncated'] and n['pid']==45864
    (HERE/'rea-runtime.json').write_text(json.dumps({'schema_version':1,'export_sha256':digest(a.export),
        'selection':'Unchanged selected REA records, not an importable bundle','records':records},ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    outputs=[]
    for rel in ['natural.jsonl','Player-natural-3.log','BepInEx/LogOutput.log']:
        raw=(a.game/rel).read_bytes()
        if rel.endswith('jsonl'):raw=raw[:raw.rfind(b'\n')+1]
        dest=HERE/(Path(rel).name+'.gz');dest.write_bytes(gzip.compress(raw,mtime=0))
        outputs.append(dict(path=dest.name,sha256=digest(dest),uncompressed_bytes=len(raw),uncompressed_sha256=hashlib.sha256(raw).hexdigest()))
    baseline=read(HERE.parent/'natural-time-stop/manifest.json')
    for i in baseline['inputs']:
        for key in ['original_path','runtime_path']:assert digest(Path(i[key]))==i['sha256']
    assert digest(a.game/'BepInEx/plugins/NaturalObserver.dll')==baseline['current_plugin_sha256']
    saves=read(a.game/'source-save-hashes.json')
    for s in saves:assert digest(Path(s['path']))==s['sha256'].lower()
    for f in ['observe.js','guard-observe.js','collect.py','analyze.py','test_analysis.py']:
        sources[(HERE/f).relative_to(ROOT).as_posix()]=digest(HERE/f)
    from analyze import analyze
    measured=analyze();(HERE/'results.json').write_text(json.dumps(measured,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    manifest=dict(schema_version=1,captured_utc=datetime.now(timezone.utc).isoformat(),game_root=str(a.game),
      evidence_ids=[r['evidence_id'] for r in records],
      sessions=[dict(session_id=sid,pid=45864,state=r['normalized_result']['state'],closed_by_operator=sid in a.closed_session) for sid,r in latest.items()],
      sources=[dict(path=k,sha256=v) for k,v in sorted(sources.items())],outputs=outputs,
      inputs=baseline['inputs'],current_plugin_sha256=baseline['current_plugin_sha256'],source_save_files_unchanged=len(saves),
      previous_checkpoint=dict(path='runtime/natural-time-stop/manifest.json',sha256=digest(HERE.parent/'natural-time-stop/manifest.json')),
      limits=['Earlier checkpoints are unchanged; only this attach window is evaluated.',
              'Getter calls and hooks add observation overhead; timing is measured under this instrumentation.',
              'Diagnostic failed hook is preserved with its successful unload, not counted as a gameplay event.',
              'Natural observation is read-only. Explicitly controlled sessions temporarily change position/MeshParent and call original notification/producer methods; they are not natural-input or animation-generation evidence.',
              'Sources assert temporary restoration at trial end; later ordinary game updates can change those states again. Missing scenario coverage remains unknown.'])
    (HERE/'manifest.json').write_text(json.dumps(manifest,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(records=len(records),sessions=len(latest),status=measured['status'])))
