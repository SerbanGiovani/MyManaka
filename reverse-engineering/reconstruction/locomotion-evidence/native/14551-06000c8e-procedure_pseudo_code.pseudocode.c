// Ghidra pseudocode; not original source or compilable C.
// ev_58a0fbcb40ae972f4fb6c8c2b66b6d7a085103cf123aef58a7c327d75c5412da

char ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__NearStrafeDirect__06000c8e
               (longlong param_1)

{
  bool bVar1;
  float fVar2;
  float fVar3;
  
  if ((*(longlong *)(param_1 + 0x88) == 0) || (*(longlong *)(param_1 + 0x90) == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  fVar2 = (float)func_0x00018039e2b0(*(undefined4 *)(*(longlong *)(param_1 + 0x88) + 0x10),
                                     *(undefined4 *)(*(longlong *)(param_1 + 0x90) + 0x10));
  fVar3 = ABS(fVar2 * 57.29578);
  bVar1 = 0.0 <= fVar2 * 57.29578;
  if (fVar3 <= 22.5) {
    return '\0';
  }
  if (67.5 < fVar3) {
    if (fVar3 <= 112.5) {
      return bVar1 + '\x02';
    }
    if (157.5 < fVar3) {
      return '\x01';
    }
    return bVar1 + '\x06';
  }
  return bVar1 + '\x04';
}

