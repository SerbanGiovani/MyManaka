"""Keep passive noise evidence and artificial receiver replays separate.

The pure classifiers never equate a false parameter or business exit with an
internal clip cancellation.  Imported previous classifiers remain unchanged.
"""
from collections import Counter, defaultdict
import json
from pathlib import Path
import runpy

HERE = Path(__file__).resolve().parent
core = runpy.run_path(str(HERE.parent / 'natural-event-coverage/analyze.py'))
FOUND = core['FOUND']
ORDINARY_NOISE_CALLER = 0x435ABF


def number(value):
    try:
        if isinstance(value, str):
            # A probe may prepend 0x to NativePointer.toString(), which already
            # has that prefix. Keep raw evidence untouched; normalize only here.
            while value.lower().startswith('0x0x'):
                value = value[2:]
            return int(value, 0)
        return int(value)
    except (ValueError, TypeError):
        return None


def ordinary_noise_change(change):
    """An observed original ordinary branch, not the separate +a0 hit branch."""
    d = change.get('data', change)
    return (d.get('old') == 1 and d.get('next') == 2
            and number(d.get('caller')) == ORDINARY_NOISE_CALLER)


def sample_gaps(samples):
    frames = sorted({s['frame'] for s in samples})
    return [dict(before=a, after=b, missing_frames=b-a-1)
            for a, b in zip(frames, frames[1:]) if b > a+1]


def source_states(sample):
    current = sample.get('current', {})
    candidates = [current]
    if sample.get('transition'):
        candidates.append(sample.get('next', {}))
    return [s for s in candidates if s.get('full') in FOUND]


def before_event(sample, event):
    return core['before'](sample, event)


def value_range(values):
    values = [v for v in values if isinstance(v, (int, float))]
    return [min(values), max(values)] if values else None


def summarize_noise_samples(samples, event=None):
    """Readback ranges, with explicit freshness for cached calculation values."""
    selected = [s for s in samples if before_event(s, event)]
    business = [s['business'] for s in selected if s.get('business')]
    fresh = [s['business']['lastCalculation']['values'][3] for s in selected
             if s.get('business', {}).get('lastCalculation')
             and s['business']['lastCalculation'].get('frame') == s['frame']
             and len(s['business']['lastCalculation'].get('values', [])) > 3]
    return dict(samples=len(selected), frame_gaps=sample_gaps(selected),
        value_range=value_range(b.get('noiseValue', b.get('value')) for b in business),
        reduce_count_range=value_range(b.get('noiseReduceCount', b.get('reduceCount')) for b in business),
        threshold_range=value_range(b.get('noiseThreshold', b.get('threshold')) for b in business),
        added_positive_samples=sum(b.get('noiseAdded', b.get('added', 0)) > 0 for b in business),
        player_not_found_samples=sum(b.get('playerFound') == 0 for b in business),
        value_below_threshold_samples=sum(
            b.get('noiseValue', b.get('value', float('inf')))
            < b.get('noiseThreshold', b.get('threshold', float('-inf'))) for b in business),
        fresh_continuous_noise_samples=len(fresh), fresh_continuous_noise_range=value_range(fresh),
        limitation='Cached lastCalculation is counted as current only on its recorded frame; these are sampled values, not all native evaluations.')


def at_order(p):
    return p.get('order', 0)


def inside(p, begin, end):
    return at_order(begin) <= at_order(p) <= (at_order(end) if end else float('inf'))


def cleanup_result(end):
    c = end.get('data', {}).get('cleanup', {}) if end else {}
    good = (not c.get('errors') and not c.get('retired')
            and all(c.get(k) is True for k in ['fieldsMatch', 'stateMatches', 'foundMatches'])
            and isinstance(c.get('positionError'), (int, float)) and c['positionError'] <= 1e-5)
    return dict(verified_listed_fields_and_position=good, readback=c,
                limitation='Only the enumerated fields, requested business state, found parameter and player position are checked; this does not establish restoration of the world or interaction side effects.')


def classify_control_trial(begin, samples, triggers, events, callbacks, end,
                           changes=(), passive_samples=()):
    """Conservative, side-effect-free classification of one (script, trial)."""
    samples = sorted(samples, key=lambda s: (s['frame'], s.get('real', 0)))
    stop_frame = end['frame'] if end else float('inf')
    samples = [s for s in samples if begin['frame'] <= s['frame'] <= stop_frame]
    passive_samples = [s for s in passive_samples if begin['frame'] <= s['frame'] <= stop_frame]
    trigger = triggers[0] if len(triggers) == 1 else None
    td = trigger.get('data', {}) if trigger else {}
    before = td.get('before', {})
    after = td.get('after', {})
    after_sound = td.get('afterSound', {})
    matching_changes = [c for c in changes if ordinary_noise_change(c)
                        and trigger and c['frame'] == trigger['frame']
                        and at_order(c) <= at_order(trigger)]
    positive = after_sound.get('added', 0) > 0
    state_two = after.get('business', {}).get('state') == 2
    receiver_readback = (positive and state_two
                         and before.get('business', {}).get('state') == 1
                         and after_sound.get('state') == 1)
    native_turn = bool(matching_changes) and receiver_readback
    trigger_sources = source_states(before)
    below_marker = bool(trigger_sources) and all(s['normalized'] < FOUND[s['full']] for s in trigger_sources)
    event_before = any(trigger and at_order(e) <= at_order(trigger) for e in events)
    # Trigger is emitted after the original calls. An event within those calls
    # also makes this a failed pre-event window, conservatively.
    pre_event_turn = bool(native_turn and below_marker and not event_before)
    after_trigger = [s for s in samples if trigger and (s['frame'], s.get('real', 0))
                     >= (trigger['frame'], trigger.get('real', 0))]
    footprints = [v for s in after_trigger for v in source_states(s)]
    gone = sorted({s['frame'] for s in after_trigger if not source_states(s) and not s.get('transition')})
    successive_gone = any(b == a+1 for a, b in zip(gone, gone[1:]))
    gaps = sample_gaps(samples)
    below_all = all(v['normalized'] < FOUND[v['full']] for v in footprints)
    complete = bool(end and end['data'].get('reason') == 'completed')
    crossings = []
    for a, b in zip(samples, samples[1:]):
        x, y = a.get('current', {}), b.get('current', {})
        h = x.get('full')
        if (h in FOUND and y.get('full') == h and b['frame'] == a['frame']+1
                and not a.get('transition') and not b.get('transition')
                and x['normalized'] < FOUND[h] <= y['normalized']):
            crossings.append(dict(before=a['frame'], after=b['frame'], full=h,
                eligible=all(s.get('fireEvents') == 1 and s.get('weight', 0) > 0
                             and s.get('speed', 0) > 0 for s in [a, b])))
    if events:
        classification = 'event-generated' if len(events) == 1 else 'multiple-events-review'
    elif complete and pre_event_turn and successive_gone and below_all and not gaps:
        classification = 'normal-transition-exit-without-event-observed'
    elif (complete and receiver_readback and below_marker and not event_before
          and successive_gone and below_all and not gaps):
        classification = 'bounded-clip-exit-without-event-after-receiver-replay'
    elif complete and any(x['eligible'] for x in crossings):
        classification = 'stable-threshold-crossing-without-event-candidate'
    else:
        classification = 'unresolved-no-event'
    stable = (bool(trigger_sources) and not before.get('transition')
              and before.get('current', {}).get('full') in FOUND)
    return dict(classification=classification, complete=complete, sample_count=len(samples),
        frame_gaps=gaps, passive_frame_gaps=sample_gaps(passive_samples),
        trigger_count=len(triggers), sound_added_positive=positive,
        after_business_state_two=state_two, receiver_replay_turn_readback=receiver_readback,
        original_ordinary_turn_confirmed=native_turn,
        original_ordinary_changes=matching_changes, trigger_below_marker=below_marker,
        trigger_from_stable_current=stable, event_observed_before_or_during_trigger=event_before,
        pre_event_turn_confirmed=pre_event_turn, trigger_snapshot=td,
        source_gone_on_consecutive_frames=successive_gone,
        last_observed_source=footprints[-1] if footprints else (trigger_sources[-1] if trigger_sources else None),
        sampled_source_stayed_below_marker=below_all, stable_crossings=crossings,
        events=len(events), callbacks=len(callbacks), event_callback_counts_match=len(events) == len(callbacks),
        cleanup=cleanup_result(end),
        limitation='A parameter false or business 1->2 alone is not clip cancellation. Receiver replay readback does not prove that a nested native callsite hook executed. Source disappearance below marker with no observed event is a bounded transition observation, not proof of the exact sub-frame cancellation mechanism. Missing snapshots and blend-only crossings remain unknown.')


def retained_messages(raw):
    sessions = {r['normalized_result'].get('session_id', r.get('parameters', {}).get('session_id'))
                for r in raw['records'] if r['operation'] == 'frida_session_status'}
    assert len(sessions) == 1, 'Do not merge status messages across Frida sessions'
    retained, joins = core['merge_statuses'](raw['records'])
    messages = [dict(m['payload'], script=m['script_id'], order=i)
                for i, m in enumerate(retained) if m['type'] == 'send']
    errors = [m for m in retained if m['type'] == 'error']
    return messages, errors, joins


def control_source_ids(raw):
    return {r['normalized_result']['script_id'] for r in raw['records']
            if r['operation'] == 'load_frida_script'
            and Path(r['normalized_result']['source_path']).name.startswith('control')}


def analyze_replay(raw):
    messages, native_errors, joins = retained_messages(raw)
    control_ids = control_source_ids(raw)
    trials = {}
    coverage_nca = {}
    for p in messages:
        d = p.get('data', {})
        if p['kind'] == 'coverage_enter':
            coverage_nca[(p['script'], d['id'])] = d['nca']
        if p['kind'] == 'noise_control_begin':
            assert p['script'] in control_ids
            trials[(p['script'], d['trial'])] = dict(begin=p, samples=[], triggers=[], events=[], callbacks=[], end=None)
        elif p['kind'].startswith('noise_control_') and 'trial' in d:
            key = (p['script'], d['trial'])
            assert key in trials, 'Control record lacks a retained trial begin'
            t = trials[key]
            if p['kind'] == 'noise_control_samples': t['samples'] += d['samples']
            elif p['kind'] == 'noise_control_trigger': t['triggers'].append(p)
            elif p['kind'] == 'noise_control_event': t['events'].append(p)
            elif p['kind'] == 'noise_control_callback': t['callbacks'].append(p)
            elif p['kind'] == 'noise_control_end': t['end'] = p
    rows = []
    for (script, trial_id), t in trials.items():
        begin, end = t['begin'], t['end']
        nca, receiver = begin['data']['nca'], begin['data']['receiver']
        window = [p for p in messages if inside(p, begin, end)]
        changes = [p for p in window if
                   (p['kind'] == 'coverage_business_change'
                    and coverage_nca.get((p['script'], p['data']['id'])) == nca)
                   or (p['kind'] == 'noise_control_change' and p['script'] == script
                       and p['data'].get('trial') == trial_id and p['data'].get('nca') == nca)]
        # Batches can be flushed after a control end. Select their embedded
        # sample frame window, not their later envelope's delivery order.
        passive = [s for p in messages if p['kind'] == 'coverage_samples'
                   and coverage_nca.get((p['script'], p['data']['id'])) == nca
                   for s in p['data']['samples'] if begin['frame'] <= s['frame']
                   <= (end['frame'] if end else float('inf'))]
        passive_events = [p for p in window if p['kind'] == 'coverage_animation' and p['data']['receiver'] == receiver]
        passive_callbacks = [p for p in window if p['kind'] == 'coverage_callback' and p['data']['receiver'] == receiver]
        event_keys = {(p['script'], p['data']['event']) for p in passive_events}
        models = [p for p in window if p['kind'] == 'coverage_model' and p['data']['receiver'] == receiver
                  and (p['script'], p['data']['event']) in event_keys]
        npc = next((p['data'].get('at', {}).get('npc') for p in passive_events if p['data'].get('at')), None)
        if npc is None:
            npc = next((s.get('npc') for s in passive if s.get('npc')), None)
        listeners = [p for p in window if p['kind'] == 'coverage_listener' and p['data'].get('npc') == npc]
        result = classify_control_trial(**t, changes=changes, passive_samples=passive)
        # These are corroborating observations of the same calls, not extra events.
        result.update(script=script, id=trial_id, plan=begin['data']['plan'], nca=nca, receiver=receiver,
            begin=begin, end=end,
            passive_corroboration=dict(events=len(passive_events), models=len(models), callbacks=len(passive_callbacks), listeners=len(listeners),
                event_frames=[p['frame'] for p in passive_events],
                counts_match=(len(passive_events) == len(t['events']) and len(passive_callbacks) == len(t['callbacks'])),
                limitation='Passive listener/model counts belong to this receiver/NPC and trial window; they corroborate control observations and are not added to their event totals.'))
        rows.append(result)
    finished = [p for p in messages if p['kind'] == 'noise_control_finished']
    loaded = {r['normalized_result']['script_id'] for r in raw['records'] if r['operation'] == 'load_frida_script'}
    ends = {p['script'] for p in messages if p['kind'] in ['noise_control_finished', 'coverage_finished', 'evaluation_finished', 'noise_decode_finished']}
    return dict(authority='controlled replay with artificial state, geometry and numeric/visibility preconditions; never natural cancellation evidence',
        trials=rows, counts=dict(Counter(r['classification'] for r in rows)),
        total_events=sum(r['events'] for r in rows), total_callbacks=sum(r['callbacks'] for r in rows),
        ordinary_pre_event_turn_trials=[dict(script=r['script'], id=r['id']) for r in rows if r['pre_event_turn_confirmed']],
        finished=finished, all_control_sources_finished=control_ids <= {p['script'] for p in finished},
        all_sources_finished=loaded <= ends, unfinished_sources=sorted(loaded-ends),
        errors=[p for p in messages if p['kind'] in ['noise_control_error', 'coverage_error', 'evaluation_error', 'noise_decode_error']],
        native_script_errors=native_errors, capture_joins=joins,
        limits=['An artificial lowered value bypasses a natural threshold guard; replay success does not establish natural reachability.',
                'Event counters remain independent of expected cancellation and of passive duplicate observations.',
                'Entering and exiting transitions may continue advancing the source after found becomes false.',
                'Cleanup checks cover only the explicitly saved fields and position.'])


def analyze_natural(here=HERE):
    # Change only this isolated imported function's input root and restore it.
    globals_ = core['analyze'].__globals__
    previous = globals_['HERE']
    globals_['HERE'] = here
    try:
        result = core['analyze']()
    finally:
        globals_['HERE'] = previous
    raw = json.loads((here/'rea-runtime.json').read_text(encoding='utf8'))
    assert not control_source_ids(raw), 'Controlled script found in passive natural evidence'
    messages, _, _ = retained_messages(raw)
    changes = [p for p in messages if p['kind'] == 'coverage_business_change']
    turns = [p for p in messages if p['kind'] == 'noise_turn']
    calculations = [p for p in messages if p['kind'] == 'noise_calculation']
    sounds = [p for p in messages if p['kind'] == 'noise_player_sound']
    loaded = {r['normalized_result']['script_id'] for r in raw['records'] if r['operation'] == 'load_frida_script'}
    ended = {p['script'] for p in messages if p['kind'] in ['coverage_finished', 'evaluation_finished', 'noise_decode_finished']}
    for c in result['cases']:
        own = [p for p in messages if p.get('data', {}).get('id') == c['id'] and p['script'] == c['script']]
        samples = [s for p in own if p['kind'] == 'coverage_samples' for s in p['data']['samples']]
        events = [p for p in own if p['kind'] == 'coverage_animation']
        c['noise_samples'] = summarize_noise_samples(samples, events[0] if events else None)
        c['ordinary_noise_business_exits'] = [p for p in own if p['kind'] == 'coverage_business_change' and ordinary_noise_change(p)]
        c['noise_turn_observations'] = [p for p in turns if p['data']['nca'] == c['nca'] and c['entry_frame'] <= p['frame'] <= (c['end']['frame'] if c['end'] else float('inf'))]
        # The observer intentionally suppresses most zero calculations outside
        # active cases. Absence in this bounded pre-entry window is not zero.
        entry_real = c['entry_real']
        prior_calc = [p for p in calculations if p['data']['nca'] == c['nca'] and entry_real-5 <= p['real'] < entry_real]
        prior_sound = [p for p in sounds if p['data']['nca'] == c['nca'] and entry_real-5 <= p['real'] < entry_real]
        c['before_entry_noise'] = dict(window_real_seconds=5, calculations=len(prior_calc),
            positive_continuous_calculations=sum(p['data']['values'][3] > 0 for p in prior_calc),
            sounds=len(prior_sound), positive_sound_readbacks=sum(p['data']['after'].get('added', 0) > 0 for p in prior_sound),
            limitation='Only emitted observations in the five seconds before this entry; zero calculations and unchanged sound readbacks are not exhaustively emitted outside active cases.')
    result.update(status='natural-noise-search-bounded',
        noise_turns=turns, ordinary_found_noise_changes=[p for p in changes if ordinary_noise_change(p)],
        noise_observation_counts=dict(calculations=len(calculations),
            positive_continuous_calculations=sum(p['data']['values'][3] > 0 for p in calculations),
            sound_readbacks=len(sounds), positive_sound_readbacks=sum(p['data']['after'].get('added', 0) > 0 for p in sounds),
            sound_increases=sum(p['data']['after'].get('added', 0) > p['data']['before'].get('added', 0) for p in sounds),
            ordinary_branch_turns=sum(number(p['data'].get('caller')) == ORDINARY_NOISE_CALLER for p in turns),
            ordinary_branch_turns_from_found=sum(number(p['data'].get('caller')) == ORDINARY_NOISE_CALLER
                and p['data'].get('before', {}).get('state') == 1 for p in turns)),
        all_sources_finished=loaded <= ended, unfinished_sources=sorted(loaded-ended),
        additional_finish_markers=[p for p in messages if p['kind'] == 'noise_decode_finished'],
        noise_decode_errors=[p for p in messages if p['kind'] == 'noise_decode_error'],
        authority='passive original input and original noise processing; separate from every artificial replay')
    result['limits'] += ['Natural found entry requires value>=1; a value-lowered replay cannot establish that the natural pre-event noise threshold gate is reachable.',
        'Positive sound readback means the added field was positive at that observation, not proof that this sound increased it or immediately caused a turn.']
    return result


def analyze():
    natural = analyze_natural() if (HERE/'rea-runtime.json').exists() else None
    replay = analyze_replay(json.loads((HERE/'replay-runtime.json').read_text(encoding='utf8'))) if (HERE/'replay-runtime.json').exists() else None
    additional = analyze_replay(json.loads((HERE/'v3-runtime.json').read_text(encoding='utf8'))) if (HERE/'v3-runtime.json').exists() else None
    return dict(schema_version=1, status='noise-cancellation-evidence-separated',
        natural=natural, replay=replay, replay_additional=additional,
        all_sources_finished=all(v is not None and v['all_sources_finished'] for v in [natural,replay,additional]),
        unavailable=[name for name, value in [('natural', natural), ('replay', replay), ('replay_additional', additional)] if value is None],
        scope='Natural and controlled counts are never combined. A bounded absence after source exit is distinct from a stable-source threshold crossing candidate.')


if __name__ == '__main__':
    print(json.dumps(analyze(), ensure_ascii=False, indent=2))
