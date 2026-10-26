"""Counterexamples for natural reachability and imported-data attribution."""
import copy
import unittest
from analyze import HERE,read,rows,analyze,build


class NaturalLoadTests(unittest.TestCase):
    def setUp(self):
        bundle=read(HERE/'rea-runtime.json');n=next(r['normalized_result'] for r in bundle['records'] if r['operation']=='frida_session_status')
        self.events=[dict(m['payload'],script_id=m['script_id']) for m in n['messages'] if m['type']=='send']
        self.snapshots=rows(HERE/'state.jsonl.gz');self.paths=rows(HERE/'native-paths.jsonl.gz');self.files=read(HERE/'save-projections.json')

    def result(self):return analyze(self.events,self.snapshots,self.paths,self.files)
    def test_capture(self):self.assertEqual(build(),read(HERE/'results.json'))

    def test_force_guard_false_rejected(self):
        next(e for e in self.events if e['kind']=='debug_cctor_leave')['data']['debug']['force']=0
        with self.assertRaisesRegex(ValueError,'constructor guard'):self.result()

    def test_reached_restore_rejected(self):
        self.events.append(dict(kind='npc_load_enter',frame=9969,data={}))
        with self.assertRaisesRegex(ValueError,'unexpectedly reached'):self.result()

    def test_natural_records_not_confused_with_import(self):
        self.files['natural_backup']['npcs']=copy.deepcopy(self.files['imported']['npcs'])
        with self.assertRaisesRegex(ValueError,'newly captured NPCs'):self.result()

    def test_backup_not_main_slot(self):
        p=next(p for p in self.paths if p['kind']=='save_path' and p['frame']==48305 and p['data']['before'].endswith('/1.sd'))
        p['data']['before']='SaveData/1.sd'
        with self.assertRaisesRegex(ValueError,'conflated'):self.result()

    def test_unobserved_readback_not_claimed(self):
        self.events.append(dict(kind='title_slot_enter',frame=49000,data=dict(type=3,slot=1)))
        with self.assertRaisesRegex(ValueError,'title_slot_enter'):self.result()

    def test_wrong_saved_pose_rejected(self):
        self.files['natural_backup']['playerPosition'][0]+=1
        with self.assertRaisesRegex(ValueError,'backup pose differs'):self.result()

    def test_loaded_flag_true_rejected(self):
        target=next(s for s in self.snapshots if s['kind']=='snapshot' and s['data']['scene']=='Night_Demo 1')
        target['data']['loaded']=True
        with self.assertRaisesRegex(ValueError,'capture guard'):self.result()


if __name__=='__main__':unittest.main()
