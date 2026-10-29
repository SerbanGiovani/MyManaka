"""Verify native appearance reference/disturb/load/application and nonunit bones."""
import argparse,gzip,hashlib,json,math,struct,sys
from pathlib import Path
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parents[1]/'salt'))
import save_codec
FIELDS=['CustomIsSkinColorFree','CustomizeSkinColorR','CustomizeSkinColorG','CustomizeSkinColorB','CustomizeEyeBlowColorR','CustomizeEyeBlowColorG','CustomizeEyeBlowColorB','CustomizeEyeLashColorR','CustomizeEyeLashColorG','CustomizeEyeLashColorB','CustomizeEyeSize','CustomizeEyeDist','CustomizeCheekFat','CustomizeEarElf','CustomizeArm','CustomizeShoulder','CustomizeNeckThick']
def read(p):return json.loads(Path(p).read_text(encoding='utf-8-sig'))
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def rows(p):return [json.loads(l) for l in gzip.decompress(Path(p).read_bytes()).decode('utf8').splitlines()]
def require(v,m):
    if not v:raise ValueError(m)
def f32(v):return struct.unpack('<f',struct.pack('<f',v))[0]
def near(a,b):return math.isfinite(a) and math.isfinite(b) and abs(a-b)<=max(3e-7,abs(b)*3e-7)
def vector(a,b):return len(a)==len(b) and all(near(x,y) for x,y in zip(a,b))
def ptr(p):return int(p,16) if str(p).startswith('0x') else int(p)
def one(items,kind):
    values=[r for r in items if r['kind']==kind];require(len(values)==1,'Missing/duplicate '+kind);return values[0]
def projection(path):
    data=Path(path).read_bytes();_,root,_=save_codec.read(data,'unReRU821Drq83');custom=root.strings()['PlayerCustomData'].strings()['value'].strings()
    return dict(path=str(path),sha256=sha(path),bytes=len(data),custom_fields=len(custom),fields={k:custom[k] for k in FIELDS})

def analyze(managed,events,files):
    require(not [r for r in managed if r['kind']=='runner_error'],'Fixture failed')
    require(not [e for e in events if e['kind']=='engine_error'],'Native engine error')
    prepared=one(managed,'prepared')['data'];results=[]
    shape_ids=read(HERE/'shape-indices.json')['indices']
    for name in ['profile-a','profile-b','nonunit-bones']:
        selected=[r for r in managed if isinstance(r.get('data'),dict) and r['data'].get('name')==name]
        get=lambda kind:one(selected,kind)
        begin=get('case_begin');ref=get('reference_immediate')['data']['snapshot'];reference=get('reference_result')['data']['snapshot'];disturbed=get('disturbed_immediate')['data']['snapshot'];dist=get('disturbed_result')['data']['snapshot'];loaded=get('loaded')['data']['snapshot'];restored=get('restore_immediate')['data']['snapshot'];end=get('result')['data']['snapshot']
        file=next(f for f in files if Path(f['path']).stem==name)
        require(file['custom_fields']==66 and file['fields']==begin['data']['fields']==ref['fields']==get('saved')['data']['fields']==loaded['fields']==restored['fields']==end['fields'],'Saved/loaded appearance fields differ')
        require(disturbed['fields']!=ref['fields'],'No actual field disturbance')
        require(loaded['custom']!=ref['custom'],'No newly loaded custom object')
        for stage,immediate in [('reference','reference_immediate'),('disturb','disturbed_immediate'),('restore','restore_immediate')]:
            native=[e for e in events if e['data'].get('name')==name+'/'+stage]
            for kind in ['marker_begin','marker_end','player_initialize_callback','broadcast','body_change','material_change','face_change']:one(native,kind)
            changes=[e for e in native if e['kind']=='bone_change'];deferred=[e for e in native if e['kind']=='bone_next_frame']
            require(len(changes)==len(deferred)==12,'Bone receiver/callback count differs')
            expected={ptr(b['pointer']) for b in end['bones']}
            require(expected=={ptr(e['data']['pointer']) for e in changes}=={ptr(e['data']['pointer']) for e in deferred},'Bone pointer identity differs')
            offset=1 if stage=='reference' else 2
            require(all(e['frame']==get(immediate)['frame']+offset for e in deferred),'Bone callback phase offset differs')
            hair=[e for e in native if e['kind']=='hair_change'];require(len(hair)==2,'Initialized hair receive count differs')
            require(sum(e['kind']=='native_save' for e in native)==(1 if stage=='reference' else 0) and sum(e['kind']=='native_load' for e in native)==(1 if stage=='restore' else 0),'Native Save/Load phase differs')
        expected_names=['bodyMaterial','faceMaterial','eyeBlowMaterial','eyeLashMaterial']
        require([m['name'] for m in ref['materials']]==expected_names,'Material receiver set differs')
        mat_max=0
        for i,(a,b,c,d) in enumerate(zip(ref['materials'],restored['materials'],disturbed['materials'],loaded['materials'])):
            require(a['name']==b['name']==c['name']==d['name'],'Material identity label differs')
            require(vector(a['color'],b['color']) and vector(a['shade'],b['shade']),'Restored material color/shade differs')
            require(vector(c['color'],d['color']),'Load applied material before dispatch')
            require(not vector(a['color'],c['color']),'Material never disturbed')
            prefix=['CustomizeSkinColor','CustomizeSkinColor','CustomizeEyeBlowColor','CustomizeEyeLashColor'][i]
            expected_color=[f32(f32(file['fields'][prefix+k])/f32(255)) for k in 'RGB']+[1]
            require(vector(b['color'],expected_color),'Stored RGB to material result differs')
            mat_max=max(mat_max,max(abs(x-y) for x,y in zip(b['color'],expected_color)))
        require([x['index'] for x in ref['shapes']]==shape_ids and len(shape_ids)==40,'Selected face channels differ')
        require(all(a['index']==b['index'] and near(a['value'],b['value']) for a,b in zip(ref['shapes'],restored['shapes'])),'Restored face weights differ')
        require(all(a['index']==b['index'] and near(a['value'],b['value']) for a,b in zip(disturbed['shapes'],loaded['shapes'])),'Load applied face before dispatch')
        changed=[a['index'] for a,b in zip(ref['shapes'],disturbed['shapes']) if not near(a['value'],b['value'])]
        require(changed,'No actual face disturbance')
        bone_error=0;nonunit=0
        for b in end['bones']:
            require(all(abs(t)>1e-6 for t in b['targetScale']),'Invalid inverse-scale fixture')
            expected=[f32(f32(1)/f32(t)) for t in b['targetScale']]
            require(vector(b['scale'],expected),'Nonunit bone inverse scale differs')
            bone_error=max(bone_error,max(abs(x-y) for x,y in zip(b['scale'],expected)))
            nonunit+=not vector(b['targetScale'],[1,1,1])
        require(nonunit>=5,'Nonunit branch not reached')
        if name=='nonunit-bones':
            require(nonunit==12 and all(vector(b['targetScale'],[1.25,.8,1.5]) for b in end['bones']),'Synthetic twelve-target fixture differs')
        results.append(dict(name=name,fields=17,file_sha256=file['sha256'],material_pairs=4,face_channels=40,changed_face_channels=changed,nonunit_bone_targets=nonunit,material_rgb_max_error=mat_max,bone_inverse_max_error=bone_error,reference_dispatch_phase='Update',reference_callback_offset=1,restore_dispatch_phase='LateUpdate',restore_frame=get('restore_immediate')['frame'],bone_callback_frame=get('restore_immediate')['frame']+2,restore_callback_offset=2))
    cleanup=one(managed,'cleanup')['data'];require(cleanup['rootsRestored'] and cleanup['fieldsRestored'] and cleanup['stop'] is False,'Cleanup flags differ')
    require(cleanup['snapshot']['fields']==prepared['fields'],'Original custom fields not restored')
    for a,b in zip(prepared['materials'],cleanup['snapshot']['materials']):require(vector(a['color'],b['color']) and vector(a['shade'],b['shade']),'Original material not restored')
    for a,b in zip(prepared['bones'],cleanup['snapshot']['bones']):require(vector(a['targetScale'],b['targetScale']) and vector(a['scale'],b['scale']),'Original bone target not restored')
    return dict(authority='controlled-native-save-load-and-initialize-callback',natural_only=False,selected_custom_fields=FIELDS,cases=results,native_messages=len(events),engine_error_events=0,
        all_custom_fields_visual_equivalence=False,limitations=['17 of66 custom fields are deliberately changed; field persistence is checked independently, not all appearance features.','Four material slots and40 face channels are compared to original native application before disturbance.','Unchanged face channels are covered for roundtrip consistency, not claimed as independent parameter-response tests.','The twelve-target case explicitly assigns nonunit Transform scales after dispatch; these scales are not claimed to be stored fields.','Callback phase offsets are measured for this fixture; frame-internal Scheduler position is an inference, not a new instrumented fact.','Original initialization callback is deliberately invoked after Load; natural UI dispatch, hair customization/paint/textures and collision results remain outside this batch.'])

def build(inputs=False):
    bundle=read(HERE/'rea-runtime.json');status=next(r['normalized_result'] for r in bundle['records'] if r['operation']=='frida_session_status')
    require(status['pid']==69516 and not status['messages_truncated'] and all(m['type']=='send' for m in status['messages']),'Native capture incomplete')
    files=read(HERE/'saved-files.json')['files'];result=analyze(rows(HERE/'managed.jsonl.gz'),[m['payload'] for m in status['messages']],files)
    post=read(HERE/'post-state.json');require(post['plugins_restored'] and post['frida_closed'] and post['process']['wait_for_exit_returned'] and post['process']['process_absent'],'Process/plugin cleanup failed')
    require(all(p['unchanged'] for k in ['profile','preserved_test_profile','inputs'] for p in post[k]),'Protected files changed')
    if inputs:
        require(all(projection(f['path'])==f for f in files),'Encrypted appearance snapshot differs')
        for k in ['profile','preserved_test_profile']:
            for p in post[k]:require(sha(p['path'])==p['before']==p['after'],'Protected save differs')
        for p in post['inputs']:require(sha(p['path'])==sha(p['original_path'])==p['sha256'],'Engine/asset input differs')
    return result

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');p.add_argument('--inputs',action='store_true');a=p.parse_args();r=build(a.inputs)
    if a.check:require(r==read(HERE/'results.json'),'Results differ')
    else:(HERE/'results.json').write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(r,ensure_ascii=False,indent=2))
