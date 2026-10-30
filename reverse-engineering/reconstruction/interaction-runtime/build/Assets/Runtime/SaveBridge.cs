using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using UnityEngine;

namespace ReconstructedManaka
{
    [Serializable]
    public sealed class InventoryEntry
    {
        public int id;
        public int count;
    }

    // Retained original data. Applying original appearance is outside this minimum loop.
    [Serializable]
    public sealed class SelectedCustomization
    {
        public int height;
        public int hair;
        public bool skinFree;
        public int skinPreset;
        public int skinR;
        public int skinG;
        public int skinB;
    }

    [Serializable]
    public sealed class SaveState
    {
        public int schemaVersion = 1;
        public string fileKind = "ReconstructedManakaSave";
        public string sceneKey = "Apartment";
        public Vector3 position;
        public Quaternion rotation = Quaternion.identity;
        public float bodyPaintRemaining;
        public bool bodyPaintReusable;
        public InventoryEntry[] inventory;
        public SelectedCustomization customization;
        public string sourceSaveSha256;
        public string savedProcessGuid;
        public int revision;
        public string savedAtUtc;
    }

    // Original .sd files are never opened here. All writes use this separate JSON profile.
    public sealed class SaveStore
    {
        private const string SaveKind = "ReconstructedManakaSave";
        private const string SeedKind = "ReconstructedManakaSeed";
        public const string FloatEqualityPolicy = "Normalize only IEEE-754 negative zero to positive zero before JSON serialization; every nonzero float bit and every canonical zero bit must survive exactly. Raw negative-zero sign bits are not preserved.";
        private readonly string root;
        public string FilePath { get; private set; }
        public bool Exists { get { return File.Exists(FilePath); } }

        public SaveStore(string profileRoot)
        {
            if (string.IsNullOrWhiteSpace(profileRoot))
                throw new ArgumentException("An independent profile directory is required.", nameof(profileRoot));
            root = Path.GetFullPath(profileRoot);
            FilePath = Path.Combine(root, "save.v1.json");
        }

        public bool TryRead(out SaveState state, out string error)
        {
            return TryReadFile(FilePath, false, out state, out error);
        }

        public bool TryImportSeed(string seedPath, out SaveState state, out string error)
        {
            return TryReadFile(seedPath, true, out state, out error);
        }

        private static bool TryReadFile(string path, bool seed, out SaveState state, out string error)
        {
            state = null;
            error = null;
            try
            {
                if (string.IsNullOrWhiteSpace(path) || !File.Exists(path))
                {
                    error = "Save file was not found: " + path;
                    return false;
                }
                state = Decode(File.ReadAllText(path, Encoding.UTF8), seed);
                return true;
            }
            catch (Exception ex)
            {
                state = null;
                error = ex.GetType().Name + ": " + ex.Message;
                return false;
            }
        }

        private static SaveState Decode(string json, bool seed)
        {
            if (string.IsNullOrWhiteSpace(json) || !json.TrimStart().StartsWith("{", StringComparison.Ordinal))
                throw new InvalidDataException("A versioned JSON object is required.");
            // Explicit sentinels detect omitted required fields even if JsonUtility preserves defaults.
            var value = new SaveState
            {
                schemaVersion = 0,
                fileKind = null,
                sceneKey = null,
                position = new Vector3(float.NaN, float.NaN, float.NaN),
                rotation = new Quaternion(float.NaN, float.NaN, float.NaN, float.NaN),
                bodyPaintRemaining = float.NaN,
                sourceSaveSha256 = null,
                inventory = null,
                customization = null,
                revision = -1
            };
            JsonUtility.FromJsonOverwrite(json, value);
            Validate(value, seed);
            return value;
        }

        private static bool Finite(float value)
        {
            return !float.IsNaN(value) && !float.IsInfinity(value);
        }

        public static int FloatBits(float value) { return BitConverter.ToInt32(BitConverter.GetBytes(value), 0); }

        public static Dictionary<string, int> CaptureFloatBits(SaveState state)
        {
            if (state == null) throw new ArgumentNullException(nameof(state));
            return new Dictionary<string, int> {
                { "position.x", FloatBits(state.position.x) }, { "position.y", FloatBits(state.position.y) }, { "position.z", FloatBits(state.position.z) },
                { "rotation.x", FloatBits(state.rotation.x) }, { "rotation.y", FloatBits(state.rotation.y) }, { "rotation.z", FloatBits(state.rotation.z) }, { "rotation.w", FloatBits(state.rotation.w) },
                { "bodyPaintRemaining", FloatBits(state.bodyPaintRemaining) }
            };
        }

        // JsonUtility writes -0 as 0.0. Canonicalize this one numerical equivalence
        // deliberately; do not normalize quaternions or round any nonzero component.
        public static int CanonicalizeSignedZero(SaveState state)
        {
            if (state == null) throw new ArgumentNullException(nameof(state));
            int changed = 0;
            var p = state.position; var q = state.rotation;
            state.position = new Vector3(CanonicalZero(p.x, ref changed), CanonicalZero(p.y, ref changed), CanonicalZero(p.z, ref changed));
            state.rotation = new Quaternion(CanonicalZero(q.x, ref changed), CanonicalZero(q.y, ref changed), CanonicalZero(q.z, ref changed), CanonicalZero(q.w, ref changed));
            state.bodyPaintRemaining = CanonicalZero(state.bodyPaintRemaining, ref changed);
            return changed;
        }

        static float CanonicalZero(float value, ref int changed)
        {
            if (value == 0f && FloatBits(value) != 0) { changed++; return 0f; }
            return value;
        }

        public static bool SameFloatBits(SaveState expected, SaveState actual, out string mismatches)
        {
            var before = CaptureFloatBits(expected); var after = CaptureFloatBits(actual); var differences = new List<string>();
            foreach (var component in before) if (after[component.Key] != component.Value)
                differences.Add(component.Key + ": expected 0x" + component.Value.ToString("x8") + ", actual 0x" + after[component.Key].ToString("x8"));
            mismatches = string.Join("; ", differences.ToArray());
            return differences.Count == 0;
        }

        private static void Validate(SaveState state, bool seed)
        {
            if (state == null || state.schemaVersion != 1)
                throw new InvalidDataException("Unsupported save schema version.");
            if (state.fileKind != (seed ? SeedKind : SaveKind))
                throw new InvalidDataException("Save/seed kind does not match this operation.");
            if (state.sceneKey != "Apartment")
                throw new InvalidDataException("Version 1 supports the Apartment scene only.");
            var p = state.position;
            var q = state.rotation;
            if (!Finite(p.x) || !Finite(p.y) || !Finite(p.z) ||
                !Finite(q.x) || !Finite(q.y) || !Finite(q.z) || !Finite(q.w))
                throw new InvalidDataException("A finite Vector3 position and Quaternion rotation are required.");
            float norm = q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w;
            if (Math.Abs(norm - 1f) > 0.01f)
                throw new InvalidDataException("Saved rotation must be a unit Quaternion.");
            if (!Finite(state.bodyPaintRemaining) || state.bodyPaintRemaining < 0)
                throw new InvalidDataException("Body-paint remaining value is invalid.");
            if (state.sourceSaveSha256 == null || state.sourceSaveSha256.Length != 64)
                throw new InvalidDataException("The original source SHA256 is required.");
            foreach (char c in state.sourceSaveSha256)
                if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')))
                    throw new InvalidDataException("Original source SHA256 contains non-hexadecimal characters.");
            if (state.inventory == null || state.customization == null)
                throw new InvalidDataException("The imported inventory and selected customization must be retained.");
            var ids = new HashSet<int>();
            foreach (var item in state.inventory)
                if (item == null || item.id < 0 || item.count < 0 || !ids.Add(item.id))
                    throw new InvalidDataException("Invalid or duplicate imported inventory entry.");
            if (seed)
            {
                if (state.revision != 0)
                    throw new InvalidDataException("An offline import seed must have revision zero.");
            }
            else if (state.revision < 1 || !Guid.TryParse(state.savedProcessGuid, out _))
                throw new InvalidDataException("A stored save needs a revision and writer process identity.");
        }

        public void Write(SaveState state)
        {
            if (state == null) throw new ArgumentNullException(nameof(state));
            CanonicalizeSignedZero(state);
            int previous = 0;
            if (Exists)
            {
                if (!TryRead(out var old, out var error))
                    throw new InvalidDataException("Existing independent save was retained: " + error);
                previous = old.revision;
            }
            state.schemaVersion = 1;
            state.fileKind = SaveKind;
            state.revision = checked(Math.Max(previous, state.revision) + 1);
            state.savedAtUtc = DateTime.UtcNow.ToString("O");
            Validate(state, false);
            string json = JsonUtility.ToJson(state, true);
            SaveState roundtrip = Decode(json, false);
            if (!SameFloatBits(state, roundtrip, out string mismatches))
                throw new InvalidDataException("Save serialization changed canonical float bits before commit: " + mismatches);
            // Both validation and exact canonical float comparison happen before any
            // temporary write or replacement of the prior independent JSON save.
            Directory.CreateDirectory(root);
            string temporary = FilePath + ".tmp." + Guid.NewGuid().ToString("N");
            try
            {
                using (var stream = new FileStream(temporary, FileMode.CreateNew, FileAccess.Write, FileShare.None))
                {
                    byte[] bytes = new UTF8Encoding(false).GetBytes(json);
                    stream.Write(bytes, 0, bytes.Length);
                    stream.Flush(true);
                }
                if (Exists) File.Replace(temporary, FilePath, FilePath + ".bak");
                else File.Move(temporary, FilePath);
            }
            finally
            {
                if (File.Exists(temporary)) File.Delete(temporary);
            }
        }
    }
}
