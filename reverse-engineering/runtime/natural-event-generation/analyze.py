"""Conservative event-generation classification, separate from queue delivery."""
from collections import Counter, defaultdict
import json
from pathlib import Path
HERE=Path(__file__).resolve().parent
FOUND={0xfa993e55: .666666687/.833333313,0xda7252cc: .383333325/.566666663,
       0x4393d49c: .666666687/.833333373,0x61df7c95: .666666687/.833333373}
def states(s):
    result=[s['current']]
    if s['transition']:result.append(s['next'])
    return [v for v in result if v['full'] in FOUND]

def classify(begin,samples,events,parameters,end):
    samples=sorted(samples,key=lambda s:(s['frame'],s.get('real',0)))
    footprints=[(s,v) for s in samples for v in states(s)]
    crosses=[]
    # Require a stable current state on both sides. Blending-only crossings
    # remain ambiguous because GetStateInfo does not expose per-clip weights.
    for a,b in zip(samples,samples[1:]):
        x,y=a['current'],b['current'];h=x['full']
        if h in FOUND and y['full']==h and b['frame']==a['frame']+1 and not a['transition'] and not b['transition'] and x['normalized']<FOUND[h]<=y['normalized']:
            crosses.append(dict(before=a['frame'],after=b['frame'],full=h,eligible=all(s['fireEvents'] and s['weight']>0 and s['speed']>0 for s in [a,b])))
    origin=begin['data'].get('origin','native-state-entry')
    complete=end is not None and end['data']['reason']=='completed-observation'
    falls=[p['frame'] for p in parameters if not p['data'].get('value',False)]
    gone=[s for s in samples if falls and s['frame']>min(falls) and not states(s) and not s['transition']]
    below=bool(footprints) and all(v['normalized']<FOUND[v['full']] for s,v in footprints)
    no_gap=all(b['frame']<=a['frame']+1 for a,b in zip(samples,samples[1:]))
    gone_frames=sorted({s['frame'] for s in gone})
    successive_gone=any(b==a+1 for a,b in zip(gone_frames,gone_frames[1:]))
    # This establishes an ordinary transition with no observed event, not the
    # exact sub-frame cancellation point: blending could cross between samples.
    cancelled=(complete and origin in ['original-parameter-write-before-native','native-state-entry','controlled-explicit-parameter-source'] and falls and successive_gone and below and no_gap)
    if events:classification='event-generated' if len(events)==1 else 'multiple-events-review'
    elif cancelled:classification='normal-transition-exit-without-event-observed'
    elif complete and any(c['eligible'] for c in crosses):classification='stable-threshold-crossing-without-event-candidate'
    elif not footprints:classification='no-found-clip-observed'
    else:classification='unresolved-no-event'
    first=events[0]['frame'] if events else float('inf')
    pre=[s for s in samples if s['frame']<first and states(s) and any(v['normalized']<FOUND[v['full']] for v in states(s))]
    changes=[]
    for a,b in zip(samples,samples[1:]):
        if b['frame']>=first or not (states(a) or states(b)):continue
        if a['meshActive']!=b['meshActive']:changes.append(dict(kind='mesh',frame=b['frame'],before=a['meshActive'],after=b['meshActive']))
        if a['distance'] is not None and b['distance'] is not None:
            for threshold in [10,20,40]:
                if (a['distance']<=threshold)!=(b['distance']<=threshold):changes.append(dict(kind='distance',frame=b['frame'],threshold=threshold,before=a['distance'],after=b['distance'],manual_before=a['manual'],manual_after=b['manual']))
        if a['manual']!=b['manual']:changes.append(dict(kind='manual',frame=b['frame'],before=a['manual'],after=b['manual']))
    return dict(classification=classification,origin=origin,complete=complete,samples=len(samples),frame_gaps=not no_gap,
      found_hashes=sorted({v['full'] for s,v in footprints}),stable_crossings=crosses,
      parameter_fall_frames=falls,pre_event_hidden_samples=sum(not s['meshActive'] for s in pre),
      pre_event_changes=changes,pre_event_manual_samples=sum(bool(s['manual']) for s in pre),
      event_frames=[e['frame'] for e in events],last_frame=samples[-1]['frame'] if samples else None)

def analyze():
    rea=json.loads((HERE/'rea-runtime.json').read_text(encoding='utf8'));messages=[]
    statuses=[r for r in rea['records'] if r['operation']=='frida_session_status']
    loads={r['normalized_result']['script_id']:r for r in rea['records'] if r['operation']=='load_frida_script'}
    control_sessions={r['parameters']['session_id'] for r in loads.values() if Path(r['normalized_result']['source_path']).name.startswith('control')}
    for r in statuses:
        assert not r['normalized_result']['messages_truncated']
        for i,m in enumerate(r['normalized_result']['messages']):
            if m['type']=='send':messages.append({**m['payload'],'script':m['script_id'],'session':r['parameters']['session_id'],'order':i})
    cases={};events=[];callbacks=[];listeners=[];errors=[];unmapped=[]
    for p in messages:
        kind=p.get('kind');d=p.get('data',{});key=(p['script'],d.get('id'))
        if kind=='generation_enter':cases[key]=dict(begin=p,samples=[],events=[],parameters=[],end=None,models=[])
        elif kind=='generation_samples':cases[key]['samples']+=d['samples']
        elif kind=='generation_animation':
            events.append(p)
            if key in cases:cases[key]['events'].append(p)
        elif kind=='generation_model':
            if key in cases:cases[key]['models'].append(p)
        elif kind in ['generation_parameter','generation_parameter_fall_fallback']:
            if key in cases:cases[key]['parameters'].append(p)
        elif kind=='generation_end':cases[key]['end']=p
        elif kind=='generation_callback':callbacks.append(p)
        elif kind=='generation_listener':listeners.append(p)
        elif kind=='generation_error':errors.append(p)
        elif kind=='generation_unmapped_parameter':unmapped.append(p)
    results=[]
    for (script,cid),c in cases.items():
        row=classify(c['begin'],c['samples'],c['events'],c['parameters'],c['end'])
        own=[p for p in callbacks if p['script']==script and p['data']['id']==cid]
        npc=next((s['npc'] for s in c['samples']),None)
        groups=[]
        for f in sorted({p['frame'] for p in own}):
            count=sum(p['script']==script and p['frame']==f and p['data']['receiver'] in {q['data']['receiver'] for q in own} for p in callbacks)
            matches=sum(p['script']==script and p['frame']==f and p['data']['npc']==npc for p in listeners)
            groups.append(dict(frame=f,callbacks=count,listeners=matches,balanced=count==matches))
        row.update(id=cid,script=script,nca=c['begin']['data']['nca'],entry_frame=c['begin']['frame'],npc=npc,models=len(c['models']),callbacks=len(own),listener_groups=groups,
                   authority='controlled-session-observation' if c['begin']['session'] in control_sessions else 'natural-input')
        results.append(row)
    formal=[];diagnostics=[]
    for script,load in loads.items():
        source=Path(load['normalized_result']['source_path']).name
        if not source.startswith('control'):continue
        own=[p for p in messages if p['script']==script]
        if source=='control.js':
            diagnostics+=own;continue
        for begin in [p for p in own if p['kind']=='generation_control_begin']:
            tid=begin['data']['trial'];trial=[p for p in own if p.get('data',{}).get('trial')==tid]
            samples=[{**s,'weight':s['weight'] if source=='control-v3.js' else 0,'layer_weight_measured':source=='control-v3.js'} for p in trial if p['kind']=='generation_control_samples' for s in p['data']['samples']]
            ev=[p for p in trial if p['kind']=='generation_control_animation'];cb=[p for p in trial if p['kind']=='generation_control_callback']
            true=next((p for p in trial if p['kind']=='generation_control_parameter_true'),None)
            false=[dict(frame=p['frame'],data={'value':False}) for p in trial if p['kind']=='generation_control_parameter_false']
            end=next((p for p in trial if p['kind']=='generation_control_end'),None)
            cond=next((p for p in trial if p['kind']=='generation_control_condition'),None)
            report=classify({'data':{'origin':'controlled-explicit-parameter-source'}},samples,ev,false,
                {'data':{'reason':'completed-observation'}} if end and end['data']['reason']=='elapsed' else None)
            first=ev[0]['real'] if ev else float('inf')
            pre=[s for s in samples if true and s['frame']>=true['frame'] and s['real']<first]
            post_condition=[s for s in pre if cond and s['frame']>cond['frame']]
            name=begin['data']['name'];condition=True
            if name=='hidden_before_near':condition=any(not s['meshActive'] and s['distance']<=10 for s in post_condition)
            elif name in ['near_far_before','hidden_far_before','early_cancel_hidden_far']:condition=any(s['distance']>50 and (not s['meshActive'] if 'hidden' in name else True) for s in post_condition)
            elif name=='far_near_before':condition=any(s['distance']>50 for s in pre) and any(s['distance']<=10 for s in post_condition)
            else:condition=bool(post_condition)
            expected=0 if name.startswith('early_cancel') else 1
            balanced=len(ev)==expected and len(cb)==expected
            pulse_order=bool(true and cond and cond['real']<first)
            cleanup=end['data'] if end else None
            native=[p for p in events if p['session']==begin['session'] and p['data']['receiver']==begin['data']['receiver'] and begin['frame']<=p['frame']<=(end['frame'] if end else float('inf'))]
            native_models=[p for p in messages if p['kind']=='generation_model' and p['session']==begin['session'] and p['data']['receiver']==begin['data']['receiver'] and begin['frame']<=p['frame']<=(end['frame'] if end else float('inf'))]
            native_at=[dict(frame=p['frame'],**{k:p['data']['at'][k] for k in ['found','current','next','transition','meshActive','manual','npc']}) for p in native if p['data'].get('at')]
            npc=next((p['npc'] for p in native_at),None)
            delivered=sum(p['session']==begin['session'] and p['data']['npc']==npc and p['frame'] in {q['frame'] for q in cb} for p in listeners)
            false_frame=false[0]['frame'] if false else None
            later_true=[s['frame'] for s in samples if false_frame is not None and s['frame']>false_frame and s['found']]
            bounded_end={'data':{'reason':'completed-observation'}}
            bounded=classify({'data':{'origin':'controlled-explicit-parameter-source'}},samples,ev,false,bounded_end)
            formal.append(dict(id=tid,script=script,name=name,authority='controlled parameter/geometry/visibility; real Unity event',
                source_frame=true['frame'] if true else None,condition_frame=cond['frame'] if cond else None,
                planned_event_count=expected,planned_count_matched=balanced,event_frames=[p['frame'] for p in ev],callback_frames=[p['frame'] for p in cb],
                callback_real_seconds=cb[0]['real']-ev[0]['real'] if len(cb)==len(ev)==1 else None,
                native_event_states=native_at,native_models=len(native_models),native_listener_entries=delivered,
                after_false_found_true_frames=later_true,bounded_transition_result=bounded['classification'],
                measured_condition=condition,condition_before_event=pulse_order,count_contract=len(ev)<=1 and len(cb)==len(ev) and len(native_models)==len(ev) and delivered==len(ev),
                complete=bool(end and end['data']['reason']=='elapsed'),cleanup=cleanup,classification=report['classification'],
                found_hashes=report['found_hashes'],pre_event_hidden_samples=sum(not s['meshActive'] for s in pre),
                pre_event_distance_range=[min(s['distance'] for s in pre),max(s['distance'] for s in pre)] if pre else None,
                pre_event_manual_samples=sum(bool(s['manual']) for s in pre),pre_event_changes=report['pre_event_changes'],samples=len(samples)))
    natural=[p for p in results if p['authority']=='natural-input']
    natural_events=[p for p in events if p['session'] not in control_sessions]
    natural_cb=[p for p in callbacks if p['session'] not in control_sessions]
    return dict(schema_version=1,status='controlled-event-generation-verified-natural-coverage-partial',natural_pre_event_coverage_complete=False,authority='natural and controlled sessions explicitly separated',
      counts=dict(Counter(p['classification'] for p in results)),trials=results,total_animation_entries=len(events),total_callbacks=len(callbacks),total_listener_entries=len(listeners),
      natural_counts=dict(Counter(p['classification'] for p in natural)),natural_animation_entries=len(natural_events),natural_callbacks=len(natural_cb),
      controlled_trials=formal,controlled_preflight=diagnostics,
      untracked_animation_entries=sum(p['data']['id'] is None for p in events),errors=errors,unmapped_parameters=len(unmapped),
      native_script_errors=[m for r in statuses for m in r['normalized_result']['messages'] if m['type']=='error'],
      pre_event_hidden_trials=[p['id'] for p in natural if p['pre_event_hidden_samples']],
      pre_event_distance_trials=[p['id'] for p in natural if any(x['kind']=='distance' for x in p['pre_event_changes'])],
      pre_event_manual_trials=[p['id'] for p in natural if p['pre_event_manual_samples']],
      limitations=['Only stable current-state crossings are potential missing-event candidates; blending clip weights are unavailable.',
       'Candidates do not prove actual clip evaluation. Disabled/manual and culling cases require further evaluation-level evidence.',
       'control-v2 hardcodes weight=1 in raw samples; analysis replaces it with unmeasured weight=0, not a measured zero. control-v3 reads the real layer weight.',
       'OnExit/false alone is not cancellation. Source disappearance and below-threshold samples support an ordinary transition without observed event, not its exact sub-frame cancellation point.',
       'First observer missed high-level entry hooks; its untracked events do not establish pre-event coverage.',
       'Natural evidence ends at the last retained running status before detach. Later observer-file lines are contextual only and cannot prove no native events in the unretained tail.',
       'Hidden-before-event, distance crossing, normal cancellation and event production are separate measured coverage axes.'])

if __name__=='__main__':print(json.dumps(analyze(),ensure_ascii=False,indent=2))
