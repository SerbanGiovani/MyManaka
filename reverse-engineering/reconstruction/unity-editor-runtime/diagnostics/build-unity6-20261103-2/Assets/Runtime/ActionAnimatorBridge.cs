using System;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

namespace ReconstructedManaka {
    public sealed class ActionAnimatorBridge : MonoBehaviour {
        Animator animator;
        PlayerAction action;
        RunEvidence evidence;
        RuntimeAnimatorController originalController;
        readonly Dictionary<string, AnimationClip> originalClips = new Dictionary<string, AnimationClip>();
        readonly Dictionary<string, AnimatorControllerParameterType> parameters = new Dictionary<string, AnimatorControllerParameterType>();
        public Animator Animator { get { return animator; } }
        public void Initialize(Animator source, PlayerAction state, InteractionManifest manifest, RunEvidence run) {
            animator = source; action = state; evidence = run; originalController = animator.runtimeAnimatorController;
            foreach (AnimationClip clip in originalController.animationClips.Distinct()) if (!originalClips.ContainsKey(clip.name)) originalClips.Add(clip.name, clip);
            foreach (var parameter in animator.parameters) parameters.Add(parameter.name, parameter.type);
            foreach (ActionDefinition definition in manifest.actions) {
                int layer = animator.GetLayerIndex(definition.layerName);
                if (layer < 0 || !animator.HasState(layer, definition.stateFullPathHash) || Animator.StringToHash(definition.statePath) != definition.stateFullPathHash)
                    throw new InvalidOperationException("Original action state is unavailable: " + definition.statePath);
                if (!originalClips.TryGetValue(definition.completion.clipName, out AnimationClip clip) || definition.clipName != clip.name)
                    throw new InvalidOperationException("Original completion clip is unavailable: " + definition.completion.clipName);
                if (!clip.events.Any(e => e.functionName == definition.completion.function && Mathf.Abs(e.time - definition.completion.eventTime) < .001f && e.intParameter == definition.completion.intParameter))
                    throw new InvalidOperationException("Original completion event differs: " + definition.completion.function);
                ValidateWrites(definition.enterParameters); ValidateWrites(definition.exitParameters);
                foreach (LayerWeight weight in definition.layers) {
                    int index = animator.GetLayerIndex(weight.name);
                    if (index < 0) throw new InvalidOperationException("Original action dependency layer missing: " + weight.name);
                    animator.SetLayerWeight(index, weight.weight);
                }
                evidence.Emit("action_definition_bound", JsonText.Data("actionId", definition.id, "name", definition.name, "canMove", definition.canMove, "sourceEvidence", definition.sourceEvidence,
                    "layer", layer, "layerName", definition.layerName, "statePath", definition.statePath, "stateFullPathHash", definition.stateFullPathHash, "clipName", clip.name, "clipInstanceId", clip.GetInstanceID(),
                    "animatorInstanceId", animator.GetInstanceID(), "controllerInstanceId", originalController.GetInstanceID(), "controllerName", originalController.name, "sameReference", animator.runtimeAnimatorController == originalController,
                    "enterParameters", definition.enterParameters, "exitParameters", definition.exitParameters, "layers", definition.layers, "completion", definition.completion,
                    "originalClipEvents", clip.events.Select(e => JsonText.Data("function", e.functionName, "time", e.time, "intParameter", e.intParameter, "floatParameter", e.floatParameter, "stringParameter", e.stringParameter)).ToArray()));
            }
            var receiver = animator.GetComponent<LocomotionAnimationEvents>();
            if (!receiver) throw new InvalidOperationException("Original animation event collector was not initialized");
            receiver.BindActions(this);
        }
        void ValidateWrites(ParameterWrite[] writes) {
            if (writes == null || writes.Length == 0) throw new InvalidOperationException("An original action transition must declare its original parameter writes");
            foreach (ParameterWrite write in writes) {
                AnimatorControllerParameterType expected;
                if (!Enum.TryParse(write.type, out expected) || !parameters.TryGetValue(write.name, out AnimatorControllerParameterType actual) || actual != expected)
                    throw new InvalidOperationException("Original action parameter missing or mismatched: " + write.name);
                if (!string.IsNullOrEmpty(write.valueSource) && write.valueSource != "previousActionId" && write.valueSource != "actionId")
                    throw new InvalidOperationException("Unsupported original action parameter value source");
            }
        }
        void WriteParameters(ParameterWrite[] writes, int previous, int next) {
            foreach (ParameterWrite write in writes) {
                int number = write.valueSource == "previousActionId" ? previous : write.valueSource == "actionId" ? next : write.intValue;
                if (write.type == "Int") animator.SetInteger(write.name, number);
                else if (write.type == "Float") animator.SetFloat(write.name, write.floatValue);
                else if (write.type == "Bool") animator.SetBool(write.name, write.boolValue);
                else if (write.type == "Trigger") animator.SetTrigger(write.name);
            }
        }
        public void StartAction(ActionDefinition definition, int previous, int sequence) {
            WriteParameters(definition.enterParameters, previous, definition.id);
            int layer = animator.GetLayerIndex(definition.layerName);
            evidence.Emit("action_animation_started", JsonText.Data("id", definition.id, "actionId", definition.id, "sequence", sequence, "originalController", true, "sameReference", animator.runtimeAnimatorController == originalController,
                "controllerName", originalController.name, "controllerInstanceId", originalController.GetInstanceID(), "animatorInstanceId", animator.GetInstanceID(), "enabled", animator.enabled, "initialized", animator.isInitialized, "speed", animator.speed, "applyRootMotion", animator.applyRootMotion,
                "layer", layer, "layerName", definition.layerName, "layerWeight", animator.GetLayerWeight(layer), "stateFullPathHash", definition.stateFullPathHash, "expectedStatePath", definition.statePath, "expectedStateFullPathHash", definition.stateFullPathHash, "expectedClipName", definition.clipName,
                "clipInstanceId", originalClips[definition.clipName].GetInstanceID(), "parameters", definition.enterParameters, "transitionMethod", "original Animator parameters and trigger; no Play/CrossFade or replacement clip"));
        }
        public void EndAction(ActionDefinition definition, int previous, int none, int sequence) {
            WriteParameters(definition.exitParameters, previous, none);
            evidence.Emit("action_animation_none_requested", JsonText.Data("previousId", previous, "actionId", none, "sequence", sequence, "parameters", definition.exitParameters, "source", "original-animation-event"));
        }
        public void ReceiveOriginalEvent(string function, AnimationEvent value) {
            ActionDefinition definition = action.Current;
            AnimationClip eventClip = value.isFiredByAnimator ? value.animatorClipInfo.clip : null;
            AnimatorStateInfo eventState = value.isFiredByAnimator ? value.animatorStateInfo : default(AnimatorStateInfo);
            bool sameClip = eventClip && originalClips.TryGetValue(eventClip.name, out AnimationClip originalClip) && eventClip == originalClip;
            bool accepted = definition != null && !action.PendingEnd && value.isFiredByAnimator && sameClip && eventClip.name == definition.completion.clipName
                && function == definition.completion.function && value.functionName == function && value.intParameter == definition.completion.intParameter
                && Mathf.Abs(value.time - definition.completion.eventTime) < .001f && eventState.fullPathHash == definition.stateFullPathHash
                && animator.runtimeAnimatorController == originalController && animator.GetLayerWeight(animator.GetLayerIndex(definition.layerName)) > 0;
            evidence.Emit("action_animation_event", JsonText.Data("function", function, "intParameter", value.intParameter, "eventTime", value.time, "clipName", eventClip ? eventClip.name : "", "clipInstanceId", eventClip ? eventClip.GetInstanceID() : 0,
                "originalClip", sameClip, "realCallback", value.isFiredByAnimator, "isFiredByAnimator", value.isFiredByAnimator, "animatorInstanceId", animator.GetInstanceID(), "actionId", action.Id, "targetId", action.TargetId, "sequence", action.Sequence,
                "via", "Unity.AnimationEvent", "actionLayer", definition == null ? -1 : animator.GetLayerIndex(definition.layerName), "layer", definition == null ? -1 : animator.GetLayerIndex(definition.layerName), "layerName", definition == null ? "" : definition.layerName, "stateFullPathHash", eventState.fullPathHash, "normalizedTime", eventState.normalizedTime,
                "accepted", accepted, "source", "original-animation-event", "sourceEvidence", definition == null ? "" : definition.completion.sourceEvidence));
            if (accepted) action.OnOriginalEndEvent();
        }
    }
}
