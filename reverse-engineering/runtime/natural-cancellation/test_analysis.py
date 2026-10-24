import unittest
from analyze import business_outcome,lifecycle_outcome
def change(frame=10,timer=3.01,producer='found-update',old=1,next=0):
    return dict(frame=frame,data=dict(old=old,next=next,business=dict(stateTime=timer),producer=producer,caller='0x42c6e8'))
class Business(unittest.TestCase):
    def test_timer_exit_after_event(self):
        self.assertEqual(business_outcome([change()],[5])[0]['classification'],'normal-timer-exit-after-event')
    def test_early_noise_exit_is_candidate(self):
        self.assertEqual(business_outcome([change(timer=.1,producer='noise-update')],[])[0]['classification'],'early-business-exit-candidate-not-clip-cancellation-proof')
    def test_later_blend_event_not_early_cancellation_proof(self):
        self.assertIn('candidate',business_outcome([change(timer=.1,producer='noise-update')],[12])[0]['classification'])
    def test_timer_without_event_not_normal_post_event(self):
        self.assertIn('candidate',business_outcome([change()],[])[0]['classification'])
    def test_freeze_without_state_exit_not_cancel(self):
        self.assertEqual(business_outcome([],[]),[])
    def test_business_entry_not_exit(self):
        self.assertEqual(business_outcome([change(old=0,next=1)],[]),[])
    def test_other_producer_after_event_not_timer(self):
        self.assertEqual(business_outcome([change(producer='noise-update')],[2])[0]['classification'],'other-exit-after-event')
    def test_three_exact_not_over_three(self):
        self.assertEqual(business_outcome([change(timer=3)],[2])[0]['classification'],'other-exit-after-event')
    def lifecycle(self,progress=.7):
        c=dict(entry_frame=1,scene='Mall',events=[],end=dict(frame=4,data=dict(reason='retired:destroyed Unity object')))
        s=[dict(current=dict(full=0xfa993e55,normalized=progress),transition=False)]
        return c,s,[dict(frame=3,data=dict(name='StationFront'))],[dict(frame=2)]
    def test_scene_retirement_below_marker(self):
        self.assertIsNotNone(lifecycle_outcome(*self.lifecycle()))
    def test_above_marker_retirement_remains_unknown(self):
        self.assertIsNone(lifecycle_outcome(*self.lifecycle(.9)))
    def test_retirement_without_scene_evidence_not_normal_cancel(self):
        c,s,sc,t=self.lifecycle();self.assertIsNone(lifecycle_outcome(c,s,[],t))
    def test_scene_change_without_original_transition_not_linked(self):
        c,s,sc,t=self.lifecycle();self.assertIsNone(lifecycle_outcome(c,s,sc,[]))
    def test_already_generated_event_not_pre_event_cancel(self):
        c,s,sc,t=self.lifecycle();c['events']=[{}];self.assertIsNone(lifecycle_outcome(c,s,sc,t))
if __name__=='__main__':unittest.main()
