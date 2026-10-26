// Ghidra pseudocode; not original source or compilable C.
// ev_e3047089ed3bddf343aa56096a84a88258fb30e6cebaaec81a180dd2500708e5

void ExposureUnnoticed2_Object3D_Player_Scripts_Other_HairCustomAdjuster__OnChangeBody__06000e9a
               (longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  longlong lVar7;
  code *pcVar8;
  float *pfVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float local_res20 [2];
  float local_a8;
  undefined4 local_a4 [3];
  float local_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  undefined1 local_88 [112];
  
  if (DAT_182eb767d == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58190);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58188);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58180);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182eb767d = '\x01';
  }
  lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
  local_a4[0] = 0;
  local_res20[0] = 0.0;
  local_a8 = 0.0;
  if (lVar2 != 0) {
    if (*(int *)(lVar2 + 0x104) != *(int *)(param_1 + 0x30)) {
      if (DAT_182eb548e == '\0') {
        FUN_1802f2810(&DAT_182d57ab8);
        LOCK();
        UNLOCK();
        DAT_182eb548e = '\x01';
      }
      lVar2 = **(longlong **)(DAT_182d57ab8 + 0xb8);
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
      if (lVar2 == 0) {
        return;
      }
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(longlong *)(lVar2 + 0x10) == 0) {
        return;
      }
    }
    lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
    if (lVar2 != 0) {
      if (*(longlong *)(lVar2 + 0x118) == 0) {
        uVar10 = FUN_1802c43a0(DAT_182d58368);
        FUN_1814df680(uVar10,param_1,DAT_182d58188,0);
        ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b(uVar10,1,0);
        return;
      }
      ExposureUnnoticed2_Object3D_Player_Scripts_Other_HairCustomAdjuster__InitializeIfNeed__06000e99
                (param_1,0);
      lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
      if ((lVar2 != 0) && (lVar2 = *(longlong *)(lVar2 + 0x118), lVar2 != 0)) {
        lVar7 = FUN_180e75f20(lVar2,*(undefined4 *)(param_1 + 0x30),DAT_182d58190);
        lVar2 = *(longlong *)(param_1 + 0x40);
        if (*(int *)(DAT_182d58180 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uVar11 = *(undefined4 *)(*(longlong *)(DAT_182d58180 + 0xb8) + 4);
        if (((*(longlong *)(param_1 + 0x38) != 0) && (lVar7 != 0)) &&
           (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x38), lVar3 != 0)) {
          uVar1 = *(uint *)(lVar7 + 0x14);
          if (*(uint *)(lVar3 + 0x18) <= uVar1) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dae0((longlong)(int)uVar1,uVar11);
          }
          if (lVar2 != 0) {
            FUN_181f11270(lVar2,uVar11,*(undefined8 *)(lVar3 + 0x20 + (longlong)(int)uVar1 * 8),0);
            lVar2 = *(longlong *)(param_1 + 0x40);
            fStack_8c = 1.0;
            fVar15 = (float)*(int *)(lVar7 + 0x18) / 255.0;
            fVar13 = (float)*(int *)(lVar7 + 0x1c) / 255.0;
            fVar16 = (float)*(int *)(lVar7 + 0x20) / 255.0;
            local_98 = fVar15;
            fStack_94 = fVar13;
            fStack_90 = fVar16;
            if (lVar2 != 0) {
              fStack_8c = 1.0;
              uVar11 = **(undefined4 **)(DAT_182d58180 + 0xb8);
              pcVar8 = DAT_182ec0500;
              if ((DAT_182ec0500 == (code *)0x0) &&
                 (pcVar8 = (code *)FUN_1802cf0c0(
                                                "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                ), pcVar8 == (code *)0x0)) {
                uVar10 = FUN_1802ced60(
                                      "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                      );
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar10,0);
              }
              DAT_182ec0500 = pcVar8;
              (*DAT_182ec0500)(lVar2,uVar11,&local_98);
              if ((fVar16 <= fVar13) || (fVar16 <= fVar15)) {
                if (fVar15 < fVar13) {
                  uVar11 = 0x40000000;
                  fVar12 = fVar13;
                }
                else {
                  uVar11 = 0;
                  fVar12 = fVar15;
                  fVar15 = fVar16;
                }
              }
              else {
                uVar11 = 0x40800000;
                fVar12 = fVar16;
                fVar15 = fVar13;
              }
              FUN_181f2bda0(uVar11,fVar12,0,fVar15,local_a4,local_res20,&local_a8,0);
              fVar15 = local_res20[0];
              if (0.0 < local_res20[0]) {
                fVar15 = 0.1;
                if (local_res20[0] < 0.1) {
                  fVar15 = local_res20[0];
                }
                fVar15 = fVar15 + local_res20[0];
                if (fVar15 < 0.0) {
                  fVar15 = 0.0;
                }
                else if (1.0 < fVar15) {
                  fVar15 = 1.0;
                }
              }
              fVar13 = local_a8 * 0.9;
              if (fVar13 < 0.0) {
                fVar13 = 0.0;
              }
              else if (1.0 < fVar13) {
                fVar13 = 1.0;
              }
              if (*(int *)(lVar7 + 0x24) < 0) {
                uVar11 = 0;
              }
              else {
                uVar11 = 0x3f20a0a1;
              }
              pfVar9 = (float *)FUN_181f2be80(&local_98,uVar11,0x3f800000,fVar13,1,0);
              fVar16 = *pfVar9;
              fVar12 = pfVar9[1];
              fVar4 = pfVar9[2];
              fVar5 = pfVar9[3];
              iVar6 = *(int *)(lVar7 + 0x24);
              if (iVar6 < 0) {
                iVar6 = -iVar6;
              }
              fVar14 = (float)iVar6 / 100.0;
              lVar2 = *(longlong *)(param_1 + 0x40);
              if (*(int *)(DAT_182d58180 + 0xe0) == 0) {
                FUN_18035c820(DAT_182d58180);
              }
              uVar11 = *(undefined4 *)(*(longlong *)(DAT_182d58180 + 0xb8) + 8);
              pfVar9 = (float *)FUN_181f2be80(local_88,local_a4[0],fVar15,fVar13,1,0);
              if (fVar14 < 0.0) {
                fVar14 = 0.0;
              }
              else if (1.0 < fVar14) {
                fVar14 = 1.0;
              }
              local_98 = (fVar16 - *pfVar9) * fVar14 + *pfVar9;
              fStack_94 = (fVar12 - pfVar9[1]) * fVar14 + pfVar9[1];
              fStack_90 = (fVar4 - pfVar9[2]) * fVar14 + pfVar9[2];
              fStack_8c = (fVar5 - pfVar9[3]) * fVar14 + pfVar9[3];
              if (lVar2 != 0) {
                pcVar8 = DAT_182ec0500;
                if ((DAT_182ec0500 == (code *)0x0) &&
                   (pcVar8 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar8 == (code *)0x0)) {
                  uVar10 = FUN_1802ced60(
                                        "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                        );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar10,0);
                }
                DAT_182ec0500 = pcVar8;
                (*DAT_182ec0500)(lVar2,uVar11,&local_98);
                return;
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

