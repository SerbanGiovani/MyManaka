"""Join passive natural inventory, delayed original effects and fresh-process paint load."""
import argparse,collections,gzip,hashlib,json,math,runpy,sys
from datetime import datetime
from pathlib import Path
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parents[1]/'salt'))
import save_codec
NUMERIC=runpy.run_path(str(HERE.parent/'timed-body-paint/analyze.py'))
near,f32,timer,alpha_step,raw_float=[NUMERIC[k] for k in ['near','f32','timer','alpha_step','raw_float']]
def read(p):
    p=Path(p)
    if p.suffix=='.gz':
        with gzip.open(p,'rt',encoding='utf-8-sig') as f:return json.load(f)
    return json.loads(p.read_text(encoding='utf-8-sig'))
def sha(p):
    with Path(p).open('rb') as f:return hashlib.file_digest(f,'sha256').hexdigest()
def rows(p):
    with gzip.open(p,'rt',encoding='utf8') as f:return [json.loads(line) for line in f]
def require(v,m):
    if not v:raise ValueError(m)
def ptr(v):return 0 if v is None else int(str(v),0)
def int32(v):
    n=ptr(v)&0xffffffff;return n if n<0x80000000 else n-0x100000000
def qty(v):return 0 if v is None else v
def canonical(v):
    if isinstance(v,save_codec.ObjectPairs):
        pairs=[(type(k).__name__+':'+str(k),canonical(x)) for k,x in v.entries];require(len({k for k,x in pairs})==len(pairs),'Duplicate typed save key');return dict(pairs=sorted(pairs))
    if isinstance(v,list):return list(map(canonical,v))
    if isinstance(v,float):return dict(float64=__import__('struct').pack('<d',v).hex())
    return v
def treehash(v):return hashlib.sha256(json.dumps(canonical(v),sort_keys=True,separators=(',',':'),ensure_ascii=False).encode('utf8')).hexdigest()
def projection(p):
    p=Path(p);data=p.read_bytes();plain,root,reader=save_codec.read(data,'unReRU821Drq83');r=root.strings();result=dict(path=str(p),sha256=sha(p),bytes=len(data),plaintext_sha256=hashlib.sha256(plain).hexdigest(),typed_tree_sha256=treehash(root),numeric_key_count=reader.numeric_key_count,root_keys=sorted(r))
    if 'GameStateData' not in r:return dict(result,kind='system',root_values=[dict(key=k,type=v.strings()['__type'],value_sha256=treehash(v.strings()['value'])) for k,v in sorted(r.items())])
    s=r['GameStateData'].strings()['value'].strings();c=r['PlayerCustomData'].strings()['value'].strings();items=s['ItemDict'].entries;require(all(type(k) is int and type(v) is int for k,v in items),'Saved inventory types differ')
    return dict(result,kind='game',slot=r['SaveDataSlotIndex'].strings()['value'],stage=s['CurrentStageType'],rp=s['CurrentRp'],exp=s['ExposeExp'],remaining=s['PlayerRemainBodyPaintTime'],reusable=s['IsActiveBodyPaintReusable'],all_items_raw_entries=[[k,v] for k,v in items],items={str(i):next((v for k,v in items if k==i),None) for i in [5,8,9]},custom_tree_sha256=treehash(r['PlayerCustomData']),custom_fields=len(c),active_parts=[k for k,v in s['PlayerCosplayPartsDict'].entries if v is True],hair=c['CurrentHair'])
def pair_events(events,complete=True):
    pending={};pairs=[];seen=set()
    for index,e in enumerate(events):
        k=e['kind'];d=e['data']
        if k.endswith('_enter'):
            family=k.removesuffix('_enter');key=('action' if family=='action_update' else 'regular',d['id']);require(key not in seen,'Duplicate native invocation identity');seen.add(key);pending[key]=(index,e,family)
        elif k.endswith('_leave'):
            family=k.removesuffix('_leave');key=('action' if family=='action_update' else 'regular',d['id']);require(key in pending,'Native return has no entry');start,entry,kind=pending.pop(key);require(kind==family and e['real']>=entry['real'] and e['frame']>=entry['frame'],'Native entry/return kind/time differs')
            if 'pointer' in d:require(d['pointer']==entry['data']['pointer'],'Native receiver changed inside invocation')
            pairs.append(dict(kind=kind,start=start,end=index,entry=entry,leave=e))
    require(not complete or not pending,'Selected natural capture has unfinished native invocations')
    return pairs
def game_actor(e):return e['data'].get('actor') or {}
def snapshot_materials(s):
    body=s.get('body');clothes=s.get('clothes');require(body and body['materials'] and clothes,'Natural body material snapshot incomplete')
    if clothes['valid']:require(len(body['materials'])>=4 and any(ptr(m['pointer'])==ptr(clothes['pointer']) for m in body['materials']),'Paint material is not in actual body renderer')
    for target,renderer in [('sao','saoRenderer'),('tama','tamaRenderer')]:
        m=s.get(target);r=s.get(renderer)
        if m and m['valid'] and r:require(r['materials'] and ptr(r['materials'][-1]['pointer'])==ptr(m['pointer']),'Natural extra material binding differs')
def verify_paint_samples(events):
    selected=[e for e in events if e['kind']=='paint_update_pair'];require(selected,'No original paint updates witnessed');checked=[];last={}
    for e in selected:
        d=e['data'];a,b=d['before'],d['after'];x,y=d['actorBefore'],d['actorAfter'];require(a and b and x and y and x.get('dto') and y.get('dto'),'Natural selected update lacks actor/DTO')
        require(d['pointer']==a['pointer']==b['pointer'] and ptr(a['pca'])==ptr(x['pca']) and ptr(b['pca'])==ptr(y['pca']),'Natural registered paint/Pca binding differs');require(e['frame']==d['entryFrame'],'Natural paint return crossed frame')
        dt=d['delta'];require(math.isfinite(dt) and dt>=0,'Invalid actual natural deltaTime');expected=timer(x['dto']['remain'],x['doki'],dt);require(near(y['dto']['remain'],expected),'Selected natural countdown differs from actual dt/Dokidoki')
        words=a['alpha']['words'];require((int(words[4],16)&255)==0 and (int(words[8],16)&255)==0,'Original BodyPaint smoothing configuration differs');alpha=alpha_step(a['alpha']['current'],a['state'],dt,raw_float(words,1),raw_float(words,2));require(near(b['alpha']['current'],alpha),'Selected natural smoothing differs')
        state=0 if a['state']==1 and alpha<=-1 else 3 if a['state']==2 and expected<=60 else 4 if a['state']==3 and expected<=24 else 1 if a['state']==4 and expected<=0 else a['state'];require(b['state']==state,'Selected natural transition differs');require(y['dto']['reusable'] is (False if a['state']==4 and state==1 else x['dto']['reusable']),'Selected natural reusable transition differs')
        require(a['alpha']['target']==b['alpha']['target'],'Natural UpdateTo was credited with Target mutation');totals=d['totals'];old=last.get(d['pointer']);require(totals['updates']>0 and (old is None or totals['updates']>old['updates'] and totals['dt']>=old['dt']),'Complete original-update aggregates not monotone');last[d['pointer']]=totals
        checked.append(dict(frame=e['frame'],pointer=d['pointer'],selection=d['selection'],count=d['count'],receiver_updates=totals['updates'],remaining=y['dto']['remain'],state=state,alpha=b['alpha']['current']))
    return dict(selected_pairs=len(checked),selection_counts=dict(collections.Counter(x['selection'] for x in checked)),latest_sample_totals=last,limits='Selected event windows/state changes/one-second samples only. Aggregates count all returns; unsampled individual updates are not reconstructed.',samples=checked)
def verify_initializations(events):
    pairs=pair_events(events);initializations=[]
    for p in pairs:
        if p['kind']!='pca_initialize':continue
        a=p['entry']['data'];b=p['leave']['data'];actor=b['actor'];paint=actor.get('paint');dto=actor.get('dto');require(paint and dto and ptr(paint['pca'])==ptr(a['pointer'])==ptr(actor['pca']),'Original Pca return did not bind its paint controller')
        remain=dto['remain'];state=0 if remain<=0 else 4 if remain<=24 else 3 if remain<=60 else 2;alpha=-1 if remain<=0 else 0 if remain<=24 else .25 if remain<=60 else .4;require(paint['state']==state and near(paint['alpha']['current'],alpha),'Inline original cold/warm initialization differs from loaded remain')
        initializations.append(dict(frame=p['leave']['frame'],time=p['leave']['time'],pca=actor['pca'],paint=paint['pointer'],remaining=remain,reusable=dto['reusable'],state=state,alpha=paint['alpha']['current']))
    require(initializations,'No complete original Pca.Initialize return observed');return initializations
def analyze_use(managed,events,files):
    require(not [r for r in managed if r['kind'] in ['snapshot_error','capture_error']],'Natural state/file observer failed');require(not [e for e in events if e['kind'] in ['engine_error','engine_error_sample']],'Natural engine error');pairs=pair_events(events);effects=[p for p in pairs if p['kind']=='item_effect' and p['entry']['data']['itemType'] in [5,8,9]];out=[];pending=[]
    command_errors=[r for r in managed if r['kind']=='command_error']
    for error in command_errors:
        require(error['data']['error'].startswith('System.IO.IOException:') and 'PassiveState.Command()' in error['data']['error'],'Unclassified observer command failure')
        require(any(r['kind']=='operator_marker' and r['data']['label']=='humancomplete' for r in managed) and any(r['kind']=='quit_requested' and r['frame']>error['frame'] and r['data']['humanComplete'] is True for r in managed),'Metadata command error lacks successful gated quit recovery')
    for effect in effects:
        entry,leave=effect['entry'],effect['leave'];typ=entry['data']['itemType'];a,b=game_actor(entry),game_actor(leave);require(a and b and a['pca']==b['pca'] and b['lastItem']==typ and b['transAction']==10008 and ptr(b['completion']),'Natural delayed effect was not scheduled on the real player');require(near(b['deadline'],f32(entry['time']+3)),'Natural deadline is not original Time.time+3')
        uses=[p for p in pairs if p['kind']=='inventory_use_process' and p['start']<effect['start']<effect['end']<p['end']];require(len(uses)==1,'Effect lacks original inventory UseProcess parent');use=uses[0];buttons=[p for p in pairs if p['kind']=='inventory_use_button' and p['start']<effect['start']];require(buttons,'Natural use has no preceding observed UI button')
        changes=[p for p in pairs if p['kind']=='item_change' and use['start']<p['start']<p['end']<use['end'] and int32(p['entry']['data']['arg0'])==typ];expected_delta=-1 if typ==5 else 0;require(len(changes)==(1 if typ==5 else 0),'Natural reusable/immediate consumption count differs')
        if typ==5:
            change=changes[0];require(change['end']<effect['start'] and int32(change['entry']['data']['arg1'])==-1,'Ordinary paint was not consumed before delayed scheduling');before=game_actor(change['entry'])['dto']['items']['5'];after=game_actor(change['leave'])['dto']['items']['5'];require(qty(before)>0 and qty(after)==qty(before)-1,'Natural ordinary inventory decrement did not persist')
        family={5:'ordinary_completion',8:'reusable_completion',9:'washer_completion'}[typ];next_effect=min([x['start'] for x in effects if x['start']>effect['start'] and game_actor(x['entry']).get('pca')==b['pca']],default=len(events));callbacks=[p for p in pairs if p['kind']==family and effect['end']<p['start']<next_effect and game_actor(p['entry']).get('pca')==b['pca']]
        if not callbacks:pending.append(dict(type=typ,frame=entry['frame'],deadline=b['deadline'],scope='Scheduled request lacks a later selected completion before next request; not counted as successful use.'));continue
        require(len(callbacks)==1,'One scheduled request produced duplicate completion');callback=callbacks[0];ca,cb=game_actor(callback['entry']),game_actor(callback['leave']);require(callback['entry']['time']>b['deadline'] and ca['currentAction']==10008 and ca['completion']==b['completion'],'Completion did not follow original strict game-time action/delegate guard')
        actions=[p for p in pairs if p['kind']=='action_update' and p['start']<callback['start']<callback['end']<p['end']];require(len(actions)==1,'Completion lacks original PlayerAction.OnUpdate parent');require(actions[0]['leave']['data']['actorAfter']['currentAction']==-1,'Original action did not return to idle after completion')
        paint=cb['paint'];dto=cb['dto']
        if typ in [8,9]:require(qty(b['dto']['items'][str(typ)])==qty(ca['dto']['items'][str(typ)])==qty(dto['items'][str(typ)])>0,'Natural reusable item stock changed during use/completion')
        if typ in [5,8]:require(dto['remain']==120 and paint['state']==2 and paint['alpha']['current']==1 and dto['reusable'] is (True if typ==8 else ca['dto']['reusable']),'Natural paint callback result differs')
        else:require(dto['remain']==0 and paint['state']==4 and dto['reusable'] is ca['dto']['reusable'],'Natural inline washer prematurely advanced/cleared reusable')
        paint_uses=[p for p in pairs if p['kind']=='paint_use' and callback['start']<p['start']<p['end']<=callback['end']]
        if typ in [5,8]:require(len(paint_uses)==1,'Original paint callback target missing/duplicated')
        else:require(not paint_uses,'Washer confused with paint use')
        out.append(dict(type=typ,effect_frame=entry['frame'],effect_time=entry['time'],deadline=b['deadline'],completion_frame=callback['entry']['frame'],completion_time=callback['entry']['time'],game_time_delay=callback['entry']['time']-entry['time'],remaining=dto['remain'],reusable=dto['reusable'],paint=paint['pointer'],pca=b['pca'],state=paint['state'],alpha=paint['alpha']['current'],inventory_delta=expected_delta,items_at_schedule=b['dto']['items'],items_at_completion=dto['items'],washer_independent_entry_required=False))
    require({x['type'] for x in out}=={5,8,9},'Natural complete use coverage requires actual types5/8/9, regardless of user completion message')
    snapshots=[r for r in managed if r['kind']=='snapshot' and r['data'].get('paint') and r['data'].get('controllerPcaBound')]
    matching=[]
    for r in snapshots:
        s=r['data'];snapshot_materials(s)
        if s['remaining']>0 and s['clothes']['valid'] and s['clothes']['hasTweak'] and near(s['clothes']['tweak'],s['paint']['smooth']['Current']):matching.append(r['frame'])
    require(matching,'No natural positive-paint actual body material/application sample');require(all(r['data']['applier'] is False and r['data']['timeStop'] is False for r in snapshots),'Natural run used a controlled applier/time stop')
    gamefiles=[f for f in files if f['kind']=='game'];require(gamefiles and all(f['slot']==1 for f in gamefiles),'Natural files did not remain in selected slot1')
    for f in gamefiles:
        if f['capture']['initial']:continue
        candidates=[p for p in pairs if p['kind']=='save' and p['leave']['frame']<=f['capture']['frame'] and game_actor(p['leave']).get('dto') and near(game_actor(p['leave'])['dto']['remain'],f['remaining']) and game_actor(p['leave'])['dto']['reusable'] is f['reusable'] and game_actor(p['leave'])['dto']['items']==f['items']]
        require(candidates,'New natural game ciphertext lacks matching original Save return DTO')
    return dict(completed=out,scheduled_without_completed_evidence=pending,initializations=verify_initializations(events),paint_updates=verify_paint_samples(events),material_matching_frames=matching,saved_game_files=len(gamefiles),command_errors_retained=command_errors,limits=['User input and passive source establish natural UI use; activeInHierarchy of the inventory view itself was not separately sampled.','Reusable confirmation can outlive the button method frame; no artificial same-stack requirement is imposed across the popup.','Repeated Body.Setup/Apply entries may be original clothing transitions, not duplicate item effects.','Independent washer completion is inline; lack of the standalone paint_wash entry is not a missed effect.'])

def analyze_cold(managed,events,files,cold_baseline,start_receipt,use_close,use_files):
    require(use_close['normal_exit'] and use_close['process_absent'] and start_receipt['start_time_utc']>use_close['utc'],'Fresh process start lacks prior verified exit')
    old=datetime.fromisoformat(use_close['utc'].replace('Z','+00:00'));new=datetime.fromisoformat(start_receipt['start_time_utc'].replace('Z','+00:00'));require(new>old,'Process creation time does not follow old exit; PID difference is not the criterion')
    require(cold_baseline['profile_copy_only'] is True and cold_baseline['manual_slot']==1 and len(cold_baseline['copied_files'])==4,'Cold run did not copy the same four-file isolated profile')
    manual=next(x for x in cold_baseline['copied_files'] if x['relative'].replace('\\','/')=='SaveData/1.sd');source=next(f for f in use_files if f['sha256']==manual['sha256'] and f['kind']=='game' and not f['capture']['initial']);require(source['remaining']>0 and source['reusable'] is True,'Cold source is not the actual natural positive reusable save')
    initial=[f for f in files if f['kind']=='game' and f['sha256']==manual['sha256'] and f['capture']['initial']];require(initial,'Cold input ciphertext is not byte-identical to natural output')
    require(not [r for r in managed if r['kind'] in ['snapshot_error','capture_error','command_error']],'Cold passive observer error');require(not [e for e in events if e['kind'] in ['engine_error','engine_error_sample']],'Cold game engine error');require(not [e for e in events if e['kind'] in ['item_effect_enter','ordinary_completion_enter','reusable_completion_enter','washer_completion_enter']],'Cold result was obtained by replaying a new item effect')
    pairs=pair_events(events);loads=[p for p in pairs if p['kind']=='load' and int32(p['entry']['data']['arg0'])==3 and int32(p['entry']['data']['arg1'])==1];require(loads,'Cold title did not invoke original manual-slot1 load');load=loads[0];dto=game_actor(load['leave'])['dto'];require(near(dto['remain'],source['remaining']) and dto['reusable'] is source['reusable'] and dto['items']==source['items'],'Cold native Load does not match decoded natural save')
    initializations=verify_initializations(events);matching=[x for x in initializations if x['remaining']>0 and x['reusable'] is True and near(x['remaining'],source['remaining'])];require(matching,'No original inline controller initialization from positive natural save');init=matching[0]
    snapshots=[r for r in managed if r['kind']=='snapshot' and r['data'].get('paint') and ptr(r['data']['paint']['pointer'])==ptr(init['paint']) and r['frame']>=init['frame']];material=[];ids=[]
    for r in snapshots:
        s=r['data'];require(s['controllerPcaBound'] is True and s['applier'] is False and s['timeStop'] is False,'Cold controller used forced state/stop guards');snapshot_materials(s)
        if s['clothes']['valid'] and s['clothes']['hasTweak'] and near(s['clothes']['tweak'],s['paint']['smooth']['Current']):material.append(r['frame'])
        check=s['staticPropertyId']
        if check.get('observed') and check.get('matches') is True:ids.append(check['staticTweakId'])
    require(material and ids,'Cold actual shader target/property identity not observed after natural initialization')
    return dict(source_ciphertext_sha256=source['sha256'],saved_remaining=source['remaining'],saved_reusable=source['reusable'],saved_items=source['items'],initializations=initializations,material_matching_frames=material,property_ids=sorted(set(ids)),paint_updates=verify_paint_samples(events),pid_reused=start_receipt['pid']==use_close['pid'],previous_close_utc=use_close['utc'],new_creation_utc=start_receipt['start_time_utc'],limits=['Different process creation and verified prior absence establish cold startup even when Windows reuses the PID.','No standalone paint_initialize entry is required: original Pca.Initialize inlines that coordination.','Material fields and renderer slots were read; renderer.enabled and visible pixels were not sampled.'])

def build(inputs=False,require_finalized_plugins=False):
    plan=read(HERE/'session-plan.json');manifest=read(HERE/'manifest.json');require(len(plan['runs'])==2 and plan['runs'][0]['session_id']!=plan['runs'][1]['session_id'],'Natural-use and fresh-process session identities required')
    for item in manifest['sources']+manifest['outputs']+manifest['dependencies']:require(sha(HERE/item['path'])==item['sha256'],'Manifest fingerprint differs: '+item['path'])
    compiled=read(HERE/'compile-only.json');require(compiled['plugin']['sha256']==manifest['plugin']['sha256'],'Observer archive differs from original compilation')
    for item in compiled['sources']:require(sha(HERE/item['path'])==item['sha256'],'Frozen passive observer source changed')
    runs=[]
    for meta in plan['runs']:
        folder=HERE/'runs'/meta['name'];bundle=read(folder/'rea-runtime.json.gz');by={r['evidence_id']:r for r in bundle['records']};require(set(by)=={meta['load_evidence_id'],meta['final_status_evidence_id']},'Exact selected Evidence IDs differ');load=by[meta['load_evidence_id']];status=by[meta['final_status_evidence_id']];n=status['normalized_result'];require(status['operation']=='frida_session_status' and n['session_id']==meta['session_id'] and n['pid']==meta['pid'] and n['state']=='running' and n['messages_truncated'] is False,'Formal natural capture is truncated or has wrong session')
        require(load['normalized_result']['source_sha256']==sha(HERE/'observe.js') and all(m['type']=='send' and m['script_id']==load['normalized_result']['script_id'] for m in n['messages']),'Formal passive script provenance/error differs')
        with gzip.open(folder/'rea-runtime-full.json.gz','rt',encoding='utf8') as f:raw=__import__('json').load(f)
        raw_by={r['evidence_id']:r for r in raw['records']};require(all(raw_by[k]==v for k,v in by.items()),'Raw full export differs from selected canonical records')
        managed=rows(folder/'managed.jsonl.gz');files=read(folder/'saved-files.json')['files'];events=[m['payload'] for m in n['messages']];close=read(folder/'close-receipt.json');require(close['normal_exit'] and close['process_absent'] and close['frida_detach_confirmed'] and close['quit_command'] and close['unity_main_thread'],'Formal target did not quit/detach normally');require(any(r['kind']=='quit_requested' and r['data']['humanComplete'] is True for r in managed),'Passive gated Unity quit not recorded')
        working=Path(meta['raw_root'])/'working-profile';redirects=[r['data']['after'] for r in rows(folder/'paths.jsonl.gz') if r['kind']=='save_path'];require(redirects and all(Path(p).resolve().is_relative_to(working.resolve()) for p in redirects),'Natural save redirection escaped isolated profile')
        with gzip.open(folder/'engine.log.gz','rt',encoding='utf8',errors='replace') as f:require(not any('[Error' in line or '[Fatal' in line or 'IndexOutOfRangeException:' in line or 'NullReferenceException:' in line for line in f),'Formal engine log contains tagged/plain exception')
        runs.append(dict(meta=meta,managed=managed,files=files,events=events,close=close))
    use,cold=runs;natural=analyze_use(use['managed'],use['events'],use['files']);restarted=analyze_cold(cold['managed'],cold['events'],cold['files'],read(HERE/'cold-baseline.json'),read(HERE/'cold-start-receipt.json'),use['close'],use['files'])
    diagnostic=read(HERE/'diagnostics.json');require(diagnostic['success'] is False and diagnostic['capture_complete'] is False and diagnostic['frida_detach_confirmed'] is False and diagnostic['engine_initial_exception_excerpt'],'Incompatible-profile diagnostic limitations lost');diagbundle=read(HERE/'diagnostics-rea.json.gz');dm=manifest['diagnostic_observation'];require(len(diagbundle['records'])==3 and {r['evidence_id'] for r in diagbundle['records']}==set(dm['evidence_ids']) and {r['evidence_id'] for r in diagbundle['records'] if r['normalized_result']['messages_truncated']}==set(dm['truncated_evidence_ids']),'Diagnostic retained truncation/IDs differ');require(dm['truncated_evidence_ids'] and not set(dm['evidence_ids'])&set(manifest['evidence_ids']),'Failed partial diagnostic merged with formal successful capture')
    for r in diagbundle['records']:
        if r['operation']=='load_frida_script':
            a=next(x for x in dm['archived_frida_sources'] if x['evidence_id']==r['evidence_id']);require(a['original_path']==r['normalized_result']['source_path'] and a['sha256']==r['normalized_result']['source_sha256']==sha(HERE/a['path']),'Archived diagnostic observer source differs')
    post=read(HERE/'post-state.json');require([len(post[k]) for k in ['profile','preserved_test_profile','inputs']]==[9,4,5] and all(x['unchanged'] for key in ['profile','preserved_test_profile','inputs'] for x in post[key]),'Original protected input inventory changed/incomplete');final=post['plugins_finalized'];require(not require_finalized_plugins or final,'Plugin restoration not finalized')
    if final:require(post['plugins_restored'] and not post['extra_plugin_dlls'],'Original plugin restoration failed')
    if inputs:
        for run in runs:
            for row in run['files']:
                expected=projection(row['path']);require(all(row[k]==v for k,v in expected.items()),'Independent natural encrypted projection differs')
        for row in manifest['raw_inputs']:require(sha(row['path'])==row['sha256'],'Full immutable raw input differs')
        for row in [manifest['plugin'],plan['cold_plugin']]+dm['plugins']:require(sha(row['archived_path'])==row['sha256'],'Archived observer plugin differs')
        for key in ['profile','preserved_test_profile']:
            for row in post[key]:require(sha(row['path'])==row['before']==row['after'],'Protected user profile differs')
        for row in post['inputs']:require(sha(row['path'])==sha(row['original_path'])==row['sha256'],'Original native/asset input differs')
        for row in read(HERE/'cold-baseline.json')['copied_files']:require(sha(row['source'])==row['sha256'],'Frozen natural source used for cold copy changed')
        if final:
            for row in post['plugins']:require(sha(row['path'])==row['before']==row['sha256'],'Current original plugin differs')
    return dict(authority=manifest['authority'],natural_only=True,natural_use=natural,cold_process=restarted,formal_sessions=[dict(session_id=r['meta']['session_id'],pid=r['meta']['pid'],native_messages=len(r['events']),encrypted_files=len(r['files'])) for r in runs],diagnostic=diagnostic,plugins_finalized=final,protected_inputs=dict(userdata=9,previous_natural_profile=4,native_resources=5),limits=['No inventory/money/skill injection, gameplay replay, clone or forced BodyPaint class initialization was used. Source/save-root isolation and metadata markers are observational infrastructure.','Existing profile0 was not compatible; successful source is protected original slot1, followed by actual natural output copied byte-for-byte for a new process.','Natural acquisition counts are witnessed; individual shop UI price/payment paths were not separately fully hooked in this observer.'])
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--inputs',action='store_true');p.add_argument('--check',action='store_true');p.add_argument('--require-finalized-plugins',action='store_true');a=p.parse_args();result=build(a.inputs,a.require_finalized_plugins)
    if a.check:require(result==read(HERE/'results.json'),'Results differ')
    else:(HERE/'results.json').write_bytes((json.dumps(result,ensure_ascii=False,indent=2)+'\n').encode('utf8'))
