"""Natural cancellation candidates require actual source and lifecycle evidence."""
import gzip,json,runpy
from collections import Counter,defaultdict
from pathlib import Path
HERE=Path(__file__).resolve().parent
core=runpy.run_path(str(HERE.parent/'natural-event-coverage/analyze.py'))
def business_outcome(changes,event_frames):
    exits=[p for p in changes if p['data']['old']==1 and p['data']['next']!=1]
    rows=[]
    for p in exits:
        d=p['data'];timer=d['business']['stateTime'];after_event=any(f<=p['frame'] for f in event_frames)
        if after_event and d['producer']=='found-update' and timer>3:kind='normal-timer-exit-after-event'
        elif not after_event:kind='early-business-exit-candidate-not-clip-cancellation-proof'
        else:kind='other-exit-after-event'
        rows.append(dict(frame=p['frame'],next=d['next'],timer=timer,producer=d['producer'],caller=d['caller'],classification=kind))
    return rows
def lifecycle_outcome(case,samples,scene_changes,transitions):
    end=case.get('end')
    if case['events'] or not end or not end['data']['reason'].startswith('retired:'):return None
    changed=[p for p in scene_changes if case['entry_frame']<=p['frame']<=end['frame']+2 and p['data']['name']!=case['scene']]
    called=[p for p in transitions if case['entry_frame']<=p['frame']<=end['frame']]
    footprints=[v for s in samples for v in core['states'](s)]
    if not changed or not called or not footprints or any(v['normalized']>=core['FOUND'][v['full']] for v in footprints):return None
    return dict(classification='scene-lifecycle-termination-without-event-observed',
      source_scene=case['scene'],scene_changes=changed,transition_entries=called,retirement_frame=end['frame'],
      last_found_state=footprints[-1],event_threshold=core['FOUND'][footprints[-1]['full']],
      limitation='Below-marker samples and retirement bound this lifecycle end; exact sub-frame clip cancellation internals remain unobserved.')
def analyze():
    # Reuse the pinned conservative clip classifier, without changing old sources.
    core['analyze'].__globals__['HERE']=HERE
    result=core['analyze']()
    raw=json.loads((HERE/'rea-runtime.json').read_text(encoding='utf8'))
    retained,joins=core['merge_statuses'](raw['records'])
    messages=[dict(m['payload'],script=m['script_id']) for m in retained if m['type']=='send']
    changes=[p for p in messages if p['kind']=='coverage_business_change']
    motion=[s for p in messages if p['kind']=='player_motion_samples' for s in p['data']['samples']]
    with gzip.open(HERE/'natural-window.jsonl.gz','rt',encoding='utf8') as f:scene_changes=[p for line in f if (p:=json.loads(line))['kind']=='scene']
    transitions=[p for p in messages if p['kind']=='guard_transition_entry']
    reentries=defaultdict(list)
    for c in result['cases']:
        key=(c['script'],c['id'])
        own=[p for p in changes if (p['script'],p['data']['id'])==key]
        samples=[s for p in messages if p['kind']=='coverage_samples' and (p['script'],p['data']['id'])==key for s in p['data']['samples']]
        first=next((s for s in samples if s.get('business')),None)
        if first:reentries[(first['npc'],first['business']['foundState'])].append(dict(script=c['script'],id=c['id']))
        c['business_exits']=business_outcome(own,c['event_frames'])
        entries=[p for p in own if p['data']['next']==1 and p['data']['old']!=1]
        c['entry_timers']=[p['data']['business']['stateTime'] for p in entries]
        c['state_backrefs_valid']=bool(samples) and all(s['business']['stateBackrefsValid'] for s in samples)
        event=c['event_frames'][0] if c['event_frames'] else (c['end']['frame'] if c['end'] else float('inf'))
        pre=[s for s in samples if s['frame']<event and core['states'](s)]
        c['pre_event_noise_positive_samples']=sum(s['business']['noiseAdded']>0 for s in pre)
        c['pre_event_player_not_found_samples']=sum(not s['business']['playerFound'] for s in pre)
        eligible=[s for s in motion if c['entry_frame']<=s['frame']<event]
        c['pre_event_motion_samples']=len(eligible)
        c['pre_event_resolved_move_samples']=sum(any(abs(v)>.0001 for v in s['inputMove']) for s in eligible)
        c['pre_event_can_move_samples']=sum(s['state']==0 and s['canMove']==1 and not s['ecstasy'] for s in eligible)
        c['natural_lifecycle_termination']=lifecycle_outcome(c,samples,scene_changes,transitions)
    call_rows=[]
    for begin in [p for p in messages if p['kind']=='guard_call_begin']:
        own=[p for p in messages if p['script']==begin['script'] and p['data'].get('call')==begin['data']['id']]
        end=next((p for p in messages if p['script']==begin['script'] and p['kind']=='guard_call_end' and p['data']['id']==begin['data']['id']),None)
        call_rows.append(dict(id=begin['data']['id'],script=begin['script'],frame=begin['frame'],name=begin['data']['name'],stop=begin['data']['stop'],skill17_level=begin['data']['skill17Level'],
            stop_compares=[p['data']['flag'] for p in own if p['kind']=='guard_stop_compare'],
            stop_reject_branch=[p for p in own if p['kind']=='guard_stop_reject_branch'],
            messages=[p['data']['text'] for p in own if p['kind']=='guard_message'],
            keys=[p['data']['key'] for p in own if p['kind']=='guard_localizer_key'],
            complete=bool(end),transition_entries=end['data']['transitions'] if end else None))
    all_sources={r['normalized_result']['script_id'] for r in raw['records'] if r['operation']=='load_frida_script'}
    ended={p['script'] for p in messages if p['kind'] in ['coverage_finished','evaluation_finished','inventory_finished','guard_decode_finished','guards_finished']}
    result.update(status='natural-cancellation-search-bounded',authority='original complete game with original input; passive hooks and getters; no controlled gameplay changes',
      business_exit_counts=dict(Counter(e['classification'] for c in result['cases'] for e in c['business_exits'])),
      repeated_same_found_objects=[dict(npc=k[0],found_state=k[1],cases=v) for k,v in reentries.items() if len(v)>1],
      guard_calls=call_rows,guard_errors=[p for p in messages if p['kind'] in ['guard_probe_error','guard_decode_error']],
      natural_lifecycle_terminated_cases=[c['id'] for c in result['cases'] if c['natural_lifecycle_termination']],
      stop_guard_actual_rejections=sum(bool(c['stop_reject_branch']) for c in call_rows),
      eligibility_inventories=[p for p in messages if p['kind']=='eligibility_inventory'],
      all_sources_finished=all_sources<=ended,unfinished_sources=sorted(all_sources-ended),
      additional_finish_markers=[p for p in messages if p['kind'] in ['inventory_finished','guard_decode_finished','guards_finished']])
    result['limits'] += ['Parsed Move is not an independent physical keyboard capture; zero parsed input cannot establish no key was pressed.',
      'A true CanMove field is only one motion guard; dash additionally requires action None. Collision and upstream input gates are separate.',
      'Entry timer zero and no repeated same object only bound the observed population; they do not prove natural reentry impossible.',
      'Noise branch reachability and a state change do not establish an actual event-before-marker cancellation without observed clip exit.']
    return result
if __name__=='__main__':print(json.dumps(analyze(),ensure_ascii=False,indent=2))
