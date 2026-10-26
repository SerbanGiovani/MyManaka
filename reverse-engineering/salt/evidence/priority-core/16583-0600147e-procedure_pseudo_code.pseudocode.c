// Ghidra pseudocode; not original source or compilable C.
// ev_4a7df09548e080bb23aed01ce346fb84a0641388dfe6be39af35d8151c13d669

bool ExposureUnnoticed2_Scripts_Mission_MissionPutClothesAndInArea__IsInCondition__0600147e
               (longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  char cVar4;
  
  if (cRam0000000182eb7932 == '\0') {
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
    cRam0000000182eb7932 = '\x01';
  }
  if ((((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
       (lVar2 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar2 != 0)) &&
      (**(longlong **)(DAT_182d58230 + 0xb8) != 0)) &&
     ((lVar1 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar1 != 0 &&
      (lVar1 = *(longlong *)(lVar1 + 0x60), lVar1 != 0)))) {
    cVar4 = '\0';
    if (*(int *)(lVar1 + 0x168) == 0) {
      lVar2 = *(longlong *)(lVar2 + 0x30);
      if (((lVar2 == 0) || (lVar2 = *(longlong *)(lVar2 + 0x40), lVar2 == 0)) ||
         ((lVar2 = *(longlong *)(lVar2 + 0x60), lVar2 == 0 ||
          (lVar2 = *(longlong *)(lVar2 + 0x10), lVar2 == 0)))) goto code_r0x00018047fdd2;
      if (*(int *)(lVar2 + 0x30) != -1) {
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
      lVar2 = ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__GetDropClothesInSameArea__0600150d
                        (**(longlong **)(DAT_182d5bcb8 + 0xb8),0);
      if (lVar2 == 0) {
        cVar4 = '\x01';
      }
      else {
        if (cRam0000000182eb54a3 == '\0') {
          FUN_1802f2810(0x182d5c950);
          LOCK();
          UNLOCK();
          cRam0000000182eb54a3 = '\x01';
        }
        lVar2 = **(longlong **)(lRam0000000182d5c950 + 0xb8);
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
            if (lVar2 == 0) goto code_r0x00018047fdd2;
            cVar4 = *(char *)(lVar2 + 0x28);
          }
        }
      }
      if (**(longlong **)(DAT_182d58230 + 0xb8) != 0) {
        uVar3 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                          (**(longlong **)(DAT_182d58230 + 0xb8),0);
        if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (cVar4 == '\0' || (uVar3 & 0x20) == 0) {
          return false;
        }
        if (cRam0000000182eb54ac == '\0') {
          FUN_1802f2810(0x182d5d580);
          LOCK();
          UNLOCK();
          cRam0000000182eb54ac = '\x01';
        }
        lVar2 = **(longlong **)(lRam0000000182d5d580 + 0xb8);
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
        if (lVar2 == 0) {
          return false;
        }
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (*(longlong *)(lVar2 + 0x10) == 0) {
          return false;
        }
        lVar2 = FUN_180498cb0();
        if ((lVar2 != 0) && (*(longlong *)(param_1 + 0x28) != 0)) {
          return *(int *)(lVar2 + 0x20) == *(int *)(*(longlong *)(param_1 + 0x28) + 0x3c);
        }
      }
    }
  }
code_r0x00018047fdd2:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

