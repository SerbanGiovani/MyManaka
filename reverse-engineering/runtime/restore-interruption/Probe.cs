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
namespace REATitleInterruption {
[BepInPlugin("rea.restore.interruption","REA Original Manager Title Interruption","1.2.0")]
[BepInDependency("rea.natural.observer")]
public class TitleInterruptPlugin:BasePlugin {
 public static string Root;
 public override void Load(){Root=Path.Combine(Paths.GameRootPath,"RestoreInterruption","20261030-3");var observer=AppDomain.CurrentDomain.GetAssemblies().Select(a=>a.GetType("Plugin")).First(t=>t?.GetField("SaveRoot")!=null);observer.GetField("SaveRoot").SetValue(null,Path.Combine(Root,"working-profile"));((StreamWriter)observer.GetField("Output").GetValue(null)).Flush();observer.GetField("Output").SetValue(null,new StreamWriter(Path.Combine(Root,"paths.jsonl"),true));Application.SetStackTraceLogType(LogType.Error,StackTraceLogType.Full);Application.SetStackTraceLogType(LogType.Exception,StackTraceLogType.Full);ClassInjector.RegisterTypeInIl2Cpp<Runner>();AddComponent<Runner>();}
}
public class Runner:MonoBehaviour {
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
 static void Log(string kind,object data=null){File.AppendAllText(Path.Combine(TitleInterruptPlugin.Root,"title-managed.jsonl"),JsonSerializer.Serialize(new{kind,frame=Time.frameCount,real=Time.realtimeSinceStartup,data})+"\n");}
 static object State=>G(typeof(GameState),"GameStateData");
 static object NM=>G(G(G(typeof(InGameManager),"Instance"),"InGameReferencer"),"NpcManager");
 static object DM=>G(G(typeof(InGameManager),"Instance"),"DroppedItemManager");
 static object Temp=>G(G(typeof(InGameManager),"Instance"),"TempInGameState");
 static object Summary()=>new{state=Ptr(State),stage=G(State,"CurrentStageType").ToString(),npcs=Count(G(State,"NpcSaveDataList")),reserve=Count(G(State,"ReserveDropList")),live=Count(G(NM,"ExistNpcList")),loaded=G(NM,"isLoadedData")};

 string phase="idle";float next,deadline;int stopFrame;object owner,owned,root,oldSaved,oldTemp,oldLoaded;Behaviour scheduler;bool oldEnabled,oldStop;
 static object[] Items(object l)=>Enumerable.Range(0,Count(l)).Select(i=>At(l,i)).ToArray();
 object Queue=>G(scheduler,"timeModelList");bool Pending()=>(bool)M(Queue,"Contains",owned);
 object Inspect(){var gm=G(typeof(InGameManager),"Instance") as UnityEngine.Object;var own=owner as UnityEngine.Object;return new{trial="original-manager-title",phase,scene=SceneManager.GetActiveScene().name,manager=Ptr(owner),managerAlive=(bool)own,managerInitialized=G(owner,"initialized"),gameManager=Ptr(gm),gameManagerAlive=(bool)gm,model=Ptr(owned),pending=Pending(),remaining=G(owned,"remainTime"),scheduler=Ptr(scheduler),schedulerEnabled=scheduler.enabled};}
 public void Update(){
  try{if(Time.realtimeSinceStartup>=next){next=Time.realtimeSinceStartup+0.05f;var path=Path.Combine(TitleInterruptPlugin.Root,"command");if(File.Exists(path)){var a=File.ReadAllText(path).Trim();File.Move(path,path+"-"+Time.frameCount);Handle(a);}}
   if(phase=="hold-title"&&SceneManager.GetActiveScene().name=="Title"){Log("after_interruption",Inspect());scheduler.enabled=true;phase="title-running";stopFrame=Time.frameCount+4;Log("scheduler_resumed",Inspect());}
   if(phase=="hold-title"&&Time.realtimeSinceStartup>=deadline)throw new Exception("original fade did not reach Title");
  }catch(Exception e){Log("runner_error",new{phase,error=e.ToString()});try{Cleanup();}catch(Exception ex){Log("cleanup_error",ex.ToString());}phase="failed";}
 }
 public void LateUpdate(){if(phase!="title-running"||Time.frameCount<stopFrame)return;try{scheduler.enabled=false;Log("result",Inspect());Cleanup();phase="done";Log("complete");}catch(Exception e){Log("runner_error",new{phase,error=e.ToString()});phase="failed";}}
 void Handle(string a){Log("command",new{action=a,phase,scene=SceneManager.GetActiveScene().name});if(a=="boot"){M(Find(T("TitleSceneView")),"OnClickContinue");return;}if(a=="continue"){M(typeof(SaveManager),"Load",3,1);S(typeof(SaveManager),"CurrentSaveSlot",1);M(Find(T("SaveDataSelectPanelView")),"TransScene");return;}if(a=="residence"){SceneManager.LoadScene("Night_Demo 1");return;}if(a=="title")Begin();}
 void Begin(){
  owner=NM;if(!(bool)G(owner,"initialized"))throw new Exception("need initialized original manager");var live=G(owner,"ExistNpcList");if(Count(live)==0)throw new Exception("need original NPC");var tr=(Transform)G(At(live,0),"Transform");root=State;oldSaved=G(root,"NpcSaveDataList");oldTemp=Temp;oldStop=(bool)G(oldTemp,"IsStopGameStateApplier");oldLoaded=G(owner,"isLoadedData");S(oldTemp,"IsStopGameStateApplier",true);scheduler=G(T("Scheduler"),"Instance") as Behaviour;oldEnabled=scheduler.enabled;scheduler.enabled=false;
  var records=Empty(oldSaved);var record=Activator.CreateInstance(T("NpcSaveData"));S(record,"Position",tr.position);S(record,"Rotation",tr.rotation);S(record,"IsExist",true);M(records,"Add",record);S(root,"NpcSaveDataList",records);var before=Items(Queue).Select(Ptr).ToArray();Log("trial_begin",new{trial="original-manager-title",scene=SceneManager.GetActiveScene().name,originalManager=Ptr(owner),record=Ptr(record),initialized=G(owner,"initialized"),live=Count(live)});M(owner,"OnLoadData");owned=Items(Queue).Single(o=>!before.Contains(Ptr(o)));Log("queued",Inspect());
  // Original confirmation callback broadcasts ExitInGame and opens the original fade.
  // Its own completion callback loads Title; no direct duplicate LoadScene call.
  var method=Game.GetTypes().Where(t=>t.FullName.Contains("SystemMenu")).SelectMany(t=>t.GetMethods(Flags)).Single(m=>m.Name.Contains("OnClickSaveAndGoToTitle")&&m.Name.Contains("18_1"));
  Log("exit_callback",new{type=method.DeclaringType.FullName,method=method.Name});method.Invoke(method.IsStatic?null:Activator.CreateInstance(method.DeclaringType),Array.Empty<object>());phase="hold-title";deadline=Time.realtimeSinceStartup+5;
 }
 void Cleanup(){if(scheduler){scheduler.enabled=false;if(owned!=null)foreach(var name in new[]{"timeModelList","timeModelListClone","timeRemoveList"})M(G(scheduler,name),"Remove",owned);}if(root!=null)S(root,"NpcSaveDataList",oldSaved);if(oldTemp!=null)S(oldTemp,"IsStopGameStateApplier",oldStop);if(owner!=null&&oldLoaded!=null)S(owner,"isLoadedData",oldLoaded);bool pending=scheduler&&owned!=null&&Pending();if(scheduler)scheduler.enabled=oldEnabled;Log("cleanup",new{ownedModelRemoved=!pending,schedulerRestored=scheduler&&scheduler.enabled==oldEnabled,scope="explicit fixture cleanup after original Title lifecycle; does not count as native cancellation"});owned=null;root=null;}
}
}
