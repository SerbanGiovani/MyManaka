import unittest
from analyze import summarize_queue,associate_listener,associate_group

def sample(frame,stop=1,remaining=.4,mesh=1,distance=1,manual=0,present=True):
    return dict(frame=frame,data=dict(stop=stop,remaining=remaining,present=present,
                actor=dict(meshActive=mesh,distance=distance,manual=manual)))

class QueueTests(unittest.TestCase):
    def test_frozen(self):
        a,b=sample(1),sample(2);a['data']['timeScale']=b['data']['timeScale']=1
        r=summarize_queue([a,b]);self.assertEqual(r['frozen_intervals'],1);self.assertEqual(r['frozen_with_timeScale_one'],1)
    def test_stop_drain_detected(self):self.assertEqual(len(summarize_queue([sample(1),sample(2,remaining=.3)])['frozen_violations']),1)
    def test_boundary_not_assumed_frozen(self):
        self.assertEqual(summarize_queue([sample(1,stop=0),sample(2)])['frozen_intervals'],0)
        a,b=sample(1),sample(2);a['data']['timeScale']=b['data']['timeScale']=0
        r=summarize_queue([a,b]);self.assertEqual(r['frozen_with_timeScale_zero'],1);self.assertEqual(r['frozen_with_timeScale_one'],0)
    def test_gap_not_continuous(self):self.assertEqual(summarize_queue([sample(1),sample(20)])['frozen_intervals'],0)
    def test_missing_membership_not_frozen(self):self.assertEqual(summarize_queue([sample(1,present=False),sample(2)])['frozen_intervals'],0)
    def test_visibility_and_distance(self):
        r=summarize_queue([sample(1),sample(2,mesh=0,distance=60,manual=1),sample(3,distance=1)])
        self.assertEqual(len(r['visibility_transitions']),2);self.assertEqual(len(r['distance_crossings']),4)

class ListenerTests(unittest.TestCase):
    def test_legacy_ambiguous_frame_rejected(self):
        self.assertEqual(associate_listener(dict(frame=1),[dict(frame=1,data={})],'A',False),[])
    def test_typed_wrong_npc_rejected(self):
        self.assertEqual(associate_listener(dict(frame=1),[dict(frame=1,data=dict(argumentConvention='value',npc='B'))],'A',True),[])
    def test_typed_same_npc(self):
        self.assertEqual(len(associate_listener(dict(frame=1),[dict(frame=1,data=dict(argumentConvention='value',npc='A'))],'A',True)),1)
    def test_two_models_two_listeners_group(self):
        rows=[dict(frame=1,data=dict(argumentConvention='NpcController',npc='A'))]*2
        r=associate_group(dict(frame=1),rows,'A',2,2)
        self.assertTrue(r['balanced']);self.assertFalse(r['individually_attributed'])
    def test_extra_group_listener_is_duplicate(self):
        rows=[dict(frame=1,data=dict(argumentConvention='NpcController',npc='A'))]*3
        self.assertFalse(associate_group(dict(frame=1),rows,'A',2,2)['balanced'])
    def test_missing_group_listener(self):
        rows=[dict(frame=1,data=dict(argumentConvention='NpcController',npc='A'))]
        self.assertFalse(associate_group(dict(frame=1),rows,'A',2,2)['balanced'])
if __name__=='__main__':unittest.main()
