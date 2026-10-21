// Additional bounded observer: first two countdown calls, pause/resume edges and expiry.
// Loaded partway through the matrix. Coverage is explicitly marked by ordering_ready.
const mod=Process.getModuleByName('GameAssembly.dll'), base=mod.base;
const resolve=new NativeFunction(mod.getExportByName('il2cpp_resolve_icall'),'pointer',['pointer']);
function get(name,ret){return new NativeFunction(resolve(Memory.allocUtf8String(name)),ret,[]);}
const frame=get('UnityEngine.Time::get_frameCount()','int'),time=get('UnityEngine.Time::get_time()','float');
const dt=get('UnityEngine.Time::get_deltaTime()','float');
function emit(kind,data){send({kind,frame:frame(),time:time(),data});}
let eventFrame=-1,callbackFrame=-1;
Interceptor.attach(base.add(0x41a730),{onEnter(){eventFrame=frame();}});
Interceptor.attach(base.add(0x41a870),{onEnter(){callbackFrame=frame();}});
Interceptor.attach(base.add(0x4b4040),{
    onEnter(){this.f=frame();if(this.f===eventFrame||this.f===eventFrame+1)emit('scheduler_begin',{});},
    onLeave(){if(this.f===eventFrame||this.f===eventFrame+1||this.f===callbackFrame)emit('scheduler_end',{});}
});
const models=new Map();
Interceptor.attach(base.add(0x4b5050),{
    onEnter(args){
        this.model=null;
        const p=args[0]; if(Math.abs(p.add(0x18).readFloat()-0.6)>1e-6)return;
        const key=p.toString(),remain=p.add(0x20).readFloat();
        let s=models.get(key);
        // GC may reuse an old model address: a new initial 0.6 begins a fresh generation.
        if(!s || (remain>0.59999 && s.prev<0.59))s={count:0,prev:null,held:false};
        s.count++;
        const held=s.prev!==null&&remain===s.prev&&remain>0;
        const resumed=s.held&&!held;
        this.should=s.count<=2 || held!==s.held || resumed || (remain>0&&remain<=dt());
        this.model=p; this.before=remain; this.s=s;
        s.held=held;s.prev=remain;models.set(key,s);
    },
    onLeave(){if(this.model&&this.should)emit('countdown_step',{model:this.model.toString(),before:this.before,after:this.model.add(0x20).readFloat(),dt:dt(),call:this.s.count});}
});
emit('ordering_ready',{});
