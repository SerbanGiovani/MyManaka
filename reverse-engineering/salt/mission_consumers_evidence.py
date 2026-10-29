"""Bind mission initialization, reward, lifecycle and UI consumption to original bytes."""
import argparse,hashlib,json
from pathlib import Path
from metadata import HERE
from scene_evidence import build as bind,read

def build():
 r=bind(batch_prefix='mission-consumers',reuse_method_ids={16488,16491,16585,16802,16803,16970,16971},extra_type_names=('MissionBase','MissionManager','MMissionOverrideRecord','MMissionRecord','NpcRouteAreaManager','TemporaryInGameState'),dispatch_targets=[],resource_boundary='Selected controlled mission initialization/update and warm reload boundaries; no natural scene completion claim.')
 assert r['new_observations']==r['new_unique_procedure_addresses']==r['new_unique_evidence_ids']==14
 fields={t['name'].split('.')[-1]:{f['name']:f for f in t['fields']} for t in r['named_types']}
 assert fields['MissionBase']['satisfy']['offset']==0x30 and fields['MissionBase']['RMission']['offset']==0x28
 r['consumer_findings']=dict(mission_key='StageType * 10000 + master record id',progress_field_offset=0x30,completion_flag_offset=0x3d,one_time_caller_rva='0x479178',per_second_caller_rva='0x4794f2',earn_helper_rva='0x48eac0',settlement_achievement_caller_rva='0x4c7977',scope='Cloned condition and temporary stage/stop coordination; repeated one-time reward is a controlled warm reconstruction boundary, not a proven natural duplicate.')
 r.setdefault('sources',[]).append(dict(path='salt/mission_consumers_evidence.py',sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest()))
 return r
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');a=p.parse_args();r=build();path=HERE/'evidence/mission-consumers-chain.json'
 if a.check:assert r==read(path)
 else:path.write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
 print(json.dumps(dict(new_queries=14)))
