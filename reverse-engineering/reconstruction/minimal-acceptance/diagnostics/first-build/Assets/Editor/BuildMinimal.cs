#if UNITY_EDITOR
using System;
using System.IO;
using System.Linq;
using UnityEditor;
using UnityEditor.Build.Reporting;
using UnityEditor.SceneManagement;
using UnityEngine;

namespace ReconstructedManaka.Editor {
    public static class BuildMinimal {
        static string Arg(string key) { string[] args = Environment.GetCommandLineArgs(); for (int i = 0; i + 1 < args.Length; i++) if (args[i] == key) return args[i + 1]; return null; }
        public static void Build() {
            string output = Arg("--output") ?? Environment.GetEnvironmentVariable("RECONSTRUCTION_BUILD_OUTPUT");
            if (string.IsNullOrEmpty(output)) throw new ArgumentException("--output <absolute executable path> is required");
            Directory.CreateDirectory(Path.GetDirectoryName(Path.GetFullPath(output)));
            Directory.CreateDirectory("Assets/Scenes"); Directory.CreateDirectory("Assets/Resources");
            var scene = EditorSceneManager.NewScene(NewSceneSetup.EmptyScene, NewSceneMode.Single);
            if (!EditorSceneManager.SaveScene(scene, "Assets/Scenes/Title.unity")) throw new IOException("Could not create the title scene");
            Shader shader = Shader.Find("Standard"); if (!shader) throw new InvalidOperationException("Builtin Standard shader is unavailable");
            if (!AssetDatabase.LoadAssetAtPath<Material>("Assets/Resources/ReconstructionStandard.mat")) AssetDatabase.CreateAsset(new Material(shader), "Assets/Resources/ReconstructionStandard.mat");
            EnsureAxis("Horizontal", "a", "d", "left", "right", 0, 0);
            EnsureAxis("Vertical", "s", "w", "down", "up", 0, 0);
            EnsureAxis("Mouse X", "", "", "", "", 1, 0);
            EnsureAxis("Mouse Y", "", "", "", "", 1, 1);
            PlayerSettings.companyName = "ReconstructedManaka"; PlayerSettings.productName = "Manaka Reconstruction";
            PlayerSettings.defaultScreenWidth = 1280; PlayerSettings.defaultScreenHeight = 720; PlayerSettings.fullScreenMode = FullScreenMode.Windowed; PlayerSettings.resizableWindow = true; PlayerSettings.runInBackground = true;
            PlayerSettings.SetScriptingBackend(BuildTargetGroup.Standalone, ScriptingImplementation.Mono2x);
            PlayerSettings.SetApiCompatibilityLevel(BuildTargetGroup.Standalone, ApiCompatibilityLevel.NET_Standard_2_0);
            EditorBuildSettings.scenes = new[] { new EditorBuildSettingsScene("Assets/Scenes/Title.unity", true) };
            AssetDatabase.SaveAssets(); AssetDatabase.Refresh();
            BuildReport report = BuildPipeline.BuildPlayer(new BuildPlayerOptions { scenes = new[] { "Assets/Scenes/Title.unity" }, target = BuildTarget.StandaloneWindows64, locationPathName = Path.GetFullPath(output), options = BuildOptions.Development });
            string proof = "{\"schemaVersion\":1,\"result\":\"" + report.summary.result + "\",\"errors\":" + report.summary.totalErrors + ",\"warnings\":" + report.summary.totalWarnings + ",\"bytes\":" + report.summary.totalSize + "}";
            File.WriteAllText(Path.Combine(Path.GetDirectoryName(Path.GetFullPath(output)), "build-proof.json"), proof + "\n");
            if (report.summary.result != BuildResult.Succeeded) throw new InvalidOperationException("Minimal reconstruction build failed: " + proof);
        }
        static void EnsureAxis(string name, string negative, string positive, string altNegative, string altPositive, int type, int axis) {
            UnityEngine.Object manager = AssetDatabase.LoadAllAssetsAtPath("ProjectSettings/InputManager.asset").FirstOrDefault();
            if (!manager) throw new InvalidOperationException("Legacy InputManager settings are unavailable");
            var serialized = new SerializedObject(manager); var axes = serialized.FindProperty("m_Axes"); SerializedProperty item = null;
            for (int i = 0; i < axes.arraySize; i++) if (axes.GetArrayElementAtIndex(i).FindPropertyRelative("m_Name").stringValue == name) { item = axes.GetArrayElementAtIndex(i); break; }
            if (item == null) { int index = axes.arraySize; axes.InsertArrayElementAtIndex(index); item = axes.GetArrayElementAtIndex(index); }
            item.FindPropertyRelative("m_Name").stringValue = name; item.FindPropertyRelative("negativeButton").stringValue = negative; item.FindPropertyRelative("positiveButton").stringValue = positive; item.FindPropertyRelative("altNegativeButton").stringValue = altNegative; item.FindPropertyRelative("altPositiveButton").stringValue = altPositive;
            item.FindPropertyRelative("gravity").floatValue = 3; item.FindPropertyRelative("dead").floatValue = .001f; item.FindPropertyRelative("sensitivity").floatValue = type == 1 ? .1f : 3; item.FindPropertyRelative("snap").boolValue = false; item.FindPropertyRelative("invert").boolValue = false; item.FindPropertyRelative("type").intValue = type; item.FindPropertyRelative("axis").intValue = axis; item.FindPropertyRelative("joyNum").intValue = 0;
            serialized.ApplyModifiedPropertiesWithoutUndo();
        }
    }
}
#endif
