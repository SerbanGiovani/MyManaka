using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using UnityEditor;
using UnityEngine;

namespace ReconstructedManaka.Editor {
public static class AnimatorProbe {
 [Serializable] public class Parameter { public string name,type; public int hash,defaultInt; public float defaultFloat; public bool defaultBool; }
 [Serializable] public class ClipEvent { public string function; public float time,floatParameter; public int intParameter; }
 [Serializable] public class Clip { public string name; public float length,frameRate; public bool legacy,humanMotion,looping; public ClipEvent[] events; }
 [Serializable] public class Entry { public string path,avatar,controller,controllerType; public bool active,enabled,human,avatarValid,rootMotion; public int layers; public string updateMode,cullingMode; public float speed; public Parameter[] parameters; public string[] clips; }
 [Serializable] public class Receipt { public string editorVersion,bundlePath,bundleSha256,playerAsset,exception; public Entry[] animators; public Clip[] clips; public string[] errors,warnings; }
 static string Arg(string key) { var args=Environment.GetCommandLineArgs();int i=Array.IndexOf(args,key);return i<0||i+1>=args.Length?null:args[i+1]; }
 static string Sha(string path) { using(var f=File.OpenRead(path))using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(f)).Replace("-","").ToLowerInvariant(); }
 static string PathOf(Transform transform,Transform root) { var names=new List<string>();while(transform&&transform!=root){names.Add(transform.name);transform=transform.parent;}names.Reverse();return string.Join("/",names); }
 public static void Run() {
  string output=Arg("-probeOutput"),models=Arg("-modelsPath");if(string.IsNullOrEmpty(output)||string.IsNullOrEmpty(models))throw new ArgumentException("-probeOutput/-modelsPath required");Directory.CreateDirectory(Path.GetDirectoryName(output));
  var errors=new List<string>();var warnings=new List<string>();Application.LogCallback listener=(m,s,t)=>{if(t==LogType.Error||t==LogType.Exception||t==LogType.Assert)errors.Add(m+"\n"+s);else if(t==LogType.Warning)warnings.Add(m);};Application.logMessageReceived+=listener;
  var receipt=new Receipt{editorVersion=Application.unityVersion,bundlePath=models,bundleSha256=Sha(models),playerAsset="assets/zzz-externalencryptasset/player.prefab"};AssetBundle bundle=null;
  try {
   bundle=AssetBundle.LoadFromFile(models);if(!bundle)throw new Exception("Bundle not accepted");var player=bundle.LoadAsset<GameObject>(receipt.playerAsset);if(!player)throw new Exception("Original player missing");
   var entries=new List<Entry>();var allClips=new HashSet<AnimationClip>();
   foreach(var animator in player.GetComponentsInChildren<Animator>(true)) {
    var controller=animator.runtimeAnimatorController;var avatar=animator.avatar;
    var parameters=animator.parameters.Select(p=>new Parameter{name=p.name,type=p.type.ToString(),hash=p.nameHash,defaultFloat=p.defaultFloat,defaultInt=p.defaultInt,defaultBool=p.defaultBool}).ToArray();
    var clips=controller?controller.animationClips.Distinct().Where(c=>c).ToArray():new AnimationClip[0];foreach(var clip in clips)allClips.Add(clip);
    entries.Add(new Entry{path=PathOf(animator.transform,player.transform),active=animator.gameObject.activeInHierarchy,enabled=animator.enabled,avatar=avatar?avatar.name:null,human=avatar&&avatar.isHuman,avatarValid=avatar&&avatar.isValid,controller=controller?controller.name:null,controllerType=controller?controller.GetType().FullName:null,rootMotion=animator.applyRootMotion,layers=animator.layerCount,updateMode=animator.updateMode.ToString(),cullingMode=animator.cullingMode.ToString(),speed=animator.speed,parameters=parameters,clips=clips.Select(c=>c.name).ToArray()});
   }
   receipt.animators=entries.ToArray();receipt.clips=allClips.OrderBy(c=>c.name).Select(c=>new Clip{name=c.name,length=c.length,frameRate=c.frameRate,legacy=c.legacy,humanMotion=c.humanMotion,looping=c.isLooping,events=AnimationUtility.GetAnimationEvents(c).Select(e=>new ClipEvent{function=e.functionName,time=e.time,floatParameter=e.floatParameter,intParameter=e.intParameter}).ToArray()}).ToArray();
  }catch(Exception ex){receipt.exception=ex.ToString();}
  finally {Application.logMessageReceived-=listener;receipt.errors=errors.ToArray();receipt.warnings=warnings.ToArray();File.WriteAllText(output,JsonUtility.ToJson(receipt,true));if(bundle)bundle.Unload(true);}
  EditorApplication.Exit(string.IsNullOrEmpty(receipt.exception)?0:2);
 }
}
}
