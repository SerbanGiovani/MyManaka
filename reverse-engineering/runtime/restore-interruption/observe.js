// Passive witness of original per-record tasks; no cancellation or state writes.
const mod=Process.getModuleByName('GameAssembly.dll'),base=mod.base;
const resolve=new NativeFunction(mod.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function ic(n,r,a){return new NativeFunction(resolve(Memory.allocUtf8String(n)),r,a);}
const frame=ic('UnityEngine.Time::get_frameCount()','int',[]),real=ic('UnityEngine.Time::get_realtimeSinceStartup()','float',[]);
const managers=new Set(),actions=new Set(),closures=new Set();let load=0,invoke=0,instantiate=0;
function safe(f){try{return f();}catch(e){return {error:String(e)};}}
function manager(p){return safe(()=>({pointer:p.toString(),native:p.add(0x10).readPointer().toString(),initialized:p.add(0x64).readU8(),loaded:p.add(0x65).readU8()}));}
function model(p){return safe(()=>({pointer:p.toString(),action:p.add(0x10).readPointer().toString(),delay:p.add(0x18).readFloat(),remaining:p.add(0x20).readFloat(),unscaled:p.add(0x24).readU8()}));}
function emit(kind,data){send({kind,frame:frame(),real:real(),data});}
Interceptor.attach(base.add(0x42f310),{onEnter(a){this.p=a[0];this.id=++load;managers.add(a[0].toString());emit('restore_enter',{id:this.id,manager:manager(a[0])});},onLeave(){emit('restore_leave',{id:this.id,manager:manager(this.p)});}});
Interceptor.attach(base.add(0x4b3d40),{onEnter(a){const caller=this.returnAddress.sub(base).toUInt32();this.record=caller>=0x42f310&&caller<0x42f810;if(!this.record)return;this.action=a[0];const target=a[0].add(0x20).readPointer();actions.add(a[0].toString());closures.add(target.toString());emit('restore_queued',{action:a[0].toString(),closure:target.toString(),record:target.add(0x10).readPointer().toString(),manager:manager(target.add(0x18).readPointer()),caller:'0x'+caller.toString(16)});}});
Interceptor.attach(base.add(0x4b4f50),{onEnter(a){this.p=a[0];this.record=actions.has(a[1].toString());},onLeave(){if(this.record)emit('time_model_created',model(this.p));}});
Interceptor.attach(base.add(0x4b5050),{onEnter(a){this.p=a[0];this.record=actions.has(a[0].add(0x10).readPointer().toString());if(this.record){this.id=++invoke;emit('time_invoke_enter',{id:this.id,model:model(this.p)});}},onLeave(ret){if(this.record)emit('time_invoke_leave',{id:this.id,result:ret.toInt32()&255,model:model(this.p)});}});
Interceptor.attach(base.add(0x432df0),{onEnter(a){this.p=a[0];this.record=closures.has(a[0].toString());if(this.record)emit('restore_callback_enter',{closure:a[0].toString(),record:a[0].add(0x10).readPointer().toString(),manager:manager(a[0].add(0x18).readPointer())});},onLeave(){if(this.record)emit('restore_callback_leave',{closure:this.p.toString()});}});
Interceptor.attach(base.add(0x42fe70),{onEnter(a){this.record=managers.has(a[0].toString());if(this.record){this.id=++instantiate;emit('instantiate_enter',{id:this.id,manager:manager(a[0]),record:a[1].toString(),caller:this.returnAddress.sub(base).toString()});}},onLeave(ret){if(this.record)emit('instantiate_leave',{id:this.id,result:ret.toString()});}});
Interceptor.attach(base.add(0x42f1a0),{onEnter(a){this.p=a[0];this.record=managers.has(a[0].toString());if(this.record)emit('manager_destroy_enter',manager(a[0]));},onLeave(){if(this.record)emit('manager_destroy_leave',manager(this.p));}});
emit('interruption_ready',{pid:Process.id,path:mod.path,base:base.toString(),scope:'original queue/model/callback/instantiate/destruction; controlled scheduler enable/disable is performed by managed fixture'});
