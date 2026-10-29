"""Create explicit typed-key save variants in a disposable test profile."""
import hashlib,json,sys
from pathlib import Path
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parents[1]/'salt'))
import save_codec as codec
ROOT=Path('E:/ManakaREA-NaturalGameplay/FullSaveRestore/20261030-1')
PASSWORD='unReRU821Drq83'
def dump(v):
    if isinstance(v,codec.ObjectPairs):return '{'+','.join(dump(k)+':'+dump(x) for k,x in v.entries)+'}'
    if isinstance(v,list):return '['+','.join(map(dump,v))+']'
    return json.dumps(v,ensure_ascii=False,allow_nan=False)
def main():
    target=ROOT/'variants';target.mkdir(exist_ok=True);original=(ROOT/'captures/baseline.sd').read_bytes();source0=Path('E:/ManakaREA-NaturalGameplay/UserData/SaveData/0.sd');records=[]
    def put(name,data,change):
        path=target/(name+'.sd');path.write_bytes(data);records.append(dict(name=name,path=str(path),sha256=hashlib.sha256(data).hexdigest(),bytes=len(data),change=change))
    put('full',original,'unmodified native baseline')
    put('advanced',source0.read_bytes(),'unmodified advanced clone slot0; no natural origin claim')
    for key in ['GameStateData','PlayerCustomData']:
        _,root,_=codec.read(original,PASSWORD);root.entries=[(k,v) for k,v in root.entries if k!=key];put('missing-root-'+key,codec.reencrypt(dump(root).encode('utf8'),PASSWORD,original[:16]),'remove only top-level '+key)
    for key in ['ItemDict','SkillLevel','PlayerPassiveSkillActiveDict','MissionAchieveCountDict','CurrentStageType']:
        _,root,_=codec.read(original,PASSWORD);state=root.strings()['GameStateData'].strings()['value'];state.entries=[(k,v) for k,v in state.entries if k!=key];put('missing-field-'+key,codec.reencrypt(dump(root).encode('utf8'),PASSWORD,original[:16]),'remove only GameStateData.'+key)
    put('truncated',original[:-7],'remove final7 ciphertext bytes')
    corrupted=bytearray(original);corrupted[16:32]=bytes(x^0x5a for x in corrupted[16:32]);put('corrupt-block',bytes(corrupted),'xor first ciphertext block, retaining envelope length')
    put('invalid-text',codec.reencrypt(b'{broken',PASSWORD,original[:16]),'valid encryption with incomplete plaintext syntax')
    (HERE/'variants.json').write_text(json.dumps(dict(baseline_sha256=hashlib.sha256(original).hexdigest(),advanced_source=dict(path=str(source0),sha256=hashlib.sha256(source0.read_bytes()).hexdigest()),variants=records),ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(json.dumps(dict(variants=len(records))))
if __name__=='__main__':main()
