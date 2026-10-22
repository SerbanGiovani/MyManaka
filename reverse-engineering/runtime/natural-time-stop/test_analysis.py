"""Guard against falsely passing different-NPC and overwritten-cache observations."""
import unittest
from analyze import pair_cases

def inputs():
    cases=[dict(session='s',id=1,frame=10,real=1,before=0,after=1,receiver_count=1,duplicates={}),
           dict(session='s',id=2,frame=20,real=2,before=1,after=0,receiver_count=1,duplicates={})]
    captures=[dict(session='s',producer_id=1,before=dict(npc='A',speed=1.2),after={},correct=True),
              dict(session='s',producer_id=2,before=dict(npc='A',cache=1.2),after=dict(speed=1.2),correct=True)]
    return cases,captures

class PairTests(unittest.TestCase):
    def test_closed_loop(self):
        c,v=inputs();self.assertTrue(pair_cases(c,v)[0]['passed'])
    def test_different_npc(self):
        c,v=inputs();v[1]['before']['npc']='B';self.assertFalse(pair_cases(c,v)[0]['passed'])
    def test_cache_overwritten_before_restore(self):
        c,v=inputs();v[1]['before']['cache']=0;v[1]['after']['speed']=0;self.assertFalse(pair_cases(c,v)[0]['passed'])
    def test_cross_attach(self):
        c,v=inputs();c[1]['session']='other';self.assertEqual(pair_cases(c,v),[])
    def test_missing_exact_resume_capture(self):
        c,v=inputs();self.assertFalse(pair_cases(c,v[:1])[0]['passed'])

if __name__=='__main__':unittest.main()
