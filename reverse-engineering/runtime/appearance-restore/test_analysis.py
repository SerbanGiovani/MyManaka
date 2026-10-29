import copy,unittest
from analyze import HERE,read,rows,analyze,build
class AppearanceTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.managed=rows(HERE/'managed.jsonl.gz');cls.files=read(HERE/'saved-files.json')['files'];s=next(r['normalized_result'] for r in read(HERE/'rea-runtime.json')['records'] if r['operation']=='frida_session_status');cls.events=[m['payload'] for m in s['messages']]
    def test_three_cases(self):self.assertEqual(len(build()['cases']),3)
    def test_wrong_saved_height_rejected(self):
        f=copy.deepcopy(self.files);f[0]['height']=119
        with self.assertRaises((ValueError,StopIteration)):analyze(self.managed,self.events,f)
    def test_wrong_avatar_scale_rejected(self):
        m=copy.deepcopy(self.managed);next(r for r in m if r['kind']=='result')['data']['snapshot']['avatarScale'][0]+=0.1
        with self.assertRaisesRegex(ValueError,'Transform scale differs'):analyze(m,self.events,self.files)
    def test_duplicate_bone_callback_rejected(self):
        e=copy.deepcopy(self.events);e.append(copy.deepcopy(next(r for r in e if r['kind']=='bone_next_frame')))
        with self.assertRaisesRegex(ValueError,'callback count differs'):analyze(self.managed,e,self.files)
    def test_same_frame_bone_callback_rejected(self):
        e=copy.deepcopy(self.events);next(r for r in e if r['kind']=='bone_next_frame')['frame']-=1
        with self.assertRaisesRegex(ValueError,'next frame'):analyze(self.managed,e,self.files)
if __name__=='__main__':unittest.main()
