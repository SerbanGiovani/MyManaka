"""Join explicit markers, native calls, original getters and encrypted snapshots."""
import gzip,json,hashlib
from pathlib import Path
from project_recovery import HERE,ROOT,build as project_build
def read(p):return json.loads(p.read_text(encoding='utf-8-sig'))
def require(v,m):
    if not v:raise ValueError(m)
def rows(p):return [json.loads(l) for l in gzip.decompress(p.read_bytes()).decode('utf8').splitlines()]
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def build(inputs=False):
    managed=rows(HERE/'managed.jsonl.gz');projection=read(HERE/'projection.json');variants=read(HERE/'variants.json')['variants'];bundle=read(HERE/'rea-runtime.json')
    status=next(r['normalized_result'] for r in bundle['records'] if r['operation']=='frida_session_status' and r['normalized_result']['pid']==47188)
    require(not status['messages_truncated'] and all(m['type']=='send' for m in status['messages']),'Native capture incomplete');events=[m['payload'] for m in status['messages']];require(len(events)==315 and not [e for e in events if e['kind']=='engine_error'],'Unexpected native message/error count')
    require(not [r for r in managed if r['kind']=='runner_error'],'Runner failed');cleanup=next(r for r in managed if r['kind']=='cleanup');require(cleanup['data']==dict(globalsRestored=True,stop=False),'Cleanup differs')
    results=[]
    for variant in variants:
        n=variant['name'];records=[r for r in managed if isinstance(r.get('data'),dict) and r['data'].get('name')==n];get=lambda k:[r for r in records if r['kind']==k]
        require(len(get('case_begin'))==len(get('case_end'))==1,'Missing/duplicate case boundary');begin,end=get('case_begin')[0],get('case_end')[0];require(begin['data']['backupExists'] and begin['data']['snapshot']==end['data']['snapshot'],'Fixture input/cleanup differs')
        native=[e for e in events if e['data'].get('name')==n];require(sum(e['kind']=='case_marker_begin' for e in native)==sum(e['kind']=='case_marker_end' for e in native)==1,'Native marker boundary differs')
        failure=n in ['system-truncated','system-invalid-text']
        if failure:
            require(len(get('case_exception'))==1 and not get('load_return') and not get('consumers') and not get('save_return'),'Damaged system silently recovered')
            error=get('case_exception')[0]['data']['error'];expected='System.ArgumentException' if n=='system-truncated' else 'System.FormatException';require(expected in error and 'SaveManager.LoadSystem' in error,'Exception not original system load')
            results.append(dict(name=n,outcome='native-system-load-exception',exception=expected));continue
        require(len(get('load_return'))==1 and len(get('save_return'))==2 and len(get('consumers'))==1 and not get('case_exception'),'Roundtrip incomplete')
        p=next(c for c in projection['cases'] if c['name']==n);require(not p['game_first_to_second'],'Second game roundtrip differs');s=p['system_first_to_second'];require(len(s)==1 and s[0]['path']=='/str:ManualSaveTime/str:value/1/str:ticks' and s[0]['after']>s[0]['before'],'Unexpected second system change')
        consumers=dict(get('consumers')[0]['data']);consumers.pop('name');require(consumers==p['expected_consumers'],'Original getter results differ from independently decoded values')
        for kind,ids in [('skill_read',[0,1,17,21,22,24]),('passive_read',[0,1,17,21,22,24]),('item_read',[10001,10002,10003]),('mission_read',[0,1,2])]:
            require(all(any(e['kind']==kind and e['data']['id']==i for e in native) for i in ids),'Missing original '+kind)
        if n=='backup-copy':
            require(len(get('pre_recovery_exception'))==len(get('native_copy_return'))==1 and 'System.FormatException' in get('pre_recovery_exception')[0]['data']['error'],'Original failed-read/copy sequence missing');copies=[e for e in native if e['kind']=='copy_enter'];require(len(copies)==1 and copies[0]['data']['source']['text']==str(ROOT/'working-profile/SaveDataBackup/1.sd') and copies[0]['data']['target']['text']==str(ROOT/'working-profile/SaveData/1.sd'),'Copy source/target differs');require(not p['game_baseline_to_first'],'Copied backup did not roundtrip to baseline')
        results.append(dict(name=n,outcome='two-native-load-save-passes',second_game_changed_leaves=0,selected_getter_result_rows_verified=12,selected_getter_scalar_values_verified=18,game_baseline_to_first_changes=len(p['game_baseline_to_first']),explicit_original_backup_copy=n=='backup-copy'))
    diagnostic=rows(HERE/'diagnostic-managed.jsonl.gz');errors=[r for r in diagnostic if r['kind']=='case_exception'];require(len(errors)==12 and sum("key '48'" in r['data']['error'] for r in errors)==10,'Diagnostic boundary differs')
    post=read(HERE/'post-state.json');require(post['plugins_restored'] and post['frida_closed'] and post['process']['process_absent'] and post['process']['wait_for_exit_returned'],'Process/plugin cleanup failed');require(all(x['unchanged'] for k in ['profile','preserved_test_profile','inputs'] for x in post[k]),'Protected input changed')
    if inputs:
        require(project_build()==projection,'Encrypted-capture projection differs')
        for p in projection['files']:require(sha(p['path'])==p['sha256'],'Capture changed')
        for v in variants:
            if v['path']:require(sha(v['path'])==v['sha256'],'Variant changed')
        for k in ['profile','preserved_test_profile']:
            for p in post[k]:require(sha(p['path'])==p['before']==p['after'],'Protected save changed')
        for p in post['inputs']:require(sha(p['path'])==sha(p['original_path'])==p['sha256'],'Protected engine/asset changed')
    return dict(authority='controlled-native-recovery-and-selected-getters',cases=results,clean_cases=12,successful_two_pass_cases=10,system_failure_cases=2,native_messages=315,encrypted_captures=len(projection['files']),verified_getter_result_rows=120,verified_getter_scalar_values=180,diagnostic_invalid_key48_cases=10,explicit_native_backup_copy_verified=True,all_runtime_consumers_verified=False,remaining=['Appearance renderer/animator and asynchronous application','Active mission updates/rewards, inventory consumption and skill effects','Natural UI recovery, aliases, migration and arbitrary field combinations'],protected_files_unchanged=True,process_exited_and_plugins_restored=True)
if __name__=='__main__':
    import argparse
    p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');p.add_argument('--inputs',action='store_true');a=p.parse_args();r=build(a.inputs)
    if a.check:require(r==read(HERE/'results.json'),'Results differ')
    else:(HERE/'results.json').write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(r,ensure_ascii=False,indent=2))
