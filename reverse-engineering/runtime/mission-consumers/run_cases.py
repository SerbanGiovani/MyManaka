"""Command runner for original mission state consumers, not a natural scene test."""
import json,time
from pathlib import Path
ROOT=Path('E:/ManakaREA-NaturalGameplay/MissionConsumers/20261030-7')
def records():return list(map(json.loads,(ROOT/'managed.jsonl').read_text(encoding='utf8').splitlines()))
def send(command,kind):
 start=len(records());(ROOT/'command').write_text(command,encoding='utf8');deadline=time.monotonic()+20
 while time.monotonic()<deadline:
  rs=records()[start:]
  if any(r['kind']=='runner_error' for r in rs):raise RuntimeError('runner_error; retain diagnostic')
  if any(r['kind']==kind for r in rs):return
  time.sleep(.1)
 raise TimeoutError(command)
def main():
 for name in ['unmet','paused','near-complete','completed']:send('case '+name,'result');print(name+' completed',flush=True)
 send('settle','result');print('settlement completed',flush=True)
 send('cleanup','cleanup');print('cleanup completed',flush=True)
if __name__=='__main__':main()
