"""Verify hair data, real materials and the default-hair warm-init boundary."""
import argparse,colorsys,gzip,hashlib,json,math,struct,sys
from pathlib import Path
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parents[1]/'salt'))
import save_codec
def read(p):return json.loads(Path(p).read_text(encoding='utf-8-sig'))
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def rows(p):return [json.loads(l) for l in gzip.decompress(Path(p).read_bytes()).decode('utf8').splitlines()]
def require(v,m):
    if not v:raise ValueError(m)
def f32(v):return struct.unpack('<f',struct.pack('<f',v))[0]
def near(a,b):return math.isfinite(a) and math.isfinite(b) and abs(a-b)<=2e-6
def vector(a,b):return len(a)==len(b) and all(near(x,y) for x,y in zip(a,b))
def one(items,kind):
    r=[r for r in items if r['kind']==kind];require(len(r)==1,'Missing/duplicate '+kind);return r[0]
def active(s):return [o['id'] for o in s['objects'] if o['active']]
def logical(s):return [{k:v for k,v in d.items() if k!='pointer'} for d in s['data']]
def projection(path,ids):
    data=Path(path).read_bytes();_,root,_=save_codec.read(data,'unReRU821Drq83');c=root.strings()['PlayerCustomData'].strings()['value'].strings();d=c['HairCustomizeDataDict'].entries
    records=[]
    for key,value in d:
        if key not in ids:continue
        r=value.strings();records.append(dict(hair=r['HairType'],texture=r['TextureId'],rgb=[r[k] for k in ['R','G','B']],shade=r['ShadeColor']))
    return dict(path=str(path),sha256=sha(path),bytes=len(data),current=c['CurrentHair'],dict_count=len(d),data=sorted(records,key=lambda r:ids.index(r['hair'])))
def expected_colors(data):
    rgb=[f32(f32(x)/f32(255)) for x in data['rgb']]
    h,s,v=colorsys.rgb_to_hsv(*rgb);s=min(1,s+min(s,.1));v=min(1,max(0,v*.9))
    base=colorsys.hsv_to_rgb(h,s,v);target=colorsys.hsv_to_rgb(0 if data['shade']<0 else struct.unpack('<f',bytes.fromhex('a1a0203f'))[0],1,v)
    factor=min(1,abs(data['shade'])/100);shade=[a+(b-a)*factor for a,b in zip(base,target)]
    return rgb+[1],shade+[1]
def analyze(managed,events,files):
    require(not [r for r in managed if r['kind']=='runner_error'],'Hair fixture failed')
    require(not [e for e in events if e['kind']=='engine_error'],'Native engine error')
    prepared=one(managed,'prepared')['data'];results=[]
    for name in ['negative-shade','positive-shade','alternate-hair']:
        selected=[r for r in managed if isinstance(r.get('data'),dict) and r['data'].get('name')==name]
        get=lambda kind:one(selected,kind)
        ref=get('reference_result')['data']['snapshot'];dist=get('disturbed_result')['data']['snapshot'];loaded=get('loaded')['data']['snapshot'];warm=get('warm_result')['data']['snapshot'];end=get('result')['data']['snapshot'];rec=get('reconciliation')['data'];file=next(f for f in files if Path(f['path']).stem==name)
        require(file['dict_count']==21 and file['current']==ref['current']==loaded['current']==warm['current']==end['current'],'Saved current hair differs')
        require(file['data']==logical(ref)==logical(loaded)==logical(end),'Hair dictionary restore differs')
        require(ref['custom']!=loaded['custom'],'Custom object not reloaded')
        require(active(ref)==[ref['current']] and active(dist)==[dist['current']] and dist['current']!=ref['current'],'No genuine model disturbance')
        require(active(loaded)==active(dist),'Load silently applied model before consumer')
        native=lambda stage:[e for e in events if e['data'].get('name')==name+'/'+stage]
        for stage in ['reference','disturb','warm','reconciled']:
            n=native(stage);one(n,'marker_begin');one(n,'marker_end');one(n,'player_initialize_callback')
            require(any(e['kind']=='hair_change' for e in n),'No hair material consumer')
            require(sum(e['kind']=='native_save' for e in n)==(1 if stage=='reference' else 0) and sum(e['kind']=='native_load' for e in n)==(1 if stage=='warm' else 0),'Hair native Save/Load phase differs')
        one(native('warm'),'hair_controller_initialize')
        changes=[e for e in native('warm') if e['kind']=='hair_controller_change']
        if file['current']==0:
            require(not changes and active(warm)==active(dist) and active(warm)!=[0],'Default warm-init mismatch was masked')
            warm_matches=False
        else:
            require(len(changes)==1 and active(warm)==[file['current']],'Nondefault initialization differs');warm_matches=True
        require(rec['desired']==file['current'] and active(warm)==[rec['actual']],'Explicit reconciliation source differs')
        one(native('reconciled'),'hair_controller_change')
        require(active(end)==[file['current']],'Reconciled model missing/duplicate')
        data=next(d for d in file['data'] if d['hair']==file['current']);expected_rgb,expected_shade=expected_colors(data)
        materials=[h for h in end['receivers'] if h['hair']==file['current'] and h['initialized']]
        reference=[h for h in ref['receivers'] if h['hair']==file['current'] and h['initialized']]
        require(len(materials)==len(reference)==2,'Expected two current-hair materials')
        max_rgb=max_shade=0
        for h in materials:
            require(vector(h['color'],expected_rgb),'Hair RGB material differs')
            require(vector(h['shade'],expected_shade),'Hair HSV shade differs')
            require(0<=data['texture']<len(h['available']) and h['texture']==h['available'][data['texture']],'Actual texture reference differs')
            require(any(vector(h['color'],r['color']) and vector(h['shade'],r['shade']) and h['texture']==r['texture'] for r in reference),'Reference material not restored')
            max_rgb=max(max_rgb,max(abs(a-b) for a,b in zip(h['color'],expected_rgb)));max_shade=max(max_shade,max(abs(a-b) for a,b in zip(h['shade'],expected_shade)))
        results.append(dict(name=name,saved_hair=file['current'],file_sha256=file['sha256'],texture_id=data['texture'],rgb=data['rgb'],shade=data['shade'],warm_active=active(warm),warm_model_matches=warm_matches,reconciled_active=active(end),materials=2,rgb_max_error=max_rgb,shade_max_error=max_shade,restore_frame=get('restore_immediate')['frame'],result_frame=get('result')['frame'],material_calls=len([e for e in native('reconciled') if e['kind']=='hair_change'])))
    cleanup=one(managed,'cleanup')['data'];require(cleanup['rootsRestored'] and cleanup['stop'] is False,'Cleanup flags differ')
    after=cleanup['snapshot'];require(after['current']==prepared['current'] and logical(after)==logical(prepared) and active(after)==active(prepared),'Original hair graph/data not restored')
    before=[h for h in prepared['receivers'] if h['initialized'] and h['hair']==prepared['current']]
    after_m=[h for h in after['receivers'] if h['initialized'] and h['hair']==after['current']]
    require(len(after_m)==len(before)==2 and all(any(vector(h['color'],b['color']) and vector(h['shade'],b['shade']) and h['texture']==b['texture'] for b in before) for h in after_m),'Original hair material not restored')
    return dict(authority='controlled-native-save-load-hair-consumers',natural_only=False,cases=results,native_messages=len(events),engine_error_events=0,
        default_cold_initialization_assumption_verified_statically=True,natural_title_defect_claimed=False,
        limits=['Selected hair types0/1 and two initialized materials each; other hair models/add-ons are not covered.','Warm default-hair reinitialization fails to switch the model in two controlled cases; it is not presented as a successful native-only restoration.','The final positive model result includes explicit saved-current coordination to the actual active object before original ChangeHair.','Native cold-title/player recreation is not replayed in this batch; no natural title-load defect is claimed.','OnEnable deferred work and explicit original broadcast can both reapply materials; repeated consumer entry is not by itself duplicate event dispatch.'])
def build(inputs=False):
    bundle=read(HERE/'rea-runtime.json');n=next(r['normalized_result'] for r in bundle['records'] if r['operation']=='frida_session_status')
    require(n['pid']==48184 and not n['messages_truncated'] and all(m['type']=='send' for m in n['messages']),'Native capture incomplete')
    files=read(HERE/'saved-files.json')['files'];result=analyze(rows(HERE/'managed.jsonl.gz'),[m['payload'] for m in n['messages']],files)
    engine=gzip.decompress((HERE/'engine.log.gz').read_bytes()).decode('utf8',errors='replace')
    require(not any('[Error' in line or '[Fatal' in line for line in engine.splitlines()),'Engine log error')
    post=read(HERE/'post-state.json');require(post['plugins_restored'] and post['frida_closed'] and post['process']['wait_for_exit_returned'] and post['process']['process_absent'],'Process/plugin cleanup failed')
    require(all(p['unchanged'] for k in ['profile','preserved_test_profile','inputs'] for p in post[k]),'Protected files changed')
    if inputs:
        ids=[d['hair'] for d in files[0]['data']];require(all(projection(f['path'],ids)==f for f in files),'Encrypted hair projection differs')
        for k in ['profile','preserved_test_profile']:
            for p in post[k]:require(sha(p['path'])==p['before']==p['after'],'Protected save differs')
        for p in post['inputs']:require(sha(p['path'])==sha(p['original_path'])==p['sha256'],'Engine/asset input differs')
    return result
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');p.add_argument('--inputs',action='store_true');a=p.parse_args();r=build(a.inputs)
    if a.check:require(r==read(HERE/'results.json'),'Result differs')
    else:(HERE/'results.json').write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(r,ensure_ascii=False,indent=2))
