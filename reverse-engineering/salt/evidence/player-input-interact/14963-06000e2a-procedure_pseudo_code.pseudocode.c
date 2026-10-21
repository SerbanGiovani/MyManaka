// Ghidra pseudocode; not original source or compilable C.
// ev_083e3d77709dadfa8c51f14503dc56b8e21d7ef854f9e6503071687e59aae08a

longlong ExposureUnnoticed2_Object3D_Player_Scripts_PlayerStateModel__get_IsPlayingSomeNonMoveAction__06000e2a
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
  if (*(int *)(lVar1 + 0x18) == -1) {
    return (ulonglong)uVar2 << 8;
  }
  return CONCAT71(uVar2,*(char *)(lVar1 + 0x1c) == '\0');
}

