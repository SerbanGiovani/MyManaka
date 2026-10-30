"""Independently check the built-player seed -> moved save -> new-process pose readback."""
import argparse,gzip,hashlib,json,math,struct,sys
from datetime import datetime
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parent))
from prepare_seed import HERE,project,sha,value_sha
def read(path):
    path=Path(path)
    if path.suffix=='.gz':
        with gzip.open(path,'rt',encoding='utf-8-sig') as f:return json.load(f)
    return json.loads(path.read_text(encoding='utf-8-sig'))
def events(path):
    path=Path(path)
    with (gzip.open(path,'rt',encoding='utf8') if path.suffix=='.gz' else path.open(encoding='utf8')) as f:return [json.loads(x) for x in f]
def local(path):
    path=Path(path);return path if path.is_absolute() else HERE/path
def require(value,message):
    if not value:raise ValueError(message)
def bits(value):
    require(type(value) in [int,float] and math.isfinite(value),'Nonfinite/nonnumeric runtime float');return struct.pack('<f',value).hex()
def runtime_float(value):return struct.unpack('<f',bytes.fromhex(bits(value)))[0]
def same(a,b,keys):return set(a)==set(b)==set(keys) and all(bits(a[k])==bits(b[k]) for k in keys)
def one(rows,kind):
    selected=[r for r in rows if r['kind']==kind];require(len(selected)==1,'Missing/duplicate '+kind);return selected[0]
def pose(row,position,rotation):return same(row['position'],position,['x','y','z']) and same(row['rotation'],rotation,['x','y','z','w'])
def quaternion_error(a,b):
    """Rotation distance is sign invariant; compare components separately for exactness."""
    keys=['x','y','z','w']
    require(set(a)==set(b)==set(keys),'Quaternion component schema differs')
    a={k:runtime_float(a[k]) for k in keys};b={k:runtime_float(b[k]) for k in keys}
    norm_a=math.sqrt(sum(a[k]**2 for k in keys));norm_b=math.sqrt(sum(b[k]**2 for k in keys))
    require(abs(norm_a-1)<.01 and abs(norm_b-1)<.01,'Runtime quaternion is not near unit length')
    dot=abs(sum(a[k]*b[k] for k in keys))/(norm_a*norm_b)
    return math.degrees(2*math.acos(min(1,max(0,dot))))
def callback_counts(proof,rows):
    errors=[r for r in rows if r['kind']=='engine_error']
    known=[r for r in errors if r['data']['classification']=='known-original-shader-constant-buffer' and r['data']['message'].strip()=="Struct '_MainTex' is not in any constant buffer."]
    require(proof['engineErrorCount']==len(errors) and proof['knownCompatibilityErrors']==len(known) and proof['unexpectedEngineErrors']==len(errors)-len(known)==0,'Engine error classifications/counters differ or include an unexpected error')
    warnings=[r for r in rows if r['kind']=='engine_message' and r['data']['type']=='Warning']
    missing=[r for r in warnings if 'referenced script' in r['data']['message'].lower() and 'missing' in r['data']['message'].lower()]
    require(proof['engineWarningCount']==len(warnings) and proof['missingScriptWarnings']==len(missing),'Engine warning counters differ')
    degraded=bool(errors or missing or proof['playerShaderFallbacks'] or proof['unresolvedBuiltinMeshes'] or proof['geometryTextures']<proof['declaredTextures'])
    require(not degraded or proof['degradedAssetCompatibility'] is True,'Resource compatibility degradation was concealed')
    require(proof['originalShaderCompatibilityVerified'] is False,'Original shader compatibility is outside this acceptance')
    return dict(callback_errors=len(errors),known_constant_buffer_errors=len(known),unexpected_callback_errors=0,warnings=len(warnings),missing_script_warnings=len(missing),player_shader_fallbacks=proof['playerShaderFallbacks'],unresolved_builtin_meshes=proof['unresolvedBuiltinMeshes'],degraded_asset_compatibility=proof['degradedAssetCompatibility'],original_shader_compatibility_verified=False)
def screenshot(path,proof,rows,title=False):
    from PIL import Image
    path=Path(path);key='titleScreenshot' if title else 'screenshot'
    require(proof[key+'Validated'] is True and sha(path)==proof[key+'Sha256'],'Screenshot missing, changed or not validated')
    validations=[r['data'] for r in rows if r['kind']=='screenshot_validation' and r['data']['sha256']==sha(path)]
    require(len(validations)==1,'Screenshot validation record missing or duplicate');record=validations[0]
    with Image.open(path) as image:
        require(image.format=='PNG','Screenshot format is not PNG');rgb=image.convert('RGB');width,height=rgb.size;first=rgb.getpixel((0,height-1));pixels=list(rgb.getdata());nonblack=sum(p!=(0,0,0) for p in pixels);different=sum(p!=first for p in pixels)
    require(width*height>0 and nonblack>width*height//100 and different>width*height//200,'Screenshot is black or uniform')
    require(record['validated'] and record['cameraActive'] and record['cameraEnabled'] and record['afterReadyFrames']>=2,'Screenshot did not use an active ready camera')
    require((record['width'],record['height'],record['pixels'],record['nonBlackPixels'],record['differentFromFirstPixel'])==(width,height,width*height,nonblack,different),'Screenshot pixel statistics differ from independent PNG decoding')
    require(record['bytes']==path.stat().st_size and record['sha256']==sha(path),'Screenshot event fingerprint differs')
    return dict(path=str(path.resolve()),sha256=sha(path),width=width,height=height,nonblack_pixels=nonblack,different_pixels=different,title=title,pixel_fidelity_verified=False)
def player_log(path):
    path=Path(path)
    with (gzip.open(path,'rt',encoding='utf-8-sig',errors='replace') if path.suffix=='.gz' else path.open(encoding='utf-8-sig',errors='replace')) as f:lines=list(f)
    unsupported=[x.strip() for x in lines if 'ERROR: Shader' in x]
    return dict(path=str(path.resolve()),sha256=sha(path),raw_shader_error_lines=len(unsupported),raw_shader_errors=unsupported,scope='Raw shader compatibility messages are preserved separately from engine callback counts; a successful loop does not prove shader parity.')
def analyze(seed,first,second,saved,first_events,second_events):
    compatibility=[]
    for proof,rows,phase in [(first,first_events,'phase1'),(second,second_events,'phase2')]:
        require(proof['phase']==phase and proof['completed'] is True and proof['passed'] is True,'Player acceptance incomplete or failed: '+phase)
        require(rows and all(r['processGuid']==proof['processGuid'] for r in rows),'Runtime event process identity differs')
        require(not [r for r in rows if r['kind']=='loop_failure'],'Runtime recorded a loop failure')
        compatibility.append(callback_counts(proof,rows))
        require(one(rows,'acceptance_complete')['data']['passed'] is True and one(rows,'process_quit')['data']['passed'] is True,'Acceptance/quit event is not successful')
        require(proof['sceneKey']=='Apartment' and proof['originalGeometry'] and proof['originalPlayerVisual'] and proof['geometryMeshes']>0 and proof['geometryColliders']>0 and proof['visualRenderers']>0,'Original-resource minimum room/player not established')
        require(proof['copiedGameBehaviours']==0,'Original game behaviours entered independent loop')
    require(first['processGuid']!=second['processGuid'],'Fresh player process identity did not change')
    require(datetime.fromisoformat(second['startedUtc'].replace('Z','+00:00'))>datetime.fromisoformat(first['finishedUtc'].replace('Z','+00:00')),'Second player started before first acceptance finished')
    imported=one(first_events,'seed_imported')['data'];require(pose(imported,seed['position'],seed['rotation']) and imported['sourceSaveSha256']==seed['sourceSaveSha256'] and imported['revision']==0,'Title seed import differs from offline original projection')
    require(same(first['loadedPosition'],seed['position'],['x','y','z']) and same(first['loadedRotation'],seed['rotation'],['x','y','z','w']) and same(first['appliedPosition'],seed['position'],['x','y','z']) and quaternion_error(first['appliedRotation'],seed['rotation'])<=.001,'Original pose was not loaded and applied before initial physics')
    require(first['controlledInput'] and first['inputSamples']>5 and first['travelledDistance']>=.1 and first['groundedSeen'] and first['belowCollisions']>0,'Same-motor movement/collision not observed')
    movement=one(first_events,'movement_observed')['data'];stored=one(first_events,'save_completed')['data'];require(same(movement['end'],stored['position'],['x','y','z']),'Saved pose does not use actual post-movement transform')
    horizontal_delta=math.hypot(movement['end']['x']-movement['start']['x'],movement['end']['z']-movement['start']['z']);require(horizontal_delta>=.1,'Movement never changed the persisted horizontal position')
    require(saved['schemaVersion']==1 and saved['fileKind']=='ReconstructedManakaSave' and saved['sceneKey']=='Apartment' and saved['revision']>=1,'Independent save schema/kind differs')
    require(saved['savedProcessGuid']==first['processGuid']==second['loadedSavedProcessGuid'] and saved['revision']==stored['revision']==second['saveRevision'],'Saved revision/writer did not cross process boundary')
    require(saved['sourceSaveSha256']==seed['sourceSaveSha256'],'Original cipher provenance was lost')
    require(pose(stored,saved['position'],saved['rotation']) and same(first['savedPosition'],saved['position'],['x','y','z']) and same(first['savedRotation'],saved['rotation'],['x','y','z','w']),'Actual saved float32 pose differs from runtime proof')
    require(first['exactStoredPosition'] and first['exactStoredRotation'],'First player did not confirm JSON pose roundtrip')
    require(same(second['loadedPosition'],saved['position'],['x','y','z']) and same(second['loadedRotation'],saved['rotation'],['x','y','z','w']),'New player did not load saved float32 pose')
    loaded=one(second_events,'saved_state_read')['data'];require(pose(loaded,saved['position'],saved['rotation']),'New-player read event differs from persisted pose')
    applied=one(second_events,'readback_verified_before_physics')['data'];require(applied['previousProcess'] is True and applied['writerProcessGuid']==first['processGuid'] and applied['readerProcessGuid']==second['processGuid'],'Readback did not identify prior writer/new reader')
    position_error=math.sqrt(sum((runtime_float(second['appliedPosition'][k])-runtime_float(saved['position'][k]))**2 for k in ['x','y','z']));rotation_error=quaternion_error(second['appliedRotation'],saved['rotation']);require(position_error<=1e-5 and rotation_error<=.001,'Saved pose was not applied before physics within declared tolerance')
    require(second['exactAppliedPosition']==same(second['appliedPosition'],saved['position'],['x','y','z']) and second['exactAppliedRotation']==same(second['appliedRotation'],saved['rotation'],['x','y','z','w']),'Applied component-exact flags disagree with independently compared float32 values')
    inventory_ok=(saved['inventory']==seed['inventory']) if 'inventory' in seed else value_sha(saved['inventory'])==seed['inventory_sha256'];custom_ok=(saved['customization']==seed['customization']) if 'customization' in seed else value_sha(saved['customization'])==seed['customization_sha256']
    require(inventory_ok and custom_ok and bits(saved['bodyPaintRemaining'])==bits(seed['bodyPaintRemaining']) and saved['bodyPaintReusable'] is seed['bodyPaintReusable'],'Imported non-pose data was dropped or changed without a tested gameplay path')
    return dict(scope='Original-data offline import and bounded independent-room movement/save/restart; no original gameplay/animation/appearance equivalence claim',scene='Apartment',original_source_sha256=seed['sourceSaveSha256'],first_process_guid=first['processGuid'],second_process_guid=second['processGuid'],pid_reused=first['processId']==second['processId'],revision=saved['revision'],saved_position=saved['position'],saved_rotation=saved['rotation'],horizontal_net_movement=horizontal_delta,applied_position_error=position_error,applied_rotation_error_degrees=rotation_error,position_applied_bit_exact=second['exactAppliedPosition'],rotation_applied_bit_exact=second['exactAppliedRotation'],inventory_entries_preserved=len(saved['inventory']),selected_custom_preserved=True,paint_data_preserved=True,controlled_input=True,hardware_keyboard_tested=False,resource_scene_fidelity_unverified=True,compatibility=compatibility)
def build(phase1=None,phase2=None,save=None,source_manifest=None,inputs=False):
    config={}
    if phase1 is None:
        config=read(HERE/'acceptance-inputs.json');phase1=config['phase1'];phase2=config['phase2'];save=config['save'];source_manifest=config['source_manifest']
    phase1,phase2,save=map(local,[phase1,phase2,save]);source_manifest=local(source_manifest or HERE/'seed-manifest.json');manifest=read(source_manifest);seed=manifest['selected_summary']
    if inputs:
        seed,detail=project(manifest['source']['source_path'],manifest['source']['source_sha256']);require(sha(manifest['seed']['path'])==manifest['seed']['sha256'],'Prepared seed changed')
    first,second,saved=read(phase1),read(phase2),read(save);first_events_path=local(config.get('phase1_events',first['eventPath']));second_events_path=local(config.get('phase2_events',second['eventPath']));first_events=events(first_events_path);second_events=events(second_events_path);result=analyze(seed,first,second,saved,first_events,second_events)
    require(sha(save)==first['saveSha256']==second['saveSha256'],'Both processes did not read the same own-save bytes')
    lifecycle=[];screenshots=[];logs=[];paths=[phase1,phase2,first_events_path,second_events_path,save,source_manifest]
    for name,path,proof,rows in [('phase1',phase1,first,first_events),('phase2',phase2,second,second_events)]:
        start_path=local(config.get(name+'_start',path.parent/'process-start.json'));exit_path=local(config.get(name+'_exit',path.parent/'process-exit.json'));started,exited=read(start_path),read(exit_path);require(exited['process_exited'] is True and exited['exit_code']==0 and exited['pid']==started['pid']==proof['processId'],'Independent player OS process did not exit cleanly')
        require(started['phase']==name and '-batchmode' not in started['arguments'],'Formal visual acceptance must use the visible player, not the black batch-mode diagnostic')
        require(Path(started['profile_root']).resolve()==Path(proof['profileRoot']).resolve() and Path(proof['savePath']).resolve().parent==Path(proof['profileRoot']).resolve(),'Runtime used a different independent save profile');paths.extend([start_path,exit_path]);lifecycle.append(dict(pid=exited['pid'],process_exited=True,exit_code=0,executable=started['executable'],executable_sha256=started['executable_sha256']))
        for title in [True,False]:
            image_path=local(config.get(name+('_title_screenshot' if title else '_screenshot'),proof['titleScreenshotPath' if title else 'screenshotPath']));screenshots.append(screenshot(image_path,proof,rows,title));paths.append(image_path)
        log_path=local(config.get(name+'_player_log',path.parent/'player.log'));logs.append(player_log(log_path));paths.append(log_path)
        if inputs:require(sha(started['executable'])==started['executable_sha256'],'Player executable fingerprint differs')
    require(lifecycle[0]['executable_sha256']==lifecycle[1]['executable_sha256'],'Readback used a different player binary')
    if inputs:
        for entry in manifest['sources']:require(sha(entry['path'])==entry['sha256'],'Save bridge preparation source changed')
    require(all(item['degraded_asset_compatibility'] for item in result['compatibility']),'This bounded fallback acceptance must not be represented as original asset fidelity')
    result.update(save_path=str(save.resolve()),save_sha256=sha(save),lifecycle=lifecycle,screenshots=screenshots,player_logs=logs,inputs=[dict(path=str(x.resolve()),sha256=sha(x)) for x in paths])
    return result
def main():
    p=argparse.ArgumentParser();p.add_argument('--phase1',type=Path);p.add_argument('--phase2',type=Path);p.add_argument('--save',type=Path);p.add_argument('--source-manifest',type=Path,default=HERE/'seed-manifest.json');p.add_argument('--output',type=Path,default=HERE/'acceptance.json');p.add_argument('--check',action='store_true');p.add_argument('--inputs',action='store_true');a=p.parse_args()
    if any(x is not None for x in [a.phase1,a.phase2,a.save]):
        if not all(x is not None for x in [a.phase1,a.phase2,a.save]):p.error('phase1,phase2,save are provided together')
        protected=[a.phase1,a.phase2,a.save,a.source_manifest];require(not any(a.output.resolve()==x.resolve() for x in protected),'Acceptance output must not replace its inputs')
        config=dict(phase1=str(a.phase1.resolve()),phase2=str(a.phase2.resolve()),save=str(a.save.resolve()),source_manifest=str(a.source_manifest.resolve()));(HERE/'acceptance-inputs.json').write_bytes((json.dumps(config,indent=2)+'\n').encode('utf8'))
    result=build(a.phase1,a.phase2,a.save,a.source_manifest,inputs=a.inputs)
    if a.check:require(result==read(a.output),'Saved acceptance result differs')
    else:a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_bytes((json.dumps(result,ensure_ascii=False,indent=2)+'\n').encode('utf8'))
    print(json.dumps(dict(scene=result['scene'],revision=result['revision'],saved_position=result['saved_position'],position_error=result['applied_position_error'],inventory_entries=result['inventory_entries_preserved']),ensure_ascii=False))
if __name__=='__main__':main()
