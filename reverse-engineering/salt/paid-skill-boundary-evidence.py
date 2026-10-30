"""Bind paid-learning UI/consumer static queries; no runtime success claim."""
import argparse,hashlib,json
from pathlib import Path
from metadata import HERE
from scene_evidence import build as bind,read

def build():
 r=bind(batch_prefix='paid-skill-boundary',reuse_method_ids={17524,17530,17878,16755,16760,16751,16970,16971},extra_type_names=('SkillItemView','SkillPanelView','SkillSwitchItemView','SkillSwitchPanelView','MSkillRecord','RSkillMaxAccessoryNum','RSkillSlow','PlayerRpBonusCalculator','BuffModel'),dispatch_targets=[],resource_boundary='Static real skill UI, prices, unlock/max/RP guards and selected capacity/passive consumers. Prepared probe is compile-only; no runtime verification.')
 assert r['new_observations']==r['new_unique_procedure_addresses']==r['new_unique_evidence_ids']==9
 fields={t['name'].split('.')[-1]:{f['name']:f for f in t['fields']} for t in r['named_types']}
 assert fields['SkillItemView']['necessaryRp']['offset']==0x78 and fields['SkillItemView']['isSomeMask']['offset']==0x98 and fields['SkillItemView']['isLearned']['offset']==0x99
 assert fields['RSkillMaxAccessoryNum']['MaxNum']['offset']==0x1c and fields['RSkillMaxAccessoryNum']['NextLevelUpRp']['offset']==0x20
 r['findings']=dict(skill_panel_open=17881,real_item_initialize=17524,unlock_refresh=17527,price_and_max_refresh=17528,paid_entry=17530,parent_paid_callback=17878,toggle=17641,capacity_consumer=17985,passive_bonus_consumer=14936,rp_guard=16759,multilevel_prices_override_base_formula=True,max_flag_means_level_at_least_max=True,passive_autoenable_only_when_key_absent=True,prepared_probe_executed=False)
 for path in [HERE/'paid-skill-boundary-evidence.py',HERE.parent/'paid-skill-boundary-metadata.json',HERE.parent/'paid-skill-boundary-assets.py',HERE.parent/'paid-skill-boundary-assets.json']:
  r.setdefault('sources',[]).append(dict(path=path.relative_to(HERE.parent).as_posix(),sha256=hashlib.sha256(path.read_bytes()).hexdigest()))
 return r
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');a=p.parse_args();r=build();path=HERE/'evidence/paid-skill-boundary-chain.json'
 if a.check:assert r==read(path)
 else:path.write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
 print(json.dumps(dict(new_queries=9,runtime_verified=False)))
