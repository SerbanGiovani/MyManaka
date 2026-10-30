"""Read original MItem table/selected records; no game or interop code executes."""
import argparse,hashlib,json,sys
from pathlib import Path
HERE=Path(__file__).resolve().parent
sys.dont_write_bytecode=True
sys.path.insert(0,str(HERE/'assets'))
import inspect_bareta as b
import inspect_player as player
from inspect_scenes import SceneInvestigation,fingerprint,mono_prefix,read_value,resolve_value
from inspect_resources import Reader

def localized_item_names(inv,selected):
 node='resources.assets';obj=inv.object(node,1484);raw=inv.raw(node,obj);reader=Reader(raw)
 label=reader.aligned_string();length=reader.number('i');payload_offset=reader.position;payload=reader.take(length);reader.align()
 assert label=='dictionary' and obj['class_id']==49 and reader.position==len(raw)
 # The source uses CRCRLF for some rows. LF is the physical record delimiter;
 # keep raw byte offsets rather than allowing universal-newline conversion.
 lines=payload.split(b'\n');header=lines[0].rstrip(b'\r').decode('utf8').split('\t');assert header[:7]==['id','key','ja','en','sc','tc','ko']
 wanted={x['name_key']:x['type'] for x in selected};rows=[];offset=len(lines[0])+1
 for line_number,raw_line in enumerate(lines[1:],2):
  line=raw_line.rstrip(b'\r');values=line.decode('utf8').split('\t')
  if len(values)>1 and values[1] in wanted:
   assert len(values)==len(header)
   fields=dict(zip(header,values));row=dict(type=wanted[fields['key']],key=fields['key'],id=int(fields['id']),physical_lf_line_number=line_number,payload_byte_offset=offset,serialized_byte_offset=payload_offset+offset,byte_length=len(line),raw_hex=line.hex(),sha256=hashlib.sha256(line).hexdigest(),en=fields['en'],sc=fields['sc'],tc=fields['tc'])
   assert raw[row['serialized_byte_offset']:row['serialized_byte_offset']+row['byte_length']].hex()==row['raw_hex'];rows.append(row)
  offset+=len(raw_line)+1
 assert sorted((x['type'],x['id']) for x in rows)==[(5,592),(8,593),(9,1142)]
 return dict(source=inv.identity(node,obj,raw),serialized_name=label,payload_serialized_offset=payload_offset,payload_byte_length=length,payload_sha256=hashlib.sha256(payload).hexdigest(),header=header,rows=rows,bytes_consumed=reader.position,end_of_object_verified=True,boundary='Original TextAsset name, payload length, UTF-8 TSV bytes and trailing alignment consume EOF. Only three selected name rows are projected; physical lines count LF delimiters and byte offsets precede UTF-8 decoding. These are original displayed translations, not proof of a runtime language selection or a rendered UI label.')
def build():
 root=Path('E:/SecretFlasherManakaREA');ns='ExposureUnnoticed2.Master.Item.'
 release_ns='ExposureUnnoticed2.Master.RankRelease.'
 b.TYPE_NAMES={ns+'MItem',ns+'MItemRecord',release_ns+'MRankRelease',release_ns+'MRankReleaseRecord','ExposureUnnoticed2.Object3D.IngameManager.AssetReferencer'};b.ENUM_NAMES={ns+'ItemType',release_ns+'RankReleaseType'}
 wrapper,metadata=b.declarations(root);original={t['full_name']:t for t in metadata['types']};properties={t['type']:{p['name']:p for p in t['properties']} for t in wrapper['types']};enums={t['full_name']:{v['value']:v['name'] for v in t['values']} for t in metadata['enums']}
 for name,t in original.items():
  for f in t['fields']:
   key=f['name']
   if key.startswith('<') and key.endswith('>k__BackingField') and key not in properties[name]:properties[name][key]=properties[name][key[1:key.index('>')]]
 inv=SceneInvestigation(root);found=player.find_script_objects(inv,['resources.assets'],{'MItem','MRankRelease','AssetReferencer'});table=next(x for x in found if x['script_identity']['fields']['class_name']=='MItem');asset=next(x for x in found if x['script_identity']['fields']['class_name']=='AssetReferencer');release_table=next(x for x in found if x['script_identity']['fields']['class_name']=='MRankRelease')
 reader,label=mono_prefix(inv.raw('resources.assets',table['source']['object']));count=read_value(reader,'i');assert count['value']==18;entries=[]
 for index in range(count['value']):
  pointer=read_value(reader,'PPtr');target=resolve_value(inv,'resources.assets',pointer);raw=inv.raw(target['node'],target['object']);record=b.scalar_record(inv,target['node'],target['object'],original,properties,enums,prefix_count=9)
  assert record['script_identity']['fields']['class_name']=='MItemRecord'
  assert record['bytes_consumed']==len(raw) and record['unparsed_tail_hex']=='','Selected nine serialized fields do not consume EOF'
  fields=record['fields'];assert [f['name'] for f in fields]==['Type','<NameKey>k__BackingField','IsReusable','IsValuables','IsDelayConsume','CanByOnlineShop','CanDrop','<DescriptionKey>k__BackingField','<Price>k__BackingField']
  record.update(end_of_object_verified=True,schema_boundary='Exactly these nine selected fields consume EOF. The final native TypeId backing field has no stored bytes in this pinned object; no claim about its runtime computed value.')
  values={f['name']:f['value'] for f in fields}
  entries.append(dict(array_index=index,serialized_pointer=pointer,type=values['Type'],record=record if values['Type'] in [5,8,9] else None))
 assert reader.position==len(reader.data)
 ar,_=mono_prefix(inv.raw('resources.assets',asset['source']['object']));bindings=[]
 for field in original['ExposureUnnoticed2.Object3D.IngameManager.AssetReferencer']['fields']:
  assert not field['is_static'],'MItem reference not found in leading serialized reference prefix';pointer=read_value(ar,'PPtr')
  if field['name'] in ['MItem','MRankRelease']:
   target=resolve_value(inv,'resources.assets',pointer);expected=table if field['name']=='MItem' else release_table;assert target['object']==expected['source']['object'];bindings.append(dict(field=field['name'],field_id=field['field_id'],registered_offset=field['registered_offset'],serialized_pointer=pointer,target=target))
   if len(bindings)==2:break
 assert len(bindings)==2
 releases=b.table(inv,release_table,'MRankReleaseRecord',original,properties,enums);body_release=next(r for r in releases['entries'] if any(f['name']=='Type' and f['value']==109 for f in r['record']['fields']));release_values={f['name']:f['value'] for f in body_release['record']['fields']};assert release_values['ReleaseRank']==5
 selected=[]
 for entry in entries:
  if entry['record'] is None:continue
  fs={f['name']:f['value'] for f in entry['record']['fields']};selected.append(dict(type=fs['Type'],enum=enums[ns+'ItemType'][fs['Type']],name_key=fs['<NameKey>k__BackingField'],description_key=fs['<DescriptionKey>k__BackingField'],price=fs['<Price>k__BackingField'],is_reusable=fs['IsReusable'],is_valuables=fs['IsValuables'],is_delay_consume=fs['IsDelayConsume'],can_by_online_shop=fs['CanByOnlineShop'],can_drop=fs['CanDrop']))
 assert sorted((x['type'],x['price'],x['is_reusable'],x['can_by_online_shop']) for x in selected)==[(5,500,False,True),(8,500,True,True),(9,0,True,True)]
 return dict(schema_version=1,authority='offline-original-shipped-MItem-serialized-records',source_bundle=fingerprint(inv.bundle.path),parser=fingerprint(Path(__file__)),wrapper_declarations=wrapper,metadata=metadata,asset_referencer_bindings=bindings,table=dict(source=table['source'],script_identity=table['script_identity'],raw_hex=table['raw_hex'],serialized_name=label,count=count,bytes_consumed=reader.position,end_of_object_verified=True,entries=entries),rank_release=dict(table=releases,body_paint=release_values),selected=selected,localized_item_names=localized_item_names(inv,selected),limits=['MItemRecord.Type determines these inventory keys. Runtime TypeId has no serialized bytes here and is not inferred from the enum value.','Source flags/price are not proof of natural purchase, available UI, successful use, or current player rank.'])
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');a=p.parse_args();result=build();out=HERE/'natural-paint-assets.json'
 if a.check:assert result==json.loads(out.read_text(encoding='utf8'))
 else:out.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
 print(json.dumps(result['selected'],ensure_ascii=False))
