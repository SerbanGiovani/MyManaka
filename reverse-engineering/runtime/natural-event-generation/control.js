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
const hash=base.add(0x2d59ea8).readPointer().add(0xb8).readPointer().add(0x24).readS32();
const rows=new Map(),used=new Set(),buffer=Memory.alloc(12);let current=null,index=0,started=0,lastEnd=0,done=false;
const names=['near_baseline','hidden_before_near','near_far_before','far_near_before','hidden_far_before','early_cancel','early_cancel_hidden_far'];
function emit(kind,data){send({kind,frame:frame(),real:real(),data});}
function live(p){return !p.isNull()&&!p.add(0x10).readPointer().isNull();}
function flag(){return base.add(0x2d53c48).readPointer().add(0xb8).readPointer().readPointer().add(0x30).readPointer().add(0x14).readU8();}
function player(){return base.add(0x2d58378).readPointer().add(0xb8).readPointer().readPointer().add(0x40).readPointer();}
function force(c){if(c.ended)return;setPos(c.pt,c.targetFar?c.far:c.near);setActive(c.mesh,c.hidden?0:1);}
function finish(reason){
 const c=current;if(!c)return;c.ended=true;
 try{setBool(c.animator,hash,c.originalFound?1:0);setPos(c.pt,c.origin);setActive(c.mesh,c.originalActive?1:0);getPos(c.pt,buffer);let error=0;for(let i=0;i<3;i++)error+=Math.abs(buffer.add(i*4).readFloat()-c.origin.add(i*4).readFloat());emit('generation_control_end',{trial:c.id,name:c.name,reason,positionError:error,meshMatches:active(c.mesh)===c.originalActive,foundMatches:getBool(c.animator,hash)===c.originalFound,stop:flag()});}
 catch(e){emit('generation_control_cleanup_error',{trial:c.id,error:e.message});done=true;}
 current=null;lastEnd=real();
}
Interceptor.attach(base.add(0x41eb80),{onEnter(a){
 const nca=a[0].add(0x18).readPointer();rows.set(nca.toString(),nca);if(current&&current.nca.equals(nca))force(current);
}});
Interceptor.attach(base.add(0x620800),{onEnter(){
 if(done)return;if(!started)started=frame();if(frame()-started<90)return;
 try{
  if(current){
   const c=current,age=real()-c.began;
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
    if(elapsed>6){finish('elapsed');return;}
   }
   force(c);return;
  }
  if(real()-lastEnd<.6)return;
  if(index>=names.length*2){done=true;emit('generation_control_complete',{trials:index});return;}
  if(flag()||scale()!==1)return;
  let chosen=null;
  for(const [key,nca] of rows){if(used.has(key))continue;try{const animator=nca.add(0x90).readPointer(),mesh=nca.add(0xc0).readPointer().add(0x20).readPointer(),root=nca.add(0x18).readPointer();
    if(live(animator)&&live(mesh)&&live(root)&&!getBool(animator,hash)&&speed(animator)>0){chosen={nca,animator,mesh,root};used.add(key);break;}
   }catch(e){rows.delete(key);}}
  if(!chosen){emit('generation_control_no_actor',{remaining:names.length*2-index});done=true;return;}
  const pt=transform(player().add(0x28).readPointer()),origin=Memory.alloc(12),near=Memory.alloc(12),far=Memory.alloc(12);getPos(pt,origin);getPos(transform(chosen.root),near);Memory.copy(far,near,12);near.writeFloat(near.readFloat()+1);far.writeFloat(far.readFloat()+60);
  const name=names[index%names.length];current={...chosen,id:++index,name,pt,origin,near,far,originalActive:active(chosen.mesh),originalFound:getBool(chosen.animator,hash),began:real(),hidden:false,targetFar:name==='far_near_before',settled:false,applied:false,ended:false};
  emit('generation_control_begin',{trial:current.id,name,nca:chosen.nca.toString(),receiver:chosen.nca.add(0x98).readPointer().toString(),authority:'controlled-parameter-source-real-Unity-event',originalActive:current.originalActive,originalFound:current.originalFound});
  setBool(current.animator,hash,0);force(current);
 }catch(e){emit('generation_control_error',{error:e.message});finish('error');done=true;}
}});
emit('generation_control_ready',{scope:'14 full-game parameter-triggered trials; temporary geometry/mesh changes; original native FPS and Unity AnimationEvent. Natural observation is a separate closed session.'});
