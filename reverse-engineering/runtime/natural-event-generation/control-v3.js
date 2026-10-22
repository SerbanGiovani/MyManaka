// Previously authorized precise timing in the independent full game copy.
// Synthetic parameter source; Unity must generate AnimationEvents itself.
// Never calls OnAnimBaretaSound, Scheduler or the delayed callback directly.
const m=Process.getModuleByName('GameAssembly.dll'),base=m.base;
const resolve=new NativeFunction(m.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function ic(n,t,a){const p=resolve(Memory.allocUtf8String(n));if(p.isNull())throw Error(n);return new NativeFunction(p,t,a,{traps:'all'});}
const frame=ic('UnityEngine.Time::get_frameCount()','int',[]),real=ic('UnityEngine.Time::get_realtimeSinceStartup()','float',[]),scale=ic('UnityEngine.Time::get_timeScale()','float',[]);
const transform=ic('UnityEngine.GameObject::get_transform()','pointer',['pointer']),getPos=ic('UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)','void',['pointer','pointer']),setPos=ic('UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)','void',['pointer','pointer']);
const active=ic('UnityEngine.GameObject::get_activeSelf()','bool',['pointer']),setActive=ic('UnityEngine.GameObject::SetActive(System.Boolean)','void',['pointer','bool']);
const getBool=ic('UnityEngine.Animator::GetBoolID(System.Int32)','bool',['pointer','int']),setBool=ic('UnityEngine.Animator::SetBoolID(System.Int32,System.Boolean)','void',['pointer','int','bool']);
const speed=ic('UnityEngine.Animator::get_speed()','float',['pointer']);
const info=ic('UnityEngine.Animator::GetAnimatorStateInfo(System.Int32,UnityEngine.StateInfoIndex,UnityEngine.AnimatorStateInfo&)','void',['pointer','int','int','pointer']);
const transition=ic('UnityEngine.Animator::IsInTransition(System.Int32)','bool',['pointer','int']);
const hierarchy=ic('UnityEngine.GameObject::get_activeInHierarchy()','bool',['pointer']);
const enabled=ic('UnityEngine.Behaviour::get_enabled()','bool',['pointer']);
const fire=ic('UnityEngine.Animator::get_fireEvents()','bool',['pointer']);
const weight=ic('UnityEngine.Animator::GetLayerWeight(System.Int32)','float',['pointer','int']);
const infoBuf=Memory.alloc(36),posBuf=Memory.alloc(12);
const hash=base.add(0x2d59ea8).readPointer().add(0xb8).readPointer().add(0x24).readS32();
const rows=new Map(),used=new Set(),buffer=Memory.alloc(12);let current=null,index=0,started=0,lastEnd=0,done=false;
const names=['early_cancel'];
const femaleHash=base.add(0x2d59ea8).readPointer().add(0xb8).readPointer().add(0x14).readS32(),sitHash=base.add(0x2d59ea8).readPointer().add(0xb8).readPointer().add(0x38).readS32();
function emit(kind,data){send({kind,frame:frame(),real:real(),data});}
function live(p){return !p.isNull()&&!p.add(0x10).readPointer().isNull();}
function flag(){return base.add(0x2d53c48).readPointer().add(0xb8).readPointer().readPointer().add(0x30).readPointer().add(0x14).readU8();}
function player(){return base.add(0x2d58378).readPointer().add(0xb8).readPointer().readPointer().add(0x40).readPointer();}
function force(c){if(c.ended)return;getPos(transform(c.root),c.near);Memory.copy(c.far,c.near,12);c.near.writeFloat(c.near.readFloat()+1);c.far.writeFloat(c.far.readFloat()+60);setPos(c.pt,c.targetFar?c.far:c.near);setActive(c.mesh,c.hidden?0:1);}
function vector(p){return [p.readFloat(),p.add(4).readFloat(),p.add(8).readFloat()];}
function state(a,i){info(a,4,i,infoBuf);return {full:infoBuf.add(8).readU32(),normalized:infoBuf.add(12).readFloat(),length:infoBuf.add(16).readFloat()};}
function flush(c){if(c.samples.length){emit('generation_control_samples',{trial:c.id,samples:c.samples});c.samples=[];}}
function sample(c){const common=c.nca.add(0x88).readPointer().add(0x10).readPointer();getPos(c.pt,buffer);getPos(transform(c.root),posBuf);let d=0;for(let i=0;i<3;i++)d+=(buffer.add(i*4).readFloat()-posBuf.add(i*4).readFloat())**2;
 c.samples.push({frame:frame(),real:real(),current:state(c.animator,0),next:state(c.animator,1),transition:transition(c.animator,4),found:getBool(c.animator,hash),meshActive:hierarchy(c.mesh),distance:Math.sqrt(d),manual:common.add(0x10).readU8(),fps:common.add(0x14).readS32(),enabled:enabled(c.animator),fireEvents:fire(c.animator),speed:speed(c.animator),weight:weight(c.animator,4)});if(c.samples.length>=60)flush(c);}
function finish(reason){
 const c=current;if(!c)return;c.ended=true;
 flush(c);const cleanup={};
 try{setPos(c.pt,c.origin);getPos(c.pt,buffer);cleanup.positionError=vector(buffer).reduce((sum,v,i)=>sum+Math.abs(v-vector(c.origin)[i]),0);}catch(e){cleanup.positionError=null;cleanup.positionErrorReason=e.message;}
 try{if(live(c.animator)){setBool(c.animator,hash,c.originalFound?1:0);cleanup.foundMatches=getBool(c.animator,hash)===c.originalFound;}else cleanup.animatorDestroyed=true;}catch(e){cleanup.animatorError=e.message;}
 try{if(live(c.mesh)){setActive(c.mesh,c.originalActive?1:0);cleanup.meshMatches=active(c.mesh)===c.originalActive;}else cleanup.meshDestroyed=true;}catch(e){cleanup.meshError=e.message;}
 emit('generation_control_end',{trial:c.id,name:c.name,reason,...cleanup,events:c.events,callbacks:c.callbacks,stop:flag()});
 current=null;lastEnd=real();
}
Interceptor.attach(base.add(0x41eb80),{onEnter(a){
 const nca=a[0].add(0x18).readPointer();rows.set(nca.toString(),nca);if(current&&current.nca.equals(nca)&&live(current.mesh)&&live(current.animator))force(current);
}});
Interceptor.attach(base.add(0x41a730),{onEnter(a){if(current&&a[0].toString()===current.receiver){current.events++;emit('generation_control_animation',{trial:current.id});}}});
Interceptor.attach(base.add(0x41a870),{onEnter(a){if(current&&a[0].toString()===current.receiver){current.callbacks++;emit('generation_control_callback',{trial:current.id});}}});
Interceptor.attach(base.add(0x620800),{onEnter(){
 if(done)return;if(!started)started=frame();if(frame()-started<90)return;
 try{
  if(current){
   const c=current,age=real()-c.began;
   if(!live(c.animator)||!live(c.mesh)||!c.nca.add(0x90).readPointer().equals(c.animator)){finish('actor-model-retired');return;}
   sample(c);
   if(flag()||scale()!==1){finish('external-pause');done=true;return;}
   if(!c.settled&&age>=1){c.settled=true;c.foundAt=real();emit('generation_control_parameter_true',{trial:c.id});setBool(c.animator,hash,1);}
   if(c.settled){const elapsed=real()-c.foundAt;
    if(!c.applied&&elapsed>=0.04){c.applied=true;
     if(c.name==='far_near_before')c.targetFar=false;
     else if(c.name.includes('far'))c.targetFar=true;
     if(c.name.includes('hidden'))c.hidden=true;
     if(c.name.startsWith('early_cancel')){setBool(c.animator,hash,0);emit('generation_control_parameter_false',{trial:c.id,elapsed});}
     emit('generation_control_condition',{trial:c.id,name:c.name,elapsed,targetFar:c.targetFar,hidden:c.hidden});
    }
    if(elapsed>2){finish('elapsed');return;}
   }
   force(c);return;
  }
  if(real()-lastEnd<.6)return;
  if(index>=names.length*2){done=true;emit('generation_control_complete',{trials:index});return;}
  if(flag()||scale()!==1)return;
  let chosen=null;
  for(const [key,nca] of rows){if(used.has(key))continue;try{const animator=nca.add(0x90).readPointer(),mesh=nca.add(0xc0).readPointer().add(0x20).readPointer(),root=nca.add(0x18).readPointer();
    if(live(animator)&&live(mesh)&&live(root)&&active(mesh)&&!getBool(animator,hash)&&speed(animator)>0&&getBool(animator,femaleHash)&&!getBool(animator,sitHash)){chosen={nca,animator,mesh,root};used.add(key);break;}
   }catch(e){rows.delete(key);}}
  if(!chosen){emit('generation_control_no_actor',{remaining:names.length*2-index});done=true;return;}
  const pt=transform(player().add(0x28).readPointer()),origin=Memory.alloc(12),near=Memory.alloc(12),far=Memory.alloc(12);getPos(pt,origin);getPos(transform(chosen.root),near);Memory.copy(far,near,12);near.writeFloat(near.readFloat()+1);far.writeFloat(far.readFloat()+60);
  const name=names[index%names.length];current={...chosen,id:++index,name,pt,origin,near,far,originalActive:active(chosen.mesh),originalFound:getBool(chosen.animator,hash),began:real(),hidden:false,targetFar:name==='far_near_before',settled:false,applied:false,ended:false,samples:[],events:0,callbacks:0,receiver:chosen.nca.add(0x98).readPointer().toString()};
  emit('generation_control_begin',{trial:current.id,name,nca:chosen.nca.toString(),receiver:current.receiver,origin:vector(origin),authority:'controlled-parameter-source-real-Unity-event',originalActive:current.originalActive,originalFound:current.originalFound});
  setBool(current.animator,hash,0);force(current);
 }catch(e){emit('generation_control_error',{error:e.message});finish('error');done=true;}
}});
emit('generation_control_ready',{scope:'Two female-standing early parameter cancellation trials; two-second bounded window; live layer weight getter; refreshed relative geometry; independent cleanup. Natural observation is a separate closed session.'});
