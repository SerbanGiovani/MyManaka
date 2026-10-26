// Ghidra pseudocode; not original source or compilable C.
// ev_85f6aa883c974a647f25ab7f0b9d99707e23c557efcb01877cbb9c9fd246f11e

void ExposureUnnoticed2_Object3D_ScenePlops_WasherMachine_WasherMachineController__OnInteract__06000a3f
               (longlong param_1)

{
  ulonglong *puVar1;
  undefined4 uVar2;
  int iVar3;
  ulonglong uVar4;
  char cVar5;
  longlong lVar6;
  undefined1 *puVar7;
  longlong *plVar8;
  code *pcVar9;
  longlong lVar10;
  undefined8 uVar11;
  longlong *plVar12;
  uint uVar13;
  undefined1 *puVar14;
  undefined8 unaff_RDI;
  ulonglong uVar15;
  longlong lVar16;
  bool bVar17;
  
  if (cRam0000000182eb8246 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6c178);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6c180);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6c170);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6c168);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6c160);
    LOCK();
    UNLOCK();
    cRam0000000182eb8246 = '\x01';
  }
  if (*(char *)(param_1 + 0x48) != '\0') {
    uVar11 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(DAT_182d6c180);
    goto code_r0x00018050c430;
  }
  if (**(longlong **)(DAT_182d58378 + 0xb8) != 0) {
    if (DAT_182eb79c1 == '\0') {
      FUN_1802f2810(&DAT_182d58398);
      LOCK();
      UNLOCK();
      DAT_182eb79c1 = '\x01';
    }
    lVar10 = ExposureUnnoticed2_Master_RankRelease_MRankRelease__Get__0600125c(3,0);
    if (((lVar10 != 0) &&
        (lVar10 = ExposureUnnoticed2_Master_Rank_MRank__GetByRank__06001262
                            (*(undefined4 *)(lVar10 + 0x38),0), lVar10 != 0)) &&
       (lVar16 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48), lVar16 != 0)) {
      if (*(int *)(lVar16 + 0x1e8) < *(int *)(lVar10 + 0x28)) {
        uVar11 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d6c160);
      }
      else if ((*(char *)(*(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48) + 0x20) == '\0')
              || (cVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsRelease__0600155e(6),
                 cVar5 != '\0')) {
        lVar10 = **(longlong **)(DAT_182d58230 + 0xb8);
        if (lVar10 == 0) goto DAT_1805f6d25;
        if (DAT_182eb83fe == '\0') {
          FUN_1802f2810(&DAT_182d3e668);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d3e660);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d5e118);
          LOCK();
          UNLOCK();
          DAT_182eb83fe = '\x01';
        }
        cVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsAttachSomeHandcuffs__0600155d
                          (0);
        if (cVar5 == '\0') {
          if ((*(longlong *)(lVar10 + 0x10) == 0) ||
             (lVar16 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x60), lVar16 == 0))
          goto DAT_1805f6d25;
          if (*(char *)(lVar16 + 0x1b) == '\0') {
            if (*(longlong *)(lVar16 + 0x48) == 0) goto DAT_1805f6d25;
            if (((*(int *)(*(longlong *)(lVar16 + 0x48) + 0x18) == -1) &&
                (lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x60),
                *(int *)(lVar10 + 0x5c) == 0)) && (*(char *)(lVar10 + 0x50) == '\0')) {
              lVar10 = FUN_180436330();
              if (lVar10 == 0) goto DAT_1805f6d25;
              if (*(char *)(lVar10 + 0x10) == '\0') {
                iVar3 = *(int *)(param_1 + 0x4c);
                if (iVar3 != 0) {
                  if (iVar3 == 1) {
                    uVar11 = FUN_181618010(&stack0x00000008,0);
                    uVar11 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017b0
                                       (uRam0000000182d6c170,uVar11,0);
                    ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
                              (uVar11,1,0);
                  }
                  else if (iVar3 == 2) {
                    lVar10 = *(longlong *)(param_1 + 0x38);
                    if ((*(longlong *)(param_1 + 0x70) != 0) &&
                       (*(undefined4 *)(*(longlong *)(param_1 + 0x70) + 0x10) = 0x3f800000,
                       lVar10 != 0)) {
                      FUN_181ef43f0();
                      if (cRam0000000182eb8245 == '\0') {
                        FUN_1802f2810(&DAT_182d58230,0,0);
                        LOCK();
                        UNLOCK();
                        FUN_1802f2810(&DAT_182d6c188);
                        LOCK();
                        UNLOCK();
                        cRam0000000182eb8245 = '\x01';
                      }
                      lVar10 = *(longlong *)(param_1 + 0x58);
                      if (*(int *)(DAT_182d6c188 + 0xe0) == 0) {
                        FUN_18035c820(DAT_182d6c188);
                      }
                      if (lVar10 != 0) {
                        uVar2 = *(undefined4 *)(*(longlong *)(DAT_182d6c188 + 0xb8) + 4);
                        pcVar9 = DAT_182ebf368;
                        if ((DAT_182ebf368 == (code *)0x0) &&
                           (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Animator::SetTriggerID(System.Int32)"
                                                  ), pcVar9 == (code *)0x0)) {
                          uVar11 = FUN_1802ced60("UnityEngine.Animator::SetTriggerID(System.Int32)")
                          ;
                    /* WARNING: Subroutine does not return */
                          FUN_1802cca90(uVar11,0);
                        }
                        DAT_182ebf368 = pcVar9;
                        (*DAT_182ebf368)(lVar10,uVar2);
                        lVar10 = *(longlong *)(param_1 + 0x20);
                        lVar16 = **(longlong **)(DAT_182d58230 + 0xb8);
                        if (lVar10 != 0) {
                          pcVar9 = DAT_182ec1080;
                          if ((DAT_182ec1080 == (code *)0x0) &&
                             (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Component::get_transform()"),
                             pcVar9 == (code *)0x0)) {
                            uVar11 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar11,0);
                          }
                          DAT_182ec1080 = pcVar9;
                          uVar11 = (*DAT_182ec1080)(lVar10);
                          if (lVar16 != 0) {
                            ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__SmoothMoveTo__06000d95
                                      (lVar16,uVar11,0);
                            if (((**(longlong **)(DAT_182d58230 + 0xb8) != 0) &&
                                (lVar10 = *(longlong *)
                                           (**(longlong **)(DAT_182d58230 + 0xb8) + 0x10),
                                lVar10 != 0)) &&
                               (lVar10 = *(longlong *)(lVar10 + 0x60), lVar10 != 0)) {
                              *(undefined4 *)(lVar10 + 0x234) = 0x271a;
                              return;
                            }
                          }
                        }
                      }
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                    goto DAT_1805f6d25;
                  }
                  return;
                }
                lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                if (lVar10 == 0) goto DAT_1805f6d25;
                if (*(int *)(lVar10 + 0x19c) == -1) {
                  uVar11 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                     (uRam0000000182d6c168);
                  goto code_r0x00018050c430;
                }
                if (cRam0000000182eb7c79 == '\0') {
                  FUN_1802f2810(&DAT_182d58238);
                  LOCK();
                  UNLOCK();
                  FUN_1802f2810(&DAT_182d58380);
                  LOCK();
                  UNLOCK();
                  FUN_1802f2810(&DAT_182d5a8e8);
                  LOCK();
                  UNLOCK();
                  cRam0000000182eb7c79 = '\x01';
                }
                if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
                  FUN_18035c820(DAT_182d58380);
                }
                if (((**(longlong **)(DAT_182d58238 + 0xb8) != 0) &&
                    (**(longlong **)(DAT_182d58380 + 0xb8) != 0)) &&
                   (plVar8 = (longlong *)
                             ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__Open__060011a0
                                       (**(longlong **)(DAT_182d58380 + 0xb8),
                                        *(undefined8 *)
                                         (**(longlong **)(DAT_182d58238 + 0xb8) + 0x138),0,0),
                   plVar8 != (longlong *)0x0)) {
                  if ((*(byte *)(DAT_182d5a8e8 + 0x130) <= *(byte *)(*plVar8 + 0x130)) &&
                     (lVar10 = *(longlong *)(*plVar8 + 200),
                     *(longlong *)(lVar10 + -8 + (ulonglong)*(byte *)(DAT_182d5a8e8 + 0x130) * 8) ==
                     DAT_182d5a8e8)) {
                    plVar12 = (longlong *)0x0;
                    if (*(longlong *)(lVar10 + -8 + (ulonglong)*(byte *)(DAT_182d5a8e8 + 0x130) * 8)
                        == DAT_182d5a8e8) {
                      plVar12 = plVar8;
                    }
                    if (cRam0000000182eb7c73 == '\0') {
                      FUN_1802f2810(0x182d58138,0);
                      LOCK();
                      UNLOCK();
                      FUN_1802f2810(&DAT_182d58368);
                      LOCK();
                      UNLOCK();
                      FUN_1802f2810(0x182d62a08);
                      LOCK();
                      UNLOCK();
                      FUN_1802f2810(0x182d62a00);
                      LOCK();
                      UNLOCK();
                      FUN_1802f2810(0x182d58130);
                      LOCK();
                      UNLOCK();
                      FUN_1802f2810(&DAT_182d583a0);
                      LOCK();
                      UNLOCK();
                      FUN_1802f2810(&DAT_182d58288);
                      LOCK();
                      UNLOCK();
                      FUN_1802f2810(0x182d5ab80);
                      LOCK();
                      UNLOCK();
                      FUN_1802f2810(0x182d629f8);
                      LOCK();
                      UNLOCK();
                      FUN_1802f2810(0x182d629e8);
                      LOCK();
                      UNLOCK();
                      FUN_1802f2810(0x182d629d8);
                      LOCK();
                      UNLOCK();
                      FUN_1802f2810(0x182d629d0);
                      LOCK();
                      UNLOCK();
                      cRam0000000182eb7c73 = '\x01';
                    }
                    lVar10 = plVar12[0xc];
                    if (*(int *)(lRam0000000182d5ab80 + 0xe0) == 0) {
                      FUN_18035c820(lRam0000000182d5ab80);
                    }
                    lVar16 = *(longlong *)(*(longlong *)(lRam0000000182d5ab80 + 0xb8) + 8);
                    if (((lVar16 != 0) && (lVar16 = *(longlong *)(lVar16 + 0x18), lVar16 != 0)) &&
                       (*(longlong *)(lVar16 + 0x40) != 0)) {
                      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
                        FUN_18035c820();
                      }
                      ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__SetHeight__0600172f
                                (lVar10);
                      lVar10 = *(longlong *)(*(longlong *)(lRam0000000182d5ab80 + 0xb8) + 8);
                      if (((lVar10 != 0) && (lVar10 = *(longlong *)(lVar10 + 0x18), lVar10 != 0)) &&
                         (lVar10 = *(longlong *)(lVar10 + 0x40), lVar10 != 0)) {
                        if (6 < *(int *)(lVar10 + 0x20) - *(int *)(lVar10 + 0x28)) {
                          lVar10 = plVar12[0xc];
                          if (lVar10 == 0) goto code_r0x0001804f779b;
                          pcVar9 = DAT_182ec1600;
                          if ((DAT_182ec1600 == (code *)0x0) &&
                             (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.RectTransform::set_sizeDelta_Injected(UnityEngine.Vector2&)"
                                                  ), pcVar9 == (code *)0x0)) {
                            uVar11 = FUN_1802ced60(
                                                  "UnityEngine.RectTransform::set_sizeDelta_Injected(UnityEngine.Vector2&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar11,0);
                          }
                          DAT_182ec1600 = pcVar9;
                          (*DAT_182ec1600)(lVar10,&stack0x00000008);
                        }
                        lVar10 = plVar12[0xb];
                        uVar13 = 0;
                        if (lVar10 != 0) {
                          lVar16 = 0x20;
                          do {
                            if (*(int *)(lVar10 + 0x18) <= (int)uVar13) {
                              FUN_180503680(plVar12);
                              if (*(int *)(lRam0000000182d629d0 + 0xe0) == 0) {
                                FUN_18035c820();
                              }
                              puVar14 = &LAB_1800c7840;
                              lVar10 = *(longlong *)(*(longlong *)(lRam0000000182d629d0 + 0xb8) + 8)
                              ;
                              if (lVar10 == 0) {
                                if (*(int *)(lRam0000000182d629d0 + 0xe0) == 0) {
                                  FUN_18035c820();
                                }
                                lVar16 = **(longlong **)(lRam0000000182d629d0 + 0xb8);
                                lVar10 = FUN_1802c43a0(DAT_182d58368);
                                lVar6 = lRam0000000182d629d8;
                                bVar17 = DAT_182eb5d50 != 0;
                                *(undefined8 *)(lVar10 + 0x10) =
                                     *(undefined8 *)(lRam0000000182d629d8 + 8);
                                *(longlong *)(lVar10 + 0x28) = lVar6;
                                *(longlong *)(lVar10 + 0x20) = lVar16;
                                if (bVar17) {
                                  uVar13 = (uint)(lVar10 + 0x20U >> 0xc);
                                  uVar15 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                                  do {
                                    uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8);
                                    LOCK();
                                    bVar17 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8);
                                    if (bVar17) {
                                      *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8) =
                                           uVar4 | 1L << (uVar13 & 0x3f);
                                    }
                                    UNLOCK();
                                  } while (!bVar17);
                                }
                                cVar5 = *(char *)(lVar6 + 0x52);
                                *(longlong *)(lVar10 + 0x40) = lVar10;
                                if ((*(byte *)(lVar6 + 0x4c) & 0x10) == 0) {
                                  if (lVar16 == 0) {
                                    uVar11 = FUN_18031daf0();
                    /* WARNING: Subroutine does not return */
                                    FUN_18031da90(uVar11,0);
                                  }
code_r0x0001804f75ad:
                                  *(undefined8 *)(lVar10 + 0x40) = *(undefined8 *)(lVar10 + 0x20);
                                  puVar7 = *(undefined1 **)(lVar10 + 0x10);
                                }
                                else {
                                  if (cVar5 != '\0') goto code_r0x0001804f75ad;
                                  puVar7 = &LAB_1800c7840;
                                }
                                *(undefined1 **)(lVar10 + 0x18) = puVar7;
                                *(code **)(lVar10 + 0x38) = FUN_1801e91e0;
                                *(longlong *)(*(longlong *)(lRam0000000182d629d0 + 0xb8) + 8) =
                                     lVar10;
                                if (DAT_182eb5d50 != 0) {
                                  uVar13 = (uint)(*(longlong *)(lRam0000000182d629d0 + 0xb8) + 8U >>
                                                 0xc);
                                  uVar15 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                                  do {
                                    uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8);
                                    LOCK();
                                    bVar17 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8);
                                    if (bVar17) {
                                      *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8) =
                                           uVar4 | 1L << (uVar13 & 0x3f);
                                    }
                                    UNLOCK();
                                  } while (!bVar17);
                                }
                              }
                              bVar17 = DAT_182eb5d50 != 0;
                              plVar12[6] = lVar10;
                              if (bVar17) {
                                uVar13 = (uint)((ulonglong)(plVar12 + 6) >> 0xc);
                                uVar15 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                                do {
                                  uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8);
                                  LOCK();
                                  bVar17 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8);
                                  if (bVar17) {
                                    *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8) =
                                         uVar4 | 1L << (uVar13 & 0x3f);
                                  }
                                  UNLOCK();
                                } while (!bVar17);
                              }
                              if (plVar12[0xd] != 0) {
                                HadakaCoat_ObjectsUi_Common_Button_ButtonGroupManager__ReSearchButton__06001de5
                                          (plVar12[0xd],0,0,0);
                                uVar11 = FUN_1802c43a0(uRam0000000182d58138);
                                FUN_180665bb0(uVar11,plVar12,uRam0000000182d629f8,0);
                                if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                                  FUN_18035c820();
                                }
                                FUN_180993250(uVar11,0,uRam0000000182d58130);
                                lVar16 = FUN_1802c43a0(DAT_182d58368);
                                lVar10 = lRam0000000182d629e8;
                                bVar17 = DAT_182eb5d50 != 0;
                                *(undefined8 *)(lVar16 + 0x10) =
                                     *(undefined8 *)(lRam0000000182d629e8 + 8);
                                *(longlong *)(lVar16 + 0x28) = lVar10;
                                *(longlong **)(lVar16 + 0x20) = plVar12;
                                if (bVar17) {
                                  uVar13 = (uint)(lVar16 + 0x20U >> 0xc);
                                  uVar15 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
                                  do {
                                    uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8);
                                    LOCK();
                                    bVar17 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8);
                                    if (bVar17) {
                                      *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8) =
                                           uVar4 | 1L << (uVar13 & 0x3f);
                                    }
                                    UNLOCK();
                                  } while (!bVar17);
                                }
                                cVar5 = *(char *)(lVar10 + 0x52);
                                *(longlong *)(lVar16 + 0x40) = lVar16;
                                if (((*(byte *)(lVar10 + 0x4c) & 0x10) == 0) || (cVar5 != '\0')) {
                                  puVar14 = *(undefined1 **)(lVar16 + 0x10);
                                  *(undefined8 *)(lVar16 + 0x40) = *(undefined8 *)(lVar16 + 0x20);
                                }
                                *(undefined1 **)(lVar16 + 0x18) = puVar14;
                                *(code **)(lVar16 + 0x38) = FUN_1801e91e0;
                                if (DAT_182eb7aa1 == '\0') {
                                  FUN_1802f2810(&DAT_182d5f910,1,0,lVar16,unaff_RDI);
                                  LOCK();
                                  UNLOCK();
                                  FUN_1802f2810(&DAT_182d5f908);
                                  LOCK();
                                  UNLOCK();
                                  DAT_182eb7aa1 = '\x01';
                                }
                                lVar10 = ExposureUnnoticed2_Scripts_Base_Scheduler__get_Instance__0600174a
                                                   (0);
                                if (lVar10 != 0) {
                                  lVar10 = *(longlong *)(lVar10 + 0x20);
                                  lVar6 = FUN_1802c43a0(DAT_182d5f910);
                                  bVar17 = DAT_182eb5d50 != 0;
                                  *(longlong *)(lVar6 + 0x10) = lVar16;
                                  if (bVar17) {
                                    uVar13 = (uint)(lVar6 + 0x10U >> 0xc);
                                    puVar1 = (ulonglong *)
                                             (&DAT_182f0c920 +
                                             (ulonglong)((uVar13 & 0x1fffff) >> 6) * 8);
                                    do {
                                      uVar4 = *puVar1;
                                      LOCK();
                                      uVar15 = *puVar1;
                                      if (uVar4 == uVar15) {
                                        *puVar1 = uVar4 | 1L << (uVar13 & 0x3f);
                                      }
                                      UNLOCK();
                                    } while (uVar4 != uVar15);
                                  }
                                  *(undefined4 *)(lVar6 + 0x18) = 1;
                                  if (lVar10 != 0) {
                                    FUN_1800068f0(lVar10,lVar6);
                                    return;
                                  }
                                }
                    /* WARNING: Subroutine does not return */
                                FUN_18031dad0();
                              }
                              break;
                            }
                            if (*(int *)(lRam0000000182d5ab80 + 0xe0) == 0) {
                              FUN_18035c820();
                            }
                            lVar10 = *(longlong *)(*(longlong *)(lRam0000000182d5ab80 + 0xb8) + 8);
                            if (((lVar10 == 0) ||
                                (lVar10 = *(longlong *)(lVar10 + 0x18), lVar10 == 0)) ||
                               (lVar10 = *(longlong *)(lVar10 + 0x40), lVar10 == 0)) break;
                            if ((int)uVar13 < *(int *)(lVar10 + 0x20) - *(int *)(lVar10 + 0x28)) {
                              lVar10 = plVar12[0xb];
                              if (lVar10 == 0) break;
                              if (*(uint *)(lVar10 + 0x18) <= uVar13) goto code_r0x0001804f77b8;
                              lVar10 = *(longlong *)(lVar16 + lVar10);
                              if (*(int *)(lRam0000000182d5ab80 + 0xe0) == 0) {
                                FUN_18035c820();
                              }
                              lVar6 = *(longlong *)(*(longlong *)(lRam0000000182d5ab80 + 0xb8) + 8);
                              if (((lVar6 == 0) || (lVar6 = *(longlong *)(lVar6 + 0x18), lVar6 == 0)
                                  ) || ((lVar6 = *(longlong *)(lVar6 + 0x40), lVar6 == 0 ||
                                        ((lVar6 = FUN_180e51260(lVar6,uVar13), lVar6 == 0 ||
                                         (lVar10 == 0)))))) break;
                              ExposureUnnoticed2_ObjectUI_InteractMenuPanel_InteractMenuItemView__Initialize__06001a2e
                                        (lVar10,*(undefined8 *)(lVar6 + 0x18));
                            }
                            lVar10 = plVar12[0xb];
                            if (lVar10 == 0) break;
                            if (*(uint *)(lVar10 + 0x18) <= uVar13) {
code_r0x0001804f77b8:
                    /* WARNING: Subroutine does not return */
                              FUN_18031dae0();
                            }
                            if (*(longlong *)(lVar16 + lVar10) == 0) break;
                            lVar10 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                                               (*(longlong *)(lVar16 + lVar10),0);
                            if (*(int *)(lRam0000000182d5ab80 + 0xe0) == 0) {
                              FUN_18035c820();
                            }
                            lVar6 = *(longlong *)(*(longlong *)(lRam0000000182d5ab80 + 0xb8) + 8);
                            if ((((lVar6 == 0) || (lVar6 = *(longlong *)(lVar6 + 0x18), lVar6 == 0))
                                || (lVar6 = *(longlong *)(lVar6 + 0x40), lVar6 == 0)) ||
                               (lVar10 == 0)) break;
                            FUN_181f3ea80(lVar10,(int)uVar13 <
                                                 *(int *)(lVar6 + 0x20) - *(int *)(lVar6 + 0x28));
                            lVar10 = plVar12[0xb];
                            uVar13 = uVar13 + 1;
                            lVar16 = lVar16 + 8;
                            if (lVar10 == 0) break;
                          } while( true );
                        }
                      }
                    }
code_r0x0001804f779b:
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                }
                    /* WARNING: Subroutine does not return */
                FUN_18031dad0();
              }
            }
            uVar11 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(DAT_182d5e118,0);
          }
          else {
            uVar11 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(DAT_182d3e668,0);
          }
        }
        else {
          uVar11 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(DAT_182d3e660,0);
        }
      }
      else {
        uVar11 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d6c178);
      }
code_r0x00018050c430:
      if (DAT_182eb7ce7 == '\0') {
        FUN_1802f2810(&DAT_182d58398,0,0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d647e0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d5aa70);
        LOCK();
        UNLOCK();
        DAT_182eb7ce7 = '\x01';
      }
      lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
      if (lVar10 != 0) {
        if (*(char *)(lVar10 + 0x36) == '\0') {
          return;
        }
        if (**(longlong **)(DAT_182d647e0 + 0xb8) != 0) {
          ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessageInstance__06001b13
                    (**(longlong **)(DAT_182d647e0 + 0xb8),uVar11,0,0);
          if (**(longlong **)(DAT_182d5aa70 + 0xb8) != 0) {
            ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
                      (**(longlong **)(DAT_182d5aa70 + 0xb8),0x45,0xbf800000,0,0);
            return;
          }
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
DAT_1805f6d25:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

