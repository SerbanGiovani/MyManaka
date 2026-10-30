"""Counterexamples retain native timing, key presence and controller/material boundaries."""
import unittest
from analyze import HERE,read,rows,analyze
class TimedPaintTests(unittest.TestCase):
 def setUp(self):
  self.managed=rows(HERE/'managed.jsonl.gz');bundle=read(HERE/'rea-runtime.json');status=next(r for r in bundle['records'] if r['operation']=='frida_session_status');self.events=[m['payload'] for m in status['normalized_result']['messages']];saved=read(HERE/'saved-files.json');self.files=saved['files'];self.baseline=saved['baseline']
 def run_analysis(self):return analyze(self.managed,self.events,self.files,self.baseline)
 def record(self,kind,name):return next(r for r in self.managed if r['kind']==kind and r['data'].get('name')==name)
 def reject(self):
  with self.assertRaises((ValueError,StopIteration)):self.run_analysis()
 def test_real_trace(self):self.assertEqual(self.run_analysis()['cases'],21)
 def test_independent_property_literal_is_exact(self):next(r for r in self.managed if r['kind']=='property_id_verified')['data']['literal']='_TweakTransparency';self.reject()
 def test_static_property_id_is_not_assumed(self):next(r for r in self.managed if r['kind']=='property_id_verified')['data']['staticTweakId']=0;self.reject()
 def test_missing_original_update_return(self):
  index=next(i for i,e in enumerate(self.events) if e['kind']=='paint_update_leave');self.events.pop(index);self.reject()
 def test_duplicate_native_call_identity(self):
  es=[e for e in self.events if e['kind'].endswith('_enter')];es[1]['data']['id']=es[0]['data']['id'];self.reject()
 def test_wrong_original_registered_controller(self):
  next(r for r in self.managed if r['kind']=='prepared')['data']['parked']['pcaBodyPaint']='1';self.reject()
 def test_clone_alpha_must_be_independent(self):
  s=next(r for r in self.managed if r['kind']=='prepared')['data']['parked'];s['clone']['smooth']['pointer']=s['original']['smooth']['pointer'];self.reject()
 def test_guard_requires_real_updates(self):
  self.events=[e for e in self.events if not(e['kind'].startswith('paint_update_') and e['data']['name']=='guard-probe/parked-five-frames')];self.reject()
 def test_guard_cannot_change_remaining(self):
  e=next(e for e in self.events if e['kind']=='paint_update_leave' and e['data']['name']=='guard-probe/parked-five-frames');e['data']['snapshot']['dto']['remain']=119;self.reject()
 def test_actual_dt_required(self):
  r=next(r for r in self.managed if r['kind']=='manual_update_before' and r['data']['name']=='rate-025');r['data']['deltaTime']=.5;self.reject()
 def test_actual_doki_required(self):
  r=next(r for r in self.managed if r['kind']=='manual_update_before' and r['data']['name']=='rate-05');r['data']['actualDokidoki']=0;self.reject()
 def test_countdown_native_value_required(self):
  e=next(e for e in self.events if e['kind']=='paint_update_leave' and e['data']['name'].startswith('rate-05/'));e['data']['snapshot']['dto']['remain']-=1;self.reject()
 def test_smoothing_native_value_required(self):
  e=next(e for e in self.events if e['kind']=='paint_update_leave' and e['data']['name'].startswith('cross-24/'));e['data']['snapshot']['alpha']['current']=0;self.reject()
 def test_restore_doki_after_each_call(self):
  next(r for r in self.managed if r['kind']=='manual_update_after')['data']['restoredDokidoki']=.5;self.reject()
 def test_exact_threshold24_branch(self):self.record('initialize_result','init-24')['data']['snapshot']['clone']['state']=3;self.reject()
 def test_actual_save_value_not_source_expectation(self):self.files[0]['remaining']+=1;self.reject()
 def test_saved_reusable_bool(self):self.files[0]['reusable']=not self.files[0]['reusable'];self.reject()
 def test_absent_map_does_not_become_false_key(self):self.files[0]['persistent_map'].append(dict(id=0,value=False));self.reject()
 def test_other_custom_data_not_mutated(self):self.files[0]['custom_tree_sha256']='0'*64;self.reject()
 def test_no_premature_wash_clear(self):self.record('wash_return','wash')['data']['snapshot']['reusable']=False;self.reject()
 def test_native_wash_callback_required(self):
  self.events=[e for e in self.events if not e['kind'].startswith('paint_wash_')];self.reject()
 def test_ordinary_item_does_not_clear_sticky_true(self):self.record('item_return','item-ordinary-true')['data']['snapshot']['reusable']=False;self.reject()
 def test_reusable_item_id(self):self.record('item_return','item-reusable')['data']['snapshot']['lastItem']=5;self.reject()
 def test_crossing_keeps_old_alpha_first_frame(self):self.record('crossing_return','cross-60')['data']['snapshot']['clone']['smooth']['fields']['Current']=.25;self.reject()
 def test_follow_frame_starts_smoothing(self):self.record('crossing_follow','cross-24')['data']['alphaAfter']=.25;self.reject()
 def test_body_material_binding(self):
  r=next(r for r in self.managed if r['kind']=='manual_update_after' and r['data']['name']=='rate-0');r['data']['snapshot']['materials'][-2]['pointer']='1';self.reject()
 def test_extra_material_binding(self):
  r=next(r for r in self.managed if r['kind']=='manual_update_after' and r['data']['name']=='rate-0');r['data']['snapshot']['saoRenderer']['materials'][-1]['pointer']='1';self.reject()
 def test_actual_shader_tweak(self):
  r=next(r for r in self.managed if r['kind']=='manual_update_after' and r['data']['name']=='rate-0');r['data']['snapshot']['tama']['tweak']=0;self.reject()
 def test_load_does_not_apply_materials(self):self.record('loaded_without_initialize','load-ordinary')['data']['snapshot']['clothes']=self.record('body_broadcast_only','load-ordinary')['data']['snapshot']['clothes'];self.reject()
 def test_broadcast_does_not_initialize_runtime_state(self):self.record('body_only_after_update','load-reusable')['data']['snapshot']['clone']['state']=2;self.reject()
 def test_explicit_initialize_required(self):self.record('explicit_initialize_result','load-ordinary')['data']['snapshot']['clone']['state']=0;self.reject()
 def test_cleanup_true_cannot_be_inferred_from_result_count(self):next(r for r in self.managed if r['kind']=='cleanup')['data']['objectsRestored']=False;self.reject()
 def test_cleanup_completion_follows_validation(self):self.managed=[r for r in self.managed if r['kind']!='cleanup_done'];self.reject()
 def test_detailed_material_failure_is_rejected(self):next(r for r in self.managed if r['kind']=='cleanup_material_diff_after')['data']['report']['propertiesRestored']=False;self.reject()
 def test_enumerated_properties_are_not_full_presence_coverage(self):next(r for r in self.managed if r['kind']=='cleanup_material_diff_after')['data']['report']['extraTweakPresenceChecks']=0;self.reject()
 def test_same_shader_reset_must_clear_added_property(self):next(r for r in self.managed if r['kind']=='shader_reset_for_tweak_presence')['data']['absenceRestored']=False;self.reject()
 def test_full_snapshot_restoration(self):next(r for r in self.managed if r['kind']=='cleanup')['data']['restored']['dokidoki']=.25;self.reject()
 def test_errors_are_not_formal_success(self):self.events.append(dict(kind='engine_error',data={}));self.reject()
if __name__=='__main__':unittest.main()
