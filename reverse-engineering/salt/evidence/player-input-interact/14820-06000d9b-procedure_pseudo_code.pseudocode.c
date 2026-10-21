// Ghidra pseudocode; not original source or compilable C.
// ev_c8c0d027988e704d75db1e690837c29e7eebabba188354ac039ea4569afed370

longlong ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__IsPlayingAction__06000d9b
                   (longlong param_1)

{
  longlong lVar1;
  uint7 uVar2;
  
  if (((*(longlong *)(param_1 + 0x10) != 0) &&
      (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60), lVar1 != 0)) &&
     (lVar1 = *(longlong *)(lVar1 + 0x48), lVar1 != 0)) {
    uVar2 = (uint7)((ulonglong)lVar1 >> 8);
    if (*(int *)(lVar1 + 0x18) != -1) {
      return CONCAT71(uVar2,1);
    }
    return (ulonglong)uVar2 << 8;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

