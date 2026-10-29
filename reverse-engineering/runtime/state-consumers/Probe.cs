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
namespace REAStateConsumers {
[BepInPlugin("rea.state.consumers","REA State Consumers","1.0.0")]
[BepInDependency("rea.natural.observer")]
public class AppearancePlugin:BasePlugin {
 public static string Root;
 public override void Load(){Root=Path.Combine(Paths.GameRootPath,"StateConsumers","20261030-3");var observer=AppDomain.CurrentDomain.GetAssemblies().Select(a=>a.GetType("Plugin")).First(t=>t?.GetField("SaveRoot")!=null);observer.GetField("SaveRoot").SetValue(null,Path.Combine(Root,"working-profile"));((StreamWriter)observer.GetField("Output").GetValue(null)).Flush();observer.GetField("Output").SetValue(null,new StreamWriter(Path.Combine(Root,"paths.jsonl"),true));Application.SetStackTraceLogType(LogType.Error,StackTraceLogType.Full);Application.SetStackTraceLogType(LogType.Exception,StackTraceLogType.Full);ClassInjector.RegisterTypeInIl2Cpp<Runner>();AddComponent<Runner>();}
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



 object[] savedRoots;object oldSlot,oldRank;bool oldStop;string current="idle";int began;int itemId;string phase="idle";float next;
 static int Id(object v)=>Convert.ToInt32(v);
 static object[] Items(object o){var vals=K(o).GetProperty("Values",Flags);if(vals!=null){var e=M(vals.GetValue(o),"GetEnumerator");var list=new System.Collections.Generic.List<object>();while((bool)M(e,"MoveNext"))list.Add(G(e,"Current"));return list.ToArray();}var n=K(o).GetProperty("Count",Flags)??K(o).GetProperty("Length",Flags);return Enumerable.Range(0,(int)n.GetValue(o)).Select(i=>At(o,i)).ToArray();}
 static object Describe(object o)=>new{type=K(o).FullName,pointer=Ptr(o),fields=K(o).GetProperties(Flags).Where(p=>p.GetIndexParameters().Length==0).Select(p=>new{name=p.Name,type=p.PropertyType.FullName}).ToArray(),methods=K(o).GetMethods(Flags).Where(m=>!m.Name.StartsWith("get_")&&!m.Name.StartsWith("set_")).Select(m=>new{name=m.Name,args=m.GetParameters().Select(p=>new{name=p.Name,type=p.ParameterType.FullName}).ToArray()}).ToArray()};
 void Begin(string name){current=name;OutputDebugStringW("REA_CONSUMER_BEGIN:"+name);}
 void End(){OutputDebugStringW("REA_CONSUMER_END:");current="idle";}
 void Restore(){if(savedRoots==null)return;for(int i=0;i<GlobalNames.Length;i++)S(typeof(GameState),GlobalNames[i],savedRoots[i]);S(typeof(SaveManager),"CurrentSaveSlot",oldSlot);S(G(Pca,"PlayerState"),"CurrentRank",oldRank);}

 object InventoryState()=>new{state=Ptr(State),item=itemId,count=(bool)M(G(State,"ItemDict"),"ContainsKey",itemId)?M(G(State,"ItemDict"),"get_Item",itemId):0,exp=G(State,"ExposeExp"),rp=G(State,"CurrentRp"),rank=G(G(Pca,"PlayerState"),"CurrentRank")==null?null:G(G(G(Pca,"PlayerState"),"CurrentRank"),"Rank")};
 object SkillState()=>new{state=Ptr(State),level=M(G(State,"SkillLevel"),"get_Item",17),active=M(T("GameStateFacade"),"IsActivePassiveSkill",17),timeStop=G(Temp,"IsTimeStop"),action=Id(G(G(G(Pca,"PlayerState"),"CurrentAction"),"type")),rp=G(State,"CurrentRp")};
 void RequestTimeStop(){var input=Activator.CreateInstance(T("InputData"));S(input,"JustTimeStop",true);M(G(Pca,"PlayerAction"),"OnUpdate",input);}
 void SaveCapture(string name){M(typeof(SaveManager),"Save",3,1,false);File.Copy(Path.Combine(AppearancePlugin.Root,"working-profile/SaveData/1.sd"),Path.Combine(AppearancePlugin.Root,"captures",name+".sd"),false);}
 void Reset(){if(phase!="idle")throw new Exception("pending case");File.Copy(Path.Combine(AppearancePlugin.Root,"baseline.sd"),Path.Combine(AppearancePlugin.Root,"working-profile/SaveData/1.sd"),true);M(typeof(SaveManager),"Load",3,1);}
 public void LateUpdate(){try{
 if(phase=="inventory-ready"&&Time.frameCount-began>=5){var panel=G(T("InventoryPanelView"),"Instance");M(panel,"RefreshItemCategory");var views=Items(G(panel,"itemViewList"));var view=views.Single(o=>Id(G(G(o,"master"),"Type"))==itemId);Log("selected_ui",new{item=itemId,panel=Ptr(panel),view=Ptr(view),active=((Component)view).gameObject.activeInHierarchy,record=new{reusable=G(G(view,"master"),"IsReusable"),delayConsume=G(G(view,"master"),"IsDelayConsume")}});M(view,"OnClickUse");Log("used_immediate",InventoryState());began=Time.frameCount;phase="inventory-used";return;}
 if(phase=="inventory-used"&&Time.frameCount-began>=30){Log("used_result",InventoryState());SaveCapture("inventory-"+itemId+"-after");M(typeof(SaveManager),"Load",3,1);Log("post_load",InventoryState());M(G(T("InventoryPanelView"),"Instance"),"OnClickBack");Log("result",new{name=current,snapshot=InventoryState()});End();phase="idle";return;}
 if(phase=="skill-wait"&&Time.frameCount-began>=100){Log("skill_result",SkillState());if((bool)G(Temp,"IsTimeStop")){RequestTimeStop();Log("resume_requested",SkillState());began=Time.frameCount;phase="skill-resume";return;}Log("result",new{name=current,snapshot=SkillState()});End();phase="idle";return;}
 if(phase=="skill-resume"&&Time.frameCount-began>=100){Log("result",new{name=current,snapshot=SkillState()});End();phase="idle";return;}
 }catch(Exception e){Log("runner_error",new{phase,error=e.ToString()});phase="failed";End();}}
 object Inventory()=>Find(T("InventoryPanelView"));
 public void Update(){if(Time.realtimeSinceStartup<next)return;next=Time.realtimeSinceStartup+.05f;var path=Path.Combine(AppearancePlugin.Root,"command");if(!File.Exists(path))return;var action=File.ReadAllText(path).Trim();File.Move(path,path+"-"+Time.frameCount);try{Handle(action);}catch(Exception e){Log("runner_error",new{action,current,error=e.ToString()});End();}}
 void Handle(string action){Log("command",new{action,current,scene=SceneManager.GetActiveScene().name});
 if(action=="boot"){M(Find(T("TitleSceneView")),"OnClickContinue");return;}
 if(action=="continue"){M(typeof(SaveManager),"Load",3,1);S(typeof(SaveManager),"CurrentSaveSlot",1);M(Find(T("SaveDataSelectPanelView")),"TransScene");return;}
 if(action=="prepare"){
 if(savedRoots!=null||SceneManager.GetActiveScene().name!="Apartment")throw new Exception("fresh Apartment required");savedRoots=GlobalNames.Select(n=>G(typeof(GameState),n)).ToArray();oldSlot=G(typeof(SaveManager),"CurrentSaveSlot");oldRank=G(G(Pca,"PlayerState"),"CurrentRank");oldStop=(bool)G(Temp,"IsStopGameStateApplier");S(Temp,"IsStopGameStateApplier",true);Directory.CreateDirectory(Path.Combine(AppearancePlugin.Root,"captures"));M(typeof(SaveManager),"Save",3,1,false);File.Copy(Path.Combine(AppearancePlugin.Root,"working-profile/SaveData/1.sd"),Path.Combine(AppearancePlugin.Root,"baseline.sd"));M(typeof(SaveManager),"Load",3,1);Log("prepared",new{state=Ptr(State),savedRoots=GlobalNames.Select((n,i)=>new{name=n,pointer=Ptr(savedRoots[i])}).ToArray()});return;}

 if(action=="inspect"){
 foreach(var t in new[]{"InputData","PlayerStateModel","MMissionOverrideRecord","MMissionRecord"})Log("type",new{name=t,info=Describe(T(t))});
 foreach(var master in new[]{"MItem","MSkill"})Log("masters",new{master,records=Items(M(T(master),"GetAll")).Select(o=>new{type=K(o).FullName,values=K(o).GetProperties(Flags).Where(p=>p.GetIndexParameters().Length==0&&p.CanRead&&(p.PropertyType.IsValueType||p.PropertyType==typeof(string))).Select(p=>new{name=p.Name,value=p.GetValue(o)?.ToString()}).ToArray()}).ToArray()});
 Log("missions",Items(G(G(T("MissionManager"),"Instance"),"MissionList")).Select(o=>new{type=K(o).Name,id=G(o,"UniqueMissionId"),satisfy=G(o,"Satisfy"),missionType=G(o,"MissionType").ToString(),record=G(G(o,"RMission"),"Id"),stage=G(G(o,"RMission"),"StageType").ToString(),required=G(G(o,"RMission"),"ReleaseRank")}).ToArray());return;}
 if(action.StartsWith("inventory ")){
 itemId=int.Parse(action.Substring(10));Reset();Begin("inventory-"+itemId);var dict=G(State,"ItemDict");M(dict,"set_Item",itemId,2);S(State,"ExposeExp",0);Log("reference",InventoryState());SaveCapture("inventory-"+itemId+"-before");M(dict,"set_Item",itemId,9);S(State,"ExposeExp",7777);Log("disturbed",InventoryState());M(typeof(SaveManager),"Load",3,1);Log("loaded",InventoryState());M(T("InventoryPanelView"),"Open",null,1);began=Time.frameCount;phase="inventory-ready";return;}
 if(action.StartsWith("skill ")){
 var mode=action.Substring(6);Reset();Begin("skill-"+mode);M(G(State,"SkillLevel"),"set_Item",17,0);M(T("GameStateFacade"),"ChangeActivePassiveSkill",17,false);
 if(mode!="unlearned")M(T("GameStateFacade"),"RiseSkillLevel",17);if(mode=="enabled")M(T("GameStateFacade"),"ChangeActivePassiveSkill",17,true);else M(T("GameStateFacade"),"ChangeActivePassiveSkill",17,false);
 Log("reference",SkillState());SaveCapture("skill-"+mode+"-before");M(G(State,"SkillLevel"),"set_Item",17,7);M(T("GameStateFacade"),"ChangeActivePassiveSkill",17,mode!="enabled");Log("disturbed",SkillState());M(typeof(SaveManager),"Load",3,1);Log("loaded",SkillState());RequestTimeStop();Log("requested",SkillState());began=Time.frameCount;phase="skill-wait";return;}
 if(action=="cleanup"){Restore();S(Temp,"IsStopGameStateApplier",oldStop);Log("cleanup",new{rootsRestored=GlobalNames.Select((n,i)=>Ptr(G(typeof(GameState),n))==Ptr(savedRoots[i])).All(x=>x)});return;}
 throw new Exception("unknown command");
 }
}
}
