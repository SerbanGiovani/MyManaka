// Ghidra pseudocode; not original source or compilable C.
// ev_705aa774b5b8e70072b454e4e93cb7b0e3716985c6095cfebdd2aaf608587193

void ExposureUnnoticed2_ObjectUI_SkillPanel_SkillItemView__OnClickReinforce__06001831
               (longlong param_1)

{
  longlong lVar1;
  char cVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 uVar5;
  longlong *plVar6;
  
  if (cRam0000000182eb7b39 == '\0') {
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58080);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61b78);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b39 = '\x01';
  }
  if ((*(char *)(param_1 + 0x98) == '\0') && (*(char *)(param_1 + 0x99) == '\0')) {
    cVar2 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsEnoughRp__0600152e
                      (*(undefined4 *)(param_1 + 0x78),0);
    if (cVar2 != '\0') {
      if (**(longlong **)(DAT_182d5aa70 + 0xb8) != 0) {
        ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
                  (**(longlong **)(DAT_182d5aa70 + 0xb8),0x31,0xbf800000,0,0);
        ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ConsumeRp__0600152f
                  (*(undefined4 *)(param_1 + 0x78),0);
        if (*(longlong *)(param_1 + 0x80) != 0) {
          ExposureUnnoticed2_Scripts_InGame_GameStateFacade__RiseSkillLevel__0600152a
                    (*(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x3c),0);
          ExposureUnnoticed2_ObjectUI_SkillPanel_SkillItemView__Refresh__0600182f(param_1,0);
          lVar3 = *(longlong *)(param_1 + 0x88);
          if (lVar3 != 0) {
            (**(code **)(lVar3 + 0x18))
                      (*(undefined8 *)(lVar3 + 0x40),*(undefined8 *)(param_1 + 0x80),
                       *(undefined8 *)(lVar3 + 0x28));
          }
          if (*(int *)(DAT_182d58080 + 0xe0) == 0) {
            FUN_18035c820(DAT_182d58080);
          }
          lVar3 = *(longlong *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x30);
          if ((*(longlong *)(param_1 + 0x80) != 0) && (lVar3 != 0)) {
            *(undefined4 *)(lVar3 + 0x10) = *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x3c);
            uVar5 = *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x30);
            if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
              FUN_18035c820();
            }
            ExposureUnnoticed2_Scripts_Base_EventManager__Broadcast__06001716(uVar5,0);
            if (*(longlong *)(param_1 + 0x80) != 0) {
              if (*(int *)(*(longlong *)(param_1 + 0x80) + 0x3c) != 0x11) {
                return;
              }
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
              lVar3 = FUN_1802c43a0(DAT_182d5f2e0);
              if (lVar3 != 0) {
                *(undefined4 *)(lVar3 + 0x10) = 0xc;
                if (*(int *)(DAT_182d59ac8 + 0xe0) == 0) {
                  FUN_18035c820(DAT_182d59ac8);
                }
                if ((*(char *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 0x18) != '\0') &&
                   (*(int *)(lVar3 + 0x10) != 0)) {
                  return;
                }
                if (*(int *)(lVar3 + 0x10) == 1) {
                  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  if (*(char *)(lVar1 + 0x10) != '\0') {
                    return;
                  }
                }
                if (*(int *)(lVar3 + 0x10) == 2) {
                  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  if (*(char *)(lVar1 + 0x11) != '\0') {
                    return;
                  }
                }
                if (*(int *)(lVar3 + 0x10) == 3) {
                  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  if (*(char *)(lVar1 + 0x12) != '\0') {
                    return;
                  }
                }
                if (*(int *)(lVar3 + 0x10) == 4) {
                  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  if (*(char *)(lVar1 + 0x13) != '\0') {
                    return;
                  }
                }
                if (*(int *)(lVar3 + 0x10) == 5) {
                  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  if (*(char *)(lVar1 + 0x14) != '\0') {
                    return;
                  }
                }
                if (*(int *)(lVar3 + 0x10) == 6) {
                  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  if (*(char *)(lVar1 + 0x15) != '\0') {
                    return;
                  }
                }
                if (*(int *)(lVar3 + 0x10) == 7) {
                  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  if (*(char *)(lVar1 + 0x16) != '\0') {
                    return;
                  }
                }
                if (*(int *)(lVar3 + 0x10) == 8) {
                  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  if (*(char *)(lVar1 + 0x17) != '\0') {
                    return;
                  }
                }
                if (*(int *)(lVar3 + 0x10) == 9) {
                  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  if (*(char *)(lVar1 + 0x18) != '\0') {
                    return;
                  }
                }
                if (*(int *)(lVar3 + 0x10) == 10) {
                  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  if (*(char *)(lVar1 + 0x19) != '\0') {
                    return;
                  }
                }
                if (*(int *)(lVar3 + 0x10) == 0xb) {
                  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  if (*(char *)(lVar1 + 0x1a) != '\0') {
                    return;
                  }
                }
                if (*(int *)(lVar3 + 0x10) == 0xc) {
                  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  if (*(char *)(lVar1 + 0x1b) != '\0') {
                    return;
                  }
                }
                if (*(int *)(lVar3 + 0x10) == 0xd) {
                  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  if (*(char *)(lVar1 + 0x1c) != '\0') {
                    return;
                  }
                }
                if (*(int *)(lVar3 + 0x10) == 0xe) {
                  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  if (*(char *)(lVar1 + 0x1d) != '\0') {
                    return;
                  }
                }
                lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40);
                if (*(int *)(lVar3 + 0x10) == 1) {
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  *(undefined1 *)(lVar1 + 0x10) = 1;
                }
                if (*(int *)(lVar3 + 0x10) == 2) {
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  *(undefined1 *)(lVar1 + 0x11) = 1;
                }
                if (*(int *)(lVar3 + 0x10) == 3) {
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  *(undefined1 *)(lVar1 + 0x12) = 1;
                }
                if (*(int *)(lVar3 + 0x10) == 4) {
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  *(undefined1 *)(lVar1 + 0x13) = 1;
                }
                if (*(int *)(lVar3 + 0x10) == 5) {
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  *(undefined1 *)(lVar1 + 0x14) = 1;
                }
                if (*(int *)(lVar3 + 0x10) == 6) {
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  *(undefined1 *)(lVar1 + 0x15) = 1;
                }
                if (*(int *)(lVar3 + 0x10) == 7) {
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  *(undefined1 *)(lVar1 + 0x16) = 1;
                }
                if (*(int *)(lVar3 + 0x10) == 8) {
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  *(undefined1 *)(lVar1 + 0x17) = 1;
                }
                if (*(int *)(lVar3 + 0x10) == 9) {
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  *(undefined1 *)(lVar1 + 0x18) = 1;
                }
                if (*(int *)(lVar3 + 0x10) == 10) {
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  *(undefined1 *)(lVar1 + 0x19) = 1;
                }
                if (*(int *)(lVar3 + 0x10) == 0xb) {
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  *(undefined1 *)(lVar1 + 0x1a) = 1;
                }
                if (*(int *)(lVar3 + 0x10) == 0xc) {
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  *(undefined1 *)(lVar1 + 0x1b) = 1;
                }
                if (*(int *)(lVar3 + 0x10) == 0xd) {
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  *(undefined1 *)(lVar1 + 0x1c) = 1;
                }
                if (*(int *)(lVar3 + 0x10) == 0xe) {
                  if (lVar1 == 0) goto LAB_1804bef4a;
                  *(undefined1 *)(lVar1 + 0x1d) = 1;
                }
                if (*(int *)(lVar3 + 0x10) != 0) {
                  uVar5 = FUN_1802c43a0(DAT_182d58368);
                  FUN_1814df680(uVar5,lVar3,DAT_182d5f2e8,0);
                  ExposureUnnoticed2_Scripts_Base_Scheduler__DelayUnscaledTime__0600174c
                            (uVar5,0x3f000000,0);
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
                if (*(int *)(lVar3 + 0x10) != 0) {
                  if (**(longlong **)(DAT_182d5aa70 + 0xb8) == 0) goto LAB_1804bef4a;
                  ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
                            (**(longlong **)(DAT_182d5aa70 + 0xb8),0x31,0xbf800000,0,0);
                }
                if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
                  FUN_18035c820(DAT_182d58380);
                }
                if (((**(longlong **)(DAT_182d58238 + 0xb8) != 0) &&
                    (**(longlong **)(DAT_182d58380 + 0xb8) != 0)) &&
                   (plVar4 = (longlong *)
                             ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__Open__060011a0
                                       (**(longlong **)(DAT_182d58380 + 0xb8),
                                        *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 600)
                                        ,1,0), plVar4 != (longlong *)0x0)) {
                  if ((*(byte *)(DAT_182d5f2d8 + 0x130) <= *(byte *)(*plVar4 + 0x130)) &&
                     (lVar1 = *(longlong *)(*plVar4 + 200),
                     *(longlong *)(lVar1 + -8 + (ulonglong)*(byte *)(DAT_182d5f2d8 + 0x130) * 8) ==
                     DAT_182d5f2d8)) {
                    plVar6 = (longlong *)0x0;
                    if (*(longlong *)(lVar1 + -8 + (ulonglong)*(byte *)(DAT_182d5f2d8 + 0x130) * 8)
                        == DAT_182d5f2d8) {
                      plVar6 = plVar4;
                    }
                    ExposureUnnoticed2_ObjectUI_TutorialPanel_TutorialPanelView__Initialize__060017eb
                              (plVar6,*(undefined4 *)(lVar3 + 0x10),0);
                    return;
                  }
                }
              }
LAB_1804bef4a:
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
          }
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    uVar5 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d61b78,0);
    ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
              (uVar5,0,0);
  }
  return;
}

