// Save isolation plus passive state sampling. No gameplay setters or method replay.
using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text.Json;
using BepInEx;
using BepInEx.Unity.IL2CPP;
using Il2CppInterop.Runtime.Injection;
using Il2CppInterop.Runtime.InteropTypes;
using UnityEngine;
using UnityEngine.SceneManagement;
using ExposureUnnoticed2.Scripts.InGame;
namespace REANaturalMission {
[BepInPlugin("rea.natural.mission.observer","REA Natural Mission Observer","1.1.0")]
[BepInDependency("rea.natural.observer")]
public class LoadObserver:BasePlugin {
 public static string Root,Case;public static StreamWriter Output;
 public override void Load(){
  Root=Path.Combine(Paths.GameRootPath,"NaturalMission","20261030-1");Case="session";
  var profile=Path.Combine(Root,"working-profile");Directory.CreateDirectory(profile);
  var observer=AppDomain.CurrentDomain.GetAssemblies().Select(a=>a.GetType("Plugin")).First(t=>t?.GetField("SaveRoot")!=null);
  observer.GetField("SaveRoot").SetValue(null,profile);
  ((StreamWriter)observer.GetField("Output").GetValue(null)).Flush();
  observer.GetField("Output").SetValue(null,new StreamWriter(Path.Combine(Root,"paths.jsonl"),true));
  Output=new StreamWriter(Path.Combine(Root,"managed.jsonl"),true);
  ClassInjector.RegisterTypeInIl2Cpp<PassiveState>();AddComponent<PassiveState>();
  Log("observer_loaded",new{profile,scope="save-root isolation and passive Unity-thread reads only; no guard/state/lifecycle replay"});
 }
 public new static void Log(string kind,object data){Output.WriteLine(JsonSerializer.Serialize(new{kind,frame=Time.frameCount,real=Time.realtimeSinceStartup,data}));Output.Flush();}
}

public class PassiveState:MonoBehaviour {
 public PassiveState(IntPtr p):base(p){}
 static readonly BindingFlags F=BindingFlags.Public|BindingFlags.NonPublic|BindingFlags.Static|BindingFlags.Instance;
 static readonly Assembly Game=typeof(SaveManager).Assembly;
 static Type T(string n)=>Game.GetTypes().Single(t=>t.Name==n);
 static object G(object o,string n){if(o==null)return null;var t=o as Type??o.GetType();var p=t.GetProperty(n,F);if(p!=null)return p.GetValue(o is Type?null:o);return t.GetField(n,F)?.GetValue(o is Type?null:o);}
 static object M(object o,string n,params object[] a){var t=o as Type??o.GetType();var m=t.GetMethods(F).Single(x=>x.Name==n&&x.GetParameters().Length==a.Length);return m.Invoke(o is Type?null:o,m.GetParameters().Select((p,i)=>p.ParameterType.IsEnum?Enum.ToObject(p.ParameterType,a[i]):a[i]).ToArray());}
 static string Ptr(object o)=>o is Il2CppObjectBase b?b.Pointer.ToString():null;
 static int Id(object o)=>Convert.ToInt32(o);
 static object[] Seq(object o){if(o==null)return Array.Empty<object>();var e=M(o,"GetEnumerator");var l=new System.Collections.Generic.List<object>();while((bool)M(e,"MoveNext"))l.Add(G(e,"Current"));return l.ToArray();}
 static object Pick(object dict,int id)=>dict!=null&&(bool)M(dict,"ContainsKey",id)?M(dict,"get_Item",id):null;
 static float[] V(Vector3 p)=>new[]{p.x,p.y,p.z};
 float next,sceneBegan;string before;int capture;System.Collections.Generic.Dictionary<string,long> writes=new();
 public void Update(){if(Time.realtimeSinceStartup<next)return;next=Time.realtimeSinceStartup+.5f;try{
  var scene=SceneManager.GetActiveScene().name;if(scene!=before){sceneBegan=Time.realtimeSinceStartup;LoadObserver.Log("scene",new{scene,previous=before});before=scene;}
  var command=Path.Combine(LoadObserver.Root,"command");if(File.Exists(command)){var label=File.ReadAllText(command).Trim();File.Move(command,command+"-"+Time.frameCount);LoadObserver.Log("operator_marker",new{label,scope="label only; no gameplay calls or state stores"});}
  var assets=G(T("AssetReferencer"),"Instance");var gm=G(typeof(InGameManager),"Instance");if(gm is UnityEngine.Object obj&&!obj)gm=null;
  var ir=G(gm,"InGameReferencer");var player=G(ir,"Player");var pca=G(player,"Pca");var ps=G(pca,"PlayerState");var temp=G(gm,"TempInGameState");var state=GameState.GameStateData;var manager=G(T("MissionManager"),"Instance");var missions=G(manager,"MissionList");var tr=G(pca,"Transform") as Transform;
  var list=(missions==null?Array.Empty<object>():Seq(missions)).Select(m=>{var rec=G(m,"RMission");int id=Id(G(m,"UniqueMissionId"));return new{pointer=Ptr(m),id,recordStage=G(rec,"StageType")?.ToString(),type=G(G(rec,"OriginalRecord"),"MissionClassName"),satisfy=G(m,"Satisfy"),done=G(m,"IsDoneOneCompleteProcess"),progress=Pick(G(state,"MissionSatisfyDict"),id),earned=Pick(G(state,"MissionEarnRpDict"),id),achieved=Pick(G(state,"MissionAchieveCountDict"),id)};}).ToArray();
  object exposed=null;if(pca!=null&&Time.realtimeSinceStartup-sceneBegan>2&&G(ps,"CurrentClothes")!=null){var facade=G(pca,"PlayerFacade");if(facade!=null)exposed=M(facade,"GetExposedBodyPartsByClothesAndCostume")?.ToString();}
  LoadObserver.Log("snapshot",new{scene,state=Ptr(state),stage=G(state,"CurrentStageType")?.ToString(),assetsReady=assets!=null&&G(assets,"MHair")!=null,player=Ptr(player),position=tr?V(tr.position):null,rank=G(G(ps,"CurrentRank"),"Rank"),exposed,action=G(G(ps,"CurrentAction"),"type")?.ToString(),rp=G(state,"CurrentRp"),exp=G(state,"ExposeExp"),pendingRp=G(state,"CurrentEarnThisTimeRp"),totalEarn=G(state,"StatistisTotalEarnRp"),stop=G(temp,"IsTimeStop"),applierStopped=G(temp,"IsStopGameStateApplier"),completed=Seq(G(temp,"MissionCompleteThisGameSet")).Select(Id).ToArray(),missionManager=Ptr(manager),missionCount=list.Length,missions=list.Where(m=>m.recordStage==G(state,"CurrentStageType")?.ToString()||Convert.ToDouble(m.satisfy)>0||Convert.ToDouble(m.earned)>0||Convert.ToInt32(m.achieved)>0).ToArray()});
  foreach(var path in Directory.EnumerateFiles(Path.Combine(LoadObserver.Root,"working-profile"),"*.sd",SearchOption.AllDirectories)){long tick=File.GetLastWriteTimeUtc(path).Ticks;if(writes.TryGetValue(path,out var old)&&tick==old)continue;bool initial=!writes.ContainsKey(path);writes[path]=tick;var dir=Path.Combine(LoadObserver.Root,"captures");Directory.CreateDirectory(dir);var target=Path.Combine(dir,(capture++).ToString("D4")+"-"+Path.GetFileName(Path.GetDirectoryName(path))+"-"+Path.GetFileName(path));File.Copy(path,target);LoadObserver.Log("file_capture",new{source=path,target,initial,tick});}
 }catch(Exception e){LoadObserver.Log("snapshot_error",new{error=e.ToString()});}}
}
}
