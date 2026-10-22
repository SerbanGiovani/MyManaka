// One-shot Unity UI readback on its original main thread; no gameplay writes.
const m=Process.getModuleByName('GameAssembly.dll');
function api(n,r,a){return new NativeFunction(m.getExportByName(n),r,a);}
const resolve=api('il2cpp_resolve_icall','pointer',['pointer']);
const stringNew=api('il2cpp_string_new','pointer',['pointer']);
const domain=api('il2cpp_domain_get','pointer',[]);
const assemblies=api('il2cpp_domain_get_assemblies','pointer',['pointer','pointer']);
const imageOf=api('il2cpp_assembly_get_image','pointer',['pointer']);
const imageName=api('il2cpp_image_get_name','pointer',['pointer']);
const klass=api('il2cpp_class_from_name','pointer',['pointer','pointer','pointer']);
const classType=api('il2cpp_class_get_type','pointer',['pointer']);
const typeObject=api('il2cpp_type_get_object','pointer',['pointer']);
const find=new NativeFunction(m.base.add(0x1f378b0),'pointer',['pointer','pointer']);
const gameObject=new NativeFunction(m.base.add(0x4aade0),'pointer',['pointer','pointer']);
const textValue=new NativeFunction(m.base.add(0x1d76ab0),'pointer',['pointer','pointer']);
const active=new NativeFunction(resolve(Memory.allocUtf8String('UnityEngine.GameObject::get_activeInHierarchy()')),'bool',['pointer']);
const frame=new NativeFunction(resolve(Memory.allocUtf8String('UnityEngine.Time::get_frameCount()')),'int',[]);
function str(p){return p.isNull()?null:p.add(0x14).readUtf16String(p.add(0x10).readS32());}
let done=false;
Interceptor.attach(m.base.add(0x620800),{onEnter(){
 if(done)return;done=true;
 const count=Memory.alloc(8);count.writeU64(0);const list=assemblies(domain(),count),texts=[];
 for(let i=0;i<count.readU64().toNumber();i++){
  const im=imageOf(list.add(i*8).readPointer());
  if(imageName(im).readUtf8String()!=='Unity.TextMeshPro.dll')continue;
  const c=klass(im,Memory.allocUtf8String('TMPro'),Memory.allocUtf8String('TMP_Text'));
  const array=find(typeObject(classType(c)),ptr(0));
  for(let j=0;j<array.add(0x18).readU64().toNumber();j++){
   const t=array.add(0x20+j*8).readPointer();if(t.isNull()||t.add(0x10).readPointer().isNull())continue;
   const go=gameObject(t,ptr(0));if(go.isNull()||!active(go))continue;
   texts.push({object:t.toString(),text:str(textValue(t,ptr(0)))});
  }
 }
 send({kind:'ui_text_readback',frame:frame(),texts});
 const name='UnityEngine.ScreenCapture::CaptureScreenshot(System.String,System.Int32,UnityEngine.ScreenCapture/StereoScreenCaptureMode)';
 const capture=resolve(Memory.allocUtf8String(name));
 if(!capture.isNull()){
  const path='E:/ManakaREA-NaturalGameplay/capture-rea-'+frame()+'.png';
  new NativeFunction(capture,'void',['pointer','int','int'])(stringNew(Memory.allocUtf8String(path)),1,1);
  send({kind:'ui_capture_requested',frame:frame(),path});
 }else send({kind:'ui_capture_unavailable',frame:frame()});
}});
