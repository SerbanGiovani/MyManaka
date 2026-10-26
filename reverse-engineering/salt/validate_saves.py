"""Capture encrypted clone samples, or reproduce their read-only validation."""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import platform

import cryptography
from save_codec import ObjectPairs, read as read_save, reencrypt
from metadata import HERE

OUTPUT=HERE/'evidence/save-codec-validation.json'
CACHE=HERE/'.cache/save-codec'


def digest(data):return hashlib.sha256(data).hexdigest()


def load(p):return json.loads(p.read_text(encoding='utf-8-sig'))


def summarize(data,password):
    plaintext,root,reader=read_save(data,password)
    schemas=load(HERE/'symbols/save-declarations.json')
    by_name={t['name'].rsplit('.',1)[-1]:t for t in schemas['types'] if t['type_id'] in schemas['root_type_ids']}
    entries=[];shape_counts=Counter()
    def walk(value):
        shape_counts[type(value).__name__]+=1
        if isinstance(value,ObjectPairs):
            for k,v in value.entries:walk(k);walk(v)
        elif isinstance(value,list):
            for v in value:walk(v)
    walk(root)
    for key,value in root.strings().items():
        if not isinstance(value,ObjectPairs):raise ValueError('Expected ES3 root envelope')
        envelope=value.strings()
        assert set(envelope)=={'__type','value'} and isinstance(envelope['__type'],str)
        item=dict(key=key,stored_type=envelope['__type'],value_kind=type(envelope['value']).__name__)
        if key in by_name:
            assert envelope['__type'].split(',')[0]==by_name[key]['name']
            members=envelope['value'].strings()
            declared={f['name'] for f in by_name[key]['fields']}
            actual=set(members)
            item.update(declared_type_id=by_name[key]['type_id'],stored_fields=len(actual),declared_fields=len(declared),
                missing_fields=sorted(declared-actual),additional_fields=sorted(actual-declared),
                all_declared_fields_present=actual==declared,stored_type_matches_declaration=True)
        entries.append(item)
    strict=True
    try:json.loads(plaintext.decode('utf-8-sig'))
    except json.JSONDecodeError:strict=False
    # This only proves codec byte compatibility on the same plaintext and IV.
    # No file is written and the game is not invoked for an object roundtrip.
    assert reencrypt(plaintext,password,data[:16])==data
    return dict(encrypted_bytes=len(data),encrypted_sha256=digest(data),
        iv_hex=data[:16].hex(),plaintext_bytes=len(plaintext),plaintext_sha256=digest(plaintext),
        utf8_bom=plaintext.startswith(b'\xef\xbb\xbf'),text_consumed=reader.position,
        numeric_dictionary_keys=reader.numeric_key_count,strict_json_accepted=strict,
        shapes=dict(sorted(shape_counts.items())),keys=entries,reencryption_matches_original=True)


def sources():
    names=['salt/save_codec.py','salt/validate_saves.py','assets/save-settings.json',
           'salt/symbols/save-declarations.json']
    return [dict(path=p,sha256=digest((HERE.parent/p).read_bytes())) for p in names]


def build(samples):
    settings=load(HERE.parent/'assets/save-settings.json')['defaults_object']['settings']
    assert settings['encryptionType']['enum_name']=='AES' and settings['compressionType']['enum_name']=='None'
    password=settings['encryptionPassword']['value']
    results=[]
    for sample in samples:
        data=Path(sample['snapshot_path']).read_bytes()
        assert digest(data)==sample['captured_sha256']
        results.append(dict(sample=sample,**summarize(data,password)))
    return dict(schema_version=1,evidence_type='Independent offline AES envelope and selected ES3 structural read of encrypted clone snapshots',
        sources=sources(),implementation=dict(python=platform.python_version(),cryptography=cryptography.__version__),
        samples=results,summary=dict(samples=len(results),root_entries=sum(len(r['keys']) for r in results),
            numeric_dictionary_keys=sum(r['numeric_dictionary_keys'] for r in results),
            reencryption_matches=sum(r['reencryption_matches_original'] for r in results),
            roots_with_all_declared_fields=sum(k.get('all_declared_fields_present',False) for r in results for k in r['keys'])),
        limitations=['Encrypted samples and all plaintext remain outside tracked artifacts; only hashes, type names, keys and schema coverage are retained.',
            'Captured source hashes were checked before/after reading; future runs use immutable cache snapshots, not changing game files.',
            'Re-encryption is in-memory with the original IV; it is not a game-object save/load roundtrip or a fresh-IV writer.',
            'Structural parsing covers the observed string/numeric-key grammar; references, object constructors, defaults, migrations and arbitrary ES3 features are not restored.'])


def capture(root):
    CACHE.mkdir(parents=True,exist_ok=True)
    rows=[]
    for folder in ('SaveData','SaveDataBackup'):
        for path in sorted((root/folder).glob('*.sd')):
            before=path.read_bytes();fingerprint=digest(before)
            dest=CACHE/(fingerprint+'.sd')
            if dest.exists():assert dest.read_bytes()==before
            else:dest.write_bytes(before)
            assert digest(path.read_bytes())==fingerprint,'Source changed during capture'
            rows.append(dict(original_path=str(path.resolve()),snapshot_path=str(dest.resolve()),
                captured_sha256=fingerprint,source_unchanged_during_capture=True))
    assert rows
    return rows


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--capture-root',type=Path)
    p.add_argument('--check',action='store_true')
    a=p.parse_args()
    if a.check and a.capture_root:p.error('Check mode never captures')
    saved=load(OUTPUT) if OUTPUT.exists() else None
    samples=capture(a.capture_root) if a.capture_root else [r['sample'] for r in saved['samples']]
    result=build(samples)
    if a.check:assert result==saved,'Save validation differs'
    else:OUTPUT.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(status='consistent' if a.check else 'written',**result['summary'])))


if __name__=='__main__':main()
