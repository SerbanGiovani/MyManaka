"""Select NPC restore/repopulation PE fragments for float-argument checking."""
import hashlib
import json
from pathlib import Path
import sqlite3
import struct

from metadata import HERE, DEFAULT_ROOT, PE


def main():
    path=DEFAULT_ROOT/'GameAssembly.dll';native=path.read_bytes()
    identity=json.loads((HERE/'evidence/artifact-identity.json').read_text(encoding='utf8'))
    assert hashlib.sha256(native).hexdigest()==identity['native_sha256']
    pe=PE(native);optional=struct.unpack_from('<I',native,0x3c)[0]+24
    rva,size=struct.unpack_from('<II',native,optional+136);offset=pe.offset(pe.base+rva,size)
    rows=list(struct.iter_unpack('<III',native[offset:offset+size]));indices={r:i for i,r in enumerate(rows)}
    roots,chains={},{}
    def root(row,visited=()):
        if row in roots:return roots[row]
        assert row not in visited
        pos=pe.offset(pe.base+row[2],4);flags,_,count,_=struct.unpack_from('<4B',native,pos)
        assert flags&7 in (1,2)
        length=4+((count*2+3)//4)*4;parent=None
        if (flags>>3)&4:
            parent=struct.unpack_from('<III',native,pos+length);assert parent in indices;length+=12
        part=dict(record=[hex(v) for v in row],version=flags&7,file_offset=pos,
            raw_hex=native[pos:pos+length].hex(),chain=[hex(v) for v in parent] if parent else None)
        roots[row]=root(parent,(*visited,row)) if parent else row
        chains[row]=[part,*chains[parent]] if parent else [part]
        return roots[row]
    for row in rows:root(row)
    c=sqlite3.connect((HERE/'.cache/methods.sqlite').as_uri()+'?mode=ro',uri=True)
    selected=[]
    for mid in (15583,15585):
        va=int(c.execute('SELECT va FROM methods WHERE id=?',(mid,)).fetchone()[0],16)
        containing=[r for r in rows if pe.base+r[0]<=va<pe.base+r[1]];assert len(containing)==1
        anchor=root(containing[0])
        for row in rows:
            if root(row)!=anchor:continue
            a,b,_=row;i=indices[row]
            selected.append(dict(method_id=mid,requested_va=hex(va),begin=hex(pe.base+a),
                end_exclusive=hex(pe.base+b),file_offset=pe.offset(pe.base+a,b-a),size=b-a,
                pdata_file_offset=offset+i*12,pdata_raw_hex=native[offset+i*12:offset+i*12+12].hex(),
                unwind_chain=chains[row]))
    c.close();decoder=DEFAULT_ROOT/'BepInEx/core/Iced.dll'
    result=dict(native=dict(path=str(path),sha256=identity['native_sha256']),
        decoder=dict(path=str(decoder),sha256=hashlib.sha256(decoder.read_bytes()).hexdigest()),
        preparer=dict(path=str(Path(__file__).resolve()),sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest()),ranges=selected)
    (HERE/'.cache/restore-decoder-input.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(methods=2,unwind_fragments=len(selected))))


if __name__=='__main__':main()
