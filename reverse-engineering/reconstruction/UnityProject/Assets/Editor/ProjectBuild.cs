#if UNITY_EDITOR
using System;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.Rendering;

namespace ReconstructedManaka.Editor {
    // Builds existing saved assets. Scene creation/import belongs to explicit
    // authoring commands, never to a build or a source synchronization step.
    public static class ProjectBuild {
        [Serializable]
        sealed class Receipt {
            public int schemaVersion = 1;
            public string result, unityVersion, editor = "Unity", scriptingBackend = "Mono2x", renderPipeline = "Built-in";
            public int errors, warnings;
            public ulong bytes;
            public int inputHandler;
            public string[] scenes;
            public bool createsScenes = false, savesScenes = false, copiesSources = false, rewritesSettings = false;
        }

        static string Arg(string key) {
            string[] args = Environment.GetCommandLineArgs();
            for (int i = 0; i + 1 < args.Length; i++) if (args[i] == key) return args[i + 1];
            return null;
        }

        public static void Build() {
            string output = Arg("--output") ?? Environment.GetEnvironmentVariable("RECONSTRUCTION_BUILD_OUTPUT");
            if (string.IsNullOrWhiteSpace(output) || !Path.IsPathRooted(output))
                throw new ArgumentException("--output requires a fresh absolute executable path");
            if (Application.unityVersion != "6000.6.7f1")
                throw new InvalidOperationException("The formal project requires Unity 6000.6.7f1");
            if (GraphicsSettings.defaultRenderPipeline || QualitySettings.renderPipeline)
                throw new InvalidOperationException("The formal project requires the Built-in render pipeline");
            if (EditorUserBuildSettings.activeBuildTarget != BuildTarget.StandaloneWindows64)
                throw new InvalidOperationException("Select Windows64 in the editor before building; the build does not rewrite target settings");
            if (PlayerSettings.GetScriptingBackend(NamedBuildTarget.Standalone) != ScriptingImplementation.Mono2x)
                throw new InvalidOperationException("The formal project requires Mono2x; the build does not rewrite player settings");
            if (PlayerSettings.GetApiCompatibilityLevel(NamedBuildTarget.Standalone) != ApiCompatibilityLevel.NET_Standard)
                throw new InvalidOperationException("The formal project requires NET_Standard; the build does not rewrite player settings");
            if (!Regex.IsMatch(File.ReadAllText("ProjectSettings/ProjectSettings.asset"), @"(?m)^[ \t]*activeInputHandler:[ \t]*0[ \t]*\r?$"))
                throw new InvalidOperationException("Enable the Legacy Input Manager before starting the editor");
            for (int i = 0; i < EditorSceneManager.sceneCount; i++)
                if (EditorSceneManager.GetSceneAt(i).isDirty)
                    throw new InvalidOperationException("An open scene has unsaved edits; save explicitly before building");
            string[] scenes = EditorBuildSettings.scenes.Where(scene => scene.enabled).Select(scene => scene.path).ToArray();
            if (scenes.Length < 2 || scenes[0] != "Assets/Scenes/Title.unity" || !scenes.Contains("Assets/Scenes/Apartment.unity"))
                throw new InvalidOperationException("Enable saved Title (first) and Apartment scenes in Build Settings");
            foreach (string scene in scenes)
                if (!scene.StartsWith("Assets/", StringComparison.Ordinal) || !File.Exists(scene) || !AssetDatabase.LoadAssetAtPath<SceneAsset>(scene))
                    throw new InvalidOperationException("An enabled saved scene is unavailable: " + scene);
            if (File.Exists(output)) throw new IOException("Build executable already exists; choose a fresh output path");
            string directory = Path.GetDirectoryName(Path.GetFullPath(output));
            if (Directory.Exists(directory) && Directory.EnumerateFileSystemEntries(directory).Any())
                throw new IOException("Build output directory is not empty; choose a fresh output directory");
            Directory.CreateDirectory(directory);
            BuildReport report = BuildPipeline.BuildPlayer(new BuildPlayerOptions {
                scenes = scenes,
                target = BuildTarget.StandaloneWindows64,
                locationPathName = Path.GetFullPath(output),
                options = BuildOptions.Development | BuildOptions.DetailedBuildReport
            });
            var receipt = new Receipt {
                result = report.summary.result.ToString(), unityVersion = Application.unityVersion,
                errors = report.summary.totalErrors, warnings = report.summary.totalWarnings,
                bytes = report.summary.totalSize, inputHandler = 0, scenes = scenes
            };
            File.WriteAllText(Path.Combine(directory, "build-proof.json"), JsonUtility.ToJson(receipt, true) + "\n");
            if (report.summary.result != BuildResult.Succeeded)
                throw new InvalidOperationException("Formal Unity build failed: " + receipt.result);
        }
    }
}
#endif
