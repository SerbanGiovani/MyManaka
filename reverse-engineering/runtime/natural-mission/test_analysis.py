"""Counterexamples preserve natural-source boundaries and known native capture gaps."""
import unittest
from analyze import HERE,read,rows,canonical_rounds,analyze
class NaturalMissionTests(unittest.TestCase):
 def setUp(self):self.managed=rows(HERE/'managed.jsonl.gz');self.paths=rows(HERE/'paths.jsonl.gz');self.rounds=canonical_rounds(read(HERE/'rea-runtime.json'));self.files=read(HERE/'saved-files.json')['files']
 def check(self):return analyze(self.managed,self.paths,self.rounds,self.files)
 def test_real_trace(self):self.assertEqual(self.check()['first_round']['achieved_after'],1)
 def test_round1_errors_cannot_be_hidden(self):
  self.rounds[0]['errors']=[]
  with self.assertRaises(ValueError):self.check()
 def test_duplicate_round_errors_not_twenty(self):
  self.rounds[0]['errors']*=2
  with self.assertRaises(ValueError):self.check()
 def test_second_round_not_always_unmet(self):
  ev=[e for e in self.rounds[1]['events'] if e['kind']=='stage_transition_enter'][-1];ev['data']['state']['target']['progress']=0
  with self.assertRaises(ValueError):self.check()
 def test_no_second_achievement(self):
  self.rounds[1]['events'].append(dict(kind='mission_achieve_enter',data={}))
  with self.assertRaises(ValueError):self.check()
 def test_no_manager_recreation(self):
  next(s for s in self.managed if s['kind']=='snapshot' and s['data']['player'] is not None)['data']['missionManager']='1'
  with self.assertRaises(ValueError):self.check()
 def test_saved_count_matches_runtime(self):
  next(f for f in self.files if f['name']=='0008-SaveData-1.sd')['target']['achieved']=2
  with self.assertRaises(ValueError):self.check()
 def test_complete_system_projection(self):
  next(f for f in self.files if f['kind']=='system')['roots'].pop()
  with self.assertRaises(ValueError):self.check()
 def test_second_pc_return_required(self):
  self.rounds[1]['events']=[e for e in self.rounds[1]['events'] if e['kind']!='pc_save_leave']
  with self.assertRaises(ValueError):self.check()
 def test_system_root_name_cannot_be_replaced(self):
  next(f for f in self.files if f['kind']=='system')['roots'][0]['key']='WrongRoot'
  with self.assertRaises(ValueError):self.check()
 def test_loaded_script_source_required(self):
  bundle=read(HERE/'rea-runtime.json');bundle['records'][0]['normalized_result']['source_sha256']='0'*64
  with self.assertRaises(ValueError):canonical_rounds(bundle)
 def test_native_session_identity_required(self):
  bundle=read(HERE/'rea-runtime.json');bundle['records'][1]['normalized_result']['session_id']='wrong-session'
  with self.assertRaises(ValueError):canonical_rounds(bundle)
 def test_system_field_projection_matches_count(self):
  root=next(r for f in self.files if f['kind']=='system' for r in f['roots'] if r['key']=='OptionData');root['fields'].pop(next(iter(root['fields'])))
  with self.assertRaises(ValueError):self.check()
 def test_second_front_sample_is_required(self):
  for s in self.managed:
   if s['kind']=='snapshot' and s['real']>=self.rounds[1]['events'][0]['real']:s['data']['exposed']='None'
  with self.assertRaises(ValueError):self.check()
 def test_second_stage_route_is_required(self):
  event=next(e for e in self.rounds[1]['events'] if e['kind']=='stage_transition_enter');event['data']['arg1'],event['data']['arg2']=event['data']['arg2'],event['data']['arg1']
  with self.assertRaises(ValueError):self.check()
if __name__=='__main__':unittest.main()
