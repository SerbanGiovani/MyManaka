"""Bind default NPC snapshot/repopulation guards and the bounded byte scan."""
import argparse
import hashlib
import json
from pathlib import Path
from metadata import HERE,DEFAULT_ROOT,PE
from scene_evidence import build as bind,read


def build():
    result=bind(batch_prefix='natural-load-',reuse_method_ids={15580,15582,15583,15585,15587,15598,16466,16823,16825,16862,16868,16970,16971,17853,17861},
        extra_type_names=('DebugController','NpcManager','GameState','GameStateData','SaveManager','SaveRapper','NpcSaveData','Events','StageTransController'),dispatch_targets=[],
        resource_boundary='Selected static natural-load guard and save paths. Runtime/source-fixture boundaries are in runtime/natural-load/.')
    new=[m for m in result['methods'] if m['new_this_round']]
    assert len(new)==result['new_unique_procedure_addresses']==result['new_unique_evidence_ids']==10
    scan_path=HERE.parent/'runtime/natural-load/guard-scan.json';scan=read(scan_path)
    native=(DEFAULT_ROOT/'GameAssembly.dll').read_bytes();pe=PE(native)
    assert hashlib.sha256(native).hexdigest()==result['native_sha256']==scan['native']['sha256']
    fields={t['name'].split('.')[-1]:{f['name']:f for f in t['fields']} for t in result['named_types']}
    assert fields['DebugController']['IsForceCreateNpc']['offset']==11
    assert fields['DebugController']['IsDebug']['offset']==0 and fields['NpcManager']['isLoadedData']['offset']==0x65
    assert scan['scan']['unwind_ranges']==139898 and scan['scan']['instructions']==8534275
    assert len(scan['methods'])==46 and len(scan['npc_ranges'])==32
    force=[r for r in scan['scan']['debugCandidates'] if r['fieldB']]
    assert [(r['begin'],len(r['fieldB'])) for r in force]==[('0x1804879f0',1),('0x180498af0',1)]
    assert len(scan['scan']['npcWrites'])==1 and scan['scan']['npcWrites'][0]['begin']=='0x18042f310'
    assert scan['scan']['restoreDirectBranches']==['0x180498b95 call 000000018042F310h']
    anchors=[]
    for address,raw,role in [(0x180487a49,'c6410b01','default force=true'),(0x180498b80,'80780b00','startup compares force with false'),(0x180498b95,'e87667f9ff','direct conditional OnLoadData call'),(0x18042f3ea,'41c6466501','OnLoadData sets isLoadedData=true')]:
        pos=pe.offset(address,len(bytes.fromhex(raw)),executable=True)
        assert native[pos:pos+len(bytes.fromhex(raw))]==bytes.fromhex(raw)
        anchors.append(dict(va=hex(address),file_offset=pos,raw_hex=raw,role=role))
    result['guard_findings']=dict(force_default=True,is_debug_default=False,startup_callback_method_id=16868,
        snapshot_eligibility_writer_method_id=15583,snapshot_guard_method_id=15598,
        conditional_requirements=['force flag false at the startup callback','original OnLoadData runs and sets manager.isLoadedData','later snapshot producer sees eligible dynamic live NPCs','restored records survive IsExist and elevator Bounds filters'],
        natural_positive_test_for_force_false=False,raw_anchors=anchors,
        scan=dict(path='runtime/natural-load/guard-scan.json',sha256=hashlib.sha256(scan_path.read_bytes()).hexdigest(),runtime_function_fragments=139898,instructions=8534275,debug_slot_fragments=25,npc_declarations=46,npc_fragments=32),
        limitation='Direct branch and same-fragment candidates only; wider stores, indirect aliasing, reflection, external code and arbitrary modifications are not excluded.')
    result.setdefault('sources',[]).append(dict(path='salt/natural_load_evidence.py',sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest()))
    return result


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--check',action='store_true');a=p.parse_args();result=build();path=HERE/'evidence/natural-load-chain.json'
    if a.check:assert result==read(path),'Natural load bindings differ'
    else:path.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(new_queries=10,guard_anchors=len(result['guard_findings']['raw_anchors']))))
