"""Retain a completed fixture run and unchanged selected REA Evidence records."""
import argparse
import gzip
import hashlib
import json
from datetime import datetime, timezone
from pathlib import Path

HERE=Path(__file__).resolve().parent


def sha(path):
    h=hashlib.sha256()
    with path.open('rb') as f:
        for chunk in iter(lambda:f.read(4*1024*1024),b''):h.update(chunk)
    return h.hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--fixture',type=Path,required=True)
    p.add_argument('--original',type=Path,default=Path('E:/SecretFlasherManakaREA'))
    p.add_argument('--export',dest='export_path',type=Path,required=True)
    p.add_argument('--session',required=True)
    p.add_argument('--final-evidence',required=True)
    p.add_argument('--pid',type=int,required=True)
    args=p.parse_args()
    rows=[json.loads(x) for x in (args.fixture/'fixture.jsonl').read_text(encoding='utf-8-sig').splitlines()]
    assert rows[-1]['kind']=='complete'
    export=json.loads(args.export_path.read_text(encoding='utf-8'))
    records=[r for r in export['records'] if r['parameters'].get('session_id')==args.session and
             (r['operation']=='load_frida_script' or r['evidence_id']==args.final_evidence)]
    assert len(records)==3
    final=next(r for r in records if r['evidence_id']==args.final_evidence)
    assert final['normalized_result']['pid']==args.pid
    assert final['normalized_result']['state']=='detached'
    assert not final['normalized_result']['messages_truncated']
    assert not [m for m in final['normalized_result']['messages'] if m['type']=='error']
    (HERE/'rea-runtime.json').write_text(json.dumps({'schema_version':1,
        'selection':'Unmodified selected Evidence records; not an importable REA bundle',
        'export_sha256':sha(args.export_path),'session_id':args.session,'records':records},ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    outputs=[]
    for source,name in [('fixture.jsonl','fixture.jsonl.gz'),('Player-fixture.log','unity.log.gz'),('BepInEx/LogOutput.log','bepinex.log.gz')]:
        src=args.fixture/source; dest=HERE/name
        dest.write_bytes(gzip.compress(src.read_bytes(),mtime=0))
        outputs.append({'path':name,'sha256':sha(dest),'uncompressed_sha256':sha(src),'uncompressed_bytes':src.stat().st_size})
    inputs=[]
    for relative in ['GameAssembly.dll','UnityPlayer.dll','SecretFlasherManaka_Data/data.unity3d',
                     'SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat',
                     'BepInEx/interop/Assembly-CSharp.dll','BepInEx/core/Il2CppInterop.Runtime.dll']:
        original=args.original/relative; fixture=args.fixture/relative
        a,b=sha(original),sha(fixture); assert a==b,relative
        inputs.append({'relative_path':relative,'original_path':str(original),'fixture_path':str(fixture),'sha256':a})
    assert inputs[0]['sha256']=='6003033049ac32e8712dc4101382534e21d65b97100c167ebec6bbca1462c18d'
    sources=[{'path':name,'sha256':sha(HERE/name)} for name in ['Probe.cs','observe.js','ordering.js']]
    for r in records:
        if r['operation']=='load_frida_script':
            v=r['normalized_result']; assert sha(HERE/Path(v['source_path'].replace('\\','/')).name)==v['source_sha256']
    manifest={'schema_version':1,'scope':'controlled Unity runtime fixture, not natural gameplay',
        'collected_utc':datetime.now(timezone.utc).isoformat(),'pid':args.pid,'frida_session_id':args.session,
        'session_closed':True,'target_exited':True,'unity':'2022.3.62f2','architecture':'x64','platform':'win32',
        'fixture_root':str(args.fixture),'inputs':inputs,'sources':sources,'outputs':outputs,
        'plugin_dll_sha256':sha(args.fixture/'BepInEx/plugins/NpcEventFixture.dll'),
        'fixture_patch_count':rows[0]['data']['patched'],'trials':sum(r['kind']=='end' for r in rows),
        'final_evidence_id':args.final_evidence,'evidence_ids':[r['evidence_id'] for r in records],
        'limits':['Original Animator, FPS and TimeStop handlers and Scheduler run with controlled minimal context.',
                  'Game MonoBehaviour lifecycle and root-motion callbacks are skipped; audio functions stubbed.',
                  'Hidden three-frame admission is reproduced by Driver, not native full NpcController.OnUpdate.',
                  'Standing female/male only; sitting, actual NPC factory, full gameplay and mods untested.',
                  'REA itself reports null artifact identity/environment; this manifest binds PID/module path and matching file hashes.',
                  'One bootstrap IntroAnimationController.OnStartFadeOut NullReference and one original missing Light script warning retained in logs. No trial-period exception was observed.']}
    (HERE/'manifest.json').write_text(json.dumps(manifest,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({'trials':manifest['trials'],'outputs':outputs,'plugin':manifest['plugin_dll_sha256']},ensure_ascii=False))


if __name__=='__main__':main()
