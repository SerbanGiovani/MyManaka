"""Read-only extraction of the exact original key prefab, trigger, clip and Apartment UI boundary."""
import sys,json,struct,hashlib
from pathlib import Path
sys.dont_write_bytecode=True
HERE=Path(__file__).resolve().parent
RE=HERE.parents[1]
sys.path.insert(0,str(RE/'assets'))
from inspect_player import models_investigation
from inspect_scenes import SceneInvestigation, fingerprint, read_value
from animator_tree import TreeDecoder
from inspect_npc_animation import parse_clip
from inspect_resources import Reader
PIN='98621b2c4fa4f9de80f355fae5776ab17efc016bcc81c581bcd0917af4308367'
model_path=RE/'salt/.cache/decrypted/models.unity3d'
assert hashlib.sha256(model_path.read_bytes()).hexdigest()==PIN
a=models_investigation(model_path); n=next(n for n in a.nodes if not n.endswith(('.resS','.resource'))); md=a.metadata(n)
# Verify the exact AssetBundle container key; root numeric ID alone is not a key lookup.
bo=next(o for o in md['objects'] if o['class_id']==142);br=a.raw(n,bo);r=Reader(br);r.aligned_string();r.take(12*r.number('i'));cnt=r.number('i'); selected=[]
for _ in range(cnt):
 start=r.position; key=read_value(r,'string'); preload=read_value(r,'i');size=read_value(r,'i');ptr=read_value(r,'PPtr')
 if key['value']=='assets/zzz-externalencryptasset/droppedhandcuffkey.prefab':selected.append(dict(key=key,preload_index=preload,preload_size=size,pointer=ptr,start=start,end=r.position,raw_hex=br[start:r.position].hex()))
assert len(selected)==1 and selected[0]['pointer']['value']=={'file_id':0,'path_id':1236904147823038301}
root=a.gameobject(n,a.object(n,1236904147823038301)); rows=[]
def walk(go,path):
 comps=[]; children=[]
 for ptr in go['components']:
  t=a.pointer(n,ptr['file_id'],ptr['path_id']);o=t['object'];raw=a.raw(n,o);typ=md['types'][o['type_index']]
  s=a.script(n,typ) if o['class_id']==114 else None
  v=TreeDecoder(typ['tree']).decode(raw) if o['class_id'] in [4,114,65,135,136] else None
  comps.append(dict(source=a.identity(n,o,raw),script=s,decoded=v,raw_hex=raw.hex(' '),type_tree=typ['tree']))
  if o['class_id']==4:
   r=Reader(raw);r.take(52); cnt=r.number('i');children=[a.pointer(n,r.number('i'),r.number('q')) for _ in range(cnt)]
 rows.append(dict(path=path,gameobject=go,components=comps))
 for t in children:
  rr=a.raw(n,t['object']); po=a.pointer(n,*struct.unpack_from('<iq',rr));cg=a.gameobject(n,po['object']); walk(cg,path+'/'+cg['name'])
walk(root,root['name'])
an=json.loads((RE/'assets/animator-wiring.json').read_text(encoding='utf-8'))['controllers'][0]
assert hashlib.sha256(a.raw(n,a.object(n,an['source']['object']['path_id']))).hexdigest()==an['source']['sha256']
clip=next(c for c in an['clips'] if c['index']==53);co=clip['target']['object']; ct=md['types'][co['type_index']]; cr=a.raw(n,co);cp=parse_clip(cr,ct['tree'])
source=SceneInvestigation(Path('E:/SecretFlasherManakaREA')); sn='level1'; sm=source.metadata(sn); areas=[]
donor=next(t for t in md['types'] if t['class_id']==114 and a.script(n,t) and a.script(n,t).get('fields',{}).get('class_name')=='InteractAreaController')
for typ in sm['types']:
 if typ['class_id']!=114:continue
 script=source.script(sn,typ)
 if script.get('fields',{}).get('class_name')!='InteractAreaController':continue
 assert typ['old_type_hash']==donor['old_type_hash'] and sm['engine_version']==md['engine_version']
 for ob in sm['objects']:
  if ob['type_index']!=typ['index']:continue
  raw=source.raw(sn,ob);owner=source.pointer(sn,*struct.unpack_from('<iq',raw));h=source.hierarchy(sn,owner['object']);v=TreeDecoder(donor['tree']).decode(raw)
  areas.append(dict(source=source.identity(sn,ob,raw),path='/'.join(x['gameobject']['name'] for x in reversed(h['entries'])),decoded=v,raw_hex=raw.hex(),schema_hash_match=typ['old_type_hash']))
assert sorted(x['decoded']['value']['type'] for x in areas)==[11,13,14]
res=dict(schema_version=1,kind='Original dropped key and pickup clip static evidence',authority='shipped-artifact / offline parser',models_source=fingerprint(model_path),node=n,container=dict(source=a.identity(n,bo,br),entry=selected[0]),root=rows,clip=dict(source=a.identity(n,co,cr),parsed=cp,type_tree=ct['tree']),controller=dict(source=an['source'],graph=an['graph'],selected_state_raw=an['decoded']['value']['m_Controller']['m_StateMachineArray'][1]['m_StateConstantArray'][17]),apartment=dict(scene='Apartment',node=sn,areas=areas,scope='All serialized InteractAreaController objects in level1; types11/13/14 map to Closet/Bed/PC UI, no fixed original key claimed.'),limits=['Static serialized facts, not target execution.','Prefab root local pose does not establish any original world placement.','Only Transform, selected MonoBehaviours and collider schemas are decoded; other components retain raw bytes without interpretation.','The companion independent Apartment fixture is a reconstruction placement, not a fixed original scene object.'])
(HERE/'target-assets.json').write_text(json.dumps(res,indent=2,ensure_ascii=False)+'\n',encoding='utf-8')
print(json.dumps(dict(saved=True,hierarchy_objects=len(rows),events=cp['event_count'],apartment_interact_types=[x['decoded']['value']['type'] for x in areas])))
