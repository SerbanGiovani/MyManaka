// Ghidra pseudocode; not original source or compilable C.
// ev_61e2f55f828a03301b0021b4994f8ccb072c079a389bef5ed4bad5ba3cf12586

float ExposureUnnoticed2_Scripts_Mission_MissionStopElevatorNaked__GetAddSatisfy__0600148b
                (longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  
  if (cRam0000000182eb7939 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb7939 = '\x01';
  }
  fVar4 = 0.0;
  if (*(int *)(param_1 + 0x48) == -1) goto code_r0x000180480b5e;
  lVar1 = *(longlong *)(param_1 + 0x58);
  if (lVar1 == 0) goto code_r0x000180480b73;
  if (*(uint *)(lVar1 + 0x18) <= *(uint *)(param_1 + 0x48)) {
code_r0x000180480b79:
                    /* WARNING: Subroutine does not return */
    FUN_18031dae0();
  }
  if (*(char *)((longlong)(int)*(uint *)(param_1 + 0x48) + 0x20 + lVar1) == '\0') {
    if (**(longlong **)(DAT_182d58230 + 0xb8) != 0) {
      uVar2 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                        (**(longlong **)(DAT_182d58230 + 0xb8),0);
      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if ((uVar2 & 0x20) == 0) goto code_r0x000180480b5e;
      *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
      lVar1 = *(longlong *)(param_1 + 0x58);
      if (lVar1 != 0) {
        if (*(uint *)(lVar1 + 0x18) <= *(uint *)(param_1 + 0x48)) goto code_r0x000180480b79;
        *(undefined1 *)((longlong)(int)*(uint *)(param_1 + 0x48) + 0x20 + lVar1) = 1;
        if (*(longlong *)(param_1 + 0x28) != 0) {
          fVar4 = 1.0 / *(float *)(*(longlong *)(param_1 + 0x28) + 0x38);
          fVar3 = (float)FUN_181dc1970(0);
          *(float *)(param_1 + 0x4c) = fVar3 + 4.0;
          goto code_r0x000180480b5e;
        }
      }
    }
code_r0x000180480b73:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
code_r0x000180480b5e:
  *(undefined4 *)(param_1 + 0x48) = 0xffffffff;
  return fVar4;
}

