#if UNITY_EDITOR
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.SceneManagement;

namespace ReconstructedManaka.Editor {
    // Explicit, one-shot assetization of the already verified partial Apartment
    // bridge. This is not a Build hook and never replaces edited project assets.
    public static class ApartmentImporter {
        const string GeometrySha = "3ef0c30c6d6ced487c6db594362f52bffba5990c0c5775a2981686293e3109c0";
        const string SourceSha = "20781befb4cc42f898b65fe03f3d16c0a77b53aecac6ddc388460cfb710ae93a";
        const string BridgeSha = "207c453d4e9d4c8a887c1f5923980e429b54c8f84c67556d4292c05cd6e2b25e";
        const string ExportManifestSha = "51be1a3528e7a0f5c6b7accad5874b0630364d20f53ed8a5f2509dfdb5833f3e";
        const string AssetsRoot = "Assets/Apartment";
        const string PrefabPath = AssetsRoot + "/Environment.prefab";
        const string ScenePath = "Assets/Scenes/Apartment.unity";
        const string CollisionPolicy = "exported original collider geometry reconstructed as static MeshColliders";
        const string VisualPolicy = "original mesh geometry, extracted primary colors and supported raw textures; reconstruction shaders, color-space interpretation not independently verified";

        [Serializable] sealed class ExportManifest { public int schemaVersion; public ExportFile[] outputs; }
        [Serializable] sealed class ExportFile { public string file, sha256; public long bytes; }
        [Serializable] sealed class Fingerprint { public string path, sha256, guid; public long bytes; }
        [Serializable] sealed class TextureProof {
            public string assetPath, rawSource, rawSha256, persistedRawSha256;
            public int width, height, format, mipCount, serializedColorSpace;
        }
        [Serializable] sealed class ImportProof {
            public int schemaVersion = 1;
            public string status = "apartment-native-assets-created", createdUtc, projectPath;
            public string geometrySha256, sourceSha256, inputManifestSha256;
            public string scenePath, prefabPath, collisionPolicy, visualPolicy;
            public int nodes, meshAssets, materialAssets, drawCount, colliderCount, textureAssets, unresolvedBuiltins;
            public bool buildInvoked = false, existingAssetsReplaced = false, originalGameplayCopied = false;
            public string scope = "Only the existing partial room bridge was assetized; source transforms, static-batch coordinates, native compressed textures and known degradations are retained. Player bundle, original shaders, complete physics, gameplay and original lighting are not reconstructed here.";
            public Fingerprint[] inputs, outputs;
            public TextureProof[] textures;
        }

        static string Arg(string name) {
            string[] args = Environment.GetCommandLineArgs();
            for (int i = 0; i + 1 < args.Length; i++) if (args[i] == name) return args[i + 1];
            return null;
        }
        static void Require(bool value, string message) { if (!value) throw new InvalidDataException(message); }
        static void RequireSavedSceneContext() {
            bool untitled = false;
            for (int i = 0; i < EditorSceneManager.sceneCount; i++) {
                Scene scene = EditorSceneManager.GetSceneAt(i);
                Require(!scene.isDirty, "Save open scene edits explicitly before Apartment authoring");
                untitled |= string.IsNullOrEmpty(scene.path);
            }
            if (!untitled) return;
            Require(Application.isBatchMode && File.Exists("Assets/Scenes/Title.unity"), "Open a saved scene before Apartment authoring; untitled scenes are never discarded in the interactive editor");
            // A fresh batch editor has no human authoring session to discard.
            // Its untouched default scene must be replaced before additive work.
            EditorSceneManager.OpenScene("Assets/Scenes/Title.unity", OpenSceneMode.Single);
        }
        static bool Finite(float value) { return !float.IsNaN(value) && !float.IsInfinity(value); }
        static bool Finite(Vector3 value) { return Finite(value.x) && Finite(value.y) && Finite(value.z); }
        static string Hash(byte[] bytes) { using (var sha = SHA256.Create()) return BitConverter.ToString(sha.ComputeHash(bytes)).Replace("-", "").ToLowerInvariant(); }
        static string HashFile(string path) { using (var sha = SHA256.Create()) using (var stream = File.OpenRead(path)) return BitConverter.ToString(sha.ComputeHash(stream)).Replace("-", "").ToLowerInvariant(); }
        static string Under(string root, string relative) {
            Require(!Path.IsPathRooted(relative), "Bridge references must be relative: " + relative);
            string fullRoot = Path.GetFullPath(root).TrimEnd(Path.DirectorySeparatorChar, Path.AltDirectorySeparatorChar) + Path.DirectorySeparatorChar;
            string path = Path.GetFullPath(Path.Combine(fullRoot, relative));
            Require(path.StartsWith(fullRoot, StringComparison.OrdinalIgnoreCase), "Bridge reference escapes its directory: " + relative);
            return path;
        }
        static void EnsureFolder(string folder) {
            string[] parts = folder.Split('/'); string parent = parts[0];
            for (int i = 1; i < parts.Length; i++) {
                string path = parent + "/" + parts[i];
                if (!AssetDatabase.IsValidFolder(path)) Require(!string.IsNullOrEmpty(AssetDatabase.CreateFolder(parent, parts[i])), "Could not create " + path);
                parent = path;
            }
        }
        static Fingerprint FileProof(string path, string display = null) {
            var file = new FileInfo(path);
            return new Fingerprint { path = display ?? path.Replace('\\', '/'), bytes = file.Length, sha256 = HashFile(path), guid = display != null && display.StartsWith("Assets/", StringComparison.Ordinal) && !display.EndsWith(".meta", StringComparison.Ordinal) ? AssetDatabase.AssetPathToGUID(display) : null };
        }

        [MenuItem("Reconstruction/Import Apartment (new assets only)")]
        public static void Import() {
            string bridgeRoot = Arg("--bridge-root") ?? Path.GetFullPath(Path.Combine(Application.dataPath, "../../asset-bridge/.cache"));
            string proofPath = Arg("--assetization-proof") ?? Path.GetFullPath(Path.Combine(Application.dataPath, "../../.cache/apartment-assetization-" + DateTime.UtcNow.ToString("yyyyMMddTHHmmssfffffffZ") + ".json"));
            ImportFrom(bridgeRoot, proofPath);
        }

        public static void ImportFrom(string bridgeRoot, string proofPath) {
            Require(Application.unityVersion == "6000.6.7f1", "Use the selected Unity 6000.6.7f1 editor");
            Require(!EditorApplication.isPlayingOrWillChangePlaymode && !EditorApplication.isCompiling, "Import requires idle edit mode");
            RequireSavedSceneContext();
            bridgeRoot = Path.GetFullPath(bridgeRoot); proofPath = Path.GetFullPath(proofPath);
            string project = Path.GetFullPath(Path.Combine(Application.dataPath, ".."));
            Require(!proofPath.StartsWith(Path.GetFullPath(Application.dataPath).TrimEnd(Path.DirectorySeparatorChar) + Path.DirectorySeparatorChar, StringComparison.OrdinalIgnoreCase), "Write the import receipt outside Assets");
            Require(!File.Exists(proofPath) && !Directory.Exists(proofPath), "Import receipt exists; use a fresh receipt path");
            Require(!Directory.Exists(AssetsRoot) && !File.Exists(AssetsRoot + ".meta") && !File.Exists(ScenePath) && !File.Exists(ScenePath + ".meta"), "Apartment assets or scene already exist; edited assets are never overwritten");
            string geometryPath = Under(bridgeRoot, "Apartment.geometry.json");
            string bridgePath = Under(bridgeRoot, "roombridge.json");
            string exportPath = Path.GetFullPath(Path.Combine(bridgeRoot, "../export-manifest.json"));
            Require(HashFile(exportPath) == ExportManifestSha, "Frozen export manifest differs");
            Require(HashFile(geometryPath) == GeometrySha && HashFile(bridgePath) == BridgeSha, "Frozen Apartment bridge input differs");
            var exported = JsonUtility.FromJson<ExportManifest>(File.ReadAllText(exportPath));
            var manifest = JsonUtility.FromJson<AssetManifest>(File.ReadAllText(bridgePath));
            var doc = JsonUtility.FromJson<GeometryDocument>(File.ReadAllText(geometryPath));
            Require(exported != null && exported.schemaVersion == 1 && exported.outputs != null, "Invalid frozen export manifest");
            Require(manifest != null && manifest.scene != null && manifest.scene.key == "Apartment" && manifest.scene.kind == "geometry" && manifest.scene.geometrySha256 == GeometrySha && manifest.scene.sourceSha256 == SourceSha, "Invalid frozen room manifest");
            Require(doc != null && doc.schemaVersion == 1 && doc.sceneKey == "Apartment" && doc.sourceSha256 == SourceSha && doc.nodes != null && doc.meshes != null && doc.textures != null, "Invalid Apartment geometry document");
            Require(doc.nodes.Length == 760 && doc.meshes.Length == 302 && doc.textures.Length == 90, "Unexpected geometry contract counts");
            var exportByPath = exported.outputs.ToDictionary(value => value.file, StringComparer.Ordinal);
            var inputs = new List<Fingerprint> { FileProof(exportPath), FileProof(bridgePath), FileProof(geometryPath) };
            foreach (var row in exported.outputs) {
                string path = Under(bridgeRoot, row.file);
                Require(File.Exists(path) && new FileInfo(path).Length == row.bytes && HashFile(path) == row.sha256, "Exported input fingerprint differs: " + row.file);
            }
            var textureBytes = new byte[doc.textures.Length][];
            for (int i = 0; i < doc.textures.Length; i++) {
                var data = doc.textures[i]; string path = Under(bridgeRoot, data.file);
                Require(exportByPath.TryGetValue(data.file, out ExportFile row) && row.bytes == data.byteLength && row.sha256 == data.sha256, "Texture is absent from frozen manifest: " + data.file);
                Require(data.width > 0 && data.height > 0 && data.mipCount > 0 && (data.format == 10 || data.format == 12), "Unsupported original texture contract");
                textureBytes[i] = File.ReadAllBytes(path);
                Require(textureBytes[i].LongLength == data.byteLength && Hash(textureBytes[i]) == data.sha256, "Texture differs: " + data.file);
                inputs.Add(FileProof(path));
            }
            var seenIds = new HashSet<long>(); int draws = 0, colliders = 0, unresolved = 0;
            for (int i = 0; i < doc.nodes.Length; i++) {
                var node = doc.nodes[i];
                Require(node != null && node.parent >= -1 && node.parent < doc.nodes.Length && node.parent != i && node.mesh >= -1 && node.mesh < doc.meshes.Length && Finite(node.position) && Finite(node.scale), "Invalid geometry node " + i);
                Require(Finite(node.rotation.x) && Finite(node.rotation.y) && Finite(node.rotation.z) && Finite(node.rotation.w) && seenIds.Add(node.sourcePathId), "Invalid rotation or duplicate original source node " + i);
                var ancestors = new HashSet<int>(); int cursor = i;
                while (cursor != -1) { Require(ancestors.Add(cursor), "Cyclic original hierarchy"); cursor = doc.nodes[cursor].parent; }
                if (node.mesh >= 0) { if (node.rendererEnabled) draws++; if (node.collider) colliders++; }
                else if (node.builtinMeshId > 0) unresolved++;
            }
            Require(draws == 269 && colliders == 33 && unresolved == 5, "Unexpected partial geometry coverage");
            foreach (var mesh in doc.meshes) {
                Require(mesh != null && mesh.vertices != null && mesh.vertices.Length > 0 && mesh.vertices.All(Finite) && mesh.triangles != null && mesh.triangles.Length % 3 == 0 && mesh.triangles.All(value => value >= 0 && value < mesh.vertices.Length), "Invalid original mesh values");
                Require(mesh.texture >= -1 && mesh.texture < doc.textures.Length, "Texture index out of range");
            }
            Shader shader = Shader.Find("Standard"); Require(shader, "Built-in Standard shader is unavailable");
            // Validation is complete before the first project asset is created.
            EnsureFolder(AssetsRoot + "/Meshes"); EnsureFolder(AssetsRoot + "/Materials"); EnsureFolder(AssetsRoot + "/Textures"); EnsureFolder("Assets/Scenes");
            var textures = new Texture2D[doc.textures.Length]; var textureProofs = new List<TextureProof>();
            for (int i = 0; i < textures.Length; i++) {
                var data = doc.textures[i];
                var texture = new Texture2D(data.width, data.height, (TextureFormat)data.format, data.mipCount > 1) { name = data.name };
                Require(texture.mipmapCount == data.mipCount, "Original texture mip layout differs");
                texture.LoadRawTextureData(textureBytes[i]); texture.Apply(false, false);
                if (data.settings != null) { texture.filterMode = (FilterMode)data.settings.m_FilterMode; texture.anisoLevel = data.settings.m_Aniso; texture.mipMapBias = data.settings.m_MipBias; texture.wrapModeU = (TextureWrapMode)data.settings.m_WrapU; texture.wrapModeV = (TextureWrapMode)data.settings.m_WrapV; texture.wrapModeW = (TextureWrapMode)data.settings.m_WrapW; }
                string path = AssetsRoot + "/Textures/Texture" + i.ToString("D3") + ".asset";
                AssetDatabase.CreateAsset(texture, path);
                textures[i] = AssetDatabase.LoadAssetAtPath<Texture2D>(path);
                Require(textures[i] && EditorUtility.IsPersistent(textures[i]), "Persistent texture reload failed");
                string persistedRaw = Hash(texture.GetRawTextureData()); Require(persistedRaw == data.sha256 && EditorUtility.IsPersistent(texture), "Persistent texture raw bytes differ");
                textureProofs.Add(new TextureProof { assetPath = path, rawSource = data.file, rawSha256 = data.sha256, persistedRawSha256 = persistedRaw, width = data.width, height = data.height, format = data.format, mipCount = data.mipCount, serializedColorSpace = data.colorSpace });
            }
            var meshes = new Mesh[doc.meshes.Length]; var materials = new Material[meshes.Length];
            for (int i = 0; i < meshes.Length; i++) {
                var data = doc.meshes[i];
                var mesh = new Mesh { name = data.name, indexFormat = IndexFormat.UInt32, vertices = data.vertices, triangles = data.triangles };
                if (data.normals != null && data.normals.Length == data.vertices.Length) mesh.normals = data.normals; else mesh.RecalculateNormals();
                if (data.uv != null && data.uv.Length == data.vertices.Length) mesh.uv = data.uv; mesh.RecalculateBounds();
                AssetDatabase.CreateAsset(mesh, AssetsRoot + "/Meshes/Mesh" + i.ToString("D3") + ".asset"); meshes[i] = mesh;
                var material = new Material(shader) { name = "Reconstructed room surface " + i, color = data.color };
                if (!string.IsNullOrEmpty(data.materialName) && data.texture >= 0 && data.uv != null && data.uv.Length == data.vertices.Length) { material.mainTexture = textures[data.texture]; material.mainTextureScale = data.textureScale; material.mainTextureOffset = data.textureOffset; }
                AssetDatabase.CreateAsset(material, AssetsRoot + "/Materials/Material" + i.ToString("D3") + ".mat"); materials[i] = material;
            }
            Scene previousActive = SceneManager.GetActiveScene();
            Scene importedScene = EditorSceneManager.NewScene(NewSceneSetup.EmptyScene, NewSceneMode.Additive);
            SceneManager.SetActiveScene(importedScene);
            try {
                var root = new GameObject("Original Apartment Geometry");
                SceneManager.MoveGameObjectToScene(root, importedScene);
                var nodes = new GameObject[doc.nodes.Length];
                for (int i = 0; i < nodes.Length; i++) nodes[i] = new GameObject(doc.nodes[i].name);
                for (int i = 0; i < nodes.Length; i++) {
                    var data = doc.nodes[i];
                    nodes[i].transform.SetParent(data.parent == -1 ? root.transform : nodes[data.parent].transform, false);
                    nodes[i].transform.localPosition = data.position; nodes[i].transform.localRotation = data.rotation; nodes[i].transform.localScale = data.scale;
                    if (data.mesh >= 0) {
                        if (data.rendererEnabled) { nodes[i].AddComponent<MeshFilter>().sharedMesh = meshes[data.mesh]; nodes[i].AddComponent<MeshRenderer>().sharedMaterial = materials[data.mesh]; }
                        if (data.collider) nodes[i].AddComponent<MeshCollider>().sharedMesh = meshes[data.mesh];
                    }
                    nodes[i].SetActive(data.active);
                }
                var light = new GameObject("Room reconstruction light").AddComponent<Light>(); light.type = LightType.Directional; light.intensity = .8f; light.transform.rotation = Quaternion.Euler(45, -30, 0); light.transform.SetParent(root.transform, false);
                var metadata = root.AddComponent<ApartmentSceneRoot>(); metadata.environmentRoot = root;
                metadata.sourcePathIds = doc.nodes.Select(value => value.sourcePathId).ToArray(); metadata.sourceTransforms = nodes.Select(value => value.transform).ToArray();
                var unresolvedNodes = doc.nodes.Where(value => value.mesh < 0 && value.builtinMeshId > 0).ToArray();
                metadata.unresolvedSourcePathIds = unresolvedNodes.Select(value => value.sourcePathId).ToArray(); metadata.unresolvedBuiltinMeshIds = unresolvedNodes.Select(value => value.builtinMeshId).ToArray();
                metadata.unresolvedBuiltinPurposes = unresolvedNodes.Select(value => value.collider ? "collider" : "renderer").ToArray();
                metadata.sourceSha256 = SourceSha; metadata.geometrySha256 = GeometrySha; metadata.inputManifestSha256 = ExportManifestSha;
                metadata.nodeCount = doc.nodes.Length; metadata.meshes = draws; metadata.colliders = colliders; metadata.textures = metadata.declaredTextures = textures.Length; metadata.unresolvedBuiltins = unresolved;
                metadata.spawnPosition = manifest.scene.spawnPosition; metadata.spawnRotation = manifest.scene.spawnRotation; metadata.collisionPolicy = CollisionPolicy; metadata.visualPolicy = VisualPolicy;
                RenderSettings.ambientMode = AmbientMode.Flat; RenderSettings.ambientLight = new Color(.6f, .6f, .6f, 1);
                PrefabUtility.SaveAsPrefabAssetAndConnect(root, PrefabPath, InteractionMode.AutomatedAction, out bool prefabSaved); Require(prefabSaved, "Could not save persistent Apartment prefab");
                Require(EditorSceneManager.SaveScene(importedScene, ScenePath), "Could not save Apartment scene");
                AssetDatabase.SaveAssets();
                for (int i = 0; i < materials.Length; i++) {
                    var data = doc.meshes[i];
                    bool hasTexture = !string.IsNullOrEmpty(data.materialName) && data.texture >= 0 && data.uv != null && data.uv.Length == data.vertices.Length;
                    var persisted = AssetDatabase.LoadAssetAtPath<Material>(AssetsRoot + "/Materials/Material" + i.ToString("D3") + ".mat");
                    Require(persisted && persisted.mainTexture == (hasTexture ? textures[data.texture] : null), "Persistent material texture binding differs at " + i);
                }
                Require(root.GetComponentsInChildren<MeshRenderer>(true).Length == draws && root.GetComponentsInChildren<MeshCollider>(true).Length == colliders, "Saved scene component counts differ");
                Require(root.GetComponentsInChildren<MeshFilter>(true).All(value => EditorUtility.IsPersistent(value.sharedMesh)) && root.GetComponentsInChildren<Renderer>(true).All(value => value.sharedMaterials.All(EditorUtility.IsPersistent)), "Scene references unsaved native assets");
                var files = Directory.EnumerateFiles(AssetsRoot, "*", SearchOption.AllDirectories).Concat(new[] { AssetsRoot + ".meta", ScenePath, ScenePath + ".meta" }).OrderBy(value => value, StringComparer.Ordinal).ToArray();
                var proof = new ImportProof {
                    createdUtc = DateTime.UtcNow.ToString("O"), projectPath = project, geometrySha256 = GeometrySha, sourceSha256 = SourceSha, inputManifestSha256 = ExportManifestSha,
                    scenePath = ScenePath, prefabPath = PrefabPath, nodes = doc.nodes.Length, meshAssets = meshes.Length, materialAssets = materials.Length, drawCount = draws, colliderCount = colliders, textureAssets = textures.Length, unresolvedBuiltins = unresolved,
                    collisionPolicy = CollisionPolicy, visualPolicy = VisualPolicy, inputs = inputs.ToArray(), outputs = files.Select(value => FileProof(value, value.Replace('\\', '/'))).ToArray(), textures = textureProofs.ToArray()
                };
                Directory.CreateDirectory(Path.GetDirectoryName(proofPath));
                using (var output = new FileStream(proofPath, FileMode.CreateNew, FileAccess.Write, FileShare.None)) using (var writer = new StreamWriter(output, new System.Text.UTF8Encoding(false))) writer.Write(JsonUtility.ToJson(proof, true) + "\n");
                Debug.Log("Apartment assetization complete: 760 source nodes, 302 persistent meshes, 269 draws, 33 colliders, 90 native textures; receipt " + proofPath);
            } finally {
                if (previousActive.IsValid() && previousActive.isLoaded) SceneManager.SetActiveScene(previousActive);
                if (importedScene.IsValid() && importedScene.isLoaded) EditorSceneManager.CloseScene(importedScene, true);
            }
        }

        [MenuItem("Reconstruction/Validate saved Apartment (read only)")]
        public static void Validate() {
            string bridgeRoot = Arg("--bridge-root") ?? Path.GetFullPath(Path.Combine(Application.dataPath, "../../asset-bridge/.cache"));
            string proofPath = Arg("--assetization-proof") ?? Path.GetFullPath(Path.Combine(Application.dataPath, "../../.cache/apartment-validation-" + DateTime.UtcNow.ToString("yyyyMMddTHHmmssfffffffZ") + ".json"));
            ValidateFrom(bridgeRoot, proofPath);
        }

        // Opens the existing saved scene additively when needed and restores the
        // prior active scene. It never calls SaveScene, SaveAssets or reimport.
        public static void ValidateFrom(string bridgeRoot, string proofPath) {
            Require(!EditorApplication.isPlayingOrWillChangePlaymode && !EditorApplication.isCompiling, "Validation requires idle edit mode");
            RequireSavedSceneContext();
            bridgeRoot = Path.GetFullPath(bridgeRoot); proofPath = Path.GetFullPath(proofPath);
            Require(!File.Exists(proofPath) && !Directory.Exists(proofPath), "Validation receipt exists; use a fresh path");
            Require(!proofPath.StartsWith(Path.GetFullPath(Application.dataPath).TrimEnd(Path.DirectorySeparatorChar) + Path.DirectorySeparatorChar, StringComparison.OrdinalIgnoreCase), "Write validation receipt outside Assets");
            string geometryPath = Under(bridgeRoot, "Apartment.geometry.json");
            string bridgePath = Under(bridgeRoot, "roombridge.json");
            string exportPath = Path.GetFullPath(Path.Combine(bridgeRoot, "../export-manifest.json"));
            Require(HashFile(geometryPath) == GeometrySha && HashFile(bridgePath) == BridgeSha && HashFile(exportPath) == ExportManifestSha, "Frozen validation input differs");
            var doc = JsonUtility.FromJson<GeometryDocument>(File.ReadAllText(geometryPath));
            Require(doc.nodes.Length == 760 && doc.meshes.Length == 302 && doc.textures.Length == 90, "Unexpected validation contract counts");
            Scene previous = SceneManager.GetActiveScene(); Scene scene = SceneManager.GetSceneByPath(ScenePath);
            bool opened = !scene.IsValid() || !scene.isLoaded;
            if (opened) scene = EditorSceneManager.OpenScene(ScenePath, OpenSceneMode.Additive);
            try {
                Require(!scene.isDirty, "Saved scene validation does not accept unsaved changes");
                var roots = scene.GetRootGameObjects();
                Require(roots.Length == 1, "Apartment must have exactly one authored environment root");
                var marker = roots[0].GetComponent<ApartmentSceneRoot>();
                Require(marker && marker.schemaVersion == 1 && marker.sceneKey == "Apartment" && marker.environmentRoot == roots[0], "Saved Apartment source metadata is absent");
                Require(marker.geometrySha256 == GeometrySha && marker.sourceSha256 == SourceSha && marker.inputManifestSha256 == ExportManifestSha, "Saved scene provenance differs");
                Require(marker.nodeCount == 760 && marker.meshes == 269 && marker.colliders == 33 && marker.textures == 90 && marker.declaredTextures == 90 && marker.unresolvedBuiltins == 5, "Saved coverage differs");
                Require(marker.sourcePathIds != null && marker.sourceTransforms != null && marker.sourcePathIds.Length == doc.nodes.Length && marker.sourceTransforms.Length == doc.nodes.Length, "Saved source mapping is incomplete");
                var unresolvedNodes = doc.nodes.Where(value => value.mesh < 0 && value.builtinMeshId > 0).ToArray();
                Require(marker.unresolvedSourcePathIds != null && marker.unresolvedBuiltinMeshIds != null && marker.unresolvedBuiltinPurposes != null
                    && marker.unresolvedSourcePathIds.SequenceEqual(unresolvedNodes.Select(value => value.sourcePathId))
                    && marker.unresolvedBuiltinMeshIds.SequenceEqual(unresolvedNodes.Select(value => value.builtinMeshId))
                    && marker.unresolvedBuiltinPurposes.SequenceEqual(unresolvedNodes.Select(value => value.collider ? "collider" : "renderer")), "Saved unresolved builtin references differ");
                Require(roots[0].GetComponentsInChildren<MeshRenderer>(true).Length == 269 && roots[0].GetComponentsInChildren<MeshCollider>(true).Length == 33, "Saved draw or collider count differs");
                Require(PrefabUtility.GetPrefabAssetPathOfNearestInstanceRoot(roots[0]) == PrefabPath, "Scene is not an instance of the persistent Apartment prefab");
                var materials = new Material[doc.meshes.Length]; var meshes = new Mesh[doc.meshes.Length];
                for (int i = 0; i < meshes.Length; i++) {
                    var data = doc.meshes[i];
                    meshes[i] = AssetDatabase.LoadAssetAtPath<Mesh>(AssetsRoot + "/Meshes/Mesh" + i.ToString("D3") + ".asset");
                    materials[i] = AssetDatabase.LoadAssetAtPath<Material>(AssetsRoot + "/Materials/Material" + i.ToString("D3") + ".mat");
                    Require(meshes[i] && materials[i] && EditorUtility.IsPersistent(meshes[i]) && EditorUtility.IsPersistent(materials[i]), "Saved native mesh or material is absent");
                    Require(meshes[i].vertices.SequenceEqual(data.vertices) && meshes[i].triangles.SequenceEqual(data.triangles), "Saved native mesh geometry differs at " + i);
                    if (data.normals != null && data.normals.Length == data.vertices.Length) Require(meshes[i].normals.SequenceEqual(data.normals), "Saved native normals differ at " + i);
                    if (data.uv != null && data.uv.Length == data.vertices.Length) Require(meshes[i].uv.SequenceEqual(data.uv), "Saved native UV differs at " + i);
                    Require(materials[i].shader && materials[i].shader.name == "Standard" && materials[i].color == data.color, "Saved partial material contract differs at " + i);
                }
                for (int i = 0; i < doc.nodes.Length; i++) {
                    var expected = doc.nodes[i]; var actual = marker.sourceTransforms[i];
                    Require(actual && marker.sourcePathIds[i] == expected.sourcePathId && actual.name == expected.name, "Saved source node identity differs at " + i);
                    Require(actual.parent == (expected.parent == -1 ? roots[0].transform : marker.sourceTransforms[expected.parent]), "Saved parent differs at " + i);
                    Require(actual.localPosition == expected.position && actual.localRotation == expected.rotation && actual.localScale == expected.scale && actual.gameObject.activeSelf == expected.active, "Saved transform differs at " + i);
                    var filter = actual.GetComponent<MeshFilter>(); var renderer = actual.GetComponent<MeshRenderer>(); var collider = actual.GetComponent<MeshCollider>();
                    Require((filter != null) == (expected.mesh >= 0 && expected.rendererEnabled) && (renderer != null) == (expected.mesh >= 0 && expected.rendererEnabled) && (collider != null) == (expected.mesh >= 0 && expected.collider), "Saved component coverage differs at " + i);
                    if (filter) Require(filter.sharedMesh == meshes[expected.mesh] && renderer.sharedMaterial == materials[expected.mesh], "Saved renderer asset reference differs at " + i);
                    if (collider) Require(collider.sharedMesh == meshes[expected.mesh] && !collider.convex && !collider.isTrigger, "Saved collider contract differs at " + i);
                }
                var textureProofs = new List<TextureProof>();
                for (int i = 0; i < doc.textures.Length; i++) {
                    var data = doc.textures[i]; string assetPath = AssetsRoot + "/Textures/Texture" + i.ToString("D3") + ".asset";
                    var texture = AssetDatabase.LoadAssetAtPath<Texture2D>(assetPath);
                    Require(texture && EditorUtility.IsPersistent(texture) && texture.width == data.width && texture.height == data.height && (int)texture.format == data.format && texture.mipmapCount == data.mipCount, "Saved native texture contract differs at " + i);
                    string rawHash = Hash(texture.GetRawTextureData()); Require(rawHash == data.sha256, "Saved native compressed bytes differ at " + i);
                    textureProofs.Add(new TextureProof { assetPath = assetPath, rawSource = data.file, rawSha256 = data.sha256, persistedRawSha256 = rawHash, width = data.width, height = data.height, format = data.format, mipCount = data.mipCount, serializedColorSpace = data.colorSpace });
                }
                for (int i = 0; i < materials.Length; i++) {
                    var data = doc.meshes[i]; bool hasTexture = !string.IsNullOrEmpty(data.materialName) && data.texture >= 0 && data.uv != null && data.uv.Length == data.vertices.Length;
                    Texture expectedTexture = hasTexture ? AssetDatabase.LoadAssetAtPath<Texture2D>(AssetsRoot + "/Textures/Texture" + data.texture.ToString("D3") + ".asset") : null;
                    Require(materials[i].mainTexture == expectedTexture, "Saved material texture binding differs at " + i);
                    if (hasTexture) Require(materials[i].mainTextureScale == data.textureScale && materials[i].mainTextureOffset == data.textureOffset, "Saved UV transform differs at " + i);
                }
                var files = Directory.EnumerateFiles(AssetsRoot, "*", SearchOption.AllDirectories).Concat(new[] { AssetsRoot + ".meta", ScenePath, ScenePath + ".meta" }).OrderBy(value => value, StringComparer.Ordinal).ToArray();
                var proof = new ImportProof {
                    status = "apartment-saved-scene-validated", createdUtc = DateTime.UtcNow.ToString("O"), projectPath = Path.GetFullPath(Path.Combine(Application.dataPath, "..")),
                    geometrySha256 = GeometrySha, sourceSha256 = SourceSha, inputManifestSha256 = ExportManifestSha, scenePath = ScenePath, prefabPath = PrefabPath,
                    nodes = 760, meshAssets = 302, materialAssets = 302, drawCount = 269, colliderCount = 33, textureAssets = 90, unresolvedBuiltins = 5,
                    collisionPolicy = CollisionPolicy, visualPolicy = VisualPolicy, textures = textureProofs.ToArray(),
                    inputs = new[] { FileProof(exportPath), FileProof(bridgePath), FileProof(geometryPath) }, outputs = files.Select(value => FileProof(value, value.Replace('\\', '/'))).ToArray()
                };
                Directory.CreateDirectory(Path.GetDirectoryName(proofPath));
                using (var output = new FileStream(proofPath, FileMode.CreateNew, FileAccess.Write, FileShare.None)) using (var writer = new StreamWriter(output, new System.Text.UTF8Encoding(false))) writer.Write(JsonUtility.ToJson(proof, true) + "\n");
                Debug.Log("Saved Apartment validated read-only: 760 source nodes, 302 meshes, 269 draws, 33 colliders, 90 exact native texture byte payloads");
            } finally {
                if (previous.IsValid() && previous.isLoaded) SceneManager.SetActiveScene(previous);
                if (opened && scene.IsValid() && scene.isLoaded) EditorSceneManager.CloseScene(scene, true);
            }
        }
    }
}
#endif
