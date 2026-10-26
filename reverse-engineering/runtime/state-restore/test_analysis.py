"""Reject broken identity, pose, queue and cleanup claims in the real capture."""
import copy
import unittest
from analyze import HERE,read,rows,analyze,build


class RestoreEvidenceTests(unittest.TestCase):
    def setUp(self):
        self.managed=rows(HERE/'managed.jsonl.gz');bundle=read(HERE/'rea-runtime.json')
        status=next(r for r in bundle['records'] if r['operation']=='frida_session_status')
        self.events=[m['payload'] for m in status['normalized_result']['messages'] if m['type']=='send']
        self.stored=read(HERE/'native-save.json')

    def result(self):return analyze(self.managed,self.events,self.stored)

    def test_pinned_capture(self):self.assertEqual(build(),read(HERE/'results.json'))

    def test_wrong_disk_pose_rejected(self):
        self.stored['npcs'][0]['position'][0]+=1
        with self.assertRaisesRegex(ValueError,'Pose differs'):self.result()

    def test_same_root_rejected(self):
        fixture=next(x for x in self.managed if x['kind']=='fixture')
        loaded=next(x for x in self.managed if x['kind']=='loaded')
        loaded['data']['summary']['state']=fixture['data']['summary']['state']
        with self.assertRaisesRegex(ValueError,'original root'):self.result()

    def test_missing_warp_return_rejected(self):
        begin=next(x['frame'] for x in self.managed if x['kind']=='fixture')
        event=next(e for e in self.events if e['kind']=='native_npc_warp_leave' and e['frame']>=begin)
        self.events.remove(event)
        with self.assertRaisesRegex(ValueError,'native_npc_warp_leave'):self.result()

    def test_duplicate_reserved_drop_rejected(self):
        begin=next(x['frame'] for x in self.managed if x['kind']=='fixture')
        event=next(e for e in self.events if e['kind']=='native_drop_enter' and e['frame']>=begin and e['data']['item']==1)
        self.events.append(copy.deepcopy(event))
        with self.assertRaisesRegex(ValueError,'native_drop_enter'):self.result()

    def test_wrong_other_stage_removal_rejected(self):
        event=next(e for e in self.events if e['kind']=='reserve_predicate_leave' and e['data']['item']==3)
        event['data']['remove']=1
        with self.assertRaisesRegex(ValueError,'Other-stage reserve'):self.result()

    def test_missing_world_activation_rejected(self):
        next(x for x in self.managed if x['kind']=='runtime')['data']['current']['active']=False
        with self.assertRaisesRegex(ValueError,'activation differs'):self.result()

    def test_failed_cleanup_rejected(self):
        next(x for x in self.managed if x['kind']=='cleanup')['data']['mapRestored']=False
        with self.assertRaisesRegex(ValueError,'cleanup failed'):self.result()


if __name__=='__main__':unittest.main()
