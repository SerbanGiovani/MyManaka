// Ghidra pseudocode; not original source or compilable C.
// ev_0097023450f5eb109828df9bef98aa93c0c37fac530cf1b273a996c1aa3e0eaf

void UnityEngine_AssetBundle__LoadAssetAsync_Internal__06000017
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  
  pcVar1 = pcRam0000000182ebf5f8;
  if ((pcRam0000000182ebf5f8 == (code *)0x0) &&
     (pcVar1 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.AssetBundle::LoadAssetAsync_Internal(System.String,System.Type)"
                                    ), pcVar1 == (code *)0x0)) {
    uVar2 = func_0x0001802ced60(
                               "UnityEngine.AssetBundle::LoadAssetAsync_Internal(System.String,System.Type)"
                               );
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar2,0);
  }
  pcRam0000000182ebf5f8 = pcVar1;
                    /* WARNING: Could not recover jumptable at 0x000181ef2de4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0000000182ebf5f8)(param_1,param_2,param_3);
  return;
}

