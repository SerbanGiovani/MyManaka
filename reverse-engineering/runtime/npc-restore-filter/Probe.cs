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
namespace REANpcFilter {
[BepInPlugin("rea.npc.restore.filter","REA Controlled NPC Filter","1.0.0")]
[BepInDependency("rea.natural.observer")]
public class FilterPlugin:BasePlugin {
 public static string Root;
 public override void Load(){
  Root=Path.Combine(Paths.GameRootPath,"NpcRestoreFilter","20261030-1");
  var observer=AppDomain.CurrentDomain.GetAssemblies().Select(a=>a.GetType("Plugin")).First(t=>t?.GetField("SaveRoot")!=null);
  observer.GetField("SaveRoot").SetValue(null,Path.Combine(Root,"working-profile"));
  ((StreamWriter)observer.GetField("Output").GetValue(null)).Flush();
  observer.GetField("Output").SetValue(null,new StreamWriter(Path.Combine(Root,"paths.jsonl"),true));
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
 static void Log(string kind,object data=null){File.AppendAllText(Path.Combine(FilterPlugin.Root,"filter-managed.jsonl"),JsonSerializer.Serialize(new{kind,frame=Time.frameCount,real=Time.realtimeSinceStartup,data})+"\n");}
 static object State=>G(typeof(GameState),"GameStateData");
 static object NM=>G(G(G(typeof(InGameManager),"Instance"),"InGameReferencer"),"NpcManager");
 static object DM=>G(G(typeof(InGameManager),"Instance"),"DroppedItemManager");
 static object Temp=>G(G(typeof(InGameManager),"Instance"),"TempInGameState");
 static object Summary()=>new{state=Ptr(State),stage=G(State,"CurrentStageType").ToString(),npcs=Count(G(State,"NpcSaveDataList")),reserve=Count(G(State,"ReserveDropList")),live=Count(G(NM,"ExistNpcList")),loaded=G(NM,"isLoadedData")};

 float next,deadline;string phase="idle",trial;object nm,oldList,oldDict,oldRemove,oldSaved,oldLoaded,oldFixed;object[] globals;bool oldStop;int oldSpawn;
 static object Model(object c)=>G(G(c,"Nca"),"StateModel");
 static object[] Items(object l)=>Enumerable.Range(0,Count(l)).Select(i=>At(l,i)).ToArray();
 static object Record(object r)=>new{pointer=Ptr(r),position=V((Vector3)G(r,"Position")),rotation=Q((Quaternion)G(r,"Rotation")),exists=G(r,"IsExist")};
 static object Npc(object n){var tr=(Transform)G(n,"Transform");return new{pointer=Ptr(n),fixedType=G(Model(n),"CurrentFixedType").ToString(),position=V(tr.position),rotation=Q(tr.rotation)};}
 static object NewRecord(Vector3 p,Quaternion q,bool exists){var r=Activator.CreateInstance(T("NpcSaveData"));S(r,"Position",p);S(r,"Rotation",q);S(r,"IsExist",exists);return r;}
 public void Update(){if(Time.realtimeSinceStartup<next)return;next=Time.realtimeSinceStartup+0.05f;
  try{
   var command=Path.Combine(FilterPlugin.Root,"command");
   if(File.Exists(command)){var action=File.ReadAllText(command).Trim();File.Move(command,command+"-"+Time.frameCount);Handle(action);}
   if(phase=="wait"&&Time.realtimeSinceStartup>=deadline)Finish();
  }catch(Exception e){Log("runner_error",new{phase,trial,error=e.ToString()});try{Cleanup();}catch(Exception ex){Log("cleanup_error",ex.ToString());}phase="failed";}
 }
 void Handle(string action){
  Log("command",new{action,phase,scene=SceneManager.GetActiveScene().name});
  if(action=="boot"){M(Find(T("TitleSceneView")),"OnClickContinue");return;}
  if(action=="continue"){M(typeof(SaveManager),"Load",3,1);S(typeof(SaveManager),"CurrentSaveSlot",1);M(Find(T("SaveDataSelectPanelView")),"TransScene");return;}
  if(action=="residence"){SceneManager.LoadScene("Night_Demo 1");return;}
  if(action=="mall"){SceneManager.LoadScene("Mall");return;}
  if(action=="inventory"){
   var elevator=Find(T("ElevatorController"));Log("inventory",new{summary=Summary(),fixedCount=G(NM,"fixedNpcCount"),npcs=Items(G(NM,"ExistNpcList")).Select(Npc).ToArray(),elevator=Ptr(elevator),bounds=elevator==null?null:(object)BoundsInfo((Bounds)G(elevator,"PushBounds"))});return;
  }
  if(action=="snapshot")BeginSnapshot();
  if(action=="elevator")BeginElevator();
 }
 static object BoundsInfo(Bounds b)=>new{center=V(b.center),extents=V(b.extents)};
 void Prepare(string name){
  if(phase!="idle"&&phase!="done")throw new Exception("previous trial pending");
  trial=name;phase="prepare";nm=NM;oldStop=(bool)G(Temp,"IsStopGameStateApplier");S(Temp,"IsStopGameStateApplier",true);
  globals=GlobalNames.Select(n=>G(typeof(GameState),n)).ToArray();oldList=G(nm,"ExistNpcList");oldDict=G(nm,"ExistNpcGameObjectDict");oldRemove=G(nm,"removeList");oldSaved=G(State,"NpcSaveDataList");oldLoaded=G(nm,"isLoadedData");oldFixed=G(nm,"fixedNpcCount");oldSpawn=(int)G(nm,"spawnNum");
  S(State,"NpcSaveDataList",Empty(oldSaved));Log("trial_begin",new{trial,summary=Summary(),oldFixed,oldLoaded});
 }
 void BeginSnapshot(){
  Prepare("snapshot-fixed-absent");
  var objects=Items(oldList);var dynamic=objects.Where(n=>Convert.ToInt32(G(Model(n),"CurrentFixedType"))==0).Take(2).ToArray();var fixedNpcs=objects.Where(n=>Convert.ToInt32(G(Model(n),"CurrentFixedType"))!=0).Take(2).ToArray();
  if(dynamic.Length!=2||fixedNpcs.Length!=2)throw new Exception("need two genuine dynamic and fixed NPCs");
  // Explicit controlled priming: empty OnLoadData sets loaded=true, queues no records.
  M(nm,"OnLoadData");var selected=Empty(oldList);foreach(var n in dynamic.Concat(fixedNpcs))M(selected,"Add",n);
  S(nm,"ExistNpcList",selected);S(nm,"fixedNpcCount",2);
  Log("snapshot_fixture",new{trial,npcs=Items(selected).Select(Npc).ToArray(),fixedCount=2});
  M(nm,"ApplyGameState");Log("snapshot_full",new{trial,records=Items(G(State,"NpcSaveDataList")).Select(Record).ToArray()});
  var reduced=Empty(oldList);foreach(var n in new[]{dynamic[0]}.Concat(fixedNpcs))M(reduced,"Add",n);
  S(nm,"ExistNpcList",reduced);M(nm,"ApplyGameState");
  Log("snapshot_reduced",new{trial,records=Items(G(State,"NpcSaveDataList")).Select(Record).ToArray()});
  S(nm,"ExistNpcList",oldList);S(nm,"fixedNpcCount",oldFixed);
  M(typeof(SaveManager),"Save",3,1,false);Log("saved",new{trial,records=Items(G(State,"NpcSaveDataList")).Select(Record).ToArray()});
  S(nm,"ExistNpcList",Empty(oldList));S(nm,"ExistNpcGameObjectDict",Empty(oldDict));S(nm,"removeList",Empty(oldRemove));
  M(typeof(SaveManager),"Load",3,1);Log("loaded",new{trial,summary=Summary(),records=Items(G(State,"NpcSaveDataList")).Select(Record).ToArray()});
  S(State,"CurrentStageType",10);Log("consumer_fixture",new{trial,scene=SceneManager.GetActiveScene().name,summary=Summary(),records=Items(G(State,"NpcSaveDataList")).Select(Record).ToArray()});
  M(nm,"OnLoadData");phase="wait";deadline=Time.realtimeSinceStartup+4;
 }
 void BeginElevator(){
  Prepare("elevator-existence");var elevator=Find(T("ElevatorController"));if(elevator==null)throw new Exception("need actual elevator");var bounds=(Bounds)G(elevator,"PushBounds");
  var outside=Items(oldList).Select(n=>(Transform)G(n,"Transform")).First(t=>!bounds.Contains(t.position));
  var records=G(State,"NpcSaveDataList");var points=new[]{outside.position,bounds.center,outside.position,bounds.center};var exists=new[]{true,true,false,false};
  for(int i=0;i<4;i++)M(records,"Add",NewRecord(points[i],outside.rotation,exists[i]));
  S(nm,"ExistNpcList",Empty(oldList));S(nm,"ExistNpcGameObjectDict",Empty(oldDict));S(nm,"removeList",Empty(oldRemove));
  Log("consumer_fixture",new{trial,scene=SceneManager.GetActiveScene().name,summary=Summary(),elevator=Ptr(elevator),bounds=BoundsInfo(bounds),records=Items(records).Select(Record).ToArray(),contains=points.Select(p=>bounds.Contains(p)).ToArray()});
  M(nm,"OnLoadData");phase="wait";deadline=Time.realtimeSinceStartup+4;
 }
 void Finish(){Log("runtime",new{trial,summary=Summary(),npcs=Items(G(nm,"ExistNpcList")).Select(Npc).ToArray()});Cleanup();phase="done";Log("complete",new{trial});}
 void Cleanup(){
  if(globals==null)return;
  var current=G(nm,"ExistNpcList");if(Ptr(current)!=Ptr(oldList))foreach(var n in Items(current))M(n,"Destroy");
  S(nm,"ExistNpcList",oldList);S(nm,"ExistNpcGameObjectDict",oldDict);S(nm,"removeList",oldRemove);S(nm,"isLoadedData",oldLoaded);S(nm,"fixedNpcCount",oldFixed);S(nm,"spawnNum",oldSpawn);
  for(int i=0;i<GlobalNames.Length;i++)S(typeof(GameState),GlobalNames[i],globals[i]);S(State,"NpcSaveDataList",oldSaved);S(Temp,"IsStopGameStateApplier",oldStop);globals=null;
  Log("cleanup",new{trial,listRestored=Ptr(G(nm,"ExistNpcList"))==Ptr(oldList),mapRestored=Ptr(G(nm,"ExistNpcGameObjectDict"))==Ptr(oldDict),savedListRestored=Ptr(G(State,"NpcSaveDataList"))==Ptr(oldSaved),loaded=G(nm,"isLoadedData"),fixedCount=G(nm,"fixedNpcCount"),stop=G(Temp,"IsStopGameStateApplier"),live=Count(oldList)});
 }
}
}
