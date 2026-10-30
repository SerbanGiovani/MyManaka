"""Derive locomotion evidence from retained evidence and read-only shipped models.

Does not execute a game, Unity editor, GameAssembly, or original scripts.
"""
import sys
sys.dont_write_bytecode = True
import argparse
import hashlib
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT / 'assets'))
sys.path.insert(0, str(HERE.parent / 'asset-bridge'))
from inspect_player import models_investigation
from inspect_resources import Reader
from inspect_npc_animation import parse_clip
from bridge_assets import SchemaReader

def digest(path):
    return {'path':str(path), 'sha256':hashlib.sha256(path.read_bytes()).hexdigest()}

def build():
    source = ROOT / 'assets/animator-wiring.json'
    saved = json.loads(source.read_text(encoding='utf8'))
    controller = next(c for c in saved['controllers'] if c['name'] == 'Player')
    value = controller['decoded']['value']
    models_path = ROOT / 'salt/.cache/decrypted/models.unity3d'
    assert hashlib.sha256(models_path.read_bytes()).hexdigest() == '98621b2c4fa4f9de80f355fae5776ab17efc016bcc81c581bcd0917af4308367'
    inv = models_investigation(models_path)
    node = next(n for n in inv.nodes if not n.endswith(('.resS','.resource')))
    schema = SchemaReader(inv)
    def parse(pid):
        obj = inv.object(node,pid)
        return obj, schema.parse(inv,node,obj)
    def go(pid): return inv.gameobject(node,inv.object(node,pid))
    transforms = {}
    def transform(pid):
        if pid not in transforms:
            transforms[pid] = parse(pid)
        return transforms[pid]
    def gameobject_transform(g):
        for ptr in g['components']:
            obj = inv.object(node,ptr['path_id'])
            if obj['class_id'] == 4: return obj['path_id']
        raise AssertionError(g['name'])
    player_root = -8406032082528140171
    root_go = go(player_root)
    root_transform = gameobject_transform(root_go)
    descendants = {}
    def walk(pid,path):
        obj,t = transform(pid)
        g = go(t['m_GameObject']['m_PathID'])
        full = path + [g['name']]
        descendants[g['source']['object']['path_id']] = {'hierarchy_path':'/'.join(full),'transform_path_id':pid,'local_position':t['m_LocalPosition'],'local_rotation':t['m_LocalRotation'],'local_scale':t['m_LocalScale'],'active_self':g['active_self_serialized']}
        for child in t['m_Children']: walk(child['m_PathID'],full)
    # Follow six candidate ancestors instead of traversing thousands of unrelated
    # clothing/bone descendants. Ancestry, not name equality, binds this prefab.
    animators=[]
    for a in saved['player_animators']:
        g=a['gameobject'];gid=g['source']['object']['path_id'];pid=gameobject_transform(g)
        chain=[];cur=pid;seen=set();inside=False
        while cur and cur not in seen:
            seen.add(cur);obj,t=transform(cur);parent_go=go(t['m_GameObject']['m_PathID']);chain.append(parent_go['name']);inside = inside or cur == root_transform;cur=t['m_Father']['m_PathID']
        if inside:
            _,t=transform(pid)
            descendants[gid]={'hierarchy_path':'/'.join(reversed(chain)),'transform_path_id':pid,'local_position':t['m_LocalPosition'],'local_rotation':t['m_LocalRotation'],'local_scale':t['m_LocalScale'],'active_self':g['active_self_serialized']}
        v=a['decoded']['value'];av=v['m_Avatar'];avatar=None
        if av['m_PathID']:
            avobj=inv.object(node,av['m_PathID']);raw=inv.raw(node,avobj)
            avatar={'source':inv.identity(node,avobj),'name':Reader(raw).aligned_string()}
        animators.append({'source':a['source'],'gameobject_path_id':gid,'name':g['name'],'hierarchy_path':'/'.join(reversed(chain)),'within_player_prefab':gid in descendants,'hierarchy':descendants.get(gid),'decoded':v,'avatar':avatar,'same_gameobject_script_classes':[s['script_identity']['fields'] for s in a['same_gameobject_scripts']]})
    param_defaults=[]
    defaults=value['m_Controller']['m_DefaultValues']
    for p in controller['graph']['parameters']:
        arr={1:'m_FloatValues',3:'m_IntValues',4:'m_BoolValues',9:'m_BoolValues'}[p['m_Type']]
        param_defaults.append({**p,'serialized_default':defaults[arr][p['m_Index']]})
    tos={x['first']:x['second'] for x in value['m_TOS']}
    machines=[]
    for i,sm in enumerate(value['m_Controller']['m_StateMachineArray']):
        states=[]
        for j,s in enumerate(sm['m_StateConstantArray']):
            states.append({'index':j,'name':tos.get(s['m_NameID']),'path':tos.get(s['m_FullPathID']),'full_path_hash_unsigned':s['m_FullPathID'],'raw':s})
        machines.append({'index':i,'default_state_index':sm['m_DefaultState'],'states':states,'graph':controller['graph']['machines'][i]})
    result = {'schema_version':1,'authority':'shipped-artifact-derived','source_evidence':digest(source),'models':digest(models_path),'controller':{'name':controller['name'],'source':controller['source'],'serialized_object_sha256':hashlib.sha256(inv.raw(node,inv.object(node,controller['source']['object']['path_id']))).hexdigest(),'state_machine_behaviour_vector':value['m_StateMachineBehaviourVectorDescription'],'state_machine_behaviours':value['m_StateMachineBehaviours'],'parameters':param_defaults,'layers':controller['graph']['layers'],'locomotion_machine':machines[0],'other_layer_defaults':[{'index':m['index'],'default_state_index':m['default_state_index'],'default_state':m['states'][m['default_state_index']]} for m in machines[1:]],'clips':controller['clips']},'animators':animators,'player_root':{'path_id':player_root,'hierarchy_path':root_go['name'],'transform_path_id':root_transform,'bound_animator_count':len(descendants)},'parser_sources':[digest(Path(__file__).resolve()),digest(ROOT/'assets/inspect_player.py'),digest(HERE.parent/'asset-bridge/bridge_assets.py')],'limitations':['Static serialized configuration is not runtime playback evidence.','Only six serialized Animator references to the selected Player controller are bound; runtime creation or overrides are not excluded.','All source controller floats/ints default to zero and bools/triggers false; native initialization can override them.','StateMachineBehaviour absence does not remove AnimationEvent messages in clips; a separate receiver policy must govern them.','The retained complete controller evidence contains all layers; this focused extraction retains only locomotion and other layer default states.']}

    result['locomotion_clip_events'] = []
    for ci in [0,1,2,20,21]:
        clip=controller['clips'][ci];obj=inv.object(node,clip['pointer']['m_PathID']);raw=inv.raw(node,obj);typ=inv.metadata(node)['types'][obj['type_index']]
        result['locomotion_clip_events'].append({'clip_table_index':ci,'name':clip['name'],'source':inv.identity(node,obj),'decoded':parse_clip(raw,typ['tree'])})
    actual = next(a for a in animators if a['within_player_prefab'])
    result['acceptance_identity'] = {'bundleSha256':result['models']['sha256'],'controllerObjectSha256':controller['source']['sha256'],'controllerPathId':controller['source']['object']['path_id'],'controllerName':'Player','playerAsset':'assets/zzz-externalencryptasset/player.prefab','controllerAsset':None,'avatarName':actual['avatar']['name'],'avatarPathId':actual['avatar']['source']['object']['path_id'],'avatarObjectSha256':actual['avatar']['source']['sha256'],'animatorPath':'Player/Manustia','animatorPathId':actual['source']['object']['path_id']}
    result['locomotion'] = {'stateFullPathHash':686120411,'stateFullPath':'Locomotion.LocomotionTree','speedParameter':'Speed','motionSpeedParameter':'LocomotionMotionSpeed','clips':{label:{'name':controller['clips'][i]['name'],'threshold':threshold,'pathId':controller['clips'][i]['pointer']['m_PathID']} for label,i,threshold in [('Idle',0,0),('Walk',1,1),('Run',2,2)]}}
    return result

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--check',action='store_true');args=ap.parse_args()
    result=build();out=HERE/'original-controller.json'
    if args.check: assert json.loads(out.read_text(encoding='utf8')) == result
    else: out.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps({'status':'consistent' if args.check else 'written','path':str(out),'player_animators':[{'path':a['hierarchy_path'],'avatar':a['avatar']['name'] if a['avatar'] else None} for a in result['animators'] if a['within_player_prefab']]}))

if __name__ == '__main__': main()
