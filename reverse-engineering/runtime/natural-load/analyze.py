"""Validate passive title/new-game traces and distinguish imported data from production."""
import argparse
import gzip
import hashlib
import json
from pathlib import Path
import struct
import sys

HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parents[1]/'salt'))
from save_codec import read as decode_save


def read(p):return json.loads(Path(p).read_text(encoding='utf-8-sig'))
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def rows(p):return [json.loads(s) for s in gzip.decompress(Path(p).read_bytes()).decode('utf8').splitlines()]
def require(value,message):
    if not value:raise ValueError(message)
def single(v):return struct.unpack('<f',struct.pack('<f',v))[0]
def equal(a,b):return len(a)==len(b) and all(single(x)==single(y) for x,y in zip(a,b))


def projection(data):
    settings=read(HERE.parents[1]/'assets/save-settings.json')
    _,root,_=decode_save(data,settings['defaults_object']['settings']['encryptionPassword']['value'])
    state=root.strings()['GameStateData'].strings()['value'].strings()
    def vector(v,keys):return [v.strings()[k] for k in keys]
    return dict(sha256=hashlib.sha256(data).hexdigest(),bytes=len(data),stage=state['CurrentStageType'],
        playerPosition=vector(state['PlayerPosition'],'xyz'),playerRotation=vector(state['PlayerRotation'],'xyzw'),
        npcs=[dict(position=vector(d.strings()['Position'],'xyz'),rotation=vector(d.strings()['Rotation'],'xyzw'),exists=d.strings()['IsExist']) for d in state['NpcSaveDataList']])


def analyze(events,snapshots,paths,files):
    require(not any(e['kind'] in ('snapshot_error','witness_error') for e in snapshots+events),'Observer failed')
    def find(kind):return [e for e in events if e['kind']==kind]
    def once(kind,predicate=lambda e:True):
        result=[e for e in find(kind) if predicate(e)];require(len(result)==1,'Missing/duplicate '+kind);return result[0]
    imports=files['imported'];saved=files['natural_backup']
    require(imports['stage']==11 and len(imports['npcs'])==3 and all(n['exists'] for n in imports['npcs']),'Imported fixture identity differs')
    slot=once('title_slot_enter');require(slot['data']['type']==3 and slot['data']['slot']==0,'Imported title slot differs')
    load=once('save_load_enter',lambda e:e['data'].get('type')==3)
    require(load['data']['caller']=='0x4e5229' and load['frame']==slot['frame'],'Not original title load call')
    loaded=once('save_load_leave',lambda e:e['script_id']==load['script_id'] and e['data']['sequence']==load['data']['sequence'])
    data=loaded['data']['state'];require(data['stage']==0 and data['npcCount']==data['npcExisting']==3,'Imported load did not retain nonempty records or normalize stage')
    require(equal(data['playerPosition'],imports['playerPosition']),'Imported pose changed unexpectedly')
    for observed,stored in zip(data['npcs'],imports['npcs']):
        require(equal(observed['position'],stored['position']) and equal(observed['rotation'],stored['rotation']),'Imported NPC payload differs')
    constructor=once('debug_cctor_leave');require(constructor['data']['debug']==dict(force=1,isDebug=0,initialized=0),'Default constructor guard differs')
    starts=find('startup_delayed_enter');require(len(starts)==2 and all(e['data']['debug']['force']==1 for e in starts),'Default startup branch differs')
    repops=[e for e in find('npc_repop_enter') if e['data']['caller']=='0x498bb3'];require(len(repops)==2,'Missing original forced-repop calls')
    require(not find('npc_load_enter'),'OnLoadData unexpectedly reached naturally')
    require(not [e for e in find('npc_instantiate') if e['data']['record']!='0x0'],'Saved NPC record unexpectedly used')
    new=once('save_load_enter',lambda e:e['data'].get('type')==5)
    require(new['data']['slot']==1 and new['data']['caller']=='0x4e4331','Not original new-game slot action')
    created=once('save_load_leave',lambda e:e['script_id']==new['script_id'] and e['data']['sequence']==new['data']['sequence'])
    require(created['data']['state']['npcCount']==0,'New game retained imported NPC data')
    root=created['data']['state']['pointer']
    residences=[r for r in snapshots if r['kind']=='snapshot' and r['frame']>new['frame'] and r['data']['scene']=='Night_Demo 1']
    require(residences and all(r['data']['loaded'] is False and r['data']['npcSaved']==0 for r in residences),'Residence NPC capture guard differs')
    aligned=[r for r in residences if r['data']['stage']=='Residence']
    require(aligned,'Scene and stored stage never aligned')
    dynamic=[r for r in aligned if r['data']['live']>r['data']['fixedCount']]
    require(dynamic,'No non-fixed live NPC evidence')
    peak=max(dynamic,key=lambda e:e['data']['live'])
    apply=[e for e in find('npc_apply_enter') if e['data']['state'] and e['data']['state']['pointer']==root and e['data']['state']['stage']==10]
    require(len(apply)>=1,'Missing original ApplyGameState entry in NPC scene')
    for before in apply:
        after=once('npc_apply_leave',lambda e:e.get('script_id')==before.get('script_id') and e['data']['sequence']==before['data']['sequence'])
        require(before['data']['manager']['loaded']==after['data']['manager']['loaded']==0,'Snapshot guard changed')
        require(before['data']['state']['npcCount']==after['data']['state']['npcCount']==0,'Blocked snapshot unexpectedly produced records')
    active=[s for s in snapshots if s['kind']=='snapshot' and s['data']['manager'] is not None]
    require(active and all(s['data']['force'] is True and s['data']['debug'] is False and s['data']['loaded'] is False for s in active),'Natural guard changed during capture')
    write=once('save_write_enter');returned=once('save_write_leave')
    require(write['data']['type']==3 and write['data']['slot']==-1 and write['data']['state']['pointer']==root,'Natural current-slot save differs')
    require(write['data']['state']['stage']==0 and saved['stage']==0 and not saved['npcs'],'Natural backup contained newly captured NPCs')
    require(equal(returned['data']['state']['playerPosition'],saved['playerPosition']) and equal(returned['data']['state']['playerRotation'],saved['playerRotation']),'Native backup pose differs from file')
    writes=[p for p in paths if p['kind']=='save_path' and p['frame']==write['frame'] and p['data']['before'].endswith('/1.sd')]
    require(len(writes)==1 and writes[0]['data']['before']=='SaveDataBackup/1.sd','Backup and main slot were conflated')
    require(not [e for e in find('title_slot_enter') if e['frame']>write['frame']],'Fresh title readback scope changed')
    final=next(e for e in reversed(snapshots) if e['kind']=='snapshot')
    require(final['data']['scene']=='Title' and final['data']['manager'] is None,'Not retained at title')
    first_warp=next(e for e in find('player_warp') if e['frame']>=load['frame'])
    require(equal(first_warp['data']['position'],imports['playerPosition']),'Imported player Warp differed')
    return dict(authority='passive-natural-input-with-explicitly-controlled-import-fixture',
        title_import=dict(source='prior controlled native file',npc_records_read=3,npc_restore_calls=0,saved_record_instantiations=0,stored_stage=11,loaded_stage=0,scene='Apartment',imported_player_pose_used=True),
        default_guard=dict(force_create_npc=True,is_debug=False,observed_cctor_calls=1,forced_startup_branches=2,on_load_data_calls=0),
        natural_new_game=dict(slot=1,initial_npc_records=0,scene='Night_Demo 1',stage=10,peak_live=peak['data']['live'],fixed_at_peak=peak['data']['fixedCount'],nonfixed_at_peak=peak['data']['live']-peak['data']['fixedCount'],sampled_apply_pairs=len(apply),captured_npc_records=0),
        natural_save=dict(type=3,slot_argument=-1,observed_path='SaveDataBackup/1.sd',stage=0,npc_records=0,pose_matches_native_return=True),
        fresh_title_readback_completed=False,last_recorded_scene='Title',
        boundary='Default shipped guards block new NPC snapshots and saved-record restoration in the observed routes. Nonempty imported data is not evidence of natural production; conditional force=false reachability is static, not a natural positive test.')


def build(inputs=False):
    bundle=read(HERE/'rea-runtime.json');statuses=[e for e in bundle['records'] if e['operation']=='frida_session_status'];require(len(statuses)==1,'Expected one final runtime checkpoint')
    n=statuses[0]['normalized_result'];require(not n['messages_truncated'] and not any(m['type']=='error' for m in n['messages']),'REA capture failed/truncated')
    events=[dict(m['payload'],script_id=m['script_id']) for m in n['messages'] if m['type']=='send']
    files=read(HERE/'save-projections.json')
    if inputs:
        require(projection((HERE/'.cache/nonempty-input.sd').read_bytes())==files['imported'],'Imported encrypted file differs')
        require(projection((HERE/'.cache/natural-backup-1.sd').read_bytes())==files['natural_backup'],'Natural encrypted backup differs')
    result=analyze(events,rows(HERE/'state.jsonl.gz'),rows(HERE/'native-paths.jsonl.gz'),files)
    require('[Error' not in gzip.decompress((HERE/'engine.log.gz').read_bytes()).decode('utf8'),'Engine errors during observed run')
    post=read(HERE/'post-state.json');require(all(p['unchanged'] for p in post['profile']),'Original UserData changed')
    require(not post['main_slot_1_exists'] and post['backup_slot_1_exists'],'Natural backup/main-slot inventory differs')
    require(post['process']['status']=='suspended' and post['process']['ntstatus']==0 and post['frida_closed'],'Requested pause incomplete')
    require(not post['process']['present_at_final_check'] and not post['process']['in_memory_resume_available'],'Final process state differs')
    require(post['process_exit']['pid']==post['process']['pid'] and any(e['id']==1002 for e in post['process_exit']['events']),'Later application-hang closure receipt differs')
    result['profile_files_unchanged']=len(post['profile']);result['process_was_suspended']=True;result['process_present_at_final_check']=False;result['resume_requires_relaunch']=True;result['engine_error_lines_in_observation_window']=0
    return result


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--check',action='store_true');p.add_argument('--inputs',action='store_true');a=p.parse_args();result=build(a.inputs)
    if a.check:require(result==read(HERE/'results.json'),'Saved analysis differs')
    else:(HERE/'results.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
    print(json.dumps(result,indent=2))


if __name__=='__main__':main()
