"""Bind natural item UI/acquisition and cold player initialization to pinned artifacts."""
import argparse,hashlib,json,sqlite3,struct
from pathlib import Path
from metadata import HERE,DEFAULT_ROOT,Metadata,PE
from scene_evidence import build as bind,read
def fp(path):return dict(path=str(path),sha256=hashlib.sha256(path.read_bytes()).hexdigest())
def build():
 reused={14462,14463,14624,14625,14627,14714,14715,14756,14757,14769,15011,15012,15015,15016,15017,15066,15067,16071,16075,16076,16077,16370,16734,16737,16794,16862,16970,16971,17409,17594,17860,17861,17925,17981,17987,18007}
 r=bind(batch_prefix='natural-paint',reuse_method_ids=reused,extra_type_names=('PlayerStateModel','BodyPaintController','SmoothFloat','MItem','MItemRecord','InventoryPanelView','InventoryItemView','OnlineShopPanelView','OnlineShopItemView','RankReleaseType','MRankReleaseRecord','MRankRecord','IOnlineShopItemRecord','SexManager','PlayerClassAccessor','PlayerController','TemporaryInGameState','PlayerBodyMaterialController'),dispatch_targets=[(2215,2599,14757)],resource_boundary='Natural UI, shop and title-load flow inferred statically; natural runtime observations and real persistent save selection are separately required. No replay or game execution in this binder.')
 assert r['new_observations']==r['new_unique_evidence_ids']==r['new_unique_procedure_addresses']==7
 native=(DEFAULT_ROOT/'GameAssembly.dll').read_bytes();pe=PE(native);md=Metadata((DEFAULT_ROOT/'SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat').read_bytes())
 named={t['name'].split('.')[-1]:{f['name']:f for f in t['fields']} for t in r['named_types']}
 for owner,items in {'PlayerStateModel':{'OnEndCommonEquip':0x170,'CommonEquipEndTime':0x178,'LastUseItemType':0x228,'TransAction':0x234,'CurrentAction':0x48,'IsCrouch':0x1b,'CurrentState':0x5c,'IsEcstasyMotion':0x50},'GameStateData':{'ExposeExp':0x1e8,'ItemDict':0x218,'PlayerRemainBodyPaintTime':0x17c,'IsActiveBodyPaintReusable':0x1df},'MItemRecord':{'Type':0x18,'IsReusable':0x28,'IsDelayConsume':0x2a,'CanByOnlineShop':0x2b,'<Price>k__BackingField':0x38},'MRankReleaseRecord':{'ReleaseRank':0x38},'MRankRecord':{'NeedRp':0x28},'SexManager':{'<IsSexMode>k__BackingField':0x10},'PlayerController':{'Instance':0,'pca':0x40}}.items():
  for name,offset in items.items():assert named[owner][name]['offset']==offset,(owner,name)
 instructions=read(HERE/'evidence/natural-paint/instructions.json');inputs=read(HERE/'evidence/natural-paint/decoder-input.json')
 for source in [instructions['native'],instructions['decoder'],instructions['preparer'],instructions['parser']]:assert hashlib.sha256(Path(source['path']).read_bytes()).hexdigest()==source['sha256']
 assert len(instructions['ranges'])==5
 for part in instructions['ranges']:
  p=part['pdata_file_offset'];assert native[p:p+12].hex()==part['pdata_raw_hex'];pos=int(part['begin'],16)
  for ins in part['instructions']:
   raw=bytes.fromhex(ins['raw_hex']);assert int(ins['va'],16)==pos and pe.offset(pos)==ins['file_offset'] and native[ins['file_offset']:ins['file_offset']+len(raw)]==raw and len(raw)==ins['length'];pos+=len(raw)
  assert pos==int(part['end_exclusive'],16)
 rows={ins['va']:ins for part in instructions['ranges'] for ins in part['instructions']}
 for address,text in [('0x1804921fc','mov ecx,[rax+38h]'),('0x180492222','mov ecx,[rcx+1E8h]'),('0x180492228','cmp [rax+28h],ecx'),('0x18049222b','setle al'),('0x1804f2ae1','cmp byte ptr [rcx+1Bh],0'),('0x1804f2af0','cmp dword ptr [rax+18h],0FFFFFFFFh'),('0x1804f2afe','cmp dword ptr [rcx+5Ch],0'),('0x1804f2b04','cmp byte ptr [rcx+50h],0'),('0x1804f2b14','cmp byte ptr [rax+10h],0')]:assert rows[address]['text'].lower()==text.lower(),address
 assert rows['0x180646c82']['direct_branch_target']=='0x180637bc0'
 assert rows['0x180646c52']['text'].lower()=='cmp byte ptr [rsp+50h],0'
 assert rows['0x180646c57']['direct_branch_target']=='0x180646c63'
 assert rows['0x180646c5e']['direct_branch_target']=='0x180646d50'
 assert rows['0x180646c70']['text'].lower()=='mov rcx,[rax+1b0h]'
 layout=read(HERE/'symbols/field-offsets.json');type_table=layout['registration']['pointer_tables']['runtime_types'];types=md.records(40,'<16i8H2I');usages=[]
 for slot,expected in [(0x182d592c0,'ExposureUnnoticed2.Scripts.InGame.SexManager'),(0x182d58330,'ExposureUnnoticed2.Object3D.Player.Scripts.Other.BodyPaintController'),(0x182d58378,'ExposureUnnoticed2.Object3D.Player.Scripts.PlayerController')]:
  off=pe.offset(slot,8);encoded=struct.unpack_from('<Q',native,off)[0];assert encoded>>29==1 and encoded&1;idx=(encoded&0x1fffffff)>>1;typ_va=struct.unpack_from('<Q',native,type_table['file_offset']+8*idx)[0];typ_off=pe.offset(typ_va,12);tid=struct.unpack_from('<Q',native,typ_off)[0];t=types[tid];name='.'.join(filter(None,(md.string(t[1]),md.string(t[0]))));assert name==expected;usages.append(dict(va=hex(slot),file_offset=off,raw_hex=native[off:off+8].hex(),type_name=name,type_id=tid,runtime_type_index=idx,runtime_type_file_offset=typ_off,runtime_type_raw_hex=native[typ_off:typ_off+12].hex()))
 cctor=next(part for part in instructions['ranges'] if part['method_id']==15018);literal_load=rows['0x1803fd39f'];assert literal_load['ip_relative_memory_address']=='0x182d58308';lit_off=pe.offset(0x182d58308,8);encoded=struct.unpack_from('<Q',native,lit_off)[0];assert encoded>>29==5;idx=(encoded&0x1fffffff)>>1;size,start=md.records(2,'<II')[idx];literal=md.region(4)[start:start+size].decode('utf8');assert literal=='_Tweak_transparency'
 c=sqlite3.connect((HERE/'.cache/methods.sqlite').resolve().as_uri()+'?mode=ro',uri=True);c.row_factory=sqlite3.Row
 hook_ids=[16370,17861,17860,16862,14756,14715,14757,15011,15012,15015,15016,16071,16075,16076,16077,14462,17925,17993,18007,17984,16970,16971,17594,17742,17747]
 hooks=[]
 for mid in hook_ids:
  row=dict(c.execute('select * from methods where id=?',(mid,)).fetchone());assert pe.offset(int(row['va'],16))==row['file_offset'];hooks.append(dict(method_id=mid,name=row['qualified_name'],va=row['va'],rva=hex(int(row['va'],16)-pe.base),file_offset=row['file_offset'],entry_bytes=native[row['file_offset']:row['file_offset']+16].hex(),parameter_count=row['parameter_count']))
 rebuilds=[]
 for mid,call,returned in [(14786,0x180646c82,0x180646c87),(14783,0x18064663e,0x180646643),(14715,0x18063f44f,0x18063f454)]:
  row=dict(c.execute('select * from methods where id=?',(mid,)).fetchone());off=pe.offset(call,5);raw=native[off:off+5];assert raw[0]==0xe8 and call+5==returned and call+5+struct.unpack_from('<i',raw,1)[0]==0x180637bc0
  rebuilds.append(dict(method_id=mid,name=row['qualified_name'],entry_va=row['va'],call_va=hex(call),return_rva=hex(returned-pe.base),file_offset=off,raw_hex=raw.hex(),target_method_id=14624,target_va='0x180637bc0',kind='bounded original-PE relative E8 call corroboration; return address is a callsite coordinate, not a distinct effect producer'))
 c.close();assets=read(HERE.parent/'natural-paint-assets.json');rank=read(HERE.parent/'assets/bareta-config.json')['tables']['MRank'];release=assets['rank_release']['body_paint'];rank5=next(e['record'] for e in rank['entries'] if any(f['name']=='Rank' and f['value']==5 for f in e['record']['fields']));need=next(f['value'] for f in rank5['fields'] if f['name']=='NeedRp');assert release['Type']==109 and release['ReleaseRank']==5 and need==5000
 methods={m['method_id']:read(HERE.parent/m['path'])['normalized_result'] for m in r['methods']}
 assert '0x6d' in methods[17742] and 'MItem__GetAll' in methods[17742] and 'ChangeItemNum' in methods[17747] and 'IsEnoughRp' in methods[17747] and 'ConsumeRp' in methods[17747]
 assert '0x2718' in methods[16071] and '+ 3.0' in methods[16071] and '+ 0x170' in methods[16071]
 assert '+ 0x178' in methods[14462] and 'fVar13 < *pfVar1 || fVar13 == *pfVar1' in methods[14462]
 assert '+ 0x1e8' in methods[14715] and '<= 24.0' in methods[14715] and '<= 60.0' in methods[14715] and methods[14715].index('<= 24.0')<methods[14715].rindex('SetupBodyPaintFromGameState')
 r['supplemental_instructions']=instructions;r['supplemental_typeinfo_usages']=usages;r['tweak_literal']=dict(value=literal,usage_va='0x182d58308',usage_file_offset=lit_off,usage_raw_hex=native[lit_off:lit_off+8].hex(),metadata_literal_index=idx,metadata_definition_file_offset=md.header[2]+idx*8,metadata_data_file_offset=md.header[4]+start)
 tails=[]
 for mid,source in [(16075,0x180468c96),(16076,0x180468d06)]:
  offset=pe.offset(source,5);raw=native[offset:offset+5];assert raw[0]==0xe9;target=source+5+struct.unpack_from('<i',raw,1)[0];assert target==0x1803fd150;assert any(int(p['begin'],16)<=source<source+5<=int(p['end_exclusive'],16) for m in r['methods'] if m['method_id']==mid for p in m['containing_unwind_ranges']);tails.append(dict(method_id=mid,va=hex(source),file_offset=offset,raw_hex=raw.hex(),kind='bounded relative E9 tail-branch corroboration',target=hex(target)))
 r['tail_branch_corroboration']=tails
 r['material_rebuild_call_corroboration']=rebuilds
 r['hook_coordinates']=hooks;r['original_item_assets']=dict(source=fp(HERE.parent/'natural-paint-assets.json'),parser=fp(HERE.parent/'natural-paint-assets.py'),selected=assets['selected'],localized_item_names=assets['localized_item_names'],rank_release=release,rank5_need_rp=need,rank_table_source=fp(HERE.parent/'assets/bareta-config.json'))
 r['findings']=dict(runtime_verified=False,shop=dict(pc_open=17600,item_tab=0,system_trial_hides_item_list=True,gate=dict(release_type=109,name='BodyPaint',rank=5,compare='GameStateData.ExposeExp>=MRank.GetByRank(5).NeedRp',threshold=5000),reusable_already_owned_masks_purchase=True,item_stack_cap=99,prices={'5':500,'8':500,'9':0},native_purchase=17747,purchase_adds_inventory_count=1,purchase_tutorial_for_types5and8=10),inventory=dict(use_entry=17925,selection_callback=17993,use_process=18007,item_record_at_view=0x70,use_delegate_at_view=0x60,guard=17984,guard_conditions=['no attached handcuffs','PlayerState.IsCrouch=false','CurrentAction.Type=-1','CurrentState=0','IsEcstasyMotion=false','SexManager.IsSexMode=false'],guard_has_no_stage_check=True,home_permitted_by_this_guard_only=True,reusable_type8_requires_confirmation_popup=True,ordinary_type5_consumed_before_scheduling=True,reusable8_and_washer9_not_consumed=True),effect=dict(mitem=16071,deadline='Time.time+3',pending_action_field='TransAction+0x234',action_type=10008,current_action_type='CurrentAction+0x48 then MActionRecord.Type+0x18',completion_guard='Time.time strictly greater than CommonEquipEndTime while CurrentAction.Type==10008',deadline_field='CommonEquipEndTime+0x178',delegate_field='OnEndCommonEquip+0x170',delegates={'5':16075,'8':16076,'9':16077},inline_or_tail_paths_mean15015_or15016_entry_is_not_universal=True),cold=dict(title_continue=16370,slot_select=17861,scene_transition=17860,ingame_start=16862,player_initialize=14756,pca_initialize=14715,body_paint_state_initialize_is_inlined=True,may_have_zero15011_entries=True,ordered='Pca body-paint inline pca/state/Current assignment, body material Initialize/Setup/Apply, body customize Initialize',subsequent_automatic_update=14757,full_process_restart_needed_to_claim_true_cold=True),scope='Static reachability only. Natural button presses, inventory change,3-second callback,save/time value and actual cold-instance/renderer reconstruction must be observed independently.')
 r.setdefault('sources',[]).extend([fp(Path(__file__)),fp(HERE/'prepare_natural_paint_instructions.py'),fp(HERE/'decode_npc_fps.ps1')]);return r
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');a=p.parse_args();result=build();out=HERE/'evidence/natural-paint-chain.json'
 if a.check:assert result==read(out),'Natural paint static binding differs'
 else:out.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
 print(json.dumps(dict(new_queries=result['new_observations'],reused=result['reused_observations'],supplemental_ranges=len(result['supplemental_instructions']['ranges']),runtime_verified=False)))
