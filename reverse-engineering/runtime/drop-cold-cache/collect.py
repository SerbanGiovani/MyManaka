"""Retain the closed cold-cache round and protect prior natural-gameplay saves."""
import gzip
import hashlib
import json
from pathlib import Path
from analyze import HERE,read,sha,projection

def dump(p,v):p.write_text(json.dumps(v,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
def main():
    baseline=read(HERE/'baseline.json');out=Path(baseline['output_root']);game=Path(baseline['game_root'])
    bundle=read(HERE/'.cache/rea-full.json');ids={'ev_e59ee703c703add736b672777a6843fb889564a5a4f30d2a7e2d9d380495d2d8','ev_e4ac7d6679a0dd9f738a26207a7bdaa60af21a36eb9bbe60a6aa0abf6a165f1b'}
    selected=[r for r in bundle['records'] if r['evidence_id'] in ids];assert len(selected)==2
    dump(HERE/'rea-runtime.json',dict(records=selected));dump(HERE/'native-save.json',projection((HERE/'.cache/native-save.sd').read_bytes()))
    for source,name in [(out/'cold-managed.jsonl','managed.jsonl.gz'),(out/'paths.jsonl','paths.jsonl.gz'),(game/'BepInEx/LogOutput.log','engine.log.gz')]:
        (HERE/name).write_bytes(gzip.compress(source.read_bytes(),mtime=0))
    post=dict(game_root=baseline['game_root'],process=read(HERE/'close-receipt.json'),frida_closed=True,frida_close_final_state='unknown',profile=[],preserved_test_profile=[],inputs=[],plugins=[],plugins_restored=False)
    for key in ['profile','preserved_test_profile']:
        for r in baseline[key]:
            after=sha(r['path']);post[key].append(dict(path=r['path'],before=r['sha256'],after=after,unchanged=after==r['sha256']))
    for r in baseline['inputs']:
        after=sha(r['path']);post['inputs'].append(dict(path=r['path'],original_path=r['original_path'],sha256=after,unchanged=after==r['sha256']==sha(r['original_path'])))
    for r in baseline['plugins']:post['plugins'].append(dict(path=r['path'],sha256=sha(r['path']),unchanged=sha(r['path'])==r['sha256']))
    post['plugins_restored']=all(r['unchanged'] for r in post['plugins']) and not (game/'BepInEx/plugins/ColdDropProbe.dll').exists()
    post['temporary_plugin']=dict(archived_path=str(out/'ColdDropProbe-completed.dll'),sha256=sha(out/'ColdDropProbe-completed.dll'))
    assert post['process']['process_absent'] and post['plugins_restored'] and all(r['unchanged'] for key in ['profile','preserved_test_profile','inputs'] for r in post[key])
    dump(HERE/'post-state.json',post)
    manifest=dict(schema_version=1,observation_complete=True,natural_only=False,authority='controlled-native-entry-replay',
        sessions=[dict(session_id='39457486-1a0a-441d-81b2-75cd0f364450',pid=32812,state='running',closed_by_operator=True)],evidence_ids=sorted(ids),sources=[],outputs=[],
        capture_scope='Only explicit fixtures with the snapshot applier frozen; natural bootstrap NPC creation is intentionally outside native hook capture.',
        input_boundary='Copy of natural slot1 in a new disposable profile; original UserData and prior natural profile remain unchanged.',
        native_snapshot=dict(path=str((HERE/'.cache/native-save.sd').resolve()),sha256=sha(HERE/'.cache/native-save.sd')),
        plugin=post['temporary_plugin'],process_subject_boundary='REA Frida subject remains null; module path, PID and pinned disk identities are supplementary evidence, not process-memory attestation.')
    for name in ['Probe.cs','build.ps1','observe.js','analyze.py','collect.py','test_analysis.py']:
        manifest['sources'].append(dict(path=name,sha256=sha(HERE/name)))
    for name in ['managed.jsonl.gz','paths.jsonl.gz','engine.log.gz']:
        raw=gzip.decompress((HERE/name).read_bytes());manifest['outputs'].append(dict(path=name,sha256=sha(HERE/name),uncompressed_bytes=len(raw),uncompressed_sha256=hashlib.sha256(raw).hexdigest()))
    dump(HERE/'manifest.json',manifest)
    print(json.dumps(dict(records=len(selected),profile_files=len(post['profile']),prior_natural_files=len(post['preserved_test_profile']),plugins_restored=True)))

if __name__=='__main__':main()
