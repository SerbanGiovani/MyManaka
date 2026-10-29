"""Check independently decoded files against native inventory and skill consumers."""
import argparse,gzip,hashlib,json,sys
from pathlib import Path
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parents[1]/'salt'))
import save_codec

def read(p):return json.loads(Path(p).read_text(encoding='utf-8-sig'))
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def rows(p):return list(map(json.loads,gzip.decompress(Path(p).read_bytes()).decode('utf8').splitlines()))
def require(v,m):
    if not v:raise ValueError(m)
def one(rs,kind):
    selected=[r for r in rs if r['kind']==kind];require(len(selected)==1,'Missing/duplicate '+kind);return selected[0]
def projection(path):
    data=Path(path).read_bytes();_,root,_=save_codec.read(data,'unReRU821Drq83');s=root.strings()['GameStateData'].strings()['value'].strings()
    lookup=lambda key,item:next((v for k,v in s[key].entries if k==item),None)
    return dict(path=str(path),sha256=sha(path),bytes=len(data),exp=s['ExposeExp'],rp=s['CurrentRp'],items={str(i):lookup('ItemDict',i) for i in [0,100002,100003]},skill17=dict(level=lookup('SkillLevel',17),active=lookup('PlayerPassiveSkillActiveDict',17)))

def analyze(managed,events,files):
    require(not [r for r in managed if r['kind']=='runner_error'],'Runner failed')
    require(not [r for r in events if r['kind']=='engine_error'],'Native engine error')
    one(managed,'prepared');cleanups=[r for r in managed if r['kind']=='cleanup']
    require(len(cleanups)==2 and all(r['data']['rootsRestored'] for r in cleanups),'Cleanup incomplete')
    # Cases are paired by actual command boundaries, not by snapshot values.
    def selected(command):
        starts=[i for i,r in enumerate(managed) if r['kind']=='command' and r['data']['action']==command]
        require(len(starts)==1,'Missing/duplicate command '+command);start=starts[0]
        stop=next((i for i in range(start+1,len(managed)) if managed[i]['kind']=='command'),len(managed))
        return managed[start:stop]
    def native(name):
        rs=[e for e in events if e['data'].get('name')==name];one(rs,'marker_begin');one(rs,'marker_end');return rs
    def file(name):
        rs=[f for f in files if Path(f['path']).stem==name];require(len(rs)==1,'Missing/duplicate encrypted file');return rs[0]
    inventory=[]
    for item,delta in [(100002,1000),(100003,100),(0,0)]:
        name='inventory-'+str(item);rs=selected('inventory '+str(item));ns=native(name)
        get=lambda k:one(rs,k)['data'];ref=get('reference');dist=get('disturbed');loaded=get('loaded');used=get('used_immediate');end=get('used_result');post=get('post_load');ui=get('selected_ui');result=get('result')
        require(ref['count']==2 and ref['exp']==0 and dist['count']==9 and dist['exp']==7777,'No real inventory disturbance')
        require(loaded['state']!=ref['state'] and loaded['count']==2 and loaded['exp']==0,'Inventory load failed')
        reusable=item!=0;count=2 if reusable else 1
        require(ui['record']==dict(reusable=reusable,delayConsume=not reusable),'Unexpected master consumption flags')
        require(ui['active'] is False,'Controlled inactive-view boundary differs')
        require(all(x['count']==count and x['exp']==delta for x in [used,end,post,result['snapshot']]),'Consumption/effect did not persist')
        require(post['state']!=end['state'],'Post-use state was not natively reloaded')
        for kind in ['inventory_use_button','inventory_use_process','item_effect']:one(ns,kind)
        effect=one(ns,'item_effect');require(effect['data']['caller']=='0x4f4389','Effect not called by original inventory closure')
        require(sum(e['kind']=='native_save' for e in ns)==2 and sum(e['kind']=='native_load' for e in ns)==2,'Inventory native Save/Load count differs')
        changes=[e for e in ns if e['kind']=='item_change']
        if reusable:require(not changes,'Reusable item unexpectedly consumed')
        else:
            require(len(changes)==1 and changes[0]['data']['arg0']=='0x0' and changes[0]['data']['arg1']=='0xffffffff' and changes[0]['data']['caller']=='0x467bdf','Water did not decrement once inside its effect')
        before=file(name+'-before');after=file(name+'-after')
        require(before['items'][str(item)]==2 and before['exp']==0 and after['items'][str(item)]==count and after['exp']==delta,'Encrypted item projection differs')
        inventory.append(dict(item=item,reusable=reusable,delayed_consume=not reusable,before=2,after=count,exp_before=0,exp_after=delta,runtime_rank_after=end['rank'],native_count_changes=len(changes),inactive_ui_callback=True,post_use_file_sha256=after['sha256']))
    skills=[]
    for mode,level,active in [('unlearned',0,False),('disabled',1,False),('enabled',1,True)]:
        name='skill-'+mode;rs=selected('skill '+mode);ns=native(name);get=lambda k:one(rs,k)['data'];ref=get('reference');dist=get('disturbed');loaded=get('loaded');req=get('requested');end=get('skill_result');result=get('result')['snapshot'];f=file(name+'-before')
        require(ref['level']==loaded['level']==level and ref['active']==loaded['active']==active,'Learned/active restoration differs')
        require(dist['level']==7 and dist['active']==(not active) and loaded['state']!=ref['state'],'No skill disturbance/reload')
        require(f['skill17']==dict(level=level,active=active),'Encrypted skill projection differs')
        require(sum(e['kind']=='native_save' for e in ns)==sum(e['kind']=='native_load' for e in ns)==1,'Skill Save/Load differs')
        require(sum(e['kind']=='rise_skill' for e in ns)==(0 if mode=='unlearned' else 1),'Native learning helper missing/duplicate')
        requests=[e for e in ns if e['kind']=='action_update'];changes=[e for e in ns if e['kind']=='action_change'];notices=[e for e in ns if e['kind']=='time_stop_event']
        if active:
            require(len(requests)==len(notices)==2,'Missing/duplicate native request/event')
            require([e['data']['arg1'] for e in changes]==['0x7','0xffffffff','0x7','0xffffffff'],'Native action sequence differs')
            require(req['action']==7 and not req['timeStop'] and end['timeStop'] and end['action']==-1,'Time stop did not activate through animation')
            resume=get('resume_requested');require(resume['action']==7 and resume['timeStop'] and result['action']==-1 and not result['timeStop'],'Time stop did not restore through animation')
            require(all(a['frame']<b['frame'] for a,b in zip(requests,notices)),'Animation event did not follow request')
        else:require(len(requests)==1 and not changes and not notices and req['action']==end['action']==result['action']==-1 and not result['timeStop'],'Disabled skill bypassed guard')
        require(all(x['rp']==0 for x in [ref,dist,loaded,req,end,result]),'Helper was incorrectly treated as UI-paid learning')
        skills.append(dict(mode=mode,level=level,active=active,controlled_input_requests=len(requests),animation_events=len(notices),event_delays_frames=[b['frame']-a['frame'] for a,b in zip(requests,notices)],event_delays_seconds=[b['real']-a['real'] for a,b in zip(requests,notices)],restored_time_stop=result['timeStop'],rp_cost_tested=False))
    require(len(events)==63,'Native capture count differs')
    return dict(authority='controlled-native-inventory-callback-and-skill-input',natural_only=False,inventory=inventory,skills=skills,native_messages=len(events),engine_error_events=0,limits=['Item callbacks were invoked from Unity LateUpdate on a constructed but inactive item view; natural UI availability, confirmation and user clicks are not verified.','Water covers native delayed-consume count once; debug experience items cover reusable effects and runtime rank recalculation.','Skill17 learning uses the level helper, not the UI: cost and rank unlock were not bypassed in a claimed natural test; they are outside this controlled scope.','InputData.JustTimeStop is a controlled request; normal keyboard and ring-menu reachability are established only by prior separate evidence.','Mission queries in state-consumers are static preparation; mission progress/reward consumers remain pending.'])

def build(inputs=False):
    b=read(HERE/'rea-runtime.json');n=next(r['normalized_result'] for r in b['records'] if r['operation']=='frida_session_status')
    require(n['pid']==51012 and not n['messages_truncated'] and all(m['type']=='send' for m in n['messages']),'Native capture incomplete')
    files=read(HERE/'saved-files.json')['files'];result=analyze(rows(HERE/'managed.jsonl.gz'),[m['payload'] for m in n['messages']],files)
    engine=gzip.decompress((HERE/'engine.log.gz').read_bytes()).decode('utf8',errors='replace');require(not any('[Error' in l or '[Fatal' in l for l in engine.splitlines()),'Engine log error')
    p=read(HERE/'post-state.json');require(p['plugins_restored'] and p['frida_closed'] and p['process']['exited'] and p['process']['process_absent'],'Process/plugin cleanup failed')
    require(all(x['unchanged'] for k in ['profile','preserved_test_profile','inputs'] for x in p[k]),'Protected files changed')
    if inputs:
        require(all(projection(f['path'])==f for f in files),'Encrypted projection differs')
        for k in ['profile','preserved_test_profile']:
            for x in p[k]:require(sha(x['path'])==x['before']==x['after'],'Protected profile differs')
        for x in p['inputs']:require(sha(x['path'])==sha(x['original_path'])==x['sha256'],'Engine/asset differs')
    return result
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');p.add_argument('--inputs',action='store_true');a=p.parse_args();r=build(a.inputs)
    if a.check:require(r==read(HERE/'results.json'),'Result differs')
    else:(HERE/'results.json').write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(r,ensure_ascii=False,indent=2))
