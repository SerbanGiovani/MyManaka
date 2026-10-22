// Authorized controlled replay in the full booted test copy. Synthetic event
// entry is explicit; this is not a claim of natural animation/input coverage.
const m=Process.getModuleByName('GameAssembly.dll'),base=m.base;
const resolve=new NativeFunction(m.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function ic(n,t,a){return new NativeFunction(resolve(Memory.allocUtf8String(n)),t,a,{traps:'all'});}
const frame=ic('UnityEngine.Time::get_frameCount()','int',[]),real=ic('UnityEngine.Time::get_realtimeSinceStartup()','float',[]);
const transform=ic('UnityEngine.GameObject::get_transform()','pointer',['pointer']);
const getPosition=ic('UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)','void',['pointer','pointer']);
const setPosition=ic('UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)','void',['pointer','pointer']);
const active=ic('UnityEngine.GameObject::get_activeSelf()','bool',['pointer']);
const setActive=ic('UnityEngine.GameObject::SetActive(System.Boolean)','void',['pointer','bool']);
const skill=new NativeFunction(base.add(0x48da50),'bool',['int','pointer']);
const toggle=new NativeFunction(base.add(0x6292f0),'void',['pointer','pointer'],{traps:'all'});
const notify=new NativeFunction(base.add(0x41a730),'void',['pointer','pointer'],{traps:'all'});
function flag(){return base.add(0x2d53c48).readPointer().add(0xb8).readPointer().readPointer().add(0x30).readPointer().add(0x14).readU8();}
function emit(kind,data){send({kind,frame:frame(),real:real(),data});}
function live(p){return !p.isNull()&&!p.add(0x10).readPointer().isNull();}
function player(){return base.add(0x2d58378).readPointer().add(0xb8).readPointer().readPointer().add(0x40).readPointer();}
const positions=new Map();let tick=0,started=0,current=null,index=0,lastEnd=0,done=false;
const names=['queue_stop','queue_hidden','queue_far_near','queue_hidden_far','queue_hidden_far_stop'];
const buffer=Memory.alloc(12),farPosition=Memory.alloc(12);let errors=0;
function locate(nca){
 const root=nca.add(0x18).readPointer(),receiver=nca.add(0x98).readPointer(),mesh=nca.add(0xc0).readPointer().add(0x20).readPointer();
 return live(root)&&live(receiver)&&live(mesh)?{root,receiver,mesh}:null;
}
function finish(reason){
 const c=current;if(!c)return;
 try{
  if(c.didStop&&flag()){toggle(c.playerReceiver,ptr(0));emit('control_resume',{trial:c.id,stop:flag()});}
  if(c.moved&&live(c.playerTransform))setPosition(c.playerTransform,c.origin);
  if(c.hidden&&live(c.mesh))setActive(c.mesh,c.originalActive);
  getPosition(c.playerTransform,buffer);let positionError=0;for(let i=0;i<3;i++)positionError+=Math.abs(buffer.add(i*4).readFloat()-c.origin.add(i*4).readFloat());
  emit('control_trial_end',{positionError,meshMatches:active(c.mesh)===c.originalActive,trial:c.id,name:c.name,reason,stop:flag(),positionRestored:c.moved,meshRestored:c.hidden});
 }catch(e){emit('control_cleanup_error',{trial:c.id,error:e.message});done=true;}
 current=null;lastEnd=real();
}
Interceptor.attach(base.add(0x41eb80),{onEnter(a){
 const nca=a[0].add(0x18).readPointer();positions.set(nca.toString(),nca);
 if(current&&current.nca.equals(nca)&&live(current.mesh)){if(current.hidden)setActive(current.mesh,0);else if(!current.applied)setActive(current.mesh,1);}
}});
Interceptor.attach(base.add(0x620800),{onEnter(){
 if(done)return;if(!started)started=frame();if(frame()-started<180)return;
 try{
  if(current){
   const c=current,age=real()-c.began;
   if(age>0.06&&!c.applied){
    c.applied=true;
    if(c.name.includes('far')){c.moved=true;setPosition(c.playerTransform,c.far);emit('control_distance_far',{trial:c.id});}
    if(c.name.includes('hidden')){c.hidden=true;setActive(c.mesh,0);emit('control_hide',{trial:c.id});}
    if(c.name.includes('stop')){if(flag())throw Error('unexpected stop before controlled toggle');toggle(c.playerReceiver,ptr(0));c.didStop=flag()===1;emit('control_stop',{trial:c.id,accepted:c.didStop});if(!c.didStop){finish('guard-rejected');return;}}
   }
   if(c.name==='queue_far_near'&&age>0.30&&!c.returned){setPosition(c.playerTransform,c.near);c.returned=true;emit('control_distance_near',{trial:c.id});}
   if(c.hidden)setActive(c.mesh,0);
   if(age>(c.didStop?2.8:1.2))finish('elapsed');
   return;
  }
  if(real()-lastEnd<0.6)return;
  if(index>=names.length*2){done=true;emit('control_complete',{trials:index});return;}
  if(flag()||(!skill(21,ptr(0))&&!skill(22,ptr(0))))return;
  let chosen=null;
  for(const [key,nca] of positions){try{const a=locate(nca);if(a&&active(a.mesh)){chosen={nca,...a};break;}else positions.delete(key);}catch(e){positions.delete(key);}}
  if(!chosen)return;
  const pca=player(),go=pca.add(0x28).readPointer(),pt=transform(go),origin=Memory.alloc(12),far=Memory.alloc(12),near=Memory.alloc(12);
  getPosition(pt,origin);getPosition(transform(chosen.root),far);Memory.copy(near,far,12);near.writeFloat(near.readFloat()+1);far.writeFloat(far.readFloat()+60);
  current={...chosen,id:++index,name:names[(index-1)%names.length],began:real(),playerTransform:pt,playerReceiver:pca.add(0x168).readPointer(),origin,far,near,
           originalActive:active(chosen.mesh),applied:false,moved:true,hidden:false,didStop:false};
  setPosition(pt,near);setActive(chosen.mesh,1);
  emit('control_trial_begin',{trial:current.id,name:current.name,receiver:current.receiver.toString(),nca:current.nca.toString(),authority:'controlled-replay',source:'Explicit original OnAnimBaretaSound invocation, not Unity AnimationEvent'});
  notify(current.receiver,ptr(0));
 }catch(e){if(errors++<10)emit('control_error',{error:e.message});finish('error');done=true;}
}});
emit('control_ready',{scope:'Two repetitions of five post-enqueue cases. Original producer toggles; temporary transform/MeshParent changes restored. No natural-input claim.'});
