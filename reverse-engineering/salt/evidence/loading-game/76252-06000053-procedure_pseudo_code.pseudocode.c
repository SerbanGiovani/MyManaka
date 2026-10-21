// Ghidra pseudocode; not original source or compilable C.
// ev_1eb1d537a82525965209f861c6d7b58361a5ad0b286c4c0d6435bb29081e68d4

void IKA9nt_Encrypter_BridgeAssetBundleRequest__LoadComplete__06000053
               (longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (lVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000181434a95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(lVar1 + 0x18))(*(undefined8 *)(lVar1 + 0x40),param_2,*(undefined8 *)(lVar1 + 0x28))
    ;
    return;
  }
  return;
}

