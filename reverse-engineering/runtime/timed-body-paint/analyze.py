"""Join timed-paint DTO files, original native returns and measured shader consumers."""
import argparse,collections,gzip,hashlib,json,math,struct,sys
from pathlib import Path
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parents[1]/'salt'))
import save_codec
CASES=['init-0','init-12','init-24','init-25','init-60','init-61','init-120','init-120-reusable','rate-0','rate-025','rate-05','rate-075','wash','item-ordinary-false','item-reusable','item-ordinary-true','load-ordinary','load-reusable','cross-60','cross-24','cross-0']
SMOOTH=['Current','Target','maxDelta','downMaxDelta','isLerp','baseValue','second','downSecond','isUnscaled']
def read(p):return json.loads(Path(p).read_text(encoding='utf-8-sig'))
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def rows(p):return list(map(json.loads,gzip.decompress(Path(p).read_bytes()).decode('utf8').splitlines()))
def require(v,m):
    if not v:raise ValueError(m)
def one(rs,kind):
    selected=[r for r in rs if r['kind']==kind];require(len(selected)==1,'Missing/duplicate '+kind);return selected[0]
def f32(v):return struct.unpack('<f',struct.pack('<f',v))[0]
def ulp(v):
    bits=struct.unpack('<I',struct.pack('<f',abs(v)))[0];return abs(struct.unpack('<f',struct.pack('<I',bits+1))[0]-f32(abs(v)))
def near(a,b):return type(a) in [int,float] and type(b) in [int,float] and math.isfinite(a) and math.isfinite(b) and abs(a-b)<=max(2e-6,2*ulp(b))
def pointer(p):return 0 if p is None else int(str(p),0)
def canon(v):
    if isinstance(v,save_codec.ObjectPairs):
        entries=[(type(k).__name__+':'+str(k),canon(x)) for k,x in v.entries];require(len({k for k,x in entries})==len(entries),'Duplicate typed save key');return dict(pairs=sorted(entries))
    if isinstance(v,list):return list(map(canon,v))
    if isinstance(v,float):return dict(float64=struct.pack('<d',v).hex())
    return v
def treehash(v):return hashlib.sha256(json.dumps(canon(v),sort_keys=True,separators=(',',':'),ensure_ascii=False).encode('utf8')).hexdigest()
def projection(p):
    p=Path(p);data=p.read_bytes();plain,root,reader=save_codec.read(data,'unReRU821Drq83');r=root.strings();require(set(r)=={'PlayerCustomData','IsTrial','GameStateData','SaveDataSlotIndex'},'Saved game roots differ')
    state=r['GameStateData'].strings()['value'].strings();custom=r['PlayerCustomData'].strings()['value'].strings();paint=custom['BodyPaintTypeDict'].entries
    require(type(state['PlayerRemainBodyPaintTime']) in [int,float] and math.isfinite(state['PlayerRemainBodyPaintTime']) and type(state['IsActiveBodyPaintReusable']) is bool,'Saved timed-paint field types differ')
    require(all(type(k) is int and 0<=k<10 and type(v) is bool for k,v in paint) and len({k for k,v in paint})==len(paint),'Persistent paint map types/keys differ')
    return dict(path=str(p),sha256=sha(p),bytes=len(data),plaintext_sha256=hashlib.sha256(plain).hexdigest(),typed_tree_sha256=treehash(root),slot=r['SaveDataSlotIndex'].strings()['value'],numeric_key_count=reader.numeric_key_count,game_field_count=len(state),custom_field_count=len(custom),remaining=state['PlayerRemainBodyPaintTime'],remaining_storage_type=type(state['PlayerRemainBodyPaintTime']).__name__,reusable=state['IsActiveBodyPaintReusable'],persistent_map=[dict(id=k,value=v) for k,v in sorted(paint)],custom_tree_sha256=treehash(r['PlayerCustomData']))
def native_pairs(events):
    pending=[];seen=set();pairs=[];marker=None
    for e in events:
        k=e['kind'];d=e['data']
        if k=='marker_begin':require(marker is None and d['thread'],'Nested/invalid native marker');marker=d['name']
        elif k=='marker_end':require(marker==d['name'] and not pending,'Unclosed native call/marker');marker=None
        elif k.endswith('_enter'):
            require(marker==d['name'] and d['id'] not in seen,'Native entry identity/marker differs');seen.add(d['id']);pending.append(e)
        elif k.endswith('_leave'):
            require(pending,'Native return without entry');entry=pending.pop();a=entry['data'];require(a['id']==d['id'] and a['name']==d['name'] and a['pointer']==d['pointer'] and entry['kind'].removesuffix('_enter')==k.removesuffix('_leave'),'Native nested return identity/order differs');require(entry['frame']==e['frame'] and entry['real']<=e['real'],'Native synchronous call frame/time differs');pairs.append((entry,e))
    require(not pending and marker is None,'Incomplete native call capture');return pairs
def current(s):return s['clone']['smooth']['fields']['Current']
def binding(s):
    if s['clothes']['valid']:
        require(len(s['materials'])==4 and pointer(s['materials'][-2]['pointer'])==pointer(s['clothes']['pointer']),'Timed body material is not the actual renderer slot')
    else:require(len(s['materials'])==3,'No-paint body topology differs')
    for target,renderer in [('sao','saoRenderer'),('tama','tamaRenderer')]:
        m=s[target];array=s[renderer]['materials'];require(m['valid'] and array and pointer(array[-1]['pointer'])==pointer(m['pointer']),'Extra material is not its actual renderer slot')
def timer(before,doki,dt):return max(0,f32(f32(before)-f32(f32(min(.5,max(0,f32(doki)))*2)*f32(dt))))
def alpha_step(before,state,dt,up,down):
    if state==0:return before
    target={1:-1.,2:f32(.4),3:.25,4:0.}[state];rate=down if target<before else up;difference=f32(target-before)
    return target if f32(dt*rate)>=abs(difference) else f32(f32(f32((-1. if difference<0 else 1.)*dt)*rate)+before)
def raw_float(words,index):return struct.unpack('<f',struct.pack('<I',int(words[index],16)))[0]
def snapshot_diff(a,b,path=''):
    if type(a)!=type(b):return [dict(path=path,expected=a,actual=b)]
    if isinstance(a,dict):
        require(set(a)==set(b),'Compared snapshot keys differ');return [d for k in a if not(path=='' and k=='clone') for d in snapshot_diff(a[k],b[k],path+'.'+k)]
    if isinstance(a,list):
        if len(a)!=len(b):return [dict(path=path,expected_length=len(a),actual_length=len(b))]
        return [d for i,(x,y) in enumerate(zip(a,b)) for d in snapshot_diff(x,y,path+'['+str(i)+']')]
    return [] if a==b else [dict(path=path,expected=a,actual=b)]
def analyze(managed,events,files,baseline_file):
    require(not [r for r in managed if r['kind'] in ['runner_error','cleanup_error','cleanup_without_material_backup']],'Fixture or cleanup failed')
    require(not [e for e in events if e['kind']=='engine_error'],'Native engine error');pairs=native_pairs(events)
    prep=one(managed,'prepared')['data'];require(prep['authority']=='controlled-unregistered-native-body-paint-clone' and prep['natural_only'] is False,'Controlled clone authority differs')
    identity=one(managed,'property_id_verified')['data'];require(identity['literal']=='_Tweak_transparency' and identity['independentTweakId']==identity['staticTweakId'] and identity['beforeInitialSnapshot'] is True,'Independent/native shader property ID differs')
    parked=prep['parked'];original=prep['original'];clone_ptr=pointer(parked['clone']['pointer']);original_ptr=pointer(parked['original']['pointer']);require(clone_ptr and original_ptr and clone_ptr!=original_ptr and pointer(parked['clone']['smooth']['pointer'])!=pointer(parked['original']['smooth']['pointer']),'Native clone/alpha aliases original')
    require(pointer(parked['pcaBodyPaint'])==original_ptr and parked['applier'] is True and parked['timeStop'] is False,'Original controller registration/guards differ')
    require(original['state']!=parked['state'] and original['custom']!=parked['custom'],'Original global roots were not detached')
    constructor=prep['cloneConstructorSmooth']['fields'];require(set(constructor)==set(SMOOTH) and constructor['Current']==0 and constructor['Target']==0 and near(constructor['maxDelta'],.075) and near(constructor['downMaxDelta'],.075) and constructor['isLerp'] is False and constructor['isUnscaled'] is False,'Original constructor smoothing defaults differ')
    require(set(prep['supportedShaderPropertyKinds'])<={'Color','Float','Range','Vector','Texture'} and all(n>0 for n in prep['supportedShaderPropertyKinds'].values()),'Shader backup support boundary differs')
    before=one(managed,'guard_before');after=one(managed,'guard_after');require(after['frame']-before['frame']==5 and after['data']['frames']==5,'Five-frame automatic-controller guard missing')
    for r in [before,after]:
        s=r['data']['snapshot'];require(s['remaining']==120 and s['dokidoki']==0 and s['original']['state']==0 and s['original']['smooth']['fields']['Current']==-1 and pointer(s['pcaBodyPaint'])==original_ptr,'Original automatic park drifted')
    guard=[p for p in pairs if p[0]['kind']=='paint_update_enter' and p[0]['data']['name']=='guard-probe/parked-five-frames'];require(len(guard)>=5,'Original automatic updates were not directly witnessed')
    original_updates=[p for p in pairs if p[0]['kind']=='paint_update_enter' and pointer(p[0]['data']['pointer'])==original_ptr]
    for a,b in original_updates:
        x=a['data']['snapshot'];y=b['data']['snapshot'];require(pointer(x['pointer'])==original_ptr and x['doki']==0 and x['state']==y['state']==0 and x['dto']==y['dto'] and x['alpha']==y['alpha'],'Automatic-controller return changed parked state')
    results=[r for r in managed if r['kind']=='result'];require([r['data']['name'] for r in results]==CASES,'Finite case order/count differs')
    all_snapshots=[r['data']['snapshot'] for r in managed if isinstance(r.get('data'),dict) and isinstance(r['data'].get('snapshot'),dict) and r['kind'] not in ['guard_before','guard_after']]
    for s in all_snapshots:require(pointer(s['pcaBodyPaint'])==original_ptr and s['original']['state']==0 and s['original']['smooth']['fields']['Current']==-1 and s['timeStop'] is False and s['tweakIdMatches'] is True and s['staticTweakId']==s['independentTweakId']==identity['independentTweakId'],'Registered original controller/property ID/stop state changed during fixture')
    saved=[r for r in managed if r['kind']=='saved'];require(len(saved)==len(files)==17 and len({r['data']['capture'] for r in saved})==17,'Seventeen unique encrypted captures required')
    counts=collections.Counter(a['kind'].removesuffix('_enter') for a,b in pairs)
    require(all(counts[k]==v for k,v in {'native_save':17,'native_load':2,'paint_use':3,'paint_wash':1,'paint_initialize':26,'player_body_broadcast':26,'body_material_setup':31,'body_apply_options':31}.items()),'Selected native producer/consumer counts differ')
    for r in saved:
        d=r['data'];s=d['snapshot'];f=next(f for f in files if Path(f['path']).stem==d['capture']);require(f['slot']==1 and near(f['remaining'],s['remaining']) and f['reusable'] is s['reusable'],'Independent saved DTO differs')
        require(f['persistent_map']==baseline_file['persistent_map'] and all(v['value'] is False for v in f['persistent_map']) and f['custom_tree_sha256']==baseline_file['custom_tree_sha256'],'Unselected saved custom/persistent-map presence changed')
        ns=[(a,b) for a,b in pairs if a['kind']=='native_save_enter' and a['frame']==r['frame'] and a['data']['name'].startswith(d['name']+'/')];require(len(ns)==1,'Save capture has no unique native entry/return');a,b=ns[0]
        require((pointer(a['data']['pointer'])&0xffffffff)==3 and (pointer(a['data']['arg1'])&0xffffffff)==1 and (pointer(a['data']['arg2'])&0xff)==0 and near(b['data']['snapshot']['dto']['remain'],s['remaining']) and b['data']['snapshot']['dto']['reusable'] is s['reusable'],'Native static save arguments/returned DTO differ')
    for r in [r for r in managed if r['kind'] in ['initialize_result','explicit_initialize_result'] and r['data']['name'] in CASES]:
        d=r['data'];s=d['snapshot'];ns=[b for a,b in pairs if a['kind']=='paint_initialize_enter' and a['frame']==r['frame'] and a['data']['name'].startswith(d['name']+'/') and pointer(a['data']['pointer'])==clone_ptr and b['data']['snapshot']['state']==s['clone']['state'] and near(b['data']['snapshot']['dto']['remain'],s['remaining'])]
        require(len(ns)==1 and near(ns[0]['data']['snapshot']['alpha']['current'],current(s)),'Initialization result lacks original native return')
    manual_before=[r for r in managed if r['kind']=='manual_update_before'];manual_after=[r for r in managed if r['kind']=='manual_update_after'];require(len(manual_before)==len(manual_after) and len({r['data']['id'] for r in manual_before})==len(manual_before),'Manual update pairing differs')
    update_results=[]
    for before,after in zip(manual_before,manual_after):
        a,b=before['data'],after['data'];require((a['name'],a['id'])==(b['name'],b['id']) and before['frame']==after['frame'],'Managed update identity/frame differs');label=a['name']+'/update-'+str(a['id']);ns=[p for p in pairs if p[0]['kind']=='paint_update_enter' and p[0]['data']['name']==label];require(len(ns)==1,'Manual update missing/duplicated native call');entry,leave=ns[0];x,y=entry['data']['snapshot'],leave['data']['snapshot'];s,t=a['snapshot'],b['snapshot'];require(pointer(x['pointer'])==pointer(y['pointer'])==clone_ptr and pointer(x['pca'])==pointer(s['pca']) and pointer(x['playerState'])==pointer(s['playerState']),'Manual original receiver binding differs')
        dt=x['delta'];doki=x['doki'];require(dt>0 and near(dt,a['deltaTime']) and near(dt,b['deltaTime']) and near(doki,a['targetDokidoki']) and near(doki,a['actualDokidoki']) and b['restoredDokidoki']==t['dokidoki']==0,'Real delta/Dokidoki or restoration differs')
        for n,z in [(x,s),(y,t)]:require(pointer(n['dto']['pointer'])==pointer(z['state']) and near(n['dto']['remain'],z['remaining']) and n['dto']['reusable'] is z['reusable'] and n['state']==z['clone']['state'] and near(n['alpha']['current'],current(z)),'Managed/native update field join differs')
        expected=timer(x['dto']['remain'],doki,dt);require(near(y['dto']['remain'],expected),'Measured float32 countdown differs')
        p=x['state'];q=y['state'];words=x['alpha']['words'];expected_alpha=alpha_step(x['alpha']['current'],p,dt,raw_float(words,1),raw_float(words,2));require(near(y['alpha']['current'],expected_alpha),'Original SmoothFloat result differs from measured MoveTowards')
        expected_state=0 if p==1 and expected_alpha<=-1 else 3 if p==2 and expected<=60 else 4 if p==3 and expected<=24 else 1 if p==4 and expected<=0 else p;require(q==expected_state,'Original timed state transition differs');require(y['dto']['reusable'] is (False if p==4 and q==1 else x['dto']['reusable']),'Reusable clear timing differs')
        smooth=t['clone']['smooth']['fields'];require(smooth['Target']==s['clone']['smooth']['fields']['Target'],'UpdateTo falsely credited with Target field mutation')
        if p!=q and p in [2,3,4]:
            base={2:.15,3:.25,4:1.}[p];require(near(smooth['baseValue'],base) and near(smooth['maxDelta'],base/smooth['second']) and near(smooth['downMaxDelta'],base/smooth['downSecond']),'Transition rates changed at wrong phase')
        binding(t)
        if q!=0:require(all(t[k]['valid'] and t[k]['hasTweak'] and near(t[k]['tweak'],expected_alpha) for k in ['clothes','sao','tama']),'Actual transparency consumers differ from native alpha')
        update_results.append(dict(name=a['name'],id=a['id'],frame=before['frame'],doki=doki,delta=dt,remaining_before=x['dto']['remain'],remaining_after=y['dto']['remain'],state_before=p,state_after=q,alpha_before=x['alpha']['current'],alpha_after=y['alpha']['current'],expected_remaining=expected,expected_alpha=expected_alpha))
    for name in CASES[:8]:
        rs=[r for r in managed if isinstance(r.get('data'),dict) and r['data'].get('name')==name];s=one(rs,'initialize_result')['data']['snapshot'];value=120 if name=='init-120-reusable' else int(name[5:]);state=0 if value<=0 else 4 if value<=24 else 3 if value<=60 else 2;alpha=-1 if value<=0 else 0 if value<=24 else .25 if value<=60 else .4;require(s['remaining']==value and s['reusable'] is name.endswith('reusable') and s['clone']['state']==state and near(current(s),alpha),'Actual initialization threshold differs')
        require(len([u for u in update_results if u['name']==name])==1,'Threshold update count differs')
    for name,target in [('rate-0',0),('rate-025',.25),('rate-05',.5),('rate-075',.75)]:
        us=[u for u in update_results if u['name']==name];require(len(us)==1 and near(us[0]['doki'],target) and us[0]['remaining_before']==120,'Rate case input/count differs')
    for name in ['wash','cross-0']:
        end=next(r for r in results if r['data']['name']==name)['data']['snapshot'];us=[u for u in update_results if u['name']==name];require(end['remaining']==0 and end['reusable'] is False and end['clone']['state']==0 and current(end)==-1 and not end['clothes']['valid'] and any(u['state_before']==1 and u['state_after']==0 for u in us),'Fade did not finish/remove body material')
    wash=[r for r in managed if isinstance(r.get('data'),dict) and r['data'].get('name')=='wash'];s=one(wash,'wash_return')['data']['snapshot'];require(s['remaining']==0 and s['reusable'] is True and s['clone']['state']==4,'Wash return prematurely cleared reusable or advanced state')
    native_wash=next(b['data']['snapshot'] for a,b in pairs if a['kind']=='paint_wash_enter');require(native_wash['dto']['remain']==0 and native_wash['dto']['reusable'] is True and native_wash['state']==4 and near(native_wash['alpha']['current'],current(s)),'Native wash return differs')
    for name in ['item-ordinary-false','item-reusable','item-ordinary-true']:
        rs=[r for r in managed if isinstance(r.get('data'),dict) and r['data'].get('name')==name];s=one(rs,'item_return')['data']['snapshot'];require(s['remaining']==120 and s['reusable'] is (name!='item-ordinary-false') and s['clone']['state']==2 and current(s)==1 and s['lastItem']==(8 if name=='item-reusable' else 5),'Original item/reusable sticky behavior differs')
        ns=[(a,b) for a,b in pairs if a['kind']=='paint_use_enter' and a['data']['name']==name+'/setup'];require(len(ns)==1,'Original item callback missing/duplicated');a,b=ns[0];require(a['data']['snapshot']['lastItem']==s['lastItem'] and b['data']['snapshot']['dto']['remain']==120 and b['data']['snapshot']['dto']['reusable'] is s['reusable'] and b['data']['snapshot']['state']==2 and b['data']['snapshot']['alpha']['current']==1,'Native item return differs')
    for name,edge,state,alpha in [('cross-60',60,3,.4),('cross-24',24,4,.25),('cross-0',0,1,0)]:
        rs=[r for r in managed if isinstance(r.get('data'),dict) and r['data'].get('name')==name];s=one(rs,'crossing_return')['data']['snapshot'];require(s['remaining']<=edge and s['clone']['state']==state and near(current(s),alpha),'Crossing first frame lost old alpha/state ordering')
        if edge:follow=one(rs,'crossing_follow')['data'];require(follow['alphaAfter']<follow['alphaBefore'] and near(follow['alphaBefore'],alpha),'New target did not start smoothing on next update')
    for name,value,reuse in [('load-ordinary',61,False),('load-reusable',120,True)]:
        rs=[r for r in managed if isinstance(r.get('data'),dict) and r['data'].get('name')==name];dist=one(rs,'load_disturbed')['data']['snapshot'];loaded=one(rs,'loaded_without_initialize')['data']['snapshot'];body=one(rs,'body_broadcast_only')['data']['snapshot'];still=one(rs,'body_only_after_update')['data']['snapshot'];initialized=one(rs,'explicit_initialize_result')['data']['snapshot'];require(loaded['state']!=dist['state'] and loaded['custom']!=dist['custom'] and loaded['remaining']==value and loaded['reusable'] is reuse,'Load did not restore independent DTO/root')
        require(loaded['clone']==dist['clone'] and loaded['materials']==dist['materials'] and loaded['clothes']==dist['clothes'] and not loaded['clothes']['valid'],'Load falsely credited with controller/material application');require(body['clone']['state']==still['clone']['state']==0 and current(body)==current(still)==-1 and body['clothes']['valid'] and body['clothes']==still['clothes'],'Broadcast-only warm-state0 distinction lost');require(initialized['clone']['state']==2 and near(current(initialized),.4),'Explicit Initialize did not reconstruct timed state')
    cleanup=one(managed,'cleanup')['data'];require(all(cleanup[k] is True for k in ['rootsRestored','controllerRestored','objectsRestored','playerStateRestored','stopRestored','slotRestored']),'Cleanup flags differ')
    detailed=one(managed,'cleanup_material_diff_after')['data']['report'];require(detailed['restored'] and detailed['referencesRestored'] and detailed['propertiesRestored'] and detailed['renderers']>0 and detailed['materials']>0 and detailed['comparedProperties']>0,'Detailed material cleanup verification missing')
    require(detailed['extraTweakPresenceChecks']==detailed['materials'] and detailed['independentTweakId']==detailed['staticTweakId']==identity['independentTweakId'],'Shader-enumeration-external Tweak coverage missing')
    require(all(d.get('kind')=='shader_property' and d.get('propertyType') in ['Float','Range'] and d.get('equivalent') is True for d in detailed['differences']),'Unrestored material properties were accepted')
    resets=[r['data'] for r in managed if r['kind']=='shader_reset_for_tweak_presence'];added=[r for r in resets if r['clearAddedTweak']];require(added and all(r['beforeHasTweak'] is True and r['afterHasTweak'] is False and r['absenceRestored'] is True and r['expectedHasTweak'] is False and r['independentTweakId']==identity['independentTweakId'] for r in added),'Added undeclared Tweak presence was not actually cleared')
    done=one(managed,'cleanup_done')['data'];require(all(done[k] is True for k in ['verified','unityMainThread','rootsRestored','controllerRestored','objectsRestored','playerStateRestored','stopRestored','slotRestored']),'Post-verification cleanup completion missing')
    require({k:v for k,v in cleanup['restored'].items() if k!='clone'}=={k:v for k,v in original.items() if k!='clone'} and cleanup['original']==original,'Observed original references/properties/controller not restored')
    require(sum(a['kind']=='paint_update_enter' for a,b in pairs)==len(original_updates)+len(update_results),'Unaccounted native paint update receiver')
    return dict(authority='controlled-unregistered-native-body-paint-clone',natural_only=False,cases=21,encrypted_files=17,baseline_independently_decoded=True,native_messages=len(events),native_call_pairs=len(pairs),automatic_park_guard_updates=len(guard),automatic_park_updates=len(original_updates),manual_updates=len(update_results),updates=update_results,initialization_threshold_cases=8,measured_dokidoki=[0,.25,.5,.75],actual_crossings=[dict(edge=e,states=s) for e,s in [(60,[2,3]),(24,[3,4]),(0,[4,1,0])]],cleanup_verified=True,shader_property_kinds=prep['supportedShaderPropertyKinds'],material_cleanup=detailed,property_id_verified=identity,tweak_presence_resets=resets,limits=['Unregistered native clone and explicit Unity-thread calls; original remains registered and parked. IsStopGameStateApplier is not an automatic-update guard. No natural item UI, three-second producer, natural dispatch or cold title reconstruction claim.','Initialize changes Current/state/pca; neither Initialize nor UpdateTo is credited with changing SmoothFloat.Target. DTO fields do not save the running alpha/state.','Rate observations cover Dokidoki0/.25/.5/.75; negative clamp and arbitrary other rates remain static-only.120 is not a fixed wall-clock120 seconds.','Body, Sao and Tama renderer material targets were read; terminal Setup may replace extra materials and its values are not required to equal the last alpha. The recorded activeInHierarchy=true does not establish Renderer.enabled or pixel visibility; neither was sampled.','Tracked roots, controller/smoothing/player fields and supported shader properties were restored. Native transition MessagePanel queue side effects and complete world/UI equivalence were not checked.'])

def build(inputs=False,require_finalized_plugins=False):
    manifest=read(HERE/'manifest.json');session=read(HERE/'session.json');bundle=read(HERE/'rea-runtime.json');require(len(bundle['records'])==2 and {r['evidence_id'] for r in bundle['records']}==set(session['evidence_ids']),'Selected Evidence identity differs')
    load=next(r for r in bundle['records'] if r['operation']=='load_frida_script');status=next(r for r in bundle['records'] if r['operation']=='frida_session_status');n=status['normalized_result'];require(n['session_id']==session['session_id'] and n['pid']==session['pid'] and n['state']=='running' and not n['messages_truncated'],'Session/capture incomplete')
    require(load['normalized_result']['source_sha256']==sha(HERE/'observe.js') and all(m['type']=='send' and m['script_id']==load['normalized_result']['script_id'] for m in n['messages']),'Observer source/errors differ')
    for item in manifest['sources']+manifest['outputs']+manifest.get('dependencies',[]):require(sha(HERE/item['path'])==item['sha256'],'Manifest fingerprint differs: '+item['path'])
    for item in manifest['outputs']:
        if item['path'].endswith('.gz'):
            raw=gzip.decompress((HERE/item['path']).read_bytes());require(len(raw)==item['uncompressed_bytes'] and hashlib.sha256(raw).hexdigest()==item['uncompressed_sha256'],'Full compressed capture differs')
    raw=json.loads(gzip.decompress((HERE/'raw/rea-runtime-full.json.gz').read_bytes()));byid={r['evidence_id']:r for r in raw['records']};require(all(byid[r['evidence_id']]==r for r in bundle['records']),'Original raw records differ from canonical projection')
    compiled=read(HERE/'compile-only.json');require(compiled['plugin']['sha256']==manifest['plugin']['sha256'],'Archived plugin differs from compilation receipt')
    for item in compiled['sources']:require(sha(HERE/item['path'])==item['sha256'],'Frozen runtime source changed')
    saved=read(HERE/'saved-files.json');managed=rows(HERE/'managed.jsonl.gz');result=analyze(managed,[m['payload'] for m in n['messages']],saved['files'],saved['baseline'])
    baseline=read(HERE/'baseline.json');post=read(HERE/'post-state.json');paths=rows(HERE/'paths.jsonl.gz');working=(Path(baseline['output_root'])/'working-profile').resolve();redirects=[r['data']['after'] for r in paths if r['kind']=='save_path'];require(redirects and all(Path(p).resolve().is_relative_to(working) for p in redirects),'Save path escaped private profile')
    engine=gzip.decompress((HERE/'engine.log.gz').read_bytes()).decode('utf8',errors='replace');require(not any('[Error' in l or '[Fatal' in l or "doesn't have a texture property" in l for l in engine.splitlines()),'Engine log tagged/plain material error')
    process=post['process'];require(process['pid']==session['pid'] and process['normal_exit'] is True and process['quit_command'] is True and process['unity_main_thread'] is True and process['forced_after_close_timeout'] is False and process['process_absent'] and post['frida_detached_reported'],'Target closure/detach incomplete');require(one(managed,'quit_requested')['data']['unityMainThread'] is True,'Unity-thread quit not recorded')
    diagnostics=read(HERE/'diagnostics.json');require(diagnostics['success'] is False and len(diagnostics['runs'])==2,'Two diagnostic boundaries required');first,second=diagnostics['runs']
    require(first['native_messages']==949 and first['engine_errors']==334 and first['reported_results']==21 and first['runner_errors'] and len(first['cleanup'])==1 and first['cleanup'][0]['objectsRestored'] is False and first['close']['forced_after_close_timeout'] is True,'Failed first-run diagnostic boundary was lost')
    require(second['native_messages']==1611 and second['engine_errors']==0 and second['reported_results']==21 and not second['runner_errors'] and second['cleanup'][0]['objectsRestored'] is True and len(second['observed_snapshot_differences'])==10 and second['close']['normal_exit'] is True,'Second-run observation coverage gap was lost')
    for name in ['first-run','second-run']:
        diagdir=HERE/'diagnostics'/name;diagcompile=read(diagdir/'compile-only.json');require(sha(diagdir/'TimedBodyPaintProbe.dll')==diagcompile['plugin']['sha256'],'Diagnostic DLL provenance differs')
        for p in diagcompile['sources']:require(sha(diagdir/p['path'])==p['sha256'],'Diagnostic frozen source differs')
    diagbundle=read(HERE/'diagnostics-rea.json');dm=manifest['diagnostic_observation'];require(dm['success'] is False and len(diagbundle['records'])==4 and {r['evidence_id'] for r in diagbundle['records']}==set(dm['evidence_ids']) and not set(dm['evidence_ids'])&set(manifest['evidence_ids']),'Diagnostic records merged with formal success')
    for r in diagbundle['records']:
        if r['operation']=='load_frida_script':
            archive=next(p for p in dm['archived_frida_sources'] if p['evidence_id']==r['evidence_id']);require(r['normalized_result']['source_sha256']==sha(HERE/archive['path'])==archive['sha256'],'Diagnostic observer provenance differs')
    require([len(post[k]) for k in ['profile','preserved_test_profile','inputs']]==[9,4,5] and all(p['unchanged'] for k in ['profile','preserved_test_profile','inputs'] for p in post[k]),'Protected inputs changed/incomplete')
    final=post['plugins_finalized'];require(not require_finalized_plugins or final,'Plugin finalization pending')
    if final:require(post['plugins_restored'] and not post['extra_plugin_dlls'],'Original plugin inventory not restored')
    if inputs:
        require(all(projection(p['path'])==p for p in saved['files']+[saved['baseline']]),'Independent encrypted projections differ')
        for p in manifest['raw_inputs']:require(sha(p['path'])==p['sha256'],'Raw input fingerprint differs')
        require(sha(manifest['plugin']['archived_path'])==manifest['plugin']['sha256'],'Archived runtime plugin differs')
        for p in dm['plugins']:require(sha(p['archived_path'])==p['sha256'],'Archived diagnostic DLL differs')
        for key in ['profile','preserved_test_profile']:
            for p in post[key]:require(sha(p['path'])==p['before']==p['after'],'Protected profile fingerprint differs')
        for p in post['inputs']:require(sha(p['path'])==sha(p['original_path'])==p['sha256'],'Protected source/resource fingerprint differs')
        if final:
            actual={str(p.resolve()).casefold() for p in (Path(baseline['game_root'])/'BepInEx/plugins').rglob('*.dll')};require(actual=={str(Path(p['path']).resolve()).casefold() for p in baseline['plugins']},'Current plugin DLL inventory differs')
            for p in post['plugins']:require(sha(p['path'])==p['sha256']==p['before'],'Current original plugin fingerprint differs')
    result.update(plugins_finalized=final,protected_inputs=dict(userdata=9,previous_natural_profile=4,native_resources=5),redirected_path_events=len(redirects),process_shutdown=process)
    return result
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--inputs',action='store_true');p.add_argument('--check',action='store_true');p.add_argument('--require-finalized-plugins',action='store_true');a=p.parse_args();r=build(a.inputs,a.require_finalized_plugins)
    if a.check:require(r==read(HERE/'results.json'),'Results differ')
    else:(HERE/'results.json').write_bytes((json.dumps(r,ensure_ascii=False,indent=2)+'\n').encode('utf8'))
    print(json.dumps(dict(cases=r['cases'],encrypted_files=r['encrypted_files'],native_messages=r['native_messages'],manual_updates=r['manual_updates'],plugins_finalized=r['plugins_finalized'])))
