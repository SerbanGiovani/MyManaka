// REA Frida observer. No replacement, forced event, timer advancement or memory write.
const module = Process.getModuleByName('GameAssembly.dll');
const base = module.base;
const icall = new NativeFunction(module.getExportByName('il2cpp_resolve_icall'), 'pointer', ['pointer']);
function unity(name, ret) {return new NativeFunction(icall(Memory.allocUtf8String(name)), ret, []);}
const frame=unity('UnityEngine.Time::get_frameCount()', 'int');
const time=unity('UnityEngine.Time::get_time()', 'float');
const real=unity('UnityEngine.Time::get_realtimeSinceStartup()', 'float');
function emit(kind, data) {send({kind,frame:frame(),time:time(),real:real(),data});}
let events=0, callbacks=0;
let exceptions=0;
Interceptor.attach(module.getExportByName('il2cpp_raise_exception'),{onEnter(args) {
    if(exceptions++<4)send({kind:'native_exception',object:args[0].toString(),trace:Thread.backtrace(this.context,Backtracer.ACCURATE).map(p=>({address:p.toString(),rva:p.sub(base).toString(),symbol:DebugSymbol.fromAddress(p).toString()}))});
}});
Interceptor.attach(base.add(0x41a730), {onEnter(args) {events++; emit('animation_event_native',{receiver:args[0].toString(),count:events});}});
// callback RVA filled from the original IL2CPP method index, not a guessed callsite.
const callbackRva=0x41a870;
Interceptor.attach(base.add(callbackRva), {onEnter(args) {callbacks++; emit('delayed_callback_native',{receiver:args[0].toString(),count:callbacks});}});
Interceptor.attach(base.add(0x4b3df0), {onEnter(args) {emit('delay_scaled_native',{action:args[0].toString()});}});
send({kind:'observer_ready',module:module.name,base:base.toString(),path:module.path,eventRva:'0x41a730',callbackRva:'0x'+callbackRva.toString(16)});
