// Read-only REA witness. The separately compiled managed probe owns all mutations.
const mod=Process.getModuleByName('GameAssembly.dll'),base=mod.base;
const resolve=new NativeFunction(mod.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function ic(n,r,a){return new NativeFunction(resolve(Memory.allocUtf8String(n)),r,a);}
const frame=ic('UnityEngine.Time::get_frameCount()','int',[]),real=ic('UnityEngine.Time::get_realtimeSinceStartup()','float',[]);
let current=null,thread=null,calculator=false;
function emit(kind,data){send({kind,frame:frame(),real:real(),data:{name:current,...data}});}
function str(p){if(p.isNull())return null;let n=p.add(0x10).readS32();return {text:p.add(0x14).readUtf16String(Math.min(n,16000)),length:n,truncated:n>16000};}
Interceptor.attach(Process.getModuleByName('kernel32.dll').getExportByName('OutputDebugStringW'),{onEnter(a){
 const s=a[0].readUtf16String();
 if(s.startsWith('REA_PAID_BEGIN:')){current=s.slice('REA_PAID_BEGIN:'.length);thread=Process.getCurrentThreadId();emit('marker_begin',{thread});}
 else if(s==='REA_PAID_END:'){emit('marker_end',{thread});current=null;thread=null;calculator=false;}
 else if(s==='REA_PAID_CALCULATE_BEGIN:')calculator=true;
 else if(s==='REA_PAID_CALCULATE_END:')calculator=false;
}});
for(const [rva,kind] of [[0x49cdf0,'native_save'],[0x49d380,'native_load'],[0x4e7d10,'skill_panel_open'],[0x4e6c70,'skill_tab'],[0x4c4740,'paid_button'],[0x4e7490,'parent_paid_callback'],[0x48ea20,'consume_rp'],[0x48e1f0,'rise_skill_level'],[0x48dae0,'change_passive'],[0x4cecd0,'toggle_callback'],[0x4cfc70,'switch_panel_open'],[0x4f2b60,'capacity_consumer'],[0x65ae60,'rp_bonus_consumer']]){
 Interceptor.attach(base.add(rva),{onEnter(a){if(current===null||thread!==Process.getCurrentThreadId())return;if(kind==='rp_bonus_consumer'&&!calculator)return;emit(kind,{arg0:a[0].toString(),arg1:a[1].toString(),arg2:a[2].toString(),caller:this.returnAddress.sub(base).toString()});}});
}
Interceptor.attach(base.add(0x1ef9c40),{onEnter(a){if([0,1,4].includes(a[2].toInt32()))emit('engine_error',{type:a[2].toInt32(),message:str(a[0]),stack:str(a[1])});}});
emit('paid_skill_ready',{pid:Process.id,path:mod.path,scope:'read-only entry hooks; calculator entry restricted to managed explicit-call brackets; no game or filesystem writes'});
