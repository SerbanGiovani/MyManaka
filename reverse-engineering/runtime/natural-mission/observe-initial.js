// Passive original native witness. No writes or game-method replay.
const mod=Process.getModuleByName('GameAssembly.dll'),base=mod.base;
const resolve=new NativeFunction(mod.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function ic(n,r,a){return new NativeFunction(resolve(Memory.allocUtf8String(n)),r,a);}
const frame=ic('UnityEngine.Time::get_frameCount()','int',[]),real=ic('UnityEngine.Time::get_realtimeSinceStartup()','float',[]);
function safe(fn){try{return fn();}catch{return null;}}
function fields(r){return base.add(r).readPointer().add(0xb8).readPointer();}
function dictionary(p,key,kind){if(p.isNull())return null;const n=p.add(0x20).readS32(),a=p.add(0x18).readPointer();if(n<0||n>20000||a.isNull())return null;for(let i=0;i<n;i++){const e=a.add(0x20+i*16);if(e.add(4).readS32()>=-1&&e.add(8).readS32()===key)return kind==='float'?e.add(12).readFloat():e.add(12).readS32();}return null;}
function state(){return safe(()=>{const s=fields(0x2d58398).add(0x48).readPointer();if(s.isNull())return null;return {pointer:s.toString(),stage:s.add(0x10).readS32(),rp:s.add(0x1e0).readDouble(),exp:s.add(0x1e8).readS32(),pending:s.add(0x1f0).readDouble(),total:s.add(0x138).readDouble(),target:{id:100000,progress:dictionary(s.add(0x100).readPointer(),100000,'float'),earned:dictionary(s.add(0x110).readPointer(),100000,'float'),achieved:dictionary(s.add(0xf0).readPointer(),100000,'int')}};});}
function mission(p){return safe(()=>{const r=p.add(0x28).readPointer();return {pointer:p.toString(),id:r.add(0x50).readS32(),stage:r.add(0x54).readS32(),satisfy:p.add(0x30).readFloat(),done:p.add(0x3d).readU8()!==0};});}
function emit(kind,data){send({kind,frame:frame(),real:real(),data});}
let last={},oneTime=0,continuous=0,updates=0;
Interceptor.attach(base.add(0x478b40),{onEnter(a){this.p=a[0];this.before=mission(a[0]);},onLeave(){const m=mission(this.p);if(!m||m.id!==100000)return;updates++;const bucket=Math.floor(m.satisfy*20);const key=m.pointer+':'+bucket+':'+m.done;if(key!==last.key){last.key=key;emit('target_progress',{mission:m,before:this.before,state:state(),updates,oneTime,continuous});}}});
Interceptor.attach(base.add(0x4796f0),{onEnter(a){const m=mission(a[0]);if(!m||m.id!==100000)return;const caller=this.returnAddress.sub(base).toString();if(caller==='0x479178'){oneTime++;emit('target_one_time',{mission:m,caller,state:state(),count:oneTime});}else continuous++;}});
for(const [rva,name] of [[0x49cdf0,'save_write'],[0x49d380,'save_load'],[0x4c8760,'result_open'],[0x4c6540,'result_initialize'],[0x4c84d0,'result_ok1'],[0x4c85e0,'result_ok2'],[0x491be0,'mission_achieve'],[0x4a7190,'stage_transition'],[0x4cae80,'pc_save']])Interceptor.attach(base.add(rva),{onEnter(a){this.sequence={caller:this.returnAddress.sub(base).toString(),arg0:a[0].toString(),arg1:a[1].toString(),arg2:a[2].toString(),state:state()};emit(name+'_enter',this.sequence);},onLeave(){emit(name+'_leave',{...this.sequence,state:state(),updates,oneTime,continuous});}});
function str(p){if(p.isNull())return null;const n=p.add(0x10).readS32();return {text:p.add(0x14).readUtf16String(Math.min(n,16000)),length:n,truncated:n>16000};}
Interceptor.attach(base.add(0x1ef9c40),{onEnter(a){if([0,1,4].includes(a[2].toInt32()))emit('engine_error',{type:a[2].toInt32(),message:str(a[0]),stack:str(a[1])});}});
emit('natural_mission_ready',{pid:Process.id,path:mod.path,scope:'passive observation only; mission id100000 progress sampled in 5% buckets; no native writes/replay; complete high-frequency totals at lifecycle boundaries'});
