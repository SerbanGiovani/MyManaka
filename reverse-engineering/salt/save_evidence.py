"""Bind reflected save declarations, generic registrations and REA bodies."""
import argparse
import hashlib
import json
import re
import struct

from metadata import HERE
from scene_evidence import build as bind, read


def fingerprint(path):
    return dict(path=path.relative_to(HERE.parent).as_posix(),
                sha256=hashlib.sha256(path.read_bytes()).hexdigest())


def build():
    result = bind(batch_prefix='save-schema-',
        reuse_method_ids={16968, 16969, 16970, 16971, 17409, 17410, 17422},
        extra_type_names=('ES3Type', 'ES3ObjectType', 'ES3ReflectedObjectType', 'ES3ReflectedType',
            'ES3Reflection', 'ES3ReflectedMember', 'ES3Member', 'ES3TypeMgr', 'ES3Reader', 'ES3Writer',
            'ES3Settings', 'ES3Stream', 'ES3Serializable', 'ES3NonSerializable', 'PlayerCustomData',
            'TutorialData', 'LoadoutData', 'LoadoutCustomizeData', 'GameState'),
        dispatch_targets=[], resource_boundary='Selected static reflected save pipeline; no save-file roundtrip or game execution.')
    declarations = read(HERE/'symbols/save-declarations.json')
    generics = read(HERE/'symbols/save-generic-methods.json')
    for item in (declarations, generics):
        assert item['native_sha256'] == result['native_sha256']
        assert item['metadata_sha256'] == result['metadata_sha256']
    methods = result['methods']
    new = [m for m in methods if m['new_this_round']]
    assert len(new) == 71
    roots = [t for t in declarations['types'] if t['type_id'] in declarations['root_type_ids']]
    result['declared_save_roots'] = [dict(type_id=t['type_id'], name=t['name'],
        fields=len(t['fields']), properties=len(t['properties']),
        explicit_es3_serializable=sum('ES3Serializable' in f['custom_attributes']['constructor_types'] for f in t['fields']))
        for t in roots]
    result['declared_nested_graph'] = dict(types=len(declarations['types']),
        runtime_types=len(declarations['runtime_types']),
        unresolved_runtime_types=[r['va'] for r in declarations['runtime_types'] if r.get('unresolved')],
        boundary='Declared game/selected Unity type closure; framework collection implementation fields are not expanded.')
    private = next(t for t in declarations['types'] if t['name'].endswith('.LoadoutCustomizeData'))
    result['private_customize_fields'] = dict(type_id=private['type_id'], count=len(private['fields']),
        all_nonpublic=all(not f['public'] for f in private['fields']),
        all_explicit_es3_serializable=all('ES3Serializable' in f['custom_attributes']['constructor_types'] for f in private['fields']))
    linked = []
    for method in new:
        if method['method_id'] is not None:
            continue
        rows = [r for r in generics['selected_instantiations'] if r['native_va'] == method['va']]
        objects = [r for r in rows if r['method_instantiation'] and
                   [a['name'] for a in r['method_instantiation']['arguments']] == ['System.Object']]
        assert len(objects) == 1
        linked.append(dict(va=method['va'], evidence_id=method['evidence_id'],
            selected_shared_alias_count=len(rows), representative=objects[0],
            boundary='Registered System.Object instantiation of a shared body; runtime MethodInfo/receiver is unobserved.'))
    assert len(linked) == 13
    result['generic_body_links'] = linked
    result['selected_generic_registration'] = dict(code_registration_va=generics['code_registration']['va'],
        module_count=len(generics['code_registration']['module_names']),
        generic_function_count=generics['generic_function_count'], method_specs_count=generics['method_specs_count'],
        selected_instantiations=len(generics['selected_instantiations']),
        selected_native_addresses=len(generics['unique_native_addresses']), queried_native_bodies=len(linked))
    # Preserve literal store width before associating bytes with individual fields.
    # These are observations of decompiler text, not a complete symbolic evaluator.
    primitive_formats = {'System.Boolean':'?', 'System.Byte':'B', 'System.SByte':'b',
        'System.Int16':'h', 'System.UInt16':'H', 'System.Char':'H', 'System.Int32':'i',
        'System.UInt32':'I', 'System.Int64':'q', 'System.UInt64':'Q',
        'System.Single':'f', 'System.Double':'d'}
    constructor_rows = []
    for tid, mid in ((2586,16741),(2587,16742),(2715,17472),(2803,17970),(2896,18515),(2917,18687),
                     (2453,16100),(2453,16101),(2472,16241),(2472,16242),(2582,16733),(2701,17405)):
        typ = next(t for t in declarations['types'] if t['type_id'] == tid)
        method = next(m for m in new if m['method_id'] == mid)
        code = read(HERE.parent/method['path'])['normalized_result']
        stores, byte_values = [], {}
        pattern = r'\*\(undefined([1248]) \*\)\(param_1 \+ (0x[0-9a-f]+|\d+)\)\s*=\s*(0x[0-9a-f]+|\d+);'
        for match in re.finditer(pattern, code):
            width, offset, value = int(match[1]), int(match[2],0), int(match[3],0)
            assert 0 <= value < 1 << (8*width)
            raw = value.to_bytes(width,'little')
            stores.append(dict(offset=offset, width=width, raw_hex=raw.hex(),
                pseudocode_line=code[:match.start()].count('\n')+1, text=match[0]))
            byte_values.update({offset+i:b for i,b in enumerate(raw)})
        projections = []
        for field in typ['fields']:
            fmt = primitive_formats.get(field['type_name'])
            if fmt is None or field['static']:
                continue
            offset, width = field['native_offset'], struct.calcsize('<'+fmt)
            covered = [b in byte_values for b in range(offset,offset+width)]
            if any(covered):
                value = None
                if all(covered):
                    raw = bytes(byte_values[b] for b in range(offset,offset+width))
                    value = struct.unpack('<'+fmt,raw)[0]
                projections.append(dict(field_id=field['field_id'], name=field['name'],
                    offset=offset, type_name=field['type_name'], width=width,
                    covered_bytes=covered, value_if_fully_covered=value))
        constructor_rows.append(dict(type_id=tid, method_id=mid, evidence_id=method['evidence_id'],
            parameter_count=next(c['parameter_count'] for c in typ['constructors'] if c['id']==mid),
            literal_stores=stores, projected_primitive_fields=projections,
            boundary='Only direct undefined1/2/4/8 integer-literal stores in selected pseudocode; helpers, branches and other assignments are not evaluated. Values are byte projections, not complete final constructor state.'))
    result['constructor_literal_observations'] = constructor_rows
    result['reflection_contract'] = [
        dict(method_ids=[12960,12961,12968,12999], finding='Fields precede properties; explicit ES3Serializable accepts before later field guards. Safe nonpublic fields otherwise require SerializeField.'),
        dict(method_ids=[12534,12431,12432], finding='ReflectedObjectType constructor eagerly obtains members with safe=true; later settings only initialize an absent member cache.'),
        dict(method_ids=[12429,12430,13007,13008], finding='Writer reads member values and resolves member ES3Type; reader matches property names and assigns through reflected member SetValue.'),
        dict(method_ids=[12536,12963,12964,12986,12987], finding='Registered ReadObject<System.Object> calls CreateInstance before ReadProperties. Ordinary classes with a parameterless constructor use it; without one, the selected CreateInstance branch allocates without calling a business constructor.'),
        dict(method_ids=[11734,11735], finding='Selected Read(key) throws when absent; Read(key,defaultValue) returns the supplied default on its absent-key branch.'),
        dict(method_ids=[18687,18689,18688], finding='LoadoutCustomizeData constructor captures current GameState.PlayerCustomData; SaveCurrentCustomize and ApplyToGameState establish opposite copy directions, with dictionary handling retained in full bodies.'),
        dict(method_ids=[13102,13103,11779,11783], finding='Configured stream path conditionally wraps encryption and compression; actual game save default resource/password and whole-file codec are not recovered by these queries.')]
    sources = ['save_evidence.py','save_declarations.py','resolve_save_generics.py','inspect_save_layouts.ps1',
        'scene_evidence.py','metadata.py','prepare_loading.py','run_batch.mjs',
        'symbols/save-declarations.json','symbols/save-generic-methods.json','symbols/save-parser-layouts.json']
    for batch in ('core','tail','defaults','nested'):
        sources.extend(['symbols/save-schema-'+batch+'.plan.json','symbols/save-schema-'+batch+'.seeds.tsv'])
    result['dependencies'] = [fingerprint(HERE/p) for p in sources]
    result['scope'] = 'Four declared save roots, selected nested graph, ES3 reflection/generic read/write and constructor defaults; static pinned build only.'
    result['limitations'] += declarations['limitations'] + generics['limitations'] + [
        'No decrypted .sd sample, independent reader/writer or original-engine save/load roundtrip is produced.',
        'RankData, TotalPlayTimeData, other system keys, historical migrations and all Unity custom serializers are outside this declared root graph.',
        'Present-member assignment leaves absent members at their created-object state in this path; parameterless constructor side effects can depend on current global objects, while no-parameterless classes follow a different allocation branch.',
        'Stream wrapper branches do not identify actual save settings or establish that resource-bundle crypto applies to .sd files.']
    return result


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--check',action='store_true')
    args=parser.parse_args()
    result=build()
    path=HERE/'evidence/save-schema-chain.json'
    if args.check:
        assert read(path)==result, 'Save evidence differs'
    else:
        path.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(status='consistent' if args.check else 'written',
        queries=result['new_observations'], roots=result['declared_save_roots'],
        generic_body_links=len(result['generic_body_links'])),ensure_ascii=False))


if __name__=='__main__':
    main()
