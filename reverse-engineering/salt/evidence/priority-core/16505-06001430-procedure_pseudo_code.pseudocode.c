// Ghidra pseudocode; not original source or compilable C.
// ev_fb62db50d78ca3ff847b9c614477403f33e32b47770e199775a8ad24c97a4f8d

ulonglong ExposureUnnoticed2_Scripts_Mission_MissionCountEcstasy__IsInCondition__06001430
                    (longlong param_1)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  if (cRam0000000182eb7903 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb7903 = '\x01';
  }
  if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
      (*(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28) != 0)) &&
     (**(longlong **)(DAT_182d58230 + 0xb8) != 0)) {
    uVar4 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                      (**(longlong **)(DAT_182d58230 + 0xb8),0);
    if ((*(longlong *)(param_1 + 0x28) != 0) &&
       (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x20), lVar3 != 0)) {
      uVar1 = *(uint *)(lVar3 + 0x34);
      uVar5 = uVar4;
      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
        uVar5 = FUN_18035c820();
      }
      if (((uint)uVar4 & uVar1) != 0) {
        if (cRam0000000182eb54ac == '\0') {
          FUN_1802f2810(0x182d5d580);
          LOCK();
          UNLOCK();
          cRam0000000182eb54ac = '\x01';
        }
        lVar3 = **(longlong **)(uRam0000000182d5d580 + 0xb8);
        uVar5 = uRam0000000182d5d580;
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          uVar5 = FUN_18035c820();
        }
        if (DAT_182ec12f4 == '\0') {
          uVar5 = FUN_1802f2810(&DAT_182d53aa8);
          LOCK();
          UNLOCK();
          DAT_182ec12f4 = '\x01';
        }
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          uVar5 = FUN_18035c820();
        }
        if (DAT_182ec129b == '\0') {
          uVar5 = FUN_1802f2810(&DAT_182d53aa8);
          LOCK();
          UNLOCK();
          DAT_182ec129b = '\x01';
        }
        if (lVar3 != 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            uVar5 = FUN_18035c820();
          }
          if (*(longlong *)(lVar3 + 0x10) != 0) {
            if (cRam0000000182eb54ac == '\0') {
              FUN_1802f2810(0x182d5d580);
              LOCK();
              UNLOCK();
              cRam0000000182eb54ac = '\x01';
            }
            if ((**(longlong **)(uRam0000000182d5d580 + 0xb8) != 0) &&
               (*(longlong *)(param_1 + 0x28) != 0)) {
              iVar2 = *(int *)(*(longlong *)(param_1 + 0x28) + 0x3c);
              return (ulonglong)
                     CONCAT31((int3)((uint)iVar2 >> 8),
                              *(int *)(**(longlong **)(uRam0000000182d5d580 + 0xb8) + 0x20) == iVar2
                             );
            }
            goto code_r0x00018047a123;
          }
        }
      }
      return uVar5 & 0xffffffffffffff00;
    }
  }
code_r0x00018047a123:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

