"""Check typed-key parsing, UTF8 derivation and corrupt-envelope rejection."""
import unittest

from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC
from save_codec import ObjectPairs, SaveTextReader, derive_key, decrypt, reencrypt


class SaveCodecTests(unittest.TestCase):
    def test_numeric_and_string_keys_remain_distinct(self):
        r=SaveTextReader('{1:false,"1":true,1.5:[null,{8:"値"}]}')
        obj=r.parse()
        self.assertEqual([type(k) for k,_ in obj.entries],[int,str,float])
        self.assertEqual(r.numeric_key_count,3)
        self.assertEqual(obj.entries[2][1][1].entries,[(8,'値')])
        with self.assertRaises(ValueError):obj.strings()

    def test_order_and_duplicates_are_retained(self):
        obj=SaveTextReader('{"x":1,"x":2}').parse()
        self.assertEqual(obj.entries,[('x',1),('x',2)])
        with self.assertRaises(ValueError):obj.strings()

    def test_escaped_string_delimiters(self):
        obj=SaveTextReader(r'{"x":"a\"b:{8:2}\\\n\u65e5"}').parse()
        self.assertEqual(obj.strings()['x'],'a"b:{8:2}\\\n日')

    def test_malformed_text_is_rejected(self):
        for text in ['{x:1}','{true:1}','{"x":01}','{"x":1,}','[1,]','{} extra','{"x" 1}','[1 2]']:
            with self.subTest(text=text),self.assertRaises((ValueError,RecursionError)):
                SaveTextReader(text).parse()

    def test_explicit_depth_limit(self):
        with self.assertRaises(ValueError):SaveTextReader('['*130+'0'+']'*130).parse()

    def test_utf8_kdf_against_second_api(self):
        iv=bytes(range(16));password='検証あß'
        independent=PBKDF2HMAC(algorithm=hashes.SHA1(),length=16,salt=iv,iterations=100).derive(password.encode('utf8'))
        self.assertEqual(derive_key(password,iv),independent)

    def test_envelope_handles_empty_aligned_and_unaligned_plaintext(self):
        iv=bytes(range(16))
        for raw in (b'',b'x',b'x'*16,'{"x":"日本語"}'.encode()):
            with self.subTest(length=len(raw)):
                self.assertEqual(decrypt(reencrypt(raw,'test',iv),'test'),raw)

    def test_lengths_and_wrong_password_are_rejected(self):
        for data in (b'',b'x'*16,b'x'*31,b'x'*33):
            with self.subTest(length=len(data)),self.assertRaises(ValueError):decrypt(data,'test')
        data=reencrypt(b'fixed test value','test',bytes(range(16)))
        with self.assertRaises(ValueError):decrypt(data,'different')
        # Leave IV/KDF unchanged. Changing the preceding ciphertext block's
        # final byte turns this fixture's final padding byte16 into17.
        self.assertEqual(len(data),48)
        damaged=bytearray(data);damaged[-17]^=1
        with self.assertRaises(ValueError):decrypt(bytes(damaged),'test')


if __name__=='__main__':unittest.main()
