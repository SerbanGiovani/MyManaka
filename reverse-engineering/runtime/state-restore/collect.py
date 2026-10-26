"""Package one explicitly selected clean trial; retain failed diagnostics separately."""
import gzip
import hashlib
import json
import subprocess
from pathlib import Path
from analyze import projection,sha,read,HERE

SESSION='00a0e0e2-f820-4f2f-8910-6c4a3ebf1d0c'


def dump(p,v):p.write_text(json.dumps(v,ensure_ascii=False,indent=2)+'\n',encoding='utf8')


def main():
    baseline=read(HERE/'baseline.json');out=Path(baseline['output_root'])
    running=subprocess.check_output(['powershell','-NoProfile','-Command',"$probeRunning = @(Get-Process -Name SecretFlasherManaka -ErrorAction SilentlyContinue); $probeRunning | Select-Object -ExpandProperty Path; exit 0"],text=True).strip()
    assert str(Path(baseline['game_root'])/'SecretFlasherManaka.exe').lower() not in running.lower(),'Test process is still running'
    full=HERE/'.cache/rea-full.json';bundle=read(full)
    selected=[r for r in bundle['records'] if r.get('parameters',{}).get('session_id')==SESSION]
    assert len(selected)==4 and sum(r['operation']=='frida_session_status' for r in selected)==1
    subset={**bundle,'records':selected};dump(HERE/'rea-runtime.json',subset)
    (HERE/'rea-diagnostics.json.gz').write_bytes(gzip.compress(full.read_bytes(),mtime=0))
    first=HERE/'rea-diagnostic.json'
    if first.exists():first.rename(HERE/'.cache/rea-diagnostic-initial.json')
    dump(HERE/'native-save.json',projection((HERE/'.cache/native-roundtrip.sd').read_bytes()))
    post=dict(profile=[],inputs=[],process=dict(pid=62136,exited=True,exit_method='CloseMainWindow attempted; then Stop-Process after the window remained open'),
        frida=dict(session_id=SESSION,capture_state='running',closed_by_operator=True,close_result={'target_state':'unknown'},post_close_status='provider removes closed sessions; status returned invalid_request'),
        temporary_plugin=dict(sha256=sha(out/'RestoreProbe-completed.dll'),removed_from_plugin_directory=True,archived_path=str(out/'RestoreProbe-completed.dll')))
    for row in baseline['profile']:
        after=sha(row['path']);post['profile'].append(dict(path=row['path'],before=row['sha256'],after=after,unchanged=after==row['sha256']))
    for row in baseline['inputs']:
        after=sha(row['path']);original=sha(row['original_path']);post['inputs'].append(dict(path=row['path'],original_path=row['original_path'],before=row['sha256'],after=after,original=original,matches_original=after==original==row['sha256']))
    post['observer_plugin']=dict(**baseline['plugin'],unchanged=sha(baseline['plugin']['path'])==baseline['plugin']['sha256'])
    assert all(x['unchanged'] for x in post['profile']) and all(x['matches_original'] for x in post['inputs']) and post['observer_plugin']['unchanged']
    dump(HERE/'post-state.json',post)
    manifest=dict(schema_version=1,observation_complete=True,natural_only=False,authority='controlled-native-entry-replay',game_root=baseline['game_root'],
        sessions=[dict(session_id=SESSION,pid=62136,state='running',closed_by_operator=True,authority='controlled-replay')],
        evidence_ids=[r['evidence_id'] for r in selected],sources=[],outputs=[],native_snapshot=dict(path=str(HERE/'.cache/native-roundtrip.sd'),sha256=sha(HERE/'.cache/native-roundtrip.sd')),
        diagnostic_archive=dict(path='rea-diagnostics.json.gz',rea_records=len(bundle['records']),selected_clean_records=len(selected),counted_as_completed_trials=False),
        plugin=dict(sha256=post['temporary_plugin']['sha256'],source='RestoreProbe.cs'),
        process_subject_boundary='REA subject is null; disk inputs are hash-pinned and module paths are observed, not process-memory hash attestation.')
    for name in ['RestoreProbe.cs','RestoreProbe-v1.cs','build.ps1','observe.js','reserve-witness.js','hide-witness.js','prepare.js','inventory.js','inventory-v2.js','api.js','proof.js','proof-v1.js','proof-v2.js','build_probe.py','analyze.py','collect.py','test_analysis.py']:
        if (HERE/name).exists():manifest['sources'].append(dict(path=name,sha256=sha(HERE/name)))
    for name in ['managed.jsonl.gz','managed-diagnostics.jsonl.gz','engine.log.gz','rea-diagnostics.json.gz']:
        raw=gzip.decompress((HERE/name).read_bytes());manifest['outputs'].append(dict(path=name,sha256=sha(HERE/name),uncompressed_bytes=len(raw),uncompressed_sha256=hashlib.sha256(raw).hexdigest()))
    dump(HERE/'manifest.json',manifest)
    print(json.dumps(dict(evidence_records=len(selected),archived_records=len(bundle['records']),profile_files=len(post['profile']),original_inputs=len(post['inputs']))))


if __name__=='__main__':main()
