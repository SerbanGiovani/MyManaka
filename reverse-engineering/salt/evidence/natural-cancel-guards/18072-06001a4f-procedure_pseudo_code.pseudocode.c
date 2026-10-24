// Ghidra pseudocode; not original source or compilable C.
// ev_b60e5cbd3034e514cac80edf284bc293bebf15ea862b81efdf063ac110628324

void ExposureUnnoticed2_ObjectUI_InGameMenu_InGameMenuView__OnClickFastTravel__06001a4f
               (longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong *plVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  float fVar13;
  longlong lStack_70;
  undefined *puStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  longlong lStack_48;
  undefined *puStack_40;
  undefined8 uStack_38;
  longlong lStack_30;
  undefined8 uStack_28;
  undefined8 uStack_18;
  
  if (cRam0000000182eb7c88 == '\0') {
    puStack_40 = &UNK_1804fa716;
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    puStack_40 = &UNK_1804fa727;
    FUN_1802f2810(0x182d5e258);
    LOCK();
    UNLOCK();
    puStack_40 = &UNK_1804fa738;
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    puStack_40 = &UNK_1804fa749;
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    puStack_40 = &UNK_1804fa75a;
    FUN_1802f2810(0x182d62810);
    LOCK();
    UNLOCK();
    puStack_40 = &UNK_1804fa76b;
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    puStack_40 = &UNK_1804fa77c;
    FUN_1802f2810(0x182d5e260);
    LOCK();
    UNLOCK();
    puStack_40 = &UNK_1804fa78d;
    FUN_1802f2810(&DAT_182d5aa70);
    LOCK();
    UNLOCK();
    puStack_40 = &UNK_1804fa79e;
    FUN_1802f2810(0x182d62808);
    LOCK();
    UNLOCK();
    puStack_40 = &UNK_1804fa7af;
    FUN_1802f2810(0x182d62800);
    LOCK();
    UNLOCK();
    puStack_40 = &UNK_1804fa7c0;
    FUN_1802f2810(0x182d627f8);
    LOCK();
    UNLOCK();
    puStack_40 = &UNK_1804fa7d1;
    FUN_1802f2810(0x182d627f0);
    LOCK();
    UNLOCK();
    puStack_40 = &UNK_1804fa7e2;
    FUN_1802f2810(0x182d62888);
    LOCK();
    UNLOCK();
    puStack_40 = &UNK_1804fa7f3;
    FUN_1802f2810(0x182d62878);
    LOCK();
    UNLOCK();
    puStack_40 = &UNK_1804fa804;
    FUN_1802f2810(0x182d62848);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c88 = '\x01';
  }
  lVar5 = **(longlong **)(DAT_182d58230 + 0xb8);
  if (lVar5 == 0) goto code_r0x0001804fac36;
  if (DAT_182eb83fe == '\0') {
    puStack_40 = &UNK_1804fa844;
    FUN_1802f2810(&DAT_182d3e668);
    LOCK();
    UNLOCK();
    puStack_40 = &UNK_1804fa855;
    FUN_1802f2810(&DAT_182d3e660);
    LOCK();
    UNLOCK();
    puStack_40 = &UNK_1804fa866;
    FUN_1802f2810(&DAT_182d5e118);
    LOCK();
    UNLOCK();
    DAT_182eb83fe = '\x01';
  }
  puStack_40 = &UNK_1804fa879;
  cVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsAttachSomeHandcuffs__0600155d(0);
  uVar8 = DAT_182d3e660;
  if (cVar3 == '\0') {
    if ((*(longlong *)(lVar5 + 0x10) == 0) ||
       (lVar7 = *(longlong *)(*(longlong *)(lVar5 + 0x10) + 0x60), lVar7 == 0))
    goto code_r0x0001804fac36;
    uVar8 = DAT_182d3e668;
    if (*(char *)(lVar7 + 0x1b) == '\0') {
      if (*(longlong *)(lVar7 + 0x48) == 0) goto code_r0x0001804fac36;
      uVar8 = DAT_182d5e118;
      if (((*(int *)(*(longlong *)(lVar7 + 0x48) + 0x18) == -1) &&
          (lVar5 = *(longlong *)(*(longlong *)(lVar5 + 0x10) + 0x60), *(int *)(lVar5 + 0x5c) == 0))
         && (*(char *)(lVar5 + 0x50) == '\0')) {
        puStack_40 = &UNK_1804fa8dd;
        lVar5 = FUN_180436330();
        if (lVar5 == 0) goto code_r0x0001804fac36;
        uVar8 = DAT_182d5e118;
        if (*(char *)(lVar5 + 0x10) == '\0') {
          uVar8 = uRam0000000182d627f0;
          if (*(char *)(param_1 + 0x8e) == '\0') {
            if (**(longlong **)(lRam0000000182d5e258 + 0xb8) == 0) {
code_r0x0001804fac36:
                    /* WARNING: Subroutine does not return */
              puStack_40 = &UNK_1804fac3b;
              FUN_18031dad0();
            }
            if (cRam0000000182eb7962 == '\0') {
              puStack_40 = &UNK_1804fa92a;
              FUN_1802f2810(&DAT_182d58398);
              LOCK();
              UNLOCK();
              cRam0000000182eb7962 = '\x01';
            }
            lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar5 == 0) goto code_r0x0001804fac36;
            uVar8 = uRam0000000182d62808;
            if (*(int *)(lVar5 + 0xbc) == -1) {
              if (**(longlong **)(lRam0000000182d5e260 + 0xb8) == 0) goto code_r0x0001804fac36;
              uVar8 = uRam0000000182d62848;
              if (*(char *)(**(longlong **)(lRam0000000182d5e260 + 0xb8) + 0x10) == '\0') {
                puStack_40 = &UNK_1804fa98d;
                cVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525
                                  (0xe);
                uVar8 = uRam0000000182d62800;
                if (cVar3 == '\0') {
                  if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
                     (lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30),
                     lVar5 == 0)) goto code_r0x0001804fac36;
                  uVar8 = uRam0000000182d62888;
                  if (*(char *)(lVar5 + 0x14) == '\0') {
                    puStack_40 = &UNK_1804fa9cb;
                    lVar5 = FUN_18041a620();
                    if (lVar5 == 0) goto code_r0x0001804fac36;
                    puStack_40 = &UNK_1804fa9de;
                    fVar13 = (float)ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__GetMinPureStrange__060010a1
                                              (lVar5);
                    uVar8 = uRam0000000182d62878;
                    if (fVar13 <= 0.0) {
                      if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x0001804fac36;
                      puStack_40 = &UNK_1804faa0b;
                      iVar4 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                                        (**(longlong **)(DAT_182d58230 + 0xb8),0);
                      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
                        puStack_40 = &UNK_1804faa22;
                        FUN_18035c820();
                      }
                      uVar8 = uRam0000000182d627f8;
                      if (iVar4 == 1) {
                        if (**(longlong **)(DAT_182d5aa70 + 0xb8) != 0) {
                          uStack_18 = 0;
                          puStack_40 = &UNK_1804faa72;
                          ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
                                    (**(longlong **)(DAT_182d5aa70 + 0xb8),0x31,0xbf800000,0);
                          *(undefined1 *)(param_1 + 0x8c) = 1;
                          puStack_40 = &UNK_1804faa85;
                          lVar5 = FUN_1802c43a0(DAT_182d58368);
                          puStack_40 = &UNK_1804faa9d;
                          FUN_1814df680(lVar5,param_1,uRam0000000182d62810,0);
                          if (cRam0000000182eb7d08 == '\0') {
                            puStack_40 = &UNK_1804faab1;
                            FUN_1802f2810(&DAT_182d58238);
                            LOCK();
                            UNLOCK();
                            puStack_40 = &UNK_1804faac1;
                            FUN_1802f2810(0x182d64620);
                            LOCK();
                            UNLOCK();
                            puStack_40 = &UNK_1804faad1;
                            FUN_1802f2810(&DAT_182d58380);
                            LOCK();
                            UNLOCK();
                            cRam0000000182eb7d08 = '\x01';
                          }
                          if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
                            puStack_40 = &UNK_1804faaf3;
                            FUN_18035c820(DAT_182d58380);
                          }
                          if ((**(longlong **)(DAT_182d58238 + 0xb8) != 0) &&
                             (**(longlong **)(DAT_182d58380 + 0xb8) != 0)) {
                            puStack_40 = &UNK_1804fab39;
                            plVar6 = (longlong *)
                                     ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__Open__060011a0
                                               (**(longlong **)(DAT_182d58380 + 0xb8),
                                                *(undefined8 *)
                                                 (**(longlong **)(DAT_182d58238 + 0xb8) + 0x208),0,0
                                               );
                            if (plVar6 != (longlong *)0x0) {
                              if ((*(byte *)(lRam0000000182d64620 + 0x130) <=
                                   *(byte *)(*plVar6 + 0x130)) &&
                                 (lVar7 = *(longlong *)(*plVar6 + 200),
                                 *(longlong *)
                                  (lVar7 + -8 +
                                  (ulonglong)*(byte *)(lRam0000000182d64620 + 0x130) * 8) ==
                                 lRam0000000182d64620)) {
                                plVar9 = (longlong *)0x0;
                                if (*(longlong *)
                                     (lVar7 + -8 +
                                     (ulonglong)*(byte *)(lRam0000000182d64620 + 0x130) * 8) ==
                                    lRam0000000182d64620) {
                                  plVar9 = plVar6;
                                }
                                if (cRam0000000182eb7d02 == '\0') {
                                  FUN_1802f2810(0x182d64660,lVar5,0);
                                  LOCK();
                                  UNLOCK();
                                  FUN_1802f2810(0x182d5e098);
                                  LOCK();
                                  UNLOCK();
                                  FUN_1802f2810(0x182d5e0a8);
                                  LOCK();
                                  UNLOCK();
                                  FUN_1802f2810(0x182d5e078);
                                  LOCK();
                                  UNLOCK();
                                  FUN_1802f2810(0x182d5e070);
                                  LOCK();
                                  UNLOCK();
                                  FUN_1802f2810(&DAT_182d58288);
                                  LOCK();
                                  UNLOCK();
                                  FUN_1802f2810(0x182d64658);
                                  LOCK();
                                  UNLOCK();
                                  FUN_1802f2810(0x182d64650);
                                  LOCK();
                                  UNLOCK();
                                  FUN_1802f2810(&DAT_182d58398);
                                  LOCK();
                                  UNLOCK();
                                  FUN_1802f2810(0x182d5e048);
                                  LOCK();
                                  UNLOCK();
                                  FUN_1802f2810(&DAT_182d5e040);
                                  LOCK();
                                  UNLOCK();
                                  FUN_1802f2810(&DAT_182d54d90);
                                  LOCK();
                                  UNLOCK();
                                  FUN_1802f2810(&DAT_182d53aa8);
                                  LOCK();
                                  UNLOCK();
                                  cRam0000000182eb7d02 = '\x01';
                                }
                                plVar9[6] = lVar5;
                                if (DAT_182eb5d50 != 0) {
                                  uVar10 = (uint)((ulonglong)(plVar9 + 6) >> 0xc);
                                  lVar5 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
                                  do {
                                    uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
                                    LOCK();
                                    bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
                                    if (bVar11) {
                                      *(ulonglong *)(&DAT_182f0c920 + lVar5) =
                                           uVar1 | 1L << (ulonglong)(uVar10 & 0x3f);
                                    }
                                    UNLOCK();
                                  } while (!bVar11);
                                }
                                lVar5 = plVar9[0xb];
                                if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
                                  FUN_18035c820();
                                }
                                ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DestroyChildren__0600172c
                                          (lVar5,0);
                                bVar11 = true;
                                if (cRam0000000182eb7870 == '\0') {
                                  FUN_1802f2810(&DAT_182d5c348);
                                  LOCK();
                                  UNLOCK();
                                  cRam0000000182eb7870 = '\x01';
                                }
                                ExposureUnnoticed2_Master_FastTravel_MFastTravel__CheckInitialize__0600129d
                                          (0);
                                lVar5 = **(longlong **)(DAT_182d5c348 + 0xb8);
                                if (lVar5 != 0) {
                                  uStack_60 = 0;
                                  uStack_58 = 0;
                                  if (DAT_182eb5d50 != 0) {
                                    uVar10 = (uint)((ulonglong)&lStack_70 >> 0xc);
                                    lVar7 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
                                    do {
                                      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar7);
                                      LOCK();
                                      bVar12 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar7);
                                      if (bVar12) {
                                        *(ulonglong *)(&DAT_182f0c920 + lVar7) =
                                             uVar1 | 1L << (ulonglong)(uVar10 & 0x3f);
                                      }
                                      UNLOCK();
                                    } while (!bVar12);
                                  }
                                  puStack_68 = (undefined *)(ulonglong)*(uint *)(lVar5 + 0x2c);
                                  uStack_50 = 2;
                                  puStack_40 = puStack_68;
                                  uStack_38 = 0;
                                  lStack_30 = 0;
                                  uStack_28 = 2;
                                  lStack_70 = lVar5;
                                  lStack_48 = lVar5;
                                  while (cVar3 = FUN_180f89450(&lStack_48,uRam0000000182d5e078),
                                        lVar5 = lStack_30, cVar3 != '\0') {
                                    lVar7 = *(longlong *)
                                             (*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                                    if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
                                      FUN_18031dad0();
                                    }
                                    lVar7 = *(longlong *)(lVar7 + 0x38);
                                    if (lStack_30 == 0) {
                    /* WARNING: Subroutine does not return */
                                      FUN_18031dad0();
                                    }
                                    if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
                                      FUN_18031dad0(0,*(undefined4 *)(lStack_30 + 0x34));
                                    }
                                    if ((*(int *)(lVar7 + 0x18) != 0) &&
                                       (iVar4 = FUN_1800b27d0(*(undefined8 *)(lVar7 + 0x10),
                                                              *(undefined4 *)(lStack_30 + 0x34),0,
                                                              *(undefined4 *)(lVar7 + 0x18),
                                                              *(undefined8 *)
                                                               (*(longlong *)
                                                                 (*(longlong *)
                                                                   (*(longlong *)
                                                                     (*(longlong *)
                                                                       (*(longlong *)
                                                                         (DAT_182d5e040 + 0x20) +
                                                                       0xc0) + 0xd0) + 0x20) + 0xc0)
                                                               + 0x148)), iVar4 != -1)) {
                                      lVar7 = plVar9[0xc];
                                      lVar2 = plVar9[0xb];
                                      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                                        FUN_18035c820();
                                      }
                                      lVar7 = FUN_1809f1050(lVar7,lVar2,DAT_182d54d90);
                                      if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
                                        FUN_18031dad0();
                                      }
                                      lVar7 = FUN_1809a08f0(lVar7,uRam0000000182d64650);
                                      uVar8 = FUN_1802c43a0(uRam0000000182d64660);
                                      FUN_180665bb0(uVar8,plVar9,uRam0000000182d64658);
                                      if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
                                        FUN_18031dad0();
                                      }
                                      Common_CommonUI_CommonButton_FastTravelPanelItemView__Initialize__06001e60
                                                (lVar7,lVar5,uVar8);
                                      if (bVar11) {
                                        bVar11 = false;
                                        plVar9[0x12] = lVar5;
                                        FUN_18031d480(plVar9 + 0x12);
                                        ExposureUnnoticed2_ObjectUI_FastTravelPanel_FastTravelPanelView__OnClickItem__06001b3b
                                                  (plVar9,lVar5,0);
                                      }
                                    }
                                  }
                                  if (plVar9[0xe] != 0) {
                                    HadakaCoat_ObjectsUi_Common_Button_ButtonGroupManager__ReSearchButton__06001de5
                                              (plVar9[0xe],0,1,0);
                                    ExposureUnnoticed2_ObjectUI_FastTravelPanel_FastTravelPanelView__ToPadModeIfNeed__06001b38
                                              (plVar9,0);
                                    return;
                                  }
                                }
                    /* WARNING: Subroutine does not return */
                                FUN_18031dad0();
                              }
                            }
                          }
                        }
                        goto code_r0x0001804fac36;
                      }
                    }
                  }
                }
              }
            }
          }
          puStack_40 = &UNK_1804fabf1;
          uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar8);
          goto code_r0x0001804fabf6;
        }
      }
    }
  }
  puStack_40 = &UNK_1804fac2d;
  uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar8,0);
code_r0x0001804fabf6:
  if (DAT_182eb7ce7 == '\0') {
    puStack_40 = (undefined *)0x18050c454;
    FUN_1802f2810(&DAT_182d58398,0,0);
    LOCK();
    UNLOCK();
    puStack_40 = (undefined *)0x18050c465;
    FUN_1802f2810(&DAT_182d647e0);
    LOCK();
    UNLOCK();
    puStack_40 = (undefined *)0x18050c476;
    FUN_1802f2810(&DAT_182d5aa70);
    LOCK();
    UNLOCK();
    DAT_182eb7ce7 = '\x01';
  }
  lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
  if (lVar5 != 0) {
    if (*(char *)(lVar5 + 0x36) == '\0') {
      return;
    }
    if (**(longlong **)(DAT_182d647e0 + 0xb8) != 0) {
      puStack_40 = (undefined *)0x18050c4c3;
      ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessageInstance__06001b13
                (**(longlong **)(DAT_182d647e0 + 0xb8),uVar8,0,0);
      if (**(longlong **)(DAT_182d5aa70 + 0xb8) != 0) {
        uStack_18 = 0;
        puStack_40 = (undefined *)0x18050c4fb;
        ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
                  (**(longlong **)(DAT_182d5aa70 + 0xb8),0x45,0xbf800000,0);
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  puStack_40 = &UNK_18050c50b;
  FUN_18031dad0();
}

