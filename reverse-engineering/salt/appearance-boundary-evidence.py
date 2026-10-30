"""Bind two distinct body-paint data paths; static observations, no runtime claim."""
import argparse,hashlib,json,struct,sys
from pathlib import Path
from metadata import HERE,DEFAULT_ROOT,Metadata
from scene_evidence import build as bind,read

def build():
    r=bind(batch_prefix='appearance-boundary',reuse_method_ids={14620,14623,14624,14625,14627,14769,16071,16970,16971},extra_type_names=('PlayerCustomData','GameStateData','PlayerBodyMaterialController','BodyPaintController','BodyPaintType','RBodyPaint','AssetReferencer','PlayerAvatarObjectReferencer','ChangeCosplayPartsOptionEvent'),dispatch_targets=[],resource_boundary='Persistent body-paint bool map and temporary item paint are distinct; no new live process or visual equivalence tested.')
    assert r['new_observations']==r['new_unique_procedure_addresses']==r['new_unique_evidence_ids']==7
    fs={t['name'].split('.')[-1]:{f['name']:f for f in t['fields']} for t in r['named_types']}
    assert fs['PlayerCustomData']['BodyPaintTypeDict']['offset']==0x108
    assert fs['GameStateData']['PlayerRemainBodyPaintTime']['offset']==0x17c
    assert fs['GameStateData']['IsActiveBodyPaintReusable']['offset']==0x1df
    assert fs['PlayerBodyMaterialController']['<ClothesPaintMaterial>k__BackingField']['offset']==0x28
    assert fs['PlayerAvatarObjectReferencer']['bodyMeshRenderer']['offset']==0x208
    raw=(DEFAULT_ROOT/'SecretFlasherManaka_Data/il2cpp_data/Metadata/global-metadata.dat').read_bytes();md=Metadata(raw);fields=md.records(24,'<iiI');defaults={v[0]:(i,v) for i,v in enumerate(md.records(16,'<iii'))}
    sys.path.insert(0,str(HERE.parent/'assets'));from inspect_player import compressed_int32
    enum=[]
    for fid in range(11870,11880):
        row,(field_id,typ,idx)=defaults[fid];value=compressed_int32(raw,md.header[18]+idx);enum.append(dict(name=md.string(fields[fid][0]),field_id=field_id,default_file_offset=md.header[16]+row*12,default_raw_hex=raw[md.header[16]+row*12:md.header[16]+row*12+12].hex(),**value))
    assert [(v['name'],v['decoded_int32']) for v in enum]==list(zip(['Inmon','Rakugaki','TattooDark','TattooFlower1','TattooFlower2','TattooLotus','TattooSatanism','TattooSlave','BodyOil','RubberSuit'],range(10)))
    r['body_paint_enum']=enum
    r['findings']=dict(persistent_map='PlayerCustomData.BodyPaintTypeDict<BodyPaintType,bool>',persistent_map_offset=0x108,
        timed_state=['GameStateData.PlayerRemainBodyPaintTime@0x17c','GameStateData.IsActiveBodyPaintReusable@0x1df'],
        receiver=14625,setup=14624,apply_options=14627,set_active=16769,switch_visible=16305,
        body_oil_type=8,body_oil_appends_material=False,body_oil_changes_second_base_material_matcap_to_white_or_black=True,
        trans_to_material_type8_throws=True,set_active_only_writes_bool_map=True,
        switch_visible_defaultType_parameter_is_unused_in_body=True,switch_visible_inlines_setup=True,
        timed_initialize=[dict(remaining='<=0',state=0,alpha=-1),dict(remaining='0<time<=24',state=4,alpha=0),dict(remaining='24<time<=60',state=3,alpha=.25),dict(remaining='>60',state=2,alpha=.4)],
        timed_use_sets_remaining=120,timed_use_state=2,timed_use_alpha=1,wash_sets_remaining=0,wash_sets_state=4,
        scope='Initialize thresholds, shader state and call flow are static; no coverage of natural UI, material restoration, timers or physics is claimed here.')
    r.setdefault('sources',[]).append(dict(path='salt/appearance-boundary-evidence.py',sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest()))
    return r

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--check',action='store_true');a=p.parse_args();r=build();out=HERE/'evidence/appearance-boundary-chain.json'
    if a.check:assert r==read(out)
    else:out.write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(new_queries=7,body_paint_types=10)))
