"""Counterexamples for accidentally claiming a backup or mismatched object restore."""
import unittest
from analyze import HERE,read,rows,analyze,build

class NaturalTitleTests(unittest.TestCase):
    def setUp(self):
        status=next(r for r in read(HERE/'rea-runtime.json')['records'] if r['operation']=='frida_session_status')
        self.events=[dict(m['payload'],script_id=m['script_id']) for m in status['normalized_result']['messages']]
        self.snapshots=rows(HERE/'state.jsonl.gz');self.paths=rows(HERE/'paths.jsonl.gz')
        self.saved=read(HERE/'saved-main.json');self.baseline=read(HERE/'baseline.json');self.post=read(HERE/'post-state.json')
    def result(self):return analyze(self.events,self.snapshots,self.paths,self.saved,self.baseline,self.post)
    def test_capture(self):self.assertEqual(build(),read(HERE/'results.json'))
    def test_backup_save_rejected(self):
        next(e for e in self.events if e['kind']=='save_write_enter')['data']['isBackup']=True
        with self.assertRaisesRegex(ValueError,'PC main save'):self.result()
    def test_wrong_title_slot_rejected(self):
        [e for e in self.events if e['kind']=='title_slot_enter'][-1]['data']['slot']=0
        with self.assertRaisesRegex(ValueError,'Wrong title slot'):self.result()
    def test_wrong_decrypted_pose_rejected(self):
        self.saved['playerPosition'][0]+=1
        with self.assertRaisesRegex(ValueError,'Saved-file pose'):self.result()
    def test_wrong_warp_argument_rejected(self):
        [e for e in self.events if e['kind']=='player_warp'][-1]['data']['rotation'][1]+=0.1
        with self.assertRaisesRegex(ValueError,'Original Warp'):self.result()
    def test_missing_main_file_rejected(self):
        self.post['disposable_profile']=[f for f in self.post['disposable_profile'] if not f['path'].endswith('SaveData\\1.sd')]
        with self.assertRaisesRegex(ValueError,'Main file changed/missing'):self.result()
    def test_false_npc_positive_rejected(self):
        self.events.append(dict(kind='npc_load_enter',frame=11000,data={}))
        with self.assertRaisesRegex(ValueError,'Default startup path'):self.result()
    def test_wrong_active_manager_rejected(self):
        target=next(s for s in self.snapshots if s['kind']=='snapshot' and s['frame']>=10763 and s['data']['actualPlayer'] is not None)
        target['data']['manager']='1'
        with self.assertRaisesRegex(ValueError,'active-manager readiness'):self.result()

if __name__=='__main__':unittest.main()
