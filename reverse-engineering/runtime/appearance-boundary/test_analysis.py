"""Counterexamples distinguish restored data, renderer application and object identities."""
import copy,unittest
from analyze import HERE,read,rows,analyze
class PaintEvidenceTests(unittest.TestCase):
 def setUp(self):
  self.managed=rows(HERE/'managed.jsonl.gz');b=read(HERE/'rea-runtime.json');self.events=[m['payload'] for r in b['records'] if r['operation']=='frida_session_status' for m in r['normalized_result']['messages']];self.files=read(HERE/'saved-files.json')['files']
 def check(self):return analyze(self.managed,self.events,self.files)
 def case(self,name,kind):return next(r['data']['snapshot'] for r in self.managed if r['kind']==kind and r['data']['name']==name)
 def test_retained_run(self):self.assertEqual([r['restored_slots'] for r in self.check()['cases']],[4,3,4])
 def test_missing_receiver(self):
  self.events.remove(next(e for e in self.events if e['kind']=='body_material_event' and e['data']['name']=='tattoo/restore'))
  with self.assertRaises(ValueError):self.check()
 def test_duplicate_receiver(self):
  self.events.append(copy.deepcopy(next(e for e in self.events if e['kind']=='body_material_event')))
  with self.assertRaises(ValueError):self.check()
 def test_nested_entry_order_checked(self):
  a=next(i for i,e in enumerate(self.events) if e['kind']=='body_material_event');b=a+1
  self.events[a],self.events[b]=self.events[b],self.events[a]
  with self.assertRaises(ValueError):self.check()
 def test_entry_must_be_in_original_callback_frame(self):
  next(e for e in self.events if e['kind']=='body_apply_options')['frame']+=1
  with self.assertRaises(ValueError):self.check()
 def test_load_must_not_be_credited_with_application(self):
  self.case('tattoo','loaded_without_application')['materials'][1]['matCap']=[0,0,0,1]
  with self.assertRaises(ValueError):self.check()
 def test_saved_map_must_match_native_map(self):
  next(f for f in self.files if f['path'].endswith('combined.sd'))['map'][8]['value']=False
  with self.assertRaises(ValueError):self.check()
 def test_shader_and_texture_must_be_restored(self):
  self.case('oil','result')['materials'][0]['shader']='1'
  with self.assertRaises(ValueError):self.check()
 def test_skin_alpha_cannot_change(self):
  self.case('combined','result')['materials'][1]['baseColor'][3]=1
  with self.assertRaises(ValueError):self.check()
 def test_new_runtime_material_identity_is_allowed(self):
  s=self.case('combined','result');s['sweat']='999999';s['materials'][-1]['pointer']='999999';s['materials'][2]['pointer']='888888'
  self.assertEqual(len(self.check()['cases']),3)
 def test_oil_cannot_append_a_slot(self):
  self.case('oil','result')['materials'].append(copy.deepcopy(self.case('oil','result')['materials'][-1]))
  with self.assertRaises(ValueError):self.check()
 def test_original_shared_properties_cleanup_checked(self):
  next(r for r in self.managed if r['kind']=='cleanup')['data']['restored']['materials'][0]['baseColor'][0]=.5
  with self.assertRaises(ValueError):self.check()
 def test_immediate_sweat_parameter_phase_checked(self):
  self.case('oil','restore_immediate')['materials'][-1]['tweak']=-1
  with self.assertRaises(ValueError):self.check()
 def test_timed_paint_is_outside_scope(self):
  self.case('oil','result')['remaining']=120
  with self.assertRaises(ValueError):self.check()
if __name__=='__main__':unittest.main()
