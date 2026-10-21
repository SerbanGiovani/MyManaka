// Ghidra pseudocode; not original source or compilable C.
// ev_b9d244960e36daf9fe0118325abc7b7c29cd12e79dad89e68160fa1654394281

longlong ExposureUnnoticed2_Object3D_Player_Scripts_PlayerStateModel__get_IsPlayingAction__06000e29
                   (longlong param_1)

{
  longlong lVar1;
  uint7 uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x48);
  if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uVar2 = (uint7)((ulonglong)lVar1 >> 8);
  if (*(int *)(lVar1 + 0x18) != -1) {
    return CONCAT71(uVar2,1);
  }
  return (ulonglong)uVar2 << 8;
}

