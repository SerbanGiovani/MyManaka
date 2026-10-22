// Read-only diagnostics on the original Unity main-thread input path.
// bool returns use AL (low 8 bits); upper return-register bits are undefined.
const m=Process.getModuleByName('GameAssembly.dll');
function fn(o,r,a){return new NativeFunction(m.base.add(o),r,a);}
const focus=fn(0x1ef9610,'bool',['pointer']);
const keyboard=fn(0x19c6780,'pointer',['pointer']);
const tab=fn(0x19c5e90,'pointer',['pointer','pointer']);
const two=fn(0x19c6100,'pointer',['pointer','pointer']);
const pressed=fn(0x198d100,'bool',['pointer','pointer']);
const action=fn(0x4b1ba0,'pointer',['int','pointer']);
const enabled=fn(0x194aa40,'bool',['pointer','pointer']);
const phase=fn(0x194a980,'int',['pointer','pointer']);
const resolve=new NativeFunction(m.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
const frame=new NativeFunction(resolve(Memory.allocUtf8String('UnityEngine.Time::get_frameCount()')),'int',[]);
let old='',calls=0,positive=0,changes=0;
Interceptor.attach(m.base.add(0x620800),{onEnter(){
 calls++;
 const k=keyboard(ptr(0)),rows=[];
 for(const type of [2,23]){
  const a=action(type,ptr(0));
  rows.push({type,enabled:enabled(a,ptr(0)),phase:phase(a,ptr(0)),controlCount:a.add(0xbc).readS32()});
 }
 const s=JSON.stringify({focus:focus(ptr(0)),keyboard:k.toString(),tab:k.isNull()?null:pressed(tab(k,ptr(0)),ptr(0)),two:k.isNull()?null:pressed(two(k,ptr(0)),ptr(0)),rows});
 if(s!==old&&changes++<150){old=s;send({kind:'keyboard_action_state',frame:frame(),calls,data:JSON.parse(s)});}
 if(calls%600===0&&calls<=18000)send({kind:'input_loop_alive',frame:frame(),calls});
}});
for(const off of [0x4b1530,0x4b1680,0x4b17d0,0x4b18e0,0x4b19f0])Interceptor.attach(m.base.add(off),{
 onEnter(a){this.type=a[0].toInt32();},
 onLeave(r){const b=r.toInt32()&255;if(b&&positive++<300)send({kind:'input_true_bool8',frame:frame(),rva:off,input:this.type,result:b});}
});
send({kind:'input_diagnostics_ready',scope:'Read-only getters and original execution hooks; no Enable/Activate/QueueEvent/gameplay writes'});
