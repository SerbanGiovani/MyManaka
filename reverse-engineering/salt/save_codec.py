"""Read the selected ES3 AES envelope and preserve typed dictionary keys.

No game assembly executes. This is a bounded structural reader, not ES3 object
construction, reference restoration, migration or an original-engine roundtrip.
"""
from dataclasses import dataclass
import hashlib
import json
import re

from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes


@dataclass
class ObjectPairs:
    entries: list

    def strings(self):
        result={}
        for key,value in self.entries:
            if not isinstance(key,str) or key in result:
                raise ValueError('Expected unique string members')
            result[key]=value
        return result


class SaveTextReader:
    """Selected ES3 text grammar: JSON values plus numeric dictionary keys."""
    NUMBER=re.compile(r'-?(?:0|[1-9][0-9]*)(?:\.[0-9]+)?(?:[eE][+-]?[0-9]+)?')

    def __init__(self,text):
        self.text=text
        self.position=0
        self.decoder=json.JSONDecoder()
        self.numeric_key_count=0

    def whitespace(self):
        while self.position<len(self.text) and self.text[self.position] in ' \t\r\n':
            self.position+=1

    def character(self,char):
        self.whitespace()
        if not self.text.startswith(char,self.position):
            raise ValueError('Expected '+repr(char)+' at character '+str(self.position))
        self.position+=len(char)

    def value(self,depth=0):
        if depth>128:
            raise ValueError('Selected structural reader depth exceeded')
        self.whitespace()
        if self.position>=len(self.text):
            raise ValueError('Unexpected end of text')
        char=self.text[self.position]
        if char=='"':
            value,self.position=self.decoder.raw_decode(self.text,self.position)
            return value
        if char=='{':
            self.position+=1; entries=[]; self.whitespace()
            if self.text.startswith('}',self.position):
                self.position+=1;return ObjectPairs(entries)
            while True:
                key=self.value(depth+1)
                if not isinstance(key,(str,int,float)) or isinstance(key,bool):
                    raise ValueError('Only string/numeric dictionary keys are covered')
                if not isinstance(key,str):self.numeric_key_count+=1
                self.character(':');value=self.value(depth+1);entries.append((key,value))
                self.whitespace()
                if self.text.startswith('}',self.position):
                    self.position+=1;return ObjectPairs(entries)
                self.character(',')
        if char=='[':
            self.position+=1;values=[];self.whitespace()
            if self.text.startswith(']',self.position):
                self.position+=1;return values
            while True:
                values.append(self.value(depth+1));self.whitespace()
                if self.text.startswith(']',self.position):
                    self.position+=1;return values
                self.character(',')
        for token,value in [('true',True),('false',False),('null',None)]:
            if self.text.startswith(token,self.position):
                self.position+=len(token);return value
        match=self.NUMBER.match(self.text,self.position)
        if match:
            self.position=match.end();lexeme=match[0]
            return float(lexeme) if any(c in lexeme for c in '.eE') else int(lexeme)
        raise ValueError('Unsupported token at character '+str(self.position))

    def parse(self):
        value=self.value();self.whitespace()
        if self.position!=len(self.text):raise ValueError('Trailing text')
        return value


def derive_key(password,iv):
    if len(iv)!=16:raise ValueError('Expected a16-byte IV/salt')
    return hashlib.pbkdf2_hmac('sha1',password.encode('utf-8'),iv,100,16)


def decrypt(data,password):
    if len(data)<32 or len(data)%16:raise ValueError('Invalid selected encrypted envelope length')
    iv=data[:16];key=derive_key(password,iv)
    decryptor=Cipher(algorithms.AES(key),modes.CBC(iv)).decryptor()
    padded=decryptor.update(data[16:])+decryptor.finalize()
    padding=padded[-1]
    if not 1<=padding<=16 or padded[-padding:]!=bytes([padding])*padding:
        raise ValueError('Invalid PKCS7 padding')
    return padded[:-padding]


def reencrypt(plaintext,password,iv):
    """Reproduce an existing envelope in memory using its retained IV."""
    key=derive_key(password,iv);padding=16-len(plaintext)%16
    encryptor=Cipher(algorithms.AES(key),modes.CBC(iv)).encryptor()
    return iv+encryptor.update(plaintext+bytes([padding])*padding)+encryptor.finalize()


def read(data,password):
    plaintext=decrypt(data,password)
    reader=SaveTextReader(plaintext.decode('utf-8-sig'))
    root=reader.parse()
    if not isinstance(root,ObjectPairs):raise ValueError('Expected root object')
    return plaintext,root,reader
