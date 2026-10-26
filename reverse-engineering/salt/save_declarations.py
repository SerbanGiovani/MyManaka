"""Recover save-root declarations and nested types; not an ES3 member selection oracle."""
import argparse
import hashlib
import json
from pathlib import Path
import sqlite3
import struct

from metadata import HERE, DEFAULT_ROOT, Metadata, PE

PRIMITIVES = {1:'System.Void', 2:'System.Boolean', 3:'System.Char', 4:'System.SByte',
    5:'System.Byte', 6:'System.Int16', 7:'System.UInt16', 8:'System.Int32', 9:'System.UInt32',
    10:'System.Int64', 11:'System.UInt64', 12:'System.Single', 13:'System.Double', 14:'System.String',
    24:'System.IntPtr', 25:'System.UIntPtr', 28:'System.Object'}


def read(p):
    return json.loads(p.read_text(encoding='utf-8-sig'))


def build():
    identity = read(HERE/'evidence/artifact-identity.json')
    native = (DEFAULT_ROOT/'GameAssembly.dll').read_bytes()
    metadata = (DEFAULT_ROOT/'SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat').read_bytes()
    assert hashlib.sha256(native).hexdigest() == identity['native_sha256']
    assert hashlib.sha256(metadata).hexdigest() == identity['metadata_sha256']
    pe, md = PE(native), Metadata(metadata)
    types, fields, properties = md.records(40,'<16i8H2I'), md.records(24,'<iiI'), md.records(10,'<5I')
    definitions = md.records(12,'<6iI4H')
    images = md.records(42,'<iiiIiIiIii')
    attribute_ranges = md.records(52,'<II')
    default_rows = md.records(16,'<iii')
    defaults = {r[0]: (i,r) for i,r in enumerate(default_rows)}
    layout = read(HERE/'symbols/field-offsets.json')
    runtime_table = layout['registration']['pointer_tables']['runtime_types']
    offset_rows = {r['type_id']:r for r in layout['all_type_field_offset_rows']}
    cache = {}
    def name(tid):
        t = types[tid]
        return '.'.join(filter(None,(md.string(t[1]),md.string(t[0]))))
    attribute_maps = {}
    def attributes(tid,token):
        image_id = next(i for i,image in enumerate(images) if image[2] <= tid < image[2]+image[3])
        image = images[image_id]
        if image_id not in attribute_maps:
            attribute_maps[image_id] = {attribute_ranges[i][0]:i for i in range(image[8],image[8]+image[9])}
            assert len(attribute_maps[image_id]) == image[9]
        index = attribute_maps[image_id].get(token)
        if index is None:
            return dict(image_id=image_id,token=hex(token),present=False,constructor_types=[])
        _,start = attribute_ranges[index]
        end = attribute_ranges[index+1][1] if index+1<len(attribute_ranges) else md.header[51]
        assert 0 <= start < end <= md.header[51]
        offset = md.header[50]+start
        blob = metadata[offset:md.header[50]+end]
        # This selected graph only uses the one-byte count form. Argument
        # payloads are preserved, not decoded or assumed to be empty.
        count = blob[0]
        assert count < 128 and 1+4*count <= len(blob)
        constructors = struct.unpack_from('<'+str(count)+'I',blob,1)
        names = []
        for mid in constructors:
            assert mid < len(definitions) and md.string(definitions[mid][0]) == '.ctor'
            names.append(name(definitions[mid][1]))
        return dict(image_id=image_id,token=hex(token),present=True,range_index=index,
            range_file_offset=md.header[52]+8*index,range_raw_hex=metadata[md.header[52]+8*index:md.header[52]+8*index+8].hex(),
            data_file_offset=offset,raw_hex=blob.hex(),count_form='selected one-byte count + little-endian int32 constructor indices',
            constructor_method_ids=list(constructors),constructor_types=names,argument_payload_decoded=False)
    def at_index(index):
        assert 0 <= index < runtime_table['count']
        va = struct.unpack_from('<Q',native,runtime_table['file_offset']+8*index)[0]
        return at_pointer(va)
    def at_pointer(va):
        if va in cache:
            return cache[va]
        offset = pe.offset(va,12)
        data,bits = struct.unpack_from('<QI',native,offset)
        kind = (bits>>16)&255
        row = dict(va=hex(va),file_offset=offset,raw_hex=native[offset:offset+12].hex(),
                   type_enum=kind,attrs=bits&65535,data=hex(data))
        cache[va] = row
        if kind in PRIMITIVES:
            row['name'] = PRIMITIVES[kind]
        elif kind in (17,18):
            assert data < len(types)
            row.update(name=name(data),type_id=data)
        elif kind in (15,16,29):
            element = at_pointer(data)
            row.update(element_va=element['va'],name=element.get('name','?')+{15:'*',16:'&',29:'[]'}[kind])
        elif kind == 21:
            off = pe.offset(data,32)
            type_pointer,inst,method_inst,cached = struct.unpack_from('<4Q',native,off)
            definition = at_pointer(type_pointer)
            inst_offset = pe.offset(inst,16)
            count,argv = struct.unpack_from('<QQ',native,inst_offset)
            assert count < 32
            args = [at_pointer(struct.unpack_from('<Q',native,pe.offset(argv+8*i,8))[0]) for i in range(count)]
            row.update(name=definition.get('name','?')+'<'+','.join(a.get('name','?') for a in args)+'>',
                generic_definition_va=definition['va'],generic_type_id=definition.get('type_id'),
                generic_argument_vas=[a['va'] for a in args],generic_class_file_offset=off,
                generic_class_raw_hex=native[off:off+32].hex(),generic_inst_file_offset=inst_offset,
                generic_inst_raw_hex=native[inst_offset:inst_offset+16].hex(),
                argument_pointer_file_offset=pe.offset(argv,count*8),argument_pointer_raw_hex=native[pe.offset(argv,count*8):pe.offset(argv,count*8)+count*8].hex())
        else:
            row.update(name='unresolved-type-enum-'+hex(kind),unresolved=True)
        return row
    c = sqlite3.connect((HERE/'.cache/methods.sqlite').as_uri()+'?mode=ro',uri=True)
    method_rows = {r[0]:dict(id=r[0],name=r[1],va=r[2]) for r in c.execute('SELECT id,qualified_name,va FROM methods')}
    c.close()
    root_names = ['ExposureUnnoticed2.Scripts.InGame.GameStateData',
        'ExposureUnnoticed2.Scripts.InGame.PlayerCustomData','ExposureUnnoticed2.ObjectUI.OptionMenu.OptionData',
        'ExposureUnnoticed2.ObjectUI.TutorialPanel.TutorialData']
    roots = [next(i for i in range(len(types)) if name(i)==n) for n in root_names]
    game_image = next(image for image in images if md.string(image[0]) == 'Assembly-CSharp.dll')
    pending, graph, visited = list(roots), [], set()
    def follow(row):
        if row.get('type_id') is not None:
            tid = row['type_id']
            # Several reachable game records/enums have an empty namespace.
            # Assembly ownership, rather than a namespace prefix, bounds them.
            if game_image[2] <= tid < game_image[2]+game_image[3] or name(tid) in ('UnityEngine.Vector3','UnityEngine.Quaternion','UnityEngine.Color','UnityEngine.Color32'):
                pending.append(tid)
        for key in ('element_va','generic_definition_va'):
            if key in row:
                follow(cache[int(row[key],16)])
        for va in row.get('generic_argument_vas',[]):
            follow(cache[int(va,16)])
    while pending:
        tid = pending.pop(0)
        if tid in visited:
            continue
        visited.add(tid)
        t = types[tid]
        enum = bool(t[24]&2)
        row = offset_rows[tid]
        declarations = []
        for j in range(t[18]):
            fid = t[8]+j
            f = fields[fid]
            rt = at_index(f[1]);flags = rt['attrs']
            item = dict(field_id=fid,name=md.string(f[0]),token=hex(f[2]),type_va=rt['va'],type_name=rt['name'],
                native_offset=row['raw_offsets'][j],field_attributes=flags,public=(flags&7)==6,
                static=bool(flags&16),init_only=bool(flags&32),literal=bool(flags&64),not_serialized=bool(flags&128),
                metadata_file_offset=md.header[24]+12*fid,metadata_raw_hex=metadata[md.header[24]+12*fid:md.header[24]+12*fid+12].hex())
            item['custom_attributes'] = attributes(tid,f[2])
            markers = set(item['custom_attributes']['constructor_types'])
            if 'ES3Serializable' in markers:
                policy = 'explicit-ES3Serializable-accept-before-later-field-guards'
            elif 'ES3NonSerializable' in markers:
                policy = 'reject-ES3NonSerializable'
            elif not item['public'] and 'UnityEngine.SerializeField' not in markers:
                policy = 'reject-nonpublic-in-safe-reflection'
            elif item['literal'] or item['init_only']:
                policy = 'reject-literal-or-readonly'
            elif item['not_serialized'] or 'System.NonSerializedAttribute' in markers or 'System.ObsoleteAttribute' in markers:
                policy = 'reject-nonserialized-or-obsolete'
            else:
                policy = 'passes-selected-field-guards-type-support-not-executed'
            item['safe_reflection_field_policy'] = policy
            if fid in defaults:
                index,(_,type_index,data_index) = defaults[fid]
                item['default_metadata'] = dict(definition_file_offset=md.header[16]+12*index,
                    raw_hex=metadata[md.header[16]+12*index:md.header[16]+12*index+12].hex(),
                    type_index=type_index,data_index=data_index)
            declarations.append(item)
            if not enum and not item['static'] and not item['literal']:
                follow(rt)
        props = []
        for j in range(t[17]):
            pid = t[11]+j
            prop = properties[pid]
            props.append(dict(name=md.string(prop[0]),getter_method_id=t[9]+prop[1] if prop[1]!=0xffffffff else None,
                setter_method_id=t[9]+prop[2] if prop[2]!=0xffffffff else None,attributes=prop[3],token=hex(prop[4]),
                metadata_file_offset=md.header[10]+20*pid,raw_hex=metadata[md.header[10]+20*pid:md.header[10]+20*pid+20].hex(),
                custom_attributes=attributes(tid,prop[4])))
        constructors = [dict(method_rows[mid],parameter_count=definitions[mid][10],flags=definitions[mid][7])
                        for mid in range(t[9],t[9]+t[16]) if method_rows[mid]['name'].endswith('::.ctor')]
        graph.append(dict(type_id=tid,name=name(tid),enum=enum,value_type=bool(t[24]&1),type_flags=t[7],custom_attributes=attributes(tid,t[-1]),
            metadata_file_offset=md.header[40]+tid*struct.calcsize('<16i8H2I'),
            raw_hex=metadata[md.header[40]+tid*struct.calcsize('<16i8H2I'):md.header[40]+(tid+1)*struct.calcsize('<16i8H2I')].hex(),
            parent_type=at_index(t[4])['name'] if t[4]>=0 else None,fields=declarations,properties=props,constructors=constructors))
    sources = [HERE/'save_declarations.py',HERE/'metadata.py',HERE/'symbols/field-offsets.json',HERE/'symbols/save-parser-layouts.json']
    return dict(schema_version=1,evidence_type='Original IL2CPP declared save field/type graph; actual ES3 member selection remains a separate predicate',
        native_sha256=identity['native_sha256'],metadata_sha256=identity['metadata_sha256'],
        root_type_ids=roots,types=sorted(graph,key=lambda a:a['type_id']),
        runtime_types=sorted(cache.values(),key=lambda a:int(a['va'],16)),
        sources=[dict(path=p.relative_to(HERE.parent).as_posix(),sha256=hashlib.sha256(p.read_bytes()).hexdigest()) for p in sources],
        limitations=['Field policy records selected ES3Reflection guards; runtime TypeIsSerializable, member filters/cache and actual save settings are separate.',
            'Selected attribute constructor prefixes are decoded; argument payloads and unsupported count forms are not generalized.',
            'Constructor defaults require native constructor observations; field default metadata is separate.',
            'Arrays/generic arguments preserve native raw pointers and bytes. Unhandled kinds remain unresolved.',
            'Game types and selected Unity value types are expanded; system collection implementation fields are not save schema.'])


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--check',action='store_true');a=p.parse_args()
    result=build();path=HERE/'symbols/save-declarations.json'
    if a.check:
        assert read(path)==result
    else:
        path.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(status='consistent' if a.check else 'written',types=len(result['types']),runtime_types=len(result['runtime_types']),
        roots=[dict(name=t['name'],fields=len(t['fields'])) for t in result['types'] if t['type_id'] in result['root_type_ids']]),ensure_ascii=False))


if __name__=='__main__':
    main()
