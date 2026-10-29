"""Fingerprint every typed leaf; retain field diffs without publishing full saves."""
import hashlib,json,struct
from prepare import codec,HERE,ROOT,PASSWORD
def key(k):return type(k).__name__+':'+str(k)
def canon(v):
    if isinstance(v,codec.ObjectPairs):
        pairs=sorted([(key(k),canon(x)) for k,x in v.entries]);assert len({k for k,_ in pairs})==len(pairs),'duplicate typed key';return {'pairs':pairs}
    if isinstance(v,list):return [canon(x) for x in v]
    if isinstance(v,float):return {'float32':struct.pack('<f',v).hex()}
    return v
def digest(v):return hashlib.sha256(json.dumps(canon(v),sort_keys=True,ensure_ascii=False,separators=(',',':')).encode('utf8')).hexdigest()
def flatten(v,path=''):
    if isinstance(v,codec.ObjectPairs):
        if not v.entries:return {path:{'empty':'object'}}
        out={}
        for k,x in v.entries:out.update(flatten(x,path+'/'+key(k)))
        return out
    if isinstance(v,list):
        if not v:return {path:{'empty':'array'}}
        out={}
        for i,x in enumerate(v):out.update(flatten(x,path+'/'+str(i)))
        return out
    return {path:canon(v)}
def diff(a,b):
    aa,bb=flatten(a),flatten(b)
    # Python equates True with1; JSON type spellings must remain distinct.
    same=lambda x,y:json.dumps(x,sort_keys=True,ensure_ascii=False)==json.dumps(y,sort_keys=True,ensure_ascii=False)
    return [dict(path=k,before=aa.get(k,{'missing':True}),after=bb.get(k,{'missing':True})) for k in sorted(aa.keys()|bb.keys()) if not same(aa.get(k,{'missing':True}),bb.get(k,{'missing':True}))]
def decode(path):return codec.read(path.read_bytes(),PASSWORD)[1]
def project(path):
    data=path.read_bytes();plain,root,reader=codec.read(data,PASSWORD);members=root.strings();fields={}
    for k,wrapped in members.items():
        value=wrapped.strings()['value']
        if isinstance(value,codec.ObjectPairs):fields[k]={str(f):digest(x) for f,x in value.entries}
    return dict(path=str(path),sha256=hashlib.sha256(data).hexdigest(),bytes=len(data),plaintext_sha256=hashlib.sha256(plain).hexdigest(),typed_tree_sha256=digest(root),root_keys=sorted(members),numeric_key_count=reader.numeric_key_count,leaf_count=len(flatten(root)),fields=fields)
def main():
    directory=ROOT/'captures';variants=json.loads((HERE/'variants.json').read_text(encoding='utf8'))['variants'];files=[project(p) for p in sorted(directory.glob('*.sd'))];cases=[]
    for v in variants:
        name=v['name'];p1=directory/(name+'-pass1.sd');p2=directory/(name+'-pass2.sd')
        if not p1.exists():continue
        original=decode(ROOT/'variants'/(name+'.sd'));one=decode(p1);two=decode(p2);system=diff(decode(directory/(name+'-pass1-system.sd')),decode(directory/(name+'-pass2-system.sd')))
        cases.append(dict(name=name,input_to_first=diff(original,one),first_to_second=diff(one,two),system_first_to_second=system))
    result=dict(schema_version=1,normalization='Typed dictionary keys remain distinct. Object order is ignored only with unique typed keys. Floating values are compared at float32 precision; integer/bool remain typed.',files=files,cases=cases)
    (HERE/'projection.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(json.dumps([dict(name=c['name'],first_changes=len(c['input_to_first']),second_changes=len(c['first_to_second']),system_changes=len(c['system_first_to_second'])) for c in cases]))
if __name__=='__main__':main()
