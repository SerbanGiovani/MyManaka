"""Check independently decoded files against native inventory and skill consumers."""
import argparse,gzip,hashlib,json,sys
from pathlib import Path
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parents[1]/'salt'))
import save_codec

def read(p):return json.loads(Path(p).read_text(encoding='utf-8-sig'))
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def rows(p):return list(map(json.loads,gzip.decompress(Path(p).read_bytes()).decode('utf8').splitlines()))
def require(v,m):
    if not v:raise ValueError(m)
def one(rs,kind):
    selected=[r for r in rs if r['kind']==kind];require(len(selected)==1,'Missing/duplicate '+kind);return selected[0]
def projection(path):
    data=Path(path).read_bytes();_,root,_=save_codec.read(data,'unReRU821Drq83');s=root.strings()['GameStateData'].strings()['value'].strings()
    get=lambda key:next((v for k,v in s[key].entries if k==100000),None)
    return dict(path=str(path),sha256=sha(path),bytes=len(data),exp=s['ExposeExp'],rp=s['CurrentRp'],pendingRp=s['CurrentEarnThisTimeRp'],total=s['StatistisTotalEarnRp'],progress=get('MissionSatisfyDict'),achieved=get('MissionAchieveCountDict'),earned=get('MissionEarnRpDict'))

def near(a,b,tol=2e-5):return isinstance(a,(int,float)) and isinstance(b,(int,float)) and abs(a-b)<=tol

def analyze(managed,events,files):
    require(not [r for r in managed if r['kind']=='runner_error'],'Mission fixture failed')
    require(not [e for e in events if e['kind']=='engine_error'],'Engine error in final replay')
    ready=one(managed,'readiness')['data'];require(ready['ready'] and ready['assets'] and ready['hair'],'Assets not ready before first load')
    prep=one(managed,'prepared')['data'];condition=one(managed,'controlled_condition')['data'];require(prep['chosen']==100000 and prep['actual']=='None' and prep['candidateCount']==8 and condition['id']==100000 and condition['originalRequired']=='Front' and condition['required']=='0' and condition['condition'],'Controlled eligibility boundary differs')
    def selected(command):
        starts=[i for i,r in enumerate(managed) if r['kind']=='command' and r['data']['action']==command];require(len(starts)==1,'Missing/duplicate command');start=starts[0];stop=next((i for i in range(start+1,len(managed)) if managed[i]['kind']=='command'),len(managed));return managed[start:stop]
    def native(name):
        rs=[e for e in events if e['data'].get('name')==name];one(rs,'marker_begin');one(rs,'marker_end');return rs
    def file(name):
        rs=[f for f in files if Path(f['path']).stem==name];require(len(rs)==1,'Missing/duplicate file');return rs[0]
    def match(snapshot,f):
        require(all(near(snapshot[k],f[k]) for k in ['rp','pendingRp','total','progress','achieved','earned']),'Independent saved mission data differs')
    results=[]
    for name in ['unmet','paused','near-complete','completed']:
        rs=selected('case '+name);ns=native(name);get=lambda k:one(rs,k)['data'];ref=get('reference');dist=get('disturbed');loaded=get('loaded');u=[get('update'+str(i)) for i in [1,2,3]];re=get('reinitialized');v=[get('reload_update'+str(i)) for i in [1,2]];end=get('result')['snapshot']
        start=1 if name=='completed' else .9999
        require(near(ref['progress'],start) and ref['earned']==ref['pendingRp']==ref['achieved']==0,'Reference fixture differs')
        require(near(dist['progress'],.1) and dist['achieved']==9 and dist['rp']==7777,'No real mission disturbance')
        require(loaded['state']!=ref['state'] and near(loaded['satisfy'],start) and loaded['progress']==ref['progress'] and loaded['achieved']==loaded['earned']==loaded['pendingRp']==loaded['rp']==0,'Mission data/consumer restore failed')
        require(not loaded['done'] and not re['done'] and re['state']!=loaded['state'] and re['mission']!=loaded['mission'],'Warm consumer was not recreated')
        calls=[e for e in ns if e['kind']=='mission_update'];require(len(calls)==5 and [int(e['data']['arg0'],16) for e in calls]==[int(loaded['mission'])]*3+[int(re['mission'])]*2,'Wrong native mission instance/update count')
        require(all(x['stage']=='Residence' and x['id']==100000 and x['timeStop']==(name=='paused') for x in u+v),'Temporary stage/stop guard differs')
        require(end['stage']=='Apart' and not end['timeStop'],'Temporary stage/stop flags escaped call')
        require(sum(e['kind']=='native_save' for e in ns)==sum(e['kind']=='native_load' for e in ns)==sum(e['kind']=='mission_initialize' for e in ns)==3,'Mission Save/Load/Initialize count differs')
        rewards=[e for e in ns if e['kind']=='mission_reward'];one_time=[e for e in rewards if e['data']['caller']=='0x479178'];per_sec=[e for e in rewards if e['data']['caller']=='0x4794f2'];earn=[e for e in ns if e['kind']=='rise_earn_rp']
        require(len(earn)==len(rewards) and all(e['data']['caller']=='0x479753' for e in earn),'Nested earn producer differs')
        if name in ['unmet','paused']:
            require(not rewards and all(not x['done'] and near(x['progress'],start) and x['earned']==x['pendingRp']==x['total']==0 for x in u+v),'Unmet/paused task produced progress or reward')
        else:
            require(len(one_time)==2 and len(per_sec)==(4 if name=='near-complete' else 5),'One-time and per-second reward calls conflated')
            require(all(x['progress']==1 and x['rp']==x['achieved']==0 for x in u+v),'Progress must finish before settlement, not count/wallet')
            if name=='near-complete':require(not u[0]['done'] and u[0]['pendingRp']==0,'One-time reward did not wait until following update')
            first=u[1] if name=='near-complete' else u[0];require(first['done'] and all(x['done'] for x in u[1:]+v),'Completion flag missing')
            amount=10*first['rpBonus'];step=first['delta']*first['rpPerSec']*first['rpBonus'];require(near(first['pendingRp'],amount+step),'One-time/continuous amount differs')
            require(near(u[2]['pendingRp']-u[1]['pendingRp'],step),'Same-object update counted as duplicate one-time reward')
            require(near(v[0]['pendingRp']-re['pendingRp'],amount+step) and near(v[1]['pendingRp']-v[0]['pendingRp'],step),'Recreated completion boundary differs')
        for suffix,snapshot in [('before',ref),('after',u[2]),('replayed',end)]:match(snapshot,file(name+'-'+suffix))
        require(near(re['earned'],u[2]['earned']) and near(re['pendingRp'],u[2]['pendingRp']),'Post-reward file was not restored')
        results.append(dict(name=name,progress_before=ref['progress'],progress_after=u[2]['progress'],native_updates=5,one_time_calls=len(one_time),per_second_calls=len(per_sec),pending_before_reinitialize=u[2]['pendingRp'],pending_after_reinitialize=end['pendingRp'],warm_recreated_done_flag=False,natural_eligibility_verified=False))
    rs=selected('settle');ns=native('settlement');before=one(rs,'settlement_before')['data'];after=one(rs,'settlement_after')['data'];manager=one(rs,'manager_rebound')['data']
    require(manager['old']==manager['current'] and manager['count']==196 and manager['satisfy']==1 and manager['complete'] and not manager['done'],'Original manager/selected binding differs')
    require(before['progress']==1 and before['achieved']==before['rp']==0 and before['pendingRp']>16,'Settlement input missing')
    require(after['achieved']==1 and after['rp']==int(before['pendingRp'])==16 and after['progress']==after['earned']==after['pendingRp']==0 and after['total']==before['total'],'Settlement count/wallet/reset failed')
    for kind in ['result_open_if_need','result_initialize','mission_achieve','native_save','mission_initialize']:one(ns,kind)
    claim=one(ns,'mission_achieve');require(int(claim['data']['arg0'],16)==100000 and claim['data']['caller']=='0x4c7977','Achievement did not originate from result initialization')
    f=file('settlement-after');match(after,f);require(f['exp']==16,'Settled experience differs')
    cleanup=one(managed,'cleanup')['data'];require(cleanup==dict(rootsRestored=True,stop=False),'Final cleanup failed')
    require(len(events)==98,'Final native capture count differs')
    return dict(authority='controlled-original-mission-consumers-and-result-settlement',natural_only=False,cases=results,settlement=dict(pending_before=before['pendingRp'],wallet_after=after['rp'],exp_after=f['exp'],achieved_after=after['achieved'],progress_after=after['progress'],earned_after=after['earned'],original_manager_reused=True),native_messages=len(events),engine_error_events=0,limits=['The cloned original mission record changes required exposure to zero for positive cases; native Residence stage is coordinated only during explicit updates while actual scene remains Apartment. Natural eligibility and scene transitions are unverified.','Paused is an explicit temporary flag, not a natural input/time-stop producer test.','Several Update calls execute within one frame. Small increments are native per-second reward per call, not proof of duplicate one-time rewards.','Recreating a complete task clears its runtime completion flag and repeats the one-time reward only in this controlled warm reconstruction. Natural lifecycle and scene-reset reachability are unverified.','Settlement uses native UI initialization and the original manager. Player clicks, result animations and repeated result opening are outside this batch.','Six prior runs include unmet eligibility, clone-init errors, a coreclr crash, nullable preparation failure and early-load HatOffset errors. Full diagnostics are retained separately.'])

def build(inputs=False):
    b=read(HERE/'rea-runtime.json');n=next(r['normalized_result'] for r in b['records'] if r['operation']=='frida_session_status')
    require(n['pid']==75008 and not n['messages_truncated'] and all(m['type']=='send' for m in n['messages']),'Native capture incomplete')
    files=read(HERE/'saved-files.json')['files'];result=analyze(rows(HERE/'managed.jsonl.gz'),[m['payload'] for m in n['messages']],files)
    engine=gzip.decompress((HERE/'engine.log.gz').read_bytes()).decode('utf8',errors='replace');require(not any('[Error' in l or '[Fatal' in l for l in engine.splitlines()),'Engine log error')
    p=read(HERE/'post-state.json');require(p['plugins_restored'] and p['frida_closed'] and p['process']['exited'] and p['process']['process_absent'],'Process/plugin cleanup failed')
    require(all(x['unchanged'] for k in ['profile','preserved_test_profile','inputs'] for x in p[k]),'Protected files changed')
    if inputs:
        require(all(projection(f['path'])==f for f in files),'Encrypted projection differs')
        for k in ['profile','preserved_test_profile']:
            for x in p[k]:require(sha(x['path'])==x['before']==x['after'],'Protected profile differs')
        for x in p['inputs']:require(sha(x['path'])==sha(x['original_path'])==x['sha256'],'Engine/asset differs')
    return result
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');p.add_argument('--inputs',action='store_true');a=p.parse_args();r=build(a.inputs)
    if a.check:require(r==read(HERE/'results.json'),'Result differs')
    else:(HERE/'results.json').write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(r,ensure_ascii=False,indent=2))
