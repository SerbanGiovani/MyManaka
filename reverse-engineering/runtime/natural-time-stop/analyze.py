"""Correlate original producer, exact receiver fields, animation and delayed models."""
from collections import Counter, defaultdict, deque
import gzip
import hashlib
import json
from pathlib import Path

HERE=Path(__file__).resolve().parent
def close(a,b):return abs(a-b)<=max(1e-6,abs(b)*1e-6)

def pair_cases(cases,captures):
    pairs=[]
    for a,b in zip(cases,cases[1:]):
        if not(a['session']==b['session'] and a['before']==0 and a['after']==1 and b['before']==1 and b['after']==0):continue
        stop=[v for v in captures if v['session']==a['session'] and v['producer_id']==a['id']]
        resume=[v for v in captures if v['session']==b['session'] and v['producer_id']==b['id']]
        sm={v['before']['npc']:v for v in stop};rm={v['before']['npc']:v for v in resume}
        violations=[];unverified=[]
        for npc in sorted(sm.keys()&rm.keys()):
            s,r=sm[npc],rm[npc];original=s['before']['speed']
            if s['correct'] is None or r['correct'] is None or r['after'] is None:
                unverified.append(npc);continue
            if not(s['correct'] is True and r['correct'] is True and close(r['before']['cache'],original) and close(r['after']['speed'],original)):
                violations.append({'npc':npc,'original_speed':original,'resume_cache':r['before']['cache'],'resume_speed':r['after']['speed']})
        complete=bool(sm and sm.keys()==rm.keys() and len(sm)==len(stop)==a['receiver_count'] and
                      len(rm)==len(resume)==b['receiver_count'] and not violations and not unverified and not a['duplicates'] and not b['duplicates'])
        pairs.append({'session':a['session'],'stop_id':a['id'],'resume_id':b['id'],'stop_frame':a['frame'],'resume_frame':b['frame'],
          'seconds':b['real']-a['real'],'stop_receivers':a['receiver_count'],'resume_receivers':b['receiver_count'],
          'closed_npcs':sorted(sm.keys()&rm.keys()),'stop_without_resume':sorted(sm.keys()-rm.keys()),
          'resume_without_stop':sorted(rm.keys()-sm.keys()),'cross_stop_restore_violations':violations,'unverified_npcs':unverified,'passed':complete})
    return pairs

def sample_receivers(cases,entries,snapshots):
    """First subsequent same-flag snapshot, strictly before another producer.

    A sampled result never becomes an exact callback/producer-return result.
    Missing NPCs and missing snapshots remain explicit unknowns.
    """
    result=[]
    for entry in entries:
        case=next(c for c in cases if c['session']==entry['session'] and c['id']==entry['producer_id'])
        later=[c['frame'] for c in cases if c['frame']>case['frame']]
        end=min(later) if later else float('inf')
        snapshot=next((s for s in snapshots if case['frame']<s['frame']<end and int(s['data']['stop'])==case['after']),None)
        before=entry['before'];after=None
        if snapshot:
            found=[n for n in snapshot['data']['npc'] if n['ptr'] is not None and int(n['ptr'])==int(before['npc'],16)]
            if len(found)==1:
                after={'npc':before['npc'],'cache':float(found[0]['cache']),'speed':found[0]['speed']}
        ok=None
        if after and after['speed'] is not None:
            ok=(close(after['cache'],before['speed']) and close(after['speed'],0)) if case['after']==1 else (close(after['cache'],before['cache']) and close(after['speed'],before['cache']))
        result.append({**entry,'after':after,'correct':ok,'sample_frame':None if snapshot is None else snapshot['frame'],
                       'sample_lag_frames':None if snapshot is None else snapshot['frame']-case['frame'],'observation':'periodic-snapshot'})
    return result

def analyze():
    rows=[json.loads(l) for l in gzip.decompress((HERE/'natural.jsonl.gz').read_bytes()).decode('utf-8-sig').splitlines()]
    starts=[i for i,r in enumerate(rows) if r['kind']=='loaded']
    current=rows[starts[-1]:];snapshots=[r for r in current if r['kind']=='snapshot']
    rea=json.loads((HERE/'rea-runtime.json').read_text(encoding='utf8'))
    status=[r for r in rea['records'] if r['operation']=='frida_session_status']
    assert all(not r['normalized_result']['messages_truncated'] for r in status)
    statuses=[r for r in status if r['normalized_result']['pid']==45864]
    messages=[]
    for r in statuses:
        for m in r['normalized_result']['messages']:
            if m['type']=='send':messages.append({**m['payload'],'session':r['parameters']['session_id'],'script':m['script_id']})
    messages.sort(key=lambda p:(p.get('frame',-1),p.get('real',-1)))
    counts=Counter(p.get('kind','unlabelled') for p in messages)
    loads=[r['normalized_result'] for r in rea['records'] if r['operation']=='load_frida_script']
    diagnostic_ids={r['script_id'] for r in loads if Path(r['source_path']).name=='input-state.js'}
    formal=[p for p in messages if p['script'] in diagnostic_ids]
    state=[p for p in formal if p.get('kind')=='keyboard_action_state']
    assert state and all(r['data']['focus'] in (0,1) for r in state)
    errors=[m for r in statuses for m in r['normalized_result']['messages'] if m['type']=='error']
    producers={};deliveries={};pairs=[]
    for p in messages:
        d=p.get('data',{});kind=p.get('kind')
        if kind=='producer_enter':producers[(p['session'],d['id'])]={'enter':p,'receivers':[]}
        elif kind=='producer_leave':producers[(p['session'],d['id'])]['leave']=p
        elif kind=='npc_stop_enter':
            owner=producers.get((p['session'],d['producer']))
            if owner is not None:owner['receivers'].append(p)
        elif kind=='npc_delivery_before':deliveries[(p['session'],d['id'])]={'before':p}
        elif kind=='npc_delivery_after':deliveries[(p['session'],d['id'])]['after']=p
    cases=[]
    for owner in producers.values():
        a,b=owner['enter'],owner.get('leave');assert b is not None
        receiver_counts=Counter(r['data']['npc'] for r in owner['receivers'])
        cases.append({'session':a['session'],'id':a['data']['id'],'frame':a['frame'],'time':a['time'],'real':a['real'],
          'before':a['data']['stop'],'after':b['data']['stop'],'receiver_count':sum(receiver_counts.values()),
          'unique_npcs':len(receiver_counts),'duplicates':{n:c for n,c in receiver_counts.items() if c>1}})
    cases.sort(key=lambda c:c['frame'])
    captures=[];incomplete=[];entries=[]
    for d in deliveries.values():
        a,b=d['before'],d.get('after')
        owners=[c for c in cases if c['session']==a['session'] and c['frame']==a['frame'] and
                any(v['data']['npc']==a['data']['npc'] for v in producers[(c['session'],c['id'])]['receivers'])]
        owner=owners[0] if len(owners)==1 else None
        before=a['data'];direction=None if owner is None else owner['after']
        entry={'session':a['session'],'producer_id':None if owner is None else owner['id'],'frame':a['frame'],'direction':direction,'before':before}
        if owner is not None:entries.append(entry)
        if b is None:
            incomplete.append(entry);continue
        after=b['data']
        if direction==1:ok=close(after['cache'],before['speed']) and close(after['speed'],0)
        elif direction==0:ok=close(after['cache'],before['cache']) and close(after['speed'],before['cache'])
        else:ok=None
        captures.append({**entry,'after':after,'correct':ok,'observation':'npc-callback-exit'})
    post=[]
    for p in messages:
        if p.get('kind')!='npc_post_broadcast':continue
        d=p['data'];owners=[c for c in cases if c['session']==p['session'] and c['frame']==p['frame'] and c['before']==d['before'] and c['after']==d['after']]
        assert len(owners)==1
        for row in d['rows']:
            before,after=row.get('before'),row.get('after');ok=None
            if before and after:
                ok=(close(after['cache'],before['speed']) and close(after['speed'],0)) if d['after']==1 else (close(after['cache'],before['cache']) and close(after['speed'],before['cache']))
            post.append({'session':p['session'],'producer_id':owners[0]['id'],'frame':p['frame'],'direction':d['after'],
                         'before':before,'after':after,'correct':ok,'observation':'outer-producer-return','error':row.get('error')})
    reliable=captures+post
    pairs=pair_cases(cases,reliable)
    sampled=sample_receivers(cases,entries,snapshots)
    sampled_pairs=pair_cases(cases,sampled)
    best={(c['session'],c['producer_id'],c['before']['npc']):c for c in sampled}
    best.update({(c['session'],c['producer_id'],c['before']['npc']):c for c in reliable if c['before'] is not None})
    combined=list(best.values());combined_pairs=pair_cases(cases,combined)
    covered={(p['session'],i) for p in pairs for i in (p['stop_id'],p['resume_id'])}
    unpaired=[c for c in cases if (c['session'],c['id']) not in covered]
    pending=defaultdict(deque);notifications=[]
    for p in messages:
        kind=p.get('kind');d=p.get('data',{})
        if kind=='animation_event_native':pending[(p['session'],d['receiver'])].append(p)
        if kind=='delayed_callback_native':
            q=pending[(p['session'],d['receiver'])]
            if q:
                a=q.popleft();notifications.append({'receiver':d['receiver'],'event_frame':a['frame'],'callback_frame':p['frame'],
                  'frames':p['frame']-a['frame'],'scaled_seconds':p['time']-a['time'],'real_seconds':p['real']-a['real']})
    ticks=[p for p in messages if p.get('kind')=='npc_delay_tick']
    frozen=[p for p in ticks if p['data']['stop']==1 and p['data']['before']>0]
    frozen_violations=[p for p in frozen if not close(p['data']['before'],p['data']['after'])]
    unexpected=[p for p in messages if p.get('kind')=='unexpected_es3_path']
    nonflipping=[c for c in cases if c['before']==c['after'] and c['receiver_count']]
    bounded_complete=bool(combined_pairs and all(p['passed'] for p in combined_pairs) and all(c['correct'] is True for c in combined) and
                  not unpaired and not any(c['duplicates'] for c in cases) and not nonflipping and not errors and not frozen_violations and not unexpected)
    # Core cycles and the user's timing/visibility questions have separate scope.
    coverage={'natural_shortcut_stop_restore':bounded_complete,
              'near_and_far_receiver_samples':bool(any(c['before']['distance']<=20 for c in entries) and any(c['before']['distance']>20 for c in entries)),
              'positive_queue_remaining_while_stopped':bool(frozen),
              'mesh_visibility_transition':None,'distance_threshold_transition':None}
    complete=all(v is True for v in coverage.values())
    actions=[p for p in messages if p.get('kind')=='change_action_time_stop']
    action_links=[]
    for c in cases:
        previous=[p for p in actions if p['session']==c['session'] and p['frame']<=c['frame']]
        if previous:
            a=previous[-1];action_links.append({'session':c['session'],'producer_id':c['id'],'action_frame':a['frame'],'producer_frame':c['frame'],
               'frames':c['frame']-a['frame'],'scaled_seconds':c['time']-a['time']})
    return {'status':'observed-natural-stop-restore' if complete else ('observed-natural-cycles-timing-partial' if cases else 'awaiting-natural-stop-restore'),
      'natural_validation_complete':complete,'scope':'Bounded recorded sessions; not all possible timing/visibility combinations',
      'bounded_stop_restore_complete':bounded_complete,'combined_stop_restore_pairs':combined_pairs,
      'scenario_coverage':coverage,
      'coverage_limits':['NPC callback onLeave was not delivered; absent exits remain unknown. Producer-return and periodic-snapshot measurements are labelled separately.',
                        'display=false is only a controller flag, not proof of hidden MeshParent. Near/far samples do not prove a distance boundary transition.',
                        'Queue freeze requires positive remaining time while stopped; ordinary post-resume callbacks do not exercise it.'],
      'startup_segments':len(starts),'scenes':sorted({r['data']['scene'] for r in snapshots}),
      'snapshot_count':len(snapshots),'last_snapshot_summary':{k:v for k,v in snapshots[-1]['data'].items() if k!='npc'},
      'formal_keyboard_states':state,'formal_bool8_true_count':sum(p.get('kind')=='input_true_bool8' for p in formal),
      'historical_invalid_bool32_records_excluded':counts['input_positive'],'producer_cases':cases,'stop_restore_pairs':pairs,'unpaired_producer_cases':unpaired,
      'input_time_stop_count':counts['input_time_stop'],'action7_count':len(actions),'action_to_producer':action_links,
      'npc_receiver_count':counts['npc_stop_enter'],'exact_npc_captures':captures,'incomplete_delivery_captures':incomplete,
      'post_broadcast_captures':post,'post_broadcast_passed_pair_count':sum(p['passed'] for p in pairs),
      'sampled_receiver_captures':sampled,'sampled_stop_restore_pairs':sampled_pairs,
      'cache_violations':[c for c in reliable if c['correct'] is False],
      'sampled_cache_violations':[c for c in sampled if c['correct'] is False],
      'distance_visibility_coverage':dict(Counter(('near' if c['before']['distance']<=20 else 'far')+('/displayed' if c['before']['display'] else '/hidden_by_controller') for c in entries)),
      'animation_event_count':counts['animation_event_native'],'callback_count':counts['delayed_callback_native'],
      'notification_pairs':notifications,'unmatched_animation_events':sum(len(q) for q in pending.values()),
      'delay_models':[p for p in messages if p.get('kind')=='npc_delay_model'],'delay_ticks':ticks,
      'positive_remaining_ticks_while_stopped':len(frozen),'frozen_countdown_violations':[p for p in frozen if not close(p['data']['before'],p['data']['after'])],
      'delay_pause_window_exercised':bool(frozen),'nonflipping_broadcasts':nonflipping,
      'ring_open_count':counts['ring_open'],'runtime_states':[p for p in messages if p.get('kind')=='runtime_state'],
      'unexpected_es3_paths':unexpected,'frida_errors':errors,
      'log_sha256':hashlib.sha256((HERE/'natural.jsonl.gz').read_bytes()).hexdigest()}

if __name__=='__main__':print(json.dumps(analyze(),ensure_ascii=False,indent=2))
