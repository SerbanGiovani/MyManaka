"""Resolve selected null generic method definitions through original registrations."""
import argparse
import hashlib
import json
from pathlib import Path
import sqlite3
import struct

from metadata import HERE, DEFAULT_ROOT, Metadata, PE
from save_declarations import PRIMITIVES

WANTED={12536,12537,12544,12545,12413,12414,11726,11734,11735,11737,11738,11739,11740,11741}


def read(p):return json.loads(p.read_text(encoding='utf-8-sig'))


def active(field,version=31):
    attrs=[a for a in field['attributes'] if a['type'].endswith('VersionAttribute')]
    if not attrs:return True
    return any(all((version>=float(s.split('=')[1]) if s.startswith('Min=') else version<=float(s.split('=')[1]))
                   for s in a['named_properties']) for a in attrs)


def build():
    native=(DEFAULT_ROOT/'GameAssembly.dll').read_bytes()
    metadata=(DEFAULT_ROOT/'SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat').read_bytes()
    identity=read(HERE/'evidence/artifact-identity.json')
    assert hashlib.sha256(native).hexdigest()==identity['native_sha256']
    assert hashlib.sha256(metadata).hexdigest()==identity['metadata_sha256']
    pe,md=PE(native),Metadata(metadata);types=md.records(40,'<16i8H2I')
    declarations=read(HERE/'symbols/save-parser-layouts.json')
    shape=next(t for t in declarations['types'] if t['name'].endswith('.Il2CppCodeRegistration'))
    fields=[f['name'] for f in shape['fields'] if active(f)]
    assert fields.index('codeGenModulesCount')==15 and fields.index('genericMethodPointers')==3
    c=sqlite3.connect((HERE/'.cache/methods.sqlite').as_uri()+'?mode=ro',uri=True)
    images={r[0] for r in c.execute('SELECT name FROM images')}
    methods={r[0]:r[1] for r in c.execute('SELECT id,qualified_name FROM methods')};c.close()
    count=len(images);candidates=[];pos=-1
    while True:
        pos=native.find(struct.pack('<Q',count),pos+1)
        if pos<0:break
        if pos<15*8:continue
        try:
            offset=pos-15*8
            values=struct.unpack_from('<'+str(len(fields))+'Q',native,offset)
            table=pe.offset(values[16],count*8)
            ptrs=struct.unpack_from('<'+str(count)+'Q',native,table);names=[]
            for pointer in ptrs:
                name_pointer=struct.unpack_from('<Q',native,pe.offset(pointer,8))[0]
                no=pe.offset(name_pointer);names.append(native[no:native.index(b'\0',no)].decode())
            if set(names)!=images or len(names)!=len(set(names)):continue
            assert 1000<values[2]<1000000
            candidates.append(dict(va=hex(pe.address(offset)),file_offset=offset,
                raw_hex=native[offset:offset+len(fields)*8].hex(),fields=dict(zip(fields,values)),module_names=names,
                module_table_file_offset=table,module_table_raw_hex=native[table:table+count*8].hex()))
        except (ValueError,UnicodeError,struct.error,AssertionError):continue
    assert len(candidates)==1, 'CodeRegistration must match the complete indexed image set uniquely'
    code=candidates[0];reg=read(HERE/'symbols/field-offsets.json')['registration']
    f=reg['fields'];spec_count=f['methodSpecsCount']['value'];spec_offset=pe.offset(f['methodSpecs']['value'],spec_count*12)
    table_count=f['genericMethodTableCount']['value'];table_offset=pe.offset(f['genericMethodTable']['value'],table_count*16)
    pointer_count=code['fields']['genericMethodPointersCount'];pointer_offset=pe.offset(code['fields']['genericMethodPointers'],pointer_count*8)
    rows=[]
    def type_name(pointer):
        off=pe.offset(pointer,12);data,bits=struct.unpack_from('<QI',native,off);kind=(bits>>16)&255
        n=PRIMITIVES.get(kind)
        if kind in (17,18):
            t=types[data];n='.'.join(filter(None,(md.string(t[1]),md.string(t[0]))))
        return dict(va=hex(pointer),file_offset=off,raw_hex=native[off:off+12].hex(),type_enum=kind,name=n)
    def inst(index):
        if index<0:return None
        assert index<f['genericInstsCount']['value']
        po=pe.offset(f['genericInsts']['value']+index*8,8);ptr=struct.unpack_from('<Q',native,po)[0]
        off=pe.offset(ptr,16);num,argv=struct.unpack_from('<QQ',native,off);assert num<32
        ao=pe.offset(argv,num*8);args=[type_name(v) for v in struct.unpack_from('<'+str(num)+'Q',native,ao)]
        return dict(index=index,pointer_file_offset=po,va=hex(ptr),file_offset=off,raw_hex=native[off:off+16].hex(),
                    argv_file_offset=ao,argv_raw_hex=native[ao:ao+num*8].hex(),arguments=args)
    for i in range(table_count):
        off=table_offset+i*16;spec,method_index,invoker,adjustor=struct.unpack_from('<4i',native,off)
        assert 0<=spec<spec_count
        so=spec_offset+spec*12;mid,cls,method=struct.unpack_from('<3i',native,so)
        if mid not in WANTED:continue
        if method_index<0:
            va=None;po=None
        else:
            assert method_index<pointer_count
            po=pointer_offset+8*method_index;va=struct.unpack_from('<Q',native,po)[0]
            if va:pe.offset(va,executable=True)
        rows.append(dict(generic_function_index=i,generic_function_file_offset=off,generic_function_raw_hex=native[off:off+16].hex(),
            method_spec_index=spec,method_spec_file_offset=so,method_spec_raw_hex=native[so:so+12].hex(),
            method_id=mid,method_name=methods[mid],method_instantiation=inst(method),class_instantiation=inst(cls),
            method_pointer_index=method_index,method_pointer_file_offset=po,native_va=hex(va) if va else None,
            pointer_raw_hex=native[po:po+8].hex() if po is not None else None,invoker_index=invoker,adjustor_index=adjustor))
    assert rows
    sources=[HERE/'resolve_save_generics.py',HERE/'metadata.py',HERE/'save_declarations.py',HERE/'symbols/save-parser-layouts.json',HERE/'symbols/field-offsets.json']
    return dict(schema_version=1,evidence_type='Original CodeRegistration + genericMethodTable + methodSpecs + generic pointers; selected closed declarations only',
        native_sha256=identity['native_sha256'],metadata_sha256=identity['metadata_sha256'],code_registration=code,
        metadata_registration_va=reg['va'],generic_function_count=table_count,method_specs_count=spec_count,
        selected_definitions=sorted(WANTED),selected_instantiations=rows,
        unique_native_addresses=sorted({r['native_va'] for r in rows if r['native_va']},key=lambda s:int(s,16)),
        sources=[dict(path=p.relative_to(HERE.parent).as_posix(),sha256=hashlib.sha256(p.read_bytes()).hexdigest()) for p in sources],
        limitations=['Static registration resolution does not observe the runtime receiver or MethodInfo instance.',
                    'Shared native bodies retain all selected closed generic aliases; native-only labels are analyst assertions.',
                    'CodeRegistration is selected by a unique full76-module identity match, not an observed registration call.'])


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--check',action='store_true');a=p.parse_args();q=build()
    path=HERE/'symbols/save-generic-methods.json'
    if a.check:assert read(path)==q
    else:path.write_text(json.dumps(q,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(status='consistent' if a.check else 'written',instantiations=len(q['selected_instantiations']),native_addresses=q['unique_native_addresses'])))


if __name__=='__main__':main()
