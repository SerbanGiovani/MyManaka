// Ghidra pseudocode; not original source or compilable C.
// ev_2be0413113212b7172505b3b7a3c670947b6eec2028bbd8d939894670bca7a0e

void __c___TransStage_b__6_1__0600166e(void)

{
  ulonglong uVar1;
  code *pcVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  uint uVar9;
  bool bVar10;
  undefined8 uStack_28;
  undefined4 uStack_20;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (cRam0000000182eb7a3d == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e190);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d59700);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fe58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5feb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fe48);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a3d = '\x01';
  }
  if (**(longlong **)(DAT_182d53c48 + 0xb8) != 0) {
    lVar4 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30);
    if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
        (lVar3 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar3 != 0)) &&
       (lVar3 = *(longlong *)(lVar3 + 0x18), lVar3 != 0)) {
      uStack_28 = 0;
      uStack_20 = 0;
      pcVar2 = DAT_182ec1698;
      if ((DAT_182ec1698 == (code *)0x0) &&
         (pcVar2 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                        ), pcVar2 == (code *)0x0)) {
        uVar6 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar6,0);
      }
      DAT_182ec1698 = pcVar2;
      (*DAT_182ec1698)(lVar3,&uStack_28);
      uStack_c = uStack_20;
      uStack_14 = (undefined4)uStack_28;
      uStack_10 = (undefined4)((ulonglong)uStack_28 >> 0x20);
      uStack_18 = 1;
      if (lVar4 != 0) {
        *(undefined4 *)(lVar4 + 0x54) = 1;
        *(undefined4 *)(lVar4 + 0x58) = uStack_14;
        *(undefined4 *)(lVar4 + 0x5c) = uStack_10;
        *(undefined4 *)(lVar4 + 0x60) = uStack_20;
        lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        if (lVar4 != 0) {
          if (*(int *)(lVar4 + 0x10) != 0) {
            if (DAT_182eb7aff == '\0') {
              FUN_1802f2810(&DAT_182d58368,0);
              LOCK();
              UNLOCK();
              FUN_1802f2810(&DAT_182d59ac8);
              LOCK();
              UNLOCK();
              FUN_1802f2810(&DAT_182d58398);
              LOCK();
              UNLOCK();
              FUN_1802f2810(&DAT_182d5f2e8);
              LOCK();
              UNLOCK();
              FUN_1802f2810(&DAT_182d5f2e0);
              LOCK();
              UNLOCK();
              DAT_182eb7aff = '\x01';
            }
            lVar4 = FUN_1802c43a0(DAT_182d5f2e0);
            if (lVar4 != 0) {
              *(undefined4 *)(lVar4 + 0x10) = 2;
              if (*(int *)(DAT_182d59ac8 + 0xe0) == 0) {
                FUN_18035c820(DAT_182d59ac8);
              }
              if ((*(char *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 0x18) != '\0') &&
                 (*(int *)(lVar4 + 0x10) != 0)) {
                return;
              }
              if (*(int *)(lVar4 + 0x10) == 1) {
                lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                if (lVar3 == 0) goto LAB_1804bef4a;
                if (*(char *)(lVar3 + 0x10) != '\0') {
                  return;
                }
              }
              if (*(int *)(lVar4 + 0x10) == 2) {
                lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                if (lVar3 == 0) goto LAB_1804bef4a;
                if (*(char *)(lVar3 + 0x11) != '\0') {
                  return;
                }
              }
              if (*(int *)(lVar4 + 0x10) == 3) {
                lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                if (lVar3 == 0) goto LAB_1804bef4a;
                if (*(char *)(lVar3 + 0x12) != '\0') {
                  return;
                }
              }
              if (*(int *)(lVar4 + 0x10) == 4) {
                lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                if (lVar3 == 0) goto LAB_1804bef4a;
                if (*(char *)(lVar3 + 0x13) != '\0') {
                  return;
                }
              }
              if (*(int *)(lVar4 + 0x10) == 5) {
                lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                if (lVar3 == 0) goto LAB_1804bef4a;
                if (*(char *)(lVar3 + 0x14) != '\0') {
                  return;
                }
              }
              if (*(int *)(lVar4 + 0x10) == 6) {
                lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                if (lVar3 == 0) goto LAB_1804bef4a;
                if (*(char *)(lVar3 + 0x15) != '\0') {
                  return;
                }
              }
              if (*(int *)(lVar4 + 0x10) == 7) {
                lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                if (lVar3 == 0) goto LAB_1804bef4a;
                if (*(char *)(lVar3 + 0x16) != '\0') {
                  return;
                }
              }
              if (*(int *)(lVar4 + 0x10) == 8) {
                lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                if (lVar3 == 0) goto LAB_1804bef4a;
                if (*(char *)(lVar3 + 0x17) != '\0') {
                  return;
                }
              }
              if (*(int *)(lVar4 + 0x10) == 9) {
                lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                if (lVar3 == 0) goto LAB_1804bef4a;
                if (*(char *)(lVar3 + 0x18) != '\0') {
                  return;
                }
              }
              if (*(int *)(lVar4 + 0x10) == 10) {
                lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                if (lVar3 == 0) goto LAB_1804bef4a;
                if (*(char *)(lVar3 + 0x19) != '\0') {
                  return;
                }
              }
              if (*(int *)(lVar4 + 0x10) == 0xb) {
                lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                if (lVar3 == 0) goto LAB_1804bef4a;
                if (*(char *)(lVar3 + 0x1a) != '\0') {
                  return;
                }
              }
              if (*(int *)(lVar4 + 0x10) == 0xc) {
                lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                if (lVar3 == 0) goto LAB_1804bef4a;
                if (*(char *)(lVar3 + 0x1b) != '\0') {
                  return;
                }
              }
              if (*(int *)(lVar4 + 0x10) == 0xd) {
                lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                if (lVar3 == 0) goto LAB_1804bef4a;
                if (*(char *)(lVar3 + 0x1c) != '\0') {
                  return;
                }
              }
              if (*(int *)(lVar4 + 0x10) == 0xe) {
                lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                if (lVar3 == 0) goto LAB_1804bef4a;
                if (*(char *)(lVar3 + 0x1d) != '\0') {
                  return;
                }
              }
              lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
              if (*(int *)(lVar4 + 0x10) == 1) {
                if (lVar3 == 0) goto LAB_1804bef4a;
                *(undefined1 *)(lVar3 + 0x10) = 1;
              }
              if (*(int *)(lVar4 + 0x10) == 2) {
                if (lVar3 == 0) goto LAB_1804bef4a;
                *(undefined1 *)(lVar3 + 0x11) = 1;
              }
              if (*(int *)(lVar4 + 0x10) == 3) {
                if (lVar3 == 0) goto LAB_1804bef4a;
                *(undefined1 *)(lVar3 + 0x12) = 1;
              }
              if (*(int *)(lVar4 + 0x10) == 4) {
                if (lVar3 == 0) goto LAB_1804bef4a;
                *(undefined1 *)(lVar3 + 0x13) = 1;
              }
              if (*(int *)(lVar4 + 0x10) == 5) {
                if (lVar3 == 0) goto LAB_1804bef4a;
                *(undefined1 *)(lVar3 + 0x14) = 1;
              }
              if (*(int *)(lVar4 + 0x10) == 6) {
                if (lVar3 == 0) goto LAB_1804bef4a;
                *(undefined1 *)(lVar3 + 0x15) = 1;
              }
              if (*(int *)(lVar4 + 0x10) == 7) {
                if (lVar3 == 0) goto LAB_1804bef4a;
                *(undefined1 *)(lVar3 + 0x16) = 1;
              }
              if (*(int *)(lVar4 + 0x10) == 8) {
                if (lVar3 == 0) goto LAB_1804bef4a;
                *(undefined1 *)(lVar3 + 0x17) = 1;
              }
              if (*(int *)(lVar4 + 0x10) == 9) {
                if (lVar3 == 0) goto LAB_1804bef4a;
                *(undefined1 *)(lVar3 + 0x18) = 1;
              }
              if (*(int *)(lVar4 + 0x10) == 10) {
                if (lVar3 == 0) goto LAB_1804bef4a;
                *(undefined1 *)(lVar3 + 0x19) = 1;
              }
              if (*(int *)(lVar4 + 0x10) == 0xb) {
                if (lVar3 == 0) goto LAB_1804bef4a;
                *(undefined1 *)(lVar3 + 0x1a) = 1;
              }
              if (*(int *)(lVar4 + 0x10) == 0xc) {
                if (lVar3 == 0) goto LAB_1804bef4a;
                *(undefined1 *)(lVar3 + 0x1b) = 1;
              }
              if (*(int *)(lVar4 + 0x10) == 0xd) {
                if (lVar3 == 0) goto LAB_1804bef4a;
                *(undefined1 *)(lVar3 + 0x1c) = 1;
              }
              if (*(int *)(lVar4 + 0x10) == 0xe) {
                if (lVar3 == 0) goto LAB_1804bef4a;
                *(undefined1 *)(lVar3 + 0x1d) = 1;
              }
              if (*(int *)(lVar4 + 0x10) != 0) {
                uVar6 = FUN_1802c43a0(DAT_182d58368);
                FUN_1814df680(uVar6,lVar4,DAT_182d5f2e8,0);
                ExposureUnnoticed2_Scripts_Base_Scheduler__DelayUnscaledTime__0600174c
                          (uVar6,0x3f000000,0);
                return;
              }
              if (DAT_182eb7b03 == '\0') {
                FUN_1802f2810(&DAT_182d58238);
                LOCK();
                UNLOCK();
                FUN_1802f2810(&DAT_182d58380);
                LOCK();
                UNLOCK();
                FUN_1802f2810(&DAT_182d5f2d8);
                LOCK();
                UNLOCK();
                FUN_1802f2810(&DAT_182d5aa70);
                LOCK();
                UNLOCK();
                DAT_182eb7b03 = '\x01';
              }
              if (*(int *)(lVar4 + 0x10) != 0) {
                if (**(longlong **)(DAT_182d5aa70 + 0xb8) == 0) goto LAB_1804bef4a;
                uStack_18 = 0;
                uStack_14 = 0;
                ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
                          (**(longlong **)(DAT_182d5aa70 + 0xb8),0x31,0xbf800000,0);
              }
              if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
                FUN_18035c820(DAT_182d58380);
              }
              if (((**(longlong **)(DAT_182d58238 + 0xb8) != 0) &&
                  (**(longlong **)(DAT_182d58380 + 0xb8) != 0)) &&
                 (plVar5 = (longlong *)
                           ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__Open__060011a0
                                     (**(longlong **)(DAT_182d58380 + 0xb8),
                                      *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 600),1
                                      ,0), plVar5 != (longlong *)0x0)) {
                if ((*(byte *)(DAT_182d5f2d8 + 0x130) <= *(byte *)(*plVar5 + 0x130)) &&
                   (lVar3 = *(longlong *)(*plVar5 + 200),
                   *(longlong *)(lVar3 + -8 + (ulonglong)*(byte *)(DAT_182d5f2d8 + 0x130) * 8) ==
                   DAT_182d5f2d8)) {
                  plVar7 = (longlong *)0x0;
                  if (*(longlong *)(lVar3 + -8 + (ulonglong)*(byte *)(DAT_182d5f2d8 + 0x130) * 8) ==
                      DAT_182d5f2d8) {
                    plVar7 = plVar5;
                  }
                  ExposureUnnoticed2_ObjectUI_TutorialPanel_TutorialPanelView__Initialize__060017eb
                            (plVar7,*(undefined4 *)(lVar4 + 0x10),0);
                  return;
                }
              }
            }
LAB_1804bef4a:
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          if (lVar4 == 0) goto code_r0x0001804a7b24;
          if (0.0 < *(float *)(lVar4 + 0x1b0)) {
            if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
                (lVar4 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar4 == 0))
               || (lVar4 = *(longlong *)(lVar4 + 0xb0), lVar4 == 0)) goto code_r0x0001804a7b24;
            ExposureUnnoticed2_Object3D_Player_Scripts_PlayerSoundManager__PlayPickingSe__06000e25
                      (lVar4,0x15,0);
            lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar4 == 0) goto code_r0x0001804a7b24;
            *(undefined4 *)(lVar4 + 0x1b0) = 0;
            uVar6 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                              (uRam0000000182d5fe48,0);
            ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
                      (uVar6,1,0);
          }
          if (cRam0000000182eb7b53 == '\0') {
            FUN_1802f2810(&DAT_182d58238);
            LOCK();
            UNLOCK();
            FUN_1802f2810(0x182d5e058);
            LOCK();
            UNLOCK();
            FUN_1802f2810(&DAT_182d53c48);
            LOCK();
            UNLOCK();
            FUN_1802f2810(&DAT_182d58380);
            LOCK();
            UNLOCK();
            FUN_1802f2810(0x182d61a48);
            LOCK();
            UNLOCK();
            cRam0000000182eb7b53 = '\x01';
          }
          if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
              (lVar4 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar4 != 0)) &&
             (lVar4 = *(longlong *)(lVar4 + 0x28), lVar4 != 0)) {
            if ((*(int *)(lVar4 + 0x20) == 0) &&
               (*(char *)(*(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30) + 0x38) ==
                '\0')) {
              if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
                 (lVar4 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar4 == 0))
              goto code_r0x0001804a7b24;
              *(undefined1 *)(lVar4 + 0x4c) = 0;
            }
            else {
              if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
                FUN_18035c820(DAT_182d58380);
              }
              if (((**(longlong **)(DAT_182d58238 + 0xb8) == 0) ||
                  (**(longlong **)(DAT_182d58380 + 0xb8) == 0)) ||
                 (plVar5 = (longlong *)
                           ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__Open__060011a0
                                     (**(longlong **)(DAT_182d58380 + 0xb8),
                                      *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x238)
                                      ,0,0), plVar5 == (longlong *)0x0)) goto code_r0x0001804a7b24;
              if ((*(byte *)(*plVar5 + 0x130) < *(byte *)(lRam0000000182d61a48 + 0x130)) ||
                 (lVar4 = *(longlong *)(*plVar5 + 200),
                 *(longlong *)(lVar4 + -8 + (ulonglong)*(byte *)(lRam0000000182d61a48 + 0x130) * 8)
                 != lRam0000000182d61a48)) goto code_r0x0001804a7b24;
              plVar7 = (longlong *)0x0;
              if (*(longlong *)(lVar4 + -8 + (ulonglong)*(byte *)(lRam0000000182d61a48 + 0x130) * 8)
                  == lRam0000000182d61a48) {
                plVar7 = plVar5;
              }
              ExposureUnnoticed2_ObjectUI_ResultPanel_ResultPanelView__Initialize__0600184e
                        (plVar7,0);
            }
            if (**(longlong **)(lRam0000000182d5e190 + 0xb8) != 0) {
              ExposureUnnoticed2_Scripts_Mission_MissionManager__ResetMission__0600146a
                        (**(longlong **)(lRam0000000182d5e190 + 0xb8),0);
              if (*(int *)(lRam0000000182d5feb8 + 0xe0) == 0) {
                FUN_18035c820();
              }
              lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d5feb8 + 0xb8) + 0x10);
              if (lVar4 == 0) {
                if (*(int *)(lRam0000000182d5feb8 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                uVar6 = **(undefined8 **)(lRam0000000182d5feb8 + 0xb8);
                lVar4 = FUN_1802c43a0(DAT_182d58368);
                FUN_1814df680(lVar4,uVar6,uRam0000000182d5fe58,0);
                *(longlong *)(*(longlong *)(lRam0000000182d5feb8 + 0xb8) + 0x10) = lVar4;
                if (DAT_182eb5d50 != 0) {
                  uVar9 = (uint)(*(longlong *)(lRam0000000182d5feb8 + 0xb8) + 0x10U >> 0xc);
                  uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                  do {
                    uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                    LOCK();
                    bVar10 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                    if (bVar10) {
                      *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                           uVar1 | 1L << (ulonglong)(uVar9 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar10);
                }
              }
              if (DAT_182eb7aa2 == '\0') {
                FUN_1802f2810(&DAT_182d5f900,0x40a00000,0);
                LOCK();
                UNLOCK();
                FUN_1802f2810(&DAT_182d5f8f8);
                LOCK();
                UNLOCK();
                DAT_182eb7aa2 = '\x01';
              }
              lVar3 = ExposureUnnoticed2_Scripts_Base_Scheduler__get_Instance__0600174a(0);
              if (lVar3 != 0) {
                lVar3 = *(longlong *)(lVar3 + 0x38);
                uVar6 = FUN_1802c43a0(DAT_182d5f900);
                uStack_28 = 0;
                DelayTimeModel___ctor__06001753(uVar6,lVar4,0x40a00000,1);
                if (lVar3 != 0) {
                  FUN_180006950(lVar3,uVar6);
                  return;
                }
              }
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
          }
        }
      }
    }
  }
code_r0x0001804a7b24:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

