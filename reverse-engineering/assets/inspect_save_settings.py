"""Read the pinned ES3Defaults resource, declarations and serialized spans."""
import argparse
import json
from pathlib import Path
import sys

sys.dont_write_bytecode = True
from inspect_resources import Reader
from inspect_scenes import SceneInvestigation, fingerprint, mono_prefix, read_value
import inspect_player as player

HERE = Path(__file__).resolve().parent
ORIGINAL = Path('E:/SecretFlasherManakaREA')
SETTINGS_FIELDS = [('_location','i'),('path','string'),('encryptionType','i'),('compressionType','i'),
    ('encryptionPassword','string'),('directory','i'),('format','i'),('prettyPrint','bool'),
    ('bufferSize','i'),('saveChildren','bool'),('postprocessRawCachedData','bool'),
    ('typeChecking','bool'),('safeReflection','bool'),('memberReferenceMode','i'),
    ('referenceMode','i'),('serializationDepthLimit','i'),('assemblyNames','strings')]
DEFAULTS_FIELDS = [('addMgrToSceneAutomatically','bool'),('autoUpdateReferences','bool'),
    ('addAllPrefabsToManager','bool'),('collectDependenciesDepth','i'),('collectDependenciesTimeout','i'),
    ('updateReferencesWhenSceneChanges','bool'),('updateReferencesWhenSceneIsSaved','bool'),
    ('updateReferencesWhenSceneIsOpened','bool'),('referenceFolders','strings'),('logDebugInfo','bool'),
    ('logWarnings','bool'),('logErrors','bool')]


def build():
    player.SELECTED_TYPES = {'ES3Defaults','ES3Settings','ES3SerializableSettings'}
    player.ENUM_NAMES = {'ES3/'+s for s in ('Location','Directory','EncryptionType','CompressionType','Format','ReferenceMode')}
    player.SERIALIZED_TYPES = set()
    wrappers = player.wrappers(ORIGINAL)
    # The reused field-offset helper expects a nonempty offset row. Retain the
    # zero-field subclass separately rather than changing the pinned helper.
    player.SELECTED_TYPES.remove('ES3SerializableSettings')
    metadata = player.original_metadata(ORIGINAL,wrappers)
    metadata.pop('requested_names_without_original_type',None)
    types = {t['full_name']:t for t in metadata['types']}
    declared = [f['name'] for f in types['ES3Settings']['fields'] if not f['is_static'] and f['name']!='encoding']
    assert declared == [name for name,_ in SETTINGS_FIELDS]
    assert [f['name'] for f in types['ES3Defaults']['fields']] == ['settings']+[n for n,_ in DEFAULTS_FIELDS]
    from metadata import Metadata
    metadata_bytes=Path(metadata['source']['path']).read_bytes()
    md=Metadata(metadata_bytes)
    subclass_id,subclass=next((i,t) for i,t in enumerate(md.records(40,'<16i8H2I')) if md.string(t[0])=='ES3SerializableSettings')
    assert subclass[18]==0
    metadata['zero_field_subclass']=dict(type_id=subclass_id,metadata_file_offset=md.header[40]+88*subclass_id,
        raw_hex=metadata_bytes[md.header[40]+88*subclass_id:md.header[40]+88*(subclass_id+1)].hex(),
        name='ES3SerializableSettings',field_count=0,parent_runtime_type_index=subclass[4])
    assert next(t for t in wrappers['types'] if t['type']=='ES3SerializableSettings')['base_type']=='ES3Settings'
    x = SceneInvestigation(ORIGINAL)
    n = 'globalgamemanagers'
    manager = next(o for o in x.metadata(n)['objects'] if o['class_id']==147)
    manager_raw=x.raw(n,manager)
    r=Reader(manager_raw)
    count=read_value(r,'i')
    entries=[dict(key=read_value(r,'string'),pointer=read_value(r,'PPtr')) for _ in range(count['value'])]
    matches=[e for e in entries if e['key']['value']=='es3/es3defaults']
    assert len(matches)==1
    entry=matches[0]
    pointer=entry['pointer']['value']
    target=x.pointer(n,pointer['file_id'],pointer['path_id'])
    obj=target['object']; node=target['node']; raw=x.raw(node,obj)
    typ=x.metadata(node)['types'][obj['type_index']]
    script=x.script(node,typ)
    assert script['fields']['class_name']=='ES3Defaults' and script['fields']['assembly_name']=='Assembly-CSharp'
    reader,object_name=mono_prefix(raw)
    assert object_name=='ES3Defaults'
    def fields(schema,owner):
        result={}
        for name,kind in schema:
            start=reader.position
            if kind=='strings':
                length=reader.number('i'); assert 0<=length<=1024
                values=[read_value(reader,'string') for _ in range(length)]
                value=dict(serialized_offset=start,serialized_end=reader.position,value=[v['value'] for v in values],
                    elements=values,raw_hex=raw[start:reader.position].hex(' '))
            else:
                value=read_value(reader,kind)
            declaration=next(f for f in types[owner]['fields'] if f['name']==name)
            result[name]=dict(value,field_id=declaration['field_id'],runtime_type=declaration['runtime_type'],
                registered_offset=declaration['registered_offset'])
        return result
    settings=fields(SETTINGS_FIELDS,'ES3Settings')
    defaults=fields(DEFAULTS_FIELDS,'ES3Defaults')
    assert reader.position==len(raw)
    enums={e['full_name']:{str(v['value']):v['name'] for v in e['values']} for e in metadata['enums']}
    for name,kind in SETTINGS_FIELDS:
        rt=settings[name]['runtime_type']
        if rt.get('type_name') in enums:
            settings[name]['enum_name']=enums[rt['type_name']][str(settings[name]['value'])]
    sources=[Path(__file__),HERE/'inspect_resources.py',HERE/'inspect_scenes.py',HERE/'inspect_player.py']
    x.bundle.file.close()
    return dict(schema_version=1,evidence_type='Pinned Resources map and ES3Defaults complete selected-layout decode; offline only',
        source=fingerprint(x.bundle.path),sources=[fingerprint(p) for p in sources],
        original_metadata=metadata,wrapper_declarations=wrappers,
        resource_manager=dict(source=x.identity(n,manager,manager_raw),entry_count=count['value'],
            selected_entry=entry,decoded_prefix_end=r.position,raw_prefix_hex=manager_raw[:r.position].hex(' '),
            boundary='Leading resource map fully decoded; dependent-assets tail is not interpreted.'),
        defaults_object=dict(source=x.identity(node,obj,raw),script_identity=script,serialized_type=typ,
            raw_hex=raw.hex(' '),name=object_name,settings=settings,defaults=defaults,
            bytes_consumed=reader.position,end_of_object_verified=True),
        limitations=['No embedded type tree is present for this object; selected layout follows original field order and independently checked wrapper types, and consumes all576 bytes.',
            'Private _location and omission of unsupported Encoding are explicit selected-layout choices; this is not a general Unity field-serialization predicate.',
            'Resource values establish shipped configuration; runtime override reachability and which defaults are copied require separate native evidence.',
            'Native offsets, metadata offsets and serialized offsets remain separate coordinates.'])


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--check',action='store_true');args=p.parse_args()
    result=build();out=HERE/'save-settings.json'
    if args.check:
        assert json.loads(out.read_text(encoding='utf8'))==result
    else:
        out.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    settings=result['defaults_object']['settings']
    print(json.dumps(dict(status='consistent' if args.check else 'written',
        bytes_consumed=result['defaults_object']['bytes_consumed'],
        settings={k:v['value'] for k,v in settings.items() if k!='encryptionPassword'}),ensure_ascii=False))


if __name__=='__main__':main()
