"""Bind shipped ES3 settings, selected native codec paths and snapshot checks."""
import argparse
from collections import defaultdict
import hashlib
import json
import re
import sqlite3

from metadata import HERE, DEFAULT_ROOT, Metadata
from scene_evidence import build as bind, read


def fingerprint(p):
    return dict(path=p.relative_to(HERE.parent).as_posix(),sha256=hashlib.sha256(p.read_bytes()).hexdigest())


def build():
    result=bind(batch_prefix='save-codec-',reuse_method_ids={11779,11783,13102,13103,17409,17422,16968,16969,16970,16971},
        extra_type_names=('ES3Settings','ES3Defaults','ES3SerializableSettings','ES3Reader','ES3Writer','ES3IO',
            'ES3Type','ES3JSONReader','ES3JSONWriter','AESEncryptionAlgorithm','ES3CryptoStream',
            'Rfc2898DeriveBytes','Aes','AesManaged','AesCryptoServiceProvider','SymmetricAlgorithm','HashAlgorithmName'),
        dispatch_targets=[],resource_boundary='Static codec/settings plus independent encrypted-snapshot reads; no original-engine object roundtrip.')
    assert result['new_observations']==result['new_unique_procedure_addresses']==56
    assets=read(HERE.parent/'assets/save-settings.json')
    validation=read(HERE/'evidence/save-codec-validation.json')
    identity=read(HERE/'evidence/artifact-identity.json')
    assert assets['original_metadata']['native_source']['sha256']==identity['native_sha256']
    assert assets['original_metadata']['source']['sha256']==identity['metadata_sha256']
    settings=assets['defaults_object']['settings']
    assert assets['defaults_object']['end_of_object_verified']
    assert settings['encryptionType']['enum_name']=='AES' and settings['format']['enum_name']=='JSON'
    assert settings['compressionType']['enum_name']=='None'
    result['shipped_settings']=dict(resource_key=assets['resource_manager']['selected_entry']['key']['value'],
        object_source=assets['defaults_object']['source'],bytes_consumed=assets['defaults_object']['bytes_consumed'],
        settings={k:dict(value=v['value'],serialized_offset=v['serialized_offset'],
            registered_offset=v['registered_offset'],field_id=v['field_id'],enum_name=v.get('enum_name')) for k,v in settings.items()})
    c=sqlite3.connect((HERE/'.cache/methods.sqlite').as_uri()+'?mode=ro',uri=True)
    c.row_factory=sqlite3.Row
    by_va=defaultdict(list)
    for row in c.execute('SELECT id,qualified_name,type_id,va FROM methods WHERE va IS NOT NULL'):
        by_va[row['va']].append(dict(row))
    c.close()
    for method in result['methods']:
        code=read(HERE.parent/method['path'])['normalized_result']
        # Preserve library aliases that the general gameplay binder omits.
        method['all_named_fun_targets']=[dict(va=va,aliases=by_va[va])
            for va in sorted({'0x'+s for s in re.findall(r'FUN_([0-9a-f]+)\s*\(',code)}) if va in by_va]
    usages={u['va']:u for u in result['usages']}
    assert usages['0x182d527a0']['value']=='ES3/ES3Defaults'
    spec=usages['0x182d527a8']['method_spec']
    assert spec['method_name']=='UnityEngine.Resources::Load'
    args=spec['method_instantiation']['arguments']
    assert len(args)==1 and args[0]['type_name']=='ES3Defaults'
    result['resource_load_generic']=dict(path_usage=usages['0x182d527a0'],method_spec_usage=usages['0x182d527a8'],
        native_helper_va='0x1809fce30',boundary='Caller usage supplies the closed type; shared helper alone does not identify a receiver.')
    md_bytes=(DEFAULT_ROOT/'SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat').read_bytes()
    md=Metadata(md_bytes);types=md.records(40,'<16i8H2I');fields=md.records(24,'<iiI')
    definitions=md.records(12,'<6iI4H');defaults={r[0]:(i,r) for i,r in enumerate(md.records(16,'<iii'))}
    import sys
    sys.path.insert(0,str(HERE.parent/'assets'))
    from inspect_player import compressed_int32
    constants=[]
    for tid,t in enumerate(types):
        if md.string(t[1])!='System.Security.Cryptography' or md.string(t[0]) not in ('CipherMode','PaddingMode'):
            continue
        values=[]
        for fid in range(t[8],t[8]+t[18]):
            if fid not in defaults:continue
            index,(_,_,data)=defaults[fid]
            value=compressed_int32(md_bytes,md.header[18]+data)
            values.append(dict(field_id=fid,name=md.string(fields[fid][0]),**value,
                default_record_offset=md.header[16]+12*index,
                default_record_raw_hex=md_bytes[md.header[16]+12*index:md.header[16]+12*(index+1)].hex()))
        constants.append(dict(type_id=tid,name=md.string(t[0]),values=values))
    assert next(v['decoded_int32'] for t in constants if t['name']=='CipherMode' for v in t['values'] if v['name']=='CBC')==1
    assert next(v['decoded_int32'] for t in constants if t['name']=='PaddingMode' for v in t['values'] if v['name']=='PKCS7')==2
    result['crypto_enum_constants']=constants
    # Virtual slot declarations identify indirect calls in the selected AES bodies.
    targets=[('System.Security.Cryptography','SymmetricAlgorithm',n) for n in ('set_Mode','set_Padding','get_IV','set_IV','set_Key','GenerateIV','CreateEncryptor','CreateDecryptor')]
    targets += [('System.Security.Cryptography','Rfc2898DeriveBytes','GetBytes')]
    slots=[]
    for namespace,owner,name in targets:
        tid,t=next((i,t) for i,t in enumerate(types) if md.string(t[0])==owner and md.string(t[1])==namespace)
        for mid in range(t[9],t[9]+t[16]):
            d=definitions[mid]
            if md.string(d[0])==name:
                slots.append(dict(method_id=mid,name=namespace+'.'+owner+'::'+name,slot=d[9],parameter_count=d[10],
                    metadata_file_offset=md.header[12]+mid*36,raw_hex=md_bytes[md.header[12]+mid*36:md.header[12]+(mid+1)*36].hex()))
    result['crypto_virtual_declarations']=slots
    result['envelope_contract']=dict(prefix_iv_bytes=16,kdf_salt='same16-byte IV',password_encoding='UTF-8',
        kdf='PBKDF2-HMAC-SHA1',iterations=100,key_bytes=16,cipher='AES-128-CBC',padding='PKCS7',compression='None',
        method_ids=[12879,12880,5473,5471,5476,5477,5479,5544,5555,5556,5812],
        boundary='Selected native paths and eight captured samples; no runtime cipher factory object or fresh game save was observed.')
    result['independent_validation']=dict(summary=validation['summary'],
        result=fingerprint(HERE/'evidence/save-codec-validation.json'),
        boundary='Encrypted snapshots only in ignored cache; plaintext stays in memory. Stored root fields/type headers are compared; no object construction/reference restoration.')
    result['sources']=[fingerprint(HERE.parent/p) for p in (
        'salt/save_codec_evidence.py','salt/scene_evidence.py','salt/metadata.py','salt/prepare_loading.py','salt/run_batch.mjs',
        'assets/inspect_save_settings.py','assets/inspect_player.py','assets/inspect_scenes.py','assets/inspect_resources.py',
        'assets/save-settings.json','salt/save_codec.py','salt/validate_saves.py','salt/test_save_codec.py',
        'salt/evidence/save-codec-validation.json','salt/symbols/save-declarations.json')]
    for batch in ('core','tail','format'):
        result['sources'] += [fingerprint(HERE/('symbols/save-codec-'+batch+suffix)) for suffix in ('.plan.json','.seeds.tsv')]
    result['scope']='Shipped ES3Defaults, default copy/path/stream/reader selection, selected AES derivation and dictionary text syntax, independent captured-save decoding.'
    result['limitations'] += ['Eight decoded samples demonstrate the selected envelope/grammar, not all historical or modded saves.',
        'System-key types are observed in stored envelopes; complete constructors, migrations and game restore behavior remain separate.',
        'No game files or source saves are modified, and no independently runnable replacement game is produced.']
    return result


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--check',action='store_true');a=p.parse_args()
    result=build();path=HERE/'evidence/save-codec-chain.json'
    if a.check:assert read(path)==result
    else:path.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(status='consistent' if a.check else 'written',queries=result['new_observations'],
        samples=result['independent_validation']['summary']['samples'])))


if __name__=='__main__':main()
