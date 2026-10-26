// One controlled fixture precondition, on the Unity thread, before native snapshot.
// ApplyGameState grows/reuses a high-water list instead of shrinking it.
const mod=Process.getModuleByName('GameAssembly.dll'),base=mod.base;
let applied=false;
Interceptor.attach(base.add(0x4320d0),{onEnter(a){
 if(applied)return;
 const nm=a[0],live=nm.add(0x38).readPointer(),n=live.add(0x18).readS32();
 if(n!==3)return;
 const gm=base.add(0x2d53c48).readPointer().add(0xb8).readPointer().readPointer();
 if(gm.isNull()||gm.add(0x30).readPointer().add(0x10).readU8()!==1)throw Error('fixture applier guard');
 const state=base.add(0x2d58398).readPointer().add(0xb8).readPointer().add(0x48).readPointer(),saved=state.add(0x40).readPointer(),before=saved.add(0x18).readS32();
 saved.add(0x18).writeS32(0);saved.add(0x1c).writeS32(saved.add(0x1c).readS32()+1);applied=true;
 send({kind:'controlled_fixture_list_reset',data:{pid:Process.id,liveCount:n,oldSavedCount:before,savedCount:saved.add(0x18).readS32(),scope:'explicit fixture list length/version only; native ApplyGameState creates all records'}});
}});
send({kind:'controlled_fixture_ready',data:{pid:Process.id,module:mod.path}});
