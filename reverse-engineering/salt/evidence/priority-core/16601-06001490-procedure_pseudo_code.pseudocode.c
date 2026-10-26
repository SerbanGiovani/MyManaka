// Ghidra pseudocode; not original source or compilable C.
// ev_3fe4c85927f802a67d4718c9b0a75c15c30b976c17a635017818c5be84839680

bool ExposureUnnoticed2_Scripts_Mission_MissionUsingDildo__IsInCondition__06001490(longlong param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  
  if (cRam0000000182eb793b == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb793b = '\x01';
  }
  if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
      (*(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28) != 0)) &&
     (**(longlong **)(DAT_182d58230 + 0xb8) != 0)) {
    uVar3 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                      (**(longlong **)(DAT_182d58230 + 0xb8),0);
    if ((*(longlong *)(param_1 + 0x28) != 0) &&
       (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x20), lVar4 != 0)) {
      uVar1 = *(uint *)(lVar4 + 0x34);
      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if ((uVar3 & uVar1) != 0) {
        if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
            (lVar4 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar4 == 0)) ||
           ((lVar4 = *(longlong *)(lVar4 + 0x60), lVar4 == 0 ||
            (lVar4 = *(longlong *)(lVar4 + 0x48), lVar4 == 0)))) goto code_r0x0001804810e0;
        iVar2 = *(int *)(lVar4 + 0x18);
        if (((iVar2 - 0x272eU < 0x45) && (4 < iVar2 - 0x274cU)) || (iVar2 == 0x2775)) {
          if (cRam0000000182eb54aa == '\0') {
            FUN_1802f2810(0x182d5d568);
            LOCK();
            UNLOCK();
            cRam0000000182eb54aa = '\x01';
          }
          lVar4 = **(longlong **)(lRam0000000182d5d568 + 0xb8);
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (DAT_182ec12f3 == '\0') {
            FUN_1802f2810(&DAT_182d53aa8);
            LOCK();
            UNLOCK();
            DAT_182ec12f3 = '\x01';
          }
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (DAT_182ec129b == '\0') {
            FUN_1802f2810(&DAT_182d53aa8);
            LOCK();
            UNLOCK();
            DAT_182ec129b = '\x01';
          }
          if (lVar4 != 0) {
            if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            if (*(longlong *)(lVar4 + 0x10) != 0) {
              lVar4 = FUN_180498d30();
              if (lVar4 != 0) {
                return *(char *)(lVar4 + 0x20) != '\0';
              }
              goto code_r0x0001804810e0;
            }
          }
          return true;
        }
      }
      return false;
    }
  }
code_r0x0001804810e0:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

