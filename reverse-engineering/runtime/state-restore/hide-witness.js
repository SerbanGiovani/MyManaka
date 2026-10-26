// Passive witness for the other-stage IsDropped -> Hide branch.
const m=Process.getModuleByName('GameAssembly.dll'),base=m.base;
const resolve=new NativeFunction(m.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
const frame=new NativeFunction(resolve(Memory.allocUtf8String('UnityEngine.Time::get_frameCount()')),'int',[]);
Interceptor.attach(base.add(0x4897a0),{onEnter(a){send({kind:'native_hide_enter',frame:frame(),data:{item:a[1].toInt32(),caller:this.returnAddress.sub(base).toString()}});}});
send({kind:'hide_witness_ready',data:{pid:Process.id}});
