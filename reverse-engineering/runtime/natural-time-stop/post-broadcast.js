// Read each receiver on entry, then again when the original producer returns.
// Does not depend on the missing NPC onLeave callbacks. Never writes game state.
const m=Process.getModuleByName('GameAssembly.dll'),base=m.base;
const resolve=new NativeFunction(m.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function icall(n,t,a){return new NativeFunction(resolve(Memory.allocUtf8String(n)),t,a);}
const frame=icall('UnityEngine.Time::get_frameCount()','int',[]),time=icall('UnityEngine.Time::get_time()','float',[]),real=icall('UnityEngine.Time::get_realtimeSinceStartup()','float',[]);
const speed=icall('UnityEngine.Animator::get_speed()','float',['pointer']);
const enabled=icall('UnityEngine.Behaviour::get_enabled()','bool',['pointer']);
function flag(){return base.add(0x2d53c48).readPointer().add(0xb8).readPointer().readPointer().add(0x30).readPointer().add(0x14).readU8();}
function read(n){const a=n.add(0x30).readPointer().add(0x90).readPointer();return {npc:n.toString(),distance:n.add(0x24).readFloat(),display:n.add(0x7c).readU8(),cache:n.add(0x74).readFloat(),speed:speed(a),animatorEnabled:enabled(a)};}
const active=new Map();let seq=0;
Interceptor.attach(base.add(0x6292f0),{onEnter(){
 this.thread=Process.getCurrentThreadId();this.batch={id:++seq,frame:frame(),time:time(),real:real(),before:flag(),rows:[]};active.set(this.thread,this.batch);
},onLeave(){
 const b=this.batch;b.after=flag();b.endReal=real();
 for(const row of b.rows){try{row.after=read(ptr(row.before.npc));}catch(e){row.error=e.message;}}
 send({kind:'npc_post_broadcast',frame:frame(),time:time(),real:real(),data:b});active.delete(this.thread);
}});
Interceptor.attach(base.add(0x42a720),{onEnter(a){const b=active.get(Process.getCurrentThreadId());if(b){try{b.rows.push({before:read(a[0])});}catch(e){b.rows.push({error:e.message});}}}});
send({kind:'post_broadcast_ready',scope:'Before NPC callback and after original outer producer; no NPC exit inference'});
