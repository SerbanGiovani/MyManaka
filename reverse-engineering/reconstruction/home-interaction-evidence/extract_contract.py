"""Bind original Apartment UI areas to serialized native triggers and REA bodies.

Read-only target/package inspection; never executes the game or writes original
assets. No raw byte scan is promoted to a proven runtime activation producer.
"""
import hashlib
import json
from pathlib import Path
import struct
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
RE = HERE.parents[1]
sys.path.insert(0, str(RE / 'assets'))
sys.path.insert(0, str(RE / 'reconstruction/asset-bridge'))
from inspect_player import models_investigation
from inspect_scenes import SceneInvestigation
from bridge_assets import SchemaReader
from animator_tree import TreeDecoder
sys.path.insert(0, str(RE / 'salt'))
from metadata import Metadata


def fingerprint(path):
    with path.open('rb') as stream:
        digest = hashlib.file_digest(stream, 'sha256').hexdigest()
    return dict(path=str(path.resolve()), bytes=path.stat().st_size, sha256=digest)


def record(path):
    value = json.loads(path.read_text('utf-8-sig'))
    assert value['subject']['digest']['sha256'] == '6003033049ac32e8712dc4101382534e21d65b97100c167ebec6bbca1462c18d'
    return dict(path=path.relative_to(RE).as_posix(), sha256=fingerprint(path)['sha256'], evidenceId=value['evidence_id'], operation=value['operation'])


def build():
    original = Path('E:/SecretFlasherManakaREA')
    models_path = RE / 'salt/.cache/decrypted/models.unity3d'
    models = models_investigation(models_path)
    scenes = SceneInvestigation(original)
    native_schema = SchemaReader(models)
    node = 'level1'
    mm = models.metadata(native_schema.node)
    scene_md = scenes.metadata(node)
    scene_input, model_input = fingerprint(scenes.bundle.path), fingerprint(models_path)
    assert scene_input['sha256'] == '20781befb4cc42f898b65fe03f3d16c0a77b53aecac6ddc388460cfb710ae93a'
    assert model_input['sha256'] == '98621b2c4fa4f9de80f355fae5776ab17efc016bcc81c581bcd0917af4308367'
    donor = next(t for t in mm['types'] if t['class_id'] == 114 and models.script(native_schema.node, t) and models.script(native_schema.node, t).get('fields', {}).get('class_name') == 'InteractAreaController')
    targets = []
    for key, label, gid, tid, cid, aid, kind in [('pc', '电脑', 391, 1395, 2185, 3777, 14), ('closet', '衣柜', 392, 1396, 2187, 3779, 11), ('bed', '床', 393, 1397, 2186, 3778, 13)]:
        go = scenes.gameobject(node, scenes.object(node, gid))
        transform_object, collider_object, area_object = [scenes.object(node, pid) for pid in [tid, cid, aid]]
        transform = native_schema.parse(scenes, node, transform_object)
        collider = native_schema.parse(scenes, node, collider_object)
        area_type = scene_md['types'][area_object['type_index']]
        assert area_type['old_type_hash'] == donor['old_type_hash']
        decoded = TreeDecoder(donor['tree']).decode(scenes.raw(node, area_object))
        area = decoded['value']
        assert decoded['end_of_object_verified'] and area['type'] == kind and area['m_GameObject']['m_PathID'] == gid
        assert collider['m_GameObject']['m_PathID'] == gid and collider_object['class_id'] == 135
        hierarchy = scenes.hierarchy(node, scenes.object(node, gid))
        path = '/'.join(x['gameobject']['name'] for x in reversed(hierarchy['entries']))
        components = []
        for object_ in [transform_object, collider_object, area_object]:
            raw = scenes.raw(node, object_)
            components.append(dict(source=scenes.identity(node, object_, raw), rawHex=raw.hex(), serializedTypeHash=scene_md['types'][object_['type_index']]['old_type_hash']))
        targets.append(dict(id='apartment-' + key, key=key, label=label, labelAuthority='reconstruction label; not a recovered localization string', interactType=kind,
            sourcePathId=tid, sourceGameObjectId=gid, sourceInteractAreaId=aid, sourceColliderId=cid, sourcePath=path, scene='Apartment', serializedNode=node, layer=go['layer'], originalSource=True,
            serializedActiveSelf=go['active_self_serialized'], allAncestorsActiveSelfSerialized=hierarchy['all_ancestors_active_self_serialized'], enabled=bool(area['m_Enabled']), canInteractWithAction=bool(area['<CanInteractWithAction>k__BackingField']),
            originalRingEffectGameObjectId=area['ringEffect']['m_PathID'],
            localPosition=transform['m_LocalPosition'], localRotation=transform['m_LocalRotation'], localScale=transform['m_LocalScale'], parentTransformId=transform['m_Father']['m_PathID'],
            trigger=dict(shape='Sphere', center=collider['m_Center'], radius=collider['m_Radius'], isTrigger=collider['m_IsTrigger'], enabled=collider['m_Enabled'], includeLayers=collider['m_IncludeLayers']['m_Bits'], excludeLayers=collider['m_ExcludeLayers']['m_Bits'], layerOverridePriority=collider['m_LayerOverridePriority']),
            gameObject=go, components=components, nativeColliderTypeHash=scene_md['types'][collider_object['type_index']]['old_type_hash'], interactionTypeHash=area_type['old_type_hash']))
    references = []
    for ob in scene_md['objects']:
        if ob['class_id'] != 114:
            continue
        raw = scenes.raw(node, ob)
        for target in [393, 1397, 3778]:
            needle = struct.pack('<iq', 0, target)
            offset = raw.find(needle)
            if offset >= 0:
                references.append(dict(owner=scenes.identity(node, ob, raw), candidateTargetId=target, rawByteOffset=offset, script=scenes.script(node, scene_md['types'][ob['type_index']]).get('fields', {})))
    reused = [record(RE / path) for path in [
        'salt/evidence/player-interaction-loop/14908-06000df3-procedure_pseudo_code.json',
        'salt/evidence/player-interaction-loop/15848-0600119f-procedure_pseudo_code.json',
        'salt/evidence/player-interaction-loop/15844-0600119b-procedure_pseudo_code.json',
        'salt/evidence/natural-load-saveui/17594-06001871-procedure_pseudo_code.json']]
    native = []
    batches = []
    for batch in ['home-ui', 'home-ui-tail']:
        new_run_path = RE / ('salt/evidence/' + batch + '/run.json')
        if not new_run_path.exists():
            continue
        new_run = json.loads(new_run_path.read_text('utf-8-sig'))
        assert new_run['success'] and not new_run.get('close_error') and not new_run.get('transport_close_error')
        batches.append(dict(name=batch, newThisRound=True, run=fingerprint(new_run_path), queries=len(new_run['functions']), sessionClosed=True))
        for method in new_run['functions']:
            native.append(dict(methodId=method['metadata_id'], qualifiedName=method['qualified_name'], va=method['va'], **record(RE / ('salt/evidence/' + batch + '/' + method['file_stem'] + '-procedure_pseudo_code.json'))))
    metadata_path = original / 'SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat'
    md = Metadata(metadata_path.read_bytes())
    types, fields = md.records(40, '<16i8H2I'), md.records(24, '<iiI')
    layout_path = RE / 'salt/symbols/field-offsets.json'
    offsets = {row['type_id']:row for row in json.loads(layout_path.read_text('utf-8-sig'))['all_type_field_offset_rows']}
    layouts = []
    selected = {2721: {'is24h','isKillTime'}, 2928:{'currentUntil'}, 2967:{'isAlreadyClose','onCloseBase','onClose','animator'}, 2586:{'IsDaytime'}}
    for tid, names in selected.items():
        t = types[tid]
        declarations = []
        for j in range(t[18]):
            fid = t[8] + j; f = fields[fid]; name = md.string(f[0])
            if name not in names:
                continue
            offset = md.header[24] + 12 * fid
            row = offsets[tid]
            declarations.append(dict(name=name, fieldId=fid, nativeOffset=row['raw_offsets'][j], metadataFileOffset=offset, metadataRawHex=md.data[offset:offset+12].hex(), offsetEntryFileOffset=row['offset_row_file_offset'] + 4*j))
        layouts.append(dict(typeId=tid, fullName='.'.join(filter(None,[md.string(t[1]),md.string(t[0])])), fields=declarations))
    result = dict(schemaVersion=1, authority='shipped-artifact static native serialization plus REA/Ghidra; not natural gameplay execution',
        nativeSha256='6003033049ac32e8712dc4101382534e21d65b97100c167ebec6bbca1462c18d', metadataSha256='457203754abe77b346fd98086a5c787bd41088d808cc81b1d4e2cae5b85c72c8',
        sourceInputs=[scene_input, model_input, fingerprint(metadata_path), fingerprint(original/'GameAssembly.dll')], parserInputs=[fingerprint(Path(__file__)), fingerprint(RE / 'reconstruction/asset-bridge/bridge_assets.py'), fingerprint(RE / 'assets/animator_tree.py'), fingerprint(RE / 'assets/inspect_scenes.py'),fingerprint(RE/'salt/metadata.py'),fingerprint(layout_path)], targets=targets, reusedNativeRecords=reused, newNativeRecords=native, batches=batches, selectedFieldLayouts=layouts,
        observedDispatch=dict(methodId=15848, closet=18630, bed=18841, pc=17589),
        pcSave=dict(methodId=17594, category=3, slot=-1, isBackup=False, scope='Observed original PC callback and natural original-game save; reconstructed application must keep its independent JSON profile boundary.'),
        sleepSelection=dict(morningValue=0, nightValue=1, stateField='GameStateData.IsDaytime', selectedUntilField='SleepSelectPanelView.currentUntil', blackPanelFlag='SleepBlackPanelView.is24h', mapping=[dict(selection=0,isDaytime=False,is24h=False),dict(selection=0,isDaytime=True,is24h=True),dict(selection=1,isDaytime=False,is24h=True),dict(selection=1,isDaytime=True,is24h=False)], isKillTime=False, mutationPoint='SleepBlackPanel.OnEnterPureBlack; see native body; selection alone is not a time mutation.'),
        sleepMutation=dict(methodId=17519, flagFalse='is24h=false: toggle IsDaytime, ChangeLighting, StageController.UpdateByDaytimeNight', flagTrue='is24h=true: retain IsDaytime', phaseResult='Equals requested morning/night after pure-black callback', alwaysCalls=['DroppedItemManager.Collect(4)','DroppedItemManager.Collect(3)','DroppedItemManager.DisposeAllPutDildo','IsDroneNeedCharge=false','NpcManager.RepopNpc','event broadcast through static event offset0x68'], ordinarySleepCalls=['Set active original player attachments at accessor offsets0x268/0x260','MissionManager.ResetMission','PlayerLife=PlayerMaxLife'], originalDayCounterOrHourFieldObserved=False, scope='This is static selected-body evidence, not a complete independent implementation of sleep/world/mission side effects.'),
        closeLifecycle=dict(baseCloseMethodId=19038, closeGuard='BasePanelView.isAlreadyClose@0x40', baseDelegateDelayFrames=1, baseDelegateMethodId=19049, baseDelegateInvokes=['onCloseBase@0x28','onClose@0x30'], destructionMethodId=19043, destructionPoint='OnAnimCloseEnd destroys UI GameObject, separate from one-frame close delegate', closetBackMethodId=18638, closetBackDelayFrames=5, closetBackDelegateMethodId=18641, closetBackDelegateCalls=['SetVisibleRightDownInfo(true)','ClosetLight(false)','DisableLookAt(6)','Save(3,-1,false)','SetInventoryCamera(false,false)','ReAdjust/appearance callbacks','BasePanel.Close'], scope='Original UI Animator clip timings and full input-gate restoration are not established merely by these selected bodies.'),
        clothingSelection=dict(methodId=18632, observedCalls=['PlayerFacade.ChangeClothes(selectedRecord)','ClosetMenu.RefreshClothesView','possible DroppedItemManager.Collect(type determined from clothes record)'], sameCurrentRecordNoop=True, catalogAndOwnershipScope='Initialize builds original clothing records and initializes customization view; no complete independent catalog or appearance application is supplied by this evidence contract.'),
        bedActivation=dict(serializedActiveSelf=False, provenRuntimeEnableProducer=None, naturalReachability='unknown', scanScope='Every original level1 class114 object was searched for raw file0 PPtr-shaped byte sequences to GO393,Transform1397,InteractArea3778. Hits are raw candidates, not typed references or execution proof.', rawReferenceCandidates=references),
        limits=['The geometry bridge sourcePathId identifies Transform, not GameObject, collider or MonoBehaviour.', 'Display labels are authored reconstruction labels.', 'A serialized inactive bed and UI dispatch branch do not prove normal play can enable or enter it.', 'Caller metadata names and static decompilation are not original C# source or runtime execution.', 'No original ES3 save is written by this inspection.'])
    return result


if __name__ == '__main__':
    output = build()
    (HERE / 'contract.json').write_text(json.dumps(output, ensure_ascii=False, indent=2) + '\n', encoding='utf8')
    print(json.dumps(dict(targets=len(output['targets']), newNativeQueries=len(output['newNativeRecords']), serializedBedActive=False)))
