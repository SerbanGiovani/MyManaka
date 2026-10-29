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
namespace REAAppearanceHair {
[BepInPlugin("rea.appearance.hair","REA Appearance Hair","1.0.0")]
[BepInDependency("rea.natural.observer")]
public class AppearancePlugin:BasePlugin {
 public static string Root;
 public override void Load(){Root=Path.Combine(Paths.GameRootPath,"AppearanceHair","20261030-1");var observer=AppDomain.CurrentDomain.GetAssemblies().Select(a=>a.GetType("Plugin")).First(t=>t?.GetField("SaveRoot")!=null);observer.GetField("SaveRoot").SetValue(null,Path.Combine(Root,"working-profile"));((StreamWriter)observer.GetField("Output").GetValue(null)).Flush();observer.GetField("Output").SetValue(null,new StreamWriter(Path.Combine(Root,"paths.jsonl"),true));Application.SetStackTraceLogType(LogType.Error,StackTraceLogType.Full);Application.SetStackTraceLogType(LogType.Exception,StackTraceLogType.Full);ClassInjector.RegisterTypeInIl2Cpp<Runner>();AddComponent<Runner>();}
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


 static readonly string[] HairFields={"HairType","TextureId","R","G","B","ShadeColor"};
 static object HairDict=>G(Custom,"HairCustomizeDataDict");
 object[] savedRoots;object oldSlot;object oldHairType;bool oldStop;object[][] oldData;
 System.Collections.Generic.Dictionary<int,object> masters;
 int[] ids;float next;new string name;string phase="idle";int began;
 static int Id(object v)=>Convert.ToInt32(v);
 static int AnyCount(object o){var p=K(o).GetProperty("Count",Flags)??K(o).GetProperty("Length",Flags);return (int)p.GetValue(o);}
 static object[] Items(object o)=>Enumerable.Range(0,AnyCount(o)).Select(i=>At(o,i)).ToArray();
 ExposureUnnoticed2.Object3D.Player.Scripts.Other.HairCustomAdjuster[] Hairs()=>UnityEngine.Object.FindObjectsOfType<ExposureUnnoticed2.Object3D.Player.Scripts.Other.HairCustomAdjuster>(true).Where(c=>c.transform.IsChildOf(((Component)Player).transform)).ToArray();
 object HairData(int id)=>M(HairDict,"get_Item",id);
 object Record(object d)=>new{pointer=Ptr(d),hair=Id(G(d,"HairType")),texture=G(d,"TextureId"),rgb=new[]{(int)G(d,"R"),(int)G(d,"G"),(int)G(d,"B")},shade=G(d,"ShadeColor")};
 object Snapshot(){
  var arr=G(G(Pca,"PlayerAvatarObjectReferencer"),"Hairs");
  return new{custom=Ptr(Custom),current=Id(G(Custom,"CurrentHair")),data=ids.Select(i=>Record(HairData(i))).ToArray(),objects=Items(arr).Select((o,i)=>{var g=(GameObject)o;return new{id=i,pointer=Ptr(g),active=g.activeSelf};}).ToArray(),receivers=Hairs().Select(h=>{bool init=(bool)G(h,"isInitialized");var mat=init?(Material)G(h,"targetMaterial"):null;var rec=init?G(h,"record"):null;var tx=rec==null?null:G(rec,"HairTextures");return new{pointer=Ptr(h),hair=Id(G(h,"HairType")),initialized=init,material=Ptr(mat),color=mat?ColorValues(mat.GetColor((int)G(h,"BaseColor"))):null,shade=mat?ColorValues(mat.GetColor((int)G(h,"FirstShadeColor"))):null,texture=mat?Ptr(mat.GetTexture((int)G(h,"MainTex"))):null,available=tx==null?null:Items(tx).Select(Ptr).ToArray()};}).ToArray()};
 }
 void BeginMarker(string stage){OutputDebugStringW("REA_HAIR_BEGIN:"+name+"/"+stage);}
 void EndMarker(){OutputDebugStringW("REA_HAIR_END:");}
 void Dispatch(){var m=Player.GetType().GetMethods(Flags).Single(x=>x.Name.Contains("Initialize")&&x.Name.Contains("30_0"));m.Invoke(Player,Array.Empty<object>());}
 int ActualHair(){var arr=G(G(Pca,"PlayerAvatarObjectReferencer"),"Hairs");return Items(arr).Select((o,i)=>new{g=(GameObject)o,id=i}).Single(x=>x.g.activeSelf).id;}
 void Select(int id){M(G(Pca,"PlayerHairController"),"ChangeHair",id);}
 void Configure(bool disturbed){int target=name=="alternate-hair"?ids[1]:ids[0];var data=HairData(target);int[] rgb=name=="positive-shade"?new[]{210,60,100}:new[]{32,96,224};for(int i=0;i<3;i++)S(data,new[]{"R","G","B"}[i],disturbed?70:rgb[i]);S(data,"ShadeColor",disturbed?0:name=="positive-shade"?100:name=="alternate-hair"?-35:-100);var textures=G(masters[target],"HairTextures");S(data,"TextureId",disturbed?0:Math.Min(1,AnyCount(textures)-1));}
 void RestoreData(){if(savedRoots==null)return;for(int i=0;i<GlobalNames.Length;i++)S(typeof(GameState),GlobalNames[i],savedRoots[i]);foreach(var row in oldData)for(int j=0;j<HairFields.Length;j++)S(row[0],HairFields[j],row[j+1]);S(Custom,"CurrentHair",oldHairType);S(typeof(SaveManager),"CurrentSaveSlot",oldSlot);}
 public void Update(){if(Time.realtimeSinceStartup<next)return;next=Time.realtimeSinceStartup+.05f;var path=Path.Combine(AppearancePlugin.Root,"command");if(!File.Exists(path))return;var action=File.ReadAllText(path).Trim();File.Move(path,path+"-"+Time.frameCount);try{Handle(action);}catch(Exception e){Log("runner_error",new{action,phase,error=e.ToString()});RestoreData();EndMarker();phase="failed";}}
 void Handle(string action){Log("command",new{action,phase,scene=SceneManager.GetActiveScene().name});
  if(action=="boot"){M(Find(T("TitleSceneView")),"OnClickContinue");return;}
  if(action=="continue"){M(typeof(SaveManager),"Load",3,1);S(typeof(SaveManager),"CurrentSaveSlot",1);M(Find(T("SaveDataSelectPanelView")),"TransScene");return;}
  if(action=="prepare"){
   if(savedRoots!=null||SceneManager.GetActiveScene().name!="Apartment")throw new Exception("fresh Apartment required");savedRoots=GlobalNames.Select(n=>G(typeof(GameState),n)).ToArray();oldSlot=G(typeof(SaveManager),"CurrentSaveSlot");oldHairType=G(Custom,"CurrentHair");oldStop=(bool)G(Temp,"IsStopGameStateApplier");S(Temp,"IsStopGameStateApplier",true);
   masters=Items(M(T("MHair"),"GetAll")).ToDictionary(o=>Id(G(o,"Type")),o=>o);int first=Id(oldHairType);int second=masters.Keys.First(i=>i!=first&&i>=0&&(bool)M(HairDict,"ContainsKey",i)&&Hairs().Any(h=>Id(G(h,"HairType"))==i));ids=new[]{first,second};oldData=ids.Select(i=>{var d=HairData(i);return new[]{d}.Concat(HairFields.Select(f=>G(d,f))).ToArray();}).ToArray();Log("prepared",Snapshot());return;
  }
  if(action.StartsWith("case ")){
   if(savedRoots==null||phase!="idle")throw new Exception("prepare/idle required");RestoreData();name=action.Substring(5);if(!new[]{"negative-shade","positive-shade","alternate-hair"}.Contains(name))throw new Exception("fixture name");Configure(false);BeginMarker("reference");Select(name=="alternate-hair"?ids[1]:ids[0]);Dispatch();Log("reference_immediate",new{name,snapshot=Snapshot()});began=Time.frameCount;phase="reference";return;
  }
  if(action=="cleanup"){
   if(phase!="idle"&&phase!="failed")throw new Exception("pending case");name="cleanup";int actual=ActualHair();RestoreData();BeginMarker("restore");S(Custom,"CurrentHair",actual);Select(Id(oldHairType));Dispatch();began=Time.frameCount;phase="cleanup";
  }
 }
 public void LateUpdate(){if(!new[]{"reference","disturb","warm","restore","cleanup"}.Contains(phase)||Time.frameCount-began<10)return;try{
  if(phase=="reference"){
   Log("reference_result",new{name,snapshot=Snapshot()});M(typeof(SaveManager),"Save",3,1,false);var captures=Path.Combine(AppearancePlugin.Root,"captures");Directory.CreateDirectory(captures);File.Copy(Path.Combine(AppearancePlugin.Root,"working-profile/SaveData/1.sd"),Path.Combine(captures,name+".sd"),false);Log("saved",new{name});EndMarker();
   Configure(true);BeginMarker("disturb");Select(name=="alternate-hair"?ids[0]:ids[1]);Dispatch();Log("disturbed_immediate",new{name,snapshot=Snapshot()});began=Time.frameCount;phase="disturb";return;
  }
  if(phase=="disturb"){
   Log("disturbed_result",new{name,snapshot=Snapshot()});EndMarker();BeginMarker("warm");M(typeof(SaveManager),"Load",3,1);Log("loaded",new{name,snapshot=Snapshot()});M(G(Pca,"PlayerHairController"),"Initialize",Pca);Dispatch();Log("warm_immediate",new{name,snapshot=Snapshot()});began=Time.frameCount;phase="warm";return;
  }
  if(phase=="warm"){Log("warm_result",new{name,snapshot=Snapshot()});EndMarker();BeginMarker("reconciled");int desired=Id(G(Custom,"CurrentHair")),actual=ActualHair();Log("reconciliation",new{name,desired,actual,scope="controlled saved-current field coordination to actual active model before original ChangeHair; not natural load"});S(Custom,"CurrentHair",actual);Select(desired);Dispatch();Log("restore_immediate",new{name,snapshot=Snapshot()});began=Time.frameCount;phase="restore";return;}
  if(phase=="restore"){Log("result",new{name,snapshot=Snapshot()});EndMarker();phase="idle";return;}
  S(Temp,"IsStopGameStateApplier",oldStop);Log("cleanup",new{rootsRestored=GlobalNames.Select((n,i)=>Ptr(G(typeof(GameState),n))==Ptr(savedRoots[i])).All(x=>x),stop=G(Temp,"IsStopGameStateApplier"),snapshot=Snapshot()});EndMarker();phase="done";
 }catch(Exception e){Log("runner_error",new{phase,error=e.ToString()});RestoreData();EndMarker();phase="failed";}}
}
}
