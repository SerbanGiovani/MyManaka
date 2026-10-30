"""Run controlled original UI callbacks and wait for native close animations."""
import json,time
from pathlib import Path
ROOT=Path('E:/ManakaREA-NaturalGameplay/PaidSkillBoundary/20261030-3')
def records():
 p=ROOT/'managed.jsonl';return list(map(json.loads,p.read_text(encoding='utf8').splitlines())) if p.exists() else []
def send(command,kind,name=None,timeout=45):
 start=len(records());(ROOT/'command').write_text(command,encoding='utf8');deadline=time.monotonic()+timeout
 while time.monotonic()<deadline:
  rs=records()[start:]
  if any(r['kind']=='runner_error' for r in rs):raise RuntimeError('runner_error; inspect full retained log')
  if any(r['kind']==kind and (name is None or r['data'].get('name')==name) for r in rs):return
  time.sleep(.1)
 raise TimeoutError(command)
def main():
 for name in ['rp-low','rp-exact','max','rank-locked','prerequisite','passive-absent','passive-false']:
  send('case '+name,'case_result',name);print(name+' completed',flush=True)
 send('cleanup','cleanup');print('cleanup completed',flush=True)
if __name__=='__main__':main()
