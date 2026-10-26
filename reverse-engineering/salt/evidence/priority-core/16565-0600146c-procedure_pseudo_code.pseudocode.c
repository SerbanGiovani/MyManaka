// Ghidra pseudocode; not original source or compilable C.
// ev_095e2feb906ef82aecd9e4427e36739bfe4f6f652c0cc4dc28b3a7230add20eb

bool ExposureUnnoticed2_Scripts_Mission_MissionMoveFromClothes__IsInCondition__0600146c
               (longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  
  if (cRam0000000182eb7928 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb7928 = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar1 != 0)) {
    lVar1 = *(longlong *)(lVar1 + 0x30);
    if (**(longlong **)(DAT_182d58230 + 0xb8) != 0) {
      iVar4 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                        (**(longlong **)(DAT_182d58230 + 0xb8),0);
      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (iVar4 == 1) {
        bVar6 = false;
      }
      else {
        if ((((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
             (lVar2 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar2 == 0)) ||
            (lVar2 = *(longlong *)(lVar2 + 0x60), lVar2 == 0)) ||
           (lVar2 = *(longlong *)(lVar2 + 0x10), lVar2 == 0)) goto DAT_18047e5e8;
        bVar6 = *(int *)(lVar2 + 0x30) == -1;
      }
      if (((**(longlong **)(DAT_182d58230 + 0xb8) != 0) &&
          (lVar2 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar2 != 0)) &&
         (lVar2 = *(longlong *)(lVar2 + 0x60), lVar2 != 0)) {
        if (*(int *)(lVar2 + 0x168) == 0) {
          if (((lVar1 == 0) || (lVar1 = *(longlong *)(lVar1 + 0x40), lVar1 == 0)) ||
             ((lVar1 = *(longlong *)(lVar1 + 0x60), lVar1 == 0 ||
              (lVar1 = *(longlong *)(lVar1 + 0x10), lVar1 == 0)))) goto DAT_18047e5e8;
          if (*(int *)(lVar1 + 0x30) != -1) {
            *(undefined1 *)((longlong)param_1 + 0x3c) = 0;
          }
        }
        else {
          *(undefined1 *)((longlong)param_1 + 0x3c) = 1;
          *(undefined4 *)((longlong)param_1 + 0x5c) = 0;
          *(undefined4 *)(param_1 + 6) = 0;
        }
        bVar5 = false;
        if (*(char *)((longlong)param_1 + 0x3c) == '\0') {
          bVar5 = bVar6;
        }
        cVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525
                          (5,0);
        if ((((cVar3 != '\0') && (*(char *)((longlong)param_1 + 0x3c) == '\0')) && (bVar5 == false))
           && (*(float *)(param_1 + 6) <= 1.0 && *(float *)(param_1 + 6) != 1.0)) {
          (**(code **)(*param_1 + 0x238))(param_1,*(undefined8 *)(*param_1 + 0x240));
        }
        *(bool *)((longlong)param_1 + 0x54) = bVar5;
        return bVar5;
      }
    }
  }
DAT_18047e5e8:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

