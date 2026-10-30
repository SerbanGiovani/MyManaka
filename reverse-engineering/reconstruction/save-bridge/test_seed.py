"""Selected original-field and write-target regression checks; no engine/game executes."""
import json,math,unittest
from prepare_seed import HERE,DEFAULT_SOURCE,DEFAULT_SHA,project,sha,f32,vector,validate_destinations,save_codec
class SeedTests(unittest.TestCase):
 def test_actual_original_projection(self):
  seed,detail=project();self.assertEqual(sha(DEFAULT_SOURCE),DEFAULT_SHA);self.assertEqual(seed['sceneKey'],'Apartment');self.assertEqual(seed['bodyPaintRemaining'],f32(118.798912));self.assertTrue(seed['bodyPaintReusable']);self.assertEqual(detail['slot'],1)
 def test_original_inventory_preserves_zero_presence(self):
  seed,_=project();items={x['id']:x['count'] for x in seed['inventory']};self.assertIn(5,items);self.assertEqual(items[5],0);self.assertEqual((items[8],items[9]),(1,1));self.assertEqual(len(items),12)
 def test_original_rotation_is_quaternion(self):
  seed,_=project();self.assertEqual(set(seed['rotation']),{'x','y','z','w'});self.assertAlmostEqual(sum(x*x for x in seed['rotation'].values()),1,places=6)
 def test_cannot_interpret_quaternion_as_euler(self):
  value=save_codec.ObjectPairs([('x',0),('y',0),('z',0),('w',1)])
  with self.assertRaises(ValueError):vector(value,['x','y','z'])
 def test_nonfinite_pose_is_rejected(self):
  with self.assertRaises(ValueError):f32(float('nan'))
 def test_wrong_cipher_identity_is_rejected(self):
  with self.assertRaises(ValueError):project(DEFAULT_SOURCE,'0'*64)
 def test_seed_cannot_overwrite_source(self):
  with self.assertRaises(ValueError):validate_destinations(DEFAULT_SOURCE,DEFAULT_SOURCE,HERE/'.cache/manifest.json')
 def test_manifest_cannot_overwrite_source(self):
  with self.assertRaises(ValueError):validate_destinations(DEFAULT_SOURCE,HERE/'.cache/seed.json',DEFAULT_SOURCE)
 def test_seed_and_manifest_are_distinct(self):
  with self.assertRaises(ValueError):validate_destinations(DEFAULT_SOURCE,HERE/'.cache/seed.json',HERE/'.cache/seed.json')
 def test_seed_is_reproducible_and_valid_json(self):
  a,_=project();b,_=project();self.assertEqual(json.dumps(a,sort_keys=True,allow_nan=False),json.dumps(b,sort_keys=True,allow_nan=False));self.assertEqual(a['fileKind'],'ReconstructedManakaSeed');self.assertEqual(a['revision'],0)
if __name__=='__main__':unittest.main()
