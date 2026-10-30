// Controlled preset branch only. All native methods execute on Unity's thread.
// Static reuse: 14602 OnChangeBody, ev_657222ee36618837bad219457cd98f55c1b884066ecb43af2300a7e2a7ac548a.
// SkinPattern is MCustomizeColor+0x18; SkinColor has two Color values (32 bytes unboxed).
// Custom index/free/RGB are +0x78/+0x88/+0x7c,+0x80,+0x84. No repeated Initialize/subscriptions.
using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text.Json;
using System.Collections.Generic;
using BepInEx;
using BepInEx.Unity.IL2CPP;
using Il2CppInterop.Runtime.Injection;
using Il2CppInterop.Runtime.InteropTypes;
using Il2CppInterop.Runtime.InteropTypes.Arrays;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.SceneManagement;
using ExposureUnnoticed2.Scripts.InGame;

namespace REASkinPreset {
[BepInPlugin("rea.skin.preset","REA Skin Preset","1.0.0")]
[BepInDependency("rea.natural.observer")]
public class SkinPresetPlugin:BasePlugin {
 public static string Root;
 public override void Load(){
  var tag=Environment.GetEnvironmentVariable("REA_SKIN_PRESET_RUN")??"20261030-1";
  if(!System.Text.RegularExpressions.Regex.IsMatch(tag,"^[A-Za-z0-9][A-Za-z0-9._-]*$")||tag=="."||tag=="..")throw new Exception("Invalid run tag");
  Root=Path.Combine(Paths.GameRootPath,"SkinPreset",tag);
  if(!File.Exists(Path.Combine(Root,"working-profile","SaveData","1.sd")))throw new Exception("Prepare disposable manual slot1 before installing the probe");
  if(File.Exists(Path.Combine(Root,"managed.jsonl")))throw new Exception("Fresh run directory required; existing logs are never replaced");
  Directory.CreateDirectory(Path.Combine(Root,"captures"));
  var observer=AppDomain.CurrentDomain.GetAssemblies().Select(a=>a.GetType("Plugin")).Single(t=>t?.GetField("SaveRoot")!=null);
  observer.GetField("SaveRoot").SetValue(null,Path.Combine(Root,"working-profile"));
  ((StreamWriter)observer.GetField("Output").GetValue(null)).Flush();
  observer.GetField("Output").SetValue(null,new StreamWriter(Path.Combine(Root,"paths.jsonl"),true));
  Application.SetStackTraceLogType(LogType.Error,StackTraceLogType.Full);
  Application.SetStackTraceLogType(LogType.Exception,StackTraceLogType.Full);
  ClassInjector.RegisterTypeInIl2Cpp<Runner>();AddComponent<Runner>();
 }
}
public class Runner:MonoBehaviour {
 [DllImport("kernel32.dll",CharSet=CharSet.Unicode)]static extern void OutputDebugStringW(string text);
 public Runner(IntPtr pointer):base(pointer){}
 static readonly BindingFlags Flags=BindingFlags.Public|BindingFlags.NonPublic|BindingFlags.Static|BindingFlags.Instance;
 static readonly Assembly Game=typeof(SaveManager).Assembly;
 static readonly string[] GlobalNames={"AutoSaveTime","ManualSaveTime","InterruptSaveTime","HomeSaveTime","DifficultData","RankData","TotalPlayTimeData","OptionData","TutorialData","GameStateData","SaveDataSlotIndex","IsTrial","OptionFaceRankBias","OptionFaceRange","PlayerCustomData"};
 static readonly string[] SkinFields={"CustomIsSkinColorFree","CustomizeSkinColor","CustomizeSkinColorR","CustomizeSkinColorG","CustomizeSkinColorB"};
 static readonly string[] BodyMaterialFields={"bodyMaterial","faceMaterial","fixedColorAreaMaterial","eyeRightMaterial","eyeLeftMaterial","eyeLashMaterial","eyeBlowMaterial","faceOptionMaterial"};
 static readonly string[] PaintMaterialFields={"SweatBodyMaterial","ClothesPaintMaterial","RubberSuitMaterial"};
 static Type T(string name)=>Game.GetTypes().Single(t=>t.Name==name);
 static Type K(object o)=>o as Type??o.GetType();
 static object O(object o)=>o is Type?null:o;
 static object G(object o,string name){if(o==null)throw new Exception("Null receiver: "+name);var p=K(o).GetProperty(name,Flags);if(p!=null)return p.GetValue(O(o));var f=K(o).GetField(name,Flags);if(f!=null)return f.GetValue(O(o));throw new MissingMemberException(K(o).FullName,name);}
 static object Arg(object v,Type t)=>v==null?v:t.IsEnum&&!t.IsInstanceOfType(v)?Enum.ToObject(t,v):v;
 static void S(object o,string name,object v){var p=K(o).GetProperty(name,Flags);if(p!=null){p.SetValue(O(o),Arg(v,p.PropertyType));return;}var f=K(o).GetField(name,Flags);if(f==null)throw new MissingMemberException(K(o).FullName,name);f.SetValue(O(o),Arg(v,f.FieldType));}
 static object M(object o,string name,params object[] args){var all=K(o).GetMethods(Flags).Where(m=>m.Name==name&&m.GetParameters().Length==args.Length).ToArray();var m=all.FirstOrDefault(m=>m.GetParameters().Select((p,i)=>args[i]==null||p.ParameterType.IsEnum||p.ParameterType.IsInstanceOfType(args[i])).All(x=>x))??all.Single();return m.Invoke(O(o),m.GetParameters().Select((p,i)=>Arg(args[i],p.ParameterType)).ToArray());}
 static object Find(Type type)=>typeof(UnityEngine.Object).GetMethods().Single(m=>m.Name=="FindObjectOfType"&&m.IsGenericMethodDefinition&&m.GetParameters().Length==0).MakeGenericMethod(type).Invoke(null,null);
 static string Ptr(object o)=>o is Il2CppObjectBase b?b.Pointer.ToString():null;
 static bool Same(object a,object b)=>a is Il2CppObjectBase||b is Il2CppObjectBase?Ptr(a)==Ptr(b):Equals(a,b);
 static object State=>G(typeof(GameState),"GameStateData");
 static object Custom=>G(typeof(GameState),"PlayerCustomData");
 static object Temp=>G(G(typeof(InGameManager),"Instance"),"TempInGameState");
 static object Player=>G(G(G(typeof(InGameManager),"Instance"),"InGameReferencer"),"Player");
 static object Pca=>G(Player,"Pca");
 static object Body=>G(Pca,"PlayerBodyCustomizeAdjuster");
 static object Materials=>G(Pca,"PlayerBodyMaterialController");
 static object Avatar=>G(Pca,"PlayerAvatarObjectReferencer");
 static Renderer BodyRenderer=>(Renderer)G(Avatar,"bodyMeshRenderer");
 static Renderer FaceRenderer=>(Renderer)G(Avatar,"FaceMesh");
 static int BaseId=>(int)G(Body,"BaseColor");
 static int ShadeId=>(int)G(Body,"StShadeColor");
 static float[] C(Color c)=>new[]{c.r,c.g,c.b,c.a};
 static bool Near(Color a,Color b){var x=C(a);var y=C(b);return Enumerable.Range(0,4).All(i=>!float.IsNaN(x[i])&&!float.IsInfinity(x[i])&&Math.Abs(x[i]-y[i])<.00001f);}
 static void Check(bool value,string message){if(!value)throw new Exception(message);}
 static void Log(string kind,object data=null)=>File.AppendAllText(Path.Combine(SkinPresetPlugin.Root,"managed.jsonl"),JsonSerializer.Serialize(new{kind,frame=Time.frameCount,real=Time.realtimeSinceStartup,data})+"\n");
 void TryLog(string kind,object data){try{Log(kind,data);}catch{}}
 object FieldValues()=>SkinFields.ToDictionary(n=>n,n=>G(Custom,n));
 string ScalarSignature(object custom)=>JsonSerializer.Serialize(custom.GetType().GetProperties(Flags).Where(p=>p.DeclaringType==custom.GetType()&&p.GetMethod!=null&&!p.GetMethod.IsStatic&&p.GetIndexParameters().Length==0&&(p.PropertyType.IsPrimitive||p.PropertyType.IsEnum)).OrderBy(p=>p.Name).ToDictionary(p=>p.Name,p=>p.GetValue(custom)));
 Color[] ReadColors(){var b=(Material)G(Body,"bodyMaterial");var f=(Material)G(Body,"faceMaterial");Check(b&&f&&b.HasProperty(BaseId)&&b.HasProperty(ShadeId)&&f.HasProperty(BaseId)&&f.HasProperty(ShadeId),"Body/face shader color targets missing");return new[]{b.GetColor(BaseId),b.GetColor(ShadeId),f.GetColor(BaseId),f.GetColor(ShadeId)};}
 bool ColorsNear(Color[] a,Color[] b)=>a.Length==b.Length&&Enumerable.Range(0,a.Length).All(i=>Near(a[i],b[i]));
 object MaterialInfo(Material m,int slot){if(!m)return new{slot,valid=false,pointer=Ptr(m)};return new{slot,valid=true,pointer=Ptr(m),name=m.name,shader=Ptr(m.shader),shaderName=m.shader?m.shader.name:null,hasBase=m.HasProperty(BaseId),hasShade=m.HasProperty(ShadeId),baseColor=m.HasProperty(BaseId)?C(m.GetColor(BaseId)):null,shadeColor=m.HasProperty(ShadeId)?C(m.GetColor(ShadeId)):null};}
 object RendererInfo(Renderer renderer){var mats=renderer.sharedMaterials;return new{pointer=Ptr(renderer),materials=Enumerable.Range(0,mats.Length).Select(i=>MaterialInfo(mats[i],i)).ToArray()};}
 object Snapshot()=>new{state=Ptr(State),custom=Ptr(Custom),fields=FieldValues(),body=MaterialInfo((Material)G(Body,"bodyMaterial"),-1),face=MaterialInfo((Material)G(Body,"faceMaterial"),-1),bodyRenderer=RendererInfo(BodyRenderer),faceRenderer=RendererInfo(FaceRenderer),stop=G(Temp,"IsStopGameStateApplier")};

 class RendererBackup {public Renderer Renderer;public Il2CppReferenceArray<Material> Materials;}
 class MaterialBackup {public Material Material;public int[] Ids;public Color[] Colors;}
 object[] roots,oldBodyRefs,oldPaintRefs;object oldSlot,master,patterns;bool oldStop,backupComplete,paused,prepared,markerOpen;
 RendererBackup[] rendererBackups;MaterialBackup[] materialBackups;
 Color[][] expected;Color[] disturbedColors;int[] disturbedRgb;string originalScalar;
 object originalSnapshot;string phase="idle",current="idle";int selected,began;float next;
 void Begin(string stage){Check(!markerOpen,"Nested marker");OutputDebugStringW("REA_SKIN_PRESET_BEGIN:"+current+"/"+stage);markerOpen=true;}
 void End(){if(markerOpen){OutputDebugStringW("REA_SKIN_PRESET_END:");markerOpen=false;}}
 void Dispatch(){var method=Player.GetType().GetMethods(Flags).Single(m=>m.Name.Contains("Initialize")&&m.Name.Contains("30_0")&&m.GetParameters().Length==0);method.Invoke(Player,Array.Empty<object>());}
 Color[][] ReadExpected(){
  var assets=G(T("AssetReferencer"),"Instance");Check(assets!=null&&G(assets,"MHair")!=null,"AssetReferencer/MHair not ready");
  var assetMaster=G(assets,"MCustomizeColor");master=G(T("MCustomizeColor"),"Instance");Check(master!=null&&Same(master,assetMaster),"MCustomizeColor.Instance differs from original AssetReferencer master");
  patterns=G(master,"SkinPattern");Check(Convert.ToInt32(G(patterns,"Length"))>=2,"Two valid SkinPattern entries required");
  return Enumerable.Range(0,2).Select(i=>{var record=M(patterns,"get_Item",i);return new[]{(Color)G(record,"BodyPrimary"),(Color)G(record,"BodySecondary")};}).ToArray();
 }
 object ExpectedInfo()=>Enumerable.Range(0,2).Select(i=>new{index=i,primary=C(expected[i][0]),secondary=C(expected[i][1])}).ToArray();
 bool MasterUnchanged(){if(!Same(master,G(T("MCustomizeColor"),"Instance"))||!Same(master,G(G(T("AssetReferencer"),"Instance"),"MCustomizeColor"))||!Same(patterns,G(master,"SkinPattern")))return false;return Enumerable.Range(0,2).All(i=>{var r=M(patterns,"get_Item",i);return Near((Color)G(r,"BodyPrimary"),expected[i][0])&&Near((Color)G(r,"BodySecondary"),expected[i][1]);});}
 void CaptureMaterials(){
  rendererBackups=((Component)Player).GetComponentsInChildren<Renderer>(true).Select(r=>new RendererBackup{Renderer=r,Materials=r.sharedMaterials}).ToArray();
  oldBodyRefs=BodyMaterialFields.Select(n=>G(Body,n)).ToArray();oldPaintRefs=PaintMaterialFields.Select(n=>G(Materials,n)).ToArray();
  var all=rendererBackups.SelectMany(r=>Enumerable.Range(0,r.Materials.Length).Select(i=>r.Materials[i])).Concat(oldBodyRefs.OfType<Material>()).Concat(oldPaintRefs.OfType<Material>()).Where(m=>m).GroupBy(m=>Ptr(m)).Select(g=>g.First()).ToArray();
  materialBackups=all.Select(m=>{var shader=m.shader;Check(shader,"Material shader missing");var ids=Enumerable.Range(0,shader.GetPropertyCount()).Where(i=>shader.GetPropertyType(i)==ShaderPropertyType.Color).Select(shader.GetPropertyNameId).ToArray();return new MaterialBackup{Material=m,Ids=ids,Colors=ids.Select(m.GetColor).ToArray()};}).ToArray();backupComplete=true;
 }
 bool RefsRestored()=>rendererBackups.All(r=>{var ms=r.Renderer.sharedMaterials;return ms.Length==r.Materials.Length&&Enumerable.Range(0,ms.Length).All(i=>Same(ms[i],r.Materials[i]));})&&BodyMaterialFields.Select((n,i)=>Same(G(Body,n),oldBodyRefs[i])).All(x=>x)&&PaintMaterialFields.Select((n,i)=>Same(G(Materials,n),oldPaintRefs[i])).All(x=>x);
 bool PropertiesRestored()=>materialBackups.All(m=>m.Material&&m.Ids.Select((id,i)=>Near(m.Material.GetColor(id),m.Colors[i])).All(x=>x));
 void RestoreRoots(){if(roots==null)return;for(int i=0;i<GlobalNames.Length;i++)S(typeof(GameState),GlobalNames[i],roots[i]);S(typeof(SaveManager),"CurrentSaveSlot",oldSlot);}
 void RestoreMaterials(){if(!backupComplete)return;foreach(var r in rendererBackups)r.Renderer.sharedMaterials=r.Materials;for(int i=0;i<BodyMaterialFields.Length;i++)S(Body,BodyMaterialFields[i],oldBodyRefs[i]);for(int i=0;i<PaintMaterialFields.Length;i++)S(Materials,PaintMaterialFields[i],oldPaintRefs[i]);foreach(var m in materialBackups)if(m.Material)for(int i=0;i<m.Ids.Length;i++)m.Material.SetColor(m.Ids[i],m.Colors[i]);}
 void RestoreStop(){if(paused){S(Temp,"IsStopGameStateApplier",oldStop);paused=false;}}
 void Fail(string action,Exception error){
  TryLog("runner_error",new{action,current,phase,error=error.ToString()});End();
  try{RestoreRoots();}catch(Exception e){TryLog("cleanup_error",new{step="roots",error=e.ToString()});}
  try{RestoreMaterials();}catch(Exception e){TryLog("cleanup_error",new{step="materials",error=e.ToString()});}
  try{RestoreStop();}catch(Exception e){TryLog("cleanup_error",new{step="stop",error=e.ToString()});}
  phase="failed";
 }
 void LoadBaseline(){File.Copy(Path.Combine(SkinPresetPlugin.Root,"baseline.sd"),Path.Combine(SkinPresetPlugin.Root,"working-profile","SaveData","1.sd"),true);M(typeof(SaveManager),"Load",3,1);S(typeof(SaveManager),"CurrentSaveSlot",1);}
 void Configure(bool free){S(Custom,"CustomIsSkinColorFree",free);S(Custom,"CustomizeSkinColor",selected);var rgb=free?disturbedRgb:new[]{13,71,199};for(int i=0;i<3;i++)S(Custom,SkinFields[i+2],rgb[i]);}
 void SaveCapture(){M(typeof(SaveManager),"Save",3,1,false);File.Copy(Path.Combine(SkinPresetPlugin.Root,"working-profile","SaveData","1.sd"),Path.Combine(SkinPresetPlugin.Root,"captures",current+".sd"),false);}
 void AssertSavedFields(){Check(!(bool)G(Custom,"CustomIsSkinColorFree")&&(int)G(Custom,"CustomizeSkinColor")==selected&&(int)G(Custom,"CustomizeSkinColorR")==13&&(int)G(Custom,"CustomizeSkinColorG")==71&&(int)G(Custom,"CustomizeSkinColorB")==199,"Saved preset/free/RGB fields not restored");}
 void AssertPreset(){AssertSavedFields();var exp=new[]{expected[selected][0],expected[selected][1],expected[selected][0],expected[selected][1]};Check(ColorsNear(ReadColors(),exp),"Actual body/face colors differ from independent original SkinPattern");Check(MasterUnchanged(),"Original preset asset changed");}
 public void Update(){
  if(Time.realtimeSinceStartup<next)return;next=Time.realtimeSinceStartup+.05f;string action="read_command";
  try{var path=Path.Combine(SkinPresetPlugin.Root,"command");if(!File.Exists(path))return;action=File.ReadAllText(path).Trim();File.Move(path,path+"-"+Time.frameCount);Handle(action);}catch(Exception e){Fail(action,e);}
 }
 void Handle(string action){
  Log("command",new{action,current,phase,scene=SceneManager.GetActiveScene().name});
  if(action=="ready"){var assets=G(T("AssetReferencer"),"Instance");Log("readiness",new{assets=Ptr(assets),hair=assets==null?null:Ptr(G(assets,"MHair")),scene=SceneManager.GetActiveScene().name});return;}
  if(action=="boot"){M(Find(T("TitleSceneView")),"OnClickContinue");return;}
  if(action=="continue"){M(typeof(SaveManager),"Load",3,1);S(typeof(SaveManager),"CurrentSaveSlot",1);M(Find(T("SaveDataSelectPanelView")),"TransScene");return;}
  if(action=="prepare"){
   Check(roots==null&&phase=="idle"&&SceneManager.GetActiveScene().name=="Apartment","Fresh Apartment required");Check(!(bool)G(Temp,"IsTimeStop"),"No time-stop during skin fixture");
   expected=ReadExpected();Check(!Near(expected[0][0],expected[1][0])||!Near(expected[0][1],expected[1][1]),"Presets 0 and 1 must be distinguishable");
   disturbedRgb=new[]{17,203,91};var freeColor=new Color(disturbedRgb[0]/255f,disturbedRgb[1]/255f,disturbedRgb[2]/255f,1);Check(expected.All(e=>!Near(e[0],freeColor)),"Perturbation RGB accidentally matches a selected preset");
   oldSlot=G(typeof(SaveManager),"CurrentSaveSlot");oldStop=(bool)G(Temp,"IsStopGameStateApplier");roots=GlobalNames.Select(n=>G(typeof(GameState),n)).ToArray();originalScalar=ScalarSignature(Custom);originalSnapshot=Snapshot();CaptureMaterials();S(Temp,"IsStopGameStateApplier",true);paused=true;
   // Existing disposable profile is loaded before the first fixture field mutation/Save.
   M(typeof(SaveManager),"Load",3,1);S(typeof(SaveManager),"CurrentSaveSlot",1);Check(!Same(Custom,roots[14])&&!Same(State,roots[9]),"Native Load did not detach original roots");
   Check(ScalarSignature(Custom)==originalScalar,"Disposable profile scalar appearance differs from original player; prepare a matching fresh profile");
   M(typeof(SaveManager),"Save",3,1,false);File.Copy(Path.Combine(SkinPresetPlugin.Root,"working-profile","SaveData","1.sd"),Path.Combine(SkinPresetPlugin.Root,"baseline.sd"),false);
   prepared=true;Log("prepared",new{authority="controlled-native-skin-preset",natural_only=false,master=Ptr(master),patterns=Ptr(patterns),expected=ExpectedInfo(),disturbedRgb,original=originalSnapshot,detached=Snapshot(),scope="Only free=false indices 0 and 1; independent original master color expectations; no repeated Initialize"});return;
  }
  if(action.StartsWith("case ")){
   Check(prepared&&phase=="idle","Prepared idle runner required");current=action.Substring(5);Check(current=="preset-0"||current=="preset-1","Unknown preset case");selected=current=="preset-0"?0:1;LoadBaseline();Configure(false);Begin("reference");Dispatch();Log("reference_immediate",new{name=current,snapshot=Snapshot()});began=Time.frameCount;phase="reference";return;
  }
  if(action=="cleanup"){
   Check(roots!=null&&(phase=="idle"||phase=="failed"),"No captured roots or pending case");current="cleanup";RestoreRoots();
   if(!backupComplete){RestoreStop();Log("cleanup_without_material_backup",new{broadcast=false,reason="Prepare failed before any fixture Load/Save/field mutation; no material broadcast is safe without a complete backup",rootsRestored=GlobalNames.Select((n,i)=>Same(G(typeof(GameState),n),roots[i])).All(x=>x),stop=G(Temp,"IsStopGameStateApplier")});phase="done";return;}
   Begin("restore");Dispatch();began=Time.frameCount;phase="cleanup";return;
  }
  throw new Exception("Unknown command");
 }
 public void LateUpdate(){
  if(!(phase=="reference"||phase=="disturb"||phase=="restore"||phase=="cleanup")||Time.frameCount-began<10)return;
  try{
   if(phase=="reference"){
    AssertPreset();Log("reference_result",new{name=current,expected=ExpectedInfo(),snapshot=Snapshot()});SaveCapture();Log("saved",new{name=current,fields=FieldValues()});End();Configure(true);Begin("disturb");Dispatch();Log("disturbed_immediate",new{name=current,snapshot=Snapshot()});began=Time.frameCount;phase="disturb";return;
   }
   if(phase=="disturb"){
    disturbedColors=ReadColors();var freeColor=new Color(disturbedRgb[0]/255f,disturbedRgb[1]/255f,disturbedRgb[2]/255f,1);Check(Near(disturbedColors[0],freeColor)&&Near(disturbedColors[2],freeColor),"Free-color perturbation was not applied to actual body/face");Check(!Near(freeColor,expected[selected][0]),"Preset did not differ from perturbation");Log("disturbed_result",new{name=current,snapshot=Snapshot()});End();Begin("restore");M(typeof(SaveManager),"Load",3,1);Log("loaded_without_application",new{name=current,snapshot=Snapshot()});AssertSavedFields();Check(ColorsNear(ReadColors(),disturbedColors),"Load applied material colors before explicit original broadcast");Dispatch();Log("restore_immediate",new{name=current,snapshot=Snapshot()});began=Time.frameCount;phase="restore";return;
   }
   if(phase=="restore"){AssertPreset();Log("result",new{name=current,expected=ExpectedInfo(),snapshot=Snapshot()});End();phase="idle";return;}
   RestoreMaterials();RestoreStop();var rootsRestored=GlobalNames.Select((n,i)=>Same(G(typeof(GameState),n),roots[i])).All(x=>x);var scalarRestored=ScalarSignature(Custom)==originalScalar;var refsRestored=RefsRestored();var colorsRestored=PropertiesRestored();var masterUnchanged=MasterUnchanged();var slotRestored=Same(G(typeof(SaveManager),"CurrentSaveSlot"),oldSlot);var stopRestored=(bool)G(Temp,"IsStopGameStateApplier")==oldStop;
   Log("cleanup",new{rootsRestored,scalarRestored,slotRestored,refsRestored,colorsRestored,masterUnchanged,stopRestored,stop=G(Temp,"IsStopGameStateApplier"),original=originalSnapshot,restored=Snapshot()});Check(rootsRestored&&scalarRestored&&slotRestored&&refsRestored&&colorsRestored&&masterUnchanged&&stopRestored,"Cleanup verification failed");End();phase="done";
  }catch(Exception e){Fail("LateUpdate",e);}
 }
}
}
