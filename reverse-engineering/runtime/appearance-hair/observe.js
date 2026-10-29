// Passive entry-only witness. Explicit markers bracket controlled Unity-thread calls.
const mod=Process.getModuleByName('GameAssembly.dll'),base=mod.base;
const resolve=new NativeFunction(mod.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function ic(n,r,a){return new NativeFunction(resolve(Memory.allocUtf8String(n)),r,a);}
const frame=ic('UnityEngine.Time::get_frameCount()','int',[]),real=ic('UnityEngine.Time::get_realtimeSinceStartup()','float',[]);
let current=null,thread=null;
function emit(kind,data){send({kind,frame:frame(),real:real(),data:{name:current,...data}});}
function str(p){if(p.isNull())return null;let n=p.add(0x10).readS32();return {text:p.add(0x14).readUtf16String(Math.min(n,16000)),length:n,truncated:n>16000};}
Interceptor.attach(Process.getModuleByName('kernel32.dll').getExportByName('OutputDebugStringW'),{onEnter(a){const s=a[0].readUtf16String();if(s.startsWith('REA_HAIR_BEGIN:')){current=s.slice('REA_HAIR_BEGIN:'.length);thread=Process.getCurrentThreadId();emit('marker_begin',{thread});}else if(s.startsWith('REA_HAIR_END:')){emit('marker_end',{thread});current=null;thread=null;}}});
for(const [rva,kind] of [[0x49cdf0,'native_save'],[0x49d380,'native_load'],[0x645ed0,'player_initialize_callback'],[0x64e100,'hair_controller_initialize'],[0x64e260,'hair_controller_change'],[0x403790,'hair_initialize'],[0x403a60,'hair_change'],[0x4042f0,'hair_deferred']])Interceptor.attach(base.add(rva),{onEnter(a){if(current===null||thread!==Process.getCurrentThreadId())return;emit(kind,{pointer:a[0].toString(),caller:this.returnAddress.sub(base).toString(),hair:kind==='hair_change'?a[0].add(0x30).readS32():null});}});
Interceptor.attach(base.add(0x1ef9c40),{onEnter(a){if([0,1,4].includes(a[2].toInt32()))emit('engine_error',{type:a[2].toInt32(),message:str(a[0]),stack:str(a[1])});}});
emit('appearance_hair_ready',{pid:Process.id,path:mod.path,scope:'entry-only observation; native methods are invoked by separate managed fixture; no observer writes'});
