"""Run three selected hair cases, including warm-init boundaries and explicit reconciliation."""
import json,time
from pathlib import Path
ROOT=Path('E:/ManakaREA-NaturalGameplay/AppearanceBoundary/20261030-1')
def records():return [json.loads(l) for l in (ROOT/'managed.jsonl').read_text(encoding='utf8').splitlines()]
def send(command,kind,name=None):
    (ROOT/'command').write_text(command,encoding='utf8');deadline=time.monotonic()+20
    while time.monotonic()<deadline:
        data=records()
        if any(r['kind']=='runner_error' for r in data):raise RuntimeError('runner_error; inspect fixture')
        if any(r['kind']==kind and (name is None or r['data']['name']==name) for r in data):return
        time.sleep(.1)
    raise TimeoutError(command)
def main():
    for name in ["tattoo","oil","combined"]:
        if not any(r['kind']=='result' and r['data']['name']==name for r in records()):send('case '+name,'result',name)
        print(name+' completed',flush=True)
    send('cleanup','cleanup');print('cleanup completed',flush=True)
if __name__=='__main__':main()
