using System;
using System.Collections.Generic;
using System.IO;
using System.Reflection;
using BepInEx;
using BepInEx.Configuration;
using BepInEx.Logging;
using BepInEx.Unity.IL2CPP;
using ExposureUnnoticed2.Master.Action;
using ExposureUnnoticed2.Master.Item;
using ExposureUnnoticed2.Object3D.Player.Scripts;
using ExposureUnnoticed2.Object3D.ScenePlops.BuyMachine;
using ExposureUnnoticed2.Scripts.InGame;
using HarmonyLib;
using Il2CppInterop.Runtime.Injection;
using UnityEngine;

[assembly: System.Runtime.Versioning.TargetFramework(".NETCoreApp,Version=v6.0", FrameworkDisplayName = ".NET 6.0")]

namespace VendingMachinePlus
{
    [BepInPlugin(PluginGuid, PluginName, PluginVersion)]
    public sealed class Plugin : BasePlugin
    {
        public const string PluginGuid = "local.vending_machine_plus";
        public const string PluginName = "Vending Machine Plus";
        public const string PluginVersion = "1.0.5";

        internal static ManualLogSource Logger;
        internal static ConfigEntry<bool> Enabled;
        internal static ConfigEntry<float> PriceMultiplier;
        internal static ConfigEntry<int> WindowWidth;
        internal static ConfigEntry<int> WindowTop;
        internal static ConfigEntry<bool> UseExternalItemList;
        internal static ConfigEntry<string> ExternalItemListPath;
        internal static ConfigEntry<bool> ReloadExternalItemListOnOpen;
        internal static ConfigEntry<float> DiureticDurationSeconds;
        internal static ConfigEntry<float> DiureticMoisturePerSecond;
        internal static ConfigEntry<float> DiureticAutoUseDelaySeconds;
        internal static ConfigEntry<bool> TriggerUseBuyMachineAction;
        internal static ConfigEntry<bool> PlayMachineAudio;
        internal static readonly List<VendingItem> Items = new List<VendingItem>();
        private static readonly List<DefaultVendingItem> DefaultItems = new List<DefaultVendingItem>();

        private Harmony harmony;
        private GameObject host;

        public override void Load()
        {
            Logger = Log;
            Enabled = Config.Bind("General", "Enabled", true, "Enable vending machine item picker.");
            PriceMultiplier = Config.Bind("General", "PriceMultiplier", 1.0f, "Multiplier applied to each item's original price unless an item price override is set.");
            UseExternalItemList = Config.Bind("ExternalList", "UseExternalItemList", true, "Load vending machine items from an external TSV file.");
            ExternalItemListPath = Config.Bind("ExternalList", "ExternalItemListPath", Path.Combine(Paths.ConfigPath, "VendingMachinePlus", "items.tsv"), "TSV file path. Columns: Enabled<TAB>ItemType<TAB>Label<TAB>PriceOverride<TAB>Effect.");
            ReloadExternalItemListOnOpen = Config.Bind("ExternalList", "ReloadExternalItemListOnOpen", true, "Reload the external item list every time a vending machine opens.");
            DiureticDurationSeconds = Config.Bind("Diuretic", "DurationSeconds", 180f, "How long the diuretic keeps increasing urinary urge.");
            DiureticMoisturePerSecond = Config.Bind("Diuretic", "MoisturePerSecond", 0.0025f, "Urinary urge added per second while the diuretic timer is active.");
            DiureticAutoUseDelaySeconds = Config.Bind("Diuretic", "AutoUseDelaySeconds", 0.75f, "Delay after purchase before the temporary water item is auto-used.");
            WindowWidth = Config.Bind("UI", "WindowWidth", 460, "Purchase window width in pixels.");
            WindowTop = Config.Bind("UI", "WindowTop", 120, "Purchase window top position in pixels.");
            TriggerUseBuyMachineAction = Config.Bind("Compatibility", "TriggerUseBuyMachineAction", true, "After a successful purchase, trigger the original UseBuyMachine player action for mission/listener compatibility.");
            PlayMachineAudio = Config.Bind("Compatibility", "PlayMachineAudio", true, "Play the vending machine AudioSource when a purchase succeeds.");

            AddDefaultItem(ItemType.Water, "Water", true);
            AddDefaultItem(ItemType.BodyPaint, "Body Paint", true);
            AddDefaultItem(ItemType.BodyPaintWasher, "Body Paint Washer", true);
            AddDefaultItem(ItemType.InvisiblePotion, "Invisible Potion", true);
            AddDefaultItem(ItemType.InvisibleInversePotion, "Visibility Potion", true);
            AddDefaultItem(ItemType.FutanariPotion, "Futanari Potion", true);
            AddDefaultItem(ItemType.FutanariInversePotion, "Futanari Reversal Potion", true);
            AddDefaultItem(ItemType.Dildo, "Dildo", true);
            AddDefaultItem(ItemType.HandcuffKey, "Handcuff Key", true);
            AddDefaultItem(ItemType.InvisiblePotionReusable, "Reusable Invisible Potion", false);
            AddDefaultItem(ItemType.BodyPaintReusable, "Reusable Body Paint", false);
            AddDefaultItem(ItemType.VibeRemocon, "Vibe Remote", false);
            AddDefaultItem(ItemType.DroneController, "Drone Controller", false);
            AddDefaultItem(ItemType.None, "利尿剂", true, 100, "Diuretic");
            LoadItems();

            try
            {
                ClassInjector.RegisterTypeInIl2Cpp<VendingMachinePlusBehaviour>();
                EnsureHost();

                harmony = new Harmony(PluginGuid);
                harmony.PatchAll(typeof(BuyMachineInteractPatch));
                Log.LogInfo("Vending Machine Plus loaded.");
            }
            catch (Exception ex)
            {
                Log.LogError("Vending Machine Plus failed to load: " + ex);
            }
        }

        public override bool Unload()
        {
            harmony?.UnpatchSelf();
            if (host != null)
            {
                UnityEngine.Object.Destroy(host);
                host = null;
            }

            return true;
        }

        private void AddDefaultItem(ItemType type, string label, bool defaultEnabled)
        {
            AddDefaultItem(type, label, defaultEnabled, -1, string.Empty);
        }

        private void AddDefaultItem(ItemType type, string label, bool defaultEnabled, int priceOverride, string effect)
        {
            DefaultItems.Add(new DefaultVendingItem(type, label, defaultEnabled, priceOverride, effect));
        }

        internal static void LoadItems()
        {
            Items.Clear();

            if (UseExternalItemList != null && UseExternalItemList.Value)
            {
                EnsureExternalItemListFile();
                if (TryLoadExternalItemList())
                {
                    return;
                }
            }

            foreach (var item in DefaultItems)
            {
                Items.Add(new VendingItem(item.Id, item.Type, item.Enabled, item.Label, item.PriceOverride, item.Effect));
            }
        }

        private static void EnsureExternalItemListFile()
        {
            try
            {
                var path = ExternalItemListPath.Value;
                var dir = Path.GetDirectoryName(path);
                if (!string.IsNullOrEmpty(dir))
                {
                    Directory.CreateDirectory(dir);
                }

                if (File.Exists(path))
                {
                    return;
                }

                var lines = new List<string>
                {
                    "# Vending Machine Plus external item list",
                    "# Columns: Enabled<TAB>ItemType<TAB>Label<TAB>PriceOverride<TAB>Effect",
                    "# Enabled: true/false, 1/0, yes/no, on/off",
                    "# PriceOverride: -1 uses original item price * PriceMultiplier",
                    "# Use ItemType=Diuretic and Effect=Diuretic for the custom diuretic item."
                };
                foreach (var item in DefaultItems)
                {
                    lines.Add($"{item.Enabled}\t{item.Id}\t{item.Label}\t{item.PriceOverride}\t{item.Effect}");
                }

                File.WriteAllLines(path, lines);
                Logger?.LogInfo("Created external vending item list: " + path);
            }
            catch (Exception ex)
            {
                Logger?.LogWarning("Failed to create external vending item list: " + ex);
            }
        }

        private static bool TryLoadExternalItemList()
        {
            try
            {
                var path = ExternalItemListPath.Value;
                if (!File.Exists(path))
                {
                    return false;
                }

                var loaded = 0;
                var lineNumber = 0;
                foreach (var rawLine in File.ReadAllLines(path))
                {
                    lineNumber++;
                    var line = rawLine.Trim();
                    if (line.Length == 0 || line.StartsWith("#"))
                    {
                        continue;
                    }

                    var parts = rawLine.Split('\t');
                    if (parts.Length < 3)
                    {
                        Logger?.LogWarning($"Skipped vending item line {lineNumber}: expected at least 3 tab-separated columns.");
                        continue;
                    }

                    if (!TryParseBool(parts[0], out var enabled))
                    {
                        Logger?.LogWarning($"Skipped vending item line {lineNumber}: invalid Enabled value '{parts[0]}'.");
                        continue;
                    }

                    var id = parts[1].Trim();
                    var effect = parts.Length >= 5 ? parts[4].Trim() : string.Empty;
                    if (!Enum.TryParse(id, true, out ItemType type))
                    {
                        if (id.Equals("Diuretic", StringComparison.OrdinalIgnoreCase))
                        {
                            type = ItemType.None;
                            if (string.IsNullOrEmpty(effect))
                            {
                                effect = "Diuretic";
                            }
                        }
                        else
                        {
                            Logger?.LogWarning($"Skipped vending item line {lineNumber}: unknown ItemType '{parts[1]}'.");
                            continue;
                        }
                    }

                    var label = parts[2].Trim();
                    if (label.Length == 0)
                    {
                        label = id;
                    }

                    var priceOverride = -1;
                    if (parts.Length >= 4 && !int.TryParse(parts[3].Trim(), out priceOverride))
                    {
                        Logger?.LogWarning($"Skipped vending item line {lineNumber}: invalid PriceOverride '{parts[3]}'.");
                        continue;
                    }

                    Items.Add(new VendingItem(id, type, enabled, label, priceOverride, effect));
                    loaded++;
                }

                Logger?.LogInfo($"Loaded {loaded} vending items from {path}.");
                return loaded > 0;
            }
            catch (Exception ex)
            {
                Logger?.LogWarning("Failed to load external vending item list: " + ex);
                return false;
            }
        }

        private static bool TryParseBool(string text, out bool value)
        {
            switch ((text ?? string.Empty).Trim().ToLowerInvariant())
            {
                case "true":
                case "1":
                case "yes":
                case "on":
                    value = true;
                    return true;
                case "false":
                case "0":
                case "no":
                case "off":
                    value = false;
                    return true;
                default:
                    value = false;
                    return false;
            }
        }

        internal static void EnsureHost()
        {
            VendingMachinePlusBehaviour.Ensure();
        }
    }

    internal sealed class VendingItem
    {
        public readonly string Id;
        public readonly ItemType Type;
        public readonly bool Enabled;
        public readonly string Label;
        public readonly int PriceOverride;
        public readonly string Effect;

        public VendingItem(string id, ItemType type, bool enabled, string label, int priceOverride, string effect)
        {
            Id = id;
            Type = type;
            Enabled = enabled;
            Label = label;
            PriceOverride = priceOverride;
            Effect = effect ?? string.Empty;
        }

        public bool IsDiuretic => Effect.Equals("Diuretic", StringComparison.OrdinalIgnoreCase) || Id.Equals("Diuretic", StringComparison.OrdinalIgnoreCase);

        public int GetPrice()
        {
            if (PriceOverride >= 0)
            {
                return PriceOverride;
            }

            if (Type == ItemType.None)
            {
                return 0;
            }

            try
            {
                var record = MItem.Get(Type);
                var basePrice = record == null ? 0 : record.Price;
                return Math.Max(0, Mathf.RoundToInt(basePrice * Plugin.PriceMultiplier.Value));
            }
            catch
            {
                return 0;
            }
        }
    }

    internal sealed class DefaultVendingItem
    {
        public readonly string Id;
        public readonly ItemType Type;
        public readonly string Label;
        public readonly bool Enabled;
        public readonly int PriceOverride;
        public readonly string Effect;

        public DefaultVendingItem(ItemType type, string label, bool enabled, int priceOverride, string effect)
        {
            Id = string.IsNullOrEmpty(effect) ? type.ToString() : effect;
            Type = type;
            Label = label;
            Enabled = enabled;
            PriceOverride = priceOverride;
            Effect = effect ?? string.Empty;
        }
    }

    [HarmonyPatch]
    internal static class BuyMachineInteractPatch
    {
        private static MethodBase TargetMethod()
        {
            return AccessTools.Method(typeof(BuyMachineController), "OnInteract");
        }

        private static bool Prefix(BuyMachineController __instance)
        {
            if (Plugin.Enabled == null || !Plugin.Enabled.Value)
            {
                return true;
            }

            if (VendingMachinePlusBehaviour.IsHandcuffed())
            {
                VendingMachinePlusBehaviour.ShowBlockedByHandcuffs();
                return false;
            }

            VendingMachinePlusBehaviour.Open(__instance);
            return false;
        }
    }

    public sealed class VendingMachinePlusBehaviour : MonoBehaviour
    {
        private static VendingMachinePlusBehaviour instance;
        private static GameObject host;
        private static BuyMachineController currentMachine;

        private Rect windowRect;
        private int page;
        private string message = string.Empty;
        private float messageUntil;
        private bool visible;
        private bool oldCursorVisible;
        private CursorLockMode oldLockMode;
        private bool pendingDiureticUse;
        private float pendingDiureticUseDelay;
        private float diureticRemaining;

        public VendingMachinePlusBehaviour(IntPtr ptr) : base(ptr)
        {
        }

        private void Awake()
        {
            instance = this;
            ResetWindowRect();
            Plugin.Logger?.LogInfo("Vending picker UI ready.");
        }

        public static bool Ensure()
        {
            if (instance != null)
            {
                return true;
            }

            try
            {
                if (host == null)
                {
                    host = new GameObject("VendingMachinePlus");
                    UnityEngine.Object.DontDestroyOnLoad(host);
                }

                instance = host.GetComponent<VendingMachinePlusBehaviour>();
                if (instance == null)
                {
                    instance = host.AddComponent<VendingMachinePlusBehaviour>();
                }

                return instance != null;
            }
            catch (Exception ex)
            {
                Plugin.Logger?.LogWarning("Failed to create vending picker UI: " + ex);
                return false;
            }
        }

        public static void Open(BuyMachineController machine)
        {
            if (!Ensure())
            {
                Plugin.Logger?.LogWarning("Vending picker is not ready.");
                return;
            }

            if (IsHandcuffed())
            {
                ShowBlockedByHandcuffs();
                return;
            }

            currentMachine = machine;
            if (Plugin.ReloadExternalItemListOnOpen?.Value == true)
            {
                Plugin.LoadItems();
            }

            instance.visible = true;
            instance.message = string.Empty;
            instance.messageUntil = 0f;
            instance.ResetWindowRect();
            instance.EnableCursor();
        }

        public static bool IsHandcuffed()
        {
            var handcuffed = false;
            try
            {
                handcuffed = GameStateFacade.IsAttachSomeHandcuffs();
            }
            catch (Exception ex)
            {
                Plugin.Logger?.LogWarning("Handcuff facade check failed: " + ex.Message);
            }

            if (handcuffed)
            {
                return true;
            }

            try
            {
                var data = GameState.GameStateData;
                if (data == null)
                {
                    return false;
                }

                if (data.PlayerIsAttachHandcuffs || data.PlayerIsAttachMapHandcuffs)
                {
                    return true;
                }

                var cuffType = data.AttachedHandcuffType.ToString();
                return !string.IsNullOrEmpty(cuffType) && !cuffType.Equals("None", StringComparison.OrdinalIgnoreCase);
            }
            catch (Exception ex)
            {
                Plugin.Logger?.LogWarning("Handcuff state check failed: " + ex.Message);
                return false;
            }
        }

        public static void ShowBlockedByHandcuffs()
        {
            if (instance != null)
            {
                instance.visible = false;
                currentMachine = null;
                instance.RestoreCursor();
            }

            Plugin.Logger?.LogInfo("Vending machine blocked: player is handcuffed.");
        }

        private void ResetWindowRect()
        {
            var width = Mathf.Clamp(Plugin.WindowWidth?.Value ?? 460, 320, 900);
            var x = Mathf.Max(12, (Screen.width - width) / 2);
            var y = Mathf.Clamp(Plugin.WindowTop?.Value ?? 120, 20, Math.Max(20, Screen.height - 220));
            windowRect = new Rect(x, y, width, 520);
        }

        private void OnGUI()
        {
            if (!visible)
            {
                return;
            }

            DrawPanel();
        }

        private void DrawPanel()
        {
            var width = windowRect.width;
            GUI.Box(windowRect, "Vending Machine");

            var localX = windowRect.x;
            var localY = windowRect.y;
            GUI.Label(new Rect(localX + 16, localY + 28, width - 32, 24), "Choose an item to buy");

            if (!string.IsNullOrEmpty(message) && Time.realtimeSinceStartup < messageUntil)
            {
                GUI.Label(new Rect(localX + 16, localY + 54, width - 32, 24), message);
            }

            var listTop = 82f;
            var listHeight = 336f;
            var enabledCount = CountEnabledItems();
            var pageSize = 8;
            var maxPage = Math.Max(0, (enabledCount - 1) / pageSize);
            if (page > maxPage)
            {
                page = maxPage;
            }

            GUI.Box(new Rect(localX + 12, localY + listTop, width - 24, listHeight), GUIContent.none);

            var visibleRow = 0;
            var enabledIndex = 0;
            for (var i = 0; i < Plugin.Items.Count; i++)
            {
                var item = Plugin.Items[i];
                if (!item.Enabled)
                {
                    continue;
                }

                if (enabledIndex >= page * pageSize && visibleRow < pageSize)
                {
                    DrawItem(i, visibleRow, localX + 20, localY + listTop + 8, width - 40);
                    visibleRow++;
                }

                enabledIndex++;
            }

            var navY = localY + listTop + listHeight + 8;
            GUI.enabled = page > 0;
            if (GUI.Button(new Rect(localX + 16, navY, 90, 30), "Prev"))
            {
                page--;
            }

            GUI.enabled = true;
            GUI.Label(new Rect(localX + 116, navY + 6, width - 232, 24), $"Page {page + 1}/{maxPage + 1}");

            GUI.enabled = page < maxPage;
            if (GUI.Button(new Rect(localX + width - 106, navY, 90, 30), "Next"))
            {
                page++;
            }

            GUI.enabled = true;

            if (GUI.Button(new Rect(localX + 16, navY + 40, width - 32, 34), "Close"))
            {
                Close();
            }
        }

        private int CountEnabledItems()
        {
            var count = 0;
            foreach (var item in Plugin.Items)
            {
                if (item.Enabled)
                {
                    count++;
                }
            }

            return count;
        }

        private void DrawItem(int itemIndex, int row, float x, float yStart, float width)
        {
            var item = Plugin.Items[itemIndex];
            var price = item.GetPrice();
            var y = yStart + row * 40;
            GUI.Box(new Rect(x, y, width, 36), GUIContent.none);
            GUI.Label(new Rect(x + 10, y + 8, width - 190, 22), item.Label);
            GUI.Label(new Rect(x + width - 170, y + 8, 78, 22), price + " RP");

            var enough = GameStateFacade.IsEnoughRp(price);
            var handcuffed = IsHandcuffed();
            GUI.enabled = enough && !handcuffed;
            var buttonText = handcuffed ? "Cuffed" : enough ? "Buy" : "No RP";
            if (GUI.Button(new Rect(x + width - 88, y + 4, 80, 28), buttonText))
            {
                Purchase(itemIndex, price);
            }

            GUI.enabled = true;
        }

        private void Purchase(int itemIndex, int price)
        {
            var item = Plugin.Items[itemIndex];
            try
            {
                if (IsHandcuffed())
                {
                    FlashMessage("Cannot use vending machine while handcuffed.");
                    return;
                }

                if (!GameStateFacade.IsEnoughRp(price))
                {
                    FlashMessage("Not enough RP.");
                    return;
                }

                GameStateFacade.ConsumeRp(price);
                if (item.IsDiuretic)
                {
                    GameStateFacade.ChangeItemNum(ItemType.Water, 1);
                    pendingDiureticUse = true;
                    pendingDiureticUseDelay = Mathf.Max(0f, Plugin.DiureticAutoUseDelaySeconds?.Value ?? 0.75f);
                }
                else
                {
                    GameStateFacade.ChangeItemNum(item.Type, 1);
                }

                if (Plugin.PlayMachineAudio.Value)
                {
                    currentMachine?.audioSource?.Play();
                }

                if (Plugin.TriggerUseBuyMachineAction.Value)
                {
                    PlayerController.Instance?.pca?.PlayerFacade?.TransAction(ActionType.UseBuyMachine);
                }

                FlashMessage("Purchased " + item.Label + ".");
                Plugin.Logger?.LogInfo($"Purchased {item.Id} for {price} RP from vending machine.");
            }
            catch (Exception ex)
            {
                FlashMessage("Purchase failed. See BepInEx log.");
                Plugin.Logger?.LogWarning("Purchase failed: " + ex);
            }
        }

        private void FlashMessage(string text)
        {
            message = text;
            messageUntil = Time.realtimeSinceStartup + 2.5f;
        }

        private void Update()
        {
            UpdateDiuretic();

            if (!visible)
            {
                return;
            }

            if (Input.GetKeyDown(KeyCode.Escape))
            {
                Close();
            }
        }

        private void UpdateDiuretic()
        {
            var dt = Time.deltaTime;
            if (pendingDiureticUse)
            {
                pendingDiureticUseDelay -= dt;
                if (pendingDiureticUseDelay <= 0f)
                {
                    pendingDiureticUse = false;
                    UsePendingDiureticWater();
                }
            }

            if (diureticRemaining > 0f)
            {
                diureticRemaining -= dt;
                try
                {
                    var add = Mathf.Max(0f, Plugin.DiureticMoisturePerSecond?.Value ?? 0.0025f) * dt;
                    if (add > 0f)
                    {
                        PlayerController.Instance?.pca?.PlayerFacade?.AddAddMoisture(add);
                    }
                }
                catch (Exception ex)
                {
                    Plugin.Logger?.LogWarning("Diuretic moisture update failed: " + ex);
                    diureticRemaining = 0f;
                }
            }
        }

        private void UsePendingDiureticWater()
        {
            try
            {
                var water = MItem.Get(ItemType.Water);
                if (water != null)
                {
                    MItem.UseItemProcess(water);
                }
                else
                {
                    PlayerController.Instance?.pca?.PlayerFacade?.TransAction(ActionType.DrinkWater);
                    PlayerController.Instance?.pca?.PlayerFacade?.AddAddMoisture(0.25f);
                    GameStateFacade.ChangeItemNum(ItemType.Water, -1);
                }

                diureticRemaining = Mathf.Max(0f, Plugin.DiureticDurationSeconds?.Value ?? 180f);
                FlashMessage("Diuretic active.");
                Plugin.Logger?.LogInfo($"Diuretic active for {diureticRemaining:0.0} seconds.");
            }
            catch (Exception ex)
            {
                FlashMessage("Diuretic failed. See BepInEx log.");
                Plugin.Logger?.LogWarning("Diuretic auto-use failed: " + ex);
            }
        }

        private void Close()
        {
            visible = false;
            currentMachine = null;
            RestoreCursor();
        }

        private void EnableCursor()
        {
            oldCursorVisible = Cursor.visible;
            oldLockMode = Cursor.lockState;
            Cursor.visible = true;
            Cursor.lockState = CursorLockMode.None;
        }

        private void RestoreCursor()
        {
            Cursor.visible = oldCursorVisible;
            Cursor.lockState = oldLockMode;
        }

        private void OnDestroy()
        {
            if (instance == this)
            {
                instance = null;
            }

            if (host == gameObject)
            {
                host = null;
            }
        }
    }
}
