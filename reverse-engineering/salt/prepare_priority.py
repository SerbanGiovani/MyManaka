"""Prepare ordered REA queries for the six agreed reconstruction priorities."""
import hashlib
import json
from pathlib import Path
import sqlite3
import subprocess
import sys

HERE = Path(__file__).resolve().parent


def main():
    c = sqlite3.connect((HERE / '.cache/methods.sqlite').as_uri() + '?mode=ro', uri=True)
    c.row_factory = sqlite3.Row
    methods = {r['id']: dict(r) for r in c.execute('SELECT m.*,t.full_name owner FROM methods m JOIN types t ON t.id=m.type_id')}
    mission = [i for i, r in methods.items() if r['owner'].startswith('ExposureUnnoticed2.Scripts.Mission.')
               and r['va'] and r['name'] not in ('.ctor', '.cctor', 'Dispose')
               and not r['name'].startswith(('get_', 'set_'))]
    groups = [
        ('state-application', [16744, 16745]),
        ('npc-movement-turn', [15553, 15554, 15555, 15556, 15557, 15558, 15559, 15685, 15686, 15687]),
        ('camera', [15918, 15919, 15920, 15921, 15922, 15923, 15924, 15925, 15926,
                    15962, 15963, 15964, 15966, 15967, 15968, 15969, 15970, 15971, 15972,
                    15943, 15944, 15945, 15946]),
        ('save-roundtrip', [16968, 16970, 17410, 17411, *range(17413, 17419), *range(17423, 17428)]),
        ('mission-rules', [16560, 16561, 16562, 16563, 16564, 16496, *sorted(mission), 16950, 16951, 16954, 16955]),
        ('concrete-interactions', [14192, 14193, 14194, 14197, 14198, 14201, 14202, 14203, 14204,
                                    *range(13953, 13971)]),
    ]
    requested, query_ids, aliases, seen = [], [], [], {}
    for priority, (group, ids) in enumerate(groups, 1):
        for mid in dict.fromkeys(ids):
            m = methods[mid]
            assert m['va'] and m['status'] == 'mapped', (mid, m)
            row = dict(priority=priority, group=group, metadata_id=mid, qualified_name=m['qualified_name'], va=m['va'])
            if m['va'] in seen:
                row['query_method_id'] = seen[m['va']]
                aliases.append(row)
            else:
                seen[m['va']] = mid
                row['query_method_id'] = mid
                query_ids.append(mid)
            requested.append(row)
    cmd = [sys.executable, str(HERE / 'prepare_loading.py'), '--name', 'priority-core', '--seed-assembly', 'Assembly-CSharp.dll']
    for mid in query_ids:
        cmd += ['--method-id', str(mid)]
    subprocess.run(cmd, check=True)
    p = HERE / 'symbols/priority-core.plan.json'
    plan = json.loads(p.read_text(encoding='utf8'))
    indexed = {f['metadata_id']: f for f in plan['functions']}
    plan['functions'] = [dict(indexed[mid], priority=next(r['priority'] for r in requested if r['metadata_id'] == mid),
        group=next(r['group'] for r in requested if r['metadata_id'] == mid)) for mid in query_ids]
    plan['requested_methods'] = requested
    plan['shared_address_aliases'] = aliases
    plan['preparer_sha256'] = hashlib.sha256(Path(__file__).read_bytes()).hexdigest()
    p.write_text(json.dumps(plan, indent=2) + '\n', encoding='utf8')
    print(json.dumps(dict(queries=len(query_ids), declarations=len(requested), groups={g:sum(r['group']==g for r in requested) for g,_ in groups})))


if __name__ == '__main__':
    main()
