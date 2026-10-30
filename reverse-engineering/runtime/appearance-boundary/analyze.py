"""Join persistent paint save values to actual ordered renderer material consumers."""
import argparse,gzip,hashlib,json,math,sys
from pathlib import Path
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parents[1]/'salt'))
import save_codec

def read(path):return json.loads(Path(path).read_text(encoding='utf-8-sig'))
def sha(path):return hashlib.sha256(Path(path).read_bytes()).hexdigest()
def rows(path):return list(map(json.loads,gzip.decompress(Path(path).read_bytes()).decode('utf8').splitlines()))
def require(value,message):
    if not value:raise ValueError(message)
def one(values,kind):
    selected=[r for r in values if r['kind']==kind];require(len(selected)==1,'Missing/duplicate '+kind);return selected[0]
def near(a,b):return isinstance(a,(int,float)) and isinstance(b,(int,float)) and math.isfinite(a) and math.isfinite(b) and abs(a-b)<=2e-6
def vector(a,b):return isinstance(a,list) and isinstance(b,list) and len(a)==len(b) and all(near(x,y) for x,y in zip(a,b))
def projection(path):
    data=Path(path).read_bytes();_,root,_=save_codec.read(data,'unReRU821Drq83');r=root.strings();c=r['PlayerCustomData'].strings()['value'].strings();state=r['GameStateData'].strings()['value'].strings();pairs=c['BodyPaintTypeDict'].entries
    require(len(pairs)==10 and set(k for k,v in pairs)==set(range(10)),'Unexpected independent paint map keys')
    require(all(type(k) is int and type(v) is bool for k,v in pairs),'Paint map key/value types changed')
    scalars={k:v for k,v in c.items() if type(v) in [bool,int,float]}
    return dict(path=str(path),sha256=sha(path),bytes=len(data),map=[dict(id=k,present=True,value=v) for k,v in sorted(pairs)],remaining=state['PlayerRemainBodyPaintTime'],reusable=state['IsActiveBodyPaintReusable'],scalar_custom=scalars)

MATERIAL_KEYS=['slot','valid','name','shader','shaderName','hasMain','texture','textureName','hasMatCap','matCap','baseColor','shadeColor','tweak']
def graph(snapshot):return [{k:m[k] for k in MATERIAL_KEYS} for m in snapshot['materials']]
def base_skin(snapshot):return [{k:m[k] for k in ['baseColor','shadeColor']} for m in snapshot['materials'][:2]]
def map_values(snapshot):return {r['id']:r['value'] for r in snapshot['map'] if r['present']}
def topology(snapshot,tattoo,oil):
    materials=snapshot['materials'];require(len(materials)==(4 if tattoo else 3),'Tattoo/oil material count differs')
    require([m['slot'] for m in materials]==list(range(len(materials))) and all(m['valid'] for m in materials),'Invalid/reordered material slots')
    require(all(m['shader'] and m['shaderName'] and m['hasMain'] and m['texture'] for m in materials),'Missing actual shader/texture reference')
    require(snapshot['sweat']==materials[-1]['pointer'] and 'Sweat' in materials[-1]['name'],'Sweat material is not last/controller-bound')
    require('DarkTatto' in materials[2]['name'] if tattoo else 'Sweat' in materials[2]['name'],'Optional TattooDark slot differs')
    require(materials[1]['hasMatCap'] and vector(materials[1]['matCap'],[1,1,1,1] if oil else [0,0,0,1]),'BodyOil second-base MatCap differs')
    require(snapshot['remaining']==0 and snapshot['reusable'] is False and snapshot['paintState']==0 and snapshot['alpha']==-1,'Timed paint entered persistent-map test')
    require(snapshot['rubberDummy'] is False and snapshot['clothes'] is None and snapshot['rubber'] is None,'Selected renderer graph scope changed')

def sequence(events,name,save=False,load=False):
    selected=[e for e in events if e['data'].get('name')==name]
    expected=['marker_begin']+(['native_load'] if load else [])+['player_initialize_callback','body_material_event','body_material_setup','body_apply_options']+(['native_save'] if save else [])+['marker_end']
    require([e['kind'] for e in selected]==expected,'Native entry order differs: '+name)
    begin,end=selected[0],selected[-1]
    require(begin['data']['thread']==end['data']['thread'] and begin['frame']+10==end['frame'],'Bracket thread/settle frame differs')
    for event in selected[1:-1]:require(event['frame']==(end['frame'] if event['kind']=='native_save' else begin['frame']),'Entry frame differs: '+name)
    return selected

def analyze(managed,events,files):
    require(not [r for r in managed if r['kind'] in ['runner_error','cleanup_error']],'Fixture/cleanup error')
    require(not [e for e in events if e['kind']=='engine_error'],'Observed engine error')
    require(len(events)==67,'Native message count differs')
    require(one(managed,'readiness')['data']['ready'],'Asset readiness not observed')
    prep=one(managed,'prepared')['data'];require(prep['authority']=='controlled-native-persistent-body-paint' and prep['natural_only'] is False,'Fixture authority differs')
    original=prep['original'];detached=prep['detached'];require(original['state']!=detached['state'] and original['custom']!=detached['custom'],'Original data roots not detached')
    original_skin=base_skin(original);results=[]
    for name,tattoo,oil in [('tattoo',True,False),('oil',False,True),('combined',True,True)]:
        rs=[r for r in managed if isinstance(r.get('data'),dict) and r['data'].get('name')==name]
        get=lambda kind:one(rs,kind)
        ref=get('reference_result')['data']['snapshot'];dist=get('disturbed_result')['data']['snapshot'];loaded=get('loaded_without_application')['data']['snapshot'];restored=get('result')['data']['snapshot'];immediate=get('restore_immediate')['data']['snapshot']
        expected={i:(tattoo if i==2 else oil if i==8 else False) for i in range(10)};opposite={**expected,2:not tattoo,8:not oil}
        require(len(ref['map'])==len(dist['map'])==len(loaded['map'])==len(restored['map'])==10 and all(r['present'] for s in [ref,dist,loaded,restored] for r in s['map']),'Incomplete native bool map')
        require(map_values(ref)==map_values(loaded)==map_values(restored)==expected and map_values(dist)==opposite,'Map disturbance or restore differs')
        topology(ref,tattoo,oil);topology(dist,not tattoo,not oil);topology(loaded,not tattoo,not oil);topology(restored,tattoo,oil)
        # topology(loaded) intentionally checks the disturbed graph, independently of its restored map.
        require(loaded['state']!=dist['state'] and loaded['custom']!=dist['custom'],'Native Load did not replace the saved data objects')
        require(graph(loaded)==graph(dist) and loaded['sweat']==dist['sweat'] and [m['pointer'] for m in loaded['materials']]==[m['pointer'] for m in dist['materials']],'Load was falsely credited with applying materials')
        require(graph(ref)==graph(restored),'Native body application failed to restore settled semantic material graph')
        # A newly created Sweat instance starts at tweak 0; the existing per-frame
        # consumer puts it at alpha -1 during the ten-frame settle. Do not call the
        # complete property graph immediately restored just because slots match.
        for immediate_kind,settled in [('reference_immediate',ref),('disturbed_immediate',dist),('restore_immediate',restored)]:
            fresh=get(immediate_kind)['data']['snapshot'];expected_fresh=graph(settled);expected_fresh[-1]['tweak']=0
            require(graph(fresh)==expected_fresh and settled['materials'][-1]['tweak']==-1,'Immediate/settled Sweat parameter phase differs')
        require(all(base_skin(s)==original_skin for s in [ref,dist,loaded,immediate,restored]),'Base skin/shade RGBA changed')
        require(len({s['renderer'] for s in [ref,dist,loaded,restored]})==len({s['materialController'] for s in [ref,dist,loaded,restored]})==1,'Renderer/controller was recreated')
        matches=[f for f in files if Path(f['path']).stem==name];require(len(matches)==1,'Missing/duplicate encrypted capture');file=matches[0]
        require(file['map']==ref['map'] and file['remaining']==0 and file['reusable'] is False,'Independent saved bool/timed projection differs')
        require(get('reference_result')['frame']-get('reference_immediate')['frame']==get('disturbed_result')['frame']-get('disturbed_immediate')['frame']==get('result')['frame']-get('restore_immediate')['frame']==10,'Settled-frame window differs')
        stages={}
        for stage,snapshot in [('reference',ref),('disturb',dist),('restore',restored)]:
            ns=sequence(events,name+'/'+stage,save=stage=='reference',load=stage=='restore')
            for kind in ['player_initialize_callback','body_material_event','body_material_setup','body_apply_options']:one(ns,kind)
            for kind in ['body_material_event','body_material_setup','body_apply_options']:require(int(one(ns,kind)['data']['pointer'],16)==int(snapshot['materialController']),'Wrong body material receiver')
            require(sum(e['kind']=='native_save' for e in ns)==(1 if stage=='reference' else 0) and sum(e['kind']=='native_load' for e in ns)==(1 if stage=='restore' else 0),'Native Save/Load phase differs')
            require(not [e for e in ns if e['kind']=='body_paint_set'],'Unexpected in-bracket fixture setter')
            stages[stage]=dict(callbacks=1,events=1,setups=1,applications=1)
        results.append(dict(name=name,active_types=[i for i,v in expected.items() if v],saved_file_sha256=file['sha256'],reference_slots=len(ref['materials']),disturbed_slots=len(dist['materials']),loaded_slots=len(loaded['materials']),restored_slots=len(restored['materials']),body_matcap=restored['materials'][1]['matCap'],skin_rgba_unchanged=True,load_applied_renderer=False,sweat_tweak_immediate=0,sweat_tweak_after_10_frames=-1,stages=stages))
    require(all(f['scalar_custom']==files[0]['scalar_custom'] for f in files),'Non-map scalar custom fields changed across captures')
    cleanup=one(managed,'cleanup')['data'];require(cleanup['rootsRestored'] and cleanup['slotRestored'] and cleanup['stop'] is False and cleanup['sharedMaterialPointersRestored'],'Cleanup flags differ')
    require(cleanup['original']==original and cleanup['restored']==original,'Observed original shared materials/properties or data roots not restored')
    ns=sequence(events,'cleanup/restore')
    for kind in ['player_initialize_callback','body_material_event','body_material_setup','body_apply_options']:one(ns,kind)
    require(sum(e['kind']=='player_initialize_callback' for e in events)==sum(e['kind']=='body_material_event' for e in events)==sum(e['kind']=='body_material_setup' for e in events)==sum(e['kind']=='body_apply_options' for e in events)==10,'Total body consumer counts differ')
    return dict(authority='controlled-original-save-load-body-material-consumers',natural_only=False,cases=results,native_messages=len(events),body_callback_sequences=10,encrypted_files=3,independently_decoded_bool_fields=30,engine_error_events=0,observed_shared_properties_restored=True,limits=['Selected persistent bool map types2 TattooDark and8 BodyOil only; other bool entries are false.','Load restores data while leaving the disturbed renderer graph until the explicit original player initialization callback; natural UI dispatch is unverified.','New runtime material pointers are identities, not a requirement to equal source assets or previous material instances. Shader/texture references, colors and slot ordering are compared.','Original renderer shared materials/properties and recorded controller references were restored. Properties of a RubberSuit material outside that observed array were not separately captured; complete material-graph equivalence is not claimed.','Timed paint fields stayed zero/false, controller state0/alpha-1; timers, physical effects, other appearance options and cold title recreation remain outside scope.'])

def build(inputs=False,require_finalized_plugins=False):
    bundle=read(HERE/'rea-runtime.json');status=one([dict(kind=r['operation'],data=r) for r in bundle['records']],'frida_session_status')['data'];n=status['normalized_result']
    require(n['session_id']=='2f47ca4b-64dc-4bfc-a5ee-6f2b957df81e' and n['pid']==61804 and not n['messages_truncated'] and all(m['type']=='send' for m in n['messages']),'Incomplete native session')
    loader=one([dict(kind=r['operation'],data=r) for r in bundle['records']],'load_frida_script')['data']['normalized_result']
    require(loader['source_sha256']==sha(HERE/'observe.js') and not loader['messages_truncated'] and all(m['script_id']==loader['script_id'] for m in n['messages']),'Observer/script provenance differs')
    manifest=read(HERE/'manifest.json')
    for item in manifest['sources']+manifest['outputs']:require(sha(HERE/item['path'])==item['sha256'],'Manifest file fingerprint differs: '+item['path'])
    compiled=read(HERE/'compile-only.json');require(compiled['plugin']['sha256']==manifest['plugin']['sha256'],'Archived plugin differs from compiled fixture')
    for item in compiled['sources']:require(sha(HERE/item['path'])==item['sha256'],'Fixture source differs from compile receipt')
    files=read(HERE/'saved-files.json')['files'];require(len(files)==3,'Encrypted file count differs');result=analyze(rows(HERE/'managed.jsonl.gz'),[m['payload'] for m in n['messages']],files)
    paths=rows(HERE/'paths.jsonl.gz');baseline=read(HERE/'baseline.json');working=(Path(baseline['output_root'])/'working-profile').resolve()
    redirected=[r['data']['after'] for r in paths if r['kind']=='save_path'];require(redirected and all(Path(p).resolve().is_relative_to(working) for p in redirected),'Save-path redirect escaped private profile')
    prep_frame=one(rows(HERE/'managed.jsonl.gz'),'prepared')['frame'];cleanup_frame=one(rows(HERE/'managed.jsonl.gz'),'cleanup')['frame'];snapshots=[r for r in paths if r['kind']=='snapshot' and prep_frame<=r['frame']<=cleanup_frame]
    require(snapshots and all(r['data']['scene']=='Apartment' and r['data']['stop'] is False for r in snapshots),'Controlled case scene/stop context differs')
    result['redirected_path_events']=len(redirected)
    engine=gzip.decompress((HERE/'engine.log.gz').read_bytes()).decode('utf8',errors='replace');require(not any('[Error' in l or '[Fatal' in l for l in engine.splitlines()),'Engine log error')
    post=read(HERE/'post-state.json');require(post['frida_closed'] and post['process']['exited'] and post['process']['process_absent'],'Appearance process not closed')
    require(all(x['unchanged'] for k in ['profile','preserved_test_profile','inputs'] for x in post[k]),'Protected inputs changed')
    final=post['plugins_finalized'];require(not require_finalized_plugins or final,'Plugin fingerprint finalization pending')
    if final:require(post['plugins_restored'] and all(p['unchanged'] for p in post['plugins']),'Original plugins not restored')
    if inputs:
        require(all(projection(p['path'])==p for p in files),'Independent encrypted projection differs')
        for key in ['profile','preserved_test_profile']:
            for p in post[key]:require(sha(p['path'])==p['before']==p['after'],'Protected profile fingerprint changed')
        for p in post['inputs']:require(sha(p['path'])==sha(p['original_path'])==p['sha256'],'Protected native/resource fingerprint changed')
        if final:
            for p in post['plugins']:require(sha(p['path'])==p['sha256'],'Final plugin fingerprint changed')
    result['plugins_finalized']=final
    result['protected_inputs']=dict(userdata=len(post['profile']),previous_natural_profile=len(post['preserved_test_profile']),native_resources=len(post['inputs']))
    return result
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--inputs',action='store_true');p.add_argument('--check',action='store_true');p.add_argument('--require-finalized-plugins',action='store_true');a=p.parse_args();r=build(a.inputs,a.require_finalized_plugins)
    if a.check:require(r==read(HERE/'results.json'),'Results differ')
    else:(HERE/'results.json').write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(r,ensure_ascii=False,indent=2))
