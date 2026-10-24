// Decode bounded original instruction windows only; no hooks or game writes.
const m=Process.getModuleByName('GameAssembly.dll'),base=m.base;
for(const [name,start,end] of [['menu',0x4fa6f0,0x4fac40],['portal',0x61d780,0x61de60]]){
 const rows=[];let p=base.add(start),limit=base.add(end);
 while(p.compare(limit)<0){try{const i=Instruction.parse(p);rows.push({rva:p.sub(base).toString(),size:i.size,mnemonic:i.mnemonic,operands:i.opStr,bytes:Array.from(new Uint8Array(p.readByteArray(i.size)))});p=i.next;}catch(e){send({kind:'guard_decode_error',data:{name,rva:p.sub(base).toString(),error:e.message}});break;}}
 send({kind:'guard_decoded',data:{name,start,end,rows}});
}send({kind:'guard_decode_finished',data:{scope:'Read-only decode of original live native bytes; no hooks.'}});
