// Controlled Unity fixture. Does not enter the game's normal scene bootstrap.
using System;
using System.IO;
using System.Reflection;
using System.Linq;
using System.Text.Json;
using BepInEx;
using BepInEx.Unity.IL2CPP;
using HarmonyLib;
using Il2CppInterop.Runtime;
using Il2CppInterop.Runtime.Injection;
using Il2CppInterop.Runtime.InteropTypes;
using UnityEngine;
using ExposureUnnoticed2.Object3D.NPC.Script;
using ExposureUnnoticed2.Object3D.Player.Scripts;
using ExposureUnnoticed2.Scripts.Base;
using ExposureUnnoticed2.Scripts.InGame;
using ExposureUnnoticed2.Scripts.Sound;
using Common.Scripts.Util;
using Object = UnityEngine.Object;

[BepInPlugin("rea.npc.event.fixture", "REA NPC Event Fixture", "1.0.0")]
public class Plugin : BasePlugin
{
    public static StreamWriter Output;
    public static string Trial = "bootstrap";
    public static int EventCount, CallbackCount, BroadcastCount;
    public static Animator Animator;
    public static void Log(string kind, object data = null) {
        Output.WriteLine(JsonSerializer.Serialize(new { kind, trial=Trial, frame=Time.frameCount,
            time=Time.time, real=Time.realtimeSinceStartup, dt=Time.deltaTime, data })); Output.Flush();
    }
    public static T Alloc<T>() where T:Il2CppObjectBase => (T)Activator.CreateInstance(typeof(T), IL2CPP.il2cpp_object_new(Il2CppClassPointerStore<T>.NativeClassPtr));
    public static void Set(object obj, string name, object value) {
        var type=obj as Type ?? obj.GetType(); var flags=BindingFlags.Public|BindingFlags.NonPublic|BindingFlags.Instance|BindingFlags.Static;
        var p=type.GetProperty(name,flags);
        if(p?.SetMethod == null) p=type.GetProperty("_"+name+"_k__BackingField",flags);
        if(p?.SetMethod == null) throw new Exception("Missing setter "+type+"."+name);
        p.SetValue(obj is Type ? null:obj,value);
    }
    static bool Skip() => false;
    static bool False(ref bool __result) {__result=false; return false;}
    static bool NullClip(ref AudioClip __result) {__result=null; return false;}
    static void QueuePrefix(Il2CppSystem.Action action) {
        if(action?.Target?.TryCast<NpcAnimationEventReceiver>()==null)return;
        EventCount++; Log("animation_queue",new {eventCount=EventCount,normalized=Animator?.GetCurrentAnimatorStateInfo(4).normalizedTime});
    }
    public static void OnFound(FoundStrangerEvent evt) {CallbackCount++; BroadcastCount++; Log("broadcast_listener",new {broadcastCount=BroadcastCount,npc=evt.FoundNpc?.Pointer.ToString()});}
    public override void Load() {
        Output=new StreamWriter(Path.Combine(Paths.GameRootPath,"fixture.jsonl"),true);
        Application.SetStackTraceLogType(LogType.Exception,StackTraceLogType.Full);
        var h=new Harmony("rea.npc.event.fixture");
        // Suppress game bootstrap and normal gameplay callbacks; Scheduler remains native.
        int patched=0;
        foreach(var t in typeof(SystemManager).Assembly.GetTypes().Where(t=>t.IsSubclassOf(typeof(MonoBehaviour)) && t!=typeof(Scheduler)))
        foreach(var m in t.GetMethods(BindingFlags.Public|BindingFlags.NonPublic|BindingFlags.Instance|BindingFlags.DeclaredOnly).Where(m=>new[]{"Awake","Start","OnEnable","OnDisable","OnDestroy","OnApplicationQuit","Update","LateUpdate","FixedUpdate","OnAnimatorMove"}.Contains(m.Name) && m.ReturnType==typeof(void) && !m.IsGenericMethod)) {
            try {h.Patch(m,prefix:new HarmonyMethod(typeof(Plugin),nameof(Skip))); patched++;} catch(Exception e) {Log("patch_error",new {type=t.FullName, method=m.Name,error=e.Message});}
        }
        foreach(var m in typeof(SaveManager).GetMethods().Where(m=>m.Name=="Save"||m.Name=="SaveSystem")) h.Patch(m,prefix:new HarmonyMethod(typeof(Plugin),nameof(Skip)));
        foreach(var m in typeof(InGameSoundManager).GetMethods().Where(m=>m.DeclaringType==typeof(InGameSoundManager))) {
            if(m.Name=="IsFootSe" || m.Name=="IsGroupSe") h.Patch(m,prefix:new HarmonyMethod(typeof(Plugin),nameof(False)));
            if(m.Name=="GetSound") h.Patch(m,prefix:new HarmonyMethod(typeof(Plugin),nameof(NullClip)));
            if(m.Name=="PlayOneShotAudioData") h.Patch(m,prefix:new HarmonyMethod(typeof(Plugin),nameof(Skip)));
        }
        h.Patch(AccessTools.Method(typeof(Scheduler),"DelayScaledTime"),prefix:new HarmonyMethod(typeof(Plugin),nameof(QueuePrefix)));
        ClassInjector.RegisterTypeInIl2Cpp<Driver>(); AddComponent<Driver>();
        Log("loaded",new {patched, persistentDataPath=Application.persistentDataPath,unity=Application.unityVersion});
    }
}

public class Driver : MonoBehaviour
{
    public Driver(IntPtr p):base(p){}
    GameObject female,male,model,playerObject; Animator animator;
    NpcComponentAccessor nca; NpcAnimatorFpsController fps; NpcController npc;
    TemporaryInGameState temp; int index=-1,phase; float began, eventAt; bool initialized,stopped,switched;
    string[] scenarios={"near","far2","hidden_far2","hidden_near","near_far_before","far_near_before","near_far_after","hide_after","stop_before","stop_after","hidden_stop_after","far_stop_before","repeated_stop","repeated_stop_before","distance_flap"};
    int total => scenarios.Length*4;
    float Age => Time.realtimeSinceStartup-began;
    string Scenario => scenarios[index%scenarios.Length];
    void Setup() {
        QualitySettings.vSyncCount=0; Application.targetFrameRate=60; Application.runInBackground=true;
        foreach(var c in Object.FindObjectsOfType<Camera>()) c.enabled=false;
        var cam=new GameObject("FixtureCamera").AddComponent<Camera>(); cam.transform.position=new Vector3(0,1,-6); cam.transform.LookAt(new Vector3(0,1,0)); cam.farClipPlane=300;
        // Native NPC prefabs live in resources.assets, not the encrypted models bundle.
        var roots=UnityEngine.Resources.LoadAll<GameObject>("");
        var gos=UnityEngine.Resources.FindObjectsOfTypeAll<GameObject>();
        Plugin.Log("assets",new {roots=roots.Length,npcs=gos.Where(g=>g.name.StartsWith("Npc")).Select(g=>g.name).ToArray()});
        female=gos.First(g=>g.name=="NpcFemale_Assemble"); male=gos.First(g=>g.name=="NpcMale");
        var game=new GameObject("FixtureInGame").AddComponent<InGameManager>(); game.enabled=false;
        temp=new TemporaryInGameState(); Plugin.Set(game,"TempInGameState",temp); InGameManager.Instance=game;
        playerObject=new GameObject("FixturePlayer"); var player=playerObject.AddComponent<PlayerController>(); player.enabled=false;
        var pca=Plugin.Alloc<PlayerClassAccessor>(); Plugin.Set(pca,"GameObject",playerObject); player.pca=pca; PlayerController.Instance=player;
        SetSound();
        GameState.GameStateData=Plugin.Alloc<GameStateData>();
        // Empty event dictionaries are initialized by the original static constructor.
        EventManager.Clear(); EventManager.AddListener<FoundStrangerEvent>((Il2CppSystem.Action<FoundStrangerEvent>)Plugin.OnFound,false);
        var scheduler=Scheduler.Instance; scheduler.enabled=true;
        foreach(var m in Object.FindObjectsOfType<MonoBehaviour>()) if(m.Pointer!=Pointer && m.Pointer!=scheduler.Pointer)m.enabled=false;
        Plugin.Log("ready",new {scheduler=scheduler.Pointer.ToString(), female=female.name,male=male.name});
    }
    void SetSound() {var s=new GameObject("FixtureSound").AddComponent<InGameSoundManager>(); s.enabled=false; InGameSoundManager.Instance=s;}
    void Begin() {
        if(model!=null) Object.Destroy(model);
        index++; if(index>=total) {Plugin.Trial="complete"; Plugin.Log("complete"); Application.Quit(); enabled=false; return;}
        bool isFemale=(index/scenarios.Length)%2==0;
        Plugin.Trial="r"+(index/(scenarios.Length*2)+1)+"/"+(isFemale?"female/":"male/")+Scenario;
        Plugin.EventCount=Plugin.CallbackCount=Plugin.BroadcastCount=0; stopped=switched=false; phase=0; eventAt=-1;
        temp.IsTimeStop=false;
        model=Object.Instantiate(isFemale?female:male); model.name="FixtureNpc";
        animator=model.GetComponent<Animator>(); Plugin.Animator=animator; animator.enabled=true; animator.speed=1;
        var receiver=model.GetComponent<NpcAnimationEventReceiver>(); var avatar=model.GetComponent<NpcAvatarComponent>();
        nca=Plugin.Alloc<NpcComponentAccessor>(); npc=Plugin.Alloc<NpcController>();
        Plugin.Set(nca,"GameObject",model); Plugin.Set(nca,"Transform",model.transform); Plugin.Set(nca,"Animator",animator);
        Plugin.Set(nca,"NpcController",npc); Plugin.Set(nca,"AvatarComponent",avatar); Plugin.Set(nca,"StateModel",new NpcStateModel());
        var comp=model.AddComponent<NpcComponent>(); comp.DokinAudioSource=model.AddComponent<AudioSource>();
        Plugin.Set(nca,"AudioSource",model.AddComponent<AudioSource>()); Plugin.Set(nca,"NpcComponent",comp);
        var sound=Plugin.Alloc<NpcSoundController>(); sound.nca=nca; Plugin.Set(nca,"NpcSoundController",sound);
        Plugin.Set(npc,"Nca",nca); Plugin.Set(npc,"GameObject",model); Plugin.Set(npc,"Transform",model.transform);
        receiver.Initialize(nca); fps=new NpcAnimatorFpsController(); fps.Initialize(nca);
        animator.Rebind(); animator.SetBool("IsFemale",isFemale); animator.SetBool("IsSit",false); animator.SetBool("IsFoundStranger",false); animator.Update(0);
        began=Time.realtimeSinceStartup;
        Plugin.Log("begin",new {scenario=Scenario, sex=isFemale?"female":"male", receiver=receiver.Pointer.ToString(), npc=npc.Pointer.ToString(),culling=(int)animator.cullingMode, fireEvents=animator.fireEvents,mesh=avatar.MeshParent.name});
    }
    void Stop(bool value) {temp.IsTimeStop=value; npc.OnTimeStopEvent(Events.TimeStopEvent); stopped=value; Plugin.Log(value?"stop":"resume",new {speed=animator.speed, cache=npc.animatorSpeedCache});}
    public void Update() {try {
        // Attach REA Frida and create the go file before starting the scenarios.
        if(!initialized) {if(!File.Exists(Path.Combine(Paths.GameRootPath,"go")))return; Setup(); initialized=true; Begin();return;}
        if(index>=total)return;
        var scenario=Scenario; var age=Age;
        if(phase==0 && age>=0.25f) {animator.SetBool("IsFoundStranger",true); phase=1; Plugin.Log("found_parameter");}
        if(Plugin.EventCount>0 && eventAt<0) eventAt=age;
        if(!switched && scenario.EndsWith("before") && !scenario.Contains("stop") && age>=0.40f) {switched=true; Plugin.Log("distance_switch");}
        if(!switched && scenario.EndsWith("after") && !scenario.Contains("stop") && eventAt>=0) {switched=true; Plugin.Log("post_event_switch");}
        bool stopScenario=scenario.Contains("stop");
        if(stopScenario && phase==1 && ((scenario.EndsWith("before") && age>=0.40f) || (!scenario.EndsWith("before") && eventAt>=0))) {Stop(true); phase=2; eventAt=age;}
        if(scenario.StartsWith("repeated_stop") && phase==2 && age-eventAt>=0.25f) {Stop(true); phase=3;}
        if(stopScenario && (phase==2||phase==3) && age-eventAt>=1.0f) {Stop(false); phase=4;}
        bool far=scenario=="far2"||scenario=="hidden_far2"||scenario=="far_stop_before"||scenario=="far_near_before";
        if(scenario.StartsWith("near_far") && switched)far=true;
        if(scenario=="far_near_before"&&switched)far=false;
        if(scenario=="distance_flap")far=((int)(age*10))%2==0;
        playerObject.transform.position=new Vector3(far?60:1,0,0);
        bool hidden=scenario.StartsWith("hidden")||(scenario=="hide_after"&&switched);
        nca.AvatarComponent.MeshParent.SetActive(!hidden);
        // Faithful admission rule from 15524, not a claim to execute the full native NpcController.OnUpdate.
        bool admitted=!hidden||temp.IsTimeStop||Time.frameCount%3==0;
        if(admitted) fps.OnUpdate();
        var state=animator.GetCurrentAnimatorStateInfo(4);
        var remaining=Scheduler.Instance.timeModelList.ToArray().Where(m=>m.action?.Target?.TryCast<NpcAnimationEventReceiver>()!=null)
            .Select(m=>new {model=m.Pointer.ToString(),remaining=m.remainTime,unscaled=m.isUnscaled}).ToArray();
        Plugin.Log("sample",new {age,hidden,far,admitted,stop=temp.IsTimeStop,speed=animator.speed, enabled=animator.enabled,
            manual=fps.animatorFPSController.isActive, fps=fps.animatorFPSController._fps, skipped=fps.animatorFPSController._skippedTime,
            state=state.fullPathHash, normalized=state.normalizedTime,transition=animator.IsInTransition(4),events=Plugin.EventCount,callbacks=Plugin.CallbackCount,broadcasts=Plugin.BroadcastCount, remaining});
        float duration=(scenario=="hidden_far2"?7:4.5f);
        if(age>=duration) {Plugin.Log("end",new {events=Plugin.EventCount,callbacks=Plugin.CallbackCount,broadcasts=Plugin.BroadcastCount,speed=animator.speed}); Begin();}
    } catch(Exception e) {Plugin.Log("fatal",e.ToString()); enabled=false; Application.Quit();}}
}
