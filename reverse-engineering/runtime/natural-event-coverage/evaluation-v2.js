// Passive bracketing of original manual Animator.Update calls. This does not
// call Update itself. Native AnimationEvent entries are counted inside scopes.
const mod=Process.getModuleByName('GameAssembly.dll'),base=mod.base;
const resolve=new NativeFunction(mod.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function ic(n,t,a){const p=resolve(Memory.allocUtf8String(n));if(p.isNull())throw Error(n);return new NativeFunction(p,t,a);}
const frame=ic('UnityEngine.Time::get_frameCount()','int',[]),real=ic('UnityEngine.Time::get_realtimeSinceStartup()','float',[]);
const info=ic('UnityEngine.Animator::GetAnimatorStateInfo(System.Int32,UnityEngine.StateInfoIndex,UnityEngine.AnimatorStateInfo&)','void',['pointer','int','int','pointer']),trans=ic('UnityEngine.Animator::IsInTransition(System.Int32)','bool',['pointer','int']);
const active=ic('UnityEngine.GameObject::get_activeInHierarchy()','bool',['pointer']),speed=ic('UnityEngine.Animator::get_speed()','float',['pointer']);
const pos=ic('UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)','void',['pointer','pointer']),transform=ic('UnityEngine.GameObject::get_transform()','pointer',['pointer']);
const buf=Memory.alloc(36),p1=Memory.alloc(12),p2=Memory.alloc(12),actors=new Map(),scopes=new Map(),hooks=[];
let sequence=0,tickReal=real(),lastCheck=0,done=false,skippedFrozen=0;
function hook(p,h){hooks.push(Interceptor.attach(p,h));}
function emit(kind,data){send({kind,frame:frame(),real:real(),data});}
function live(p){return !p.isNull()&&!p.add(0x10).readPointer().isNull();}
function state(a,i){info(a,4,i,buf);return {full:buf.add(8).readU32(),normalized:buf.add(12).readFloat()};}
function snapshot(row){const nca=row.nca,a=row.animator,mesh=nca.add(0xc0).readPointer().add(0x20).readPointer();if(!live(a)||!live(mesh))throw Error('destroyed');const pc=base.add(0x2d58378).readPointer().add(0xb8).readPointer().readPointer().add(0x40).readPointer().add(0x28).readPointer();pos(transform(pc),p1);pos(transform(nca.add(0x18).readPointer()),p2);let d=0;for(let i=0;i<3;i++)d+=(p1.add(i*4).readFloat()-p2.add(i*4).readFloat())**2;
 return {current:state(a,0),next:state(a,1),transition:trans(a,4),meshActive:active(mesh),distance:Math.sqrt(d),speed:speed(a),stop:base.add(0x2d53c48).readPointer().add(0xb8).readPointer().readPointer().add(0x30).readPointer().add(0x14).readU8()};}
hook(base.add(0x41eb80),{onEnter(a){try{const nca=a[0].add(0x18).readPointer(),animator=nca.add(0x90).readPointer(),key=animator.toString();let row=actors.get(key);if(!row){row={nca,animator,until:0};actors.set(key,row);}if(nca.add(0x38).readPointer().add(0x48).readPointer().add(0x10).readS32()===1)row.until=tickReal+3;}catch(e){}}});
hook(base.add(0x41ee90),{onEnter(){const row=actors.get(this.context.rdi.toString());if(!row||row.until<tickReal)return;try{if(speed(row.animator)===0&&tickReal-(row.lastFrozenLog||0)<15){skippedFrozen++;return;}row.lastFrozenLog=tickReal;const delta=this.context.rbx.add(0x24).readFloat(),s={id:++sequence,row,frame:frame(),events:0};scopes.set(Process.getCurrentThreadId(),s);emit('evaluation_before',{id:s.id,nca:row.nca.toString(),receiver:row.nca.add(0x98).readPointer().toString(),delta,pre:snapshot(row)});}catch(e){emit('evaluation_error',{where:'before',error:e.message});}}});
hook(base.add(0x41a730),{onEnter(a){const s=scopes.get(Process.getCurrentThreadId());if(s&&s.frame===frame()&&s.row.nca.add(0x98).readPointer().equals(a[0])){s.events++;emit('evaluation_animation_inside',{id:s.id,receiver:a[0].toString()});}}});
hook(base.add(0x41ee98),{onEnter(){const tid=Process.getCurrentThreadId(),s=scopes.get(tid);if(!s)return;scopes.delete(tid);if(s.frame!==frame())return;try{emit('evaluation_after',{id:s.id,events:s.events,post:snapshot(s.row)});}catch(e){emit('evaluation_error',{where:'after',id:s.id,error:e.message});}}});
hook(base.add(0x620800),{onEnter(){tickReal=real();if(done||tickReal-lastCheck<1)return;lastCheck=tickReal;let finish=false;try{finish=File.readAllText('E:/ManakaREA-NaturalGameplay/coverage-natural-finish-20261022-D').trim()==='finish';}catch(e){}if(finish){done=true;emit('evaluation_finished',{evaluations:sequence,pending:scopes.size,skippedFrozen});for(const h of hooks)h.detach();}}});
emit('evaluation_ready',{scope:'Original manual Update call at RVA41ee90 bracketed through41ee98; no direct gameplay or Update invocation.'});
