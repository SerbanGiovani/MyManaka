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
namespace REARestoreInterruption {
[BepInPlugin("rea.restore.interruption","REA Controlled Restore Interruption","1.0.0")]
[BepInDependency("rea.natural.observer")]
public class InterruptPlugin:BasePlugin {
 public static string Root;
 public override void Load(){
  Root=Path.Combine(Paths.GameRootPath,"RestoreInterruption","20261030-1");
  var observer=AppDomain.CurrentDomain.GetAssemblies().Select(a=>a.GetType("Plugin")).First(t=>t?.GetField("SaveRoot")!=null);
  observer.GetField("SaveRoot").SetValue(null,Path.Combine(Root,"working-profile"));((StreamWriter)observer.GetField("Output").GetValue(null)).Flush();observer.GetField("Output").SetValue(null,new StreamWriter(Path.Combine(Root,"paths.jsonl"),true));
  ClassInjector.RegisterTypeInIl2Cpp<Runner>();AddComponent<Runner>();
 }
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
 static void Log(string kind,object data=null){File.AppendAllText(Path.Combine(InterruptPlugin.Root,"interrupt-managed.jsonl"),JsonSerializer.Serialize(new{kind,frame=Time.frameCount,real=Time.realtimeSinceStartup,data})+"\n");}
 static object State=>G(typeof(GameState),"GameStateData");
 static object NM=>G(G(G(typeof(InGameManager),"Instance"),"InGameReferencer"),"NpcManager");
 static object DM=>G(G(typeof(InGameManager),"Instance"),"DroppedItemManager");
 static object Temp=>G(G(typeof(InGameManager),"Instance"),"TempInGameState");
 static object Summary()=>new{state=Ptr(State),stage=G(State,"CurrentStageType").ToString(),npcs=Count(G(State,"NpcSaveDataList")),reserve=Count(G(State,"ReserveDropList")),live=Count(G(NM,"ExistNpcList")),loaded=G(NM,"isLoadedData")};

 string phase="idle",trial;float next,deadline;int stopFrame=-1;object oldSaved,root,owned;Behaviour scheduler;bool oldEnabled,oldStop;object oldTemp;NpcManager clone;GameObject cloneObject;
 static object[] Items(object l)=>Enumerable.Range(0,Count(l)).Select(i=>At(l,i)).ToArray();
 object Queue=>G(scheduler,"timeModelList");
 bool Pending()=>owned!=null&&(bool)M(Queue,"Contains",owned);
 object Inspect()=>new{trial,phase,scene=SceneManager.GetActiveScene().name,manager=Ptr(clone),managerAlive=(bool)clone,managerNative=clone?clone.Pointer.ToString():null,queue=Ptr(Queue),model=Ptr(owned),pending=Pending(),remaining=owned==null?null:G(owned,"remainTime"),scheduler=Ptr(scheduler),schedulerEnabled=scheduler.enabled,live=clone==null?null:(object)Count(G(clone,"ExistNpcList"))};
 public void Update(){
  try{
   var command=Path.Combine(InterruptPlugin.Root,"command");
   if(Time.realtimeSinceStartup>=next){next=Time.realtimeSinceStartup+0.05f;if(File.Exists(command)){var action=File.ReadAllText(command).Trim();File.Move(command,command+"-"+Time.frameCount);Handle(action);}}
   if(phase=="hold"&&Time.realtimeSinceStartup>=deadline){Log("after_interruption",Inspect());scheduler.enabled=true;phase="running";deadline=Time.realtimeSinceStartup+2;Log("scheduler_resumed",Inspect());}
   if(phase=="running"&&(!Pending()||(float)G(owned,"remainTime")<=0||Time.realtimeSinceStartup>=deadline)&&stopFrame<0)stopFrame=Time.frameCount+1;
  }catch(Exception e){Log("runner_error",new{trial,phase,error=e.ToString()});try{Cleanup();}catch(Exception ex){Log("cleanup_error",ex.ToString());}phase="failed";}
 }
 public void LateUpdate(){
  if(phase!="running"||stopFrame<0||Time.frameCount<stopFrame)return;
  try{scheduler.enabled=false;Log("result",Inspect());Cleanup();phase="done";Log("complete",new{trial});}catch(Exception e){Log("runner_error",new{trial,phase,error=e.ToString()});phase="failed";}
 }
 void Handle(string action){
  Log("command",new{action,phase,scene=SceneManager.GetActiveScene().name});
  if(action=="boot"){M(Find(T("TitleSceneView")),"OnClickContinue");return;}
  if(action=="continue"){M(typeof(SaveManager),"Load",3,1);S(typeof(SaveManager),"CurrentSaveSlot",1);M(Find(T("SaveDataSelectPanelView")),"TransScene");return;}
  if(action=="residence"){SceneManager.LoadScene("Night_Demo 1");return;}
  if(action=="control"||action=="destroy"||action=="scene")Begin(action);
 }
 void Begin(string name){
  if(phase!="idle"&&phase!="done")throw new Exception("trial pending");trial=name;stopFrame=-1;
  var original=NM;var list=G(original,"ExistNpcList");if(Count(list)==0)throw new Exception("need a live original NPC pose");
  var tr=(Transform)G(At(list,0),"Transform");root=State;oldSaved=G(root,"NpcSaveDataList");oldTemp=Temp;oldStop=(bool)G(oldTemp,"IsStopGameStateApplier");S(oldTemp,"IsStopGameStateApplier",true);
  scheduler=G(T("Scheduler"),"Instance") as Behaviour;if(!scheduler)throw new Exception("scheduler missing");oldEnabled=scheduler.enabled;scheduler.enabled=false;
  var records=Empty(oldSaved);var record=Activator.CreateInstance(T("NpcSaveData"));S(record,"Position",tr.position);S(record,"Rotation",tr.rotation);S(record,"IsExist",true);M(records,"Add",record);S(root,"NpcSaveDataList",records);
  cloneObject=new GameObject("REA disposable queued NPC manager");clone=cloneObject.AddComponent<NpcManager>();S(clone,"npcPrefabs",G(original,"npcPrefabs"));S(clone,"player",G(original,"player"));S(clone,"rCurrentStage",G(original,"rCurrentStage"));
  // Do not Initialize/register this temporary manager as the global singleton.
  var before=Items(Queue).Select(Ptr).ToArray();Log("trial_begin",new{trial,scene=SceneManager.GetActiveScene().name,originalManager=Ptr(original),temporaryManager=Ptr(clone),globalManagerUnchanged=Ptr(NM)==Ptr(original),record=Ptr(record),position=V(tr.position),rotation=Q(tr.rotation),schedulerEnabledBefore=oldEnabled});
  M(clone,"OnLoadData");var added=Items(Queue).Where(o=>!before.Contains(Ptr(o))).ToArray();if(added.Length!=1)throw new Exception("expected one original time model");owned=added[0];Log("queued",Inspect());
  phase="hold";deadline=Time.realtimeSinceStartup+0.25f;
  if(trial=="destroy"){UnityEngine.Object.Destroy(cloneObject);Log("destroy_requested",Inspect());}
  if(trial=="scene"){Log("scene_unload_requested",Inspect());SceneManager.LoadScene("Mall");deadline=Time.realtimeSinceStartup+1;}
 }
 void Cleanup(){
  if(scheduler){scheduler.enabled=false;if(owned!=null)foreach(var name in new[]{"timeModelList","timeModelListClone","timeRemoveList"})M(G(scheduler,name),"Remove",owned);}
  if(clone){var live=G(clone,"ExistNpcList");foreach(var n in Items(live))M(n,"Destroy");}
  if(cloneObject)UnityEngine.Object.Destroy(cloneObject);
  bool stateRestored=root!=null&&Ptr(State)==Ptr(root);if(stateRestored)S(root,"NpcSaveDataList",oldSaved);
  if(oldTemp!=null)S(oldTemp,"IsStopGameStateApplier",oldStop);if(Temp!=null&&Ptr(Temp)!=Ptr(oldTemp))S(Temp,"IsStopGameStateApplier",false);
  bool stillPending=scheduler&&Pending();if(scheduler)scheduler.enabled=oldEnabled;
  Log("cleanup",new{trial,ownedModelRemoved=!stillPending,stateRestored,schedulerRestored=scheduler&&scheduler.enabled==oldEnabled,originalManager=Ptr(NM),temporaryManager=Ptr(clone),scope="explicit fixture cleanup; never counted as original scheduler cancellation"});owned=null;root=null;
 }
}
}
