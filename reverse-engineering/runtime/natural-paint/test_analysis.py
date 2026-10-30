"""Counterexamples distinguish scheduled use, actual effect, natural saves and real restart."""
import copy,unittest
from analyze import HERE,read,rows,analyze_use,analyze_cold
class NaturalPaintTests(unittest.TestCase):
 def setUp(self):
  self.plan=read(HERE/'session-plan.json');self.use=HERE/'runs/use';self.cold=HERE/'runs/cold';self.managed=rows(self.use/'managed.jsonl.gz');self.files=read(self.use/'saved-files.json')['files'];self.cold_managed=rows(self.cold/'managed.jsonl.gz');self.cold_files=read(self.cold/'saved-files.json')['files'];self.baseline=read(HERE/'cold-baseline.json');self.start=read(HERE/'cold-start-receipt.json');self.close=read(self.use/'close-receipt.json')
  def ev(folder,meta):return [m['payload'] for r in read(folder/'rea-runtime.json.gz')['records'] if r['evidence_id']==meta['final_status_evidence_id'] for m in r['normalized_result']['messages']]
  self.events=ev(self.use,self.plan['runs'][0]);self.cold_events=ev(self.cold,self.plan['runs'][1])
 def natural(self):return analyze_use(self.managed,self.events,self.files)
 def restart(self):return analyze_cold(self.cold_managed,self.cold_events,self.cold_files,self.baseline,self.start,self.close,self.files)
 def reject_use(self):
  with self.assertRaises((ValueError,StopIteration)):self.natural()
 def reject_cold(self):
  with self.assertRaises((ValueError,StopIteration)):self.restart()
 def event(self,kind):return next(e for e in self.events if e['kind']==kind)
 def test_real_natural_types(self):self.assertEqual({x['type'] for x in self.natural()['completed']},{5,8,9})
 def test_real_cold_same_pid_is_valid(self):self.assertTrue(self.restart()['pid_reused'])
 def test_missing_type8_not_user_reply_coverage(self):self.events=[e for e in self.events if not(e['kind'].startswith('item_effect_') and e['data']['itemType']==8)];self.reject_use()
 def test_no_ui_callback_is_not_natural_ui_proof(self):self.events=[e for e in self.events if not e['kind'].startswith('inventory_use_button_')];self.reject_use()
 def test_deadline_is_game_time_plus3(self):self.event('item_effect_leave')['data']['actor']['deadline']+=1;self.reject_use()
 def test_completion_must_be_strictly_after_deadline(self):self.event('ordinary_completion_enter')['time']=0;self.reject_use()
 def test_completion_requires_original_action10008(self):self.event('ordinary_completion_enter')['data']['actor']['currentAction']=-1;self.reject_use()
 def test_delegate_pointer_must_match(self):self.event('ordinary_completion_enter')['data']['actor']['completion']='0x0';self.reject_use()
 def test_consumption_before_schedule_required(self):
  e=next(e for e in self.events if e['kind']=='item_change_enter' and int(e['data']['arg1'],0)&0xffffffff==0xffffffff);e['data']['arg1']='0x0';self.reject_use()
 def test_reusable_stock_is_not_consumed(self):self.event('reusable_completion_leave')['data']['actor']['dto']['items']['8']=0;self.reject_use()
 def test_inline_washer_does_not_require_standalone_hook(self):self.assertFalse(any(e['kind']=='paint_wash_enter' for e in self.events));self.assertTrue(any(x['type']==9 for x in self.natural()['completed']))
 def test_duplicate_actual_completion_rejected(self):
  a=copy.deepcopy(self.event('reusable_completion_enter'));b=copy.deepcopy(self.event('reusable_completion_leave'));a['data']['id']=b['data']['id']=1000000;i=self.events.index(self.event('reusable_completion_leave'))+1;self.events[i:i]=[a,b];self.reject_use()
 def test_selected_update_countdown(self):self.event('paint_update_pair')['data']['actorAfter']['dto']['remain']+=1;self.reject_use()
 def test_selected_update_alpha(self):self.event('paint_update_pair')['data']['after']['alpha']['current']+=.1;self.reject_use()
 def test_original_inline_initialization_required(self):self.event('pca_initialize_leave')['data']['actor']['paint']['state']=2;self.reject_use()
 def test_saved_state_requires_native_return_join(self):next(f for f in self.files if f['kind']=='game' and not f['capture']['initial'])['remaining']=9876;self.reject_use()
 def test_metadata_io_error_is_retained(self):self.assertEqual(len(self.natural()['command_errors_retained']),1)
 def test_metadata_io_error_without_quit_recovery_rejected(self):self.managed=[r for r in self.managed if r['kind']!='quit_requested'];self.reject_use()
 def test_snapshot_failure_is_not_metadata_io(self):self.managed.append(dict(kind='snapshot_error',data={}));self.reject_use()
 def test_old_process_absence_required(self):self.close['process_absent']=False;self.reject_cold()
 def test_creation_after_exit_required(self):self.start['start_time_utc']='2020-01-01T00:00:00Z';self.reject_cold()
 def test_byte_identical_cold_input_required(self):next(f for f in self.cold_files if f['kind']=='game' and f['capture']['initial'])['sha256']='0'*64;self.reject_cold()
 def test_cold_source_must_be_positive_actual_save(self):
  for f in self.files:
   if f['kind']=='game' and f['remaining']>0:f['remaining']=0
  self.reject_cold()
 def test_cold_load_native_dto(self):next(e for e in self.cold_events if e['kind']=='load_leave')['data']['actor']['dto']['reusable']=False;self.reject_cold()
 def test_cold_inline_controller_state(self):next(e for e in self.cold_events if e['kind']=='pca_initialize_leave')['data']['actor']['paint']['state']=0;self.reject_cold()
 def test_cold_must_not_replay_item(self):self.cold_events.append(dict(kind='item_effect_enter',data={}));self.reject_cold()
 def test_cold_actual_renderer_binding(self):
  s=next(r['data'] for r in self.cold_managed if r['kind']=='snapshot' and r['data'].get('clothes',{}).get('valid'));s['clothes']['pointer']='1';self.reject_cold()
 def test_no_controlled_stop_in_natural_cold(self):
  s=next(r['data'] for r in self.cold_managed if r['kind']=='snapshot' and r['data'].get('controllerPcaBound'));s['applier']=True;self.reject_cold()
if __name__=='__main__':unittest.main()
