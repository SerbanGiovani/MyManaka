// REA Frida observer; no replacements, calls into producers or writes to target memory.
const mod=Process.getModuleByName('GameAssembly.dll'), base=mod.base;
const resolve=new NativeFunction(mod.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function get(name,ret){return new NativeFunction(resolve(Memory.allocUtf8String(name)),ret,[]);}
const frame=get('UnityEngine.Time::get_frameCount()','int'),time=get('UnityEngine.Time::get_time()','float'),real=get('UnityEngine.Time::get_realtimeSinceStartup()','float');
function flag(){try{return base.add(0x2d53c48).readPointer().add(0xb8).readPointer().readPointer().add(0x30).readPointer().add(0x14).readU8();}catch(e){return null;}}
function emit(kind,data){send({kind,frame:frame(),time:time(),real:real(),data});}
const active=new Map();let sequence=0;
Interceptor.attach(base.add(0x6292f0),{
 onEnter(args){this.thread=Process.getCurrentThreadId();this.id=++sequence;active.set(this.thread,this.id);emit('producer_enter',{id:this.id,receiver:args[0].toString(),stop:flag()});},
 onLeave(){emit('producer_leave',{id:this.id,stop:flag()});active.delete(this.thread);}
});
Interceptor.attach(base.add(0x42a720),{
 onEnter(args){this.npc=args[0];emit('npc_stop_enter',{producer:active.get(Process.getCurrentThreadId())??null,npc:this.npc.toString(),stop:flag(),cache:this.npc.add(0x74).readFloat()});},
 onLeave(){emit('npc_stop_leave',{npc:this.npc.toString(),stop:flag(),cache:this.npc.add(0x74).readFloat()});}
});
Interceptor.attach(base.add(0x41a730),{onEnter(args){emit('animation_event_native',{receiver:args[0].toString()});}});
Interceptor.attach(base.add(0x41a870),{onEnter(args){emit('delayed_callback_native',{receiver:args[0].toString()});}});
send({kind:'observer_ready',module:mod.name,path:mod.path,base:base.toString()});
