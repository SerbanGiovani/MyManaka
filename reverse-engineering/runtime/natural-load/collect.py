"""Package passive capture and the user's requested suspended-process receipt."""
import gzip
import hashlib
import json
from pathlib import Path
from analyze import HERE,read,sha,projection


def dump(p,v):p.write_text(json.dumps(v,ensure_ascii=False,indent=2)+'\n',encoding='utf8')


def main():
    baseline=read(HERE/'baseline.json');out=Path(baseline['output_root']);checkpoint=read(HERE/'process-checkpoint.json')
    dump(HERE/'save-projections.json',dict(imported=projection((HERE/'.cache/nonempty-input.sd').read_bytes()),natural_backup=projection((HERE/'.cache/natural-backup-1.sd').read_bytes())))
    exit_receipt=read(HERE/'process-exit.json')
    post=dict(profile=[],inputs=[],process={**checkpoint,'present_at_final_check':exit_receipt['process_present'],'in_memory_resume_available':False},process_exit=exit_receipt,frida_closed=True,frida_close_result={'target_state':'unknown'},plugin=dict(path=str(Path(baseline['game_root'])/'BepInEx/plugins/NaturalLoadObserver.dll'),source='Observe.cs',retained_loaded_for_resume=False,retained_on_disk_for_relaunch=True))
    post['plugin']['sha256']=sha(post['plugin']['path'])
    profile=out/'nonempty-A'
    post['disposable_profile_files']=[dict(path=p.relative_to(profile).as_posix(),bytes=p.stat().st_size,sha256=sha(p)) for p in sorted(profile.rglob('*.sd'))]
    post['main_slot_1_exists']=(profile/'SaveData/1.sd').exists()
    post['backup_slot_1_exists']=(profile/'SaveDataBackup/1.sd').exists()
    for row in baseline['profile']:
        after=sha(row['path']);post['profile'].append(dict(path=row['path'],before=row['sha256'],after=after,unchanged=after==row['sha256']))
    for row in baseline['inputs']:
        after=sha(row['path']);original=sha(row['original_path']);post['inputs'].append(dict(path=row['path'],original_path=row['original_path'],sha256=after,unchanged=after==original==row['sha256']))
    assert all(p['unchanged'] for p in post['profile']+post['inputs'])
    dump(HERE/'post-state.json',post)
    bundle=read(HERE/'rea-runtime.json');manifest=dict(schema_version=1,observation_complete=True,natural_only=False,passive_only=True,user_input_driven=True,
        input_boundary='Natural UI/actions and passive game-state observation; initial three-NPC input comes from the prior controlled trial, new-game and backup are naturally produced.',
        sessions=[dict(session_id='2ba79344-527b-49ba-9722-4bf2501d20f4',pid=49736,state='running',closed_by_operator=True,authority='passive-natural')],
        evidence_ids=[r['evidence_id'] for r in bundle['records']],sources=[],outputs=[],process_suspend_receipt_success=True,process_retained_suspended=False,resume_requires_relaunch=True)
    for name in ['Observe.cs','build.ps1','observe.js','observe-v2.js','scan-guards.ps1','prepare_guard_scan.py','hold-process.ps1','analyze.py','collect.py','test_analysis.py']:
        if (HERE/name).exists():manifest['sources'].append(dict(path=name,sha256=sha(HERE/name)))
    for name in ['state.jsonl.gz','native-paths.jsonl.gz','engine.log.gz']:
        raw=gzip.decompress((HERE/name).read_bytes());manifest['outputs'].append(dict(path=name,sha256=sha(HERE/name),uncompressed_bytes=len(raw),uncompressed_sha256=hashlib.sha256(raw).hexdigest()))
    dump(HERE/'manifest.json',manifest);print(json.dumps(dict(records=len(bundle['records']),profile_files=len(post['profile']),suspension_receipt=checkpoint['status'],process_present=post['process']['present_at_final_check'])))


if __name__=='__main__':main()
