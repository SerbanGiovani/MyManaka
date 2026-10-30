// Controlled native BodyPaintController clone, never registered with the game updater.
// Original automatic controller stays in Pca, parked state0/Dokidoki0; applier is NOT an update guard.
using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using System.Text.Json;
using BepInEx;
using BepInEx.Unity.IL2CPP;
using Il2CppInterop.Runtime.Injection;
using Il2CppInterop.Runtime.InteropTypes;
using Il2CppInterop.Runtime.InteropTypes.Arrays;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.SceneManagement;
using ExposureUnnoticed2.Scripts.InGame;
namespace REATimedBodyPaint {
[BepInPlugin("rea.timed.body.paint","REA Timed Body Paint","1.0.0")]
[BepInDependency("rea.natural.observer")]
public class TimedPaintPlugin:BasePlugin {
 public static string Root;
 public override void Load(){
  var tag=Environment.GetEnvironmentVariable("REA_TIMED_BODY_PAINT_RUN")??"20261031-2";
  if(!System.Text.RegularExpressions.Regex.IsMatch(tag,"^[A-Za-z0-9][A-Za-z0-9._-]*$")||tag=="."||tag=="..")throw new Exception("Invalid run tag");
  Root=Path.Combine(Paths.GameRootPath,"TimedBodyPaint",tag);
  if(!File.Exists(Path.Combine(Root,"working-profile","SaveData","1.sd")))throw new Exception("Disposable manual slot1 required");
  if(File.Exists(Path.Combine(Root,"managed.jsonl")))throw new Exception("Fresh run directory required");
  Directory.CreateDirectory(Path.Combine(Root,"captures"));
  var observer=AppDomain.CurrentDomain.GetAssemblies().Select(a=>a.GetType("Plugin")).Single(t=>t?.GetField("SaveRoot")!=null);
  observer.GetField("SaveRoot").SetValue(null,Path.Combine(Root,"working-profile"));((StreamWriter)observer.GetField("Output").GetValue(null)).Flush();observer.GetField("Output").SetValue(null,new StreamWriter(Path.Combine(Root,"paths.jsonl"),true));
  Application.SetStackTraceLogType(LogType.Error,StackTraceLogType.Full);Application.SetStackTraceLogType(LogType.Exception,StackTraceLogType.Full);
  ClassInjector.RegisterTypeInIl2Cpp<Runner>();AddComponent<Runner>();
 }
}
public class Runner:MonoBehaviour {
 [DllImport("kernel32.dll",CharSet=CharSet.Unicode)]static extern void OutputDebugStringW(string text);
 public Runner(IntPtr p):base(p){}
 static readonly BindingFlags F=BindingFlags.Public|BindingFlags.NonPublic|BindingFlags.Static|BindingFlags.Instance;
 static readonly Assembly Game=typeof(SaveManager).Assembly;
 static readonly string[] GlobalNames={"AutoSaveTime","ManualSaveTime","InterruptSaveTime","HomeSaveTime","DifficultData","RankData","TotalPlayTimeData","OptionData","TutorialData","GameStateData","SaveDataSlotIndex","IsTrial","OptionFaceRankBias","OptionFaceRange","PlayerCustomData"};
 static readonly string[] SmoothFields={"Current","Target","maxDelta","downMaxDelta","isLerp","baseValue","second","downSecond","isUnscaled"};
 static readonly string[] PaintFields={"alpha","pca","currentState"};
 static readonly string[] BodyRefs={"bodyMaterial","faceMaterial","fixedColorAreaMaterial","eyeRightMaterial","eyeLeftMaterial","eyeLashMaterial","eyeBlowMaterial","faceOptionMaterial"};
 static readonly string[] MaterialRefs={"SweatBodyMaterial","ClothesPaintMaterial","RubberSuitMaterial"};
 static readonly string[] FutaRefs={"TamaClothesPaintMaterial","SaoClothesPaintMaterial"};
 static readonly string[] Cases={"init-0","init-12","init-24","init-25","init-60","init-61","init-120","init-120-reusable","rate-0","rate-025","rate-05","rate-075","wash","item-ordinary-false","item-reusable","item-ordinary-true","load-ordinary","load-reusable","cross-60","cross-24","cross-0"};
 static Type T(string n)=>Game.GetTypes().Single(t=>t.Name==n);
 static Type K(object o)=>o as Type??o.GetType();static object O(object o)=>o is Type?null:o;
 static object G(object o,string n){if(o==null)throw new Exception("Null receiver: "+n);var p=K(o).GetProperty(n,F);if(p!=null)return p.GetValue(O(o));var f=K(o).GetField(n,F);if(f!=null)return f.GetValue(O(o));throw new MissingMemberException(K(o).FullName,n);}
 static object A(object v,Type t)=>v==null?v:t.IsEnum&&!t.IsInstanceOfType(v)?Enum.ToObject(t,v):v;
 static void S(object o,string n,object v){var p=K(o).GetProperty(n,F);if(p!=null){p.SetValue(O(o),A(v,p.PropertyType));return;}var f=K(o).GetField(n,F);if(f==null)throw new MissingMemberException(K(o).FullName,n);f.SetValue(O(o),A(v,f.FieldType));}
 static object M(object o,string n,params object[] a){var all=K(o).GetMethods(F).Where(m=>m.Name==n&&m.GetParameters().Length==a.Length).ToArray();var m=all.FirstOrDefault(m=>m.GetParameters().Select((p,i)=>a[i]==null||p.ParameterType.IsEnum||p.ParameterType.IsInstanceOfType(a[i])).All(x=>x))??all.Single();return m.Invoke(O(o),m.GetParameters().Select((p,i)=>A(a[i],p.ParameterType)).ToArray());}
 static object Find(Type t)=>typeof(UnityEngine.Object).GetMethods().Single(m=>m.Name=="FindObjectOfType"&&m.IsGenericMethodDefinition&&m.GetParameters().Length==0).MakeGenericMethod(t).Invoke(null,null);
 static string Ptr(object o)=>o is Il2CppObjectBase b?b.Pointer.ToString():null;
 static bool Same(object a,object b)=>a is Il2CppObjectBase||b is Il2CppObjectBase?Ptr(a)==Ptr(b):Equals(a,b);
 static void Check(bool v,string m){if(!v)throw new Exception(m);}
 static object State=>G(typeof(GameState),"GameStateData");static object Custom=>G(typeof(GameState),"PlayerCustomData");
 static object Manager=>G(typeof(InGameManager),"Instance");static object Temp=>G(Manager,"TempInGameState");
 static object Player=>G(G(Manager,"InGameReferencer"),"Player");static object Pca=>G(Player,"Pca");
 static object PS=>G(Pca,"PlayerState");object OriginalPaint=>parkedOriginal??G(Pca,"BodyPaintController");
 static object Body=>G(Pca,"PlayerBodyCustomizeAdjuster");static object Materials=>G(Pca,"PlayerBodyMaterialController");static object Futa=>G(Pca,"FutanariController");
 static object Avatar=>G(Pca,"PlayerAvatarObjectReferencer");
 static Renderer Renderer=>(Renderer)G(Avatar,"bodyMeshRenderer");static Renderer SaoRenderer=>(Renderer)G(Avatar,"FutanariMeshSao");static Renderer TamaRenderer=>(Renderer)G(Avatar,"FutanariMeshTama");
 static int Tweak=>(int)G(T("BodyPaintController"),"TweakTransparency");
 static float Remaining{get=>(float)G(State,"PlayerRemainBodyPaintTime");set=>S(State,"PlayerRemainBodyPaintTime",value);}
 static bool Reusable{get=>(bool)G(State,"IsActiveBodyPaintReusable");set=>S(State,"IsActiveBodyPaintReusable",value);}
 static float Doki{get=>(float)G(PS,"Dokidoki");set=>S(PS,"Dokidoki",value);}
 static float[] C(Color c)=>new[]{c.r,c.g,c.b,c.a};static float[] V(Vector4 v)=>new[]{v.x,v.y,v.z,v.w};
 static bool Near(float a,float b,float tolerance=.00001f)=>!float.IsNaN(a)&&!float.IsNaN(b)&&!float.IsInfinity(a)&&!float.IsInfinity(b)&&Math.Abs(a-b)<=tolerance;
 static bool Bits(float a,float b)=>BitConverter.SingleToInt32Bits(a)==BitConverter.SingleToInt32Bits(b);
 static bool EqualColor(Color a,Color b)=>Bits(a.r,b.r)&&Bits(a.g,b.g)&&Bits(a.b,b.b)&&Bits(a.a,b.a);
 static bool EqualVector(Vector4 a,Vector4 b)=>Bits(a.x,b.x)&&Bits(a.y,b.y)&&Bits(a.z,b.z)&&Bits(a.w,b.w);
 static bool EqualVector2(Vector2 a,Vector2 b)=>Bits(a.x,b.x)&&Bits(a.y,b.y);
 static object FloatInfo(float x)=>new{value=x.ToString("R",System.Globalization.CultureInfo.InvariantCulture),bits="0x"+unchecked((uint)BitConverter.SingleToInt32Bits(x)).ToString("x8"),finite=!float.IsNaN(x)&&!float.IsInfinity(x)};
 static object FloatPair(float a,float b)=>new{expected=FloatInfo(a),actual=FloatInfo(b),exactBits=Bits(a,b),absoluteDifference=(!float.IsNaN(a)&&!float.IsNaN(b)&&!float.IsInfinity(a)&&!float.IsInfinity(b))?Math.Abs((double)a-b).ToString("R",System.Globalization.CultureInfo.InvariantCulture):"non-finite"};
 static void Log(string k,object d=null)=>File.AppendAllText(Path.Combine(TimedPaintPlugin.Root,"managed.jsonl"),JsonSerializer.Serialize(new{kind=k,frame=Time.frameCount,real=Time.realtimeSinceStartup,data=d})+"\n");
 static void SafeLog(string k,object d){try{Log(k,d);}catch{}}
 object[] roots,oldPaint,oldSmooth,cloneSmooth,oldBody,oldMaterials,oldFuta;object oldSlot,oldLastItem,oldSmoothObject,clone,cloneAlpha,parkedOriginal;float oldDoki;bool oldStop,captured,paused,prepared,cleanupDone,markerOpen;
 string current="idle",phase="idle";int began,step,updateId;float desiredDoki;object initialSnapshot,guardSnapshot;
 class RenderBackup {public Renderer Renderer;public Il2CppReferenceArray<Material> Materials;}
 class PropertyBackup {public int Id;public ShaderPropertyType Kind;public Color Color;public float Float;public Vector4 Vector;public Texture Texture;public Vector2 Offset,Scale;}
 class MaterialBackup {public Material Material;public Shader Shader;public PropertyBackup[] Props;}
 RenderBackup[] renders;MaterialBackup[] props;
 object SmoothInfo(object a)=>new{pointer=Ptr(a),fields=SmoothFields.ToDictionary(n=>n,n=>G(a,n))};
 object ControllerInfo(object p)=>p==null?null:new{pointer=Ptr(p),pca=Ptr(G(p,"pca")),state=G(p,"currentState"),smooth=SmoothInfo(G(p,"alpha"))};
 object MaterialInfo(Material m,int slot=-1){if(!m)return new{slot,valid=false,pointer=Ptr(m)};int main=Shader.PropertyToID("_MainTex");bool hasMain=m.HasProperty(main);return new{slot,valid=true,pointer=Ptr(m),name=m.name,shader=Ptr(m.shader),shaderName=m.shader?m.shader.name:null,hasTweak=m.HasProperty(Tweak),tweak=m.HasProperty(Tweak)?(float?)m.GetFloat(Tweak):null,hasMain,texture=hasMain?Ptr(m.GetTexture(main)):null};}
 object RendererInfo(Renderer renderer){var mats=renderer.sharedMaterials;return new{pointer=Ptr(renderer),active=renderer.gameObject.activeInHierarchy,materials=Enumerable.Range(0,mats.Length).Select(i=>MaterialInfo(mats[i],i)).ToArray()};}
 object Snapshot(){var ms=Renderer.sharedMaterials;var sao=(Material)G(Futa,"SaoClothesPaintMaterial");var tama=(Material)G(Futa,"TamaClothesPaintMaterial");return new{state=Ptr(State),custom=Ptr(Custom),pca=Ptr(Pca),pcaBodyPaint=Ptr(G(Pca,"BodyPaintController")),playerState=Ptr(PS),remaining=Remaining,reusable=Reusable,dokidoki=Doki,lastItem=Convert.ToInt32(G(PS,"LastUseItemType")),applier=G(Temp,"IsStopGameStateApplier"),timeStop=G(Temp,"IsTimeStop"),original=ControllerInfo(OriginalPaint),clone=ControllerInfo(clone),renderer=Ptr(Renderer),materials=Enumerable.Range(0,ms.Length).Select(i=>MaterialInfo(ms[i],i)).ToArray(),clothes=MaterialInfo((Material)G(Materials,"ClothesPaintMaterial")),sao=MaterialInfo(sao),tama=MaterialInfo(tama),saoRenderer=RendererInfo(SaoRenderer),tamaRenderer=RendererInfo(TamaRenderer)};}
 string Scalars()=>JsonSerializer.Serialize(Custom.GetType().GetProperties(F).Where(p=>p.DeclaringType==Custom.GetType()&&p.GetMethod!=null&&!p.GetMethod.IsStatic&&p.GetIndexParameters().Length==0&&(p.PropertyType.IsPrimitive||p.PropertyType.IsEnum)).OrderBy(p=>p.Name).ToDictionary(p=>p.Name,p=>p.GetValue(Custom)));
 void Begin(string stage){Check(!markerOpen,"Nested marker");OutputDebugStringW("REA_TIMED_BODY_PAINT_BEGIN:"+current+"/"+stage);markerOpen=true;}
 void End(){if(markerOpen){OutputDebugStringW("REA_TIMED_BODY_PAINT_END:");markerOpen=false;}}
 void Dispatch()=>Player.GetType().GetMethods(F).Single(m=>m.Name.Contains("Initialize")&&m.Name.Contains("30_0")&&m.GetParameters().Length==0).Invoke(Player,Array.Empty<object>());
 void Capture(){
  parkedOriginal=G(Pca,"BodyPaintController");
  oldPaint=PaintFields.Select(n=>G(OriginalPaint,n)).ToArray();oldSmoothObject=G(OriginalPaint,"alpha");oldSmooth=SmoothFields.Select(n=>G(oldSmoothObject,n)).ToArray();
  oldBody=BodyRefs.Select(n=>G(Body,n)).ToArray();oldMaterials=MaterialRefs.Select(n=>G(Materials,n)).ToArray();oldFuta=FutaRefs.Select(n=>G(Futa,n)).ToArray();
  renders=((Component)Player).GetComponentsInChildren<Renderer>(true).Concat(new[]{SaoRenderer,TamaRenderer}).Where(r=>r).GroupBy(Ptr).Select(g=>g.First()).Select(r=>new RenderBackup{Renderer=r,Materials=r.sharedMaterials}).ToArray();
  var mats=renders.SelectMany(r=>Enumerable.Range(0,r.Materials.Length).Select(i=>r.Materials[i])).Concat(oldBody.OfType<Material>()).Concat(oldMaterials.OfType<Material>()).Concat(oldFuta.OfType<Material>()).Where(m=>m).GroupBy(Ptr).Select(g=>g.First());
  props=mats.Select(m=>new MaterialBackup{Material=m,Shader=m.shader,Props=Enumerable.Range(0,m.shader.GetPropertyCount()).Select(i=>{int id=m.shader.GetPropertyNameId(i);var kind=m.shader.GetPropertyType(i);var p=new PropertyBackup{Id=id,Kind=kind};if(kind==ShaderPropertyType.Color)p.Color=m.GetColor(id);else if(kind==ShaderPropertyType.Float||kind==ShaderPropertyType.Range)p.Float=m.GetFloat(id);else if(kind==ShaderPropertyType.Vector)p.Vector=m.GetVector(id);else if(kind==ShaderPropertyType.Texture){p.Texture=m.GetTexture(id);p.Offset=m.GetTextureOffset(id);p.Scale=m.GetTextureScale(id);}else throw new Exception("Unsupported backup ShaderPropertyType "+kind+" on "+m.name);return p;}).ToArray()}).ToArray();captured=true;
 }
 void RestoreRoots(){if(roots==null)return;for(int i=0;i<GlobalNames.Length;i++)S(typeof(GameState),GlobalNames[i],roots[i]);S(typeof(SaveManager),"CurrentSaveSlot",oldSlot);}
 void RestoreObjects(){if(!captured)return;
  for(int i=0;i<PaintFields.Length;i++)S(OriginalPaint,PaintFields[i],oldPaint[i]);for(int i=0;i<SmoothFields.Length;i++)S(oldSmoothObject,SmoothFields[i],oldSmooth[i]);Doki=oldDoki;S(PS,"LastUseItemType",oldLastItem);
  foreach(var r in renders)r.Renderer.sharedMaterials=r.Materials;for(int i=0;i<BodyRefs.Length;i++)S(Body,BodyRefs[i],oldBody[i]);for(int i=0;i<MaterialRefs.Length;i++)S(Materials,MaterialRefs[i],oldMaterials[i]);for(int i=0;i<FutaRefs.Length;i++)S(Futa,FutaRefs[i],oldFuta[i]);
  foreach(var m in props){if(!m.Material)continue;if(!Same(m.Material.shader,m.Shader))m.Material.shader=m.Shader;foreach(var p in m.Props){if(p.Kind==ShaderPropertyType.Color){if(!EqualColor(m.Material.GetColor(p.Id),p.Color))m.Material.SetColor(p.Id,p.Color);}else if(p.Kind==ShaderPropertyType.Float||p.Kind==ShaderPropertyType.Range){if(!Bits(m.Material.GetFloat(p.Id),p.Float))m.Material.SetFloat(p.Id,p.Float);}else if(p.Kind==ShaderPropertyType.Vector){if(!EqualVector(m.Material.GetVector(p.Id),p.Vector))m.Material.SetVector(p.Id,p.Vector);}else if(p.Kind==ShaderPropertyType.Texture){if(!Same(m.Material.GetTexture(p.Id),p.Texture))m.Material.SetTexture(p.Id,p.Texture);if(!EqualVector2(m.Material.GetTextureOffset(p.Id),p.Offset))m.Material.SetTextureOffset(p.Id,p.Offset);if(!EqualVector2(m.Material.GetTextureScale(p.Id),p.Scale))m.Material.SetTextureScale(p.Id,p.Scale);}}}
 }
 object CompareObjects(out bool restored){
  var differences=new List<object>();var legacyDisagreements=new List<object>();bool references=true,properties=true;int comparedProperties=0;
  foreach(var r in renders){var ms=r.Renderer.sharedMaterials;bool same=ms.Length==r.Materials.Length&&Enumerable.Range(0,ms.Length).All(i=>Same(ms[i],r.Materials[i]));if(!same){references=false;differences.Add(new{kind="renderer_slots",renderer=Ptr(r.Renderer),name=r.Renderer.name,expected=Enumerable.Range(0,r.Materials.Length).Select(i=>Ptr(r.Materials[i])).ToArray(),actual=Enumerable.Range(0,ms.Length).Select(i=>Ptr(ms[i])).ToArray()});}}
  void Refs(object owner,string[] names,object[] expected,string category){for(int i=0;i<names.Length;i++){var actual=G(owner,names[i]);if(!Same(actual,expected[i])){references=false;differences.Add(new{kind="cached_material_ref",category,field=names[i],owner=Ptr(owner),expected=Ptr(expected[i]),actual=Ptr(actual)});}}}
  Refs(Body,BodyRefs,oldBody,"body");Refs(Materials,MaterialRefs,oldMaterials,"materialController");Refs(Futa,FutaRefs,oldFuta,"futanari");
  foreach(var m in props){if(!m.Material){properties=false;differences.Add(new{kind="missing_material",expected=Ptr(m.Material)});continue;}if(!Same(m.Material.shader,m.Shader)){properties=false;differences.Add(new{kind="shader_ref",material=Ptr(m.Material),name=m.Material.name,expected=Ptr(m.Shader),actual=Ptr(m.Material.shader)});}
   foreach(var p in m.Props){comparedProperties++;bool exact=true,equivalent=true,legacy=true;object detail=null;
    try{
     if(p.Kind==ShaderPropertyType.Color){var v=m.Material.GetColor(p.Id);exact=equivalent=EqualColor(p.Color,v);legacy=p.Color.Equals(v);detail=new[]{FloatPair(p.Color.r,v.r),FloatPair(p.Color.g,v.g),FloatPair(p.Color.b,v.b),FloatPair(p.Color.a,v.a)};}
     else if(p.Kind==ShaderPropertyType.Float||p.Kind==ShaderPropertyType.Range){float v=m.Material.GetFloat(p.Id);exact=Bits(p.Float,v);equivalent=exact||Near(p.Float,v);legacy=Near(p.Float,v);detail=FloatPair(p.Float,v);}
     else if(p.Kind==ShaderPropertyType.Vector){var v=m.Material.GetVector(p.Id);exact=equivalent=EqualVector(p.Vector,v);legacy=p.Vector.Equals(v);detail=new[]{FloatPair(p.Vector.x,v.x),FloatPair(p.Vector.y,v.y),FloatPair(p.Vector.z,v.z),FloatPair(p.Vector.w,v.w)};}
     else if(p.Kind==ShaderPropertyType.Texture){var v=m.Material.GetTexture(p.Id);var offset=m.Material.GetTextureOffset(p.Id);var scale=m.Material.GetTextureScale(p.Id);exact=equivalent=Same(p.Texture,v)&&EqualVector2(p.Offset,offset)&&EqualVector2(p.Scale,scale);legacy=Same(p.Texture,v)&&offset.Equals(p.Offset)&&scale.Equals(p.Scale);detail=new{expected=Ptr(p.Texture),actual=Ptr(v),offset=new[]{FloatPair(p.Offset.x,offset.x),FloatPair(p.Offset.y,offset.y)},scale=new[]{FloatPair(p.Scale.x,scale.x),FloatPair(p.Scale.y,scale.y)}};}
     else{exact=equivalent=false;detail=new{unsupported=p.Kind.ToString()};}
    }catch(Exception e){exact=equivalent=false;detail=new{error=e.ToString()};}
    if(!equivalent)properties=false;if(legacy!=equivalent)legacyDisagreements.Add(new{material=Ptr(m.Material),name=m.Material.name,propertyId=p.Id,propertyType=p.Kind.ToString(),legacyEquals=legacy,componentComparison=equivalent,detail});if(!exact)differences.Add(new{kind="shader_property",material=Ptr(m.Material),name=m.Material.name,shader=Ptr(m.Material.shader),propertyId=p.Id,propertyName=m.Shader.GetPropertyName(Enumerable.Range(0,m.Shader.GetPropertyCount()).Single(i=>m.Shader.GetPropertyNameId(i)==p.Id)),propertyType=p.Kind.ToString(),exactBits=exact,equivalent,detail});
   }
  }
  restored=references&&properties;return new{restored,referencesRestored=references,propertiesRestored=properties,renderers=renders.Length,materials=props.Length,comparedProperties,differences=differences.ToArray(),legacyComparisonDisagreements=legacyDisagreements.ToArray(),floatPolicy="Color/Vector/texture coordinates require exact component bits, including unchanged NaN payloads; Float/Range retain the original finite 1e-5 tolerance, with every nonexact value reported"};
 }
 void RestoreStop(){if(paused){S(Temp,"IsStopGameStateApplier",oldStop);paused=false;}}
 void Fail(string action,Exception e){SafeLog("runner_error",new{action,current,phase,error=e.ToString()});End();try{RestoreRoots();}catch(Exception x){SafeLog("cleanup_error",new{step="roots",error=x.ToString()});}try{RestoreObjects();}catch(Exception x){SafeLog("cleanup_error",new{step="objects",error=x.ToString()});}try{RestoreStop();}catch(Exception x){SafeLog("cleanup_error",new{step="stop",error=x.ToString()});}phase="failed";}
 void ResetClone(){for(int i=0;i<SmoothFields.Length;i++)S(cloneAlpha,SmoothFields[i],cloneSmooth[i]);S(clone,"currentState",0);Doki=0;}
 void Init(float time,bool reusable){Remaining=time;Reusable=reusable;ResetClone();M(clone,"Initialize",Pca);int state=time<=0?0:time<=24?4:time<=60?3:2;float alpha=time<=0?-1:time<=24?0:time<=60?.25f:.4f;Check(Convert.ToInt32(G(clone,"currentState"))==state&&Near((float)G(cloneAlpha,"Current"),alpha),"Initialize threshold differs");Log("initialize_result",new{name=current,expected=new{remaining=time,reusable,state,alpha},snapshot=Snapshot()});}
 void SaveCapture(string suffix=""){M(typeof(SaveManager),"Save",3,1,false);var n=current+suffix;File.Copy(Path.Combine(TimedPaintPlugin.Root,"working-profile","SaveData","1.sd"),Path.Combine(TimedPaintPlugin.Root,"captures",n+".sd"),false);Log("saved",new{name=current,capture=n,snapshot=Snapshot()});}
 void Baseline(){File.Copy(Path.Combine(TimedPaintPlugin.Root,"baseline.sd"),Path.Combine(TimedPaintPlugin.Root,"working-profile","SaveData","1.sd"),true);M(typeof(SaveManager),"Load",3,1);S(typeof(SaveManager),"CurrentSaveSlot",1);Doki=0;Check(Convert.ToInt32(G(OriginalPaint,"currentState"))==0&&Near((float)G(G(OriginalPaint,"alpha"),"Current"),-1),"Original controller left park");}
 void SingleUpdate(float target){
  int id=++updateId;float before=Remaining,dt=Time.deltaTime;float rate=2*Mathf.Clamp(target,0,.5f),expected=Mathf.Max(0,before-rate*dt);Begin("update-"+id);Doki=target;Log("manual_update_before",new{name=current,id,targetDokidoki=target,actualDokidoki=Doki,deltaTime=dt,expectedRate=rate,expectedRemaining=expected,snapshot=Snapshot()});
  try{M(clone,"OnUpdate");}finally{Doki=0;}
  Check(Near(Remaining,expected,Mathf.Max(.00002f,Math.Abs(before)*.000001f)),"Single native countdown differs from measured deltaTime");Check(Doki==0,"Doki failed to restore to park");
  int state=Convert.ToInt32(G(clone,"currentState"));float alpha=(float)G(cloneAlpha,"Current");if(state!=0){foreach(var mat in new[]{(Material)G(Materials,"ClothesPaintMaterial"),(Material)G(Futa,"SaoClothesPaintMaterial"),(Material)G(Futa,"TamaClothesPaintMaterial")})if(mat)Check(mat.HasProperty(Tweak)&&Near(mat.GetFloat(Tweak),alpha),"Native transparency target differs from alpha");}
  Log("manual_update_after",new{name=current,id,targetDokidoki=target,deltaTime=dt,expectedRate=rate,expectedRemaining=expected,restoredDokidoki=Doki,snapshot=Snapshot()});End();
 }
 void Result(){Log("result",new{name=current,snapshot=Snapshot()});phase="idle";}
 public void Update(){
  try{
   if(phase=="single"){SingleUpdate(desiredDoki);Result();return;}
   if(phase=="cross-follow"){float before=(float)G(cloneAlpha,"Current");SingleUpdate(0);float after=(float)G(cloneAlpha,"Current");Check(after<before,"Threshold crossing did not begin smoothing on next update");Log("crossing_follow",new{name=current,alphaBefore=before,alphaAfter=after,snapshot=Snapshot()});Result();return;}
   if(phase=="wash"){SingleUpdate(0);step++;Log("wash_frame",new{name=current,step,snapshot=Snapshot()});if(Convert.ToInt32(G(clone,"currentState"))==0){Check(Remaining==0&&!Reusable&&!(Material)G(Materials,"ClothesPaintMaterial"),"Wash did not remove timed body material");Result();}else Check(step<600&&Time.realtimeSinceStartup-beganReal<15,"Wash fade timeout");return;}
   if(phase=="warm-body"){Begin("body-only");Dispatch();Log("body_broadcast_only",new{name=current,snapshot=Snapshot()});End();var mat=(Material)G(Materials,"ClothesPaintMaterial");Check(mat,"Positive loaded time failed to recreate material");float before=mat.GetFloat(Tweak);SingleUpdate(0);Check(Convert.ToInt32(G(clone,"currentState"))==0&&Near((float)G(cloneAlpha,"Current"),-1)&&Near(mat.GetFloat(Tweak),before),"State0 trap was not isolated");Log("body_only_after_update",new{name=current,snapshot=Snapshot()});phase="warm-init";return;}
   if(phase=="warm-init"){Begin("explicit-initialize");M(clone,"Initialize",Pca);Log("explicit_initialize_result",new{name=current,snapshot=Snapshot()});End();SingleUpdate(0);Check(Convert.ToInt32(G(clone,"currentState"))==2&&Near((float)G(cloneAlpha,"Current"),.4f),"Explicit initialization did not recover positive timed state");Result();return;}
   var path=Path.Combine(TimedPaintPlugin.Root,"command");if(!File.Exists(path))return;var action=File.ReadAllText(path).Trim();File.Move(path,path+"-"+Time.frameCount);Handle(action);
  }catch(Exception e){Fail("Update",e);}
 }
 float beganReal;
 void Handle(string action){
  Log("command",new{action,current,phase,scene=SceneManager.GetActiveScene().name});
  if(action=="ready"){var a=G(T("AssetReferencer"),"Instance");Log("readiness",new{assets=Ptr(a),hair=a==null?null:Ptr(G(a,"MHair")),scene=SceneManager.GetActiveScene().name});return;}
  if(action=="boot"){M(Find(T("TitleSceneView")),"OnClickContinue");return;}
  if(action=="continue"){M(typeof(SaveManager),"Load",3,1);S(typeof(SaveManager),"CurrentSaveSlot",1);M(Find(T("SaveDataSelectPanelView")),"TransScene");return;}
  if(action=="quit"){
   if(phase=="failed"){bool callsCompleted=true;try{RestoreRoots();}catch(Exception e){callsCompleted=false;SafeLog("cleanup_error",new{step="quit_roots",error=e.ToString()});}try{RestoreObjects();}catch(Exception e){callsCompleted=false;SafeLog("cleanup_error",new{step="quit_objects",error=e.ToString()});}try{RestoreStop();}catch(Exception e){callsCompleted=false;SafeLog("cleanup_error",new{step="quit_stop",error=e.ToString()});}SafeLog("failed_quit_requested",new{unityMainThread=true,restorationAttempted=true,restoreCallsCompleted=callsCompleted,cleanupVerified=false});Application.Quit();return;}
   Check(cleanupDone&&phase=="done","Successful cleanup or failed-phase restore required before quit");Log("quit_requested",new{unityMainThread=true,cleanupVerified=true});Application.Quit();return;
  }
  if(action=="prepare"){
   Check(roots==null&&phase=="idle"&&SceneManager.GetActiveScene().name=="Apartment","Fresh Apartment required");Check(!(bool)G(Temp,"IsTimeStop"),"No time stop");var assets=G(T("AssetReferencer"),"Instance");Check(assets!=null&&G(assets,"MHair")!=null,"Assets not ready");Check(Remaining==0&&!Reusable,"Fresh unpainted data required");
   oldSlot=G(typeof(SaveManager),"CurrentSaveSlot");oldStop=(bool)G(Temp,"IsStopGameStateApplier");oldDoki=Doki;oldLastItem=G(PS,"LastUseItemType");roots=GlobalNames.Select(n=>G(typeof(GameState),n)).ToArray();var scalar=Scalars();initialSnapshot=Snapshot();Capture();
   S(Temp,"IsStopGameStateApplier",true);paused=true;M(typeof(SaveManager),"Load",3,1);S(typeof(SaveManager),"CurrentSaveSlot",1);Check(!Same(State,roots[9])&&!Same(Custom,roots[14])&&Scalars()==scalar,"Detached matching data roots required");
   Check(Remaining==0&&!Reusable,"Disposable profile must start unpainted");var dict=G(Custom,"BodyPaintTypeDict");for(int i=0;i<10;i++)Check(!(bool)M(dict,"ContainsKey",i)||!(bool)M(dict,"get_Item",i),"Persistent body paint must be absent/false in this timed-only batch");
   M(typeof(SaveManager),"Save",3,1,false);File.Copy(Path.Combine(TimedPaintPlugin.Root,"working-profile","SaveData","1.sd"),Path.Combine(TimedPaintPlugin.Root,"baseline.sd"),false);
   clone=Activator.CreateInstance(OriginalPaint.GetType());cloneAlpha=G(clone,"alpha");cloneSmooth=SmoothFields.Select(n=>G(cloneAlpha,n)).ToArray();Check(!Same(clone,OriginalPaint)&&!Same(cloneAlpha,oldSmoothObject),"Clone/alpha must be independent native instances");
   S(OriginalPaint,"currentState",0);S(oldSmoothObject,"Current",-1f);Doki=0;Init(0,false);Remaining=120;current="guard-probe";Begin("parked-five-frames");guardSnapshot=Snapshot();Log("guard_before",new{name=current,frames=5,authority="original-auto-state0-Dokidoki0; native clone unregistered; applier does not block updates",snapshot=guardSnapshot});began=Time.frameCount;phase="guard";return;
  }
  if(action.StartsWith("case ")){
   Check(prepared&&phase=="idle","Prepared idle runner required");current=action.Substring(5);Check(Cases.Contains(current),"Unknown finite case");Baseline();Begin("setup");desiredDoki=0;
   if(current.StartsWith("init-")){float time=current=="init-120-reusable"?120:float.Parse(current.Substring(5),System.Globalization.CultureInfo.InvariantCulture);Init(time,current.EndsWith("reusable"));Dispatch();Log("case_begin",new{name=current,group="threshold",snapshot=Snapshot()});SaveCapture();End();phase="single";return;}
   if(current.StartsWith("rate-")){Init(120,false);Dispatch();desiredDoki=current=="rate-025"?.25f:current=="rate-05"?.5f:current=="rate-075"?.75f:0;Log("case_begin",new{name=current,group="rate",targetDokidoki=desiredDoki,snapshot=Snapshot()});End();phase="single";return;}
   if(current=="wash"){Init(120,true);Dispatch();Log("wash_before",new{name=current,snapshot=Snapshot()});M(clone,"OnUseWashItem");Check(Remaining==0&&Reusable&&Convert.ToInt32(G(clone,"currentState"))==4,"Wash must only set time0/state4 before next update");Log("wash_return",new{name=current,snapshot=Snapshot()});SaveCapture("-return");End();phase="wash";step=0;beganReal=Time.realtimeSinceStartup;return;}
   if(current.StartsWith("item-")){bool prior=current=="item-ordinary-true",reusableItem=current=="item-reusable";Init(0,prior);Dispatch();S(PS,"LastUseItemType",reusableItem?8:5);Log("item_before",new{name=current,priorReusable=prior,itemType=reusableItem?8:5,snapshot=Snapshot()});M(clone,"OnUseItem");Check(Remaining==120&&Reusable==(prior||reusableItem)&&Convert.ToInt32(G(clone,"currentState"))==2&&Near((float)G(cloneAlpha,"Current"),1),"Native item behavior differs");Log("item_return",new{name=current,snapshot=Snapshot()});SaveCapture();End();phase="single";return;}
   if(current.StartsWith("cross-")){float edge=current=="cross-60"?60:current=="cross-24"?24:0;Init(edge==60?61:edge==24?25:12,edge==0);Dispatch();End();Remaining=edge+Time.deltaTime/4;Log("crossing_before",new{name=current,edge,deltaTime=Time.deltaTime,snapshot=Snapshot()});SingleUpdate(.5f);int expectedState=edge==60?3:edge==24?4:1;float expectedAlpha=edge==60?.4f:edge==24?.25f:0;Check(Convert.ToInt32(G(clone,"currentState"))==expectedState&&Near((float)G(cloneAlpha,"Current"),expectedAlpha)&&(edge!=0||!Reusable),"Native runtime threshold transition differs");Log("crossing_return",new{name=current,edge,expectedState,expectedAlpha,snapshot=Snapshot()});Begin("cross-save");SaveCapture();End();if(edge==0){phase="wash";step=0;beganReal=Time.realtimeSinceStartup;}else phase="cross-follow";return;}
   bool reuse=current=="load-reusable";Init(reuse?120:61,reuse);Dispatch();Log("save_reference",new{name=current,snapshot=Snapshot()});SaveCapture();Init(0,!reuse);Dispatch();Log("load_disturbed",new{name=current,snapshot=Snapshot()});M(typeof(SaveManager),"Load",3,1);Log("loaded_without_initialize",new{name=current,snapshot=Snapshot()});Check(Remaining==(reuse?120:61)&&Reusable==reuse&&Convert.ToInt32(G(clone,"currentState"))==0&&Near((float)G(cloneAlpha,"Current"),-1)&&!(Material)G(Materials,"ClothesPaintMaterial"),"Load unexpectedly initialized controller/material");End();phase="warm-body";return;
  }
  if(action=="cleanup"){
   Check(roots!=null&&(phase=="idle"||phase=="failed"),"Captured roots and no pending case required");current="cleanup";RestoreRoots();
   if(!captured){RestoreStop();Log("cleanup_without_material_backup",new{broadcast=false});phase="failed";return;}
   Begin("native-restore");Doki=0;M(OriginalPaint,"Initialize",Pca);Dispatch();began=Time.frameCount;phase="cleanup";return;
  }
  throw new Exception("Unknown command");
 }
 public void LateUpdate(){try{
  if(phase=="guard"&&Time.frameCount-began>=5){Check(Remaining==120&&Doki==0&&Convert.ToInt32(G(OriginalPaint,"currentState"))==0&&Near((float)G(oldSmoothObject,"Current"),-1)&&Convert.ToInt32(G(clone,"currentState"))==0&&Near((float)G(cloneAlpha,"Current"),-1)&&Same(G(Pca,"BodyPaintController"),OriginalPaint),"Park guard failed");Log("guard_after",new{name=current,frames=Time.frameCount-began,snapshot=Snapshot()});End();Remaining=0;Reusable=false;prepared=true;phase="idle";Log("prepared",new{authority="controlled-unregistered-native-body-paint-clone",natural_only=false,original=initialSnapshot,parked=Snapshot(),cloneConstructorSmooth=new{pointer=Ptr(cloneAlpha),fields=SmoothFields.Select((n,i)=>new{n,i}).ToDictionary(x=>x.n,x=>cloneSmooth[x.i])},supportedShaderPropertyKinds=props.SelectMany(m=>m.Props).GroupBy(p=>p.Kind.ToString()).ToDictionary(g=>g.Key,g=>g.Count()),scope="Original automatic controller remains registered, state0/Dokidoki0; no claim applier suppresses OnUpdate"});return;}
  if(phase=="cleanup"&&Time.frameCount-began>=5){var before=CompareObjects(out bool beforeRestored);Log("cleanup_material_diff_before",new{name=current,report=before});RestoreObjects();RestoreStop();var after=CompareObjects(out bool objectsRestored);Log("cleanup_material_diff_after",new{name=current,report=after});bool rootsRestored=GlobalNames.Select((n,i)=>Same(G(typeof(GameState),n),roots[i])).All(x=>x),controllerRestored=PaintFields.Select((n,i)=>Same(G(OriginalPaint,n),oldPaint[i])).All(x=>x)&&SmoothFields.Select((n,i)=>Same(G(oldSmoothObject,n),oldSmooth[i])).All(x=>x),playerStateRestored=Near(Doki,oldDoki)&&Same(G(PS,"LastUseItemType"),oldLastItem),stopRestored=(bool)G(Temp,"IsStopGameStateApplier")==oldStop,slotRestored=Same(G(typeof(SaveManager),"CurrentSaveSlot"),oldSlot);Log("cleanup",new{rootsRestored,controllerRestored,objectsRestored,playerStateRestored,stopRestored,slotRestored,original=initialSnapshot,restored=Snapshot()});Check(rootsRestored&&controllerRestored&&objectsRestored&&playerStateRestored&&stopRestored&&slotRestored,"Cleanup verification failed");End();cleanupDone=true;phase="done";Log("cleanup_done",new{verified=true,unityMainThread=true,objectsRestored,rootsRestored,controllerRestored,playerStateRestored,stopRestored,slotRestored});}
 }catch(Exception e){Fail("LateUpdate",e);}}
}
}
