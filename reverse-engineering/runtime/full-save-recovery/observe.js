// Entry-only passive native witness. Controlled invocations are Unity-thread C#.
const mod=Process.getModuleByName('GameAssembly.dll'),base=mod.base;
const resolve=new NativeFunction(mod.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function ic(n,r,a){return new NativeFunction(resolve(Memory.allocUtf8String(n)),r,a);}
const frame=ic('UnityEngine.Time::get_frameCount()','int',[]),real=ic('UnityEngine.Time::get_realtimeSinceStartup()','float',[]);
function emit(kind,data){send({kind,frame:frame(),real:real(),data});}
function str(p){if(p.isNull())return null;const n=p.add(0x10).readS32();return {text:p.add(0x14).readUtf16String(Math.min(n,16000)),length:n,truncated:n>16000};}
let current=null,ownerThread=null;
Interceptor.attach(Process.getModuleByName('kernel32.dll').getExportByName('OutputDebugStringW'),{onEnter(a){const text=a[0].readUtf16String();if(text.startsWith('REA_RECOVERY_BEGIN:')){current=text.slice('REA_RECOVERY_BEGIN:'.length);ownerThread=Process.getCurrentThreadId();emit('case_marker_begin',{name:current,thread:ownerThread});}else if(text.startsWith('REA_RECOVERY_END:')){emit('case_marker_end',{name:current,thread:ownerThread});current=null;ownerThread=null;}}});
for(const [rva,kind] of [[0x48e170,'skill_read'],[0x48da50,'passive_read'],[0x4915a0,'item_read'],[0x491b10,'mission_read'],[0x4ba280,'copy_enter']])Interceptor.attach(base.add(rva),{onEnter(a){if(current===null||ownerThread!==Process.getCurrentThreadId())return;emit(kind,{name:current,id:kind==='copy_enter'?null:a[0].toInt32(),source:kind==='copy_enter'?str(a[0]):null,target:kind==='copy_enter'?str(a[1]):null,caller:this.returnAddress.sub(base).toString()});}});
for(const [rva,kind] of [[0x49cdf0,'native_save_enter'],[0x49d380,'native_load_enter']])Interceptor.attach(base.add(rva),{onEnter(a){emit(kind,{type:a[0].toInt32(),slot:a[1].toInt32(),backup:kind==='native_save_enter'?a[2].toInt32():null,caller:this.returnAddress.sub(base).toString()});}});
Interceptor.attach(base.add(0x1ef9c40),{onEnter(a){const t=a[2].toInt32();if([0,1,4].includes(t))emit('engine_error',{type:t,message:str(a[0]),stack:str(a[1])});}});
emit('recovery_ready',{pid:Process.id,path:mod.path,scope:'entry-only passive native witness; no target writes or calls of game methods'});
