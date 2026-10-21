// Ghidra pseudocode; not original source or compilable C.
// ev_b3008e92c6262929f5cbc834f485f12348a841c50053fedb312e46cc6035f840

void UnityEngine_AssetBundleRequest__GetResult__0600001d(undefined8 param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  
  pcVar1 = pcRam0000000182ebf630;
  if ((pcRam0000000182ebf630 == (code *)0x0) &&
     (pcVar1 = (code *)FUN_1802cf0c0("UnityEngine.AssetBundleRequest::GetResult()"),
     pcVar1 == (code *)0x0)) {
    uVar2 = func_0x0001802ced60("UnityEngine.AssetBundleRequest::GetResult()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar2,0);
  }
  pcRam0000000182ebf630 = pcVar1;
                    /* WARNING: Could not recover jumptable at 0x000181ef2fc5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0000000182ebf630)(param_1);
  return;
}

