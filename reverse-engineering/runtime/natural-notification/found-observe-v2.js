// Original state and broadcast listener entries, without invoking them.
const m=Process.getModuleByName('GameAssembly.dll'),base=m.base;
const resolve=new NativeFunction(m.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
const frame=new NativeFunction(resolve(Memory.allocUtf8String('UnityEngine.Time::get_frameCount()')),'int',[]);
for(const [rva,kind] of [[0x42c140,'scenario_found_enter'],[0x42c820,'scenario_found_exit']])Interceptor.attach(base.add(rva),{onEnter(a){
 const n=a[0].add(0x20).readPointer();send({kind,frame:frame(),data:{nca:n.toString(),receiver:n.add(0x98).readPointer().toString(),npc:n.add(0x38).readPointer().toString()}});
}});
Interceptor.attach(base.add(0x645a60),{onEnter(a){send({kind:'scenario_found_listener',frame:frame(),data:{player:a[0].toString(),npc:a[1].toString(),argumentConvention:'single-pointer value-type FoundStrangerEvent'}});}});
send({kind:'scenario_found_ready'});
