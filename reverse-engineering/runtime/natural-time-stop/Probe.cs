// Complete game bootstrap. Only save-path redirection; observation never sets gameplay state.
using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text.Json;
using BepInEx;
using BepInEx.Unity.IL2CPP;
using HarmonyLib;
using Il2CppInterop.Runtime.Injection;
using UnityEngine;
using UnityEngine.SceneManagement;
using ExposureUnnoticed2.Object3D.NPC.Script;
using ExposureUnnoticed2.Object3D.Player.Scripts;
using ExposureUnnoticed2.Scripts.InGame;
using ExposureUnnoticed2.Scripts.Base;
using Object=UnityEngine.Object;

[BepInPlugin("rea.natural.observer", "REA Natural Gameplay Observer", "1.0.0")]
public class Plugin:BasePlugin {
 public static StreamWriter Output;
 public static string SaveRoot;
 public new static void Log(string kind,object data=null){Output.WriteLine(JsonSerializer.Serialize(new{kind,frame=Time.frameCount,time=Time.time,real=Time.realtimeSinceStartup,data}));Output.Flush();}
 public static object Get(object o,string name){try{if(o==null)return null;var t=o as Type??o.GetType();var p=t.GetProperty(name)??t.GetProperty("_"+name+"_k__BackingField");return p?.GetValue(o is Type?null:o);}catch{return null;}}
 public static string Str(object o)=>o?.ToString();
 static bool Persistent(ref string __result){__result=SaveRoot;return false;}
 static bool NoBindingSave(){Log("binding_save_suppressed");return false;}
 static void SavePath(ref string __result){var before=__result;__result=Path.Combine(SaveRoot,before.Replace('/',Path.DirectorySeparatorChar));Log("save_path",new{before,after=__result});}
 public override void Load(){
  SaveRoot=Path.Combine(Paths.GameRootPath,"UserData");Directory.CreateDirectory(SaveRoot);
  Output=new StreamWriter(Path.Combine(Paths.GameRootPath,"natural.jsonl"),true);
  var h=new Harmony("rea.natural.save.isolation");
  h.Patch(AccessTools.PropertyGetter(typeof(Application),"persistentDataPath"),prefix:new HarmonyMethod(typeof(Plugin),nameof(Persistent)));
  foreach(var name in new[]{"GetSaveDataPath","GetSpecifiedSaveDataPath"})h.Patch(AccessTools.Method(typeof(SaveRapper),name),postfix:new HarmonyMethod(typeof(Plugin),nameof(SavePath)));
  h.Patch(AccessTools.Method(typeof(InputRebindSaveManager),"Save"),prefix:new HarmonyMethod(typeof(Plugin),nameof(NoBindingSave)));
  Application.SetStackTraceLogType(LogType.Exception,StackTraceLogType.Full);
  if(Application.persistentDataPath!=SaveRoot)throw new Exception("Save isolation failed");
  ClassInjector.RegisterTypeInIl2Cpp<Observer>();AddComponent<Observer>();
  Log("loaded",new{persistentDataPath=Application.persistentDataPath,unity=Application.unityVersion,scope="full bootstrap, original input/gameplay/animation; persistentDataPath redirected only"});
 }
}
public class Observer:MonoBehaviour{
 public Observer(IntPtr p):base(p){}
 float next;string scene;
 public void Update(){
  if(Time.realtimeSinceStartup<next)return;next=Time.realtimeSinceStartup+1;
  try{
   var s=SceneManager.GetActiveScene().name;if(s!=scene){scene=s;Plugin.Log("scene",new{name=s});}
   var npcs=Object.FindObjectsOfType<NpcAnimationEventReceiver>();
   var players=Object.FindObjectsOfType<PlayerController>();
   Plugin.Log("snapshot",new{scene=s,player=players.Select(p=>new{ptr=p.Pointer.ToString(),pos=p.transform.position.ToString(),action=Plugin.Str(Plugin.Get(Plugin.Get(p,"pca"),"Action"))}).ToArray(),npc=npcs.Select(n=>{
    var nca=Plugin.Get(n,"Nca")??Plugin.Get(n,"nca");var c=Plugin.Get(nca,"NpcController");var a=Plugin.Get(nca,"Animator") as Animator;
    return new{ptr=Plugin.Str(Plugin.Get(c,"Pointer")),receiver=n.Pointer.ToString(),pos=n.transform.position.ToString(),cache=Plugin.Str(Plugin.Get(c,"animatorSpeedCache")),speed=a?.speed,enabled=a?.enabled,display=Plugin.Str(Plugin.Get(c,"isDisplay"))};}).ToArray(),stop=Plugin.Get(Plugin.Get(Plugin.Get(typeof(InGameManager),"Instance"),"TempInGameState"),"IsTimeStop"),skill17=Skill(17),skill21=Skill(21),skill22=Skill(22)});
   if(File.Exists(Path.Combine(BepInEx.Paths.GameRootPath,"inspect"))){
    File.Move(Path.Combine(BepInEx.Paths.GameRootPath,"inspect"),Path.Combine(BepInEx.Paths.GameRootPath,"inspect-"+Time.frameCount));
    foreach(var p in players){var pca=Plugin.Get(p,"pca");Dump("player",p);Dump("pca",pca);}
    var es=UnityEngine.EventSystems.EventSystem.current;
    Plugin.Log("selected",new{name=es?.currentSelectedGameObject?.name});
    ScreenCapture.CaptureScreenshot(Path.Combine(BepInEx.Paths.GameRootPath,"capture-"+Time.frameCount+".png"));
    foreach(var c in Object.FindObjectsOfType<TMPro.TMP_Text>().Where(t=>t.gameObject.activeInHierarchy))Plugin.Log("ui_text",new{name=c.name,text=c.text});
   }
  }catch(Exception e){Plugin.Log("observer_error",new{error=e.ToString()});}
 }
 void Dump(string kind,object o){if(o==null)return;foreach(var p in o.GetType().GetProperties(BindingFlags.Public|BindingFlags.Instance).Where(p=>p.GetIndexParameters().Length==0))Plugin.Log("inspect",new{kind,property=p.Name,value=Plugin.Str(Plugin.Get(o,p.Name))});}
 object Skill(int id){try{var m=typeof(GameStateFacade).GetMethod("IsActivePassiveSkill");var t=m.GetParameters()[0].ParameterType;return m.Invoke(null,new[]{t.IsEnum?Enum.ToObject(t,id):(object)id});}catch{return null;}}
}
