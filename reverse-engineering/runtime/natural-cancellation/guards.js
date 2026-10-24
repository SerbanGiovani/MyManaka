// Observe original travel guards and parsed movement; no game writes or input injection.
const mod=Process.getModuleByName('GameAssembly.dll'),base=mod.base;
const resolve=new NativeFunction(mod.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function ic(n,t){return new NativeFunction(resolve(Memory.allocUtf8String(n)),t,[]);}
const frame=ic('UnityEngine.Time::get_frameCount()','int'),real=ic('UnityEngine.Time::get_realtimeSinceStartup()','float');
const level=new NativeFunction(base.add(0x48e170),'int',['int','pointer']);
const hooks=[],stack=new Map();let seq=0,ended=false,lastCheck=0,windowUntil=0,motion=[];
function emit(kind,data){send({kind,frame:frame(),real:real(),data});}
function hook(rva,h){hooks.push(Interceptor.attach(base.add(rva),h));}
function instance(rva){return base.add(rva).readPointer().add(0xb8).readPointer().readPointer();}
function stop(){return instance(0x2d53c48).add(0x30).readPointer().add(0x14).readU8();}
function textValue(p){if(p.isNull())return null;const n=p.add(0x10).readS32();return n>=0&&n<10000?p.add(0x14).readUtf16String(n):null;}
function current(){const a=stack.get(Process.getCurrentThreadId());return a?.[a.length-1];}
function emitCall(kind,data){const c=current();if(c)emit(kind,{call:c.id,name:c.name,...data});}
for(const [rva,name] of [[0x4fa6f0,'menu-fast-travel'],[0x61d780,'portal-enter'],[0x512820,'panel-fast-travel']])hook(rva,{onEnter(a){this.thread=Process.getCurrentThreadId();this.row={id:++seq,name,view:a[0],transitions:0};const ss=stack.get(this.thread)||[];ss.push(this.row);stack.set(this.thread,ss);emit('guard_call_begin',{id:this.row.id,name,stop:stop(),skill17Level:level(17,ptr(0))});},onLeave(){emit('guard_call_end',{id:this.row.id,name:this.row.name,stop:stop(),transitions:this.row.transitions});stack.get(this.thread).pop();}});
for(const [rva,name,reject,bytes] of [[0x4fa9bc,'menu-fast-travel',0x4fabbf,[128,120,20,0]],[0x61dd5a,'portal-enter',0x61dddf,[128,120,20,0]]]){
 const got=Array.from(new Uint8Array(base.add(rva).readByteArray(bytes.length)));if(JSON.stringify(got)!==JSON.stringify(bytes))throw Error('guard bytes mismatch '+rva);
 hook(rva,{onEnter(){const c=current();if(c?.name===name){c.flag=this.context.rax.add(0x14).readU8();emitCall('guard_stop_compare',{rva:'0x'+rva.toString(16),flag:c.flag});}}});
 hook(reject,{onEnter(){if(current()?.name===name)emitCall('guard_stop_reject_branch',{rva:'0x'+reject.toString(16),flag:current().flag});}});
}
hook(0x4b9690,{onEnter(a){if(current())emitCall('guard_localizer_key',{key:textValue(a[0])});}});
hook(0x50c430,{onEnter(a){if(current())emitCall('guard_message',{text:textValue(a[0])});}});
for(const [rva,name] of [[0x4a6cf0,'trans-stage-if-condition'],[0x4a7190,'trans-stage']])hook(rva,{onEnter(a){const c=current();if(c)c.transitions++;emit('guard_transition_entry',{call:c?.id??null,name,source:a[1].toInt32(),target:a[2].toInt32()});}});
hook(0x429740,{onEnter(a){if(a[1].toInt32()===1)windowUntil=real()+5;}});
function flush(){if(motion.length){emit('player_motion_samples',{samples:motion});motion=[];}}
hook(0x620800,{onLeave(){if(ended)return;try{const pc=instance(0x2d58378);if(!pc.isNull()){const pca=pc.add(0x40).readPointer(),s=pca.add(0x60).readPointer(),action=s.add(0x48).readPointer(),input=pc.add(0x38).readPointer().add(0x20).readPointer();
 const move=[0,4,8].map(n=>input.add(0x10+n).readFloat());if(real()<windowUntil||move.some(v=>Math.abs(v)>0.0001))motion.push({frame:frame(),real:real(),inputMove:move,dash:input.add(0x26).readU8(),state:s.add(0x5c).readS32(),action:action.isNull()?null:action.add(0x18).readS32(),canMove:action.isNull()?null:action.add(0x1c).readU8(),invalidLocomotion:s.add(0x124).readFloat(),moveV:[0,4,8].map(n=>s.add(0x190+n).readFloat()),ecstasy:s.add(0x50).readU8(),stop:stop()});if(motion.length>=120)flush();}
 if(real()-lastCheck>1){lastCheck=real();let finish=false;try{finish=File.readAllText('E:/ManakaREA-NaturalGameplay/cancellation-natural-finish-20261024-A').trim()==='finish';}catch(e){}if(finish){ended=true;flush();emit('guards_finished',{calls:seq});for(const h of hooks)h.detach();}}
 }catch(e){emit('guard_probe_error',{error:e.message});ended=true;for(const h of hooks)h.detach();}}});
emit('guards_ready',{scope:'Original compare and reject branch observation; original input movement readback; no gameplay mutation.'});
