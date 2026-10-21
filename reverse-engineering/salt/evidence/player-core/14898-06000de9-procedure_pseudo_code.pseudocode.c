// Ghidra pseudocode; not original source or compilable C.
// ev_3ee0ebfa9f600f01d37dd25f0b5fc727f227dcec8ff49db2f6a7041da9a2cfb8

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerLocomotion__SetMoveSpeedInverse__06000de9
               (longlong param_1,byte param_2)

{
  longlong lVar1;
  
  if (*(byte *)(param_1 + 0x80) == param_2) {
    return;
  }
  lVar1 = *(longlong *)(param_1 + 0x78);
  *(byte *)(param_1 + 0x80) = param_2;
  if (lVar1 != 0) {
    if ((*(longlong *)(lVar1 + 0x170) != 0) && (*(longlong *)(lVar1 + 0x48) != 0)) {
      *(float *)(*(longlong *)(lVar1 + 0x48) + 0x24) =
           (float)(int)((param_2 ^ 1) * 2 + -1) * *(float *)(*(longlong *)(lVar1 + 0x170) + 0xb0);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

