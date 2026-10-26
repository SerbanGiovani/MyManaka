"""Bind ordered reconstruction queries to metadata fields and virtual targets."""
import argparse
import hashlib
import json
from pathlib import Path
import struct

from metadata import HERE, DEFAULT_ROOT, Metadata, PE
from scene_evidence import build as bind, read


def digest(p):
    return hashlib.sha256(p.read_bytes()).hexdigest()


def build():
    plan_path = HERE / 'symbols/priority-core.plan.json'
    plan = read(plan_path)
    result = bind(batch_prefix='priority-', reuse_method_ids={16743, 16862, 16864, 16865, 14756,
        16738, 15524, 15623, 15690, 16969, 16971, 17304, 16825, 17422},
        extra_type_names=('NpcState', 'NpcStateModel', 'NpcClassAccessor', 'NpcController', 'NpcLocomotion',
            'PlayerSearcher', 'PlayerStateModel', 'MCommon', 'GameState', 'GameStateApplier',
            'MissionBase', 'MMissionRecord', 'MMission', 'MissionType', 'MissionCountType', 'InteractType'),
        dispatch_targets=[], resource_boundary='Static function/field/virtual target reconstruction; no new gameplay execution or independent replacement project.')
    md_bytes = (DEFAULT_ROOT / 'SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat').read_bytes()
    assert hashlib.sha256(md_bytes).hexdigest() == result['metadata_sha256']
    md = Metadata(md_bytes)
    types, definitions = md.records(40, '<16i8H2I'), md.records(12, '<6iI4H')
    slots = md.records(36, '<I')
    method_to_observations = {}
    for m in result['methods']:
        method_to_observations.setdefault(m['method_id'], []).append(m)
    def owner(tid):
        t = types[tid]
        return '.'.join(filter(None, (md.string(t[1]), md.string(t[0]))))
    virtuals = []
    for tid, t in enumerate(types):
        name = owner(tid)
        if not name.startswith('ExposureUnnoticed2.Scripts.Mission.'):
            continue
        rows = []
        for slot in range(t[21]):
            index = t[14] + slot
            encoded = slots[index][0]
            offset = md.header[36] + 4*index
            row = dict(slot=slot, encoded=encoded, metadata_file_offset=offset,
                       raw_hex=md_bytes[offset:offset+4].hex(), tag=encoded >> 29)
            if encoded >> 29 == 3:
                mid = (encoded & 0x1fffffff) >> 1
                method = definitions[mid]
                row.update(method_id=mid, method_name=md.string(method[0]), declaring_type=owner(method[1]),
                           queried=mid in method_to_observations,
                           evidence_ids=[m['evidence_id'] for m in method_to_observations.get(mid, [])])
            rows.append(row)
        virtuals.append(dict(type_id=tid, name=name, slots=rows))
    requested = []
    definition_size = struct.calcsize('<6iI4H')
    for r in plan['requested_methods']:
        evidence = method_to_observations[r['query_method_id']]
        new = [m for m in evidence if m['new_this_round']]
        assert new and all(m['va'] == r['va'] for m in new)
        method = definitions[r['metadata_id']]
        requested.append(dict(r, evidence_ids=[m['evidence_id'] for m in new],
            metadata_definition_file_offset=md.header[12] + r['metadata_id']*definition_size,
            metadata_definition_raw_hex=md_bytes[md.header[12]+r['metadata_id']*definition_size:md.header[12]+(r['metadata_id']+1)*definition_size].hex(),
            actual_declaring_type=owner(method[1]),
            shared_address=r['metadata_id'] != r['query_method_id']))
    # Each priority group stays visible even when native implementation addresses are shared.
    result['priority_groups'] = [dict(priority=i, name=g,
        method_ids=[r['metadata_id'] for r in requested if r['group'] == g],
        query_method_ids=sorted({r['query_method_id'] for r in requested if r['group'] == g}),
        status='static-bodies-and-metadata-bound; runtime-equivalence-unverified')
        for i, g in enumerate(dict.fromkeys(r['group'] for r in requested), 1)]
    result['requested_methods'] = requested
    result['mission_virtual_dispatch'] = virtuals
    usages = {u['va']: u for u in result['usages']}
    result['save_key_literals'] = []
    for mid in (16968, 16970, 16969, 16971):
        for method in method_to_observations.get(mid, []):
            result['save_key_literals'].append(dict(method_id=mid, evidence_id=method['evidence_id'],
                strings=[dict(va=v, value=usages[v]['value']) for v in method['usage_vas'] if usages[v]['tag'] == 5]))
    instruction_path = HERE / 'symbols/priority-instructions.json'
    instructions = read(instruction_path)
    native = (DEFAULT_ROOT / 'GameAssembly.dll').read_bytes()
    assert hashlib.sha256(native).hexdigest() == instructions['native']['sha256'] == result['native_sha256']
    pe = PE(native)
    instruction_count = 0
    for part in instructions['ranges']:
        end = int(part['begin'], 16)
        for row in part['instructions']:
            pos = pe.offset(int(row['va'], 16), row['length'], executable=True)
            assert int(row['va'], 16) == end
            assert native[pos:pos+row['length']] == bytes.fromhex(row['raw_hex'])
            end += row['length']
            instruction_count += 1
        assert end == int(part['end_exclusive'], 16)
    constants = []
    for va in (0x182a94604, 0x182a94660):
        offset = pe.offset(va, 4)
        constants.append(dict(va=hex(va), file_offset=offset, raw_hex=native[offset:offset+4].hex(),
                              float32=struct.unpack_from('<f', native, offset)[0]))
    result['npc_fixed_guard'] = dict(path=instruction_path.relative_to(HERE.parent).as_posix(),
        sha256=digest(instruction_path), instructions_verified=instruction_count, constants=constants,
        boundary='Explicit 0x42e660..0x42e740 instruction window, not complete method bounds or execution.',
        finding='For finite distances: >20 takes the skip-count-2 comparison before the later >30/skip-count-4 branch can be reached; retain actual branch order.')
    result['shared_virtual_declarations'] = [r for r in requested if r['shared_address']]
    deps = ['salt/prepare_priority.py', 'salt/priority_evidence.py', 'salt/scene_evidence.py',
            'salt/metadata.py', 'salt/symbols/priority-core.plan.json', 'salt/symbols/priority-core.seeds.tsv',
            'salt/symbols/priority-tail.plan.json', 'salt/symbols/priority-tail.seeds.tsv',
            'salt/prepare_priority_instructions.py', 'salt/decode_npc_fps.ps1', 'salt/symbols/priority-instructions.json']
    result['dependencies'] = [dict(path=p, sha256=digest(HERE.parent / p)) for p in deps]
    result['scope'] = 'The six agreed critical method groups, queried in priority order; selected mission virtuals and native shared-address aliases retained.'
    result['limitations'] += ['Mission vtable slots are static declared targets, not runtime receiver observations.',
        'Selected SaveRapper overloads do not establish every ES3 generic serializer or historical save migration.',
        'Recovering these methods does not produce an independently runnable replacement GameAssembly.']
    return result


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--check', action='store_true')
    args = p.parse_args()
    result = build()
    path = HERE / 'evidence/priority-chain.json'
    if args.check:
        assert read(path) == result, 'Priority evidence differs'
    else:
        path.write_text(json.dumps(result, ensure_ascii=False, indent=2) + '\n', encoding='utf8')
    print(json.dumps(dict(status='consistent' if args.check else 'written', queries=result['new_observations'],
        declarations=len(result['requested_methods']), mission_types=len(result['mission_virtual_dispatch']))))


if __name__ == '__main__':
    main()
