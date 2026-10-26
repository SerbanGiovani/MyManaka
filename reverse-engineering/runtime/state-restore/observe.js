// Passive REA witness. Controlled calls originate in a separate managed Update,
// so the observer does not depend on nested calls from its own callback.
const mod=Process.getModuleByName('GameAssembly.dll'),base=mod.base;
const resolve=new NativeFunction(mod.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function ic(n,r,a){return new NativeFunction(resolve(Memory.allocUtf8String(n)),r,a);}
const frame=ic('UnityEngine.Time::get_frameCount()','int',[]),real=ic('UnityEngine.Time::get_realtimeSinceStartup()','float',[]);
const getPos=ic('UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)','void',['pointer','pointer']);
const getRot=ic('UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)','void',['pointer','pointer']);
function vec(p,n){return Array.from({length:n},(_,i)=>p.add(4*i).readFloat());}
function npcRecord(p){return {pointer:p.toString(),position:vec(p.add(0x10),3),rotation:vec(p.add(0x1c),4),exists:p.add(0x2c).readU8()};}
function npcPose(p){const tr=p.add(0x10).readPointer(),pos=Memory.alloc(12),rot=Memory.alloc(16);getPos(tr,pos);getRot(tr,rot);return {pointer:p.toString(),position:vec(pos,3),rotation:vec(rot,4)};}
function emit(kind,data){send({kind,frame:frame(),real:real(),data});}
let load=0,save=0,warp=0,instantiate=0,drop=0;
for(const [rva,name] of [[0x49cdf0,'save'],[0x49d380,'load']])Interceptor.attach(base.add(rva),{onEnter(a){this.name=name;this.seq=name==='save'?++save:++load;emit('native_'+name+'_enter',{sequence:this.seq,type:a[0].toInt32(),slot:a[1].toInt32()});},onLeave(){emit('native_'+this.name+'_leave',{sequence:this.seq});}});
for(const [rva,name] of [[0x4320d0,'npc_apply'],[0x42f310,'npc_load'],[0x488de0,'reserve_apply'],[0x48aa90,'drop_activate']])Interceptor.attach(base.add(rva),{onEnter(a){this.p=a[0];emit('native_'+name+'_enter',{pointer:a[0].toString(),caller:this.returnAddress.sub(base).toString()});},onLeave(){emit('native_'+name+'_leave',{pointer:this.p.toString()});}});
Interceptor.attach(base.add(0x42fe70),{onEnter(a){this.id=++instantiate;this.record=a[1];if(instantiate<=60)emit('native_npc_instantiate',{id:this.id,record:a[1].isNull()?null:npcRecord(a[1]),random:a[2].toInt32(),fixed:a[3].toInt32(),caller:this.returnAddress.sub(base).toString()});}});
Interceptor.attach(base.add(0x429fa0),{onEnter(a){this.p=a[0];this.id=++warp;if(warp<=60)emit('native_npc_warp_enter',{id:this.id,pointer:a[0].toString(),position:vec(a[1],3),rotation:vec(a[2],4),caller:this.returnAddress.sub(base).toString()});},onLeave(){if(this.id<=60)try{emit('native_npc_warp_leave',{id:this.id,...npcPose(this.p)});}catch(e){emit('witness_error',{at:'warp',error:e.stack});}}});
Interceptor.attach(base.add(0x488f70),{onEnter(a){emit('native_drop_enter',{id:++drop,position:vec(a[1],3),rotation:vec(a[2],4),item:a[3].toInt32(),caller:this.returnAddress.sub(base).toString()});}});
Interceptor.attach(base.add(0x489550),{onEnter(a){emit('native_reserve_enter',{item:a[1].toInt32(),stage:a[2].toInt32(),caller:this.returnAddress.sub(base).toString()});}});
emit('witness_ready',{pid:Process.id,module:mod.path,base:base.toString(),scope:'passive native entry/return; separate managed controlled fixture; no writes'});
