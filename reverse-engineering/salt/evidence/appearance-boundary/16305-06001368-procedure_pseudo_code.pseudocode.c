// Ghidra pseudocode; not original source or compilable C.
// ev_a58d75174bbeee61838f5d67b310cf7e52152f95fa2829abeb4a1b91f3f9e9c7

void ExposureUnnoticed2_Master_BodyPaint_RBodyPaint__SwitchVisible__06001368(longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  ulonglong uVar3;
  byte bVar4;
  char cVar5;
  longlong lVar6;
  code *pcVar7;
  longlong lVar8;
  longlong *plVar9;
  undefined8 uVar10;
  longlong lVar11;
  longlong lVar12;
  undefined8 uVar13;
  ulonglong uVar14;
  int iVar15;
  uint uVar16;
  int *piVar17;
  bool bVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined *puStack_30;
  
  if (cRam0000000182eb7897 == '\0') {
    puStack_30 = &UNK_18046c60e;
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb7897 = '\x01';
  }
  puStack_30 = &UNK_18046c624;
  bVar4 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsEquipBodyPaint__06001537
                    (*(undefined4 *)(param_1 + 0x18),0);
  puStack_30 = &UNK_18046c634;
  ExposureUnnoticed2_Scripts_InGame_GameStateFacade__SetActiveBodyPaint__06001538
            (*(undefined4 *)(param_1 + 0x18),bVar4 ^ 1,0);
  if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
      (lVar2 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar2 == 0)) ||
     (lVar2 = *(longlong *)(lVar2 + 0x1b0), lVar2 == 0)) {
                    /* WARNING: Subroutine does not return */
    puStack_30 = &UNK_18046c670;
    FUN_18031dad0();
  }
  if (DAT_182eb83b5 == '\0') {
    FUN_1802f2810(&DAT_182d58238,0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d3e9b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59f58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d3e9b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d65a98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58228);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58220);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58218);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58208);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58200);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d3e9d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182eb83b5 = '\x01';
  }
  if ((*(longlong *)(lVar2 + 0x10) != 0) &&
     (lVar12 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x70), lVar12 != 0)) {
    lVar12 = *(longlong *)(lVar12 + 0x208);
    lVar6 = FUN_1802c43a0(DAT_182d58200);
    FUN_1811cf4f0(lVar6,DAT_182d58218);
    if (lVar12 != 0) {
      pcVar7 = DAT_182ec01b0;
      if ((DAT_182ec01b0 == (code *)0x0) &&
         (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Renderer::GetMaterialArray()"),
         pcVar7 == (code *)0x0)) {
        uVar10 = FUN_1802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar10,0);
      }
      DAT_182ec01b0 = pcVar7;
      lVar8 = (*DAT_182ec01b0)(lVar12);
      if (lVar8 != 0) {
        if (*(int *)(lVar8 + 0x18) == 0) goto LAB_180638631;
        if (lVar6 != 0) {
          FUN_1800053a0(lVar6,*(undefined8 *)(lVar8 + 0x20));
          pcVar7 = DAT_182ec01b0;
          if ((DAT_182ec01b0 == (code *)0x0) &&
             (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Renderer::GetMaterialArray()"),
             pcVar7 == (code *)0x0)) {
            uVar10 = FUN_1802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar10,0);
          }
          DAT_182ec01b0 = pcVar7;
          lVar8 = (*DAT_182ec01b0)(lVar12);
          if (lVar8 != 0) {
            if (*(uint *)(lVar8 + 0x18) < 2) goto LAB_180638631;
            FUN_1800053a0(lVar6,*(undefined8 *)(lVar8 + 0x28));
            lVar8 = DAT_182d3e9b0;
            if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            if (DAT_182ebb9aa == '\0') {
              FUN_1802f2810(&DAT_182d535d8);
              LOCK();
              UNLOCK();
              DAT_182ebb9aa = '\x01';
            }
            plVar9 = (longlong *)0x0;
            if (lVar8 != 0) {
              if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
                FUN_18035c820();
              }
              lVar8 = FUN_1803613f0(lVar8,1);
              plVar9 = (longlong *)FUN_1802c5ac0(lVar8 + 0x20);
            }
            if (*(int *)(DAT_182d59f58 + 0xe0) == 0) {
              FUN_18035c820();
            }
            if (DAT_182ebba98 == '\0') {
              FUN_1802f2810(&DAT_182d535d8);
              LOCK();
              UNLOCK();
              DAT_182ebba98 = '\x01';
            }
            if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            if (plVar9 == (longlong *)0x0) {
              uVar10 = thunk_FUN_1802f2810(&DAT_182d528c8);
              uVar10 = thunk_FUN_1802c43a0(uVar10);
              uVar13 = thunk_FUN_1802f2810(&DAT_182d27920);
              FUN_1815c6a10(uVar10,uVar13,0);
              uVar13 = thunk_FUN_1802f2810(&DAT_182d28d98);
                    /* WARNING: Subroutine does not return */
              FUN_18031da90(uVar10,uVar13);
            }
            uVar10 = (**(code **)(*plVar9 + 0x898))(plVar9,*(undefined8 *)(*plVar9 + 0x8a0));
            lVar11 = FUN_18093ca00(uVar10,DAT_182d3e9b8);
            lVar8 = DAT_182d65a98;
            if (*(longlong *)(DAT_182d65a98 + 0x38) == 0) {
              FUN_1803204f0(DAT_182d65a98);
            }
            if (lVar11 == 0) {
              uVar10 = thunk_FUN_1802f2810(&DAT_182d438a8);
              uVar10 = FUN_1816e95a0(uVar10,0);
                    /* WARNING: Subroutine does not return */
              FUN_18031da90(uVar10,lVar8);
            }
            uStack_68 = 0;
            uStack_60 = 0;
            FUN_180d66730(&uStack_68,lVar11,*(undefined8 *)(*(longlong *)(lVar8 + 0x38) + 0x10));
            uStack_58 = (undefined4)uStack_68;
            uStack_54 = uStack_68._4_4_;
            uStack_50 = (undefined4)uStack_60;
            uStack_4c = uStack_60._4_4_;
            lVar8 = FUN_180020930(&uStack_58,*(undefined8 *)(*(longlong *)(lVar8 + 0x38) + 0x18));
            uVar16 = 0;
            if (lVar8 != 0) {
              piVar17 = (int *)(lVar8 + 0x20);
              while ((int)uVar16 < *(int *)(lVar8 + 0x18)) {
                if (*(uint *)(lVar8 + 0x18) <= uVar16) goto LAB_180638631;
                iVar15 = *piVar17;
                cVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsEquipBodyPaint__06001537
                                  (iVar15);
                if (iVar15 == 8) {
                  lVar11 = FUN_180002d60(lVar6,1);
                  if (*(int *)(DAT_182d3e9d0 + 0xe0) == 0) {
                    FUN_18035c820(DAT_182d3e9d0);
                  }
                  uVar19 = 0;
                  uVar20 = 0;
                  uVar21 = 0;
                  if (cVar5 != '\0') {
                    uVar19 = 0x3f800000;
                    uVar20 = 0x3f800000;
                    uVar21 = 0x3f800000;
                  }
                  uVar1 = *(undefined4 *)(*(longlong *)(DAT_182d3e9d0 + 0xb8) + 8);
                  if (lVar11 == 0) goto LAB_1806384f1;
                  uStack_4c = 0x3f800000;
                  pcVar7 = DAT_182ec0500;
                  uStack_58 = uVar19;
                  uStack_54 = uVar20;
                  uStack_50 = uVar21;
                  if ((DAT_182ec0500 == (code *)0x0) &&
                     (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar7 == (code *)0x0)) {
                    uVar10 = FUN_1802ced60(
                                          "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                          );
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar10,0);
                  }
                  DAT_182ec0500 = pcVar7;
                  (*DAT_182ec0500)(lVar11,uVar1,&uStack_58);
LAB_18063802b:
                  uVar16 = uVar16 + 1;
                  piVar17 = piVar17 + 1;
                }
                else {
                  if (cVar5 == '\0') goto LAB_18063802b;
                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyMaterialController__TransToMaterialAsset__06000cd6
                            (lVar2,iVar15,0);
                  FUN_1800053a0(lVar6);
                  uVar16 = uVar16 + 1;
                  piVar17 = piVar17 + 1;
                }
              }
              if (((*(longlong *)(lVar2 + 0x10) != 0) &&
                  (lVar8 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x70), lVar8 != 0)) &&
                 (lVar8 = *(longlong *)(lVar8 + 0x188), lVar8 != 0)) {
                pcVar7 = DAT_182ec1148;
                if ((DAT_182ec1148 == (code *)0x0) &&
                   (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_activeInHierarchy()"
                                                  ), pcVar7 == (code *)0x0)) {
                  uVar10 = FUN_1802ced60("UnityEngine.GameObject::get_activeInHierarchy()");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar10,0);
                }
                DAT_182ec1148 = pcVar7;
                cVar5 = (*DAT_182ec1148)(lVar8);
                if (cVar5 != '\0') {
                  if (**(longlong **)(DAT_182d58238 + 0xb8) == 0) goto LAB_1806384f1;
                  FUN_1800053a0(lVar6,*(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x2d0)
                               );
                }
                lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                if (lVar8 != 0) {
                  if (0.0 < *(float *)(lVar8 + 0x17c)) {
                    if (**(longlong **)(DAT_182d58238 + 0xb8) == 0) goto LAB_1806384f1;
                    FUN_1800053a0(lVar6,*(undefined8 *)
                                         (**(longlong **)(DAT_182d58238 + 0xb8) + 0x298));
                  }
                  if (**(longlong **)(DAT_182d58238 + 0xb8) != 0) {
                    FUN_1800053a0(lVar6,*(undefined8 *)
                                         (**(longlong **)(DAT_182d58238 + 0xb8) + 0x280));
                    lVar6 = FUN_1811d1d70(lVar6,DAT_182d58220);
                    if (lVar6 == 0) {
                      uVar19 = 0;
                      lVar6 = 0;
                    }
                    else {
                      uVar19 = *(undefined4 *)(lVar6 + 0x18);
                    }
                    pcVar7 = DAT_182ec01b8;
                    if ((DAT_182ec01b8 == (code *)0x0) &&
                       (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Renderer::SetMaterialArray(UnityEngine.Material[],System.Int32)"
                                                  ), pcVar7 == (code *)0x0)) {
                      uVar10 = FUN_1802ced60(
                                            "UnityEngine.Renderer::SetMaterialArray(UnityEngine.Material[],System.Int32)"
                                            );
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar10,0);
                    }
                    DAT_182ec01b8 = pcVar7;
                    (*DAT_182ec01b8)(lVar12,lVar6,uVar19);
                    pcVar7 = DAT_182ec01b0;
                    if ((DAT_182ec01b0 == (code *)0x0) &&
                       (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Renderer::GetMaterialArray()"),
                       pcVar7 == (code *)0x0)) {
                      uVar10 = FUN_1802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar10,0);
                    }
                    DAT_182ec01b0 = pcVar7;
                    lVar6 = (*DAT_182ec01b0)(lVar12);
                    if (lVar6 != 0) {
                      lVar8 = (longlong)*(int *)(lVar6 + 0x18) + -1;
                      if (*(uint *)(lVar6 + 0x18) <= (uint)lVar8) {
LAB_180638631:
                    /* WARNING: Subroutine does not return */
                        FUN_18031dae0();
                      }
                      bVar18 = DAT_182eb5d50 != 0;
                      *(undefined8 *)(lVar2 + 0x20) = *(undefined8 *)(lVar6 + 0x20 + lVar8 * 8);
                      if (bVar18) {
                        uVar16 = (uint)(lVar2 + 0x20U >> 0xc);
                        uVar14 = (ulonglong)((uVar16 & 0x1fffff) >> 6);
                        do {
                          uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
                          LOCK();
                          bVar18 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
                          if (bVar18) {
                            *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8) =
                                 uVar3 | 1L << (uVar16 & 0x3f);
                          }
                          UNLOCK();
                        } while (!bVar18);
                      }
                      lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                      if (lVar6 != 0) {
                        if (*(float *)(lVar6 + 0x17c) <= 0.0) {
                          uVar10 = 0;
                        }
                        else {
                          pcVar7 = DAT_182ec01b0;
                          if ((DAT_182ec01b0 == (code *)0x0) &&
                             (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Renderer::GetMaterialArray()"),
                             pcVar7 == (code *)0x0)) {
                            uVar10 = FUN_1802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar10,0);
                          }
                          DAT_182ec01b0 = pcVar7;
                          lVar6 = (*DAT_182ec01b0)(lVar12);
                          if (lVar6 == 0) goto LAB_1806384f1;
                          lVar8 = (longlong)*(int *)(lVar6 + 0x18) + -2;
                          if (*(uint *)(lVar6 + 0x18) <= (uint)lVar8) goto LAB_180638631;
                          uVar10 = *(undefined8 *)(lVar6 + 0x20 + lVar8 * 8);
                        }
                        bVar18 = DAT_182eb5d50 != 0;
                        *(undefined8 *)(lVar2 + 0x28) = uVar10;
                        if (bVar18) {
                          uVar16 = (uint)(lVar2 + 0x28U >> 0xc);
                          uVar14 = (ulonglong)((uVar16 & 0x1fffff) >> 6);
                          do {
                            uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
                            LOCK();
                            bVar18 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
                            if (bVar18) {
                              *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8) =
                                   uVar3 | 1L << (uVar16 & 0x3f);
                            }
                            UNLOCK();
                          } while (!bVar18);
                        }
                        bVar18 = DAT_182eb5d50 != 0;
                        *(undefined8 *)(lVar2 + 0x30) = 0;
                        if (bVar18) {
                          uVar16 = (uint)(lVar2 + 0x30U >> 0xc);
                          uVar14 = (ulonglong)((uVar16 & 0x1fffff) >> 6);
                          do {
                            uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
                            LOCK();
                            bVar18 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
                            if (bVar18) {
                              *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8) =
                                   uVar3 | 1L << (uVar16 & 0x3f);
                            }
                            UNLOCK();
                          } while (!bVar18);
                        }
                        if (((*(longlong *)(lVar2 + 0x10) != 0) &&
                            (lVar6 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x70), lVar6 != 0))
                           && (lVar6 = *(longlong *)(lVar6 + 0x188), lVar6 != 0)) {
                          pcVar7 = DAT_182ec1148;
                          if ((DAT_182ec1148 == (code *)0x0) &&
                             (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::get_activeInHierarchy()")
                             , pcVar7 == (code *)0x0)) {
                            uVar10 = FUN_1802ced60("UnityEngine.GameObject::get_activeInHierarchy()"
                                                  );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar10,0);
                          }
                          DAT_182ec1148 = pcVar7;
                          cVar5 = (*DAT_182ec1148)(lVar6);
                          if (cVar5 != '\0') {
                            lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                            if (lVar6 == 0) goto LAB_1806384f1;
                            iVar15 = 2;
                            if (0.0 < *(float *)(lVar6 + 0x17c)) {
                              iVar15 = 3;
                            }
                            pcVar7 = DAT_182ec01b0;
                            if ((DAT_182ec01b0 == (code *)0x0) &&
                               (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Renderer::GetMaterialArray()"),
                               pcVar7 == (code *)0x0)) {
                              uVar10 = FUN_1802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
                              FUN_1802cca90(uVar10,0);
                            }
                            DAT_182ec01b0 = pcVar7;
                            lVar12 = (*DAT_182ec01b0)(lVar12);
                            if (lVar12 == 0) goto LAB_1806384f1;
                            uVar16 = *(int *)(lVar12 + 0x18) - iVar15;
                            if (*(uint *)(lVar12 + 0x18) <= uVar16) goto LAB_180638631;
                            bVar18 = DAT_182eb5d50 != 0;
                            *(undefined8 *)(lVar2 + 0x30) =
                                 *(undefined8 *)(lVar12 + 0x20 + (longlong)(int)uVar16 * 8);
                            if (bVar18) {
                              uVar16 = (uint)(lVar2 + 0x30U >> 0xc);
                              uVar14 = (ulonglong)((uVar16 & 0x1fffff) >> 6);
                              do {
                                uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
                                LOCK();
                                bVar18 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8);
                                if (bVar18) {
                                  *(ulonglong *)(&DAT_182f0c920 + uVar14 * 8) =
                                       uVar3 | 1L << (uVar16 & 0x3f);
                                }
                                UNLOCK();
                              } while (!bVar18);
                            }
                          }
                          if ((*(longlong *)(lVar2 + 0x10) != 0) &&
                             (lVar12 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x1d8),
                             lVar12 != 0)) {
                            ExposureUnnoticed2_Object3D_Player_Scripts_Other_FutanariController__SetupPaint__06000e91
                                      (lVar12,0);
                            ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyMaterialController__ApplyFromGameState__06000cda
                                      (lVar2,0);
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
LAB_1806384f1:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

