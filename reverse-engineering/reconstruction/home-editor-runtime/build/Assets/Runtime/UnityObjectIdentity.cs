namespace ReconstructedManaka {
    // Historical evidence schema names such as instanceId/clipInstanceId are
    // retained for joins. On Unity6 their values are the complete unsigned
    // 64-bit EntityId, never GetHashCode(), an int cast or truncated bits.
    // Original serialized path IDs and Animator state hashes are unchanged.
    public static class UnityObjectIdentity {
        public static ulong EvidenceId(this UnityEngine.Object value) {
            return UnityEngine.EntityId.ToULong(value.GetEntityId());
        }
    }
}
