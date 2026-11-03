// Ghidra pseudocode; not original source or compilable C.
// ev_b422a4808b0592222599695a36d8962fe601877651e87c2fbd7578f51a1de6f5

void ExposureUnnoticed2_ObjectUI_BarberMenu_ClosetMenuView___OnClickBack_b__24_0__06001c88
               (longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  code *pcVar6;
  ulonglong uVar7;
  uint uVar8;
  bool bVar9;
  
  if (cRam0000000182eb7dc7 == '\0') {
    FUN_1802f2810(&DAT_182d5aa20);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58380);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61a50);
    LOCK();
    UNLOCK();
    cRam0000000182eb7dc7 = '\x01';
  }
  if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d58380);
  }
  if (**(longlong **)(DAT_182d58380 + 0xb8) != 0) {
    ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__SetVisibleRightDownInfo__060011a5
              (**(longlong **)(DAT_182d58380 + 0xb8),1,0);
    if (**(longlong **)(DAT_182d5aa70 + 0xb8) != 0) {
      ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
                (**(longlong **)(DAT_182d5aa70 + 0xb8),0x32,0xbf800000,0,0);
      if (((((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
            (lVar2 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar2 != 0)) &&
           (lVar2 = *(longlong *)(lVar2 + 0x30), lVar2 != 0)) &&
          ((lVar2 = *(longlong *)(lVar2 + 0x40), lVar2 != 0 &&
           (lVar2 = *(longlong *)(lVar2 + 0x170), lVar2 != 0)))) &&
         ((*(longlong *)(lVar2 + 0x40) != 0 &&
          (lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0x40) + 0x48), lVar3 != 0)))) {
        bVar9 = cRam0000000182eb7e8b == '\0';
        *(undefined4 *)(lVar3 + 0x24) = *(undefined4 *)(lVar2 + 0xb0);
        if (bVar9) {
          FUN_1802f2810(&DAT_182d65318);
          LOCK();
          UNLOCK();
          cRam0000000182eb7e8b = '\x01';
        }
        if (**(longlong **)(DAT_182d65318 + 0xb8) != 0) {
          ExposureUnnoticed2_Object3D_ScenePlops_ClosetLight_ClosetLightController__SetClosetLight__06000b38
                    (**(longlong **)(DAT_182d65318 + 0xb8),0,0);
          if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
              (lVar2 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar2 != 0)) &&
             ((lVar2 = *(longlong *)(lVar2 + 0x30), lVar2 != 0 &&
              ((lVar2 = *(longlong *)(lVar2 + 0x40), lVar2 != 0 &&
               (lVar2 = *(longlong *)(lVar2 + 0x120), lVar2 != 0)))))) {
            ExposureUnnoticed2_Object3D_Player_Scripts_LookAtController__DisableLookAt__06000c10
                      (lVar2,6,0);
            ExposureUnnoticed2_Scripts_InGame_SaveManager__Save__06001601(3,0xffffffff,0,0);
            uVar5 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                              (uRam0000000182d61a50,0);
            ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
                      (uVar5,1,0);
            if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
               ((lVar2 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar2 != 0 &&
                (lVar2 = *(longlong *)(lVar2 + 0x38), lVar2 != 0)))) {
              ExposureUnnoticed2_Object3D_Camera_BaseCameraController__SetInventoryCamera__060011ec
                        (lVar2,0,0,0);
              if ((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
                 ((lVar2 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar2 != 0
                  && (lVar2 = *(longlong *)(lVar2 + 0x1d0), lVar2 != 0)))) {
                ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBoneScaleAdjustManager__ReAdjust__06000ce6
                          (lVar2,0);
                if ((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
                   ((lVar2 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar2 != 0
                    && (lVar2 = *(longlong *)(lVar2 + 0x170), lVar2 != 0)))) {
                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyCustomizeAdjuster__OnChangeCostumeCosplayEvent__06000cc6
                            (lVar2,0,0);
                  *(undefined1 *)(param_1 + 0x58) = 1;
                  if ((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
                     ((lVar2 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40),
                      lVar2 != 0 && (lVar2 = *(longlong *)(lVar2 + 0x48), lVar2 != 0)))) {
                    ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetPreviewNakedArmPose__06000c83
                              (lVar2,0,0);
                    bVar9 = DAT_182eb5d50 != 0;
                    **(undefined8 **)(DAT_182d5aa20 + 0xb8) = 0;
                    if (bVar9) {
                      uVar8 = (uint)(*(ulonglong *)(DAT_182d5aa20 + 0xb8) >> 0xc);
                      uVar7 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
                      do {
                        uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
                        LOCK();
                        bVar9 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
                        if (bVar9) {
                          *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8) = uVar4 | 1L << (uVar8 & 0x3f);
                        }
                        UNLOCK();
                      } while (!bVar9);
                    }
                    ExposureUnnoticed2_ObjectUI_BarberMenu_ClosetMenuView__RefreshEquipment__06001c84
                              (param_1,0);
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
                      uVar5 = FUN_1802c43a0(DAT_182d58368);
                      FUN_1814df680(uVar5,param_1,DAT_182d69200,0);
                      ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b(uVar5,1,0);
                      lVar2 = *(longlong *)(param_1 + 0x38);
                      if (*(int *)(DAT_182d5f3b8 + 0xe0) == 0) {
                        FUN_18035c820(DAT_182d5f3b8);
                      }
                      if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
                        FUN_18031dad0();
                      }
                      uVar1 = **(undefined4 **)(DAT_182d5f3b8 + 0xb8);
                      pcVar6 = DAT_182ebf368;
                      if ((DAT_182ebf368 == (code *)0x0) &&
                         (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Animator::SetTriggerID(System.Int32)"
                                                  ), pcVar6 == (code *)0x0)) {
                        uVar5 = FUN_1802ced60("UnityEngine.Animator::SetTriggerID(System.Int32)");
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar5,0);
                      }
                      DAT_182ebf368 = pcVar6;
                      (*DAT_182ebf368)(lVar2,uVar1);
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
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

