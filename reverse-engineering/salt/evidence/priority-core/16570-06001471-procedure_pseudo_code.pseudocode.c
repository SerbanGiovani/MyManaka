// Ghidra pseudocode; not original source or compilable C.
// ev_672558d12393c8bbd7a738f8159ee8308ee06bdf4f4e196b351c021e0b66b3b0

bool ExposureUnnoticed2_Scripts_Mission_MissionMoveFromClothesInArea__IsInCondition__06001471
               (longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  bool bVar6;
  bool bVar7;
  
  if (cRam0000000182eb792b == '\0') {
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
    cRam0000000182eb792b = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar1 != 0)) {
    lVar1 = *(longlong *)(lVar1 + 0x30);
    if (DAT_182eb54a2 == '\0') {
      FUN_1802f2810(&DAT_182d5bcb8);
      LOCK();
      UNLOCK();
      DAT_182eb54a2 = '\x01';
    }
    if (**(longlong **)(DAT_182d5bcb8 + 0xb8) != 0) {
      lVar5 = ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__GetDropClothesInSameArea__0600150d
                        (**(longlong **)(DAT_182d5bcb8 + 0xb8),0);
      if (**(longlong **)(DAT_182d58230 + 0xb8) != 0) {
        iVar4 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                          (**(longlong **)(DAT_182d58230 + 0xb8),0);
        if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
          FUN_18035c820();
        }
        bVar7 = false;
        bVar6 = bVar7;
        if (iVar4 != 1) {
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
              if (cRam0000000182eb54a3 == '\0') {
                FUN_1802f2810(0x182d5c950);
                LOCK();
                UNLOCK();
                cRam0000000182eb54a3 = '\x01';
              }
              if (**(longlong **)(lRam0000000182d5c950 + 0xb8) == 0) goto code_r0x00018047eda1;
              if (*(char *)(**(longlong **)(lRam0000000182d5c950 + 0xb8) + 0x28) != '\0') {
                bVar6 = lVar5 != 0;
              }
            }
          }
        }
        if (((**(longlong **)(DAT_182d58230 + 0xb8) != 0) &&
            (lVar5 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar5 != 0)) &&
           (lVar5 = *(longlong *)(lVar5 + 0x60), lVar5 != 0)) {
          if (*(int *)(lVar5 + 0x168) == 0) {
            if (((lVar1 == 0) || (lVar1 = *(longlong *)(lVar1 + 0x40), lVar1 == 0)) ||
               ((lVar1 = *(longlong *)(lVar1 + 0x60), lVar1 == 0 ||
                (lVar1 = *(longlong *)(lVar1 + 0x10), lVar1 == 0)))) goto code_r0x00018047eda1;
            if (*(int *)(lVar1 + 0x30) != -1) {
              *(undefined1 *)((longlong)param_1 + 0x3c) = 0;
            }
          }
          else {
            *(undefined1 *)((longlong)param_1 + 0x3c) = 1;
            *(undefined4 *)((longlong)param_1 + 0x5c) = 0;
            *(undefined4 *)(param_1 + 6) = 0;
          }
          if (*(char *)((longlong)param_1 + 0x3c) == '\0') {
            bVar7 = bVar6;
          }
          cVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525
                            (5,0);
          if (((cVar3 != '\0') && (bVar7 == false)) &&
             (*(float *)(param_1 + 6) <= 1.0 && *(float *)(param_1 + 6) != 1.0)) {
            (**(code **)(*param_1 + 0x238))(param_1,*(undefined8 *)(*param_1 + 0x240));
          }
          *(bool *)((longlong)param_1 + 0x54) = bVar7;
          return bVar7;
        }
      }
    }
  }
code_r0x00018047eda1:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

