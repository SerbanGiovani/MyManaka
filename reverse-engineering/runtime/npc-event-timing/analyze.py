"""Analyze measured Unity fixture logs and independently collected REA messages.

No simulation and no execution of the target; --check compares saved results.
"""
import argparse
import gzip
import hashlib
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent


def read_log(path):
    opener = gzip.open if path.suffix == '.gz' else open
    with opener(path, 'rt', encoding='utf-8-sig') as f:
        return [json.loads(line) for line in f if line.strip()]


def analyze(rows, evidence):
    assert rows[-1]['kind'] == 'complete', 'Run did not complete'
    assert not any(r['kind'] in ('fatal', 'patch_error') for r in rows), 'Fixture error'
    payloads = []
    for record in evidence['records']:
        if record['operation'] != 'frida_session_status':
            continue
        result = record['normalized_result']
        assert not result['messages_truncated'], 'REA capture truncated'
        payloads.extend(m['payload'] for m in result['messages'] if m['type'] == 'send')
    # Multiple status observations retain overlapping history; use the final snapshot.
    statuses = [r for r in evidence['records'] if r['operation'] == 'frida_session_status']
    if statuses:
        # Select most complete retained snapshot, not lexicographic evidence ID order.
        last = max(statuses, key=lambda r: len(r['normalized_result']['messages']))
        payloads = [m['payload'] for m in last['normalized_result']['messages'] if m['type'] == 'send']
    begins = [r for r in rows if r['kind'] == 'begin']
    ordering_start=next(m['frame'] for m in payloads if m['kind']=='ordering_ready')
    results = []
    for begin in begins:
        trial = begin['trial']
        rr = [r for r in rows if r['trial'] == trial]
        end = next(r for r in rr if r['kind'] == 'end')
        native = [m for m in payloads if begin['frame'] <= m.get('frame', -1) <= end['frame']
                  and m.get('data', {}).get('receiver') == hex(int(begin['data']['receiver']))]
        events = [m for m in native if m['kind'] == 'animation_event_native']
        callbacks = [m for m in native if m['kind'] == 'delayed_callback_native']
        queues = [r for r in rr if r['kind'] == 'animation_queue']
        broadcasts = [r for r in rr if r['kind'] == 'broadcast_listener']
        stops = [r for r in rr if r['kind'] == 'stop']
        resumes = [r for r in rr if r['kind'] == 'resume']
        samples = [r for r in rr if r['kind'] == 'sample']
        model_ptrs={hex(int(m['model'])) for s in samples for m in s['data']['remaining']}
        steps=[m for m in payloads if m['kind']=='countdown_step' and m['data']['model'] in model_ptrs
               and begin['frame']<=m['frame']<=end['frame']]
        first_step=next((m for m in steps if m['data']['call']==1 and abs(m['data']['before']-0.6)<1e-6),None)
        assert len(events) == len(queues), (trial, 'event/queue mismatch')
        assert len(callbacks) == len(broadcasts), (trial, 'callback/broadcast mismatch')
        assert end['data']['events'] == len(queues), (trial, 'queue counter mismatch')
        assert end['data']['broadcasts'] == len(broadcasts), (trial, 'listener mismatch')
        assert all(r['data']['npc'] == begin['data']['npc'] for r in broadcasts), (trial, 'wrong NPC')
        paused = [s for s in samples if s['data']['stop']]
        remaining = [m['remaining'] for s in paused for m in s['data']['remaining']]
        expected = 0 if trial.endswith('/repeated_stop_before') else 1
        assert len(events) == len(callbacks) == expected, (trial, 'unexpected delivery')
        if stops:
            assert all(s['data']['speed'] == 0 for s in paused), (trial, 'paused animator advanced speed')
            assert not any(stops[0]['frame'] <= r['frame'] < resumes[0]['frame'] for r in broadcasts), (trial, 'broadcast during pause')
            assert not any(stops[0]['frame'] <= r['frame'] < resumes[0]['frame'] for r in events), (trial, 'animation event during pause')
        if remaining:
            assert max(remaining)-min(remaining) < 1e-6, (trial, 'remaining decremented during stop')
        event = events[0] if events else None
        callback = callbacks[0] if callbacks else None
        results.append({
            'trial': trial, 'native_events': len(events), 'queues': len(queues),
            'native_callbacks': len(callbacks), 'broadcast_listeners': len(broadcasts),
            'parameter_to_event_real_s': round(event['real']-next(r['real'] for r in rr if r['kind']=='found_parameter'), 6) if event else None,
            'event_to_callback_real_s': round(callback['real']-event['real'], 6) if callback else None,
            'event_to_callback_scaled_s': round(callback['time']-event['time'], 6) if callback else None,
            'event_callback_frames': callback['frame']-event['frame'] if callback else None,
            'event_frame': event['frame'] if event else None,
            'callback_frame': callback['frame'] if callback else None,
            'countdown_observer_covered_from_trial_start':begin['frame']>=ordering_start,
            'first_observed_initial_countdown_frame':first_step['frame'] if first_step else None,
            'first_countdown_event_frame_offset':first_step['frame']-event['frame'] if first_step and event else None,
            'stop_records': [{'frame':r['frame'], 'age_s': round(r['real']-begin['real'],6), **r['data']} for r in stops],
            'resume_records': [{'frame':r['frame'], **r['data']} for r in resumes],
            'paused_queue_remaining_min': min(remaining) if remaining else None,
            'paused_queue_remaining_max': max(remaining) if remaining else None,
            'paused_normalized_min': min(s['data']['normalized'] for s in paused) if paused else None,
            'paused_normalized_max': max(s['data']['normalized'] for s in paused) if paused else None,
            'final_speed':end['data']['speed'],
        })
    assert len(results) == 60, 'Incomplete matrix'
    return {'schema_version':1,'kind':'controlled-runtime-measurement',
            'trials':len(results),'native_events':sum(r['native_events'] for r in results),
            'native_callbacks':sum(r['native_callbacks'] for r in results),
            'duplicate_events':sum(max(0,r['native_events']-1) for r in results),
            'duplicate_callbacks':sum(max(0,r['native_callbacks']-1) for r in results),
            'results':results}


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--log',type=Path,default=HERE/'fixture.jsonl.gz')
    p.add_argument('--evidence',type=Path,default=HERE/'rea-runtime.json')
    p.add_argument('--output',type=Path,default=HERE/'results.json')
    p.add_argument('--check',action='store_true')
    args=p.parse_args()
    result=analyze(read_log(args.log),json.loads(args.evidence.read_text(encoding='utf-8-sig')))
    result['inputs']={str(path.name):hashlib.sha256(path.read_bytes()).hexdigest() for path in [args.log,args.evidence]}
    if args.check:
        assert result==json.loads(args.output.read_text(encoding='utf-8')), 'Saved result differs'
    else:
        args.output.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:v for k,v in result.items() if k!='results'},ensure_ascii=False))


if __name__=='__main__': main()
