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
namespace REAColdDrop {
[BepInPlugin("rea.drop.cold","REA Controlled Cold Drop Cache","1.0.0")]
[BepInDependency("rea.natural.observer")]
public class ColdPlugin:BasePlugin {
 public static string Root;
 public override void Load(){
  Root=Path.Combine(Paths.GameRootPath,"DropColdCache","20261030-1");
  var observer=AppDomain.CurrentDomain.GetAssemblies().Select(a=>a.GetType("Plugin")).First(t=>t?.GetField("SaveRoot")!=null);
  observer.GetField("SaveRoot").SetValue(null,Path.Combine(Root,"working-profile"));((StreamWriter)observer.GetField("Output").GetValue(null)).Flush();
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
 static void Log(string kind,object data=null){File.AppendAllText(Path.Combine(ColdPlugin.Root,"cold-managed.jsonl"),JsonSerializer.Serialize(new{kind,frame=Time.frameCount,real=Time.realtimeSinceStartup,data})+"\n");}
 static object State=>G(typeof(GameState),"GameStateData");
 static object NM=>G(G(G(typeof(InGameManager),"Instance"),"InGameReferencer"),"NpcManager");
 static object DM=>G(G(typeof(InGameManager),"Instance"),"DroppedItemManager");
 static object Temp=>G(G(typeof(InGameManager),"Instance"),"TempInGameState");
 static object Summary()=>new{state=Ptr(State),stage=G(State,"CurrentStageType").ToString(),npcs=Count(G(State,"NpcSaveDataList")),reserve=Count(G(State,"ReserveDropList")),live=Count(G(NM,"ExistNpcList")),loaded=G(NM,"isLoadedData")};

 static readonly string[] DropFields={"IsDropped","IsReserve","IsViewCompassInDroneMission","Position","Rotation","StageType","ItemType"};
 float next,deadline;string phase="idle";object dm,oldCache;object[] globals;object[][] oldRecords;bool oldStop;Component destroyed;
 static object D(int id)=>M(G(State,"DropDataDict"),"get_Item",id);
 static object Record(int id){var d=D(id);return new{item=id,pointer=Ptr(d),dropped=G(d,"IsDropped"),stage=G(d,"StageType").ToString(),position=V((Vector3)G(d,"Position")),rotation=Q((Quaternion)G(d,"Rotation"))};}
 static object Runtime(object manager,int id){var cache=G(manager,"cache");bool exists=(bool)M(cache,"ContainsKey",id);var c=exists?M(cache,"get_Item",id) as Component:null;return new{item=id,present=exists,pointer=Ptr(c),alive=(bool)c,gameObject=c?Ptr(c.gameObject):null,active=c?(bool?)c.gameObject.activeSelf:null,position=c?V(c.transform.position):null,rotation=c?Q(c.transform.rotation):null};}
 object Snap()=>new{scene=SceneManager.GetActiveScene().name,stage=G(State,"CurrentStageType").ToString(),state=Ptr(State),cache=Ptr(G(dm,"cache")),cacheCount=Count(G(dm,"cache")),current=Runtime(dm,0),other=Runtime(dm,4),untouched=Runtime(dm,3)};
 public void Update(){if(Time.realtimeSinceStartup<next)return;next=Time.realtimeSinceStartup+0.05f;
  try{
   var command=Path.Combine(ColdPlugin.Root,"command");if(File.Exists(command)){var action=File.ReadAllText(command).Trim();File.Move(command,command+"-"+Time.frameCount);Handle(action);}
   if(phase=="destroy-wait"&&Time.realtimeSinceStartup>=deadline){Log("stale_before",Snap());M(dm,"ActiveDroppedItemIfNeed");Log("stale_return",Snap());phase="settle";deadline=Time.realtimeSinceStartup+1;}
   if(phase=="settle"&&Time.realtimeSinceStartup>=deadline){Log("runtime",Snap());Cleanup();phase="done";Log("complete");}
  }catch(Exception e){Log("runner_error",new{phase,error=e.ToString()});try{Cleanup();}catch(Exception ex){Log("cleanup_error",ex.ToString());}phase="failed";}
 }
 void Handle(string action){
  Log("command",new{action,phase,scene=SceneManager.GetActiveScene().name});
  if(action=="boot"){M(Find(T("TitleSceneView")),"OnClickContinue");return;}
  if(action=="continue"){M(typeof(SaveManager),"Load",3,1);S(typeof(SaveManager),"CurrentSaveSlot",1);M(Find(T("SaveDataSelectPanelView")),"TransScene");return;}
  if(action=="run")Begin();
 }
 void Begin(){
  if(phase!="idle"||SceneManager.GetActiveScene().name!="Apartment")throw new Exception("need fresh Apartment");
  phase="prepare";dm=DM;oldStop=(bool)G(Temp,"IsStopGameStateApplier");S(Temp,"IsStopGameStateApplier",true);globals=GlobalNames.Select(n=>G(typeof(GameState),n)).ToArray();oldCache=G(dm,"cache");
  oldRecords=new[]{0,4}.Select(id=>new[]{D(id)}.Concat(DropFields.Select(f=>G(D(id),f))).ToArray()).ToArray();
  var player=G(G(G(typeof(InGameManager),"Instance"),"InGameReferencer"),"Player");var pos=((Transform)G(G(player,"Pca"),"Transform")).position;
  S(D(0),"IsDropped",true);S(D(0),"IsReserve",false);S(D(0),"StageType",0);S(D(0),"Position",pos+new Vector3(0.5f,0,0.5f));S(D(0),"Rotation",Quaternion.Euler(0,35,0));
  S(D(4),"IsDropped",true);S(D(4),"IsReserve",false);S(D(4),"StageType",10);S(D(4),"Position",pos+new Vector3(1,0,0));S(D(4),"Rotation",Quaternion.identity);
  S(dm,"cache",Empty(oldCache));Log("fixture",new{snapshot=Snap(),records=new[]{Record(0),Record(4)}});
  M(typeof(SaveManager),"Save",3,1,false);Log("saved",new{records=new[]{Record(0),Record(4)}});
  M(typeof(SaveManager),"Load",3,1);Log("loaded",new{snapshot=Snap(),records=new[]{Record(0),Record(4)}});
  Log("cold_before",Snap());M(dm,"ActiveDroppedItemIfNeed");Log("cold_return",Snap());
  M(dm,"ActiveDroppedItemIfNeed");Log("warm_return",Snap());
  destroyed=M(G(dm,"cache"),"get_Item",0) as Component;Log("destroy_requested",new{pointer=Ptr(destroyed),gameObject=Ptr(destroyed.gameObject)});UnityEngine.Object.Destroy(destroyed.gameObject);
  phase="destroy-wait";deadline=Time.realtimeSinceStartup+0.2f;
 }
 void Cleanup(){
  if(globals==null)return;var cache=G(dm,"cache");foreach(var id in new[]{0,4})if((bool)M(cache,"ContainsKey",id)){var c=M(cache,"get_Item",id) as Component;if(c)UnityEngine.Object.Destroy(c.gameObject);}
  S(dm,"cache",oldCache);for(int i=0;i<GlobalNames.Length;i++)S(typeof(GameState),GlobalNames[i],globals[i]);foreach(var row in oldRecords)for(int i=0;i<DropFields.Length;i++)S(row[0],DropFields[i],row[i+1]);S(Temp,"IsStopGameStateApplier",oldStop);globals=null;
  Log("cleanup",new{cacheRestored=Ptr(G(dm,"cache"))==Ptr(oldCache),cacheCount=Count(oldCache),stop=G(Temp,"IsStopGameStateApplier")});
 }
}
}
