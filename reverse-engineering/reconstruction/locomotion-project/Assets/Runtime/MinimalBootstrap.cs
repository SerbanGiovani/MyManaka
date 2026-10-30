using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace ReconstructedManaka {
    [DefaultExecutionOrder(200)]
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
        LocomotionAnimatorBridge animationBridge;
        FollowCamera follow;
        GameObject actor;
        Camera view;
        string phase, seedPath, message = "", profileRoot;
        bool loading, playing, ended, saveQuitInProgress;
        int failureSerial;
        Font font;
        static string Arg(string key, string fallback = null) {
            string[] args = Environment.GetCommandLineArgs();
            for (int i = 0; i < args.Length; i++) { if (args[i] == key && i + 1 < args.Length) return args[i + 1]; if (args[i].StartsWith(key + "=", StringComparison.Ordinal)) return args[i].Substring(key.Length + 1); }
            return fallback;
        }
        void Awake() {
            DontDestroyOnLoad(gameObject); QualitySettings.vSyncCount = 0; Application.targetFrameRate = 60;
            profileRoot = Arg("--profile-root", Path.Combine(Application.persistentDataPath, "ReconstructedManaka", "locomotion-profiles", "default"));
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
            if (phase == "phase1" || phase == "phase2" || IsKeyboardPhase) { yield return CaptureProofScreenshot("title.png", true); if (ended) yield break; }
            if (phase == "phase1" || phase == "keyboard") yield return Open(false); else if (phase == "phase2" || phase == "keyboard-resume") yield return Open(true);
        }
        bool IsKeyboardPhase { get { return phase == "keyboard" || phase == "keyboard-resume"; } }
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
            controller = actor.AddComponent<CharacterController>(); controller.enabled = false; controller.height = 1.6f; controller.center = new Vector3(0, .8f, 0); controller.radius = .2f; controller.skinWidth = .0001f; controller.stepOffset = .2f; controller.slopeLimit = 45; controller.minMoveDistance = .001f;
            actor.transform.SetPositionAndRotation(state.position, state.rotation);
            room.playerVisual.transform.SetParent(actor.transform, false); room.playerVisual.transform.localPosition = room.visualOffset; room.playerVisual.transform.localRotation = Quaternion.identity;
            motor = actor.AddComponent<PlayerMotor>(); motor.cameraBasis = view.transform; motor.InputEnabled = false;
            string inputOrigin = Arg("--input-origin", "undeclared");
            motor.InputProvenance = inputOrigin == "os-injected-keyboard" ? "externally_declared_os_injection" : inputOrigin == "physical-keyboard" ? "externally_declared_physical_keyboard_unverified" : "undeclared_keyboard_device";
            follow.Bind(actor.transform);
            try { animationBridge = actor.AddComponent<LocomotionAnimatorBridge>(); animationBridge.Initialize(room, motor, evidence); }
            catch (Exception ex) { Fail("Original Animator initialization failed: " + ex); yield break; }
            evidence.Proof.sceneKey = state.sceneKey; evidence.Proof.environmentSource = room.environmentSource; evidence.Proof.playerSource = room.playerSource; evidence.Proof.originalGeometry = room.originalGeometry; evidence.Proof.originalPlayerVisual = room.originalPlayerVisual;
            evidence.Proof.geometryMeshes = room.meshes; evidence.Proof.geometryColliders = room.colliders; evidence.Proof.geometryTextures = room.textures; evidence.Proof.declaredTextures = room.declaredTextures; evidence.Proof.unresolvedBuiltinMeshes = room.unresolvedBuiltins; evidence.Proof.visualRenderers = room.visualRenderers; evidence.Proof.copiedGameBehaviours = 0; evidence.Proof.playerShaderFallbacks = room.shaderFallbacks; evidence.Proof.collisionPolicy = room.collisionPolicy; evidence.Proof.visualPolicy = room.visualPolicy; evidence.Proof.playerVisualOffset = room.visualOffset; evidence.Proof.playerVisualBoundsSize = room.visualBoundsSize;
            if (room.shaderFallbacks > 0 || room.unresolvedBuiltins > 0 || room.textures < room.declaredTextures) evidence.Proof.degradedAssetCompatibility = true;
            evidence.Proof.appliedPosition = actor.transform.position; evidence.Proof.appliedRotation = actor.transform.rotation;
            evidence.Proof.exactAppliedPosition = Exact(state.position, actor.transform.position); evidence.Proof.exactAppliedRotation = Exact(state.rotation, actor.transform.rotation);
            evidence.Proof.positionError = Vector3.Distance(state.position, actor.transform.position); evidence.Proof.rotationErrorDegrees = Quaternion.Angle(state.rotation, actor.transform.rotation);
            evidence.Emit("pose_applied_before_physics", JsonText.Data("sceneKey", state.sceneKey, "position", actor.transform.position, "rotation", actor.transform.rotation, "exactPosition", evidence.Proof.exactAppliedPosition, "exactRotation", evidence.Proof.exactAppliedRotation, "positionError", evidence.Proof.positionError, "rotationErrorDegrees", evidence.Proof.rotationErrorDegrees));
            loading = false; playing = true; message = "";
            if (phase == "phase2") { yield return ReadbackAcceptance(); yield break; }
            if (phase == "keyboard-resume") {
                if (!RecordReadback()) { Fail("Cross-process scene/pose readback failed"); yield break; }
                yield return CaptureProofScreenshot("keyboard-readback.png", false); if (ended) yield break;
            }
            controller.enabled = true; motor.InputEnabled = true;
            evidence.Emit("scene_ready", JsonText.Data("sceneKey", state.sceneKey, "position", actor.transform.position, "controller", "CharacterController", "originalGeometry", room.originalGeometry, "originalPlayerVisual", room.originalPlayerVisual));
            if (phase == "phase1") yield return MovementAcceptance();
            else if (IsKeyboardPhase) {
                evidence.Proof.inputDescription = "Waiting for Unity legacy keyboard axes/buttons. Device provenance is declared separately; Unity cannot prove physical key origin. F5 saves actual pose; F6 saves, captures GPU pixels and exits.";
                evidence.Emit("keyboard_ready", JsonText.Data("inputSource", "unity-legacy", "inputProvenance", motor.InputProvenance, "simulated", false, "focused", Application.isFocused, "keys", "WASD move; LeftShift jog; C crouch toggle; F5 save; F6 save and quit", "timeout", "none; waits for normal keyboard input", "position", actor.transform.position));
                yield return CaptureProofScreenshot("keyboard-ready.png", false);
            }
        }
        void Update() {
            if (!playing || loading || ended || saveQuitInProgress) return;
            if (Input.GetKeyDown(KeyCode.F5)) {
                evidence.Proof.keyboardSaveCommands++;
                evidence.Emit("keyboard_command", JsonText.Data("key", "F5", "action", "save", "GetKeyDown", true, "inputSource", "unity-legacy", "inputProvenance", motor.InputProvenance, "simulated", false, "focused", Application.isFocused, "position", actor.transform.position, "rotation", actor.transform.rotation));
                SaveCurrent();
            }
            if (Input.GetKeyDown(KeyCode.F6)) {
                evidence.Proof.keyboardSaveQuitCommands++;
                evidence.Emit("keyboard_command", JsonText.Data("key", "F6", "action", "save-and-quit", "GetKeyDown", true, "inputSource", "unity-legacy", "inputProvenance", motor.InputProvenance, "simulated", false, "focused", Application.isFocused, "position", actor.transform.position, "rotation", actor.transform.rotation));
                StartCoroutine(KeyboardSaveAndQuit());
            }
        }
        IEnumerator KeyboardSaveAndQuit() {
            if (saveQuitInProgress) yield break;
            bool resumeInput = motor.InputEnabled; saveQuitInProgress = true; motor.InputEnabled = false;
            try {
                if (!SaveCurrent()) yield break;
                int failuresBeforeCapture = failureSerial;
                yield return CaptureProofScreenshot("keyboard-saved.png", false);
                if (ended || failureSerial != failuresBeforeCapture) yield break;
                bool valid = room.originalGeometry && room.originalPlayerVisual && evidence.Proof.originalAnimatorController && evidence.Proof.animatorInitialized;
                CompleteAndQuit(valid, valid ? null : "Original room/player/Animator resources were not ready");
            } finally {
                // A failed save/capture keeps a manual keyboard session usable.
                if (!ended) { saveQuitInProgress = false; if (motor) motor.InputEnabled = resumeInput; }
            }
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
            motor.InputEnabled = false;
            if (!SaveCurrent()) yield break;
            yield return CaptureProofScreenshot("movement.png", false); if (ended) yield break;
            bool validAssets = room.originalGeometry && room.originalPlayerVisual;
            CompleteAndQuit(validAssets, validAssets ? null : "Original room/player resources were not supplied");
        }
        IEnumerator ReadbackAcceptance() {
            bool restored = RecordReadback();
            yield return CaptureProofScreenshot("readback.png", false); if (ended) yield break;
            CompleteAndQuit(restored && room.originalGeometry && room.originalPlayerVisual, restored ? null : "Cross-process scene/pose readback failed");
        }
        bool RecordReadback() {
            bool previousProcess = !string.IsNullOrEmpty(state.savedProcessGuid) && state.savedProcessGuid != evidence.ProcessGuid && state.revision > 0;
            bool pose = evidence.Proof.positionError <= .00001f && evidence.Proof.rotationErrorDegrees <= .001f;
            evidence.Proof.savePath = store.FilePath; evidence.Proof.saveSha256 = ManifestSceneAssets.HashFile(store.FilePath); evidence.Proof.saveRevision = state.revision; evidence.Proof.savedPosition = state.position; evidence.Proof.savedRotation = state.rotation;
            evidence.Emit("readback_verified_before_physics", JsonText.Data("previousProcess", previousProcess, "writerProcessGuid", state.savedProcessGuid, "readerProcessGuid", evidence.ProcessGuid, "sceneKey", state.sceneKey, "position", state.position, "rotation", state.rotation, "exactAppliedPosition", evidence.Proof.exactAppliedPosition, "exactAppliedRotation", evidence.Proof.exactAppliedRotation, "saveSha256", evidence.Proof.saveSha256));
            return previousProcess && pose;
        }
        IEnumerator CaptureProofScreenshot(string fileName, bool title) {
            yield return null; yield return null;
            string path = Path.Combine(Path.GetDirectoryName(evidence.Proof.proofPath), fileName);
            ScreenCapture.CaptureScreenshot(path); float deadline = Time.realtimeSinceStartup + 5;
            long previousLength = -1; int stable = 0;
            while (Time.realtimeSinceStartup < deadline) {
                long length = File.Exists(path) ? new FileInfo(path).Length : 0;
                stable = length > 100 && length == previousLength ? stable + 1 : 0; previousLength = length;
                if (stable >= 2) break; yield return null;
            }
            if (stable < 2) { Fail("GPU screenshot was not produced: " + fileName); yield break; }
            byte[] bytes = File.ReadAllBytes(path); var image = new Texture2D(2, 2, TextureFormat.RGBA32, false);
            if (!ImageConversion.LoadImage(image, bytes, false)) { Destroy(image); Fail("GPU screenshot PNG did not decode"); yield break; }
            Color32[] pixels = image.GetPixels32(); Color32 first = pixels[0]; int nonBlack = 0, different = 0;
            foreach (Color32 pixel in pixels) { if (pixel.r != 0 || pixel.g != 0 || pixel.b != 0) nonBlack++; if (pixel.r != first.r || pixel.g != first.g || pixel.b != first.b) different++; }
            bool valid = view && view.enabled && view.gameObject.activeInHierarchy && nonBlack > pixels.Length / 100 && different > pixels.Length / 200;
            string hash = ManifestSceneAssets.HashFile(path);
            evidence.Emit("screenshot_validation", JsonText.Data("path", path, "sha256", hash, "bytes", bytes.LongLength, "width", image.width, "height", image.height, "nonBlackPixels", nonBlack, "differentFromFirstPixel", different, "pixels", pixels.Length, "validated", valid, "cameraActive", view && view.gameObject.activeInHierarchy, "cameraEnabled", view && view.enabled, "cameraPosition", view.transform.position, "cameraRotation", view.transform.rotation, "cameraClearFlags", view.clearFlags.ToString(), "background", view.backgroundColor, "graphicsDevice", SystemInfo.graphicsDeviceType.ToString(), "afterReadyFrames", 2));
            if (title) { evidence.Proof.titleScreenshotPath = path; evidence.Proof.titleScreenshotSha256 = hash; evidence.Proof.titleScreenshotValidated = valid; }
            else { evidence.Proof.screenshotPath = path; evidence.Proof.screenshotBytes = bytes.LongLength; evidence.Proof.screenshotSha256 = hash; evidence.Proof.screenshotWidth = image.width; evidence.Proof.screenshotHeight = image.height; evidence.Proof.screenshotNonBlackPixels = nonBlack; evidence.Proof.screenshotDifferentPixels = different; evidence.Proof.screenshotValidated = valid; evidence.Proof.cameraActive = view.gameObject.activeInHierarchy; evidence.Proof.cameraEnabled = view.enabled; evidence.Proof.cameraPosition = view.transform.position; evidence.Proof.cameraRotation = view.transform.rotation; evidence.Proof.graphicsDevice = SystemInfo.graphicsDeviceType.ToString(); }
            Destroy(image); evidence.WriteProof();
            if (!valid) { Fail("GPU screenshot is black or single-color: " + fileName); yield break; }
            evidence.Emit("screenshot_written", JsonText.Data("path", path, "sha256", hash, "bytes", bytes.LongLength, "validated", true, "title", title));
        }
        void UpdateMotorProof() { if (!motor) return; evidence.Proof.groundedSeen = motor.GroundedSeen; evidence.Proof.inputSamples = motor.InputSamples; evidence.Proof.travelledDistance = motor.TravelledDistance; evidence.Proof.belowCollisions = motor.BelowCollisions; evidence.Proof.sideCollisions = motor.SideCollisions; }
        public bool SaveCurrent() {
            if (!playing || !actor) return false;
            Dictionary<string, int> sourcePoseBits = null, canonicalPoseBits = null, diskPoseBits = null;
            int zeroSignNormalizations = 0;
            try {
                state.sceneKey = room.sceneKey; state.position = actor.transform.position; state.rotation = actor.transform.rotation; state.savedProcessGuid = evidence.ProcessGuid;
                Vector3 sourcePosition = state.position; Quaternion sourceRotation = state.rotation;
                sourcePoseBits = SaveStore.CaptureFloatBits(state);
                zeroSignNormalizations = SaveStore.CanonicalizeSignedZero(state);
                canonicalPoseBits = SaveStore.CaptureFloatBits(state);
                evidence.Proof.lastSaveZeroSignNormalizations = zeroSignNormalizations; evidence.Proof.saveZeroSignNormalizations += zeroSignNormalizations; evidence.Proof.saveEqualityPolicy = SaveStore.FloatEqualityPolicy;
                evidence.Emit("save_pose_canonicalized", JsonText.Data("sourcePosition", sourcePosition, "sourceRotation", sourceRotation, "canonicalPosition", state.position, "canonicalRotation", state.rotation,
                    "sourcePoseBits", sourcePoseBits, "canonicalPoseBits", canonicalPoseBits, "zeroSignNormalizations", zeroSignNormalizations, "equalityPolicy", SaveStore.FloatEqualityPolicy, "actorTransformModified", false));
                store.Write(state);
                SaveState disk; string error; if (!store.TryRead(out disk, out error)) throw new IOException("Written save could not be read: " + error);
                diskPoseBits = SaveStore.CaptureFloatBits(disk);
                bool samePosition = Exact(state.position, disk.position), sameRotation = Exact(state.rotation, disk.rotation);
                bool sameFloats = SaveStore.SameFloatBits(state, disk, out string mismatches);
                bool sameIdentity = disk.sceneKey == state.sceneKey && disk.savedProcessGuid == evidence.ProcessGuid;
                evidence.Emit("save_roundtrip_verified", JsonText.Data("sourcePoseBits", sourcePoseBits, "canonicalPoseBits", canonicalPoseBits, "diskPoseBits", diskPoseBits,
                    "zeroSignNormalizations", zeroSignNormalizations, "equalityPolicy", SaveStore.FloatEqualityPolicy, "exactCanonicalFloatBits", sameFloats, "sameSceneAndWriter", sameIdentity, "mismatches", mismatches));
                if (!sameFloats || !sameIdentity) throw new IOException("Saved canonical values did not survive JSON roundtrip: " + (sameFloats ? "sceneKey/savedProcessGuid differs" : mismatches));
                evidence.Proof.exactStoredPosition = samePosition; evidence.Proof.exactStoredRotation = sameRotation; evidence.Proof.savedPosition = disk.position; evidence.Proof.savedRotation = disk.rotation; evidence.Proof.savePath = store.FilePath; evidence.Proof.saveSha256 = ManifestSceneAssets.HashFile(store.FilePath); evidence.Proof.saveRevision = disk.revision;
                evidence.Emit("save_completed", JsonText.Data("sceneKey", disk.sceneKey, "position", disk.position, "rotation", disk.rotation, "processGuid", disk.savedProcessGuid, "revision", disk.revision, "savePath", store.FilePath, "saveSha256", evidence.Proof.saveSha256, "sourceSaveSha256", disk.sourceSaveSha256, "exactPosition", samePosition, "exactRotation", sameRotation,
                    "sourcePoseBits", sourcePoseBits, "canonicalPoseBits", canonicalPoseBits, "diskPoseBits", diskPoseBits, "zeroSignNormalizations", zeroSignNormalizations, "equalityPolicy", SaveStore.FloatEqualityPolicy));
                evidence.WriteProof(); message = "已保存 / Saved"; return true;
            } catch (Exception ex) {
                evidence.Emit("save_failed", JsonText.Data("detail", ex.ToString(), "sourcePoseBits", sourcePoseBits, "canonicalPoseBits", canonicalPoseBits, "diskPoseBits", diskPoseBits, "zeroSignNormalizations", zeroSignNormalizations, "equalityPolicy", SaveStore.FloatEqualityPolicy));
                Fail(ex.ToString()); message = "保存失败 / Save failed: " + ex.Message + " · F5重试 / retry"; return false;
            }
        }
        static int Bits(float value) { return BitConverter.ToInt32(BitConverter.GetBytes(value), 0); }
        static bool Exact(Vector3 a, Vector3 b) { return Bits(a.x) == Bits(b.x) && Bits(a.y) == Bits(b.y) && Bits(a.z) == Bits(b.z); }
        static bool Exact(Quaternion a, Quaternion b) { return Bits(a.x) == Bits(b.x) && Bits(a.y) == Bits(b.y) && Bits(a.z) == Bits(b.z) && Bits(a.w) == Bits(b.w); }
        void Fail(string detail) {
            failureSerial++; loading = false; message = "操作失败，请检查资源或存档。 / Operation failed; check resources or save.";
            bool automaticAcceptance = phase == "phase1" || phase == "phase2";
            evidence.Emit("loop_failure", JsonText.Data("detail", detail, "automaticExit", automaticAcceptance, "windowKeptOpen", !automaticAcceptance)); evidence.Proof.failure = detail;
            if (automaticAcceptance) CompleteAndQuit(false, detail); else evidence.WriteProof();
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
            } else if (phase == "manual" || IsKeyboardPhase) {
                GUILayout.BeginArea(new Rect(15, 15, 520, 300), GUI.skin.box);
                GUILayout.Label("自宅 / Apartment · Original Animator"); GUILayout.Label("WASD移动 · Left Shift慢跑 · C蹲姿"); GUILayout.Label("右键拖动视角 / Right-drag to look");
                GUILayout.Label("F5保存 / Save · F6保存并退出 / Save & Quit");
                if (IsKeyboardPhase) GUILayout.Label("等待键盘：走动 → Shift慢跑 → 松开回Idle → F5 → F6");
                if (motor && motor.CurrentInput != null) {
                    GUILayout.Label("Unity axes: " + motor.CurrentInput.unityAxes + " · Focus: " + Application.isFocused);
                    GUILayout.Label("Speed: " + motor.CurrentSpeed.ToString("F2") + " · Crouch: " + motor.IsCrouch + " · Frames: " + evidence.Proof.locomotionFrames);
                    GUILayout.Label("Walk/Jog input frames: " + evidence.Proof.movingKeyboardFrames + " · Bone changes: " + evidence.Proof.animatorBoneChangeFrames);
                    GUILayout.Label("F5 saves: " + evidence.Proof.keyboardSaveCommands + " · Input provenance: " + motor.InputProvenance);
                }
                if (GUILayout.Button("保存 / Save")) SaveCurrent();
                if (GUILayout.Button("保存并退出 / Save & Quit")) StartCoroutine(KeyboardSaveAndQuit());
                GUILayout.Label(message); GUILayout.EndArea();
            }
        }
    }
}
