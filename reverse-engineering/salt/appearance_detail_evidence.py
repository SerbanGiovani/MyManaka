"""Bind reused native appearance methods and selected original face channels."""
import argparse,hashlib,json,re
from pathlib import Path
from metadata import HERE
from scene_evidence import build as bind,read
def build():
    r=bind(batch_prefix='appearance-detail-',reuse_method_ids={14602,14632,14636,14847,15075,14769,16970,16971},extra_type_names=('PlayerCustomData','PlayerBodyCustomizeAdjuster','PlayerBoneScaleAdjuster','PlayerFaceController','HairCustomAdjuster'),dispatch_targets=[],resource_boundary='Selected appearance reference/disturb/native-load/runtime recovery; no new static query.')
    assert r['new_observations']==0
    source=HERE/'evidence/state-restore-tail/14847-06000db6-procedure_pseudo_code.pseudocode.c'
    indices=list(dict.fromkeys(int(x,0) for x in re.findall(r'\)\(lVar3,(0x[0-9a-f]+|[0-9]+)\)',source.read_text(encoding='utf8'))))
    assert indices==read(HERE.parent/'runtime/appearance-detail/shape-indices.json')['indices'] and len(indices)==40
    r['face_channels']=dict(indices=indices,source='salt/evidence/state-restore-tail/'+source.name,source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),boundary='Native face-method selected indices; fixture measures resulting weights instead of assuming missing decompiler float arguments.')
    r.setdefault('sources',[]).append(dict(path='salt/appearance_detail_evidence.py',sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest()))
    return r
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');a=p.parse_args();r=build();path=HERE/'evidence/appearance-detail-chain.json'
    if a.check:assert r==read(path)
    else:path.write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(new_queries=0,reused=r['reused_observations'],face_channels=40)))
