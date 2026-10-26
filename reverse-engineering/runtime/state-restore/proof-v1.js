// Shared runtime-invoke helper, supplied in full to REA with each probe.
const module=Process.getModuleByName('GameAssembly.dll'),base=module.base;
function exp(name,r,a){return new NativeFunction(module.getExportByName(name),r,a,{traps:'all'});}
const api={domain:exp('il2cpp_domain_get','pointer',[]),assemblies:exp('il2cpp_domain_get_assemblies','pointer',['pointer','pointer']),
 image:exp('il2cpp_assembly_get_image','pointer',['pointer']),imageName:exp('il2cpp_image_get_name','pointer',['pointer']),
 klass:exp('il2cpp_class_from_name','pointer',['pointer','pointer','pointer']),objectClass:exp('il2cpp_object_get_class','pointer',['pointer']),
 method:exp('il2cpp_class_get_method_from_name','pointer',['pointer','pointer','int']),
 invoke:exp('il2cpp_runtime_invoke','pointer',['pointer','pointer','pointer','pointer']),
 field:exp('il2cpp_class_get_field_from_name','pointer',['pointer','pointer']),
 setStatic:exp('il2cpp_field_static_set_value','void',['pointer','pointer']),
 newObject:exp('il2cpp_object_new','pointer',['pointer']),string:exp('il2cpp_string_new','pointer',['pointer']),
 root:exp('il2cpp_gchandle_new','uint',['pointer','bool']),unroot:exp('il2cpp_gchandle_free','void',['uint']),
 barrier:exp('il2cpp_gc_wbarrier_set_field','void',['pointer','pointer','pointer']),
 resolve:exp('il2cpp_resolve_icall','pointer',['pointer'])};
function utf(s){return Memory.allocUtf8String(s);}
function str(p){return p.isNull()?null:p.add(0x14).readUtf16String(p.add(0x10).readS32());}
function ic(n,r,a){const p=api.resolve(utf(n));if(p.isNull())throw Error('icall missing '+n);return new NativeFunction(p,r,a,{traps:'all'});}
const frame=ic('UnityEngine.Time::get_frameCount()','int',[]),real=ic('UnityEngine.Time::get_realtimeSinceStartup()','float',[]);
const componentGO=ic('UnityEngine.Component::get_gameObject()','pointer',['pointer']);
const goTransform=ic('UnityEngine.GameObject::get_transform()','pointer',['pointer']);
const getPosition=ic('UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)','void',['pointer','pointer']);
const getRotation=ic('UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)','void',['pointer','pointer']);
const activeSelf=ic('UnityEngine.GameObject::get_activeSelf()','bool',['pointer']);
const setActive=ic('UnityEngine.GameObject::SetActive(System.Boolean)','void',['pointer','bool']);
function instance(r){return base.add(r).readPointer().add(0xb8).readPointer().readPointer();}
function list(p){const n=p.add(0x18).readS32(),a=p.add(0x10).readPointer();if(n<0||n>2000)throw Error('list count '+n);return Array.from({length:n},(_,i)=>a.add(0x20+i*8).readPointer());}
function vector(p,n){return Array.from({length:n},(_,i)=>p.add(i*4).readFloat());}
function structValue(v){const p=Memory.alloc(v.length*4);v.forEach((x,i)=>p.add(i*4).writeFloat(x));return p;}
function integer(v){const p=Memory.alloc(4);p.writeS32(v);return p;}
function reference(p){const a=Memory.alloc(8);a.writePointer(p);return a;}
const methods=new Map(),roots=[];
function hold(p){if(!p.isNull())roots.push(api.root(p,false));return p;}
function type(image,ns,name){const k=api.klass(image,utf(ns),utf(name));if(k.isNull())throw Error('class missing '+name);return k;}
function method(k,name,count,offset){const key=k+':'+name+':'+count;if(methods.has(key))return methods.get(key);const p=api.method(k,utf(name),count);if(p.isNull())throw Error('method missing '+key);if(offset!==undefined&&!p.readPointer().equals(base.add(offset)))throw Error('native method address differs '+key);methods.set(key,p);return p;}
function call(k,obj,name,values,offset){const args=Memory.alloc(Math.max(8,values.length*8));values.forEach((p,i)=>args.add(i*8).writePointer(p));const error=Memory.alloc(8);error.writePointer(ptr(0));const value=api.invoke(method(k,name,values.length,offset),obj,args,error);if(!error.readPointer().isNull())throw Error('managed exception in '+name+' object '+error.readPointer());return value;}
function member(obj,name,values=[]){return call(api.objectClass(obj),obj,name,values);}
function emptyLike(obj){const k=api.objectClass(obj),p=hold(api.newObject(k));call(k,p,'.ctor',[]);return p;}
function writeRef(obj,offset,p){api.barrier(obj,obj.add(offset),p);}
function findImage(){const n=Memory.alloc(8),p=api.assemblies(api.domain(),n),count=n.readU64().toNumber();if(count>300)throw Error('assemblies count');for(let i=0;i<count;i++){const im=api.image(p.add(i*8).readPointer());if(api.imageName(im).readUtf8String()==='Assembly-CSharp.dll')return im;}throw Error('game image missing');}
const image=findImage();
const classes={save:type(image,'ExposureUnnoticed2.Scripts.InGame','SaveManager'),state:type(image,'ExposureUnnoticed2.Scripts.InGame','GameState')};
function log(kind,data){send({kind,frame:frame(),real:real(),data});}
function context(){const gm=instance(0x2d53c48),ir=gm.add(0x28).readPointer();return {gm,ir,stat:base.add(0x2d58398).readPointer().add(0xb8).readPointer(),temp:gm.add(0x30).readPointer(),nm:ir.add(0x50).readPointer(),dm:gm.add(0x20).readPointer(),pc:ir.add(0x30).readPointer(),stage:gm.add(0x40).readPointer().add(0x20).readS32()};}
function gameState(c){return c.stat.add(0x48).readPointer();}
const globals=[['AutoSaveTime',0,8,true],['ManualSaveTime',8,8,true],['InterruptSaveTime',0x10,8,false],['HomeSaveTime',0x18,8,false],['DifficultData',0x20,8,true],['RankData',0x28,8,true],['TotalPlayTimeData',0x30,8,true],['OptionData',0x38,8,true],['TutorialData',0x40,8,true],['GameStateData',0x48,8,true],['SaveDataSlotIndex',0x50,4,false],['IsTrial',0x54,1,false],['OptionFaceRankBias',0x58,4,false],['OptionFaceRange',0x5c,4,false],['PlayerCustomData',0x60,8,true]];
function backup(c){const saved=globals.map(([name,offset,size,isRef])=>{if(isRef)hold(c.stat.add(offset).readPointer());return {name,raw:c.stat.add(offset).readByteArray(size)};});const state=gameState(c);const scalar=[{offset:0x168,raw:state.add(0x168).readByteArray(4)},{offset:0x19c,raw:state.add(0x19c).readByteArray(4)}];const arrays=[];for(const [offset,size] of [[0,8],[8,8],[0x20,4],[0x28,4],[0x30,4]]){const p=c.stat.add(offset).readPointer();if(p.isNull())continue;const n=p.add(0x18).readU64().toNumber();if(n>1000)throw Error('array count');arrays.push({p,raw:p.add(0x20).readByteArray(n*size)});}return {saved,state,scalar,arrays,stop:c.temp.add(0x10).readU8()};}
function restoreGlobals(c,b){for(const x of b.saved){const data=Memory.alloc(x.raw.byteLength||1);data.writeByteArray(x.raw);api.setStatic(api.field(classes.state,utf(x.name)),data);}for(const x of b.scalar)b.state.add(x.offset).writeByteArray(x.raw);for(const x of b.arrays)x.p.add(0x20).writeByteArray(x.raw);c.temp.add(0x10).writeU8(b.stop);}
function snapshot(c){const s=gameState(c);return {state:s.toString(),stage:s.add(0x10).readS32(),npcCount:list(s.add(0x40).readPointer()).length,reserveCount:list(s.add(0x28).readPointer()).length,playerPosition:vector(s.add(0x180),3)};}

// Controlled main-thread SaveManager API probe; profile roots restored in finally.
const outputRoot="E:/ManakaREA-NaturalGameplay/RestoreRoundtrip/20261027-1/baseline";
let route=true,started=false,phase='armed',backupState=null,c=null;
for(const off of [0x4b9b00,0x4b9da0])Interceptor.attach(base.add(off),{onLeave(r){if(!route||r.isNull())return;const original=str(r),name=original.split(/[\\/]/).pop();if(!/^[a-zA-Z0-9_.-]+$/.test(name))throw Error('path component');const path=outputRoot+'/'+name;r.replace(api.string(utf(path)));log('restore_path',{phase,name,path});}});
for(const [off,name] of [[0x49cdf0,'SaveManager.Save'],[0x49d380,'SaveManager.Load']])Interceptor.attach(base.add(off),{onEnter(a){if(phase==='armed'||phase==='done')return;this.record=true;log('restore_native_enter',{phase,name,type:a[0].toInt32(),slot:a[1].toInt32()});},onLeave(){if(this.record)log('restore_native_leave',{phase,name});}});
Interceptor.attach(base.add(0x620800),{onEnter(){if(started)return;started=true;
 try{
  c=context();if(c.temp.add(0x14).readU8()||c.temp.add(0x11).readU8())throw Error('stop/gameover precondition');backupState=backup(c);
  c.temp.add(0x10).writeU8(1);phase='proof-save';log('restore_proof_begin',snapshot(c));
  call(classes.save,ptr(0),'Save',[integer(0),integer(0),integer(0)],0x49cdf0);
  phase='proof-load';log('restore_proof_saved',snapshot(c));
  call(classes.save,ptr(0),'Load',[integer(0),integer(0)],0x49d380);
  log('restore_proof_loaded',snapshot(c));
 }catch(e){log('restore_proof_error',{phase,error:e.stack});}
 finally{
  phase='cleanup';try{if(c&&backupState){restoreGlobals(c,backupState);log('restore_proof_cleanup',snapshot(c));}}catch(e){log('restore_proof_cleanup_error',{error:e.stack});}
  route=false;phase='done';for(const h of roots)api.unroot(h);log('restore_proof_complete',{});
 }
}});
log('restore_proof_ready',{pid:Process.id,scope:'Controlled native SaveManager.Save/Load inside a main-thread hook; isolated file paths; original global roots and two save-mutated scalars restored.'});
