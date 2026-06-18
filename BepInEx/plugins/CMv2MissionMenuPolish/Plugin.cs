using System;
using System.Collections.Generic;
using System.Reflection;
using BepInEx;
using BepInEx.Logging;
using BepInEx.Unity.IL2CPP;
using HarmonyLib;
using Il2CppInterop.Runtime.Injection;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

namespace CMv2MissionMenuPolish
{
    [BepInPlugin(PluginGuid, PluginName, PluginVersion)]
    public sealed class Plugin : BasePlugin
    {
        public const string PluginGuid = "local.cmv2_mission_menu_polish";
        public const string PluginName = "CMv2 Mission Menu Polish";
        public const string PluginVersion = "1.0.0";

        internal static ManualLogSource Logger;
        private static Harmony harmony;
        private static bool patched;

        public override void Load()
        {
            Logger = Log;
            harmony = new Harmony(PluginGuid);
            ClassInjector.RegisterTypeInIl2Cpp<DelayedPatcher>();
            AddComponent<DelayedPatcher>();

            if (!TryPatch())
            {
                Log.LogInfo("CMv2 Mission Menu Polish waiting for Custom Missions v2 UI.");
            }
        }

        internal static bool TryPatch()
        {
            if (patched)
            {
                return true;
            }

            var type = FindType("SFM_custom_mission_v2.UI.PluginGUI+MissionMenu");
            var method = type?.GetMethod("OnShow", BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
            if (method == null)
            {
                return false;
            }

            MissionMenuOnShowPatch.Bind(type);
            harmony.Patch(method, postfix: new HarmonyMethod(typeof(MissionMenuOnShowPatch), nameof(MissionMenuOnShowPatch.Postfix)));
            patched = true;
            Logger.LogInfo("CMv2 Mission Menu Polish patched MissionMenu.OnShow.");
            return true;
        }

        internal static Type FindType(string fullName)
        {
            foreach (var assembly in AppDomain.CurrentDomain.GetAssemblies())
            {
                var name = assembly.GetName().Name;
                if (name != "SFM_custom_mission_v2")
                {
                    continue;
                }

                return assembly.GetType(fullName, false);
            }

            return null;
        }
    }

    internal static class MissionMenuOnShowPatch
    {
        private const string SeparatorPrefix = "CMv2MissionSeparator";
        private static FieldInfo listField;
        private static FieldInfo scaleField;

        internal static void Bind(Type missionMenuType)
        {
            listField = missionMenuType.GetField("list", BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
            var pluginGuiType = Plugin.FindType("SFM_custom_mission_v2.UI.PluginGUI");
            scaleField = pluginGuiType?.GetField("scale", BindingFlags.Static | BindingFlags.Public | BindingFlags.NonPublic);
        }

        public static void Postfix(object __instance)
        {
            try
            {
                var list = listField?.GetValue(__instance) as GameObject;
                if (list == null)
                {
                    return;
                }

                var scale = 1f;
                if (scaleField?.GetValue(null) is float s && s > 0f)
                {
                    scale = s;
                }

                PolishList(list, scale);
            }
            catch (Exception ex)
            {
                Plugin.Logger.LogWarning("Failed to polish CMv2 mission menu: " + ex.Message);
            }
        }

        internal static float CurrentScale()
        {
            if (scaleField?.GetValue(null) is float s && s > 0f)
            {
                return s;
            }

            return 1f;
        }

        internal static void PolishList(GameObject list, float scale)
        {
            var layout = list.GetComponent<VerticalLayoutGroup>();
            if (layout != null)
            {
                layout.spacing = 0f;
                layout.childForceExpandHeight = false;
                layout.padding.top = Mathf.Max(layout.padding.top, Mathf.RoundToInt(1.5f * scale));
                layout.padding.bottom = Mathf.Max(layout.padding.bottom, Mathf.RoundToInt(2f * scale));
            }

            var items = new List<GameObject>();
            var count = list.transform.childCount;
            for (var i = 0; i < count; i++)
            {
                var item = list.transform.GetChild(i)?.gameObject;
                if (item == null)
                {
                    continue;
                }

                if (item.name.StartsWith("CMv2MissionSeparator", StringComparison.Ordinal))
                {
                    continue;
                }

                if (item.GetComponentsInChildren<TextMeshProUGUI>(true).Length <= 0)
                {
                    continue;
                }

                items.Add(item);
            }

            for (var i = 0; i < items.Count; i++)
            {
                var item = items[i];
                PolishItem(item, scale);
                EnsureSeparatorAfter(list, item, scale, i);
            }

            RemoveExtraSeparators(list, items.Count);
        }

        private static void PolishItem(GameObject item, float scale)
        {
            var image = item.GetComponent<Image>();
            if (image != null)
            {
                image.color = new Color(0.92f, 0.92f, 0.92f, image.color.a);
            }

            var outline = item.GetComponent<Outline>();
            if (outline != null)
            {
                outline.enabled = false;
            }

            RemoveOldInnerSeparator(item);
            PolishText(item, scale);
        }

        private static void RemoveOldInnerSeparator(GameObject item)
        {
            for (var i = item.transform.childCount - 1; i >= 0; i--)
            {
                var child = item.transform.GetChild(i);
                if (child != null && child.name.StartsWith(SeparatorPrefix, StringComparison.Ordinal))
                {
                    UnityEngine.Object.Destroy(child.gameObject);
                }
            }
        }

        private static void EnsureSeparatorAfter(GameObject list, GameObject item, float scale, int itemIndex)
        {
            var sepName = SeparatorPrefix + "_" + itemIndex;
            var existing = list.transform.Find(sepName);
            var sep = existing == null ? new GameObject(sepName) : existing.gameObject;
            if (existing == null)
            {
                sep.transform.SetParent(list.transform, false);
                sep.AddComponent<Image>();
                var le = sep.AddComponent<LayoutElement>();
                le.ignoreLayout = false;
            }
            else
            {
                var le = sep.GetComponent<LayoutElement>();
                if (le == null)
                {
                    le = sep.AddComponent<LayoutElement>();
                }
                le.ignoreLayout = false;
            }

            var targetIndex = item.transform.GetSiblingIndex() + 1;
            sep.transform.SetSiblingIndex(targetIndex);

            var image = sep.GetComponent<Image>();
            if (image != null)
            {
                image.color = new Color(0f, 0f, 0f, 0.22f);
                image.raycastTarget = false;
            }

            var layout = sep.GetComponent<LayoutElement>();
            var h = Mathf.Max(1f, 0.8f * scale);
            if (layout != null)
            {
                layout.minHeight = h;
                layout.preferredHeight = h;
                layout.flexibleHeight = 0f;
            }

            var rect = sep.GetComponent<RectTransform>();
            if (rect != null)
            {
                rect.anchorMin = new Vector2(0f, 0.5f);
                rect.anchorMax = new Vector2(1f, 0.5f);
                rect.pivot = new Vector2(0.5f, 0.5f);
                rect.anchoredPosition = Vector2.zero;
                rect.sizeDelta = new Vector2(0f, h);
            }
        }

        private static void RemoveExtraSeparators(GameObject list, int itemCount)
        {
            for (var i = list.transform.childCount - 1; i >= 0; i--)
            {
                var child = list.transform.GetChild(i);
                if (child == null || !child.name.StartsWith(SeparatorPrefix, StringComparison.Ordinal))
                {
                    continue;
                }

                var expected = false;
                for (var j = 0; j < itemCount; j++)
                {
                    if (child.name == SeparatorPrefix + "_" + j)
                    {
                        expected = true;
                        break;
                    }
                }

                if (!expected)
                {
                    UnityEngine.Object.Destroy(child.gameObject);
                }
            }
        }

        private static void PolishText(GameObject item, float scale)
        {
            var texts = item.GetComponentsInChildren<TextMeshProUGUI>(true);
            if (texts == null || texts.Length < 1)
            {
                return;
            }

            for (var i = 0; i < texts.Length; i++)
            {
                var text = texts[i];
                if (text == null || string.IsNullOrWhiteSpace(text.text))
                {
                    continue;
                }

                text.color = new Color(0f, 0f, 0f, text.color.a);
                text.margin = new Vector4(1f * scale, text.margin.y, text.margin.z, text.margin.w);
                text.enableWordWrapping = true;
            }
        }
    }

    internal sealed class DelayedPatcher : MonoBehaviour
    {
        private float elapsed;

        public DelayedPatcher(IntPtr ptr) : base(ptr)
        {
        }

        private void Update()
        {
            Plugin.TryPatch();

            elapsed += Time.unscaledDeltaTime;
            if (elapsed < 0.5f)
            {
                return;
            }

            elapsed = 0f;
            RuntimePolish();
        }

        private static void RuntimePolish()
        {
            var missionMenuType = Plugin.FindType("SFM_custom_mission_v2.UI.PluginGUI+MissionMenu");
            if (missionMenuType == null)
            {
                return;
            }

            var missionMenuField = Plugin.FindType("SFM_custom_mission_v2.UI.PluginGUI")?.GetField("missionMenu", BindingFlags.Static | BindingFlags.Public | BindingFlags.NonPublic);
            var missionMenu = missionMenuField?.GetValue(null);
            if (missionMenu == null)
            {
                return;
            }

            var listField = missionMenuType.GetField("list", BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
            var list = listField?.GetValue(missionMenu) as GameObject;
            if (list != null && list.activeInHierarchy)
            {
                MissionMenuOnShowPatch.PolishList(list, MissionMenuOnShowPatch.CurrentScale());
            }
        }
    }
}
