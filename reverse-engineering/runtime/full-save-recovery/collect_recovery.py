"""Retain clean recovery observations and the separately labeled invalid-key probe."""
import gzip,hashlib,json
from pathlib import Path
from project_recovery import HERE,ROOT
def read(p):return json.loads(p.read_text(encoding='utf-8-sig'))
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def dump(p,v):p.write_text(json.dumps(v,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
def main():
    baseline=read(HERE/'baseline.json');game=Path(baseline['game_root']);out1=ROOT.parent/'20261030-1'
    for stem in ['managed.jsonl','paths.jsonl','engine.log']:
        if not (HERE/(stem+'.gz')).exists():(HERE/(stem+'.gz')).write_bytes(gzip.compress((ROOT/stem).read_bytes(),mtime=0))
    ids=['ev_fc545e015820d2d606af6c398abf5cfc680313c76778fee1613fafaf25ee53fe','ev_b23120f66f2128eb5c87d89d40767984bb7ae66df7f7b481c2300d546d2889b7','ev_8664294ececcc95e29a7180dc96047256de8c58fd54789be2d9af16f9483092d','ev_d38ff3cddf35aaa3ac78ab647659803534b799e1e5759e12e1241d1b5fc26ddf'];records=[r for r in read(HERE/'.cache/rea-full.json')['records'] if r['evidence_id'] in ids];assert len(records)==4;dump(HERE/'rea-runtime.json',dict(records=records))
    post=dict(game_root=str(game),process=read(HERE/'close-receipt.json'),frida_closed=True,frida_close_final_state='unknown',profile=[],preserved_test_profile=[],inputs=[],plugins=[])
    for key in ['profile','preserved_test_profile']:
        for x in baseline[key]:
            after=sha(x['path']);post[key].append(dict(path=x['path'],before=x['sha256'],after=after,unchanged=after==x['sha256']))
    for x in baseline['inputs']:post['inputs'].append(dict(path=x['path'],original_path=x['original_path'],sha256=sha(x['path']),unchanged=sha(x['path'])==x['sha256']==sha(x['original_path'])))
    for x in baseline['plugins']:post['plugins'].append(dict(path=x['path'],sha256=sha(x['path']),unchanged=sha(x['path'])==x['sha256']))
    post['plugins_restored']=all(x['unchanged'] for x in post['plugins']) and not list((game/'BepInEx/plugins').glob('*RecoveryProbe*.dll'));dump(HERE/'post-state.json',post)
    manifest=dict(schema_version=1,natural_only=False,authority='controlled-native-save-recovery-and-selected-getters',sessions=[dict(session_id='5939c667-9655-4dcd-bdbd-4f1225ddb112',pid=71664,state='running',closed_by_operator=True,scope='invalid-key-fixture-diagnostic'),dict(session_id='d68adea8-479a-4e6b-93f3-3cc63412b82a',pid=47188,state='running',closed_by_operator=True,scope='clean-selected-cases')],evidence_ids=ids,plugins=[dict(archived_path=str(p),sha256=sha(p)) for p in [out1/'RecoveryProbe-diagnostic.dll',ROOT/'RecoveryProbe-completed.dll']],sources=[],outputs=[],getter_scope='six real skill keys, three item ids and three mission ids; read outputs independently compared to decoded pass1 data; no rendering/active mission update equivalence',diagnostic_boundary='Version1 incorrectly selected absent skill key48. Ten cases stopped at that getter; two system-damage exceptions were separate. None counted as complete clean two-pass cases.')
    for name in ['Probe.cs','Probe-v1.cs','build.ps1','observe.js','prepare.py','run_cases.py','project_recovery.py','collect_recovery.py','analyze_recovery.py','test_recovery.py']:manifest['sources'].append(dict(path=name,sha256=sha(HERE/name)))
    for prefix in ['','diagnostic-']:
        for stem in ['managed.jsonl','paths.jsonl','engine.log']:
            name=prefix+stem+'.gz';raw=gzip.decompress((HERE/name).read_bytes());manifest['outputs'].append(dict(path=name,sha256=sha(HERE/name),uncompressed_bytes=len(raw),uncompressed_sha256=hashlib.sha256(raw).hexdigest()))
    dump(HERE/'manifest.json',manifest)
if __name__=='__main__':main()
