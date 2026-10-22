// Read the original time-stop admission guard, never set it or invoke actions.
const m=Process.getModuleByName('GameAssembly.dll'),base=m.base;
const resolve=new NativeFunction(m.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
const frame=new NativeFunction(resolve(Memory.allocUtf8String('UnityEngine.Time::get_frameCount()')),'int',[]);
const skill=new NativeFunction(base.add(0x48da50),'bool',['int','pointer']);
function read(){const n=base.add(0x2d57a70).readPointer().add(0xb8).readPointer().readPointer();return {manager:n.toString(),maxStrange:n.isNull()?null:n.add(0x5a).readU8(),skill17:skill(17,ptr(0)),skill21:skill(21,ptr(0)),skill22:skill(22,ptr(0))};}
Interceptor.attach(base.add(0x6292f0),{onEnter(){send({kind:'scenario_producer_guard',frame:frame(),data:read()});}});
let old='',calls=0;
Interceptor.attach(base.add(0x620800),{onEnter(){if(calls++%30)return;try{const d=read(),s=JSON.stringify(d);if(s!==old){old=s;send({kind:'scenario_guard_state',frame:frame(),data:d});}}catch(e){}}});
send({kind:'scenario_guard_ready'});
