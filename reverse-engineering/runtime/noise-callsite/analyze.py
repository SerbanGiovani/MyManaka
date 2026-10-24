"""Separate passive eligibility evidence from deferred original-call replays.

Message order belongs to one reconstructed Frida session.  A scoped native
1->2 trace is required for the strong replay classification; readbacks alone
never substitute for that trace.  Existing analyzers are imported in isolation.
"""
from collections import Counter, defaultdict
import json
from pathlib import Path
import runpy

HERE = Path(__file__).resolve().parent
legacy = runpy.run_path(str(HERE.parent / 'noise-cancellation/analyze.py'))
number = legacy['number']
value_range = legacy['value_range']
ORDINARY_NOISE_CALLER = 0x435ABF
KNOWN_NOISE_ENTRY_CALLER = 0x428BF3
FINISH_KINDS = {'coverage_finished', 'evaluation_finished',
                'noise_decode_finished', 'eligibility_finished',
                'noise_control_finished'}


def data(message):
    return message.get('data', message) if message else {}


def validate_native_scope(begin, changes, trigger):
    """Pure validation of a retained begin < original change < return chain.

    Inputs are original message envelopes with script and order annotations.
    A trigger has no nca field in this probe: its identity is supplied by the
    unique script/trial/scope/thread tuple, while changes must match begin.nca.
    """
    changes = list(changes)
    b, t = data(begin), data(trigger)
    reasons = []
    if not begin:
        reasons.append('missing-native-begin')
    if not trigger:
        reasons.append('missing-trigger')
    for key in ('script',):
        if not begin or begin.get(key) is None or not trigger or trigger.get(key) != begin.get(key):
            reasons.append('missing-or-mismatched-' + key)
    for key in ('trial', 'scope', 'thread'):
        if b.get(key) is None or t.get(key) != b.get(key):
            reasons.append('missing-or-mismatched-' + key)
    if b.get('nca') is None:
        reasons.append('missing-nca')
    if t.get('nca') is not None and t['nca'] != b.get('nca'):
        reasons.append('mismatched-trigger-nca')
    bo, to = (begin or {}).get('order'), (trigger or {}).get('order')
    order_valid = (isinstance(bo, int) and not isinstance(bo, bool)
                   and isinstance(to, int) and not isinstance(to, bool) and bo < to)
    if not order_valid:
        reasons.append('missing-or-invalid-begin-trigger-order')
    matched = []
    for change in changes:
        d = data(change)
        identity = (begin is not None and change.get('script') == begin.get('script')
                    and all(d.get(k) == b.get(k) and b.get(k) is not None
                            for k in ('trial', 'scope', 'thread', 'nca')))
        co = change.get('order')
        ordered = order_valid and isinstance(co, int) and not isinstance(co, bool) and bo < co < to
        ordinary = (d.get('old') == 1 and d.get('next') == 2
                    and number(d.get('caller')) == ORDINARY_NOISE_CALLER)
        if not identity:
            reasons.append('mismatched-change-identity')
        if not ordered:
            reasons.append('change-outside-strict-native-scope-order')
        if not ordinary:
            reasons.append('change-is-not-original-ordinary-1-to-2')
        if identity and ordered and ordinary:
            matched.append(change)
    if len(matched) != 1:
        reasons.append('expected-exactly-one-matching-original-change')
    return dict(valid=not reasons, reasons=list(dict.fromkeys(reasons)),
                matched_changes=matched, entry_caller=b.get('entryCaller'),
                scope=b.get('scope'), thread=b.get('thread'))


def precedes(a, b):
    """Strict retained order, with a frame/time fallback for derived endpoints."""
    if b is None:
        return True
    if isinstance(a.get('order'), int) and isinstance(b.get('order'), int):
        return a['order'] < b['order']
    return (a.get('frame', -1), a.get('real', 0)) < (b.get('frame', -1), b.get('real', 0))


def in_window(message, begin, cutoff):
    return not precedes(message, begin) and precedes(message, cutoff)


def location(message):
    return {k: message[k] for k in ('script', 'order', 'frame', 'real') if k in message}


def summarize_pairs(pairs):
    """Numeric changes in completed observations, without inferring a writer."""
    drops, increases, reduced = [], [], []
    for p in pairs:
        b, a = p['before'], p['after']
        bc, ac = b.get('count'), a.get('count')
        if isinstance(bc, (int, float)) and isinstance(ac, (int, float)):
            row = dict(at=p['at'], before=bc, after=ac)
            if ac < bc:
                drops.append(row)
            if ac > bc:
                increases.append(row)
        bv, av = b.get('value'), a.get('value')
        if isinstance(bv, (int, float)) and isinstance(av, (int, float)) and av < bv:
            reduced.append(dict(at=p['at'], before=bv, after=av))
    snapshots = [s for p in pairs for s in (p['before'], p['after'])]
    return dict(completed_observations=len(pairs), count_decreases=drops,
        count_increases=increases, count_increases_to_120=[r for r in increases if r['after'] == 120],
        value_decreases=reduced,
        ranges={k: value_range(s.get(k) for s in snapshots)
                for k in ('count', 'value', 'rate', 'threshold', 'dt', 'timeScale')},
        player_found_counts=dict(Counter(str(s.get('playerFound')) for s in snapshots)),
        value_below_threshold_snapshots=sum(
            isinstance(s.get('value'), (int, float)) and isinstance(s.get('threshold'), (int, float))
            and s['value'] < s['threshold'] for s in snapshots))


def summarize_eligibility(messages, nca, begin, cutoff):
    """Pure per-case pre-event summary; absent returns remain explicit gaps."""
    ready = [p for p in messages if p.get('kind') == 'eligibility_ready']
    finished = [p for p in messages if p.get('kind') == 'eligibility_finished']
    sources = {p['script'] for p in ready}
    applicable = [p for p in ready if precedes(p, cutoff)]
    active_from_entry = [p for p in applicable if not precedes(begin, p)
                        and not any(f['script'] == p['script'] and precedes(f, cutoff) for f in finished)]
    coverage = ('no-per-call-coverage-before-ready' if not applicable else
                'ready-before-entry' if active_from_entry else 'partial-window-or-finished-before-cutoff')
    selected = [p for p in messages if p.get('kind', '').startswith('eligibility_')
                and in_window(p, begin, cutoff)]
    befores = [p for p in selected if p['kind'] == 'eligibility_noise_before'
               and data(p).get('at', {}).get('nca') == nca]
    all_afters = defaultdict(list)
    for p in messages:
        if p.get('kind') == 'eligibility_noise_after':
            all_afters[(p['script'], data(p).get('call'))].append(p)
    pairs, missing, late, ambiguous = [], [], [], []
    for p in befores:
        candidates = all_afters[(p['script'], data(p).get('call'))]
        good = [q for q in candidates if data(q).get('at', {}).get('nca') == nca
                and precedes(p, q) and precedes(q, cutoff)]
        if len(good) == 1 and len(candidates) == 1:
            pairs.append(dict(at=location(good[0]), entry=location(p),
                              before=data(p)['at'], after=data(good[0])['at']))
        elif not candidates:
            missing.append(dict(**location(p), call=data(p).get('call')))
        elif len(candidates) == 1 and precedes(p, candidates[0]) and not precedes(candidates[0], cutoff):
            late.append(dict(**location(p), call=data(p).get('call')))
        else:
            ambiguous.append(dict(**location(p), call=data(p).get('call')))
    decays, sounds = [], []
    for p in selected:
        d = data(p)
        if p['kind'] not in ('eligibility_decay', 'eligibility_sound') or d.get('before', {}).get('nca') != nca:
            continue
        if d.get('after', {}).get('nca') != nca:
            continue
        row = dict(at=location(p), before=d['before'], after=d['after'])
        if p['kind'] == 'eligibility_decay':
            row['freezeReduction'] = d.get('freezeReduction')
            decays.append(row)
        else:
            row['type'] = d.get('type')
            sounds.append(row)
    decays.sort(key=lambda p: p['at'].get('order', -1))
    intervals = []
    for previous, following in zip(decays, decays[1:]):
        a, b = previous['after'].get('count'), following['before'].get('count')
        if isinstance(a, (int, float)) and isinstance(b, (int, float)) and b > a:
            intervals.append(dict(previous=previous['at'], following=following['at'],
                                  previous_after=a, following_before=b, increased_to_120=b == 120))
    errors = [p for p in selected if p['kind'] == 'eligibility_error' and p['script'] in sources]
    snapshots = [data(p)['at'] for p in befores]
    snapshots += [s for p in decays + sounds for s in (p['before'], p['after'])]
    return dict(coverage_status=coverage, ready=ready, finished=finished,
        cutoff=location(cutoff) if cutoff else None,
        noise_before=len(befores), noise_complete_pairs=len(pairs),
        noise_return_readback_complete=bool(befores) and len(pairs) == len(befores),
        noise_missing_return_readbacks=missing, noise_returns_after_cutoff=late,
        noise_ambiguous_return_readbacks=ambiguous, noise_pairs=summarize_pairs(pairs),
        decay=summarize_pairs(decays), decay_freeze_reduction_counts=dict(Counter(str(p.get('freezeReduction')) for p in decays)),
        decay_observations=decays, interval_count_increases=intervals,
        interval_count_increases_to_120=sum(p['increased_to_120'] for p in intervals),
        sound=summarize_pairs(sounds), sound_observations=sounds,
        sound_added_increases=sum(p['after'].get('added', 0) > p['before'].get('added', 0) for p in sounds),
        sound_types=dict(Counter(str(p['type']) for p in sounds)),
        observed_ranges={k: value_range(s.get(k) for s in snapshots)
                         for k in ('value', 'count', 'rate', 'threshold', 'added', 'ignore', 'dt', 'timeScale')},
        player_found_counts=dict(Counter(str(s.get('playerFound')) for s in snapshots)),
        errors=errors,
        limitation='The pre-event window uses retained message order, including same-frame order. Missing noise returns are not completed native readbacks. A decay record contains actual before/after observations, whereas a count increase between successive decay records only locates a net change in that interval, not its writer. These entry/readback probes do not identify every individual rejection branch.')


def loaded_sources(raw):
    return {r['normalized_result']['script_id']: Path(r['normalized_result']['source_path']).name
            for r in raw['records'] if r['operation'] == 'load_frida_script'}


def finish_status(raw, messages):
    loaded = loaded_sources(raw)
    ended = {p['script'] for p in messages if p.get('kind') in FINISH_KINDS}
    return dict(all_sources_finished=set(loaded) <= ended,
                unfinished_sources=sorted(set(loaded) - ended),
                sources=loaded,
                finish_markers=[p for p in messages if p.get('kind') in FINISH_KINDS])


def caller_summary(messages, kind):
    raw = [data(p).get('entryCaller') for p in messages if p.get('kind') == kind]
    parsed = [number(v) for v in raw]
    valid = [v for v in parsed if v is not None]
    return dict(observations=len(raw), raw_counts=dict(Counter(str(v) for v in raw)),
                rvas=[hex(v) for v in sorted(set(valid))],
                rva_range=[hex(min(valid)), hex(max(valid))] if valid else None,
                invalid_values=[v for v in raw if number(v) is None],
                known_static_caller=hex(KNOWN_NOISE_ENTRY_CALLER),
                all_observed_match_known_static_caller=bool(raw) and all(v == KNOWN_NOISE_ENTRY_CALLER for v in parsed),
                limitation='Observed return addresses only; the known original controller call is not an exhaustive caller whitelist.')


def analyze_natural(here=HERE):
    here = Path(here)
    result = legacy['analyze_natural'](here=here)
    raw = json.loads((here / 'rea-runtime.json').read_text(encoding='utf8'))
    messages, native_errors, _ = legacy['retained_messages'](raw)
    assert not any(p.get('kind', '').startswith('noise_control_') for p in messages), 'Replay messages in natural session'
    for c in result['cases']:
        own = [p for p in messages if p['script'] == c['script'] and data(p).get('id') == c['id']]
        begin = next(p for p in own if p['kind'] == 'coverage_enter')
        events = [p for p in own if p['kind'] == 'coverage_animation']
        cutoff = events[0] if events else c['end']
        c['eligibility'] = summarize_eligibility(messages, c['nca'], begin, cutoff)
    kinds = Counter(p.get('kind') for p in messages if p.get('kind', '').startswith('eligibility_'))
    before_keys = {(p['script'], data(p).get('call')) for p in messages if p.get('kind') == 'eligibility_noise_before'}
    after_keys = {(p['script'], data(p).get('call')) for p in messages if p.get('kind') == 'eligibility_noise_after'}
    result.update(finish_status(raw, messages))
    result.update(eligibility_observation_counts=dict(kinds),
        eligibility_pairing=dict(before=len(before_keys), after=len(after_keys),
            unmatched_before=len(before_keys - after_keys), orphan_after=len(after_keys - before_keys),
            limitation='Global key presence only; per-case analysis additionally requires identity, unique return, order and pre-event bounds.'),
        eligibility_errors=[p for p in messages if p.get('kind') == 'eligibility_error'],
        original_noise_entry_callers=caller_summary(messages, 'eligibility_noise_before'),
        native_script_errors=native_errors)
    result['limits'] += ['Cases ending before eligibility_ready have no per-call eligibility coverage; absence of such records is not a zero-count observation.',
        'Noise onEnter without onLeave is a capture/readback gap, not evidence that the original game failed to return. Completed decay readbacks remain separately usable.']
    return result


def analyze_replay(raw):
    messages, native_errors, joins = legacy['retained_messages'](raw)
    sources = loaded_sources(raw)
    replay_ids = {s for s, name in sources.items() if name == 'replay-deferred.js'}
    assert replay_ids, 'Expected the independent deferred-call script'
    assert not any(p.get('kind') == 'coverage_enter' for p in messages), 'Natural cases in replay session'
    trials = {}
    kinds = {'noise_control_samples': 'samples', 'noise_control_native_begin': 'native_begins',
             'noise_control_change': 'changes', 'noise_control_trigger': 'triggers',
             'noise_control_event': 'events', 'noise_control_callback': 'callbacks',
             'noise_control_model': 'models', 'noise_control_listener': 'listeners'}
    errors = [p for p in messages if p.get('kind') == 'noise_control_error']
    for p in messages:
        d, kind = data(p), p.get('kind')
        if kind == 'noise_control_begin':
            assert p['script'] in replay_ids, 'Unexpected replay source'
            key = (p['script'], d['trial'])
            assert key not in trials, 'Duplicate script/trial begin'
            trials[key] = dict(begin=p, end=None, **{v: [] for v in kinds.values()})
        elif kind in kinds or kind == 'noise_control_end':
            key = (p['script'], d['trial'])
            assert key in trials, 'Replay record lacks retained begin'
            if kind == 'noise_control_end':
                assert trials[key]['end'] is None, 'Duplicate trial end'
                trials[key]['end'] = p
            elif kind == 'noise_control_samples':
                trials[key]['samples'] += d['samples']
            else:
                trials[key][kinds[kind]].append(p)
    rows = []
    for (script, trial_id), t in trials.items():
        begin, end = t['begin'], t['end']
        native = t['native_begins'][0] if len(t['native_begins']) == 1 else None
        trigger = t['triggers'][0] if len(t['triggers']) == 1 else None
        validation = validate_native_scope(native, t['changes'], trigger)
        if len(t['native_begins']) != 1:
            validation['reasons'].append('expected-exactly-one-native-begin')
        if len(t['triggers']) != 1:
            validation['reasons'].append('expected-exactly-one-trigger')
        if native and data(native).get('nca') != data(begin).get('nca'):
            validation['reasons'].append('native-begin-nca-differs-from-trial')
        window_errors = [p for p in errors if legacy['inside'](p, begin, end)]
        if window_errors or native_errors:
            validation['reasons'].append('script-error-in-capture-or-trial')
        if native and not legacy['inside'](native, begin, end):
            validation['reasons'].append('native-begin-outside-trial')
        if trigger and not legacy['inside'](trigger, begin, end):
            validation['reasons'].append('trigger-outside-trial')
        validation['valid'] = not validation['reasons']
        result = legacy['classify_control_trial'](begin, t['samples'], t['triggers'],
            t['events'], t['callbacks'], end,
            changes=validation['matched_changes'] if validation['valid'] else [])
        observed = {k: len(t[k]) for k in ('events', 'models', 'callbacks', 'listeners')}
        reported = {k: data(end).get(k) for k in observed}
        counts_match = bool(end) and observed == reported
        # A retained event-marker gap cannot become a cancellation proof simply
        # because source snapshots are continuous. Keep positive events visible.
        if not t['events'] and (not counts_match or window_errors or native_errors):
            result['classification'] = 'unresolved-no-event'
        result.update(script=script, id=trial_id, plan=data(begin).get('plan'),
            nca=data(begin).get('nca'), receiver=data(begin).get('receiver'),
            begin=begin, end=end, native_begins=t['native_begins'],
            native_scope_chain_valid=validation['valid'], native_scope_validation=validation,
            models=observed['models'], listeners=observed['listeners'],
            observed_counts=observed, end_reported_counts=reported,
            end_counts_match=counts_match,
            all_four_counts_equal=len(set(observed.values())) == 1,
            markers={k: t[k] for k in ('events', 'models', 'callbacks', 'listeners')},
            errors=window_errors)
        rows.append(result)
    finish = finish_status(raw, messages)
    ended = {p['script'] for p in messages if p.get('kind') == 'noise_control_finished'}
    return dict(authority='controlled original game-invoked noise body after callback return; artificial numeric, state and geometry preconditions; separate from natural reachability',
        trials=rows, counts=dict(Counter(r['classification'] for r in rows)),
        total_events=sum(r['events'] for r in rows), total_callbacks=sum(r['callbacks'] for r in rows),
        total_models=sum(r['models'] for r in rows), total_listeners=sum(r['listeners'] for r in rows),
        native_scope_chain_valid_trials=[dict(script=r['script'], id=r['id']) for r in rows if r['native_scope_chain_valid']],
        ordinary_pre_event_turn_trials=[dict(script=r['script'], id=r['id']) for r in rows if r['pre_event_turn_confirmed']],
        original_noise_entry_callers=caller_summary(messages, 'noise_control_native_begin'),
        all_control_sources_finished=replay_ids <= ended,
        errors=errors, native_script_errors=native_errors, capture_joins=joins,
        limits=['A native 1->2 trace proves execution of the ordinary branch in this artificial trial, not that natural Found values can pass its threshold before the animation event.',
                'A plan name does not predict event outcome; actual event, model, callback and listener markers are independently counted.',
                'Source exit below its marker without an event is bounded by retained consecutive snapshots; it does not identify the exact sub-frame cancellation point.',
                'Cleanup verifies only enumerated fields/state/found and player position, not all world effects.'], **finish)


def analyze(here=HERE):
    here = Path(here)
    natural = analyze_natural(here) if (here / 'rea-runtime.json').exists() else None
    replay = analyze_replay(json.loads((here / 'replay-runtime.json').read_text(encoding='utf8'))) if (here / 'replay-runtime.json').exists() else None
    return dict(schema_version=1, status='noise-original-callsite-evidence-separated',
        natural=natural, replay=replay,
        all_sources_finished=all(v is not None and v['all_sources_finished'] for v in (natural, replay)),
        unavailable=[name for name, value in (('natural', natural), ('replay', replay)) if value is None],
        scope='Natural and artificial trials are never combined; script/trial and native scope identities are retained. Missing returns are explicit readback gaps.')


if __name__ == '__main__':
    print(json.dumps(analyze(), ensure_ascii=False, indent=2))
