"""Read selected native skill tier assets using existing pure readers; no game execution."""
import sys,json
from pathlib import Path
HERE=Path(__file__).resolve().parent
sys.dont_write_bytecode=True
sys.path.insert(0,str(HERE/'assets'))
import inspect_bareta as b
import inspect_player as player
from inspect_scenes import SceneInvestigation,fingerprint,mono_prefix,read_value,resolve_value

def build():
 root=Path('E:/SecretFlasherManakaREA')
 pairs=[('MSkillMaxAccessoryNum','RSkillMaxAccessoryNum','ExposureUnnoticed2.Master.Skill.SkillMaxAccessoryNum.'),('MSkillSlow','RSkillSlow','ExposureUnnoticed2.Master.Skill.SkillSlow.')]
 b.TYPE_NAMES={'ExposureUnnoticed2.Object3D.IngameManager.AssetReferencer'}|{ns+n for first,second,ns in pairs for n in [first,second]};b.ENUM_NAMES=set()
 wrapper,md=b.declarations(root);original={t['full_name']:t for t in md['types']};properties={t['type']:{p['name']:p for p in t['properties']} for t in wrapper['types']};inv=SceneInvestigation(root)
 selected=player.find_script_objects(inv,['resources.assets'],{'MSkillMaxAccessoryNum','MSkillSlow','AssetReferencer'});by={x['script_identity']['fields']['class_name']:x for x in selected};tables={a:b.table(inv,by[a],rec,original,properties,{}) for a,rec,ns in pairs}
 asset=by['AssetReferencer'];reader,_=mono_prefix(inv.raw('resources.assets',asset['source']['object']));bindings=[]
 for f in original['ExposureUnnoticed2.Object3D.IngameManager.AssetReferencer']['fields'][:27]:
  ptr=read_value(reader,'PPtr')
  if f['name'] not in tables:continue
  target=resolve_value(inv,'resources.assets',ptr);assert target['object']==tables[f['name']]['source']['object'];bindings.append(dict(field=f['name'],field_id=f['field_id'],offset=f['registered_offset'],pointer=ptr,target=target))
 assert len(bindings)==2
 return dict(schema_version=1,authority='offline-shipped-asset-interpretation',source_bundle=fingerprint(inv.bundle.path),parser=fingerprint(Path(__file__)),wrapper_declarations=wrapper,metadata=md,bindings=bindings,tables=tables,limitations=['Uses generated field-property types corroborated by original metadata and full record EOF.','Primary asset bytes, not observed runtime use; UI Refresh calls the corresponding master Get.'])
if __name__=='__main__':
 result=build();(HERE/'paid-skill-boundary-assets.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
 for name,table in result['tables'].items():print(name,[{f['name']:f['value'] for f in r['record']['fields']} for r in table['entries']])
