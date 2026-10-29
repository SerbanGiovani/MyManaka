"""Join an actual PC save, encrypted file, title load and original player Warp."""
import argparse
import gzip
import hashlib
import json
import math
from pathlib import Path
import struct
import sys

HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parents[1]/'salt'))
from save_codec import read as decode_save

def read(p):return json.loads(Path(p).read_text(encoding='utf-8-sig'))
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def rows(p):return [json.loads(l) for l in gzip.decompress(Path(p).read_bytes()).decode('utf8').splitlines()]
def require(v,m):
    if not v:raise ValueError(m)
def f32(v):return struct.unpack('<f',struct.pack('<f',v))[0]
def equal(a,b):return len(a)==len(b) and all(f32(x)==f32(y) for x,y in zip(a,b))

def projection(data):
    settings=read(HERE.parents[1]/'assets/save-settings.json')
    _,root,_=decode_save(data,settings['defaults_object']['settings']['encryptionPassword']['value'])
    state=root.strings()['GameStateData'].strings()['value'].strings()
    return dict(sha256=hashlib.sha256(data).hexdigest(),bytes=len(data),stage=state['CurrentStageType'],
        playerPosition=[state['PlayerPosition'].strings()[k] for k in 'xyz'],
        playerRotation=[state['PlayerRotation'].strings()[k] for k in 'xyzw'],
        npcs=[dict(exists=n.strings()['IsExist']) for n in state['NpcSaveDataList']])

def analyze(events,snapshots,paths,saved,baseline,post):
    require(not any(e['kind']=='snapshot_error' for e in snapshots),'Snapshot error')
    def find(kind):return [e for e in events if e['kind']==kind]
    def once(kind,predicate=lambda e:True):
        result=[e for e in find(kind) if predicate(e)]
        require(len(result)==1,'Missing/duplicate '+kind);return result[0]
    def paired(before):
        return once(before['kind'].replace('_enter','_leave'),lambda e:e['script_id']==before['script_id'] and e['data']['sequence']==before['data']['sequence'])
    def path_at(frame,name):return [e for e in paths if e['kind']=='save_path' and e['frame']==frame and e['data']['before']==name]
    require(not any(Path(f['path']).as_posix().endswith('/SaveData/1.sd') for f in baseline['disposable_profile']),'Main slot already existed')
    require(any(Path(f['path']).as_posix().endswith('/SaveDataBackup/1.sd') for f in baseline['disposable_profile']),'No initial backup')
    slots=find('title_slot_enter');require(len(slots)==2,'Expected absent and present title-slot attempts')
    first,last=slots
    require(all(e['data']['type']==3 and e['data']['slot']==1 for e in slots),'Wrong title slot')
    first_end=paired(first)
    require(not [e for e in find('save_load_enter') if first['real']<=e['real']<=first_end['real']],'Absent slot unexpectedly loaded')
    require(path_at(first['frame'],'SaveData/1.sd') and not path_at(first['frame'],'SaveDataBackup/1.sd'),'Absent slot did not check main path')
    new=once('save_load_enter',lambda e:e['data']['type']==5)
    require(new['data']['slot']==1 and new['data']['caller']=='0x4e4331','Not original new game')
    require(paired(new)['data']['state']['npcCount']==0,'New game not empty')
    pc=once('pc_manual_save_enter');pc_end=paired(pc)
    write=once('save_write_enter');returned=paired(write)
    require(pc['real']<write['real']<returned['real']<pc_end['real'],'PC/save nesting broken')
    require(write['data']['type']==3 and write['data']['slot']==-1 and write['data']['isBackup'] is False and write['data']['caller']=='0x4caf20','Not PC main save')
    preprocess=once('save_preprocess_enter',lambda e:write['real']<e['real']<returned['real'] and not e['data']['isSystem'])
    require(preprocess['data']['slot']==1 and preprocess['data']['isBackup'] is False,'Save routed to backup/wrong slot')
    saved_state=returned['data']['state']
    require(saved_state['stage']==saved['stage']==0 and not saved['npcs'] and saved_state['npcCount']==0,'Unexpected saved state')
    require(equal(saved_state['playerPosition'],saved['playerPosition']) and equal(saved_state['playerRotation'],saved['playerRotation']),'Saved-file pose differs')
    require(len(path_at(write['frame'],'SaveData/1.sd'))==1 and not path_at(write['frame'],'SaveDataBackup/1.sd'),'Save did not write main path')
    load=once('save_load_enter',lambda e:e['data']['type']==3);loaded=paired(load)
    require(load['data']['slot']==1 and load['data']['caller']=='0x4e5229' and load['frame']==last['frame'] and write['frame']<load['frame'],'Not subsequent original title load')
    require(loaded['data']['state']['pointer']!=saved_state['pointer'],'No new deserialized state object')
    state=loaded['data']['state']
    require(state['stage']==saved['stage'] and state['npcCount']==0,'Loaded state differs')
    require(equal(state['playerPosition'],saved['playerPosition']) and equal(state['playerRotation'],saved['playerRotation']),'Loaded-file pose differs')
    title_pre=once('save_preprocess_enter',lambda e:load['real']<e['real']<loaded['real'] and not e['data']['isSystem'])
    require(title_pre['data']['slot']==1 and title_pre['data']['isBackup'] is False,'Title loaded backup/wrong slot')
    require(len(path_at(load['frame'],'SaveData/1.sd'))==2 and not path_at(load['frame'],'SaveDataBackup/1.sd'),'Title main path missing')
    warp=once('player_warp',lambda e:e['frame']>load['frame'])
    require(warp['data']['caller']=='0x4979ff' and equal(warp['data']['position'],saved['playerPosition']) and equal(warp['data']['rotation'],saved['playerRotation']),'Original Warp pose differs')
    spring=once('springboard_enter',lambda e:e['frame']>load['frame'])
    start=once('ingame_start_enter',lambda e:e['frame']>spring['frame'])
    require(load['frame']<spring['frame']<start['frame']<=warp['frame'],'Scene startup order differs')
    starts=find('startup_delayed_enter');repops=find('npc_repop_enter')
    require(len(starts)==len(repops)==2 and not find('npc_load_enter'),'Default startup path differs')
    require(all(e['data']['debug']['force']==1 and e['data']['debug']['isDebug']==0 for e in starts),'Default guard differs')
    require(all(e['data']['caller']=='0x498bb3' and e['data']['manager']['loaded']==0 for e in repops),'Forced-repop path differs')
    current=repops[-1]['data']['manager']['pointer']
    settled=[s for s in snapshots if s['kind']=='snapshot' and warp['real']<=s['real']<=warp['real']+10 and s['data']['actualPlayer'] is not None]
    require(len(settled)>=10 and settled[-1]['real']>=warp['real']+9,'Insufficient actual-transform window')
    require(all(s['data']['scene']=='Apartment' and s['data']['stage']=='Apart' and s['data']['initialized'] is True and s['data']['loaded'] is False and s['data']['force'] is True and s['data']['debug'] is False and s['data']['npcSaved']==0 and int(s['data']['manager'])==int(current,16) for s in settled),'Scene/active-manager readiness differs')
    errors=[math.dist(s['data']['actualPlayer'],saved['playerPosition']) for s in settled]
    require(max(errors)<0.002,'Actual transform not at restored position')
    main=[f for f in post['disposable_profile'] if Path(f['path']).as_posix().endswith('/SaveData/1.sd')]
    require(len(main)==1 and main[0]['sha256']==saved['sha256'],'Main file changed/missing after title load')
    require(all(p['unchanged'] for p in post['profile']+post['inputs']),'Protected input changed')
    return dict(authority='passive-native-observation-of-original-user-input-in-isolated-save-root',
        absent_slot=dict(frame=first['frame'],load_called=False,path='SaveData/1.sd',backup_fallback_observed=False),
        new_game=dict(frame=new['frame'],slot=1),
        save=dict(frame=write['frame'],caller=write['data']['caller'],isBackup=False,preprocess_slot=1,path='SaveData/1.sd',sha256=saved['sha256'],bytes=saved['bytes'],stage=saved['stage'],position=saved['playerPosition'],rotation=saved['playerRotation'],npc_count=0),
        title_load=dict(frame=load['frame'],caller=load['data']['caller'],slot=1,isBackup=False,state_object_changed=True,springboard_frame=spring['frame'],ingame_start_frame=start['frame'],warp_frame=warp['frame'],warp_caller=warp['data']['caller'],position_and_rotation_float32_equal=True),
        scene=dict(name='Apartment',stage='Apart',active_manager=current,first_snapshot_frame=settled[0]['frame'],samples=len(settled),covered_seconds=settled[-1]['real']-warp['real'],first_position_error_metres=errors[0],maximum_position_error_metres=max(errors),actual_rotation_observed=False),
        npc=dict(startups=len(starts),forced_repop=len(repops),on_load_calls=0,isLoadedData=False,nonempty_restore_verified=False),
        protected_files=dict(user_data=len(post['profile']),engine_assets=len(post['inputs']),unchanged=True),
        limits=['No native backup recovery route observed in this selected UI path; absence of every recovery path is not proven.','This new-game/home round contains no NPCs; prior nonempty controlled and natural Residence scopes remain separate.','Rotation equality covers stored/loaded fields and original Warp arguments; actual Transform rotation is not sampled.','Actual Transform position is sampled on the Unity thread, allowing bounded physical settling.','No guard writes, OnLoadData replay, state patch or direct scene loading.'])

def build(inputs=False):
    baseline=read(HERE/'baseline.json');post=read(HERE/'post-state.json');bundle=read(HERE/'rea-runtime.json')
    status=next(r for r in bundle['records'] if r['operation']=='frida_session_status')
    require(not status['normalized_result']['messages_truncated'],'Native capture truncated')
    messages=status['normalized_result']['messages'];require(all(m['type']=='send' for m in messages),'Native script error')
    events=[dict(m['payload'],script_id=m['script_id']) for m in messages]
    ready=next(e for e in events if e['kind']=='natural_title_ready')
    require(ready['data']['pid']==post['process']['pid']==4276 and Path(ready['data']['path'])==Path(baseline['game_root'])/'GameAssembly.dll','Observed module identity differs')
    require(post['process']['process_absent'] and post['process']['close_main_window_returned'] and post['process']['wait_for_exit_returned'] and post['frida_closed'] and post['plugin']['previous_plugin_restored'],'Round cleanup incomplete')
    result=analyze(events,rows(HERE/'state.jsonl.gz'),rows(HERE/'paths.jsonl.gz'),read(HERE/'saved-main.json'),baseline,post)
    engine=gzip.decompress((HERE/'engine.log.gz').read_bytes()).decode('utf8',errors='replace')
    require(not any('[Error' in l or '[Fatal' in l for l in engine.splitlines()),'Engine error')
    result['engine_error_lines']=0
    if inputs:
        require(projection((HERE/'.cache/natural-main-1.sd').read_bytes())==read(HERE/'saved-main.json'),'Retained encrypted save differs')
        require(sha(HERE/'.cache/NaturalLoadObserver.dll')==post['plugin']['installed_for_round_sha256'],'Round observer archive differs')
        for row in post['profile']:require(sha(row['path'])==row['before']==row['after'],'UserData fingerprint differs')
        for row in post['inputs']:require(sha(row['path'])==sha(row['original_path'])==row['sha256'],'Engine/asset fingerprint differs')
    return result

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');p.add_argument('--inputs',action='store_true');a=p.parse_args();r=build(a.inputs)
    if a.check:require(r==read(HERE/'results.json'),'Results differ')
    else:(HERE/'results.json').write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(r,ensure_ascii=False,indent=2))
