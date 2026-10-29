using System;
using System.IO;
using UnityEditor;
using UnityEditor.Build.Reporting;
using UnityEditor.SceneManagement;
using UnityEngine;
namespace REAToolchain {
public static class BuildSmoke {
 [Serializable]public class Receipt {public string editorVersion,result,outputPath;public int errors,warnings;public ulong bytes;}
 static string Arg(string key){var args=Environment.GetCommandLineArgs();int i=Array.IndexOf(args,key);if(i<0||i+1>=args.Length)throw new ArgumentException(key);return args[i+1];}
 public static void Run(){
  string output=Path.GetFullPath(Arg("-reaBuildRoot"));Directory.CreateDirectory(output);
  var scene=EditorSceneManager.NewScene(NewSceneSetup.EmptyScene,NewSceneMode.Single);
  var camera=new GameObject("Camera").AddComponent<Camera>();camera.transform.position=new Vector3(0,2,-5);camera.transform.LookAt(Vector3.zero);camera.backgroundColor=new Color(0.1f,0.15f,0.2f);
  var cube=GameObject.CreatePrimitive(PrimitiveType.Cube);cube.name="CompilerSmokeCube";cube.AddComponent<RuntimeSmoke>();
  new GameObject("Sun").AddComponent<Light>().type=LightType.Directional;
  const string scenePath="Assets/ToolchainSmoke.unity";EditorSceneManager.SaveScene(scene,scenePath);
  PlayerSettings.productName="REA Toolchain Smoke";PlayerSettings.companyName="Local REA";
  PlayerSettings.SetScriptingBackend(BuildTargetGroup.Standalone,ScriptingImplementation.Mono2x);
  var report=BuildPipeline.BuildPlayer(new BuildPlayerOptions{scenes=new[]{scenePath},locationPathName=Path.Combine(output,"ToolchainSmoke.exe"),target=BuildTarget.StandaloneWindows64,options=BuildOptions.StrictMode});
  var summary=report.summary;File.WriteAllText(Path.Combine(output,"build-receipt.json"),JsonUtility.ToJson(new Receipt{editorVersion=Application.unityVersion,result=summary.result.ToString(),outputPath=summary.outputPath,errors=summary.totalErrors,warnings=summary.totalWarnings,bytes=summary.totalSize},true));
  if(summary.result!=BuildResult.Succeeded)throw new Exception("Smoke build failed: "+summary.result);
 }
}
}
