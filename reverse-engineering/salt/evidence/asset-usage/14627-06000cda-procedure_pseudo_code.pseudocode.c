// Ghidra pseudocode; not original source or compilable C.
// ev_81bdab9882d89d6456152ad012facae87f64100df1c3f8834317aae486cbd679

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyMaterialController__ApplyFromGameState__06000cda
               (longlong param_1)

{
  longlong lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  longlong lVar8;
  code *pcVar9;
  float *pfVar10;
  undefined8 uVar11;
  float fVar12;
  undefined8 uVar13;
  undefined4 uVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float afStackX_8 [4];
  float afStackX_18 [2];
  undefined4 auStackX_20 [2];
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined1 auStack_c8 [160];
  
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
  lVar1 = *(longlong *)(param_1 + 0x30);
  auStackX_20[0] = 0;
  afStackX_8[0] = 0.0;
  afStackX_18[0] = 0.0;
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
  if (lVar1 != 0) {
    if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar1 + 0x10) != 0) {
      lVar8 = FUN_180490520(0x272b,0);
      lVar1 = *(longlong *)(param_1 + 0x30);
      if (*(int *)(lRam0000000182d3e9d0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (lVar8 != 0) {
        if (*(int *)(lVar8 + 0x20) == 0) {
          if (**(longlong **)(lRam0000000182d58238 + 0xb8) == 0) goto DAT_180638c93;
          uVar11 = *(undefined8 *)(**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x310);
        }
        else {
          if (**(longlong **)(lRam0000000182d58238 + 0xb8) == 0) goto DAT_180638c93;
          uVar11 = *(undefined8 *)(**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x318);
        }
        if (lVar1 != 0) {
          FUN_181f11270(lVar1,*(undefined4 *)(*(longlong *)(lRam0000000182d3e9d0 + 0xb8) + 0x14),
                        uVar11,0);
          lVar1 = *(longlong *)(param_1 + 0x30);
          if (*(int *)(lRam0000000182d3e9d0 + 0xe0) == 0) {
            FUN_18035c820(lRam0000000182d3e9d0);
          }
          if (*(char *)(lVar8 + 0x24) == '\0') {
            uVar11 = 0x3f8000003f800000;
            uVar13 = 0x3f8000003f800000;
          }
          else {
            uVar11 = 0;
            uVar13 = 0x3f80000000000000;
          }
          uVar14 = *(undefined4 *)(*(longlong *)(lRam0000000182d3e9d0 + 0xb8) + 8);
          if (lVar1 != 0) {
            pcVar9 = pcRam0000000182ec0500;
            uStack_e8 = uVar11;
            uStack_e0 = uVar13;
            if ((pcRam0000000182ec0500 == (code *)0x0) &&
               (pcVar9 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                              ), pcVar9 == (code *)0x0)) {
              uVar11 = func_0x0001802ced60(
                                          "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                          );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar11,0);
            }
            pcRam0000000182ec0500 = pcVar9;
            (*pcRam0000000182ec0500)(lVar1,uVar14,&uStack_e8);
            fVar19 = (float)*(int *)(lVar8 + 0x14) / 255.0;
            fVar20 = (float)*(int *)(lVar8 + 0x18) / 255.0;
            fVar18 = (float)*(int *)(lVar8 + 0x10) / 255.0;
            if (((fVar20 <= fVar19) ||
                (fVar12 = fVar20, fVar17 = fVar18, fVar15 = fVar19, fVar20 <= fVar18)) &&
               (fVar12 = fVar19, fVar17 = fVar20, fVar15 = fVar18, fVar19 <= fVar18)) {
              fVar12 = fVar18;
              fVar17 = fVar19;
              fVar15 = fVar20;
            }
            FUN_181f2bda0(afStackX_8,fVar12,fVar17,fVar15,auStackX_20,afStackX_8,afStackX_18,0);
            fVar12 = afStackX_8[0];
            if (0.0 < afStackX_8[0]) {
              fVar12 = 0.1;
              if (afStackX_8[0] < 0.1) {
                fVar12 = afStackX_8[0];
              }
              fVar12 = fVar12 + afStackX_8[0];
              if (fVar12 < 0.0) {
                fVar12 = 0.0;
              }
              else if (1.0 < fVar12) {
                fVar12 = 1.0;
              }
            }
            fVar17 = afStackX_18[0] * 0.9;
            if (fVar17 < 0.0) {
              fVar17 = 0.0;
            }
            else if (1.0 < fVar17) {
              fVar17 = 1.0;
            }
            if (*(int *)(lVar8 + 0x1c) < 0) {
              uVar14 = 0;
            }
            else {
              uVar14 = 0x3f20a0a1;
            }
            pfVar10 = (float *)FUN_181f2be80(&uStack_d8,uVar14,0x3f800000,fVar17,1,0);
            fVar15 = *pfVar10;
            fVar2 = pfVar10[1];
            fVar3 = pfVar10[2];
            fVar4 = pfVar10[3];
            iVar7 = *(int *)(lVar8 + 0x1c);
            if (iVar7 < 0) {
              iVar7 = -iVar7;
            }
            fVar16 = (float)iVar7 / 100.0;
            pfVar10 = (float *)FUN_181f2be80(auStack_c8,auStackX_20[0],fVar12,fVar17,1,0);
            fVar12 = *pfVar10;
            fVar17 = pfVar10[1];
            fVar5 = pfVar10[2];
            fVar6 = pfVar10[3];
            if (fVar16 < 0.0) {
              fVar16 = 0.0;
            }
            else if (1.0 < fVar16) {
              fVar16 = 1.0;
            }
            lVar1 = *(longlong *)(param_1 + 0x30);
            if (*(int *)(lRam0000000182d3e9d0 + 0xe0) == 0) {
              FUN_18035c820(lRam0000000182d3e9d0);
            }
            uStack_e8 = CONCAT44(fVar19,fVar18);
            uStack_e0 = CONCAT44(0x3f800000,fVar20);
            if (lVar1 != 0) {
              uVar14 = *(undefined4 *)(*(longlong *)(lRam0000000182d3e9d0 + 0xb8) + 0xc);
              uStack_d8 = uStack_e8;
              uStack_d0 = uStack_e0;
              pcVar9 = pcRam0000000182ec0500;
              if ((pcRam0000000182ec0500 == (code *)0x0) &&
                 (pcVar9 = (code *)FUN_1802cf0c0(
                                                "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                ), pcVar9 == (code *)0x0)) {
                uVar11 = func_0x0001802ced60(
                                            "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                            );
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar11,0);
              }
              pcRam0000000182ec0500 = pcVar9;
              (*pcRam0000000182ec0500)(lVar1,uVar14,&uStack_d8);
              lVar1 = *(longlong *)(param_1 + 0x30);
              uStack_e8 = CONCAT44((fVar2 - fVar17) * fVar16 + fVar17,
                                   (fVar15 - fVar12) * fVar16 + fVar12);
              uStack_e0 = CONCAT44((fVar4 - fVar6) * fVar16 + fVar6,(fVar3 - fVar5) * fVar16 + fVar5
                                  );
              if (lVar1 != 0) {
                uVar14 = *(undefined4 *)(*(longlong *)(lRam0000000182d3e9d0 + 0xb8) + 0x10);
                pcVar9 = pcRam0000000182ec0500;
                if ((pcRam0000000182ec0500 == (code *)0x0) &&
                   (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar9 == (code *)0x0)) {
                  uVar11 = func_0x0001802ced60(
                                              "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                              );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar11,0);
                }
                pcRam0000000182ec0500 = pcVar9;
                (*pcRam0000000182ec0500)(lVar1,uVar14,&uStack_e8);
                if ((*(longlong *)(param_1 + 0x10) != 0) &&
                   (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x1d8), lVar1 != 0)) {
                  FUN_180402090(lVar1,0);
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

