// One main-thread read-only snapshot of the already booted independent copy.
const m=Process.getModuleByName('GameAssembly.dll'),base=m.base;
const resolve=new NativeFunction(m.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function ic(n,t,a){return new NativeFunction(resolve(Memory.allocUtf8String(n)),t,a);}
const frame=ic('UnityEngine.Time::get_frameCount()','int',[]);
const real=ic('UnityEngine.Time::get_realtimeSinceStartup()','float',[]);
const transform=ic('UnityEngine.GameObject::get_transform()','pointer',['pointer']);
const getPos=ic('UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)','void',['pointer','pointer']);
function instance(r){return base.add(r).readPointer().add(0xb8).readPointer().readPointer();}
function list(p){const n=p.add(0x18).readS32(),a=p.add(0x10).readPointer();if(n<0||n>1000)throw Error('list count');return Array.from({length:n},(_,i)=>a.add(0x20+i*8).readPointer());}
function v(p,n){return Array.from({length:n},(_,i)=>p.add(i*4).readFloat());}
let done=false;
Interceptor.attach(base.add(0x620800),{onEnter(){if(done)return;done=true;try{
 const gm=instance(0x2d53c48),stat=base.add(0x2d58398).readPointer().add(0xb8).readPointer();
 const state=stat.add(0x48).readPointer(),ir=gm.add(0x28).readPointer(),nm=ir.add(0x50).readPointer();
 const pc=ir.add(0x30).readPointer(),npc=list(nm.add(0x38).readPointer());
 const stage=gm.add(0x40).readPointer().add(0x20).readS32(),temp=gm.add(0x30).readPointer();
 const pca=pc.add(0x40).readPointer(),pos=Memory.alloc(12);getPos(transform(pca.add(0x28).readPointer()),pos);
 send({kind:'restore_inventory',frame:frame(),real:real(),data:{pid:Process.id,module:base.toString(),gm:gm.toString(),state:state.toString(),stage,
  storedStage:state.add(0x10).readS32(),playerPosition:v(pos,3),npcManager:nm.toString(),npcCount:npc.length,loaded:nm.add(0x65).readU8(),
  savedNpcCount:state.add(0x40).readPointer().add(0x18).readS32(),reserveCount:state.add(0x28).readPointer().add(0x18).readS32(),
  stop:temp.add(0x14).readU8(),gameOver:temp.add(0x11).readU8(),applierStopped:temp.add(0x10).readU8(),
  npcs:npc.slice(0,3).map(n=>({ptr:n.toString(),nca:n.add(0x30).readPointer().toString(),fixed:n.add(0x30).readPointer().add(0x40).readPointer().add(0x20).readS32()}))}});
}catch(e){send({kind:'restore_inventory_error',error:e.stack});}}});
send({kind:'restore_inventory_ready',pid:Process.id,scope:'read-only main-thread getters/fields; no action or state mutation'});
