// Ghidra pseudocode; not original source or compilable C.
// ev_0eb07cb8034f8d8c36b7f95bb6563a3254f109c3391be3712c6ed79059fdd18c

bool ExposureUnnoticed2_Scripts_Mission_MissionHandcuffsMapExpose__IsInCondition__06001457(void)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  
  if (cRam0000000182eb7919 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
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
    cRam0000000182eb7919 = '\x01';
  }
  if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
      (lVar4 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar4 != 0)) &&
     (lVar4 = *(longlong *)(lVar4 + 0x30), **(longlong **)(DAT_182d58230 + 0xb8) != 0)) {
    iVar3 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                      ();
    if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (iVar3 != 1) {
      lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar1 == 0) goto code_r0x00018047c1c9;
      if (*(char *)(lVar1 + 0x1a9) != '\0') {
        if (((lVar4 == 0) || (lVar4 = *(longlong *)(lVar4 + 0x40), lVar4 == 0)) ||
           (lVar4 = *(longlong *)(lVar4 + 0xf0), lVar4 == 0)) goto code_r0x00018047c1c9;
        cVar2 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerHandcuffsController__IsConditionMission__06000dc8
                          (lVar4,0);
        if (cVar2 != '\0') {
          lVar4 = FUN_180498d30();
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
              goto code_r0x00018047c1c9;
            }
          }
          return true;
        }
      }
    }
    return false;
  }
code_r0x00018047c1c9:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

