"""Counterexamples for excluded records, duplicate callbacks and wrong object joins."""
import copy
import unittest
from analyze import HERE,read,rows,analyze,build

class FilterTests(unittest.TestCase):
    def setUp(self):
        n=next(r['normalized_result'] for r in read(HERE/'rea-runtime.json')['records'] if r['operation']=='frida_session_status')
        self.events=[dict(m['payload'],script_id=m['script_id']) for m in n['messages']]
        self.managed=rows(HERE/'managed.jsonl.gz');self.saved=read(HERE/'native-save.json')
    def result(self):return analyze(self.managed,self.events,self.saved)
    def test_capture(self):self.assertEqual(build(),read(HERE/'results.json'))
    def test_fixed_snapshot_rejected(self):
        next(e for e in self.managed if e['kind']=='snapshot_full')['data']['records'].append({})
        with self.assertRaisesRegex(ValueError,'Fixed NPC snapshot'):self.result()
    def test_absent_save_flag_rejected(self):
        self.saved['npcs'][1]['exists']=True
        with self.assertRaisesRegex(ValueError,'Encrypted save exclusion'):self.result()
    def test_absent_record_queue_rejected(self):
        fixture=next(e for e in self.managed if e['kind']=='consumer_fixture')['data']
        next(e for e in self.events if e['kind']=='restore_queued')['data']['record']=copy.deepcopy(fixture['records'][1])
        with self.assertRaisesRegex(ValueError,'Excluded record'):self.result()
    def test_inside_record_queue_rejected(self):
        fixture=[e for e in self.managed if e['kind']=='consumer_fixture'][-1]['data']
        [e for e in self.events if e['kind']=='restore_queued'][-1]['data']['record']=copy.deepcopy(fixture['records'][1])
        with self.assertRaisesRegex(ValueError,'Excluded record'):self.result()
    def test_bounds_for_absent_record_rejected(self):
        self.events.append(copy.deepcopy(next(e for e in self.events if e['kind']=='restore_bounds')))
        with self.assertRaisesRegex(ValueError,'existence-before-Bounds'):self.result()
    def test_wrong_warp_pose_rejected(self):
        next(e for e in self.events if e['kind']=='npc_warp_leave')['data']['position'][0]+=1
        with self.assertRaisesRegex(ValueError,'Pose mismatch'):self.result()
    def test_duplicate_callback_rejected(self):
        self.events.append(copy.deepcopy(next(e for e in self.events if e['kind']=='restore_callback')))
        with self.assertRaisesRegex(ValueError,'duplicate native restore_callback'):self.result()
    def test_unrestored_guard_rejected(self):
        next(e for e in self.managed if e['kind']=='cleanup')['data']['loaded']=True
        with self.assertRaisesRegex(ValueError,'cleanup incomplete'):self.result()

if __name__=='__main__':unittest.main()
