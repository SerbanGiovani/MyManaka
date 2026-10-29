"""Verify the saved-height/native-dispatch/actual-scale and deferred callback joins."""
import argparse,gzip,hashlib,json,math,struct,sys
from pathlib import Path
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parents[1]/'salt'))
import save_codec
def read(p):return json.loads(Path(p).read_text(encoding='utf-8-sig'))
def rows(p):return [json.loads(l) for l in gzip.decompress(Path(p).read_bytes()).decode('utf8').splitlines()]
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def require(v,m):
    if not v:raise ValueError(m)
def f32(v):return struct.unpack('<f',struct.pack('<f',v))[0]
def near(a,b):return abs(a-b)<=max(2e-7,abs(b)*2e-7)
def one(rows,kind):
    found=[r for r in rows if r['kind']==kind];require(len(found)==1,'Missing/duplicate '+kind);return found[0]
def projection(path):
    raw=Path(path).read_bytes();plain,root,_=save_codec.read(raw,'unReRU821Drq83');wrapped=root.strings();custom=wrapped['PlayerCustomData'].strings()['value'].strings()
    return dict(path=str(path),sha256=sha(path),bytes=len(raw),plaintext_sha256=hashlib.sha256(plain).hexdigest(),height=custom['CustomizeHeight'],custom_fields=len(custom))
def analyze(managed,events,files):
    require(not [r for r in managed if r['kind']=='runner_error'],'Fixture failed');require(not [e for e in events if e['kind']=='engine_error'],'Unexpected engine error')
    prepared=one(managed,'prepared');results=[]
    for height in [120,160,200]:
        name='height-'+str(height);records=[r for r in managed if isinstance(r.get('data'),dict) and r['data'].get('name')==name];native=[e for e in events if e['data'].get('name')==name]
        begin=one(records,'case_begin');saved=one(records,'saved');disturbed=one(records,'disturbed');loaded=one(records,'loaded');dispatch=one(records,'dispatch');immediate=one(records,'immediate');result=one(records,'result')
        file=next(f for f in files if f['height']==height);require(file['custom_fields']==66 and saved['data']['height']==height and disturbed['data']['height']==137 and loaded['data']['snapshot']['height']==height,'Saved/disturbed/loaded height mismatch')
        require(dispatch['data']['method'].endswith('Initialize_b__30_0') and saved['frame']==loaded['frame']==dispatch['frame']==immediate['frame'],'Not selected original initialization callback')
        for kind in ['marker_begin','native_save','native_load','player_initialize_callback','broadcast','face_change','material_change','body_change','marker_end']:one(native,kind)
        body=one(native,'body_change');require(int(body['data']['pointer'],16)==int(result['data']['snapshot']['body']),'Actual body object differs')
        require(loaded['data']['snapshot']['heightScale']==begin['data']['snapshot']['heightScale'],'Load unexpectedly applied visual scale before dispatch')
        scale=f32(height/160);factor=f32(.6 if scale<=1 else .8);speed=f32(1/f32(f32(f32(scale-1)*factor)+1))
        for label,snap in [('immediate',immediate['data']['snapshot']),('result',result['data']['snapshot'])]:
            require(near(snap['heightScale'],scale),'Height scale differs');expected=f32(f32(snap['defaultBaseScale'])*scale);require(all(near(x,expected) for x in snap['avatarScale']),'Actual avatar Transform scale differs')
            require(near(snap['moveSpeed'],speed) and near(snap['animationMoveSpeed'],speed),'Movement speed copy differs')
        snapshot=result['data']['snapshot'];bones=snapshot['bones'];bone_events=[e for e in native if e['kind']=='bone_change'];deferred=[e for e in native if e['kind']=='bone_next_frame'];require(len(bones)==len(bone_events)==len(deferred)==12,'Bone receiver/callback count differs')
        ptr=lambda v:int(v,16) if str(v).startswith('0x') else int(v)
        require({ptr(b['pointer']) for b in bones}=={ptr(e['data']['pointer']) for e in bone_events}=={ptr(e['data']['pointer']) for e in deferred},'Bone callback receiver join differs')
        require(all(e['frame']==dispatch['frame']+1 for e in deferred),'Bone work did not run on next frame')
        for b in bones:require(all(near(v,f32(1/t)) for v,t in zip(b['scale'],b['targetScale'])),'Bone inverse scale differs')
        initialized=[h for h in snapshot['hair'] if h['initialized']];hair=[e for e in native if e['kind']=='hair_change'];require(len(initialized)==len(hair)==2 and {ptr(h['pointer']) for h in initialized}=={ptr(e['data']['pointer']) for e in hair},'Initialized hair receiver join differs')
        results.append(dict(height=height,saved_file_sha256=file['sha256'],save_frame=saved['frame'],dispatch_frame=dispatch['frame'],bone_callback_frame=deferred[0]['frame'],height_scale=scale,actual_avatar_scale=snapshot['avatarScale'],move_speed=snapshot['moveSpeed'],animation_move_speed=snapshot['animationMoveSpeed'],bone_receivers=12,next_frame_callbacks=12,initialized_hair_receivers=2,total_hair_components=len(snapshot['hair']),nonunit_bone_targets=sum(any(not near(t,1) for t in b['targetScale']) for b in bones)))
    cleanup=one(managed,'cleanup');require(cleanup['data']['rootsRestored'] and cleanup['data']['stop'] is False,'Cleanup failed');before=prepared['data'];after=cleanup['data']['snapshot'];require(before['height']==after['height']==160 and before['avatarScale']==after['avatarScale'] and near(before['moveSpeed'],after['moveSpeed']),'Original appearance not restored')
    return dict(authority='controlled-original-save-load-initialize-callback',cases=results,cleanup_original_height=160,cleanup_next_frame_callbacks=sum(e['kind']=='bone_next_frame' and e['data'].get('name')=='cleanup' for e in events),native_messages=len(events),natural_only=False,engine_error_events=0,all_custom_fields_visual_equivalence=False,limitations=['Only CustomizeHeight changed; colors, textures, face weights and other custom fields are not equivalence-tested.','All selected bone targets had unit local scale; the nonunit inverse-scale branch remains untested.','Original callback is deliberately invoked after Load; natural UI dispatch is not claimed.','Only two initialized hair receivers, out of22 components, are expected to receive this event.'])
def build(inputs=False):
    bundle=read(HERE/'rea-runtime.json');status=next(r['normalized_result'] for r in bundle['records'] if r['operation']=='frida_session_status');require(status['pid']==74792 and not status['messages_truncated'] and all(m['type']=='send' for m in status['messages']),'Native capture incomplete');files=read(HERE/'saved-files.json')['files'];result=analyze(rows(HERE/'managed.jsonl.gz'),[m['payload'] for m in status['messages']],files)
    post=read(HERE/'post-state.json');require(post['plugins_restored'] and post['frida_closed'] and post['process']['wait_for_exit_returned'] and post['process']['process_absent'],'Process/plugin cleanup failed');require(all(x['unchanged'] for k in ['profile','preserved_test_profile','inputs'] for x in post[k]),'Protected input changed')
    if inputs:
        require(all(projection(f['path'])==f for f in files),'Encrypted height projection differs')
        for k in ['profile','preserved_test_profile']:
            for p in post[k]:require(sha(p['path'])==p['before']==p['after'],'Protected save changed')
        for p in post['inputs']:require(sha(p['path'])==sha(p['original_path'])==p['sha256'],'Protected engine/asset changed')
    return result
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');p.add_argument('--inputs',action='store_true');a=p.parse_args();result=build(a.inputs)
    if a.check:require(result==read(HERE/'results.json'),'Result differs')
    else:(HERE/'results.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(result,ensure_ascii=False,indent=2))
