"""Bind TimeStop producer/dispatch observations and bounded xref candidates."""
import argparse
import hashlib
import json
import struct
import sys
from pathlib import Path
from scene_evidence import build as bind, read
from metadata import HERE, DEFAULT_ROOT, Metadata


def build():
    result=bind(batch_prefix='time-stop-',reuse_method_ids={14421,14462,14536,15518,15536,17304,17309},
        extra_type_names=('InputResolver','InputModel','PlayerAnimationReceiver','PlayerAction','PlayerStateModel',
          'NpcManager','NpcController','NpcComponentAccessor','InGameManager','TemporaryInGameState',
          'Events','EventManager','TimeStopEvent','MentalManager','RingItemType','SkillType'),
        dispatch_targets=[],resource_boundary='Runtime uses original resources NPC prefabs and models/manustia.prefab; asset byte parsing is reused from animator-wiring/player-config and runtime inventory.')
    dependency=HERE/'symbols/time-stop-xrefs.json'
    result['xref_scan_dependency']={'path':dependency.relative_to(HERE.parent).as_posix(),'sha256':hashlib.sha256(dependency.read_bytes()).hexdigest()}
    scan=read(dependency)
    assert scan['native']['sha256']==result['native_sha256']
    assert len(scan['scan']['candidates'])==9
    native=(DEFAULT_ROOT/'GameAssembly.dll').read_bytes()
    result['encoded_slot_carrier_search']=[]
    for va in ('0x182d58080','0x182d53c48'):
        usage=next(u for u in result['usages'] if u['va']==va)
        needle=bytes.fromhex(usage['raw_hex']);positions=[];start=0
        while (start:=native.find(needle,start))>=0:positions.append(start);start+=1
        assert positions==[usage['file_offset']]
        result['encoded_slot_carrier_search'].append({'usage_va':va,'raw_hex':usage['raw_hex'],'file_offsets':positions,
          'boundary':'Exact encoded8byte carrier matches in original native file, not dynamic alias exclusion'})
    raw=(DEFAULT_ROOT/'SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat').read_bytes();md=Metadata(raw)
    fields=md.records(24,'<iiI');defaults={r[0]:(i,r) for i,r in enumerate(md.records(16,'<iii'))}
    sys.path.insert(0,str(HERE.parent/'assets'))
    from inspect_player import compressed_int32
    result['enum_values']=[]
    for fid,name,value in [(11229,'SkillType.TimeStop',17),(11233,'SkillType.Exhibitionism',21),(11234,'SkillType.Sex',22),(14120,'RingItemType.TimeStop',10)]:
        idx,(field_id,type_index,data_index)=defaults[fid];v=compressed_int32(raw,md.header[18]+data_index)
        assert field_id==fid and md.string(fields[fid][0])==name.split('.')[-1] and v['decoded_int32']==value
        off=md.header[16]+idx*12;fo=md.header[24]+fid*12
        result['enum_values'].append({'name':name,'field_id':fid,'value':value,'field_file_offset':fo,'field_raw_hex':raw[fo:fo+12].hex(),
          'default_file_offset':off,'default_raw_hex':raw[off:off+12].hex(),**v})
    assets=HERE.parent/'assets/animator-wiring.json';wiring=read(assets);player=next(c for c in wiring['controllers'] if c['name']=='Player')
    machine=player['graph']['machines'][7];state=next(s for s in machine['states'] if s['name']=='SwitchTimeStop')
    result['player_controller_dependency']={'path':assets.relative_to(HERE.parent).as_posix(),'sha256':hashlib.sha256(assets.read_bytes()).hexdigest()}
    result['player_switch_state']={'layer':player['graph']['layers'][7],'state':state,
      'incoming_any_state':[t for t in machine['any_state_transitions'] if t.get('m_DestinationState')==state['index']],
      'clip':player['clips'][179]}
    result['candidate_adjudication']=[
      {'va':'0x1804942b0','method_id':16825,'classification':'false-positive: MentalManager.IsRedBlinkGauge clear, not TemporaryInGameState'},
      {'va':'0x1804960af','method_id':None,'classification':'false-positive: InGameManager.Start cold fragment allocates StatisticsManager at owner+a0; broadcasts other Events'},
      {'va':'0x1804985b0','method_id':16864,'classification':'false-positive: owner+a0 StatisticsManager and GameOverEvent, no TimeStopEvent field load'},
      {'va':'0x180498af0','method_id':16868,'classification':'false-positive: MentalManager.IsRedBlinkGauge clear'},
      {'va':'0x1804b5fc0','method_id':17335,'classification':'Events static initialization, not an event dispatch producer'},
      {'va':'0x18052a150','method_id':18609,'classification':'false-positive: Events+200 (0xc8), not TimeStop field0xa0'},
      {'va':'0x18052a360','method_id':18612,'classification':'false-positive: Events+0xd8'},
      {'va':'0x180627fc0','method_id':14471,'classification':'false-positive: Events+0x80'},
      {'va':'0x1806293bf','method_id':14479,'classification':'OnChangeTimeStop cold fragment loads Events.TimeStopEvent+0xa0 after toggling flag'}]
    assert {r['va'] for r in result['candidate_adjudication']}=={r['begin'] for r in scan['scan']['candidates']}
    result['findings']=[
      {'claim':'InputResolver ring shortcut10 -> JustTimeStop -> PlayerAction CurrentAction.Id!=7, CanUseHand and skill17 -> ChangeAction7 -> TransAction -> original clip event -> OnChangeTimeStop',
       'kind':'static selected natural entry chain','methods':[14421,14462,14463,14536,14479]},
      {'claim':'OnChangeTimeStop checks NpcManager.IsMaxStrangeSomeOne; if true requires skill21 Exhibitionism or22 Sex; then flips Temp.IsTimeStop before broadcasting Events.TimeStopEvent',
       'kind':'static observed native body','methods':[14479]},
      {'claim':'AddListener checks s_EventLookups for equal delegate and returns when present, before head/tail combine; isHead is not an immediate callback option',
       'kind':'static native shared generic body, runtime equality corroboration','va':'0x180993250'},
      {'claim':'NpcController.Initialize registers original target/method delegate; Destroy calls Accessor.Dispose then removes the delegate using shared0x180993960',
       'kind':'static observed selected lifecycle','methods':[15518,15532,15490],'remove_va':'0x180993960'},
      {'claim':'No second natural TimeStop producer identified within the explicit RIP-slot/field-displacement candidate scan. This is not a complete pointer/data-flow or full gameplay proof.',
       'kind':'bounded negative search','dependency':'salt/symbols/time-stop-xrefs.json'}]
    result['limitations'].append('No full natural gameplay session. Runtime controls are separately retained; forced animation triggers and injected extra broadcasts/resets are not natural input observations.')
    return result


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--check',action='store_true');args=p.parse_args()
    result=build(); path=HERE/'evidence/time-stop-chain.json'
    if args.check:assert result==read(path),'Saved TimeStop chain differs'
    else:path.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({'new':result['new_observations'],'methods':len(result['methods']),'candidates':len(result['candidate_adjudication'])}))


if __name__=='__main__':main()
