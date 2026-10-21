// Ghidra pseudocode; not original source or compilable C.
// ev_412f0075e8184256a5a48d7a9b6adba517d06fe2d1a38f2970312c6da90623e9

void IKA9nt_Encrypter_BridgeAssetBundleRequest____ctor_b__32_0__06000056(longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  pcVar2 = pcRam0000000182ebf620;
  if ((pcRam0000000182ebf620 == (code *)0x0) &&
     (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.AssetBundleCreateRequest::get_assetBundle()"),
     pcVar2 == (code *)0x0)) {
    uVar3 = func_0x0001802ced60("UnityEngine.AssetBundleCreateRequest::get_assetBundle()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar3,0);
  }
  pcRam0000000182ebf620 = pcVar2;
  uVar3 = (*pcRam0000000182ebf620)(lVar1);
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (lVar1 != 0) {
    (**(code **)(lVar1 + 0x18))(*(undefined8 *)(lVar1 + 0x40),uVar3,*(undefined8 *)(lVar1 + 0x28));
  }
  return;
}

