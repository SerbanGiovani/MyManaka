"""Keep successful controlled lifetime observations separate from crash diagnostics."""
import argparse
import gzip
import hashlib
import json
from pathlib import Path
import struct
HERE=Path(__file__).resolve().parent
def read(p):return json.loads(Path(p).read_text(encoding='utf-8-sig'))
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def rows(p):return [json.loads(l) for l in gzip.decompress(Path(p).read_bytes()).decode('utf8').splitlines()]
def require(v,m):
    if not v:raise ValueError(m)
def pointer(v):return int(v,16) if str(v).startswith('0x') else int(v)
def f32(v):return struct.unpack('<f',struct.pack('<f',v))[0]
def one(records,kind):
    found=[r for r in records if r['kind']==kind];require(len(found)==1,'Missing/duplicate '+kind);return found[0]
def case(managed,events,title=False):
    begin=one(managed,'trial_begin');queued=one(managed,'queued');after=one(managed,'after_interruption');resumed=one(managed,'scheduler_resumed');result=one(managed,'result');cleanup=one(managed,'cleanup');one(managed,'complete')
    trial=begin['data']['trial'];b=begin['data'];q=queued['data'];a=after['data'];s=resumed['data'];r=result['data']
    selected=[e for e in events if begin['real']<=e['real']<=result['real']]
    enqueue=one(selected,'restore_queued');constructor=one(selected,'time_model_constructor');callback=one(selected,'restore_callback_enter');attempt=one(selected,'instantiate_enter')
    calls=[e for e in selected if e['kind']=='time_invoke_enter'];clones=[e for e in selected if e['kind']=='npc_clone_enter']
    owner=b['originalManager'] if title else b['temporaryManager']
    require(pointer(q['manager'])==pointer(a['manager'])==pointer(r['manager'])==pointer(owner),'Managed receiver identity differs')
    require(pointer(enqueue['data']['manager']['pointer'])==pointer(callback['data']['manager']['pointer'])==pointer(attempt['data']['manager']['pointer'])==pointer(owner),'Native receiver identity differs')
    require(enqueue['data']['record']==callback['data']['record']==attempt['data']['record'] and pointer(enqueue['data']['record'])==pointer(b['record']),'Record identity differs')
    require(enqueue['data']['action']==constructor['data']['action'] and enqueue['data']['closure']==callback['data']['closure'],'Action/closure identity differs')
    require(pointer(constructor['data']['pointer'])==pointer(q['model'])==pointer(r['model']),'Time model identity differs')
    require(calls and all(pointer(e['data']['model']['pointer'])==pointer(q['model']) and e['data']['model']['action']==enqueue['data']['action'] and e['data']['model']['unscaled']==1 for e in calls),'Not the original unscaled model')
    require(q['pending'] and a['pending'] and q['schedulerEnabled'] is False and a['schedulerEnabled'] is False and s['schedulerEnabled'] is True,'Timing hold missing')
    require(f32(q['remaining'])==f32(a['remaining'])==f32(s['remaining']),'Hold changed the original remaining time')
    require(all(e['real']>=resumed['real'] for e in calls) and callback['real']>=resumed['real'],'Callback ran while scheduler held')
    require(attempt['data']['caller']=='0x432e18' and callback['frame']==attempt['frame'],'Not the selected original restore call')
    require(r['pending'] is False and r['remaining']<=0,'Original task not removed after the recorded attempt')
    if trial=='control':
        require(q['managerAlive'] and a['managerAlive'] and r['managerAlive'] and r['live']==len(r['objects'])==1 and len(clones)==1,'Live control did not instantiate exactly once')
        require(callback['data']['manager']['native']!='0x0' and clones[0]['data']['parent']!='0x0','Control had dead native receiver/parent')
        kind='one_object_created'
    else:
        require(q['managerAlive'] and a['managerAlive'] is False and r['managerAlive'] is False and callback['data']['manager']['native']=='0x0','Receiver was not destroyed before execution')
        destroys=[e for e in selected if e['kind']=='manager_destroy_enter' and pointer(e['data']['pointer'])==pointer(owner)]
        require(len(destroys)==1 and destroys[0]['real']<after['real']<callback['real'],'Original destruction order differs')
        require(not clones,'Destroyed receiver reached clone helper')
        if title:
            require(b['initialized'] is True and destroys[0]['data']['initialized']==1 and a['scene']==r['scene']=='Title' and a['gameManagerAlive'] is False,'Not initialized original-manager Title exit')
            exit_call=one(managed,'exit_callback');require(exit_call['data']['method']=='_OnClickSaveAndGoToTitle_b__18_1','Not original exit/fade callback')
        else:require(r['live']==0 and not r['objects'],'Destroyed temporary owner contains created objects')
        kind='attempted_without_observed_clone_then_dequeued'
    c=cleanup['data'];require(c['ownedModelRemoved'] and c['schedulerRestored'],'Probe cleanup failed')
    if not title:require(c['stateRestored'] and b['globalManagerUnchanged'],'Temporary manager was not isolated/restored')
    return dict(trial=trial,original_owner=title,begin_frame=begin['frame'],destroyed_before_callback=trial!='control',queue_frame=enqueue['frame'],callback_frame=callback['frame'],queue_entries=1,callback_entries=1,instantiate_attempts=1,clone_entries=len(clones),model_invocations=len(calls),initial_remaining=q['remaining'],remaining_during_hold=a['remaining'],pending_before_resume=True,pending_before_probe_cleanup=False,outcome=kind)
def analyze(temporary,original,events3,events4):
    require(not [r for r in temporary+original if r['kind'] in ('runner_error','cleanup_error')],'Controlled runner failed')
    results=[]
    for name in ['control','destroy','scene']:
        records=[r for r in temporary if isinstance(r.get('data'),dict) and r['data'].get('trial')==name]
        results.append(case(records,events3))
    results.append(case(original,events4,True))
    errors=[e for e in events3+events4 if e['kind']=='engine_error']
    groups={}
    for e in errors:
        d=e['data'];stack=d['stack'];require(isinstance(stack,dict) and not stack.get('truncated') and isinstance(stack.get('text'),str),'Error stack unavailable')
        require(d['context'] is None,'An error is attributed to the selected callback; inspect before claiming a clean consumer result')
        if 'SplineContainer.DisposeNativeSplinesCache' in stack['text']:name='SplineContainer finalizer'
        elif 'NpcInteractState.OnUpdate' in stack['text']:name='NPC interaction update'
        else:raise ValueError('Unclassified engine error stack')
        groups[name]=groups.get(name,0)+1
    return dict(authority='controlled-original-method-replay-with-entry-only-REA-witness',clean_cases=results,
        destruction_cancels_queue_immediately=False,expired_dead_receiver_tasks_attempt_once=True,dead_receiver_clone_entries=0,duplicate_queue_or_callback_entries=0,
        engine_error_events=len(errors),engine_error_stack_groups=groups,selected_restore_callback_error_events=0,
        limitation_on_early_exit='Entry-only evidence proves the attempt, lack of clone-helper entry and final queue removal. The exact return/early-exit branch is not dynamically attributed.',
        natural_reachability_verified=False,limits=['Scheduler enabled/disabled is an explicit timing hold; no natural timing probability is claimed.','Three temporary managers are never registered as global managers and have initialized=false; the separate Title case uses initialized=true on the real manager.','Direct scene reload generated unrelated finalizer and interaction errors; those are retained, not counted as restore exceptions.','No statement of complete arbitrary-callback cancellation, permanent persistence, future-scene behavior or uninstrumented equivalence.'])
def build(inputs=False):
    bundle=read(HERE/'rea-runtime.json');sessions=read(HERE/'manifest.json')['sessions'];statuses={r['normalized_result']['session_id']:r for r in bundle['records'] if r['operation']=='frida_session_status'}
    def events(session):
        n=statuses[session]['normalized_result'];require(not n['messages_truncated'],'Truncated native capture');require(all(m['type']=='send' for m in n['messages']),'Native script error');return [m['payload'] for m in n['messages']]
    r=analyze(rows(HERE/'clean-v3-managed.jsonl.gz'),rows(HERE/'managed.jsonl.gz'),events('5666d254-8985-4689-82fb-365acb0008fc'),events('3193486b-af59-4423-981b-8c309b60be17'))
    post=read(HERE/'post-state.json');require(all(p['process_absent'] and p['wait_for_exit_returned'] for p in post['clean_processes']) and post['plugins_restored'] and post['frida_closed'],'Clean process/plugin cleanup failed')
    require(all(x['unchanged'] for k in ['profile','preserved_test_profile','inputs'] for x in post[k]),'Protected inputs changed')
    crash=read(HERE/'crash-receipt.json');require(crash['pid']==59580 and crash['exception_code']=='e06d7363' and crash['native_probe_present'],'Diagnostic crash receipt differs')
    diag=rows(HERE/'diagnostic-managed.jsonl.gz');require(len([d for d in diag if d['kind']=='complete'])==4,'Diagnostic partial-pass boundary differs')
    r['diagnostic_run']=dict(pid=59580,completed_before_exit=4,not_counted_as_clean_cases=True,crash_code='0xe06d7363',cause='unassigned',missing_second_pass_cases=crash['missing_second_pass_cases'])
    for sid,pid in [('5666d254-8985-4689-82fb-365acb0008fc',74160),('3193486b-af59-4423-981b-8c309b60be17',10064)]:
        ready=next(e for e in events(sid) if e['kind'] in ['interruption_v3_ready','interruption_v4_ready']);require(ready['data']['pid']==pid and Path(ready['data']['path'])==Path(post['game_root'])/'GameAssembly.dll','Observed module identity differs')
    r['protected_files']=dict(user_data=len(post['profile']),prior_natural=len(post['preserved_test_profile']),engine_assets=len(post['inputs']),unchanged=True)
    if inputs:
        for k in ['profile','preserved_test_profile']:
            for x in post[k]:require(sha(x['path'])==x['before']==x['after'],'Protected save fingerprint differs')
        for x in post['inputs']:require(sha(x['path'])==sha(x['original_path'])==x['sha256'],'Protected engine/asset differs')
    return r
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');p.add_argument('--inputs',action='store_true');a=p.parse_args();r=build(a.inputs)
    if a.check:require(r==read(HERE/'results.json'),'Results differ')
    else:(HERE/'results.json').write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(r,ensure_ascii=False,indent=2))
