using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Security.Cryptography;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using Object=UnityEngine.Object;

namespace ReconstructedManaka.Editor {
public static class CompatibilityProbe {
 [Serializable] public class Receipt {
  public string editorVersion,graphicsDevice,modelsPath,modelsSha256,buildDataPath,buildDataSha256,playerAsset;
  public bool modelsLoaded,buildDataLoaded,playerLoaded,playerInstantiated,textureReadback,playerRenderReadback;
  public int assetNames,playerTransforms,meshRenderers,skinnedRenderers,meshVertices,meshTriangles,materials,missingMonoSlots,animators,controllers,unsupportedShaders;
  public int textureWidth,textureHeight,renderDifferentPixels;public string textureName,textureFormat,texturePng,playerPng;
  public string[] scenePaths,matchingAssetNames,shaderNames,errors,warnings;public string exception,focusRenderer;public Vector3 focusCenter,focusSize;public string[] candidateRenderers;
 }
 static string Arg(string name){var a=Environment.GetCommandLineArgs();int p=Array.IndexOf(a,name);return p>=0&&p+1<a.Length?a[p+1]:null;}
 static string Sha(string path){using(var s=File.OpenRead(path))using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(s)).Replace("-","").ToLowerInvariant();}
 public static void Run(){
  string output=Arg("-probeOutput");if(string.IsNullOrEmpty(output))throw new ArgumentException("-probeOutput required");Directory.CreateDirectory(Path.GetDirectoryName(output));
  var errors=new List<string>();var warnings=new List<string>();Application.LogCallback listener=(message,stack,type)=>{if(type==LogType.Error||type==LogType.Exception||type==LogType.Assert){if(errors.Count<100)errors.Add(message+"\n"+stack);}else if(type==LogType.Warning&&warnings.Count<100)warnings.Add(message);};Application.logMessageReceived+=listener;
  var r=new Receipt{editorVersion=Application.unityVersion,graphicsDevice=SystemInfo.graphicsDeviceType.ToString(),modelsPath=Arg("-modelsPath"),buildDataPath=Arg("-buildDataPath"),playerAsset="assets/zzz-externalencryptasset/player.prefab"};AssetBundle bundle=null,data=null;GameObject holder=null;
  try {
   r.modelsSha256=Sha(r.modelsPath);bundle=AssetBundle.LoadFromFile(r.modelsPath);r.modelsLoaded=bundle;if(!bundle)throw new Exception("Original models bundle was not accepted");
   var names=bundle.GetAllAssetNames();r.assetNames=names.Length;r.scenePaths=bundle.GetAllScenePaths();r.matchingAssetNames=names.Where(n=>n.Contains("apartment")||n.Contains("mapasset")||n.EndsWith("player.prefab")).ToArray();
   var player=bundle.LoadAsset<GameObject>(r.playerAsset);r.playerLoaded=player;if(!player)throw new Exception("Original player prefab missing");
   var transforms=player.GetComponentsInChildren<Transform>(true);r.playerTransforms=transforms.Length;r.missingMonoSlots=transforms.Sum(t=>t.GetComponents<MonoBehaviour>().Count(m=>!m));
   var skinned=player.GetComponentsInChildren<SkinnedMeshRenderer>(true);var filters=player.GetComponentsInChildren<MeshFilter>(true);r.skinnedRenderers=skinned.Length;r.meshRenderers=player.GetComponentsInChildren<MeshRenderer>(true).Length;
   var meshes=skinned.Select(s=>s.sharedMesh).Concat(filters.Select(f=>f.sharedMesh)).Where(m=>m).Distinct().ToArray();r.meshVertices=meshes.Sum(m=>m.vertexCount);r.meshTriangles=meshes.Sum(m=>(int)Enumerable.Range(0,m.subMeshCount).Sum(i=>(long)m.GetIndexCount(i)/3));
   var mats=player.GetComponentsInChildren<Renderer>(true).SelectMany(x=>x.sharedMaterials).Where(m=>m).Distinct().ToArray();r.materials=mats.Length;r.shaderNames=mats.Select(m=>m.shader?m.shader.name:"<null>").Distinct().ToArray();r.unsupportedShaders=mats.Count(m=>!m.shader||!m.shader.isSupported);
   var anim=player.GetComponentsInChildren<Animator>(true);r.animators=anim.Length;r.controllers=anim.Count(a=>a.runtimeAnimatorController);
   int main=Shader.PropertyToID("_MainTex");var tex=mats.Where(m=>m.HasProperty(main)).Select(m=>m.GetTexture(main)).OfType<Texture2D>().FirstOrDefault();
   if(tex){r.textureName=tex.name;r.textureFormat=tex.format.ToString();r.textureWidth=tex.width;r.textureHeight=tex.height;r.texturePng=Path.Combine(Path.GetDirectoryName(output),"original-texture.png");ReadTexture(tex,r.texturePng);r.textureReadback=File.Exists(r.texturePng);}
   EditorSceneManager.NewScene(NewSceneSetup.EmptyScene,NewSceneMode.Single);holder=new GameObject("OriginalPlayerCompatibility");holder.SetActive(false);var instance=Object.Instantiate(player,holder.transform,false);r.playerInstantiated=instance;
   foreach(var a in instance.GetComponentsInChildren<Animator>(true))a.enabled=false;
   foreach(var rb in instance.GetComponentsInChildren<Rigidbody>(true))rb.isKinematic=true;
   // Missing original behaviours are counted above. Their gameplay is not executed by this probe.
   holder.SetActive(true);var renderers=instance.GetComponentsInChildren<Renderer>(false).Where(x=>x.enabled&&(x is MeshRenderer||x is SkinnedMeshRenderer)).ToArray();r.candidateRenderers=renderers.Select(x=>x.name+" | "+x.GetType().Name+" | "+x.bounds.ToString()).Take(80).ToArray();if(renderers.Length>0){var focus=renderers.FirstOrDefault(x=>x.name.Equals("Selestia_body",StringComparison.OrdinalIgnoreCase))??renderers.FirstOrDefault(x=>x.name.IndexOf("body",StringComparison.OrdinalIgnoreCase)>=0)??renderers[0];var bounds=focus.bounds;if(focus is SkinnedMeshRenderer skin&&skin.sharedMesh){var b=skin.sharedMesh.bounds;var scale=skin.transform.lossyScale;bounds=new Bounds(skin.transform.TransformPoint(b.center),Vector3.Scale(b.size,new Vector3(Mathf.Abs(scale.x),Mathf.Abs(scale.y),Mathf.Abs(scale.z))));}r.focusRenderer=focus.name;r.focusCenter=bounds.center;r.focusSize=bounds.size;r.playerPng=Path.Combine(Path.GetDirectoryName(output),"original-player.png");r.renderDifferentPixels=RenderPlayer(bounds,r.playerPng);r.playerRenderReadback=r.renderDifferentPixels>1000;}
   if(!string.IsNullOrEmpty(r.buildDataPath)){r.buildDataSha256=Sha(r.buildDataPath);data=AssetBundle.LoadFromFile(r.buildDataPath);r.buildDataLoaded=data;}
  }catch(Exception e){r.exception=e.ToString();}
  finally{Application.logMessageReceived-=listener;r.errors=errors.ToArray();r.warnings=warnings.ToArray();File.WriteAllText(output,JsonUtility.ToJson(r,true));if(holder)Object.DestroyImmediate(holder);if(data)data.Unload(true);if(bundle)bundle.Unload(true);}
  EditorApplication.Exit(r.modelsLoaded&&r.playerLoaded&&r.playerInstantiated&&r.textureReadback?0:2);
 }
 static void ReadTexture(Texture source,string path){var rt=RenderTexture.GetTemporary(512,512,0,RenderTextureFormat.ARGB32);var old=RenderTexture.active;var image=new Texture2D(512,512,TextureFormat.RGBA32,false);try{Graphics.Blit(source,rt);RenderTexture.active=rt;image.ReadPixels(new Rect(0,0,512,512),0,0);image.Apply();File.WriteAllBytes(path,image.EncodeToPNG());}finally{RenderTexture.active=old;RenderTexture.ReleaseTemporary(rt);Object.DestroyImmediate(image);}}
 static int RenderPlayer(Bounds bounds,string path){var cam=new GameObject("CompatibilityCamera").AddComponent<Camera>();var light=new GameObject("CompatibilityLight").AddComponent<Light>();light.type=LightType.Directional;light.transform.rotation=Quaternion.Euler(35,-35,0);RenderSettings.ambientLight=Color.white*.75f;cam.backgroundColor=new Color(.08f,.1f,.12f,1);cam.clearFlags=CameraClearFlags.SolidColor;cam.fieldOfView=35;float distance=Mathf.Max(2,bounds.extents.magnitude*2.8f);cam.transform.position=bounds.center+new Vector3(0,.05f,-distance);cam.transform.LookAt(bounds.center);cam.nearClipPlane=.01f;cam.farClipPlane=1000;var rt=RenderTexture.GetTemporary(640,640,24,RenderTextureFormat.ARGB32);var old=RenderTexture.active;var image=new Texture2D(640,640,TextureFormat.RGB24,false);try{cam.targetTexture=rt;cam.Render();RenderTexture.active=rt;image.ReadPixels(new Rect(0,0,640,640),0,0);image.Apply();var pixels=image.GetPixels32();var background=pixels[0];int different=pixels.Count(c=>Math.Abs(c.r-background.r)+Math.Abs(c.g-background.g)+Math.Abs(c.b-background.b)>20);File.WriteAllBytes(path,image.EncodeToPNG());return different;}finally{cam.targetTexture=null;RenderTexture.active=old;RenderTexture.ReleaseTemporary(rt);Object.DestroyImmediate(image);Object.DestroyImmediate(cam.gameObject);Object.DestroyImmediate(light.gameObject);}}
}
}
