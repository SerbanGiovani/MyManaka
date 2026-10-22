"""Separate natural observations from explicitly controlled post-enqueue trials."""
from collections import Counter,defaultdict,deque
import gzip,json
from pathlib import Path
HERE=Path(__file__).resolve().parent
def close(a,b):return abs(a-b)<=max(1e-6,abs(b)*1e-6)

def associate_listener(callback,rows,npc,unique_callback):
    candidates=[r for r in rows if r['frame']==callback['frame']]
    if not unique_callback:return []
    return [r for r in candidates if r['data'].get('argumentConvention') is None or r['data']['npc']==npc]

def associate_group(callback,rows,npc,expected,frame_callbacks):
    same_frame=[r for r in rows if r['frame']==callback['frame']]
    typed=[r for r in same_frame if r['data'].get('argumentConvention') is not None]
    candidates=[r for r in typed if r['data']['npc']==npc] if typed else associate_listener(callback,same_frame,npc,frame_callbacks==1)
    return dict(frame=callback['frame'],npc=npc if typed else None,expected_callbacks=expected,
       listener_entries=len(candidates),balanced=expected>0 and len(candidates)==expected,
       association='same-NPC/frame group' if typed else 'unique callback/listener frame; legacy NPC field ignored',
       individually_attributed=expected==1)

def summarize_queue(samples):
    violations=[];frozen=[];hidden=[];crossings=[];isolated=0;ordinary=0
    for a,b in zip(samples,samples[1:]):
        x,y=a['data'],b['data']
        if b['frame']==a['frame']+1 and x.get('present') and y.get('present') and x['stop']==1 and y['stop']==1 and x['remaining']>0 and y['remaining']>0:
            frozen.append((a['frame'],b['frame']))
            if x.get('timeScale')==1 and y.get('timeScale')==1:isolated+=1
            if x.get('timeScale')==0 and y.get('timeScale')==0:ordinary+=1
            if not close(x['remaining'],y['remaining']):violations.append([a['frame'],b['frame'],x['remaining'],y['remaining']])
        ax,ay=x.get('actor'),y.get('actor')
        if ax and ay and ax['meshActive']!=ay['meshActive']:hidden.append([a['frame'],b['frame'],ax['meshActive'],ay['meshActive']])
        if ax and ay and ax['distance'] is not None and ay['distance'] is not None:
            for threshold in [10,20]:
                if (ax['distance']<=threshold)!=(ay['distance']<=threshold):crossings.append(dict(frame=b['frame'],threshold=threshold,before=ax['distance'],after=ay['distance'],manual_before=ax['manual'],manual_after=ay['manual']))
    return dict(samples=len(samples),frozen_intervals=len(frozen),frozen_with_timeScale_one=isolated,frozen_with_timeScale_zero=ordinary,frozen_violations=violations,
       hidden_samples=sum(s['data'].get('actor') is not None and s['data']['actor']['meshActive']==0 for s in samples),
       visibility_transitions=hidden,distance_crossings=crossings,
       far_manual_samples=sum(s['data'].get('actor') is not None and s['data']['actor']['manual']==1 for s in samples))

def analyze():
    rea=json.loads((HERE/'rea-runtime.json').read_text(encoding='utf8'));records=rea['records']
    loads={r['normalized_result']['script_id']:r for r in records if r['operation']=='load_frida_script'}
    unloads={r['parameters']['script_id'] for r in records if r['operation']=='unload_frida_script' and r['normalized_result']['unloaded']}
    statuses=[r for r in records if r['operation']=='frida_session_status'];messages=[]
    active_scripts={s['script_id'] for r in statuses for s in r['normalized_result']['scripts']}
    # REA unload returns a plain operation result and is not retained in the
    # ledger. The final status independently shows these scripts are absent.
    unloads.update(set(loads)-active_scripts)
    for r in statuses:
        assert not r['normalized_result']['messages_truncated']
        for m in r['normalized_result']['messages']:
            if m['type']=='send':messages.append({**m['payload'],'session':r['parameters']['session_id'],'script':m['script_id']})
    messages.sort(key=lambda m:(m.get('frame',-1),m.get('real',-1)))
    controlled_sessions={r['parameters']['session_id'] for r in loads.values() if Path(r['normalized_result']['source_path']).name.startswith('control')}
    events={};pending=defaultdict(deque);unmatched_callbacks=[]
    for p in messages:
        kind=p.get('kind');d=p.get('data',{});sid=p['session']
        if kind=='scenario_animation':
            key=(sid,p['script'],d['id']);events[key]=dict(event=p,model=None,samples=[],callbacks=[],removed=None);pending[(sid,p['script'],d['receiver'])].append(key)
        elif kind=='scenario_model':events[(sid,p['script'],d['id'])]['model']=p
        elif kind=='scenario_queue_sample':events[(sid,p['script'],d['id'])]['samples'].append(p)
        elif kind=='scenario_queue_removed':events[(sid,p['script'],d['id'])]['removed']=p
        elif kind=='scenario_callback':
            q=pending[(sid,p['script'],d['receiver'])]
            if q:events[q.popleft()]['callbacks'].append(p)
            else:unmatched_callbacks.append(p)
    callback_groups=Counter()
    for (sid,script,eid),e in events.items():
        npc=next((s['data']['actor']['npc'] for s in e['samples'] if s['data'].get('actor')),None)
        for c in e['callbacks']:callback_groups[(sid,c['frame'],npc)]+=1
    summaries=[]
    for (sid,script,eid),e in events.items():
        p=e['event'];callbacks=e['callbacks'];samples=e['samples'];removed=e['removed'];q=summarize_queue(samples)
        npc=next((s['data']['actor']['npc'] for s in samples if s['data'].get('actor')),None)
        listener_rows=[m for m in messages if m['session']==sid and m.get('kind')=='scenario_found_listener']
        callback_rows=[m for m in messages if m['session']==sid and m.get('kind')=='scenario_callback']
        group=None if not callbacks else associate_group(callbacks[0],listener_rows,npc,callback_groups[(sid,callbacks[0]['frame'],npc)],sum(m['frame']==callbacks[0]['frame'] for m in callback_rows))
        summaries.append(dict(session=sid,script=script,id=eid,origin=p['data'].get('origin','native-animation-entry'),authority='controlled-replay' if sid in controlled_sessions else 'natural-observation',
          receiver=p['data']['receiver'],nca=p['data']['nca'],event_frame=p['frame'],callback_frames=[c['frame'] for c in callbacks],
          real_seconds=None if not callbacks else callbacks[0]['real']-p['real'],scaled_seconds=None if not callbacks else callbacks[0]['time']-p['time'],
          last_queue_sample_stop=None if not samples else samples[-1]['data']['stop'],
          callback_sample_lag_frames=None if not callbacks or not samples else callbacks[0]['frame']-samples[-1]['frame'],
          queue_removed=removed is not None,removed_without_callback=bool(removed and not callbacks),listener_count=None if group is None or not group['individually_attributed'] else group['listener_entries'],
          broadcast_group=group,listener_association='14765 receives NpcController directly. Legacy +0x10 payload is ignored; simultaneous callbacks retain group-level attribution.',**q))
    trials=[]
    for p in messages:
        if p.get('kind')!='control_trial_begin':continue
        d=p['data'];sid=p['session'];script=p['script']
        end=next((m for m in messages if m['session']==sid and m['script']==script and m.get('kind')=='control_trial_end' and m['data']['trial']==d['trial']),None)
        stop_frame=end['frame'] if end else float('inf')
        ev=[e for e in summaries if e['session']==sid and e['receiver']==d['receiver'] and p['frame']<=e['event_frame']<=stop_frame]
        # Native callbacks can complete after cleanup/restoration, so associate
        # by the event's start frame rather than the trial's end timestamp.
        version=Path(loads[script]['normalized_result']['source_path']).name
        expected=version in ['control-v3.js','control-v4.js']
        passed=bool(end and end['data']['reason']=='elapsed' and end['data'].get('positionError',1)<0.001 and (not end['data']['meshRestored'] or end['data'].get('meshMatches')) and end['data']['stop']==0 and len(ev)==1 and len(ev[0]['callback_frames'])==1 and ev[0]['broadcast_group'] is not None and ev[0]['broadcast_group']['balanced'] and ev[0]['queue_removed'] and not ev[0]['frozen_violations'])
        contract_passed=passed
        if passed and 'stop' in d['name']:passed=ev[0]['frozen_intervals']>0
        if passed and 'hidden' in d['name']:passed=ev[0]['hidden_samples']>0
        if passed and 'far' in d['name']:passed=bool(ev[0]['distance_crossings'] and ev[0]['far_manual_samples'])
        trials.append(dict(session=sid,script=script,trial=d['trial'],name=d['name'],formal=expected,start_frame=p['frame'],end_frame=None if end is None else end['frame'],
          reason=None if end is None else end['data']['reason'],event_ids=[e['id'] for e in ev],passed=passed,notification_contract_passed=contract_passed,corrective=version=='control-v4.js',
          restored=None if end is None else end['data']))
    natural=[e for e in summaries if e['authority']=='natural-observation'];formal=[t for t in trials if t['formal']]
    diagnostics=[m for r in statuses for m in r['normalized_result']['messages'] if m['type']=='error' and m['script_id'] in unloads]
    active_errors=[m for r in statuses for m in r['normalized_result']['messages'] if m['type']=='error' and m['script_id'] not in unloads]
    transition_counts=Counter();previous={}
    for p in messages:
        if p['session'] in controlled_sessions:continue
        if p.get('kind')=='scenario_actor_retired':previous.pop((p['session'],p['data']['nca']),None)
        if p.get('kind')!='scenario_actor_transition':continue
        d=p['data'];key=(p['session'],d['nca']);old=previous.get(key)
        if old:
            if old['meshActive']!=d['meshActive']:transition_counts['mesh_visibility_changes']+=1
            if old['manual']!=d['manual']:
                transition_counts['manual_mode_changes']+=1
                if old['distance'] is not None and d['distance'] is not None and any((old['distance']<=t)!=(d['distance']<=t) for t in [10,20]):transition_counts['distance_threshold_mode_switches']+=1
        previous[key]=d
    formal_scripts={t['script'] for t in formal}
    formal_errors=[m for m in messages if m['script'] in formal_scripts and m.get('kind') in ['control_error','control_cleanup_error']]
    coverage={name:any(t['passed'] for t in formal if t['name']==name) for name in ['queue_stop','queue_hidden','queue_far_near','queue_hidden_far','queue_hidden_far_stop']}
    return dict(schema_version=1,status='bounded-controlled-coverage-verified' if all(coverage.values()) and not active_errors and not formal_errors else 'partial-coverage',
      natural_event_count=len(natural),natural_callback_count=sum(len(e['callback_frames']) for e in natural),natural_events=natural,
      natural_transition_counts=dict(transition_counts),controlled_events=[e for e in summaries if e not in natural],trials=trials,
      formal_trials=len(formal),passed_formal_trials=sum(t['passed'] for t in formal),notification_contract_passed_trials=sum(t['notification_contract_passed'] for t in formal),scenario_coverage=coverage,
      condition_coverage_failures=[t for t in formal if t['notification_contract_passed'] and not t['passed']],unmatched_callbacks=unmatched_callbacks,
      diagnostic_errors=diagnostics,active_frida_errors=active_errors,
      formal_control_errors=formal_errors,
      scenario_errors=[m for m in messages if m.get('kind') in ['scenario_error','control_error','control_cleanup_error','scenario_trace_limit']],
      producer_guards=[m for m in messages if m.get('kind')=='scenario_producer_guard'],
      limits=['Controlled OnAnimBaretaSound entry is synthetic and does not validate animation-event generation under every condition.',
              'Natural actor visibility/mode transitions alone do not prove an event was pending at that time.',
              'A callback entry and actual FoundStranger listener delivery are recorded separately.'])

if __name__=='__main__':print(json.dumps(analyze(),ensure_ascii=False,indent=2))
