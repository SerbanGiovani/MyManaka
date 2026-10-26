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
namespace REAStateRestore {
[BepInPlugin("rea.state.restore", "REA Controlled State Restore", "1.0.0")]
[BepInDependency("rea.natural.observer")]
public class RestorePlugin:BasePlugin {
 public static string Root;
 public override void Load(){
  Root=Path.Combine(Paths.GameRootPath,"RestoreRoundtrip","20261027-1");
  var observer=AppDomain.CurrentDomain.GetAssemblies().Select(a=>a.GetType("Plugin")).First(t=>t?.GetField("SaveRoot")!=null);
  observer.GetField("SaveRoot").SetValue(null,Path.Combine(Root,"working-profile"));
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
 static void Log(string kind,object data=null){File.AppendAllText(Path.Combine(RestorePlugin.Root,"restore-managed.jsonl"),JsonSerializer.Serialize(new{kind,frame=Time.frameCount,real=Time.realtimeSinceStartup,data})+"\n");}
 static object State=>G(typeof(GameState),"GameStateData");
 static object NM=>G(G(G(typeof(InGameManager),"Instance"),"InGameReferencer"),"NpcManager");
 static object DM=>G(G(typeof(InGameManager),"Instance"),"DroppedItemManager");
 static object Temp=>G(G(typeof(InGameManager),"Instance"),"TempInGameState");
 static object Summary()=>new{state=Ptr(State),stage=G(State,"CurrentStageType").ToString(),npcs=Count(G(State,"NpcSaveDataList")),reserve=Count(G(State,"ReserveDropList")),live=Count(G(NM,"ExistNpcList")),loaded=G(NM,"isLoadedData")};
 float next;string phase="idle";float deadline;object[] savedGlobals;object oldList,oldDict,oldRemove,oldCache;object nm,dm;object oldLoaded,oldFixed;bool oldStop;object[] seedNpcs;object oldSavedList,oldReserve;int oldSpawn;object[][] oldDropValues;static readonly string[] DropFields={"IsDropped","IsReserve","IsViewCompassInDroneMission","Position","Rotation","StageType","ItemType"};int trials;bool booted;
 public void Update(){if(Time.realtimeSinceStartup<next)return;next=Time.realtimeSinceStartup+0.05f;
  try{
   var command=Path.Combine(RestorePlugin.Root,"command");
   if(File.Exists(command)){var action=File.ReadAllText(command).Trim();File.Move(command,command+"-"+Time.frameCount);Handle(action);}
   if(phase=="wait-spawn"&&Time.realtimeSinceStartup>=deadline)Finish();
  }catch(Exception e){Log("runner_error",new{phase,error=e.ToString()});try{Cleanup();}catch(Exception c){Log("cleanup_error",c.ToString());}phase="failed";}
 }
 void Handle(string action){
  Log("command",new{action,phase,scene=SceneManager.GetActiveScene().name});
  if(action=="boot"){phase="idle";
   var title=Find(T("TitleSceneView"));Log("boot_ui",new{title=Ptr(title),count=G(title,"IsEndLoadCount"),assembly=GetType().Assembly.Location});
   M(title,"OnClickContinue");return;
  }
  if(action=="continue"){M(typeof(SaveManager),"Load",5,19);S(typeof(SaveManager),"CurrentSaveSlot",0);M(Find(T("SaveDataSelectPanelView")),"TransScene");booted=true;return;}
  if(action=="mall"){SceneManager.LoadScene("Mall");return;}
  if(action=="inventory"){
   Log("inventory",Summary());
   foreach(var name in new[]{"NpcManager","DroppedItemManager","GameStateData","InGameManager","NpcController","NpcClassAccessor","NpcStateModel","DropData","NpcSaveData"})try{var t=T(name);Log("members",new{name,properties=t.GetProperties(Flags).Select(p=>new{p.Name,type=p.PropertyType.FullName}).ToArray()});}catch(Exception e){Log("members_error",new{name,error=e.Message});}
   return;
  }
  if(action=="reset"){phase="idle";return;}
  if(action=="scene-continue"){M(Find(T("SaveDataSelectPanelView")),"TransScene");booted=true;phase="idle";return;}
  if(action=="loaded"){M(NM,"OnLoadData");return;}
  if(action=="run")Begin();
 }
 void Begin(){
  if(!booted||phase!="idle")throw new Exception("isolated boot/run sequence required");
  phase="prepare";nm=NM;dm=DM;var temp=Temp;oldStop=(bool)G(temp,"IsStopGameStateApplier");S(temp,"IsStopGameStateApplier",true);
  savedGlobals=GlobalNames.Select(n=>G(typeof(GameState),n)).ToArray();
  oldList=G(nm,"ExistNpcList");oldDict=G(nm,"ExistNpcGameObjectDict");oldRemove=G(nm,"removeList");oldCache=G(dm,"cache");oldLoaded=G(nm,"isLoadedData");oldFixed=G(nm,"fixedNpcCount");
  oldSpawn=(int)G(nm,"spawnNum");oldSavedList=G(State,"NpcSaveDataList");oldReserve=G(State,"ReserveDropList");
  oldDropValues=new[]{0,1,3,4}.Select(id=>{var d=M(G(State,"DropDataDict"),"get_Item",id);return new[]{d}.Concat(DropFields.Select(f=>G(d,f))).ToArray();}).ToArray();
  S(State,"NpcSaveDataList",Empty(oldSavedList));S(State,"ReserveDropList",Empty(oldReserve));
  var selected=Empty(oldList);int n=Math.Min(3,Count(oldList));if(n<3)throw new Exception("need at least three naturally spawned NPCs");
  for(int i=0;i<n;i++)M(selected,"Add",At(oldList,i));
  // Use the native snapshot producer; isLoadedData must already be true.
  S(nm,"ExistNpcList",selected);S(nm,"fixedNpcCount",0);M(nm,"ApplyGameState");S(nm,"ExistNpcList",oldList);S(nm,"fixedNpcCount",oldFixed);
  var records=G(State,"NpcSaveDataList");if(Count(records)!=3)throw new Exception("native NPC snapshot did not produce three records");
  seedNpcs=Enumerable.Range(0,Count(records)).Select(i=>At(records,i)).ToArray();
  var player=G(G(G(typeof(InGameManager),"Instance"),"InGameReferencer"),"Player");
  var position=((Transform)G(G(player,"Pca"),"Transform")).position+new Vector3(0.5f,0,0.5f);var rotation=Quaternion.identity;
  S(dm,"cache",Empty(oldCache));M(dm,"Drop",position,rotation,0);M(dm,"ReserveDrop",1,11);M(dm,"ReserveDrop",3,0);
  M(dm,"Drop",position+new Vector3(1,0,0),rotation,4);S(M(G(State,"DropDataDict"),"get_Item",4),"StageType",0);
  Log("fixture",new{summary=Summary(),npc=seedNpcs.Select(Pose).ToArray(),drop=DropRecord(0),otherStage=DropRecord(4),reserve=Enumerable.Range(0,Count(G(State,"ReserveDropList"))).Select(i=>DropPose(At(G(State,"ReserveDropList"),i))).ToArray()});
  phase="save";M(typeof(SaveManager),"Save",3,0,false);Log("saved",Summary());
  // Remove runtime objects from the restoration manager without deleting originals.
  M(dm,"Hide",0);S(nm,"ExistNpcList",Empty(oldList));S(nm,"ExistNpcGameObjectDict",Empty(oldDict));S(nm,"removeList",Empty(oldRemove));
  // Establish a different in-memory graph, then load from the actual native file.
  S(State,"NpcSaveDataList",Empty(records));M(G(State,"ReserveDropList"),"Clear");
  Log("disturbed",Summary());phase="load";M(typeof(SaveManager),"Load",3,0);Log("loaded",new{summary=Summary(),npc=Enumerable.Range(0,Count(G(State,"NpcSaveDataList"))).Select(i=>Pose(At(G(State,"NpcSaveDataList"),i))).ToArray(),drop=DropRecord(0),otherStage=DropRecord(4),reserve=Enumerable.Range(0,Count(G(State,"ReserveDropList"))).Select(i=>DropPose(At(G(State,"ReserveDropList"),i))).ToArray()});
  // Native Load normalizes to Apart. Replay only consumers after scene reconciliation.
  S(State,"CurrentStageType",11);phase="restore";Log("reconciled",Summary());
  M(nm,"OnLoadData");M(dm,"ActiveDroppedItemIfNeed");M(dm,"ApplyReserveDropIfNeed");
  Log("consumers_return",new{summary=Summary(),current=DropRuntime(0),reserved=DropRuntime(1),otherStage=DropRuntime(4)});
  phase="wait-spawn";deadline=Time.realtimeSinceStartup+3;
 }
 static object DropPose(object d)=>new{pointer=Ptr(d),isDropped=G(d,"IsDropped"),isReserve=G(d,"IsReserve"),stage=G(d,"StageType").ToString(),item=G(d,"ItemType").ToString(),position=V((Vector3)G(d,"Position")),rotation=Q((Quaternion)G(d,"Rotation"))};
 static object DropRecord(int id)=>DropPose(M(G(State,"DropDataDict"),"get_Item",id));
 object DropRuntime(int id){var c=M(dm,"GetCache",id) as Component;return new{record=DropRecord(id),component=Ptr(c),active=c.gameObject.activeSelf,position=V(c.transform.position),rotation=Q(c.transform.rotation)};}
 void Finish(){
  var live=G(nm,"ExistNpcList");
  Log("runtime",new{summary=Summary(),npcs=Enumerable.Range(0,Count(live)).Select(i=>{var c=At(live,i);var tr=(Transform)G(c,"Transform");return new{pointer=Ptr(c),active=((GameObject)G(c,"GameObject")).activeSelf,position=V(tr.position),rotation=Q(tr.rotation)};}).ToArray(),current=DropRuntime(0),reserved=DropRuntime(1),otherStage=DropRuntime(4)});
  M(dm,"ApplyReserveDropIfNeed");Log("reserve_replay",new{summary=Summary(),reserved=DropRuntime(1),pending=Enumerable.Range(0,Count(G(State,"ReserveDropList"))).Select(i=>DropPose(At(G(State,"ReserveDropList"),i))).ToArray()});
  Cleanup();phase="done";Log("complete",new{trials=++trials});
 }
 void Cleanup(){
  if(savedGlobals==null)return;
  var live=G(nm,"ExistNpcList");if(!ReferenceEquals(live,oldList)&&Ptr(live)!=Ptr(oldList)){for(int i=Count(live)-1;i>=0;i--)M(At(live,i),"Destroy");}
  foreach(int id in new[]{0,1,4}){var c=M(dm,"GetCache",id) as Component;if(c)UnityEngine.Object.Destroy(c.gameObject);}
  S(nm,"ExistNpcList",oldList);S(nm,"ExistNpcGameObjectDict",oldDict);S(nm,"removeList",oldRemove);S(nm,"isLoadedData",oldLoaded);S(nm,"fixedNpcCount",oldFixed);S(nm,"spawnNum",oldSpawn);S(dm,"cache",oldCache);
  for(int i=0;i<GlobalNames.Length;i++)S(typeof(GameState),GlobalNames[i],savedGlobals[i]);
  if(oldSavedList!=null)S(State,"NpcSaveDataList",oldSavedList);if(oldReserve!=null)S(State,"ReserveDropList",oldReserve);
  if(oldDropValues!=null)foreach(var row in oldDropValues)for(int i=0;i<DropFields.Length;i++)S(row[0],DropFields[i],row[i+1]);
  S(Temp,"IsStopGameStateApplier",oldStop);savedGlobals=null;Log("cleanup",new{summary=Summary(),spawn=(int)G(nm,"spawnNum"),oldSpawn,listRestored=Ptr(G(nm,"ExistNpcList"))==Ptr(oldList),mapRestored=Ptr(G(nm,"ExistNpcGameObjectDict"))==Ptr(oldDict),cacheRestored=Ptr(G(dm,"cache"))==Ptr(oldCache),stop=G(Temp,"IsStopGameStateApplier")});
 }
}
}
