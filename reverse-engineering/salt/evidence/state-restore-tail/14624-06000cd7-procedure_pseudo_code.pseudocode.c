// Ghidra pseudocode; not original source or compilable C.
// ev_7114f108c45ac068a3e1405d8a39de87fe46b4bc84644182c9e078d768570f3a

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyMaterialController__SetupBodyPaintFromGameState__06000cd7
               (longlong param_1)

{
  undefined4 uVar1;
  ulonglong uVar2;
  char cVar3;
  longlong lVar4;
  code *pcVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined8 uVar8;
  longlong lVar9;
  longlong lVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  int iVar13;
  uint uVar14;
  int *piVar15;
  bool bVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  
  if (DAT_182eb83b5 == '\0') {
    FUN_1802f2810(&DAT_182d58238);
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
  if ((*(longlong *)(param_1 + 0x10) != 0) &&
     (lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x70), lVar10 != 0)) {
    lVar10 = *(longlong *)(lVar10 + 0x208);
    lVar4 = FUN_1802c43a0(DAT_182d58200);
    FUN_1811cf4f0(lVar4,DAT_182d58218);
    if (lVar10 != 0) {
      pcVar5 = DAT_182ec01b0;
      if ((DAT_182ec01b0 == (code *)0x0) &&
         (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Renderer::GetMaterialArray()"),
         pcVar5 == (code *)0x0)) {
        uVar8 = FUN_1802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar8,0);
      }
      DAT_182ec01b0 = pcVar5;
      lVar6 = (*DAT_182ec01b0)(lVar10);
      if (lVar6 != 0) {
        if (*(int *)(lVar6 + 0x18) == 0) goto LAB_180638631;
        if (lVar4 != 0) {
          FUN_1800053a0(lVar4,*(undefined8 *)(lVar6 + 0x20));
          pcVar5 = DAT_182ec01b0;
          if ((DAT_182ec01b0 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Renderer::GetMaterialArray()"),
             pcVar5 == (code *)0x0)) {
            uVar8 = FUN_1802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar8,0);
          }
          DAT_182ec01b0 = pcVar5;
          lVar6 = (*DAT_182ec01b0)(lVar10);
          if (lVar6 != 0) {
            if (*(uint *)(lVar6 + 0x18) < 2) goto LAB_180638631;
            FUN_1800053a0(lVar4,*(undefined8 *)(lVar6 + 0x28));
            lVar6 = DAT_182d3e9b0;
            if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            if (DAT_182ebb9aa == '\0') {
              FUN_1802f2810(&DAT_182d535d8);
              LOCK();
              UNLOCK();
              DAT_182ebb9aa = '\x01';
            }
            plVar7 = (longlong *)0x0;
            if (lVar6 != 0) {
              if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
                FUN_18035c820();
              }
              lVar6 = FUN_1803613f0(lVar6,1);
              plVar7 = (longlong *)FUN_1802c5ac0(lVar6 + 0x20);
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
            if (plVar7 == (longlong *)0x0) {
              uVar8 = thunk_FUN_1802f2810(&DAT_182d528c8);
              uVar8 = thunk_FUN_1802c43a0(uVar8);
              uVar11 = thunk_FUN_1802f2810(&DAT_182d27920);
              FUN_1815c6a10(uVar8,uVar11,0);
              uVar11 = thunk_FUN_1802f2810(&DAT_182d28d98);
                    /* WARNING: Subroutine does not return */
              FUN_18031da90(uVar8,uVar11);
            }
            uVar8 = (**(code **)(*plVar7 + 0x898))(plVar7,*(undefined8 *)(*plVar7 + 0x8a0));
            lVar9 = FUN_18093ca00(uVar8,DAT_182d3e9b8);
            lVar6 = DAT_182d65a98;
            if (*(longlong *)(DAT_182d65a98 + 0x38) == 0) {
              FUN_1803204f0(DAT_182d65a98);
            }
            if (lVar9 == 0) {
              uVar8 = thunk_FUN_1802f2810(&DAT_182d438a8);
              uVar8 = FUN_1816e95a0(uVar8,0);
                    /* WARNING: Subroutine does not return */
              FUN_18031da90(uVar8,lVar6);
            }
            local_68 = 0;
            uStack_60 = 0;
            FUN_180d66730(&local_68,lVar9,*(undefined8 *)(*(longlong *)(lVar6 + 0x38) + 0x10));
            local_58 = (undefined4)local_68;
            uStack_54 = local_68._4_4_;
            uStack_50 = (undefined4)uStack_60;
            uStack_4c = uStack_60._4_4_;
            lVar6 = FUN_180020930(&local_58,*(undefined8 *)(*(longlong *)(lVar6 + 0x38) + 0x18));
            uVar14 = 0;
            if (lVar6 != 0) {
              piVar15 = (int *)(lVar6 + 0x20);
              while ((int)uVar14 < *(int *)(lVar6 + 0x18)) {
                if (*(uint *)(lVar6 + 0x18) <= uVar14) goto LAB_180638631;
                iVar13 = *piVar15;
                cVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsEquipBodyPaint__06001537
                                  (iVar13);
                if (iVar13 == 8) {
                  lVar9 = FUN_180002d60(lVar4,1);
                  if (*(int *)(DAT_182d3e9d0 + 0xe0) == 0) {
                    FUN_18035c820(DAT_182d3e9d0);
                  }
                  uVar17 = 0;
                  uVar18 = 0;
                  uVar19 = 0;
                  if (cVar3 != '\0') {
                    uVar17 = 0x3f800000;
                    uVar18 = 0x3f800000;
                    uVar19 = 0x3f800000;
                  }
                  uVar1 = *(undefined4 *)(*(longlong *)(DAT_182d3e9d0 + 0xb8) + 8);
                  if (lVar9 == 0) goto LAB_1806384f1;
                  uStack_4c = 0x3f800000;
                  pcVar5 = DAT_182ec0500;
                  local_58 = uVar17;
                  uStack_54 = uVar18;
                  uStack_50 = uVar19;
                  if ((DAT_182ec0500 == (code *)0x0) &&
                     (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar5 == (code *)0x0)) {
                    uVar8 = FUN_1802ced60(
                                         "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                         );
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar8,0);
                  }
                  DAT_182ec0500 = pcVar5;
                  (*DAT_182ec0500)(lVar9,uVar1,&local_58);
LAB_18063802b:
                  uVar14 = uVar14 + 1;
                  piVar15 = piVar15 + 1;
                }
                else {
                  if (cVar3 == '\0') goto LAB_18063802b;
                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyMaterialController__TransToMaterialAsset__06000cd6
                            (param_1,iVar13,0);
                  FUN_1800053a0(lVar4);
                  uVar14 = uVar14 + 1;
                  piVar15 = piVar15 + 1;
                }
              }
              if (((*(longlong *)(param_1 + 0x10) != 0) &&
                  (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x70), lVar6 != 0)) &&
                 (lVar6 = *(longlong *)(lVar6 + 0x188), lVar6 != 0)) {
                pcVar5 = DAT_182ec1148;
                if ((DAT_182ec1148 == (code *)0x0) &&
                   (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_activeInHierarchy()"
                                                  ), pcVar5 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60("UnityEngine.GameObject::get_activeInHierarchy()");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec1148 = pcVar5;
                cVar3 = (*DAT_182ec1148)(lVar6);
                if (cVar3 != '\0') {
                  if (**(longlong **)(DAT_182d58238 + 0xb8) == 0) goto LAB_1806384f1;
                  FUN_1800053a0(lVar4,*(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x2d0)
                               );
                }
                lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                if (lVar6 != 0) {
                  if (0.0 < *(float *)(lVar6 + 0x17c)) {
                    if (**(longlong **)(DAT_182d58238 + 0xb8) == 0) goto LAB_1806384f1;
                    FUN_1800053a0(lVar4,*(undefined8 *)
                                         (**(longlong **)(DAT_182d58238 + 0xb8) + 0x298));
                  }
                  if (**(longlong **)(DAT_182d58238 + 0xb8) != 0) {
                    FUN_1800053a0(lVar4,*(undefined8 *)
                                         (**(longlong **)(DAT_182d58238 + 0xb8) + 0x280));
                    lVar4 = FUN_1811d1d70(lVar4,DAT_182d58220);
                    if (lVar4 == 0) {
                      uVar17 = 0;
                      lVar4 = 0;
                    }
                    else {
                      uVar17 = *(undefined4 *)(lVar4 + 0x18);
                    }
                    pcVar5 = DAT_182ec01b8;
                    if ((DAT_182ec01b8 == (code *)0x0) &&
                       (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Renderer::SetMaterialArray(UnityEngine.Material[],System.Int32)"
                                                  ), pcVar5 == (code *)0x0)) {
                      uVar8 = FUN_1802ced60(
                                           "UnityEngine.Renderer::SetMaterialArray(UnityEngine.Material[],System.Int32)"
                                           );
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar8,0);
                    }
                    DAT_182ec01b8 = pcVar5;
                    (*DAT_182ec01b8)(lVar10,lVar4,uVar17);
                    pcVar5 = DAT_182ec01b0;
                    if ((DAT_182ec01b0 == (code *)0x0) &&
                       (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Renderer::GetMaterialArray()"),
                       pcVar5 == (code *)0x0)) {
                      uVar8 = FUN_1802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar8,0);
                    }
                    DAT_182ec01b0 = pcVar5;
                    lVar4 = (*DAT_182ec01b0)(lVar10);
                    if (lVar4 != 0) {
                      lVar6 = (longlong)*(int *)(lVar4 + 0x18) + -1;
                      if (*(uint *)(lVar4 + 0x18) <= (uint)lVar6) {
LAB_180638631:
                    /* WARNING: Subroutine does not return */
                        FUN_18031dae0();
                      }
                      bVar16 = DAT_182eb5d50 != 0;
                      *(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(lVar4 + 0x20 + lVar6 * 8);
                      if (bVar16) {
                        uVar14 = (uint)(param_1 + 0x20U >> 0xc);
                        uVar12 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
                        do {
                          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                          LOCK();
                          bVar16 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                          if (bVar16) {
                            *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) =
                                 uVar2 | 1L << (uVar14 & 0x3f);
                          }
                          UNLOCK();
                        } while (!bVar16);
                      }
                      lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                      if (lVar4 != 0) {
                        if (*(float *)(lVar4 + 0x17c) <= 0.0) {
                          uVar8 = 0;
                        }
                        else {
                          pcVar5 = DAT_182ec01b0;
                          if ((DAT_182ec01b0 == (code *)0x0) &&
                             (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Renderer::GetMaterialArray()"),
                             pcVar5 == (code *)0x0)) {
                            uVar8 = FUN_1802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar8,0);
                          }
                          DAT_182ec01b0 = pcVar5;
                          lVar4 = (*DAT_182ec01b0)(lVar10);
                          if (lVar4 == 0) goto LAB_1806384f1;
                          lVar6 = (longlong)*(int *)(lVar4 + 0x18) + -2;
                          if (*(uint *)(lVar4 + 0x18) <= (uint)lVar6) goto LAB_180638631;
                          uVar8 = *(undefined8 *)(lVar4 + 0x20 + lVar6 * 8);
                        }
                        bVar16 = DAT_182eb5d50 != 0;
                        *(undefined8 *)(param_1 + 0x28) = uVar8;
                        if (bVar16) {
                          uVar14 = (uint)(param_1 + 0x28U >> 0xc);
                          uVar12 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
                          do {
                            uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                            LOCK();
                            bVar16 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                            if (bVar16) {
                              *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) =
                                   uVar2 | 1L << (uVar14 & 0x3f);
                            }
                            UNLOCK();
                          } while (!bVar16);
                        }
                        bVar16 = DAT_182eb5d50 != 0;
                        *(undefined8 *)(param_1 + 0x30) = 0;
                        if (bVar16) {
                          uVar14 = (uint)(param_1 + 0x30U >> 0xc);
                          uVar12 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
                          do {
                            uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                            LOCK();
                            bVar16 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                            if (bVar16) {
                              *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) =
                                   uVar2 | 1L << (uVar14 & 0x3f);
                            }
                            UNLOCK();
                          } while (!bVar16);
                        }
                        if (((*(longlong *)(param_1 + 0x10) != 0) &&
                            (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x70), lVar4 != 0
                            )) && (lVar4 = *(longlong *)(lVar4 + 0x188), lVar4 != 0)) {
                          pcVar5 = DAT_182ec1148;
                          if ((DAT_182ec1148 == (code *)0x0) &&
                             (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::get_activeInHierarchy()")
                             , pcVar5 == (code *)0x0)) {
                            uVar8 = FUN_1802ced60("UnityEngine.GameObject::get_activeInHierarchy()")
                            ;
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar8,0);
                          }
                          DAT_182ec1148 = pcVar5;
                          cVar3 = (*DAT_182ec1148)(lVar4);
                          if (cVar3 != '\0') {
                            lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                            if (lVar4 == 0) goto LAB_1806384f1;
                            iVar13 = 2;
                            if (0.0 < *(float *)(lVar4 + 0x17c)) {
                              iVar13 = 3;
                            }
                            pcVar5 = DAT_182ec01b0;
                            if ((DAT_182ec01b0 == (code *)0x0) &&
                               (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Renderer::GetMaterialArray()"),
                               pcVar5 == (code *)0x0)) {
                              uVar8 = FUN_1802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
                              FUN_1802cca90(uVar8,0);
                            }
                            DAT_182ec01b0 = pcVar5;
                            lVar10 = (*DAT_182ec01b0)(lVar10);
                            if (lVar10 == 0) goto LAB_1806384f1;
                            uVar14 = *(int *)(lVar10 + 0x18) - iVar13;
                            if (*(uint *)(lVar10 + 0x18) <= uVar14) goto LAB_180638631;
                            bVar16 = DAT_182eb5d50 != 0;
                            *(undefined8 *)(param_1 + 0x30) =
                                 *(undefined8 *)(lVar10 + 0x20 + (longlong)(int)uVar14 * 8);
                            if (bVar16) {
                              uVar14 = (uint)(param_1 + 0x30U >> 0xc);
                              uVar12 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
                              do {
                                uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                                LOCK();
                                bVar16 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                                if (bVar16) {
                                  *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) =
                                       uVar2 | 1L << (uVar14 & 0x3f);
                                }
                                UNLOCK();
                              } while (!bVar16);
                            }
                          }
                          if ((*(longlong *)(param_1 + 0x10) != 0) &&
                             (lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x1d8),
                             lVar10 != 0)) {
                            ExposureUnnoticed2_Object3D_Player_Scripts_Other_FutanariController__SetupPaint__06000e91
                                      (lVar10,0);
                            ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyMaterialController__ApplyFromGameState__06000cda
                                      (param_1,0);
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

