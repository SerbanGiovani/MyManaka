"""Project both game/system roundtrips and independent expected getter values."""
import sys,json
from pathlib import Path
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parent/'full-save-restore'))
from project import project,decode,diff,codec
ROOT=Path('E:/ManakaREA-NaturalGameplay/FullSaveRecovery/20261030-2')
def expected(root):
    s=root.strings()['GameStateData'].strings()['value'].strings();skills=dict(s['SkillLevel'].entries);active=dict(s['PlayerPassiveSkillActiveDict'].entries);items=dict(s['ItemDict'].entries);missions=dict(s['MissionAchieveCountDict'].entries)
    return dict(skills=[dict(id=i,level=skills[i],active=skills[i]>0 and active.get(i,False)) for i in [0,1,17,21,22,24]],items=[dict(id=i,carried=items.get(i,0)>0) for i in [10001,10002,10003]],missions=[dict(id=i,count=missions.get(i,0)) for i in [0,1,2]])
def build():
    directory=ROOT/'captures';records=json.loads((HERE/'variants.json').read_text(encoding='utf8'))['variants'];files=[project(p) for p in sorted(directory.glob('*.sd'))];cases=[]
    for r in records:
        n=r['name'];p1=directory/(n+'-pass1.sd');p2=directory/(n+'-pass2.sd')
        if not p1.exists():continue
        one,two=decode(p1),decode(p2);s1,s2=decode(directory/(n+'-pass1-system.sd')),decode(directory/(n+'-pass2-system.sd'));base_game=decode(directory/'baseline.sd');base_system=decode(directory/'baseline-system.sd')
        if n=='consumer-advanced':base_game=decode(Path(r['path']))
        cases.append(dict(name=n,game_baseline_to_first=diff(base_game,one),system_baseline_to_first=diff(base_system,s1),game_first_to_second=diff(one,two),system_first_to_second=diff(s1,s2),expected_consumers=expected(one)))
    return dict(schema_version=1,files=files,cases=cases,scope='All stored fields and selected original getters; no appearance-renderer or active mission-update equivalence claim.')
if __name__=='__main__':
    result=build();(HERE/'projection.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(json.dumps([dict(name=c['name'],game_first=len(c['game_baseline_to_first']),game_second=len(c['game_first_to_second']),system_second=c['system_first_to_second']) for c in result['cases']]))
