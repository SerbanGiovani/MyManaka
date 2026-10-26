// Ghidra pseudocode; not original source or compilable C.
// ev_4c6fa25c6423ebdedddca3e11c22c5cbf9fa332c10a18fd5561060e43159323b

bool ExposureUnnoticed2_Scripts_Mission_MissionToiletOpenNaked__IsInCondition__0600148e(void)

{
  ulonglong uVar1;
  longlong lVar2;
  
  if (cRam0000000182eb793a == '\0') {
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
    cRam0000000182eb793a = '\x01';
  }
  if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
      (*(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28) == 0)) ||
     (**(longlong **)(DAT_182d58230 + 0xb8) == 0)) goto code_r0x000180480e7e;
  uVar1 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                    (**(longlong **)(DAT_182d58230 + 0xb8),0);
  if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if ((uVar1 & 0x20) != 0) {
    if (DAT_182eb5497 == '\0') {
      FUN_1802f2810(&DAT_182d5a8f8);
      LOCK();
      UNLOCK();
      DAT_182eb5497 = '\x01';
    }
    lVar2 = **(longlong **)(DAT_182d5a8f8 + 0xb8);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182ec12f4 == '\0') {
      FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      DAT_182ec12f4 = '\x01';
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
    if (lVar2 != 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(longlong *)(lVar2 + 0x10) != 0) {
        if (DAT_182eb5497 == '\0') {
          FUN_1802f2810(&DAT_182d5a8f8);
          LOCK();
          UNLOCK();
          DAT_182eb5497 = '\x01';
        }
        if (**(longlong **)(DAT_182d5a8f8 + 0xb8) == 0) {
code_r0x000180480e7e:
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        if (*(char *)(**(longlong **)(DAT_182d5a8f8 + 0xb8) + 0xb0) != '\0') {
          lVar2 = FUN_180477da0();
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (DAT_182ec12f4 == '\0') {
            FUN_1802f2810(&DAT_182d53aa8);
            LOCK();
            UNLOCK();
            DAT_182ec12f4 = '\x01';
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
          if (lVar2 != 0) {
            if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            if (*(longlong *)(lVar2 + 0x10) != 0) {
              lVar2 = FUN_180477da0();
              if (lVar2 != 0) {
                return *(char *)(lVar2 + 0x28) == '\0';
              }
              goto code_r0x000180480e7e;
            }
          }
        }
      }
    }
  }
  return false;
}

