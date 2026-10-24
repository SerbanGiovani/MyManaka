// Passive population and eligibility snapshot; raw pointers observed in original FPS calls.
const mod=Process.getModuleByName('GameAssembly.dll'),base=mod.base;
const resolve=new NativeFunction(mod.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function query(name,type){return new NativeFunction(resolve(Memory.allocUtf8String(name)),type,[]);}
const frame=query('UnityEngine.Time::get_frameCount()','int'),real=query('UnityEngine.Time::get_realtimeSinceStartup()','float');
const rows=new Map(),hooks=[];let last=-10,ended=false;
function emit(kind,data){send({kind,frame:frame(),real:real(),data});}
hooks.push(Interceptor.attach(base.add(0x41eb80),{onEnter(a){try{const nca=a[0].add(0x18).readPointer();rows.set(nca.toString(),nca);}catch(e){}}}));
hooks.push(Interceptor.attach(base.add(0x620800),{onEnter(){if(ended||real()-last<5)return;last=real();const states=[];
 for(const [key,nca] of rows){try{const animator=nca.add(0x90).readPointer();if(animator.isNull()||animator.add(0x10).readPointer().isNull()){rows.delete(key);continue;}
 const npc=nca.add(0x38).readPointer(),m=nca.add(0x40).readPointer(),found=npc.add(0x50).readPointer();states.push({nca:key,npc:npc.toString(),state:m.add(0x10).readS32(),alreadyFound:m.add(0x1d).readU8(),timer:found.add(0x10).readFloat(),distanceCached:npc.add(0x24).readFloat()});}catch(e){rows.delete(key);}}
 emit('eligibility_inventory',{actors:states.length,alreadyFound:states.filter(s=>s.alreadyFound).length,notAlreadyFound:states.filter(s=>!s.alreadyFound).length,nearest:states.sort((a,b)=>a.distanceCached-b.distanceCached).slice(0,8)});
 let finish=false;try{finish=File.readAllText('E:/ManakaREA-NaturalGameplay/cancellation-natural-finish-20261024-A').trim()==='finish';}catch(e){}
 if(finish){ended=true;emit('inventory_finished',{});for(const h of hooks)h.detach();}
}}));emit('inventory_ready',{scope:'No writes or gameplay calls; distanceCached is only context, not threshold proof.'});
