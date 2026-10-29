// Controlled fixture runner. Native game methods execute from Unity Update.
// All files belong to a disposable profile, outside the clone's UserData.
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
using UnityEngine;
using UnityEngine.SceneManagement;
using ExposureUnnoticed2.Scripts.InGame;
using ExposureUnnoticed2.Object3D.NPC.Script;
namespace REAAppearanceDetail {
[BepInPlugin("rea.appearance.detail","REA Appearance Detail","1.0.0")]
[BepInDependency("rea.natural.observer")]
public class AppearancePlugin:BasePlugin {
 public static string Root;
 public override void Load(){Root=Path.Combine(Paths.GameRootPath,"AppearanceDetail","20261030-1");var observer=AppDomain.CurrentDomain.GetAssemblies().Select(a=>a.GetType("Plugin")).First(t=>t?.GetField("SaveRoot")!=null);observer.GetField("SaveRoot").SetValue(null,Path.Combine(Root,"working-profile"));((StreamWriter)observer.GetField("Output").GetValue(null)).Flush();observer.GetField("Output").SetValue(null,new StreamWriter(Path.Combine(Root,"paths.jsonl"),true));Application.SetStackTraceLogType(LogType.Error,StackTraceLogType.Full);Application.SetStackTraceLogType(LogType.Exception,StackTraceLogType.Full);ClassInjector.RegisterTypeInIl2Cpp<Runner>();AddComponent<Runner>();}
}
public class Runner:MonoBehaviour {
 [DllImport("kernel32.dll",CharSet=CharSet.Unicode)]static extern void OutputDebugStringW(string text);
 public Runner(IntPtr p):base(p){}
 static readonly BindingFlags Flags=BindingFlags.Public|BindingFlags.NonPublic|BindingFlags.Static|BindingFlags.Instance;
 static readonly Assembly Game=typeof(SaveManager).Assembly;
 static readonly string[] GlobalNames={"AutoSaveTime","ManualSaveTime","InterruptSaveTime","HomeSaveTime","DifficultData","RankData","TotalPlayTimeData","OptionData","TutorialData","GameStateData","SaveDataSlotIndex","IsTrial","OptionFaceRankBias","OptionFaceRange","PlayerCustomData"};
 static Type T(string name)=>Game.GetTypes().Single(t=>t.Name==name);
 static Type K(object o)=>o as Type??o.GetType();
 static object O(object o)=>o is Type?null:o;
 public static object G(object o,string name){var p=K(o).GetProperty(name,Flags);if(p!=null)return p.GetValue(O(o));var f=K(o).GetField(name,Flags);if(f!=null)return f.GetValue(O(o));throw new MissingMemberException(K(o).FullName,name);}
 static object ConvertArg(object v,Type t)=>v==null?v:t.IsEnum&&!t.IsInstanceOfType(v)?Enum.ToObject(t,v):v;
 public static void S(object o,string name,object v){var p=K(o).GetProperty(name,Flags);if(p!=null){p.SetValue(O(o),ConvertArg(v,p.PropertyType));return;}var f=K(o).GetField(name,Flags);if(f==null)throw new MissingMemberException(K(o).FullName,name);f.SetValue(O(o),ConvertArg(v,f.FieldType));}
 public static object M(object o,string name,params object[] args){var ms=K(o).GetMethods(Flags).Where(m=>m.Name==name&&m.GetParameters().Length==args.Length).ToArray();var m=ms.FirstOrDefault(m=>m.GetParameters().Select((p,i)=>args[i]==null||p.ParameterType.IsEnum||p.ParameterType.IsInstanceOfType(args[i])).All(x=>x))??ms.Single();return m.Invoke(O(o),m.GetParameters().Select((p,i)=>ConvertArg(args[i],p.ParameterType)).ToArray());}
 static object Find(Type t)=>typeof(UnityEngine.Object).GetMethods().Single(m=>m.Name=="FindObjectOfType"&&m.IsGenericMethodDefinition&&m.GetParameters().Length==0).MakeGenericMethod(t).Invoke(null,null);
 static int Count(object o)=>(int)G(o,"Count");
 static object At(object o,int i)=>M(o,"get_Item",i);
 static object Empty(object o)=>Activator.CreateInstance(o.GetType());
 static string Ptr(object o)=>o is Il2CppObjectBase b?b.Pointer.ToString():null;
 static float[] V(Vector3 p)=>new[]{p.x,p.y,p.z};
 static float[] Q(Quaternion p)=>new[]{p.x,p.y,p.z,p.w};
 static object Pose(object o)=>new{pointer=Ptr(o),position=V((Vector3)G(o,"Position")),rotation=Q((Quaternion)G(o,"Rotation"))};
 static void Log(string kind,object data=null){File.AppendAllText(Path.Combine(AppearancePlugin.Root,"managed.jsonl"),JsonSerializer.Serialize(new{kind,frame=Time.frameCount,real=Time.realtimeSinceStartup,data})+"\n");}
 static object State=>G(typeof(GameState),"GameStateData");
 static object NM=>G(G(G(typeof(InGameManager),"Instance"),"InGameReferencer"),"NpcManager");
 static object DM=>G(G(typeof(InGameManager),"Instance"),"DroppedItemManager");
 static object Temp=>G(G(typeof(InGameManager),"Instance"),"TempInGameState");
 static object Summary()=>new{state=Ptr(State),stage=G(State,"CurrentStageType").ToString(),npcs=Count(G(State,"NpcSaveDataList")),reserve=Count(G(State,"ReserveDropList")),live=Count(G(NM,"ExistNpcList")),loaded=G(NM,"isLoadedData")};
 static object Player=>G(G(G(typeof(InGameManager),"Instance"),"InGameReferencer"),"Player");
 static object Pca=>G(Player,"Pca");
 static object Custom=>G(typeof(GameState),"PlayerCustomData");
 static object Body=>G(Pca,"PlayerBodyCustomizeAdjuster");
 static float[] ColorValues(Color c)=>new[]{c.r,c.g,c.b,c.a};

 static readonly string[] Fields=new[]{"CustomIsSkinColorFree","CustomizeSkinColorR","CustomizeSkinColorG","CustomizeSkinColorB","CustomizeEyeBlowColorR","CustomizeEyeBlowColorG","CustomizeEyeBlowColorB","CustomizeEyeLashColorR","CustomizeEyeLashColorG","CustomizeEyeLashColorB","CustomizeEyeSize","CustomizeEyeDist","CustomizeCheekFat","CustomizeEarElf","CustomizeArm","CustomizeShoulder","CustomizeNeckThick"};
 static readonly int[] Shapes=new[]{401,400,379,380,55,64,375,376,373,374,147,148,149,150,145,146,158,159,160,161,162,163,164,165,166,167,168,169,170,414,363,364,365,393,392,394,395,388,312,313};
 object FieldValues()=>Fields.ToDictionary(n=>n,n=>G(Custom,n));
 ExposureUnnoticed2.Object3D.Player.Scripts.PlayerBoneScaleAdjuster[] Bones()=>UnityEngine.Object.FindObjectsOfType<ExposureUnnoticed2.Object3D.Player.Scripts.PlayerBoneScaleAdjuster>(true).Where(c=>c.transform.IsChildOf(((Component)Player).transform)).ToArray();
 object Snapshot(){var body=Body;int color=(int)G(body,"BaseColor"),shade=(int)G(body,"StShadeColor");
  var face=(SkinnedMeshRenderer)G(G(Pca,"PlayerAvatarObjectReferencer"),"FaceMesh");
  var mats=new[]{"bodyMaterial","faceMaterial","eyeBlowMaterial","eyeLashMaterial"};
  return new{custom=Ptr(Custom),fields=FieldValues(),materials=mats.Select(n=>{var mat=(Material)G(body,n);return new{name=n,pointer=Ptr(mat),color=ColorValues(mat.GetColor(color)),shade=ColorValues(mat.GetColor(shade))};}).ToArray(),face=Ptr(face),shapes=Shapes.Select(i=>new{index=i,value=face.GetBlendShapeWeight(i)}).ToArray(),bones=Bones().Select(c=>{var target=(Transform)G(c,"target");return new{pointer=Ptr(c),transform=Ptr(c.transform),scale=V(c.transform.localScale),target=Ptr(target),targetScale=V(target.localScale)};}).ToArray()};
 }
 float next;string phase="idle";new string name;int began;object[] globals,originalFields;object oldSlot;bool oldStop;
 System.Collections.Generic.Dictionary<Transform,Vector3> originalTargets;
 void Mark(string stage){OutputDebugStringW("REA_APPEARANCE_DETAIL_BEGIN:"+name+"/"+stage);}
 void End(){OutputDebugStringW("REA_APPEARANCE_DETAIL_END:");}
 void Dispatch(){var m=Player.GetType().GetMethods(Flags).Single(x=>x.Name.Contains("Initialize")&&x.Name.Contains("30_0"));m.Invoke(Player,Array.Empty<object>());}
 void RestoreData(){if(globals==null)return;for(int i=0;i<GlobalNames.Length;i++)S(typeof(GameState),GlobalNames[i],globals[i]);for(int i=0;i<Fields.Length;i++)S(Custom,Fields[i],originalFields[i]);S(typeof(SaveManager),"CurrentSaveSlot",oldSlot);}
 void Configure(bool disturbed){
  int[] a=name=="profile-b"?new[]{192,96,48,130,30,210,20,180,90,-35,30,-25,50,-15,25,-20}:new[]{88,142,196,20,80,140,160,40,120,35,-25,30,40,15,-10,20};
  S(Custom,Fields[0],true);for(int i=1;i<Fields.Length;i++)S(Custom,Fields[i],disturbed?(i<=9?50:0):a[i-1]);
 }
 void Targets(bool disturbed){if(name!="nonunit-bones")return;foreach(var t in originalTargets.Keys)t.localScale=disturbed?new Vector3(.9f,1.1f,1.2f):new Vector3(1.25f,.8f,1.5f);}
 public void Update(){if(Time.realtimeSinceStartup<next)return;next=Time.realtimeSinceStartup+.05f;var path=Path.Combine(AppearancePlugin.Root,"command");if(!File.Exists(path))return;var action=File.ReadAllText(path).Trim();File.Move(path,path+"-"+Time.frameCount);try{Handle(action);}catch(Exception e){Log("runner_error",new{action,phase,error=e.ToString()});RestoreData();End();phase="failed";}}
 void Handle(string action){Log("command",new{action,phase,scene=SceneManager.GetActiveScene().name});
  if(action=="boot"){M(Find(T("TitleSceneView")),"OnClickContinue");return;}
  if(action=="continue"){M(typeof(SaveManager),"Load",3,1);S(typeof(SaveManager),"CurrentSaveSlot",1);M(Find(T("SaveDataSelectPanelView")),"TransScene");return;}
  if(action=="prepare"){
   if(globals!=null||SceneManager.GetActiveScene().name!="Apartment")throw new Exception("fresh Apartment required");globals=GlobalNames.Select(n=>G(typeof(GameState),n)).ToArray();originalFields=Fields.Select(n=>G(Custom,n)).ToArray();oldSlot=G(typeof(SaveManager),"CurrentSaveSlot");oldStop=(bool)G(Temp,"IsStopGameStateApplier");S(Temp,"IsStopGameStateApplier",true);
   originalTargets=new System.Collections.Generic.Dictionary<Transform,Vector3>();foreach(var c in Bones()){var t=(Transform)G(c,"target");if(!originalTargets.ContainsKey(t))originalTargets.Add(t,t.localScale);}Log("prepared",Snapshot());return;
  }
  if(action.StartsWith("case ")){
   if(globals==null||phase!="idle")throw new Exception("prepare/idle required");RestoreData();name=action.Substring(5);if(!new[]{"profile-a","profile-b","nonunit-bones"}.Contains(name))throw new Exception("fixture name");Configure(false);Mark("reference");Log("case_begin",new{name,fields=FieldValues()});Dispatch();Targets(false);Log("reference_immediate",new{name,snapshot=Snapshot()});began=Time.frameCount;phase="reference";return;
  }
  if(action=="cleanup"){
   if(phase!="idle"&&phase!="failed")throw new Exception("pending case");name="cleanup";RestoreData();Mark("restore");Dispatch();foreach(var kv in originalTargets)kv.Key.localScale=kv.Value;began=Time.frameCount;phase="cleanup";
  }
 }
 public void LateUpdate(){if(!new[]{"reference","disturb","restore","cleanup"}.Contains(phase)||Time.frameCount-began<5)return;
  try{
   if(phase=="reference"){
    Log("reference_result",new{name,snapshot=Snapshot()});M(typeof(SaveManager),"Save",3,1,false);var directory=Path.Combine(AppearancePlugin.Root,"captures");Directory.CreateDirectory(directory);File.Copy(Path.Combine(AppearancePlugin.Root,"working-profile/SaveData/1.sd"),Path.Combine(directory,name+".sd"),false);Log("saved",new{name,fields=FieldValues()});End();
    Configure(true);Mark("disturb");Dispatch();Targets(true);Log("disturbed_immediate",new{name,snapshot=Snapshot()});began=Time.frameCount;phase="disturb";return;
   }
   if(phase=="disturb"){
    Log("disturbed_result",new{name,snapshot=Snapshot()});End();Mark("restore");M(typeof(SaveManager),"Load",3,1);Log("loaded",new{name,snapshot=Snapshot()});Dispatch();Targets(false);Log("restore_immediate",new{name,snapshot=Snapshot()});began=Time.frameCount;phase="restore";return;
   }
   if(phase=="restore"){Log("result",new{name,snapshot=Snapshot()});End();phase="idle";return;}
   S(Temp,"IsStopGameStateApplier",oldStop);Log("cleanup",new{rootsRestored=GlobalNames.Select((n,i)=>Ptr(G(typeof(GameState),n))==Ptr(globals[i])).All(x=>x),fieldsRestored=Fields.Select((n,i)=>Equals(G(Custom,n),originalFields[i])).All(x=>x),stop=G(Temp,"IsStopGameStateApplier"),snapshot=Snapshot()});End();phase="done";
  }catch(Exception e){Log("runner_error",new{phase,error=e.ToString()});RestoreData();End();phase="failed";}
 }
}
}
