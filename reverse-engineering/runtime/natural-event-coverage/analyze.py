"""Natural-only event coverage; pauses and lifecycle loss are not missing events."""
from collections import Counter,defaultdict
import gzip,json,runpy,hashlib
from pathlib import Path
HERE=Path(__file__).resolve().parent
PREVIOUS=HERE.parent/'natural-event-generation'
shared=runpy.run_path(str(PREVIOUS/'analyze.py'))
FOUND=shared['FOUND'];states=shared['states'];classify=shared['classify']
TRUSTED={'original-business-change-before-call','original-animation-manager-before-call','original-parameter-before-native'}
def message_key(m):return hashlib.sha256(json.dumps(m,sort_keys=True,ensure_ascii=False).encode()).digest()
def merge_statuses(records):
    """Keep original bounded records; reconstruct only a matching suffix/prefix."""
    captures=[r for r in records if r['operation']=='frida_session_status']
    captures.sort(key=lambda r:max(m.get('payload',{}).get('frame',-1) for m in r['normalized_result']['messages']))
    assert captures and not captures[0]['normalized_result']['messages_truncated']
    merged=list(captures[0]['normalized_result']['messages']);joins=[]
    for r in captures[1:]:
        incoming=r['normalized_result']['messages'];pattern=[message_key(m) for m in incoming]
        # KMP finds the incoming prefix matching the full retained suffix.
        table=[0]*len(pattern)
        for i in range(1,len(pattern)):
            k=table[i-1]
            while k and pattern[i]!=pattern[k]:k=table[k-1]
            if pattern[i]==pattern[k]:k+=1
            table[i]=k
        k=0
        for key in map(message_key,merged):
            while k and (k==len(pattern) or key!=pattern[k]):k=table[k-1]
            if key==pattern[k]:k+=1
        assert k>=32,'Bounded capture has no verified 32-message overlap'
        joins.append(dict(evidence_id=r['evidence_id'],overlapping_messages=k,added_messages=len(incoming)-k,truncated_original=r['normalized_result']['messages_truncated']))
        merged+=incoming[k:]
    return merged,joins
def before(sample,event):
    return event is None or sample['frame']<event['frame'] or (sample['frame']==event['frame'] and sample.get('real',0)<event.get('real',0))
def below(s):return any(v['normalized']<FOUND[v['full']] for v in states(s))
def summarize_samples(samples,event):
    samples=sorted(samples,key=lambda x:(x['frame'],x.get('real',0)))
    pre=[s for s in samples if before(s,event) and states(s) and below(s)]
    changes=[];manual_changes=[]
    for a,b in zip(pre,pre[1:]):
        if b['frame']>a['frame']+1:continue
        if a['manual']!=b['manual']:
            manual_changes.append(dict(frame=b['frame'],before=a['manual'],after=b['manual'],distance=b['distance'],stop=b['stop']))
        for threshold in [10,20,40]:
            if (a['distance']<=threshold)!=(b['distance']<=threshold):
                changes.append(dict(frame=b['frame'],threshold=threshold,direction='near-to-far' if b['distance']>a['distance'] else 'far-to-near',before=a['distance'],after=b['distance'],manual_before=a['manual'],manual_after=b['manual'],stop_before=a['stop'],stop_after=b['stop']))
    return dict(pre_event_samples=len(pre),pre_event_hidden_samples=sum(not s['meshActive'] for s in pre),
      pre_event_distance_crossings=changes,pre_event_manual_modes=sorted({int(s['manual']) for s in pre}),pre_event_manual_changes=manual_changes,
      skill_stop_samples=sum(s['stop']==1 and s['speed']==0 and s['timeScale']==1 for s in pre),
      ordinary_pause_samples=sum(s['timeScale']==0 for s in pre),
      pre_event_distance_range=[min(s['distance'] for s in pre),max(s['distance'] for s in pre)] if pre else None)
def evaluation_result(start,end,inside):
    pre=start['data']['pre'];valid=bool(end and end['data']['events']==len(inside))
    candidates=[pre['current']]+([pre['next']] if pre['transition'] else [])
    started_below=any(s['full'] in FOUND and s['normalized']<FOUND[s['full']] for s in candidates)
    return dict(id=start['data']['id'],script=start.get('script'),receiver=start['data']['receiver'],nca=start['data']['nca'],frame=start['frame'],
      paired=valid,events_inside=len(inside),delta=start['data']['delta'],pre=pre,
      post=end['data']['post'] if end and 'post' in end['data'] else None,
      hidden_before_actual_update=bool(valid and inside and not pre['meshActive'] and started_below),
      event_generation_proven_inside_call=bool(valid and inside))

def frozen_signature(s):
    if s['stop']!=1 or s['speed']!=0 or not below(s):return None
    return (s['current']['full'],s['current']['normalized'],bool(s['transition']),
            s['next']['full'],s['next']['normalized'])

def continuation_link(a,b,evaluations,parameters):
    """Join only frozen observer handoffs, never a fresh business entry."""
    if not a['samples'] or not b['samples'] or not a['end']:return None
    if a['end']['data']['reason'] not in ['observation-limit','operator-ended']:return None
    if b['begin']['data']['origin'] in TRUSTED:return None
    if a['begin']['data']['nca']!=b['begin']['data']['nca']:return None
    aa=sorted(a['samples'],key=lambda s:s['frame']);bb=sorted(b['samples'],key=lambda s:s['frame'])
    x,y=aa[-1],bb[0];identity=['npc','receiver','animator','mesh']
    if any(x[k]!=y[k] for k in identity):return None
    signature=frozen_signature(x)
    if signature is None or frozen_signature(y)!=signature:return None
    lo,hi=sorted([x['frame'],y['frame']])
    if any(lo<=p['frame']<=hi and not p['data'].get('value',False) for p in parameters):return None
    overlap=sorted(set(s['frame'] for s in aa)&set(s['frame'] for s in bb))
    if overlap:
        shared=[s for s in aa+bb if s['frame'] in overlap]
        if not all(frozen_signature(s)==signature and all(s[k]==x[k] for k in identity) for s in shared):return None
        return dict(method='matching-frozen-overlap',overlap_frames=overlap,gap_frames=[])
    gap=list(range(x['frame']+1,y['frame']))
    if len(gap)>30:return None
    bridge=[v for v in evaluations if v['nca']==a['begin']['data']['nca'] and v['receiver']==x['receiver'] and v['frame'] in gap]
    covered={v['frame'] for v in bridge if v['paired'] and not v['events_inside'] and v['post'] and frozen_signature(v['pre'])==signature and frozen_signature(v['post'])==signature}
    if set(gap)!=covered or any(not v['paired'] or v['events_inside'] or not v['post'] or frozen_signature(v['pre'])!=signature or frozen_signature(v['post'])!=signature for v in bridge):return None
    return dict(method='matching-frozen-evaluations-cover-gap',overlap_frames=[],gap_frames=gap,
                evaluation_scopes=[dict(script=v['script'],id=v['id']) for v in bridge])

def analyze():
    raw=json.loads((HERE/'rea-runtime.json').read_text(encoding='utf8'));records=raw['records']
    loads=[r for r in records if r['operation']=='load_frida_script']
    assert all('control' not in Path(r['normalized_result']['source_path']).name for r in loads)
    messages=[];native_errors=[]
    retained,capture_joins=merge_statuses(records)
    for order,m in enumerate(retained):
        if m['type']=='send':messages.append({**m['payload'],'script':m['script_id'],'order':order})
        elif m['type']=='error':native_errors.append(m)
    cases={};events=[];models=[];callbacks=[];listeners=[];parameters=defaultdict(list)
    evals={};finished=[]
    for p in messages:
        d=p.get('data',{});kind=p['kind'];key=(p['script'],d.get('id'))
        if kind=='coverage_enter':cases[key]=dict(begin=p,samples=[],events=[],end=None)
        elif kind=='coverage_samples':cases[key]['samples']+=d['samples']
        elif kind=='coverage_end':cases[key]['end']=p
        elif kind in ['coverage_parameter','coverage_parameter_fall_readback']:
            parameters[key].append(p)
        elif kind=='coverage_animation':
            events.append(p)
            if key in cases:cases[key]['events'].append(p)
        elif kind=='coverage_model':models.append(p)
        elif kind=='coverage_callback':callbacks.append(p)
        elif kind=='coverage_listener':listeners.append(p)
        elif kind=='evaluation_before':evals[key]=dict(start=p,end=None,inside=[])
        elif kind=='evaluation_after':evals[key]['end']=p
        elif kind=='evaluation_animation_inside':evals[key]['inside'].append(p)
        elif kind in ['coverage_finished','evaluation_finished']:finished.append(p)
    evaluation_rows=[evaluation_result(**v) for v in evals.values()]
    event_rows=[]
    for e in events:
        d=e['data'];own_models=[m for m in models if m['script']==e['script'] and m['data']['event']==d['event']]
        own_cb=[c for c in callbacks if c['script']==e['script'] and c['data']['event']==d['event']]
        npc=d.get('at',{}).get('npc') if d.get('at') else None
        groups=[]
        for f in sorted({c['frame'] for c in own_cb}):
            same=[c for c in callbacks if c['script']==e['script'] and c['frame']==f and c['data']['receiver']==d['receiver']]
            heard=[l for l in listeners if l['script']==e['script'] and l['frame']==f and l['data']['npc']==npc]
            groups.append(dict(frame=f,callbacks=len(same),listeners=len(heard),balanced=len(same)==len(heard)))
        event_rows.append(dict(id=d['event'],case=d['id'],script=e['script'],frame=e['frame'],real=e['real'],receiver=d['receiver'],npc=npc,
          at=d.get('at'),models=len(own_models),callbacks=len(own_cb),groups=groups,
          callback_frames=[c['frame'] for c in own_cb],callback_real=[c['real'] for c in own_cb],
          callback_delay_real=own_cb[0]['real']-e['real'] if len(own_cb)==1 else None,
          delivery_balanced=len(own_models)==len(own_cb)==1 and bool(groups) and all(g['balanced'] for g in groups)))
    case_rows=[]
    for key,c in cases.items():
        origin=c['begin']['data']['origin'];params=parameters[key]
        remapped=[{**p,'data':{**p['data'],'value':p['data'].get('value',False)}} for p in params]
        legacy_begin={'data':{'origin':'original-parameter-write-before-native' if origin in TRUSTED else 'getter-rise-fallback'}}
        row=classify(legacy_begin,c['samples'],c['events'],remapped,c['end'])
        row.update(summarize_samples(c['samples'],c['events'][0] if c['events'] else None))
        own_event_rows=[e for e in event_rows if e['script']==key[0] and e['case']==key[1]]
        own_evals=[v for v in evaluation_rows if v['nca']==c['begin']['data']['nca'] and c['begin']['frame']<=v['frame']<=(c['end']['frame'] if c['end'] else float('inf'))]
        hidden_scopes=[dict(script=v['script'],id=v['id']) for v in own_evals if v['hidden_before_actual_update']]
        row.update(id=key[1],script=key[0],origin=origin,entry_frame=c['begin']['frame'],entry_real=c['begin']['real'],
          end=c['end'],nca=c['begin']['data']['nca'],events=own_event_rows,evaluation_scopes=[dict(script=v['script'],id=v['id']) for v in own_evals],
          hidden_update_scopes=hidden_scopes,hidden_before_event=bool(row['pre_event_hidden_samples'] or hidden_scopes),
          pause_assisted=bool(row['skill_stop_samples']),delivery_balanced=bool(own_event_rows) and all(e['delivery_balanced'] for e in own_event_rows),
          initial_blind_spot=origin not in TRUSTED)
        case_rows.append(row)
    with gzip.open(HERE/'natural-window.jsonl.gz','rt',encoding='utf8') as f:context=[json.loads(x) for x in f]
    scene_changes=[x for x in context if x.get('kind')=='scene'];snapshots=[x for x in context if x.get('kind')=='snapshot']
    for c in case_rows:
        prior=[x for x in scene_changes if x['frame']<=c['entry_frame']]
        scene=prior[-1]['data']['name'] if prior else next((x['data']['scene'] for x in snapshots if x['frame']>=c['entry_frame']),None)
        c['scene']=scene;c['near_threshold']=10 if scene=='Mall' else (20 if scene else None)
        c['natural_near_far_crossings']=[x for x in c['pre_event_distance_crossings'] if x['threshold']==c['near_threshold']]
        # Both actual native modes must be observed before the event. Geometry
        # alone does not prove the FPS controller admitted that switch.
        c['near_far_before_event']=bool(c['natural_near_far_crossings'] and c['pre_event_manual_modes']==[0,1])
        end=c.get('end');c['lifecycle_retired']=bool(end and end['data']['reason'].startswith(('retired:','model-replaced')))
    # Capture limits are observer boundaries. Retain fragments, then separately
    # reconstruct only continuity backed by frozen overlap or paired evaluations.
    ordered=sorted(cases,key=lambda k:cases[k]['begin']['frame']);chains=[];links=[]
    for key in ordered:
        attached=False
        for chain in reversed(chains):
            last=chain[-1];nca=cases[last]['begin']['data']['nca']
            link=continuation_link(cases[last],cases[key],evaluation_rows,[p for k,ps in parameters.items() if cases[k]['begin']['data']['nca']==nca for p in ps])
            if link:
                links.append(dict(before=dict(script=last[0],id=last[1]),after=dict(script=key[0],id=key[1]),**link));chain.append(key);attached=True;break
        if not attached:chains.append([key])
    by_key={(c['script'],c['id']):c for c in case_rows};lineages=[]
    for number,chain in enumerate(chains,1):
        samples={}
        for key in chain:
            for s in cases[key]['samples']:samples[s['frame']]=s
        own_events=[e for key in chain for e in cases[key]['events']]
        summary=summarize_samples(list(samples.values()),own_events[0] if own_events else None)
        rows=[by_key[k] for k in chain];threshold=rows[0]['near_threshold']
        crossings=[x for x in summary['pre_event_distance_crossings'] if x['threshold']==threshold]
        admitted=[]
        for ci,crossing in enumerate(crossings):
            target=1 if crossing['direction']=='near-to-far' else 0
            bound=crossings[ci+1]['frame'] if ci+1<len(crossings) else float('inf')
            if any(crossing['frame']<=v['frame']<bound and v['after']==target and ((v['distance']>threshold) if target else (v['distance']<=threshold)) for v in summary['pre_event_manual_changes']):admitted.append(crossing['direction'])
        lineages.append(dict(id=number,fragments=[dict(script=k[0],id=k[1]) for k in chain],
          source_origin=rows[0]['origin'],trusted_entry=rows[0]['origin'] in TRUSTED,
          entry_frame=rows[0]['entry_frame'],end_frame=rows[-1]['end']['frame'] if rows[-1]['end'] else None,
          nca=rows[0]['nca'],scene=rows[0]['scene'],events=len(own_events),
          delivery_balanced=bool(own_events) and all(e['delivery_balanced'] for row in rows for e in row['events']),
          hidden_before_event=any(r['hidden_before_event'] for r in rows),
          near_far_before_event=bool(admitted),
          directions=sorted(set(admitted)),geometry_directions=sorted({x['direction'] for x in crossings}),**summary))
    hidden=[c['id'] for c in lineages if c['hidden_before_event'] and c['delivery_balanced'] and c['trusted_entry']]
    switching=[c['id'] for c in lineages if c['near_far_before_event'] and c['delivery_balanced'] and c['trusted_entry']]
    reverse_switching=[c['id'] for c in lineages if c['id'] in switching and 'far-to-near' in c['directions']]
    sources={r['normalized_result']['script_id']:Path(r['normalized_result']['source_path']).name for r in loads}
    done={p['script'] for p in finished}
    return dict(schema_version=1,status='natural-coverage-observed' if hidden and switching else 'natural-coverage-partial',
      authority='passive original game, original player input and original time-stop skill; no controlled scripts',
      natural_hidden_before_event_complete=bool(hidden),natural_near_far_before_event_complete=bool(switching),
      natural_far_near_before_event_complete=bool(reverse_switching),
      hidden_before_event_lineages=hidden,near_far_before_event_lineages=switching,far_near_before_event_lineages=reverse_switching,
      cases=case_rows,lineages=lineages,continuation_links=links,capture_joins=capture_joins,reconstructed_messages=len(retained),events=event_rows,evaluations=evaluation_rows,
      counts=dict(Counter(c['classification'] for c in case_rows)),total_events=len(events),total_models=len(models),total_callbacks=len(callbacks),total_listeners=len(listeners),
      stop_producers=[p for p in messages if p['kind']=='coverage_stop_producer'],
      readback_ends=finished,all_sources_finished=set(sources)<=done,unfinished_sources=[sources[s] for s in set(sources)-done],
      errors=[p for p in messages if p['kind'] in ['coverage_error','evaluation_error']],native_script_errors=native_errors,
      limits=['Natural time-stop-assisted coverage is separately marked; it does not establish ordinary moving, unpaused coverage.',
       'A missing event while the source is frozen or while it never reaches its marker is not a missing-event failure.',
       'Destroyed/replaced actors are lifecycle-censored unless independent scene evidence establishes the expected removal.',
       'Source disappearance below a marker only supports a bounded ordinary transition without observed event, not its exact sub-frame cancellation point.',
       'A same-frame hidden event snapshot alone is weaker than a bracketed original manual Update with hidden pre-state and the event inside.',
       'Observer overhead changes frame steps. Event/callback delivery is measured under instrumentation, not a frame-rate-independent timing guarantee.',
       'Callback identity on the same receiver/frame uses group-level listener counts.'])
if __name__=='__main__':print(json.dumps(analyze(),ensure_ascii=False,indent=2))
