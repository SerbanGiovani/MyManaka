"""Freeze the first full-state batch without treating detach timeout as success."""
import gzip,json,hashlib
from project import HERE,ROOT,project
def read(p):return json.loads(p.read_text(encoding='utf-8-sig'))
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def dump(p,v):p.write_text(json.dumps(v,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
def main():
    baseline=read(HERE/'baseline.json');game=__import__('pathlib').Path(baseline['game_root'])
    for src,name in [(ROOT/'managed.jsonl','managed.jsonl.gz'),(ROOT/'paths.jsonl','paths.jsonl.gz'),(game/'BepInEx/LogOutput.log','engine.log.gz')]:
        if not (HERE/name).exists():(HERE/name).write_bytes(gzip.compress(src.read_bytes(),mtime=0))
    ids=['ev_88782676cc81af20af27bd03d1820243cc349d36a54afb7eac6c00e97aead85c','ev_2801710849b6110d035fdb3135cf6fd947a0c78e82633a2f4c284f5bb7f3f791'];selected=[r for r in read(HERE/'.cache/rea-full.json')['records'] if r['evidence_id'] in ids];assert len(selected)==2;dump(HERE/'rea-runtime.json',dict(records=selected))
    post=dict(game_root=str(game),process=read(HERE/'close-receipt.json'),profile=[],preserved_test_profile=[],inputs=[],plugins=[])
    for key in ['profile','preserved_test_profile']:
        for x in baseline[key]:
            after=sha(__import__('pathlib').Path(x['path']));post[key].append(dict(path=x['path'],before=x['sha256'],after=after,unchanged=after==x['sha256']))
    for x in baseline['inputs']:
        p=__import__('pathlib').Path(x['path']);op=__import__('pathlib').Path(x['original_path']);post['inputs'].append(dict(path=str(p),original_path=str(op),sha256=sha(p),unchanged=sha(p)==x['sha256']==sha(op)))
    for x in baseline['plugins']:
        post['plugins'].append(dict(path=x['path'],sha256=sha(__import__('pathlib').Path(x['path'])),unchanged=sha(__import__('pathlib').Path(x['path']))==x['sha256']))
    post['plugins_restored']=all(x['unchanged'] for x in post['plugins']) and not list((game/'BepInEx/plugins').glob('*FullSaveProbe*.dll'));dump(HERE/'post-state.json',post)
    manifest=dict(schema_version=1,natural_only=False,authority='controlled-native-load-save-two-pass',sessions=[dict(session_id='4928c304-2328-4187-a2a7-589b4b4ac86a',pid=77664,state='running',closed_by_operator=False)],frida_close_attempted=True,frida_detach_confirmed=False,process_exited_normally=True,evidence_ids=ids,plugin=dict(archived_path=str(ROOT/'FullSaveProbe-completed.dll'),sha256=sha(ROOT/'FullSaveProbe-completed.dll')),sources=[],outputs=[],scope='Two serialized game roots and nine system keys; selected missing-key and corrupt-main cases. No all-consumer runtime equivalence or UI recovery claim.')
    for name in ['Probe.cs','build.ps1','observe.js','prepare.py','run_cases.py','project.py','collect.py','analyze.py','test_analysis.py']:manifest['sources'].append(dict(path=name,sha256=sha(HERE/name)))
    for name in ['managed.jsonl.gz','paths.jsonl.gz','engine.log.gz']:
        raw=gzip.decompress((HERE/name).read_bytes());manifest['outputs'].append(dict(path=name,sha256=sha(HERE/name),uncompressed_bytes=len(raw),uncompressed_sha256=hashlib.sha256(raw).hexdigest()))
    dump(HERE/'manifest.json',manifest)
if __name__=='__main__':main()
