using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using BepInEx;
using BepInEx.Configuration;
using BepInEx.Logging;
using BepInEx.Unity.IL2CPP;
using ExposureUnnoticed2.Master.ReinforceEffect;
using ExposureUnnoticed2.ObjectUI.OptionMenu;
using ExposureUnnoticed2.ObjectUI.PcMenuPanel.ReinforcePanel;
using ExposureUnnoticed2.Scripts.Base;
using HarmonyLib;
using Il2CppInterop.Runtime.InteropTypes.Arrays;
using Il2CppInput = BepInEx.Unity.IL2CPP.UnityEngine.Input;
using Il2CppKeyCode = BepInEx.Unity.IL2CPP.UnityEngine.KeyCode;

namespace EnchanceControl
{
    internal enum ActiveField
    {
        Effect,
        Value
    }

    [BepInPlugin(PluginGuid, PluginName, PluginVersion)]
    public sealed class Plugin : BasePlugin
    {
        public const string PluginGuid = "local.reinforce_chooser";
        public const string PluginName = "Enchance Control";
        public const string PluginVersion = "1.2.8";
        public const int StoredNoEffectId = -1;

        internal static ManualLogSource Logger;
        internal static ConfigEntry<bool> Enabled;
        internal static ConfigEntry<bool> OverrideGacha;
        internal static ConfigEntry<bool> PreferClickedRank;
        internal static ConfigEntry<string> Slot1Effect;
        internal static ConfigEntry<string> Slot2Effect;
        internal static ConfigEntry<string> Slot3Effect;
        internal static ConfigEntry<string> Slot1Kind;
        internal static ConfigEntry<string> Slot2Kind;
        internal static ConfigEntry<string> Slot3Kind;
        internal static ConfigEntry<int> Slot1Rank;
        internal static ConfigEntry<int> Slot2Rank;
        internal static ConfigEntry<int> Slot3Rank;
        internal static ConfigEntry<int> Slot1RecordId;
        internal static ConfigEntry<int> Slot2RecordId;
        internal static ConfigEntry<int> Slot3RecordId;
        internal static ConfigEntry<bool> FillMissingWithOriginalGacha;
        internal static ConfigFile ConfigFile;
        internal static string CurrentItemKey;
        internal static bool DumpedEffectTable;
        internal static readonly Dictionary<string, ItemSlotConfig> ItemConfigs = new Dictionary<string, ItemSlotConfig>(StringComparer.Ordinal);
        internal static AcceptableValueList<string> EffectList;
        internal static AcceptableValueList<string> KindList;
        internal static readonly string[] EffectNames =
        {
            "RpBonus",
            "AddBareyasusa",
            "Dokidoki",
            "Stamina",
            "EcstasyGauge",
            "MissionGauge",
            "SlowGauge",
            "SkillCoolTime",
            "GameOverPenaltyRp",
            "GameOverPenaltyRank",
            "MentalDecreaseScale",
            "DashSpeed",
            "StaminaRegenerate",
            "ReduceFootStepSound",
            "UnlockSpeed"
        };

        private Harmony harmony;

        public override void Load()
        {
            Logger = Log;
            ConfigFile = Config;

            Enabled = Config.Bind("General", "Enabled", true, "Enable plugin.");
            OverrideGacha = Config.Bind("General", "OverrideGacha", true, "Replace random reinforcement results when upgrading equipment.");
            PreferClickedRank = Config.Bind("General", "PreferClickedRank", true, "Use selected upgrade rank for every slot. If false, each SlotRank is used.");
            FillMissingWithOriginalGacha = Config.Bind("General", "FillMissingWithOriginalGacha", true, "If a configured effect cannot be found, keep original random result for that slot.");

            EffectList = new AcceptableValueList<string>(EffectNames);
            KindList = new AcceptableValueList<string>("Any", "Positive", "Negative", "Neutral");

            Slot1Effect = Config.Bind("Defaults", "Slot1Effect", "AddBareyasusa", new ConfigDescription("Default reinforcement effect for slot 1.", EffectList));
            Slot2Effect = Config.Bind("Defaults", "Slot2Effect", "AddBareyasusa", new ConfigDescription("Default reinforcement effect for slot 2.", EffectList));
            Slot3Effect = Config.Bind("Defaults", "Slot3Effect", "AddBareyasusa", new ConfigDescription("Default reinforcement effect for slot 3.", EffectList));
            Slot1Kind = Config.Bind("Defaults", "Slot1Kind", "Negative", new ConfigDescription("Default effect sign for slot 1.", KindList));
            Slot2Kind = Config.Bind("Defaults", "Slot2Kind", "Negative", new ConfigDescription("Default effect sign for slot 2.", KindList));
            Slot3Kind = Config.Bind("Defaults", "Slot3Kind", "Negative", new ConfigDescription("Default effect sign for slot 3.", KindList));
            Slot1Rank = Config.Bind("Slots", "Slot1Rank", 3, "Effect rank 1-3. Used only when PreferClickedRank=false.");
            Slot2Rank = Config.Bind("Slots", "Slot2Rank", 3, "Effect rank 1-3. Used only when PreferClickedRank=false.");
            Slot3Rank = Config.Bind("Slots", "Slot3Rank", 3, "Effect rank 1-3. Used only when PreferClickedRank=false.");
            Slot1RecordId = Config.Bind("Slots", "Slot1RecordId", 0, "Exact RReinforceEffect id for slot 1. 0 migrates from Slot1Effect/Kind/Rank.");
            Slot2RecordId = Config.Bind("Slots", "Slot2RecordId", 0, "Exact RReinforceEffect id for slot 2. 0 migrates from Slot2Effect/Kind/Rank.");
            Slot3RecordId = Config.Bind("Slots", "Slot3RecordId", 0, "Exact RReinforceEffect id for slot 3. 0 migrates from Slot3Effect/Kind/Rank.");

            harmony = new Harmony(PluginGuid);
            harmony.PatchAll(typeof(ReinforcePanelViewPatch));
            harmony.PatchAll(typeof(ReinforceSettingPanelViewPatch));
            harmony.PatchAll(typeof(CustomizeCheckItemViewPatch));
            harmony.PatchAll(typeof(ReinforceEffectGachaPatch));
            Log.LogInfo("Enchance Control loaded.");
        }

        internal static ItemSlotConfig GetItemConfig(string itemKey)
        {
            if (string.IsNullOrEmpty(itemKey))
            {
                return null;
            }

            if (ItemConfigs.TryGetValue(itemKey, out var existing))
            {
                return existing;
            }

            var section = "Item." + itemKey;
            var config = new ItemSlotConfig
            {
                Slot1Effect = ConfigFile.Bind(section, "Slot1Effect", Slot1Effect.Value, new ConfigDescription("Reinforcement effect for this equipment slot 1.", EffectList)),
                Slot2Effect = ConfigFile.Bind(section, "Slot2Effect", Slot2Effect.Value, new ConfigDescription("Reinforcement effect for this equipment slot 2.", EffectList)),
                Slot3Effect = ConfigFile.Bind(section, "Slot3Effect", Slot3Effect.Value, new ConfigDescription("Reinforcement effect for this equipment slot 3.", EffectList)),
                Slot1Kind = ConfigFile.Bind(section, "Slot1Kind", Slot1Kind.Value, new ConfigDescription("Effect sign for this equipment slot 1.", KindList)),
                Slot2Kind = ConfigFile.Bind(section, "Slot2Kind", Slot2Kind.Value, new ConfigDescription("Effect sign for this equipment slot 2.", KindList)),
                Slot3Kind = ConfigFile.Bind(section, "Slot3Kind", Slot3Kind.Value, new ConfigDescription("Effect sign for this equipment slot 3.", KindList)),
                Slot1RecordId = ConfigFile.Bind(section, "Slot1RecordId", Slot1RecordId.Value, "Exact RReinforceEffect id for this equipment slot 1."),
                Slot2RecordId = ConfigFile.Bind(section, "Slot2RecordId", Slot2RecordId.Value, "Exact RReinforceEffect id for this equipment slot 2."),
                Slot3RecordId = ConfigFile.Bind(section, "Slot3RecordId", Slot3RecordId.Value, "Exact RReinforceEffect id for this equipment slot 3.")
            };

            ItemConfigs[itemKey] = config;
            ConfigFile.Save();
            Logger.LogInfo("[EnchanceControl] Created config section for equipment: " + itemKey);
            return config;
        }

        internal static void DumpEffectTableIfNeeded()
        {
            if (DumpedEffectTable)
            {
                return;
            }

            DumpedEffectTable = true;
            try
            {
                Localizer.LoadLocalizeDataIfNot();
                var rows = new List<RReinforceEffect>();
                for (var id = 0; id <= 999; id++)
                {
                    try
                    {
                        var record = MReinforceEffect.Get(id);
                        if (record != null)
                        {
                            rows.Add(record);
                        }
                    }
                    catch
                    {
                    }
                }

                rows.Sort(CompareRecords);
                var path = Path.Combine(Paths.ConfigPath, "reinforce_effect_dump.tsv");
                var builder = new StringBuilder();
                builder.AppendLine("Id\tEnum\tNameKey\tDisplay\tRank\tKind\tAmount\tSuffix\tText");
                foreach (var record in rows)
                {
                    var display = SafeTranslate(record.NameKey);
                    var kind = record.IsNegativeEffect ? "Negative" : record.IsNeutralEffect ? "Neutral" : "Positive";
                    var amount = record.EffectAmount100;
                    var sign = amount > 0 ? "+" : string.Empty;
                    var suffix = record.Suffix ?? string.Empty;
                    builder.Append(record.Id).Append('\t')
                        .Append(record.ReinforceEffectType).Append('\t')
                        .Append(record.NameKey).Append('\t')
                        .Append(display).Append('\t')
                        .Append(record.EffectRank).Append('\t')
                        .Append(kind).Append('\t')
                        .Append(amount).Append('\t')
                        .Append(suffix).Append('\t')
                        .Append(display).Append(' ').Append(sign).Append(amount).Append(suffix)
                        .AppendLine();
                }

                File.WriteAllText(path, builder.ToString(), Encoding.UTF8);
                Logger.LogInfo("[EnchanceControl] Dumped reinforce effect table: " + path);
            }
            catch (Exception ex)
            {
                Logger.LogWarning("[EnchanceControl] Failed to dump reinforce effect table: " + ex);
            }
        }

        internal static int CompareRecords(RReinforceEffect left, RReinforceEffect right)
        {
            if (left.Id == MReinforceEffect.NoEffectId && right.Id != MReinforceEffect.NoEffectId) return -1;
            if (right.Id == MReinforceEffect.NoEffectId && left.Id != MReinforceEffect.NoEffectId) return 1;

            var typeCompare = ((int)left.ReinforceEffectType).CompareTo((int)right.ReinforceEffectType);
            if (typeCompare != 0) return typeCompare;

            var leftKind = left.IsNegativeEffect ? 0 : left.IsNeutralEffect ? 1 : 2;
            var rightKind = right.IsNegativeEffect ? 0 : right.IsNeutralEffect ? 1 : 2;
            var kindCompare = leftKind.CompareTo(rightKind);
            if (kindCompare != 0) return kindCompare;

            var rankCompare = left.EffectRank.CompareTo(right.EffectRank);
            if (rankCompare != 0) return rankCompare;

            return left.Id.CompareTo(right.Id);
        }

        internal static string SafeTranslate(string key)
        {
            try
            {
                var translated = Localizer.Trans(key);
                return string.IsNullOrEmpty(translated) ? key : translated;
            }
            catch
            {
                return key;
            }
        }
    }

    internal sealed class ItemSlotConfig
    {
        public ConfigEntry<string> Slot1Effect;
        public ConfigEntry<string> Slot2Effect;
        public ConfigEntry<string> Slot3Effect;
        public ConfigEntry<string> Slot1Kind;
        public ConfigEntry<string> Slot2Kind;
        public ConfigEntry<string> Slot3Kind;
        public ConfigEntry<int> Slot1RecordId;
        public ConfigEntry<int> Slot2RecordId;
        public ConfigEntry<int> Slot3RecordId;
    }

    [HarmonyPatch(typeof(ReinforceSettingPanelView))]
    internal static class ReinforceSettingPanelViewPatch
    {
        private static bool prevNextPressed;
        private static bool prevPrevPressed;
        private static bool prevSlotUpPressed;
        private static bool prevSlotDownPressed;
        private static bool prevSlot1Pressed;
        private static bool prevSlot2Pressed;
        private static bool prevSlot3Pressed;
        private static bool prevValue1Pressed;
        private static bool prevValue2Pressed;
        private static bool prevValue3Pressed;
        internal static ReinforceSettingPanelView CurrentView;
        internal static int ActiveSlot = 1;
        internal static ActiveField ActiveField = ActiveField.Effect;

        [HarmonyPostfix]
        [HarmonyPatch(nameof(ReinforceSettingPanelView.Initialize))]
        private static void InitializePostfix(ReinforceSettingPanelView __instance, IReinforcableRecord record)
        {
            if (record == null)
            {
                return;
            }

            Plugin.CurrentItemKey = record.NameKey;
            Plugin.GetItemConfig(Plugin.CurrentItemKey);
            Plugin.DumpEffectTableIfNeeded();
            CurrentView = __instance;
            ActiveSlot = 1;
            ActiveField = ActiveField.Effect;
            RefreshTexts(__instance);
        }

        [HarmonyPostfix]
        [HarmonyPatch("Update")]
        private static void UpdatePostfix(ReinforceSettingPanelView __instance)
        {
            if (__instance == null || string.IsNullOrEmpty(Plugin.CurrentItemKey))
            {
                return;
            }

            var nextPressed = GetKey(120);
            var prevPressed = GetKey(122);
            var slotUpPressed = GetKey(273);
            var slotDownPressed = GetKey(274);
            var slot1Pressed = GetKey(49);
            var slot2Pressed = GetKey(50);
            var slot3Pressed = GetKey(51);
            var value1Pressed = GetKey(52);
            var value2Pressed = GetKey(53);
            var value3Pressed = GetKey(54);

            if (slot1Pressed && !prevSlot1Pressed)
            {
                ActiveSlot = 1;
                ActiveField = ActiveField.Effect;
                RefreshTexts(__instance);
            }
            else if (slot2Pressed && !prevSlot2Pressed)
            {
                ActiveSlot = 2;
                ActiveField = ActiveField.Effect;
                RefreshTexts(__instance);
            }
            else if (slot3Pressed && !prevSlot3Pressed)
            {
                ActiveSlot = 3;
                ActiveField = ActiveField.Effect;
                RefreshTexts(__instance);
            }
            else if (value1Pressed && !prevValue1Pressed)
            {
                ActiveSlot = 1;
                ActiveField = ActiveField.Value;
                RefreshTexts(__instance);
            }
            else if (value2Pressed && !prevValue2Pressed)
            {
                ActiveSlot = 2;
                ActiveField = ActiveField.Value;
                RefreshTexts(__instance);
            }
            else if (value3Pressed && !prevValue3Pressed)
            {
                ActiveSlot = 3;
                ActiveField = ActiveField.Value;
                RefreshTexts(__instance);
            }
            else if (slotUpPressed && !prevSlotUpPressed)
            {
                ActiveSlot--;
                if (ActiveSlot < 1) ActiveSlot = 3;
                RefreshTexts(__instance);
            }
            else if (slotDownPressed && !prevSlotDownPressed)
            {
                ActiveSlot++;
                if (ActiveSlot > 3) ActiveSlot = 1;
                RefreshTexts(__instance);
            }

            if (nextPressed && !prevNextPressed)
            {
                CycleSelection(ActiveSlot, 1);
                RefreshTexts(__instance);
            }
            else if (prevPressed && !prevPrevPressed)
            {
                CycleSelection(ActiveSlot, -1);
                RefreshTexts(__instance);
            }

            prevNextPressed = nextPressed;
            prevPrevPressed = prevPressed;
            prevSlotUpPressed = slotUpPressed;
            prevSlotDownPressed = slotDownPressed;
            prevSlot1Pressed = slot1Pressed;
            prevSlot2Pressed = slot2Pressed;
            prevSlot3Pressed = slot3Pressed;
            prevValue1Pressed = value1Pressed;
            prevValue2Pressed = value2Pressed;
            prevValue3Pressed = value3Pressed;
        }

        private static void CycleSelection(int slot, int delta)
        {
            var config = Plugin.GetItemConfig(Plugin.CurrentItemKey);
            if (config == null)
            {
                return;
            }

            var current = GetRecord(config, slot);
            var ids = ActiveField == ActiveField.Effect ? GetEffectRecordIds(current) : GetValueRecordIds(current);
            if (ids.Count == 0)
            {
                return;
            }

            var entry = GetRecordIdEntry(config, slot);
            var currentId = EnsureRecordId(config, slot);
            var index = ids.IndexOf(currentId);
            if (index < 0)
            {
                index = 0;
            }

            index = (index + delta + ids.Count) % ids.Count;
            entry.Value = ids[index];
            Plugin.ConfigFile.Save();
            Plugin.Logger.LogInfo("[EnchanceControl] " + Plugin.CurrentItemKey + " slot " + slot + " " + ActiveField + " record = " + entry.Value);
        }

        private static ConfigEntry<int> GetRecordIdEntry(ItemSlotConfig config, int slot)
        {
            if (slot == 1) return config.Slot1RecordId;
            if (slot == 2) return config.Slot2RecordId;
            return config.Slot3RecordId;
        }

        private static void RefreshTexts(ReinforceSettingPanelView view)
        {
            var config = Plugin.GetItemConfig(Plugin.CurrentItemKey);
            if (config == null)
            {
                return;
            }

            view.slot1Text.text = SlotPrefix(1) + "\u69fd\u4f4d1\uff1a" + GetDisplayName(config, 1) + "\uff08Z/X\u5207\u6362\uff09";
            view.slot2Text.text = SlotPrefix(2) + "\u69fd\u4f4d2\uff1a" + GetDisplayName(config, 2) + "\uff08Z/X\u5207\u6362\uff09";
            view.slot3Text.text = SlotPrefix(3) + "\u69fd\u4f4d3\uff1a" + GetDisplayName(config, 3) + "\uff08Z/X\u5207\u6362\uff09";
        }

        internal static void RefreshCurrentView()
        {
            if (CurrentView != null)
            {
                RefreshTexts(CurrentView);
            }
        }

        private static string SlotPrefix(int slot)
        {
            if (ActiveSlot != slot)
            {
                return "  ";
            }

            return ActiveField == ActiveField.Effect ? ">\u6548\u679c " : ">\u6570\u503c ";
        }

        private static string GetDisplayName(ItemSlotConfig config, int slot)
        {
            var record = GetRecord(config, slot);
            return record == null ? "<none>" : FormatDisplay(record.ReinforceEffectType.ToString(), record);
        }

        internal static RReinforceEffect GetRecord(ItemSlotConfig config, int slot)
        {
            var id = EnsureRecordId(config, slot);
            if (id == Plugin.StoredNoEffectId)
            {
                return MReinforceEffect.Get(MReinforceEffect.NoEffectId);
            }

            if (id > 0)
            {
                try
                {
                    return MReinforceEffect.Get(id);
                }
                catch
                {
                }
            }

            return null;
        }

        private static int EnsureRecordId(ItemSlotConfig config, int slot)
        {
            var entry = GetRecordIdEntry(config, slot);
            if (entry.Value > 0)
            {
                return entry.Value;
            }

            var record = FindLegacyRecord(config, slot);
            if (record == null)
            {
                return 0;
            }

            entry.Value = ToStoredId(record);
            Plugin.ConfigFile.Save();
            return entry.Value;
        }

        private static RReinforceEffect FindLegacyRecord(ItemSlotConfig config, int slot)
        {
            var effectName = slot == 1 ? config.Slot1Effect.Value : slot == 2 ? config.Slot2Effect.Value : config.Slot3Effect.Value;
            var kind = slot == 1 ? config.Slot1Kind.Value : slot == 2 ? config.Slot2Kind.Value : config.Slot3Kind.Value;
            var rank = GetDisplayRank();
            if (string.Equals(effectName, "Dokidoki", StringComparison.OrdinalIgnoreCase))
            {
                return MReinforceEffect.Get(MReinforceEffect.NoEffectId);
            }

            if (!Enum.TryParse(effectName, true, out ReinforceEffectType desiredType))
            {
                return null;
            }

            RReinforceEffect fallback = null;
            for (var id = 0; id <= 999; id++)
            {
                RReinforceEffect record = null;
                try
                {
                    record = MReinforceEffect.Get(id);
                }
                catch
                {
                    continue;
                }

                if (record == null || record.ReinforceEffectType != desiredType || !KindMatches(record, kind))
                {
                    continue;
                }

                if (fallback == null)
                {
                    fallback = record;
                }

                if (record.EffectRank != rank)
                {
                    continue;
                }

                return record;
            }

            return fallback;
        }

        private static List<int> GetRecordIds()
        {
            var rows = new List<RReinforceEffect>();
            for (var id = 0; id <= 999; id++)
            {
                try
                {
                    var record = MReinforceEffect.Get(id);
                    if (record != null)
                    {
                        rows.Add(record);
                    }
                }
                catch
                {
                }
            }

            rows.Sort(CompareRecords);
            var ids = new List<int>(rows.Count);
            foreach (var row in rows)
            {
                ids.Add(ToStoredId(row));
            }

            return ids;
        }

        private static int ToStoredId(RReinforceEffect record)
        {
            return record.Id == MReinforceEffect.NoEffectId ? Plugin.StoredNoEffectId : record.Id;
        }

        private static RReinforceEffect FromStoredId(int id)
        {
            return MReinforceEffect.Get(id == Plugin.StoredNoEffectId ? MReinforceEffect.NoEffectId : id);
        }

        private static List<int> GetEffectRecordIds(RReinforceEffect current)
        {
            var rows = new List<RReinforceEffect>();
            var seen = new HashSet<ReinforceEffectType>();
            RReinforceEffect noEffect = null;

            foreach (var id in GetRecordIds())
            {
                RReinforceEffect record = null;
                try
                {
                    record = FromStoredId(id);
                }
                catch
                {
                }

                if (record == null)
                {
                    continue;
                }

                if (record.Id == MReinforceEffect.NoEffectId)
                {
                    noEffect = record;
                    continue;
                }

                if (seen.Add(record.ReinforceEffectType))
                {
                    rows.Add(PickBestValueForEffect(record.ReinforceEffectType, current) ?? record);
                }
            }

            rows.Sort(CompareRecords);
            var ids = new List<int>();
            if (noEffect != null)
            {
                ids.Add(Plugin.StoredNoEffectId);
            }

            foreach (var row in rows)
            {
                ids.Add(ToStoredId(row));
            }

            return ids;
        }

        private static List<int> GetValueRecordIds(RReinforceEffect current)
        {
            var ids = new List<int>();
            if (current == null || current.Id == MReinforceEffect.NoEffectId)
            {
                ids.Add(Plugin.StoredNoEffectId);
                return ids;
            }

            var rows = new List<RReinforceEffect>();
            foreach (var id in GetRecordIds())
            {
                RReinforceEffect record = null;
                try
                {
                    record = FromStoredId(id);
                }
                catch
                {
                }

                if (record != null && record.Id != MReinforceEffect.NoEffectId && record.ReinforceEffectType == current.ReinforceEffectType)
                {
                    rows.Add(record);
                }
            }

            rows.Sort(CompareRecords);
            foreach (var row in rows)
            {
                ids.Add(ToStoredId(row));
            }

            return ids;
        }

        private static RReinforceEffect PickBestValueForEffect(ReinforceEffectType effectType, RReinforceEffect current)
        {
            RReinforceEffect best = null;
            var bestScore = int.MinValue;
            foreach (var id in GetRecordIds())
            {
                RReinforceEffect record = null;
                try
                {
                    record = FromStoredId(id);
                }
                catch
                {
                }

                if (record == null || record.Id == MReinforceEffect.NoEffectId || record.ReinforceEffectType != effectType)
                {
                    continue;
                }

                var score = 0;
                if (current != null)
                {
                    if (record.EffectRank == current.EffectRank) score += 1000;
                    if (record.IsNegativeEffect == current.IsNegativeEffect) score += 100;
                    if (record.IsNeutralEffect == current.IsNeutralEffect) score += 50;
                    score -= Math.Abs(record.EffectAmount100 - current.EffectAmount100);
                }

                if (best == null || score > bestScore)
                {
                    best = record;
                    bestScore = score;
                }
            }

            return best;
        }

        private static int CompareRecords(RReinforceEffect left, RReinforceEffect right)
        {
            if (left.Id == MReinforceEffect.NoEffectId && right.Id != MReinforceEffect.NoEffectId) return -1;
            if (right.Id == MReinforceEffect.NoEffectId && left.Id != MReinforceEffect.NoEffectId) return 1;

            var typeCompare = ((int)left.ReinforceEffectType).CompareTo((int)right.ReinforceEffectType);
            if (typeCompare != 0) return typeCompare;

            var leftKind = left.IsNegativeEffect ? 0 : left.IsNeutralEffect ? 1 : 2;
            var rightKind = right.IsNegativeEffect ? 0 : right.IsNeutralEffect ? 1 : 2;
            var kindCompare = leftKind.CompareTo(rightKind);
            if (kindCompare != 0) return kindCompare;

            var rankCompare = left.EffectRank.CompareTo(right.EffectRank);
            if (rankCompare != 0) return rankCompare;

            return left.Id.CompareTo(right.Id);
        }

        private static string FormatDisplay(string effectName, RReinforceEffect record)
        {
            var name = effectName;
            try
            {
                Localizer.LoadLocalizeDataIfNot();
                var translated = Localizer.Trans(record.NameKey);
                if (!string.IsNullOrEmpty(translated))
                {
                    name = translated;
                }
            }
            catch (Exception ex)
            {
                Plugin.Logger.LogWarning("[EnchanceControl] Failed to localize " + record.NameKey + ": " + ex.Message);
                if (!string.IsNullOrEmpty(record.NameKey))
                {
                    name = record.NameKey;
                }
            }

            if (record.Id == MReinforceEffect.NoEffectId)
            {
                return name;
            }

            var amount = record.EffectAmount100;
            var sign = amount > 0 ? "+" : string.Empty;
            var suffix = string.Empty;
            try
            {
                suffix = record.Suffix ?? string.Empty;
            }
            catch
            {
            }

            return name + " " + sign + amount + suffix;
        }

        private static int GetDisplayRank()
        {
            try
            {
                var panel = ReinforcePanelView.Instance;
                if (panel != null)
                {
                    return Clamp(panel.currentRank, 1, 3);
                }
            }
            catch
            {
            }

            return 3;
        }

        private static int Clamp(int value, int min, int max)
        {
            if (value < min) return min;
            if (value > max) return max;
            return value;
        }

        private static bool KindMatches(RReinforceEffect record, string kind)
        {
            if (string.Equals(kind, "Any", StringComparison.OrdinalIgnoreCase))
            {
                return true;
            }

            if (string.Equals(kind, "Negative", StringComparison.OrdinalIgnoreCase))
            {
                return record.IsNegativeEffect;
            }

            if (string.Equals(kind, "Neutral", StringComparison.OrdinalIgnoreCase))
            {
                return record.IsNeutralEffect;
            }

            if (string.Equals(kind, "Positive", StringComparison.OrdinalIgnoreCase))
            {
                return !record.IsNegativeEffect && !record.IsNeutralEffect;
            }

            return true;
        }

        private static bool GetKey(int keyCode)
        {
            return Il2CppInput.GetKeyInt((Il2CppKeyCode)keyCode);
        }
    }

    [HarmonyPatch(typeof(CustomizeCheckItemView), nameof(CustomizeCheckItemView.OnChangeToggle))]
    internal static class CustomizeCheckItemViewPatch
    {
        private static void Postfix(CustomizeCheckItemView __instance)
        {
            var view = ReinforceSettingPanelViewPatch.CurrentView;
            if (view == null || __instance == null)
            {
                return;
            }

            try
            {
                if (__instance.Pointer == view.slot1View.Pointer)
                {
                    ReinforceSettingPanelViewPatch.ActiveSlot = 1;
                    ReinforceSettingPanelViewPatch.ActiveField = ActiveField.Effect;
                    ReinforceSettingPanelViewPatch.RefreshCurrentView();
                }
                else if (__instance.Pointer == view.slot2View.Pointer)
                {
                    ReinforceSettingPanelViewPatch.ActiveSlot = 2;
                    ReinforceSettingPanelViewPatch.ActiveField = ActiveField.Effect;
                    ReinforceSettingPanelViewPatch.RefreshCurrentView();
                }
                else if (__instance.Pointer == view.slot3View.Pointer)
                {
                    ReinforceSettingPanelViewPatch.ActiveSlot = 3;
                    ReinforceSettingPanelViewPatch.ActiveField = ActiveField.Effect;
                    ReinforceSettingPanelViewPatch.RefreshCurrentView();
                }
            }
            catch
            {
            }
        }
    }

    [HarmonyPatch(typeof(ReinforcePanelView))]
    internal static class ReinforcePanelViewPatch
    {
        [HarmonyPostfix]
        [HarmonyPatch(nameof(ReinforcePanelView.OnClickItem))]
        private static void OnClickItemPostfix(IReinforcableRecord record)
        {
            if (record == null)
            {
                return;
            }

            try
            {
                Plugin.CurrentItemKey = record.NameKey;
                Plugin.GetItemConfig(Plugin.CurrentItemKey);
                Plugin.DumpEffectTableIfNeeded();
            }
            catch (Exception ex)
            {
                Plugin.Logger.LogWarning("[EnchanceControl] Failed to read selected equipment: " + ex.Message);
            }
        }
    }

    [HarmonyPatch(typeof(ReinforceEffectGacha), nameof(ReinforceEffectGacha.ChooseEffect))]
    internal static class ReinforceEffectGachaPatch
    {
        private static void Postfix(int rank, Il2CppStructArray<bool> settings, ref Il2CppReferenceArray<RReinforceEffect> __result)
        {
            if (!Plugin.Enabled.Value || !Plugin.OverrideGacha.Value)
            {
                return;
            }

            try
            {
                var count = __result == null ? Clamp(rank, 1, 3) : Math.Max(__result.Length, 3);
                var forced = new Il2CppReferenceArray<RReinforceEffect>(count);

                for (var i = 0; i < count; i++)
                {
                    var slot = i + 1;
                    if (slot > 3)
                    {
                        forced[i] = __result == null ? null : __result[i];
                        continue;
                    }

                    var itemConfig = Plugin.GetItemConfig(Plugin.CurrentItemKey);
                    var record = GetConfiguredRecord(slot, itemConfig);
                    if (record == null)
                    {
                        var effectName = GetSlotEffect(slot, itemConfig);
                        var kind = GetSlotKind(slot, itemConfig);
                        var effectRank = Plugin.PreferClickedRank.Value ? rank : GetSlotRank(slot);
                        record = FindBestRecord(effectName, Clamp(effectRank, 1, 3), kind);
                    }

                    if (record == null && Plugin.FillMissingWithOriginalGacha.Value && __result != null && i < __result.Length)
                    {
                        record = __result[i];
                    }

                    if (record == null)
                    {
                        record = MReinforceEffect.Get(MReinforceEffect.NoEffectId);
                    }

                    forced[i] = record;
                }

                __result = forced;
                Plugin.Logger.LogInfo("[EnchanceControl] Forced " + count + " reinforcement effect(s) for rank " + rank + " on " + (Plugin.CurrentItemKey ?? "<unknown>") + ".");
            }
            catch (Exception ex)
            {
                Plugin.Logger.LogError("[EnchanceControl] Failed to force reinforcement effects: " + ex);
            }
        }

        private static RReinforceEffect GetConfiguredRecord(int slot, ItemSlotConfig itemConfig)
        {
            var id = GetSlotRecordId(slot, itemConfig);
            if (id == Plugin.StoredNoEffectId)
            {
                return MReinforceEffect.Get(MReinforceEffect.NoEffectId);
            }

            if (id <= 0)
            {
                return null;
            }

            try
            {
                return MReinforceEffect.Get(id);
            }
            catch
            {
                return null;
            }
        }

        private static RReinforceEffect FindBestRecord(string effectName, int rank, string kind)
        {
            if (!Enum.TryParse(effectName, true, out ReinforceEffectType desiredType))
            {
                Plugin.Logger.LogWarning("[EnchanceControl] Unknown effect type: " + effectName);
                return null;
            }

            RReinforceEffect best = null;
            var bestScore = int.MinValue;

            for (var id = 0; id <= 999; id++)
            {
                RReinforceEffect record = null;
                try
                {
                    record = MReinforceEffect.Get(id);
                }
                catch
                {
                    continue;
                }

                if (record == null || record.ReinforceEffectType != desiredType)
                {
                    continue;
                }

                if (!KindMatches(record, kind))
                {
                    continue;
                }

                var rankDistance = Math.Abs(record.EffectRank - rank);
                var amount = Math.Abs(record.EffectAmount100);
                var score = -rankDistance * 100000 + amount;

                if (score > bestScore)
                {
                    best = record;
                    bestScore = score;
                }
            }

                if (best == null)
            {
                Plugin.Logger.LogWarning("[EnchanceControl] No record found for " + effectName + " rank " + rank + " kind " + kind + ".");
            }

            return best;
        }

        private static bool KindMatches(RReinforceEffect record, string kind)
        {
            if (string.Equals(kind, "Any", StringComparison.OrdinalIgnoreCase))
            {
                return true;
            }

            if (string.Equals(kind, "Negative", StringComparison.OrdinalIgnoreCase))
            {
                return record.IsNegativeEffect;
            }

            if (string.Equals(kind, "Neutral", StringComparison.OrdinalIgnoreCase))
            {
                return record.IsNeutralEffect;
            }

            if (string.Equals(kind, "Positive", StringComparison.OrdinalIgnoreCase))
            {
                return !record.IsNegativeEffect && !record.IsNeutralEffect;
            }

            Plugin.Logger.LogWarning("[EnchanceControl] Unknown kind: " + kind + ". Using Any.");
            return true;
        }

        private static string GetSlotEffect(int slot, ItemSlotConfig itemConfig)
        {
            if (itemConfig != null)
            {
                if (slot == 1) return itemConfig.Slot1Effect.Value;
                if (slot == 2) return itemConfig.Slot2Effect.Value;
                return itemConfig.Slot3Effect.Value;
            }

            if (slot == 1) return Plugin.Slot1Effect.Value;
            if (slot == 2) return Plugin.Slot2Effect.Value;
            return Plugin.Slot3Effect.Value;
        }

        private static string GetSlotKind(int slot, ItemSlotConfig itemConfig)
        {
            if (itemConfig != null)
            {
                if (slot == 1) return itemConfig.Slot1Kind.Value;
                if (slot == 2) return itemConfig.Slot2Kind.Value;
                return itemConfig.Slot3Kind.Value;
            }

            if (slot == 1) return Plugin.Slot1Kind.Value;
            if (slot == 2) return Plugin.Slot2Kind.Value;
            return Plugin.Slot3Kind.Value;
        }

        private static int GetSlotRecordId(int slot, ItemSlotConfig itemConfig)
        {
            if (itemConfig != null)
            {
                if (slot == 1) return itemConfig.Slot1RecordId.Value;
                if (slot == 2) return itemConfig.Slot2RecordId.Value;
                return itemConfig.Slot3RecordId.Value;
            }

            if (slot == 1) return Plugin.Slot1RecordId.Value;
            if (slot == 2) return Plugin.Slot2RecordId.Value;
            return Plugin.Slot3RecordId.Value;
        }

        private static int GetSlotRank(int slot)
        {
            if (slot == 1) return Plugin.Slot1Rank.Value;
            if (slot == 2) return Plugin.Slot2Rank.Value;
            return Plugin.Slot3Rank.Value;
        }

        private static int Clamp(int value, int min, int max)
        {
            if (value < min) return min;
            if (value > max) return max;
            return value;
        }
    }

}
