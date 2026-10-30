"""Counterexamples must not turn field restoration into a visual-application claim."""
import unittest
from analyze import HERE,IDS,read,rows,analyze
class SkinPresetTests(unittest.TestCase):
 def setUp(self):
  self.managed=rows(HERE/'managed.jsonl.gz');bundle=read(HERE/'rea-runtime.json');self.events=[m['payload'] for r in bundle['records'] if r['evidence_id']==IDS[1] for m in r['normalized_result']['messages']];saved=read(HERE/'saved-files.json');self.files=saved['files'];self.baseline=saved['baseline']
 def run_analysis(self):return analyze(self.managed,self.events,self.files,self.baseline)
 def record(self,kind,name='preset-0'):return next(r for r in self.managed if r['kind']==kind and r['data'].get('name')==name)
 def reject(self):
  with self.assertRaises(ValueError):self.run_analysis()
 def test_real_trace(self):self.assertEqual(self.run_analysis()['body_callback_sequences'],7)
 def test_saved_false_branch_required(self):self.files[0]['fields']['CustomIsSkinColorFree']=True;self.reject()
 def test_both_indices_required(self):self.files[1]['fields']['CustomizeSkinColor']=0;self.reject()
 def test_saved_rgb_is_preserved(self):self.files[0]['fields']['CustomizeSkinColorG']=203;self.reject()
 def test_master_expectation_is_independent(self):next(r for r in self.managed if r['kind']=='prepared')['data']['expected'][1]['primary'][1]=.3;self.reject()
 def test_preset_alpha_is_not_normalized(self):self.record('result')['data']['snapshot']['body']['baseColor'][3]=1;self.reject()
 def test_free_disturbance_applied(self):self.record('disturbed_result')['data']['snapshot']['face']['baseColor']=[1,1,1,0];self.reject()
 def test_load_cannot_be_credited_for_application(self):self.record('loaded_without_application')['data']['snapshot']['body']=self.record('result')['data']['snapshot']['body'];self.reject()
 def test_load_must_replace_custom_root(self):self.record('loaded_without_application')['data']['snapshot']['custom']=self.record('disturbed_result')['data']['snapshot']['custom'];self.reject()
 def test_actual_renderer_binding_required(self):self.record('result')['data']['snapshot']['bodyRenderer']['materials'][1]['pointer']='1';self.reject()
 def test_sweat_target_required(self):self.record('result')['data']['snapshot']['bodyRenderer']['materials'][2]['shadeColor']=[0,0,0,0];self.reject()
 def test_face_option_target_required(self):self.record('result')['data']['snapshot']['faceRenderer']['materials'][6]['baseColor']=[0,0,0,0];self.reject()
 def test_broadcast_receiver_required(self):self.events=[e for e in self.events if not(e['kind']=='body_customize_event' and e['data']['name']=='preset-1/restore')];self.reject()
 def test_original_receiver_must_not_change(self):next(e for e in self.events if e['kind']=='body_customize_event' and e['data']['name']=='preset-1/restore')['data']['pointer']='0x1';self.reject()
 def test_guard_is_controlled(self):self.record('result')['data']['snapshot']['stop']=False;self.reject()
 def test_cleanup_flags_required(self):next(r for r in self.managed if r['kind']=='cleanup')['data']['colorsRestored']=False;self.reject()
 def test_cleanup_observed_refs_required(self):next(r for r in self.managed if r['kind']=='cleanup')['data']['restored']['body']['pointer']='1';self.reject()
 def test_readiness_history_retained(self):self.managed=[r for r in self.managed if r['kind']!='readiness' or r['frame']!=414];self.reject()
 def test_other_scalar_appearance_does_not_change(self):self.files[0]['scalar_custom']['CustomizeHeight']=0;self.reject()
 def test_no_false_success_with_runner_error(self):self.managed.append(dict(kind='runner_error',data={}));self.reject()
 def test_bool_cannot_masquerade_as_index(self):self.files[0]['fields']['CustomizeSkinColor']=False;self.reject()
 def test_native_manual_slot_required(self):next(e for e in self.events if e['kind']=='native_save')['data']['arg1']='0x0';self.reject()
if __name__=='__main__':unittest.main()
