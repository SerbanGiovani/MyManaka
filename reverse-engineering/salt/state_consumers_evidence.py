"""Bind item UI/effect, skill and mission consumer observations to shipped metadata."""
import argparse,hashlib,json
from pathlib import Path
from metadata import HERE
from scene_evidence import build as bind,read

def build():
 r=bind(batch_prefix='state-consumers',reuse_method_ids={14462,14463,14479,16750,16754,16970,16971},extra_type_names=('GameStateData','MItemRecord','MSkillRecord','InputData','PlayerStateModel','MActionRecord','MRankRecord','InventoryItemView','InventoryPanelView'),dispatch_targets=[],resource_boundary='Controlled inventory callback and skill-input consumers; mission queries are static preparation only in this batch.')
 assert r['new_observations']==r['new_unique_procedure_addresses']==r['new_unique_evidence_ids']==19
 fields={t['name'].split('.')[-1]:{f['name']:f for f in t['fields']} for t in r['named_types']}
 assert fields['MItemRecord']['IsReusable']['offset']==0x28 and fields['MItemRecord']['IsDelayConsume']['offset']==0x2a
 assert fields['InputData']['JustTimeStop']['offset']==0x36
 assert fields['GameStateData']['ExposeExp']['offset']==0x1e8 and fields['GameStateData']['ItemDict']['offset']==0x218
 r['consumer_findings']=dict(inventory_button=17925,inventory_use_closure=18007,item_effect=16071,item_count=16794,skill_learn_ui=17530,skill_level=16755,skill_activation=16751,skill_input=14462,skill_action=14463,time_stop_event=14479,
  closure_decrements_only_when_not_reusable_and_not_delay_consume=True,
  water_decrements_inside_effect=True,selected_exp_debug_items_are_reusable=True,
  skill_level_helper_does_not_charge_rp=True,skill_item_view_charges_rp_before_level_increment=True,
  scope='Callback invocation is controlled, including an inactive item UI view; no natural click, rank unlock, shop acquisition, UI learning, or mission runtime completion claimed.')
 r.setdefault('sources',[]).append(dict(path='salt/state_consumers_evidence.py',sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest()))
 return r
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');a=p.parse_args();r=build();path=HERE/'evidence/state-consumers-chain.json'
 if a.check:assert r==read(path)
 else:path.write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
 print(json.dumps(dict(new_queries=19)))
