// Entry-only passive native witness. Controlled invocations are Unity-thread C#.
const mod=Process.getModuleByName('GameAssembly.dll'),base=mod.base;
const resolve=new NativeFunction(mod.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function ic(n,r,a){return new NativeFunction(resolve(Memory.allocUtf8String(n)),r,a);}
const frame=ic('UnityEngine.Time::get_frameCount()','int',[]),real=ic('UnityEngine.Time::get_realtimeSinceStartup()','float',[]);
function emit(kind,data){send({kind,frame:frame(),real:real(),data});}
function str(p){if(p.isNull())return null;const n=p.add(0x10).readS32();return {text:p.add(0x14).readUtf16String(Math.min(n,16000)),length:n,truncated:n>16000};}
for(const [rva,kind] of [[0x49cdf0,'native_save_enter'],[0x49d380,'native_load_enter']])Interceptor.attach(base.add(rva),{onEnter(a){emit(kind,{type:a[0].toInt32(),slot:a[1].toInt32(),backup:kind==='native_save_enter'?a[2].toInt32():null,caller:this.returnAddress.sub(base).toString()});}});
Interceptor.attach(base.add(0x1ef9c40),{onEnter(a){const t=a[2].toInt32();if([0,1,4].includes(t))emit('engine_error',{type:t,message:str(a[0]),stack:str(a[1])});}});
emit('full_save_ready',{pid:Process.id,path:mod.path,scope:'entry-only passive native witness; no target writes or calls of game methods'});
