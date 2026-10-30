"""Finite controlled native-clone cases; communication only, no off-thread game calls."""
import json,time
from pathlib import Path
ROOT=Path('E:/ManakaREA-NaturalGameplay/TimedBodyPaint/20261030-1')
CASES=['init-0','init-12','init-24','init-25','init-60','init-61','init-120','init-120-reusable','rate-0','rate-025','rate-05','rate-075','wash','item-ordinary-false','item-reusable','item-ordinary-true','load-ordinary','load-reusable','cross-60','cross-24','cross-0']
def records():
    path=ROOT/'managed.jsonl'
    if not path.exists():return []
    result=[]
    for line in path.read_text(encoding='utf8').splitlines():
        try:result.append(json.loads(line))
        except json.JSONDecodeError:break
    return result
def send(command,kind,name=None,timeout=30):
    start=len(records());assert not (ROOT/'command').exists(),'Previous command still pending'
    (ROOT/'command').write_text(command,encoding='utf8');end=time.monotonic()+timeout
    while time.monotonic()<end:
        new=records()[start:]
        if any(r['kind'] in ['runner_error','cleanup_error'] for r in new):raise RuntimeError('Fixture failed; inspect managed.jsonl; do not continue cases')
        if any(r['kind']==kind and (name is None or r['data'].get('name')==name) for r in new):return
        time.sleep(.05)
    raise TimeoutError(command)
def main():
    if not any(r['kind']=='prepared' for r in records()):send('prepare','prepared')
    for name in CASES:
        if not any(r['kind']=='result' and r['data'].get('name')==name for r in records()):send('case '+name,'result',name)
        print(name+' completed',flush=True)
    send('cleanup','cleanup');print('cleanup completed; quit is now permitted',flush=True)
if __name__=='__main__':main()
