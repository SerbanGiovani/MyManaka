import unittest
from analyze import summarize_samples,evaluation_result,continuation_link,merge_statuses
H=0xfa993e55
def sample(f,d,manual=0,stop=1,n=.4,mesh=1):
    return dict(frame=f,real=float(f),current={'full':H,'normalized':n},next={'full':H,'normalized':n},transition=False,distance=d,manual=manual,stop=stop,speed=0 if stop else 1,timeScale=1,meshActive=mesh)
class Coverage(unittest.TestCase):
    def test_skill_pause_crossing(self):
        r=summarize_samples([sample(1,9),sample(2,11,1)],{'frame':3,'real':3})
        self.assertEqual(r['skill_stop_samples'],2);self.assertEqual(r['pre_event_distance_crossings'][0]['direction'],'near-to-far')
    def test_post_event_hidden_does_not_count(self):
        self.assertEqual(summarize_samples([sample(1,9),sample(2,12,1,mesh=0)],{'frame':2,'real':1.5})['pre_event_hidden_samples'],0)
    def test_ordinary_pause_separate(self):
        s=sample(1,11,1);s['timeScale']=0
        r=summarize_samples([s],None);self.assertEqual(r['skill_stop_samples'],0);self.assertEqual(r['ordinary_pause_samples'],1)
    def test_after_marker_not_precondition(self):
        self.assertEqual(summarize_samples([sample(1,50,n=.9,mesh=0)],None)['pre_event_hidden_samples'],0)
    def test_frozen_no_event_not_failure(self):
        self.assertEqual(summarize_samples([sample(1,10),sample(2,10)],None)['pre_event_distance_crossings'],[])
    def test_gap_does_not_prove_crossing(self):
        self.assertEqual(summarize_samples([sample(1,9),sample(4,11,1)],None)['pre_event_distance_crossings'],[])
    def test_hidden_manual_generation_inside_original_call(self):
        pre=sample(1,50,1,stop=0,mesh=0)
        r=evaluation_result({'frame':1,'data':{'id':1,'receiver':'R','nca':'N','delta':.5,'pre':pre}},{'data':{'events':1}},[{}])
        self.assertTrue(r['hidden_before_actual_update'])
    def test_hidden_snapshot_without_paired_call_not_proof(self):
        pre=sample(1,50,1,stop=0,mesh=0)
        r=evaluation_result({'frame':1,'data':{'id':1,'receiver':'R','nca':'N','delta':.5,'pre':pre}},None,[{}])
        self.assertFalse(r['hidden_before_actual_update'])
    def fragments(self,first=1,last=3):
        def case(f,origin):
            s=sample(f,12,1);s.update(npc='P',receiver='R',animator='A',mesh='M')
            return dict(begin=dict(frame=f,data=dict(nca='N',origin=origin)),samples=[s],end=dict(data=dict(reason='observation-limit')))
        return case(first,'original-business-change-before-call'),case(last,'business-rise-fallback')
    def bridge(self,f=2):
        return dict(script='E',id=f,nca='N',receiver='R',frame=f,paired=True,events_inside=0,pre=sample(f,12,1),post=sample(f,12,1))
    def test_uncovered_gap_rejects_join(self):
        a,b=self.fragments();self.assertIsNone(continuation_link(a,b,[],[]))
    def test_paired_frozen_evaluation_bridges_gap(self):
        a,b=self.fragments();self.assertEqual(continuation_link(a,b,[self.bridge()],[])['gap_frames'],[2])
    def test_changed_progress_rejects_join(self):
        a,b=self.fragments();b['samples'][0]['current']['normalized']=.5
        self.assertIsNone(continuation_link(a,b,[self.bridge()],[]))
    def test_recycled_identity_rejects_join(self):
        a,b=self.fragments();b['samples'][0]['animator']='new'
        self.assertIsNone(continuation_link(a,b,[self.bridge()],[]))
    def test_native_fresh_entry_not_continuation(self):
        a,b=self.fragments();b['begin']['data']['origin']='original-business-change-before-call'
        self.assertIsNone(continuation_link(a,b,[self.bridge()],[]))
    def test_event_in_gap_rejects_join(self):
        a,b=self.fragments();v=self.bridge();v['events_inside']=1
        self.assertIsNone(continuation_link(a,b,[v],[]))
    def test_overlap_frozen_identity(self):
        a,b=self.fragments(3,3)
        self.assertEqual(continuation_link(a,b,[],[])['overlap_frames'],[3])
    def test_parameter_exit_rejects_join(self):
        a,b=self.fragments();self.assertIsNone(continuation_link(a,b,[self.bridge()],[dict(frame=2,data=dict(value=False))]))
    def capture(self,lo,hi,truncated=False):
        return dict(operation='frida_session_status',evidence_id=str(hi),normalized_result=dict(messages_truncated=truncated,messages=[dict(type='send',script_id='S',payload=dict(frame=f,kind='test')) for f in range(lo,hi)]))
    def test_exact_overlap_reconstructs_bounded_tail(self):
        ms,joins=merge_statuses([self.capture(0,100),self.capture(50,150,True)])
        self.assertEqual([m['payload']['frame'] for m in ms],list(range(150)))
        self.assertEqual(joins[0]['overlapping_messages'],50)
    def test_capture_gap_rejected(self):
        with self.assertRaises(AssertionError):merge_statuses([self.capture(0,100),self.capture(101,150,True)])
    def test_truncated_prefix_rejected(self):
        with self.assertRaises(AssertionError):merge_statuses([self.capture(0,100,True)])
    def test_tiny_overlap_rejected(self):
        with self.assertRaises(AssertionError):merge_statuses([self.capture(0,100),self.capture(80,150,True)])
if __name__=='__main__':unittest.main()
