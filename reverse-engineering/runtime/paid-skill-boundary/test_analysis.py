"""Counterexamples keep actual UI consumers separate from dictionary assignments."""
import copy,unittest
from analyze import HERE,STATUS_ID,read,rows,analyze
class PaidEvidenceTests(unittest.TestCase):
 def setUp(self):
  self.managed=rows(HERE/'managed.jsonl.gz');self.events=[m['payload'] for r in read(HERE/'rea-runtime.json')['records'] if r['evidence_id']==STATUS_ID for m in r['normalized_result']['messages']];self.files=read(HERE/'saved-files.json')['files'];self.assets=read(HERE/'asset-tiers.json')
 def check(self):return analyze(self.managed,self.events,self.files,self.assets)
 def data(self,name,kind):return next(r['data']['data'] for r in self.managed if r['kind']==kind and r['data'].get('name')==name)
 def test_formal_retained_run(self):self.assertEqual(len(self.check()['cases']),7)
 def test_missing_native_consume_rejected(self):
  self.events.remove(next(e for e in self.events if e['kind']=='consume_rp'))
  with self.assertRaises(ValueError):self.check()
 def test_reordered_native_purchase_rejected(self):
  i=next(i for i,e in enumerate(self.events) if e['kind']=='consume_rp');self.events[i],self.events[i+1]=self.events[i+1],self.events[i]
  with self.assertRaises(ValueError):self.check()
 def test_wrong_native_price_rejected(self):
  next(e for e in self.events if e['kind']=='consume_rp')['data']['arg0']='0xa'
  with self.assertRaises(ValueError):self.check()
 def test_wrong_native_slow_receiver_rejected(self):
  next(e for e in self.events if e['kind']=='paid_button' and e['data']['name']=='prerequisite' and int(e['data']['arg0'],16)==int(self.data('prerequisite','slow_before')['pointer']))['data']['arg0']='0x1'
  with self.assertRaises(ValueError):self.check()
 def test_wrong_passive_argument_rejected(self):
  next(e for e in self.events if e['kind']=='change_passive' and e['data']['name']=='passive-absent')['data']['arg1']='0x0'
  with self.assertRaises(ValueError):self.check()
 def test_saved_phase_not_inferred_from_total_counts(self):
  next(e for e in self.events if e['kind']=='native_load')['frame']+=1
  with self.assertRaises(ValueError):self.check()
 def test_exact_rp_gate_rejected_if_spend_wrong(self):
  self.data('rp-exact','post_use')['rp']=1
  with self.assertRaises(ValueError):self.check()
 def test_denied_button_cannot_change_level(self):
  self.data('rank-locked','clicked')['snapshot']['skills'][-1]['level']=1
  with self.assertRaises(ValueError):self.check()
 def test_maximum_is_not_unlock_mask(self):
  self.data('max','view_before')['masked']=True
  with self.assertRaises(ValueError):self.check()
 def test_static_generic_init_price_is_not_tier_price(self):
  self.data('rp-low','view_before')['price']=10
  with self.assertRaises(ValueError):self.check()
 def test_same_auto_item_refresh_required(self):
  self.data('prerequisite','slow_bought')['auto']['pointer']='1'
  with self.assertRaises(ValueError):self.check()
 def test_auto_prerequisite_mask_must_clear(self):
  self.data('prerequisite','slow_bought')['auto']['masked']=True
  with self.assertRaises(ValueError):self.check()
 def test_capacity_requires_runtime_consumer(self):
  self.data('rp-exact','capacity_ui')['text']='1/5'
  with self.assertRaises(ValueError):self.check()
 def test_non_toggle_effective_false_is_allowed(self):
  result=self.check();self.assertFalse(next(r for r in result['cases'] if r['name']=='rp-exact')['passive_effective']);self.assertEqual(next(r for r in result['cases'] if r['name']=='rp-exact')['capacity'],10)
 def test_existing_false_must_not_autoenable(self):
  self.data('passive-false','post_use')['skills'][1]['stored']=True
  with self.assertRaises(ValueError):self.check()
 def test_dictionary_presence_is_not_false_value(self):
  next(f for f in self.files if f['path'].endswith('passive-false-before.sd'))['passive']=[]
  with self.assertRaises(ValueError):self.check()
 def test_actual_buff_must_follow_switch(self):
  self.data('passive-absent','toggle_on')['npcDirectBuff']['active']=False
  with self.assertRaises(ValueError):self.check()
 def test_unselected_serialized_skill_cannot_change(self):
  next(s for f in self.files if f['path'].endswith('rp-exact-after.sd') for s in f['skills'] if s['id']==5)['level']=1
  with self.assertRaises(ValueError):self.check()
 def test_load_must_replace_global_root(self):
  self.data('max','loaded')['state']=self.data('max','disturbed')['state']
  with self.assertRaises(ValueError):self.check()
 def test_load_must_restore_runtime_buff(self):
  self.data('passive-false','loaded')['npcDirectBuff']['active']=True
  with self.assertRaises(ValueError):self.check()
 def test_illegal_disturbance_key_rejected(self):
  self.data('rp-low','disturbed')['skills'][1]['present']=False
  with self.assertRaises(ValueError):self.check()
 def test_init_switch_event_not_miscounted_as_manual(self):
  next(e for e in self.events if e['kind']=='toggle_callback' and e['data']['caller']=='0xb8d8be')['data']['caller']='0x35bd19'
  with self.assertRaises(ValueError):self.check()
 def test_failed_setup_cannot_be_merged_into_formal(self):
  self.managed.append(dict(kind='runner_error',data=dict(error='diagnostic')))
  with self.assertRaises(ValueError):self.check()
 def test_cleanup_rank_required(self):
  next(r for r in self.managed if r['kind']=='cleanup')['data']['rankRestored']=False
  with self.assertRaises(ValueError):self.check()
if __name__=='__main__':unittest.main()
