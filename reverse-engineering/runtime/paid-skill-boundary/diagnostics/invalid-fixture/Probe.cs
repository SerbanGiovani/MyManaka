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
namespace REAPaidSkillBoundary {
[BepInPlugin("rea.paid.skill.boundary","REA Paid Skill Boundary","1.0.0")]
[BepInDependency("rea.natural.observer")]
public class PaidSkillPlugin:BasePlugin {
 public static string Root;
 public override void Load(){Root=Path.Combine(Paths.GameRootPath,"PaidSkillBoundary","20261030-2");Directory.CreateDirectory(Root);if(!Directory.Exists(Path.Combine(Root,"working-profile")))throw new DirectoryNotFoundException("Prepare a disposable working-profile before installing this probe");var observer=AppDomain.CurrentDomain.GetAssemblies().Select(a=>a.GetType("Plugin")).First(t=>t?.GetField("SaveRoot")!=null);observer.GetField("SaveRoot").SetValue(null,Path.Combine(Root,"working-profile"));((StreamWriter)observer.GetField("Output").GetValue(null)).Flush();observer.GetField("Output").SetValue(null,new StreamWriter(Path.Combine(Root,"paths.jsonl"),true));Application.SetStackTraceLogType(LogType.Error,StackTraceLogType.Full);Application.SetStackTraceLogType(LogType.Exception,StackTraceLogType.Full);ClassInjector.RegisterTypeInIl2Cpp<Runner>();AddComponent<Runner>();}
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
 static void Log(string kind,object data=null){File.AppendAllText(Path.Combine(PaidSkillPlugin.Root,"managed.jsonl"),JsonSerializer.Serialize(new{kind,frame=Time.frameCount,real=Time.realtimeSinceStartup,data})+"\n");}
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

 static readonly int[] Skills={6,7,9,11,17};
 static readonly string[] BuffFields={"SourceName","BuffSourceType","SpecialType","RpBonus100","RpBonusLastMult100","Strange100","Dokidoki100","IsActive","ItemIdParseInt"};
 static readonly string[] PlayerFields={"RpBonus","RpBonusInt","MiscRpBonus"};
 static readonly string[] CalculatorFields={"pathCalcTime","lastClothesRpBonus","currentStageType"};
 object[] roots,oldPlayerFields,oldCalculatorFields;object[][] oldBuffFields;
 object oldSlot,oldRank,panel;bool oldStop;new string name="idle";string phase="idle",afterClose;int target,began;float next,closeReal;bool studyActive;
 static int Id(object o)=>Convert.ToInt32(o);
 static object[] Items(object o){var values=K(o).GetProperty("Values",Flags);if(values!=null){var e=M(values.GetValue(o),"GetEnumerator");var list=new System.Collections.Generic.List<object>();while((bool)M(e,"MoveNext"))list.Add(G(e,"Current"));return list.ToArray();}var n=K(o).GetProperty("Count",Flags)??K(o).GetProperty("Length",Flags);return Enumerable.Range(0,(int)n.GetValue(o)).Select(i=>At(o,i)).ToArray();}
 static bool Same(object a,object b)=>a is Il2CppObjectBase||b is Il2CppObjectBase?Ptr(a)==Ptr(b):Equals(a,b);
 static object PlayerState=>G(Pca,"PlayerState");
 static object Calculator=>G(Pca,"PlayerRpBonusCalculator");
 static object Passive=>G(State,"PlayerPassiveSkillActiveDict");
 static int Level(int i)=>Id(M(G(State,"SkillLevel"),"get_Item",i));
 static bool HasPassive(int i)=>(bool)M(Passive,"ContainsKey",i);
 static bool Active(int i)=>(bool)M(T("GameStateFacade"),"IsActivePassiveSkill",i);
 static void Level(int i,int value)=>M(G(State,"SkillLevel"),"set_Item",i,value);
 static object CapacityRecord()=>M(T("MSkillMaxAccessoryNum"),"Get",Level(11));
 static object Capacity()=>new{level=Level(11),max=G(CapacityRecord(),"MaxNum"),nextRp=G(CapacityRecord(),"NextLevelUpRp")};
 static object Buff(){var dict=G(PlayerState,"OtherBuffDict");if(!(bool)M(dict,"ContainsKey",33))return null;var b=M(dict,"get_Item",33);return new{pointer=Ptr(b),active=G(b,"IsActive"),flat=G(b,"RpBonus100"),lastMultiplier=G(b,"RpBonusLastMult100")};}
 static object Snapshot()=>new{state=Ptr(State),rank=G(G(PlayerState,"CurrentRank"),"Rank"),rp=G(State,"CurrentRp"),usedRp=G(State,"StatistisTotalUseRp"),skills=Skills.Select(i=>new{id=i,level=Level(i),present=HasPassive(i),stored=HasPassive(i)?(bool?)M(Passive,"get_Item",i):null,effective=Active(i)}).ToArray(),capacity=Capacity(),npcDirectBuff=Buff(),rpBonus=G(PlayerState,"RpBonus"),rpBonusInt=G(PlayerState,"RpBonusInt")};
 static object View(object view)=>new{pointer=Ptr(view),active=((Component)view).gameObject.activeInHierarchy,id=Id(G(G(view,"skill"),"Type")),price=G(view,"necessaryRp"),masked=G(view,"isSomeMask"),max=G(view,"isLearned"),button=((GameObject)G(view,"reinforceButtonObject")).activeInHierarchy,hasParentCallback=G(view,"onClickReinforce")!=null,parentCallback=Ptr(G(view,"onClickReinforce"))};
 object SkillView(int id)=>Items(G(panel,"childViewList")).Single(v=>Id(G(G(v,"skill"),"Type"))==id);
 void Step(string kind,object data=null)=>Log(kind,new{name,phase,data});
 void Begin(string value){name=value;OutputDebugStringW("REA_PAID_BEGIN:"+name);}
 void End(){OutputDebugStringW("REA_PAID_END:");name="idle";}
 void Calculate(){OutputDebugStringW("REA_PAID_CALCULATE_BEGIN:");try{M(Calculator,"OnUpdate");}finally{OutputDebugStringW("REA_PAID_CALCULATE_END:");}}
 void SaveCapture(string suffix){M(typeof(SaveManager),"Save",3,1,false);File.Copy(Path.Combine(PaidSkillPlugin.Root,"working-profile/SaveData/1.sd"),Path.Combine(PaidSkillPlugin.Root,"captures",name+"-"+suffix+".sd"),false);}
 void Restore(){if(roots==null)return;for(int i=0;i<GlobalNames.Length;i++)S(typeof(GameState),GlobalNames[i],roots[i]);S(typeof(SaveManager),"CurrentSaveSlot",oldSlot);S(PlayerState,"CurrentRank",oldRank);if(oldBuffFields!=null)foreach(var row in oldBuffFields)for(int i=0;i<BuffFields.Length;i++)S(row[0],BuffFields[i],row[i+1]);if(oldPlayerFields!=null)for(int i=0;i<PlayerFields.Length;i++)S(PlayerState,PlayerFields[i],oldPlayerFields[i]);if(oldCalculatorFields!=null)for(int i=0;i<CalculatorFields.Length;i++)S(Calculator,CalculatorFields[i],oldCalculatorFields[i]);S(Temp,"IsStopGameStateApplier",oldStop);}
 void OpenStudy(string nextPhase){M(T("SkillPanelView"),"Open",(object)null);panel=Find(T("SkillPanelView"));if(panel==null)throw new Exception("native SkillPanelView not found");M(panel,"OnClickTab",0);began=Time.frameCount;phase=nextPhase;}
 void ClosePanel(string nextPhase,bool study){if(panel==null)throw new Exception("no panel to close");if(study)M(panel,"OnClickBack");else M(panel,"Close");began=Time.frameCount;closeReal=Time.realtimeSinceStartup;afterClose=nextPhase;phase="closing";}
 void Configure(string value){
  if(roots==null||phase!="idle")throw new Exception("prepare/idle required");
  if(!new[]{"rp-low","rp-exact","max","rank-locked","prerequisite","passive-absent","passive-false"}.Contains(value))throw new Exception("unknown case");
  File.Copy(Path.Combine(PaidSkillPlugin.Root,"baseline.sd"),Path.Combine(PaidSkillPlugin.Root,"working-profile/SaveData/1.sd"),true);M(typeof(SaveManager),"Load",3,1);S(PlayerState,"CurrentRank",oldRank);S(Temp,"IsStopGameStateApplier",true);Begin(value);
  target=value.StartsWith("passive")?7:value=="prerequisite"?9:value=="rank-locked"?17:11;
  if(target==11){Level(11,value=="max"?3:0);S(State,"CurrentRp",value=="rp-low"?299d:value=="rp-exact"?300d:2000d);}
  if(value=="rank-locked"){Level(17,0);S(State,"CurrentRp",1000d);}
  if(value=="prerequisite"){Level(6,0);Level(9,0);M(Passive,"Remove",9);S(State,"CurrentRp",250d);}
  if(target==7){Level(7,0);M(Passive,"Remove",7);if(value=="passive-false")M(Passive,"set_Item",7,false);S(State,"CurrentRp",100d);}
  Calculate();Step("configured",Snapshot());SaveCapture("before");OpenStudy("study-ready");
 }
 void SaveLoadProof(){
  Calculate();Step("post_use",Snapshot());SaveCapture("after");
  foreach(var id in Skills)Level(id,Level(id)==0?1:0);S(State,"CurrentRp",7777d);M(Passive,"set_Item",7,!Active(7));Calculate();Step("disturbed",Snapshot());
  M(typeof(SaveManager),"Load",3,1);Calculate();Step("loaded",Snapshot());OpenStudy("verify-ready");
 }
 public void Update(){if(Time.realtimeSinceStartup<next)return;next=Time.realtimeSinceStartup+.05f;var path=Path.Combine(PaidSkillPlugin.Root,"command");if(!File.Exists(path))return;var action=File.ReadAllText(path).Trim();File.Move(path,path+"-"+Time.frameCount);try{Handle(action);}catch(Exception e){Log("runner_error",new{action,name,phase,error=e.ToString()});phase="failed";End();}}
 void Handle(string action){Log("command",new{action,name,phase,scene=SceneManager.GetActiveScene().name});
  if(action=="ready"){var a=G(T("AssetReferencer"),"Instance");var hair=a==null?null:G(a,"MHair");var skills=a==null?null:G(a,"MSkill");var view=a==null?null:G(a,"SkillPanel");Log("readiness",new{ready=a!=null&&hair!=null&&skills!=null&&view!=null,assets=Ptr(a),hair=Ptr(hair),skills=Ptr(skills),panel=Ptr(view),scene=SceneManager.GetActiveScene().name});return;}
  if(action=="boot"){M(Find(T("TitleSceneView")),"OnClickContinue");return;}
  if(action=="continue"){M(typeof(SaveManager),"Load",3,1);S(typeof(SaveManager),"CurrentSaveSlot",1);M(Find(T("SaveDataSelectPanelView")),"TransScene");return;}
  if(action=="prepare"){
   if(roots!=null||SceneManager.GetActiveScene().name!="Apartment"||Player==null)throw new Exception("fresh initialized Apartment required");
   roots=GlobalNames.Select(n=>G(typeof(GameState),n)).ToArray();oldSlot=G(typeof(SaveManager),"CurrentSaveSlot");oldRank=G(PlayerState,"CurrentRank");oldStop=(bool)G(Temp,"IsStopGameStateApplier");oldPlayerFields=PlayerFields.Select(f=>G(PlayerState,f)).ToArray();oldCalculatorFields=CalculatorFields.Select(f=>G(Calculator,f)).ToArray();oldBuffFields=Items(G(PlayerState,"OtherBuffDict")).Select(o=>new[]{o}.Concat(BuffFields.Select(f=>G(o,f))).ToArray()).ToArray();S(Temp,"IsStopGameStateApplier",true);
   Directory.CreateDirectory(Path.Combine(PaidSkillPlugin.Root,"captures"));M(typeof(SaveManager),"Save",3,1,false);File.Copy(Path.Combine(PaidSkillPlugin.Root,"working-profile/SaveData/1.sd"),Path.Combine(PaidSkillPlugin.Root,"baseline.sd"),false);var previous=Ptr(State);M(typeof(SaveManager),"Load",3,1);if(previous==Ptr(State))throw new Exception("Load did not detach global data before fixtures");Log("prepared",new{previous,state=Ptr(State),oldRank=Ptr(oldRank),rank=G(oldRank,"Rank"),otherBuffs=oldBuffFields.Length,scope="controlled real UI callbacks; no keyboard or natural unlock claim"});return;
  }
  if(action.StartsWith("case ")){Configure(action.Substring(5));return;}
  if(action=="cleanup"){if(phase!="idle"&&phase!="failed")throw new Exception("pending case");Restore();Log("cleanup",new{rootsRestored=GlobalNames.Select((n,i)=>Same(G(typeof(GameState),n),roots[i])).All(x=>x),rankRestored=Same(G(PlayerState,"CurrentRank"),oldRank),playerFieldsRestored=PlayerFields.Select((n,i)=>Same(G(PlayerState,n),oldPlayerFields[i])).All(x=>x),calculatorFieldsRestored=CalculatorFields.Select((n,i)=>Same(G(Calculator,n),oldCalculatorFields[i])).All(x=>x),buffFieldsRestored=oldBuffFields.Select(row=>BuffFields.Select((f,i)=>Same(G(row[0],f),row[i+1])).All(x=>x)).All(x=>x),stop=G(Temp,"IsStopGameStateApplier")});return;}
  throw new Exception("unknown command");
 }
 public void LateUpdate(){try{
  if(phase=="study-ready"&&Time.frameCount-began>=5){
   var view=SkillView(target);Step("view_before",View(view));
   if(name=="prerequisite"){
    M(view,"OnClickReinforce");Step("prerequisite_rejected",new{view=View(view),snapshot=Snapshot()});var slow=SkillView(6);Step("slow_before",View(slow));M(slow,"OnClickReinforce");Step("slow_bought",new{view=View(slow),auto=View(SkillView(9)),snapshot=Snapshot()});M(SkillView(9),"OnClickReinforce");Step("auto_bought",new{view=View(SkillView(9)),snapshot=Snapshot()});
   }else{M(view,"OnClickReinforce");Step("clicked",new{view=View(view),snapshot=Snapshot()});}
   Calculate();Step("consumer_after_click",Snapshot());studyActive=Active(7);ClosePanel(target==7?"open-switch":target==11?"open-capacity":"save-proof",true);return;
  }
  if(phase=="closing"&&Time.frameCount-began>=30&&Time.realtimeSinceStartup-closeReal>=1.5f){panel=null;var nextPhase=afterClose;phase=nextPhase;
   if(nextPhase=="open-switch"){M(T("SkillSwitchPanelView"),"Open");panel=Find(T("SkillSwitchPanelView"));if(panel==null)throw new Exception("native skill switch panel missing");began=Time.frameCount;phase="switch-ready";return;}
   if(nextPhase=="open-capacity"){M(T("InventoryPanelView"),"Open",null,0);panel=G(T("InventoryPanelView"),"Instance");began=Time.frameCount;phase="capacity-ready";return;}
   if(nextPhase=="save-proof"){SaveLoadProof();return;}
   if(nextPhase=="complete"){Step("case_result",Snapshot());End();phase="idle";return;}
   throw new Exception("unknown after-close phase");
  }
  if(phase=="capacity-ready"&&Time.frameCount-began>=5){M(panel,"RefreshEquipCount");var actual=M(panel,"CalcEquipCount");var can=M(panel,"CanEquipByMaxCount");Step("capacity_ui",new{panel=Ptr(panel),active=((Component)panel).gameObject.activeInHierarchy,actual,canEquip=can,text=G(G(panel,"equipCountText"),"text"),capacity=Capacity()});M(panel,"OnClickBack");began=Time.frameCount;closeReal=Time.realtimeSinceStartup;afterClose="save-proof";phase="closing";return;}
  if(phase=="switch-ready"&&Time.frameCount-began>=5){var v=Items(G(panel,"itemList")).Single(o=>Id(G(G(o,"record"),"Type"))==7);var toggle=G(v,"toggle");Step("toggle_reference",new{view=Ptr(v),active=((Component)v).gameObject.activeInHierarchy,stored=G(toggle,"isOn"),snapshot=Snapshot()});
   M(toggle,"SetIsOnWithoutNotify",false);M(v,"OnChangeToggle");Calculate();Step("toggle_off",Snapshot());M(toggle,"SetIsOnWithoutNotify",true);M(v,"OnChangeToggle");Calculate();Step("toggle_on",Snapshot());
   if(!studyActive){M(toggle,"SetIsOnWithoutNotify",false);M(v,"OnChangeToggle");Calculate();Step("toggle_restore_false",Snapshot());}ClosePanel("save-proof",false);return;}
  if(phase=="verify-ready"&&Time.frameCount-began>=5){var v=SkillView(target);M(v,"Refresh");M(v,"UpdateMask");Step("verified_ui",new{view=View(v),snapshot=Snapshot()});ClosePanel("complete",true);return;}
 }catch(Exception e){Log("runner_error",new{name,phase,error=e.ToString()});phase="failed";End();}}
}
}




