// Passive native witness. Managed Unity-thread runner owns all controlled calls.
const mod=Process.getModuleByName('GameAssembly.dll'),base=mod.base;
const resolve=new NativeFunction(mod.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function ic(n,r,a){return new NativeFunction(resolve(Memory.allocUtf8String(n)),r,a);}
const frame=ic('UnityEngine.Time::get_frameCount()','int',[]),real=ic('UnityEngine.Time::get_realtimeSinceStartup()','float',[]);
const getGO=ic('UnityEngine.Component::get_gameObject()','pointer',['pointer']),getTR=ic('UnityEngine.Component::get_transform()','pointer',['pointer']);
const getPos=ic('UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)','void',['pointer','pointer']),getRot=ic('UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)','void',['pointer','pointer']);
const active=ic('UnityEngine.GameObject::get_activeSelf()','bool',['pointer']);
function fields(rva){return base.add(rva).readPointer().add(0xb8).readPointer();}
function safe(fn){try{return fn();}catch(e){return {error:String(e)};}}
function stopped(){return safe(()=>fields(0x2d53c48).readPointer().add(0x30).readPointer().add(0x10).readU8()===1)===true;}
function vec(p,n){return Array.from({length:n},(_,i)=>p.add(4*i).readFloat());}
function object(p){if(p.isNull())return null;const go=getGO(p),tr=getTR(p),v=Memory.alloc(12),q=Memory.alloc(16);getPos(tr,v);getRot(tr,q);return {pointer:p.toString(),gameObject:go.toString(),active:active(go),position:vec(v,3),rotation:vec(q,4)};}
function prefab(item){return safe(()=>{const sm=fields(0x2d58238).readPointer(),arr=sm.add(item<10000?0x320:0x328).readPointer(),i=item<10000?item:Math.floor(item/100)-100;return arr.add(0x20+8*i).readPointer().toString();});}
function emit(kind,data){send({kind,frame:frame(),real:real(),thread:Process.getCurrentThreadId(),data});}
const stack=[],counts={};function seq(k){return counts[k]=(counts[k]??0)+1;}
for(const [rva,name] of [[0x49cdf0,'save'],[0x49d380,'load'],[0x48aa90,'restore'],[0x488f70,'drop'],[0x4897a0,'hide']])Interceptor.attach(base.add(rva),{
 onEnter(a){this.record=stopped();if(!this.record)return;this.id=seq(name);emit(name+'_enter',{sequence:this.id,caller:this.returnAddress.sub(base).toString(),item:name==='drop'?a[3].toInt32():name==='hide'?a[1].toInt32():null,type:name==='save'||name==='load'?a[0].toInt32():null,slot:name==='save'||name==='load'?a[1].toInt32():null,isBackup:name==='save'?(a[2].toInt32()&255)!==0:null});},
 onLeave(){if(this.record)emit(name+'_leave',{sequence:this.id});}
});
Interceptor.attach(base.add(0x488a50),{onEnter(a){this.record=stopped();if(!this.record)return;this.id=seq('cache');this.item=a[1].toInt32();stack.push(this.id);emit('cache_enter',{id:this.id,manager:a[0].toString(),cache:a[0].add(0x10).readPointer().toString(),item:this.item,prefab:prefab(this.item),caller:this.returnAddress.sub(base).toString()});},onLeave(ret){if(!this.record)return;emit('cache_leave',{id:this.id,item:this.item,result:safe(()=>object(ret))});stack.pop();}});
Interceptor.attach(base.add(0x9f1050),{onEnter(a){this.record=stack.length>0;if(!this.record)return;this.cache=stack.at(-1);emit('clone_enter',{cache_id:this.cache,source:a[0].toString(),parent:a[1].toString(),caller:this.returnAddress.sub(base).toString()});},onLeave(ret){if(this.record)emit('clone_leave',{cache_id:this.cache,result:ret.toString()});}});
Interceptor.attach(base.add(0x459880),{onEnter(a){this.record=stack.length>0;if(!this.record)return;this.cache=stack.at(-1);this.p=a[0];this.item=a[1].toInt32();emit('controller_init_enter',{cache_id:this.cache,item:this.item,pointer:a[0].toString()});},onLeave(){if(this.record)emit('controller_init_leave',{cache_id:this.cache,item:this.item,result:safe(()=>object(this.p))});}});
for(const rva of [0x1438cf0,0x1439090,0x1433680,0x1433c90,0x1ef2610,0x1ef26f0,0x1ef2d90])Interceptor.attach(base.add(rva),{onEnter(){if(stopped())emit('asset_load_during_fixture',{rva:'0x'+rva.toString(16),caller:this.returnAddress.sub(base).toString()});}});
emit('drop_cache_ready',{pid:Process.id,path:mod.path,base:base.toString(),asset_load_monitors:['0x1438cf0','0x1439090','0x1433680','0x1433c90','0x1ef2610','0x1ef26f0','0x1ef2d90'],scope:'passive manager cache/clone/controller initialization; asset API entry monitors during explicit fixtures'});
