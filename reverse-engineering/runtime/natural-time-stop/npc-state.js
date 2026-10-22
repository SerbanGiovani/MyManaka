// Snapshot the exact receiver fields when original TimeStopEvent is delivered.
const m=Process.getModuleByName('GameAssembly.dll'),base=m.base;
const resolve=new NativeFunction(m.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function icall(n,t,a){return new NativeFunction(resolve(Memory.allocUtf8String(n)),t,a);}
const frame=icall('UnityEngine.Time::get_frameCount()','int',[]),time=icall('UnityEngine.Time::get_time()','float',[]),real=icall('UnityEngine.Time::get_realtimeSinceStartup()','float',[]);
const speed=icall('UnityEngine.Animator::get_speed()','float',['pointer']);
const enabled=icall('UnityEngine.Behaviour::get_enabled()','bool',['pointer']);
let calls=0;
function emit(kind,n,id){
 const a=n.add(0x30).readPointer().add(0x90).readPointer();
 send({kind,frame:frame(),time:time(),real:real(),data:{id,npc:n.toString(),distance:n.add(0x24).readFloat(),display:n.add(0x7c).readU8(),cache:n.add(0x74).readFloat(),speed:speed(a),animatorEnabled:enabled(a)}});
}
Interceptor.attach(base.add(0x42a720),{onEnter(a){this.n=a[0];this.id=++calls;emit('npc_delivery_before',this.n,this.id);},onLeave(){emit('npc_delivery_after',this.n,this.id);}});
send({kind:'npc_state_ready',scope:'Read-only callback entry/exit; controller PlayerDistance is its last native sample'});
