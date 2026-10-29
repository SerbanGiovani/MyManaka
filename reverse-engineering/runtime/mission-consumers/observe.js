// Passive entry-only witness. Explicit markers bracket controlled Unity-thread calls.
const mod=Process.getModuleByName('GameAssembly.dll'),base=mod.base;
const resolve=new NativeFunction(mod.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function ic(n,r,a){return new NativeFunction(resolve(Memory.allocUtf8String(n)),r,a);}
const frame=ic('UnityEngine.Time::get_frameCount()','int',[]),real=ic('UnityEngine.Time::get_realtimeSinceStartup()','float',[]);
let current=null,thread=null;
function emit(kind,data){send({kind,frame:frame(),real:real(),data:{name:current,...data}});}
function str(p){if(p.isNull())return null;let n=p.add(0x10).readS32();return {text:p.add(0x14).readUtf16String(Math.min(n,16000)),length:n,truncated:n>16000};}
Interceptor.attach(Process.getModuleByName('kernel32.dll').getExportByName('OutputDebugStringW'),{onEnter(a){const s=a[0].readUtf16String();if(s.startsWith('REA_MISSION_BEGIN:')){current=s.slice('REA_MISSION_BEGIN:'.length);thread=Process.getCurrentThreadId();emit('marker_begin',{thread});}else if(s.startsWith('REA_MISSION_END:')){emit('marker_end',{thread});current=null;thread=null;}}});
for(const [rva,kind] of [[0x49cdf0,'native_save'],[0x49d380,'native_load'],[0x478710,'mission_initialize'],[0x478b40,'mission_update'],[0x4796f0,'mission_reward'],[0x491be0,'mission_achieve'],[0x491d70,'mission_continue_achieve'],[0x48eac0,'rise_earn_rp'],[0x4c6540,'result_initialize'],[0x4c8760,'result_open_if_need'],[0x47d430,'mission_manager_initialize']])Interceptor.attach(base.add(rva),{onEnter(a){if(current===null||thread!==Process.getCurrentThreadId())return;emit(kind,{arg0:a[0].toString(),arg1:a[1].toString(),caller:this.returnAddress.sub(base).toString()});}});
Interceptor.attach(base.add(0x1ef9c40),{onEnter(a){if([0,1,4].includes(a[2].toInt32()))emit('engine_error',{type:a[2].toInt32(),message:str(a[0]),stack:str(a[1])});}});
emit('mission_consumers_ready',{pid:Process.id,path:mod.path,scope:'entry-only observation; native methods are invoked by separate managed fixture; no observer writes'});
