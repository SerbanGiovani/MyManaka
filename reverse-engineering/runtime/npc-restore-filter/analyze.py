"""Join controlled fixed/absent/elevator consumers to passive native witnesses."""
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
def pointer(v):return int(v,16) if str(v).startswith('0x') else int(v)
def f32(v):return struct.unpack('<f',struct.pack('<f',v))[0]
def error(a,b,quat=False):
    require(len(a)==len(b) and all(math.isfinite(x) for x in a+b),'Invalid pose')
    direct=max(abs(f32(x)-f32(y)) for x,y in zip(a,b))
    return min(direct,max(abs(f32(x)+f32(y)) for x,y in zip(a,b))) if quat else direct
def pose(a,b,tolerance=0):
    d=error(a['position'],b['position']);q=error(a['rotation'],b['rotation'],True)
    require(max(d,q)<=tolerance,'Pose mismatch');return d,q

def projection(data):
    setting=read(HERE.parents[1]/'assets/save-settings.json')
    _,root,_=decode_save(data,setting['defaults_object']['settings']['encryptionPassword']['value'])
    s=root.strings()['GameStateData'].strings()['value'].strings()
    return dict(ciphertext_sha256=hashlib.sha256(data).hexdigest(),ciphertext_bytes=len(data),stage=s['CurrentStageType'],
        npcs=[dict(position=[n.strings()['Position'].strings()[k] for k in 'xyz'],rotation=[n.strings()['Rotation'].strings()[k] for k in 'xyzw'],exists=n.strings()['IsExist']) for n in s['NpcSaveDataList']])

def analyze(managed,events,stored):
    require(not [r for r in managed if r['kind'] in ('runner_error','cleanup_error')],'Controlled runner failed')
    require(not [e for e in events if e['kind']=='witness_error'],'Native witness failed')
    def phase(trial,kind):
        r=[r for r in managed if r['kind']==kind and r['data'].get('trial')==trial]
        require(len(r)==1,'Missing/duplicate managed phase '+kind);return r[0]
    def once(items,kind):
        r=[e for e in items if e['kind']==kind];require(len(r)==1,'Missing/duplicate native '+kind);return r[0]
    snapshot='snapshot-fixed-absent';elevator='elevator-existence'
    fixture=phase(snapshot,'snapshot_fixture')['data'];full=phase(snapshot,'snapshot_full')['data']['records'];reduced=phase(snapshot,'snapshot_reduced')['data']['records']
    require(len(fixture['npcs'])==4 and fixture['fixedCount']==2 and [n['fixedType'] for n in fixture['npcs'][:2]]==['None','None'] and all(n['fixedType']!='None' for n in fixture['npcs'][2:]),'Not genuine dynamic/fixed fixture')
    require(len(full)==2 and all(n['exists'] for n in full),'Fixed NPC snapshot exclusion differs')
    for n,r in zip(fixture['npcs'][:2],full):pose(n,r)
    require(len(reduced)==2 and [n['exists'] for n in reduced]==[True,False] and [n['pointer'] for n in full]==[n['pointer'] for n in reduced],'High-water absent marking differs')
    require(stored['stage']==10 and [n['exists'] for n in stored['npcs']]==[True,False],'Encrypted save exclusion state differs')
    loaded=phase(snapshot,'loaded')['data'];require(loaded['summary']['stage']=='Apart','Original Load stage normalization differs')
    for before,after,file_record in zip(reduced,loaded['records'],stored['npcs']):
        pose(before,file_record);pose(after,file_record);require(before['exists']==after['exists']==file_record['exists'],'Saved exists flag differs')
        require(pointer(before['pointer'])!=pointer(after['pointer']),'Load did not deserialize a new record')
    snap_begin=phase(snapshot,'trial_begin');snap_end=phase(snapshot,'complete')
    first=[e for e in events if snap_begin['frame']<=e['frame']<=snap_end['frame']]
    applies=[e for e in first if e['kind']=='npc_apply_enter'];require(len(applies)==2,'Snapshot producer capture missing')
    require([len(e['data']['manager']['npcs']) for e in applies]==[4,3] and all(e['data']['manager']['fixed']==2 and e['data']['manager']['loaded']==1 for e in applies),'Native snapshot manager inputs differ')
    # The original guard tests zero/nonzero; fixed type is an enum, not bool 1.
    require([[n['fixedType']!=0 for n in e['data']['manager']['npcs']] for e in applies]==[[False,False,True,True],[False,True,True]],'Native fixed type inputs differ')
    reduced_npcs=[fixture['npcs'][0]]+fixture['npcs'][2:]
    expected_pointers=[[pointer(n['pointer']) for n in ns] for ns in [fixture['npcs'],reduced_npcs]]
    require([[pointer(n['pointer']) for n in e['data']['manager']['npcs']] for e in applies]==expected_pointers,'Native/managed snapshot NPC identity differs')
    returns=[e for e in first if e['kind']=='npc_apply_leave'];require(len(returns)==2 and [[r['exists'] for r in e['data']['records']] for e in returns]==[[1,1],[1,0]],'Native high-water snapshot output differs')
    save=once(first,'save_enter');once(first,'save_leave');load=once(first,'load_enter');once(first,'load_leave')
    require(save['data']['type']==load['data']['type']==3 and save['data']['slot']==load['data']['slot']==1 and save['data']['isBackup'] is False,'Not native working main Save/Load')
    results=[]
    for trial in [snapshot,elevator]:
        begin=phase(trial,'trial_begin');end=phase(trial,'complete');inputs=phase(trial,'consumer_fixture');runtime=phase(trial,'runtime');cleanup=phase(trial,'cleanup')
        selected=[e for e in events if inputs['real']<=e['real']<=runtime['real']]
        records=inputs['data']['records']
        if trial==snapshot:
            require(inputs['data']['scene']=='Night_Demo 1' and inputs['data']['summary']['stage']=='Residence','Controlled stage reconciliation missing')
            expected=records[0];require(not [e for e in selected if e['kind']=='restore_bounds'],'Unexpected Residence elevator')
        else:
            require(inputs['data']['scene']=='Mall' and inputs['data']['summary']['stage']=='ShoppingMall' and inputs['data']['elevator'],'Actual mall elevator missing')
            require(len(records)==4 and [r['exists'] for r in records]==[True,True,False,False] and inputs['data']['contains']==[False,True,False,True],'Elevator fixture matrix differs')
            bounds=inputs['data']['bounds'];require(all(e>0 for e in bounds['extents']),'Degenerate actual Bounds')
            observed=[e for e in selected if e['kind']=='restore_bounds']
            require(len(observed)==2 and [e['data']['inside'] for e in observed]==[False,True],'Native existence-before-Bounds ordering differs')
            for r,e in zip(records[:2],observed):
                require(error(r['position'],e['data']['position'])==0 and error(e['data']['bounds'],bounds['center']+bounds['extents'])==0,'Native Bounds arguments differ')
            expected=records[0]
        nload=once(selected,'npc_load_enter');returned=once(selected,'npc_load_leave')
        require([r['exists'] for r in nload['data']['records']]==[int(r['exists']) for r in records] and returned['data']['manager']['loaded']==1,'Native restore input/loaded flag differs')
        queue=once(selected,'restore_queued');callback=once(selected,'restore_callback');instantiate=once(selected,'npc_instantiate_enter');instantiated=once(selected,'npc_instantiate_leave');warp=once(selected,'npc_warp_enter');warped=once(selected,'npc_warp_leave')
        for e in [queue,callback,instantiate]:
            require(pointer(e['data']['record']['pointer'])==pointer(expected['pointer']),'Excluded record reached restore consumer')
            pose(e['data']['record'],expected)
        require(queue['data']['closure']==callback['data']['closure'] and queue['data']['caller']=='0x42f6f7','Queue/closure identity differs')
        require(instantiate['data']['caller']=='0x432e18' and instantiate['data']['random']==instantiate['data']['fixed']==0,'Not original saved-record instantiate')
        require(warp['data']['caller']=='0x427c18' and instantiated['data']['result']==warp['data']['pointer']==warped['data']['pointer'],'Instantiate/Warp object identity differs')
        pose(warp['data'],expected);d,q=pose(warped['data'],expected,1e-5)
        require(queue['real']<callback['real']<=instantiate['real']<warp['real']<warped['real']<instantiated['real'],'Original delayed callback order differs')
        require(runtime['real']-returned['real']>=4 and runtime['data']['summary']['live']==len(runtime['data']['npcs'])==1,'Restore observation incomplete/duplicate')
        require(pointer(runtime['data']['npcs'][0]['pointer'])==pointer(instantiated['data']['result']),'Runtime object join differs')
        c=cleanup['data'];require(c['listRestored'] and c['mapRestored'] and c['savedListRestored'] and c['loaded'] is False and c['stop'] is False,'Trial cleanup incomplete')
        results.append(dict(trial=trial,begin_frame=begin['frame'],restore_frame=nload['frame'],queue_frame=queue['frame'],callback_frame=callback['frame'],callback_delay_seconds=callback['real']-queue['real'],queued=1,callbacks=1,instantiated=1,warp_position_max_error=d,warp_rotation_max_error=q,live_after_wait=1,wait_seconds=runtime['real']-returned['real'],restored_original_live=c['live'],restored_fixed_count=c['fixedCount']))
    return dict(authority='controlled-native-replay-with-passive-REA-witness',natural_positive_restore=False,
        fixed_snapshot=dict(actual_fixed_types=[n['fixedType'] for n in fixture['npcs'][2:]],live_input=4,fixed_count=2,records_after_full=2,records_after_removal=2,exists_after_removal=[True,False]),
        native_save=dict(stage=stored['stage'],npc_records=2,exists=[True,False],sha256=stored['ciphertext_sha256'],bytes=stored['ciphertext_bytes'],load_stage='Apart',explicit_consumer_stage='Residence'),
        elevator=dict(bounds=phase(elevator,'consumer_fixture')['data']['bounds'],record_exists=[True,True,False,False],contains=[False,True,False,True],native_bounds_calls=2,queued_records=1,absent_records_queued=0,inside_records_queued=0),
        trials=results,limits=['Explicit empty OnLoadData priming and temporary containers are controlled preconditions.','Fixed NPCs are excluded at snapshot production; no claim of a fixed-type field in NpcSaveData.','Elevator Bounds use the actual Mall singleton; boundary faces, invalid positions, destroyed elevator and scheduler interruption are not covered.','Only the producer/IsExist case uses native Save/Load; the elevator matrix is constructed in memory and directly consumed.','Natural default force=true reachability remains unchanged.'])

def build(inputs=False):
    bundle=read(HERE/'rea-runtime.json');status=next(r for r in bundle['records'] if r['operation']=='frida_session_status')
    require(not status['normalized_result']['messages_truncated'],'Truncated native capture')
    messages=status['normalized_result']['messages'];require(all(m['type']=='send' for m in messages),'Native script error')
    events=[dict(m['payload'],script_id=m['script_id']) for m in messages]
    result=analyze(rows(HERE/'managed.jsonl.gz'),events,read(HERE/'native-save.json'))
    engine=gzip.decompress((HERE/'engine.log.gz').read_bytes()).decode('utf8',errors='replace');require(not any('[Error' in l or '[Fatal' in l for l in engine.splitlines()),'Engine error')
    post=read(HERE/'post-state.json');require(post['process']['process_absent'] and post['process']['close_main_window_returned'] and post['process']['wait_for_exit_returned'] and post['frida_closed'] and post['plugins_restored'],'Process/plugin cleanup incomplete')
    require(all(p['unchanged'] for p in post['profile']+post['preserved_test_profile']+post['inputs']),'Protected files changed')
    ready=[e for e in events if e['kind']=='npc_filter_ready'];require(len(ready)==1 and ready[0]['data']['pid']==post['process']['pid'] and Path(ready[0]['data']['path'])==Path(post['game_root'])/'GameAssembly.dll','Observed module differs')
    result['engine_error_lines']=0;result['protected_files']=dict(user_data=len(post['profile']),prior_natural_profile=len(post['preserved_test_profile']),engine_assets=len(post['inputs']),unchanged=True)
    if inputs:
        require(projection((HERE/'.cache/native-snapshot.sd').read_bytes())==read(HERE/'native-save.json'),'Independent encrypted-file projection differs')
        for row in post['profile']+post['preserved_test_profile']:require(sha(row['path'])==row['before']==row['after'],'Protected save fingerprint differs')
        for row in post['inputs']:require(sha(row['path'])==sha(row['original_path'])==row['sha256'],'Protected input differs')
    return result

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');p.add_argument('--inputs',action='store_true');a=p.parse_args();r=build(a.inputs)
    if a.check:require(r==read(HERE/'results.json'),'Result differs')
    else:(HERE/'results.json').write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(r,ensure_ascii=False,indent=2))
