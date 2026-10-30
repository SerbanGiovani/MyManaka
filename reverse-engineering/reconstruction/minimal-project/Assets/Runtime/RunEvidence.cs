using System;
using System.Collections;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Text;
using UnityEngine;

namespace ReconstructedManaka {
    [Serializable]
    public sealed class LoopProof {
        public int schemaVersion = 1;
        public string processGuid, phase, startedUtc, finishedUtc, profileRoot, eventPath, proofPath;
        public int processId, engineErrorCount, engineWarningCount, missingScriptWarnings, knownCompatibilityErrors, unexpectedEngineErrors;
        public bool degradedAssetCompatibility, originalShaderCompatibilityVerified;
        public string unityVersion, sceneKey, environmentSource, playerSource, savePath, saveSha256, loadedSavedProcessGuid;
        public bool passed, completed, originalGeometry, originalPlayerVisual, groundedSeen, controlledInput;
        public int geometryMeshes, geometryColliders, geometryTextures, declaredTextures, unresolvedBuiltinMeshes, visualRenderers, copiedGameBehaviours, playerShaderFallbacks, inputSamples, belowCollisions, sideCollisions;
        public float travelledDistance, horizontalDisplacement, positionError, rotationErrorDegrees;
        public Vector3 movementStart, movementEnd, loadedPosition, appliedPosition, savedPosition;
        public Quaternion loadedRotation, appliedRotation, savedRotation;
        public int saveRevision;
        public bool exactStoredPosition, exactStoredRotation, exactAppliedPosition, exactAppliedRotation;
        public string failure, inputDescription, collisionPolicy, visualPolicy;
        public string screenshotPath, screenshotSha256;
        public long screenshotBytes;
        public int screenshotWidth, screenshotHeight, screenshotNonBlackPixels, screenshotDifferentPixels;
        public bool screenshotValidated, cameraActive, cameraEnabled;
        public Vector3 cameraPosition;
        public Quaternion cameraRotation;
        public string graphicsDevice, titleScreenshotPath, titleScreenshotSha256;
        public bool titleScreenshotValidated;
        public Vector3 playerVisualOffset, playerVisualBoundsSize;
    }

    // Public fields only; avoids dependencies on System.Text.Json or original game assemblies.
    public static class JsonText {
        public static Dictionary<string, object> Data(params object[] pairs) {
            var result = new Dictionary<string, object>();
            for (int i = 0; i < pairs.Length; i += 2) result.Add((string)pairs[i], pairs[i + 1]);
            return result;
        }
        public static string Encode(object value) { var b = new StringBuilder(); Append(b, value); return b.ToString(); }
        static void Quote(StringBuilder b, string value) {
            b.Append('"'); foreach (char c in value ?? "") {
                switch (c) { case '"': b.Append("\\\""); break; case '\\': b.Append("\\\\"); break; case '\n': b.Append("\\n"); break; case '\r': b.Append("\\r"); break; case '\t': b.Append("\\t"); break;
                    default: if (c < 32) b.Append("\\u").Append(((int)c).ToString("x4")); else b.Append(c); break; }
            } b.Append('"');
        }
        static void Append(StringBuilder b, object value) {
            if (value == null) { b.Append("null"); return; }
            if (value is string s) { Quote(b, s); return; }
            if (value is bool flag) { b.Append(flag ? "true" : "false"); return; }
            if (value is float f) { if (float.IsNaN(f) || float.IsInfinity(f)) Quote(b, f.ToString(CultureInfo.InvariantCulture)); else b.Append(f.ToString("R", CultureInfo.InvariantCulture)); return; }
            if (value is double d) { if (double.IsNaN(d) || double.IsInfinity(d)) Quote(b, d.ToString(CultureInfo.InvariantCulture)); else b.Append(d.ToString("R", CultureInfo.InvariantCulture)); return; }
            var type = value.GetType();
            if (type.IsPrimitive || type.IsEnum || value is decimal) { b.Append(Convert.ToString(type.IsEnum ? Convert.ToInt64(value) : value, CultureInfo.InvariantCulture)); return; }
            if (value is IDictionary map) { b.Append('{'); bool first = true; foreach (DictionaryEntry item in map) { if (!first) b.Append(','); first = false; Quote(b, Convert.ToString(item.Key, CultureInfo.InvariantCulture)); b.Append(':'); Append(b, item.Value); } b.Append('}'); return; }
            if (value is IEnumerable values) { b.Append('['); bool first = true; foreach (object item in values) { if (!first) b.Append(','); first = false; Append(b, item); } b.Append(']'); return; }
            b.Append('{'); bool start = true; foreach (FieldInfo field in type.GetFields(BindingFlags.Instance | BindingFlags.Public)) { if (!start) b.Append(','); start = false; Quote(b, field.Name); b.Append(':'); Append(b, field.GetValue(value)); } b.Append('}');
        }
    }

    public sealed class RunEvidence : MonoBehaviour {
        struct EngineMessage { public string message, stack, type, utc; }
        readonly ConcurrentQueue<EngineMessage> pending = new ConcurrentQueue<EngineMessage>();
        StreamWriter writer;
        public LoopProof Proof { get; private set; }
        public int ErrorCount { get; private set; }
        public int UnexpectedErrorCount { get; private set; }
        public string ProcessGuid { get { return Proof.processGuid; } }
        public void Initialize(string profileRoot, string proofRoot, string phase) {
            string id = Guid.NewGuid().ToString("N");
            string directory = string.IsNullOrEmpty(proofRoot) ? Path.Combine(profileRoot, "runs", id) : Path.GetFullPath(proofRoot);
            Directory.CreateDirectory(directory);
            Proof = new LoopProof { processGuid = id, processId = System.Diagnostics.Process.GetCurrentProcess().Id, phase = phase ?? "manual", profileRoot = Path.GetFullPath(profileRoot), startedUtc = DateTime.UtcNow.ToString("O"), unityVersion = Application.unityVersion, eventPath = Path.Combine(directory, "events.jsonl"), proofPath = Path.Combine(directory, "proof.json") };
            writer = new StreamWriter(Proof.eventPath, false, new UTF8Encoding(false)) { AutoFlush = true };
            Application.logMessageReceivedThreaded += OnEngineMessage;
            Emit("process_start", JsonText.Data("processGuid", id, "processId", Proof.processId, "phase", Proof.phase, "unityVersion", Application.unityVersion, "profileRoot", Proof.profileRoot, "controlledInput", false));
            WriteProof();
        }
        void OnEngineMessage(string message, string stack, LogType type) { pending.Enqueue(new EngineMessage { message = message, stack = stack, type = type.ToString(), utc = DateTime.UtcNow.ToString("O") }); }
        void Update() { Drain(); }
        public void Drain() {
            while (pending.TryDequeue(out EngineMessage m)) {
                bool error = m.type == "Error" || m.type == "Exception" || m.type == "Assert";
                bool known = error && m.message.Trim() == "Struct '_MainTex' is not in any constant buffer.";
                if (error) { ErrorCount++; if (known) { Proof.knownCompatibilityErrors++; Proof.degradedAssetCompatibility = true; } else UnexpectedErrorCount++; }
                else if (m.type == "Warning") { Proof.engineWarningCount++; if (m.message.IndexOf("referenced script", StringComparison.OrdinalIgnoreCase) >= 0 && m.message.IndexOf("missing", StringComparison.OrdinalIgnoreCase) >= 0) { Proof.missingScriptWarnings++; Proof.degradedAssetCompatibility = true; } }
                Emit(error ? "engine_error" : "engine_message", JsonText.Data("type", m.type, "message", m.message, "stack", m.stack, "emittedUtc", m.utc, "classification", known ? "known-original-shader-constant-buffer" : error ? "unexpected" : "message"));
            }
            if (Proof != null) { Proof.engineErrorCount = ErrorCount; Proof.unexpectedEngineErrors = UnexpectedErrorCount; }
        }
        public void Emit(string kind, object data) {
            if (writer == null) return;
            writer.WriteLine(JsonText.Encode(JsonText.Data("kind", kind, "processGuid", ProcessGuid, "frame", Time.frameCount, "real", Time.realtimeSinceStartup, "utc", DateTime.UtcNow.ToString("O"), "data", data)));
        }
        public void Complete(bool passed, string failure) {
            Drain(); Proof.completed = true; Proof.passed = passed && UnexpectedErrorCount == 0; Proof.failure = failure; Proof.finishedUtc = DateTime.UtcNow.ToString("O"); WriteProof();
            Emit("acceptance_complete", JsonText.Data("passed", Proof.passed, "failure", failure, "engineErrors", ErrorCount, "proof", Proof.proofPath));
        }
        public void WriteProof() { if (Proof != null) File.WriteAllText(Proof.proofPath, JsonText.Encode(Proof) + "\n", new UTF8Encoding(false)); }
        void OnApplicationQuit() {
            if (Proof == null) return; Drain(); if (Proof.completed && UnexpectedErrorCount != 0) Proof.passed = false;
            Emit("process_quit", JsonText.Data("completed", Proof.completed, "passed", Proof.passed, "engineErrors", ErrorCount)); WriteProof(); writer?.Dispose(); writer = null;
        }
        void OnDestroy() { Application.logMessageReceivedThreaded -= OnEngineMessage; writer?.Dispose(); writer = null; }
    }
}
