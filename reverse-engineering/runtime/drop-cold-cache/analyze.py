"""Distinguish manager cold/warm/stale caches from an asset-bundle cold load."""
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
def equal(a,b):return len(a)==len(b) and all(f32(x)==f32(y) for x,y in zip(a,b))
def pose(a,b):require(equal(a['position'],b['position']) and equal(a['rotation'],b['rotation']),'Pose differs')
def projection(data):
    settings=read(HERE.parents[1]/'assets/save-settings.json')
    _,root,_=decode_save(data,settings['defaults_object']['settings']['encryptionPassword']['value'])
    s=root.strings()['GameStateData'].strings()['value'].strings()
    def drop(k,v):
        d=v.strings();return dict(item=k,dropped=d['IsDropped'],stage=d['StageType'],position=[d['Position'].strings()[k] for k in 'xyz'],rotation=[d['Rotation'].strings()[k] for k in 'xyzw'])
    return dict(sha256=hashlib.sha256(data).hexdigest(),bytes=len(data),stage=s['CurrentStageType'],drops=[drop(k,v) for k,v in s['DropDataDict'].entries if k in (0,4)])
def analyze(managed,events,stored):
    require(not any(r['kind'] in ('runner_error','cleanup_error') for r in managed),'Runner failed')
    def one(kind):
        found=[r for r in managed if r['kind']==kind];require(len(found)==1,'Missing/duplicate '+kind);return found[0]
    fixture=one('fixture');loaded=one('loaded');cold_before=one('cold_before');cold=one('cold_return');warm=one('warm_return');stale_before=one('stale_before');stale=one('stale_return');late=one('runtime');cleanup=one('cleanup')
    require(fixture['data']['snapshot']['cacheCount']==cold_before['data']['cacheCount']==0,'Manager cache not cold')
    require(fixture['data']['snapshot']['state']!=loaded['data']['snapshot']['state'],'Load retained state root')
    require(stored['stage']==0 and len(stored['drops'])==2,'Wrong stored stage/items')
    file_items={d['item']:d for d in stored['drops']}
    require(file_items[0]['dropped'] and file_items[0]['stage']==0 and file_items[4]['dropped'] and file_items[4]['stage']==10,'Stored current/other-stage guard differs')
    for record in fixture['data']['records']+loaded['data']['records']:pose(record,file_items[record['item']])
    selected=[e for e in events if fixture['real']<=e['real']<=late['real']]
    require(not [e for e in selected if e['kind']=='asset_load_during_fixture'],'Unexpected bundle asset load')
    def find(kind):return [e for e in selected if e['kind']==kind]
    def native_one(kind):
        found=find(kind);require(len(found)==1,'Missing/duplicate native '+kind);return found[0]
    for kind in ['save_enter','save_leave','load_enter','load_leave']:native_one(kind)
    require(native_one('save_enter')['data']['type']==native_one('load_enter')['data']['type']==3 and native_one('save_enter')['data']['isBackup'] is False,'Not native main save/load')
    restores=find('restore_enter');returns=find('restore_leave');require(len(restores)==len(returns)==3,'Restore replay count differs')
    get=find('cache_enter');got=find('cache_leave');clones=find('clone_enter');cloned=find('clone_leave');inits=find('controller_init_enter');initialized=find('controller_init_leave')
    require(len(get)==len(got)==6 and sorted(e['data']['item'] for e in get)==[0,0,0,4,4,4],'Cache calls/items differ')
    require(len(clones)==len(cloned)==len(inits)==len(initialized)==3,'Cold/stale initialization count differs')
    grouped=[]
    for enter,leave,after in zip(restores,returns,[cold,warm,stale]):
        require(enter['frame']==leave['frame']==after['frame'] and enter['real']<leave['real']<after['real'],'Restore was not synchronous in the recorded frame')
        calls=[e for e in get if enter['real']<=e['real']<=leave['real']]
        require(len(calls)==2 and {e['data']['item'] for e in calls}=={0,4},'Wrong per-restore cache calls')
        new=[]
        for e in calls:
            data=e['data'];cid=data['id'];ret=next((r for r in got if r['data']['id']==cid),None);require(ret is not None and ret['frame']==e['frame'],'Cache return missing')
            obj=ret['data']['result'];require(obj and 'error' not in obj,'Native object read failed')
            key='current' if data['item']==0 else 'other';actual=after['data'][key]
            require(pointer(obj['pointer'])==pointer(actual['pointer']) and pointer(obj['gameObject'])==pointer(actual['gameObject']),'Cache/runtime identity differs')
            matching=[c for c in clones if c['data']['cache_id']==cid]
            if matching:
                require(len(matching)==1 and matching[0]['data']['source']==data['prefab'],'Clone source is not selected preloaded prefab')
                cr=next(c for c in cloned if c['data']['cache_id']==cid);ini=next(c for c in inits if c['data']['cache_id']==cid);done=next(c for c in initialized if c['data']['cache_id']==cid)
                require(ini['data']['item']==data['item'] and pointer(ini['data']['pointer'])==pointer(obj['pointer']) and cr['data']['result']==obj['gameObject'],'Clone/controller/object join differs')
                require(e['real']<matching[0]['real']<cr['real']<ini['real']<done['real']<ret['real'],'Clone/initialize call order differs')
                new.append(data['item'])
        grouped.append(dict(frame=enter['frame'],new_items=sorted(new),get_cache_calls=2,synchronous=True))
    require([r['new_items'] for r in grouped]==[[0,4],[],[0]],'Cold/warm/stale allocation partition differs')
    for row in [cold,warm,stale,late]:
        d=row['data'];require(d['cacheCount']==2 and d['current']['alive'] and d['current']['active'] is True and d['other']['alive'] and d['other']['active'] is False and d['untouched']['present'] is False,'Activation/filter/untouched cache differs')
        pose(d['current'],file_items[0])
    require(cold['data']['current']['pointer']==warm['data']['current']['pointer'] and cold['data']['other']['pointer']==warm['data']['other']['pointer']==stale['data']['other']['pointer'],'Warm cache not reused')
    dead=stale_before['data']['current'];require(dead['present'] and dead['alive'] is False and dead['pointer']==warm['data']['current']['pointer'],'No stale cached Unity object')
    require(stale['data']['current']['pointer']!=dead['pointer'] and late['data']['current']['pointer']==stale['data']['current']['pointer'],'Stale cache not rebuilt exactly once')
    require(cleanup['data']['cacheRestored'] and cleanup['data']['cacheCount']==0 and cleanup['data']['stop'] is False,'Cleanup failed')
    return dict(authority='controlled-native-replay-with-passive-REA-witness',scope='manager cache cold; title assets already loaded',native_save=dict(sha256=stored['sha256'],bytes=stored['bytes'],stage=stored['stage'],items=[0,4]),cases=grouped,
        cache_calls=6,clones=3,controller_initializations=3,observed_asset_load_entries=0,asset_load_entrypoints_monitored=7,
        current_stage_active=True,other_stage_hidden=True,undropped_item_uncached=True,stale_entry_retained_until_native_get=True,original_cache_restored=True,
        limits=['No asset-bundle cold load, missing-prefab recovery or asynchronous load completion is claimed.','Coverage is ordinary item0/4 prefabs, current Home and stored Residence stage guards; high item IDs and other prefab families remain unverified.','Explicit flags/cache isolation and native Save/Load are controlled preconditions.','Asset absence is limited to the seven monitored entrypoints and this fixture window.'])
def build(inputs=False):
    bundle=read(HERE/'rea-runtime.json');status=next(r for r in bundle['records'] if r['operation']=='frida_session_status');require(not status['normalized_result']['messages_truncated'],'Truncated capture')
    messages=status['normalized_result']['messages'];require(all(m['type']=='send' for m in messages),'Script error');events=[m['payload'] for m in messages]
    r=analyze(rows(HERE/'managed.jsonl.gz'),events,read(HERE/'native-save.json'));post=read(HERE/'post-state.json')
    require(post['process']['process_absent'] and post['process']['wait_for_exit_returned'] and post['frida_closed'] and post['plugins_restored'],'Process/plugin cleanup failed')
    require(all(x['unchanged'] for key in ['profile','preserved_test_profile','inputs'] for x in post[key]),'Protected files changed')
    ready=next(e for e in events if e['kind']=='drop_cache_ready');require(ready['data']['pid']==post['process']['pid'] and Path(ready['data']['path'])==Path(post['game_root'])/'GameAssembly.dll','Observed module differs')
    engine=gzip.decompress((HERE/'engine.log.gz').read_bytes()).decode('utf8',errors='replace');require(not any('[Error' in l or '[Fatal' in l for l in engine.splitlines()),'Engine error');r['engine_error_lines']=0
    if inputs:
        require(projection((HERE/'.cache/native-save.sd').read_bytes())==read(HERE/'native-save.json'),'Encrypted snapshot differs')
        for key in ['profile','preserved_test_profile']:
            for x in post[key]:require(sha(x['path'])==x['before']==x['after'],'Protected save changed')
        for x in post['inputs']:require(sha(x['path'])==sha(x['original_path'])==x['sha256'],'Protected asset changed')
    return r
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--inputs',action='store_true');p.add_argument('--check',action='store_true');a=p.parse_args();r=build(a.inputs)
    if a.check:require(r==read(HERE/'results.json'),'Result differs')
    else:(HERE/'results.json').write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(r,ensure_ascii=False,indent=2))
