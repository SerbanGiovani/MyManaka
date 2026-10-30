"""Prepare bounded guards/cctor and cosplay rebuild code for the pinned Iced decoder."""
import hashlib,json,sqlite3,struct
from metadata import HERE,DEFAULT_ROOT,PE
def build():
 path=DEFAULT_ROOT/'GameAssembly.dll';native=path.read_bytes();pe=PE(native);identity=json.loads((HERE/'evidence/artifact-identity.json').read_text(encoding='utf8'));assert hashlib.sha256(native).hexdigest()==identity['native_sha256']
 optional=struct.unpack_from('<I',native,0x3c)[0]+24;rva,size=struct.unpack_from('<II',native,optional+136);offset=pe.offset(pe.base+rva,size);rows=list(struct.iter_unpack('<III',native[offset:offset+size]));by_record={row:i for i,row in enumerate(rows)};roots={};paths={}
 def root(record,seen=()):
  if record in roots:return roots[record]
  assert record not in seen;pos=pe.offset(pe.base+record[2],4);flags,_,count,_=struct.unpack_from('<4B',native,pos);assert flags&7 in (1,2);length=4+((count*2+3)//4)*4;chain=None
  if flags>>3&4:chain=struct.unpack_from('<III',native,pos+length);assert chain in by_record;length+=12
  part=dict(record=[hex(x) for x in record],version=flags&7,file_offset=pos,raw_hex=native[pos:pos+length].hex(),chain=[hex(x) for x in chain] if chain else None);roots[record]=root(chain,(*seen,record)) if chain else record;paths[record]=[part,*paths[chain]] if chain else [part];return roots[record]
 for row in rows:root(row)
 c=sqlite3.connect((HERE/'.cache/methods.sqlite').resolve().as_uri()+'?mode=ro',uri=True);selected=[]
 for mid,extra in [(16807,None),(17984,None),(15018,None),(None,0x180436330),(14786,None)]:
  va=extra if mid is None else int(c.execute('select va from methods where id=?',(mid,)).fetchone()[0],16);containing=[r for r in rows if pe.base+r[0]<=va<pe.base+r[1]];assert len(containing)==1;anchor=root(containing[0])
  for row in rows:
   if root(row)!=anchor:continue
   a,b,_=row;i=by_record[row];selected.append(dict(method_id=mid,requested_va=hex(va),begin=hex(pe.base+a),end_exclusive=hex(pe.base+b),file_offset=pe.offset(pe.base+a,b-a),size=b-a,pdata_file_offset=offset+i*12,pdata_raw_hex=native[offset+i*12:offset+i*12+12].hex(),unwind_chain=paths[row]))
 c.close();decoder=DEFAULT_ROOT/'BepInEx/core/Iced.dll';return dict(native=dict(path=str(path),sha256=identity['native_sha256']),decoder=dict(path=str(decoder),sha256=hashlib.sha256(decoder.read_bytes()).hexdigest()),preparer=dict(path=str(HERE/'prepare_natural_paint_instructions.py'),sha256=hashlib.sha256((HERE/'prepare_natural_paint_instructions.py').read_bytes()).hexdigest()),ranges=selected)
if __name__=='__main__':
 result=build();(HERE/'evidence/natural-paint/decoder-input.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8');print(json.dumps(dict(methods=5,unwind_fragments=len(result['ranges']))))
