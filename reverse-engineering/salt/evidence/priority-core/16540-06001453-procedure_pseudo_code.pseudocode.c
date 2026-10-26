// Ghidra pseudocode; not original source or compilable C.
// ev_b7524095d7724225069dcba6cdd49e3db756e112bcab2d1231ae9f81f5b7d2d5

ulonglong ExposureUnnoticed2_Scripts_Mission_MissionExposeIntercom__IsInCondition__06001453
                    (longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  if (cRam0000000182eb7917 == '\0') {
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
    cRam0000000182eb7917 = '\x01';
  }
  if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
      (*(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28) != 0)) &&
     (**(longlong **)(DAT_182d58230 + 0xb8) != 0)) {
    uVar3 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                      (**(longlong **)(DAT_182d58230 + 0xb8),0);
    if ((*(longlong *)(param_1 + 0x28) != 0) &&
       (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x20), lVar2 != 0)) {
      uVar1 = *(uint *)(lVar2 + 0x34);
      uVar4 = uVar3;
      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
        uVar4 = FUN_18035c820();
      }
      if (((uint)uVar3 & uVar1) != 0) {
        if (cRam0000000182eb549c == '\0') {
          FUN_1802f2810(0x182d5ae70);
          LOCK();
          UNLOCK();
          cRam0000000182eb549c = '\x01';
        }
        lVar2 = **(longlong **)(uRam0000000182d5ae70 + 0xb8);
        uVar4 = uRam0000000182d5ae70;
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          uVar4 = FUN_18035c820();
        }
        if (DAT_182ec12f4 == '\0') {
          uVar4 = FUN_1802f2810(&DAT_182d53aa8);
          LOCK();
          UNLOCK();
          DAT_182ec12f4 = '\x01';
        }
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          uVar4 = FUN_18035c820();
        }
        if (DAT_182ec129b == '\0') {
          uVar4 = FUN_1802f2810(&DAT_182d53aa8);
          LOCK();
          UNLOCK();
          DAT_182ec129b = '\x01';
        }
        if (lVar2 != 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            uVar4 = FUN_18035c820();
          }
          if (*(longlong *)(lVar2 + 0x10) != 0) {
            if (cRam0000000182eb549c == '\0') {
              FUN_1802f2810(0x182d5ae70);
              LOCK();
              UNLOCK();
              cRam0000000182eb549c = '\x01';
            }
            if (**(longlong **)(uRam0000000182d5ae70 + 0xb8) != 0) {
              return (ulonglong)*(byte *)(**(longlong **)(uRam0000000182d5ae70 + 0xb8) + 0x28);
            }
            goto code_r0x00018047be46;
          }
        }
      }
      return uVar4 & 0xffffffffffffff00;
    }
  }
code_r0x00018047be46:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

