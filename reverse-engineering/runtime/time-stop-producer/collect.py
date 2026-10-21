"""Retain this completed producer test, without rewriting prior experiment files."""
import argparse
import gzip
import hashlib
import json
from pathlib import Path
from datetime import datetime, timezone
HERE=Path(__file__).resolve().parent


def sha(path):
    h=hashlib.sha256()
    with path.open('rb') as f:
        for b in iter(lambda:f.read(4*1024*1024),b''):h.update(b)
    return h.hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--fixture',type=Path,required=True);p.add_argument('--export',type=Path,required=True)
    p.add_argument('--session',required=True);p.add_argument('--evidence',required=True);p.add_argument('--pid',type=int,required=True)
    args=p.parse_args()
    raw=(args.fixture/'fixture.jsonl').read_bytes(); rows=[json.loads(x) for x in raw.decode('utf-8-sig').splitlines()]
    assert rows[-1]['kind']=='complete' and sum(r['kind']=='end' for r in rows)==32
    bundle=json.loads(args.export.read_text(encoding='utf8'))
    records=[r for r in bundle['records'] if r['parameters'].get('session_id')==args.session and (r['operation']=='load_frida_script' or r['evidence_id']==args.evidence)]
    assert len(records)==2
    status=next(r for r in records if r['operation']=='frida_session_status')['normalized_result']
    assert status['pid']==args.pid and status['state']=='detached' and not status['messages_truncated']
    assert not [m for m in status['messages'] if m['type']=='error']
    (HERE/'rea-runtime.json').write_text(json.dumps({'schema_version':1,'selection':'Unchanged selected Evidence records, not an importable REA bundle','export_sha256':sha(args.export),'session_id':args.session,'records':records},ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    outputs=[]
    for source,name in [('fixture.jsonl','fixture.jsonl.gz'),('Player-fixture.log','unity.log.gz'),('BepInEx/LogOutput.log','bepinex.log.gz')]:
        src=args.fixture/source;dest=HERE/name;data=src.read_bytes();dest.write_bytes(gzip.compress(data,mtime=0))
        outputs.append({'path':name,'sha256':sha(dest),'uncompressed_sha256':sha(src),'uncompressed_bytes':len(data)})
    baseline=json.loads((HERE.parent/'npc-event-timing/manifest.json').read_text(encoding='utf8'))
    inputs=[]
    for old in baseline['inputs']:
        src=Path(old['original_path']);dst=args.fixture/old['relative_path']
        assert sha(src)==sha(dst)==old['sha256']
        inputs.append({**old,'fixture_path':str(dst)})
    models=args.fixture/'models.unity3d'; expected='98621b2c4fa4f9de80f355fae5776ab17efc016bcc81c581bcd0917af4308367'
    assert sha(models)==expected
    inputs.append({'relative_path':'models.unity3d','fixture_path':str(models),'sha256':expected})
    sources=[{'path':name,'sha256':sha(HERE/name)} for name in ('Probe.cs','observe.js')]
    assert records[0]['operation'] in ('load_frida_script','frida_session_status')
    load=next(r for r in records if r['operation']=='load_frida_script')['normalized_result']
    assert load['source_sha256']==sha(HERE/'observe.js')
    manifest={'schema_version':1,'scope':'Controlled original producer/Animator/EventManager/NPC runtime, not a natural input session',
      'collected_utc':datetime.now(timezone.utc).isoformat(),'pid':args.pid,'frida_session_id':args.session,
      'session_closed':True,'target_exited':True,'fixture_root':str(args.fixture),'trials':32,
      'unity':'2022.3.62f2','platform':'win32','architecture':'x64','sources':sources,'inputs':inputs,'outputs':outputs,
      'plugin_dll_sha256':sha(args.fixture/'BepInEx/plugins/TimeStopProducerFixture.dll'),
      'final_evidence_id':args.evidence,'evidence_ids':[r['evidence_id'] for r in records],
      'limits':['No full scene/input/native NpcController.Initialize; native listener built exactly from target/method via original Action constructor.',
        'Game bootstrap/root motion and irrelevant player clip audio/completion callbacks skipped; original OnChangeTimeStop and NPC handlers preserved.',
        f"Append-only fixture log retains {sum(r['kind']=='loaded' for r in rows)} startup loaded records; all32 trial records are correlated with selected PID/session.",
        'Injected extra true broadcast and silent reset are counterfactual controls, not naturally observed gameplay.',
        'First producer_enter flag is null because its native metadata slot was not resolved until the method initialized it; listener and leave flag are observed.',
        'REA subject/environment remain null; PID/module-path plus this independent fingerprint manifest bind the runtime target.']}
    (HERE/'manifest.json').write_text(json.dumps(manifest,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps({'trials':32,'messages':len(status['messages']),'plugin':manifest['plugin_dll_sha256']}))


if __name__=='__main__':main()
