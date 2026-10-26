// Controlled main-thread SaveManager API probe; profile roots restored in finally.
const outputRoot=__OUTPUT_ROOT__;
let route=true,started=false,phase='armed',backupState=null,c=null;
for(const off of [0x4b9b00,0x4b9da0])Interceptor.attach(base.add(off),{onLeave(r){if(!route||r.isNull())return;const original=str(r),name=original.split(/[\\/]/).pop();if(!/^[a-zA-Z0-9_.-]+$/.test(name))throw Error('path component');const path=outputRoot+'/'+name;r.replace(api.string(utf(path)));log('restore_path',{phase,name,path});}});
for(const [off,name] of [[0x49cdf0,'SaveManager.Save'],[0x49d380,'SaveManager.Load']])Interceptor.attach(base.add(off),{onEnter(a){if(phase==='armed'||phase==='done')return;this.record=true;log('restore_native_enter',{phase,name,type:a[0].toInt32(),slot:a[1].toInt32()});},onLeave(){if(this.record)log('restore_native_leave',{phase,name});}});
Interceptor.attach(base.add(0x620800),{onEnter(){if(started)return;started=true;
 try{
  c=context();if(c.temp.add(0x14).readU8()||c.temp.add(0x11).readU8())throw Error('stop/gameover precondition');backupState=backup(c);
  c.temp.add(0x10).writeU8(1);phase='proof-save';log('restore_proof_begin',snapshot(c));
  call(classes.save,ptr(0),'Save',[integer(0),integer(0),integer(0)],0x49cdf0);
  phase='proof-load';log('restore_proof_saved',snapshot(c));
  call(classes.save,ptr(0),'Load',[integer(0),integer(0)],0x49d380);
  log('restore_proof_loaded',snapshot(c));
 }catch(e){log('restore_proof_error',{phase,error:e.stack});}
 finally{
  phase='cleanup';try{if(c&&backupState){restoreGlobals(c,backupState);log('restore_proof_cleanup',snapshot(c));}}catch(e){log('restore_proof_cleanup_error',{error:e.stack});}
  route=false;phase='done';for(const h of roots)api.unroot(h);log('restore_proof_complete',{});
 }
}});
log('restore_proof_ready',{pid:Process.id,scope:'Controlled native SaveManager.Save/Load inside a main-thread hook; isolated file paths; original global roots and two save-mutated scalars restored.'});
