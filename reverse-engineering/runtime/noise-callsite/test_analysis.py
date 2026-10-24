"""Reject falsely joined native traces and absent/late eligibility readbacks."""
import copy,runpy,unittest
from pathlib import Path
m=runpy.run_path(str(Path(__file__).with_name('analyze.py')))
def trace():
    identity=dict(trial=1,scope='1:10',thread=3052,nca='0xabc')
    return (dict(script='probe',frame=10,order=1,data={**identity,'entryCaller':'0x428bf3'}),
      [dict(script='probe',frame=10,order=2,data={**identity,'old':1,'next':2,'caller':'0x435abf'})],
      dict(script='probe',frame=10,order=3,data={k:v for k,v in identity.items() if k!='nca'}))
class Tests(unittest.TestCase):
    def validate(self,b=None,c=None,t=None):
        if b is None and c is None and t is None:b,c,t=trace()
        return m['validate_native_scope'](b,c,t)
    def test_actual_scope_passes_without_trigger_nca(self):self.assertTrue(self.validate()['valid'])
    def test_wrong_thread(self):
        b,c,t=trace();c[0]['data']['thread']=99;self.assertFalse(self.validate(b,c,t)['valid'])
    def test_wrong_object(self):
        b,c,t=trace();c[0]['data']['nca']='0xdef';self.assertFalse(self.validate(b,c,t)['valid'])
    def test_wrong_script(self):
        b,c,t=trace();c[0]['script']='other';self.assertFalse(self.validate(b,c,t)['valid'])
    def test_wrong_trial(self):
        b,c,t=trace();c[0]['data']['trial']=2;self.assertFalse(self.validate(b,c,t)['valid'])
    def test_wrong_scope(self):
        b,c,t=trace();t['data']['scope']='2:10';self.assertFalse(self.validate(b,c,t)['valid'])
    def test_hit_branch_does_not_pass(self):
        b,c,t=trace();c[0]['data']['caller']='0x435c7e';self.assertFalse(self.validate(b,c,t)['valid'])
    def test_idle_turn_not_found(self):
        b,c,t=trace();c[0]['data']['old']=0;self.assertFalse(self.validate(b,c,t)['valid'])
    def test_readback_only_not_native_proof(self):
        b,c,t=trace();self.assertFalse(self.validate(b,[],t)['valid'])
    def test_duplicate_changes_require_review(self):
        b,c,t=trace();c.append(copy.deepcopy(c[0]));self.assertFalse(self.validate(b,c,t)['valid'])
    def test_same_frame_does_not_replace_order(self):
        b,c,t=trace();c[0]['order']=3;self.assertFalse(self.validate(b,c,t)['valid'])
    def test_missing_begin(self):
        b,c,t=trace();self.assertFalse(self.validate(None,c,t)['valid'])
    def test_missing_return(self):
        b,c,t=trace();self.assertFalse(self.validate(b,c,None)['valid'])
    def test_numeric_readbacks_locate_only_interval(self):
        r=m['summarize_pairs']([dict(at={'frame':1},before={'count':120,'value':1},after={'count':119,'value':1})])
        self.assertEqual(len(r['count_decreases']),1);self.assertEqual(r['value_decreases'],[])
    def test_missing_noise_return_is_explicit(self):
        ps=[dict(kind='eligibility_ready',script='e',order=0,frame=0),dict(kind='eligibility_noise_before',script='e',order=2,frame=1,data=dict(call=1,at={'nca':'npc'}))]
        r=m['summarize_eligibility'](ps,'npc',dict(order=1),dict(order=4))
        self.assertEqual(r['noise_complete_pairs'],0);self.assertEqual(len(r['noise_missing_return_readbacks']),1)
    def test_no_ready_is_not_zero_coverage(self):
        r=m['summarize_eligibility']([],'npc',dict(order=1),dict(order=4))
        self.assertEqual(r['coverage_status'],'no-per-call-coverage-before-ready')
if __name__=='__main__':unittest.main()
