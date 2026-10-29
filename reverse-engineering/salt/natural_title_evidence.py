"""Bind original PC main-save, title path and explicit backup flag handling."""
import argparse
import hashlib
import json
from pathlib import Path
from metadata import HERE
from scene_evidence import build as bind,read

def build():
    result=bind(batch_prefix='natural-title-',reuse_method_ids={16967,16970,16971,17406,17407,17594,17861,17865,16690,16693,16868,15583,15587},
        extra_type_names=('DebugController','NpcManager','GameState','GameStateData','SaveManager','SaveRapper'),dispatch_targets=[],
        resource_boundary='Selected original main-save/title/backup flag paths. Natural runtime round is recorded separately in runtime/natural-title/.')
    assert result['new_observations']==result['new_unique_procedure_addresses']==result['new_unique_evidence_ids']==2
    fields={t['name'].split('.')[-1]:{f['name']:f for f in t['fields']} for t in result['named_types']}
    methods={m['method_id']:m for m in result['methods']}
    assert [p['name'] for p in methods[17409]['signature']['parameters']]==['isSystem','slot','isBackUp']
    assert methods[16970]['signature']['parameters'][2]['name']=='isBackup'
    result['path_findings']=dict(pc_manual_save_method_id=17594,save_method_id=16970,preprocess_method_id=17409,
        title_slot_method_id=17861,load_method_id=16971,specified_path_method_id=17407,
        isBackup_static_field_candidates=[f for f in fields['SaveRapper'].values() if f['offset']==4 and f['is_static']],
        pc_arguments=dict(type=3,slot=-1,isBackup=False),title_load_arguments=dict(type=3,slot=1),
        title_main_read_preprocess_backup=False,backup_recovery_observed=False,
        limitation='Selected methods and UI path do not establish global absence of a backup-recovery command.')
    assert len(result['path_findings']['isBackup_static_field_candidates'])==1
    result.setdefault('sources',[]).append(dict(path='salt/natural_title_evidence.py',sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest()))
    return result

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');a=p.parse_args();r=build();path=HERE/'evidence/natural-title-chain.json'
    if a.check:assert r==read(path)
    else:path.write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(new_queries=r['new_observations'])))
