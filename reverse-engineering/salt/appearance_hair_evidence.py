"""Bind hair switching/default initialization and actual customization consumers."""
import argparse,hashlib,json
from pathlib import Path
from metadata import HERE
from scene_evidence import build as bind,read
def build():
    r=bind(batch_prefix='appearance-hair',reuse_method_ids={15075,14769,16970,16971},extra_type_names=('PlayerCustomData','PlayerHairController','HairCustomAdjuster','HairCustomizeData','MHairRecord','HairType'),dispatch_targets=[],resource_boundary='Selected native hair initialization, switching, texture/color consumers and controlled warm graph restoration.')
    assert r['new_observations']==r['new_unique_procedure_addresses']==r['new_unique_evidence_ids']==5
    fields={t['name'].split('.')[-1]:{f['name']:f for f in t['fields']} for t in r['named_types']}
    assert fields['PlayerCustomData']['CurrentHair']['offset']==0x104 and fields['PlayerCustomData']['HairCustomizeDataDict']['offset']==0x118
    assert fields['HairCustomAdjuster']['targetMaterial']['offset']==0x40
    assert fields['HairCustomizeData']['R']['offset']==0x18 and fields['HairCustomizeData']['ShadeColor']['offset']==0x24
    r['hair_findings']=dict(initialize_method_id=14858,change_method_id=14859,facade_method_id=14818,initialize_material_method_id=15074,apply_material_method_id=15075,ui_method_id=18703,
        default_hair_zero_initialize_returns=True,change_hair_uses_saved_current_to_disable_previous=True,
        default_initialize_requires_default_prefab_already_active=True,
        boundary='The default early return is a cold-init assumption. Direct warm Load/Initialize is controlled replay, not evidence of a natural title-load defect.')
    r.setdefault('sources',[]).append(dict(path='salt/appearance_hair_evidence.py',sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest()))
    return r
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');a=p.parse_args();r=build();path=HERE/'evidence/appearance-hair-chain.json'
    if a.check:assert r==read(path)
    else:path.write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(new_queries=5)))
