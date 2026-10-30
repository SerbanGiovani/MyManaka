using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using UnityEngine;

namespace ReconstructedManaka {
    [DefaultExecutionOrder(-100)]
    public sealed class InteractionManager : MonoBehaviour {
        readonly List<InteractionTarget> candidates = new List<InteractionTarget>();
        readonly List<InteractionTarget> targets = new List<InteractionTarget>();
        RunEvidence evidence;
        PlayerMotor motor;
        LocomotionAnimatorBridge locomotion;
        PlayerAction action;
        bool ready, fDown, fHeld, fUp, attemptAccepted;
        string attemptReason = "no-F-edge";
        int enterSerial;
        bool simulatedF, simulatedHeld, previousSimulatedHeld;
        public event Action<int, int> ItemCollected;
        public CharacterController PlayerController { get; private set; }
        public PlayerAction Action { get { return action; } }
        public InteractionTarget Selected { get { return candidates.Count == 0 ? null : candidates[candidates.Count - 1]; } }
        public Vector3 FixturePosition { get { return targets[0].VisualRoot.transform.position; } }
        public void SetSimulatedF(bool enabled, bool held) { simulatedF = enabled; simulatedHeld = held; }
        public string Prompt { get { return !ready ? "交互资源载入中 / Loading interaction" : action.Active ? action.Current.name + " · 动作进行中 / Acting" : Selected ? "F · " + Selected.Definition.label : "走近钥匙，再按 F / Approach the key and press F"; } }
        public IEnumerator Initialize(string path, SceneAssetResult room, ManifestSceneAssets assets, PlayerMotor movement, LocomotionAnimatorBridge animation, RunEvidence run, Action<string> failed) {
            evidence = run; motor = movement; locomotion = animation; PlayerController = motor.GetComponent<CharacterController>();
            InteractionManifest manifest = null;
            try {
                manifest = JsonUtility.FromJson<InteractionManifest>(File.ReadAllText(path));
                if (manifest == null || manifest.schemaVersion != 1 || manifest.sceneKey != room.sceneKey || manifest.noneActionId != -1 || manifest.actions == null || manifest.actions.Length == 0 || manifest.targets == null || manifest.targets.Length == 0 || string.IsNullOrEmpty(manifest.sourceEvidence))
                    throw new InvalidDataException("A source-backed finite original interaction manifest is required");
                action = gameObject.AddComponent<PlayerAction>(); var bridge = gameObject.AddComponent<ActionAnimatorBridge>();
                bridge.Initialize(animation.Animator, action, manifest, run); action.Initialize(manifest, run, bridge); motor.Action = action; action.OriginalCompletion += CollectOriginalTarget;
                evidence.Emit("interaction_manifest_loaded", JsonText.Data("path", Path.GetFullPath(path), "sha256", ManifestSceneAssets.HashFile(path), "scope", manifest.scope, "sourceScene", manifest.sourceScene, "sourceBundleSha256", manifest.sourceBundleSha256, "sourceEvidence", manifest.sourceEvidence,
                    "candidatePolicy", "original Register appends; GetHead selects the most recently entered live candidate", "inputPolicy", "normal runs use Unity legacy F GetKeyDown with focus; controlled mode is explicitly simulated and does not establish keyboard reception; held F does not restart", "movementPolicy", "selected original MActionRecord.CanMove gates ordinary input targets; original world/animation smooth decay and CharacterController gravity continue"));
            } catch (Exception ex) { failed(ex.ToString()); yield break; }
            foreach (InteractionTargetDefinition definition in manifest.targets) {
                GameObject root = null; string loadError = null;
                if (definition.visual != null && !string.IsNullOrEmpty(definition.visual.bundle)) {
                    yield return assets.LoadInteractionVisual(definition.visual, room, value => root = value, value => loadError = value);
                    if (loadError != null) { failed(loadError); yield break; }
                } else if (room.sourceNodes.TryGetValue(definition.sourcePathId, out Transform sourceNode)) root = sourceNode.gameObject;
                try {
                    if (!root || !definition.originalSource || definition.trigger == null || !definition.trigger.isTrigger || string.IsNullOrEmpty(definition.sourceEvidence)) throw new InvalidDataException("Original interaction target or trigger provenance is incomplete");
                    if (!manifest.actions.Any(value => value.id == definition.actionId)) throw new InvalidDataException("Target action is outside the bounded original contract");
                    if (definition.visual != null) { root.transform.position = definition.worldPosition; root.transform.rotation = definition.worldRotation; root.transform.localScale = definition.worldScale; }
                    Transform triggerOwner = string.IsNullOrEmpty(definition.triggerPath) ? root.transform : root.transform.Find(definition.triggerPath);
                    if (!triggerOwner) throw new InvalidDataException("Exact original trigger child is absent: " + definition.triggerPath);
                    var target = triggerOwner.gameObject.AddComponent<InteractionTarget>(); target.Initialize(this, definition, root); targets.Add(target);
                    evidence.Emit("interaction_target_registered", JsonText.Data("targetId", definition.id, "label", definition.label, "originalSource", definition.originalSource, "sourcePathId", definition.sourcePathId, "sourcePath", definition.sourcePath,
                        "sourceScene", definition.sourceScene, "sourceBundleSha256", definition.sourceBundleSha256, "sourceEvidence", definition.sourceEvidence, "fixturePlacement", definition.placementProvenance,
                        "position", root.transform.position, "rotation", root.transform.rotation, "scale", root.transform.lossyScale, "actionId", definition.actionId, "targetInstanceId", root.GetInstanceID(), "triggerId", target.Trigger.GetInstanceID(), "triggerInstanceId", target.Trigger.GetInstanceID(), "originalComponent", definition.originalComponent,
                        "trigger", definition.trigger, "rejectCrouch", definition.rejectCrouch, "guardEvidence", definition.guardEvidence, "candidateMethod", "OnTriggerEnter/OnTriggerExit; last entered first", "playerColliderInstanceId", PlayerController.GetInstanceID(), "gameBehavioursCopied", 0,
                        "fixtureRecreatedThisProcess", definition.visual != null, "fixturePolicy", "original dropped-key prefab deliberately placed for this independent process; not an original Apartment target or natural respawn"));
                } catch (Exception ex) { failed(ex.ToString()); yield break; }
            }
            ready = true;
            evidence.Emit("interaction_ready", JsonText.Data("targetCount", targets.Count, "position", transform.position, "inputSource", "unity-legacy", "inputProvenance", motor.InputProvenance, "simulated", false, "focused", Application.isFocused));
        }
        public void Register(InteractionTarget target, Collider other, bool entering) {
            if (other != PlayerController) return;
            if (entering) {
                candidates.Remove(target); target.EnterSerial = ++enterSerial; target.Overlapping = true; candidates.Add(target);
            } else { target.Overlapping = false; candidates.Remove(target); }
            evidence.Emit("interaction_trigger", JsonText.Data("phase", entering ? "enter" : "exit", "via", entering ? "OnTriggerEnter" : "OnTriggerExit", "targetId", target.Definition.id,
                "triggerId", target.Trigger.GetInstanceID(), "triggerInstanceId", target.Trigger.GetInstanceID(), "colliderInstanceId", other.GetInstanceID(), "otherColliderInstanceId", other.GetInstanceID(), "otherIsPlayerController", true, "playerColliderInstanceId", PlayerController.GetInstanceID(),
                "enterSerial", target.EnterSerial, "actualOverlap", entering, "overlapEvidence", "Unity physics trigger callback for the actual player CharacterController", "selectedTargetId", Selected ? Selected.Definition.id : null, "position", transform.position));
        }
        void CollectOriginalTarget(string targetId, int sequence) {
            InteractionTarget target = targets.FirstOrDefault(value => value.Definition.id == targetId);
            if (!target || !target.Definition.collectOnCompletion) return;
            target.Overlapping = false; candidates.Remove(target); target.VisualRoot.SetActive(false);
            evidence.Emit("interaction_target_collected", JsonText.Data("targetId", targetId, "sequence", sequence, "itemId", target.Definition.collectItemId, "countDelta", 1, "active", target.VisualRoot.activeSelf, "source", "original-animation-event", "sourceEvidence", target.Definition.sourceEvidence));
            ItemCollected?.Invoke(target.Definition.collectItemId, 1);
        }
        void Update() {
            if (!ready) return;
            action.TickOriginalCompletion();
            fDown = simulatedF ? simulatedHeld && !previousSimulatedHeld : Input.GetKeyDown(KeyCode.F);
            fHeld = simulatedF ? simulatedHeld : Input.GetKey(KeyCode.F); fUp = simulatedF ? !simulatedHeld && previousSimulatedHeld : Input.GetKeyUp(KeyCode.F);
            previousSimulatedHeld = simulatedHeld;
            attemptAccepted = false; attemptReason = "no-F-edge";
            if (!fDown) return;
            InteractionTarget selected = Selected; int previous = action.Id; bool canMoveBefore = action.CanMove; int beforeSequence = action.Sequence;
            attemptReason = !Application.isFocused && !simulatedF ? "not-focused" : !motor.InputEnabled ? "input-disabled" : action.Active ? "action-busy" : !selected ? "no-target" : !selected.Overlapping ? "not-overlapping" : selected.Definition.rejectCrouch && motor.IsCrouch ? "crouch-guard" : "accepted";
            if (attemptReason == "accepted") { attemptAccepted = action.TryStart(selected.Definition.actionId, selected.Definition.id); if (!attemptAccepted) attemptReason = "action-guard-rejected"; }
            evidence.Emit("interaction_attempt", JsonText.Data("key", "F", "GetKeyDown", !simulatedF && fDown, "fDown", fDown, "fHeld", fHeld, "fUp", fUp, "focused", Application.isFocused, "inputSource", simulatedF ? "simulated-keys" : "unity-legacy", "inputProvenance", simulatedF ? "internal_controlled_F" : motor.InputProvenance, "simulated", simulatedF,
                "inputEnabled", motor.InputEnabled, "targetId", selected ? selected.Definition.id : null, "selectedTargetId", selected ? selected.Definition.id : null, "selected", selected != null, "beforeActionId", previous, "canMoveBefore", canMoveBefore, "crouch", motor.IsCrouch,
                "beforeSequence", beforeSequence, "sequence", action.Sequence, "accepted", attemptAccepted, "reason", attemptReason));
        }
        // Execution order -100 makes this run before the locomotion bridge's LateUpdate.
        // Capture after all animation evaluation via a separate order-150 sampler.
        public void RecordSample() {
            if (!ready || motor.CurrentInput == null) return;
            var input = motor.CurrentInput;
            evidence.Emit("interaction_sample", JsonText.Data("inputSource", input.inputSource, "inputProvenance", input.inputProvenance, "simulated", input.simulated, "focused", input.focused,
                "fDown", fDown, "fHeld", fHeld, "fUp", fUp, "actualUnityFDown", Input.GetKeyDown(KeyCode.F), "actualUnityFHeld", Input.GetKey(KeyCode.F), "actualUnityFUp", Input.GetKeyUp(KeyCode.F), "simulatedF", simulatedF, "inputEnabled", motor.InputEnabled, "keys", input.keys, "keyDown", input.keyDown, "keyUp", input.keyUp,
                "candidates", candidates.Select(target => JsonText.Data("targetId", target.Definition.id, "sourcePathId", target.Definition.sourcePathId, "sourcePath", target.Definition.sourcePath, "enterSerial", target.EnterSerial, "overlapping", target.Overlapping)).ToArray(),
                "selectedTargetId", Selected ? Selected.Definition.id : null, "playerAction", action.Snapshot(), "guard", JsonText.Data("accepted", attemptAccepted, "reason", attemptReason),
                "positionBefore", motor.PositionBeforeStep, "positionAfter", motor.PositionAfterStep, "rotation", transform.rotation, "axes", input.axes, "unityAxes", input.unityAxes, "resolvedAxes", motor.ResolvedAxes, "motionDirection", motor.MotionDirection,
                "dt", motor.LastDeltaTime, "currentSpeed", motor.CurrentSpeed, "targetSpeed", motor.TargetSpeed, "animationSpeed", motor.AnimationSpeed, "targetAnimationSpeed", motor.TargetAnimationSpeed, "controllerMoveCalled", motor.ControllerMoveCalled,
                "collisionFlags", (int)motor.LastCollisionFlags, "animator", locomotion.CurrentAnimatorSample));
        }
        public void DrawTargetPrompts(Camera camera) {
            if (!ready || !camera) return;
            foreach (InteractionTarget target in targets) {
                if (!target.VisualRoot.activeInHierarchy) continue;
                Vector3 screen = camera.WorldToScreenPoint(target.VisualRoot.transform.position + Vector3.up * .25f);
                if (screen.z > 0 && screen.x > 0 && screen.x < Screen.width && screen.y > 0 && screen.y < Screen.height)
                    GUI.Label(new Rect(screen.x - 80, Screen.height - screen.y - 20, 220, 40), "钥匙 / Key" + (target == Selected ? "  [F]" : ""));
            }
        }
    }
    public sealed class InteractionTarget : MonoBehaviour {
        InteractionManager manager;
        public InteractionTargetDefinition Definition { get; private set; }
        public Collider Trigger { get; private set; }
        public int EnterSerial { get; set; }
        public bool Overlapping { get; set; }
        public GameObject VisualRoot { get; private set; }
        public void Initialize(InteractionManager value, InteractionTargetDefinition definition, GameObject root) {
            manager = value; Definition = definition; VisualRoot = root; TriggerDefinition shape = definition.trigger;
            Trigger = GetComponents<Collider>().SingleOrDefault(collider => collider.isTrigger);
            bool originalShape = Trigger is SphereCollider sphere && shape.shape == "Sphere" && sphere.center == shape.center && sphere.radius == shape.radius
                || Trigger is BoxCollider box && shape.shape == "Box" && box.center == shape.center && box.size == shape.size
                || Trigger is CapsuleCollider capsule && shape.shape == "Capsule" && capsule.center == shape.center && capsule.radius == shape.radius && capsule.height == shape.height && capsule.direction == shape.direction;
            if (!originalShape) throw new InvalidDataException("Native copied original trigger differs from the evidence contract");
            // The original trigger shape is retained. A kinematic rigidbody is an
            // independent Unity physics adapter for CharacterController callbacks.
            var body = gameObject.AddComponent<Rigidbody>(); body.isKinematic = true; body.useGravity = false;
        }
        void OnTriggerEnter(Collider other) { manager.Register(this, other, true); }
        void OnTriggerExit(Collider other) { manager.Register(this, other, false); }
    }
    [DefaultExecutionOrder(150)]
    public sealed class InteractionSampleRecorder : MonoBehaviour {
        public InteractionManager manager;
        void LateUpdate() { if (manager) manager.RecordSample(); }
    }
}
