"""Reuse the already queried synchronous cache and cloning paths."""
import argparse
import hashlib
import json
from pathlib import Path
from metadata import HERE
from scene_evidence import build as bind,read

def build():
    r=bind(batch_prefix='drop-cold-cache-no-new-static',reuse_method_ids={16710,16712,16717,16727,15889,16970,16971},
        extra_type_names=('AssetReferencer','DroppedItemManager','DroppedItemController','DropData'),dispatch_targets=[],
        resource_boundary='Manager-cache misses clone already loaded title prefabs. Asset cold-load behavior is not inferred from this consumer.')
    assert r['new_observations']==0
    fields={t['name'].split('.')[-1]:t['fields'] for t in r['named_types']}
    owner=next(u for u in r['usages'] if u['va']=='0x182d58238')
    assert owner['type_name']=='ExposureUnnoticed2.Object3D.IngameManager.AssetReferencer'
    prefab_fields=[f for f in fields['AssetReferencer'] if f['offset'] in (0x320,0x328)]
    assert len(prefab_fields)==2
    clone=read(HERE/'evidence/asset-clone-helpers/native-0x1809f1050-procedure_pseudo_code.json')
    r['cache_findings']=dict(prefab_arrays=prefab_fields,clone_helper=dict(va='0x1809f1050',evidence_id=clone['evidence_id'],path='salt/evidence/asset-clone-helpers/native-0x1809f1050-procedure_pseudo_code.json'),
        prefab_owner=owner,behavior=['Existing live cached object is returned','Cached destroyed Unity object is removed and recreated','Miss selects item prefab from AssetReferencer arrays and clones synchronously','DroppedItemController.Initialize runs before cache insertion/return','Drop activates and applies pose; other-stage Hide may also create a hidden cache object'],
        limitation='Selected ordinary item cache path has no asynchronous asset request. This does not prove missing asset/prefab recovery or high item-ID behavior.')
    r.setdefault('sources',[]).append(dict(path='salt/drop_cache_evidence.py',sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest()))
    return r
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');a=p.parse_args();r=build();path=HERE/'evidence/drop-cache-chain.json'
    if a.check:assert r==read(path)
    else:path.write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(new_static_queries=0,reused=r['reused_observations'])))
