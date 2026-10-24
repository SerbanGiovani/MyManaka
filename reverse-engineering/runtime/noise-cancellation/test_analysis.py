"""Regressions for evidence strength, sampling gaps and receiver readback."""
import copy,runpy,unittest
from pathlib import Path
m=runpy.run_path(str(Path(__file__).with_name('analyze.py')))
H=0xfa993e55
def sample(frame,progress=None):
    return dict(frame=frame,real=float(frame),current=dict(full=H if progress is not None else 0,normalized=progress or 0),next=dict(full=0,normalized=0),transition=False,weight=1,speed=1,fireEvents=1)
def fixture():
    return dict(begin=dict(frame=1,order=0),samples=[sample(1,.3),sample(2,.5),sample(3),sample(4)],
      triggers=[dict(frame=1,real=1,order=1,data=dict(before={**sample(1,.3),'business':{'state':1}},afterSound=dict(added=.000001,state=1),after={'business':{'state':2}}))],
      events=[],callbacks=[],end=dict(frame=5,data={'reason':'completed'}),changes=[])
class Tests(unittest.TestCase):
    def classify(self,f=None):return m['classify_control_trial'](**(f or fixture()))
    def test_readback_is_not_native_callsite(self):
        r=self.classify();self.assertFalse(r['original_ordinary_turn_confirmed']);self.assertEqual(r['classification'],'bounded-clip-exit-without-event-after-receiver-replay')
    def test_actual_ordinary_callsite_strengthens(self):
        f=fixture();f['changes']=[dict(frame=1,order=0,data=dict(old=1,next=2,caller='0x435abf'))]
        self.assertEqual(self.classify(f)['classification'],'normal-transition-exit-without-event-observed')
    def test_hit_callsite_is_separate(self):
        self.assertFalse(m['ordinary_noise_change'](dict(old=1,next=2,caller='0x435c7e')))
    def test_ordinary_idle_turn_is_not_found_cancel(self):
        self.assertFalse(m['ordinary_noise_change'](dict(old=0,next=2,caller='0x435abf')))
    def test_event_overrides_below_marker_sampling(self):
        f=fixture();f['events']=[dict(frame=2,order=2)]
        self.assertEqual(self.classify(f)['classification'],'event-generated')
    def test_duplicate_events_require_review(self):
        f=fixture();f['events']=[dict(frame=2,order=2),dict(frame=3,order=3)]
        self.assertEqual(self.classify(f)['classification'],'multiple-events-review')
    def test_gap_prevents_cancel_classification(self):
        f=fixture();f['samples']=[sample(1,.3),sample(3),sample(4)]
        self.assertEqual(self.classify(f)['classification'],'unresolved-no-event')
    def test_no_positive_sound_stays_unknown(self):
        f=fixture();f['triggers'][0]['data']['afterSound']['added']=0
        self.assertEqual(self.classify(f)['classification'],'unresolved-no-event')
    def test_no_found_before_is_not_turn_proof(self):
        f=fixture();f['triggers'][0]['data']['before']['business']['state']=0
        self.assertFalse(self.classify(f)['receiver_replay_turn_readback'])
    def test_unfinished_not_cancelled(self):
        f=fixture();f['end']=None
        self.assertEqual(self.classify(f)['classification'],'unresolved-no-event')
    def test_missing_cleanup_is_not_success(self):
        self.assertFalse(m['cleanup_result'](None)['verified_listed_fields_and_position'])
    def test_stale_calculation_not_current(self):
        s=sample(2,.3);s['business']=dict(lastCalculation=dict(frame=1,values=[0,0,0,1,0]))
        self.assertEqual(m['summarize_noise_samples']([s])['fresh_continuous_noise_samples'],0)
if __name__=='__main__':unittest.main()
