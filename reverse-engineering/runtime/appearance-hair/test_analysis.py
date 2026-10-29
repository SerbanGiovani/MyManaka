import copy,unittest
from analyze import HERE,read,rows,analyze,build
class HairTests(unittest.TestCase):
    def setUp(self):
        n=next(r['normalized_result'] for r in read(HERE/'rea-runtime.json')['records'] if r['operation']=='frida_session_status');self.events=[m['payload'] for m in n['messages']];self.managed=rows(HERE/'managed.jsonl.gz');self.files=read(HERE/'saved-files.json')['files']
    def result(self):return analyze(self.managed,self.events,self.files)
    def test_capture(self):self.assertEqual(build(),read(HERE/'results.json'))
    def test_wrong_dictionary_value(self):
        self.files[0]['data'][0]['rgb'][0]+=1
        with self.assertRaisesRegex(ValueError,'dictionary restore'):self.result()
    def test_warm_failure_cannot_be_erased(self):
        w=next(r for r in self.managed if r['kind']=='warm_result')['data']['snapshot']
        for o in w['objects']:o['active']=o['id']==0
        with self.assertRaisesRegex(ValueError,'mismatch was masked'):self.result()
    def test_duplicate_model_rejected(self):
        x=next(r for r in self.managed if r['kind']=='result')['data']['snapshot'];next(o for o in x['objects'] if o['id']==1)['active']=True
        with self.assertRaisesRegex(ValueError,'model missing/duplicate'):self.result()
    def test_wrong_material(self):
        x=next(r for r in self.managed if r['kind']=='result')['data']['snapshot'];next(h for h in x['receivers'] if h['hair']==0 and h['initialized'])['color'][0]+=.1
        with self.assertRaisesRegex(ValueError,'RGB material'):self.result()
    def test_wrong_texture(self):
        x=next(r for r in self.managed if r['kind']=='result')['data']['snapshot'];next(h for h in x['receivers'] if h['hair']==0 and h['initialized'])['texture']='0'
        with self.assertRaisesRegex(ValueError,'texture reference'):self.result()
    def test_wrong_reconciliation_source(self):
        next(r for r in self.managed if r['kind']=='reconciliation')['data']['actual']=0
        with self.assertRaisesRegex(ValueError,'reconciliation source'):self.result()
    def test_duplicate_load(self):
        self.events.append(copy.deepcopy(next(e for e in self.events if e['kind']=='native_load')))
        with self.assertRaisesRegex(ValueError,'Save/Load phase'):self.result()
if __name__=='__main__':unittest.main()
