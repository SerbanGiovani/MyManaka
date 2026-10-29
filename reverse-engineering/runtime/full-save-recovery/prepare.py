"""Explicit recovery fixtures; all writes remain below a disposable directory."""
import json,hashlib,sys
from pathlib import Path
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parent/'full-save-restore'))
from project import codec
from prepare import dump
ROOT=Path('E:/ManakaREA-NaturalGameplay/FullSaveRecovery/20261030-2');PASSWORD='unReRU821Drq83'
def main():
    target=ROOT/'variants';target.mkdir(exist_ok=True);game=(ROOT/'captures/baseline.sd').read_bytes();system=(ROOT/'captures/baseline-system.sd').read_bytes();records=[]
    def put(name,data,scope,change):
        path=target/(name+'.sd')
        if data is not None:path.write_bytes(data)
        records.append(dict(name=name,scope=scope,path=str(path) if data is not None else None,sha256=hashlib.sha256(data).hexdigest() if data is not None else None,change=change))
    put('full',game,'game','unmodified baseline');put('missing-game',None,'game','remove main game file');put('missing-system',None,'system','remove system file')
    for key in ['OptionData','TutorialData','RankData','ManualSaveTime']:
        _,v,_=codec.read(system,PASSWORD);v.entries=[(k,x) for k,x in v.entries if k!=key];put('system-missing-'+key,codec.reencrypt(dump(v).encode('utf8'),PASSWORD,system[:16]),'system','remove root '+key)
    _,v,_=codec.read(system,PASSWORD);o=v.strings()['OptionData'].strings()['value'];o.entries=[(k,x) for k,x in o.entries if k!='Language'];put('system-missing-field-Language',codec.reencrypt(dump(v).encode('utf8'),PASSWORD,system[:16]),'system','remove OptionData.Language')
    put('system-truncated',system[:-7],'system','truncate7 ciphertext bytes');put('system-invalid-text',codec.reencrypt(b'{broken',PASSWORD,system[:16]),'system','valid encryption with malformed plaintext')
    damaged=bytearray(game);damaged[16:32]=bytes(x^0x5a for x in damaged[16:32]);put('backup-copy',bytes(damaged),'game','first fail original Load, then original SaveRapper.Copy from valid backup and retry')
    source=Path('E:/ManakaREA-NaturalGameplay/UserData/SaveData/0.sd');put('consumer-advanced',source.read_bytes(),'game','unmodified advanced clone input for original getters')
    (HERE/'variants.json').write_text(json.dumps(dict(variants=records),ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(json.dumps(dict(variants=len(records))))
if __name__=='__main__':main()
