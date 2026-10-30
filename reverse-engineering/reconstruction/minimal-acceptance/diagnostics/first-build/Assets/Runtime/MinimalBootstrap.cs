using System;
using System.Collections;
using System.IO;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace ReconstructedManaka {
    public sealed class MinimalBootstrap : MonoBehaviour {
        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
        static void Install() { if (!FindObjectOfType<MinimalBootstrap>()) { var root = new GameObject("Reconstructed Manaka"); root.AddComponent<MinimalBootstrap>(); } }
        RunEvidence evidence;
        SaveStore store;
        SaveState state;
        ISceneAssetProvider assets;
        SceneAssetResult room;
        CharacterController controller;
        PlayerMotor motor;
        FollowCamera follow;
        GameObject actor;
        Camera view;
        string phase, seedPath, message = "", profileRoot;
        bool loading, playing, ended;
        Font font;
        static string Arg(string key, string fallback = null) {
            string[] args = Environment.GetCommandLineArgs();
            for (int i = 0; i < args.Length; i++) { if (args[i] == key && i + 1 < args.Length) return args[i + 1]; if (args[i].StartsWith(key + "=", StringComparison.Ordinal)) return args[i].Substring(key.Length + 1); }
            return fallback;
        }
        void Awake() {
            DontDestroyOnLoad(gameObject); Application.targetFrameRate = 60;
            profileRoot = Arg("--profile-root", Path.Combine(Application.persistentDataPath, "ReconstructedManaka", "profiles", "default"));
            phase = Arg("--acceptance", "manual"); seedPath = Arg("--seed", Path.Combine(Application.streamingAssetsPath, "seed.json"));
            evidence = gameObject.AddComponent<RunEvidence>(); evidence.Initialize(profileRoot, Arg("--proof-dir"), phase);
            store = new SaveStore(profileRoot);
            assets = new ManifestSceneAssets(Arg("--asset-manifest", Path.Combine(Application.streamingAssetsPath, "Original", "roombridge.json")), evidence);
            font = Font.CreateDynamicFontFromOSFont(new[] { "Microsoft YaHei UI", "Microsoft YaHei", "Arial" }, 18);
            var cameraObject = new GameObject("Reconstruction camera"); cameraObject.transform.SetParent(transform, false); view = cameraObject.AddComponent<Camera>(); cameraObject.tag = "MainCamera"; view.clearFlags = CameraClearFlags.SolidColor; view.backgroundColor = new Color(.07f, .09f, .12f); view.nearClipPlane = .05f; view.farClipPlane = 150;
            cameraObject.AddComponent<AudioListener>(); follow = cameraObject.AddComponent<FollowCamera>();
        }
        IEnumerator Start() {
            evidence.Emit("title_ready", JsonText.Data("hasSave", store.Exists, "phase", phase, "automaticEntryUsesSameOpenMethod", true));
            yield return null; yield return null; yield return null;
            if (phase == "phase1") yield return Open(false); else if (phase == "phase2") yield return Open(true);
        }
        IEnumerator Open(bool readExisting) {
            if (loading || playing) yield break; loading = true; message = "正在载入… / Loading…";
            string error;
            if (readExisting) {
                if (!store.TryRead(out state, out error)) { Fail("Save read failed: " + error); yield break; }
            } else {
                if (!store.TryImportSeed(seedPath, out state, out error)) { Fail("Initial data unavailable: " + error); yield break; }
            }
            // This is recorded before any scene, CharacterController or physics adjustment.
            evidence.Proof.loadedPosition = state.position; evidence.Proof.loadedRotation = state.rotation; evidence.Proof.loadedSavedProcessGuid = state.savedProcessGuid;
            evidence.Emit(readExisting ? "saved_state_read" : "seed_imported", JsonText.Data("sceneKey", state.sceneKey, "position", state.position, "rotation", state.rotation, "revision", state.revision, "savedProcessGuid", state.savedProcessGuid, "sourceSaveSha256", state.sourceSaveSha256));
            SceneAssetResult loaded = null; string assetError = null;
            yield return assets.Load(state.sceneKey, value => loaded = value, value => assetError = value);
            if (loaded == null || assetError != null) { Fail("Scene assets failed: " + assetError); yield break; }
            room = loaded; SceneManager.SetActiveScene(room.scene);
            foreach (Camera other in FindObjectsOfType<Camera>()) if (other != view) other.enabled = false;
            actor = new GameObject("Player"); SceneManager.MoveGameObjectToScene(actor, room.scene);
            controller = actor.AddComponent<CharacterController>(); controller.enabled = false; controller.height = 1.6f; controller.center = new Vector3(0, .8f, 0); controller.radius = .23f; controller.skinWidth = .025f; controller.stepOffset = .2f; controller.slopeLimit = 50;
            actor.transform.SetPositionAndRotation(state.position, state.rotation);
            room.playerVisual.transform.SetParent(actor.transform, false); room.playerVisual.transform.localPosition = room.visualOffset; room.playerVisual.transform.localRotation = Quaternion.identity;
            motor = actor.AddComponent<PlayerMotor>(); motor.cameraBasis = view.transform; motor.InputEnabled = false; follow.Bind(actor.transform);
            evidence.Proof.sceneKey = state.sceneKey; evidence.Proof.environmentSource = room.environmentSource; evidence.Proof.playerSource = room.playerSource; evidence.Proof.originalGeometry = room.originalGeometry; evidence.Proof.originalPlayerVisual = room.originalPlayerVisual;
            evidence.Proof.geometryMeshes = room.meshes; evidence.Proof.geometryColliders = room.colliders; evidence.Proof.geometryTextures = room.textures; evidence.Proof.declaredTextures = room.declaredTextures; evidence.Proof.unresolvedBuiltinMeshes = room.unresolvedBuiltins; evidence.Proof.visualRenderers = room.visualRenderers; evidence.Proof.copiedGameBehaviours = 0; evidence.Proof.playerShaderFallbacks = room.shaderFallbacks; evidence.Proof.collisionPolicy = room.collisionPolicy; evidence.Proof.visualPolicy = room.visualPolicy; evidence.Proof.playerVisualOffset = room.visualOffset; evidence.Proof.playerVisualBoundsSize = room.visualBoundsSize;
            evidence.Proof.appliedPosition = actor.transform.position; evidence.Proof.appliedRotation = actor.transform.rotation;
            evidence.Proof.exactAppliedPosition = Exact(state.position, actor.transform.position); evidence.Proof.exactAppliedRotation = Exact(state.rotation, actor.transform.rotation);
            evidence.Proof.positionError = Vector3.Distance(state.position, actor.transform.position); evidence.Proof.rotationErrorDegrees = Quaternion.Angle(state.rotation, actor.transform.rotation);
            evidence.Emit("pose_applied_before_physics", JsonText.Data("sceneKey", state.sceneKey, "position", actor.transform.position, "rotation", actor.transform.rotation, "exactPosition", evidence.Proof.exactAppliedPosition, "exactRotation", evidence.Proof.exactAppliedRotation, "positionError", evidence.Proof.positionError, "rotationErrorDegrees", evidence.Proof.rotationErrorDegrees));
            loading = false; playing = true; message = "";
            if (phase == "phase2") { yield return ReadbackAcceptance(); yield break; }
            controller.enabled = true; motor.InputEnabled = true;
            evidence.Emit("scene_ready", JsonText.Data("sceneKey", state.sceneKey, "position", actor.transform.position, "controller", "CharacterController", "originalGeometry", room.originalGeometry, "originalPlayerVisual", room.originalPlayerVisual));
            if (phase == "phase1") yield return MovementAcceptance();
        }
        IEnumerator MovementAcceptance() {
            evidence.Proof.controlledInput = true; evidence.Proof.inputDescription = "Simulated axes enter the same PlayerMotor.Update/StepFromInput/CharacterController.Move path as hardware; this is not a physical keyboard test.";
            motor.SetSimulatedInput(true, Vector2.zero);
            float until = Time.realtimeSinceStartup + 8;
            while (!motor.GroundedSeen && Time.realtimeSinceStartup < until) yield return null;
            Vector3 start = actor.transform.position; evidence.Proof.movementStart = start;
            Vector2[] directions = { Vector2.up, Vector2.right, Vector2.down, Vector2.left }; float[] durations = { .7f, .6f, .2f, .15f };
            for (int index = 0; index < directions.Length; index++) {
                Vector2 axes = directions[index]; motor.SetSimulatedInput(true, axes); float end = Time.realtimeSinceStartup + durations[index];
                evidence.Emit("controlled_input", JsonText.Data("axes", axes, "method", "same PlayerMotor.Update path", "position", actor.transform.position));
                while (Time.realtimeSinceStartup < end) yield return null;
            }
            motor.SetSimulatedInput(true, Vector2.zero); yield return null;
            UpdateMotorProof(); evidence.Proof.movementEnd = actor.transform.position;
            evidence.Proof.horizontalDisplacement = Vector3.ProjectOnPlane(actor.transform.position - start, Vector3.up).magnitude;
            bool moved = motor.TravelledDistance >= .1f && evidence.Proof.horizontalDisplacement >= .05f && motor.InputSamples > 5;
            bool grounded = motor.GroundedSeen && motor.BelowCollisions > 0 && Mathf.Abs(actor.transform.position.y - start.y) < 3;
            evidence.Emit("movement_observed", JsonText.Data("start", start, "end", actor.transform.position, "travelledDistance", motor.TravelledDistance, "groundedSeen", motor.GroundedSeen, "belowCollisions", motor.BelowCollisions, "sideCollisions", motor.SideCollisions, "inputSamples", motor.InputSamples));
            if (!moved || !grounded) { Fail("Movement/ground collision acceptance failed"); yield break; }
            if (!SaveCurrent()) yield break;
            bool validAssets = room.originalGeometry && room.originalPlayerVisual;
            CompleteAndQuit(validAssets, validAssets ? null : "Original room/player resources were not supplied");
        }
        IEnumerator ReadbackAcceptance() {
            bool previousProcess = !string.IsNullOrEmpty(state.savedProcessGuid) && state.savedProcessGuid != evidence.ProcessGuid && state.revision > 0;
            bool pose = evidence.Proof.positionError <= .00001f && evidence.Proof.rotationErrorDegrees <= .001f;
            evidence.Proof.savePath = store.FilePath; evidence.Proof.saveSha256 = ManifestSceneAssets.HashFile(store.FilePath); evidence.Proof.saveRevision = state.revision; evidence.Proof.savedPosition = state.position; evidence.Proof.savedRotation = state.rotation;
            evidence.Emit("readback_verified_before_physics", JsonText.Data("previousProcess", previousProcess, "writerProcessGuid", state.savedProcessGuid, "readerProcessGuid", evidence.ProcessGuid, "sceneKey", state.sceneKey, "position", state.position, "rotation", state.rotation, "exactAppliedPosition", evidence.Proof.exactAppliedPosition, "exactAppliedRotation", evidence.Proof.exactAppliedRotation, "saveSha256", evidence.Proof.saveSha256));
            yield return CaptureProofScreenshot();
            CompleteAndQuit(previousProcess && pose && room.originalGeometry && room.originalPlayerVisual, previousProcess && pose ? null : "Cross-process scene/pose readback failed");
        }
        IEnumerator CaptureProofScreenshot() {
            yield return null; yield return null;
            string path = Path.Combine(Path.GetDirectoryName(evidence.Proof.proofPath), "readback.png");
            ScreenCapture.CaptureScreenshot(path); float deadline = Time.realtimeSinceStartup + 5;
            while ((!File.Exists(path) || new FileInfo(path).Length < 100) && Time.realtimeSinceStartup < deadline) yield return null;
            if (!File.Exists(path) || new FileInfo(path).Length < 100) { Fail("Readback GPU screenshot was not produced"); yield break; }
            evidence.Proof.screenshotPath = path; evidence.Proof.screenshotBytes = new FileInfo(path).Length; evidence.Proof.screenshotSha256 = ManifestSceneAssets.HashFile(path);
            evidence.Emit("screenshot_written", JsonText.Data("path", path, "sha256", evidence.Proof.screenshotSha256, "bytes", evidence.Proof.screenshotBytes, "afterPoseAppliedFrames", 2));
        }
        void UpdateMotorProof() { if (!motor) return; evidence.Proof.groundedSeen = motor.GroundedSeen; evidence.Proof.inputSamples = motor.InputSamples; evidence.Proof.travelledDistance = motor.TravelledDistance; evidence.Proof.belowCollisions = motor.BelowCollisions; evidence.Proof.sideCollisions = motor.SideCollisions; }
        public bool SaveCurrent() {
            if (!playing || !actor) return false;
            try {
                state.sceneKey = room.sceneKey; state.position = actor.transform.position; state.rotation = actor.transform.rotation; state.savedProcessGuid = evidence.ProcessGuid;
                store.Write(state);
                SaveState disk; string error; if (!store.TryRead(out disk, out error)) throw new IOException("Written save could not be read: " + error);
                bool samePosition = Exact(state.position, disk.position), sameRotation = Exact(state.rotation, disk.rotation);
                if (!samePosition || !sameRotation || disk.sceneKey != state.sceneKey || disk.savedProcessGuid != evidence.ProcessGuid) throw new IOException("Saved actual pose did not survive JSON roundtrip");
                evidence.Proof.exactStoredPosition = samePosition; evidence.Proof.exactStoredRotation = sameRotation; evidence.Proof.savedPosition = disk.position; evidence.Proof.savedRotation = disk.rotation; evidence.Proof.savePath = store.FilePath; evidence.Proof.saveSha256 = ManifestSceneAssets.HashFile(store.FilePath); evidence.Proof.saveRevision = disk.revision;
                evidence.Emit("save_completed", JsonText.Data("sceneKey", disk.sceneKey, "position", disk.position, "rotation", disk.rotation, "processGuid", disk.savedProcessGuid, "revision", disk.revision, "savePath", store.FilePath, "saveSha256", evidence.Proof.saveSha256, "sourceSaveSha256", disk.sourceSaveSha256, "exactPosition", samePosition, "exactRotation", sameRotation));
                evidence.WriteProof(); message = "已保存 / Saved"; return true;
            } catch (Exception ex) { Fail(ex.ToString()); return false; }
        }
        static int Bits(float value) { return BitConverter.ToInt32(BitConverter.GetBytes(value), 0); }
        static bool Exact(Vector3 a, Vector3 b) { return Bits(a.x) == Bits(b.x) && Bits(a.y) == Bits(b.y) && Bits(a.z) == Bits(b.z); }
        static bool Exact(Quaternion a, Quaternion b) { return Bits(a.x) == Bits(b.x) && Bits(a.y) == Bits(b.y) && Bits(a.z) == Bits(b.z) && Bits(a.w) == Bits(b.w); }
        void Fail(string detail) {
            loading = false; message = "无法继续，请检查资源或存档。 / Unable to continue."; evidence.Emit("loop_failure", JsonText.Data("detail", detail)); evidence.Proof.failure = detail;
            if (phase != "manual") CompleteAndQuit(false, detail); else evidence.WriteProof();
        }
        void CompleteAndQuit(bool success, string error) {
            if (ended) return; ended = true; if (motor) motor.InputEnabled = false; UpdateMotorProof(); evidence.Complete(success, error); Application.Quit(evidence.Proof.passed ? 0 : 20);
        }
        void OnGUI() {
            if (font) GUI.skin.font = font;
            GUI.skin.label.fontSize = 18; GUI.skin.button.fontSize = 18;
            if (!playing) {
                GUILayout.BeginArea(new Rect((Screen.width - 440) / 2f, (Screen.height - 300) / 2f, 440, 300), GUI.skin.box);
                GUILayout.Label("Manaka"); GUILayout.Space(20); GUI.enabled = !loading;
                if (GUILayout.Button("继续 / Continue", GUILayout.Height(45))) StartCoroutine(Open(true));
                if (GUILayout.Button("新建进度 / New", GUILayout.Height(45))) StartCoroutine(Open(false));
                if (GUILayout.Button("退出 / Quit", GUILayout.Height(40))) CompleteAndQuit(false, "Manual title quit");
                GUI.enabled = true; GUILayout.Label(message); GUILayout.EndArea();
            } else if (phase == "manual") {
                GUILayout.BeginArea(new Rect(15, 15, 420, 190), GUI.skin.box);
                GUILayout.Label("自宅 / Apartment"); GUILayout.Label("WASD移动 · Shift跑步 · 空格跳跃"); GUILayout.Label("右键拖动视角 / Right-drag to look");
                if (GUILayout.Button("保存 / Save")) SaveCurrent();
                if (GUILayout.Button("保存并退出 / Save & Quit") && SaveCurrent()) CompleteAndQuit(room.originalGeometry && room.originalPlayerVisual, null);
                GUILayout.Label(message); GUILayout.EndArea();
            }
        }
    }
}
