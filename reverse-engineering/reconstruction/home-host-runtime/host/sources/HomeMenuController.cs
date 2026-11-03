using System;
using System.Collections;
using UnityEngine;

namespace ReconstructedManaka {
    // The menu owns only its input lock and delegates. Sleep and customization
    // semantics are supplied by the source-backed consumers, never invented here.
    [DefaultExecutionOrder(-200)]
    public sealed class HomeMenuController : MonoBehaviour {
        PlayerMotor motor;
        RunEvidence evidence;
        Func<bool> saveHandler, sleepHandler;
        Func<int, bool> closetHandler;
        string[] closetLabels = new string[0];
        bool initialized, inputBeforeOpen, busy, closing;
        Font font;
        int serial, lastOperationFrame = -1, selectedClosetOption;
        string message = "";

        public bool IsOpen { get; private set; }
        public string Kind { get; private set; }
        public int LastClosedFrame { get; private set; } = -1;
        public int OpenSerial { get { return serial; } }
        public bool IsBusy { get { return busy || closing; } }
        public int SelectedClosetOption { get { return selectedClosetOption; } }
        public SaveState State { get; private set; }
        public GameObject PlayerVisual { get; private set; }

        public void Initialize(PlayerMotor movement, RunEvidence run, Func<bool> save, SaveState state, GameObject playerVisual) {
            if (IsOpen || busy) throw new InvalidOperationException("Close the active home menu before reinitializing it");
            if (!movement || !run || save == null || state == null) throw new ArgumentException("Home menus require the active player, evidence, state and save consumer");
            motor = movement; evidence = run; saveHandler = save; State = state; PlayerVisual = playerVisual; initialized = true;
            if (!font) font = Font.CreateDynamicFontFromOSFont(new[] { "Microsoft YaHei UI", "Microsoft YaHei", "Arial" }, 18);
        }

        // The closet integer is an index into these explicit labels. The caller
        // maps it to its verified setting; it is not an original item/appearance ID.
        public void SetHandlers(Func<bool> sleep, Func<int, bool> closet, string[] closetOptionLabels) {
            if (IsOpen || busy) throw new InvalidOperationException("Configure home menu consumers before opening a menu");
            sleepHandler = sleep; closetHandler = closet;
            closetLabels = closetOptionLabels == null ? new string[0] : (string[])closetOptionLabels.Clone();
            selectedClosetOption = 0;
        }

        public bool Open(string kind) {
            string normalized = (kind ?? "").ToLowerInvariant();
            string rejected = !initialized ? "not-initialized" : IsOpen ? "menu-already-open" : busy ? "operation-busy" : Time.frameCount <= LastClosedFrame ? "closed-this-frame" : normalized != "pc" && normalized != "bed" && normalized != "closet" ? "unknown-menu-kind" : null;
            if (rejected != null) { Emit("home_menu_rejected", "kind", normalized, "reason", rejected); return false; }
            Kind = normalized; IsOpen = true; serial++; inputBeforeOpen = motor.InputEnabled; motor.InputEnabled = false; message = "";
            selectedClosetOption = Mathf.Clamp(selectedClosetOption, 0, Math.Max(0, closetLabels.Length - 1));
            Emit("home_menu_opened", "kind", Kind, "serial", serial, "inputEnabledBefore", inputBeforeOpen, "inputEnabledAfter", motor.InputEnabled);
            return true;
        }

        public bool Close(string reason = "cancel") {
            if (!IsOpen || busy || closing) return false;
            if (Kind == "closet") { closing = true; StartCoroutine(CloseCloset(reason)); return true; }
            CloseInternal(reason); return true;
        }

        IEnumerator CloseCloset(string reason) {
            int requestedFrame = Time.frameCount;
            // Original Closet Back's delegate18641 saves after DelayFrame(5).
            for (int i = 0; i < 5; i++) yield return null;
            bool saved = false;
            try { saved = saveHandler(); }
            catch (Exception ex) { Emit("home_menu_operation_failed", "kind", "closet", "operation", "close-save", "serial", serial, "detail", ex.ToString()); }
            Emit("home_closet_autosave", "serial", serial, "requestedFrame", requestedFrame, "actualFrame", Time.frameCount, "delayFrames", 5, "success", saved, "revision", State.revision, "source", "ClosetMenuPanelView.<Back>b__18641; Save(3,-1,false)");
            closing = false;
            if (saved) CloseInternal(reason); else message = "保存失败，请重试关闭。";
        }

        void CloseInternal(string reason) {
            if (!IsOpen) return;
            string previous = Kind; IsOpen = false; Kind = null; LastClosedFrame = Time.frameCount;
            if (motor) motor.InputEnabled = inputBeforeOpen;
            Emit("home_menu_closed", "kind", previous, "serial", serial, "reason", reason, "inputEnabledAfter", motor && motor.InputEnabled, "closedFrame", LastClosedFrame);
        }

        public bool TrySave() { return Perform("pc", "save", saveHandler, false); }
        public bool TrySleep() { return Perform("bed", "sleep", sleepHandler, true); }
        public bool TryApplyCloset(int optionIndex) {
            if (optionIndex < 0 || optionIndex >= closetLabels.Length) { Emit("home_menu_operation_rejected", "kind", Kind, "operation", "closet", "reason", "option-out-of-range", "optionIndex", optionIndex); return false; }
            return Perform("closet", "closet", closetHandler == null ? null : (Func<bool>)(() => closetHandler(optionIndex)), true, optionIndex);
        }

        bool Perform(string requiredKind, string operation, Func<bool> handler, bool closeOnSuccess, int optionIndex = -1) {
            string rejected = !initialized ? "not-initialized" : !IsOpen ? "menu-closed" : Kind != requiredKind ? "wrong-menu" : busy || closing ? "operation-busy" : handler == null ? "consumer-unavailable" : lastOperationFrame == Time.frameCount ? "operation-already-attempted-this-frame" : null;
            if (rejected != null) { Emit("home_menu_operation_rejected", "kind", Kind, "operation", operation, "reason", rejected); return false; }
            if (optionIndex >= 0) selectedClosetOption = optionIndex;
            busy = true; lastOperationFrame = Time.frameCount; bool success = false; int operationSerial = serial;
            try {
                Emit("home_menu_operation_started", "kind", Kind, "operation", operation, "serial", operationSerial, "optionIndex", selectedClosetOption);
                success = handler();
            } catch (Exception ex) {
                Emit("home_menu_operation_failed", "kind", Kind, "operation", operation, "serial", operationSerial, "detail", ex.ToString());
            } finally { busy = false; }
            Emit("home_menu_operation_completed", "kind", Kind, "operation", operation, "serial", operationSerial, "success", success, "optionIndex", selectedClosetOption);
            if (IsOpen && serial == operationSerial) {
                message = success ? operation == "save" ? "已保存" : "已完成" : "操作未完成，请重试。";
                if (success && closeOnSuccess) Close("completed-" + operation);
            }
            return success;
        }

        void Update() { if (IsOpen && !busy && !closing && Input.GetKeyDown(KeyCode.Escape)) Close("escape"); }
        void OnDisable() { CloseInternal("component-disabled"); }
        void OnDestroy() { CloseInternal("component-destroyed"); if (font) Destroy(font); }
        void Emit(string kind, params object[] data) { if (evidence) evidence.Emit(kind, JsonText.Data(data)); }

        void OnGUI() {
            if (!IsOpen) return;
            bool priorEnabled = GUI.enabled;
            if (font) GUI.skin.font = font;
            GUILayout.BeginArea(new Rect((Screen.width - 420) / 2f, (Screen.height - 350) / 2f, 420, 350), GUI.skin.box);
            GUILayout.Label(Kind == "pc" ? "电脑" : Kind == "bed" ? "床" : "衣柜"); GUILayout.Space(14);
            GUI.enabled = !busy && !closing;
            if (Kind == "pc") {
                if (GUILayout.Button("保存游戏", GUILayout.Height(42))) TrySave();
            } else if (Kind == "bed") {
                GUILayout.Label("要睡觉吗？");
                GUI.enabled = !busy && !closing && sleepHandler != null;
                if (GUILayout.Button("睡觉", GUILayout.Height(42))) TrySleep();
            } else {
                if (closetLabels.Length > 0) selectedClosetOption = GUILayout.SelectionGrid(selectedClosetOption, closetLabels, 1);
                GUI.enabled = !busy && !closing && closetHandler != null && closetLabels.Length > 0;
                if (GUILayout.Button("应用", GUILayout.Height(42))) TryApplyCloset(selectedClosetOption);
            }
            GUI.enabled = !busy && !closing;
            GUILayout.Space(12);
            if (GUILayout.Button("关闭", GUILayout.Height(38))) Close("button");
            GUILayout.Label(message); GUILayout.EndArea(); GUI.enabled = priorEnabled;
        }
    }
}
