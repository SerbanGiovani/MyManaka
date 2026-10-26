"""Join a controlled native save/load with independent file and engine witnesses.

No game methods are executed here. --inputs additionally re-decodes the private
encrypted fixture snapshot; the tracked projection permits offline comparisons.
"""
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
def rows(p):return [json.loads(x) for x in gzip.decompress(Path(p).read_bytes()).decode('utf8').splitlines()]
def require(v,message):
    if not v:raise ValueError(message)


def projection(data):
    settings=read(HERE.parents[1]/'assets/save-settings.json')
    password=settings['defaults_object']['settings']['encryptionPassword']['value']
    _,root,_=decode_save(data,password)
    state=root.strings()['GameStateData'].strings()['value'].strings()
    def vector(v,keys):return [v.strings()[k] for k in keys]
    def npc(v):
        d=v.strings();return dict(position=vector(d['Position'],'xyz'),rotation=vector(d['Rotation'],'xyzw'),exists=d['IsExist'])
    def drop(v):
        d=v.strings();return dict(item=d['ItemType'],stage=d['StageType'],dropped=d['IsDropped'],reserve=d['IsReserve'],position=vector(d['Position'],'xyz'),rotation=vector(d['Rotation'],'xyzw'))
    return dict(ciphertext_sha256=hashlib.sha256(data).hexdigest(),ciphertext_bytes=len(data),stage=state['CurrentStageType'],
        npcs=[npc(n) for n in state['NpcSaveDataList']],drop_records=[drop(v) for k,v in state['DropDataDict'].entries if k in (0,1,3,4)],
        reserve=[drop(v) for v in state['ReserveDropList']])


def pointer(v):return int(v,16) if str(v).startswith('0x') else int(v)
def single(x):return struct.unpack('<f',struct.pack('<f',x))[0]
def delta(a,b,quaternion=False):
    require(len(a)==len(b) and all(math.isfinite(v) for v in a+b),'Invalid pose')
    direct=max(abs(single(x)-single(y)) for x,y in zip(a,b))
    return min(direct,max(abs(single(x)+single(y)) for x,y in zip(a,b))) if quaternion else direct
def pose(a,b,tolerance=0):
    d=delta(a['position'],b['position']);q=delta(a['rotation'],b['rotation'],True)
    require(d<=tolerance and q<=max(tolerance,0),f'Pose differs: position {d}, rotation {q}')
    return d,q


def analyze(managed,events,stored):
    require(not any(r['kind'] in ('runner_error','cleanup_error') for r in managed),'Controlled trial failed')
    def one(kind):
        found=[r for r in managed if r['kind']==kind];require(len(found)==1,'Missing/duplicate phase '+kind);return found[0]
    fixture=one('fixture');saved=one('saved');disturbed=one('disturbed');loaded=one('loaded');reconciled=one('reconciled')
    consumers=one('consumers_return');runtime=one('runtime');replay=one('reserve_replay');cleanup=one('cleanup');complete=one('complete')
    f=fixture['data'];l=loaded['data'];r=runtime['data'];c=cleanup['data'];rp=replay['data']
    begin,end=fixture['frame'],complete['frame']
    selected=[e for e in events if begin<=e.get('frame',-1)<=end]
    def matching(kind,**values):return [e for e in selected if e['kind']==kind and all(e['data'].get(k)==v for k,v in values.items())]
    def single_event(kind,**values):
        found=matching(kind,**values);require(len(found)==1,f'Expected one {kind} {values}, got {len(found)}');return found[0]
    require(begin==saved['frame']==loaded['frame'] and begin<runtime['frame']<=end,'Phase frame order differs')
    require(single_event('native_save_enter')['data']['type']==3 and single_event('native_load_enter')['data']['type']==3,'Not original manual-slot Save/Load')
    single_event('native_save_leave');single_event('native_load_leave')
    require(stored['stage']==11 and l['summary']['stage']=='Apart' and reconciled['data']['stage']=='ShoppingMall','Stage normalization/reconciliation differs')
    require(f['summary']['state']!=l['summary']['state'],'Load retained original root')
    require(disturbed['data']['npcs']==disturbed['data']['reserve']==disturbed['data']['live']==0,'Working graph was not disturbed')
    require(len(stored['npcs'])==len(f['npc'])==len(l['npc'])==3,'Expected three NPC records')
    for before,after,file_record in zip(f['npc'],l['npc'],stored['npcs']):
        pose(before,file_record);pose(after,file_record)
        require(pointer(before['pointer'])!=pointer(after['pointer']),'NPC record identity reused across Load')
    expected={pointer(n['pointer']):(n,s) for n,s in zip(l['npc'],stored['npcs']) if s['exists']}
    calls=[e for e in matching('native_npc_instantiate') if e['data']['record'] is not None]
    require(len(calls)==len(expected)==3,'Nonempty native NPC restore coverage differs')
    require({pointer(e['data']['record']['pointer']) for e in calls}==set(expected),'NPC record/instantiate join differs')
    restored=[];initial_poses={};max_pos=max_rot=0
    for event in calls:
        data=event['data'];record,file_record=expected[pointer(data['record']['pointer'])]
        require(data['random']==data['fixed']==0 and data['caller']=='0x432e18','Not selected OnLoadData closure')
        pose(data['record'],file_record)
        index=selected.index(event)
        warp=next(e for e in selected[index+1:] if e['kind']=='native_npc_warp_enter')
        require(warp['frame']==event['frame'] and warp['data']['caller']=='0x427c18','Initialize -> Warp join differs')
        pose(warp['data'],file_record)
        returned=single_event('native_npc_warp_leave',id=warp['data']['id'])
        d,q=pose(returned['data'],file_record,1e-5);max_pos=max(max_pos,d);max_rot=max(max_rot,q)
        restored.append(pointer(returned['data']['pointer']))
        initial_poses[pointer(returned['data']['pointer'])]=returned['data']['position']
    require(set(restored)=={pointer(n['pointer']) for n in r['npcs']} and all(n['active'] for n in r['npcs']),'Restored Unity NPC identities differ')
    require(r['summary']['live']==3,'Unexpected restored manager population')
    moved=sum(math.dist(initial_poses[pointer(n['pointer'])],n['position'])>1e-4 for n in r['npcs'])
    file_drops={x['item']:x for x in stored['drop_records']}
    require(file_drops[0]['dropped'] and file_drops[0]['stage']==11,'Missing current-stage dropped input')
    require(file_drops[4]['dropped'] and file_drops[4]['stage']==0,'Missing other-stage dropped control')
    for key,item in [('drop',0),('otherStage',4)]:
        pose(f[key],file_drops[item]);pose(l[key],file_drops[item])
    current=single_event('native_drop_enter',item=0,caller='0x48ac81')
    pose(current['data'],file_drops[0]);pose(r['current'],file_drops[0])
    require(r['current']['active'] and not r['otherStage']['active'],'Current/other-stage activation differs')
    single_event('native_hide_enter',item=4,caller='0x48ac9e')
    require(r['otherStage']['record']['isDropped'],'Hide incorrectly cleared IsDropped')
    require(len(stored['reserve'])==2 and {d['item']:d['stage'] for d in stored['reserve']}=={1:11,3:0},'Reserve controls differ')
    require(l['summary']['reserve']==2 and consumers['data']['summary']['reserve']==r['summary']['reserve']==rp['summary']['reserve']==1,'Reserve queue counts differ')
    reserve=single_event('native_drop_enter',item=1)
    require(reserve['data']['caller']=='0x48af4e','Reserve did not call original Drop')
    pose(reserve['data'],r['reserved']);require(r['reserved']['active'] and r['reserved']['record']['isDropped'],'Reserved world object not active')
    before=single_event('reserve_predicate_enter',item=1);after=single_event('reserve_predicate_leave',item=1)
    require(before['data']['reserve']==1 and after['data']['reserve']==0 and after['data']['remove']==1,'Reserve flag/remove witness differs')
    require(pointer(before['data']['pointer'])==pointer(l['reserve'][0]['pointer']),'Loaded reserve identity differs')
    require(len(matching('reserve_predicate_leave',item=3))==2 and all(e['data']['reserve']==1 and e['data']['remove']==0 for e in matching('reserve_predicate_leave',item=3)),'Other-stage reserve incorrectly consumed')
    require(not matching('native_drop_enter',item=3),'Other-stage reserve was dropped')
    require(len(rp['pending'])==1 and rp['pending'][0]['item']=='Pants' and rp['pending'][0]['isReserve'],'Pending other-stage record lost')
    require(rp['reserved']['component']==r['reserved']['component'],'Reserve replay replaced the world object')
    require(c['listRestored'] and c['mapRestored'] and c['cacheRestored'] and c['spawn']==c['oldSpawn'] and not c['stop'],'Controlled cleanup failed')
    require(c['summary']['live']==30 and c['summary']['npcs']==30 and c['summary']['reserve']==0,'Original manager/record populations not restored')
    require(complete['data']['trials']==1,'Unexpected completed-trial count')
    return dict(authority='controlled-native-entry-replay-in-full-game',natural_trials=0,completed_trials=1,
        frame_range=[begin,end],wait_seconds=runtime['real']-consumers['real'],
        native_save_load_pairs=1,root_identity_changed=True,npc=dict(stored=3,instantiated=3,warped=3,active_runtime_objects=3,
            max_warp_position_delta=max_pos,max_warp_quaternion_delta=max_rot,moved_after_spawn=moved),
        drops=dict(current_stage_activated=1,other_stage_hidden=1,hide_keeps_dropped=True),
        reserve=dict(stored=2,matching_consumed=1,other_stage_retained=1,matching_drop_calls_including_replay=1,other_stage_false_predicates=2),
        stage=dict(stored=11,native_load=0,controlled_consumer_scene=11),cleanup=dict(original_live_npcs=30,references_and_spawn_counter_restored=True,applier_reenabled=True),
        limitations=['Consumers are explicitly replayed after setting the loaded stage to the actual Mall; this is not a natural title-to-Mall load lifecycle.',
            'Three valid dynamic NPC records and selected drop/reserve branches only; fixed NPCs, IsExist=false, elevator exclusion and interrupted callbacks remain untested.',
            'GetCache reactivates the existing hidden current-item cache in this trial; cold-cache reconstruction of that item is not established.',
            'Warp return is compared immediately; subsequent normal NPC movement is not a serialization error.',
            'No replacement executable, all-fields equality, navigation-path equivalence or cross-version migration is claimed.'])


def build(inputs=False):
    bundle=read(HERE/'rea-runtime.json');status=[r for r in bundle['records'] if r['operation']=='frida_session_status'];require(len(status)==1,'Expected final retained checkpoint')
    n=status[0]['normalized_result'];require(not n['messages_truncated'],'Truncated REA checkpoint')
    require(not any(m['type']=='error' or m.get('payload',{}).get('kind')=='witness_error' for m in n['messages']),'REA witness failed')
    events=[m['payload'] for m in n['messages'] if m['type']=='send']
    stored=read(HERE/'native-save.json')
    if inputs:require(projection((HERE/'.cache/native-roundtrip.sd').read_bytes())==stored,'Independent native-file projection differs')
    result=analyze(rows(HERE/'managed.jsonl.gz'),events,stored)
    engine=gzip.decompress((HERE/'engine.log.gz').read_bytes()).decode('utf8');require('[Error' not in engine,'Engine error in completed trial')
    post=read(HERE/'post-state.json');require(all(p['unchanged'] for p in post['profile']) and all(p['matches_original'] for p in post['inputs']) and post['observer_plugin']['unchanged'],'Baseline file checks failed')
    result['profile_files_unchanged']=len(post['profile']);result['pinned_inputs_unchanged']=len(post['inputs']);result['engine_error_lines']=0
    return result


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--check',action='store_true');p.add_argument('--inputs',action='store_true');a=p.parse_args()
    result=build(a.inputs)
    if a.check:require(result==read(HERE/'results.json'),'Saved results differ')
    else:(HERE/'results.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(result,ensure_ascii=False,indent=2))


if __name__=='__main__':main()
