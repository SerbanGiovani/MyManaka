"""Independent preset-file, master-color and actual-renderer consumer checks."""
import argparse,gzip,hashlib,json,math,struct,sys
from pathlib import Path
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parents[1]/'salt'))
import save_codec
SESSION='cba4cc57-1948-4d3b-abe8-81d7e9ba8b74'
IDS=['ev_3e31896e2e2af1feb18d12d21bcf13169bec57b92fe8cdbdfba5a1d56b851c22','ev_dcea3db349f2ca41f850b7f0cf2d486c22563b0e9e8bac5c90e014bf813d6310']
FIELDS=['CustomIsSkinColorFree','CustomizeSkinColor','CustomizeSkinColorR','CustomizeSkinColorG','CustomizeSkinColorB']
MATERIAL_KEYS=['slot','valid','pointer','name','shader','shaderName','hasBase','hasShade','baseColor','shadeColor']
def read(path):return json.loads(Path(path).read_text(encoding='utf-8-sig'))
def sha(path):return hashlib.sha256(Path(path).read_bytes()).hexdigest()
def rows(path):return list(map(json.loads,gzip.decompress(Path(path).read_bytes()).decode('utf8').splitlines()))
def require(value,message):
    if not value:raise ValueError(message)
def one(values,kind):
    selected=[r for r in values if r['kind']==kind];require(len(selected)==1,'Missing/duplicate '+kind);return selected[0]
def near(a,b):return type(a) in [int,float] and type(b) in [int,float] and math.isfinite(a) and math.isfinite(b) and abs(a-b)<=2e-6
def vector(a,b):return isinstance(a,list) and isinstance(b,list) and len(a)==len(b)==4 and all(near(x,y) for x,y in zip(a,b))
def canon(value):
    if isinstance(value,save_codec.ObjectPairs):return {'pairs':sorted((type(k).__name__+':'+str(k),canon(v)) for k,v in value.entries)}
    if isinstance(value,list):return list(map(canon,value))
    if isinstance(value,float):return {'float64':struct.pack('<d',value).hex()}
    return value
def projection(path):
    path=Path(path);data=path.read_bytes();plain,root,reader=save_codec.read(data,'unReRU821Drq83');r=root.strings();require(set(r)=={'PlayerCustomData','IsTrial','GameStateData','SaveDataSlotIndex'},'Game roots differ')
    custom=r['PlayerCustomData'].strings()['value'].strings();fields={k:custom[k] for k in FIELDS}
    require(type(fields[FIELDS[0]]) is bool and all(type(fields[k]) is int for k in FIELDS[1:]),'Independent saved skin field type differs')
    return dict(path=str(path),sha256=sha(path),bytes=len(data),plaintext_sha256=hashlib.sha256(plain).hexdigest(),typed_tree_sha256=hashlib.sha256(json.dumps(canon(root),sort_keys=True,separators=(',',':'),ensure_ascii=False).encode('utf8')).hexdigest(),root_keys=sorted(r),slot=r['SaveDataSlotIndex'].strings()['value'],numeric_key_count=reader.numeric_key_count,custom_field_count=len(custom),fields=fields,scalar_custom={k:v for k,v in custom.items() if type(v) in [int,bool,float]})
def expected_fields(index,free=False):return dict(zip(FIELDS,[free,index,*([17,203,91] if free else [13,71,199])]))
def field_types(fields):return set(fields)==set(FIELDS) and type(fields[FIELDS[0]]) is bool and all(type(fields[k]) is int for k in FIELDS[1:])
def colors(snapshot):return [snapshot[target][key] for target in ['body','face'] for key in ['baseColor','shadeColor']]
def semantic_graph(snapshot):
    return {name:[{k:m[k] for k in MATERIAL_KEYS if k!='pointer'} for m in snapshot[name]['materials']] for name in ['bodyRenderer','faceRenderer']}
def check_targets(snapshot,primary,secondary):
    require(all(vector(c,e) for c,e in zip(colors(snapshot),[primary,secondary,primary,secondary])),'Actual body/face base/shade differs from independent master RGBA')
    for target,renderer,slot in [('body','bodyRenderer',1),('face','faceRenderer',2)]:
        cached=snapshot[target];array=snapshot[renderer]['materials'];require(len(array)>(slot) and cached['valid'] and cached['hasBase'] and cached['hasShade'] and cached['shader'] and cached['shaderName'],'Missing actual skin material/shader')
        require({k:array[slot][k] for k in MATERIAL_KEYS if k!='slot'}=={k:cached[k] for k in MATERIAL_KEYS if k!='slot'},'Skin receiver is not the actual renderer slot')
    for renderer,count in [('bodyRenderer',3),('faceRenderer',7)]:
        materials=snapshot[renderer]['materials'];require(len(materials)==count and [m['slot'] for m in materials]==list(range(count)) and all(m['valid'] and m['shader'] and m['shaderName'] for m in materials),'Renderer topology/shader differs')
    # These additional native writes are visible in the selected renderer arrays.
    for renderer,slot in [('bodyRenderer',2),('faceRenderer',6)]:
        material=snapshot[renderer]['materials'][slot];require(vector(material['baseColor'],primary) and vector(material['shadeColor'],secondary),'Sweat/face-option skin color target differs')
def sequence(events,name,frame,save=False,load=False):
    es=[e for e in events if e['data'].get('name')==name];kinds=['marker_begin']+(['native_load'] if load else [])+['player_initialize_callback','body_customize_event']+(['native_save'] if save else [])+['marker_end']
    require([e['kind'] for e in es]==kinds,'Native entry order differs: '+name)
    require(es[0]['frame']==frame and es[-1]['frame']==frame+10 and es[0]['data']['thread']==es[-1]['data']['thread'],'Bracket thread/10-frame settle differs')
    for e in es[1:-1]:require(e['frame']==(frame+10 if e['kind']=='native_save' else frame),'Native event phase differs')
    for e in es:
        if e['kind'] in ['native_save','native_load']:require(e['data']['pointer']=='0x3' and e['data']['arg1']=='0x1','Native Save/Load type or slot differs')
    require(all(es[i]['real']<=es[i+1]['real'] for i in range(len(es)-1)),'Native event time reversed')
    return es
def analyze(managed,events,files,baseline_file):
    require(not [r for r in managed if r['kind'] in ['runner_error','cleanup_error','cleanup_without_material_backup']],'Fixture/cleanup failed')
    require(len(events)==33 and not [e for e in events if e['kind']=='engine_error'],'Native events incomplete/error')
    ready=one(events,'skin_preset_ready');require(ready['data']['pid']==21048,'Native ready PID differs')
    readiness=[r for r in managed if r['kind']=='readiness'];require(len(readiness)==6 and len([r for r in readiness if r['data']['scene']=='Apartment' and r['data']['hair']])==2,'Readiness polling history was dropped')
    prep=one(managed,'prepared')['data'];require(prep['authority']=='controlled-native-skin-preset' and prep['natural_only'] is False and prep['master'] and prep['patterns'] and prep['disturbedRgb']==[17,203,91],'Fixture authority/master expectation differs')
    expected=prep['expected'];require(len(expected)==2 and [e['index'] for e in expected]==[0,1] and all(vector(e[k],e[k]) for e in expected for k in ['primary','secondary']),'Incomplete master RGBA expectation')
    require(expected[0]!=expected[1] and (not vector(expected[0]['primary'],expected[1]['primary']) or not vector(expected[0]['secondary'],expected[1]['secondary'])),'Preset branches indistinguishable')
    original=prep['original'];detached=prep['detached'];require(original['state']!=detached['state'] and original['custom']!=detached['custom'] and original['stop'] is False and detached['stop'] is True,'Original roots not detached/paused')
    require(baseline_file['fields']==original['fields'] and baseline_file['slot']==1,'Detached baseline differs from original selected skin fields')
    require(len(files)==2 and {Path(f['path']).stem for f in files}=={'preset-0','preset-1'},'Missing/duplicate selected ciphertext')
    results=[];receivers=set();callbacks=set()
    for index in [0,1]:
        name='preset-'+str(index);rs=[r for r in managed if isinstance(r.get('data'),dict) and r['data'].get('name')==name];get=lambda kind:one(rs,kind)
        reference=get('reference_result')['data'];restored_record=get('result')['data'];ref=reference['snapshot'];dist=get('disturbed_result')['data']['snapshot'];loaded=get('loaded_without_application')['data']['snapshot'];restored=restored_record['snapshot']
        require(reference['expected']==restored_record['expected']==expected,'Master expectation changed between phases')
        primary,secondary=expected[index]['primary'],expected[index]['secondary'];free=[17/255,203/255,91/255,1];require(not vector(primary,free),'Perturbation accidentally matches preset')
        for s in [ref,loaded,restored]:require(field_types(s['fields']) and s['fields']==expected_fields(index) and s['stop'] is True,'Saved/free/index/RGB or controlled guard differs')
        require(field_types(dist['fields']) and dist['fields']==expected_fields(index,True) and dist['stop'] is True,'Free=true disturbance differs')
        for s in [ref,restored,get('reference_immediate')['data']['snapshot'],get('restore_immediate')['data']['snapshot']]:check_targets(s,primary,secondary)
        check_targets(dist,free,dist['body']['shadeColor']);require(not vector(dist['body']['shadeColor'],secondary),'Disturbance did not change shade')
        require(loaded['state']!=dist['state'] and loaded['custom']!=dist['custom'],'Load did not recreate saved roots')
        require(loaded['body']==dist['body'] and loaded['face']==dist['face'] and loaded['bodyRenderer']==dist['bodyRenderer'] and loaded['faceRenderer']==dist['faceRenderer'],'Load was falsely credited with material application')
        require(semantic_graph(ref)==semantic_graph(restored),'Broadcast did not restore semantic renderer graph')
        require(len({s['bodyRenderer']['pointer'] for s in [ref,dist,loaded,restored]})==len({s['faceRenderer']['pointer'] for s in [ref,dist,loaded,restored]})==1,'Skin renderers were recreated')
        file=next(f for f in files if Path(f['path']).stem==name);require(field_types(file['fields']) and file['fields']==expected_fields(index) and file['slot']==1 and file['custom_field_count']==baseline_file['custom_field_count'],'Independent saved fields differ')
        require({k:v for k,v in file['scalar_custom'].items() if k not in FIELDS}=={k:v for k,v in baseline_file['scalar_custom'].items() if k not in FIELDS},'Unselected scalar appearance changed in selected captures')
        stages={}
        for stage,start,end in [('reference','reference_immediate','reference_result'),('disturb','disturbed_immediate','disturbed_result'),('restore','restore_immediate','result')]:
            require(get(end)['frame']-get(start)['frame']==10,'Managed settle interval differs')
            es=sequence(events,name+'/'+stage,get(start)['frame'],save=stage=='reference',load=stage=='restore');apply=one(es,'body_customize_event');receivers.add(apply['data']['pointer']);callbacks.add(one(es,'player_initialize_callback')['data']['pointer']);stages[stage]=dict(callbacks=1,body_events=1,frame=get(start)['frame'],settled_frame=get(end)['frame'])
        results.append(dict(name=name,saved_fields=file['fields'],ciphertext_sha256=file['sha256'],expected_primary=primary,expected_secondary=secondary,actual_primary=restored['body']['baseColor'],actual_secondary=restored['body']['shadeColor'],maximum_rgba_error=max(abs(a-b) for observed,wanted in zip(colors(restored),[primary,secondary,primary,secondary]) for a,b in zip(observed,wanted)),load_applied_materials=False,actual_renderer_bindings=dict(body_slot=1,face_slot=2,sweat_slot=2,face_option_slot=6),stages=stages))
    require(len(receivers)==len(callbacks)==1,'Original body/player native receiver changed')
    cleanup=one(managed,'cleanup')['data'];require(all(cleanup[k] is True for k in ['rootsRestored','scalarRestored','slotRestored','refsRestored','colorsRestored','masterUnchanged','stopRestored']) and cleanup['stop'] is False,'Cleanup verification differs')
    require(cleanup['original']==original and cleanup['restored']==original,'Observed original data/material references/colors not restored')
    end=one(managed,'cleanup');es=sequence(events,'cleanup/restore',end['frame']-10);require(one(es,'body_customize_event')['data']['pointer'] in receivers and one(es,'player_initialize_callback')['data']['pointer'] in callbacks,'Cleanup native receiver differs')
    require(sum(e['kind']=='player_initialize_callback' for e in events)==sum(e['kind']=='body_customize_event' for e in events)==7,'Native consumer counts differ')
    return dict(authority='controlled-original-save-load-skin-preset-consumers',natural_only=False,native_messages=33,body_callback_sequences=7,encrypted_files=2,baseline_file_independently_decoded=True,selected_saved_fields=FIELDS,cases=results,readiness=dict(total=6,ready_apartment=2,root_polling_assertion_is_game_error=False),engine_error_events=0,cleanup_verified=True,limits=['Only free=false skin presets0 and1 plus an explicit free=true RGB disturbance are covered. Other appearance fields, physics, UI interactions and cold reconstruction are outside this batch.','SkinPattern expectations are read from original MCustomizeColor/AssetReferencer master RGBA; they are not derived from the reference renderer. Alpha is retained, including preset0 alpha0.','Load restores data but leaves the disturbed material graph until the explicit original player initialization callback. Natural UI dispatch is not demonstrated.','Entry-only hooks prove selected original callback/consumer entries; no unobserved native returns are invented. Body color application was immediate and remains correct after ten frames.','Renderer arrays expose body,face,Sweat and face-option base/shade. All-player shader-color and cached-reference cleanup is additionally asserted by the fixture; a complete shader/property/physics graph is not claimed.','Two Apartment readiness responses and earlier Title polling are retained. An orchestration assertion read an old readiness response; no game runner_error was generated.'])
def build(inputs=False,require_finalized_plugins=False):
    bundle=read(HERE/'rea-runtime.json');require(len(bundle['records'])==2 and {r['evidence_id'] for r in bundle['records']}==set(IDS),'REA records differ')
    byid={r['evidence_id']:r for r in bundle['records']};loader=byid[IDS[0]]['normalized_result'];n=byid[IDS[1]]['normalized_result'];require(n['session_id']==SESSION and n['pid']==21048 and n['mode']=='attach' and n['state']=='running' and not n['messages_truncated'],'Native session differs/truncated')
    require(loader['source_sha256']==sha(HERE/'observe.js') and not loader['messages_truncated'] and all(m['type']=='send' and m['script_id']==loader['script_id'] for m in n['messages']),'Script provenance/errors differ')
    manifest=read(HERE/'manifest.json')
    for item in manifest['sources']+manifest['outputs']+manifest['reused_static']:require(sha(HERE/item['path'])==item['sha256'],'Manifest file fingerprint differs: '+item['path'])
    raw=gzip.decompress((HERE/'raw/rea-runtime-full.json.gz').read_bytes());records={r['evidence_id']:r for r in json.loads(raw)['records']};require(all(records[r['evidence_id']]==r for r in bundle['records']),'Canonical records differ from raw export')
    for item in manifest['outputs']:
        if item['path'].endswith('.gz'):
            data=gzip.decompress((HERE/item['path']).read_bytes());require(len(data)==item['uncompressed_bytes'] and hashlib.sha256(data).hexdigest()==item['uncompressed_sha256'],'Complete gzip content differs')
    compiled=read(HERE/'compile-only.json');require(compiled['plugin']['sha256']==manifest['plugin']['sha256'],'Archived plugin differs from emitted fixture')
    for item in compiled['sources']:require(sha(HERE/item['path'])==item['sha256'],'Frozen compiled source differs')
    saved=read(HERE/'saved-files.json');managed=rows(HERE/'managed.jsonl.gz');result=analyze(managed,[m['payload'] for m in n['messages']],saved['files'],saved['baseline'])
    baseline=read(HERE/'baseline.json');paths=rows(HERE/'paths.jsonl.gz');working=(Path(baseline['output_root'])/'working-profile').resolve();redirected=[r['data']['after'] for r in paths if r['kind']=='save_path'];require(redirected and all(Path(p).resolve().is_relative_to(working) for p in redirected),'Save escaped disposable profile')
    frames=(one(managed,'prepared')['frame'],one(managed,'cleanup')['frame']);context=[r for r in paths if r['kind']=='snapshot' and frames[0]<=r['frame']<=frames[1]];require(context and all(r['data']['scene']=='Apartment' and r['data']['stop'] is False for r in context),'Actual scene/time-stop context differs')
    engine=gzip.decompress((HERE/'engine.log.gz').read_bytes()).decode('utf8',errors='replace');require(not any('[Error' in line or '[Fatal' in line for line in engine.splitlines()),'Engine log error')
    post=read(HERE/'post-state.json');process=post['process'];require(process['pid']==21048 and Path(process['exe']).resolve()==(Path(baseline['game_root'])/'SecretFlasherManaka.exe').resolve() and process['exited'] and process['process_absent'] and process['forced_after_close_timeout'] is True and process['close_main_window'] is False and process['normal_exit_wait_ms']==20000,'Actual forced-stop receipt differs; do not call it a normal exit')
    require(post['frida_detached_reported'] and all(x['unchanged'] for key in ['profile','preserved_test_profile','inputs'] for x in post[key]),'Detach/protected file checks differ')
    require([len(post[k]) for k in ['profile','preserved_test_profile','inputs']]==[9,4,5],'Protected inventory incomplete')
    for key in ['profile','preserved_test_profile','inputs']:
        require({x['path'] for x in post[key]}=={x['path'] for x in baseline[key]},'Protected path inventory differs')
        for x in post[key]:require((x['before'] if 'before' in x else x['sha256'])==next(b['sha256'] for b in baseline[key] if b['path']==x['path']),'Protected baseline hash differs')
    final=post['plugins_finalized'];require(not require_finalized_plugins or final,'Plugin fingerprint finalization pending')
    if final:require(post['plugins_restored'] and all(x['unchanged'] for x in post['plugins']) and not post['extra_plugin_dlls'],'Original plugin cleanup incomplete')
    if inputs:
        require(all(projection(f['path'])==f for f in saved['files']+[saved['baseline']]),'Independent ciphertext projection differs')
        for x in manifest['raw_inputs']:require(sha(x['path'])==x['sha256'],'Immutable raw input fingerprint differs')
        require(sha(manifest['plugin']['archived_path'])==manifest['plugin']['sha256'],'Archived fixture fingerprint differs')
        for key in ['profile','preserved_test_profile']:
            for x in post[key]:require(sha(x['path'])==x['before']==x['after'],'Protected profile changed')
        for x in post['inputs']:require(sha(x['path'])==sha(x['original_path'])==x['sha256'],'Protected native/resource changed')
        if final:
            known={str(Path(x['path']).resolve()).casefold() for x in baseline['plugins']};actual={str(p.resolve()).casefold() for p in (Path(baseline['game_root'])/'BepInEx/plugins').rglob('*') if p.is_file() and p.suffix.lower()=='.dll'};require(actual==known,'Current plugin DLL inventory differs')
            require({x['path'] for x in post['plugins']}=={x['path'] for x in baseline['plugins']},'Plugin baseline inventory differs')
            for x in post['plugins']:require(sha(x['path'])==x['sha256']==x['before']==next(p['sha256'] for p in baseline['plugins'] if p['path']==x['path']),'Current original plugin fingerprint differs')
    result.update(plugins_finalized=final,redirected_path_events=len(redirected),protected_inputs=dict(userdata=9,previous_natural_profile=4,native_resources=5),process_shutdown=dict(normal_exit=False,forced_after_close_timeout=True,native_cleanup_completed_before_stop=True,frida_detached_reported=True))
    return result
if __name__=='__main__':
    parser=argparse.ArgumentParser();parser.add_argument('--inputs',action='store_true');parser.add_argument('--check',action='store_true');parser.add_argument('--require-finalized-plugins',action='store_true');a=parser.parse_args();result=build(a.inputs,a.require_finalized_plugins)
    if a.check:require(result==read(HERE/'results.json'),'Results differ')
    else:(HERE/'results.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(result,ensure_ascii=False,indent=2))
