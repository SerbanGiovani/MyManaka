// Previously authorized isolated precise replay. Artificial preconditions are explicit.
// Original OnPlayerSound -> original noise OnUpdate -> ChangeState; Unity alone emits events.
// Never calls OnAnimBaretaSound, delay callback, Scheduler, or broadcasts a found notification.
const mod=Process.getModuleByName('GameAssembly.dll'),base=mod.base,hooks=[];
const resolve=new NativeFunction(mod.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function ic(n,t,a){const p=resolve(Memory.allocUtf8String(n));if(p.isNull())throw Error(n);return new NativeFunction(p,t,a,{traps:'all'});}
function native(r,t,a){return new NativeFunction(base.add(r),t,a,{traps:'all'});}
const frame=ic('UnityEngine.Time::get_frameCount()','int',[]),real=ic('UnityEngine.Time::get_realtimeSinceStartup()','float',[]),scale=ic('UnityEngine.Time::get_timeScale()','float',[]);
const transform=ic('UnityEngine.GameObject::get_transform()','pointer',['pointer']),position=ic('UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)','void',['pointer','pointer']),setPosition=ic('UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)','void',['pointer','pointer']);
const getBool=ic('UnityEngine.Animator::GetBoolID(System.Int32)','bool',['pointer','int']),setBool=ic('UnityEngine.Animator::SetBoolID(System.Int32,System.Boolean)','void',['pointer','int','bool']),speed=ic('UnityEngine.Animator::get_speed()','float',['pointer']),active=ic('UnityEngine.GameObject::get_activeInHierarchy()','bool',['pointer']);
const info=ic('UnityEngine.Animator::GetAnimatorStateInfo(System.Int32,UnityEngine.StateInfoIndex,UnityEngine.AnimatorStateInfo&)','void',['pointer','int','int','pointer']),transition=ic('UnityEngine.Animator::IsInTransition(System.Int32)','bool',['pointer','int']),weight=ic('UnityEngine.Animator::GetLayerWeight(System.Int32)','float',['pointer','int']);
const change=native(0x429740,'void',['pointer','int','pointer']),onSound=native(0x435fb0,'void',['pointer','pointer','pointer']),noiseUpdate=native(0x435300,'void',['pointer','pointer']);
const params=base.add(0x2d59ea8).readPointer().add(0xb8).readPointer(),foundHash=params.add(0x24).readS32(),femaleHash=params.add(0x14).readS32(),sitHash=params.add(0x38).readS32();
const buf=Memory.alloc(36),v=Memory.alloc(12),rows=new Map(),used=new Set(),plans=['stable-early','near-marker','stable-early','near-marker'];
let current=null,index=0,done=false,lastEnd=0,readyAt=real(),lastWait=0;
function hook(r,h){hooks.push(Interceptor.attach(base.add(r),h));}
function emit(kind,data){send({kind,frame:frame(),real:real(),data});}
function live(p){return !p.isNull()&&!p.add(0x10).readPointer().isNull();}
function temp(){return base.add(0x2d53c48).readPointer().add(0xb8).readPointer().readPointer().add(0x30).readPointer();}
function player(){return base.add(0x2d58378).readPointer().add(0xb8).readPointer().readPointer().add(0x40).readPointer();}
function vector(p){return [0,4,8].map(o=>p.add(o).readFloat());}
function state(a,i){info(a,4,i,buf);return {full:buf.add(8).readU32(),normalized:buf.add(12).readFloat()};}
function details(c){return {state:c.model.add(0x10).readS32(),value:c.value.add(0x14).readFloat(),reduceCount:c.value.add(0x18).readS32(),rate:c.value.add(0x10).readFloat(),threshold:c.model.add(0xcc).readFloat(),added:c.noise.add(0x30).readFloat(),playerFound:c.search.add(0x68).readU8(),ignore:c.model.add(0x24).readFloat(),justHit:c.model.add(0xa0).readU8(),alreadyFound:c.model.add(0x1d).readU8()};}
function snapshot(c){position(c.pt,v);const pp=vector(v);position(transform(c.root),v);const np=vector(v);return {frame:frame(),real:real(),current:state(c.animator,0),next:state(c.animator,1),transition:transition(c.animator,4),found:getBool(c.animator,foundHash),meshActive:active(c.mesh),distance:Math.sqrt(pp.reduce((s,n,i)=>s+(n-np[i])**2,0)),speed:speed(c.animator),weight:weight(c.animator,4),business:details(c)};}
function flush(c){if(c.samples.length){emit('noise_control_samples',{trial:c.id,samples:c.samples});c.samples=[];}}
function force(c){position(transform(c.root),c.near);c.near.writeFloat(c.near.readFloat()+1);setPosition(c.pt,c.near);}
function finish(reason){const c=current;if(!c)return;flush(c);const cleanup={errors:[]};
 try{if(live(c.animator))change(c.npc,c.oldState,ptr(0));else cleanup.retired=true;}catch(e){cleanup.errors.push('state:'+e.message);}
 try{if(live(c.animator))setBool(c.animator,foundHash,c.oldFound);}catch(e){cleanup.errors.push('found:'+e.message);}
 for(const r of c.saved){try{if(r.type==='float')r.p.writeFloat(r.value);else if(r.type==='int')r.p.writeS32(r.value);else r.p.writeU8(r.value);}catch(e){cleanup.errors.push('field:'+r.p+':'+e.message);}}
 try{cleanup.fieldsMatch=c.saved.every(r=>(r.type==='float'?r.p.readFloat():r.type==='int'?r.p.readS32():r.p.readU8())===r.value);cleanup.stateMatches=c.model.add(0x10).readS32()===c.oldState;cleanup.foundMatches=getBool(c.animator,foundHash)===c.oldFound;}catch(e){cleanup.errors.push('verify:'+e.message);}
 try{setPosition(c.pt,c.origin);position(c.pt,v);cleanup.positionError=vector(v).reduce((s,n,i)=>s+Math.abs(n-vector(c.origin)[i]),0);}catch(e){cleanup.errors.push('position:'+e.message);}
 emit('noise_control_end',{trial:c.id,plan:c.plan,reason,events:c.events,callbacks:c.callbacks,cleanup});current=null;lastEnd=real();}
function complete(reason){done=true;emit('noise_control_finished',{trials:index,reason});for(const h of hooks)h.detach();}
hook(0x41eb80,{onEnter(a){try{const nca=a[0].add(0x18).readPointer();rows.set(nca.toString(),nca);}catch(e){}}});
hook(0x429740,{onEnter(a){if(current&&current.insideNoise&&a[0].equals(current.npc))emit('noise_control_change',{trial:current.id,nca:current.nca.toString(),old:current.model.add(0x10).readS32(),next:a[1].toInt32(),caller:'0x'+this.returnAddress.sub(base).toString(16),before:details(current)});}});
hook(0x41a730,{onEnter(a){if(current&&a[0].equals(current.receiver)){current.events++;emit('noise_control_event',{trial:current.id,at:snapshot(current)});}}});
hook(0x41a870,{onEnter(a){if(current&&a[0].equals(current.receiver)){current.callbacks++;emit('noise_control_callback',{trial:current.id});}}});
hook(0x620800,{onEnter(){if(done)return;try{
 if(current){const c=current;if(!live(c.animator)||!live(c.mesh)){finish('actor-retired');complete('actor-retired');return;}
  if(temp().add(0x14).readU8()||temp().add(0x11).readU8()||scale()!==1){finish('external-pause-or-game-over');complete('external-pause-or-game-over');return;}
  force(c);const s=snapshot(c);c.samples.push(s);if(c.samples.length>=60)flush(c);
  if(!c.entered&&real()-c.began>.8){c.entered=true;c.enterAt=real();c.fs.add(0x10).writeFloat(0);c.model.add(0x1d).writeU8(1);c.value.add(0x14).writeFloat(1);c.value.add(0x18).writeS32(120);change(c.npc,1,ptr(0));emit('noise_control_enter',{trial:c.id,at:snapshot(c)});return;}
  const sources=[s.current,...(s.transition?[s.next]:[])].filter(x=>x.full===0xfa993e55);
  if(c.entered&&!c.triggered&&sources.length){const progress=Math.max(...sources.map(x=>x.normalized)),target=c.plan==='stable-early'?.25:.60;
   if(progress>=target&&!s.transition&&s.current.full===0xfa993e55){c.triggered=true;c.triggerAt=real();const before=snapshot(c),savedSearch=c.search.add(0x68).readU8(),savedIgnore=c.model.add(0x24).readFloat();
    c.search.add(0x68).writeU8(0);c.model.add(0x24).writeFloat(-1);c.model.add(0xa0).writeU8(0);c.noise.add(0x30).writeFloat(0);c.value.add(0x14).writeFloat(c.model.add(0xcc).readFloat()-.000001);
    const evt=base.add(0x2d58080).readPointer().add(0xb8).readPointer().add(0x90).readPointer(),oldType=evt.add(0x10).readS32(),oldMachine=evt.add(0x14).readU8();let afterSound;
    try{evt.add(0x10).writeS32(2);evt.add(0x14).writeU8(0);onSound(c.noise,evt,ptr(0));afterSound=details(c);}finally{evt.add(0x10).writeS32(oldType);evt.add(0x14).writeU8(oldMachine);}
    let after;try{c.insideNoise=true;noiseUpdate(c.noise,ptr(0));after=snapshot(c);}finally{c.insideNoise=false;c.search.add(0x68).writeU8(savedSearch);c.model.add(0x24).writeFloat(savedIgnore);}
    emit('noise_control_trigger',{trial:c.id,targetProgress:target,before,afterSound,after,source:'original OnPlayerSound SeType2 then original noise OnUpdate',artificial:['state entry','near geometry','value lowered below threshold','PlayerFound=false','IgnoreNoise=-1']});
   }}
  if(c.triggered&&real()-c.triggerAt>2.5&&!sources.length&&!s.transition){finish('completed');return;}
  if(real()-c.began>8){finish('observation-bound');return;}return;
 }
 if(index>=plans.length){complete('completed');return;}if(real()-lastEnd<1||real()-readyAt<2)return;
 if(temp().add(0x14).readU8()||temp().add(0x11).readU8()||scale()!==1)return;
 let chosen=null;
 for(const [key,nca] of rows){if(used.has(key))continue;try{const animator=nca.add(0x90).readPointer(),mesh=nca.add(0xc0).readPointer().add(0x20).readPointer(),model=nca.add(0x40).readPointer(),npc=nca.add(0x38).readPointer(),root=nca.add(0x18).readPointer();
  if(live(animator)&&live(mesh)&&live(root)&&active(mesh)&&!getBool(animator,foundHash)&&getBool(animator,femaleHash)&&!getBool(animator,sitHash)&&speed(animator)>.6&&speed(animator)<1&&model.add(0x54).readU8()===0&&model.add(0x23).readU8()===0&&model.add(0x85).readU8()===0&&model.add(0x10).readS32()===0){chosen={nca,npc,animator,mesh,model,root,noise:nca.add(0x60).readPointer(),search:nca.add(0x68).readPointer(),fs:npc.add(0x50).readPointer(),receiver:nca.add(0x98).readPointer()};used.add(key);break;}
 }catch(e){rows.delete(key);}}
 if(!chosen){if(real()-lastWait>5){lastWait=real();emit('noise_control_waiting',{actors:rows.size});}if(real()-readyAt>60)complete('no-matching-actor');return;}
 const c=chosen;c.value=c.noise.add(0x10).readPointer();c.id=++index;c.plan=plans[index-1];c.oldState=c.model.add(0x10).readS32();c.oldFound=getBool(c.animator,foundHash);c.origin=Memory.alloc(12);c.near=Memory.alloc(12);c.pt=transform(player().add(0x28).readPointer());position(c.pt,c.origin);c.began=real();c.samples=[];c.events=0;c.callbacks=0;
 c.saved=[[c.model.add(0x1d),'byte'],[c.model.add(0x24),'float'],[c.model.add(0xa0),'byte'],[c.model.add(0x30),'byte'],[c.search.add(0x68),'byte'],[c.fs.add(0x10),'float'],[c.value.add(0x14),'float'],[c.value.add(0x18),'int'],[c.noise.add(0x30),'float']].map(([p,type])=>({p,type,value:type==='float'?p.readFloat():type==='int'?p.readS32():p.readU8()}));
 current=c;emit('noise_control_begin',{trial:c.id,plan:c.plan,nca:c.nca.toString(),receiver:c.receiver.toString(),origin:vector(c.origin),oldState:c.oldState,baseline:details(c),authority:'controlled receiver replay; artificial numeric/visibility preconditions; real Unity animation events'});setBool(c.animator,foundHash,0);force(c);
 }catch(e){emit('noise_control_error',{error:e.message});finish('error');complete('error');}}});
emit('noise_control_ready',{plans,authority:'Controlled replay separated from the closed natural session; never a natural noise cancellation claim.'});
