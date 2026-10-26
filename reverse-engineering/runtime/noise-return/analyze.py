"""Validate entry/leave/native-continuation identity and natural event coverage."""
from collections import Counter, defaultdict
import json
from pathlib import Path
import runpy

HERE = Path(__file__).resolve().parent
legacy = runpy.run_path(str(HERE.parent / 'noise-cancellation/analyze.py'))
number = legacy['number']


def d(p):
    return p.get('data', {})


def validate_call(rows):
    """Never use equal counts or matching readbacks alone as a return proof."""
    groups = {k: [p for p in rows if p['kind'] == k] for k in
              ('return_entry', 'return_onleave', 'return_continuation', 'return_decay')}
    reasons = []
    required = ['return_entry', 'return_onleave', 'return_continuation']
    for k in required:
        if len(groups[k]) != 1:
            reasons.append(k + '-not-unique')
    if len(groups['return_decay']) != 1:
        reasons.append('return_decay-not-unique')
    if reasons:
        return dict(valid=False, reasons=reasons)
    a, b, c = (groups[k][0] for k in required)
    for row in [b, c, *groups['return_decay']]:
        if row.get('script') != a.get('script') or any(
                d(row).get(k) != d(a).get(k) for k in ('call', 'thread', 'nca', 'id', 'entryCaller')):
            reasons.append('identity-mismatch')
    if not a.get('script') or any(d(a).get(k) is None for k in ('call', 'thread', 'nca', 'entryCaller')):
        reasons.append('missing-identity')
    orders = [p.get('order') for p in (a, b, c)]
    if not all(isinstance(v, int) and not isinstance(v, bool) for v in orders) or not orders[0] < orders[1] < orders[2]:
        reasons.append('invalid-order')
    if not d(c).get('onLeaveSeen'):
        reasons.append('leave-flag-missing')
    if number(d(a).get('entryCaller')) != 0x428bf3:
        reasons.append('other-caller')
    if d(b).get('at') != d(c).get('at'):
        reasons.append('leave-continuation-readbacks-differ')
    for decay in groups['return_decay']:
        if not isinstance(decay.get('order'), int) or not a['order'] < decay['order'] < b['order']:
            reasons.append('decay-outside-call')
    return dict(valid=not reasons, reasons=sorted(set(reasons)),
                script=a['script'], call=d(a)['call'], nca=d(a)['nca'], id=d(a)['id'],
                frame=a['frame'], entry=a, leave=b, continuation=c,
                decays=groups['return_decay'])


def summarize_calls(messages):
    groups = defaultdict(list)
    for p in messages:
        if p['kind'] in ('return_entry', 'return_onleave', 'return_continuation', 'return_decay'):
            groups[(p.get('script'), d(p).get('call'))].append(p)
    rows = [validate_call(v) for v in groups.values()]
    return dict(selected_calls=len(rows), valid_calls=sum(r['valid'] for r in rows),
                invalid_calls=[r for r in rows if not r['valid']], calls=rows)


def summarize_pre_event(calls, script, case_id, cutoff):
    """A completed decay and continuation must both precede the first event."""
    selected = [r for r in calls if r.get('valid') and r['script'] == script and r['id'] == case_id
                and r['continuation']['order'] < cutoff]
    decays = [p for r in selected for p in r['decays'] if p['order'] < cutoff]
    values = [v for r in selected for v in (d(r['entry'])['at']['value'], d(r['leave'])['at']['value'])]
    counts = [v for r in selected for v in (d(r['entry'])['at']['count'], d(r['leave'])['at']['count'])]
    return dict(calls=len(selected), decays=len(decays),
                value_range=legacy['value_range'](values), count_range=legacy['value_range'](counts),
                decrement_pairs=sum(d(p)['after']['count'] == d(p)['before']['count'] - 1 for p in decays),
                actual_value_decreases=sum(d(p)['after']['value'] < d(p)['before']['value'] for p in decays),
                below_threshold_entries=sum(d(r['entry'])['at']['value'] < d(r['entry'])['at']['threshold'] for r in selected),
                player_not_found_entries=sum(d(r['entry'])['at']['playerFound'] == 0 for r in selected),
                within_call_count_increases=sum(d(r['leave'])['at']['count'] > d(p)['after']['count']
                    for r in selected for p in r['decays']),
                interval_count_increases=sum(d(b['entry'])['at']['count'] > d(a['leave'])['at']['count']
                                             for a, b in zip(selected, selected[1:])))


def analyze(here=HERE):
    here = Path(here)
    raw = json.loads((here / 'rea-runtime.json').read_text(encoding='utf8'))
    messages, script_errors, joins = legacy['retained_messages'](raw)
    natural = legacy['analyze_natural'](here=here)
    pairing = summarize_calls(messages)
    for c in natural['cases']:
        events = [p for p in messages if p['kind'] == 'coverage_animation' and p['script'] == c['script'] and d(p).get('id') == c['id']]
        cutoff = events[0]['order'] if events else (c['end'] or {}).get('order', float('inf'))
        c['native_pre_event'] = summarize_pre_event(pairing['calls'], c['script'], c['id'], cutoff)
    finishes = [p for p in messages if p['kind'] == 'return_finished']
    counts = Counter(p['kind'] for p in messages)
    return dict(schema_version=1, status='single-passive-noise-return-checkpoint',
                authority='passive natural input; independent post-call native continuation',
                natural=natural, native_pairing=pairing,
                counter_finishes=finishes, counts=dict(counts), script_errors=script_errors,
                finished=natural['all_sources_finished'] and len(finishes) == 1,
                capture_joins=joins,
                limits=['Single-script capture repairs current return coverage; it does not identify the cause of earlier multi-script loss.',
                        'Only first 12 baseline calls and active discovery calls emit individual return records; total counters are a separate aggregate.',
                        'Native continuation identity and strict order are required; no event absence alone establishes a bug.',
                        'Count increases inside or between calls are net changes bounded by readbacks, not exact write-PC attribution.'])


if __name__ == '__main__':
    print(json.dumps(analyze(), ensure_ascii=False, indent=2))
