// Ghidra pseudocode; not original source or compilable C.
// ev_fbe4bd90c6f5f0818b7621518e149c195473fb3bd0f21aec8257fa4759308f40

void ExposureUnnoticed2_ObjectUI_PcMenuPanel_OnlineShopPanel_OnlineShopPanelView__OnClickPurchase__0600190a
               (longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  char cVar5;
  undefined4 uVar6;
  int iVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  uint uVar11;
  bool bVar12;
  
  if (cRam0000000182eb7bc5 == '\0') {
    FUN_1802f2810(&DAT_182d5dae8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d61520);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61518);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61510);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dae0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5de00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ddc8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dd38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d61530);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dd80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5da50);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60030);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d613d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d613d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d613c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5da48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5da40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61b78);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d613c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d613b8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7bc5 = '\x01';
  }
  if (*(char *)(param_1 + 0x148) != '\0') {
    return;
  }
  if (*(longlong *)(param_1 + 0x120) == 0) goto code_r0x0001804dc1ff;
  uVar6 = FUN_180002c20(1,DAT_182d61530);
  cVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsEnoughRp__0600152e(uVar6,0);
  if (cVar5 != '\0') {
    plVar1 = *(longlong **)(param_1 + 0x120);
    if (plVar1 != (longlong *)0x0) {
      if ((*(byte *)(lRam0000000182d613d0 + 0x130) <= *(byte *)(*plVar1 + 0x130)) &&
         (*(longlong *)
           (*(longlong *)(*plVar1 + 200) + -8 +
           (ulonglong)*(byte *)(lRam0000000182d613d0 + 0x130) * 8) == lRam0000000182d613d0)) {
        lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        if ((lVar2 == 0) || (lVar2 = *(longlong *)(lVar2 + 0x218), lVar2 == 0))
        goto code_r0x0001804dc1ff;
        iVar7 = FUN_180e6c800(lVar2,(int)plVar1[3],
                              *(undefined8 *)
                               (*(longlong *)(*(longlong *)(DAT_182d5dae8 + 0x20) + 0xc0) + 0xf8));
        if (-1 < iVar7) {
          lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if ((lVar2 == 0) || (lVar2 = *(longlong *)(lVar2 + 0x218), lVar2 == 0))
          goto code_r0x0001804dc1ff;
          iVar7 = FUN_180e71cd0(lVar2,(int)plVar1[3],DAT_182d5dae0);
          if (0x62 < iVar7) {
            uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                              (uRam0000000182d613c0,0);
            uVar9 = 0;
            goto code_r0x0001804dc1c8;
          }
        }
      }
    }
    if (*(longlong *)(param_1 + 0x120) != 0) {
      uVar6 = FUN_180002c20(1,DAT_182d61530);
      ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ConsumeRp__0600152f(uVar6,0);
      if (**(longlong **)(DAT_182d5aa70 + 0xb8) != 0) {
        ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
                  (**(longlong **)(DAT_182d5aa70 + 0xb8),0x2f,0xbf800000,0,0);
        uVar8 = *(undefined8 *)(param_1 + 0x158);
        lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        uVar9 = FUN_1802c43a0(uRam0000000182d5ddc8);
        FUN_180e6bd40(uVar9,uVar8,0,
                      *(undefined8 *)
                       (*(longlong *)(*(longlong *)(lRam0000000182d61518 + 0x20) + 0xc0) + 0x40));
        if (lVar2 != 0) {
          bVar12 = DAT_182eb5d50 != 0;
          *(undefined8 *)(lVar2 + 0x210) = uVar9;
          if (bVar12) {
            uVar11 = (uint)(lVar2 + 0x210U >> 0xc);
            uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
            do {
              uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
              LOCK();
              bVar12 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
              if (bVar12) {
                *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar3 | 1L << (uVar11 & 0x3f);
              }
              UNLOCK();
            } while (!bVar12);
          }
          uVar8 = *(undefined8 *)(param_1 + 0x168);
          lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          uVar9 = FUN_1802c43a0(uRam0000000182d5de00);
          FUN_180e43550(uVar9,uVar8,0,
                        *(undefined8 *)
                         (*(longlong *)(*(longlong *)(lRam0000000182d61510 + 0x20) + 0xc0) + 0x40));
          if (lVar2 != 0) {
            bVar12 = DAT_182eb5d50 != 0;
            *(undefined8 *)(lVar2 + 0x220) = uVar9;
            if (bVar12) {
              uVar11 = (uint)(lVar2 + 0x220U >> 0xc);
              uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
              do {
                uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                LOCK();
                bVar12 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                if (bVar12) {
                  *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar3 | 1L << (uVar11 & 0x3f);
                }
                UNLOCK();
              } while (!bVar12);
            }
            uVar8 = *(undefined8 *)(param_1 + 0x160);
            lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
            uVar9 = FUN_1802c43a0(DAT_182d5dd38);
            FUN_180e6bd40(uVar9,uVar8,0,
                          *(undefined8 *)
                           (*(longlong *)(*(longlong *)(DAT_182d61520 + 0x20) + 0xc0) + 0x40));
            if (lVar2 != 0) {
              bVar12 = DAT_182eb5d50 != 0;
              *(undefined8 *)(lVar2 + 0x108) = uVar9;
              if (bVar12) {
                uVar11 = (uint)(lVar2 + 0x108U >> 0xc);
                uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
                do {
                  uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                  LOCK();
                  bVar12 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                  if (bVar12) {
                    *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar3 | 1L << (uVar11 & 0x3f);
                  }
                  UNLOCK();
                } while (!bVar12);
              }
              plVar1 = *(longlong **)(param_1 + 0x120);
              if (plVar1 != (longlong *)0x0) {
                lVar2 = *plVar1;
                if ((*(byte *)(lVar2 + 0x130) < *(byte *)(DAT_182d5da50 + 0x130)) ||
                   (*(longlong *)
                     (*(longlong *)(lVar2 + 200) + -8 +
                     (ulonglong)*(byte *)(DAT_182d5da50 + 0x130) * 8) != DAT_182d5da50)) {
                  if ((*(byte *)(lVar2 + 0x130) < *(byte *)(DAT_182d5da40 + 0x130)) ||
                     (*(longlong *)
                       (*(longlong *)(lVar2 + 200) + -8 +
                       (ulonglong)*(byte *)(DAT_182d5da40 + 0x130) * 8) != DAT_182d5da40)) {
                    if ((*(byte *)(lVar2 + 0x130) < *(byte *)(DAT_182d5da48 + 0x130)) ||
                       (*(longlong *)
                         (*(longlong *)(lVar2 + 200) + -8 +
                         (ulonglong)*(byte *)(DAT_182d5da48 + 0x130) * 8) != DAT_182d5da48)) {
                      if ((*(byte *)(lVar2 + 0x130) < *(byte *)(lRam0000000182d60030 + 0x130)) ||
                         (*(longlong *)
                           (*(longlong *)(lVar2 + 200) + -8 +
                           (ulonglong)*(byte *)(lRam0000000182d60030 + 0x130) * 8) !=
                          lRam0000000182d60030)) {
                        lVar2 = *plVar1;
                        if ((*(byte *)(lVar2 + 0x130) < *(byte *)(lRam0000000182d613d8 + 0x130)) ||
                           (*(longlong *)
                             (*(longlong *)(lVar2 + 200) + -8 +
                             (ulonglong)*(byte *)(lRam0000000182d613d8 + 0x130) * 8) !=
                            lRam0000000182d613d8)) {
                          if ((*(byte *)(lVar2 + 0x130) < *(byte *)(lRam0000000182d613d0 + 0x130))
                             || (*(longlong *)
                                  (*(longlong *)(lVar2 + 200) + -8 +
                                  (ulonglong)*(byte *)(lRam0000000182d613d0 + 0x130) * 8) !=
                                 lRam0000000182d613d0)) {
                            if ((*(byte *)(lRam0000000182d613c8 + 0x130) <= *(byte *)(lVar2 + 0x130)
                                ) && (*(longlong *)
                                       (*(longlong *)(lVar2 + 200) + -8 +
                                       (ulonglong)*(byte *)(lRam0000000182d613c8 + 0x130) * 8) ==
                                      lRam0000000182d613c8)) {
                              ExposureUnnoticed2_Scripts_InGame_GameStateFacade__SetActiveBodyPaint__06001538
                                        ((int)plVar1[3],0,0);
                            }
                          }
                          else {
                            ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ChangeItemNum__06001551
                                      ((int)plVar1[3],1,0);
                            if ((int)plVar1[3] == 1) {
                              ExposureUnnoticed2_ObjectUI_TutorialPanel_TutorialPanelView__Open__060017f0
                                        (5,0);
                            }
                            if (((int)plVar1[3] == 5) || ((int)plVar1[3] == 8)) {
                              ExposureUnnoticed2_ObjectUI_TutorialPanel_TutorialPanelView__Open__060017f0
                                        (10,0);
                            }
                            if (((int)plVar1[3] == 2) || ((int)plVar1[3] == 7)) {
                              ExposureUnnoticed2_ObjectUI_TutorialPanel_TutorialPanelView__Open__060017f0
                                        (0xb,0);
                            }
                          }
                        }
                        else {
                          lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                          if ((lVar2 == 0) || (lVar2 = *(longlong *)(lVar2 + 0x240), lVar2 == 0))
                          goto code_r0x0001804dc1ff;
                          FUN_180006140(lVar2,(int)plVar1[3]);
                        }
                      }
                      else {
                        ExposureUnnoticed2_Scripts_InGame_GameStateFacade__AddClothes__06001533
                                  (plVar1,0);
                      }
                    }
                    else {
                      lVar2 = plVar1[0x1a];
                      iVar7 = *(int *)((longlong)plVar1 + 0xcc);
                      if (cRam0000000182eb79ae == '\0') {
                        FUN_1802f2810(&DAT_182d5dbc0);
                        LOCK();
                        UNLOCK();
                        FUN_1802f2810(&DAT_182d58398);
                        LOCK();
                        UNLOCK();
                        cRam0000000182eb79ae = '\x01';
                      }
                      lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                      if ((lVar4 == 0) || (lVar4 = *(longlong *)(lVar4 + 0x220), lVar4 == 0))
                      goto code_r0x0001804dc1ff;
                      FUN_180e44740(lVar4,(int)lVar2 * 10000 + iVar7,0,2,
                                    *(undefined8 *)
                                     (*(longlong *)(*(longlong *)(DAT_182d5dbc0 + 0x20) + 0xc0) +
                                     0x100));
                      if (*(int *)((longlong)plVar1 + 0x54) != 0) {
                        ExposureUnnoticed2_ObjectUI_TutorialPanel_TutorialPanelView__Open__060017f0
                                  (0xd,0);
                      }
                    }
                  }
                  else {
                    lVar2 = plVar1[3];
                    if (cRam0000000182eb79a4 == '\0') {
                      FUN_1802f2810(0x182d5dc68);
                      LOCK();
                      UNLOCK();
                      FUN_1802f2810(&DAT_182d58398);
                      LOCK();
                      UNLOCK();
                      cRam0000000182eb79a4 = '\x01';
                    }
                    lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                    if ((lVar4 == 0) || (lVar4 = *(longlong *)(lVar4 + 0x210), lVar4 == 0))
                    goto code_r0x0001804dc1ff;
                    FUN_180e6cbf0(lVar4,(int)lVar2,0,2,
                                  *(undefined8 *)
                                   (*(longlong *)(*(longlong *)(lRam0000000182d5dc68 + 0x20) + 0xc0)
                                   + 0x100));
                  }
                }
                else {
                  ExposureUnnoticed2_Scripts_InGame_GameStateFacade__AddAdultGoods__06001535
                            ((int)plVar1[3],0);
                  if (((int)plVar1[10] == 1) &&
                     (cVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsBringItem__06001552
                                        (0x2711,0), cVar5 == '\0')) {
                    ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ChangeItemNum__06001551
                              (0x2711,1,0);
                    ExposureUnnoticed2_ObjectUI_TutorialPanel_TutorialPanelView__Open__060017f0(7,0)
                    ;
                  }
                  if (((int)plVar1[3] == 4) &&
                     (cVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsBringItem__06001552
                                        (10000,0), cVar5 == '\0')) {
                    ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ChangeItemNum__06001551
                              (10000,1,0);
                  }
                  if ((int)plVar1[10] == 3) {
                    ExposureUnnoticed2_ObjectUI_TutorialPanel_TutorialPanelView__Open__060017f0(9,0)
                    ;
                  }
                  iVar7 = (int)plVar1[3];
                  if (((iVar7 == 3) || (iVar7 == 4)) || (iVar7 == 5)) {
                    ExposureUnnoticed2_ObjectUI_TutorialPanel_TutorialPanelView__Open__060017f0(6,0)
                    ;
                  }
                }
              }
              lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
              if (lVar2 != 0) {
                uVar8 = *(undefined8 *)(lVar2 + 0x210);
                uVar9 = FUN_1802c43a0(uRam0000000182d5ddc8);
                FUN_180e6bd40(uVar9,uVar8,0,
                              *(undefined8 *)
                               (*(longlong *)(*(longlong *)(lRam0000000182d61518 + 0x20) + 0xc0) +
                               0x40));
                bVar12 = DAT_182eb5d50 != 0;
                *(undefined8 *)(param_1 + 0x158) = uVar9;
                if (bVar12) {
                  uVar11 = (uint)(param_1 + 0x158U >> 0xc);
                  uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
                  do {
                    uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                    LOCK();
                    bVar12 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                    if (bVar12) {
                      *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar3 | 1L << (uVar11 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar12);
                }
                lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                if (lVar2 != 0) {
                  uVar8 = *(undefined8 *)(lVar2 + 0x108);
                  uVar9 = FUN_1802c43a0(DAT_182d5dd38);
                  FUN_180e6bd40(uVar9,uVar8,0,
                                *(undefined8 *)
                                 (*(longlong *)(*(longlong *)(DAT_182d61520 + 0x20) + 0xc0) + 0x40))
                  ;
                  bVar12 = DAT_182eb5d50 != 0;
                  *(undefined8 *)(param_1 + 0x160) = uVar9;
                  if (bVar12) {
                    uVar11 = (uint)(param_1 + 0x160U >> 0xc);
                    uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
                    do {
                      uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                      LOCK();
                      bVar12 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                      if (bVar12) {
                        *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar3 | 1L << (uVar11 & 0x3f);
                      }
                      UNLOCK();
                    } while (!bVar12);
                  }
                  lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                  if (lVar2 != 0) {
                    uVar8 = *(undefined8 *)(lVar2 + 0x220);
                    uVar9 = FUN_1802c43a0(uRam0000000182d5de00);
                    FUN_180e43550(uVar9,uVar8,0,
                                  *(undefined8 *)
                                   (*(longlong *)(*(longlong *)(lRam0000000182d61510 + 0x20) + 0xc0)
                                   + 0x40));
                    bVar12 = DAT_182eb5d50 != 0;
                    *(undefined8 *)(param_1 + 0x168) = uVar9;
                    if (bVar12) {
                      uVar11 = (uint)(param_1 + 0x168U >> 0xc);
                      uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
                      do {
                        uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                        LOCK();
                        bVar12 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                        if (bVar12) {
                          *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) =
                               uVar3 | 1L << (ulonglong)(uVar11 & 0x3f);
                        }
                        UNLOCK();
                      } while (!bVar12);
                    }
                    if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
                        (lVar2 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40),
                        lVar2 != 0)) &&
                       ((*(longlong *)(lVar2 + 0x118) != 0 &&
                        (lVar2 = *(longlong *)
                                  (*(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40) +
                                  0x1b8), lVar2 != 0)))) {
                      ExposureUnnoticed2_Object3D_Player_Scripts_PlayerCosplayManager__SetupCostumeFromGameState__06000d76
                                (lVar2,0);
                      if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
                          (lVar2 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40),
                          lVar2 != 0)) && (lVar2 = *(longlong *)(lVar2 + 0x1b0), lVar2 != 0)) {
                        ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyMaterialController__SetupBodyPaintFromGameState__06000cd7
                                  (lVar2,0);
                        lVar2 = *(longlong *)(param_1 + 0x120);
                        *(undefined1 *)(param_1 + 0x188) = 1;
                        if (*(longlong *)(param_1 + 0x78) != 0) {
                          ExposureUnnoticed2_ObjectUI_PcMenuPanel_OnlineShopPanel_OnlineShopPanelView__OnClickTab__06001905
                                    (param_1,*(undefined4 *)(*(longlong *)(param_1 + 0x78) + 0x20),1
                                     ,0);
                          *(undefined1 *)(param_1 + 0x188) = 0;
                          ExposureUnnoticed2_ObjectUI_PcMenuPanel_OnlineShopPanel_OnlineShopPanelView__set_CurrentRecord__06001900
                                    (param_1,0);
                          ExposureUnnoticed2_ObjectUI_PcMenuPanel_OnlineShopPanel_OnlineShopPanelView__RefreshRight__06001909
                                    (param_1,lVar2,0);
                          if (lVar2 != 0) {
                            uVar8 = FUN_180002c20(0,DAT_182d61530,lVar2);
                            uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                              (uVar8,0);
                            uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017b0
                                              (uRam0000000182d613b8,uVar8,0);
                            uVar9 = 1;
                            goto code_r0x0001804dc1c8;
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
code_r0x0001804dc1ff:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d61b78,0);
  uVar9 = 0;
code_r0x0001804dc1c8:
  ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
            (uVar8,uVar9,0);
  return;
}

