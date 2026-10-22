// Natural gameplay only: observe original callbacks and Unity getters, no writes.
const m=Process.getModuleByName('GameAssembly.dll'),base=m.base;
const resolve=new NativeFunction(m.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function icall(n,t,a){const p=resolve(Memory.allocUtf8String(n));if(p.isNull())throw Error(n);return new NativeFunction(p,t,a);}
const frame=icall('UnityEngine.Time::get_frameCount()','int',[]),time=icall('UnityEngine.Time::get_time()','float',[]),real=icall('UnityEngine.Time::get_realtimeSinceStartup()','float',[]);
const scale=icall('UnityEngine.Time::get_timeScale()','float',[]),dt=icall('UnityEngine.Time::get_deltaTime()','float',[]);
const speed=icall('UnityEngine.Animator::get_speed()','float',['pointer']),enabled=icall('UnityEngine.Behaviour::get_enabled()','bool',['pointer']);
const hierarchy=icall('UnityEngine.GameObject::get_activeInHierarchy()','bool',['pointer']);
const transform=icall('UnityEngine.GameObject::get_transform()','pointer',['pointer']);
const position=icall('UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)','void',['pointer','pointer']);
const v1=Memory.alloc(12),v2=Memory.alloc(12);
function flag(){return base.add(0x2d53c48).readPointer().add(0xb8).readPointer().readPointer().add(0x30).readPointer().add(0x14).readU8();}
function live(p){return !p.isNull()&&!p.add(0x10).readPointer().isNull();}
function actualDistance(nca){
 const player=base.add(0x2d58378).readPointer().add(0xb8).readPointer().readPointer();
 const go=player.add(0x40).readPointer().add(0x28).readPointer(),npc=nca.add(0x18).readPointer();
 if(!live(go)||!live(npc))return null;
 position(transform(go),v1);position(transform(npc),v2);
 let d=0;for(let i=0;i<3;i++){const q=v1.add(i*4).readFloat()-v2.add(i*4).readFloat();d+=q*q;}return Math.sqrt(d);
}
function state(nca){
 const npc=nca.add(0x38).readPointer(),a=nca.add(0x90).readPointer(),av=nca.add(0xc0).readPointer(),mesh=av.add(0x20).readPointer();
 if(!live(a)||!live(mesh))throw Error('destroyed Unity object');
 const fps=nca.add(0x88).readPointer(),common=fps.isNull()?ptr(0):fps.add(0x10).readPointer();
 return {npc:npc.toString(),nca:nca.toString(),receiver:nca.add(0x98).readPointer().toString(),animator:a.toString(),mesh:mesh.toString(),
  display:npc.add(0x7c).readU8(),meshActive:hierarchy(mesh),animatorEnabled:enabled(a),speed:speed(a),cache:npc.add(0x74).readFloat(),
  cachedDistance:npc.add(0x24).readFloat(),distance:actualDistance(nca),manual:common.isNull()?null:common.add(0x10).readU8(),
  fps:common.isNull()?null:common.add(0x14).readS32(),skipped:common.isNull()?null:common.add(0x24).readFloat()};
}
function emit(kind,data){send({kind,frame:frame(),time:time(),real:real(),data});}
const actors=new Map(),animators=new Map(),models=new Map(),eventStacks=new Map();let scheduler=ptr(0),sequence=0,lastFrame=-1,transitions=0,errors=0;
function observeActor(nca){
 const key=nca.toString();if(!actors.has(key))actors.set(key,{nca,old:null,updates:0,lastManual:null});
 const row=actors.get(key);row.updates++;
}
Interceptor.attach(base.add(0x41eb80),{onEnter(a){observeActor(a[0].add(0x18).readPointer());}});
Interceptor.attach(base.add(0x41ee90),{onEnter(){
 const a=this.context.rdi.toString(),row=animators.get(a);if(row){row.manualCalls=(row.manualCalls||0)+1;row.lastManual={frame:frame(),delta:this.context.rbx.add(0x24).readFloat()};}
}});
Interceptor.attach(base.add(0x41a730),{onEnter(a){
 const receiver=a[0],nca=receiver.add(0x20).readPointer(),event={id:++sequence,receiver:receiver.toString(),nca:nca.toString(),frame:frame()};
 eventStacks.set(Process.getCurrentThreadId(),event);observeActor(nca);emit('scenario_animation',event);
}});
// The ctor is called synchronously inside OnAnimBaretaSound; use the same-frame
// stack marker and original Action target to avoid relying on a native onLeave.
Interceptor.attach(base.add(0x4b4f50),{onEnter(a){
 const e=eventStacks.get(Process.getCurrentThreadId());if(!e||e.frame!==frame())return;
 const action=a[1];if(action.isNull()||action.add(0x40).readPointer().toString()!==e.receiver)return;
 const rec={...e,p:a[0],samples:0,callback:false};models.set(a[0].toString(),rec);eventStacks.delete(Process.getCurrentThreadId());
 emit('scenario_model',{...e,model:a[0].toString()});
}});
Interceptor.attach(base.add(0x41a870),{onEnter(a){
 const receiver=a[0].toString();for(const row of models.values())if(row.receiver===receiver&&!row.callback){row.callback=true;row.callbackFrame=frame();break;}
 emit('scenario_callback',{receiver});
}});
Interceptor.attach(base.add(0x4b4040),{onEnter(a){scheduler=a[0];}});
function membership(){
 const result=new Set();if(scheduler.isNull())return result;
 const list=scheduler.add(0x38).readPointer();if(list.isNull())return result;
 const items=list.add(0x10).readPointer(),size=list.add(0x18).readS32();if(size<0||size>10000)throw Error('queue size');
 for(let i=0;i<size;i++)result.add(items.add(0x20+i*8).readPointer().toString());return result;
}
Interceptor.attach(base.add(0x620800),{onEnter(){
 const f=frame();if(f===lastFrame)return;lastFrame=f;
 try{
  const stop=flag(),ts=scale(),queue=membership();
  for(const [key,row] of actors){
   try{
    const s=state(row.nca);animators.set(s.animator,row);
    const signature=JSON.stringify([s.meshActive,s.display,s.animatorEnabled,s.manual,s.fps,stop,ts]);
    if(row.old!==signature&&transitions++<2500){row.old=signature;emit('scenario_actor_transition',{...s,stop,timeScale:ts});}
    row.state=s;
   }catch(e){actors.delete(key);emit('scenario_actor_retired',{nca:key,reason:e.message});}
  }
  for(const [key,row] of models){
   const present=queue.has(key),actor=actors.get(row.nca);
   if(!present){if(row.samples>0){emit('scenario_queue_removed',{id:row.id,model:key,receiver:row.receiver,callback:row.callback});models.delete(key);}continue;}
   if(row.samples++>=2400){emit('scenario_trace_limit',{id:row.id});models.delete(key);continue;}
   emit('scenario_queue_sample',{id:row.id,model:key,receiver:row.receiver,present:true,stop,timeScale:ts,delta:dt(),
    remaining:row.p.add(0x20).readFloat(),unscaled:row.p.add(0x24).readU8(),actor:actor?.state||null,manual:actor?.lastManual||null});
  }
 }catch(e){if(errors++<10)emit('scenario_error',{error:e.message});}
}});
emit('scenario_ready',{scope:'No state writes. Queue membership checked before model read; geometry via original getters; observation caps explicit.'});
