"""Select NpcManager and nested declarations, resolving declaring TypeIndex."""
import hashlib
import json
from pathlib import Path
import sqlite3
import struct
import sys

HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parents[1]/'salt'))
from metadata import Metadata,PE,DEFAULT_ROOT


def build():
    data=(DEFAULT_ROOT/'GameAssembly.dll').read_bytes();pe=PE(data)
    md=Metadata((DEFAULT_ROOT/'SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat').read_bytes())
    types=md.records(40,'<16i8H2I');byval={t[2]:i for i,t in enumerate(types)}
    c=sqlite3.connect((HERE.parents[1]/'salt/.cache/methods.sqlite').as_uri()+'?mode=ro',uri=True)
    root_id=c.execute("SELECT id FROM types WHERE full_name='ExposureUnnoticed2.Object3D.NPC.Script.NpcManager'").fetchone()[0]
    selected={root_id}
    while True:
        extra={i for i,t in enumerate(types) if byval.get(t[3]) in selected}-selected
        if not extra:break
        selected|=extra
    methods=[dict(id=i,name=n,va=int(v,16)) for i,n,v in c.execute('SELECT id,qualified_name,va FROM methods WHERE type_id IN ('+','.join('?'*len(selected))+') AND va IS NOT NULL',tuple(selected))]
    opt=struct.unpack_from('<I',data,0x3c)[0]+24;rva,size=struct.unpack_from('<II',data,opt+136)
    offset=pe.offset(pe.base+rva,size);ranges=list(struct.iter_unpack('<III',data[offset:offset+size]));roots={}
    def root(row):
        if row in roots:return roots[row]
        pos=pe.offset(pe.base+row[2],4);flags,_,n,_=struct.unpack_from('<4B',data,pos)
        parent=struct.unpack_from('<III',data,pos+4+((n*2+3)//4)*4) if flags>>3&4 else None
        roots[row]=root(parent) if parent else row;return roots[row]
    anchors={root(row) for m in methods for row in ranges if pe.base+row[0]<=m['va']<pe.base+row[1]}
    chosen=[dict(begin=hex(pe.base+a),end=hex(pe.base+b),pdata_file_offset=offset+i*12,pdata_raw_hex=data[offset+i*12:offset+i*12+12].hex()) for i,row in enumerate(ranges) for a,b,_ in [row] if root(row) in anchors]
    return dict(native_sha256=hashlib.sha256(data).hexdigest(),methods=methods,npc_ranges=chosen)


if __name__=='__main__':
    result=build();(HERE/'.cache').mkdir(exist_ok=True)
    (HERE/'.cache/guard-scan-input.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(methods=len(result['methods']),ranges=len(result['npc_ranges']))))
