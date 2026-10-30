// Passive Unity-thread natural item/cold-title observer. No gameplay setters or replay.
// BodyPaintController and SmoothFloat are read through verified native field offsets,
// so observing an uninitialized controller does not execute its managed wrapper cctor.
using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text.Json;
using System.Text.Json.Serialization;
using BepInEx;
using BepInEx.Unity.IL2CPP;
using Il2CppInterop.Runtime.Injection;
using Il2CppInterop.Runtime.InteropTypes;
using UnityEngine;
using UnityEngine.SceneManagement;
using ExposureUnnoticed2.Scripts.InGame;

namespace REANaturalPaint {
[BepInPlugin("rea.natural.paint.observer","REA Natural Paint Observer","1.0.0")]
[BepInDependency("rea.natural.observer")]
public class PaintObserver:BasePlugin {
 public static string Root,Profile;
 public override void Load(){
  string tag=Environment.GetEnvironmentVariable("REA_NATURAL_PAINT_RUN")??"20261031-1";
  if(!System.Text.RegularExpressions.Regex.IsMatch(tag,"^[A-Za-z0-9][A-Za-z0-9._-]*$")||tag=="."||tag=="..")throw new Exception("Invalid run tag");
  Root=Path.Combine(Paths.GameRootPath,"NaturalPaint",tag);Profile=Path.Combine(Root,"working-profile");
  if(!Directory.Exists(Profile))throw new Exception("Prepare the disposable working-profile before installing this observer");
  if(File.Exists(Path.Combine(Root,"managed.jsonl")))throw new Exception("Fresh observer output directory required");
  Directory.CreateDirectory(Path.Combine(Root,"captures"));
  var observer=AppDomain.CurrentDomain.GetAssemblies().Select(a=>a.GetType("Plugin")).Single(t=>t?.GetField("SaveRoot")!=null);
  observer.GetField("SaveRoot").SetValue(null,Profile);
  ((StreamWriter)observer.GetField("Output").GetValue(null)).Flush();
  observer.GetField("Output").SetValue(null,new StreamWriter(Path.Combine(Root,"paths.jsonl"),true));
  ClassInjector.RegisterTypeInIl2Cpp<PassiveState>();AddComponent<PassiveState>();
 }
}

public class PassiveState:MonoBehaviour {
 public PassiveState(IntPtr pointer):base(pointer){}
 [DllImport("kernel32.dll",CharSet=CharSet.Unicode)]static extern IntPtr GetModuleHandleW(string name);
 [DllImport("kernel32.dll",CharSet=CharSet.Unicode)]static extern void OutputDebugStringW(string message);
 [StructLayout(LayoutKind.Sequential)]struct MemoryInfo {public IntPtr BaseAddress,AllocationBase;public uint AllocationProtect;public ushort PartitionId,Padding;public UIntPtr RegionSize;public uint State,Protect,Type,Padding2;}
 [DllImport("kernel32.dll")]static extern UIntPtr VirtualQuery(IntPtr address,out MemoryInfo buffer,UIntPtr length);
 static readonly BindingFlags F=BindingFlags.Public|BindingFlags.NonPublic|BindingFlags.Static|BindingFlags.Instance;
 static readonly Assembly Game=typeof(SaveManager).Assembly;
 static readonly Dictionary<string,Type> Types=new();
 static readonly JsonSerializerOptions Json=new(){IncludeFields=true,NumberHandling=JsonNumberHandling.AllowNamedFloatingPointLiterals};
 const string TweakLiteral="_Tweak_transparency";
 static Type T(string name){if(!Types.TryGetValue(name,out var t)){t=Game.GetTypes().Single(x=>x.Name==name);Types.Add(name,t);}return t;}
 static bool Alive(object o)=>o!=null&&(!(o is UnityEngine.Object u)||u);
 static object G(object o,string name){if(!Alive(o))return null;var t=o as Type??o.GetType();var receiver=o is Type?null:o;var p=t.GetProperty(name,F);if(p!=null)return p.GetValue(receiver);var f=t.GetField(name,F);if(f!=null)return f.GetValue(receiver);throw new MissingMemberException(t.FullName,name);}
 static IntPtr P(object o)=>o is Il2CppObjectBase b?b.Pointer:IntPtr.Zero;
 static string Ptr(object o)=>P(o)==IntPtr.Zero?null:P(o).ToString();
 static string Ptr(IntPtr p)=>p==IntPtr.Zero?null:p.ToString();
 static bool Readable(IntPtr p,int length,bool aligned=false){
  ulong address=unchecked((ulong)p.ToInt64());if(address<0x10000||address>0x7fffffffffffUL||(aligned&&(address&7)!=0)||length<0)return false;
  if(VirtualQuery(p,out var m,(UIntPtr)Marshal.SizeOf<MemoryInfo>())==UIntPtr.Zero||m.State!=0x1000||(m.Protect&0x101)!=0)return false;
  uint access=m.Protect&0xff;if(access!=2&&access!=4&&access!=8&&access!=0x20&&access!=0x40&&access!=0x80)return false;
  ulong offset=address-unchecked((ulong)m.BaseAddress.ToInt64());return offset+(ulong)length<=m.RegionSize.ToUInt64();
 }
 static IntPtr RP(IntPtr p,int offset){var at=IntPtr.Add(p,offset);if(!Readable(at,8,true))throw new Exception("Unreadable native pointer at "+at);return Marshal.ReadIntPtr(at);}
 static int RI(IntPtr p,int offset){var at=IntPtr.Add(p,offset);if(!Readable(at,4))throw new Exception("Unreadable native int at "+at);return Marshal.ReadInt32(at);}
 static float RF(IntPtr p,int offset)=>BitConverter.Int32BitsToSingle(RI(p,offset));
 static bool RB(IntPtr p,int offset){var at=IntPtr.Add(p,offset);if(!Readable(at,1))throw new Exception("Unreadable native bool at "+at);return Marshal.ReadByte(at)!=0;}
 static float? Bucket(float? value,float width)=>value.HasValue&&!float.IsNaN(value.Value)&&!float.IsInfinity(value.Value)?(float?)(Math.Floor(value.Value/width)*width):value;
 static void Log(string kind,object data)=>File.AppendAllText(Path.Combine(PaintObserver.Root,"managed.jsonl"),JsonSerializer.Serialize(new{kind,frame=Time.frameCount,real=Time.realtimeSinceStartup,data},Json)+"\n");

 class PaintRead {public string pointer,pca,alpha;public int? state;public bool pcaBound;public Dictionary<string,object> smooth;}
 class MaterialRead {public int slot;public bool valid,hasMain,hasTweak;public string pointer,name,shader,shaderName,texture,textureName;public float? tweak;}
 class RendererRead {public string pointer;public bool active;public MaterialRead[] materials;}
 static PaintRead ReadPaint(IntPtr p,IntPtr pca){
  if(p==IntPtr.Zero)return null;var a=RP(p,0x10);var bound=RP(p,0x18);
  var result=new PaintRead{pointer=Ptr(p),pca=Ptr(bound),alpha=Ptr(a),state=RI(p,0x20),pcaBound=pca!=IntPtr.Zero&&bound==pca};
  if(a!=IntPtr.Zero)result.smooth=new Dictionary<string,object>{{"Current",RF(a,0x10)},{"maxDelta",RF(a,0x14)},{"downMaxDelta",RF(a,0x18)},{"Target",RF(a,0x1c)},{"isLerp",RB(a,0x20)},{"baseValue",RF(a,0x24)},{"second",RF(a,0x28)},{"downSecond",RF(a,0x2c)},{"isUnscaled",RB(a,0x30)}};
  return result;
 }
 static object ReadStaticId(bool afterPcaBound,int independentId){
  if(!afterPcaBound)return new{status="waiting-native-pca-binding",observed=false};
  var module=GetModuleHandleW("GameAssembly.dll");if(module==IntPtr.Zero)return new{status="module-unavailable",observed=false};
  // Exact original TypeInfo usage: BodyPaintController, RVA2d58330; unresolved value is 0x20006a89.
  var slot=IntPtr.Add(module,0x2d58330);if(!Readable(slot,8,true))return new{status="usage-slot-unreadable",observed=false};
  var klass=Marshal.ReadIntPtr(slot);if(!Readable(klass,0xe4,true))return new{status="usage-unresolved",observed=false,rawUsage="0x"+unchecked((ulong)klass.ToInt64()).ToString("x")};
  int guard=RI(klass,0xe0);var fields=RP(klass,0xb8);if(fields==IntPtr.Zero||!Readable(fields,4))return new{status="static-fields-pending",observed=false,klass=Ptr(klass),rawCctorGuardAtE0=guard};
  int value=RI(fields,0);return new{status=guard==0?"resolved-raw-guard-zero":"resolved-raw-guard-nonzero",observed=true,klass=Ptr(klass),staticFields=Ptr(fields),rawCctorGuardAtE0=guard,staticTweakId=value,independentTweakId=independentId,matches=guard==0?(bool?)null:value==independentId,readOnly=true};
 }
 static MaterialRead Mat(Material m,int slot,int tweakId,int mainId){
  var r=new MaterialRead{slot=slot,valid=m,pointer=Ptr(m)};if(!m)return r;
  r.name=m.name;r.shader=Ptr(m.shader);r.shaderName=m.shader?m.shader.name:null;r.hasMain=m.HasProperty(mainId);r.hasTweak=m.HasProperty(tweakId);
  if(r.hasMain){var tex=m.GetTexture(mainId);r.texture=Ptr(tex);r.textureName=tex?tex.name:null;}if(r.hasTweak)r.tweak=m.GetFloat(tweakId);return r;
 }
 static RendererRead Render(Renderer renderer,int tweakId,int mainId){if(!renderer)return null;var ms=renderer.sharedMaterials;return new RendererRead{pointer=Ptr(renderer),active=renderer.gameObject.activeInHierarchy,materials=Enumerable.Range(0,ms.Length).Select(i=>Mat(ms[i],i,tweakId,mainId)).ToArray()};}
 static object MaterialSignature(MaterialRead m)=>m==null?null:new{m.pointer,m.valid,m.shader,m.texture,m.hasMain,m.hasTweak,tweak=Bucket(m.tweak,.01f)};
 static object RendererSignature(RendererRead r)=>r==null?null:new{r.pointer,r.active,materials=r.materials.Select(MaterialSignature).ToArray()};

 string previousScene,previousPlayer,signature;float next,heartbeat;int generation,commandIndex,captureIndex;bool loaded,humanComplete;
 class FileStamp {public long tick,length,capturedTick=-1,capturedLength=-1;public int stable;public string hash;}
 readonly Dictionary<string,FileStamp> files=new();
 object Collect(out string nextSignature){
  string scene=SceneManager.GetActiveScene().name;var gm=G(typeof(InGameManager),"Instance");if(!Alive(gm))gm=null;
  var ir=G(gm,"InGameReferencer");var player=G(ir,"Player");if(!Alive(player))player=null;var pca=G(player,"Pca");var pcaPtr=P(pca);
  var state=G(typeof(GameState),"GameStateData");var custom=G(typeof(GameState),"PlayerCustomData");var temp=G(gm,"TempInGameState");
  var paintPtr=pcaPtr==IntPtr.Zero?IntPtr.Zero:RP(pcaPtr,0x1e8);var paint=ReadPaint(paintPtr,pcaPtr);var ps=pcaPtr==IntPtr.Zero?IntPtr.Zero:RP(pcaPtr,0x60);
  float? doki=ps==IntPtr.Zero?null:RF(ps,0x58),deadline=ps==IntPtr.Zero?null:RF(ps,0x178);
  int? lastItem=ps==IntPtr.Zero?null:RI(ps,0x228),transAction=ps==IntPtr.Zero?null:RI(ps,0x234);
  var onEnd=ps==IntPtr.Zero?IntPtr.Zero:RP(ps,0x170);var action=ps==IntPtr.Zero?IntPtr.Zero:RP(ps,0x48);int? actionType=action==IntPtr.Zero?null:RI(action,0x18);
  float? remaining=state==null?null:(float?)Convert.ToSingle(G(state,"PlayerRemainBodyPaintTime"));bool? reusable=state==null?null:(bool?)G(state,"IsActiveBodyPaintReusable");
  var avatar=G(pca,"PlayerAvatarObjectReferencer");var materialController=G(pca,"PlayerBodyMaterialController");var futa=G(pca,"FutanariController");
  int tweak=Shader.PropertyToID(TweakLiteral),main=Shader.PropertyToID("_MainTex");
  var body=Render(G(avatar,"bodyMeshRenderer") as Renderer,tweak,main);var saoRenderer=Render(G(avatar,"FutanariMeshSao") as Renderer,tweak,main);var tamaRenderer=Render(G(avatar,"FutanariMeshTama") as Renderer,tweak,main);
  var clothes=Mat(G(materialController,"ClothesPaintMaterial") as Material,-1,tweak,main);var sao=Mat(G(futa,"SaoClothesPaintMaterial") as Material,-1,tweak,main);var tama=Mat(G(futa,"TamaClothesPaintMaterial") as Material,-1,tweak,main);
  var assets=G(T("AssetReferencer"),"Instance");var hair=G(assets,"MHair");string playerId=Ptr(player);if(playerId!=previousPlayer){generation++;Log("player_identity_change",new{previous=previousPlayer,current=playerId,generation,scene});previousPlayer=playerId;}
  if(scene!=previousScene){Log("scene",new{scene,previous=previousScene});previousScene=scene;}
  float? alpha=paint?.smooth!=null?(float?)Convert.ToSingle(paint.smooth["Current"]):null;
  var staticId=ReadStaticId(paint?.pcaBound==true,tweak);
  nextSignature=JsonSerializer.Serialize(new{scene,player=playerId,pca=Ptr(pca),state=Ptr(state),custom=Ptr(custom),generation,paint=paint?.pointer,paintPca=paint?.pca,paintAlpha=paint?.alpha,paintState=paint?.state,paintBound=paint?.pcaBound,alpha=Bucket(alpha,.01f),remaining=Bucket(remaining,.1f),reusable,doki=Bucket(doki,.01f),deadline,lastItem,transAction,currentAction=Ptr(action),actionType,onEndCommonEquip=Ptr(onEnd),assets=Ptr(assets),hair=Ptr(hair),applier=G(temp,"IsStopGameStateApplier"),timeStop=G(temp,"IsTimeStop"),staticId,body=RendererSignature(body),clothes=MaterialSignature(clothes),sao=MaterialSignature(sao),tama=MaterialSignature(tama),saoRenderer=RendererSignature(saoRenderer),tamaRenderer=RendererSignature(tamaRenderer)},Json);
  return new{scene,stage=G(state,"CurrentStageType")?.ToString(),state=Ptr(state),custom=Ptr(custom),player=playerId,pca=Ptr(pca),generation,playerState=Ptr(ps),paint,remaining,reusable,dokidoki=doki,lastUseItemType=lastItem,transAction,currentAction=Ptr(action),currentActionType=actionType,commonEquipEndTime=deadline,onEndCommonEquip=Ptr(onEnd),gameTime=Time.time,deltaTime=Time.deltaTime,assets=Ptr(assets),hair=Ptr(hair),assetsReady=assets!=null&&hair!=null,controllerPcaBound=paint?.pcaBound,staticPropertyId=staticId,independentTweakId=tweak,tweakLiteral=TweakLiteral,applier=G(temp,"IsStopGameStateApplier"),timeStop=G(temp,"IsTimeStop"),body,clothes,sao,tama,saoRenderer,tamaRenderer,authority="passive-original-player-natural-input-isolated-save-root"};
 }
 void CaptureFiles(){
  foreach(var path in Directory.EnumerateFiles(PaintObserver.Profile,"*.sd",SearchOption.AllDirectories)){
   try{var info=new FileInfo(path);long tick=info.LastWriteTimeUtc.Ticks,length=info.Length;if(!files.TryGetValue(path,out var stamp)){stamp=new FileStamp{tick=tick,length=length,stable=1};files.Add(path,stamp);continue;}
    if(stamp.tick!=tick||stamp.length!=length){stamp.tick=tick;stamp.length=length;stamp.stable=1;continue;}stamp.stable++;if(stamp.stable<2||(stamp.capturedTick==tick&&stamp.capturedLength==length))continue;
    byte[] data=File.ReadAllBytes(path);info.Refresh();if(info.LastWriteTimeUtc.Ticks!=tick||info.Length!=length||data.LongLength!=length){stamp.stable=0;continue;}
    string hash=Convert.ToHexString(SHA256.HashData(data)).ToLowerInvariant();bool initial=stamp.capturedTick<0;
    if(hash!=stamp.hash){var target=Path.Combine(PaintObserver.Root,"captures",(captureIndex++).ToString("D4")+"-"+Path.GetFileName(Path.GetDirectoryName(path))+"-"+Path.GetFileName(path));File.WriteAllBytes(target,data);Log("file_capture",new{source=path,target,initial,tick,bytes=length,sha256=hash,stableSamples=stamp.stable,encrypted=true});}
    else Log("file_write_same_cipher",new{source=path,tick,bytes=length,sha256=hash});stamp.capturedTick=tick;stamp.capturedLength=length;stamp.hash=hash;
   }catch(IOException e){Log("capture_retry",new{source=path,error=e.Message});}
  }
 }
 void Command(){var path=Path.Combine(PaintObserver.Root,"command");if(!File.Exists(path))return;string action=File.ReadAllText(path).Trim();File.Move(path,path+"-"+Time.frameCount+"-"+(commandIndex++));
  if(action.StartsWith("marker ",StringComparison.Ordinal)){string label=action.Substring(7).Trim();if(label.Length==0||label.Length>160){Log("command_rejected",new{action,reason="marker label length"});return;}if(label=="humancomplete")humanComplete=true;OutputDebugStringW("REA_NATURAL_PAINT_MARKER:"+label);Log("operator_marker",new{label,scope="label only; no gameplay calls or stores",humanComplete});return;}
  if(action=="quit"){if(!humanComplete){Log("command_rejected",new{action,reason="marker humancomplete required before optional quit"});return;}Log("quit_requested",new{unityMainThread=true,humanComplete});Application.Quit();return;}
  Log("command_rejected",new{action,reason="Only marker <label> and quit are supported; no UI/native gameplay helpers"});
 }
 public void Update(){
  if(Time.realtimeSinceStartup<next)return;next=Time.realtimeSinceStartup+.05f;
  if(!loaded){Log("observer_loaded",new{profile=PaintObserver.Profile,scope="SaveRoot isolation plus passive Unity-thread raw/controller/material reads; no gameplay setters, replay, clone or forced class initialization",samplingSeconds=.05,remainingBucket=.1,alphaBucket=.01,heartbeatSeconds=1});loaded=true;}
  try{Command();}catch(Exception e){Log("command_error",new{error=e.ToString()});}
  try{var data=Collect(out var current);if(current!=signature||Time.realtimeSinceStartup>=heartbeat){Log("snapshot",data);signature=current;heartbeat=Time.realtimeSinceStartup+1;}}catch(Exception e){Log("snapshot_error",new{scene=SceneManager.GetActiveScene().name,error=e.ToString()});}
  try{CaptureFiles();}catch(Exception e){Log("capture_error",new{error=e.ToString()});}
 }
}
}
