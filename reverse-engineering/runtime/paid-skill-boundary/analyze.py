"""Offline proof of active skill UI gates, original consumers, and serialized state."""
import argparse,collections,gzip,hashlib,json,math,sys
from pathlib import Path
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parents[1]/'salt'))
import save_codec
NAMES=['rp-low','rp-exact','max','rank-locked','prerequisite','passive-absent','passive-false']
IDS=[6,7,9,11,17]
LOAD_ID='ev_ce7d5401050ae2fead9f88e7a3ac36cb4a9a8b24c7480ed969e556bfa67899d0'
STATUS_ID='ev_6a159de54c712a31a08cf3623fbfa0dc99d373c6b811808fdd7a2bc6167f0610'
COUNTS={'rp_bonus_consumer':40,'skill_tab':28,'native_save':14,'skill_panel_open':14,'paid_button':9,'change_passive':8,'marker_begin':7,'native_load':7,'marker_end':7,'toggle_callback':6,'consume_rp':5,'rise_skill_level':5,'parent_paid_callback':5,'capacity_consumer':3,'switch_panel_open':2,'paid_skill_ready':1}
def read(path):return json.loads(Path(path).read_text(encoding='utf-8-sig'))
def sha(path):return hashlib.sha256(Path(path).read_bytes()).hexdigest()
def rows(path):return [json.loads(l) for l in gzip.decompress(Path(path).read_bytes()).decode('utf8').splitlines()]
def require(value,message):
 if not value:raise ValueError(message)
def one(values,kind):
 selected=[r for r in values if r['kind']==kind];require(len(selected)==1,'Missing/duplicate '+kind);return selected[0]
def near(a,b):return isinstance(a,(int,float)) and isinstance(b,(int,float)) and math.isfinite(a) and math.isfinite(b) and abs(a-b)<2e-6
def skill(snapshot,i):return next(s for s in snapshot['skills'] if s['id']==i)
def semantic(s):return {k:v for k,v in s.items() if k!='state'}
def projection(path):
 data=Path(path).read_bytes();_,root,_=save_codec.read(data,'unReRU821Drq83');state=root.strings()['GameStateData'].strings()['value'].strings()
 levels=state['SkillLevel'].entries;passive=state['PlayerPassiveSkillActiveDict'].entries
 require(len(dict(levels))==len(levels) and all(type(k) is int and type(v) is int for k,v in levels),'Invalid serialized level dictionary')
 require(len(dict(passive))==len(passive) and all(type(k) is int and type(v) is bool for k,v in passive),'Invalid serialized passive dictionary')
 return dict(path=str(path),sha256=sha(path),bytes=len(data),rp=state['CurrentRp'],usedRp=state['StatistisTotalUseRp'],skills=[dict(id=k,level=v) for k,v in sorted(levels)],passive=[dict(id=k,stored=v) for k,v in sorted(passive)])
def serialized_matches(file,snapshot):
 require(file['rp']==snapshot['rp'] and file['usedRp']==snapshot['usedRp'],'Serialized RP/statistic differs')
 levels={s['id']:s['level'] for s in file['skills']};passive={s['id']:s['stored'] for s in file['passive']}
 for s in snapshot['skills']:
  require(levels.get(s['id'])==s['level'] and (s['id'] in passive)==s['present'] and passive.get(s['id'])==s['stored'],'Serialized level/key-presence/value differs')
def tier(assets,i,level):return next(r for r in assets['tiers'][str(i)] if r['Level']==level)
def price(assets,i,level):
 if i in [6,11]:return tier(assets,i,level)['NextLevelUpRp']
 record=assets['records'][str(i)];return int(record['InitRp'])+level*int(record['IncrementRp'])
def view(v,assets,i,level,masked=False):
 require(v['active'] and v['pointer'] and v['id']==i and v['hasParentCallback'] and v['parentCallback'],'Inactive/wrong/unwired real skill view')
 maximum=level>=int(assets['records'][str(i)]['MaxLevel'])
 require(v['price']==price(assets,i,level) and v['masked'] is masked and v['max'] is maximum and v['button'] is (not maximum),'Actual skill price/mask/max/button differs')
def passive_consumer(s,active):
 v=skill(s,7);require(v['level']==1 and v['present'] and v['stored'] is active and v['effective'] is active,'NpcDirect stored/effective state differs')
 require(s['npcDirectBuff']['active'] is active and s['npcDirectBuff']['flat']==-10 and s['npcDirectBuff']['lastMultiplier']==0,'NpcDirect actual buff differs')
 require(near(s['rpBonus'],.72 if active else .8) and abs(s['rpBonusInt']-(72 if active else 80))<3e-5,'Observed fixture RP bonus consumer differs')
def analyze(managed,events,files,assets):
 require(not any(r['kind'] in ['runner_error','cleanup_error'] for r in managed),'Formal run fixture error')
 require(collections.Counter(e['kind'] for e in events)==COUNTS,'Native message/event counts differ')
 require(len(events)==161,'Formal native message count differs')
 readiness=[r for r in managed if r['kind']=='readiness'];require(readiness and all(r['data']['ready'] for r in readiness),'Assets not ready')
 prep=one(managed,'prepared')['data'];require(prep['previous']!=prep['state'] and prep['rank']==0 and prep['oldRank'] and prep['otherBuffs']==43,'Global state was not detached before fixtures')
 require(int(assets['records']['17']['ReleaseRank'])==7 and int(assets['records']['9']['ReleaseOrderTargetId'])==6,'Static rank/prerequisite binding differs')
 require(len(files)==14 and len({Path(f['path']).stem for f in files})==14,'Encrypted capture coverage differs')
 output=[]
 for name in NAMES:
  rs=[r for r in managed if r.get('data',{}).get('name')==name and r['kind']!='command'];get=lambda kind:one(rs,kind)['data']['data']
  conf=get('configured');post=get('post_use');dist=get('disturbed');loaded=get('loaded');verified=get('verified_ui');result=get('case_result');before=get('view_before')
  target=7 if name.startswith('passive') else 9 if name=='prerequisite' else 17 if name=='rank-locked' else 11
  expected_before_rp={'rp-low':299,'rp-exact':300,'max':2000,'rank-locked':1000,'prerequisite':250,'passive-absent':100,'passive-false':100}[name]
  expected_spend={'rp-exact':300,'prerequisite':250,'passive-absent':100,'passive-false':100}.get(name,0)
  require(conf['rank']==0 and conf['rp']==expected_before_rp and conf['usedRp']==0,'Fixture input RP/rank differs')
  require([s['id'] for s in conf['skills']]==IDS and all(s['level']==(3 if name=='max' and s['id']==11 else 0) for s in conf['skills']),'Fixture input levels differ')
  require(all(s['present'] is (name=='passive-false' and s['id']==7) and s['stored'] is (False if name=='passive-false' and s['id']==7 else None) and s['effective'] is False for s in conf['skills']),'Fixture input passive dictionary differs')
  view(before,assets,target,skill(conf,target)['level'],name in ['rank-locked','prerequisite'])
  require(post['rp']==conf['rp']-expected_spend and post['usedRp']==expected_spend,'Wrong spend or denied button changed RP')
  expected_levels={s['id']:s['level'] for s in conf['skills']}
  for i in ([6,9] if name=='prerequisite' else [target] if expected_spend else []):expected_levels[i]+=1
  require({s['id']:s['level'] for s in post['skills']}==expected_levels,'Wrong acquired levels')
  expected_passive={9:True} if name=='prerequisite' else {7:name=='passive-absent'} if target==7 else {}
  require({s['id']:s['stored'] for s in post['skills'] if s['present']}==expected_passive,'First learn key-presence or preserved false differs')
  require(all(s['effective'] is False for s in post['skills'] if s['id'] in [6,11]),'Non-toggle indicator is not a passive capability test')
  if name!='prerequisite':
   clicked=get('clicked');require(clicked['snapshot']['rp']==post['rp'] and clicked['snapshot']['usedRp']==post['usedRp'],'Click/accounting phase differs');view(clicked['view'],assets,target,expected_levels[target],name=='rank-locked')
   if not expected_spend:require(clicked['snapshot']==conf,'Rejected original callback changed state')
  else:
   rejected=get('prerequisite_rejected');require(rejected['snapshot']==conf and rejected['view']==before,'Masked prerequisite callback did not reject')
   slow=get('slow_before');bought=get('slow_bought');auto=get('auto_bought');view(slow,assets,6,0);view(bought['view'],assets,6,1);view(bought['auto'],assets,9,0);view(auto['view'],assets,9,1)
   require(before['pointer']==bought['auto']['pointer']==auto['view']['pointer'] and before['parentCallback']==bought['auto']['parentCallback'],'Prerequisite was not refreshed on same panel/item')
   require(bought['snapshot']['rp']==200 and bought['snapshot']['usedRp']==50 and skill(bought['snapshot'],6)['level']==1 and skill(bought['snapshot'],9)['level']==0,'Slow tier price/purchase differs')
   require(auto['snapshot']['rp']==0 and auto['snapshot']['usedRp']==250 and skill(auto['snapshot'],9)['stored'] is True,'AutoSlow purchase differs')
   require(near(post['rpBonus'],.64),'AutoSlow observed RP consumer differs')
  if target==11:
   ui=get('capacity_ui');record=tier(assets,11,expected_levels[11]);require(ui['active'] and ui['actual']==1 and ui['canEquip'] is True and ui['capacity']==post['capacity'] and ui['capacity']['max']==record['MaxNum'] and ui['text'].endswith('1/'+str(record['MaxNum'])),'Actual inventory capacity consumer/text differs')
  if target==7:
   active=name=='passive-absent';ref=get('toggle_reference');require(ref['active'] and ref['stored'] is active,'Real switch view value differs')
   passive_consumer(get('consumer_after_click'),active);passive_consumer(ref['snapshot'],active);passive_consumer(get('toggle_off'),False);passive_consumer(get('toggle_on'),True);passive_consumer(post,active)
   if not active:passive_consumer(get('toggle_restore_false'),False)
  require(dist['state']==post['state'] and dist['rp']==7777 and all(skill(dist,i)['level']==(1 if skill(post,i)['level']==0 else 0) for i in IDS),'Disturbance did not change same live data roots')
  require(all(s['present'] and s['stored'] is not None for s in dist['skills'] if s['level']>0),'Disturbance is missing a legal passive lookup key')
  require(loaded['state']!=dist['state'] and semantic(loaded)==semantic(post)==semantic(result)==semantic(verified['snapshot']),'Native Load/UI did not restore actual consumer state')
  view(verified['view'],assets,target,expected_levels[target],name=='rank-locked')
  before_file=next(f for f in files if Path(f['path']).stem==name+'-before');after_file=next(f for f in files if Path(f['path']).stem==name+'-after')
  serialized_matches(before_file,conf);serialized_matches(after_file,post)
  full_before={s['id']:s['level'] for s in before_file['skills']};full_after={s['id']:s['level'] for s in after_file['skills']};full_expected=dict(full_before)
  for i in IDS:full_expected[i]=expected_levels[i]
  require(full_after==full_expected and len(full_after)==len(full_before),'Unselected serialized skill changed')
  require({s['id']:s['stored'] for s in after_file['passive']}==expected_passive,'Unexpected passive dictionary key serialized')
  ns=[e for e in events if e['data'].get('name')==name];begin=one(ns,'marker_begin');end=one(ns,'marker_end');require(ns[0]==begin and ns[-1]==end and begin['data']['thread']==end['data']['thread'],'Native marker order/thread differs')
  require(begin['frame']==one(rs,'configured')['frame'] and end['frame']==one(rs,'case_result')['frame'],'Managed/native case frames differ')
  require(sum(e['kind']=='native_save' for e in ns)==2 and sum(e['kind']=='native_load' for e in ns)==1 and sum(e['kind']=='skill_panel_open' for e in ns)==2 and sum(e['kind']=='skill_tab' for e in ns)==4,'Native Save/Load/panel coverage differs')
  require([e['frame'] for e in ns if e['kind']=='native_save']==[one(rs,'configured')['frame'],one(rs,'post_use')['frame']] and one(ns,'native_load')['frame']==one(rs,'post_use')['frame'],'Native Save/Load capture phase differs')
  click_frame=one(rs,'view_before')['frame'];purchase=[e for e in ns if e['frame']==click_frame and e['kind'] in ['paid_button','consume_rp','rise_skill_level','change_passive','parent_paid_callback']]
  intended=[(6,50),(9,200)] if name=='prerequisite' else [(target,expected_spend)] if expected_spend else []
  pattern=['paid_button'] if name=='prerequisite' or not expected_spend else []
  for i,cost in intended:pattern+=['paid_button','consume_rp','rise_skill_level']+(['change_passive'] if i==9 or name=='passive-absent' else [])+['parent_paid_callback']
  require([e['kind'] for e in purchase]==pattern,'Paid original callback/consume/rise/parent ordering differs')
  require([int(e['data']['arg0'],16) for e in purchase if e['kind']=='consume_rp']==[p[1] for p in intended] and [int(e['data']['arg0'],16) for e in purchase if e['kind']=='rise_skill_level']==[p[0] for p in intended],'Native price/skill arguments differ')
  for e in purchase:
   if e['kind']=='consume_rp':require(e['data']['caller']=='0x4c480b','Consume did not come from real paid button')
   if e['kind']=='rise_skill_level':require(e['data']['caller']=='0x4c4825','Rise did not come from real paid button')
   if e['kind']=='parent_paid_callback':require(e['data']['caller']=='0x4c4850','Parent callback did not come from real paid button')
  require(int(next(e for e in purchase if e['kind']=='paid_button')['data']['arg0'],16)==int(before['pointer']),'Clicked native view differs from actual active item')
  expected_views=[before['pointer'],get('slow_before')['pointer'],before['pointer']] if name=='prerequisite' else [before['pointer']]
  require([int(e['data']['arg0'],16) for e in purchase if e['kind']=='paid_button']==list(map(int,expected_views)),'Native button receiver sequence differs')
  passive_calls=[(int(e['data']['arg0'],16),int(e['data']['arg1'],16)) for e in ns if e['kind']=='change_passive']
  expected_calls=[(9,1)] if name=='prerequisite' else [(7,1),(7,0),(7,1)] if name=='passive-absent' else [(7,0),(7,0),(7,1),(7,0)] if name=='passive-false' else []
  require(passive_calls==expected_calls,'Native passive argument sequence differs')
  output.append(dict(name=name,target=target,rank=0,rp_before=conf['rp'],rp_after=post['rp'],spent=expected_spend,level_before=skill(conf,target)['level'],level_after=skill(post,target)['level'],masked_before=before['masked'],maximum_before=before['max'],capacity=post['capacity']['max'] if target==11 else None,passive_present=skill(post,target)['present'],passive_stored=skill(post,target)['stored'],passive_effective=skill(post,target)['effective'],save_load_consumers_equal=True,encrypted_before=before_file['sha256'],encrypted_after=after_file['sha256']))
 cleanup=one(managed,'cleanup')['data'];require(all(cleanup[k] for k in ['rootsRestored','rankRestored','playerFieldsRestored','calculatorFieldsRestored','buffFieldsRestored']) and cleanup['stop'] is False,'Recorded cleanup did not restore globals/rank/cache/buffs/stop')
 toggles=[e for e in events if e['kind']=='toggle_callback'];initial=[e for e in toggles if e['data']['caller']=='0xb8d8be'];require(len(initial)==1 and initial[0]['data']['name']=='passive-false' and sum(e['data']['caller']=='0x35bd19' for e in toggles)==5,'Switch initialization/explicit callback distinction differs')
 return dict(authority='controlled-active-original-skill-ui-and-runtime-consumers',natural_only=False,run='20261030-3',cases=output,native_messages=161,counts=COUNTS,encrypted_files=14,cleanup_recorded_restored=True,switch_initialization_callbacks=1,explicit_switch_callbacks=5,limits=['Active original views and callbacks were invoked on Unity main thread; no natural mouse, player rank progression or successful TimeStop tutorial claim.','Skills6 Slow and11 capacity are not passive toggles. The helper effective=false does not mean those abilities are ineffective; inventory capacity was actually read as5/10/30.','Observed NpcDirect buff flat=-10 changed this fixture multiplier about0.80 to0.72; other difficulty, equipment or buffs may yield different totals.','Cold title load, consumer saturation at equipment count==limit, and further ranks/prerequisites remain untested.','Only formal v3 is a successful batch. Bootstrap v1 and invalid-fixture v2 diagnostics remain separate, including3439 observed v2 engine errors.'])
def build(inputs=False,require_finalized_plugins=False):
 bundle=read(HERE/'rea-runtime.json');status=next(r for r in bundle['records'] if r['evidence_id']==STATUS_ID);n=status['normalized_result'];loader=next(r for r in bundle['records'] if r['evidence_id']==LOAD_ID)['normalized_result']
 require(n['session_id']=='dfe861aa-0082-4de9-be89-7e8e006e1b71' and n['pid']==72824 and not n['messages_truncated'] and all(m['type']=='send' for m in n['messages']),'Wrong/incomplete formal native session')
 require(loader['source_sha256']==sha(HERE/'observe.js') and not loader['messages_truncated'] and all(m['script_id']==loader['script_id'] for m in n['messages']),'Observer script provenance differs')
 manifest=read(HERE/'manifest.json')
 for item in manifest['sources']+manifest['outputs']+manifest['dependencies']:require(sha(HERE/item['path'])==item['sha256'],'Manifest fingerprint differs: '+item['path'])
 files=read(HERE/'saved-files.json')['files'];result=analyze(rows(HERE/'managed.jsonl.gz'),[m['payload'] for m in n['messages']],files,read(HERE/'asset-tiers.json'))
 diagnostic=read(HERE/'diagnostics.json')['separate_failed_setup_runs'];require(len(diagnostic)==2 and all(d['success'] is False for d in diagnostic),'Failed diagnostic classification differs')
 invalid=next(d for d in diagnostic if d['name']=='invalid-fixture');require(invalid['rea_engine_errors']==invalid['engine_error_lines']==3439 and invalid['runner_errors'] and invalid['cleanup'],'Invalid-fixture failure/cleanup evidence differs')
 engine=gzip.decompress((HERE/'engine.log.gz').read_bytes()).decode('utf8',errors='replace');require(not any('[Error' in l or '[Fatal' in l for l in engine.splitlines()),'Formal engine error')
 post=read(HERE/'post-state.json');require(post['frida_closed'] and post['process']['exited'] and post['process']['process_absent'],'Formal process not recorded closed')
 require(all(p['unchanged'] for k in ['profile','preserved_test_profile','inputs'] for p in post[k]),'Protected inputs changed')
 final=post['plugins_finalized'];require(not require_finalized_plugins or final,'Final plugin fingerprints pending')
 if final:require(post['plugins_restored'] and all(p['unchanged'] for p in post['plugins']),'Original plugins not restored')
 paths=rows(HERE/'paths.jsonl.gz');working=(Path(read(HERE/'baseline.json')['output_root'])/'working-profile').resolve();redirects=[r['data']['after'] for r in paths if r['kind']=='save_path'];require(redirects and all(Path(p).resolve().is_relative_to(working) for p in redirects),'Save redirect escaped private profile')
 managed=rows(HERE/'managed.jsonl.gz');first=one(managed,'prepared')['frame'];last=one(managed,'cleanup')['frame'];snaps=[r for r in paths if r['kind']=='snapshot' and first<=r['frame']<=last];require(snaps and all(r['data']['scene']=='Apartment' for r in snaps),'Controlled runtime scene differs')
 if inputs:
  require(all(projection(f['path'])==f for f in files),'Independent cipher decoding differs')
  for key in ['profile','preserved_test_profile']:
   for p in post[key]:require(sha(p['path'])==p['before']==p['after'],'Protected profile fingerprint changed')
  for p in post['inputs']:require(sha(p['path'])==sha(p['original_path'])==p['sha256'],'Protected native/resource fingerprint changed')
  for p in manifest['raw_inputs']:require(sha(p['path'])==p['sha256'],'Raw captured input fingerprint changed')
  require(sha(manifest['plugin']['archived_path'])==manifest['plugin']['sha256'],'Archived fixture fingerprint changed')
  for p in manifest['diagnostic_observation']['plugins']:require(sha(p['archived_path'])==p['sha256'],'Archived diagnostic plugin fingerprint changed')
  if final:
   for p in post['plugins']:require(sha(p['path'])==p['sha256'],'Final plugin fingerprint changed')
 result['redirected_path_events']=len(redirects);result['plugins_finalized']=final;result['protected_inputs']={k:len(post[k]) for k in ['profile','preserved_test_profile','inputs']};return result
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--inputs',action='store_true');p.add_argument('--check',action='store_true');p.add_argument('--require-finalized-plugins',action='store_true');a=p.parse_args();r=build(a.inputs,a.require_finalized_plugins)
 if a.check:require(r==read(HERE/'results.json'),'Stored results differ')
 else:(HERE/'results.json').write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
 print(json.dumps(dict(cases=len(r['cases']),messages=r['native_messages'],encrypted_files=r['encrypted_files'],plugins_finalized=r['plugins_finalized'],protected_inputs=r['protected_inputs'])))
