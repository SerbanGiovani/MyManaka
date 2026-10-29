import copy,json,unittest
from analyze import build,require
from project import codec,diff,digest
class EvidenceTests(unittest.TestCase):
    def test_complete_batch(self):
        r=build();self.assertEqual(len(r['cases']),12);self.assertEqual(r['total_serialized_declared_fields'],256)
    def test_numeric_string_keys_differ(self):self.assertNotEqual(digest(codec.ObjectPairs([(1,False)])),digest(codec.ObjectPairs([('1',False)])))
    def test_object_order_ignored(self):self.assertEqual(digest(codec.ObjectPairs([('a',1),('b',2)])),digest(codec.ObjectPairs([('b',2),('a',1)])))
    def test_duplicate_key_rejected(self):
        with self.assertRaises(AssertionError):digest(codec.ObjectPairs([('a',1),('a',2)]))
    def test_empty_and_missing_differ(self):self.assertTrue(diff(codec.ObjectPairs([]),codec.ObjectPairs([('a',codec.ObjectPairs([]))])))
    def test_bool_int_distinct_in_hash(self):self.assertNotEqual(digest(True),digest(1));self.assertTrue(diff(True,1))
if __name__=='__main__':unittest.main()
