"""Select the complete final passive session without changing REA records."""
import argparse
import gzip
import hashlib
import json
from pathlib import Path
import runpy

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent.parent
GAME = Path('E:/ManakaREA-NaturalGameplay')


def read(p):
    return json.loads(p.read_text(encoding='utf-8-sig'))


def digest(p):
    return hashlib.sha256(p.read_bytes()).hexdigest()


def collect(export, session, pid):
    rows = [r for r in read(export)['records'] if r['parameters'].get('session_id') == session]
    statuses = [r for r in rows if r['operation'] == 'frida_session_status']
    completed = [r for r in statuses if any(m.get('payload', {}).get('kind') == 'return_finished'
                 for m in r['normalized_result']['messages'])]
    assert len(completed) == 1, 'Need one explicit finished status; Evidence bundle order is canonical, not chronological'
    final = completed[0]
    n = final['normalized_result']
    assert not n['messages_truncated'] and n['pid'] == pid and n['state'] == 'running'
    records = [r for r in rows if r['operation'] == 'load_frida_script'] + [final]
    assert len(records) == 2
    loaded = records[0]['normalized_result']
    assert digest(Path(loaded['source_path'])) == loaded['source_sha256']
    (HERE / 'rea-runtime.json').write_text(json.dumps(dict(schema_version=1,
        export_sha256=digest(export), selection='unchanged load and final untruncated pre-detach status',
        records=records), ensure_ascii=False, separators=(',', ':')) + '\n', encoding='utf8')
    ps = [m['payload'] for m in n['messages'] if m.get('payload', {}).get('frame') is not None]
    lo, hi = min(p['frame'] for p in ps), max(p['frame'] for p in ps)
    markers = [p['real'] for p in ps if p['kind'] in ('coverage_enter', 'coverage_animation', 'coverage_end')]
    baseline = read(HERE / 'source-save-baseline.json')
    offset = baseline['natural_log_offset']
    for s in baseline['source_save_hashes']:
        assert digest(Path(s['path'])) == s['sha256']
    with (GAME / 'natural.jsonl').open('rb') as f:
        f.seek(offset)
        raw = f.read()
    raw = raw[:raw.rfind(b'\n')+1]
    selected, last = [], -1e30
    for line in raw.splitlines(keepends=True):
        p = json.loads(line)
        if not lo <= p.get('frame', -1) <= hi:
            continue
        now = p.get('real', 0)
        if p['kind'] != 'snapshot' or now-last >= 15 or any(abs(now-t) <= 2 for t in markers):
            selected.append(line)
            if p['kind'] == 'snapshot':
                last = now
    data = b''.join(selected)
    log = HERE / 'natural-window.jsonl.gz'
    log.write_bytes(gzip.compress(data, mtime=0))
    old = read(HERE.parent / 'natural-time-stop/manifest.json')
    for row in old['inputs']:
        for k in ('original_path', 'runtime_path'):
            assert digest(Path(row[k])) == row['sha256']
    assert digest(GAME / 'BepInEx/plugins/NaturalObserver.dll') == old['current_plugin_sha256']
    decode = next(m['payload']['data'] for m in n['messages'] if m.get('payload', {}).get('kind') == 'return_decode')
    native = (GAME / 'GameAssembly.dll').read_bytes()
    pe = runpy.run_path(str(ROOT / 'salt/metadata.py'))['PE'](native)
    for row in decode['rows']:
        pos = pe.offset(0x180000000 + int(row['rva'], 16), executable=True)
        assert native[pos:pos+row['size']] == bytes(row['bytes'])
    result = runpy.run_path(str(HERE / 'analyze.py'))['analyze']()
    assert result['finished'] and not result['native_pairing']['invalid_calls']
    (HERE / 'results.json').write_text(json.dumps(result, ensure_ascii=False, indent=2) + '\n', encoding='utf8')
    sources = [HERE / name for name in ('observe.js', 'build_probe.py', 'analyze.py', 'test_analysis.py', 'collect.py')]
    deps = ['runtime/noise-callsite/observe-natural.js', 'runtime/noise-cancellation/analyze.py',
            'runtime/natural-event-coverage/analyze.py', 'runtime/natural-event-generation/analyze.py']
    manifest = dict(schema_version=1, observation_complete=result['finished'], natural_only=True,
        game_root=str(GAME), evidence_ids=[r['evidence_id'] for r in records],
        sessions=[dict(session_id=session, pid=pid, state='running', closed_by_operator=True, authority='passive-natural')],
        sources=[dict(path=p.relative_to(ROOT).as_posix(), sha256=digest(p)) for p in sources],
        dependencies=[dict(path=p, sha256=digest(ROOT / p)) for p in deps],
        source_save_baseline=dict(path='source-save-baseline.json', sha256=digest(HERE / 'source-save-baseline.json')),
        source_save_files_unchanged=len(baseline['source_save_hashes']), inputs=old['inputs'],
        current_plugin_sha256=old['current_plugin_sha256'],
        outputs=[dict(path=log.name, sha256=digest(log), uncompressed_bytes=len(data),
            uncompressed_sha256=hashlib.sha256(data).hexdigest(), original_path=str(GAME / 'natural.jsonl'),
            original_start_offset=offset, original_snapshot_bytes=len(raw),
            original_snapshot_sha256=hashlib.sha256(raw).hexdigest(),
            selection=dict(min_frame=lo, max_frame=hi, retained_lines=len(selected),
                marker_real_times=markers, snapshot_cadence_real_seconds=15, marker_window_seconds=2,
                complete_original_lines=True))],
        static_continuation=dict(rea_decode_in_final_status=True, instructions_verified=len(decode['rows']),
            source_sha256=hashlib.sha256(native).hexdigest(), call_rva='0x428bee', return_rva='0x428bf3'),
        limits=result['limits'])
    (HERE / 'manifest.json').write_text(json.dumps(manifest, ensure_ascii=False, indent=2) + '\n', encoding='utf8')
    print(json.dumps(dict(cases=len(result['natural']['cases']), valid_calls=result['native_pairing']['valid_calls'],
        cases_summary=[dict(id=c['id'], native=c['native_pre_event']) for c in result['natural']['cases']]), indent=2))


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--export', type=Path, required=True)
    p.add_argument('--session', required=True)
    p.add_argument('--pid', type=int, required=True)
    a = p.parse_args()
    collect(a.export, a.session, a.pid)
