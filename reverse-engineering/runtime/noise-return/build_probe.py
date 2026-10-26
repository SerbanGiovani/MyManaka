"""Build a single-listener passive probe from the immutable prior checkpoint."""
from pathlib import Path

HERE = Path(__file__).resolve().parent
source = (HERE.parent / 'noise-callsite/observe-natural.js').read_text(encoding='utf8')
source = source.replace('noise-callsite-natural-finish-20261025', 'noise-return-finish-20261027')
source = source.replace("[[0x435300,'noise-update'],", '[')
assert "[[0x42a300,'push']" in source
needle = "const c=cases.get(nca.toString());if(c){emit('coverage_business_change'"
assert source.count(needle) == 1
source = source.replace(needle, "const c=cases.get(nca.toString());if(scopeForTurn(nca,next))recordTurn(nca,this.returnAddress);if(c){emit('coverage_business_change'")
start = source.index('hook(base.add(0x435300),{onEnter(a){try{this.thread=')
end = source.index('hook(base.add(0x65fb90)', start)
source = source[:start] + r'''
const nativeScopes=new Map(),valueOwners=new Map(),callCounts={entry:0,leave:0,continuation:0,selected:0};
let nativeSequence=0;
function eligibility(nca){const m=nca.add(0x40).readPointer(),n=nca.add(0x60).readPointer(),v=n.add(0x10).readPointer();return {...noiseRead(nca),nca:nca.toString(),count:v.add(0x18).readS32(),rate:v.add(0x10).readFloat(),hidden:m.add(0x84).readU8(),alreadyFound:m.add(0x1d).readU8(),dt:dt(),timeScale:scale()};}
const dt=ic('UnityEngine.Time::get_deltaTime()','float',[]);
function contextOf(s){return {call:s.call,thread:s.thread,nca:s.nca.toString(),id:s.id,entryCaller:s.caller};}
function scopeForTurn(nca,next){const s=nativeScopes.get(Process.getCurrentThreadId());return next===2&&s&&s.nca.equals(nca);}
function recordTurn(nca,ret){const s=nativeScopes.get(Process.getCurrentThreadId());emit('noise_turn',{...contextOf(s),caller:ret.sub(base).toString(),context:noiseScopes.get(s.thread),before:noiseRead(nca),calculation:lastCalculations.get(nca.toString())??null});}
hook(base.add(0x435300),{onEnter(a){
 try{const nca=a[0].add(0x28).readPointer(),thread=Process.getCurrentThreadId(),previous=nativeScopes.get(thread),at=eligibility(nca);
 const s={call:++nativeSequence,thread,nca,id:cases.get(nca.toString())?.id??null,caller:this.returnAddress.sub(base).toString(),previous,selected:false,left:false};
 s.selected=s.id!==null||callCounts.selected<12;
 if(s.selected)callCounts.selected++;callCounts.entry++;this.returnScope=s;nativeScopes.set(thread,s);valueOwners.set(a[0].add(0x10).readPointer().toString(),nca);
 producerStack.set(thread,'noise-update');noiseScopes.set(thread,{nca:nca.toString(),before:at,frame:frame(),call:s.call});
 if(s.selected)emit('return_entry',{...contextOf(s),at});
 if(s.id!==null)emit('noise_update_before',{id:s.id,nca:nca.toString(),...at});
 }catch(e){fail('single-noise-entry',e);}
},onLeave(){try{const s=this.returnScope;if(!s)return;callCounts.leave++;s.left=true;
 if(s.selected)emit('return_onleave',{...contextOf(s),at:eligibility(s.nca)});
 if(s.id!==null)emit('noise_update_after',{id:s.id,nca:s.nca.toString(),...noiseRead(s.nca)});
 // Keep only the continuation's identity, not a stale producer scope.
 noiseScopes.delete(s.thread);producerStack.delete(s.thread);
 }catch(e){fail('single-noise-leave',e);}}});
hook(base.add(0x428bf3),{onEnter(){try{const thread=Process.getCurrentThreadId(),s=nativeScopes.get(thread);if(!s)return;
 callCounts.continuation++;
 if(s.selected)emit('return_continuation',{...contextOf(s),onLeaveSeen:s.left,at:eligibility(s.nca)});
 if(s.previous)nativeScopes.set(thread,s.previous);else nativeScopes.delete(thread);
 noiseScopes.delete(thread);producerStack.delete(thread);
 }catch(e){fail('native-continuation',e);}}});
hook(base.add(0x43f4f0),{onEnter(a){try{const nca=valueOwners.get(a[0].toString()),s=nativeScopes.get(Process.getCurrentThreadId());if(nca&&s&&s.selected&&s.nca.equals(nca)){this.decayScope=s;this.beforeDecay=eligibility(nca);this.freeze=a[1].toInt32();}}catch(e){fail('decay-entry',e);}},onLeave(){try{if(this.decayScope)emit('return_decay',{...contextOf(this.decayScope),before:this.beforeDecay,after:eligibility(this.decayScope.nca),freezeReduction:this.freeze});}catch(e){fail('decay-return',e);}}});
''' + source[end:]
start = source.index('hook(base.add(0x429740),{onEnter(a){try{const scope=noiseScopes')
end = source.index("hook(base.add(0x65e1a0)", start)
source = source[:start] + source[end:]
source = source.replace("if(after.added!==this.before.added||cases.has(this.nca.toString()))", "if(after.added!==this.before.added||cases.has(this.nca.toString()))")
source = source.replace("emit('coverage_finished',{cases:sequence", "emit('return_finished',{...callCounts,scope:'single passive script; native continuation independent of onLeave'});emit('coverage_finished',{cases:sequence")
# Decode the continuation before instrumentation changes its bytes.
needle = 'const nativeScopes=new Map()'
insert = "const continuationWindow=[];for(let p=base.add(0x428bee),i=0;i<8;i++){const row=Instruction.parse(p);continuationWindow.push({rva:p.sub(base).toString(),size:row.size,bytes:Array.from(new Uint8Array(p.readByteArray(row.size))),text:row.toString()});p=row.next;}send({kind:'return_decode',data:{path:mod.path,base:base.toString(),rows:continuationWindow}});\n"
source = source.replace(needle, insert + needle)
assert source.count('hook(base.add(0x435300)') == 1
assert source.count('hook(base.add(0x429740)') == 1
source = source.replace('ordinary noise source pack,', 'single entry/leave/continuation and decay pairing, ordinary noise source pack,')
(HERE / 'observe.js').write_text(source, encoding='utf8')
print('Built observe.js with one listener per noise/state entry')
