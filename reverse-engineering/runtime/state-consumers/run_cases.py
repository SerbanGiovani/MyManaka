"""Issue disposable commands; all game calls execute in the managed Unity-thread runner."""
import json,time
from pathlib import Path
ROOT=Path('E:/ManakaREA-NaturalGameplay/StateConsumers/20261030-3')
def records():
 p=ROOT/'managed.jsonl'
 return list(map(json.loads,p.read_text(encoding='utf8').splitlines())) if p.exists() else []
def send(command,kind,name=None,timeout=25):
 start=len(records());(ROOT/'command').write_text(command,encoding='utf8');deadline=time.monotonic()+timeout
 while time.monotonic()<deadline:
  rs=records()[start:]
  if any(r['kind']=='runner_error' for r in rs):raise RuntimeError('runner error; inspect full retained log')
  if any(r['kind']==kind and (name is None or r['data'].get('name')==name) for r in rs):return
  time.sleep(.1)
 raise TimeoutError(command)
def main():
 if not any(r['kind']=='prepared' for r in records()):
  send('continue','command');time.sleep(3);send('prepare','prepared')
 for item in [100002,100003]:
  send('inventory '+str(item),'result','inventory-'+str(item));print('inventory',item,'completed',flush=True);time.sleep(.7)
 for mode in ['unlearned','disabled','enabled']:
  send('skill '+mode,'result','skill-'+mode);print('skill',mode,'completed',flush=True);time.sleep(.3)
 send('cleanup','cleanup');print('cleanup completed',flush=True)
 send('inventory 0','result','inventory-0');print('ordinary water callback completed',flush=True)
 send('cleanup','cleanup');print('final cleanup completed',flush=True)
if __name__=='__main__':main()
