using System;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Runtime.ExceptionServices;
using System.Text;
using System.Threading;
using BepInEx;
using BepInEx.Configuration;
using BepInEx.Logging;
using BepInEx.Unity.IL2CPP;

[assembly: System.Runtime.Versioning.TargetFramework(".NETCoreApp,Version=v6.0", FrameworkDisplayName = ".NET 6.0")]

namespace LifecycleLogHook
{
    [BepInPlugin(PluginGuid, PluginName, PluginVersion)]
    public sealed class Plugin : BasePlugin
    {
        public const string PluginGuid = "local.lifecycle_log_hook";
        public const string PluginName = "Lifecycle Log Hook";
        public const string PluginVersion = "1.0.0";

        private static readonly object Sync = new object();
        private static ManualLogSource logger;
        private static string logPath;
        private static long lastFirstChanceTicks;
        private static ConfigEntry<bool> mirrorToBepInEx;

        private ConfigEntry<bool> captureFirstChanceExceptions;
        private ConfigEntry<int> heartbeatSeconds;
        private Timer heartbeatTimer;

        public override void Load()
        {
            logger = Log;
            BindConfig();
            InitializeLog();
            SubscribeHooks();
            StartHeartbeat();
            Write("Plugin", "Loaded version=" + PluginVersion + " pid=" + Process.GetCurrentProcess().Id);
            Log.LogInfo("Lifecycle Log Hook loaded. File: " + logPath);
        }

        public override bool Unload()
        {
            Write("Plugin", "Unload requested");
            heartbeatTimer?.Dispose();
            UnsubscribeHooks();
            return true;
        }

        private void BindConfig()
        {
            mirrorToBepInEx = Config.Bind("Logging", "MirrorToBepInEx", true, "Also write lifecycle events to BepInEx LogOutput.log.");
            captureFirstChanceExceptions = Config.Bind("Logging", "CaptureFirstChanceExceptions", false, "Capture first-chance managed exceptions. Leave disabled unless hunting a startup-only failure.");
            heartbeatSeconds = Config.Bind("Logging", "HeartbeatSeconds", 10, "Interval for process heartbeat lines. Set 0 to disable.");
        }

        private void InitializeLog()
        {
            logPath = Path.Combine(Paths.BepInExRootPath, "LifecycleLogHook.log");
            Directory.CreateDirectory(Path.GetDirectoryName(logPath));
            WriteRaw("");
            WriteRaw("==== Lifecycle Log Hook session " + Timestamp() + " ====");
            WriteRaw("root=" + Paths.GameRootPath);
            WriteRaw("bepinex=" + Paths.BepInExRootPath);
            WriteRaw("commandLine=" + Environment.CommandLine);
            WriteRaw("os=" + Environment.OSVersion + " clr=" + Environment.Version + " x64=" + Environment.Is64BitProcess);
        }

        private void SubscribeHooks()
        {
            AppDomain.CurrentDomain.UnhandledException += OnUnhandledException;
            AppDomain.CurrentDomain.ProcessExit += OnProcessExit;
            AppDomain.CurrentDomain.FirstChanceException += OnFirstChanceException;
        }

        private void UnsubscribeHooks()
        {
            AppDomain.CurrentDomain.UnhandledException -= OnUnhandledException;
            AppDomain.CurrentDomain.ProcessExit -= OnProcessExit;
            AppDomain.CurrentDomain.FirstChanceException -= OnFirstChanceException;
        }

        private void StartHeartbeat()
        {
            var seconds = Math.Max(0, heartbeatSeconds.Value);
            if (seconds == 0)
            {
                return;
            }

            heartbeatTimer = new Timer(_ => WriteHeartbeat(), null, seconds * 1000, seconds * 1000);
        }

        private static void WriteHeartbeat()
        {
            try
            {
                using (var process = Process.GetCurrentProcess())
                {
                    Write("Heartbeat", "workingSetMB=" + (process.WorkingSet64 / 1024 / 1024) +
                        " privateMB=" + (process.PrivateMemorySize64 / 1024 / 1024) +
                        " threads=" + process.Threads.Count +
                        " handles=" + process.HandleCount);
                }
            }
            catch (Exception ex)
            {
                Write("Heartbeat", "failed=" + OneLine(ex));
            }
        }

        private static void OnProcessExit(object sender, EventArgs e)
        {
            Write("Process", "exit");
        }

        private static void OnUnhandledException(object sender, UnhandledExceptionEventArgs e)
        {
            Write("UnhandledException", "terminating=" + e.IsTerminating + " " + OneLine(e.ExceptionObject));
        }

        private void OnFirstChanceException(object sender, FirstChanceExceptionEventArgs e)
        {
            if (!captureFirstChanceExceptions.Value)
            {
                return;
            }

            var now = DateTime.UtcNow.Ticks;
            if (now - Interlocked.Read(ref lastFirstChanceTicks) < TimeSpan.TicksPerSecond)
            {
                return;
            }

            Interlocked.Exchange(ref lastFirstChanceTicks, now);
            Write("FirstChance", OneLine(e.Exception));
        }

        private static void Write(string category, string detail)
        {
            var line = "[" + Timestamp() + "] [" + category + "] " + detail;
            WriteRaw(line);
            if (mirrorToBepInEx == null || mirrorToBepInEx.Value)
            {
                logger?.LogInfo(line);
            }
        }

        private static void WriteRaw(string line)
        {
            lock (Sync)
            {
                File.AppendAllText(logPath, line + Environment.NewLine, Encoding.UTF8);
            }
        }

        private static string Timestamp()
        {
            return DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss.fff", CultureInfo.InvariantCulture);
        }

        private static string OneLine(object value)
        {
            return Trim(Convert.ToString(value, CultureInfo.InvariantCulture), 1400);
        }

        private static string Trim(string text, int max)
        {
            if (string.IsNullOrEmpty(text))
            {
                return text;
            }

            text = text.Replace("\r", "\\r").Replace("\n", "\\n");
            return text.Length <= max ? text : text.Substring(0, max) + "...";
        }
    }
}
