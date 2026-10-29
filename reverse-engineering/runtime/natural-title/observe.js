// Passive native witness. No state stores, lifecycle calls, or guard overrides.
const mod=Process.getModuleByName('GameAssembly.dll'),base=mod.base;
const resolve=new NativeFunction(mod.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function ic(n,r,a){return new NativeFunction(resolve(Memory.allocUtf8String(n)),r,a);}
const frame=ic('UnityEngine.Time::get_frameCount()','int',[]),real=ic('UnityEngine.Time::get_realtimeSinceStartup()','float',[]);
const counters={},managers=new Set();const applyContexts=new Set(),applyByManager={};let applySequence=0,instantiated=0,lastPoll=-10;
function vec(p,n){return Array.from({length:n},(_,i)=>p.add(4*i).readFloat());}
function list(p){const n=p.add(0x18).readS32();if(n<0||n>2000)throw Error('list bound');const a=p.add(0x10).readPointer();return Array.from({length:n},(_,i)=>a.add(0x20+8*i).readPointer());}
function safe(f){try{return f();}catch{return null;}}
function staticFields(rva){return base.add(rva).readPointer().add(0xb8).readPointer();}
function gameState(){return staticFields(0x2d58398).add(0x48).readPointer();}
function state(){return safe(()=>{const s=gameState();if(s.isNull())return null;const records=list(s.add(0x40).readPointer());return {pointer:s.toString(),stage:s.add(0x10).readS32(),playerPosition:vec(s.add(0x180),3),playerRotation:vec(s.add(0x18c),4),npcCount:records.length,npcExisting:records.filter(p=>p.add(0x2c).readU8()).length,npcs:records.slice(0,6).map(p=>({pointer:p.toString(),exists:p.add(0x2c).readU8(),position:vec(p.add(0x10),3),rotation:vec(p.add(0x1c),4)}))};});}
function debug(){return safe(()=>{const p=staticFields(0x2d59ac8);return {force:p.add(0xb).readU8(),isDebug:p.readU8(),initialized:p.add(0xc).readU8()};});}
function manager(p){return safe(()=>({pointer:p.toString(),loaded:p.add(0x65).readU8(),initialized:p.add(0x64).readU8(),fixed:p.add(0x68).readS32(),spawn:p.add(0x6c).readS32(),live:list(p.add(0x38).readPointer()).length}));}
function context(){return {debug:debug(),state:state(),managers:Array.from(managers).map(p=>manager(ptr(p)))};}
function emit(kind,data){send({kind,frame:frame(),real:real(),data});}
function enterCount(name){counters[name]=(counters[name]??0)+1;return counters[name];}
function track(rva,name,reader){Interceptor.attach(base.add(rva),{onEnter(a){this.sequence=enterCount(name);this.extra=reader?reader.call(this,a):{};emit(name+'_enter',{sequence:this.sequence,caller:this.returnAddress.sub(base).toString(),...this.extra,...context()});},onLeave(){emit(name+'_leave',{sequence:this.sequence,...context()});}});}
track(0x4879f0,'debug_cctor');track(0x4869f0,'debug_initialize');
track(0x49d380,'save_load',a=>({type:a[0].toInt32(),slot:a[1].toInt32()}));
track(0x49cdf0,'save_write',a=>({type:a[0].toInt32(),slot:a[1].toInt32(),isBackup:(a[2].toInt32()&255)!==0}));
track(0x4cae80,'pc_manual_save');
track(0x4ba110,'save_preprocess',a=>({isSystem:(a[0].toInt32()&255)!==0,slot:a[1].toInt32(),isBackup:(a[2].toInt32()&255)!==0}));
track(0x4e52b0,'title_manual_category');
track(0x4e5180,'title_slot',a=>({type:a[1].toInt32(),slot:a[2].toInt32()}));
track(0x4780e0,'springboard');track(0x495dc0,'ingame_start');
track(0x498af0,'startup_delayed');
for(const [rva,name] of [[0x42f130,'npc_initialize'],[0x42f300,'npc_stage'],[0x42f310,'npc_load'],[0x42f810,'npc_repop']])track(rva,name,a=>{managers.add(a[0].toString());return {manager:manager(a[0])};});
Interceptor.attach(base.add(0x4320d0),{onEnter(a){this.p=a[0];managers.add(a[0].toString());this.sequence=++applySequence;this.before={manager:manager(a[0]),state:state()};const key=a[0]+':'+this.before.state?.stage+':'+this.before.state?.npcCount+':'+this.before.manager?.loaded;this.record=this.sequence<=4||!applyContexts.has(key)||this.before.manager?.loaded===1;applyContexts.add(key);applyByManager[a[0].toString()]=(applyByManager[a[0].toString()]??0)+1;if(this.record)emit('npc_apply_enter',{sequence:this.sequence,...this.before});},onLeave(){const after={manager:manager(this.p),state:state()};if(this.record||JSON.stringify(this.before)!==JSON.stringify(after))emit('npc_apply_leave',{sequence:this.sequence,...after});}});
Interceptor.attach(base.add(0x42fe70),{onEnter(a){const seq=++instantiated;enterCount('npc_instantiate');if(seq<=50||!a[1].isNull())emit('npc_instantiate',{sequence:seq,manager:a[0].toString(),record:a[1].toString(),random:a[2].toInt32(),fixed:a[3].toInt32(),caller:this.returnAddress.sub(base).toString()});}});
Interceptor.attach(base.add(0x6455f0),{onEnter(a){emit('player_warp',{player:a[0].toString(),position:vec(a[1],3),rotation:vec(a[2],4),caller:this.returnAddress.sub(base).toString()});}});
Interceptor.attach(base.add(0x4a7190),{onEnter(a){emit('stage_transition',{target:a[1].toInt32(),caller:this.returnAddress.sub(base).toString(),...context()});}});
Interceptor.attach(base.add(0x620800),{onEnter(){const now=real();if(now-lastPoll<30)return;lastPoll=now;emit('guard_poll',{counters:{...counters,npc_apply:applySequence},applyByManager:{...applyByManager},...context()});}});
emit('natural_title_ready',{pid:Process.id,path:mod.path,base:base.toString(),scope:'passive original native entry/return; first snapshot per manager/stage/list-count context; no setters or replay'});
