import copy
import unittest
from analyze import HERE,read,rows,analyze,build

class ColdCacheTests(unittest.TestCase):
    def setUp(self):
        s=next(r for r in read(HERE/'rea-runtime.json')['records'] if r['operation']=='frida_session_status')
        self.events=[m['payload'] for m in s['normalized_result']['messages']];self.managed=rows(HERE/'managed.jsonl.gz');self.stored=read(HERE/'native-save.json')
    def result(self):return analyze(self.managed,self.events,self.stored)
    def test_capture(self):self.assertEqual(build(),read(HERE/'results.json'))
    def test_not_cold_rejected(self):
        next(r for r in self.managed if r['kind']=='cold_before')['data']['cacheCount']=1
        with self.assertRaisesRegex(ValueError,'not cold'):self.result()
    def test_extra_clone_rejected(self):
        self.events.append(copy.deepcopy(next(e for e in self.events if e['kind']=='clone_enter')))
        with self.assertRaisesRegex(ValueError,'initialization count'):self.result()
    def test_asset_load_rejected(self):
        r=next(e for e in self.events if e['kind']=='restore_enter');self.events.append(dict(r,kind='asset_load_during_fixture'))
        with self.assertRaisesRegex(ValueError,'bundle asset load'):self.result()
    def test_other_stage_activation_rejected(self):
        next(r for r in self.managed if r['kind']=='cold_return')['data']['other']['active']=True
        with self.assertRaisesRegex(ValueError,'Activation/filter'):self.result()
    def test_live_stale_entry_rejected(self):
        next(r for r in self.managed if r['kind']=='stale_before')['data']['current']['alive']=True
        with self.assertRaisesRegex(ValueError,'No stale cached'):self.result()
    def test_wrong_saved_pose_rejected(self):
        self.stored['drops'][0]['position'][0]+=1
        with self.assertRaisesRegex(ValueError,'Pose differs'):self.result()
    def test_cleanup_rejected(self):
        next(r for r in self.managed if r['kind']=='cleanup')['data']['cacheRestored']=False
        with self.assertRaisesRegex(ValueError,'Cleanup failed'):self.result()

if __name__=='__main__':unittest.main()
