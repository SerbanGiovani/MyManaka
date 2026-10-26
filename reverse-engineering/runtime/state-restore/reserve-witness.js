// Passive predicate return and record mutation witness for reserve consumption.
const base=Process.getModuleByName('GameAssembly.dll').base;
const resolve=new NativeFunction(Process.getModuleByName('GameAssembly.dll').getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
const frame=new NativeFunction(resolve(Memory.allocUtf8String('UnityEngine.Time::get_frameCount()')),'int',[]);
function record(p){return {pointer:p.toString(),dropped:p.add(0x10).readU8(),reserve:p.add(0x11).readU8(),stage:p.add(0x30).readS32(),item:p.add(0x34).readS32()};}
Interceptor.attach(base.add(0x48ad30),{onEnter(a){this.p=a[1];send({kind:'reserve_predicate_enter',frame:frame(),data:record(this.p)});},onLeave(r){send({kind:'reserve_predicate_leave',frame:frame(),data:{...record(this.p),remove:r.toInt32()&255}});}});
send({kind:'reserve_witness_ready',data:{pid:Process.id}});
