// Ghidra pseudocode; not original source or compilable C.
// ev_6ce8f0979bb10ef2d477bc92e3ba8b3c860704adedcb5b0e1df8200afb8c3086

void ExposureUnnoticed2_ObjectUI_SystemMenu_SystemMenuView___OnClickEmergencyEscape_b__15_3__06001818
               (longlong param_1)

{
  undefined4 uVar1;
  ulonglong uVar2;
  char cVar3;
  byte bVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  code *pcVar8;
  ulonglong uVar9;
  undefined8 unaff_RDI;
  uint uVar10;
  bool bVar11;
  
  if (cRam0000000182eb7b1a == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58080);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e060);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e190);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60190);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f200);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f1f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f260);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b1a = '\x01';
  }
  if (**(longlong **)(DAT_182d53c48 + 0xb8) != 0) {
    lVar6 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x60);
    if (*(int *)(lRam0000000182d5f260 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar5 = *(longlong *)(*(longlong *)(lRam0000000182d5f260 + 0xb8) + 0x10);
    if (lVar5 == 0) {
      if (*(int *)(lRam0000000182d5f260 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar7 = **(undefined8 **)(lRam0000000182d5f260 + 0xb8);
      lVar5 = FUN_1802c43a0(DAT_182d58368);
      FUN_1814df680(lVar5,uVar7,uRam0000000182d5f200,0);
      *(longlong *)(*(longlong *)(lRam0000000182d5f260 + 0xb8) + 0x10) = lVar5;
      if (DAT_182eb5d50 != 0) {
        uVar10 = (uint)(*(longlong *)(lRam0000000182d5f260 + 0xb8) + 0x10U >> 0xc);
        uVar9 = (ulonglong)((uVar10 & 0x1fffff) >> 6);
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
          LOCK();
          bVar11 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
          if (bVar11) {
            *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar2 | 1L << (uVar10 & 0x3f);
          }
          UNLOCK();
        } while (!bVar11);
      }
    }
    if (lVar6 != 0) {
      ExposureUnnoticed2_Scripts_InGame_StageTransController__TransStageIfInCondition__06001668
                (lVar6,10,0,0,lVar5,0);
      if ((((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
           (lVar6 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar6 != 0)) &&
          (lVar6 = *(longlong *)(lVar6 + 0x30), lVar6 != 0)) &&
         ((lVar6 = *(longlong *)(lVar6 + 0x40), lVar6 != 0 &&
          (lVar6 = *(longlong *)(lVar6 + 0xf0), lVar6 != 0)))) {
        if ((*(char *)(lVar6 + 0x2c) == '\0') &&
           ((*(char *)(lVar6 + 0x2d) == '\0' &&
            (cVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsAttachSomeHandcuffs__0600155d
                               (0), cVar3 != '\0')))) {
          *(undefined4 *)(lVar6 + 0x30) = 1;
        }
        if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
            (lVar6 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar6 != 0)) &&
           (lVar6 = *(longlong *)(lVar6 + 0x60), lVar6 != 0)) {
          bVar11 = DAT_182eb5d50 != 0;
          *(undefined8 *)(lVar6 + 0x60) = 0;
          if (bVar11) {
            uVar10 = (uint)(lVar6 + 0x60U >> 0xc);
            uVar9 = (ulonglong)((uVar10 & 0x1fffff) >> 6);
            do {
              uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
              LOCK();
              bVar11 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
              if (bVar11) {
                *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) =
                     uVar2 | 1L << (ulonglong)(uVar10 & 0x3f);
              }
              UNLOCK();
            } while (!bVar11);
          }
          if (**(longlong **)(lRam0000000182d5e190 + 0xb8) != 0) {
            ExposureUnnoticed2_Scripts_Mission_MissionManager__ResetMission__0600146a
                      (**(longlong **)(lRam0000000182d5e190 + 0xb8),0);
            lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar6 != 0) {
              *(undefined8 *)(lVar6 + 0x1f0) = 0;
              lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
              if (lVar6 != 0) {
                *(undefined4 *)(lVar6 + 0x120) = 0;
                lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                if (lVar6 != 0) {
                  *(undefined4 *)(lVar6 + 0xbc) = 0;
                  lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                  if (lVar6 != 0) {
                    *(undefined4 *)(lVar6 + 0xc0) = 0;
                    lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                    if (lVar6 != 0) {
                      *(undefined4 *)(lVar6 + 0x1b8) = 0;
                      lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                      if (lVar6 != 0) {
                        *(undefined4 *)(lVar6 + 0x274) = 0;
                        lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                        if (lVar6 != 0) {
                          *(undefined4 *)(lVar6 + 0x10) = 0;
                          lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                          if (lVar6 != 0) {
                            *(undefined8 *)(lVar6 + 0x180) = 0x3dcccccd00000000;
                            *(undefined4 *)(lVar6 + 0x188) = 0;
                            if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                                (lVar6 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30)
                                , lVar6 != 0)) && (lVar6 = *(longlong *)(lVar6 + 0x28), lVar6 != 0))
                            {
                              if (0 < *(int *)(lVar6 + 0x24)) {
                                FUN_181646f50(*(undefined8 *)(lVar6 + 0x18),0,
                                              *(undefined4 *)(lVar6 + 0x24),0);
                                if (*(longlong *)(lVar6 + 0x10) == 0) goto code_r0x0001804c1ee3;
                                FUN_181646f50(*(undefined8 *)(lVar6 + 0x10),0,
                                              *(undefined4 *)(*(longlong *)(lVar6 + 0x10) + 0x18),0)
                                ;
                                *(undefined8 *)(lVar6 + 0x20) = 0;
                                *(undefined4 *)(lVar6 + 0x28) = 0xffffffff;
                              }
                              *(int *)(lVar6 + 0x38) = *(int *)(lVar6 + 0x38) + 1;
                              lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                              if (lVar6 != 0) {
                                if (*(char *)(lVar6 + 0x1a9) != '\0') {
                                  *(undefined1 *)(lVar6 + 0x1a9) = 0;
                                  lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                                  if (lVar6 == 0) goto code_r0x0001804c1ee3;
                                  uVar1 = *(undefined4 *)(lVar6 + 0x1ac);
                                  bVar4 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsEquipAdultGoods__0600153c
                                                    (*(undefined4 *)
                                                      (*(longlong *)
                                                        (*(longlong *)(DAT_182d58398 + 0xb8) + 0x48)
                                                      + 0x1ac),0);
                                  ExposureUnnoticed2_Scripts_InGame_GameStateFacade__UpdateAdultGoodsState__0600153d
                                            (uVar1,bVar4 ^ 1,0);
                                }
                                lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                                if (lVar6 != 0) {
                                  if (*(char *)(lVar6 + 0x1a8) != '\0') {
                                    *(undefined1 *)(lVar6 + 0x1a8) = 0;
                                    lVar6 = *(longlong *)
                                             (*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                                    if (lVar6 == 0) goto code_r0x0001804c1ee3;
                                    uVar1 = *(undefined4 *)(lVar6 + 0x1ac);
                                    bVar4 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsEquipAdultGoods__0600153c
                                                      (*(undefined4 *)
                                                        (*(longlong *)
                                                          (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                          0x48) + 0x1ac),0);
                                    ExposureUnnoticed2_Scripts_InGame_GameStateFacade__UpdateAdultGoodsState__0600153d
                                              (uVar1,bVar4 ^ 1,0);
                                  }
                                  ExposureUnnoticed2_Scripts_InGame_SaveManager__Save__06001601
                                            (3,0xffffffff,0,0);
                                  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                                     (lVar6 = *(longlong *)
                                               (**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30),
                                     lVar6 != 0)) {
                                    *(undefined1 *)(lVar6 + 0x10) = 1;
                                    ExposureUnnoticed2_Scripts_InGame_SaveManager__Load__06001602
                                              (3,**(undefined4 **)(lRam0000000182d60190 + 0xb8),0);
                                    if (*(int *)(DAT_182d58080 + 0xe0) == 0) {
                                      FUN_18035c820(DAT_182d58080);
                                    }
                                    uVar7 = *(undefined8 *)
                                             (*(longlong *)(DAT_182d58080 + 0xb8) + 0x18);
                                    if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                                      FUN_18035c820();
                                    }
                                    ExposureUnnoticed2_Scripts_Base_EventManager__Broadcast__06001716
                                              (uVar7,0);
                                    if (*(int *)(lRam0000000182d5f260 + 0xe0) == 0) {
                                      FUN_18035c820();
                                    }
                                    lVar6 = *(longlong *)
                                             (*(longlong *)(lRam0000000182d5f260 + 0xb8) + 0x18);
                                    if (lVar6 == 0) {
                                      if (*(int *)(lRam0000000182d5f260 + 0xe0) == 0) {
                                        FUN_18035c820();
                                      }
                                      uVar7 = **(undefined8 **)(lRam0000000182d5f260 + 0xb8);
                                      lVar6 = FUN_1802c43a0(DAT_182d58368);
                                      FUN_1814df680(lVar6,uVar7,uRam0000000182d5f1f8,0);
                                      *(longlong *)
                                       (*(longlong *)(lRam0000000182d5f260 + 0xb8) + 0x18) = lVar6;
                                      if (DAT_182eb5d50 != 0) {
                                        uVar10 = (uint)(*(longlong *)(lRam0000000182d5f260 + 0xb8) +
                                                        0x18U >> 0xc);
                                        uVar9 = (ulonglong)((uVar10 & 0x1fffff) >> 6);
                                        do {
                                          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
                                          LOCK();
                                          bVar11 = uVar2 == *(ulonglong *)
                                                             (&DAT_182f0c920 + uVar9 * 8);
                                          if (bVar11) {
                                            *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) =
                                                 uVar2 | 1L << (uVar10 & 0x3f);
                                          }
                                          UNLOCK();
                                        } while (!bVar11);
                                      }
                                    }
                                    ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b
                                              (lVar6,1,0);
                                    if (DAT_182eb7fd7 == '\0') {
                                      FUN_1802f2810(&DAT_182d58368,0);
                                      LOCK();
                                      UNLOCK();
                                      FUN_1802f2810(&DAT_182d69200);
                                      LOCK();
                                      UNLOCK();
                                      FUN_1802f2810(&DAT_182d5f3b8);
                                      LOCK();
                                      UNLOCK();
                                      DAT_182eb7fd7 = '\x01';
                                    }
                                    if (*(char *)(param_1 + 0x40) == '\0') {
                                      *(undefined1 *)(param_1 + 0x40) = 1;
                                      uVar7 = FUN_1802c43a0(DAT_182d58368);
                                      FUN_1814df680(uVar7,param_1,DAT_182d69200,0,unaff_RDI);
                                      ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b
                                                (uVar7,1,0);
                                      lVar6 = *(longlong *)(param_1 + 0x38);
                                      if (*(int *)(DAT_182d5f3b8 + 0xe0) == 0) {
                                        FUN_18035c820(DAT_182d5f3b8);
                                      }
                                      if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
                                        FUN_18031dad0();
                                      }
                                      uVar1 = **(undefined4 **)(DAT_182d5f3b8 + 0xb8);
                                      pcVar8 = DAT_182ebf368;
                                      if ((DAT_182ebf368 == (code *)0x0) &&
                                         (pcVar8 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Animator::SetTriggerID(System.Int32)"
                                                  ), pcVar8 == (code *)0x0)) {
                                        uVar7 = FUN_1802ced60(
                                                  "UnityEngine.Animator::SetTriggerID(System.Int32)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                        FUN_1802cca90(uVar7,0);
                                      }
                                      DAT_182ebf368 = pcVar8;
                                      (*DAT_182ebf368)(lVar6,uVar1);
                                    }
                                    return;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
code_r0x0001804c1ee3:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

