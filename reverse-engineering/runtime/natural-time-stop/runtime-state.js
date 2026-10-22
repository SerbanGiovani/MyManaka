// Observe guards, skill availability and native delayed models. No writes/calls into gameplay actions.
const m=Process.getModuleByName('GameAssembly.dll'),base=m.base;
function fn(o,r,a){return new NativeFunction(base.add(o),r,a);}
const resolve=new NativeFunction(m.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function get(n,t){return new NativeFunction(resolve(Memory.allocUtf8String(n)),t,[]);}
const frame=get('UnityEngine.Time::get_frameCount()','int'),time=get('UnityEngine.Time::get_time()','float'),real=get('UnityEngine.Time::get_realtimeSinceStartup()','float'),scale=get('UnityEngine.Time::get_timeScale()','float');
const ring=fn(0x4fdb10,'pointer',['pointer']),level=fn(0x48e170,'int',['int','pointer']),skill=fn(0x48da50,'bool',['int','pointer']);
function instance(r){try{return base.add(r).readPointer().add(0xb8).readPointer().readPointer();}catch(e){return ptr(0);}}
function flag(){try{return instance(0x2d53c48).add(0x30).readPointer().add(0x14).readU8();}catch(e){return null;}}
function emit(kind,data){send({kind,frame:frame(),time:time(),real:real(),data});}
function str(p){return p.isNull()?null:p.add(0x14).readUtf16String(p.add(0x10).readS32());}
let old='',calls=0,changes=0;
Interceptor.attach(base.add(0x620800),{onEnter(){
 if(calls++%10)return;
 try{
  const p=ring(ptr(0)),u=instance(0x2d58380),g=instance(0x2d53c48),camera=g.add(0x28).readPointer().add(0x38).readPointer();
  const model=p.add(0x90).readPointer();
  const state={stop:flag(),timeScale:scale(),skill17Level:level(17,ptr(0)),skill17Active:skill(17,ptr(0)),
   ringOpen:p.add(0x70).readU8(),ringLock:p.add(0x71).readU8(),click:p.add(0xe0).readU8(),
   cancelUI:u.add(0x21).readU8(),allowUI:u.add(0x22).readU8(),cameraLock:camera.add(0x28).readU8(),
   shortcut:model.isNull()?null:{item:model.add(0x14).readS32(),name:str(model.add(0x20).readPointer())}};
  const s=JSON.stringify(state);if(s!==old&&changes++<250){old=s;emit('runtime_state',state);}
 }catch(e){if(changes++<3)emit('runtime_state_error',{error:e.message});}
}});
for(const [off,kind] of [[0x504320,'shortcut_common_assignment'],[0x504480,'shortcut_skill_assignment']])Interceptor.attach(base.add(off),{onEnter(a){
 const v=a[1];emit(kind,{model:v.toString(),item:v.isNull()?null:v.add(0x14).readS32(),name:v.isNull()?null:str(v.add(0x20).readPointer())});
}});
const animating=new Map(),models=new Map();let events=0;
Interceptor.attach(base.add(0x41a730),{onEnter(a){this.thread=Process.getCurrentThreadId();animating.set(this.thread,{id:++events,receiver:a[0].toString()});},onLeave(){animating.delete(this.thread);}});
Interceptor.attach(base.add(0x4b4f50),{onEnter(a){this.event=animating.get(Process.getCurrentThreadId());this.model=a[0];},onLeave(){
 if(!this.event)return;
 const p=this.model;models.set(p.toString(),{...this.event,lastStop:flag(),lastFrame:frame()});
 emit('npc_delay_model',{...this.event,model:p.toString(),delay:p.add(0x18).readFloat(),remain:p.add(0x20).readFloat(),unscaled:p.add(0x24).readU8()});
}});
Interceptor.attach(base.add(0x4b5050),{onEnter(a){
 this.p=a[0];this.record=models.get(this.p.toString());if(!this.record)return;
 this.before=this.p.add(0x20).readFloat();this.stop=flag();
},onLeave(r){
 if(!this.record)return;const p=this.p,v=this.record,after=p.add(0x20).readFloat(),due=(r.toInt32()&255)!==0;
 if(v.lastStop!==this.stop||due||frame()-v.lastFrame>=60){
  emit('npc_delay_tick',{...v,model:p.toString(),stop:this.stop,before:this.before,after,due});v.lastFrame=frame();v.lastStop=this.stop;
 }
 if(due)models.delete(p.toString());
}});
emit('runtime_state_ready',{scope:'Original main-thread hooks; read-only getters; queue models correlated with native OnAnimBaretaSound'});
