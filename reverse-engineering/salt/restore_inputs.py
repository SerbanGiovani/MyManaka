"""Check stored restore inputs and classify selected static drop guards.

Does not instantiate game objects, execute callbacks or simulate restoration.
"""
import argparse
import hashlib
import json
import math
from pathlib import Path
import struct

from metadata import HERE
from save_codec import ObjectPairs, read as read_save


def read(p):return json.loads(p.read_text(encoding='utf-8-sig'))


def pose(value,keys):
    assert isinstance(value,ObjectPairs)
    fields=value.strings();assert set(fields)==set(keys)
    for key in keys:
        number=fields[key]
        assert isinstance(number,(int,float)) and not isinstance(number,bool) and math.isfinite(number)
        encoded=struct.pack('<f',number)
        assert math.isfinite(struct.unpack('<f',encoded)[0])


def summarize(state):
    assert isinstance(state,ObjectPairs)
    s=state.strings();current=s['CurrentStageType']
    assert isinstance(current,int) and not isinstance(current,bool)
    pose(s['PlayerPosition'],'xyz');pose(s['PlayerRotation'],'xyzw')
    npcs=s['NpcSaveDataList'];assert isinstance(npcs,list)
    existing=0
    for record in npcs:
        n=record.strings();assert set(n)=={'Position','Rotation','IsExist'}
        assert isinstance(n['IsExist'],bool)
        pose(n['Position'],'xyz');pose(n['Rotation'],'xyzw');existing+=n['IsExist']
    drops=s['DropDataDict'];assert isinstance(drops,ObjectPairs)
    counts=dict(records=0,not_dropped_untouched=0,current_stage_drop_calls=0,other_stage_hide_calls=0)
    seen=set()
    def drop(record):
        d=record.strings()
        assert set(d)=={'IsDropped','IsReserve','IsViewCompassInDroneMission','Position','Rotation','StageType','ItemType'}
        assert all(isinstance(d[k],bool) for k in ('IsDropped','IsReserve','IsViewCompassInDroneMission'))
        assert all(isinstance(d[k],int) and not isinstance(d[k],bool) for k in ('StageType','ItemType'))
        pose(d['Position'],'xyz');pose(d['Rotation'],'xyzw')
        return d
    for key,record in drops.entries:
        assert isinstance(key,int) and not isinstance(key,bool) and key not in seen
        seen.add(key);d=drop(record);assert key==d['ItemType']
        counts['records']+=1
        if not d['IsDropped']:counts['not_dropped_untouched']+=1
        elif d['StageType']==current:counts['current_stage_drop_calls']+=1
        else:counts['other_stage_hide_calls']+=1
    reserve=s['ReserveDropList'];assert isinstance(reserve,list)
    matched=sum(drop(row)['StageType']==current for row in reserve)
    for name in ('LoadoutDatas','LoadoutCustomizeDatas'):assert isinstance(s[name],list)
    return dict(player_pose_finite_float32=True,npc_records=len(npcs),npc_existing_before_elevator_filter=existing,
        npc_elevator_filter_not_evaluated=existing>0,drop_activation_guards=counts,
        reserve_records=len(reserve),reserve_matching_stage_before_random_position=matched,
        loadout_counts={n:len(s[n]) for n in ('LoadoutDatas','LoadoutCustomizeDatas')},
        boundary='Counts follow selected metadata-backed predicates only; no engine objects, elevator bounds, random positions or callback outcomes are evaluated.')


def build():
    validation=read(HERE/'evidence/save-codec-validation.json')
    settings=read(HERE.parent/'assets/save-settings.json')
    password=settings['defaults_object']['settings']['encryptionPassword']['value']
    rows=[]
    for sample in validation['samples']:
        p=Path(sample['sample']['snapshot_path']);data=p.read_bytes()
        assert hashlib.sha256(data).hexdigest()==sample['encrypted_sha256']
        _,root,_=read_save(data,password);roots=root.strings()
        if 'GameStateData' not in roots:continue
        s=roots['GameStateData'].strings()['value']
        rows.append(dict(snapshot_sha256=sample['encrypted_sha256'],**summarize(s)))
    counts={name:sum(r['drop_activation_guards'][name] for r in rows) for name in
        ('records','not_dropped_untouched','current_stage_drop_calls','other_stage_hide_calls')}
    paths=[HERE/'restore_inputs.py',HERE/'save_codec.py',HERE/'evidence/save-codec-validation.json',
           HERE.parent/'assets/save-settings.json']
    return dict(schema_version=1,evidence_type='Read-only stored input checks and selected static guard projections; not runtime restoration',
        samples=rows,summary=dict(game_snapshots=len(rows),npc_records=sum(r['npc_records'] for r in rows),
            reserve_records=sum(r['reserve_records'] for r in rows),drop_activation_guards=counts,
            all_loadout_lists_have21=all(all(n==21 for n in r['loadout_counts'].values()) for r in rows)),
        sources=[dict(path=p.relative_to(HERE.parent).as_posix(),sha256=hashlib.sha256(p.read_bytes()).hexdigest()) for p in paths],
        limitations=['The eight prior encrypted samples contain seven game snapshots, all with empty NPC and reserve-drop lists.',
            'Three dropped records occur only in one backup and belong to another stage; no current-stage active-drop case is demonstrated.',
            'Pose checks validate stored finite Single-compatible values, not collision, NavMesh or restored transforms.',
            'Synthetic tests of nonempty branches remain structural examples and are never counted as natural or native coverage.'])


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--check',action='store_true');args=p.parse_args()
    result=build();out=HERE/'evidence/state-restore-inputs.json'
    if args.check:assert read(out)==result
    else:out.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(status='consistent' if args.check else 'written',**result['summary'])))


if __name__=='__main__':main()
