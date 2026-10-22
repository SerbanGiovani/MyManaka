"""Snapshot a bounded, possibly still active natural-gameplay observation."""
import argparse
from datetime import datetime, timezone
import gzip
import hashlib
import json
from pathlib import Path

HERE=Path(__file__).resolve().parent
RE=HERE.parent.parent

def digest(p):
    h=hashlib.sha256()
    with p.open('rb') as f:
        for b in iter(lambda:f.read(4*1024*1024),b''):h.update(b)
    return h.hexdigest()

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--game',type=Path,required=True);p.add_argument('--export',type=Path,required=True)
    p.add_argument('--closed-session',action='append',default=[])
    args=p.parse_args()
    bundle=json.loads(args.export.read_text(encoding='utf8'))
    sessions={'0b09d4c4-345c-4cdf-8616-97fe6e457344':31156,
              'f2f9cfb5-6d45-4e0b-a141-41b7d10a446d':48960,
              '3df9ddd5-daef-44b5-be88-3a640c3cc115':45864,
              'e98300ef-3def-4196-b9b0-109d998a63f1':45864}
    records=[];latest={}
    for r in bundle['records']:
        sid=r['parameters'].get('session_id')
        if sid not in sessions:continue
        if r['operation']=='load_frida_script' and r['normalized_result']['source_kind']=='file':records.append(r)
        if r['operation']=='frida_session_status':
            # Bundle record order is not chronology. Messages are cumulative here,
            # untruncated; prefer the most complete retained status per session.
            score=lambda x:(len(x['normalized_result']['messages']),x['normalized_result']['state']=='detached')
            if sid not in latest or score(r)>score(latest[sid]):latest[sid]=r
    assert set(latest)==set(sessions)
    records+=list(latest.values())
    sources={}
    for r in records:
        n=r['normalized_result'];assert not n['messages_truncated']
        if r['operation']=='load_frida_script':
            src=Path(n['source_path']);assert digest(src)==n['source_sha256']
            sources[src.relative_to(RE).as_posix()]=digest(src)
        else:assert n['pid']==sessions[r['parameters']['session_id']]
    (HERE/'rea-runtime.json').write_text(json.dumps({'schema_version':1,
        'selection':'Unchanged selected REA records, not an importable evidence bundle',
        'export_sha256':digest(args.export),'records':records},ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    outputs=[]
    for name in ['natural.jsonl','Player-natural.log','Player-natural-2.log','Player-natural-3.log','BepInEx/LogOutput.log']:
        raw=(args.game/name).read_bytes()
        if name.endswith('.jsonl'):raw=raw[:raw.rfind(b'\n')+1]
        dest=Path(name).name+'.gz';(HERE/dest).write_bytes(gzip.compress(raw,mtime=0))
        outputs.append({'path':dest,'source_relative_path':name,'sha256':digest(HERE/dest),
                        'uncompressed_sha256':hashlib.sha256(raw).hexdigest(),'uncompressed_bytes':len(raw)})
    old=json.loads((args.game/'source-save-hashes.json').read_text(encoding='utf-8-sig'))
    source_saves=[]
    for entry in old:
        src=Path(entry['path']);assert digest(src).lower()==entry['sha256'].lower()
        parts=src.parts; rel='/'.join(parts[-2:]) if src.parent.name in ['SaveData','SaveDataBackup'] else src.name
        source_saves.append({'relative_path':rel,'sha256':digest(src),'unchanged':True})
    inputs=[]
    for rel in ['GameAssembly.dll','UnityPlayer.dll','SecretFlasherManaka_Data/data.unity3d',
                'SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat',
                'SecretFlasherManaka_Data/StreamingAssets/StandaloneWindows64/-265379604']:
        original=Path('E:/SecretFlasherManakaREA')/rel;current=args.game/rel
        assert digest(original)==digest(current)
        inputs.append({'relative_path':rel,'original_path':str(original),'runtime_path':str(current),'sha256':digest(current)})
    sources.update({(HERE/name).relative_to(RE).as_posix():digest(HERE/name) for name in ['Probe.cs','observe.js','observe-v2.js','input-state.js','runtime-state.js','npc-state.js','ui-readback.js','build.ps1','prepare.ps1','collect.py','analyze.py','test_analysis.py']})
    from analyze import analyze
    measured=analyze()
    (HERE/'results.json').write_text(json.dumps(measured,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    manifest={'schema_version':1,'status':measured['status'],
        'captured_utc':datetime.now(timezone.utc).isoformat(),'game_root':str(args.game),
        'natural_validation_complete':measured['natural_validation_complete'],'evidence_ids':[r['evidence_id'] for r in records],
        'sessions':[{'session_id':sid,'pid':pid,'state':latest[sid]['normalized_result']['state'],'closed_by_operator':sid in args.closed_session} for sid,pid in sessions.items()],
        'current_plugin_sha256':digest(args.game/'BepInEx/plugins/NaturalObserver.dll'),
        'sources':[{'path':path,'sha256':sha} for path,sha in sorted(sources.items())],
        'inputs':inputs,'outputs':outputs,'source_saves':source_saves,
        'limits':['Source code is the final third-start observer; earlier two startup revisions are historical diagnostics, not replayable from this final source.',
                  'Session state is the last retained Evidence state, not live status; closure is separately recorded. The test game can remain open after detach.',
                  'REA Frida has no artifact subject hash; separate original/runtime file digests establish the tested copy, not REA-attested process memory identity.',
                  '100 temporary input_positive diagnostics used the wrong return width and are excluded; only bool8 and formal input-state.js are admissible.',
                  'Coverage is bounded by measured cases; unexercised timing/visibility combinations are not passing results.',
                  'Probe UI inspection encountered destroyed-selected-object name reads; those errors are observational, separate from vanilla gameplay exceptions.']}
    (HERE/'manifest.json').write_text(json.dumps(manifest,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps({'records':len(records),'outputs':len(outputs),'source_saves_unchanged':len(source_saves)}))

if __name__=='__main__':main()
