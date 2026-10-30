using System;
using System.Collections.Generic;
using UnityEngine;

namespace ReconstructedManaka {
    [Serializable] public sealed class InteractionManifest {
        public int schemaVersion = 1, noneActionId = -1;
        public string sceneKey, sourceScene, sourceBundleSha256, sourceEvidence, scope;
        public bool noneCanMove = true;
        public ActionDefinition[] actions;
        public InteractionTargetDefinition[] targets;
    }
    [Serializable] public sealed class ActionDefinition {
        public int id, stateFullPathHash;
        public string name, sourceEvidence, layerName, statePath, clipName;
        public bool canMove;
        public ParameterWrite[] enterParameters, exitParameters;
        public LayerWeight[] layers;
        public ActionCompletion completion;
    }
    [Serializable] public sealed class ParameterWrite {
        public string name, type, valueSource;
        public int intValue;
        public float floatValue;
        public bool boolValue;
    }
    [Serializable] public sealed class LayerWeight { public string name; public float weight; }
    [Serializable] public sealed class ActionCompletion {
        public string function, clipName, sourceEvidence;
        public float eventTime;
        public int intParameter, deferFrames;
    }
    [Serializable] public sealed class InteractionTargetDefinition {
        public string id, label, sourcePath, sourceScene, sourceBundleSha256, sourceEvidence, placementProvenance, triggerPath, originalComponent;
        public long sourcePathId;
        public int actionId;
        public bool collectOnCompletion;
        public bool rejectCrouch;
        public string guardEvidence;
        public int collectItemId;
        public bool originalSource;
        public Vector3 worldPosition, worldScale = Vector3.one;
        public Quaternion worldRotation = Quaternion.identity;
        public TriggerDefinition trigger;
        public InteractionVisualDefinition visual;
    }
    [Serializable] public sealed class TriggerDefinition {
        public string shape;
        public Vector3 center, size;
        public float radius, height;
        public int direction = 1;
        public bool isTrigger = true;
    }
    [Serializable] public sealed class InteractionVisualDefinition {
        public string bundle, bundleSha256, asset, objectName;
        public long sourcePathId;
    }

    // This is the bounded reconstruction of the selected original MAction record.
    // The selected record's CanMove field controls ordinary target-speed calculation;
    // it does not suppress CharacterController gravity or already-smoothed inertia.
    public sealed class PlayerAction : MonoBehaviour {
        readonly Dictionary<int, ActionDefinition> definitions = new Dictionary<int, ActionDefinition>();
        RunEvidence evidence;
        ActionAnimatorBridge bridge;
        int noneId = -1;
        bool noneCanMove;
        public int Id { get; private set; } = -1;
        public int Sequence { get; private set; }
        public int StartFrame { get; private set; } = -1;
        public int EndEventFrame { get; private set; } = -1;
        public int NoneFrame { get; private set; } = -1;
        public int CompletionDeferFrames { get; private set; }
        public bool PendingEnd { get; private set; }
        public bool Active { get { return Id != noneId; } }
        public bool CanMove { get { return Active ? definitions[Id].canMove : noneCanMove; } }
        public ActionDefinition Current { get { return Active ? definitions[Id] : null; } }
        public string TargetId { get; private set; }
        public event Action<string, int> OriginalCompletion;
        public void Initialize(InteractionManifest manifest, RunEvidence run, ActionAnimatorBridge animation) {
            evidence = run; bridge = animation; noneId = manifest.noneActionId; Id = noneId; noneCanMove = manifest.noneCanMove;
            foreach (ActionDefinition value in manifest.actions) {
                if (value.id == noneId || definitions.ContainsKey(value.id) || value.completion == null || value.completion.deferFrames < 0 || string.IsNullOrEmpty(value.sourceEvidence) || string.IsNullOrEmpty(value.completion.sourceEvidence))
                    throw new InvalidOperationException("Unproven or invalid original action definition");
                definitions.Add(value.id, value);
            }
            evidence.Emit("player_action_initialized", JsonText.Data("noneActionId", noneId, "canMove", CanMove, "sourceEvidence", manifest.sourceEvidence, "completionPolicy", "only validated original AnimationEvent callbacks; no timeout completion"));
        }
        public bool TryStart(int id, string targetId) {
            if (Active || !definitions.TryGetValue(id, out ActionDefinition definition)) return false;
            int previous = Id; Id = id; Sequence++; TargetId = targetId; StartFrame = Time.frameCount;
            EndEventFrame = -1; NoneFrame = -1; PendingEnd = false; CompletionDeferFrames = definition.completion.deferFrames;
            evidence.Emit("player_action_changed", JsonText.Data("previousId", previous, "actionId", Id, "name", definition.name, "targetId", TargetId, "sequence", Sequence, "source", "F-interaction", "canMove", CanMove, "sourceEvidence", definition.sourceEvidence));
            bridge.StartAction(definition, previous, Sequence);
            return true;
        }
        public void OnOriginalEndEvent() {
            if (!Active || PendingEnd) return;
            EndEventFrame = Time.frameCount;
            OriginalCompletion?.Invoke(TargetId, Sequence);
            CompletionDeferFrames = Current.completion.deferFrames;
            if (CompletionDeferFrames == 0) { ChangeToNone("original-animation-event"); return; }
            PendingEnd = true;
            evidence.Emit("action_end_deferred", JsonText.Data("actionId", Id, "targetId", TargetId, "sequence", Sequence, "eventFrame", EndEventFrame, "deferFrames", CompletionDeferFrames, "earliestNoneFrame", EndEventFrame + CompletionDeferFrames, "source", "original-animation-event", "sourceEvidence", Current.completion.sourceEvidence));
        }
        public void TickOriginalCompletion() {
            if (PendingEnd && Time.frameCount >= EndEventFrame + CompletionDeferFrames) ChangeToNone("deferred-original-animation-event");
        }
        void ChangeToNone(string source) {
            ActionDefinition completed = Current; int previous = Id;
            bridge.EndAction(completed, previous, noneId, Sequence);
            Id = noneId; PendingEnd = false; NoneFrame = Time.frameCount;
            evidence.Emit("player_action_changed", JsonText.Data("previousId", previous, "actionId", Id, "name", "None", "targetId", TargetId, "sequence", Sequence, "source", source, "eventFrame", EndEventFrame, "deferFrames", CompletionDeferFrames, "actualFrameDelay", NoneFrame - EndEventFrame, "canMove", CanMove, "sourceEvidence", completed.completion.sourceEvidence));
        }
        public object Snapshot() {
            return JsonText.Data("id", Id, "name", Active ? Current.name : "None", "canMove", CanMove, "active", Active, "startFrame", StartFrame, "endEventFrame", EndEventFrame, "noneFrame", NoneFrame, "pendingEnd", PendingEnd, "completionDeferFrames", CompletionDeferFrames, "sequence", Sequence, "targetId", TargetId);
        }
    }
}
