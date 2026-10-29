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
namespace REAFullRecovery {
[BepInPlugin("rea.full.recovery","REA Save Recovery","1.0.0")]
[BepInDependency("rea.natural.observer")]
public class RecoveryPlugin:BasePlugin {
 public static string Root;
 public override void Load(){Root=Path.Combine(Paths.GameRootPath,"FullSaveRecovery","20261030-2");var observer=AppDomain.CurrentDomain.GetAssemblies().Select(a=>a.GetType("Plugin")).First(t=>t?.GetField("SaveRoot")!=null);observer.GetField("SaveRoot").SetValue(null,Path.Combine(Root,"working-profile"));((StreamWriter)observer.GetField("Output").GetValue(null)).Flush();observer.GetField("Output").SetValue(null,new StreamWriter(Path.Combine(Root,"paths.jsonl"),true));Application.SetStackTraceLogType(LogType.Error,StackTraceLogType.Full);Application.SetStackTraceLogType(LogType.Exception,StackTraceLogType.Full);ClassInjector.RegisterTypeInIl2Cpp<Runner>();AddComponent<Runner>();}
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
 static void Log(string kind,object data=null){File.AppendAllText(Path.Combine(RecoveryPlugin.Root,"managed.jsonl"),JsonSerializer.Serialize(new{kind,frame=Time.frameCount,real=Time.realtimeSinceStartup,data})+"\n");}
 static object State=>G(typeof(GameState),"GameStateData");
 static object NM=>G(G(G(typeof(InGameManager),"Instance"),"InGameReferencer"),"NpcManager");
 static object DM=>G(G(typeof(InGameManager),"Instance"),"DroppedItemManager");
 static object Temp=>G(G(typeof(InGameManager),"Instance"),"TempInGameState");
 static object Summary()=>new{state=Ptr(State),stage=G(State,"CurrentStageType").ToString(),npcs=Count(G(State,"NpcSaveDataList")),reserve=Count(G(State,"ReserveDropList")),live=Count(G(NM,"ExistNpcList")),loaded=G(NM,"isLoadedData")};
 static string FilePath=>Path.Combine(RecoveryPlugin.Root,"working-profile","SaveData","1.sd");
 static string SystemPath=>Path.Combine(RecoveryPlugin.Root,"working-profile","SaveData","s.sd");
 static object Value(object v){if(v==null)return null;if(v is Vector3 v3)return V(v3);if(v is Quaternion q)return Q(q);if(v is Il2CppObjectBase)return new{pointer=Ptr(v),type=v.GetType().FullName};if(v is Il2CppSystem.DateTime)return v.ToString();return v.GetType().IsEnum?Convert.ToInt32(v):v;}
 static object Snapshot(){var state=State;return new{scene=SceneManager.GetActiveScene().name,slot=G(typeof(SaveManager),"CurrentSaveSlot"),roots=GlobalNames.Select(n=>new{name=n,value=Value(G(typeof(GameState),n))}).ToArray(),selected=new[]{"CurrentStageType","CurrentRp","PlayerLife","PlayerEcstasy","SkillLevel","PlayerPassiveSkillActiveDict","MissionAchieveCountDict","ItemDict","PlayerPosition","PlayerCurrentClothes"}.Select(n=>new{name=n,value=Value(G(state,n))}).ToArray()};}
 static void Copy(string src,string dst){Directory.CreateDirectory(Path.GetDirectoryName(dst));File.Copy(src,dst,true);}
 static void Capture(string name){Copy(FilePath,Path.Combine(RecoveryPlugin.Root,"captures",name+".sd"));Copy(SystemPath,Path.Combine(RecoveryPlugin.Root,"captures",name+"-system.sd"));}
 float next;bool prepared,oldStop;object[] globals;object oldSlot;
 public void Update(){if(Time.realtimeSinceStartup<next)return;next=Time.realtimeSinceStartup+0.1f;var path=Path.Combine(RecoveryPlugin.Root,"command");if(!File.Exists(path))return;var action=File.ReadAllText(path).Trim();File.Move(path,path+"-"+Time.frameCount);try{Handle(action);}catch(Exception e){Log("runner_error",new{action,error=e.ToString()});}}
 void Handle(string action){
  Log("command",new{action,scene=SceneManager.GetActiveScene().name});
  if(action=="boot"){M(Find(T("TitleSceneView")),"OnClickContinue");return;}
  if(action=="continue"){M(typeof(SaveManager),"Load",3,1);S(typeof(SaveManager),"CurrentSaveSlot",1);M(Find(T("SaveDataSelectPanelView")),"TransScene");return;}
  if(action=="prepare"){
   if(SceneManager.GetActiveScene().name!="Apartment"||prepared)throw new Exception("fresh Apartment required");oldStop=(bool)G(Temp,"IsStopGameStateApplier");S(Temp,"IsStopGameStateApplier",true);globals=GlobalNames.Select(n=>G(typeof(GameState),n)).ToArray();oldSlot=G(typeof(SaveManager),"CurrentSaveSlot");prepared=true;
   Log("prepare_before",Snapshot());M(typeof(SaveManager),"Save",3,1,false);Capture("baseline");Log("prepared",Snapshot());return;
  }
  if(action.StartsWith("case ")){if(!prepared)throw new Exception("prepare first");Run(action.Substring(5));return;}
  if(action=="cleanup"){Restore();S(Temp,"IsStopGameStateApplier",oldStop);prepared=false;Log("cleanup",new{globalsRestored=GlobalNames.Select((n,i)=>Ptr(G(typeof(GameState),n))==Ptr(globals[i])).All(v=>v),stop=G(Temp,"IsStopGameStateApplier")});}
 }
 void Restore(){if(globals!=null)for(int i=0;i<GlobalNames.Length;i++)S(typeof(GameState),GlobalNames[i],globals[i]);if(oldSlot!=null)S(typeof(SaveManager),"CurrentSaveSlot",oldSlot);}
 void Run(string name){
  if(name.IndexOfAny(new[]{'/', '\\', ':'})>=0)throw new Exception("invalid case");Restore();S(typeof(SaveManager),"CurrentSaveSlot",1);
  Copy(Path.Combine(RecoveryPlugin.Root,"captures","baseline-system.sd"),SystemPath);Copy(Path.Combine(RecoveryPlugin.Root,"captures","baseline.sd"),FilePath);
  if(name=="missing-game")File.Delete(FilePath);
  else if(name=="missing-system")File.Delete(SystemPath);
  else if(name.StartsWith("system-"))Copy(Path.Combine(RecoveryPlugin.Root,"variants",name+".sd"),SystemPath);
  else Copy(Path.Combine(RecoveryPlugin.Root,"variants",name+".sd"),FilePath);
  Copy(Path.Combine(RecoveryPlugin.Root,"captures","baseline.sd"),Path.Combine(RecoveryPlugin.Root,"working-profile","SaveDataBackup","1.sd"));
  OutputDebugStringW("REA_RECOVERY_BEGIN:"+name);Log("case_begin",new{name,snapshot=Snapshot(),backupExists=File.Exists(Path.Combine(RecoveryPlugin.Root,"working-profile","SaveDataBackup","1.sd"))});
  try{
   if(name=="backup-copy"){
    try{M(typeof(SaveManager),"Load",3,1);throw new Exception("corrupt main unexpectedly loaded");}catch(Exception e){Log("pre_recovery_exception",new{name,error=e.ToString()});}
    var backup=Path.Combine(RecoveryPlugin.Root,"working-profile","SaveDataBackup","1.sd");M(T("SaveRapper"),"Copy",backup,FilePath);Log("native_copy_return",new{name,source=backup,target=FilePath,bytes=File.ReadAllBytes(FilePath).Length});
   }
   M(typeof(SaveManager),"Load",3,1);Log("load_return",new{name,snapshot=Snapshot()});
   var facade=T("GameStateFacade");
   Log("consumers",new{name,skills=new[]{0,1,17,21,22,24}.Select(id=>new{id,level=M(facade,"GetSkillLevel",id),active=M(facade,"IsActivePassiveSkill",id)}).ToArray(),items=new[]{10001,10002,10003}.Select(id=>new{id,carried=M(facade,"IsBringItem",id)}).ToArray(),missions=new[]{0,1,2}.Select(id=>new{id,count=M(facade,"GetMissionAchieveCount",id)}).ToArray()});
   M(typeof(SaveManager),"Save",3,1,false);Capture(name+"-pass1");Log("save_return",new{name,pass=1,snapshot=Snapshot()});M(typeof(SaveManager),"Load",3,1);M(typeof(SaveManager),"Save",3,1,false);Capture(name+"-pass2");Log("save_return",new{name,pass=2,snapshot=Snapshot()});}
  catch(Exception e){Log("case_exception",new{name,error=e.ToString(),snapshot=Snapshot()});}
  finally{Restore();M(T("SaveRapper"),"AfterProcess");Log("case_end",new{name,snapshot=Snapshot()});OutputDebugStringW("REA_RECOVERY_END:"+name);}
 }
}
}

