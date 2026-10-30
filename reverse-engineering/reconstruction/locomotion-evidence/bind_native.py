"""Bind this directory's REA results to original IL2CPP method/parameter bytes."""
import sys
sys.dont_write_bytecode=True
import argparse
import hashlib
import json
import sqlite3
import struct
from pathlib import Path

HERE=Path(__file__).resolve().parent
RE=HERE.parents[1]
sys.path.insert(0,str(RE/'salt'))
from metadata import Metadata,PE

def sha(path): return hashlib.sha256(path.read_bytes()).hexdigest()

def build():
    original=Path('E:/SecretFlasherManakaREA')
    dll=original/'GameAssembly.dll'
    meta=original/'SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat'
    native=dll.read_bytes();raw=meta.read_bytes();pe=PE(native);md=Metadata(raw)
    assert sha(dll)=='6003033049ac32e8712dc4101382534e21d65b97100c167ebec6bbca1462c18d'
    assert sha(meta)=='457203754abe77b346fd98086a5c787bd41088d808cc81b1d4e2cae5b85c72c8'
    definitions=md.records(12,'<6iI4H');params=md.records(22,'<iIi')
    layout=json.loads((RE/'salt/symbols/field-offsets.json').read_text(encoding='utf8'))
    runtime=layout['registration']['pointer_tables']['runtime_types']
    def runtime_type(index):
        off=runtime['file_offset']+index*8;ptr=struct.unpack_from('<Q',native,off)[0];r=pe.offset(ptr,12);data,bits=struct.unpack_from('<QI',native,r)
        return {'runtime_type_index':index,'pointer_file_offset':off,'type_va':hex(ptr),'type_file_offset':r,'type_raw_hex':native[r:r+12].hex(),'type_enum':(bits>>16)&255,'data':data,'attributes':bits&65535}
    conn=sqlite3.connect((RE/'salt/.cache/methods.sqlite').resolve().as_uri()+'?mode=ro',uri=True);conn.row_factory=sqlite3.Row
    methods={r['id']:dict(r) for r in conn.execute('SELECT * FROM methods')};conn.close()
    observations=[]
    runs=[]
    for dirname in ['native','native-decoded-code']:
        rp=HERE/dirname/'run.json'
        if not rp.exists():continue
        run=json.loads(rp.read_text(encoding='utf8'));assert run['success']
        plan=json.loads(Path(run['plan']).read_text(encoding='utf8'));assert sha(Path(plan['seed_file']))==plan['seed_sha256']==run['seed_sha256']
        runs.append({'path':str(rp),'sha256':sha(rp),'queries':len(run['functions']),'elapsed_seconds':run['elapsed_seconds'],'closed_without_error':not run.get('close_error') and not run.get('transport_close_error')})
        for f in run['functions']:
            method=methods[f['metadata_id']];record=definitions[method['id']];definition_size=struct.calcsize('<6iI4H');off=md.header[12]+method['id']*definition_size
            assert struct.unpack_from('<6iI4H',raw,off)==record
            assert method['va']==f['va'] and method['token']==int(f['token'],16)==record[6]
            assert method['name']==md.string(record[0]) and method['type_id']==record[1]
            assert method['file_offset']==pe.offset(int(method['va'],16),executable=True)
            ep=HERE/dirname/(f['file_stem']+'-'+f['operation']+'.json');ev=json.loads(ep.read_text(encoding='utf8'))
            assert ev['subject']['digest']['sha256']==sha(dll) and ev['evidence_id']==f['evidence_id']
            pp=[]
            for pid in range(record[4],record[4]+record[10]):
                poff=md.header[22]+pid*12
                pp.append({'name':md.string(params[pid][0]),'metadata_file_offset':poff,'raw_hex':raw[poff:poff+12].hex(),'type':runtime_type(params[pid][2])})
            observations.append({'method_id':method['id'],'qualified_name':method['qualified_name'],'va':method['va'],'file_offset':method['file_offset'],'token':f['token'],'metadata_file_offset':off,'metadata_raw_hex':raw[off:off+definition_size].hex(),'parameters':pp,'return_type':runtime_type(record[2]),'native_address_aliases':[{'method_id':m['id'],'name':m['qualified_name']} for m in methods.values() if m['va']==method['va']],'operation':f['operation'],'evidence_id':f['evidence_id'],'evidence_path':str(ep),'evidence_file_sha256':sha(ep),'nonempty_result':bool(ev['normalized_result'])})
    reused=[]
    for name,ids in [('player-chain',[14421,14757,14894,14899,14900,14901,14906,17228]),('animator-chain',[14525,14526,14553])]:
        p=RE/'salt/evidence'/f'{name}.json';d=json.loads(p.read_text(encoding='utf8'))
        for m in d['methods']:
            if m['method_id'] in ids:
                reused.append({'method_id':m['method_id'],'name':m['name'],'va':m['va'],'evidence_id':m['evidence_id'],'canonical_path':str(RE/m['path']),'source_chain_path':str(p),'source_chain_sha256':sha(p)})
    return {'schema_version':1,'authority':'shipped-artifact','native':{'path':str(dll),'sha256':sha(dll)},'metadata':{'path':str(meta),'sha256':sha(meta)},'runs':runs,'new_observations':observations,'reused_observations':reused,'limitations':['Static Ghidra decompilation and listing; no execution or timing observations.','Native addresses may have multiple metadata methods; the selected metadata method is not established by the Ghidra display label alone.','The first native batch has empty assembly results for seven seeded function listings; these empty records are retained explicitly and are not used to prove instruction arithmetic. The decoded-code batch adds explicit code seeds.','Float/stack ABI artifacts in pseudocode require instruction corroboration before adopting exact arithmetic.','Metadata pointer coordinates and serialized controller hashes belong to this exact native/metadata/asset identity.']}

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--check',action='store_true');a=ap.parse_args();result=build();out=HERE/'native-contract.json'
    if a.check:assert json.loads(out.read_text(encoding='utf8'))==result
    else:out.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps({'status':'consistent' if a.check else 'written','new_observations':len(result['new_observations']),'reused_observations':len(result['reused_observations'])}))

if __name__=='__main__':main()
