// Passive natural gameplay. No setters, injected input, gameplay invocations or
// writes to game objects. A private file marker flushes and detaches this probe.
const mod=Process.getModuleByName('GameAssembly.dll'),base=mod.base;
const resolve=new NativeFunction(mod.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
const addresses={},hooks=[];
function ic(n,t,a){const p=resolve(Memory.allocUtf8String(n));if(p.isNull())throw Error(n);addresses[n]=p.toString();return new NativeFunction(p,t,a);}
function hook(p,handlers){hooks.push(Interceptor.attach(p,handlers));}
const frame=ic('UnityEngine.Time::get_frameCount()','int',[]),time=ic('UnityEngine.Time::get_time()','float',[]),real=ic('UnityEngine.Time::get_realtimeSinceStartup()','float',[]),scale=ic('UnityEngine.Time::get_timeScale()','float',[]);
const speed=ic('UnityEngine.Animator::get_speed()','float',['pointer']),enabled=ic('UnityEngine.Behaviour::get_enabled()','bool',['pointer']),fire=ic('UnityEngine.Animator::get_fireEvents()','bool',['pointer']),culling=ic('UnityEngine.Animator::get_cullingMode()','int',['pointer']);
const active=ic('UnityEngine.GameObject::get_activeInHierarchy()','bool',['pointer']),transform=ic('UnityEngine.GameObject::get_transform()','pointer',['pointer']),position=ic('UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)','void',['pointer','pointer']);
const info=ic('UnityEngine.Animator::GetAnimatorStateInfo(System.Int32,UnityEngine.StateInfoIndex,UnityEngine.AnimatorStateInfo&)','void',['pointer','int','int','pointer']),transition=ic('UnityEngine.Animator::IsInTransition(System.Int32)','bool',['pointer','int']),weight=ic('UnityEngine.Animator::GetLayerWeight(System.Int32)','float',['pointer','int']),getBool=ic('UnityEngine.Animator::GetBoolID(System.Int32)','bool',['pointer','int']);
const foundHash=base.add(0x2d59ea8).readPointer().add(0xb8).readPointer().add(0x24).readS32(),buf=Memory.alloc(36),v1=Memory.alloc(12),v2=Memory.alloc(12);
const foundHashes=new Set([0xfa993e55,0xda7252cc,0x4393d49c,0x61df7c95]);
const finishPath='E:/ManakaREA-NaturalGameplay/coverage-natural-finish-20261022-C';
const actors=new Map(),byAnimator=new Map(),byMesh=new Map(),cases=new Map(),models=new Map(),stack=new Map();
let sequence=0,eventSequence=0,ordinal=0,lastFrame=-1,lastHeartbeat=0,lastFileCheck=0,finished=false,errors=0;
function live(p){return !p.isNull()&&!p.add(0x10).readPointer().isNull();}
function stop(){return base.add(0x2d53c48).readPointer().add(0xb8).readPointer().readPointer().add(0x30).readPointer().add(0x14).readU8();}
function emit(kind,data){send({kind,ordinal:++ordinal,frame:frame(),time:time(),real:real(),data});}
function state(a,i){info(a,4,i,buf);return {short:buf.readU32(),full:buf.add(8).readU32(),normalized:buf.add(12).readFloat(),length:buf.add(16).readFloat(),speed:buf.add(20).readFloat(),multiplier:buf.add(24).readFloat(),loop:buf.add(32).readS32()};}
function geometry(nca){const pc=base.add(0x2d58378).readPointer().add(0xb8).readPointer().readPointer(),go=pc.add(0x40).readPointer().add(0x28).readPointer(),ng=nca.add(0x18).readPointer();if(!live(go)||!live(ng))throw Error('destroyed geometry');position(transform(go),v1);position(transform(ng),v2);let sum=0;const player=[],npc=[];for(let i=0;i<3;i++){const a=v1.add(i*4).readFloat(),b=v2.add(i*4).readFloat();player.push(a);npc.push(b);sum+=(a-b)**2;}return {distance:Math.sqrt(sum),playerPosition:player,npcPosition:npc};}
function actor(nca){
 const key=nca.toString(),a=nca.add(0x90).readPointer(),mesh=nca.add(0xc0).readPointer().add(0x20).readPointer();let row=actors.get(key);
 if(row&&(!row.animator.equals(a)||!row.mesh.equals(mesh))){const c=cases.get(key);if(c)end(c,'model-replaced');byAnimator.delete(row.animator.toString());byMesh.delete(row.mesh.toString());row=null;}
 if(!row){row={nca,animator:a,mesh,npc:nca.add(0x38).readPointer(),lastBusiness:null};actors.set(key,row);byAnimator.set(a.toString(),row);byMesh.set(mesh.toString(),row);}
 return row;
}
function snapshot(nca){const row=actor(nca),npc=row.npc,a=row.animator;if(!live(a)||!live(row.mesh))throw Error('destroyed Unity object');const common=nca.add(0x88).readPointer().add(0x10).readPointer();
 return {npc:npc.toString(),receiver:nca.add(0x98).readPointer().toString(),animator:a.toString(),mesh:row.mesh.toString(),display:npc.add(0x7c).readU8(),meshActive:active(row.mesh),enabled:enabled(a),speed:speed(a),fireEvents:fire(a),culling:culling(a),found:getBool(a,foundHash),...geometry(nca),cachedDistance:npc.add(0x24).readFloat(),manual:common.add(0x10).readU8(),fps:common.add(0x14).readS32(),skipped:common.add(0x24).readFloat(),current:state(a,0),next:state(a,1),transition:transition(a,4),weight:weight(a,4),stop:stop(),timeScale:scale(),businessState:npc.add(0x48).readPointer().add(0x10).readS32()};
}
function flush(c){if(c.samples.length){emit('coverage_samples',{id:c.id,nca:c.nca.toString(),samples:c.samples});c.samples=[];}}
function sample(c,phase){const s=snapshot(c.nca);if(!cases.has(c.nca.toString()))throw Error('epoch retired during snapshot');c.last=s;c.samples.push({frame:frame(),time:time(),real:real(),phase,...s});if(c.samples.length>=60)flush(c);return s;}
function end(c,reason){flush(c);emit('coverage_end',{id:c.id,nca:c.nca.toString(),reason,events:c.events,callbacks:c.callbacks,exitFrame:c.exitFrame??null});cases.delete(c.nca.toString());}
function begin(nca,origin){const key=nca.toString();let c=cases.get(key);if(c){if(!c.exitAt)return c;end(c,'reentered');}if(sequence>=80){emit('coverage_limit',{limit:80});return null;}c={id:++sequence,nca,began:real(),samples:[],events:0,callbacks:0,exitAt:null,goneFrames:0};cases.set(key,c);emit('coverage_enter',{id:c.id,nca:key,origin});sample(c,'enter');return c;}
function fail(where,e){if(errors++<20)emit('coverage_error',{where,error:e.message});}
hook(base.add(0x429740),{onEnter(a){try{const npc=a[0],nca=npc.add(0x30).readPointer(),old=npc.add(0x48).readPointer().add(0x10).readS32(),next=a[1].toInt32();actor(nca);if(next===1&&old!==1)begin(nca,'original-business-change-before-call');const c=cases.get(nca.toString());if(c){emit('coverage_business_change',{id:c.id,old,next});if(old===1&&next!==1){c.exitAt=real();c.exitFrame=frame();}}}catch(e){fail('change-state',e);}}});
hook(base.add(0x41c5d0),{onEnter(a){try{const row=byAnimator.get(a[0].add(0x18).readPointer().toString());if(!row)return;const nca=row.nca,value=a[1].toInt32()!==0,c=value?begin(nca,'original-animation-manager-before-call'):cases.get(nca.toString());if(c){emit('coverage_parameter',{id:c.id,value,caller:this.returnAddress.toString()});if(!value){c.exitAt=real();c.exitFrame=frame();}}}catch(e){fail('animation-manager',e);}}});
const boolAddress=resolve(Memory.allocUtf8String('UnityEngine.Animator::SetBoolID(System.Int32,System.Boolean)'));
hook(boolAddress,{onEnter(a){if(a[1].toInt32()!==foundHash)return;try{const row=byAnimator.get(a[0].toString());if(!row){emit('coverage_unmapped_parameter',{animator:a[0].toString(),value:a[2].toInt32()});return;}const value=a[2].toInt32()!==0,c=value?begin(row.nca,'original-parameter-before-native'):cases.get(row.nca.toString());if(c){emit('coverage_parameter',{id:c.id,value,caller:this.returnAddress.toString()});if(!value){c.exitAt=real();c.exitFrame=frame();}}}catch(e){fail('parameter',e);}}});
const activeAddress=resolve(Memory.allocUtf8String('UnityEngine.GameObject::SetActive(System.Boolean)'));
hook(activeAddress,{onEnter(a){const row=byMesh.get(a[0].toString());this.row=row;this.c=row&&cases.get(row.nca.toString());this.value=a[1].toInt32()!==0;this.changed=row&&row.lastVisibility!==this.value;if(row)row.lastVisibility=this.value;},onLeave(){if(!this.c||!this.changed)return;try{emit('coverage_visibility_return',{id:this.c.id,value:this.value,actual:active(this.row.mesh),mesh:this.row.mesh.toString()});}catch(e){fail('visibility',e);}}});
hook(base.add(0x41eb80),{onEnter(a){try{actor(a[0].add(0x18).readPointer());}catch(e){}}});
hook(base.add(0x41ee90),{onEnter(){const row=byAnimator.get(this.context.rdi.toString()),c=row&&cases.get(row.nca.toString());if(c)emit('coverage_manual_step',{id:c.id,delta:this.context.rbx.add(0x24).readFloat()});}});
hook(base.add(0x41a730),{onEnter(a){try{const receiver=a[0],nca=receiver.add(0x20).readPointer(),c=cases.get(nca.toString());if(c)c.events++;const row={event:++eventSequence,id:c?.id??null,nca:nca.toString(),receiver:receiver.toString(),frame:frame()};stack.set(Process.getCurrentThreadId(),row);let at=null;try{at=snapshot(nca);}catch(e){}emit('coverage_animation',{...row,at});}catch(e){fail('animation',e);}}});
hook(base.add(0x4b4f50),{onEnter(a){const e=stack.get(Process.getCurrentThreadId());if(!e||e.frame!==frame()||a[1].add(0x40).readPointer().toString()!==e.receiver)return;const row={...e,model:a[0].toString(),callback:false};models.set(row.model,row);stack.delete(Process.getCurrentThreadId());emit('coverage_model',row);}});
hook(base.add(0x41a870),{onEnter(a){const receiver=a[0].toString(),m=[...models.values()].find(x=>x.receiver===receiver&&!x.callback);if(m){m.callback=true;const c=cases.get(m.nca);if(c&&c.id===m.id)c.callbacks++;}emit('coverage_callback',{event:m?.event??null,id:m?.id??null,model:m?.model??null,receiver});}});
hook(base.add(0x645a60),{onEnter(a){emit('coverage_listener',{npc:a[1].toString(),player:a[0].toString()});}});
hook(base.add(0x6292f0),{onEnter(){emit('coverage_stop_producer',{before:stop()});},onLeave(){try{emit('coverage_stop_producer_return',{after:stop()});}catch(e){}}});
hook(base.add(0x627a90),{onEnter(a){if(a[1].toInt32()===7)emit('coverage_stop_action_request',{});}});
hook(base.add(0x42a720),{onEnter(a){try{const c=cases.get(a[0].add(0x30).readPointer().toString());if(c)emit('coverage_stop_receiver',{id:c.id,stop:stop()});}catch(e){}}});
hook(base.add(0x620800),{onEnter(){
 if(finished)return;const f=frame(),now=real();if(f===lastFrame)return;lastFrame=f;
 for(const c of [...cases.values()]){try{const s=sample(c,'input-frame');if(!s.found&&!c.exitAt){c.exitAt=now;c.exitFrame=f;emit('coverage_parameter_fall_readback',{id:c.id});}if(s.found&&c.exitAt&&s.businessState===1){c.exitAt=null;c.exitFrame=null;}
 const source=foundHashes.has(s.current.full)||(s.transition&&foundHashes.has(s.next.full));c.goneFrames=!source&&!s.transition?c.goneFrames+1:0;
 const pending=[...models.values()].some(x=>x.nca===c.nca.toString()&&x.id===c.id&&!x.callback);
 if(c.exitAt&&now-c.exitAt>2&&c.goneFrames>=2&&!pending)end(c,'completed-observation');else if(now-c.began>180)end(c,'observation-limit');
 }catch(e){if(cases.has(c.nca.toString()))end(c,'retired:'+e.message);}}
 // Raw business-state reads only for idle actors; no polling of 252 Unity
 // Animators every three frames. Original setter/change hooks are the origin.
 if(f%6===0){for(const [key,row] of actors){if(cases.has(key))continue;try{if(!live(row.animator)||!live(row.mesh))throw Error('destroyed idle actor');const current=row.npc.add(0x48).readPointer().add(0x10).readS32();if(current===1&&row.lastBusiness!==1)begin(row.nca,row.lastBusiness===null?'initial-business-left-censored':'business-rise-fallback');row.lastBusiness=current;}catch(e){actors.delete(key);if(byAnimator.get(row.animator.toString())===row)byAnimator.delete(row.animator.toString());if(byMesh.get(row.mesh.toString())===row)byMesh.delete(row.mesh.toString());}}}
 if(now-lastHeartbeat>5){lastHeartbeat=now;try{emit('coverage_heartbeat',{actors:actors.size,activeCases:cases.size,totalCases:sequence,events:eventSequence,stop:stop(),errors});}catch(e){}}
 if(now-lastFileCheck>1){lastFileCheck=now;let requested=false;try{requested=File.readAllText(finishPath).trim()==='finish';}catch(e){}if(requested){finished=true;for(const c of [...cases.values()])end(c,'operator-ended');emit('coverage_finished',{cases:sequence,events:eventSequence,errors,finishPath});for(const h of hooks)h.detach();}}
}});
emit('coverage_ready',{path:mod.path,base:base.toString(),scope:'passive natural input including original time-stop skill; 180 second per-epoch bound; no game writes; explicit end-marker before final checkpoint',foundHash,finishPath,addresses});
