// Ghidra pseudocode; not original source or compilable C.
// ev_cacc3a8e59afe36f2433fcb45733daf7f6a6652d6c5fb183111336bae48c7175

void ExposureUnnoticed2_Object3D_Player_Scripts_Other_FutanariController__SetupCosplayOption__06000e92
               (longlong param_1)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  code *pcVar5;
  longlong lVar6;
  longlong lVar7;
  float *pfVar8;
  undefined8 uVar9;
  float fVar10;
  undefined8 uVar11;
  float fVar12;
  undefined4 uVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float local_res8 [4];
  float local_res18 [2];
  undefined4 local_res20 [2];
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  
  if (DAT_182eb7676 == '\0') {
    FUN_1802f2810(&DAT_182d58248);
    LOCK();
    UNLOCK();
    DAT_182eb7676 = '\x01';
  }
  local_res20[0] = 0;
  local_res8[0] = 0.0;
  local_res18[0] = 0.0;
  if (((*(longlong *)(param_1 + 0x10) != 0) &&
      (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x70), lVar6 != 0)) &&
     (lVar6 = *(longlong *)(lVar6 + 0x188), lVar6 != 0)) {
    pcVar5 = DAT_182ec1148;
    if ((DAT_182ec1148 == (code *)0x0) &&
       (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_activeInHierarchy()"),
       pcVar5 == (code *)0x0)) {
      uVar9 = FUN_1802ced60("UnityEngine.GameObject::get_activeInHierarchy()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    DAT_182ec1148 = pcVar5;
    cVar3 = (*DAT_182ec1148)(lVar6);
    if (cVar3 == '\0') {
      return;
    }
    ExposureUnnoticed2_Object3D_Player_Scripts_Other_FutanariController__SetupPaint__06000e91
              (param_1,0);
    if (((*(longlong *)(param_1 + 0x10) != 0) &&
        (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x70), lVar6 != 0)) &&
       (lVar6 = *(longlong *)(lVar6 + 0x1b8), lVar6 != 0)) {
      pcVar5 = DAT_182ec01b0;
      if ((DAT_182ec01b0 == (code *)0x0) &&
         (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Renderer::GetMaterialArray()"),
         pcVar5 == (code *)0x0)) {
        uVar9 = FUN_1802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar9,0);
      }
      DAT_182ec01b0 = pcVar5;
      lVar6 = (*DAT_182ec01b0)(lVar6);
      if (lVar6 != 0) {
        if (*(int *)(lVar6 + 0x18) == 0) {
LAB_1804028e5:
                    /* WARNING: Subroutine does not return */
          FUN_18031dae0();
        }
        lVar6 = *(longlong *)(lVar6 + 0x20);
        lVar7 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetCosplayPartsOptionData__06001548
                          (0x272b,0);
        if (*(int *)(DAT_182d58248 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d58248);
        }
        if (lVar7 != 0) {
          if (*(char *)(lVar7 + 0x24) == '\0') {
            uVar9 = 0x3f8000003f800000;
            uVar11 = 0x3f8000003f800000;
          }
          else {
            uVar9 = 0;
            uVar11 = 0x3f80000000000000;
          }
          uVar13 = *(undefined4 *)(*(longlong *)(DAT_182d58248 + 0xb8) + 0x18);
          if (lVar6 != 0) {
            pcVar5 = DAT_182ec0500;
            local_e8 = uVar9;
            uStack_e0 = uVar11;
            if ((DAT_182ec0500 == (code *)0x0) &&
               (pcVar5 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                              ), pcVar5 == (code *)0x0)) {
              uVar9 = FUN_1802ced60(
                                   "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar9,0);
            }
            DAT_182ec0500 = pcVar5;
            (*DAT_182ec0500)(lVar6,uVar13,&local_e8);
            if (*(int *)(lVar7 + 0x20) == 0) {
              fVar12 = 0.0;
            }
            else {
              fVar12 = 0.8;
            }
            fVar17 = ((float)*(int *)(lVar7 + 0x14) / 255.0) * fVar12;
            fVar18 = ((float)*(int *)(lVar7 + 0x18) / 255.0) * fVar12;
            fVar12 = ((float)*(int *)(lVar7 + 0x10) / 255.0) * fVar12;
            if (((fVar18 <= fVar17) || (fVar10 = fVar18, fVar15 = fVar17, fVar18 <= fVar12)) &&
               (fVar10 = fVar17, fVar15 = fVar12, fVar17 <= fVar12)) {
              fVar10 = fVar12;
              fVar15 = fVar18;
            }
            FUN_181f2bda0(local_res8,fVar10,0,fVar15,local_res20,local_res8,local_res18,0);
            fVar10 = local_res8[0];
            if (0.0 < local_res8[0]) {
              fVar10 = 0.1;
              if (local_res8[0] < 0.1) {
                fVar10 = local_res8[0];
              }
              fVar10 = fVar10 + local_res8[0];
              if (fVar10 < 0.0) {
                fVar10 = 0.0;
              }
              else if (1.0 < fVar10) {
                fVar10 = 1.0;
              }
            }
            fVar15 = local_res18[0] * 0.9;
            if (fVar15 < 0.0) {
              fVar15 = 0.0;
            }
            else if (1.0 < fVar15) {
              fVar15 = 1.0;
            }
            if (*(int *)(lVar7 + 0x1c) < 0) {
              uVar13 = 0;
            }
            else {
              uVar13 = 0x3f20a0a1;
            }
            pfVar8 = (float *)FUN_181f2be80(&local_c8,uVar13,0x3f800000,fVar15,1,0);
            fVar16 = *pfVar8;
            fVar19 = pfVar8[1];
            fVar1 = pfVar8[2];
            fVar2 = pfVar8[3];
            iVar4 = *(int *)(lVar7 + 0x1c);
            if (iVar4 < 0) {
              iVar4 = -iVar4;
            }
            fVar14 = (float)iVar4 / 100.0;
            pfVar8 = (float *)FUN_181f2be80(&local_c8,local_res20[0],fVar10,fVar15,1,0);
            if (fVar14 < 0.0) {
              fVar14 = 0.0;
            }
            else if (1.0 < fVar14) {
              fVar14 = 1.0;
            }
            fVar10 = (fVar16 - *pfVar8) * fVar14 + *pfVar8;
            fVar15 = (fVar19 - pfVar8[1]) * fVar14 + pfVar8[1];
            fVar16 = (fVar1 - pfVar8[2]) * fVar14 + pfVar8[2];
            fVar19 = (fVar2 - pfVar8[3]) * fVar14 + pfVar8[3];
            if (*(int *)(DAT_182d58248 + 0xe0) == 0) {
              FUN_18035c820(DAT_182d58248);
            }
            uVar13 = *(undefined4 *)(*(longlong *)(DAT_182d58248 + 0xb8) + 0xc);
            local_d8 = CONCAT44(fVar17,fVar12);
            uStack_d0 = CONCAT44(0x3f800000,fVar18);
            local_e8 = CONCAT44(fVar17,fVar12);
            uStack_e0 = CONCAT44(0x3f800000,fVar18);
            pcVar5 = DAT_182ec0500;
            if ((DAT_182ec0500 == (code *)0x0) &&
               (pcVar5 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                              ), pcVar5 == (code *)0x0)) {
              uVar9 = FUN_1802ced60(
                                   "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar9,0);
            }
            DAT_182ec0500 = pcVar5;
            (*DAT_182ec0500)(lVar6,uVar13,&local_d8);
            uVar13 = *(undefined4 *)(*(longlong *)(DAT_182d58248 + 0xb8) + 0x24);
            local_e8 = CONCAT44(fVar15,fVar10);
            uStack_e0 = CONCAT44(fVar19,fVar16);
            pcVar5 = DAT_182ec0500;
            if ((DAT_182ec0500 == (code *)0x0) &&
               (pcVar5 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                              ), pcVar5 == (code *)0x0)) {
              uVar9 = FUN_1802ced60(
                                   "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar9,0);
            }
            DAT_182ec0500 = pcVar5;
            (*DAT_182ec0500)(lVar6,uVar13,&local_e8);
            if (((*(longlong *)(param_1 + 0x10) != 0) &&
                (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x70), lVar6 != 0)) &&
               (lVar6 = *(longlong *)(lVar6 + 0x1c0), lVar6 != 0)) {
              pcVar5 = DAT_182ec01b0;
              if ((DAT_182ec01b0 == (code *)0x0) &&
                 (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Renderer::GetMaterialArray()"),
                 pcVar5 == (code *)0x0)) {
                uVar9 = FUN_1802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar9,0);
              }
              DAT_182ec01b0 = pcVar5;
              lVar6 = (*DAT_182ec01b0)(lVar6);
              if (lVar6 != 0) {
                if (*(int *)(lVar6 + 0x18) == 0) goto LAB_1804028e5;
                if (*(char *)(lVar7 + 0x24) == '\0') {
                  uVar9 = 0x3f8000003f800000;
                  uVar11 = 0x3f8000003f800000;
                }
                else {
                  uVar9 = 0;
                  uVar11 = 0x3f80000000000000;
                }
                lVar6 = *(longlong *)(lVar6 + 0x20);
                uVar13 = *(undefined4 *)(*(longlong *)(DAT_182d58248 + 0xb8) + 0x18);
                if (lVar6 != 0) {
                  pcVar5 = DAT_182ec0500;
                  local_d8 = uVar9;
                  uStack_d0 = uVar11;
                  if ((DAT_182ec0500 == (code *)0x0) &&
                     (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar5 == (code *)0x0)) {
                    uVar9 = FUN_1802ced60(
                                         "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                         );
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar9,0);
                  }
                  DAT_182ec0500 = pcVar5;
                  (*DAT_182ec0500)(lVar6,uVar13,&local_d8);
                  if (*(int *)(DAT_182d58248 + 0xe0) == 0) {
                    FUN_18035c820(DAT_182d58248);
                  }
                  local_e8 = CONCAT44(fVar17,fVar12);
                  uVar13 = *(undefined4 *)(*(longlong *)(DAT_182d58248 + 0xb8) + 0xc);
                  uStack_e0 = CONCAT44(0x3f800000,fVar18);
                  local_c8 = local_e8;
                  uStack_c0 = uStack_e0;
                  pcVar5 = DAT_182ec0500;
                  if ((DAT_182ec0500 == (code *)0x0) &&
                     (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar5 == (code *)0x0)) {
                    uVar9 = FUN_1802ced60(
                                         "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                         );
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar9,0);
                  }
                  DAT_182ec0500 = pcVar5;
                  (*DAT_182ec0500)(lVar6,uVar13,&local_c8);
                  uVar13 = *(undefined4 *)(*(longlong *)(DAT_182d58248 + 0xb8) + 0x24);
                  local_d8 = CONCAT44(fVar15,fVar10);
                  uStack_d0 = CONCAT44(fVar19,fVar16);
                  pcVar5 = DAT_182ec0500;
                  if ((DAT_182ec0500 == (code *)0x0) &&
                     (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar5 == (code *)0x0)) {
                    uVar9 = FUN_1802ced60(
                                         "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                         );
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar9,0);
                  }
                  DAT_182ec0500 = pcVar5;
                  (*DAT_182ec0500)(lVar6,uVar13,&local_d8);
                  return;
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

