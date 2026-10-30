using System;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

namespace ReconstructedManaka {
    // Motor.Update runs before this component. Unity evaluates the original Animator
    // after Update, and LateUpdate records its evaluated bones and current clip weights.
    [DefaultExecutionOrder(100)]
    public sealed class LocomotionAnimatorBridge : MonoBehaviour {
        Animator animator;
        PlayerMotor motor;
        RunEvidence evidence;
        readonly Dictionary<string, AnimatorControllerParameterType> parameters = new Dictionary<string, AnimatorControllerParameterType>();
        readonly List<Transform> bones = new List<Transform>();
        readonly Dictionary<Transform, Quaternion> previousBoneRotations = new Dictionary<Transform, Quaternion>();
        readonly Dictionary<int, int> previousStates = new Dictionary<int, int>();
        Transform visualRoot;
        bool ready;
        float previousProofTime;
        public Animator Animator { get { return animator; } }
        public void Initialize(SceneAssetResult room, PlayerMotor movement, RunEvidence run) {
            motor = movement; evidence = run; animator = room.playerAnimator; visualRoot = room.playerVisual.transform;
            if (!animator || !animator.avatar || !animator.runtimeAnimatorController) throw new InvalidOperationException("Original Animator references are incomplete");
            var receiver = animator.gameObject.AddComponent<LocomotionAnimationEvents>(); receiver.Initialize(run, movement, animator);
            // Source prefab assets are inactive and expose zero runtime parameters/layers.
            // Enumerate only after activating and rebinding this independent Animator.
            animator.enabled = true; animator.Rebind(); animator.Update(0);
            var sourceLayerWeights = new List<object>();
            for (int layer = 1; layer < animator.layerCount; layer++) {
                sourceLayerWeights.Add(JsonText.Data("layer", layer, "name", animator.GetLayerName(layer), "weightBeforeIsolation", animator.GetLayerWeight(layer)));
                animator.SetLayerWeight(layer, 0);
            }
            foreach (var parameter in animator.parameters) parameters.Add(parameter.name, parameter.type);
            RequireParameter("Speed", AnimatorControllerParameterType.Float);
            RequireParameter("LocomotionMotionSpeed", AnimatorControllerParameterType.Float);
            RequireParameter("IsStrafe", AnimatorControllerParameterType.Bool);
            RequireParameter("StrafeX", AnimatorControllerParameterType.Float);
            RequireParameter("StrafeY", AnimatorControllerParameterType.Float);
            RequireParameter("IsCrouch", AnimatorControllerParameterType.Bool);
            DriveParameters(); animator.Update(0);
            HumanBodyBones[] sampled = { HumanBodyBones.Hips, HumanBodyBones.Spine, HumanBodyBones.Head, HumanBodyBones.LeftUpperLeg, HumanBodyBones.LeftLowerLeg, HumanBodyBones.LeftFoot, HumanBodyBones.RightUpperLeg, HumanBodyBones.RightLowerLeg, HumanBodyBones.RightFoot, HumanBodyBones.LeftUpperArm, HumanBodyBones.RightUpperArm };
            if (animator.isHuman) foreach (var bone in sampled) { Transform t = animator.GetBoneTransform(bone); if (t && !bones.Contains(t)) bones.Add(t); }
            if (bones.Count == 0) foreach (var skin in visualRoot.GetComponentsInChildren<SkinnedMeshRenderer>(true)) foreach (Transform bone in skin.bones) {
                if (bone && bone != visualRoot && !bones.Contains(bone)) bones.Add(bone); if (bones.Count >= 12) break;
            }
            foreach (Transform bone in bones) previousBoneRotations[bone] = bone.localRotation;
            var controller = animator.runtimeAnimatorController;
            var clips = controller.animationClips.Distinct().Select(clip => JsonText.Data("name", clip.name, "instanceId", clip.GetInstanceID(), "length", clip.length, "frameRate", clip.frameRate, "legacy", clip.legacy, "humanMotion", clip.humanMotion)).ToArray();
            var declaredParameters = animator.parameters.Select(p => JsonText.Data("name", p.name, "nameHash", p.nameHash, "type", p.type.ToString(), "defaultFloat", p.defaultFloat, "defaultInt", p.defaultInt, "defaultBool", p.defaultBool)).ToArray();
            evidence.Proof.originalAnimatorController = true; evidence.Proof.originalAnimatorAvatar = true; evidence.Proof.animatorInitialized = animator.isInitialized;
            evidence.Proof.animatorControllerName = room.animatorControllerName; evidence.Proof.animatorAvatarName = room.animatorAvatarName; evidence.Proof.animatorPath = room.animatorPath;
            evidence.Proof.inputProvenance = motor.InputProvenance;
            evidence.Emit("animator_bound", JsonText.Data("playerSource", room.playerSource, "animatorPath", room.animatorPath, "sourceAnimatorCount", room.sourceAnimators,
                "controller", JsonText.Data("name", controller.name, "instanceId", controller.GetInstanceID(), "sourceInstanceId", room.animatorControllerInstanceId, "sameReference", room.animatorControllerSameReference, "source", "original prefab Animator.runtimeAnimatorController reference"),
                "avatar", JsonText.Data("name", animator.avatar.name, "instanceId", animator.avatar.GetInstanceID(), "sourceInstanceId", room.animatorAvatarInstanceId, "sameReference", room.animatorAvatarSameReference, "valid", animator.avatar.isValid, "human", animator.avatar.isHuman, "source", "original prefab Animator.avatar reference"),
                "enabled", animator.enabled, "isInitialized", animator.isInitialized, "layers", animator.layerCount, "applyRootMotion", animator.applyRootMotion, "fireEvents", animator.fireEvents, "gameBehavioursCopied", 0,
                "parameters", declaredParameters, "clips", clips, "sampledBonePaths", bones.Select(b => PathOf(b, visualRoot)).ToArray(), "ancillaryLayerWeightsBeforeIsolation", sourceLayerWeights,
                "layerPolicy", "original full controller reference retained; layer 0 Locomotion is evaluated; ancillary action, clothing, arm and face layers have weight 0 in this independent locomotion scope",
                "parameterPolicy", "native animation target=input magnitude*(dash?2:1), including crouch; original blend thresholds idle=0 walk=1 jog=2, crouch saturates at .5; independent animation smoothing; LocomotionMotionSpeed=1; IsStrafe=false; StrafeX/Y=0",
                "movementPolicy", "original base walk/jog/crouch speeds, world/animation SmoothFloat rates and CharacterController dimensions; reconstructed turning, gravity and Update integration; no Jump binding",
                "movementConfiguration", JsonText.Data("walk", motor.walkSpeed, "jog", motor.jogSpeed, "crouch", motor.crouchSpeed, "worldRisePerSecond", motor.acceleration, "worldFallPerSecond", motor.deceleration, "animationRisePerSecond", motor.animationAcceleration, "animationFallPerSecond", motor.animationDeceleration, "turnDegreesPerSecond", motor.turnDegreesPerSecond, "gravity", motor.gravity)));
            ready = true; evidence.WriteProof();
        }
        void RequireParameter(string name, AnimatorControllerParameterType type) {
            if (!parameters.TryGetValue(name, out var found) || found != type) throw new InvalidOperationException("Original Animator parameter missing or mismatched: " + name);
        }
        void Update() { if (ready) DriveParameters(); }
        void DriveParameters() {
            animator.SetFloat("Speed", motor.AnimationSpeed); animator.SetFloat("LocomotionMotionSpeed", 1);
            animator.SetBool("IsCrouch", motor.IsCrouch); animator.SetBool("IsStrafe", false); animator.SetFloat("StrafeX", 0); animator.SetFloat("StrafeY", 0);
        }
        Dictionary<string, object> ParameterValues() {
            var values = new Dictionary<string, object>();
            foreach (var p in animator.parameters) {
                if (p.type == AnimatorControllerParameterType.Float) values[p.name] = animator.GetFloat(p.nameHash);
                else if (p.type == AnimatorControllerParameterType.Int) values[p.name] = animator.GetInteger(p.nameHash);
                else if (p.type == AnimatorControllerParameterType.Bool) values[p.name] = animator.GetBool(p.nameHash);
            }
            return values;
        }
        void LateUpdate() {
            if (!ready || motor.CurrentInput == null) return;
            var layerSamples = new List<object>();
            for (int layer = 0; layer < animator.layerCount; layer++) {
                AnimatorStateInfo state = animator.GetCurrentAnimatorStateInfo(layer); bool transitioning = animator.IsInTransition(layer);
                AnimatorStateInfo next = transitioning ? animator.GetNextAnimatorStateInfo(layer) : default(AnimatorStateInfo);
                if (previousStates.TryGetValue(layer, out int previous) && previous != state.fullPathHash) {
                    evidence.Proof.animatorStateChanges++;
                    evidence.Emit("animator_state_changed", JsonText.Data("layer", layer, "layerName", animator.GetLayerName(layer), "previousFullPathHash", previous, "fullPathHash", state.fullPathHash, "shortNameHash", state.shortNameHash, "normalizedTime", state.normalizedTime));
                }
                previousStates[layer] = state.fullPathHash;
                var clips = animator.GetCurrentAnimatorClipInfo(layer).Select(c => JsonText.Data("name", c.clip ? c.clip.name : "", "instanceId", c.clip ? c.clip.GetInstanceID() : 0, "length", c.clip ? c.clip.length : 0, "weight", c.weight)).ToArray();
                layerSamples.Add(JsonText.Data("layer", layer, "layerName", animator.GetLayerName(layer), "layerWeight", animator.GetLayerWeight(layer), "stateName", KnownState(state.fullPathHash), "fullPathHash", state.fullPathHash, "shortNameHash", state.shortNameHash, "normalizedTime", state.normalizedTime, "length", state.length, "speed", state.speed, "speedMultiplier", state.speedMultiplier, "inTransition", transitioning, "nextFullPathHash", next.fullPathHash, "clips", clips));
            }
            var boneSamples = new List<object>(); float maximumDelta = 0;
            foreach (Transform bone in bones) {
                float delta = Quaternion.Angle(previousBoneRotations[bone], bone.localRotation); maximumDelta = Mathf.Max(maximumDelta, delta);
                boneSamples.Add(JsonText.Data("path", PathOf(bone, visualRoot), "localPosition", bone.localPosition, "localRotation", bone.localRotation, "rotationDeltaDegrees", delta));
                previousBoneRotations[bone] = bone.localRotation;
            }
            if (maximumDelta > .01f) { evidence.Proof.animatorBonesChanged = true; evidence.Proof.animatorBoneChangeFrames++; }
            evidence.Proof.animatorMaximumBoneRotationDelta = Mathf.Max(evidence.Proof.animatorMaximumBoneRotationDelta, maximumDelta);
            evidence.Proof.animatorInitialized = animator.isInitialized;
            LocomotionInput input = motor.CurrentInput;
            evidence.Proof.locomotionFrames++;
            if (input.simulated) evidence.Proof.simulatedAxisFrames++;
            else {
                evidence.Proof.unityKeyboardFrames++;
                if (input.axes.sqrMagnitude > .001f) evidence.Proof.movingKeyboardFrames++;
                evidence.Proof.keyboardTravelledDistance += Vector3.ProjectOnPlane(motor.PositionAfterStep - motor.PositionBeforeStep, Vector3.up).magnitude;
            }
            evidence.Emit("locomotion_sample", JsonText.Data("inputSource", input.inputSource, "inputProvenance", input.inputProvenance, "simulated", input.simulated, "focused", input.focused,
                "axes", input.axes, "unityAxes", input.unityAxes, "resolvedAxes", motor.ResolvedAxes, "keys", input.keys, "keyDown", input.keyDown, "keyUp", input.keyUp,
                "inputEnabled", motor.InputEnabled, "positionBefore", motor.PositionBeforeStep, "positionAfter", transform.position, "rotation", transform.rotation, "dt", motor.LastDeltaTime,
                "currentSpeed", motor.CurrentSpeed, "targetSpeed", motor.TargetSpeed, "animationSpeed", motor.AnimationSpeed, "targetAnimationSpeed", motor.TargetAnimationSpeed, "sprint", motor.SprintActive, "crouch", motor.IsCrouch, "grounded", motor.IsGrounded, "groundedSeen", motor.GroundedSeen, "collisionFlags", (int)motor.LastCollisionFlags,
                "animator", JsonText.Data("enabled", animator.enabled, "active", animator.gameObject.activeInHierarchy, "isInitialized", animator.isInitialized, "speed", animator.speed, "applyRootMotion", animator.applyRootMotion, "parameters", ParameterValues(), "layers", layerSamples, "bones", boneSamples, "maximumBoneRotationDeltaDegrees", maximumDelta)));
            if (Time.realtimeSinceStartup - previousProofTime >= 1) { previousProofTime = Time.realtimeSinceStartup; evidence.WriteProof(); }
        }
        static string KnownState(int hash) { if (hash == 686120411) return "Locomotion.LocomotionTree"; if (hash == 1097057632) return "Locomotion.CrouchTree"; return ""; }
        static string PathOf(Transform value, Transform root) { var parts = new List<string>(); while (value && value != root) { parts.Add(value.name); value = value.parent; } parts.Reverse(); return string.Join("/", parts); }
    }

    public sealed class LocomotionAnimationEvents : MonoBehaviour {
        RunEvidence evidence; PlayerMotor motor; Animator animator;
        public void Initialize(RunEvidence run, PlayerMotor movement, Animator source) { evidence = run; motor = movement; animator = source; }
        public void FootL(int value) { Record("FootL", value); }
        public void FootR(int value) { Record("FootR", value); }
        void Record(string function, int value) {
            if (!evidence || !animator) return;
            var state = animator.GetCurrentAnimatorStateInfo(0);
            evidence.Emit("animation_event", JsonText.Data("function", function, "intParameter", value, "receiver", "independent locomotion event collector; audio not implemented", "inputSource", motor.CurrentInput == null ? "not-sampled" : motor.CurrentInput.inputSource, "position", motor.transform.position, "fullPathHash", state.fullPathHash, "normalizedTime", state.normalizedTime, "Speed", animator.GetFloat("Speed")));
        }
    }
}
