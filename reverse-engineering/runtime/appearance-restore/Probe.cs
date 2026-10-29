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
namespace REAAppearanceRestore {
[BepInPlugin("rea.appearance.restore","REA Appearance Restore","1.0.0")]
[BepInDependency("rea.natural.observer")]
public class AppearancePlugin:BasePlugin {
 public static string Root;
 public override void Load(){Root=Path.Combine(Paths.GameRootPath,"AppearanceRestore","20261030-1");var observer=AppDomain.CurrentDomain.GetAssemblies().Select(a=>a.GetType("Plugin")).First(t=>t?.GetField("SaveRoot")!=null);observer.GetField("SaveRoot").SetValue(null,Path.Combine(Root,"working-profile"));((StreamWriter)observer.GetField("Output").GetValue(null)).Flush();observer.GetField("Output").SetValue(null,new StreamWriter(Path.Combine(Root,"paths.jsonl"),true));Application.SetStackTraceLogType(LogType.Error,StackTraceLogType.Full);Application.SetStackTraceLogType(LogType.Exception,StackTraceLogType.Full);ClassInjector.RegisterTypeInIl2Cpp<Runner>();AddComponent<Runner>();}
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
 object Snapshot(){
  var body=Body;var avatar=(Transform)G(body,"avatarTransform");var player=(Component)Player;
  var bones=UnityEngine.Object.FindObjectsOfType<ExposureUnnoticed2.Object3D.Player.Scripts.PlayerBoneScaleAdjuster>(true).Where(c=>c.transform.IsChildOf(player.transform)).ToArray();
  var hair=UnityEngine.Object.FindObjectsOfType<ExposureUnnoticed2.Object3D.Player.Scripts.Other.HairCustomAdjuster>(true).Where(c=>c.transform.IsChildOf(player.transform)).ToArray();
  var material=(Material)G(body,"bodyMaterial");int colorId=(int)G(body,"BaseColor");
  return new{scene=SceneManager.GetActiveScene().name,custom=Ptr(Custom),height=G(Custom,"CustomizeHeight"),body=Ptr(body),heightScale=G(body,"HeightScale"),defaultBaseScale=G(body,"defaultBaseScale"),avatar=Ptr(avatar),avatarScale=V(avatar.localScale),moveSpeed=G(body,"MoveSpeed"),animationMoveSpeed=G(G(Pca,"PlayerAnimationManager"),"baseMoveSpeed"),material=Ptr(material),baseColor=material.HasProperty(colorId)?ColorValues(material.GetColor(colorId)):null,bones=bones.Select(c=>{var target=(Transform)G(c,"target");return new{pointer=Ptr(c),transform=Ptr(c.transform),scale=V(c.transform.localScale),target=Ptr(target),targetScale=V(target.localScale)};}).ToArray(),hair=hair.Select(c=>new{pointer=Ptr(c),initialized=G(c,"isInitialized"),type=G(c,"HairType").ToString()}).ToArray()};
 }
 float next;string phase="idle",name;int began;object[] globals;object oldSlot;int oldHeight;bool oldStop;
 void Dispatch(){var player=Player;var method=player.GetType().GetMethods(Flags).Single(m=>m.Name.Contains("Initialize")&&m.Name.Contains("30_0"));Log("dispatch",new{name,method=method.Name,player=Ptr(player)});method.Invoke(player,Array.Empty<object>());}
 void RestoreData(){if(globals==null)return;for(int i=0;i<GlobalNames.Length;i++)S(typeof(GameState),GlobalNames[i],globals[i]);S(Custom,"CustomizeHeight",oldHeight);S(typeof(SaveManager),"CurrentSaveSlot",oldSlot);}
 public void Update(){if(Time.realtimeSinceStartup<next)return;next=Time.realtimeSinceStartup+.05f;var path=Path.Combine(AppearancePlugin.Root,"command");if(!File.Exists(path))return;var action=File.ReadAllText(path).Trim();File.Move(path,path+"-"+Time.frameCount);try{Handle(action);}catch(Exception e){Log("runner_error",new{action,phase,error=e.ToString()});RestoreData();phase="failed";}}
 void Handle(string action){Log("command",new{action,phase,scene=SceneManager.GetActiveScene().name});
  if(action=="boot"){M(Find(T("TitleSceneView")),"OnClickContinue");return;}
  if(action=="continue"){M(typeof(SaveManager),"Load",3,1);S(typeof(SaveManager),"CurrentSaveSlot",1);M(Find(T("SaveDataSelectPanelView")),"TransScene");return;}
  if(action=="prepare"){
   if(globals!=null||SceneManager.GetActiveScene().name!="Apartment")throw new Exception("fresh Apartment required");globals=GlobalNames.Select(n=>G(typeof(GameState),n)).ToArray();oldSlot=G(typeof(SaveManager),"CurrentSaveSlot");oldHeight=(int)G(Custom,"CustomizeHeight");oldStop=(bool)G(Temp,"IsStopGameStateApplier");S(Temp,"IsStopGameStateApplier",true);Log("prepared",Snapshot());return;
  }
  if(action.StartsWith("case ")){
   if(globals==null||phase!="idle")throw new Exception("prepare/idle required");int height=int.Parse(action.Substring(5));if(!new[]{120,160,200}.Contains(height))throw new Exception("unsupported fixture height");RestoreData();S(typeof(SaveManager),"CurrentSaveSlot",1);S(Custom,"CustomizeHeight",height);name="height-"+height;OutputDebugStringW("REA_APPEARANCE_BEGIN:"+name);Log("case_begin",new{name,height,snapshot=Snapshot()});
   M(typeof(SaveManager),"Save",3,1,false);var directory=Path.Combine(AppearancePlugin.Root,"captures");Directory.CreateDirectory(directory);File.Copy(Path.Combine(AppearancePlugin.Root,"working-profile","SaveData","1.sd"),Path.Combine(directory,name+".sd"),true);Log("saved",new{name,height});
   S(Custom,"CustomizeHeight",137);Log("disturbed",new{name,height=G(Custom,"CustomizeHeight")});M(typeof(SaveManager),"Load",3,1);Log("loaded",new{name,snapshot=Snapshot()});Dispatch();Log("immediate",new{name,snapshot=Snapshot()});began=Time.frameCount;phase="sampling";return;
  }
  if(action=="cleanup"){
   if(phase!="idle")throw new Exception("case still pending");name="cleanup";OutputDebugStringW("REA_APPEARANCE_BEGIN:"+name);RestoreData();Dispatch();began=Time.frameCount;phase="cleanup-wait";
  }
 }
 public void LateUpdate(){if(phase!="sampling"&&phase!="cleanup-wait")return;try{int age=Time.frameCount-began;if(age==1||age==2)Log("sample",new{name,age,snapshot=Snapshot()});if(age<5)return;
  if(phase=="sampling"){Log("result",new{name,age,snapshot=Snapshot()});OutputDebugStringW("REA_APPEARANCE_END:"+name);phase="idle";}
  else{S(Temp,"IsStopGameStateApplier",oldStop);Log("cleanup",new{age,stop=G(Temp,"IsStopGameStateApplier"),rootsRestored=GlobalNames.Select((n,i)=>Ptr(G(typeof(GameState),n))==Ptr(globals[i])).All(x=>x),snapshot=Snapshot()});OutputDebugStringW("REA_APPEARANCE_END:"+name);phase="done";}
 }catch(Exception e){Log("runner_error",new{phase,error=e.ToString()});RestoreData();phase="failed";}}
}
}
