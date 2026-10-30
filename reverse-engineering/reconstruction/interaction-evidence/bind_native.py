"""Bind this round's retained REA records to original IL2CPP method definitions and known usage slots."""
import sys,json,hashlib,sqlite3,struct
from pathlib import Path
sys.dont_write_bytecode=True
HERE=Path(__file__).resolve().parent; RE=HERE.parents[1];sys.path.insert(0,str(RE/'salt'));sys.path.insert(0,str(RE/'assets'))
from metadata import Metadata,PE
from inspect_player import compressed_int32
read=lambda p:json.loads(Path(p).read_text(encoding='utf-8-sig'))
raw=Path('E:/SecretFlasherManakaREA/SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat').read_bytes();native=Path('E:/SecretFlasherManakaREA/GameAssembly.dll').read_bytes();md=Metadata(raw);pe=PE(native)
assert hashlib.sha256(native).hexdigest()=='6003033049ac32e8712dc4101382534e21d65b97100c167ebec6bbca1462c18d'; assert hashlib.sha256(raw).hexdigest()=='457203754abe77b346fd98086a5c787bd41088d808cc81b1d4e2cae5b85c72c8'
c=sqlite3.connect((RE/'salt/.cache/methods.sqlite').as_uri()+'?mode=ro',uri=True);c.row_factory=sqlite3.Row;methods={r['id']:dict(r) for r in c.execute('select * from methods')};c.close();definitions=md.records(12,'<6iI4H');types=md.records(40,'<16i8H2I');fields=md.records(24,'<iiI');defaults={x[0]:(i,x) for i,x in enumerate(md.records(16,'<iii'))}
obs=[];runs=[]
for name in ['native','native-key-callback']:
 run=read(HERE/name/'run.json');plan=read(run['plan']);assert run['success'] and not any(run.get(x) for x in ['close_error','transport_close_error','error']);assert hashlib.sha256(Path(plan['seed_file']).read_bytes()).hexdigest()==plan['seed_sha256']==run['seed_sha256'];runs.append(dict(path=name+'/run.json',observations=len(run['functions']),success=True,closed=True,seed_sha256=run['seed_sha256']))
 for f in run['functions']:
  m=methods[f['metadata_id']]; assert m['va']==f['va'] and m['token']==int(f['token'],16);off=md.header[12]+m['id']*36; d=definitions[m['id']]; assert d[6]==m['token'] and md.string(d[0])==m['name'];assert pe.offset(int(m['va'],16),executable=True)==m['file_offset']
  path=HERE/name/(f['file_stem']+'-'+f['operation']+'.json');ev=read(path); assert ev['subject']['digest']['sha256']==hashlib.sha256(native).hexdigest() and ev['evidence_id']==f['evidence_id'];assert ev['provider']['id']=='ghidra';text=ev['normalized_result'];assert isinstance(text,str)
  obs.append(dict(method_id=m['id'],qualified_name=m['qualified_name'],va=m['va'],file_offset=m['file_offset'],token=hex(m['token']),metadata_definition_file_offset=off,metadata_definition_raw_hex=raw[off:off+36].hex(),operation=f['operation'],evidence_id=ev['evidence_id'],path=path.relative_to(HERE).as_posix(),provider=ev['provider'],analysis_profile=ev['analysis_profile'],listing_empty=not bool(text.strip()),limitations=ev['limitations'],aliases=[dict(method_id=x['id'],name=x['qualified_name']) for x in methods.values() if x['va']==m['va']]))
callback=next(o for o in obs if o['method_id']==15896 and o['operation']=='procedure_pseudo_code');text=read(HERE/callback['path'])['normalized_result']; assert '(lVar1 + 0x224) = 5' in text and '(lVar1 + 0x238) = 1' in text and '(lVar1 + 0x234) = 0x2729' in text
uoff=pe.offset(0x182d5ca10,8);u=struct.unpack_from('<Q',native,uoff)[0];assert u==0x60007c31 and ((u&0x1fffffff)>>1)==15896
vals=[]
for tid,t in enumerate(types):
 if md.string(t[0])!='DropItemType':continue
 for fid in range(t[8],t[8]+t[18]):
  if fid not in defaults:continue
  did,(_,rt,di)=defaults[fid];value=compressed_int32(raw,md.header[18]+di);vals.append(dict(name=md.string(fields[fid][0]),value=value['decoded_int32'],field_id=fid,metadata_default_record_file_offset=md.header[16]+did*12,metadata_default_record_raw_hex=raw[md.header[16]+did*12:md.header[16]+did*12+12].hex(),encoded_value=value))
assert next(x['value'] for x in vals if x['name']=='HandcuffKey')==5
res=dict(schema_version=1,authority='shipped-artifact / static native decompilation and original metadata bytes',native_sha256=hashlib.sha256(native).hexdigest(),metadata_sha256=hashlib.sha256(raw).hexdigest(),runs=runs,observations=obs,callback_binding=dict(initializer_method_id=15889,interact_type=15,usage_va='0x182d5ca10',usage_file_offset=uoff,raw_hex=native[uoff:uoff+8].hex(),method_id=15896,callback_evidence_id=callback['evidence_id']),DropItemType=vals,guards=dict(callback_fields={'LastPickUpItemType':5,'ForceSkipHandcuffCheckTransAction':True,'TransAction':10025},external_request='14462 checks IsPlayingAction then CanUseHand(true, state.ForceSkipHandcuffCheckTransAction, false, false, false), clears skip flag and calls ChangeAction',CanUseHand_arguments={'isSendMessage':True,'isSkipHandcuff':True,'isSkipBasket':False,'isSkipPlayingAction':False,'isSkipCrouch':False},reject_crouch=True,requires_handcuffs=False,handcuff_guard_explicitly_skipped=True,neutral_scope='CurrentAction=None, CurrentState=Idle, no ecstasy, no active SexManager, no held clothing. Other subsystems are neutral and not reconstructed.'),limits=['This round has five nonempty pseudocode queries and one empty assembly listing. The empty Listing is preserved as unavailable instruction-level corroboration; it is not evidence of an empty function.','Four initializer/cache/drop/collect queries repeated existing saved observations; only callback15896 was a newly decompiled procedure.','Pseudocode is not original source. Static analysis did not execute the original game or observe animation or input.','No original Apartment fixed-key placement is claimed.'])
(HERE/'native-contract.json').write_text(json.dumps(res,ensure_ascii=False,indent=2)+'\n',encoding='utf-8');print(json.dumps(dict(observations=len(obs),nonempty_pseudocode=5,empty_assembly=1,runs_closed=2,callback=callback['evidence_id'])))
