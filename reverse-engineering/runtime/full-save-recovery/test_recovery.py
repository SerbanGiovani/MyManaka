import unittest
from unittest.mock import patch
import analyze_recovery as analysis
class RecoveryTests(unittest.TestCase):
    def test_complete_batch(self):self.assertEqual(analysis.build()['verified_getter_scalar_values'],180)
    def test_changed_original_getter_rejected(self):
        original=analysis.rows
        def altered(p):
            value=original(p)
            if p.name=='managed.jsonl.gz':next(r for r in value if r['kind']=='consumers')['data']['skills'][0]['level']+=1
            return value
        with patch.object(analysis,'rows',side_effect=altered),self.assertRaisesRegex(ValueError,'getter results differ'):analysis.build()
    def test_changed_copy_source_rejected(self):
        original=analysis.read
        def altered(p):
            value=original(p)
            if p.name=='rea-runtime.json':
                status=next(r for r in value['records'] if r['operation']=='frida_session_status' and r['normalized_result']['pid']==47188)
                next(m for m in status['normalized_result']['messages'] if m['payload']['kind']=='copy_enter')['payload']['data']['source']['text']+='wrong'
            return value
        with patch.object(analysis,'read',side_effect=altered),self.assertRaisesRegex(ValueError,'Copy source/target differs'):analysis.build()
    def test_unstable_second_game_rejected(self):
        original=analysis.read
        def altered(p):
            value=original(p)
            if p.name=='projection.json':value['cases'][0]['game_first_to_second']=[{'unexpected':'change'}]
            return value
        with patch.object(analysis,'read',side_effect=altered),self.assertRaisesRegex(ValueError,'Second game roundtrip differs'):analysis.build()
if __name__=='__main__':unittest.main()
