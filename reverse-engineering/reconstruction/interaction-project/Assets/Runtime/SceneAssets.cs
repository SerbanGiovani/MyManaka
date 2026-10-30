using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.SceneManagement;

namespace ReconstructedManaka {
    [Serializable] public sealed class AssetManifest { public int schemaVersion = 1; public SceneDescriptor scene; public PlayerDescriptor player; }
    [Serializable] public sealed class SceneDescriptor {
        public string key, kind, geometry, geometrySha256, sourceSha256, bundle, asset;
        public bool original, geometry_only, materials_approximate;
        public Vector3 spawnPosition; public Quaternion spawnRotation = Quaternion.identity;
    }
    [Serializable] public sealed class PlayerDescriptor { public string kind, bundle, asset, sha256; public float scale = 1; public string[] rendererPaths; }
    [Serializable] public sealed class GeometryDocument { public int schemaVersion; public string sceneKey, sourceSha256; public GeometryNode[] nodes; public GeometryMesh[] meshes; public GeometryTexture[] textures; }
    [Serializable] public sealed class GeometryNode { public string name; public int parent = -1, mesh = -1, builtinMeshId; public Vector3 position, scale = Vector3.one; public Quaternion rotation = Quaternion.identity; public bool active = true, rendererEnabled = true, collider; public long sourcePathId; }
    [Serializable] public sealed class GeometryMesh { public string name, materialName; public Vector3[] vertices, normals; public int[] triangles; public Vector2[] uv; public Color color = Color.gray; public int texture = -1; public Vector2 textureScale = Vector2.one, textureOffset; }
    [Serializable] public sealed class GeometryTexture { public string name, file, sha256; public int width, height, format, mipCount, byteLength, colorSpace; public TextureSettings settings; }
    [Serializable] public sealed class TextureSettings { public int m_FilterMode, m_Aniso, m_WrapU, m_WrapV, m_WrapW; public float m_MipBias; }

    public sealed class SceneAssetResult {
        public Scene scene;
        public GameObject environmentRoot, playerVisual;
        public Animator playerAnimator;
        public string animatorPath, animatorControllerName, animatorAvatarName;
        public int sourceAnimators, animatorControllerInstanceId, animatorAvatarInstanceId;
        public bool animatorControllerSameReference, animatorAvatarSameReference;
        public bool originalGeometry, originalPlayerVisual;
        public string sceneKey, environmentSource, playerSource, collisionPolicy, visualPolicy;
        public int meshes, colliders, textures, declaredTextures, unresolvedBuiltins, visualRenderers, ignoredGameBehaviours, shaderFallbacks;
        public Vector3 visualOffset, visualBoundsSize;
        public readonly Dictionary<long, Transform> sourceNodes = new Dictionary<long, Transform>();
    }
    public interface ISceneAssetProvider {
        IEnumerator Load(string sceneKey, Action<SceneAssetResult> completed, Action<string> failed);
    }

    public sealed class ManifestSceneAssets : ISceneAssetProvider {
        readonly string manifestPath;
        readonly RunEvidence evidence;
        readonly Dictionary<string, AssetBundle> bundles = new Dictionary<string, AssetBundle>();
        public ManifestSceneAssets(string path, RunEvidence run) { manifestPath = Path.GetFullPath(path); evidence = run; }
        public static string HashFile(string path) { using (var stream = File.OpenRead(path)) using (var sha = SHA256.Create()) return BitConverter.ToString(sha.ComputeHash(stream)).Replace("-", "").ToLowerInvariant(); }
        string Resolve(string relative) { if (string.IsNullOrEmpty(relative)) throw new InvalidDataException("Asset path is empty"); return Path.IsPathRooted(relative) ? relative : Path.GetFullPath(Path.Combine(Path.GetDirectoryName(manifestPath), relative)); }
        static bool Finite(float value) { return !float.IsNaN(value) && !float.IsInfinity(value); }
        static bool Finite(Vector3 value) { return Finite(value.x) && Finite(value.y) && Finite(value.z); }
        static void Require(bool value, string message) { if (!value) throw new InvalidDataException(message); }
        static Shader FallbackShader() { return Shader.Find("Standard") ?? Shader.Find("Universal Render Pipeline/Lit") ?? Shader.Find("Legacy Shaders/Diffuse") ?? Shader.Find("Sprites/Default"); }

        public IEnumerator Load(string sceneKey, Action<SceneAssetResult> completed, Action<string> failed) {
            AssetManifest manifest;
            try {
                Require(File.Exists(manifestPath), "Room assets are unavailable"); manifest = JsonUtility.FromJson<AssetManifest>(File.ReadAllText(manifestPath));
                Require(manifest != null && manifest.schemaVersion == 1 && manifest.scene != null, "Unsupported asset manifest");
                Require(manifest.scene.key == sceneKey, "The saved scene is not supplied by this asset manifest");
            } catch (Exception ex) { failed(ex.Message); yield break; }
            var result = new SceneAssetResult { sceneKey = sceneKey };
            if (manifest.scene.kind == "geometry") {
                try { BuildGeometry(manifest.scene, result); } catch (Exception ex) { failed(ex.ToString()); yield break; }
            } else if (manifest.scene.kind == "scene") {
                AssetBundle sceneBundle = null; string error = null;
                yield return LoadBundle(Resolve(manifest.scene.bundle), "", value => sceneBundle = value, value => error = value);
                if (error != null) { failed(error); yield break; }
                string path = sceneBundle.GetAllScenePaths().SingleOrDefault(value => string.Equals(value, manifest.scene.asset, StringComparison.OrdinalIgnoreCase));
                if (path == null) { failed("The manifest scene is not present in its bundle"); yield break; }
                yield return SceneManager.LoadSceneAsync(path, LoadSceneMode.Additive);
                result.scene = SceneManager.GetSceneByPath(path); result.originalGeometry = manifest.scene.original; result.environmentSource = HashFile(Resolve(manifest.scene.bundle)) + ":" + path;
                result.collisionPolicy = "colliders supplied by the explicit scene bundle";
            } else { failed("No supported original room geometry is configured"); yield break; }
            if (manifest.player == null || manifest.player.kind != "prefab") { failed("The player model is unavailable"); yield break; }
            AssetBundle playerBundle = null; string playerError = null;
            yield return LoadBundle(Resolve(manifest.player.bundle), manifest.player.sha256, value => playerBundle = value, value => playerError = value);
            if (playerError != null) { failed(playerError); yield break; }
            if (!playerBundle.GetAllAssetNames().Contains(manifest.player.asset)) { failed("The exact player prefab is absent from its bundle"); yield break; }
            var request = playerBundle.LoadAssetAsync<GameObject>(manifest.player.asset); yield return request;
            if (!(request.asset is GameObject original)) { failed("The player prefab could not be decoded"); yield break; }
            try {
                result.playerVisual = CopyVisualHierarchy(original, manifest.player, result);
                Require(result.visualRenderers > 0, "The original player has no usable mesh renderers");
                result.originalPlayerVisual = true; result.playerSource = HashFile(Resolve(manifest.player.bundle)) + ":" + manifest.player.asset;
                result.visualPolicy += "; original body/face and default-active attachments; Standard player materials; original Animator controller/avatar, reconstructed FootL/FootR event collector, root motion disabled, no original game behaviours";
                evidence.Emit("assets_ready", JsonText.Data("sceneKey", sceneKey, "originalGeometry", result.originalGeometry, "originalPlayerVisual", true, "environmentSource", result.environmentSource, "playerSource", result.playerSource, "meshes", result.meshes, "colliders", result.colliders, "texturesLoaded", result.textures, "texturesDeclared", result.declaredTextures, "visualRenderers", result.visualRenderers, "visualOffset", result.visualOffset, "visualBoundsSize", result.visualBoundsSize, "gameBehavioursCopied", 0, "gameBehavioursIgnored", result.ignoredGameBehaviours, "shaderFallbacks", result.shaderFallbacks));
                completed(result);
            } catch (Exception ex) { failed(ex.ToString()); }
        }
        IEnumerator LoadBundle(string path, string expected, Action<AssetBundle> completed, Action<string> failed) {
            if (!File.Exists(path)) { failed("Packaged model resources are missing"); yield break; }
            if (!string.IsNullOrEmpty(expected) && !string.Equals(HashFile(path), expected, StringComparison.OrdinalIgnoreCase)) { failed("Asset bundle fingerprint differs"); yield break; }
            if (bundles.TryGetValue(path, out AssetBundle existing)) { completed(existing); yield break; }
            var request = AssetBundle.LoadFromFileAsync(path); yield return request;
            if (!request.assetBundle) { failed("The asset bundle is incompatible with this engine"); yield break; }
            bundles.Add(path, request.assetBundle); completed(request.assetBundle);
        }
        public IEnumerator LoadInteractionVisual(InteractionVisualDefinition description, SceneAssetResult result, Action<GameObject> completed, Action<string> failed) {
            AssetBundle bundle = null; string error = null;
            yield return LoadBundle(Resolve(description.bundle), description.bundleSha256, value => bundle = value, value => error = value);
            if (error != null) { failed(error); yield break; }
            GameObject source = null;
            if (!string.IsNullOrEmpty(description.asset)) { var request = bundle.LoadAssetAsync<GameObject>(description.asset); yield return request; source = request.asset as GameObject; }
            else if (!string.IsNullOrEmpty(description.objectName)) {
                var request = bundle.LoadAllAssetsAsync<GameObject>(); yield return request;
                var candidates = request.allAssets.OfType<GameObject>().Where(value => value.name == description.objectName).ToArray();
                if (candidates.Length == 1) source = candidates[0];
            }
            if (!source) { failed("Exact original interaction prefab is absent or ambiguous"); yield break; }
            try {
                var map = new Dictionary<Transform, Transform>();
                foreach (Transform original in source.GetComponentsInChildren<Transform>(true)) map.Add(original, new GameObject(original.name).transform);
                foreach (var pair in map) {
                    Transform original = pair.Key, copy = pair.Value;
                    if (original != source.transform) copy.SetParent(map[original.parent], false);
                    copy.localPosition = original.localPosition; copy.localRotation = original.localRotation; copy.localScale = original.localScale;
                    copy.gameObject.SetActive(original.gameObject.activeSelf);
                    var mesh = original.GetComponent<MeshFilter>(); var renderer = original.GetComponent<MeshRenderer>();
                    if (mesh && mesh.sharedMesh && renderer) {
                        copy.gameObject.AddComponent<MeshFilter>().sharedMesh = mesh.sharedMesh;
                        var targetRenderer = copy.gameObject.AddComponent<MeshRenderer>(); targetRenderer.sharedMaterials = CompatibleMaterials(renderer.sharedMaterials, result); targetRenderer.enabled = renderer.enabled;
                    }
                    foreach (Collider originalCollider in original.GetComponents<Collider>()) {
                        Collider copied = null;
                        if (originalCollider is SphereCollider sphere) { var collider = copy.gameObject.AddComponent<SphereCollider>(); collider.center = sphere.center; collider.radius = sphere.radius; copied = collider; }
                        else if (originalCollider is BoxCollider box) { var collider = copy.gameObject.AddComponent<BoxCollider>(); collider.center = box.center; collider.size = box.size; copied = collider; }
                        else if (originalCollider is CapsuleCollider capsule) { var collider = copy.gameObject.AddComponent<CapsuleCollider>(); collider.center = capsule.center; collider.radius = capsule.radius; collider.height = capsule.height; collider.direction = capsule.direction; copied = collider; }
                        else if (originalCollider is MeshCollider meshCollider) { var collider = copy.gameObject.AddComponent<MeshCollider>(); collider.sharedMesh = meshCollider.sharedMesh; collider.convex = meshCollider.convex; copied = collider; }
                        if (copied) { copied.isTrigger = originalCollider.isTrigger; copied.enabled = originalCollider.enabled; }
                    }
                }
                GameObject root = map[source.transform].gameObject; root.SetActive(true);
                SceneManager.MoveGameObjectToScene(root, result.scene);
                evidence.Emit("interaction_original_visual_loaded", JsonText.Data("sourceBundleSha256", HashFile(Resolve(description.bundle)), "sourceAsset", description.asset, "sourceObjectName", source.name, "sourcePathId", description.sourcePathId,
                    "sourceInstanceId", source.GetInstanceID(), "runtimeInstanceId", root.GetInstanceID(), "renderers", root.GetComponentsInChildren<Renderer>(true).Length, "gameBehavioursCopied", 0, "copyPolicy", "original mesh references and native transforms; reconstruction compatible materials; no original game MonoBehaviours"));
                completed(root);
            } catch (Exception ex) { failed(ex.ToString()); }
        }
        void BuildGeometry(SceneDescriptor description, SceneAssetResult result) {
            string path = Resolve(description.geometry); Require(File.Exists(path), "Original room geometry is missing");
            string hash = HashFile(path); Require(string.IsNullOrEmpty(description.geometrySha256) || string.Equals(description.geometrySha256, hash, StringComparison.OrdinalIgnoreCase), "Room geometry fingerprint differs");
            var document = JsonUtility.FromJson<GeometryDocument>(File.ReadAllText(path));
            Require(document != null && document.schemaVersion == 1 && document.sceneKey == description.key && document.nodes != null && document.meshes != null, "Unsupported room geometry document");
            Require(string.IsNullOrEmpty(description.sourceSha256) || document.sourceSha256 == description.sourceSha256, "Original scene source fingerprint differs");
            var shader = FallbackShader(); Require(shader, "A reconstruction geometry shader is unavailable");
            var textures = new Texture2D[document.textures == null ? 0 : document.textures.Length]; result.declaredTextures = textures.Length;
            for (int i = 0; i < textures.Length; i++) {
                GeometryTexture data = document.textures[i]; string texturePath = Resolve(data.file);
                Require(File.Exists(texturePath) && new FileInfo(texturePath).Length == data.byteLength && HashFile(texturePath) == data.sha256, "Original texture data fingerprint differs");
                if (!Enum.IsDefined(typeof(TextureFormat), data.format) || !SystemInfo.SupportsTextureFormat((TextureFormat)data.format)) { evidence.Emit("texture_degraded", JsonText.Data("name", data.name, "reason", "unsupported original texture format", "format", data.format)); continue; }
                var texture = new Texture2D(data.width, data.height, (TextureFormat)data.format, data.mipCount > 1);
                if (texture.mipmapCount != data.mipCount) { UnityEngine.Object.Destroy(texture); evidence.Emit("texture_degraded", JsonText.Data("name", data.name, "reason", "original mip layout is not the constructor full chain")); continue; }
                texture.LoadRawTextureData(File.ReadAllBytes(texturePath)); texture.Apply(false, true); texture.name = data.name;
                if (data.settings != null) { texture.filterMode = (FilterMode)data.settings.m_FilterMode; texture.anisoLevel = data.settings.m_Aniso; texture.mipMapBias = data.settings.m_MipBias; texture.wrapModeU = (TextureWrapMode)data.settings.m_WrapU; texture.wrapModeV = (TextureWrapMode)data.settings.m_WrapV; texture.wrapModeW = (TextureWrapMode)data.settings.m_WrapW; }
                textures[i] = texture; result.textures++;
                evidence.Emit("original_texture_loaded", JsonText.Data("name", data.name, "sha256", data.sha256, "format", data.format, "width", data.width, "height", data.height, "mipCount", data.mipCount, "serializedColorSpace", data.colorSpace, "colorSpacePolicy", "engine default constructor; serialized color-space interpretation not independently verified"));
            }
            var meshes = new Mesh[document.meshes.Length]; var materials = new Material[meshes.Length];
            for (int i = 0; i < meshes.Length; i++) {
                GeometryMesh data = document.meshes[i]; Require(data.vertices != null && data.vertices.Length > 0 && data.triangles != null && data.triangles.Length % 3 == 0, "Invalid geometry mesh");
                Require(data.vertices.All(Finite) && data.triangles.All(index => index >= 0 && index < data.vertices.Length), "Nonfinite vertex or invalid triangle index");
                var mesh = new Mesh { name = data.name, indexFormat = IndexFormat.UInt32 }; mesh.vertices = data.vertices; mesh.triangles = data.triangles;
                if (data.normals != null && data.normals.Length == data.vertices.Length) mesh.normals = data.normals; else mesh.RecalculateNormals();
                if (data.uv != null && data.uv.Length == data.vertices.Length) mesh.uv = data.uv; mesh.RecalculateBounds(); meshes[i] = mesh;
                materials[i] = new Material(shader) { name = "Reconstructed room surface " + i, color = data.color };
                if (!string.IsNullOrEmpty(data.materialName) && data.texture >= 0 && data.texture < textures.Length && textures[data.texture] && data.uv != null && data.uv.Length == data.vertices.Length) { materials[i].mainTexture = textures[data.texture]; materials[i].mainTextureScale = data.textureScale; materials[i].mainTextureOffset = data.textureOffset; }
            }
            result.scene = SceneManager.CreateScene("MainRoom"); result.environmentRoot = new GameObject("Original Apartment Geometry"); SceneManager.MoveGameObjectToScene(result.environmentRoot, result.scene);
            var nodes = new GameObject[document.nodes.Length];
            for (int i = 0; i < nodes.Length; i++) nodes[i] = new GameObject(document.nodes[i].name);
            for (int i = 0; i < nodes.Length; i++) {
                var data = document.nodes[i]; Require(data.parent >= -1 && data.parent < nodes.Length && data.parent != i, "Invalid geometry parent");
                if (data.mesh < 0 && data.builtinMeshId > 0) { result.unresolvedBuiltins++; evidence.Emit("unresolved_builtin_mesh", JsonText.Data("node", data.name, "builtinMeshId", data.builtinMeshId, "collider", data.collider, "rendererEnabled", data.rendererEnabled)); }
                Require(Finite(data.position) && Finite(data.scale), "Nonfinite room transform");
                nodes[i].transform.SetParent(data.parent == -1 ? result.environmentRoot.transform : nodes[data.parent].transform, false);
                nodes[i].transform.localPosition = data.position; nodes[i].transform.localRotation = data.rotation; nodes[i].transform.localScale = data.scale;
                if (data.mesh >= 0) {
                    Require(data.mesh < meshes.Length, "Missing geometry mesh index");
                    if (data.rendererEnabled) { nodes[i].AddComponent<MeshFilter>().sharedMesh = meshes[data.mesh]; nodes[i].AddComponent<MeshRenderer>().sharedMaterial = materials[data.mesh]; result.meshes++; }
                    if (data.collider) { nodes[i].AddComponent<MeshCollider>().sharedMesh = meshes[data.mesh]; result.colliders++; }
                }
                nodes[i].SetActive(data.active);
                if (data.sourcePathId != 0) result.sourceNodes[data.sourcePathId] = nodes[i].transform;
            }
            Require(result.meshes > 0 && result.colliders > 0, "Original room requires actual mesh and collision geometry");
            result.originalGeometry = description.original; result.environmentSource = document.sourceSha256 + ":" + hash;
            result.collisionPolicy = "exported original collider geometry reconstructed as static MeshColliders";
            result.visualPolicy = "original mesh geometry, extracted primary colors and supported raw textures; reconstruction shaders, color-space interpretation not independently verified";
            var light = new GameObject("Room reconstruction light").AddComponent<Light>(); light.type = LightType.Directional; light.intensity = .8f; light.transform.rotation = Quaternion.Euler(45, -30, 0); light.transform.SetParent(result.environmentRoot.transform, false);
            RenderSettings.ambientMode = AmbientMode.Flat; RenderSettings.ambientLight = new Color(.6f, .6f, .6f, 1);
        }
        static string RelativePath(Transform value, Transform root) { var parts = new List<string>(); while (value && value != root) { parts.Add(value.name); value = value.parent; } parts.Reverse(); return string.Join("/", parts); }
        static bool ActiveChain(Transform value, Transform root) { while (value && value != root) { if (!value.gameObject.activeSelf) return false; value = value.parent; } return true; }
        static bool Token(Renderer renderer, string token) { return renderer.name.IndexOf(token, StringComparison.OrdinalIgnoreCase) >= 0 || renderer.sharedMaterials.Any(m => m && m.name.IndexOf(token, StringComparison.OrdinalIgnoreCase) >= 0); }
        static GameObject CopyVisualHierarchy(GameObject source, PlayerDescriptor description, SceneAssetResult result) {
            // Never instantiate the game prefab or copy its game scripts/event receivers.
            Transform[] originals = source.GetComponentsInChildren<Transform>(true); var map = new Dictionary<Transform, Transform>();
            foreach (Transform original in originals) map.Add(original, new GameObject(original.name).transform);
            var skins = source.GetComponentsInChildren<SkinnedMeshRenderer>(true).Where(s => s.sharedMesh).ToArray();
            var selected = new HashSet<Renderer>();
            SkinnedMeshRenderer primary = skins.Where(s => Token(s, "Selestia_body")).OrderBy(s => RelativePath(s.transform, source.transform).Length).FirstOrDefault();
            if (!primary) primary = skins.Where(s => Token(s, "body") && s.sharedMesh.bounds.size.y > .7f && s.sharedMesh.bounds.size.y < 3f).OrderByDescending(s => s.sharedMesh.vertexCount).FirstOrDefault();
            Require(primary, "The standard original body renderer was not found"); selected.Add(primary);
            var face = skins.Where(s => Token(s, "Manuka_face")).OrderBy(s => RelativePath(s.transform, source.transform).Length).FirstOrDefault(); if (face) selected.Add(face);
            if (description.rendererPaths != null && description.rendererPaths.Length > 0) { foreach (Renderer r in source.GetComponentsInChildren<Renderer>(true)) if (description.rendererPaths.Contains(RelativePath(r.transform, source.transform))) selected.Add(r); }
            else {
                foreach (Renderer r in source.GetComponentsInChildren<Renderer>(true).Where(r => Token(r, "トレンチコート01") || Token(r, "sakura_bob_A")).OrderBy(r => !ActiveChain(r.transform, source.transform)).ThenBy(r => RelativePath(r.transform, source.transform).Length).Take(8)) selected.Add(r);
                foreach (Renderer r in source.GetComponentsInChildren<Renderer>(true).Where(r => r.enabled && ActiveChain(r.transform, source.transform) && (Token(r, "hair") || Token(r, "cloth"))).Take(4)) selected.Add(r);
            }
            SkinnedMeshRenderer bodyCopy = null;
            foreach (Transform original in originals) {
                Transform target = map[original]; if (original != source.transform) target.SetParent(map[original.parent], false);
                target.localPosition = original.localPosition; target.localRotation = original.localRotation; target.localScale = original.localScale; target.gameObject.SetActive(original.gameObject.activeSelf);
            }
            // Activate selected default body/face/coat/hair only after preserving source local transforms.
            foreach (Renderer r in selected) { Transform t = r.transform; while (t && t != source.transform) { map[t].gameObject.SetActive(true); t = t.parent; } }
            foreach (Transform original in originals) {
                GameObject target = map[original].gameObject;
                foreach (SkinnedMeshRenderer skin in original.GetComponents<SkinnedMeshRenderer>()) {
                    if (!skin.sharedMesh || !selected.Contains(skin)) continue; var copy = target.AddComponent<SkinnedMeshRenderer>(); copy.sharedMesh = skin.sharedMesh; copy.sharedMaterials = CompatibleMaterials(skin.sharedMaterials, result);
                    copy.bones = skin.bones.Select(bone => bone && map.ContainsKey(bone) ? map[bone] : null).ToArray(); copy.rootBone = skin.rootBone && map.ContainsKey(skin.rootBone) ? map[skin.rootBone] : null;
                    copy.localBounds = skin.localBounds; copy.updateWhenOffscreen = true; copy.enabled = true; if (skin == primary) bodyCopy = copy;
                    for (int i = 0; i < skin.sharedMesh.blendShapeCount; i++) copy.SetBlendShapeWeight(i, skin.GetBlendShapeWeight(i)); result.visualRenderers++;
                }
                var filter = original.GetComponent<MeshFilter>(); var renderer = original.GetComponent<MeshRenderer>();
                if (filter && filter.sharedMesh && renderer && selected.Contains(renderer)) { target.AddComponent<MeshFilter>().sharedMesh = filter.sharedMesh; var copy = target.AddComponent<MeshRenderer>(); copy.sharedMaterials = CompatibleMaterials(renderer.sharedMaterials, result); copy.enabled = true; result.visualRenderers++; }
                result.ignoredGameBehaviours += original.GetComponents<MonoBehaviour>().Length;
            }
            GameObject root = map[source.transform].gameObject; root.name = "Original player mesh hierarchy"; root.transform.localPosition = Vector3.zero; root.transform.localRotation = Quaternion.identity; root.transform.localScale = source.transform.localScale * (description.scale > 0 ? description.scale : 1); root.SetActive(true);
            var baked = new Mesh(); bodyCopy.BakeMesh(baked); Vector3[] vertices = baked.vertices; Require(vertices.Length > 0, "Original body skin did not bake");
            Bounds bounds = new Bounds(root.transform.InverseTransformPoint(bodyCopy.transform.TransformPoint(vertices[0])), Vector3.zero);
            foreach (Vector3 vertex in vertices) bounds.Encapsulate(root.transform.InverseTransformPoint(bodyCopy.transform.TransformPoint(vertex))); UnityEngine.Object.Destroy(baked);
            Require(Finite(bounds.size) && bounds.size.y > .5f && bounds.size.y < 3.5f, "Original body dimensions are not a standard player");
            result.visualOffset = new Vector3(-bounds.center.x, -bounds.min.y, -bounds.center.z); result.visualBoundsSize = bounds.size; root.transform.localPosition = result.visualOffset;
            Animator[] originalAnimators = source.GetComponentsInChildren<Animator>(true); result.sourceAnimators = originalAnimators.Length;
            Animator originalAnimator = originalAnimators.FirstOrDefault(a => RelativePath(a.transform, source.transform) == "Manustia");
            if (!originalAnimator) originalAnimator = primary.GetComponentInParent<Animator>();
            if (!originalAnimator || !originalAnimator.runtimeAnimatorController) originalAnimator = originalAnimators.FirstOrDefault(a => a.runtimeAnimatorController);
            Require(originalAnimator && originalAnimator.runtimeAnimatorController, "The original player Animator/controller is unavailable");
            Require(originalAnimator.avatar && originalAnimator.avatar.isValid, "The original player Avatar is unavailable or invalid");
            var animator = map[originalAnimator.transform].gameObject.AddComponent<Animator>();
            animator.enabled = false; animator.avatar = originalAnimator.avatar; animator.runtimeAnimatorController = originalAnimator.runtimeAnimatorController;
            // Independent CharacterController owns world motion. A new FootL/FootR
            // collector receives the original locomotion clip events, without game audio.
            animator.applyRootMotion = false; animator.fireEvents = true; animator.cullingMode = AnimatorCullingMode.AlwaysAnimate; animator.updateMode = AnimatorUpdateMode.Normal;
            result.playerAnimator = animator; result.animatorPath = RelativePath(originalAnimator.transform, source.transform);
            result.animatorControllerName = originalAnimator.runtimeAnimatorController.name; result.animatorControllerInstanceId = originalAnimator.runtimeAnimatorController.GetInstanceID();
            result.animatorAvatarName = originalAnimator.avatar.name; result.animatorAvatarInstanceId = originalAnimator.avatar.GetInstanceID();
            result.animatorControllerSameReference = animator.runtimeAnimatorController == originalAnimator.runtimeAnimatorController;
            result.animatorAvatarSameReference = animator.avatar == originalAnimator.avatar;
            return root;
        }
        static Material[] CompatibleMaterials(Material[] source, SceneAssetResult result) {
            return source.Select(material => {
                result.shaderFallbacks++; var replacement = new Material(FallbackShader()) { name = "Reconstruction player shader fallback", color = Color.white };
                if (material && material.HasProperty("_BaseColor")) { Color color = material.GetColor("_BaseColor"); color.a = 1; replacement.color = color; }
                else if (material && material.HasProperty("_Color")) { Color color = material.GetColor("_Color"); color.a = 1; replacement.color = color; }
                if (material && material.HasProperty("_MainTex") && replacement.HasProperty("_MainTex")) replacement.SetTexture("_MainTex", material.GetTexture("_MainTex")); return replacement;
            }).ToArray();
        }
    }
}
