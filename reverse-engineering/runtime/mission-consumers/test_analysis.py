"""Reject false positives in mission progress, repeated reward and settlement claims."""
import copy,unittest
from analyze import HERE,read,rows,analyze
class MissionEvidenceTests(unittest.TestCase):
 def setUp(self):
  self.managed=rows(HERE/'managed.jsonl.gz');b=read(HERE/'rea-runtime.json');self.events=[m['payload'] for r in b['records'] if r['operation']=='frida_session_status' for m in r['normalized_result']['messages']];self.files=read(HERE/'saved-files.json')['files']
 def check(self):return analyze(self.managed,self.events,self.files)
 def test_retained_evidence(self):self.assertEqual(self.check()['settlement']['wallet_after'],16)
 def test_paused_reward(self):
  start=next(i for i,r in enumerate(self.managed) if r['kind']=='command' and r['data']['action']=='case paused');next(r for r in self.managed[start:] if r['kind']=='update1')['data']['pendingRp']=8
  with self.assertRaises(ValueError):self.check()
 def test_missing_achievement_producer(self):
  self.events=[e for e in self.events if e['kind']!='mission_achieve']
  with self.assertRaises(ValueError):self.check()
 def test_no_masking_warm_completion_reset(self):
  next(r for r in self.managed if r['kind']=='reinitialized')['data']['done']=True
  with self.assertRaises(ValueError):self.check()
 def test_missing_one_time_reward(self):
  self.events.remove(next(e for e in self.events if e['kind']=='mission_reward' and e['data']['caller']=='0x479178'))
  with self.assertRaises(ValueError):self.check()
 def test_incorrect_saved_progress(self):
  next(f for f in self.files if f['path'].endswith('near-complete-after.sd'))['progress']=.9999
  with self.assertRaises(ValueError):self.check()
 def test_fractional_wallet_is_not_settled_integer(self):
  next(r for r in self.managed if r['kind']=='settlement_after')['data']['rp']=16.007
  with self.assertRaises(ValueError):self.check()
 def test_controlled_condition_must_stay_explicit(self):
  next(r for r in self.managed if r['kind']=='controlled_condition')['data']['originalRequired']='0'
  with self.assertRaises(ValueError):self.check()
if __name__=='__main__':unittest.main()
