using System;
using UnityEngine;

namespace ReconstructedManaka {
    // Exact selected original SkinPattern primary colors applied to the already
    // declared Standard shader bridge. This does not implement the original shade shader.
    public sealed class HomeAppearance {
        readonly SceneAssetResult room;
        readonly SaveState state;
        readonly RunEvidence evidence;
        public HomeAppearance(SceneAssetResult room, SaveState state, RunEvidence evidence) { this.room = room; this.state = state; this.evidence = evidence; }
        public bool SelectPreset(int index) {
            if (index < 0 || index > 1) return false;
            bool oldFree = state.customization.skinFree; int oldPreset = state.customization.skinPreset;
            state.customization.skinFree = false; state.customization.skinPreset = index;
            try { Apply("closet"); return true; }
            catch { state.customization.skinFree = oldFree; state.customization.skinPreset = oldPreset; throw; }
        }
        public bool Apply(string reason) {
            var data = state.customization;
            if (!data.skinFree && (data.skinPreset < 0 || data.skinPreset > 1)) {
                evidence.Emit("home_appearance_unsupported", JsonText.Data("preset", data.skinPreset, "reason", reason)); return false;
            }
            Color color = data.skinFree ? new Color(data.skinR / 255f, data.skinG / 255f, data.skinB / 255f, 1) : data.skinPreset == 0 ? new Color(1, 1, 1, 0) : new Color(1, .9957806f, .93670887f, 1);
            if (!room.bodyRenderer || !room.faceRenderer) throw new InvalidOperationException("Original body/face renderer bindings are absent");
            Material[] body = room.bodyRenderer.sharedMaterials, face = room.faceRenderer.sharedMaterials;
            if (body.Length <= 1 || face.Length <= 2 || !body[1] || !face[2] || !body[1].HasProperty("_Color") || !face[2].HasProperty("_Color")) throw new InvalidOperationException("Original selected body1/face2 slots are absent");
            body[1].SetColor("_Color", color); face[2].SetColor("_Color", color);
            evidence.Emit("home_appearance_applied", JsonText.Data("reason", reason, "skinFree", data.skinFree, "skinPreset", data.skinPreset, "expectedPrimary", color, "actualBodyPrimary", body[1].GetColor("_Color"), "actualFacePrimary", face[2].GetColor("_Color"), "bodyRenderer", room.bodyRenderer.name, "faceRenderer", room.faceRenderer.name, "bodySlot", 1, "faceSlot", 2, "bodyShader", body[1].shader.name, "faceShader", face[2].shader.name, "originalSecondaryShadeApplied", false, "source", "runtime/skin-preset/skin-preset-runtime.md; PlayerBodyCustomizeAdjuster.OnChangeBody14602"));
            return true;
        }
    }
}
