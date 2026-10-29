"""Dispatch each explicit recovery fixture and await its terminal record."""
import json,time
from pathlib import Path
HERE=Path(__file__).resolve().parent
ROOT=Path('E:/ManakaREA-NaturalGameplay/FullSaveRecovery/20261030-2')
def main():
    for entry in json.loads((HERE/'variants.json').read_text(encoding='utf8'))['variants']:
        name=entry['name'];(ROOT/'command').write_text('case '+name,encoding='utf8');deadline=time.monotonic()+30
        while time.monotonic()<deadline:
            records=[json.loads(l) for l in (ROOT/'managed.jsonl').read_text(encoding='utf8').splitlines()]
            if any(r['kind']=='runner_error' for r in records):raise RuntimeError('runner_error; inspect logs')
            if any(r['kind']=='case_end' and r['data']['name']==name for r in records):
                print(json.dumps(dict(case=name,result='exception' if any(r['kind']=='case_exception' and r['data']['name']==name for r in records) else 'two-native-passes')),flush=True);break
            time.sleep(.2)
        else:raise TimeoutError(name)
if __name__=='__main__':main()
