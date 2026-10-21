// Ghidra pseudocode; not original source or compilable C.
// ev_14862baf9afa9ed59186d585b33a2ac576523c87e3c638f7bf05351c4cb047f6

/* WARNING: Removing unreachable block (ram,0x000180638a15) */
/* WARNING: Removing unreachable block (ram,0x000180638a1b) */

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyMaterialController__SetupBodyPaintFromGameState__06000cd7
               (longlong param_1)

{
  ulonglong uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  char cVar7;
  int iVar8;
  longlong lVar9;
  code *pcVar10;
  longlong lVar11;
  longlong *plVar12;
  undefined8 uVar13;
  longlong lVar14;
  undefined8 uVar15;
  float *pfVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  uint uVar19;
  int *piVar20;
  bool bVar21;
  float fVar22;
  undefined4 uVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  undefined4 unaff_XMM12_Dc;
  undefined4 unaff_XMM12_Dd;
  float fVar29;
  ulonglong uStackX_8;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined1 auStack_c8 [56];
  undefined8 uStack_90;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  
  if (cRam0000000182eb83b5 == '\0') {
    uStack_90 = &UNK_180637be5;
    FUN_1802f2810(0x182d58238);
    LOCK();
    UNLOCK();
    uStack_90 = &UNK_180637bf6;
    FUN_1802f2810(0x182d3e9b0);
    LOCK();
    UNLOCK();
    uStack_90 = &UNK_180637c07;
    FUN_1802f2810(&DAT_182d59f58);
    LOCK();
    UNLOCK();
    uStack_90 = &UNK_180637c18;
    FUN_1802f2810(0x182d3e9b8);
    LOCK();
    UNLOCK();
    uStack_90 = &UNK_180637c29;
    FUN_1802f2810(0x182d65a98);
    LOCK();
    UNLOCK();
    uStack_90 = &UNK_180637c3a;
    FUN_1802f2810(0x182d58398);
    LOCK();
    UNLOCK();
    uStack_90 = &UNK_180637c4b;
    FUN_1802f2810(0x182d58228);
    LOCK();
    UNLOCK();
    uStack_90 = &UNK_180637c5c;
    FUN_1802f2810(0x182d58220);
    LOCK();
    UNLOCK();
    uStack_90 = &UNK_180637c6d;
    FUN_1802f2810(0x182d58218);
    LOCK();
    UNLOCK();
    uStack_90 = &UNK_180637c7e;
    FUN_1802f2810(0x182d58208);
    LOCK();
    UNLOCK();
    uStack_90 = &UNK_180637c8f;
    FUN_1802f2810(0x182d58200);
    LOCK();
    UNLOCK();
    uStack_90 = &UNK_180637ca0;
    FUN_1802f2810(0x182d3e9d0);
    LOCK();
    UNLOCK();
    uStack_90 = &UNK_180637cb1;
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    cRam0000000182eb83b5 = '\x01';
  }
  if ((*(longlong *)(param_1 + 0x10) != 0) &&
     (lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x70), lVar9 != 0)) {
    uVar18 = *(ulonglong *)(lVar9 + 0x208);
    uStack_90 = &UNK_180637d29;
    uStackX_8 = uVar18;
    lVar9 = FUN_1802c43a0(uRam0000000182d58200);
    uStack_90 = &UNK_180637d3b;
    FUN_1811cf4f0(lVar9,uRam0000000182d58218);
    if (uVar18 != 0) {
      pcVar10 = pcRam0000000182ec01b0;
      if (pcRam0000000182ec01b0 == (code *)0x0) {
        uStack_90 = &UNK_180637d5c;
        pcVar10 = (code *)FUN_1802cf0c0("UnityEngine.Renderer::GetMaterialArray()");
        if (pcVar10 == (code *)0x0) {
          uStack_90 = &UNK_180638503;
          uVar13 = func_0x0001802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
          uStack_90 = &UNK_18063850d;
          FUN_1802cca90(uVar13,0);
        }
      }
      pcRam0000000182ec01b0 = pcVar10;
      uStack_90 = &UNK_180637d71;
      lVar11 = (*pcRam0000000182ec01b0)(uVar18);
      if (lVar11 != 0) {
        if (*(int *)(lVar11 + 0x18) == 0) goto code_r0x000180638631;
        if (lVar9 != 0) {
          uStack_90 = &UNK_180637d99;
          FUN_1800053a0(lVar9,*(undefined8 *)(lVar11 + 0x20));
          pcVar10 = pcRam0000000182ec01b0;
          if (pcRam0000000182ec01b0 == (code *)0x0) {
            uStack_90 = &UNK_180637db1;
            pcVar10 = (code *)FUN_1802cf0c0("UnityEngine.Renderer::GetMaterialArray()");
            if (pcVar10 == (code *)0x0) {
              uStack_90 = &UNK_18063851a;
              uVar13 = func_0x0001802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
              uStack_90 = &UNK_180638524;
              FUN_1802cca90(uVar13,0);
            }
          }
          pcRam0000000182ec01b0 = pcVar10;
          uStack_90 = &UNK_180637dc6;
          lVar11 = (*pcRam0000000182ec01b0)(uVar18);
          if (lVar11 != 0) {
            if (*(uint *)(lVar11 + 0x18) < 2) goto code_r0x000180638631;
            uStack_90 = &UNK_180637de5;
            FUN_1800053a0(lVar9,*(undefined8 *)(lVar11 + 0x28));
            lVar11 = lRam0000000182d3e9b0;
            if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
              uStack_90 = &UNK_180637e01;
              FUN_18035c820();
            }
            if (DAT_182ebb9aa == '\0') {
              uStack_90 = &UNK_180637e16;
              FUN_1802f2810(&DAT_182d535d8);
              LOCK();
              UNLOCK();
              DAT_182ebb9aa = '\x01';
            }
            plVar12 = (longlong *)0x0;
            if (lVar11 != 0) {
              if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
                uStack_90 = &UNK_180637e3c;
                FUN_18035c820();
              }
              uStack_90 = &UNK_180637e46;
              lVar11 = FUN_1803613f0(lVar11,1);
              uStack_90 = &UNK_180637e4f;
              plVar12 = (longlong *)FUN_1802c5ac0(lVar11 + 0x20);
            }
            if (*(int *)(DAT_182d59f58 + 0xe0) == 0) {
              uStack_90 = &UNK_180637e67;
              FUN_18035c820();
            }
            if (cRam0000000182ebba98 == '\0') {
              uStack_90 = &UNK_180637e7c;
              FUN_1802f2810(&DAT_182d535d8);
              LOCK();
              UNLOCK();
              cRam0000000182ebba98 = '\x01';
            }
            if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
              uStack_90 = &UNK_180637e9d;
              FUN_18035c820();
            }
            if (plVar12 == (longlong *)0x0) {
              uStack_90 = &UNK_1806385f4;
              uVar13 = thunk_FUN_1802f2810(&DAT_182d528c8);
              uStack_90 = &UNK_1806385fc;
              uVar13 = thunk_FUN_1802c43a0(uVar13);
              uStack_90 = &UNK_18063860b;
              uVar15 = thunk_FUN_1802f2810(0x182d27920);
              uStack_90 = &UNK_180638619;
              FUN_1815c6a10(uVar13,uVar15,0);
              uStack_90 = &UNK_180638625;
              uVar15 = thunk_FUN_1802f2810(0x182d28d98);
                    /* WARNING: Subroutine does not return */
              uStack_90 = &UNK_180638630;
              FUN_18031da90(uVar13,uVar15);
            }
            uStack_90 = &UNK_180637ebc;
            uVar13 = (**(code **)(*plVar12 + 0x898))(plVar12,*(undefined8 *)(*plVar12 + 0x8a0));
            uStack_90 = &UNK_180637ecb;
            lVar14 = FUN_18093ca00(uVar13,uRam0000000182d3e9b8);
            lVar11 = lRam0000000182d65a98;
            if (*(longlong *)(lRam0000000182d65a98 + 0x38) == 0) {
              uStack_90 = &UNK_180637ee4;
              FUN_1803204f0(lRam0000000182d65a98);
            }
            if (lVar14 == 0) {
              uStack_90 = &UNK_1806385d2;
              uVar13 = thunk_FUN_1802f2810(0x182d438a8);
              uStack_90 = &UNK_1806385dc;
              uVar13 = FUN_1816e95a0(uVar13,0);
                    /* WARNING: Subroutine does not return */
              uStack_90 = &UNK_1806385e7;
              FUN_18031da90(uVar13,lVar11);
            }
            uStack_68 = 0;
            uStack_60 = 0;
            uStack_90 = &UNK_180637f0a;
            FUN_180d66730(&uStack_68,lVar14,*(undefined8 *)(*(longlong *)(lVar11 + 0x38) + 0x10));
            uStack_58 = uStack_68;
            uStack_50 = uStack_60;
            uStack_90 = &UNK_180637f27;
            lVar11 = FUN_180020930(&uStack_58,*(undefined8 *)(*(longlong *)(lVar11 + 0x38) + 0x18));
            uVar19 = 0;
            if (lVar11 != 0) {
              piVar20 = (int *)(lVar11 + 0x20);
              while ((int)uVar19 < *(int *)(lVar11 + 0x18)) {
                if (*(uint *)(lVar11 + 0x18) <= uVar19) goto code_r0x000180638631;
                iVar8 = *piVar20;
                uStack_90 = &UNK_180637f70;
                cVar7 = FUN_18048ef80(iVar8);
                if (iVar8 == 8) {
                  uStack_90 = &UNK_180637faf;
                  lVar14 = FUN_180002d60(lVar9,1);
                  if (*(int *)(lRam0000000182d3e9d0 + 0xe0) == 0) {
                    uStack_90 = &UNK_180637fca;
                    FUN_18035c820(lRam0000000182d3e9d0);
                  }
                  uVar13 = 0;
                  uVar15 = 0x3f80000000000000;
                  if (cVar7 != '\0') {
                    uVar13 = 0x3f8000003f800000;
                    uVar15 = 0x3f8000003f800000;
                  }
                  uVar23 = *(undefined4 *)(*(longlong *)(lRam0000000182d3e9d0 + 0xb8) + 8);
                  if (lVar14 == 0) goto code_r0x0001806384f1;
                  pcVar10 = pcRam0000000182ec0500;
                  uStack_58 = uVar13;
                  uStack_50 = uVar15;
                  if (pcRam0000000182ec0500 == (code *)0x0) {
                    uStack_90 = &UNK_18063800f;
                    pcVar10 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  );
                    if (pcVar10 == (code *)0x0) {
                      uStack_90 = &UNK_180638531;
                      uVar13 = func_0x0001802ced60(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                      uStack_90 = &UNK_18063853b;
                      FUN_1802cca90(uVar13,0);
                    }
                  }
                  pcRam0000000182ec0500 = pcVar10;
                  uStack_90 = &UNK_18063802b;
                  (*pcRam0000000182ec0500)(lVar14,uVar23,&uStack_58);
code_r0x00018063802b:
                  uVar19 = uVar19 + 1;
                  piVar20 = piVar20 + 1;
                }
                else {
                  if (cVar7 == '\0') goto code_r0x00018063802b;
                  uStack_90 = &UNK_180637f8d;
                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyMaterialController__TransToMaterialAsset__06000cd6
                            (param_1,iVar8,0);
                  uStack_90 = &UNK_180637f98;
                  FUN_1800053a0(lVar9);
                  uVar19 = uVar19 + 1;
                  piVar20 = piVar20 + 1;
                }
              }
              if (((*(longlong *)(param_1 + 0x10) != 0) &&
                  (lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x70), lVar11 != 0)) &&
                 (lVar11 = *(longlong *)(lVar11 + 0x188), lVar11 != 0)) {
                pcVar10 = pcRam0000000182ec1148;
                if (pcRam0000000182ec1148 == (code *)0x0) {
                  uStack_90 = &UNK_18063807b;
                  pcVar10 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_activeInHierarchy()")
                  ;
                  if (pcVar10 == (code *)0x0) {
                    uStack_90 = &UNK_180638548;
                    uVar13 = func_0x0001802ced60("UnityEngine.GameObject::get_activeInHierarchy()");
                    /* WARNING: Subroutine does not return */
                    uStack_90 = &UNK_180638552;
                    FUN_1802cca90(uVar13,0);
                  }
                }
                pcRam0000000182ec1148 = pcVar10;
                uStack_90 = &UNK_180638090;
                cVar7 = (*pcRam0000000182ec1148)(lVar11);
                if (cVar7 != '\0') {
                  if (**(longlong **)(lRam0000000182d58238 + 0xb8) == 0) goto code_r0x0001806384f1;
                  uStack_90 = &UNK_1806380bd;
                  FUN_1800053a0(lVar9,*(undefined8 *)
                                       (**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x2d0));
                }
                lVar11 = *(longlong *)(*(longlong *)(lRam0000000182d58398 + 0xb8) + 0x48);
                if (lVar11 != 0) {
                  if (0.0 < *(float *)(lVar11 + 0x17c)) {
                    if (**(longlong **)(lRam0000000182d58238 + 0xb8) == 0)
                    goto code_r0x0001806384f1;
                    uStack_90 = &UNK_180638111;
                    FUN_1800053a0(lVar9,*(undefined8 *)
                                         (**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x298));
                  }
                  if (**(longlong **)(lRam0000000182d58238 + 0xb8) != 0) {
                    uStack_90 = &UNK_18063813a;
                    FUN_1800053a0(lVar9,*(undefined8 *)
                                         (**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x280));
                    uStack_90 = &UNK_180638149;
                    lVar9 = FUN_1811d1d70(lVar9,uRam0000000182d58220);
                    if (lVar9 == 0) {
                      uVar23 = 0;
                      lVar9 = 0;
                    }
                    else {
                      uVar23 = *(undefined4 *)(lVar9 + 0x18);
                    }
                    pcVar10 = pcRam0000000182ec01b8;
                    if (pcRam0000000182ec01b8 == (code *)0x0) {
                      uStack_90 = &UNK_180638172;
                      pcVar10 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Renderer::SetMaterialArray(UnityEngine.Material[],System.Int32)"
                                                  );
                      if (pcVar10 == (code *)0x0) {
                        uStack_90 = &UNK_18063855f;
                        uVar13 = func_0x0001802ced60(
                                                  "UnityEngine.Renderer::SetMaterialArray(UnityEngine.Material[],System.Int32)"
                                                  );
                    /* WARNING: Subroutine does not return */
                        uStack_90 = &UNK_180638569;
                        FUN_1802cca90(uVar13,0);
                      }
                    }
                    pcRam0000000182ec01b8 = pcVar10;
                    uVar18 = uStackX_8;
                    uStack_90 = &UNK_180638195;
                    (*pcRam0000000182ec01b8)(uStackX_8,lVar9,uVar23);
                    pcVar10 = pcRam0000000182ec01b0;
                    if (pcRam0000000182ec01b0 == (code *)0x0) {
                      uStack_90 = &UNK_1806381ad;
                      pcVar10 = (code *)FUN_1802cf0c0("UnityEngine.Renderer::GetMaterialArray()");
                      if (pcVar10 == (code *)0x0) {
                        uStack_90 = &UNK_180638576;
                        uVar13 = func_0x0001802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
                        uStack_90 = &UNK_180638580;
                        FUN_1802cca90(uVar13,0);
                      }
                    }
                    pcRam0000000182ec01b0 = pcVar10;
                    uStack_90 = &UNK_1806381c2;
                    lVar9 = (*pcRam0000000182ec01b0)(uVar18);
                    if (lVar9 != 0) {
                      lVar11 = (longlong)*(int *)(lVar9 + 0x18) + -1;
                      if (*(uint *)(lVar9 + 0x18) <= (uint)lVar11) {
code_r0x000180638631:
                    /* WARNING: Subroutine does not return */
                        uStack_90 = &UNK_180638636;
                        FUN_18031dae0();
                      }
                      bVar21 = DAT_182eb5d50 != 0;
                      *(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(lVar9 + 0x20 + lVar11 * 8);
                      if (bVar21) {
                        uVar19 = (uint)(param_1 + 0x20U >> 0xc);
                        uVar17 = (ulonglong)((uVar19 & 0x1fffff) >> 6);
                        do {
                          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar17 * 8);
                          LOCK();
                          bVar21 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar17 * 8);
                          if (bVar21) {
                            *(ulonglong *)(&DAT_182f0c920 + uVar17 * 8) =
                                 uVar1 | 1L << (uVar19 & 0x3f);
                          }
                          UNLOCK();
                        } while (!bVar21);
                      }
                      lVar9 = *(longlong *)(*(longlong *)(lRam0000000182d58398 + 0xb8) + 0x48);
                      if (lVar9 != 0) {
                        if (*(float *)(lVar9 + 0x17c) <= 0.0) {
                          uVar13 = 0;
                        }
                        else {
                          pcVar10 = pcRam0000000182ec01b0;
                          if (pcRam0000000182ec01b0 == (code *)0x0) {
                            uStack_90 = &UNK_18063827b;
                            pcVar10 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Renderer::GetMaterialArray()");
                            if (pcVar10 == (code *)0x0) {
                              uStack_90 = &UNK_18063858d;
                              uVar13 = func_0x0001802ced60(
                                                  "UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
                              uStack_90 = &UNK_180638597;
                              FUN_1802cca90(uVar13,0);
                            }
                          }
                          pcRam0000000182ec01b0 = pcVar10;
                          uStack_90 = &UNK_180638290;
                          lVar9 = (*pcRam0000000182ec01b0)(uVar18);
                          if (lVar9 == 0) goto code_r0x0001806384f1;
                          lVar11 = (longlong)*(int *)(lVar9 + 0x18) + -2;
                          if (*(uint *)(lVar9 + 0x18) <= (uint)lVar11) goto code_r0x000180638631;
                          uVar13 = *(undefined8 *)(lVar9 + 0x20 + lVar11 * 8);
                        }
                        bVar21 = DAT_182eb5d50 != 0;
                        *(undefined8 *)(param_1 + 0x28) = uVar13;
                        if (bVar21) {
                          uVar19 = (uint)(param_1 + 0x28U >> 0xc);
                          uVar17 = (ulonglong)((uVar19 & 0x1fffff) >> 6);
                          do {
                            uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar17 * 8);
                            LOCK();
                            bVar21 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar17 * 8);
                            if (bVar21) {
                              *(ulonglong *)(&DAT_182f0c920 + uVar17 * 8) =
                                   uVar1 | 1L << (uVar19 & 0x3f);
                            }
                            UNLOCK();
                          } while (!bVar21);
                        }
                        bVar21 = DAT_182eb5d50 != 0;
                        *(undefined8 *)(param_1 + 0x30) = 0;
                        if (bVar21) {
                          uVar19 = (uint)(param_1 + 0x30U >> 0xc);
                          uVar17 = (ulonglong)((uVar19 & 0x1fffff) >> 6);
                          do {
                            uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar17 * 8);
                            LOCK();
                            bVar21 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar17 * 8);
                            if (bVar21) {
                              *(ulonglong *)(&DAT_182f0c920 + uVar17 * 8) =
                                   uVar1 | 1L << (uVar19 & 0x3f);
                            }
                            UNLOCK();
                          } while (!bVar21);
                        }
                        if (((*(longlong *)(param_1 + 0x10) != 0) &&
                            (lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x70), lVar9 != 0
                            )) && (lVar9 = *(longlong *)(lVar9 + 0x188), lVar9 != 0)) {
                          pcVar10 = pcRam0000000182ec1148;
                          if (pcRam0000000182ec1148 == (code *)0x0) {
                            uStack_90 = &UNK_18063839e;
                            pcVar10 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::get_activeInHierarchy()")
                            ;
                            if (pcVar10 == (code *)0x0) {
                              uStack_90 = &UNK_1806385a4;
                              uVar13 = func_0x0001802ced60(
                                                  "UnityEngine.GameObject::get_activeInHierarchy()")
                              ;
                    /* WARNING: Subroutine does not return */
                              uStack_90 = &UNK_1806385ae;
                              FUN_1802cca90(uVar13,0);
                            }
                          }
                          pcRam0000000182ec1148 = pcVar10;
                          uStack_90 = &UNK_1806383b3;
                          cVar7 = (*pcRam0000000182ec1148)(lVar9);
                          if (cVar7 != '\0') {
                            lVar9 = *(longlong *)(*(longlong *)(lRam0000000182d58398 + 0xb8) + 0x48)
                            ;
                            if (lVar9 == 0) goto code_r0x0001806384f1;
                            iVar8 = 2;
                            if (0.0 < *(float *)(lVar9 + 0x17c)) {
                              iVar8 = 3;
                            }
                            pcVar10 = pcRam0000000182ec01b0;
                            if (pcRam0000000182ec01b0 == (code *)0x0) {
                              uStack_90 = &UNK_180638406;
                              pcVar10 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Renderer::GetMaterialArray()");
                              if (pcVar10 == (code *)0x0) {
                                uStack_90 = &UNK_1806385bb;
                                uVar13 = func_0x0001802ced60(
                                                  "UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
                                uStack_90 = &UNK_1806385c5;
                                FUN_1802cca90(uVar13,0);
                              }
                            }
                            pcRam0000000182ec01b0 = pcVar10;
                            uStack_90 = &UNK_18063841b;
                            lVar9 = (*pcRam0000000182ec01b0)(uVar18);
                            if (lVar9 == 0) goto code_r0x0001806384f1;
                            uVar19 = *(int *)(lVar9 + 0x18) - iVar8;
                            if (*(uint *)(lVar9 + 0x18) <= uVar19) goto code_r0x000180638631;
                            bVar21 = DAT_182eb5d50 != 0;
                            *(undefined8 *)(param_1 + 0x30) =
                                 *(undefined8 *)(lVar9 + 0x20 + (longlong)(int)uVar19 * 8);
                            if (bVar21) {
                              uVar19 = (uint)(param_1 + 0x30U >> 0xc);
                              uVar18 = (ulonglong)((uVar19 & 0x1fffff) >> 6);
                              do {
                                uVar17 = *(ulonglong *)(&DAT_182f0c920 + uVar18 * 8);
                                LOCK();
                                bVar21 = uVar17 == *(ulonglong *)(&DAT_182f0c920 + uVar18 * 8);
                                if (bVar21) {
                                  *(ulonglong *)(&DAT_182f0c920 + uVar18 * 8) =
                                       uVar17 | 1L << (uVar19 & 0x3f);
                                }
                                UNLOCK();
                              } while (!bVar21);
                            }
                          }
                          if ((*(longlong *)(param_1 + 0x10) != 0) &&
                             (lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x1d8),
                             lVar9 != 0)) {
                            uStack_90 = &UNK_1806384a8;
                            ExposureUnnoticed2_Object3D_Player_Scripts_Other_FutanariController__SetupPaint__06000e91
                                      (lVar9,0);
                            if (cRam0000000182eb83b6 == '\0') {
                              FUN_1802f2810(0x182d58238);
                              LOCK();
                              UNLOCK();
                              FUN_1802f2810(0x182d53aa8);
                              LOCK();
                              UNLOCK();
                              FUN_1802f2810(0x182d3e9d0);
                              LOCK();
                              UNLOCK();
                              cRam0000000182eb83b6 = '\x01';
                            }
                            lVar9 = *(longlong *)(param_1 + 0x30);
                            uStackX_8 = uStackX_8 & 0xffffffff00000000;
                            if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
                              FUN_18035c820();
                            }
                            if (cRam0000000182ec12f3 == '\0') {
                              FUN_1802f2810(0x182d53aa8);
                              LOCK();
                              UNLOCK();
                              cRam0000000182ec12f3 = '\x01';
                            }
                            if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
                              FUN_18035c820();
                            }
                            if (cRam0000000182ec129b == '\0') {
                              FUN_1802f2810(0x182d53aa8);
                              LOCK();
                              UNLOCK();
                              cRam0000000182ec129b = '\x01';
                            }
                            if (lVar9 != 0) {
                              if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
                                FUN_18035c820();
                              }
                              if (*(longlong *)(lVar9 + 0x10) != 0) {
                                lVar11 = FUN_180490520(0x272b,0);
                                lVar9 = *(longlong *)(param_1 + 0x30);
                                if (*(int *)(lRam0000000182d3e9d0 + 0xe0) == 0) {
                                  FUN_18035c820();
                                }
                                if (lVar11 != 0) {
                                  if (*(int *)(lVar11 + 0x20) == 0) {
                                    if (**(longlong **)(lRam0000000182d58238 + 0xb8) == 0)
                                    goto DAT_180638c93;
                                    uVar13 = *(undefined8 *)
                                              (**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x310)
                                    ;
                                  }
                                  else {
                                    if (**(longlong **)(lRam0000000182d58238 + 0xb8) == 0)
                                    goto DAT_180638c93;
                                    uVar13 = *(undefined8 *)
                                              (**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x318)
                                    ;
                                  }
                                  if (lVar9 != 0) {
                                    FUN_181f11270(lVar9,*(undefined4 *)
                                                         (*(longlong *)(lRam0000000182d3e9d0 + 0xb8)
                                                         + 0x14),uVar13,0);
                                    lVar9 = *(longlong *)(param_1 + 0x30);
                                    if (*(int *)(lRam0000000182d3e9d0 + 0xe0) == 0) {
                                      FUN_18035c820(lRam0000000182d3e9d0);
                                    }
                                    if (*(char *)(lVar11 + 0x24) == '\0') {
                                      uVar13 = 0x3f8000003f800000;
                                      uVar15 = 0x3f8000003f800000;
                                    }
                                    else {
                                      uVar13 = 0;
                                      uVar15 = 0x3f80000000000000;
                                    }
                                    uVar23 = *(undefined4 *)
                                              (*(longlong *)(lRam0000000182d3e9d0 + 0xb8) + 8);
                                    if (lVar9 != 0) {
                                      pcVar10 = pcRam0000000182ec0500;
                                      uStack_e8 = uVar13;
                                      uStack_e0 = uVar15;
                                      if ((pcRam0000000182ec0500 == (code *)0x0) &&
                                         (pcVar10 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar10 == (code *)0x0)) {
                                        uVar13 = func_0x0001802ced60(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                        FUN_1802cca90(uVar13,0);
                                      }
                                      pcRam0000000182ec0500 = pcVar10;
                                      uStack_90 = (undefined *)
                                                  CONCAT44(unaff_XMM12_Dd,unaff_XMM12_Dc);
                                      (*pcRam0000000182ec0500)(lVar9,uVar23,&uStack_e8);
                                      fVar28 = (float)*(int *)(lVar11 + 0x14) / 255.0;
                                      fVar29 = (float)*(int *)(lVar11 + 0x18) / 255.0;
                                      fVar27 = (float)*(int *)(lVar11 + 0x10) / 255.0;
                                      if (((fVar29 <= fVar28) ||
                                          (fVar22 = fVar29, fVar24 = fVar27, fVar25 = fVar28,
                                          fVar29 <= fVar27)) &&
                                         (fVar22 = fVar28, fVar24 = fVar29, fVar25 = fVar27,
                                         fVar28 <= fVar27)) {
                                        fVar22 = fVar27;
                                        fVar24 = fVar28;
                                        fVar25 = fVar29;
                                      }
                                      FUN_181f2bda0(&uStackX_8,fVar22,fVar24,fVar25,&stack0x00000020
                                                    ,&uStackX_8,&stack0x00000018,0);
                                      fVar22 = (float)uStackX_8;
                                      if (0.0 < (float)uStackX_8) {
                                        fVar22 = 0.1;
                                        if ((float)uStackX_8 < 0.1) {
                                          fVar22 = (float)uStackX_8;
                                        }
                                        fVar22 = fVar22 + (float)uStackX_8;
                                        if (fVar22 < 0.0) {
                                          fVar22 = 0.0;
                                        }
                                        else if (1.0 < fVar22) {
                                          fVar22 = 1.0;
                                        }
                                      }
                                      if (*(int *)(lVar11 + 0x1c) < 0) {
                                        uVar23 = 0;
                                      }
                                      else {
                                        uVar23 = 0x3f20a0a1;
                                      }
                                      pfVar16 = (float *)FUN_181f2be80(&uStack_d8,uVar23,0x3f800000,
                                                                       0,1,0);
                                      fVar24 = *pfVar16;
                                      fVar25 = pfVar16[1];
                                      fVar2 = pfVar16[2];
                                      fVar3 = pfVar16[3];
                                      iVar8 = *(int *)(lVar11 + 0x1c);
                                      if (iVar8 < 0) {
                                        iVar8 = -iVar8;
                                      }
                                      fVar26 = (float)iVar8 / 100.0;
                                      pfVar16 = (float *)FUN_181f2be80(auStack_c8,0,fVar22,0,1,0);
                                      fVar22 = *pfVar16;
                                      fVar4 = pfVar16[1];
                                      fVar5 = pfVar16[2];
                                      fVar6 = pfVar16[3];
                                      if (fVar26 < 0.0) {
                                        fVar26 = 0.0;
                                      }
                                      else if (1.0 < fVar26) {
                                        fVar26 = 1.0;
                                      }
                                      lVar9 = *(longlong *)(param_1 + 0x30);
                                      if (*(int *)(lRam0000000182d3e9d0 + 0xe0) == 0) {
                                        FUN_18035c820(lRam0000000182d3e9d0);
                                      }
                                      uStack_e8 = CONCAT44(fVar28,fVar27);
                                      uStack_e0 = CONCAT44(0x3f800000,fVar29);
                                      if (lVar9 != 0) {
                                        uVar23 = *(undefined4 *)
                                                  (*(longlong *)(lRam0000000182d3e9d0 + 0xb8) + 0xc)
                                        ;
                                        uStack_d8 = uStack_e8;
                                        uStack_d0 = uStack_e0;
                                        pcVar10 = pcRam0000000182ec0500;
                                        if ((pcRam0000000182ec0500 == (code *)0x0) &&
                                           (pcVar10 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar10 == (code *)0x0)) {
                                          uVar13 = func_0x0001802ced60(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                          FUN_1802cca90(uVar13,0);
                                        }
                                        pcRam0000000182ec0500 = pcVar10;
                                        (*pcRam0000000182ec0500)(lVar9,uVar23,&uStack_d8);
                                        lVar9 = *(longlong *)(param_1 + 0x30);
                                        uStack_e8 = CONCAT44((fVar25 - fVar4) * fVar26 + fVar4,
                                                             (fVar24 - fVar22) * fVar26 + fVar22);
                                        uStack_e0 = CONCAT44((fVar3 - fVar6) * fVar26 + fVar6,
                                                             (fVar2 - fVar5) * fVar26 + fVar5);
                                        if (lVar9 != 0) {
                                          uVar23 = *(undefined4 *)
                                                    (*(longlong *)(lRam0000000182d3e9d0 + 0xb8) +
                                                    0x10);
                                          pcVar10 = pcRam0000000182ec0500;
                                          if ((pcRam0000000182ec0500 == (code *)0x0) &&
                                             (pcVar10 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar10 == (code *)0x0)) {
                                            uVar13 = func_0x0001802ced60(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                            FUN_1802cca90(uVar13,0);
                                          }
                                          pcRam0000000182ec0500 = pcVar10;
                                          (*pcRam0000000182ec0500)(lVar9,uVar23,&uStack_e8);
                                          if ((*(longlong *)(param_1 + 0x10) != 0) &&
                                             (lVar9 = *(longlong *)
                                                       (*(longlong *)(param_1 + 0x10) + 0x1d8),
                                             lVar9 != 0)) {
                                            FUN_180402090(lVar9,0);
                                            return;
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
DAT_180638c93:
                    /* WARNING: Subroutine does not return */
                                FUN_18031dad0();
                              }
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
code_r0x0001806384f1:
                    /* WARNING: Subroutine does not return */
  uStack_90 = &UNK_1806384f6;
  FUN_18031dad0();
}

