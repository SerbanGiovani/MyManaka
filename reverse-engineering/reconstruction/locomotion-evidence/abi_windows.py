"""Verify finite x64 byte windows where recovered float call arguments are missing.

The mnemonics are explicit analyst decoding, not output from another disassembler.
No code is executed. Full Ghidra dossier and its body-coverage limits are linked.
"""
import sys
sys.dont_write_bytecode=True
import argparse
import hashlib
import json
import struct
from pathlib import Path
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parents[1]/'salt'))
from metadata import PE

def build():
    p=Path('E:/SecretFlasherManakaREA/GameAssembly.dll');raw=p.read_bytes();pe=PE(raw)
    sha=hashlib.sha256(raw).hexdigest();assert sha=='6003033049ac32e8712dc4101382534e21d65b97100c167ebec6bbca1462c18d'
    dossier_path=HERE/'native-decoded-code/14526-06000c75-analyze_function.json'
    ev=json.loads(dossier_path.read_text(encoding='utf8'))
    def instruction(va,hexbytes,text):
        code=bytes.fromhex(hexbytes);off=pe.offset(va,len(code));assert raw[off:off+len(code)]==code,(hex(va),text)
        return {'va':hex(va),'file_offset':off,'raw_hex':code.hex(' '),'analyst_decoded_instruction':text}
    target=[instruction(0x18062cccb,'48 8b 8b a0 00 00 00','MOV RCX, qword ptr [RBX+0xA0]'),instruction(0x18062ccd2,'48 85 c9','TEST RCX, RCX'),instruction(0x18062ccd5,'0f 84 5d 09 00 00','JZ 0x18062d638'),instruction(0x18062ccdb,'f3 0f 10 4b 10','MOVSS XMM1, dword ptr [RBX+0x10]'),instruction(0x18062cce0,'45 33 c0','XOR R8D, R8D'),instruction(0x18062cce3,'e8 08 88 e8 ff','CALL 0x1804b54f0 (SmoothFloat.UpdateTo)')]
    call=target[-1];off=call['file_offset'];assert int(call['va'],16)+5+struct.unpack_from('<i',raw,off+1)[0]==0x1804b54f0
    output=[instruction(0x18062d031,'48 8b 93 a0 00 00 00','MOV RDX, qword ptr [RBX+0xA0]'),instruction(0x18062d041,'48 8b 7b 30','MOV RDI, qword ptr [RBX+0x30]'),instruction(0x18062d055,'f3 0f 10 72 10','MOVSS XMM6, dword ptr [RDX+0x10]'),instruction(0x18062d068,'8b 31','MOV ESI, dword ptr [RCX] (static field offset 0: MoveSpeed/Speed ID)'),instruction(0x18062d08b,'0f 28 d6','MOVAPS XMM2, XMM6'),instruction(0x18062d08e,'8b d6','MOV EDX, ESI'),instruction(0x18062d090,'48 8b cf','MOV RCX, RDI'),instruction(0x18062d093,'ff d0','CALL RAX (resolved Animator.SetFloatID ICall)')]
    windows=[]
    for va,size,purpose in [(0x18062cccb,29,'moveSpeedBlend.UpdateTo TargetMoveSpeed argument'),(0x18062d031,100,'Speed SetFloatID Current value argument')]:
        off=pe.offset(va,size);data=raw[off:off+size];windows.append({'purpose':purpose,'va':hex(va),'file_offset':off,'byte_length':size,'sha256':hashlib.sha256(data).hexdigest(),'raw_hex':data.hex(' ')})
    return {'schema_version':1,'evidence_type':'finite original x64 byte windows with explicit analyst decoding','authority':'shipped-artifact bytes; analyst-derived instruction interpretation','native_path':str(p),'native_sha256':sha,'rea_dossier':{'path':str(dossier_path),'evidence_id':ev['evidence_id'],'sha256':hashlib.sha256(dossier_path.read_bytes()).hexdigest(),'observed_body':ev['normalized_result']['procedure']['body'],'high_pcode_operations':len(ev['normalized_result']['native_value_flow']['operations']),'high_pcode_truncated':ev['normalized_result']['native_value_flow']['truncated']},'windows':windows,'target_argument_instructions':target,'speed_output_instructions':output,'field_bindings':{'manager_RBX+0x10':'TargetMoveSpeed','manager_RBX+0x24':'baseMoveSpeed','manager_RBX+0x30':'Animator','manager_RBX+0xA0':'moveSpeedBlend','SmoothFloat+0x10':'Current','source':'../../salt/evidence/player-chain.json and native-contract.json'},'derived_conclusion':'The normal path passes TargetMoveSpeed directly in XMM1 to moveSpeedBlend.UpdateTo. It passes moveSpeedBlend.Current directly in XMM2 to Animator.SetFloatID(Speed). Neither of these two finite paths applies baseMoveSpeed multiplication.','limitations':['Analyst x64 decoding is finite and backed by asserted bytes, not an independent full disassembler.','The Ghidra seeded OnUpdate body remains one byte and its assembly listing covers only one instruction even after explicit code seeding. High-p-code/pseudocode follows more code and recovers call sites but drops float call bindings; neither is advertised as complete assembly coverage.','The output window also contains ICall-resolution control flow; the linked Ghidra pseudocode identifies SetFloatID and its static parameter ID.','This is static calling-convention reasoning, not an executed register observation.']}

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--check',action='store_true');a=ap.parse_args();d=build();out=HERE/'abi-windows.json'
    if a.check:assert json.loads(out.read_text(encoding='utf8'))==d
    else:out.write_text(json.dumps(d,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps({'status':'consistent' if a.check else 'written','windows':len(d['windows']),'instructions':len(d['target_argument_instructions'])+len(d['speed_output_instructions'])}))

if __name__=='__main__':main()
