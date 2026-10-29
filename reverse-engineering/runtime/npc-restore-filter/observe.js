// Read-only REA witness; controlled calls originate in a separate Unity Update.
const mod=Process.getModuleByName('GameAssembly.dll'),base=mod.base;
const resolve=new NativeFunction(mod.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function address(n){return resolve(Memory.allocUtf8String(n));}
function ic(n,r,a){return new NativeFunction(address(n),r,a);}
const frame=ic('UnityEngine.Time::get_frameCount()','int',[]),real=ic('UnityEngine.Time::get_realtimeSinceStartup()','float',[]);
const getPos=ic('UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)','void',['pointer','pointer']);
const getRot=ic('UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)','void',['pointer','pointer']);
function vec(p,n){return Array.from({length:n},(_,i)=>p.add(i*4).readFloat());}
function safe(fn){try{return fn();}catch{return null;}}
function items(p){const n=p.add(0x18).readS32();if(n<0||n>500)throw Error('list bound');const a=p.add(0x10).readPointer();return Array.from({length:n},(_,i)=>a.add(0x20+8*i).readPointer());}
function fields(rva){return base.add(rva).readPointer().add(0xb8).readPointer();}
function stopped(){return safe(()=>{const gm=fields(0x2d53c48).readPointer();return gm.add(0x30).readPointer().add(0x10).readU8()===1;})===true;}
function npcRecord(p){return {pointer:p.toString(),position:vec(p.add(0x10),3),rotation:vec(p.add(0x1c),4),exists:p.add(0x2c).readU8()};}
function records(){return safe(()=>items(fields(0x2d58398).add(0x48).readPointer().add(0x40).readPointer()).map(npcRecord));}
function nm(p){return safe(()=>({pointer:p.toString(),loaded:p.add(0x65).readU8(),fixed:p.add(0x68).readS32(),npcs:items(p.add(0x38).readPointer()).map(c=>({pointer:c.toString(),fixedType:c.add(0x30).readPointer().add(0x40).readPointer().add(0x58).readS32()}))}));}
function pose(p){const tr=p.add(0x10).readPointer(),pos=Memory.alloc(12),rot=Memory.alloc(16);getPos(tr,pos);getRot(tr,rot);return {pointer:p.toString(),position:vec(pos,3),rotation:vec(rot,4)};}
function emit(kind,data){send({kind,frame:frame(),real:real(),data});}
const counts={};function seq(name){return counts[name]=(counts[name]??0)+1;}
for(const [rva,name] of [[0x4320d0,'npc_apply'],[0x42f310,'npc_load']])Interceptor.attach(base.add(rva),{
 onEnter(a){this.record=stopped();if(!this.record)return;this.id=seq(name);this.p=a[0];emit(name+'_enter',{sequence:this.id,caller:this.returnAddress.sub(base).toString(),manager:nm(this.p),records:records()});},
 onLeave(){if(this.record)emit(name+'_leave',{sequence:this.id,manager:nm(this.p),records:records()});}
});
for(const [rva,name] of [[0x49cdf0,'save'],[0x49d380,'load']])Interceptor.attach(base.add(rva),{
 onEnter(a){this.record=stopped();if(!this.record)return;this.id=seq(name);emit(name+'_enter',{sequence:this.id,type:a[0].toInt32(),slot:a[1].toInt32(),isBackup:name==='save'?(a[2].toInt32()&255)!==0:null,records:records()});},
 onLeave(){if(this.record)emit(name+'_leave',{sequence:this.id,records:records()});}
});
Interceptor.attach(base.add(0x4b3d40),{onEnter(a){const caller=this.returnAddress.sub(base).toUInt32();if(caller<0x42f310||caller>=0x42f810)return;const target=a[0].add(0x20).readPointer();emit('restore_queued',{action:a[0].toString(),closure:target.toString(),record:npcRecord(target.add(0x10).readPointer()),caller:'0x'+caller.toString(16)});}});
Interceptor.attach(base.add(0x432df0),{onEnter(a){if(stopped())emit('restore_callback',{closure:a[0].toString(),record:npcRecord(a[0].add(0x10).readPointer())});}});
Interceptor.attach(base.add(0x42fe70),{onEnter(a){this.record=stopped();if(!this.record)return;this.id=seq('instantiate');emit('npc_instantiate_enter',{id:this.id,record:a[1].isNull()?null:npcRecord(a[1]),random:a[2].toInt32(),fixed:a[3].toInt32(),caller:this.returnAddress.sub(base).toString()});},onLeave(ret){if(this.record)emit('npc_instantiate_leave',{id:this.id,result:ret.toString()});}});
Interceptor.attach(base.add(0x429fa0),{onEnter(a){this.record=stopped();if(!this.record)return;this.id=seq('warp');this.p=a[0];emit('npc_warp_enter',{id:this.id,pointer:a[0].toString(),position:vec(a[1],3),rotation:vec(a[2],4),caller:this.returnAddress.sub(base).toString()});},onLeave(){if(this.record)try{emit('npc_warp_leave',{id:this.id,...pose(this.p)});}catch(e){emit('witness_error',{error:String(e)});}}});
Interceptor.attach(address('UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)'),{onEnter(a){const caller=this.returnAddress.sub(base).toUInt32();this.record=caller>=0x42f310&&caller<0x42f810;if(!this.record)return;this.bounds=vec(a[0],6);this.position=vec(a[1],3);this.caller='0x'+caller.toString(16);},onLeave(ret){if(this.record)emit('restore_bounds',{bounds:this.bounds,position:this.position,inside:(ret.toInt32()&255)!==0,caller:this.caller});}});
emit('npc_filter_ready',{pid:Process.id,path:mod.path,base:base.toString(),scope:'passive original methods, queue, callbacks and Bounds.Contains; separate managed controlled replay'});
