"""Join natural mission/return-home observations while retaining round1 hook gaps."""
import argparse,collections,gzip,hashlib,json,math,struct,sys
from pathlib import Path
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parents[1]/'salt'))
import save_codec
PASSWORD='unReRU821Drq83'
ROUND_IDS=[('ev_f32f3bffd1826eb6b17ca381b1e20d2a22bd320a9ffa193e8d1debbdaab3adb5','ev_63f0c98005ec837beccebe9ea133bab8bed0cbfd24dbf355956545350e579edc'),('ev_390f04b6140ff67cf29ada8a80552bb22f9c42dd3f8be3b6212cc900ad0444b7','ev_782a5d711246f44112c7afe667cba3fd4efa3e3e5f4303790a274717e7f1bf44')]
ROUND_SOURCES=[('a5c08cb5-1349-450c-a7a9-39bf85289fdc','observe-round1.js'),('6b9c9eca-58ae-45a1-bd34-a87069dd080d','observe.js')]
SYSTEM_ROOTS={'OptionData','TutorialData','HomeSaveTime','InterruptSaveTime','TotalPlayTimeData','RankData','DifficultData','ManualSaveTime','AutoSaveTime'}

def read(p):return json.loads(Path(p).read_text(encoding='utf-8-sig'))
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def rows(p):return list(map(json.loads,gzip.decompress(Path(p).read_bytes()).decode('utf8').splitlines()))
def require(v,m):
    if not v:raise ValueError(m)
def near(a,b,t=2e-6):return isinstance(a,(int,float)) and isinstance(b,(int,float)) and math.isfinite(a) and math.isfinite(b) and abs(a-b)<=t
def one(rs,kind,predicate=lambda e:True):
    matches=[r for r in rs if r['kind']==kind and predicate(r)];require(len(matches)==1,'Missing/duplicate '+kind);return matches[0]
def canon(x):
    if isinstance(x,save_codec.ObjectPairs):
        pairs=sorted((type(k).__name__+':'+str(k),canon(v)) for k,v in x.entries);require(len({k for k,_ in pairs})==len(pairs),'Duplicate typed key');return dict(pairs=pairs)
    if isinstance(x,list):return [canon(v) for v in x]
    if isinstance(x,float):return dict(float64=struct.pack('<d',x).hex())
    return x
def treehash(x):return hashlib.sha256(json.dumps(canon(x),ensure_ascii=False,sort_keys=True,separators=(',',':')).encode('utf8')).hexdigest()
def projection(path):
    path=Path(path);data=path.read_bytes();plain,root,reader=save_codec.read(data,PASSWORD);roots=root.strings();out=dict(path=str(path),name=path.name,sha256=sha(path),bytes=len(data),plaintext_sha256=hashlib.sha256(plain).hexdigest(),typed_tree_sha256=treehash(root),numeric_key_count=reader.numeric_key_count,root_keys=sorted(roots))
    if 'GameStateData' in roots:
        s=roots['GameStateData'].strings()['value'].strings();get=lambda name:next((v for k,v in s[name].entries if k==100000),None)
        out.update(kind='game',slot=roots['SaveDataSlotIndex'].strings()['value'],stage=s['CurrentStageType'],rp=s['CurrentRp'],exp=s['ExposeExp'],pending=s['CurrentEarnThisTimeRp'],total=s['StatistisTotalEarnRp'],target=dict(id=100000,progress=get('MissionSatisfyDict'),earned=get('MissionEarnRpDict'),achieved=get('MissionAchieveCountDict')),game_fields=len(s),custom_fields=len(roots['PlayerCustomData'].strings()['value'].strings()))
    else:
        projected=[]
        for key,wrapped in sorted(roots.items()):
            w=wrapped.strings();value=w['value'];p=dict(key=key,type=w['__type'],value_kind=type(value).__name__,value_sha256=treehash(value))
            if isinstance(value,save_codec.ObjectPairs):p['fields']={str(k):treehash(v) for k,v in value.entries};p['field_count']=len(value.entries)
            if isinstance(value,list):p['length']=len(value)
            projected.append(p)
        out.update(kind='system',roots=projected)
    return out
def canonical_rounds(bundle):
    all_records=bundle['records'];require(len(all_records)==4 and len({r['evidence_id'] for r in all_records})==4,'Canonical rounds duplicated or incomplete')
    rounds=[]
    for (load_id,status_id),(session,source) in zip(ROUND_IDS,ROUND_SOURCES):
        load=next(r for r in all_records if r['evidence_id']==load_id);status=next(r for r in all_records if r['evidence_id']==status_id);n=status['normalized_result'];require(n['pid']==79816 and not n['messages_truncated'],'Native identity/capture differs')
        require(n['session_id']==session and n['mode']=='attach' and n['state']=='running','Native session identity differs')
        require(load['normalized_result']['source_sha256']==sha(HERE/source),'Archived native source differs from loaded script')
        messages=n['messages'];events=[dict(m['payload'],script_id=m['script_id']) for m in messages if m['type']=='send'];errors=[m for m in messages if m['type']!='send'];require(all(m['script_id']==load['normalized_result']['script_id'] for m in messages),'Script identity mismatch')
        ready=one(events,'natural_mission_ready');require(ready['data']['pid']==79816,'Ready PID differs')
        rounds.append(dict(load=load,status=status,events=events,errors=errors,messages=len(messages)))
    return rounds
def analyze(managed,paths,rounds,files):
    require(not [r for r in managed if r['kind']=='snapshot_error'],'Passive snapshot failed')
    require(not [e for r in rounds for e in r['events'] if e['kind']=='engine_error'],'Engine error')
    r1,r2=rounds;a=r1['events'];b=r2['events'];errors=r1['errors']
    require(r1['messages']==74 and len(errors)==10 and r2['messages']==43 and not r2['errors'],'Round script errors/gaps were hidden or changed')
    require(all(e['type']=='error' and e['description']=="ReferenceError: 'm' is not defined" and e['line_number']==15 and 'onLeave' in e['stack'] for e in errors),'Unexpected round1 error')
    missing=collections.Counter(e['kind'].replace('_enter','_leave') for e in a if e['kind'].endswith('_enter'))
    require(missing==collections.Counter(save_load_leave=1,stage_transition_leave=2,result_initialize_leave=1,mission_achieve_leave=1,save_write_leave=3,result_ok1_leave=1,pc_save_leave=1) and not [e for e in a if e['kind'].endswith('_leave')],'Round1 lifecycle gaps differ')
    load=one(a,'save_load_enter');require(load['data']['arg0']=='0x3' and load['data']['arg1']=='0x1' and load['data']['caller']=='0x4e5229','Wrong natural title slot')
    notices=[e for e in a if e['kind']=='target_one_time'];require(len(notices)==1 and notices[0]['data']['mission']['id']==100000 and notices[0]['data']['caller']=='0x479178','One-time reward source differs');notice=notices[0]
    reaches=[e for e in a if e['kind']=='target_progress' and e['data']['mission']['id']==100000 and e['data']['mission']['satisfy']==1 and not e['data']['mission']['done']];require(len(reaches)==1,'Threshold point missing');threshold=reaches[0]
    after=one(a,'target_progress',lambda e:e['data']['mission']['id']==100000 and e['data']['mission']['done']);require(threshold['frame']<notice['frame']==after['frame'] and notice['data']['state']['pending']==0 and after['data']['state']['pending']>8,'Threshold/one-time/post-update ordering differs')
    transitions=[e for e in a if e['kind']=='stage_transition_enter'];require(len(transitions)==2 and [(e['data']['arg1'],e['data']['arg2']) for e in transitions]==[('0x0','0xa'),('0xa','0x0')],'Round1 stage route differs')
    leave=transitions[-1];init=one(a,'result_initialize_enter');achieve=one(a,'mission_achieve_enter');pc1=one(a,'pc_save_enter');save1=one(a,'save_write_enter',lambda e:e['data']['caller']=='0x4caf20')
    pending=leave['data']['state']['pending'];require(near(pending,8.599584173411131) and init['data']['state']['pending']==pending and leave['real']<init['real']<achieve['real']<pc1['real']<save1['real'],'Natural settlement nesting differs')
    require(achieve['data']['caller']=='0x4c7977' and int(achieve['data']['arg0'],16)==100000,'Achievement source differs')
    require(achieve['data']['state']['rp']==achieve['data']['state']['exp']==int(pending)==8 and achieve['data']['state']['target']['achieved'] is None,'Achievement entry must not masquerade as returned count')
    settled=save1['data']['state'];require(settled['rp']==settled['exp']==8 and settled['pending']==0 and settled['target']==dict(id=100000,progress=0,earned=0,achieved=1),'Post-settlement state not closed by subsequent native entry')
    play=[s for s in managed if s['kind']=='snapshot' and s['frame']>=load['frame'] and s['data']['player'] is not None];require(len(play)==426 and all(s['data']['missionCount']==196 and s['data']['stop'] is False and s['data']['applierStopped'] is False for s in play),'Natural sampling/stop/manager count differs')
    identities={key:sorted({s['data'][key] for s in play}) for key in ['state','player','missionManager']};require(all(len(v)==1 for v in identities.values()),'Natural route recreated manager/player/state')
    target_rows=[(s,m) for s in play for m in s['data']['missions'] if m['id']==100000];ptrs={m['pointer'] for s,m in target_rows};require(len(ptrs)==1,'Mission instance changed')
    require(int(identities['state'][0])==int(settled['pointer'],16) and int(next(iter(ptrs)))==int(notice['data']['mission']['pointer'],16),'Native/managed pointers disagree')
    fronts=[s for s in play if transitions[0]['real']<=s['real']<=leave['real'] and s['data']['stage']=='Residence' and s['data']['exposed']=='Front'];require(len(fronts)>5,'Actual Front condition not sampled')
    post1=[(s,m) for s,m in target_rows if init['real']<s['real']<pc1['real'] and s['data']['stage']=='Apart'];require(post1 and all(m['satisfy']==m['progress']==m['earned']==0 and m['done'] is False and m['achieved']==1 and s['data']['rp']==s['data']['exp']==8 and s['data']['pendingRp']==0 for s,m in post1),'Original object was not reset naturally')
    require(not [e for e in b if e['kind'] in ['target_one_time','result_initialize_enter','result_initialize_leave','mission_achieve_enter','mission_achieve_leave']],'Second round added completion/settlement')
    tr2=[e for e in b if e['kind']=='stage_transition_enter'];tr2leave=[e for e in b if e['kind']=='stage_transition_leave'];require(len(tr2)==len(tr2leave)==2 and [(e['data']['arg1'],e['data']['arg2']) for e in tr2]==[('0x0','0xa'),('0xa','0x0')],'Second route incomplete/different')
    for enter,returned in zip(tr2,tr2leave):require(enter['real']<returned['real'] and all(enter['data'][k]==returned['data'][k] for k in ['caller','arg0','arg1','arg2']),'Second transition return differs from entry')
    partial=tr2[-1]['data']['state']['target']['progress'];require(0<partial<1 and near(partial,.07217653095722198),'Second round was incorrectly called always unmet/empty')
    pc2=one(b,'pc_save_enter');pcleave=one(b,'pc_save_leave');write2=one(b,'save_write_enter',lambda e:e['data']['caller']=='0x4caf20');written2=one(b,'save_write_leave',lambda e:e['data']['caller']=='0x4caf20')
    require(pc2['real']<write2['real']<written2['real']<pcleave['real'],'Fixed round PC Save return nesting missing')
    require(write2['data']['arg0']=='0x3' and write2['data']['arg1']=='0xffffffff' and write2['data']['arg2']=='0x0','PC save was not current manual main')
    require(written2['data']['oneTime']==written2['data']['continuous']==0 and written2['data']['updates']==3415,'Second round aggregate counters differ')
    require(written2['data']['state']['rp']==written2['data']['state']['exp']==8 and written2['data']['state']['pending']==0 and written2['data']['state']['target']==settled['target'],'Second round state differs')
    second=[(s,m) for s,m in target_rows if tr2[0]['real']<=s['real']<=pc2['real']];require(any(m['progress']>0 and s['data']['stage']=='Residence' and s['data']['exposed']=='Front' for s,m in second) and all(m['earned']==0 and m['achieved']==1 and s['data']['rp']==s['data']['exp']==8 and s['data']['pendingRp']==0 for s,m in second),'Incomplete second-round progress not preserved with sampled Front exposure and without reward')
    home2=[(s,m) for s,m in second if s['real']>tr2[-1]['real'] and s['data']['stage']=='Apart'];require(home2 and home2[-1][1]['satisfy']==home2[-1][1]['progress']==0 and home2[-1][1]['done'] is False,'Second natural return did not clear original task')
    captures=[m for m in managed if m['kind']=='file_capture'];require(len(captures)==len(files)==14 and sum(f['kind']=='game' for f in files)==8,'Capture count differs')
    byname={f['name']:f for f in files};require(len(byname)==14,'Duplicate capture filename')
    for c in captures:require(Path(c['data']['target']).name in byname,'Unprojected capture')
    games=[f for f in files if f['kind']=='game'];systems=[f for f in files if f['kind']=='system'];require(len(systems)==6 and all(set(f['root_keys'])==SYSTEM_ROOTS and {r['key'] for r in f['roots']}==SYSTEM_ROOTS and len(f['roots'])==9 for f in systems),'System root projection incomplete')
    require(all(set(f['root_keys'])=={'PlayerCustomData','IsTrial','GameStateData','SaveDataSlotIndex'} for f in games),'Game root projection incomplete')
    for f in systems:
        require(next(x for x in f['roots'] if x['key']=='OptionData')['field_count']==68 and next(x for x in f['roots'] if x['key']=='TutorialData')['field_count']==15,'System fields incomplete')
        require(all(x['field_count']==len(x['fields']) for x in f['roots'] if 'fields' in x),'System field projection differs from count')
    first_file=byname['0008-SaveData-1.sd'];second_file=byname['0010-SaveData-1.sd'];auto=byname['0004-SaveData-1.sd']
    for f in [first_file,second_file,auto]:require(f['slot']==1 and f['stage']==0 and f['rp']==f['exp']==8 and f['pending']==0 and f['target']==settled['target'] and f['total']==pending,'Decoded natural main save differs')
    require(byname['0001-SaveData-1.sd']['rp']==byname['0001-SaveData-1.sd']['exp']==0 and byname['0000-SaveData-0.sd']['stage']==11,'Copied initial profile boundary differs')
    for ev in [save1,write2]:
        matched=[p for p in paths if p['kind']=='save_path' and p['frame']==ev['frame'] and p['data']['before']=='SaveData/1.sd'];require(matched,'PC main save routing missing')
        require(all('NaturalMission' in p['data']['after'] and 'working-profile' in p['data']['after'] for p in matched),'Save escaped private profile')
    return dict(authority='passive-original-user-input-in-isolated-save-root',natural_only=True,managed_samples=len(play),identities=dict(**{k:v[0] for k,v in identities.items()},mission100000=next(iter(ptrs))),first_round=dict(messages=74,script_errors=10,lifecycle_returns_complete=False,missing_leave=dict(missing),threshold_frame=threshold['frame'],one_time_frame=notice['frame'],one_time_calls_observed=1,pending_before_return=pending,result_frame=init['frame'],wallet_after=8,experience_after=8,achieved_after=1,original_instance_reset_observed=True,pc_save_frame=save1['frame'],pc_main_sha256=first_file['sha256']),second_round=dict(messages=43,script_errors=0,partial_progress=partial,condition_always_unmet=False,incomplete=True,one_time_calls=0,continuous_calls=0,aggregate_active_mission_updates=3415,result_initialize_calls=0,achieve_calls=0,wallet_after=8,experience_after=8,achieved_after=1,original_instance_reset_observed=True,pc_save_frame=write2['frame'],pc_main_sha256=second_file['sha256']),captures=dict(total=14,game=8,system=6,initial_copied=4,initial_slot0_loaded=False),engine_error_events=0,limits=['Round1 has ten ReferenceError failures in native onLeave callbacks; native return states and final high-frequency totals are unavailable there. Subsequent native entries, managed snapshots and encrypted files close only the selected result/save state.','Round2 had real partial progress and sampled Front exposure, not a condition-always-unmet or truly empty run.','Progress samples are native 5% buckets and managed 0.5s reads. Exact condition changes between samples and the reason for a visually blank UI remain unknown.','Hook update counters aggregate matching active missions, not only task100000.','This natural route preserved original objects and reset progress through normal return/settlement; it does not demonstrate the controlled warm-recreation duplicate reward is naturally reachable.','The copied initial slot0 capture is decoded for integrity only and was not loaded in this observed title route.'])

def build(inputs=False):
    bundle=read(HERE/'rea-runtime.json');rounds=canonical_rounds(bundle);managed=rows(HERE/'managed.jsonl.gz');files=read(HERE/'saved-files.json')['files'];result=analyze(managed,rows(HERE/'paths.jsonl.gz'),rounds,files)
    archived={}
    for n in ['rea-round1.json','rea-round2.json']:
        for r in json.loads(gzip.decompress((HERE/'raw'/(n+'.gz')).read_bytes()))['records']:
            require(r['evidence_id'] not in archived or archived[r['evidence_id']]==r,'Duplicate raw Evidence changed')
            archived[r['evidence_id']]=r
    require(all(archived[r['evidence_id']]==r for r in bundle['records']),'Canonical record differs from complete raw exports')
    manifest=read(HERE/'manifest.json')
    for x in manifest['sources']+manifest['outputs']:require(sha(HERE/x['path'])==x['sha256'],'Archived source/output fingerprint differs: '+x['path'])
    for x in manifest['outputs']:
        if x['path'].endswith('.gz'):
            raw=gzip.decompress((HERE/x['path']).read_bytes());require(len(raw)==x['uncompressed_bytes'] and hashlib.sha256(raw).hexdigest()==x['uncompressed_sha256'],'Complete gzip content differs')
    engine=gzip.decompress((HERE/'engine.log.gz').read_bytes()).decode('utf8',errors='replace');require(not any('[Error' in l or '[Fatal' in l for l in engine.splitlines()),'Engine log error')
    post=read(HERE/'post-state.json');require(post['process']['pid']==79816 and post['process']['exited'] and post['process']['process_absent'],'Natural process not closed')
    require(all(x['unchanged'] for k in ['profile','preserved_test_profile','inputs'] for x in post[k]),'Protected files changed')
    if post['plugin_verification']['checked']:require(post['plugin_verification']['restored'],'Original plugin fingerprints differ')
    result['plugin_verification']=post['plugin_verification'];result['protected_files']=dict(user_data=len(post['profile']),prior_natural=len(post['preserved_test_profile']),inputs=len(post['inputs']),unchanged=True)
    if inputs:
        require(all(projection(f['path'])==f for f in files),'Independent ciphertext projection differs')
        for k in ['profile','preserved_test_profile']:
            for x in post[k]:require(sha(x['path'])==x['before']==x['after'],'Protected save changed')
        for x in post['inputs']:require(sha(x['path'])==sha(x['original_path'])==x['sha256'],'Engine/asset fingerprint differs')
    return result

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--inputs',action='store_true');p.add_argument('--check',action='store_true');a=p.parse_args();r=build(a.inputs)
    if a.check:require(r==read(HERE/'results.json'),'Results differ')
    else:(HERE/'results.json').write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(r,ensure_ascii=False,indent=2))
