import unittest
from analyze import classify
H=0xfa993e55
def sample(f,n,full=H,transition=False):
    v=dict(full=full,normalized=n)
    return dict(frame=f,current=v,next=v,transition=transition,fireEvents=True,weight=1,speed=1,meshActive=True,distance=1,manual=0)
BEGIN={'data':{'origin':'original-parameter-write-before-native'}}
END={'data':{'reason':'completed-observation'}}
class Classification(unittest.TestCase):
    def check_case(self,samples,events=[],parameters=[],end=END):return classify(BEGIN,samples,events,parameters,end)
    def test_false_does_not_cancel_blend(self):
        s=[sample(1,.4),sample(2,.7,transition=True),sample(3,.9,transition=True),sample(4,0,0)]
        r=self.check_case(s,parameters=[{'frame':2,'data':{'value':False}}]);self.assertEqual(r['classification'],'unresolved-no-event')
    def test_source_disappears_before_event(self):
        s=[sample(1,.2),sample(2,.4,transition=True),sample(3,0,0),sample(4,0,0)]
        r=self.check_case(s,parameters=[{'frame':2,'data':{'value':False}}]);self.assertEqual(r['classification'],'normal-transition-exit-without-event-observed')
    def test_queued_event_excludes_cancel(self):
        r=self.check_case([sample(1,.2),sample(2,0,0)],events=[{'frame':1}]);self.assertEqual(r['classification'],'event-generated')
    def test_stable_crossing_candidate(self):
        r=self.check_case([sample(1,.7),sample(2,.9)]);self.assertEqual(r['classification'],'stable-threshold-crossing-without-event-candidate')
    def test_gap_not_candidate(self):self.assertEqual(self.check_case([sample(1,.7),sample(3,.9)])['classification'],'unresolved-no-event')
    def test_retirement_not_cancellation(self):
        s=[sample(1,.2),sample(2,0,0),sample(3,0,0)];r=self.check_case(s,parameters=[{'frame':1,'data':{'value':False}}],end={'data':{'reason':'retired'}});self.assertEqual(r['classification'],'unresolved-no-event')
    def test_crossing_after_event_not_pre_event(self):
        a,b=sample(1,.7),sample(2,.9);a['distance']=9;b['distance']=11
        self.assertFalse(self.check_case([a,b],[{'frame':2}])['pre_event_changes'])
    def test_two_samples_same_frame_do_not_confirm_exit(self):
        r=self.check_case([sample(1,.2),sample(2,0,0),sample(2,0,0)],parameters=[{'frame':1,'data':{'value':False}}]);self.assertEqual(r['classification'],'unresolved-no-event')
    def test_getter_rise_cannot_confirm_cancellation(self):
        r=classify({'data':{'origin':'getter-rise-fallback'}},[sample(1,.2),sample(2,0,0),sample(3,0,0)],[],[{'frame':1,'data':{'value':False}}],END);self.assertEqual(r['classification'],'unresolved-no-event')
if __name__=='__main__':unittest.main()
