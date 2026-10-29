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
namespace REANaturalLoad {
[BepInPlugin("rea.natural.load.observer","REA Natural Load Observer","1.1.0")]
[BepInDependency("rea.natural.observer")]
public class LoadObserver:BasePlugin {
 public static string Root,Case;public static StreamWriter Output;
 public override void Load(){
  Root=Path.Combine(Paths.GameRootPath,"NaturalLoad","20261029-1");Case=File.ReadAllText(Path.Combine(Root,"profile.txt")).Trim();
  if(Case.IndexOfAny(new[]{'/', '\\', ':'})>=0)throw new Exception("case name");
  var profile=File.ReadAllText(Path.Combine(Root,"profile-root.txt")).Trim();Directory.CreateDirectory(profile);
  var observer=AppDomain.CurrentDomain.GetAssemblies().Select(a=>a.GetType("Plugin")).First(t=>t?.GetField("SaveRoot")!=null);
  observer.GetField("SaveRoot").SetValue(null,profile);
  ((StreamWriter)observer.GetField("Output").GetValue(null)).Flush();
  observer.GetField("Output").SetValue(null,new StreamWriter(Path.Combine(Root,Case+"-natural.jsonl"),true));
  Output=new StreamWriter(Path.Combine(Root,Case+"-state.jsonl"),true);
  ClassInjector.RegisterTypeInIl2Cpp<PassiveState>();AddComponent<PassiveState>();
  Log("observer_loaded",new{profile,scope="save-root isolation and passive Unity-thread reads only; no guard/state/lifecycle replay"});
 }
 public new static void Log(string kind,object data){Output.WriteLine(JsonSerializer.Serialize(new{kind,frame=Time.frameCount,real=Time.realtimeSinceStartup,data}));Output.Flush();}
}
public class PassiveState:MonoBehaviour {
 public PassiveState(IntPtr p):base(p){}
 static readonly BindingFlags Flags=BindingFlags.Public|BindingFlags.NonPublic|BindingFlags.Static|BindingFlags.Instance;
 static readonly Type DebugType=typeof(SaveManager).Assembly.GetTypes().Single(t=>t.Name=="DebugController");
 static object G(object o,string n){if(o==null)return null;var t=o as Type??o.GetType();var p=t.GetProperty(n,Flags);if(p!=null)return p.GetValue(o is Type?null:o);return t.GetField(n,Flags)?.GetValue(o is Type?null:o);}
 static string Ptr(object o)=>o is Il2CppObjectBase b?b.Pointer.ToString():null;
 static int Count(object o)=>o==null?0:(int)G(o,"Count");
 static float[] V(Vector3 p)=>new[]{p.x,p.y,p.z};
 float next;string before;
 public void Update(){if(Time.realtimeSinceStartup<next)return;next=Time.realtimeSinceStartup+0.5f;
  try{
   var scene=SceneManager.GetActiveScene().name;var gm=G(typeof(InGameManager),"Instance");if(gm is UnityEngine.Object u&&!u)gm=null;
   var ir=G(gm,"InGameReferencer");var nm=G(ir,"NpcManager");var state=GameState.GameStateData;var player=G(ir,"Player");var tr=G(G(player,"Pca"),"Transform") as Transform;
   LoadObserver.Log("snapshot",new{scene,sceneChanged=scene!=before,state=Ptr(state),stage=G(state,"CurrentStageType")?.ToString(),manager=Ptr(nm),npcSaved=Count(G(state,"NpcSaveDataList")),live=Count(G(nm,"ExistNpcList")),loaded=G(nm,"isLoadedData"),initialized=G(nm,"initialized"),fixedCount=G(nm,"fixedNpcCount"),spawn=G(nm,"spawnNum"),force=gm==null?null:G(DebugType,"IsForceCreateNpc"),debug=gm==null?null:G(DebugType,"IsDebug"),applierStopped=G(G(gm,"TempInGameState"),"IsStopGameStateApplier"),storedPlayer=state==null?null:V(state.PlayerPosition),actualPlayer=tr?V(tr.position):null});before=scene;
  }catch(Exception e){LoadObserver.Log("snapshot_error",new{error=e.ToString()});}
 }
}
}
