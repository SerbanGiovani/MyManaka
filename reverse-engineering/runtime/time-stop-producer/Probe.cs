// Controlled Unity fixture. Does not enter the game's normal scene bootstrap.
using System;
using System.IO;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Diagnostics;
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

[BepInPlugin("rea.time.stop.fixture", "REA TimeStop Producer Fixture", "1.0.0")]
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
        Application.targetFrameRate=60; QualitySettings.vSyncCount=0;
        Application.SetStackTraceLogType(LogType.Exception,StackTraceLogType.Full);
        var h=new Harmony("rea.time.stop.fixture");
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
        foreach(var method in new[]{"OnPlaySe","CommonOnEndAnim"}) h.Patch(AccessTools.Method(typeof(PlayerAnimationReceiver),method),prefix:new HarmonyMethod(typeof(Plugin),nameof(Skip)));
        var intro=typeof(SystemManager).Assembly.GetType("ExposureUnnoticed2.ObjectTitle.IntroAnimationController");
        h.Patch(AccessTools.Method(intro,"OnStartFadeOut"),prefix:new HarmonyMethod(typeof(Plugin),nameof(Skip)));
        ClassInjector.RegisterTypeInIl2Cpp<Driver>(); AddComponent<Driver>();
        Log("loaded",new {patched, persistentDataPath=Application.persistentDataPath,unity=Application.unityVersion});
    }
}

public class Driver : MonoBehaviour
{
    public Driver(IntPtr p):base(p){}
    GameObject female,male,model,playerObject,playerModel; Animator animator,playerAnimator;
    NpcComponentAccessor nca; NpcAnimatorFpsController fps; NpcController npc;
    PlayerAnimationReceiver producer; TemporaryInGameState temp;
    Il2CppSystem.Action<TimeStopEvent> nativeListener;
    delegate void DelegateCtor(IntPtr action,IntPtr target,IntPtr method,IntPtr context);
    DelegateCtor nativeCtor; IntPtr nativeMethod;
    string[] cases={"producer_pair","producer_rapid_four","native_delegate_dedup","native_delegate_head_dedup","player_clip_pair","player_clip_retrigger","extra_true_broadcast","silent_reset_then_toggle"};
    int index=-1,step; float began; bool ready; int total=>cases.Length*4;
    string Case=>cases[index%cases.Length]; float Age=>Time.realtimeSinceStartup-began;
    void Setup() {
        Application.runInBackground=true;
        foreach(var c in Object.FindObjectsOfType<Camera>())c.enabled=false;
        var cam=new GameObject("FixtureCamera").AddComponent<Camera>(); cam.transform.position=new Vector3(0,1,-6); cam.transform.LookAt(new Vector3(0,1,0)); cam.farClipPlane=300;
        var roots=UnityEngine.Resources.LoadAll<GameObject>(""); var gos=UnityEngine.Resources.FindObjectsOfTypeAll<GameObject>();
        female=gos.First(g=>g.name=="NpcFemale_Assemble");male=gos.First(g=>g.name=="NpcMale");
        var game=new GameObject("FixtureInGame").AddComponent<InGameManager>();game.enabled=false;
        temp=new TemporaryInGameState();Plugin.Set(game,"TempInGameState",temp);InGameManager.Instance=game;
        var manager=new GameObject("FixtureNpcManager").AddComponent<NpcManager>();manager.enabled=false;Plugin.Set(typeof(NpcManager),"Instance",manager);
        playerObject=new GameObject("FixturePlayer");var player=playerObject.AddComponent<PlayerController>();player.enabled=false;
        var pca=Plugin.Alloc<PlayerClassAccessor>();Plugin.Set(pca,"GameObject",playerObject);player.pca=pca;PlayerController.Instance=player;
        var sound=new GameObject("FixtureSound").AddComponent<InGameSoundManager>();sound.enabled=false;InGameSoundManager.Instance=sound;
        GameState.GameStateData=Plugin.Alloc<GameStateData>();
        var bundle=AssetBundle.LoadFromFile(Path.Combine(Paths.GameRootPath,"models.unity3d"));
        var prefab=bundle.LoadAsset<GameObject>("assets/zzz-externalencryptasset/manustia.prefab");
        playerModel=Object.Instantiate(prefab);playerModel.transform.position=new Vector3(5,0,0);
        playerAnimator=playerModel.GetComponent<Animator>();producer=playerModel.GetComponent<PlayerAnimationReceiver>();
        playerAnimator.enabled=false;
        Plugin.Log("player_asset",new {prefab=prefab.name,controller=playerAnimator.runtimeAnimatorController.name,
            receiver=producer.Pointer.ToString(),clips=playerAnimator.runtimeAnimatorController.animationClips.Where(c=>c.name.Contains("TimeStop")).Select(c=>new {c.name,c.length,events=c.events.Select(e=>new {e.functionName,e.time}).ToArray()}).ToArray()});
        IntPtr nativeBase=Process.GetCurrentProcess().Modules.Cast<ProcessModule>().First(m=>m.ModuleName=="GameAssembly.dll").BaseAddress;
        nativeCtor=Marshal.GetDelegateForFunctionPointer<DelegateCtor>(IntPtr.Add(nativeBase,0x665bb0));
        nativeMethod=IL2CPP.il2cpp_class_get_method_from_name(Il2CppClassPointerStore<NpcController>.NativeClassPtr,"OnTimeStopEvent",1);
        var scheduler=Scheduler.Instance;scheduler.enabled=true;
        foreach(var m in Object.FindObjectsOfType<MonoBehaviour>())if(m.Pointer!=Pointer&&m.Pointer!=scheduler.Pointer)m.enabled=false;
        Plugin.Log("ready",new {scheduler=scheduler.Pointer.ToString(),nativeMethod=nativeMethod.ToString()});
    }
    Il2CppSystem.Action<TimeStopEvent> MakeNativeListener() {
        var action=Plugin.Alloc<Il2CppSystem.Action<TimeStopEvent>>();
        nativeCtor(action.Pointer,npc.Pointer,nativeMethod,IntPtr.Zero);
        return action;
    }
    void Register(bool head) {
        var action=MakeNativeListener();int before=EventManager.s_EventLookups.Count;
        EventManager.AddListener<TimeStopEvent>(action,head);
        Plugin.Log("subscribe",new {head,before,after=EventManager.s_EventLookups.Count,target=action.Target.Pointer.ToString(),action=action.Pointer.ToString()});
        nativeListener=action;
    }
    void Begin() {
        if(model!=null)Object.Destroy(model);
        index++;if(index>=total){Plugin.Trial="complete";Plugin.Log("complete");enabled=false;Application.Quit();return;}
        bool isFemale=(index/cases.Length)%2==0;
        Plugin.Trial="r"+(index/(cases.Length*2)+1)+"/"+(isFemale?"female/":"male/")+Case;
        Plugin.EventCount=Plugin.CallbackCount=Plugin.BroadcastCount=0;step=0;temp.IsTimeStop=false;
        EventManager.Clear();EventManager.AddListener<FoundStrangerEvent>((Il2CppSystem.Action<FoundStrangerEvent>)Plugin.OnFound,false);
        model=Object.Instantiate(isFemale?female:male);model.name="FixtureNpc";
        animator=model.GetComponent<Animator>();Plugin.Animator=animator;animator.enabled=true;animator.speed=1;
        var receiver=model.GetComponent<NpcAnimationEventReceiver>();var avatar=model.GetComponent<NpcAvatarComponent>();
        nca=Plugin.Alloc<NpcComponentAccessor>();npc=Plugin.Alloc<NpcController>();
        Plugin.Set(nca,"GameObject",model);Plugin.Set(nca,"Transform",model.transform);Plugin.Set(nca,"Animator",animator);
        Plugin.Set(nca,"NpcController",npc);Plugin.Set(nca,"AvatarComponent",avatar);Plugin.Set(nca,"StateModel",new NpcStateModel());
        var comp=model.AddComponent<NpcComponent>();comp.DokinAudioSource=model.AddComponent<AudioSource>();
        Plugin.Set(nca,"AudioSource",model.AddComponent<AudioSource>());Plugin.Set(nca,"NpcComponent",comp);
        var sound=Plugin.Alloc<NpcSoundController>();sound.nca=nca;Plugin.Set(nca,"NpcSoundController",sound);
        Plugin.Set(npc,"Nca",nca);Plugin.Set(npc,"GameObject",model);Plugin.Set(npc,"Transform",model.transform);
        receiver.Initialize(nca);fps=new NpcAnimatorFpsController();fps.Initialize(nca);
        animator.Rebind();animator.SetBool("IsFemale",isFemale);animator.SetBool("IsSit",false);animator.SetBool("IsFoundStranger",false);animator.Update(0);
        playerAnimator.enabled=false;playerAnimator.Rebind();playerAnimator.Update(0);playerAnimator.speed=1;
        playerObject.transform.position=new Vector3(1,0,0);
        began=Time.realtimeSinceStartup;
        Plugin.Log("begin",new {scenario=Case,receiver=receiver.Pointer.ToString(),npc=npc.Pointer.ToString(),playerReceiver=producer.Pointer.ToString()});
        Register(false);
        if(Case=="native_delegate_dedup"||Case=="native_delegate_head_dedup")Register(Case=="native_delegate_head_dedup");
    }
    void Toggle() {
        bool before=temp.IsTimeStop;producer.OnChangeTimeStop();
        Plugin.Log("producer_return",new {before,after=temp.IsTimeStop,speed=animator.speed,cache=npc.animatorSpeedCache});
    }
    void Play() {
        playerAnimator.enabled=true;playerAnimator.SetInteger("ActionId",7);playerAnimator.SetTrigger("TransAction");
        Plugin.Log("player_trigger");
    }
    public void Update(){try {
        if(!ready){if(!File.Exists(Path.Combine(Paths.GameRootPath,"go")))return;Setup();ready=true;Begin();return;}
        if(index>=total)return;
        float age=Age;
        if(step==0&&age>=0.25f){animator.SetBool("IsFoundStranger",true);Plugin.Log("found_parameter");step=1;}
        if(Case.StartsWith("player_clip")) {
            if(step==1&&age>=0.10f){Play();step=2;}
            if(Case=="player_clip_retrigger") {
                if(step==2&&age>=0.40f){Play();step=3;}
                if(step==3&&age>=0.60f){Play();step=4;}
                if(step==4&&age>=2.00f){Play();step=5;}
            }else if(step==2&&age>=1.60f){Play();step=5;}
        }else if(Case=="producer_rapid_four") {
            float[] at={0.40f,0.44f,0.48f,1.48f};
            if(step>=1&&step<=4&&age>=at[step-1]){Toggle();step++;}
        }else {
            if(step==1&&age>=0.40f){Toggle();step=2;}
            if(step==2&&age>=0.60f&&(Case=="extra_true_broadcast"||Case=="silent_reset_then_toggle")) {
                if(Case=="extra_true_broadcast"){EventManager.Broadcast(Events.TimeStopEvent);Plugin.Log("injected_extra_broadcast",new {speed=animator.speed,cache=npc.animatorSpeedCache});}
                else {temp.IsTimeStop=false;Plugin.Log("injected_silent_reset");Toggle();}
                step=3;
            }
            if((step==2||step==3)&&age>=1.40f){Toggle();step=5;}
        }
        fps.OnUpdate();
        Plugin.Log("sample",new {age,stop=temp.IsTimeStop,speed=animator.speed,cache=npc.animatorSpeedCache,
            normalized=animator.GetCurrentAnimatorStateInfo(4).normalizedTime,playerState=playerAnimator.GetCurrentAnimatorStateInfo(7).fullPathHash,
            playerNormalized=playerAnimator.GetCurrentAnimatorStateInfo(7).normalizedTime,events=Plugin.EventCount,broadcasts=Plugin.BroadcastCount});
        if(age>=4.5f){Plugin.Log("end",new {events=Plugin.EventCount,broadcasts=Plugin.BroadcastCount,speed=animator.speed,cache=npc.animatorSpeedCache,stop=temp.IsTimeStop});Begin();}
    }catch(Exception e){Plugin.Log("fatal",e.ToString());enabled=false;Application.Quit();}}
}

