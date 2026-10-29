"""Verify native observations, all retained field hashes and bounded failure cases."""
import gzip,json
from pathlib import Path
from project import HERE,project,decode,diff,ROOT
def read(p):return json.loads(p.read_text(encoding='utf-8-sig'))
def require(v,m):
    if not v:raise ValueError(m)
def build(inputs=False):
    managed=[json.loads(l) for l in gzip.decompress((HERE/'managed.jsonl.gz').read_bytes()).decode('utf8').splitlines()];projection=read(HERE/'projection.json');variants=read(HERE/'variants.json')['variants']
    require(not [r for r in managed if r['kind']=='runner_error'],'Runner failed')
    cleanup=[r for r in managed if r['kind']=='cleanup'];require(len(cleanup)==1 and cleanup[0]['data']==dict(globalsRestored=True,stop=False),'Cleanup incomplete')
    bundle=read(HERE/'rea-runtime.json');status=next(r for r in bundle['records'] if r['operation']=='frida_session_status');native=status['normalized_result'];require(native['pid']==77664 and not native['messages_truncated'] and all(m['type']=='send' for m in native['messages']),'Native capture incomplete')
    events=[m['payload'] for m in native['messages']];require(not [e for e in events if e['kind']=='engine_error'],'Unexpected logged engine exception')
    require(sum(e['kind']=='native_load_enter' for e in events)==22 and sum(e['kind']=='native_save_enter' for e in events)==19,'Native entry counts differ')
    results=[]
    for variant in variants:
        name=variant['name'];rows=[r for r in managed if isinstance(r.get('data'),dict) and r['data'].get('name')==name];bykind={k:[r for r in rows if r['kind']==k] for k in ['case_begin','load_return','save_return','case_exception','case_end']}
        require(len(bykind['case_begin'])==len(bykind['case_end'])==1,'Missing case boundaries')
        begin,end=bykind['case_begin'][0],bykind['case_end'][0];require(begin['data']['backupExists'],'No valid backup fixture')
        require(begin['data']['snapshot']==end['data']['snapshot'],'Global/selected state not restored between cases')
        selected=[e for e in events if begin['real']<=e['real']<=end['real']];loads=sum(e['kind']=='native_load_enter' for e in selected);saves=sum(e['kind']=='native_save_enter' for e in selected)
        failure=name in ['truncated','corrupt-block','invalid-text']
        if failure:
            require(len(bykind['case_exception'])==1 and not bykind['load_return'] and not bykind['save_return'] and loads==1 and saves==0,'Failure silently recovered or incomplete')
            error=bykind['case_exception'][0]['data']['error'];expected='System.ArgumentException' if name=='truncated' else 'System.FormatException';require(expected in error and 'SaveManager.Load' in error,'Failure not attributed to original load')
            result=dict(name=name,outcome='native-load-exception-with-valid-backup-present',exception=expected,automatic_backup_fallback_observed=False)
        else:
            require(len(bykind['load_return'])==1 and len(bykind['save_return'])==2 and not bykind['case_exception'] and loads==saves==2,'Incomplete two-pass original roundtrip')
            p=next(c for c in projection['cases'] if c['name']==name);require(not p['first_to_second'],'Game state changed on second roundtrip')
            changes=p['system_first_to_second'];require(len(changes)==1 and changes[0]['path']=='/str:ManualSaveTime/str:value/1/str:ticks' and changes[0]['after']>changes[0]['before'],'Unexpected system change')
            if name=='full':require(not p['input_to_first'],'Baseline failed roundtrip')
            if name=='advanced':require(p['input_to_first']==[dict(path='/str:SaveDataSlotIndex/str:value',before=0,after=1)],'Advanced sample unexpected change')
            result=dict(name=name,outcome='two-native-load-save-passes',input_to_first_changed_leaves=len(p['input_to_first']),second_game_changed_leaves=0,system_changed_paths=[x['path'] for x in changes])
        results.append(result)
    baseline=next(p for p in projection['files'] if Path(p['path']).name=='baseline.sd');system=next(p for p in projection['files'] if Path(p['path']).name=='baseline-system.sd')
    coverage={k:len(v) for p in [baseline,system] for k,v in p['fields'].items() if k in ['GameStateData','PlayerCustomData','OptionData','TutorialData']};require(coverage==dict(GameStateData=107,PlayerCustomData=66,OptionData=68,TutorialData=15),'Declared field coverage differs')
    post=read(HERE/'post-state.json');require(post['plugins_restored'] and post['process']['process_absent'] and post['process']['wait_for_exit_returned'],'Process/plugins cleanup failed');require(all(x['unchanged'] for k in ['profile','preserved_test_profile','inputs'] for x in post[k]),'Protected input changed')
    if inputs:
        from collect import sha
        for p in projection['files']:require(project(Path(p['path']))==p,'Encrypted capture projection differs')
        for p in variants:require(sha(Path(p['path']))==p['sha256'],'Variant changed')
        for k in ['profile','preserved_test_profile']:
            for p in post[k]:require(sha(Path(p['path']))==p['before']==p['after'],'Protected save changed')
        for p in post['inputs']:require(sha(Path(p['path']))==sha(Path(p['original_path']))==p['sha256'],'Protected engine/asset changed')
        for p in projection['cases']:
            n=p['name'];require(diff(decode(ROOT/'variants'/(n+'.sd')),decode(ROOT/'captures'/(n+'-pass1.sd')))==p['input_to_first'] and diff(decode(ROOT/'captures'/(n+'-pass1.sd')),decode(ROOT/'captures'/(n+'-pass2.sd')))==p['first_to_second'],'Stored differences differ')
    return dict(authority='controlled-native-two-pass-save-load',cases=results,serialized_declared_fields=coverage,total_serialized_declared_fields=sum(coverage.values()),game_root_keys=baseline['root_keys'],system_root_keys=system['root_keys'],native_load_entries=22,native_save_entries=19,retained_native_messages=len(events),retained_encrypted_captures=len(projection['files']),engine_error_events=0,frida_detach_confirmed=False,normal_process_exit=True,natural_only=False,all_runtime_consumers_verified=False,remaining=['Explicit native backup copy/recovery; no UI recovery claim','Missing/corrupt system file and absent whole game file','Inventory/appearance/mission/skill runtime consumers and actual gameplay equivalence','Object-reference alias restoration, migration and arbitrary missing fields are not exhaustively covered'])
if __name__=='__main__':
    import argparse
    p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');p.add_argument('--inputs',action='store_true');a=p.parse_args();r=build(a.inputs)
    if a.check:require(r==read(HERE/'results.json'),'Results differ')
    else:(HERE/'results.json').write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(r,ensure_ascii=False,indent=2))
