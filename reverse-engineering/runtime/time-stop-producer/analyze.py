"""Reconcile native producer, NPC delivery, animation and listener observations."""
import argparse
import gzip
import hashlib
import json
from pathlib import Path
HERE=Path(__file__).resolve().parent


def read(path):return json.loads(path.read_text(encoding='utf-8-sig'))


def analyze(root=HERE):
    raw=gzip.decompress((root/'fixture.jsonl.gz').read_bytes())
    rows=[json.loads(x) for x in raw.decode('utf-8-sig').splitlines()]
    assert rows[-1]['kind']=='complete' and not any(r['kind'] in ('fatal','patch_error') for r in rows)
    evidence=read(root/'rea-runtime.json')
    status=next(r for r in evidence['records'] if r['operation']=='frida_session_status')['normalized_result']
    assert not status['messages_truncated'] and not any(m['type']=='error' for m in status['messages'])
    payload=[m['payload'] for m in status['messages'] if m['type']=='send']
    results=[]
    for begin in [r for r in rows if r['kind']=='begin']:
        trial=begin['trial'];rr=[r for r in rows if r['trial']==trial];end=next(r for r in rr if r['kind']=='end')
        mm=[m for m in payload if begin['frame']<=m.get('frame',-1)<=end['frame']]
        npc=hex(int(begin['data']['npc']));receiver=hex(int(begin['data']['receiver']))
        enter=[m for m in mm if m['kind']=='producer_enter']
        leave=[m for m in mm if m['kind']=='producer_leave']
        delivered=[m for m in mm if m['kind']=='npc_stop_enter' and m['data']['npc']==npc]
        returned=[m for m in mm if m['kind']=='npc_stop_leave' and m['data']['npc']==npc]
        events=[m for m in mm if m['kind']=='animation_event_native' and m['data']['receiver']==receiver]
        callbacks=[m for m in mm if m['kind']=='delayed_callback_native' and m['data']['receiver']==receiver]
        broadcasts=[r for r in rr if r['kind']=='broadcast_listener']
        queues=[r for r in rr if r['kind']=='animation_queue']
        case=begin['data']['scenario'];control=case in ('extra_true_broadcast','silent_reset_then_toggle')
        expected=0 if control else 1
        assert len(events)==len(queues)==len(callbacks)==len(broadcasts)==expected,(trial,'event delivery')
        assert len(enter)==len(leave) and len(delivered)==len(returned),(trial,'unpaired calls')
        producer_states=[m['data']['stop'] for m in leave]
        delivery_states=[m['data']['stop'] for m in delivered]
        expected_states=([1,1,0] if case=='silent_reset_then_toggle' else [1,0,1,0] if case=='producer_rapid_four' else [1,0])
        assert producer_states==expected_states,(trial,producer_states)
        assert delivery_states==([1,1,0] if control else expected_states),(trial,delivery_states)
        assert end['data']['speed']==(0 if control else 1) and end['data']['stop'] is False
        assert end['data']['events']==expected and end['data']['broadcasts']==expected
        assert all(r['data']['npc']==begin['data']['npc'] for r in broadcasts)
        for m in enter:
            nested=[d for d in delivered if d['data']['producer']==m['data']['id']]
            assert len(nested)==1,(trial,'producer delivery duplicated')
        subscriptions=[r['data'] for r in rr if r['kind']=='subscribe']
        assert subscriptions[0]['before']==1 and subscriptions[0]['after']==2
        if 'dedup' in case:
            assert len(subscriptions)==2 and subscriptions[1]['before']==subscriptions[1]['after']==2
            assert subscriptions[0]['target']==subscriptions[1]['target']==begin['data']['npc']
            assert subscriptions[0]['action']!=subscriptions[1]['action']
        for q in rr:
            if q['kind']=='producer_return':assert q['data']['before']!=q['data']['after']
        results.append({'trial':trial,'kind':'injected counterfactual' if control else 'controlled original producer path',
          'producer_after_states':producer_states,'npc_delivery_states':delivery_states,
          'npc_cache_after_delivery':[r['data']['cache'] for r in returned],
          'native_events':len(events),'native_callbacks':len(callbacks),'listener_broadcasts':len(broadcasts),
          'final_speed':end['data']['speed'],'subscriptions':subscriptions,
          'player_animation_triggers':sum(r['kind']=='player_trigger' for r in rr),
          'producer_frames':[m['frame'] for m in enter],'npc_event_frame':events[0]['frame'] if events else None,
          'npc_callback_frame':callbacks[0]['frame'] if callbacks else None})
    assert len(results)==32
    return {'schema_version':1,'scope':'controlled original producer paths and explicit counterfactual controls',
      'trials':len(results),'producer_calls':sum(len(r['producer_after_states']) for r in results),
      'npc_time_stop_deliveries':sum(len(r['npc_delivery_states']) for r in results),
      'native_events':sum(r['native_events'] for r in results),'native_callbacks':sum(r['native_callbacks'] for r in results),
      'normal_path_trials':sum(r['kind']=='controlled original producer path' for r in results),
      'injected_control_trials':sum(r['kind']=='injected counterfactual' for r in results),
      'bootstrap_loaded_records':sum(r['kind']=='loaded' for r in rows),'results':results}


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--check',action='store_true');args=p.parse_args()
    result=analyze()
    result['input_sha256']={name:hashlib.sha256((HERE/name).read_bytes()).hexdigest() for name in ('fixture.jsonl.gz','rea-runtime.json')}
    target=HERE/'results.json'
    if args.check:assert result==read(target),'Saved measurements differ'
    else:target.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps({k:v for k,v in result.items() if k!='results'}))


if __name__=='__main__':main()
