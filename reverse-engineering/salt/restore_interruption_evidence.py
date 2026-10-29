"""Bind persistent scheduling and the original NPC closure's lifetime checks."""
import argparse
import hashlib
import json
from pathlib import Path
from metadata import HERE
from scene_evidence import build as bind,read
def build():
    r=bind(batch_prefix='restore-interruption',reuse_method_ids={15581,15583,15587,15605,17299,17301,17304,17309,47069},
        extra_type_names=('NpcManager','Scheduler','DelayTimeModel'),dispatch_targets=[],
        resource_boundary='Selected original queue/expiry/closure/destruction paths; controlled timing hold is documented independently.')
    assert r['new_observations']==1
    scheduler=next(t for t in r['named_types'] if t['name']=='ExposureUnnoticed2.Scripts.Base.Scheduler')
    fields={f['name']:f['offset'] for f in scheduler['fields']}
    assert fields['timeModelList']==0x38 and fields['timeRemoveList']==0x40 and fields['timeModelListClone']==0x48
    r['lifetime_findings']=dict(scheduler_persistent_method_id=17299,enqueue_method_id=17301,update_method_id=17304,expiry_method_id=17309,
        closure_method_id=15605,manager_destroy_method_id=15581,
        static_behavior=['Scheduler is created on a DontDestroyOnLoad GameObject','DelayTimeModel keeps the Action as a managed reference',
            'Selected NPC closure checks manager reference nonzero before calling InstantiateNpc','NpcManager.OnDestroy destroys existing NPCs when initialized; this method does not remove the selected time model',
            'Expiry invokes the action before reporting successful completion/removal'],
        limitation='Static statements do not establish actual cancellation, exception/retry behavior or natural reachability; use the separately recorded controlled runtime.')
    r.setdefault('sources',[]).append(dict(path='salt/restore_interruption_evidence.py',sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest()));return r
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');a=p.parse_args();r=build();path=HERE/'evidence/restore-interruption-chain.json'
    if a.check:assert r==read(path)
    else:path.write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(new_static_queries=r['new_observations'],reused=r['reused_observations'])))
