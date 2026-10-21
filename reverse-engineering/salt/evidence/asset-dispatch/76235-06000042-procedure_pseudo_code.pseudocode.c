// Ghidra pseudocode; not original source or compilable C.
// ev_a4fff856a2e511ccd1b2961bec87e3bc697e28df89f56862767aabd58ecbe0e3

undefined8 IKA9nt_Encrypter_BridgeAssetBundleRequest__get_asset__06000042(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  if (*(longlong *)(param_1 + 0x10) == 0) {
    return 0;
  }
  lVar1 = **(longlong **)(param_1 + 0x10);
                    /* WARNING: Could not recover jumptable at 0x000181433f6f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(lVar1 + 0x178))
                    (*(longlong **)(param_1 + 0x10),*(undefined8 *)(lVar1 + 0x180));
  return uVar2;
}

