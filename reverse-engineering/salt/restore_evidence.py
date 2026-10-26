"""Bind selected save-to-runtime consumers, callbacks and float-delay arguments."""
import argparse
import hashlib
import json

from metadata import HERE, DEFAULT_ROOT, PE
from scene_evidence import build as bind, read


def fingerprint(p):
    return dict(path=p.relative_to(HERE.parent).as_posix(),sha256=hashlib.sha256(p.read_bytes()).hexdigest())


def build():
    result=bind(batch_prefix='state-restore-',reuse_method_ids={16862,16868,16825,14756,14763,14715,14964,
        16971,16969,15587,15588,15518,15532,15598,16710,17301,17304,18689},
        extra_type_names=('DebugController','GameState','Events','ChangeBodyEvent','NpcManager','NpcSaveData',
            'DropData','DropItemType','DroppedItemManager','DroppedItemController','PlayerController',
            'PlayerClassAccessor','PlayerBodyCustomizeAdjuster','PlayerBodyMaterialController','PlayerFaceController',
            'HairCustomAdjuster','PlayerBoneScaleAdjuster','ElevatorController','StageController','StageRandomPositionManager',
            'PlayerAnimationManager','PortalManager','NpcSpawnInterval','StageTransController'),
        dispatch_targets=[],resource_boundary='Selected static restore consumers and snapshot-input projections; no native load/save roundtrip.')
    new=[m for m in result['methods'] if m['new_this_round']]
    assert len(new)==result['new_unique_procedure_addresses']==result['new_unique_evidence_ids']==50
    by_id={}
    for m in result['methods']:by_id.setdefault(m['method_id'],[]).append(m)
    usages={u['va']:u for u in result['usages']}
    def selected(mid):
        candidates=by_id[mid]
        return next((m for m in candidates if m['new_this_round']),candidates[0])
    def code(mid):return read(HERE.parent/selected(mid)['path'])['normalized_result']
    def field(owner,name):
        typ=next(t for t in result['named_types'] if t['name']==owner or t['name'].endswith('.'+owner))
        f=next(f for f in typ['fields'] if f['name']==name)
        return dict(type_id=typ['type_id'],owner=typ['name'],**f)
    result['restore_fields']=[field(owner,name) for owner,name in (
        ('GameStateData','CurrentStageType'),('GameStateData','PlayerPosition'),('GameStateData','PlayerRotation'),
        ('GameStateData','NpcSaveDataList'),('GameStateData','DropDataDict'),('GameStateData','ReserveDropList'),
        ('GameStateData','LoadoutDatas'),('GameStateData','LoadoutCustomizeDatas'),
        ('NpcManager','initialized'),('NpcManager','isLoadedData'),('NpcManager','fixedNpcCount'),('NpcManager','spawnNum'),
        ('NpcSaveData','IsExist'),('NpcSaveData','Position'),('NpcSaveData','Rotation'),
        ('DropData','IsDropped'),('DropData','IsReserve'),('DropData','StageType'),('DropData','ItemType'),
        ('DropData','Position'),('DropData','Rotation'),('DebugController','IsForceCreateNpc'),
        ('Events','ChangeBodyEvent'))]
    result['npc_restore_delegate']=dict(producer_method_id=15583,delegate_usage=usages['0x182d59548'],
        closure_type_usage=usages['0x182d59540'],callback_method_id=15605,
        callback_evidence_id=selected(15605)['evidence_id'],target_method_id=15587,
        arguments=dict(npcSaveData='captured record reference',isRandomPathSpawn=False,fixedType=0))
    assert result['npc_restore_delegate']['delegate_usage']['method_id']==15605
    result['npc_repop_delegate']=dict(producer_method_id=15585,delegate_usage=usages['0x182d594e0'],
        callback_method_id=15603,callback_evidence_id=selected(15603)['evidence_id'],target_method_id=15587,
        arguments=dict(npcSaveData=None,isRandomPathSpawn=True,fixedType=0))
    assert result['npc_repop_delegate']['delegate_usage']['method_id']==15603
    assert usages['0x182d59260']['type_name'].endswith('.ElevatorController')
    result['elevator_filter']=dict(singleton_helper_va='0x180436630',type_usage=usages['0x182d59260'],
        finding='OnLoadData skips an existing saved record inside the available elevator Bounds; otherwise it queues the captured reference.')
    body_spec=usages['0x182d582e8']
    assert body_spec['method_spec']['method_id']==17245
    assert body_spec['method_spec']['method_instantiation']['arguments'][0]['type_name'].endswith('.ChangeBodyEvent')
    listeners=[]
    for initialize,callback in ((14598,14602),(14620,14625),(14630,14632),(14840,14847),(15074,15075)):
        method=selected(initialize)
        callbacks=[usages[v] for v in method['usage_vas'] if usages[v].get('method_id')==callback]
        assert callbacks and body_spec['va'] in method['usage_vas']
        listeners.append(dict(initialize_method_id=initialize,initialize_evidence_id=method['evidence_id'],
            callback_method_id=callback,callback_evidence_id=selected(callback)['evidence_id'],
            callback_delegate_usages=callbacks,add_listener_method_spec_usage=body_spec['va']))
    result['body_restore_event']=dict(producer_method_id=14769,producer_evidence_id=selected(14769)['evidence_id'],
        static_event_field=field('Events','ChangeBodyEvent'),listener_method_spec=body_spec,listeners=listeners,
        post_broadcast_move_speed_copy=dict(source=field('PlayerBodyCustomizeAdjuster','<MoveSpeed>k__BackingField'),
            destination=field('PlayerAnimationManager','baseMoveSpeed')),
        deferred_bone_callback_method_id=14636,
        boundary='Original declared registration/consumer paths; actual listener order and rendered results are not measured.')
    # Verify original bytes for the two random-delay call sites rather than
    # trusting Ghidra's omitted/undefined floating-point arguments.
    instruction_path=HERE/'symbols/state-restore-instructions.json'
    instruction_input=read(instruction_path)
    native=(DEFAULT_ROOT/'GameAssembly.dll').read_bytes();pe=PE(native)
    assert hashlib.sha256(native).hexdigest()==result['native_sha256']==instruction_input['native']['sha256']
    count=0;sites=[]
    for part in instruction_input['ranges']:
        end=int(part['begin'],16)
        for row in part['instructions']:
            pos=pe.offset(int(row['va'],16),row['length'],executable=True)
            assert int(row['va'],16)==end and native[pos:pos+row['length']]==bytes.fromhex(row['raw_hex'])
            end+=row['length'];count+=1
        assert end==int(part['end_exclusive'],16)
        assert native[part['pdata_file_offset']:part['pdata_file_offset']+12]==bytes.fromhex(part['pdata_raw_hex'])
        for chain in part['unwind_chain']:
            raw=bytes.fromhex(chain['raw_hex']);assert native[chain['file_offset']:chain['file_offset']+len(raw)]==raw
        indices=[i for i,r in enumerate(part['instructions']) if r['direct_branch_target']=='0x1804b3d40']
        assert len(indices)==1
        i=indices[0];window=part['instructions'][i-4:i+1]
        assert window[2]['text'].lower()=='movaps xmm1,xmm0'
        sites.append(dict(method_id=part['method_id'],scheduler_method_id=17301,instructions=window,
            finding='Random.value return in XMM0 is moved directly to XMM1 for DelayUnscaledTime; no multiplier intervenes in this call window.'))
    result['restore_delay_abi']=dict(source=fingerprint(instruction_path),instructions_verified=count,sites=sites,
        instruction_sources=[instruction_input[k] for k in ('decoder','preparer','parser')])
    assert count==557
    result['selected_restore_order']=[
        dict(method_ids=[16971,16862,14763],finding='Load produces GameState data; startup compares current StageController stage before applying stored player pose via Warp. Stage mismatch updates stored stage instead.'),
        dict(method_ids=[16868,15583,15605,15587,15518],finding='Startup callback selects OnLoadData unless DebugController.IsForceCreateNpc requests repopulation; eligible saved NPC records are queued individually.'),
        dict(method_ids=[16825,17059,14763,15582,15585,15603],finding='Stage-completion path selects portal spawn pose, warps player and requests fresh NPC repopulation; it is distinct from saved-record restore.'),
        dict(method_ids=[16707,16727,16712,16717],finding='Dropped-item cache construction/activation reads IsDropped and stage; matching records invoke Drop, other-stage dropped records invoke Hide, and not-dropped records are untouched by this selected loop.'),
        dict(method_ids=[16715,16711,16732,17067,18301],finding='Reserved drop callback checks stage, clears IsReserve, selects a random placement, drops/registers compass target and returns success for removal from pending list.'),
        dict(method_ids=[14756,14769,14602,14625,14632,14847,15075],finding='Delayed initialization broadcasts ChangeBodyEvent to selected generic typed listeners; bone adjustment defers an additional frame.'),
        dict(method_ids=[16813,16814,16971],finding='Default loadout factories create20 entries, while the selected load compatibility loops pad through index20; covered samples contain21 entries in both lists.')]
    inputs_path=HERE/'evidence/state-restore-inputs.json'
    result['stored_input_checks']=dict(source=fingerprint(inputs_path),summary=read(inputs_path)['summary'])
    dependencies=['salt/restore_evidence.py','salt/restore_inputs.py','salt/test_restore_inputs.py',
        'salt/prepare_restore_instructions.py','salt/decode_npc_fps.ps1','salt/symbols/state-restore-instructions.json',
        'salt/scene_evidence.py','salt/metadata.py','salt/prepare_loading.py','salt/run_batch.mjs',
        'salt/save_codec.py','salt/evidence/state-restore-inputs.json','salt/evidence/save-codec-validation.json']
    for batch in ('core','tail'):
        dependencies.extend(['salt/symbols/state-restore-'+batch+suffix for suffix in ('.plan.json','.seeds.tsv')])
    result['dependencies']=[fingerprint(HERE.parent/p) for p in dependencies]
    result['scope']='Selected NPC, dropped-item, player-pose and body-customization restoration, guarded against conflating stage transitions, debug repopulation and saved-record restore.'
    result['limitations'] += ['All seven encrypted game snapshots have empty NPC/reserve lists, and only three other-stage dropped records; no nonempty NPC or current-stage active-drop native recovery is validated.',
        'Snapshot predicate projections are not executions of original methods or game-object roundtrips.',
        'Pending callback cancellation across scene changes, complete appearance/physics/reference restore and exact runtime ordering remain unverified.',
        'Constructor decompilation can include a followed tail call; it does not create a separate synchronous copy of the activation loop.']
    return result


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--check',action='store_true');a=p.parse_args()
    result=build();out=HERE/'evidence/state-restore-chain.json'
    if a.check:assert read(out)==result
    else:out.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(status='consistent' if a.check else 'written',queries=result['new_observations'],
        body_listeners=len(result['body_restore_event']['listeners']),instructions=result['restore_delay_abi']['instructions_verified'])))


if __name__=='__main__':main()
