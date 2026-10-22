// Passive full-game observation. No setters, NativeFunction gameplay calls or writes
// to game objects. AnimatorStateInfo ABI comes from the pinned Unity managed binding.
const mod=Process.getModuleByName('GameAssembly.dll'),base=mod.base;
const resolve=new NativeFunction(mod.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
const addresses={};
function ic(n,t,a){const p=resolve(Memory.allocUtf8String(n));if(p.isNull())throw Error(n);addresses[n]=p.toString();return new NativeFunction(p,t,a);}
const frame=ic('UnityEngine.Time::get_frameCount()','int',[]),time=ic('UnityEngine.Time::get_time()','float',[]),real=ic('UnityEngine.Time::get_realtimeSinceStartup()','float',[]),scale=ic('UnityEngine.Time::get_timeScale()','float',[]);
const speed=ic('UnityEngine.Animator::get_speed()','float',['pointer']),enabled=ic('UnityEngine.Behaviour::get_enabled()','bool',['pointer']);
const fire=ic('UnityEngine.Animator::get_fireEvents()','bool',['pointer']),culling=ic('UnityEngine.Animator::get_cullingMode()','int',['pointer']);
const active=ic('UnityEngine.GameObject::get_activeInHierarchy()','bool',['pointer']),transform=ic('UnityEngine.GameObject::get_transform()','pointer',['pointer']);
const position=ic('UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)','void',['pointer','pointer']);
const info=ic('UnityEngine.Animator::GetAnimatorStateInfo(System.Int32,UnityEngine.StateInfoIndex,UnityEngine.AnimatorStateInfo&)','void',['pointer','int','int','pointer']);
const transition=ic('UnityEngine.Animator::IsInTransition(System.Int32)','bool',['pointer','int']);
const weight=ic('UnityEngine.Animator::GetLayerWeight(System.Int32)','float',['pointer','int']);
const getBool=ic('UnityEngine.Animator::GetBoolID(System.Int32)','bool',['pointer','int']);
const foundHash=base.add(0x2d59ea8).readPointer().add(0xb8).readPointer().add(0x24).readS32();
const buf=Memory.alloc(36),v1=Memory.alloc(12),v2=Memory.alloc(12);
function live(p){return !p.isNull()&&!p.add(0x10).readPointer().isNull();}
function stop(){return base.add(0x2d53c48).readPointer().add(0xb8).readPointer().readPointer().add(0x30).readPointer().add(0x14).readU8();}
function stateInfo(a,index){
 info(a,4,index,buf);return {short:buf.readU32(),path:buf.add(4).readU32(),full:buf.add(8).readU32(),normalized:buf.add(12).readFloat(),length:buf.add(16).readFloat(),speed:buf.add(20).readFloat(),multiplier:buf.add(24).readFloat(),tag:buf.add(28).readU32(),loop:buf.add(32).readS32()};
}
function distance(nca){
 const pc=base.add(0x2d58378).readPointer().add(0xb8).readPointer().readPointer(),go=pc.add(0x40).readPointer().add(0x28).readPointer(),ng=nca.add(0x18).readPointer();
 if(!live(go)||!live(ng))return null;position(transform(go),v1);position(transform(ng),v2);
 let sum=0;for(let i=0;i<3;i++){const d=v1.add(i*4).readFloat()-v2.add(i*4).readFloat();sum+=d*d;}return Math.sqrt(sum);
}
function snapshot(nca){
 const npc=nca.add(0x38).readPointer(),a=nca.add(0x90).readPointer(),mesh=nca.add(0xc0).readPointer().add(0x20).readPointer();
 if(!live(a)||!live(mesh))throw Error('destroyed Unity object');
 const fps=nca.add(0x88).readPointer(),common=fps.add(0x10).readPointer();
 return {npc:npc.toString(),receiver:nca.add(0x98).readPointer().toString(),animator:a.toString(),mesh:mesh.toString(),display:npc.add(0x7c).readU8(),meshActive:active(mesh),enabled:enabled(a),speed:speed(a),fireEvents:fire(a),culling:culling(a),found:getBool(a,foundHash),distance:distance(nca),cachedDistance:npc.add(0x24).readFloat(),manual:common.add(0x10).readU8(),fps:common.add(0x14).readS32(),skipped:common.add(0x24).readFloat(),current:stateInfo(a,0),next:stateInfo(a,1),transition:transition(a,4),weight:weight(a,4),stop:stop(),timeScale:scale()};
}
function emit(kind,data){send({kind,frame:frame(),time:time(),real:real(),data});}
let sequence=0,lastFrame=-1,errorCount=0,caseCap=0;
const cases=new Map(),actors=new Map(),byAnimator=new Map(),models=new Map(),stack=new Map();
const actorByAnimator=new Map();
function begin(nca,origin){const key=nca.toString(),old=cases.get(key);if(old){if(old.last?.found)return old;end(old,'reentered');}if(caseCap++>=80){if(caseCap===81)emit('generation_case_cap',{cap:80});return null;}const c={id:++sequence,nca,began:real(),samples:[],events:0,callbacks:0,manualCalls:0};cases.set(key,c);emit('generation_enter',{id:c.id,nca:key,origin});sample(c,origin);return c;}
const boolAddress=resolve(Memory.allocUtf8String('UnityEngine.Animator::SetBoolID(System.Int32,System.Boolean)'));
if(boolAddress.isNull())throw Error('SetBoolID unresolved');
Interceptor.attach(boolAddress,{onEnter(a){if(a[1].toInt32()!==foundHash)return;const row=actorByAnimator.get(a[0].toString());if(!row){emit('generation_unmapped_parameter',{animator:a[0].toString(),value:a[2].toInt32()});return;}const value=a[2].toInt32()!==0;row.found=value;const c=value?begin(row.nca,'original-parameter-write-before-native'):cases.get(row.nca.toString());if(c){emit('generation_parameter',{id:c.id,value,caller:this.returnAddress.toString()});if(!value){c.exitFrame=frame();c.exitAt=real();}}}});
function flush(c){if(c.samples.length){emit('generation_samples',{id:c.id,nca:c.nca.toString(),samples:c.samples});c.samples=[];}}
function sample(c,phase){const s=snapshot(c.nca);c.last=s;byAnimator.set(s.animator,c);c.samples.push({frame:frame(),time:time(),real:real(),phase,...s});if(c.samples.length>=60)flush(c);}
function end(c,reason){flush(c);emit('generation_end',{id:c.id,reason,events:c.events,callbacks:c.callbacks,manualCalls:c.manualCalls,exitFrame:c.exitFrame??null});cases.delete(c.nca.toString());if(c.last)byAnimator.delete(c.last.animator);}
Interceptor.attach(base.add(0x42c140),{onEnter(a){
 try{const nca=a[0].add(0x20).readPointer(),key=nca.toString(),old=cases.get(key);if(old)end(old,'reentered');if(caseCap++>=80){if(caseCap===81)emit('generation_case_cap',{cap:80});return;}
 const c={id:++sequence,nca,began:real(),samples:[],events:0,callbacks:0,manualCalls:0};cases.set(key,c);emit('generation_enter',{id:c.id,nca:key,state:a[0].toString(),prior:actors.get(key)?.state||null});sample(c,'enter-before-inline-setter');
 }catch(e){emit('generation_error',{where:'enter',error:e.message});}
}});
Interceptor.attach(base.add(0x42c820),{onEnter(a){const nca=a[0].add(0x20).readPointer(),c=cases.get(nca.toString());if(c){c.exitFrame=frame();c.exitAt=real();emit('generation_exit',{id:c.id});try{sample(c,'exit-before-inline-setter');}catch(e){emit('generation_error',{where:'exit',error:e.message});}}}});
Interceptor.attach(base.add(0x41eb80),{onEnter(a){const nca=a[0].add(0x18).readPointer(),key=nca.toString();if(!actors.has(key)){const row={nca,found:null};actors.set(key,row);actorByAnimator.set(nca.add(0x90).readPointer().toString(),row);}}});
Interceptor.attach(base.add(0x41ee90),{onEnter(){const c=byAnimator.get(this.context.rdi.toString());if(c){c.manualCalls++;emit('generation_manual_step',{id:c.id,delta:this.context.rbx.add(0x24).readFloat()});}}});
Interceptor.attach(base.add(0x41a730),{onEnter(a){
 const receiver=a[0],nca=receiver.add(0x20).readPointer(),c=cases.get(nca.toString());if(c)c.events++;
 const row={id:c?.id??null,receiver:receiver.toString(),nca:nca.toString(),frame:frame()};stack.set(Process.getCurrentThreadId(),row);
 let at=null;try{at=snapshot(nca);}catch(e){}emit('generation_animation',{...row,at});
}});
Interceptor.attach(base.add(0x4b4f50),{onEnter(a){const e=stack.get(Process.getCurrentThreadId());if(!e||e.frame!==frame()||a[1].add(0x40).readPointer().toString()!==e.receiver)return;models.set(a[0].toString(),{...e,model:a[0].toString()});stack.delete(Process.getCurrentThreadId());emit('generation_model',{...e,model:a[0].toString()});}});
Interceptor.attach(base.add(0x41a870),{onEnter(a){const receiver=a[0].toString(),model=[...models.values()].find(x=>x.receiver===receiver&&!x.callback);if(model){model.callback=true;const c=cases.get(model.nca);if(c&&c.id===model.id)c.callbacks++;}emit('generation_callback',{id:model?.id??null,receiver,model:model?.model??null});}});
Interceptor.attach(base.add(0x645a60),{onEnter(a){emit('generation_listener',{player:a[0].toString(),npc:a[1].toString(),argumentConvention:'direct NpcController reference'});}});
Interceptor.attach(base.add(0x620800),{onEnter(){
 const f=frame();if(f===lastFrame)return;lastFrame=f;
 for(const c of [...cases.values()]){try{sample(c,'input-frame');if(real()-c.began>12||(c.exitAt&&real()-c.exitAt>2))end(c,'completed-observation');}catch(e){end(c,'retired:'+e.message);}}
 if(f%3===0){for(const [key,row] of actors){try{const a=row.nca.add(0x90).readPointer();if(!live(a))throw Error('destroyed');const value=getBool(a,foundHash);if(value&&!row.found&&!cases.has(key))begin(row.nca,row.found===null?'initial-true-left-censored':'getter-rise-fallback');if(!value&&row.found){const c=cases.get(key);if(c&&!c.exitAt){c.exitFrame=f;c.exitAt=real();emit('generation_parameter_fall_fallback',{id:c.id});}}row.found=value;}catch(e){actors.delete(key);}}}
 if(f%300===0)emit('generation_heartbeat',{cases:cases.size,actors:actors.size,totalCases:sequence,errors:errorCount});
}});
emit('generation_ready',{path:mod.path,base:base.toString(),scope:'passive natural input only; layer4; 36-byte managed binding ABI; parameter icall plus getter fallback; no game state writes',foundHash,setBoolAddress:boolAddress.toString(),addresses});
