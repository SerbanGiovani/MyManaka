"""Bind the real elevator singleton and fixed/absent snapshot/restore guards."""
import argparse
import hashlib
import json
from pathlib import Path
from metadata import HERE
from scene_evidence import build as bind,read

def build():
    r=bind(batch_prefix='npc-restore-filter',reuse_method_ids={15583,15598,15605,15587,16970,16971,17301},
        extra_type_names=('NpcManager','NpcStateModel','NpcController','NpcComponentAccessor','ElevatorController','NpcSaveData'),
        dispatch_targets=[],resource_boundary='Explicit controlled NPC snapshot and native restore exclusions. Natural guard reachability remains separate.')
    assert r['new_observations']==r['new_unique_procedure_addresses']==r['new_unique_evidence_ids']==3
    usage=next(u for u in r['usages'] if u['va']=='0x182d59260')
    assert usage['type_name']=='ExposureUnnoticed2.Object3D.ScenePlops.Elevator.ElevatorController'
    fields={t['name'].split('.')[-1]:{f['name']:f for f in t['fields']} for t in r['named_types']}
    assert fields['ElevatorController']['<PushBounds>k__BackingField']['offset']==0x5c
    assert fields['NpcStateModel']['CurrentFixedType']['offset']==0x58
    assert fields['NpcSaveData']['IsExist']['offset']==0x2c
    r['filter_coordinates']=dict(elevator_singleton_helper='0x180436630',elevator_type_usage=usage,
        restore_method_id=15583,snapshot_method_id=15598,callback_method_id=15605,scheduler_method_id=17301,
        producer_fixed_count_offset=0x68,loaded_guard_offset=0x65,
        conditions=['ApplyGameState returns when loaded=false','dynamic snapshot count = live count - fixed count',
            'unused high-water records get IsExist=false','OnLoadData skips IsExist=false before Bounds/scheduling',
            'existing live elevator PushBounds containing saved Position skips scheduling',
            'eligible records queue the original per-record closure'],
        limitations=['The helper name is an analyst label; its recovered body reads the bound ElevatorController static singleton.','Static branch evidence is separate from the controlled runtime fixture.','No natural force=false or complete game-state equivalence is claimed.'])
    r.setdefault('sources',[]).append(dict(path='salt/npc_restore_filter_evidence.py',sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest()))
    return r

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');a=p.parse_args();r=build();path=HERE/'evidence/npc-restore-filter-chain.json'
    if a.check:assert r==read(path)
    else:path.write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(new_queries=3)))
