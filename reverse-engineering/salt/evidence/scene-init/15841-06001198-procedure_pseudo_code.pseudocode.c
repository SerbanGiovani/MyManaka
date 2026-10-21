// Ghidra pseudocode; not original source or compilable C.
// ev_cdc1c75d28b281a209ad4187747b443349359bbee15682ee236cf9abf71ff10c

void ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__Initialize__06001198
               (longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  undefined8 uVar7;
  code *pcVar8;
  longlong lVar9;
  ulonglong uVar10;
  uint uVar11;
  bool bVar12;
  
  if (cRam0000000182eb77ea == '\0') {
    FUN_1802f2810(0x182d57d38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5abb0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aab0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d57d30);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aba8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aaa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aaa0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58380);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d57d90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aa98);
    LOCK();
    UNLOCK();
    cRam0000000182eb77ea = '\x01';
  }
  if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar9 = **(longlong **)(DAT_182d58380 + 0xb8);
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
  if (lVar9 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar9 + 0x10) != 0) {
      return;
    }
  }
  if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
    FUN_18035c820();
  }
  **(longlong **)(DAT_182d58380 + 0xb8) = param_1;
  if (DAT_182eb5d50 != 0) {
    uVar11 = (uint)(*(ulonglong *)(DAT_182d58380 + 0xb8) >> 0xc);
    uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
      LOCK();
      bVar12 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar1 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  iVar6 = DAT_182eb5d50;
  *(longlong *)(param_1 + 0x168) = param_2;
  if (iVar6 != 0) {
    uVar11 = (uint)(param_1 + 0x168U >> 0xc);
    uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
      LOCK();
      bVar12 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar1 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  plVar2 = *(longlong **)(param_1 + 0x138);
  plVar3 = *(longlong **)(param_1 + 0x140);
  if (plVar2 != (longlong *)0x0) {
    uVar7 = (**(code **)(*plVar2 + 0x338))(plVar2,*(undefined8 *)(*plVar2 + 0x340));
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar7 = FUN_1809f0e30(uVar7,uRam0000000182d57d90);
    (**(code **)(*plVar2 + 0x348))(plVar2,uVar7,*(undefined8 *)(*plVar2 + 0x350));
    if (plVar3 != (longlong *)0x0) {
      (**(code **)(*plVar3 + 0x348))(plVar3,uVar7,*(undefined8 *)(*plVar3 + 0x350));
      bVar12 = DAT_182eb5d50 != 0;
      *(undefined8 *)(param_1 + 0x1a0) = uVar7;
      if (bVar12) {
        uVar11 = (uint)(param_1 + 0x1a0U >> 0xc);
        uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
          LOCK();
          bVar12 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
          if (bVar12) {
            *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar1 | 1L << (uVar11 & 0x3f);
          }
          UNLOCK();
        } while (!bVar12);
      }
      if (*(longlong *)(param_1 + 0x188) != 0) {
        *(undefined4 *)(*(longlong *)(param_1 + 0x188) + 0x1c) = 0x3f800000;
        uVar7 = FUN_1802c43a0(uRam0000000182d5aa98);
        bVar12 = DAT_182eb5d50 != 0;
        *(undefined8 *)(param_1 + 0x170) = uVar7;
        if (bVar12) {
          uVar11 = (uint)(param_1 + 0x170U >> 0xc);
          uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
          do {
            uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
            LOCK();
            bVar12 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
            if (bVar12) {
              *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar1 | 1L << (uVar11 & 0x3f);
            }
            UNLOCK();
          } while (!bVar12);
        }
        if ((((*(longlong *)(param_1 + 0x28) != 0) &&
             (*(undefined4 *)(*(longlong *)(param_1 + 0x28) + 0x40) = 0x43480000, param_2 != 0)) &&
            (*(longlong *)(param_2 + 0x40) != 0)) &&
           ((lVar9 = *(longlong *)(*(longlong *)(param_2 + 0x40) + 0xd0), lVar9 != 0 &&
            (*(longlong *)(param_1 + 0x28) != 0)))) {
          Common_CommonUI_CommonGauge_GaugeView__SetMax__06001e4c
                    (*(longlong *)(param_1 + 0x28),*(undefined4 *)(lVar9 + 0x14),0);
          if (*(longlong *)(param_1 + 0x38) != 0) {
            *(undefined4 *)(*(longlong *)(param_1 + 0x38) + 0x40) = 0x40000000;
            if (((*(longlong *)(param_2 + 0x40) != 0) &&
                (lVar9 = *(longlong *)(*(longlong *)(param_2 + 0x40) + 200), lVar9 != 0)) &&
               (*(longlong *)(param_1 + 0x38) != 0)) {
              Common_CommonUI_CommonGauge_GaugeView__SetMax__06001e4c
                        (*(longlong *)(param_1 + 0x38),*(undefined4 *)(lVar9 + 0x10),0);
              if (*(longlong *)(param_1 + 0x40) != 0) {
                *(undefined4 *)(*(longlong *)(param_1 + 0x40) + 0x40) = 0x43c80000;
                if ((((*(longlong *)(param_1 + 0x40) != 0) &&
                     (Common_CommonUI_CommonGauge_GaugeView__SetMax__06001e4c
                                (*(longlong *)(param_1 + 0x40),0x3f800000,0),
                     *(longlong *)(param_1 + 0x58) != 0)) && (*(longlong *)(param_2 + 0x40) != 0))
                   && (*(longlong *)(param_1 + 0x60) != 0)) {
                  ExposureUnnoticed2_ObjectUI_InGame_HeatBeatPanel_HeartRatePanelView__Initialize__06001b1d
                            (*(longlong *)(param_1 + 0x60),
                             *(undefined8 *)(*(longlong *)(param_2 + 0x40) + 0x188),0);
                  lVar9 = *(longlong *)(param_1 + 0x70);
                  if (lVar9 != 0) {
                    if (cRam0000000182eb7cde == '\0') {
                      FUN_1802f2810(&DAT_182d58288);
                      LOCK();
                      UNLOCK();
                      FUN_1802f2810(&DAT_182d53c48);
                      LOCK();
                      UNLOCK();
                      cRam0000000182eb7cde = '\x01';
                    }
                    if (**(longlong **)(DAT_182d53c48 + 0xb8) != 0) {
                      bVar12 = DAT_182eb5d50 != 0;
                      *(undefined8 *)(lVar9 + 0x50) =
                           *(undefined8 *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x38);
                      if (bVar12) {
                        uVar11 = (uint)(lVar9 + 0x50U >> 0xc);
                        uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
                        do {
                          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                          LOCK();
                          bVar12 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                          if (bVar12) {
                            *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) =
                                 uVar1 | 1L << (uVar11 & 0x3f);
                          }
                          UNLOCK();
                        } while (!bVar12);
                      }
                      uVar7 = *(undefined8 *)(lVar9 + 0x48);
                      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
                        FUN_18035c820();
                      }
                      ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DestroyChildren__0600172c
                                (uVar7,0);
                      lVar9 = *(longlong *)(param_1 + 0x78);
                      if (lVar9 != 0) {
                        if (cRam0000000182eb7c9d == '\0') {
                          FUN_1802f2810(&DAT_182d53c48);
                          LOCK();
                          UNLOCK();
                          cRam0000000182eb7c9d = '\x01';
                        }
                        lVar4 = *(longlong *)(lVar9 + 0x20);
                        if (lVar4 != 0) {
                          pcVar8 = DAT_182ec1138;
                          if ((DAT_182ec1138 == (code *)0x0) &&
                             (pcVar8 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar8 == (code *)0x0)) {
                            uVar7 = FUN_1802ced60(
                                                 "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                 );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar7,0);
                          }
                          DAT_182ec1138 = pcVar8;
                          (*DAT_182ec1138)(lVar4,0);
                          lVar4 = *(longlong *)(lVar9 + 0x38);
                          if (lVar4 != 0) {
                            pcVar8 = DAT_182ec4fa8;
                            if ((DAT_182ec4fa8 == (code *)0x0) &&
                               (pcVar8 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.CanvasGroup::set_alpha(System.Single)"
                                                  ), pcVar8 == (code *)0x0)) {
                              uVar7 = FUN_1802ced60(
                                                  "UnityEngine.CanvasGroup::set_alpha(System.Single)"
                                                  );
                    /* WARNING: Subroutine does not return */
                              FUN_1802cca90(uVar7,0);
                            }
                            DAT_182ec4fa8 = pcVar8;
                            (*DAT_182ec4fa8)(lVar4,0);
                            if ((((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                                 (lVar4 = *(longlong *)
                                           (**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28),
                                 lVar4 != 0)) && (lVar4 = *(longlong *)(lVar4 + 0x30), lVar4 != 0))
                               && (lVar4 = *(longlong *)(lVar4 + 0x40), lVar4 != 0)) {
                              bVar12 = DAT_182eb5d50 != 0;
                              *(undefined8 *)(lVar9 + 0x40) = *(undefined8 *)(lVar4 + 0xf0);
                              if (bVar12) {
                                uVar11 = (uint)(lVar9 + 0x40U >> 0xc);
                                uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
                                do {
                                  uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                                  LOCK();
                                  bVar12 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                                  if (bVar12) {
                                    *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) =
                                         uVar1 | 1L << (uVar11 & 0x3f);
                                  }
                                  UNLOCK();
                                } while (!bVar12);
                              }
                              if (*(longlong *)(param_1 + 0x80) != 0) {
                                ExposureUnnoticed2_ObjectUI_InGame_Compass_CompassView__Initialize__06001b2d
                                          (*(longlong *)(param_1 + 0x80),0);
                                lVar9 = *(longlong *)(param_1 + 0x90);
                                if (lVar9 != 0) {
                                  if (cRam0000000182eb77fb == '\0') {
                                    FUN_1802f2810(&DAT_182d5a8e0);
                                    LOCK();
                                    UNLOCK();
                                    cRam0000000182eb77fb = '\x01';
                                  }
                                  **(longlong **)(DAT_182d5a8e0 + 0xb8) = lVar9;
                                  if (DAT_182eb5d50 != 0) {
                                    uVar11 = (uint)(*(ulonglong *)(DAT_182d5a8e0 + 0xb8) >> 0xc);
                                    uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
                                    do {
                                      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                                      LOCK();
                                      bVar12 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                                      if (bVar12) {
                                        *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) =
                                             uVar1 | 1L << (uVar11 & 0x3f);
                                      }
                                      UNLOCK();
                                    } while (!bVar12);
                                  }
                                  if (*(longlong *)(param_1 + 0x88) != 0) {
                                    ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__Initialize__06001a96
                                              (*(longlong *)(param_1 + 0x88),0);
                                    lVar9 = *(longlong *)(param_1 + 0xe8);
                                    if (lVar9 != 0) {
                                      if (cRam0000000182eb7ccd == '\0') {
                                        FUN_1802f2810(&DAT_182d58398);
                                        LOCK();
                                        UNLOCK();
                                        cRam0000000182eb7ccd = '\x01';
                                      }
                                      lVar4 = *(longlong *)
                                               (*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                                      if (lVar4 != 0) {
                                        lVar5 = *(longlong *)(lVar9 + 0x30);
                                        *(undefined4 *)(lVar9 + 0x38) =
                                             *(undefined4 *)(lVar4 + 0x7c);
                                        if (*(longlong *)(lVar9 + 0x40) != 0) {
                                          *(undefined4 *)(*(longlong *)(lVar9 + 0x40) + 0x10) = 0;
                                          *(undefined4 *)(lVar9 + 0x3c) = 0;
                                          if (lVar5 != 0) {
                                            pcVar8 = DAT_182ec4fa8;
                                            if ((DAT_182ec4fa8 == (code *)0x0) &&
                                               (pcVar8 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.CanvasGroup::set_alpha(System.Single)"
                                                  ), pcVar8 == (code *)0x0)) {
                                              uVar7 = FUN_1802ced60(
                                                  "UnityEngine.CanvasGroup::set_alpha(System.Single)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                              FUN_1802cca90(uVar7,0);
                                            }
                                            DAT_182ec4fa8 = pcVar8;
                                            (*DAT_182ec4fa8)(lVar5,0);
                                            ExposureUnnoticed2_ObjectUI_InGame_MotionSpeedPanel_MotionSpeedPanelView__AdjustSpeed__06001aed
                                                      (lVar9,0);
                                            ExposureUnnoticed2_ObjectUI_InGame_MotionSpeedPanel_MotionSpeedPanelView__RefreshView__06001aec
                                                      (lVar9,0);
                                            lVar9 = *(longlong *)(param_1 + 0xf0);
                                            if (lVar9 != 0) {
                                              if (cRam0000000182eb7cd2 == '\0') {
                                                FUN_1802f2810(&DAT_182d58398);
                                                LOCK();
                                                UNLOCK();
                                                cRam0000000182eb7cd2 = '\x01';
                                              }
                                              lVar4 = *(longlong *)
                                                       (*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                                              if (lVar4 != 0) {
                                                lVar5 = *(longlong *)(lVar9 + 0x30);
                                                *(int *)(lVar9 + 0x38) = *(int *)(lVar4 + 0x80) + 2;
                                                if (*(longlong *)(lVar9 + 0x40) != 0) {
                                                  *(undefined4 *)
                                                   (*(longlong *)(lVar9 + 0x40) + 0x10) = 0;
                                                  *(undefined4 *)(lVar9 + 0x3c) = 0;
                                                  if (lVar5 != 0) {
                                                    pcVar8 = DAT_182ec4fa8;
                                                    if ((DAT_182ec4fa8 == (code *)0x0) &&
                                                       (pcVar8 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.CanvasGroup::set_alpha(System.Single)"
                                                  ), pcVar8 == (code *)0x0)) {
                                                    uVar7 = FUN_1802ced60(
                                                  "UnityEngine.CanvasGroup::set_alpha(System.Single)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar7,0);
                                                  }
                                                  DAT_182ec4fa8 = pcVar8;
                                                  (*DAT_182ec4fa8)(lVar5,0);
                                                  ExposureUnnoticed2_ObjectUI_InGame_MotionSpeedPanel_WalkSpeedPanelView__AdjustSpeed__06001af2
                                                            (lVar9,0);
                                                  ExposureUnnoticed2_ObjectUI_InGame_MotionSpeedPanel_WalkSpeedPanelView__RefreshView__06001af1
                                                            (lVar9,0);
                                                  if (*(longlong *)(param_1 + 0x118) != 0) {
                                                                                                        
                                                  ExposureUnnoticed2_ObjectUI_InGame_VIbeStatePanel_VibeStatePanelView__Initialize__06001a6e
                                                            (*(longlong *)(param_1 + 0x118),0);
                                                  if (*(longlong *)(param_1 + 0x120) != 0) {
                                                                                                        
                                                  ExposureUnnoticed2_ObjectUI_InGame_IngameUiManualView__Initialize__06001a69
                                                            (*(longlong *)(param_1 + 0x120),0);
                                                  lVar9 = FUN_180735660(param_1,uRam0000000182d5aab0
                                                                       );
                                                  if (lVar9 != 0) {
                                                                                                        
                                                  ExposureUnnoticed2_Scripts_Base_AspectRatioApplyer__Initialize__06001760
                                                            (lVar9,0);
                                                  uVar7 = FUN_1802c43a0(DAT_182d5abb0);
                                                  FUN_180665bb0(uVar7,param_1,uRam0000000182d5aaa0,0
                                                               );
                                                  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  FUN_180993250(uVar7,0,DAT_182d5aba8);
                                                  uVar7 = FUN_1802c43a0(uRam0000000182d57d38);
                                                  FUN_180665bb0(uVar7,param_1,uRam0000000182d5aaa8,0
                                                               );
                                                  FUN_180993250(uVar7,0,uRam0000000182d57d30);
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
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

