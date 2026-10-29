import copy
import unittest
from analyze import HERE,analyze,build,read,rows
class AnalysisTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.temp=rows(HERE/'clean-v3-managed.jsonl.gz');cls.title=rows(HERE/'managed.jsonl.gz')
        statuses={r['normalized_result']['session_id']:r['normalized_result'] for r in read(HERE/'rea-runtime.json')['records'] if r['operation']=='frida_session_status'}
        cls.ev3=[m['payload'] for m in statuses['5666d254-8985-4689-82fb-365acb0008fc']['messages']];cls.ev4=[m['payload'] for m in statuses['3193486b-af59-4423-981b-8c309b60be17']['messages']]
    def test_complete(self):self.assertEqual(len(build()['clean_cases']),4)
    def test_duplicate_callback_rejected(self):
        altered=copy.deepcopy(self.ev4);altered.append(copy.deepcopy(next(e for e in altered if e['kind']=='restore_callback_enter')))
        with self.assertRaises(ValueError):analyze(self.temp,self.title,self.ev3,altered)
    def test_premature_queue_removal_rejected(self):
        altered=copy.deepcopy(self.title);next(r for r in altered if r['kind']=='after_interruption')['data']['pending']=False
        with self.assertRaises(ValueError):analyze(self.temp,altered,self.ev3,self.ev4)
    def test_dead_receiver_clone_rejected(self):
        altered=copy.deepcopy(self.ev4);clone=copy.deepcopy(next(e for e in self.ev3 if e['kind']=='npc_clone_enter'));callback=next(e for e in altered if e['kind']=='restore_callback_enter');clone['real']=callback['real'];altered.append(clone)
        with self.assertRaises(ValueError):analyze(self.temp,self.title,self.ev3,altered)
    def test_callback_error_not_hidden(self):
        altered=copy.deepcopy(self.ev3);next(e for e in altered if e['kind']=='engine_error')['data']['context']={'restore':True}
        with self.assertRaises(ValueError):analyze(self.temp,self.title,altered,self.ev4)
if __name__=='__main__':unittest.main()
