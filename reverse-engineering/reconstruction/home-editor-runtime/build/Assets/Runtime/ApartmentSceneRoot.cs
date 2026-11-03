using UnityEngine;

namespace ReconstructedManaka {
    // Authored scene metadata, not a runtime geometry generator. References point
    // to the saved prefab instance's native assets and original-source nodes.
    public sealed class ApartmentSceneRoot : MonoBehaviour {
        public int schemaVersion = 1;
        public string sceneKey = "Apartment";
        public string sourceSha256, geometrySha256, inputManifestSha256;
        public GameObject environmentRoot;
        public long[] sourcePathIds;
        public Transform[] sourceTransforms;
        public long[] unresolvedSourcePathIds;
        public int[] unresolvedBuiltinMeshIds;
        public string[] unresolvedBuiltinPurposes;
        public int nodeCount, meshes, colliders, textures, declaredTextures, unresolvedBuiltins;
        public Vector3 spawnPosition;
        public Quaternion spawnRotation = Quaternion.identity;
        public string collisionPolicy, visualPolicy;
    }
}
