// Minimal entry-only witness: no native return hooks, throw-helper or Unity ICall hooks.
const mod=Process.getModuleByName('GameAssembly.dll'),base=mod.base;
const resolve=new NativeFunction(mod.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function ic(n,r,a){return new NativeFunction(resolve(Memory.allocUtf8String(n)),r,a);}
const frame=ic('UnityEngine.Time::get_frameCount()','int',[]),real=ic('UnityEngine.Time::get_realtimeSinceStartup()','float',[]);
const managers=new Set(),actions=new Set(),closures=new Set(),current={};
function safe(f){try{return f();}catch(e){return {error:String(e)};}}
function manager(p){return safe(()=>({pointer:p.toString(),native:p.add(0x10).readPointer().toString(),initialized:p.add(0x64).readU8(),loaded:p.add(0x65).readU8()}));}
function model(p){return safe(()=>({pointer:p.toString(),action:p.add(0x10).readPointer().toString(),delay:p.add(0x18).readFloat(),remaining:p.add(0x20).readFloat(),unscaled:p.add(0x24).readU8()}));}
function emit(kind,data){send({kind,frame:frame(),real:real(),thread:Process.getCurrentThreadId(),data});}
function context(){const c=current[Process.getCurrentThreadId()];return c&&c.frame===frame()?c:null;}
function string(p){if(p.isNull())return null;const n=p.add(0x10).readS32();if(n<0||n>1000000)return {invalidLength:n};return {text:p.add(0x14).readUtf16String(Math.min(n,24000)),length:n,truncated:n>24000};}
Interceptor.attach(base.add(0x42f310),{onEnter(a){managers.add(a[0].toString());emit('restore_enter',{manager:manager(a[0])});}});
Interceptor.attach(base.add(0x4b3d40),{onEnter(a){const caller=this.returnAddress.sub(base).toUInt32();if(caller<0x42f310||caller>=0x42f810)return;const target=a[0].add(0x20).readPointer();actions.add(a[0].toString());closures.add(target.toString());emit('restore_queued',{action:a[0].toString(),closure:target.toString(),record:target.add(0x10).readPointer().toString(),manager:manager(target.add(0x18).readPointer()),caller:'0x'+caller.toString(16)});}});
Interceptor.attach(base.add(0x4b4f50),{onEnter(a){if(actions.has(a[1].toString()))emit('time_model_constructor',{pointer:a[0].toString(),action:a[1].toString()});}});
Interceptor.attach(base.add(0x4b5050),{onEnter(a){if(actions.has(a[0].add(0x10).readPointer().toString()))emit('time_invoke_enter',{model:model(a[0])});}});
Interceptor.attach(base.add(0x432df0),{onEnter(a){if(!closures.has(a[0].toString()))return;const c={closure:a[0].toString(),frame:frame(),manager:a[0].add(0x18).readPointer().toString()};current[Process.getCurrentThreadId()]=c;emit('restore_callback_enter',{...c,record:a[0].add(0x10).readPointer().toString(),manager:manager(a[0].add(0x18).readPointer())});}});
Interceptor.attach(base.add(0x42fe70),{onEnter(a){if(managers.has(a[0].toString()))emit('instantiate_enter',{manager:manager(a[0]),record:a[1].toString(),caller:this.returnAddress.sub(base).toString()});else delete current[Process.getCurrentThreadId()];}});
Interceptor.attach(base.add(0x9f1050),{onEnter(a){const c=context(),caller=this.returnAddress.sub(base).toUInt32();if(c&&caller>=0x42fe70&&caller<0x430400)emit('npc_clone_enter',{...c,source:a[0].toString(),parent:a[1].toString(),caller:'0x'+caller.toString(16)});}});
Interceptor.attach(base.add(0x42f1a0),{onEnter(a){if(managers.has(a[0].toString()))emit('manager_destroy_enter',manager(a[0]));}});
Interceptor.attach(base.add(0x1ef9c40),{onEnter(a){const type=a[2].toInt32();if(type!==0&&type!==1&&type!==4)return;emit('engine_error',{type,condition:safe(()=>string(a[0])),stack:safe(()=>string(a[1])),context:context()});}});
emit('interruption_v3_ready',{pid:Process.id,path:mod.path,base:base.toString(),scope:'entry-only original queue/model/callback/instantiate/clone/destruction and Application.CallLogCallback; no return hooks or throw/Icall hooks'});
