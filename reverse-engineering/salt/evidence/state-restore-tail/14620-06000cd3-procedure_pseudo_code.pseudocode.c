// Ghidra pseudocode; not original source or compilable C.
// ev_b665e10e31d156a1aeb4ecd8fdcf2ac703d685b446698f4a688f9478414df41f

/* WARNING: Removing unreachable block (ram,0x0001806389ce) */
/* WARNING: Removing unreachable block (ram,0x0001806389db) */
/* WARNING: Removing unreachable block (ram,0x0001806389de) */
/* WARNING: Removing unreachable block (ram,0x0001806389f7) */
/* WARNING: Removing unreachable block (ram,0x0001806389eb) */
/* WARNING: Removing unreachable block (ram,0x0001806389f1) */

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyMaterialController__Initialize__06000cd3
               (longlong param_1,undefined8 param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int iVar11;
  undefined8 uVar12;
  longlong lVar13;
  code *pcVar14;
  float *pfVar15;
  uint uVar16;
  bool bVar17;
  undefined8 uVar18;
  undefined4 uVar19;
  float fVar20;
  float fVar21;
  undefined *unaff_XMM6_Qb;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float afStackX_18 [2];
  undefined4 auStackX_20 [2];
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined1 auStack_c8 [152];
  undefined *puStack_30;
  
  if (cRam0000000182eb83b1 == '\0') {
    puStack_30 = &UNK_1806375b5;
    FUN_1802f2810(&DAT_182d58300);
    LOCK();
    UNLOCK();
    puStack_30 = &UNK_1806375c6;
    FUN_1802f2810(0x182d58000);
    LOCK();
    UNLOCK();
    puStack_30 = &UNK_1806375d7;
    FUN_1802f2810(&DAT_182d582e8);
    LOCK();
    UNLOCK();
    puStack_30 = &UNK_1806375e8;
    FUN_1802f2810(0x182d57ff8);
    LOCK();
    UNLOCK();
    puStack_30 = &UNK_1806375f9;
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    puStack_30 = &UNK_18063760a;
    FUN_1802f2810(0x182d3e9e0);
    LOCK();
    UNLOCK();
    puStack_30 = &UNK_18063761b;
    FUN_1802f2810(0x182d3e9d8);
    LOCK();
    UNLOCK();
    cRam0000000182eb83b1 = '\x01';
  }
  bVar17 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x10) = param_2;
  if (bVar17) {
    uVar16 = (uint)(param_1 + 0x10U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar16 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar3 == uVar2) {
        *puVar1 = uVar3 | 1L << (uVar16 & 0x3f);
      }
      UNLOCK();
    } while (uVar3 != uVar2);
  }
  puStack_30 = &UNK_18063767d;
  uVar12 = FUN_1802c43a0(DAT_182d58300);
  puStack_30 = &UNK_180637695;
  FUN_180665bb0(uVar12,param_1,uRam0000000182d3e9e0,0);
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    puStack_30 = &UNK_1806376aa;
    FUN_18035c820();
  }
  puStack_30 = &UNK_1806376bb;
  FUN_180993250(uVar12,0,DAT_182d582e8);
  puStack_30 = &UNK_1806376c7;
  uVar12 = FUN_1802c43a0(uRam0000000182d58000);
  puStack_30 = &UNK_1806376df;
  FUN_180665bb0(uVar12,param_1,uRam0000000182d3e9d8,0);
  puStack_30 = &UNK_1806376f0;
  FUN_180993250(uVar12,0,uRam0000000182d57ff8);
  puStack_30 = &UNK_1806376fa;
  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyMaterialController__SetupBodyPaintFromGameState__06000cd7
            (param_1,0);
  if (DAT_182eb83b6 == '\0') {
    FUN_1802f2810(&DAT_182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d3e9d0);
    LOCK();
    UNLOCK();
    DAT_182eb83b6 = '\x01';
  }
  lVar4 = *(longlong *)(param_1 + 0x30);
  auStackX_20[0] = 0;
  afStackX_18[0] = 0.0;
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec12f3 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec12f3 = '\x01';
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
  if (lVar4 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar4 + 0x10) != 0) {
      lVar13 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetCosplayPartsOptionData__06001548
                         (0x272b,0);
      lVar4 = *(longlong *)(param_1 + 0x30);
      if (*(int *)(DAT_182d3e9d0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (lVar13 != 0) {
        if (*(int *)(lVar13 + 0x20) == 0) {
          if (**(longlong **)(DAT_182d58238 + 0xb8) == 0) goto LAB_180638c93;
          uVar12 = *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x310);
        }
        else {
          if (**(longlong **)(DAT_182d58238 + 0xb8) == 0) goto LAB_180638c93;
          uVar12 = *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x318);
        }
        if (lVar4 != 0) {
          FUN_181f11270(lVar4,*(undefined4 *)(*(longlong *)(DAT_182d3e9d0 + 0xb8) + 0x14),uVar12,0);
          lVar4 = *(longlong *)(param_1 + 0x30);
          if (*(int *)(DAT_182d3e9d0 + 0xe0) == 0) {
            FUN_18035c820(DAT_182d3e9d0);
          }
          if (*(char *)(lVar13 + 0x24) == '\0') {
            uVar12 = 0x3f8000003f800000;
            uVar18 = 0x3f8000003f800000;
          }
          else {
            uVar12 = 0;
            uVar18 = 0x3f80000000000000;
          }
          uVar19 = *(undefined4 *)(*(longlong *)(DAT_182d3e9d0 + 0xb8) + 8);
          if (lVar4 != 0) {
            pcVar14 = DAT_182ec0500;
            uStack_e8 = uVar12;
            uStack_e0 = uVar18;
            if ((DAT_182ec0500 == (code *)0x0) &&
               (pcVar14 = (code *)FUN_1802cf0c0(
                                               "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                               ), pcVar14 == (code *)0x0)) {
              uVar12 = FUN_1802ced60(
                                    "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                    );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar12,0);
            }
            DAT_182ec0500 = pcVar14;
            puStack_30 = unaff_XMM6_Qb;
            (*DAT_182ec0500)(lVar4,uVar19,&uStack_e8);
            fVar24 = (float)*(int *)(lVar13 + 0x14) / 255.0;
            fVar25 = (float)*(int *)(lVar13 + 0x18) / 255.0;
            fVar23 = (float)*(int *)(lVar13 + 0x10) / 255.0;
            if (((fVar25 <= fVar24) || (fVar22 = fVar25, fVar20 = fVar24, fVar25 <= fVar23)) &&
               (fVar22 = fVar24, fVar20 = fVar23, fVar24 <= fVar23)) {
              fVar22 = fVar23;
              fVar20 = fVar25;
            }
            FUN_181f2bda0(&stack0x00000008,fVar22,0,fVar20,auStackX_20,&stack0x00000008,afStackX_18,
                          0);
            fVar22 = afStackX_18[0] * 0.9;
            if (fVar22 < 0.0) {
              fVar22 = 0.0;
            }
            else if (1.0 < fVar22) {
              fVar22 = 1.0;
            }
            if (*(int *)(lVar13 + 0x1c) < 0) {
              uVar19 = 0;
            }
            else {
              uVar19 = 0x3f20a0a1;
            }
            pfVar15 = (float *)FUN_181f2be80(&uStack_d8,uVar19,0x3f800000,fVar22,1,0);
            fVar20 = *pfVar15;
            fVar5 = pfVar15[1];
            fVar6 = pfVar15[2];
            fVar7 = pfVar15[3];
            iVar11 = *(int *)(lVar13 + 0x1c);
            if (iVar11 < 0) {
              iVar11 = -iVar11;
            }
            fVar21 = (float)iVar11 / 100.0;
            pfVar15 = (float *)FUN_181f2be80(auStack_c8,auStackX_20[0],0,fVar22,1,0);
            fVar22 = *pfVar15;
            fVar8 = pfVar15[1];
            fVar9 = pfVar15[2];
            fVar10 = pfVar15[3];
            if (fVar21 < 0.0) {
              fVar21 = 0.0;
            }
            else if (1.0 < fVar21) {
              fVar21 = 1.0;
            }
            lVar4 = *(longlong *)(param_1 + 0x30);
            if (*(int *)(DAT_182d3e9d0 + 0xe0) == 0) {
              FUN_18035c820(DAT_182d3e9d0);
            }
            uStack_e8 = CONCAT44(fVar24,fVar23);
            uStack_e0 = CONCAT44(0x3f800000,fVar25);
            if (lVar4 != 0) {
              uVar19 = *(undefined4 *)(*(longlong *)(DAT_182d3e9d0 + 0xb8) + 0xc);
              uStack_d8 = uStack_e8;
              uStack_d0 = uStack_e0;
              pcVar14 = DAT_182ec0500;
              if ((DAT_182ec0500 == (code *)0x0) &&
                 (pcVar14 = (code *)FUN_1802cf0c0(
                                                 "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                 ), pcVar14 == (code *)0x0)) {
                uVar12 = FUN_1802ced60(
                                      "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                      );
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar12,0);
              }
              DAT_182ec0500 = pcVar14;
              (*DAT_182ec0500)(lVar4,uVar19,&uStack_d8);
              lVar4 = *(longlong *)(param_1 + 0x30);
              uStack_e8 = CONCAT44((fVar5 - fVar8) * fVar21 + fVar8,
                                   (fVar20 - fVar22) * fVar21 + fVar22);
              uStack_e0 = CONCAT44((fVar7 - fVar10) * fVar21 + fVar10,
                                   (fVar6 - fVar9) * fVar21 + fVar9);
              if (lVar4 != 0) {
                uVar19 = *(undefined4 *)(*(longlong *)(DAT_182d3e9d0 + 0xb8) + 0x10);
                pcVar14 = DAT_182ec0500;
                if ((DAT_182ec0500 == (code *)0x0) &&
                   (pcVar14 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar14 == (code *)0x0)) {
                  uVar12 = FUN_1802ced60(
                                        "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                        );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar12,0);
                }
                DAT_182ec0500 = pcVar14;
                (*DAT_182ec0500)(lVar4,uVar19,&uStack_e8);
                if ((*(longlong *)(param_1 + 0x10) != 0) &&
                   (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x1d8), lVar4 != 0)) {
                  ExposureUnnoticed2_Object3D_Player_Scripts_Other_FutanariController__SetupCosplayOption__06000e92
                            (lVar4,0);
                  return;
                }
              }
            }
          }
        }
      }
LAB_180638c93:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
  return;
}

