"""Read original bundle inventory and export bounded Apartment triangle geometry.

No Unity, target assembly, editor, process, or input is executed. Native class
schemas come from the original decrypted models bundle and are accepted for
build objects only when their original serialized type hash matches exactly.
"""
import argparse
import collections
import hashlib
import json
import math
import struct
import sys
from pathlib import Path

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
ASSETS = HERE.parents[1] / 'assets'
sys.path.insert(0, str(ASSETS))
import inspect_player as player
from inspect_resources import Reader
from inspect_scenes import SceneInvestigation, fingerprint, read_value, resolve_value

ORIGINAL = Path('E:/SecretFlasherManakaREA')
MODELS = HERE.parents[1] / 'salt/.cache/decrypted/models.unity3d'
ORIGINAL_DATA_SHA256='20781befb4cc42f898b65fe03f3d16c0a77b53aecac6ddc388460cfb710ae93a'
MODELS_SHA256='98621b2c4fa4f9de80f355fae5776ab17efc016bcc81c581bcd0917af4308367'
COMMON = {0:'AABB',49:'Array',55:'Base',76:'bool',81:'char',106:'data',155:'first',161:'float',222:'int',245:'Matrix4x4f',349:'m_Enabled',374:'m_GameObject',427:'m_Name',778:'second',795:'size',800:'SInt16',814:'SInt64',840:'string',894:'TypelessData',907:'UInt16',921:'UInt64',928:'UInt8',934:'unsigned int',981:'vector',997:'Vector3f',1006:'Vector4f'}
PRIMITIVES = {'bool':'?', 'char':'B','float':'f','int':'i','SInt16':'h','SInt64':'q','UInt16':'H','UInt64':'Q','UInt8':'B','unsigned int':'I','double':'d'}

def resolved(text):
    return COMMON.get(int(text.split(':')[1]), text) if text.startswith('$common:') else text

def finite(value):
    if isinstance(value, dict):
        return all(finite(x) for x in value.values())
    if isinstance(value, (list,tuple)):
        return all(finite(x) for x in value)
    return not isinstance(value,float) or math.isfinite(value)

class SchemaReader:
    def __init__(self, models):
        node=next(iter(models.nodes)); metadata=models.metadata(node)
        self.models=models; self.node=node
        self.schemas={(t['class_id'], t['old_type_hash']):t for t in metadata['types'] if t.get('tree')}

    def parse(self, inv, node, obj):
        typ=inv.metadata(node)['types'][obj['type_index']]
        schema=self.schemas[(obj['class_id'],typ['old_type_hash'])]
        tree=schema['tree']; raw=inv.raw(node,obj); reader=Reader(raw)
        end=[]
        for i,t in enumerate(tree):
            j=i+1
            while j<len(tree) and tree[j]['level']>t['level']:j+=1
            end.append(j)
        def children(i):
            j=i+1
            while j<end[i]:
                yield j
                j=end[j]
        def parse(i):
            t=tree[i];kind=resolved(t['type']);ch=list(children(i))
            if kind=='string':value=reader.aligned_string()
            elif kind in PRIMITIVES:value=reader.number(PRIMITIVES[kind])
            elif kind=='Array' or kind=='TypelessData':
                assert len(ch)==2 and resolved(tree[ch[0]]['name'])=='size'
                count=reader.number('i');assert 0<=count<=10_000_000
                elem=ch[1]
                if not list(children(elem)) and resolved(tree[elem]['type']) in ('UInt8','char'):
                    value=reader.take(count)
                else:value=[parse(elem) for _ in range(count)]
            elif len(ch)==1 and resolved(tree[ch[0]]['type'])=='Array':value=parse(ch[0])
            elif ch:value={resolved(tree[j]['name']):parse(j) for j in ch}
            else:raise ValueError('Unsupported leaf '+str((kind,t['name'],t['byte_size'])))
            if t['meta_flags']&0x4000:reader.align()
            return value
        result=parse(0)
        assert reader.position==len(raw),(node,obj['path_id'],reader.position,len(raw))
        assert finite(result)
        return result

def pointer(inv,node,value):
    return inv.pointer(node,value['m_FileID'],value['m_PathID'])

def inventory(models,original):
    node=next(iter(models.nodes));m=models.metadata(node)
    obj=next(o for o in m['objects'] if o['class_id']==142);raw=models.raw(node,obj);r=Reader(raw)
    name=read_value(r,'string');pre=read_value(r,'i');pre_start=r.position;r.take(12*pre['value']);count=read_value(r,'i');entries=[]
    for i in range(count['value']):
        begin=r.position;key=read_value(r,'string');index=read_value(r,'i');size=read_value(r,'i');ptr=read_value(r,'PPtr');target=resolve_value(models,node,ptr)
        entries.append(dict(index=i,asset=key['value'],classId=target['object']['class_id'],pathId=target['object']['path_id'],preloadIndex=index['value'],preloadSize=size['value'],serializedOffset=begin,serializedEnd=r.position))
    classes=collections.Counter(x['classId'] for x in entries)
    build_nodes=[]; bundle_objects=[]
    for n in original.nodes:
        if not (n.endswith('.assets') or n.startswith('level') and '.' not in n or n=='globalgamemanagers'):continue
        md=original.metadata(n);found=[o['path_id'] for o in md['objects'] if o['class_id']==142]
        build_nodes.append(dict(name=n,objects=len(md['objects']),assetBundleObjectCount=len(found),hasTypeTree=md['has_type_tree']))
        bundle_objects.extend((n,x) for x in found)
    assert not bundle_objects
    selected=[e for e in entries if e['asset']=='assets/zzz-externalencryptasset/player.prefab']
    assert len(selected)==1 and selected[0]['classId']==1
    return dict(schemaVersion=1,kind='offline-original-bundle-container-and-build-data-inventory',parser=fingerprint(Path(__file__)),models=fingerprint(MODELS),originalBuildData=fingerprint(original.bundle.path),engineVersion=models.bundle.engine_version,assetBundle=dict(source=models.identity(node,obj,raw),serializedName=name['value'],preloadCount=pre['value'],preloadTableOffset=pre_start,containerCount=count['value'],entries=entries,parsedPrefixEnd=r.position,unparsedTailHex=raw[r.position:].hex()),containerClassCounts={str(k):v for k,v in sorted(classes.items())},buildNodes=build_nodes,player=selected[0],apartment=dict(buildIndex=1,scenePath='Assets/ZZZ-ExternalAsset/MapAsset/JP_Apartment/Scenes/Apartment.unity',serializedNode='level1',containerEntryInModels=False),limitations=['No AssetBundle object occurs in scanned original build nodes. This is a structural distinction; actual native LoadFromFile acceptance must be tested separately.','No scene/class-102 SceneAsset occurs in models container. The Apartment is build scene data, not a discovered models scene bundle.','Container keys can repeat for FBX subassets. Do not assume one key maps to one native object.','Native MonoBehaviour methods, shaders, clips, avatar binding and rendering are not verified by this offline inventory.'])

def stream_bytes(inv,path,offset,size):
    name=path.rsplit('/',1)[-1]
    assert name in inv.nodes,(path,name)
    node=inv.nodes[name];assert 0<=offset<=offset+size<=node['size']
    return inv.bundle.read(node['offset']+offset,size)

def decode_mesh(inv,node,obj,schema):
    d=schema.parse(inv,node,obj);vd=d['m_VertexData'];channels=vd['m_Channels'];count=vd['m_VertexCount'];data=vd['m_DataSize'];stream=d['m_StreamData']
    if stream['size']:
        assert not data
        data=stream_bytes(inv,stream['path'],stream['offset'],stream['size'])
    assert d['m_MeshCompression']==0,'Compressed native meshes are explicitly unsupported'
    sizes={0:4,1:2,2:1,3:1,4:2,5:2,6:1,7:1,8:2,9:2,10:4,11:4}
    strides={}
    for c in channels:
        dim=c['dimension']&15
        if dim:
            assert c['format'] in sizes
            strides[c['stream']]=max(strides.get(c['stream'],0),c['offset']+sizes[c['format']]*dim)
    bases={};at=0
    for s,stride in sorted(strides.items()):bases[s]=at;at=(at+stride*count+15)&~15
    assert max((bases[s]+stride*count for s,stride in strides.items()),default=0)<=len(data)
    def channel(index,expected):
        if len(channels)<=index or not channels[index]['dimension']&15:return []
        c=channels[index];dim=c['dimension']&15;fmt=c['format'];assert dim>=expected
        out=[]
        for i in range(count):
            start=bases[c['stream']]+i*strides[c['stream']]+c['offset'];values=[]
            for j in range(expected):
                at=start+j*sizes[fmt]
                if fmt in (0,1):v=struct.unpack_from('<f' if fmt==0 else '<e',data,at)[0]
                elif fmt==2:v=data[at]/255
                elif fmt==3:v=max(-1,struct.unpack_from('<b',data,at)[0]/127)
                elif fmt==4:v=struct.unpack_from('<H',data,at)[0]/65535
                elif fmt==5:v=max(-1,struct.unpack_from('<h',data,at)[0]/32767)
                else:v=struct.unpack_from({6:'<B',7:'<b',8:'<H',9:'<h',10:'<I',11:'<i'}[fmt],data,at)[0]
                assert math.isfinite(v);values.append(v)
            out.append(values)
        return out
    positions=channel(0,3);assert len(positions)==count
    fmt=d['m_IndexFormat'];assert fmt in (0,1);width=2 if fmt==0 else 4;indices=d['m_IndexBuffer'];assert len(indices)%width==0
    all_indices=[x[0] for x in struct.iter_unpack('<H' if fmt==0 else '<I',indices)]
    return dict(name=d['m_Name'],positions=positions,normals=channel(1,3),uv=channel(4,2),submeshes=d['m_SubMeshes'],indices=all_indices,indexWidth=width,source=inv.identity(node,obj),schemaHash=inv.metadata(node)['types'][obj['type_index']]['old_type_hash'])

def subset(mesh,first=0,count=None):
    subs=mesh['submeshes'][first:] if count is None else mesh['submeshes'][first:first+count]
    assert subs and (count is None or len(subs)==count)
    src=[]
    for sub in subs:
        assert sub['topology']==0,'Only native triangle topology is supported'
        assert sub['firstByte']%mesh['indexWidth']==0 and sub['indexCount']%3==0
        a=sub['firstByte']//mesh['indexWidth'];b=a+sub['indexCount'];assert b<=len(mesh['indices'])
        src.extend(x+sub['baseVertex'] for x in mesh['indices'][a:b])
    assert src and min(src)>=0 and max(src)<len(mesh['positions'])
    selected=list(dict.fromkeys(src));mapping={old:i for i,old in enumerate(selected)}
    def vec(row,keys):return dict(zip(keys,row))
    return dict(name=mesh['name'],vertices=[vec(mesh['positions'][i],'xyz') for i in selected],triangles=[mapping[i] for i in src],normals=[vec(mesh['normals'][i],'xyz') for i in selected] if mesh['normals'] else [],uv=[vec(mesh['uv'][i],'xy') for i in selected] if mesh['uv'] else [],color=dict(r=.75,g=.75,b=.75,a=1))

def mesh_collider(inv,node,obj):
    # The shared Collider prefix is corroborated by the original BoxCollider
    # type tree. Only these four pinned 64-byte original MeshCollider objects
    # are accepted; the MeshCollider-specific suffix is structural, not an
    # invented matching type tree. Its PPtr must independently resolve below.
    typ=inv.metadata(node)['types'][obj['type_index']];raw=inv.raw(node,obj)
    assert obj['class_id']==64 and typ['old_type_hash']=='8934b3d2abd40a5397f3edf8c2bfc16b' and len(raw)==64
    r=Reader(raw);pptr=lambda:dict(m_FileID=r.number('i'),m_PathID=r.number('q'))
    d=dict(m_GameObject=pptr(),m_Material=pptr(),m_IncludeLayers=r.number('I'),m_ExcludeLayers=r.number('I'),m_LayerOverridePriority=r.number('i'))
    for field in ('m_IsTrigger','m_ProvidesContacts'):
        v=r.number('B');assert v in (0,1);d[field]=bool(v)
    assert r.position==38;r.align();v=r.number('B');assert v in (0,1);d['m_Enabled']=bool(v);r.align();assert r.position==44
    v=r.number('B');assert v in (0,1);d['m_Convex']=bool(v);r.align();d['m_CookingOptions']=r.number('i');d['m_Mesh']=pptr()
    assert r.position==len(raw)
    return d

def geometry(models,original):
    schema=SchemaReader(models);node='level1';md=original.metadata(node);by_id={o['path_id']:o for o in md['objects']}
    transforms={};objects={};go_transform={};nodes=[];node_index={};meshes=[];mesh_index={};mesh_cache={};failures=[];proof=[];materials={};collider_proof=[];builtin_refs=[];textures=[];texture_indices={};texture_payloads={}
    for obj in md['objects']:
        if obj['class_id']!=4:continue
        d=schema.parse(original,node,obj);go=pointer(original,node,d['m_GameObject']);assert go and go['node']==node
        g=original.gameobject(node,go['object']);transforms[obj['path_id']]=d;objects[g['source']['object']['path_id']]=g;go_transform[g['source']['object']['path_id']]=obj['path_id']
    for tid,d in transforms.items():
        go=objects[d['m_GameObject']['m_PathID']];node_index[tid]=len(nodes)
        nodes.append(dict(name=go['name'],parent=-1,position=d['m_LocalPosition'],rotation=d['m_LocalRotation'],scale=d['m_LocalScale'],mesh=-1,collider=False,active=go['active_self_serialized'],rendererEnabled=False,sourcePathId=tid))
    for tid,d in transforms.items():
        father=d['m_Father'];assert father['m_FileID']==0
        if father['m_PathID'] in node_index:nodes[node_index[tid]]['parent']=node_index[father['m_PathID']]
        elif father['m_PathID']!=0:failures.append(dict(kind='unexported-transform-parent',pathId=tid,parent=father))
    def active(tid):
        seen=set()
        while tid:
            assert tid not in seen;seen.add(tid)
            if tid not in transforms:return False
            go=objects[transforms[tid]['m_GameObject']['m_PathID']]
            if not go['active_self_serialized']:return False
            tid=transforms[tid]['m_Father']['m_PathID']
        return True
    def add_mesh(target,first=0,count=None,material_signature=None):
        key=(target['node'],target['object']['path_id']);skey=(*key,first,count,material_signature)
        if skey in mesh_index:return mesh_index[skey]
        if key not in mesh_cache:mesh_cache[key]=decode_mesh(original,*[target[k] for k in ('node','object')],schema)
        source=mesh_cache[key];value=subset(source,first,count);idx=len(meshes);meshes.append(value);mesh_index[skey]=idx
        proof.append(dict(mesh=idx,source=source['source'],schemaHash=source['schemaHash'],firstSubMesh=first,subMeshCount=count,sourceVertexCount=len(source['positions']),exportedVertices=len(value['vertices']),triangles=len(value['triangles'])//3))
        return idx
    def material_info(ptr):
        target=pointer(original,node,ptr)
        if not target:return dict(name='None',color=dict(r=.75,g=.75,b=.75,a=1))
        if 'object' not in target:return dict(name='Unresolved built-in material '+str(ptr['m_PathID']),color=dict(r=.75,g=.75,b=.75,a=1),unresolved=target)
        key=(target['node'],target['object']['path_id'])
        if key not in materials:
            d=schema.parse(original,*[target[k] for k in ('node','object')]);colors={p['first']:p['second'] for p in d['m_SavedProperties']['m_Colors']};primary=next((k for k in ('_Color','_BaseColor','_MainColor') if k in colors),None)
            textures=[dict(property=p['first'],pointer=p['second']['m_Texture'],scale=p['second']['m_Scale'],offset=p['second']['m_Offset']) for p in d['m_SavedProperties']['m_TexEnvs']]
            materials[key]=dict(name=d['m_Name'],color=colors.get(primary,dict(r=.75,g=.75,b=.75,a=1)),primaryProperty=primary,source=original.identity(*[target[k] for k in ('node','object')]),shader=d['m_Shader'],textures=textures)
        return materials[key]
    def add_texture(material):
        env=next((x for x in material.get('textures',[]) if x['property']=='_MainTex'),None)
        if not env:return -1,dict(x=1,y=1),dict(x=0,y=0)
        target=pointer(original,material['source']['node'],env['pointer'])
        if not target:return -1,env['scale'],env['offset']
        assert 'object' in target and target['object']['class_id']==28
        key=(target['node'],target['object']['path_id'])
        if key not in texture_indices:
            d=schema.parse(original,*[target[k] for k in ('node','object')]);assert d['m_TextureDimension']==2 and d['m_ImageCount']==1 and d['m_MipsStripped']==0
            data=d['image data'];stream=d['m_StreamData']
            if stream['size']:
                assert not data;data=stream_bytes(original,stream['path'],stream['offset'],stream['size'])
            assert len(data)==d['m_CompleteImageSize'] and len(data)>0
            file='Textures/'+key[0]+'.'+str(key[1])+'.raw';texture_payloads[file]=data;idx=len(textures);texture_indices[key]=idx
            textures.append(dict(name=d['m_Name'],file=file,width=d['m_Width'],height=d['m_Height'],format=d['m_TextureFormat'],mipCount=d['m_MipCount'],byteLength=len(data),sha256=hashlib.sha256(data).hexdigest(),colorSpace=d['m_ColorSpace'],settings=d['m_TextureSettings'],source=original.identity(*[target[k] for k in ('node','object')]),stream=stream,boundary='Original native Texture2D header decoded by equal type hash with EOF validation. Exact original compressed image bytes retained; native compatibility and color-space interpretation require the consuming engine test.'))
        return texture_indices[key],env['scale'],env['offset']
    filters={}
    for obj in md['objects']:
        if obj['class_id']==33:
            d=schema.parse(original,node,obj);filters[d['m_GameObject']['m_PathID']]=d
    renderers=0;static_batches=0
    for obj in md['objects']:
        if obj['class_id']!=23:continue
        d=schema.parse(original,node,obj);go=d['m_GameObject']['m_PathID'];tid=go_transform.get(go)
        if tid is None or not active(tid) or not d['m_Enabled']:continue
        try:
            f=filters[go];target=pointer(original,node,f['m_Mesh']);assert target
            mats=[material_info(p) for p in d['m_Materials']];primary=mats[0] if mats else dict(name='None',color=dict(r=.75,g=.75,b=.75,a=1));signature=tuple(p['m_PathID'] for p in d['m_Materials'])
            if 'object' not in target:
                out=nodes[node_index[tid]];out.update(rendererEnabled=True,builtinMeshId=f['m_Mesh']['m_PathID'],materialName=primary['name'],color=primary['color']);builtin_refs.append(dict(component=obj['path_id'],node=node_index[tid],purpose='renderer',target=target,originalPointer=f['m_Mesh']));continue
            assert target['object']['class_id']==43
            batch=d['m_StaticBatchInfo'];cnt=batch['subMeshCount'];first=batch['firstSubMesh'] if cnt else 0
            ix=add_mesh(target,first,cnt or None,signature);meshes[ix].update(color=primary['color'],materialName=primary['name'],materialNames=[p['name'] for p in mats],texture=-1);out=nodes[node_index[tid]]
            try:
                texture,scale,offset=add_texture(primary);meshes[ix].update(texture=texture,textureScale=scale,textureOffset=offset)
            except (AssertionError,ValueError,KeyError,struct.error) as error:failures.append(dict(kind='primary-albedo-export',material=primary['name'],error=str(error)))
            if cnt:
                root=d['m_StaticBatchRoot'];assert root['m_FileID']==0
                parent=node_index.get(root['m_PathID'],-1);assert root['m_PathID']==0 or parent>=0
                out=dict(name=out['name']+' [static batch geometry]',parent=parent,position=dict(x=0,y=0,z=0),rotation=dict(x=0,y=0,z=0,w=1),scale=dict(x=1,y=1,z=1),mesh=-1,collider=False,active=True,rendererEnabled=True,sourcePathId=obj['path_id']);nodes.append(out);static_batches+=1
            out['mesh']=ix;out['rendererEnabled']=True;out['materialName']=primary['name'];renderers+=1
        except (AssertionError,ValueError,KeyError,struct.error) as error:failures.append(dict(kind='renderer-mesh-export',pathId=obj['path_id'],name=objects.get(go,{}).get('name'),error=str(error)))
    mesh_colliders=0;boxes=0
    for obj in md['objects']:
        if obj['class_id'] not in (64,65):continue
        try:
            d=mesh_collider(original,node,obj) if obj['class_id']==64 else schema.parse(original,node,obj);go=d['m_GameObject']['m_PathID'];tid=go_transform.get(go)
            if tid is None or not active(tid) or not d['m_Enabled'] or d['m_IsTrigger']:continue
            if obj['class_id']==64:
                target=pointer(original,node,d['m_Mesh']);assert target
                collider_proof.append(dict(source=original.identity(node,obj),parsed=d,resolvedMesh=target,bytesConsumed=64,endOfObjectVerified=True,schemaBoundary='BoxCollider type-tree corroborates shared prefix through enabled@40/alignment44. MeshCollider suffix convex@44,cookingOptions@48,meshPPtr@52 structurally consumes all four pinned64-byte objects. Native suffix field offsets are not supplied by a MeshCollider type tree.'))
                if 'object' not in target:
                    out=dict(name=objects[go]['name']+' [original builtin mesh collider]',parent=node_index[tid],position=dict(x=0,y=0,z=0),rotation=dict(x=0,y=0,z=0,w=1),scale=dict(x=1,y=1,z=1),mesh=-1,collider=True,active=True,rendererEnabled=False,sourcePathId=obj['path_id'],builtinMeshId=d['m_Mesh']['m_PathID']);nodes.append(out);builtin_refs.append(dict(component=obj['path_id'],node=len(nodes)-1,purpose='collider',target=target,originalPointer=d['m_Mesh']));continue
                assert target['object']['class_id']==43;ix=add_mesh(target);mesh_colliders+=1
            else:
                center=d['m_Center'];size=d['m_Size'];vertices=[dict(zip('xyz',[center[k]+sign[j]*size[k]/2 for j,k in enumerate('xyz')])) for sign in [(-1,-1,-1),(1,-1,-1),(1,1,-1),(-1,1,-1),(-1,-1,1),(1,-1,1),(1,1,1),(-1,1,1)]]
                ix=len(meshes);meshes.append(dict(name='Original BoxCollider '+str(obj['path_id']),vertices=vertices,triangles=[0,2,1,0,3,2,4,5,6,4,6,7,0,1,5,0,5,4,2,3,7,2,7,6,0,4,7,0,7,3,1,2,6,1,6,5],normals=[],uv=[],color=dict(r=.75,g=.75,b=.75,a=1)));boxes+=1
            nodes.append(dict(name=objects[go]['name']+' [original collider geometry]',parent=node_index[tid],position=dict(x=0,y=0,z=0),rotation=dict(x=0,y=0,z=0,w=1),scale=dict(x=1,y=1,z=1),mesh=ix,collider=True,active=True,rendererEnabled=False,sourcePathId=obj['path_id']))
        except (AssertionError,ValueError,KeyError,struct.error) as error:failures.append(dict(kind='collider-export',pathId=obj['path_id'],error=str(error)))
    assert renderers>0 and meshes and finite(nodes) and finite(meshes)
    digest=fingerprint(original.bundle.path)['sha256']
    output=dict(schemaVersion=1,sceneKey='Apartment',sourceSha256=digest,nodes=nodes,meshes=meshes,textures=textures)
    report=dict(schemaVersion=1,source=fingerprint(original.bundle.path),modelsSchemaSource=fingerprint(MODELS),sceneNode=node,engineVersion=md['engine_version'],parsed3dTransforms=len(transforms),renderersExported=renderers,staticBatchDrawsReparented=static_batches,meshCollidersExported=mesh_colliders,boxCollidersExported=boxes,meshEntries=len(meshes),triangles=sum(len(m['triangles'])//3 for m in meshes),vertices=sum(len(m['vertices']) for m in meshes),meshProof=proof,materials=list(materials.values()),meshColliderProof=collider_proof,builtinMeshReferences=builtin_refs,failures=failures,scope='Original Apartment local hierarchy, active enabled triangle mesh surfaces, original primary material color/name and selected original non-trigger collider geometry. Only primary color is applied by the minimal renderer, without original shader/texture equivalence. Lighting, lightmaps, scripts, interactions, animations, NavMesh, sphere/capsule/trigger/rigidbody physics and runtime fidelity are not reconstructed. Built-in mesh references retain original IDs and require a separately recorded native resolution; they are not fabricated vertex data.',schemaRule='Except for the separately bounded64-byte MeshCollider structural suffix, only the original models type-tree with exactly equal class ID and original serialized type hash may decode a build object. Every decoded native object consumes EOF. Vertex values must be finite and each triangle index in range. Static-batch draws use their original submesh range and are attached to original batch root coordinates.')
    assert digest==ORIGINAL_DATA_SHA256 and report['modelsSchemaSource']['sha256']==MODELS_SHA256
    report['parser']=fingerprint(Path(__file__));report['albedoTexturesExported']=len(textures);report['albedoRawBytes']=sum(len(v) for v in texture_payloads.values());report['scope']=report['scope'].replace('Only primary color is applied by the minimal renderer, without original shader/texture equivalence.','Original primary color and first material MainTex compressed bytes/UV transform are provided for a new minimal material; original shaders and secondary submesh material fidelity are not reconstructed. Native texture acceptance must be tested separately.')
    return output,report,texture_payloads

def write(path,data):
    path.parent.mkdir(parents=True,exist_ok=True);path.write_text(json.dumps(data,ensure_ascii=False,separators=(',',':'))+'\n',encoding='utf8')

if __name__=='__main__':
    a=argparse.ArgumentParser();a.add_argument('--geometry',action='store_true');a.add_argument('--check',action='store_true');a.add_argument('--output',type=Path,default=HERE/'.cache');args=a.parse_args()
    models=player.models_investigation(MODELS);original=SceneInvestigation(ORIGINAL)
    if args.geometry:
        value,proof,texture_payloads=geometry(models,original)
        if args.check:
            assert json.loads((args.output/'Apartment.geometry.json').read_text(encoding='utf8'))==value
            assert json.loads((args.output/'Apartment.geometry-proof.json').read_text(encoding='utf8'))==proof
            for file,data in texture_payloads.items():assert (args.output/file).read_bytes()==data
        else:
            write(args.output/'Apartment.geometry.json',value);write(args.output/'Apartment.geometry-proof.json',proof)
            for file,data in texture_payloads.items():
                path=args.output/file;path.parent.mkdir(parents=True,exist_ok=True);path.write_bytes(data)
        print(json.dumps({k:v for k,v in proof.items() if k not in ('meshProof','source','modelsSchemaSource','materials','meshColliderProof','builtinMeshReferences')},ensure_ascii=False))
    else:
        value=inventory(models,original);assert value['models']['sha256']==MODELS_SHA256 and value['originalBuildData']['sha256']==ORIGINAL_DATA_SHA256
        if args.check:assert json.loads((HERE/'inventory.json').read_text(encoding='utf8'))==value
        else:write(HERE/'inventory.json',value)
        print(json.dumps(dict(containers=value['assetBundle']['containerCount'],classes=value['containerClassCounts'],player=value['player'],buildBundleObjects=sum(x['assetBundleObjectCount'] for x in value['buildNodes'])),ensure_ascii=False))
