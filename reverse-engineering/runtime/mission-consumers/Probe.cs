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
namespace REAMissionConsumers {
[BepInPlugin("rea.mission.consumers","REA Mission Consumers","1.0.0")]
[BepInDependency("rea.natural.observer")]
public class AppearancePlugin:BasePlugin {
 public static string Root;
 public override void Load(){Root=Path.Combine(Paths.GameRootPath,"MissionConsumers","20261030-7");var observer=AppDomain.CurrentDomain.GetAssemblies().Select(a=>a.GetType("Plugin")).First(t=>t?.GetField("SaveRoot")!=null);observer.GetField("SaveRoot").SetValue(null,Path.Combine(Root,"working-profile"));((StreamWriter)observer.GetField("Output").GetValue(null)).Flush();observer.GetField("Output").SetValue(null,new StreamWriter(Path.Combine(Root,"paths.jsonl"),true));Application.SetStackTraceLogType(LogType.Error,StackTraceLogType.Full);Application.SetStackTraceLogType(LogType.Exception,StackTraceLogType.Full);ClassInjector.RegisterTypeInIl2Cpp<Runner>();AddComponent<Runner>();}
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




 static readonly string[] MissionFields={"_RpPerSec_k__BackingField","rpPerSecScale","rpPerSecScaleChangeRemainTime","remainStartPerSecTime","_ContinueSatisfy_k__BackingField","RMission","satisfy","lastAddSatisfyTime","lastNonAddSatisfyTime","isCancelByHideCosplay","_IsDoneOneCompleteProcess_k__BackingField","isDoneOneCompleteProcessContinue","perSecScale"};
 static readonly string[] TempFields={"IsCollectDropItem","IsStopGameStateApplier","IsGameOver","IsFirstLoadStage","IsPlayingSomePerformance","IsTimeStop","BeforeStageType","IsDownRank","LostExp","LostRp","MissionCompleteThisGameSet","MissionMaxRpBonus100ThisGameDict","DroneMissionCompleteThisGame","AchieveMissionCountByStageThisGameDict","CurrentEarnThisTimePerSecRp","IsNoAchieveMissionMode","CurrentMotionSpeed"};
 object[][] oldMissionFields;object[] oldTemp;
 object[] savedRoots;object oldSlot,oldManager,oldRank,originalRequired;bool oldStop;float next;string current="idle";object chosen,mission;UnityEngine.Object[] clones;int mid;
 static int Id(object v)=>Convert.ToInt32(v);
 static object[] Items(object o){var vals=K(o).GetProperty("Values",Flags);if(vals!=null){var e=M(vals.GetValue(o),"GetEnumerator");var list=new System.Collections.Generic.List<object>();while((bool)M(e,"MoveNext"))list.Add(G(e,"Current"));return list.ToArray();}var n=K(o).GetProperty("Count",Flags)??K(o).GetProperty("Length",Flags);return Enumerable.Range(0,(int)n.GetValue(o)).Select(i=>At(o,i)).ToArray();}
 void Begin(string name){current=name;OutputDebugStringW("REA_MISSION_BEGIN:"+name);}
 void End(){OutputDebugStringW("REA_MISSION_END:");current="idle";}
 object NewMission(object record){var c=(string)G(G(record,"OriginalRecord"),"MissionClassName");var type=Game.GetTypes().Single(t=>t.Name==c||t.FullName==c);var o=Activator.CreateInstance(type);M(o,"Initialize",record);return o;}
 object Pick(object dict,int id)=> (bool)M(dict,"ContainsKey",id)?M(dict,"get_Item",id):null;
 object Snap()=>new{state=Ptr(State),mission=Ptr(mission),id=mid,stage=G(State,"CurrentStageType").ToString(),delta=Time.deltaTime,rpBonus=G(G(Pca,"PlayerState"),"RpBonus"),rpPerSec=G(mission,"RpPerSec"),satisfy=G(mission,"Satisfy"),done=G(mission,"IsDoneOneCompleteProcess"),timeStop=G(Temp,"IsTimeStop"),progress=Pick(G(State,"MissionSatisfyDict"),mid),achieved=Pick(G(State,"MissionAchieveCountDict"),mid),earned=Pick(G(State,"MissionEarnRpDict"),mid),rp=G(State,"CurrentRp"),pendingRp=G(State,"CurrentEarnThisTimeRp"),total=G(State,"StatistisTotalEarnRp")};
 void Restore(){if(savedRoots==null)return;for(int i=0;i<GlobalNames.Length;i++)S(typeof(GameState),GlobalNames[i],savedRoots[i]);S(typeof(SaveManager),"CurrentSaveSlot",oldSlot);S(Temp,"IsStopGameStateApplier",oldStop);S(T("MissionManager"),"Instance",oldManager);S(G(Pca,"PlayerState"),"CurrentRank",oldRank);if(oldMissionFields!=null)foreach(var row in oldMissionFields)for(int i=0;i<MissionFields.Length;i++)S(row[0],MissionFields[i],row[i+1]);if(oldTemp!=null)for(int i=0;i<TempFields.Length;i++)S(Temp,TempFields[i],oldTemp[i]);}
 void SaveCapture(string name){M(typeof(SaveManager),"Save",3,1,false);File.Copy(Path.Combine(AppearancePlugin.Root,"working-profile/SaveData/1.sd"),Path.Combine(AppearancePlugin.Root,"captures",name+".sd"),false);}
 void InStage(System.Action action){var old=G(State,"CurrentStageType");S(State,"CurrentStageType",G(chosen,"StageType"));var oldTime=G(Temp,"IsTimeStop");S(Temp,"IsTimeStop",current=="paused");try{action();}finally{S(State,"CurrentStageType",old);S(Temp,"IsTimeStop",oldTime);}}
 public void Update(){if(Time.realtimeSinceStartup<next)return;next=Time.realtimeSinceStartup+.05f;var path=Path.Combine(AppearancePlugin.Root,"command");if(!File.Exists(path))return;var action=File.ReadAllText(path).Trim();File.Move(path,path+"-"+Time.frameCount);try{Handle(action);}catch(Exception e){Log("runner_error",new{action,current,error=e.ToString()});End();}}
 void Handle(string action){Log("command",new{action,current,scene=SceneManager.GetActiveScene().name});
 if(action=="ready"){var assets=G(T("AssetReferencer"),"Instance");var hair=assets==null?null:G(assets,"MHair");Log("readiness",new{assets=Ptr(assets),hair=Ptr(hair),ready=assets!=null&&hair!=null,scene=SceneManager.GetActiveScene().name});return;}
 if(action=="boot"){M(Find(T("TitleSceneView")),"OnClickContinue");return;}
 if(action=="continue"){M(typeof(SaveManager),"Load",3,1);S(typeof(SaveManager),"CurrentSaveSlot",1);M(Find(T("SaveDataSelectPanelView")),"TransScene");return;}
 if(action=="prepare"){
 if(savedRoots!=null||SceneManager.GetActiveScene().name!="Apartment")throw new Exception("fresh Apartment required");savedRoots=GlobalNames.Select(n=>G(typeof(GameState),n)).ToArray();oldSlot=G(typeof(SaveManager),"CurrentSaveSlot");oldManager=G(T("MissionManager"),"Instance");oldRank=G(G(Pca,"PlayerState"),"CurrentRank");oldStop=(bool)G(Temp,"IsStopGameStateApplier");oldMissionFields=Items(G(oldManager,"MissionList")).Select(o=>new[]{o}.Concat(MissionFields.Select(f=>G(o,f))).ToArray()).ToArray();oldTemp=TempFields.Select(f=>G(Temp,f)).ToArray();foreach(var f in new[]{"MissionCompleteThisGameSet","MissionMaxRpBonus100ThisGameDict","AchieveMissionCountByStageThisGameDict"})S(Temp,f,Activator.CreateInstance(G(Temp,f).GetType()));S(Temp,"IsStopGameStateApplier",true);Directory.CreateDirectory(Path.Combine(AppearancePlugin.Root,"captures"));M(typeof(SaveManager),"Save",3,1,false);File.Copy(Path.Combine(AppearancePlugin.Root,"working-profile/SaveData/1.sd"),Path.Combine(AppearancePlugin.Root,"baseline.sd"));M(typeof(SaveManager),"Load",3,1);
 var list=Items(G(G(T("MissionManager"),"Instance"),"MissionList"));var candidates=list.Select(o=>G(o,"RMission")).Where(o=>((string)G(G(o,"OriginalRecord"),"MissionClassName")).Contains("SimpleBodyExpose")&&Id(G(o,"ReleaseRank"))==0).ToArray();
 foreach(var rec in candidates){var m=NewMission(rec);bool ok=(bool)M(m,"IsInCondition");Log("candidate",new{id=G(rec,"Id"),cls=G(G(rec,"OriginalRecord"),"MissionClassName"),stage=G(rec,"StageType").ToString(),required=G(G(rec,"OriginalRecord"),"ExposedBodyPartsParam").ToString(),condition=ok,reward=G(rec,"RewardRankPoint"),addScale=G(rec,"AddSatisfyScale"),trial=G(rec,"Trial")});if(chosen==null&&ok)chosen=rec;}
 if(chosen==null){var original=candidates.First();var a=UnityEngine.Object.Instantiate((UnityEngine.Object)original);var b=UnityEngine.Object.Instantiate((UnityEngine.Object)G(original,"OriginalRecord"));clones=new[]{a,b};chosen=Activator.CreateInstance(original.GetType(),new object[]{a.Pointer});var source=G(original,"OriginalRecord");var changed=Activator.CreateInstance(source.GetType(),new object[]{b.Pointer});originalRequired=G(source,"ExposedBodyPartsParam");S(changed,"ExposedBodyPartsParam",0);S(chosen,"OriginalRecord",changed);M(chosen,"Initialize",G(source,"Id"),G(original,"StageType"));Log("controlled_condition",new{id=G(chosen,"Id"),originalRequired=G(source,"ExposedBodyPartsParam").ToString(),required=G(changed,"ExposedBodyPartsParam").ToString(),condition=M(NewMission(chosen),"IsInCondition"),scope="runtime ScriptableObject clones only; no natural mission eligibility claim"});}
 Log("prepared",new{chosen=chosen==null?null:G(chosen,"Id"),actual=G(Pca,"PlayerFacade")==null?null:M(G(Pca,"PlayerFacade"),"GetExposedBodyPartsByClothesAndCostume").ToString(),rank=G(G(G(Pca,"PlayerState"),"CurrentRank"),"Rank"),candidateCount=candidates.Length});return;}
 if(action.StartsWith("case ")){
 if(chosen==null)throw new Exception("no naturally satisfied selected candidate");var label=action.Substring(5);S(G(chosen,"OriginalRecord"),"ExposedBodyPartsParam",label=="unmet"?originalRequired:0);Begin(label);File.Copy(Path.Combine(AppearancePlugin.Root,"baseline.sd"),Path.Combine(AppearancePlugin.Root,"working-profile/SaveData/1.sd"),true);M(typeof(SaveManager),"Load",3,1);mid=Id(G(chosen,"Id"));M(G(State,"MissionSatisfyDict"),"set_Item",mid,label=="completed"?1f:.9999f);M(G(State,"MissionAchieveCountDict"),"set_Item",mid,0);M(G(State,"MissionEarnRpDict"),"set_Item",mid,0f);S(State,"CurrentRp",0d);S(State,"CurrentEarnThisTimeRp",0d);S(State,"StatistisTotalEarnRp",0d);mission=NewMission(chosen);Log("reference",Snap());SaveCapture(label+"-before");M(G(State,"MissionSatisfyDict"),"set_Item",mid,.1f);M(G(State,"MissionAchieveCountDict"),"set_Item",mid,9);S(State,"CurrentRp",7777d);Log("disturbed",Snap());M(typeof(SaveManager),"Load",3,1);mission=NewMission(chosen);Log("loaded",Snap());InStage(()=>{M(mission,"Update");Log("update1",Snap());M(mission,"Update");Log("update2",Snap());M(mission,"Update");Log("update3",Snap());});SaveCapture(label+"-after");M(typeof(SaveManager),"Load",3,1);mission=NewMission(chosen);Log("reinitialized",Snap());InStage(()=>{M(mission,"Update");Log("reload_update1",Snap());M(mission,"Update");Log("reload_update2",Snap());});SaveCapture(label+"-replayed");Log("result",new{name=label,snapshot=Snap()});End();return;}
 if(action=="settle"){Begin("settlement");Log("settlement_before",Snap());var manager=G(T("MissionManager"),"Instance");var selected=Items(G(manager,"MissionList")).Single(o=>Id(G(o,"UniqueMissionId"))==mid);M(selected,"Initialize",G(selected,"RMission"));Log("manager_rebound",new{old=Ptr(oldManager),current=Ptr(manager),count=Count(G(manager,"MissionList")),mission=Ptr(selected),satisfy=G(selected,"Satisfy"),complete=G(selected,"IsComplete"),done=G(selected,"IsDoneOneCompleteProcess")});M(T("ResultPanelView"),"OpenIfNeed");Log("settlement_after",Snap());SaveCapture("settlement-after");Log("result",new{name="settlement",snapshot=Snap()});End();return;}
 if(action=="cleanup"){Restore();if(clones!=null)foreach(var clone in clones)UnityEngine.Object.Destroy(clone);Log("cleanup",new{rootsRestored=GlobalNames.Select((n,i)=>Ptr(G(typeof(GameState),n))==Ptr(savedRoots[i])).All(x=>x),stop=G(Temp,"IsStopGameStateApplier")});return;}
 throw new Exception("unknown command");
 }
}
}
