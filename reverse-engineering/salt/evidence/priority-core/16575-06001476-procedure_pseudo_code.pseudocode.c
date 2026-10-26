// Ghidra pseudocode; not original source or compilable C.
// ev_62ad6c5070b03ebc5756d98d106f76f2927ab71c900b8aede74935593070ecb3

bool ExposureUnnoticed2_Scripts_Mission_MissionMoveVerticalFromClothes__IsInCondition__06001476
               (longlong param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  
  if (cRam0000000182eb792e == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb792e = '\x01';
  }
  if ((((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
       (lVar3 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar3 != 0)) &&
      (**(longlong **)(DAT_182d58230 + 0xb8) != 0)) &&
     ((lVar1 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar1 != 0 &&
      (lVar1 = *(longlong *)(lVar1 + 0x60), lVar1 != 0)))) {
    if (*(int *)(lVar1 + 0x168) == 0) {
      lVar3 = *(longlong *)(lVar3 + 0x30);
      if (((lVar3 == 0) || (lVar3 = *(longlong *)(lVar3 + 0x40), lVar3 == 0)) ||
         ((lVar3 = *(longlong *)(lVar3 + 0x60), lVar3 == 0 ||
          (lVar3 = *(longlong *)(lVar3 + 0x10), lVar3 == 0)))) goto code_r0x00018047f37b;
      if (*(int *)(lVar3 + 0x30) != -1) {
        *(undefined1 *)(param_1 + 0x3c) = 0;
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x3c) = 1;
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
    if (*(char *)(param_1 + 0x3c) != '\0') {
      return false;
    }
    if (DAT_182eb54a2 == '\0') {
      FUN_1802f2810(&DAT_182d5bcb8);
      LOCK();
      UNLOCK();
      DAT_182eb54a2 = '\x01';
    }
    if (**(longlong **)(DAT_182d5bcb8 + 0xb8) != 0) {
      lVar3 = ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__GetDropClothesInSameArea__0600150d
                        (**(longlong **)(DAT_182d5bcb8 + 0xb8),0);
      if (**(longlong **)(DAT_182d58230 + 0xb8) != 0) {
        iVar2 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                          (**(longlong **)(DAT_182d58230 + 0xb8),0);
        if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (iVar2 == 1) {
          return false;
        }
        return lVar3 != 0;
      }
    }
  }
code_r0x00018047f37b:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

