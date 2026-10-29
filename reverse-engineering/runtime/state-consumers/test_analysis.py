"""Counterexamples protect against falsely declaring consumer restoration complete."""
import copy,unittest
from analyze import HERE,read,rows,analyze
class ConsumerEvidenceTests(unittest.TestCase):
 def setUp(self):
  self.managed=rows(HERE/'managed.jsonl.gz');b=read(HERE/'rea-runtime.json');self.events=[m['payload'] for r in b['records'] if r['operation']=='frida_session_status' for m in r['normalized_result']['messages']];self.files=read(HERE/'saved-files.json')['files']
 def check(self):return analyze(self.managed,self.events,self.files)
 def test_retained_evidence(self):self.assertEqual(len(self.check()['inventory']),3)
 def test_missing_water_decrement(self):
  self.events=[e for e in self.events if e['kind']!='item_change']
  with self.assertRaises(ValueError):self.check()
 def test_duplicate_water_decrement(self):
  self.events.append(copy.deepcopy(next(e for e in self.events if e['kind']=='item_change')))
  with self.assertRaises(ValueError):self.check()
 def test_falsified_file(self):
  next(f for f in self.files if f['path'].endswith('inventory-0-after.sd'))['items']['0']=2
  with self.assertRaises(ValueError):self.check()
 def test_extra_animation_event(self):
  self.events.append(copy.deepcopy(next(e for e in self.events if e['kind']=='time_stop_event')))
  with self.assertRaises(ValueError):self.check()
 def test_inactive_view_must_remain_disclosed(self):
  next(r for r in self.managed if r['kind']=='selected_ui')['data']['active']=True
  with self.assertRaises(ValueError):self.check()
 def test_disabled_skill_does_not_activate(self):
  r=next(r for r in self.managed if r['kind']=='result' and r['data']['name']=='skill-disabled');r['data']['snapshot']['timeStop']=True
  with self.assertRaises(ValueError):self.check()
if __name__=='__main__':unittest.main()
