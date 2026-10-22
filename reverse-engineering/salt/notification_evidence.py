"""Bind native visibility producers; runtime scenarios have separate authority."""
import argparse,json
from metadata import HERE
from scene_evidence import build as bind

def build():
    r=bind(batch_prefix='notification-',reuse_method_ids={15350,15358,15405,15524,15590,17304,17308,17309,14479,15382,15548,15550,14765},
           extra_type_names=('ObjectCullCollider','ObjectCuller','ObjectCullerManager','NpcCullArea','NpcComponentAccessor','NpcAvatarComponent',
                             'NpcController','NpcAnimatorFpsController','AnimatorFPSController','DelayTimeModel','Scheduler','NpcStateModel','PlayerStateModel','FoundStrangerEvent','GameEvent'),
           dispatch_targets=[],resource_boundary='Native visibility and queued-event conditions; separate natural/controlled runtime authority.')
    assert r['new_observations']==10
    r['scope']='Camera-controller trigger regions and Mall daytime distance hiding; camera occlusion is not a visibility transition.'
    return r
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');a=p.parse_args()
    dest=HERE/'evidence/notification-chain.json';r=build()
    if a.check:assert json.loads(dest.read_text(encoding='utf8'))==r
    else:dest.write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(new_observations=r['new_observations'],methods=len(r['methods']))))
