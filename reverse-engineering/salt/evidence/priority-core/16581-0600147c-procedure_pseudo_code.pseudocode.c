// Ghidra pseudocode; not original source or compilable C.
// ev_78caaa3cd30e18bf7b1dc68a39fe31c188c50c40ca4e35f28c46ab69798aa863

bool ExposureUnnoticed2_Scripts_Mission_MissionPoseExpose__IsInCondition__0600147c(void)

{
  int iVar1;
  longlong lVar2;
  
  if (cRam0000000182eb7931 == '\0') {
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
    cRam0000000182eb7931 = '\x01';
  }
  if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
      (*(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28) != 0)) &&
     (**(longlong **)(DAT_182d58230 + 0xb8) != 0)) {
    iVar1 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                      ();
    if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (iVar1 != 1) {
      if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
          (lVar2 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar2 == 0)) ||
         ((lVar2 = *(longlong *)(lVar2 + 0x60), lVar2 == 0 ||
          (lVar2 = *(longlong *)(lVar2 + 0x48), lVar2 == 0)))) goto code_r0x00018047fa3f;
      iVar1 = *(int *)(lVar2 + 0x18);
      if ((49999 < iVar1) && (iVar1 < 0xea61)) {
        if (cRam0000000182eb54aa == '\0') {
          FUN_1802f2810(0x182d5d568);
          LOCK();
          UNLOCK();
          cRam0000000182eb54aa = '\x01';
        }
        lVar2 = **(longlong **)(lRam0000000182d5d568 + 0xb8);
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
        if (lVar2 != 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (*(longlong *)(lVar2 + 0x10) != 0) {
            lVar2 = FUN_180498d30();
            if (lVar2 != 0) {
              return *(char *)(lVar2 + 0x20) != '\0';
            }
            goto code_r0x00018047fa3f;
          }
        }
        return true;
      }
    }
    return false;
  }
code_r0x00018047fa3f:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

