import copy,unittest
from analyze import HERE,read,rows,analyze,build
class AppearanceDetailTests(unittest.TestCase):
    def setUp(self):
        n=next(r['normalized_result'] for r in read(HERE/'rea-runtime.json')['records'] if r['operation']=='frida_session_status');self.events=[m['payload'] for m in n['messages']];self.managed=rows(HERE/'managed.jsonl.gz');self.files=read(HERE/'saved-files.json')['files']
    def result(self):return analyze(self.managed,self.events,self.files)
    def test_capture(self):self.assertEqual(build(),read(HERE/'results.json'))
    def test_wrong_stored_rgb(self):
        self.files[0]['fields']['CustomizeSkinColorR']+=1
        with self.assertRaisesRegex(ValueError,'Saved/loaded appearance'):self.result()
    def test_wrong_material(self):
        next(r for r in self.managed if r['kind']=='restore_immediate')['data']['snapshot']['materials'][0]['color'][0]+=.1
        with self.assertRaisesRegex(ValueError,'Restored material'):self.result()
    def test_wrong_face_weight(self):
        next(r for r in self.managed if r['kind']=='restore_immediate')['data']['snapshot']['shapes'][0]['value']+=1
        with self.assertRaisesRegex(ValueError,'Restored face'):self.result()
    def test_wrong_inverse_scale(self):
        next(r for r in self.managed if r['kind']=='result')['data']['snapshot']['bones'][0]['scale'][0]+=.2
        with self.assertRaisesRegex(ValueError,'inverse scale'):self.result()
    def test_duplicate_deferred_callback(self):
        self.events.append(copy.deepcopy(next(e for e in self.events if e['kind']=='bone_next_frame')))
        with self.assertRaisesRegex(ValueError,'callback count'):self.result()
    def test_early_deferred_callback(self):
        next(e for e in self.events if e['kind']=='bone_next_frame')['frame']-=1
        with self.assertRaisesRegex(ValueError,'phase offset'):self.result()
    def test_late_update_cannot_assume_one_frame(self):
        next(e for e in self.events if e['kind']=='bone_next_frame' and e['data']['name'].endswith('/restore'))['frame']-=1
        with self.assertRaisesRegex(ValueError,'phase offset'):self.result()
    def test_unrestored_original_fields(self):
        next(r for r in self.managed if r['kind']=='cleanup')['data']['fieldsRestored']=False
        with self.assertRaisesRegex(ValueError,'Cleanup flags'):self.result()
if __name__=='__main__':unittest.main()
