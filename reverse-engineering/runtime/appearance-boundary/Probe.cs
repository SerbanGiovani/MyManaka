// Controlled persistent-body-paint fixture. Every game call executes on Unity's thread.
// Build with -EmitOnly while another test process is running; installation is separate.
using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text.Json;
using BepInEx;
using BepInEx.Unity.IL2CPP;
using Il2CppInterop.Runtime.Injection;
using Il2CppInterop.Runtime.InteropTypes;
using Il2CppInterop.Runtime.InteropTypes.Arrays;
using UnityEngine;
using UnityEngine.SceneManagement;
using ExposureUnnoticed2.Scripts.InGame;

namespace REAAppearanceBoundary {
[BepInPlugin("rea.appearance.boundary", "REA Appearance Boundary", "1.0.0")]
[BepInDependency("rea.natural.observer")]
public class AppearanceBoundaryPlugin : BasePlugin {
 public static string Root;
 public override void Load() {
  var tag=Environment.GetEnvironmentVariable("REA_APPEARANCE_BOUNDARY_RUN")??"20261030-1";
  if(!System.Text.RegularExpressions.Regex.IsMatch(tag,"^[A-Za-z0-9][A-Za-z0-9._-]*$")||tag=="."||tag=="..")throw new Exception("Invalid run tag");
  Root=Path.Combine(Paths.GameRootPath,"AppearanceBoundary",tag);
  if(!File.Exists(Path.Combine(Root,"working-profile","SaveData","1.sd")))throw new Exception("Prepare a disposable profile with manual slot1 before installing the probe");
  if(File.Exists(Path.Combine(Root,"managed.jsonl")))throw new Exception("A fresh run directory is required; existing logs are never replaced");
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

public class Runner : MonoBehaviour {
 [DllImport("kernel32.dll",CharSet=CharSet.Unicode)] static extern void OutputDebugStringW(string text);
 public Runner(IntPtr pointer):base(pointer){}
 static readonly BindingFlags Flags=BindingFlags.Public|BindingFlags.NonPublic|BindingFlags.Static|BindingFlags.Instance;
 static readonly Assembly Game=typeof(SaveManager).Assembly;
 static readonly string[] GlobalNames={"AutoSaveTime","ManualSaveTime","InterruptSaveTime","HomeSaveTime","DifficultData","RankData","TotalPlayTimeData","OptionData","TutorialData","GameStateData","SaveDataSlotIndex","IsTrial","OptionFaceRankBias","OptionFaceRange","PlayerCustomData"};
 static readonly string[] PaintControllerFields={"alpha","pca","currentState"};
 static readonly string[] SmoothFields={"Current","Target","maxDelta","downMaxDelta","isLerp","baseValue","second","downSecond","isUnscaled"};
 static Type T(string name)=>Game.GetTypes().Single(t=>t.Name==name);
 static Type K(object o)=>o as Type??o.GetType();
 static object O(object o)=>o is Type?null:o;
 public static object G(object o,string name){var p=K(o).GetProperty(name,Flags);if(p!=null)return p.GetValue(O(o));var f=K(o).GetField(name,Flags);if(f!=null)return f.GetValue(O(o));throw new MissingMemberException(K(o).FullName,name);}
 static object ConvertArg(object v,Type t)=>v==null?v:t.IsEnum&&!t.IsInstanceOfType(v)?Enum.ToObject(t,v):v;
 public static void S(object o,string name,object v){var p=K(o).GetProperty(name,Flags);if(p!=null){p.SetValue(O(o),ConvertArg(v,p.PropertyType));return;}var f=K(o).GetField(name,Flags);if(f==null)throw new MissingMemberException(K(o).FullName,name);f.SetValue(O(o),ConvertArg(v,f.FieldType));}
 public static object M(object o,string name,params object[] args){var all=K(o).GetMethods(Flags).Where(m=>m.Name==name&&m.GetParameters().Length==args.Length).ToArray();var m=all.FirstOrDefault(m=>m.GetParameters().Select((p,i)=>args[i]==null||p.ParameterType.IsEnum||p.ParameterType.IsInstanceOfType(args[i])).All(x=>x))??all.Single();return m.Invoke(O(o),m.GetParameters().Select((p,i)=>ConvertArg(args[i],p.ParameterType)).ToArray());}
 static object Find(Type type)=>typeof(UnityEngine.Object).GetMethods().Single(m=>m.Name=="FindObjectOfType"&&m.IsGenericMethodDefinition&&m.GetParameters().Length==0).MakeGenericMethod(type).Invoke(null,null);
 static string Ptr(object o)=>o is Il2CppObjectBase b?b.Pointer.ToString():null;
 static bool Same(object a,object b)=>a is Il2CppObjectBase||b is Il2CppObjectBase?Ptr(a)==Ptr(b):Equals(a,b);
 static object State=>G(typeof(GameState),"GameStateData");
 static object Custom=>G(typeof(GameState),"PlayerCustomData");
 static object Temp=>G(G(typeof(InGameManager),"Instance"),"TempInGameState");
 static object Player=>G(G(G(typeof(InGameManager),"Instance"),"InGameReferencer"),"Player");
 static object Pca=>G(Player,"Pca");
 static object Avatar=>G(Pca,"PlayerAvatarObjectReferencer");
 static object Materials=>G(Pca,"PlayerBodyMaterialController");
 static object Paint=>G(Pca,"BodyPaintController");
 static Renderer BodyRenderer=>(Renderer)G(Avatar,"bodyMeshRenderer");
 static object Dict=>G(Custom,"BodyPaintTypeDict");
 static int ShaderId(string name)=>(int)G(T("PlayerBodyMaterialController"),name);
 static float[] C(Color c)=>new[]{c.r,c.g,c.b,c.a};
 static void Log(string kind,object data=null)=>File.AppendAllText(Path.Combine(AppearanceBoundaryPlugin.Root,"managed.jsonl"),JsonSerializer.Serialize(new{kind,frame=Time.frameCount,real=Time.realtimeSinceStartup,data})+"\n");

 object[] roots,oldPaint,oldSmooth,oldMaterialRefs;object oldSlot,oldSmoothObject;bool oldStop,ready,markerOpen;
 Il2CppReferenceArray<Material> oldShared;
 MaterialRecord[] originalProperties;
 string current="idle",phase="idle";int began;float next;
 object initialSnapshot;
 class MaterialRecord {
  public Material Material;public int[] ColorIds;public Color[] Colors;public bool HasTexture,HasTweak;public Texture Texture;public float Tweak;
 }
 object PaintMap()=>Enumerable.Range(0,10).Select(id=>{bool present=(bool)M(Dict,"ContainsKey",id);return new{id,present,value=present?(bool?)M(Dict,"get_Item",id):null};}).ToArray();
 object MaterialInfo(Material m,int slot){
  if(!m)return new{slot,valid=false,pointer=Ptr(m)};
  int main=ShaderId("MainTex"),cap=ShaderId("MatCapColor"),baseId=ShaderId("BaseColor"),shade=ShaderId("FirstShadeColor"),tweak=ShaderId("TweakTransparency");
  return new{slot,valid=true,pointer=Ptr(m),name=m.name,shader=Ptr(m.shader),shaderName=m.shader?m.shader.name:null,hasMain=m.HasProperty(main),texture=m.HasProperty(main)?Ptr(m.GetTexture(main)):null,textureName=m.HasProperty(main)&&m.GetTexture(main)?m.GetTexture(main).name:null,hasMatCap=m.HasProperty(cap),matCap=m.HasProperty(cap)?C(m.GetColor(cap)):null,baseColor=m.HasProperty(baseId)?C(m.GetColor(baseId)):null,shadeColor=m.HasProperty(shade)?C(m.GetColor(shade)):null,tweak=m.HasProperty(tweak)?(float?)m.GetFloat(tweak):null};
 }
 object Snapshot(){var ms=BodyRenderer.sharedMaterials;return new{state=Ptr(State),custom=Ptr(Custom),map=PaintMap(),remaining=G(State,"PlayerRemainBodyPaintTime"),reusable=G(State,"IsActiveBodyPaintReusable"),paintState=G(Paint,"currentState"),alpha=G(G(Paint,"alpha"),"Current"),renderer=Ptr(BodyRenderer),materialController=Ptr(Materials),sweat=Ptr(G(Materials,"SweatBodyMaterial")),clothes=Ptr(G(Materials,"ClothesPaintMaterial")),rubber=Ptr(G(Materials,"RubberSuitMaterial")),rubberDummy=((GameObject)G(Avatar,"RubberSuitDummy")).activeInHierarchy,materials=Enumerable.Range(0,ms.Length).Select(i=>MaterialInfo(ms[i],i)).ToArray()};}
 string ScalarCustomSignature()=>JsonSerializer.Serialize(Custom.GetType().GetProperties(Flags).Where(p=>p.DeclaringType==Custom.GetType()&&p.GetMethod!=null&&!p.GetMethod.IsStatic&&p.GetIndexParameters().Length==0&&p.PropertyType.IsPrimitive).OrderBy(p=>p.Name).ToDictionary(p=>p.Name,p=>p.GetValue(Custom)));
 void Begin(string stage){if(markerOpen)throw new Exception("Nested fixture marker");OutputDebugStringW("REA_APPEARANCE_BOUNDARY_BEGIN:"+current+"/"+stage);markerOpen=true;}
 void End(){if(!markerOpen)return;OutputDebugStringW("REA_APPEARANCE_BOUNDARY_END:");markerOpen=false;}
 void Dispatch(){var m=Player.GetType().GetMethods(Flags).Single(x=>x.Name.Contains("Initialize")&&x.Name.Contains("30_0"));m.Invoke(Player,Array.Empty<object>());}
 void LoadBaseline(){File.Copy(Path.Combine(AppearanceBoundaryPlugin.Root,"baseline.sd"),Path.Combine(AppearanceBoundaryPlugin.Root,"working-profile","SaveData","1.sd"),true);M(typeof(SaveManager),"Load",3,1);}
 void Configure(bool disturbed){
  if((float)G(State,"PlayerRemainBodyPaintTime")!=0||(bool)G(State,"IsActiveBodyPaintReusable"))throw new Exception("Timed-paint fields must remain zero/false");
  bool tattoo=current=="tattoo"||current=="combined",oil=current=="oil"||current=="combined";
  if(disturbed){tattoo=!tattoo;oil=!oil;}
  for(int i=0;i<10;i++)M(T("GameStateFacade"),"SetActiveBodyPaint",i,i==2?tattoo:i==8&&oil);
 }
 void SaveCapture(){M(typeof(SaveManager),"Save",3,1,false);File.Copy(Path.Combine(AppearanceBoundaryPlugin.Root,"working-profile","SaveData","1.sd"),Path.Combine(AppearanceBoundaryPlugin.Root,"captures",current+".sd"),false);}
 void CaptureOriginal(){
  oldShared=BodyRenderer.sharedMaterials;
  int[] ids={ShaderId("MatCapColor"),ShaderId("BaseColor"),ShaderId("FirstShadeColor")};int main=ShaderId("MainTex"),tweak=ShaderId("TweakTransparency");
  originalProperties=Enumerable.Range(0,oldShared.Length).Select(i=>oldShared[i]).Where(m=>m).Distinct().Select(m=>{var has=ids.Where(m.HasProperty).ToArray();return new MaterialRecord{Material=m,ColorIds=has,Colors=has.Select(m.GetColor).ToArray(),HasTexture=m.HasProperty(main),Texture=m.HasProperty(main)?m.GetTexture(main):null,HasTweak=m.HasProperty(tweak),Tweak=m.HasProperty(tweak)?m.GetFloat(tweak):0};}).ToArray();
  oldMaterialRefs=new[]{G(Materials,"SweatBodyMaterial"),G(Materials,"ClothesPaintMaterial"),G(Materials,"RubberSuitMaterial")};
  oldPaint=PaintControllerFields.Select(f=>G(Paint,f)).ToArray();oldSmoothObject=G(Paint,"alpha");oldSmooth=SmoothFields.Select(f=>G(oldSmoothObject,f)).ToArray();
 }
 void RestoreRoots(){if(roots==null)return;for(int i=0;i<GlobalNames.Length;i++)S(typeof(GameState),GlobalNames[i],roots[i]);S(typeof(SaveManager),"CurrentSaveSlot",oldSlot);}
 void RestoreObjects(){
  if(oldShared==null)return;
  BodyRenderer.sharedMaterials=oldShared;
  foreach(var record in originalProperties){if(!record.Material)continue;for(int i=0;i<record.ColorIds.Length;i++)record.Material.SetColor(record.ColorIds[i],record.Colors[i]);if(record.HasTexture)record.Material.SetTexture(ShaderId("MainTex"),record.Texture);if(record.HasTweak)record.Material.SetFloat(ShaderId("TweakTransparency"),record.Tweak);}
  for(int i=0;i<3;i++)S(Materials,new[]{"SweatBodyMaterial","ClothesPaintMaterial","RubberSuitMaterial"}[i],oldMaterialRefs[i]);
  for(int i=0;i<PaintControllerFields.Length;i++)S(Paint,PaintControllerFields[i],oldPaint[i]);
  for(int i=0;i<SmoothFields.Length;i++)S(oldSmoothObject,SmoothFields[i],oldSmooth[i]);
 }
 void Fail(string action,Exception error){Log("runner_error",new{action,phase,current,error=error.ToString()});End();try{RestoreRoots();RestoreObjects();if(roots!=null)S(Temp,"IsStopGameStateApplier",oldStop);}catch(Exception second){Log("cleanup_error",new{error=second.ToString()});}phase="failed";}
 public void Update(){
  if(Time.realtimeSinceStartup<next)return;next=Time.realtimeSinceStartup+.05f;
  var path=Path.Combine(AppearanceBoundaryPlugin.Root,"command");if(!File.Exists(path))return;var action=File.ReadAllText(path).Trim();File.Move(path,path+"-"+Time.frameCount);
  try{Handle(action);}catch(Exception e){Fail(action,e);}
 }
 void Handle(string action){
  Log("command",new{action,phase,current,scene=SceneManager.GetActiveScene().name});
  if(action=="ready"){var assets=G(T("AssetReferencer"),"Instance");var hair=assets==null?null:G(assets,"MHair");Log("readiness",new{ready=assets!=null&&hair!=null,assets=Ptr(assets),hair=Ptr(hair),scene=SceneManager.GetActiveScene().name});return;}
  if(action=="boot"){M(Find(T("TitleSceneView")),"OnClickContinue");return;}
  if(action=="continue"){M(typeof(SaveManager),"Load",3,1);S(typeof(SaveManager),"CurrentSaveSlot",1);M(Find(T("SaveDataSelectPanelView")),"TransScene");return;}
  if(action=="prepare"){
   if(roots!=null||SceneManager.GetActiveScene().name!="Apartment")throw new Exception("Fresh Apartment required");
   if(BodyRenderer.sharedMaterials.Length<2)throw new Exception("At least two original base materials required");
   if(((GameObject)G(Avatar,"RubberSuitDummy")).activeInHierarchy)throw new Exception("RubberSuitDummy must be inactive for this selected scope");
   if((float)G(State,"PlayerRemainBodyPaintTime")!=0||(bool)G(State,"IsActiveBodyPaintReusable")||(int)G(Paint,"currentState")!=0)throw new Exception("Fresh unpainted state required; timed-paint consumers are outside this batch");
   var scalarBefore=ScalarCustomSignature();
   roots=GlobalNames.Select(n=>G(typeof(GameState),n)).ToArray();oldSlot=G(typeof(SaveManager),"CurrentSaveSlot");oldStop=(bool)G(Temp,"IsStopGameStateApplier");CaptureOriginal();initialSnapshot=Snapshot();S(Temp,"IsStopGameStateApplier",true);
   // Detach the stored roots before any fixture dictionary writes or baseline Save.
   M(typeof(SaveManager),"Load",3,1);S(typeof(SaveManager),"CurrentSaveSlot",1);
   if(Same(Custom,roots[14])||Same(State,roots[9]))throw new Exception("Native Load did not detach original data roots");
   if(ScalarCustomSignature()!=scalarBefore)throw new Exception("The disposable slot must match the fresh player's scalar appearance before this body-paint-only batch");
   if((float)G(State,"PlayerRemainBodyPaintTime")!=0||(bool)G(State,"IsActiveBodyPaintReusable"))throw new Exception("Disposable slot contains timed paint");
   M(typeof(SaveManager),"Save",3,1,false);File.Copy(Path.Combine(AppearanceBoundaryPlugin.Root,"working-profile","SaveData","1.sd"),Path.Combine(AppearanceBoundaryPlugin.Root,"baseline.sd"),false);
   ready=true;Log("prepared",new{authority="controlled-native-persistent-body-paint",natural_only=false,original=initialSnapshot,detached=Snapshot(),scope="TattooDark2/BodyOil8; timed fields zero; original callback applies, material instance identity is not source-asset identity"});return;
  }
  if(action.StartsWith("case ")){
   if(!ready||phase!="idle")throw new Exception("Prepared idle fixture required");current=action.Substring(5);if(!new[]{"tattoo","oil","combined"}.Contains(current))throw new Exception("Unknown case");
   LoadBaseline();Configure(false);Begin("reference");Dispatch();Log("reference_immediate",new{name=current,snapshot=Snapshot()});began=Time.frameCount;phase="reference";return;
  }
  if(action=="cleanup"){
   if(roots==null||!new[]{"idle","failed"}.Contains(phase))throw new Exception("No roots or case still pending");current="cleanup";RestoreRoots();Begin("restore");Dispatch();began=Time.frameCount;phase="cleanup";return;
  }
  throw new Exception("Unknown command");
 }
 public void LateUpdate(){
  if(!new[]{"reference","disturb","restore","cleanup"}.Contains(phase)||Time.frameCount-began<10)return;
  try{
   if(phase=="reference"){
    Log("reference_result",new{name=current,snapshot=Snapshot()});SaveCapture();Log("saved",new{name=current});End();Configure(true);Begin("disturb");Dispatch();Log("disturbed_immediate",new{name=current,snapshot=Snapshot()});began=Time.frameCount;phase="disturb";return;
   }
   if(phase=="disturb"){
    Log("disturbed_result",new{name=current,snapshot=Snapshot()});End();Begin("restore");M(typeof(SaveManager),"Load",3,1);Log("loaded_without_application",new{name=current,snapshot=Snapshot()});Dispatch();Log("restore_immediate",new{name=current,snapshot=Snapshot()});began=Time.frameCount;phase="restore";return;
   }
   if(phase=="restore"){Log("result",new{name=current,snapshot=Snapshot()});End();phase="idle";return;}
   RestoreObjects();S(Temp,"IsStopGameStateApplier",oldStop);var now=BodyRenderer.sharedMaterials;
   Log("cleanup",new{rootsRestored=GlobalNames.Select((n,i)=>Same(G(typeof(GameState),n),roots[i])).All(x=>x),slotRestored=Same(G(typeof(SaveManager),"CurrentSaveSlot"),oldSlot),stop=G(Temp,"IsStopGameStateApplier"),sharedMaterialPointersRestored=now.Length==oldShared.Length&&Enumerable.Range(0,now.Length).All(i=>Same(now[i],oldShared[i])),original=initialSnapshot,restored=Snapshot()});End();phase="done";
  }catch(Exception e){Fail("LateUpdate",e);}
 }
}
}
