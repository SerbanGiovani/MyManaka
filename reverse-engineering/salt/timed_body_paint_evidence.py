"""Bind timed paint's native state machine, dispatch and float ABI to pinned bytes."""
import argparse,hashlib,json,struct,sys
from pathlib import Path
from metadata import HERE,DEFAULT_ROOT,Metadata,PE
from scene_evidence import build as bind,read

def fingerprint(path):return dict(path=str(path),sha256=hashlib.sha256(path.read_bytes()).hexdigest(),bytes=path.stat().st_size)
def build():
 r=bind(batch_prefix='timed-body-paint',reuse_method_ids={14462,14463,14494,14497,14513,14624,14625,14626,14627,14714,14715,14756,14757,14769,15011,15012,15015,15016,16071,16075,16076,16077,16734,16737,16744},extra_type_names=('BodyPaintController','SmoothFloat','PlayerStateModel','PlayerClassAccessor','FutanariController','PlayerAvatarObjectReferencer','PlayerBodyMaterialController','TemporaryInGameState','EventMethodManager','ItemType','IUpdater'),dispatch_targets=[(2215,2599,14757)],resource_boundary='Static temporary paint chain only; controlled runtime coverage is a separate artifact. Generic JustEffectItem is excluded as the BodyPaint producer.')
 assert r['new_observations']==r['new_unique_evidence_ids']==r['new_unique_procedure_addresses']==8
 # The class type is read from the actual method, not inferred from a short name.
 # PlayerController's type id for this build is pinned by the dispatch verifier.
 types={t['name'].split('.')[-1]:t for t in r['named_types']};fields={k:{f['name']:f for f in t['fields']} for k,t in types.items()}
 required={'BodyPaintController':{'alpha':0x10,'pca':0x18,'currentState':0x20},'SmoothFloat':{'<Current>k__BackingField':0x10,'maxDelta':0x14,'downMaxDelta':0x18,'<Target>k__BackingField':0x1c,'isLerp':0x20,'baseValue':0x24,'second':0x28,'downSecond':0x2c,'isUnscaled':0x30},'PlayerStateModel':{'Dokidoki':0x58,'OnEndCommonEquip':0x170,'CommonEquipEndTime':0x178,'LastUseItemType':0x228},'PlayerClassAccessor':{'<PlayerState>k__BackingField':0x60,'<PlayerAvatarObjectReferencer>k__BackingField':0x70,'<PlayerBodyMaterialController>k__BackingField':0x1b0,'<FutanariController>k__BackingField':0x1d8,'<BodyPaintController>k__BackingField':0x1e8},'FutanariController':{'<TamaClothesPaintMaterial>k__BackingField':0xa0,'<SaoClothesPaintMaterial>k__BackingField':0xa8},'PlayerAvatarObjectReferencer':{'FutanariMeshSao':0x1b8,'FutanariMeshTama':0x1c0},'EventMethodManager':{'updaterList':0x28},'InGameManager':{'eventMethodManager':0x78},'TemporaryInGameState':{'IsStopGameStateApplier':0x10},'GameStateData':{'PlayerRemainBodyPaintTime':0x17c,'IsActiveBodyPaintReusable':0x1df}}
 for owner,items in required.items():
  for name,offset in items.items():assert fields[owner][name]['offset']==offset,(owner,name)
 raw=(DEFAULT_ROOT/'SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat').read_bytes();md=Metadata(raw);ts=md.records(40,'<16i8H2I');fs=md.records(24,'<iiI');defaults={row[0]:(i,row) for i,row in enumerate(md.records(16,'<iii'))}
 sys.path.insert(0,str(HERE.parent/'assets'));from inspect_player import compressed_int32
 enums={}
 for name,tid in [('BodyPaintController.State',2259),('ItemType',2449)]:
  t=ts[tid];values=[]
  for fid in range(t[8],t[8]+t[18]):
   if fid not in defaults:continue
   idx,row=defaults[fid];values.append(dict(name=md.string(fs[fid][0]),field_id=fid,default_record_file_offset=md.header[16]+12*idx,default_record_raw_hex=raw[md.header[16]+12*idx:md.header[16]+12*idx+12].hex(),**compressed_int32(raw,md.header[18]+row[2])))
  enums[name]=values
 assert {v['name']:v['decoded_int32'] for v in enums['BodyPaintController.State']}=={'NoActiveNoMaterial':0,'NoActive':1,'Start':2,'FirstReduce':3,'SecondReduce':4}
 item={v['name']:v['decoded_int32'] for v in enums['ItemType']};assert item['BodyPaint']==5 and item['BodyPaintReusable']==8 and item['BodyPaintWasher']==9 and item['InvisiblePotionReusable']==7
 wrapper_path=HERE/'evidence/timed-body-paint/interop.json';wrapper=read(wrapper_path);byname={t['name'].split('.')[-1]:t for t in wrapper}
 assert next(p for p in byname['PlayerStateModel']['properties'] if p['name']=='Dokidoki')['type']=='System.Single'
 assert next(p for p in byname['PlayerStateModel']['properties'] if p['name']=='LastUseItemType')['type']=='ExposureUnnoticed2.Master.Item.ItemType'
 assert next(p for p in byname['EventMethodManager']['properties'] if p['name']=='updaterList')['type']=='Il2CppSystem.Collections.Generic.List`1<ExposureUnnoticed2.Scripts.InGame.IUpdater>'
 assert byname['EventMethodManager']['base_type']=='UnityEngine.MonoBehaviour'
 methods={m['method_id']:m for m in r['methods']};body_methods={m['name']:m for m in byname['BodyPaintController']['methods'] if m['name']!='.ctor'}
 assert body_methods['GetMaxDeltaAdd']['return_type']=='System.Single' and methods[15013]['signature']['return_type']['type_enum']==12
 assert body_methods['IsPainted']['return_type']=='System.Boolean' and methods[15014]['signature']['return_type']['type_enum']==2
 assert body_methods['Initialize']['parameters']==[{'name':'pca','type':'ExposureUnnoticed2.Object3D.Player.Scripts.PlayerClassAccessor'}]
 assert all(not body_methods[n]['parameters'] for n in ['OnUpdate','OnUseItem','OnUseWashItem'])
 native=(DEFAULT_ROOT/'GameAssembly.dll').read_bytes();pe=PE(native);method=methods[15013];ranges=method['containing_unwind_ranges'];assert len(ranges)==1
 start=int(ranges[0]['begin'],16);end=int(ranges[0]['end_exclusive'],16);assert start==int(method['va'],16)
 base=pe.offset(start,end-start);code=native[base:base+end-start];returns=[]
 # Bounded x64 opcode corroboration, not an exhaustive independent disassembler.
 # F3 0F 10 05 disp32 is MOVSS XMM0,[RIP+disp32]; all selected sites have
 # ADD RSP,20h / POP RBX / RET immediately after that instruction.
 for delta in range(len(code)-13):
  if code[delta:delta+4]!=b'\xf3\x0f\x10\x05' or code[delta+8:delta+14]!=bytes.fromhex('48 83 c4 20 5b c3'):continue
  va=start+delta;constant_va=va+8+struct.unpack_from('<i',code,delta+4)[0];constant_offset=pe.offset(constant_va,4);value=struct.unpack_from('<f',native,constant_offset)[0];returns.append(dict(va=hex(va),file_offset=base+delta,raw_hex=code[delta:delta+14].hex(),instruction='movss xmm0,dword ptr [rip+disp32]; add rsp,20h; pop rbx; ret',return_register='xmm0',constant_va=hex(constant_va),constant_file_offset=constant_offset,constant_raw_hex=native[constant_offset:constant_offset+4].hex(),value=value))
 assert len(returns)==4 and sorted(round(v['value'],2) for v in returns)==[.03,.1,.3,3.0]
 painted=methods[15014];painted_bytes=native[painted['file_offset']:painted['file_offset']+16];assert painted_bytes==bytes.fromhex('83 79 20 01 75 03 32 c0 c3 83 79 20 00 0f 97 c0') and native[painted['file_offset']+16]==0xc3
 r['return_abi']={'GetMaxDeltaAdd':dict(metadata_method_id=15013,pseudocode_misidentified_as_integer=True,declared_return='System.Single',register='xmm0',bounded_opcode_sites=returns),'IsPainted':dict(metadata_method_id=15014,declared_return='System.Boolean',register='al',file_offset=painted['file_offset'],raw_hex=native[painted['file_offset']:painted['file_offset']+17].hex())}
 r['enum_defaults']=enums;r['interop']=dict(snapshot=fingerprint(wrapper_path),sources=[fingerprint(DEFAULT_ROOT/'BepInEx/interop/Assembly-CSharp.dll'),fingerprint(DEFAULT_ROOT/'BepInEx/interop/Il2Cppmscorlib.dll')],parser=fingerprint(DEFAULT_ROOT/'BepInEx/core/Mono.Cecil.dll'),types=wrapper,limitation='Generated interop declarations are read with Cecil; original field registration and method signatures independently corroborate the names/types used here.')
 r['findings']=dict(runtime_verified=False,timer='max(0,remain - 2*clamp(PlayerStateModel.Dokidoki,0,0.5)*Time.deltaTime)',timer_runs_in_state0=True,initialize_thresholds=[dict(time='<=0',state=0,current=-1),dict(time='0<t<=24',state=4,current=0),dict(time='24<t<=60',state=3,current=.25),dict(time='t>60',state=2,current=.4)],smooth_ctor=dict(second=2,base_value=.15,default_value=0,is_lerp=False,is_unscaled=False,down_second_input=-1,down_second_actual=2,up_rate=.075,down_rate=.075),smooth_ctor_down_second_epsilon=.001,smooth_update='MoveTowards(Current,target,selected_rate*deltaTime), with exact snap; does not write Target',state_targets={'1':-1,'2':.4,'3':.25,'4':0},transition_rates={'2_to_3':.075,'3_to_4':.125,'4_to_1':.5},state1_completion='UpdateTo(-1); when Current<=-1, SetupBodyPaintFromGameState then state0, then early return before writing three shader targets',item_use=dict(ordinary_type=5,reusable_type=8,washer_type=9,remain=120,state=2,current=1,rebuild_materials_only_if_old_remain_nonpositive=True,reusable_true_only_for_type8=True,ordinary_does_not_clear_existing_reusable=True),wash=dict(state=4,remain=0,does_not_directly_clear_reusable=True,reusable_cleared_on_next_4_to_1_update=True),material_slot_condition='remaining>0, strict and without epsilon; body plus optional persistent/Rubber slots then timed paint then Sweat',get_max_delta_add_by_state={'0':3,'1':3,'2':.03,'3':.1,'4':.3},is_painted='state not 0 and not 1',natural_item_effect=dict(producer=16071,ordinary_delegate=16075,reusable_delegate=16076,wash_delegate=16077,deadline='Time.time+3',action=10008,consumer=14462,guard='CurrentAction.Type==10008 && Time.time>CommonEquipEndTime',delegate_field='PlayerStateModel.OnEndCommonEquip+0x170',generic_animation_just_effect_item_is_not_this_path=True),auto_frame=[16737,14757,15012],applier_flag_does_not_skip_paint=True,applier_guard_method=16744,warm_load_trap='state0 remains state0 after positive remaining Load + body material broadcast; timer still decays when Dokidoki>0. Initialize required to reconstruct state/Current; this alone does not demonstrate a natural cold-load bug.',futanari=dict(setup=15066,option_method=15067,option_va='0x180402090',renderers=['PlayerAvatarObjectReferencer.FutanariMeshSao+0x1b8','PlayerAvatarObjectReferencer.FutanariMeshTama+0x1c0'],bindings=['FutanariController.SaoClothesPaintMaterial+0xa8','FutanariController.TamaClothesPaintMaterial+0xa0'],setup_rebuilds_renderer_arrays=True,bindings_point_to_last_slot_even_without_timed_paint=True))
 r.setdefault('sources',[]).append(fingerprint(Path(__file__)))
 return r
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');a=p.parse_args();r=build();out=HERE/'evidence/timed-body-paint-chain.json'
 if a.check:assert read(out)==r,'Timed paint binding differs'
 else:out.write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
 print(json.dumps(dict(new_queries=r['new_observations'],reused=r['reused_observations'],float_return_sites=len(r['return_abi']['GetMaxDeltaAdd']['bounded_opcode_sites']),runtime_verified=False)))
