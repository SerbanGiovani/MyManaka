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
// Additional read-only links from the original ring/input/action path.
const speedFn=new NativeFunction(resolve(Memory.allocUtf8String('UnityEngine.Animator::get_speed()')),'float',['pointer']);
function speed(n){try{return speedFn(n.add(0x30).readPointer().add(0x90).readPointer());}catch(e){return null;}}
Interceptor.attach(base.add(0x42a720),{onEnter(a){this.n=a[0];emit('npc_speed_before',{npc:this.n.toString(),speed:speed(this.n),cache:this.n.add(0x74).readFloat()});},onLeave(){emit('npc_speed_after',{npc:this.n.toString(),speed:speed(this.n),cache:this.n.add(0x74).readFloat()});}});
Interceptor.attach(base.add(0x620800),{onEnter(a){this.r=a[0];},onLeave(){try{const d=this.r.add(0x20).readPointer();if(d.add(0x36).readU8())emit('input_time_stop',{resolver:this.r.toString(),input:d.toString()});}catch(e){}}});
Interceptor.attach(base.add(0x627a90),{onEnter(a){if(a[1].toInt32()===7)emit('change_action_time_stop',{playerAction:a[0].toString(),action:7});}});
for(const [rva,name] of [[0x501d40,'ring_open'],[0x504320,'ring_command_0'],[0x504480,'ring_command_1'],[0x505330,'ring_state']])Interceptor.attach(base.add(rva),{onEnter(a){emit(name,{object:a[0].toString(),arg1:a[1].toInt32()});}});
Interceptor.attach(base.add(0x3cc690),{onLeave(r){try{const s=r.add(0x14).readUtf16String(r.add(0x10).readS32());if(!s.replace(/\//g,'\\').toLowerCase().startsWith('e:\\manakarea-naturalgameplay\\'))emit('unexpected_es3_path',{path:s});}catch(e){}}});
send({kind:'natural_links_ready'});
