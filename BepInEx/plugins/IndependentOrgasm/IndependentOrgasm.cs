using System;
using System.Diagnostics;
using System.Reflection;
using BepInEx;
using BepInEx.Configuration;
using BepInEx.Logging;
using BepInEx.Unity.IL2CPP;
using HarmonyLib;

[assembly: System.Runtime.Versioning.TargetFramework(".NETCoreApp,Version=v6.0", FrameworkDisplayName = ".NET 6.0")]

namespace IndependentOrgasm
{
    [BepInPlugin(PluginGuid, PluginName, PluginVersion)]
    public sealed class Plugin : BasePlugin
    {
        public const string PluginGuid = "local.independent_orgasm";
        public const string PluginName = "Independent Orgasm";
        public const string PluginVersion = "0.1.0";

        internal static ManualLogSource Logger;
        private Harmony harmony;

        public override void Load()
        {
            Logger = Log;
            Settings.Bind(Config);
            IndependentOrgasmSystem.Initialize();

            try
            {
                harmony = new Harmony(PluginGuid);
                harmony.PatchAll(typeof(PlayerEcstasyControllerPatch));
                harmony.PatchAll(typeof(InGameUiManagerPatch));
                harmony.PatchAll(typeof(InGameUiManagerInitializePatch));
                harmony.PatchAll(typeof(BlackCensorControllerPatch));
                Log.LogInfo("Independent Orgasm loaded. Four independent meters: vaginal, clit, anal, nipple.");
            }
            catch (Exception ex)
            {
                Log.LogError("Independent Orgasm failed to patch PlayerEcstasyController.OnUpdate: " + ex);
            }
        }
    }

    internal static class Settings
    {
        public static ConfigEntry<bool> Enabled;
        public static ConfigEntry<bool> OverrideVanillaEcstasy;
        public static ConfigEntry<bool> TriggerVanillaAnimation;
        public static ConfigEntry<bool> MirrorStrongestMeterToVanillaGauge;
        public static ConfigEntry<bool> TreatFutaPistonAsVaginal;
        public static ConfigEntry<bool> ReplaceEcstasyGaugeWithPartGauges;
        public static ConfigEntry<float> PartGaugeHorizontalSpacing;
        public static ConfigEntry<float> PartGaugeVerticalSpacing;
        public static ConfigEntry<float> PartGaugeScaleX;
        public static ConfigEntry<float> PartGaugeScaleY;
        public static ConfigEntry<float> OrgasmThreshold;
        public static ConfigEntry<float> CooldownSeconds;
        public static ConfigEntry<float> DecayPerSecond;
        public static ConfigEntry<float> DildoActionRate;
        public static ConfigEntry<float> ClitActionRate;
        public static ConfigEntry<float> NippleActionRate;
        public static ConfigEntry<float> VibratorLowRate;
        public static ConfigEntry<float> VibratorHighRate;
        public static ConfigEntry<float> PistonBaseRate;
        public static ConfigEntry<bool> LogEvents;
        public static ConfigEntry<bool> LogMeters;
        public static ConfigEntry<float> LogMeterInterval;

        public static void Bind(ConfigFile config)
        {
            Enabled = config.Bind("General", "Enabled", true, "Enable independent orgasm calculation.");
            OverrideVanillaEcstasy = config.Bind("General", "OverrideVanillaEcstasy", true, "Skip the original PlayerEcstasyController.OnUpdate and use independent part meters instead.");
            TriggerVanillaAnimation = config.Bind("General", "TriggerVanillaAnimation", true, "Call the game's original orgasm animation transition when one independent meter reaches the threshold.");
            MirrorStrongestMeterToVanillaGauge = config.Bind("General", "MirrorStrongestMeterToVanillaGauge", false, "Write the strongest independent meter back to the vanilla ecstasy gauge for mission compatibility.");
            TreatFutaPistonAsVaginal = config.Bind("General", "TreatFutaPistonAsVaginal", false, "Count PistonFuta stimulation as vaginal stimulation.");

            ReplaceEcstasyGaugeWithPartGauges = config.Bind("UI", "ReplaceEcstasyGaugeWithPartGauges", true, "Replace the vanilla ecstasy gauge with four independent part gauges.");
            PartGaugeHorizontalSpacing = config.Bind("UI", "PartGaugeHorizontalSpacing", 14.0f, "Horizontal spacing between independent part gauges.");
            PartGaugeVerticalSpacing = config.Bind("UI", "PartGaugeVerticalSpacing", 0.0f, "Vertical spacing between independent part gauges.");
            PartGaugeScaleX = config.Bind("UI", "PartGaugeScaleX", 0.75f, "Horizontal scale of each independent part gauge.");
            PartGaugeScaleY = config.Bind("UI", "PartGaugeScaleY", 1.0f, "Vertical scale of each independent part gauge.");

            OrgasmThreshold = config.Bind("Meters", "OrgasmThreshold", 1.0f, "Meter value needed to trigger orgasm.");
            CooldownSeconds = config.Bind("Meters", "CooldownSeconds", 2.0f, "Minimum seconds after an independent orgasm before another one can trigger.");
            DecayPerSecond = config.Bind("Meters", "DecayPerSecond", 0.015f, "Per-second decay applied to inactive meters.");

            DildoActionRate = config.Bind("Rates", "DildoActionRate", 0.16f, "Per-second gain for dildo pussy/anal actions.");
            ClitActionRate = config.Bind("Rates", "ClitActionRate", 0.14f, "Per-second gain for clit masturbation actions.");
            NippleActionRate = config.Bind("Rates", "NippleActionRate", 0.12f, "Per-second gain for nipple actions.");
            VibratorLowRate = config.Bind("Rates", "VibratorLowRate", 0.045f, "Per-second gain for low vibrator/rotor stimulation.");
            VibratorHighRate = config.Bind("Rates", "VibratorHighRate", 0.09f, "Per-second gain for high vibrator/rotor stimulation.");
            PistonBaseRate = config.Bind("Rates", "PistonBaseRate", 0.11f, "Per-second gain for piston stimulation. Higher piston modes scale this up.");

            LogEvents = config.Bind("Logging", "LogEvents", true, "Log independent orgasm trigger events.");
            LogMeters = config.Bind("Logging", "LogMeters", false, "Periodically log all four meter values.");
            LogMeterInterval = config.Bind("Logging", "LogMeterInterval", 2.0f, "Seconds between meter logs when LogMeters is enabled.");
        }
    }

    [HarmonyPatch]
    internal static class PlayerEcstasyControllerPatch
    {
        private static MethodBase TargetMethod()
        {
            var type = TypeResolver.Find("ExposureUnnoticed2.Object3D.Player.Scripts.PlayerEcstasyController");
            var method = type == null ? null : type.GetMethod("OnUpdate", BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
            if (method == null)
            {
                throw new MissingMethodException("ExposureUnnoticed2.Object3D.Player.Scripts.PlayerEcstasyController", "OnUpdate");
            }

            return method;
        }

        private static bool Prefix(object __instance)
        {
            if (!Settings.Enabled.Value || !Settings.OverrideVanillaEcstasy.Value)
            {
                return true;
            }

            IndependentOrgasmSystem.Tick(__instance);
            return false;
        }
    }

    internal enum Part
    {
        Vaginal,
        Clit,
        Anal,
        Nipple
    }

    [HarmonyPatch]
    internal static class InGameUiManagerPatch
    {
        private static MethodBase TargetMethod()
        {
            var type = TypeResolver.Find("ExposureUnnoticed2.Object3D.IngameManager.InGameUiManager");
            var method = type == null ? null : type.GetMethod("OnLateUpdate", BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
            if (method == null)
            {
                throw new MissingMethodException("ExposureUnnoticed2.Object3D.IngameManager.InGameUiManager", "OnLateUpdate");
            }

            return method;
        }

        private static void Postfix(object __instance)
        {
            if (!Settings.Enabled.Value || !Settings.ReplaceEcstasyGaugeWithPartGauges.Value)
            {
                return;
            }

            PartGaugeUiController.Update(__instance);
        }
    }

    [HarmonyPatch]
    internal static class InGameUiManagerInitializePatch
    {
        private static MethodBase TargetMethod()
        {
            var type = TypeResolver.Find("ExposureUnnoticed2.Object3D.IngameManager.InGameUiManager");
            var method = type == null ? null : type.GetMethod("Initialize", BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
            if (method == null)
            {
                throw new MissingMethodException("ExposureUnnoticed2.Object3D.IngameManager.InGameUiManager", "Initialize");
            }

            return method;
        }

        private static void Postfix(object __instance)
        {
            if (!Settings.Enabled.Value || !Settings.ReplaceEcstasyGaugeWithPartGauges.Value)
            {
                return;
            }

            PartGaugeUiController.Update(__instance);
        }
    }

    [HarmonyPatch]
    internal static class BlackCensorControllerPatch
    {
        private static bool logged;

        private static MethodBase TargetMethod()
        {
            var type = TypeResolver.Find("ExposureUnnoticed2.Object3D.Player.Scripts.Other.BlackCensorController");
            var method = type == null ? null : type.GetMethod("OnChange", BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
            if (method == null)
            {
                throw new MissingMethodException("ExposureUnnoticed2.Object3D.Player.Scripts.Other.BlackCensorController", "OnChange");
            }

            return method;
        }

        private static bool Prefix()
        {
            if (!logged)
            {
                logged = true;
                Plugin.Logger.LogWarning("[IndependentOrgasm] Disabled BlackCensorController.OnChange to suppress null reference spam.");
            }

            return false;
        }
    }

    internal static class IndependentOrgasmSystem
    {
        private static readonly BindingFlags InstanceFlags = BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic;
        private static readonly BindingFlags StaticFlags = BindingFlags.Static | BindingFlags.Public | BindingFlags.NonPublic;

        private static readonly Stopwatch Clock = Stopwatch.StartNew();
        private static double lastTime;
        private static double cooldownUntil;
        private static double nextMeterLog;

        private static float vaginal;
        private static float clit;
        private static float anal;
        private static float nipple;

        private static Type adultGoodsType;
        private static Type gameStateType;
        private static Type gameStateFacadeType;
        private static Type vibratorControllerType;

        public static void Initialize()
        {
            adultGoodsType = TypeResolver.Find("ExposureUnnoticed2.Master.AdultGoods.MAdultGoodsType");
            gameStateType = TypeResolver.Find("ExposureUnnoticed2.Scripts.InGame.GameState");
            gameStateFacadeType = TypeResolver.Find("ExposureUnnoticed2.Scripts.InGame.GameStateFacade");
            vibratorControllerType = TypeResolver.Find("ExposureUnnoticed2.Object3D.AdultGoods.CommonVibratorController");
        }

        public static void Tick(object ecstasyController)
        {
            var now = Clock.Elapsed.TotalSeconds;
            var dt = lastTime <= 0 ? 0.016f : (float)(now - lastTime);
            lastTime = now;

            if (dt < 0.001f)
            {
                dt = 0.001f;
            }
            else if (dt > 0.1f)
            {
                dt = 0.1f;
            }

            try
            {
                var pca = GetValue(ecstasyController, "pca");
                if (pca == null)
                {
                    return;
                }

                var state = GetValue(pca, "PlayerState");
                if (ToBool(GetValue(state, "IsEcstasyMotion")))
                {
                    SetVanillaEcstasy(1.0f);
                    return;
                }

                ApplySources(pca, dt);

                var strongest = Strongest();
                if (Settings.MirrorStrongestMeterToVanillaGauge.Value)
                {
                    SetVanillaEcstasy(Math.Min(strongest, Settings.OrgasmThreshold.Value - 0.001f));
                }

                if (now >= cooldownUntil)
                {
                    TryTrigger(pca, now);
                }

                LogMeters(now);
            }
            catch (Exception ex)
            {
                Plugin.Logger.LogWarning("[IndependentOrgasm] Tick failed: " + ex.Message);
            }
        }

        public static float GetMeter(Part part)
        {
            if (part == Part.Vaginal)
            {
                return vaginal;
            }
            if (part == Part.Clit)
            {
                return clit;
            }
            if (part == Part.Anal)
            {
                return anal;
            }

            return nipple;
        }

        public static float GetMeterNormalized(Part part)
        {
            var threshold = Math.Max(0.1f, Settings.OrgasmThreshold.Value);
            return Clamp(GetMeter(part) / threshold, 0f, 1f);
        }

        private static void ApplySources(object pca, float dt)
        {
            var rates = new PartRates();
            var state = GetValue(pca, "PlayerState");
            var actionType = GetActionType(state);
            ApplyActionRates(actionType, ref rates);
            ApplyToyRates(ref rates);

            vaginal = ApplyRate(vaginal, rates.Vaginal, dt);
            clit = ApplyRate(clit, rates.Clit, dt);
            anal = ApplyRate(anal, rates.Anal, dt);
            nipple = ApplyRate(nipple, rates.Nipple, dt);
        }

        private static float ApplyRate(float value, float rate, float dt)
        {
            if (rate > 0f)
            {
                value += rate * dt;
            }
            else
            {
                value -= Settings.DecayPerSecond.Value * dt;
            }

            return Clamp(value, 0f, Math.Max(1f, Settings.OrgasmThreshold.Value + 0.2f));
        }

        private static void ApplyActionRates(int actionType, ref PartRates rates)
        {
            if (InRange(actionType, 10030, 10034) || InRange(actionType, 10045, 10049) || actionType == 10060 || actionType == 10063)
            {
                rates.Vaginal += Settings.DildoActionRate.Value;
            }
            else if (InRange(actionType, 10035, 10039) || InRange(actionType, 10050, 10054) || actionType == 10061 || actionType == 10064)
            {
                rates.Anal += Settings.DildoActionRate.Value;
            }
            else if (actionType == 50018 || actionType == 50014 || actionType == 50015 || actionType == 50016 || actionType == 50019)
            {
                rates.Clit += Settings.ClitActionRate.Value;
            }
            else if (actionType == 50013)
            {
                rates.Nipple += Settings.NippleActionRate.Value;
            }
        }

        private static void ApplyToyRates(ref PartRates rates)
        {
            var vibeRate = CurrentVibratorRate();
            if (vibeRate > 0f)
            {
                if (IsEquipAdultGoods(1))
                {
                    rates.Vaginal += vibeRate;
                }
                if (IsEquipAdultGoods(7))
                {
                    rates.Clit += vibeRate;
                }
                if (IsEquipAdultGoods(6))
                {
                    rates.Nipple += vibeRate;
                }
                if (IsEquipAdultGoods(0))
                {
                    rates.Anal += vibeRate * 0.5f;
                }
            }

            var pistonMode = GetPistonMode();
            if (pistonMode > 0)
            {
                var pistonRate = Settings.PistonBaseRate.Value * (1f + Math.Min(3, pistonMode - 1) * 0.35f);
                if (IsEquipAdultGoods(10))
                {
                    rates.Vaginal += pistonRate;
                }
                if (IsEquipAdultGoods(9))
                {
                    rates.Anal += pistonRate;
                }
                if (Settings.TreatFutaPistonAsVaginal.Value && IsEquipAdultGoods(8))
                {
                    rates.Vaginal += pistonRate;
                }
            }
        }

        private static void TryTrigger(object pca, double now)
        {
            var threshold = Math.Max(0.1f, Settings.OrgasmThreshold.Value);
            var part = Part.Vaginal;
            var value = vaginal;
            if (clit > value)
            {
                part = Part.Clit;
                value = clit;
            }
            if (anal > value)
            {
                part = Part.Anal;
                value = anal;
            }
            if (nipple > value)
            {
                part = Part.Nipple;
                value = nipple;
            }

            if (value < threshold)
            {
                return;
            }

            var beforeText = MeterText();
            SetPart(part, 0f);
            cooldownUntil = now + Math.Max(0.1f, Settings.CooldownSeconds.Value);
            SetVanillaEcstasy(1.0f);

            if (Settings.TriggerVanillaAnimation.Value)
            {
                TriggerVanillaOrgasm(pca);
            }

            if (Settings.LogEvents.Value)
            {
                Plugin.Logger.LogInfo("[IndependentOrgasm] Trigger " + part + " orgasm. before=" + beforeText + ", after=" + MeterText() + ", cooldown=" + Settings.CooldownSeconds.Value.ToString("0.00"));
            }
        }

        private static void TriggerVanillaOrgasm(object pca)
        {
            var animationManager = GetValue(pca, "PlayerAnimationManager");
            if (animationManager == null)
            {
                Plugin.Logger.LogWarning("[IndependentOrgasm] PlayerAnimationManager was null; cannot trigger vanilla orgasm animation.");
                return;
            }

            Invoke(animationManager, "TransEcstasy");
        }

        private static void LogMeters(double now)
        {
            if (!Settings.LogMeters.Value || now < nextMeterLog)
            {
                return;
            }

            nextMeterLog = now + Math.Max(0.2f, Settings.LogMeterInterval.Value);
            Plugin.Logger.LogInfo("[IndependentOrgasm] meters=" + MeterText());
        }

        private static string MeterText()
        {
            return "vaginal=" + vaginal.ToString("0.00") + ", clit=" + clit.ToString("0.00") + ", anal=" + anal.ToString("0.00") + ", nipple=" + nipple.ToString("0.00");
        }

        private static float Strongest()
        {
            return Math.Max(Math.Max(vaginal, clit), Math.Max(anal, nipple));
        }

        private static void SetPart(Part part, float value)
        {
            if (part == Part.Vaginal)
            {
                vaginal = value;
            }
            else if (part == Part.Clit)
            {
                clit = value;
            }
            else if (part == Part.Anal)
            {
                anal = value;
            }
            else
            {
                nipple = value;
            }
        }

        private static int GetActionType(object state)
        {
            var action = GetValue(state, "CurrentAction");
            var value = GetValue(action, "Type");
            if (value == null)
            {
                value = GetValue(action, "type");
            }

            return ToInt(value);
        }

        private static float CurrentVibratorRate()
        {
            var strength = GetStaticInt(vibratorControllerType, "VibrationStrength");
            if (strength <= 0)
            {
                return 0f;
            }

            if (strength == 1)
            {
                return Settings.VibratorLowRate.Value;
            }

            if (strength == 2)
            {
                return Settings.VibratorHighRate.Value;
            }

            return (Settings.VibratorLowRate.Value + Settings.VibratorHighRate.Value) * 0.5f;
        }

        private static int GetPistonMode()
        {
            var data = GetGameStateData();
            var mode = ToInt(GetValue(data, "PistonMachineModeType"));
            if (mode > 0)
            {
                return mode;
            }

            var pistonType = TypeResolver.Find("ExposureUnnoticed2.Object3D.Player.Scripts.Costume.PistonMachineController");
            return GetStaticInt(pistonType, "Mode");
        }

        private static bool IsEquipAdultGoods(int id)
        {
            if (gameStateFacadeType == null || adultGoodsType == null)
            {
                return false;
            }

            var method = gameStateFacadeType.GetMethod("IsEquipAdultGoods", StaticFlags, null, new[] { adultGoodsType }, null);
            if (method == null)
            {
                return false;
            }

            var enumValue = Enum.ToObject(adultGoodsType, id);
            return ToBool(method.Invoke(null, new[] { enumValue }));
        }

        private static object GetGameStateData()
        {
            if (gameStateType == null)
            {
                return null;
            }

            var getter = AccessTools.PropertyGetter(gameStateType, "GameStateData");
            return getter == null ? null : getter.Invoke(null, null);
        }

        private static void SetVanillaEcstasy(float value)
        {
            var data = GetGameStateData();
            if (data == null)
            {
                return;
            }

            SetValue(data, "PlayerEcstasy", Clamp(value, 0f, 1.1f));
        }

        public static object GetValue(object obj, string name)
        {
            if (obj == null)
            {
                return null;
            }

            var type = obj as Type;
            var targetType = type ?? obj.GetType();
            var flags = type == null ? InstanceFlags : StaticFlags;

            var property = targetType.GetProperty(name, flags);
            if (property != null)
            {
                return property.GetValue(type == null ? obj : null, null);
            }

            var field = targetType.GetField(name, flags);
            return field == null ? null : field.GetValue(type == null ? obj : null);
        }

        public static void SetValue(object obj, string name, object value)
        {
            if (obj == null)
            {
                return;
            }

            var property = obj.GetType().GetProperty(name, InstanceFlags);
            if (property != null)
            {
                property.SetValue(obj, value, null);
                return;
            }

            var field = obj.GetType().GetField(name, InstanceFlags);
            if (field != null)
            {
                field.SetValue(obj, value);
            }
        }

        public static void Invoke(object obj, string name)
        {
            if (obj == null)
            {
                return;
            }

            var method = obj.GetType().GetMethod(name, InstanceFlags, null, Type.EmptyTypes, null);
            if (method != null)
            {
                method.Invoke(obj, null);
            }
        }

        private static int GetStaticInt(Type type, string propertyName)
        {
            return ToInt(GetValue(type, propertyName));
        }

        private static int ToInt(object value)
        {
            if (value == null)
            {
                return 0;
            }

            try
            {
                return Convert.ToInt32(value);
            }
            catch
            {
                return 0;
            }
        }

        private static bool ToBool(object value)
        {
            if (value == null)
            {
                return false;
            }

            if (value is bool)
            {
                return (bool)value;
            }

            return ToInt(value) != 0;
        }

        private static bool InRange(int value, int min, int max)
        {
            return value >= min && value <= max;
        }

        public static float Clamp(float value, float min, float max)
        {
            if (value < min)
            {
                return min;
            }

            if (value > max)
            {
                return max;
            }

            return value;
        }

        private struct PartRates
        {
            public float Vaginal;
            public float Clit;
            public float Anal;
            public float Nipple;
        }
    }

    internal static class PartGaugeUiController
    {
        private static readonly BindingFlags Flags = BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic;

        private static object sourceGauge;
        private static readonly object[] gauges = new object[4];
        private static readonly object[] gaugeObjects = new object[4];
        private static readonly MethodInfo[] setMethods = new MethodInfo[4];
        private static float baseX;
        private static float baseY;
        private static bool hasBasePosition;
        private static bool created;
        private static bool warned;
        private static bool loggedFirstUpdate;
        private static bool loggedMissingGauge;
        private static bool loggedCreated;

        public static void Update(object uiManager)
        {
            try
            {
                if (!loggedFirstUpdate)
                {
                    loggedFirstUpdate = true;
                    Plugin.Logger.LogInfo("[IndependentOrgasm] InGameUiManager UI patch reached.");
                }

                Ensure(uiManager);
                SetGauge(0, IndependentOrgasmSystem.GetMeterNormalized(Part.Vaginal));
                SetGauge(1, IndependentOrgasmSystem.GetMeterNormalized(Part.Clit));
                SetGauge(2, IndependentOrgasmSystem.GetMeterNormalized(Part.Anal));
                SetGauge(3, IndependentOrgasmSystem.GetMeterNormalized(Part.Nipple));
            }
            catch (Exception ex)
            {
                if (!warned)
                {
                    warned = true;
                    Plugin.Logger.LogWarning("[IndependentOrgasm] Part gauge UI failed: " + ex.Message);
                }
            }
        }

        private static void Ensure(object uiManager)
        {
            if (created)
            {
                return;
            }

            var ecstasyGauge = IndependentOrgasmSystem.GetValue(uiManager, "ecstasyGauge");
            if (ecstasyGauge == null)
            {
                if (!loggedMissingGauge)
                {
                    loggedMissingGauge = true;
                    Plugin.Logger.LogWarning("[IndependentOrgasm] InGameUiManager.ecstasyGauge is null; cannot create part gauges yet.");
                }
                return;
            }

            sourceGauge = ecstasyGauge;
            gauges[0] = ecstasyGauge;
            gaugeObjects[0] = IndependentOrgasmSystem.GetValue(ecstasyGauge, "gameObject");
            setMethods[0] = GetSetMethod(gauges[0]);
            CaptureBasePosition(ecstasyGauge);

            for (var i = 1; i < 4; i++)
            {
                gaugeObjects[i] = CloneGaugeObject(gaugeObjects[0], "IndependentOrgasmGauge" + i);
                gauges[i] = GetGaugeComponent(gaugeObjects[i]);
                setMethods[i] = GetSetMethod(gauges[i]);
                Plugin.Logger.LogInfo("[IndependentOrgasm] Part gauge clone " + i + ": object=" + (gaugeObjects[i] != null) + ", gauge=" + (gauges[i] != null));
            }

            Layout();
            created = true;
            if (!loggedCreated)
            {
                loggedCreated = true;
                Plugin.Logger.LogInfo("[IndependentOrgasm] Replaced vanilla ecstasy gauge with four part gauges.");
            }
        }

        private static object CloneGaugeObject(object originalGameObject, string name)
        {
            if (originalGameObject == null)
            {
                return null;
            }

            var objectType = TypeResolver.FindUnity("UnityEngine.Object", "UnityEngine.CoreModule");
            var transform = IndependentOrgasmSystem.GetValue(originalGameObject, "transform");
            var parent = IndependentOrgasmSystem.GetValue(transform, "parent");
            var method = objectType == null ? null : objectType.GetMethod("Instantiate", BindingFlags.Static | BindingFlags.Public, null, new[] { objectType, TypeResolver.FindUnity("UnityEngine.Transform", "UnityEngine.CoreModule"), typeof(bool) }, null);
            var clone = method == null ? null : method.Invoke(null, new[] { originalGameObject, parent, false });
            if (clone != null)
            {
                IndependentOrgasmSystem.SetValue(clone, "name", name);
                InvokeMethod(clone, "SetActive", new object[] { true });
                var cloneTransform = IndependentOrgasmSystem.GetValue(clone, "transform");
                InvokeMethod(cloneTransform, "SetAsLastSibling", new object[0]);
            }

            return clone;
        }

        private static object GetGaugeComponent(object gameObject)
        {
            if (gameObject == null)
            {
                return null;
            }

            var method = gameObject.GetType().GetMethod("GetComponent", Flags, null, new[] { typeof(string) }, null);
            return method == null ? null : method.Invoke(gameObject, new object[] { "Common.CommonUI.CommonGauge.GaugeFillView" });
        }

        private static MethodInfo GetSetMethod(object gauge)
        {
            return gauge == null ? null : gauge.GetType().GetMethod("Set", Flags, null, new[] { typeof(float) }, null);
        }

        private static void SetGauge(int index, float value)
        {
            var gauge = gauges[index];
            if (gauge == null)
            {
                return;
            }

            var method = setMethods[index];
            if (method != null)
            {
                method.Invoke(gauge, new object[] { value });
            }
        }

        private static void CaptureBasePosition(object gauge)
        {
            var transform = IndependentOrgasmSystem.GetValue(gauge, "transform");
            var anchored = IndependentOrgasmSystem.GetValue(transform, "anchoredPosition");
            if (anchored == null)
            {
                return;
            }

            baseX = ReadFloat(anchored, "x");
            baseY = ReadFloat(anchored, "y");
            hasBasePosition = true;
        }

        private static void Layout()
        {
            if (!hasBasePosition)
            {
                return;
            }

            for (var i = 0; i < 4; i++)
            {
                var gameObject = gaugeObjects[i];
                if (gameObject == null)
                {
                    continue;
                }

                var transform = IndependentOrgasmSystem.GetValue(gameObject, "transform");
                SetVector2(transform, "anchoredPosition", baseX + Settings.PartGaugeHorizontalSpacing.Value * i, baseY + Settings.PartGaugeVerticalSpacing.Value * i);
                SetVector3(transform, "localPosition", Settings.PartGaugeHorizontalSpacing.Value * i, Settings.PartGaugeVerticalSpacing.Value * i, 0f);
                SetVector3(transform, "localScale", Settings.PartGaugeScaleX.Value, Settings.PartGaugeScaleY.Value, 1f);
                InvokeMethod(transform, "SetAsLastSibling", new object[0]);
            }
        }

        private static void SetVector2(object target, string propertyName, float x, float y)
        {
            var vectorType = TypeResolver.FindUnity("UnityEngine.Vector2", "UnityEngine.CoreModule");
            if (target == null || vectorType == null)
            {
                return;
            }

            var value = Activator.CreateInstance(vectorType, new object[] { x, y });
            IndependentOrgasmSystem.SetValue(target, propertyName, value);
        }

        private static void SetVector3(object target, string propertyName, float x, float y, float z)
        {
            var vectorType = TypeResolver.FindUnity("UnityEngine.Vector3", "UnityEngine.CoreModule");
            if (target == null || vectorType == null)
            {
                return;
            }

            var value = Activator.CreateInstance(vectorType, new object[] { x, y, z });
            IndependentOrgasmSystem.SetValue(target, propertyName, value);
        }

        private static float ReadFloat(object obj, string name)
        {
            var field = obj.GetType().GetField(name, Flags);
            if (field != null)
            {
                return Convert.ToSingle(field.GetValue(obj));
            }

            var property = obj.GetType().GetProperty(name, Flags);
            return property == null ? 0f : Convert.ToSingle(property.GetValue(obj, null));
        }

        private static void InvokeMethod(object obj, string name, object[] args)
        {
            if (obj == null)
            {
                return;
            }

            foreach (var method in obj.GetType().GetMethods(Flags))
            {
                if (method.Name != name || method.GetParameters().Length != args.Length)
                {
                    continue;
                }

                method.Invoke(obj, args);
                return;
            }
        }
    }

    internal static class TypeResolver
    {
        public static Type Find(string fullName)
        {
            var type = Type.GetType(fullName + ", Assembly-CSharp", false);
            if (type != null)
            {
                return type;
            }

            foreach (var assembly in AppDomain.CurrentDomain.GetAssemblies())
            {
                if (!string.Equals(assembly.GetName().Name, "Assembly-CSharp", StringComparison.Ordinal))
                {
                    continue;
                }

                return assembly.GetType(fullName, false);
            }

            return null;
        }

        public static Type FindUnity(string fullName, string assemblyName)
        {
            var type = Type.GetType(fullName + ", " + assemblyName, false);
            if (type != null)
            {
                return type;
            }

            foreach (var assembly in AppDomain.CurrentDomain.GetAssemblies())
            {
                if (!string.Equals(assembly.GetName().Name, assemblyName, StringComparison.Ordinal))
                {
                    continue;
                }

                return assembly.GetType(fullName, false);
            }

            return null;
        }
    }
}
