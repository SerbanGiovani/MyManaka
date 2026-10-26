// Ghidra pseudocode; not original source or compilable C.
// ev_657222ee36618837bad219457cd98f55c1b884066ecb43af2300a7e2a7ac548a

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyCustomizeAdjuster__OnChangeBody__06000cc1
               (longlong param_1)

{
  longlong lVar1;
  undefined1 auVar2 [16];
  undefined4 uVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  longlong lVar8;
  longlong lVar9;
  undefined4 *puVar10;
  undefined8 *puVar11;
  undefined8 uVar12;
  int iVar13;
  uint uVar14;
  bool bVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined8 uStack_118;
  float fStack_110;
  undefined8 uStack_108;
  float fStack_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined1 auStack_c8 [176];
  
  if (cRam0000000182eb83aa == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ea68);
    LOCK();
    UNLOCK();
    cRam0000000182eb83aa = '\x01';
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
  if (lVar8 == 0) goto code_r0x000180635022;
  bVar15 = DAT_182eb548b == '\0';
  lVar9 = *(longlong *)(param_1 + 0x50);
  *(float *)(param_1 + 0x28) = (float)*(int *)(lVar8 + 0x10) / 160.0;
  if (bVar15) {
    FUN_1802f2810(&DAT_182d522a8);
    LOCK();
    UNLOCK();
    DAT_182eb548b = '\x01';
  }
  fVar17 = *(float *)(param_1 + 0x4c);
  uStack_d8 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0xc);
  fVar16 = *(float *)(param_1 + 0x28);
  fVar19 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x14) * fVar17 * fVar16;
  if (lVar9 == 0) {
code_r0x00018063545f:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uStack_118 = CONCAT44((float)((ulonglong)uStack_d8 >> 0x20) * fVar17 * fVar16,
                        (float)uStack_d8 * fVar17 * fVar16);
  pcVar7 = DAT_182ec16e0;
  fStack_110 = fVar19;
  if ((DAT_182ec16e0 == (code *)0x0) &&
     (pcVar7 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                    ), pcVar7 == (code *)0x0)) {
    uVar12 = FUN_1802ced60("UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar12,0);
  }
  DAT_182ec16e0 = pcVar7;
  (*DAT_182ec16e0)(lVar9,&uStack_118);
  lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
  if (lVar8 == 0) goto code_r0x00018063545f;
  if (*(char *)(lVar8 + 0x110) == '\0') {
    if ((*(longlong *)(param_1 + 0x40) == 0) ||
       (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x70), lVar8 == 0))
    goto code_r0x000180635022;
    lVar8 = *(longlong *)(lVar8 + 0xc0);
    if (DAT_182eb548b == '\0') {
      FUN_1802f2810(&DAT_182d522a8);
      LOCK();
      UNLOCK();
      DAT_182eb548b = '\x01';
    }
    fVar17 = *(float *)(param_1 + 0x48);
    uStack_d8 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0xc);
    lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
    if (lVar9 == 0) goto code_r0x000180635022;
    fVar16 = ((float)*(int *)(lVar9 + 0x14) / 50.0 - 1.0) * 0.2 + 1.0;
    fStack_100 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x14) * fVar17 * fVar16;
    if (lVar8 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    uStack_108 = CONCAT44((float)((ulonglong)uStack_d8 >> 0x20) * fVar17 * fVar16,
                          (float)uStack_d8 * fVar17 * fVar16);
    pcVar7 = DAT_182ec16e0;
    if ((DAT_182ec16e0 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                      ), pcVar7 == (code *)0x0)) {
      uVar12 = FUN_1802ced60("UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)")
      ;
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar12,0);
    }
  }
  else {
    if (lVar8 == 0) goto code_r0x000180635022;
    fVar17 = (float)(*(int *)(lVar8 + 0x10) + -0x78) / 40.0;
    if (1.25 <= fVar17) {
      fVar17 = 1.25;
    }
    if ((*(longlong *)(param_1 + 0x40) == 0) ||
       (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x70), lVar8 == 0))
    goto code_r0x000180635022;
    lVar8 = *(longlong *)(lVar8 + 0xc0);
    if (DAT_182eb548b == '\0') {
      FUN_1802f2810(&DAT_182d522a8);
      LOCK();
      UNLOCK();
      DAT_182eb548b = '\x01';
    }
    fVar16 = *(float *)(param_1 + 0x48);
    uStack_d8 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0xc);
    fVar17 = (fVar17 - 1.0) * -0.1 + 1.0;
    fStack_100 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x14) * fVar16 * fVar17;
    if (lVar8 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    uStack_108 = CONCAT44((float)((ulonglong)uStack_d8 >> 0x20) * fVar16 * fVar17,
                          (float)uStack_d8 * fVar16 * fVar17);
    pcVar7 = DAT_182ec16e0;
    if ((DAT_182ec16e0 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                      ), pcVar7 == (code *)0x0)) {
      uVar12 = FUN_1802ced60("UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)")
      ;
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar12,0);
    }
  }
  DAT_182ec16e0 = pcVar7;
  (*DAT_182ec16e0)(lVar8,&uStack_108);
  lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
  if (lVar8 == 0) goto code_r0x000180635022;
  if (*(int *)(lVar8 + 0x1c) < 0x32) {
    fVar17 = 1.0 - ((float)(0x32 - *(int *)(lVar8 + 0x1c)) / 50.0) * 0.2;
  }
  else {
    fVar17 = ((float)(*(int *)(lVar8 + 0x1c) + -0x32) / 50.0) * 0.4 + 1.0;
  }
  if (((*(longlong *)(param_1 + 0x40) == 0) ||
      (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x70), lVar8 == 0)) ||
     (lVar8 = *(longlong *)(lVar8 + 200), lVar8 == 0)) {
code_r0x000180635453:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uStack_118 = CONCAT44(0x3f800000,fVar17);
  pcVar7 = DAT_182ec16e0;
  fStack_110 = fVar17;
  if ((DAT_182ec16e0 == (code *)0x0) &&
     (pcVar7 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                    ), pcVar7 == (code *)0x0)) {
    uVar12 = FUN_1802ced60("UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar12,0);
  }
  DAT_182ec16e0 = pcVar7;
  (*DAT_182ec16e0)(lVar8,&uStack_118);
  lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
  if (lVar8 == 0) goto code_r0x000180635453;
  iVar6 = *(int *)(lVar8 + 0x20) + (*(int *)(lVar8 + 0x24) + *(int *)(lVar8 + 0x28) * 2) * 2;
  iVar5 = iVar6 * 2 + -100;
  *(int *)(param_1 + 0x24) = iVar6;
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  else if (2000 < iVar5) {
    iVar5 = 2000;
  }
  iVar13 = iVar6 * 2;
  *(int *)(param_1 + 0x1c) = iVar5;
  if (iVar13 < 0) {
    iVar13 = 0;
  }
  else if (100 < iVar13) {
    iVar13 = 100;
  }
  lVar8 = *(longlong *)(param_1 + 0x58);
  *(int *)(param_1 + 0x20) = iVar13;
  if (lVar8 == 0) goto code_r0x000180635453;
  pcVar7 = DAT_182ec0728;
  if ((DAT_182ec0728 == (code *)0x0) &&
     (pcVar7 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.SkinnedMeshRenderer::SetBlendShapeWeight(System.Int32,System.Single)"
                                    ), pcVar7 == (code *)0x0)) {
    uVar12 = FUN_1802ced60(
                          "UnityEngine.SkinnedMeshRenderer::SetBlendShapeWeight(System.Int32,System.Single)"
                          );
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar12,0);
  }
  DAT_182ec0728 = pcVar7;
  (*DAT_182ec0728)(lVar8,4);
  lVar8 = *(longlong *)(param_1 + 0x58);
  if (lVar8 == 0) goto code_r0x000180635453;
  pcVar7 = DAT_182ec0728;
  if ((DAT_182ec0728 == (code *)0x0) &&
     (pcVar7 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.SkinnedMeshRenderer::SetBlendShapeWeight(System.Int32,System.Single)"
                                    ), pcVar7 == (code *)0x0)) {
    uVar12 = FUN_1802ced60(
                          "UnityEngine.SkinnedMeshRenderer::SetBlendShapeWeight(System.Int32,System.Single)"
                          );
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar12,0);
  }
  DAT_182ec0728 = pcVar7;
  (*DAT_182ec0728)(lVar8,3);
  if (((*(longlong *)(param_1 + 0x40) == 0) ||
      (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x70), lVar8 == 0)) ||
     (lVar8 = *(longlong *)(lVar8 + 0x208), lVar8 == 0)) goto code_r0x000180635453;
  pcVar7 = DAT_182ec01b0;
  if ((DAT_182ec01b0 == (code *)0x0) &&
     (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Renderer::GetMaterialArray()"),
     pcVar7 == (code *)0x0)) {
    uVar12 = FUN_1802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar12,0);
  }
  DAT_182ec01b0 = pcVar7;
  lVar8 = (*DAT_182ec01b0)(lVar8);
  if (lVar8 == 0) goto code_r0x000180635453;
  if (*(uint *)(lVar8 + 0x18) < 2) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dae0();
  }
  lVar8 = *(longlong *)(lVar8 + 0x28);
  if (*(int *)(lRam0000000182d3ea68 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d3ea68);
  }
  uVar21 = *(undefined4 *)(*(longlong *)(lRam0000000182d3ea68 + 0xb8) + 8);
  lVar9 = ExposureUnnoticed2_Master_Common_MCustomizeColor__get_Instance__06001340(0);
  if (iVar6 < 0x14) {
    if (lVar9 == 0) goto code_r0x000180635022;
    uVar12 = *(undefined8 *)(lVar9 + 0x38);
  }
  else {
    if (lVar9 == 0) goto code_r0x000180635022;
    uVar12 = *(undefined8 *)(lVar9 + 0x30);
  }
  if (lVar8 != 0) {
    pcVar7 = DAT_182ec04e0;
    if ((DAT_182ec04e0 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Material::SetTextureImpl(System.Int32,UnityEngine.Texture)"
                                      ), pcVar7 == (code *)0x0)) {
      uVar12 = FUN_1802ced60(
                            "UnityEngine.Material::SetTextureImpl(System.Int32,UnityEngine.Texture)"
                            );
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar12,0);
    }
    DAT_182ec04e0 = pcVar7;
    (*DAT_182ec04e0)(lVar8,uVar21,uVar12);
    iVar5 = iVar6 + -200;
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    else if (0x15e < iVar5) {
      iVar5 = 0x15e;
    }
    iVar6 = iVar6 + -0x15e;
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    else if (0x15e < iVar6) {
      iVar6 = 0x15e;
    }
    fVar17 = (float)iVar6 * 0.05 + (float)iVar5 * -0.1;
    if ((*(longlong *)(param_1 + 0x40) != 0) &&
       (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x70), lVar8 != 0)) {
      lVar8 = *(longlong *)(lVar8 + 0xd0);
      uStack_108 = (ulonglong)(uint)(fVar17 * 0.017453292) << 0x20;
      fStack_100 = 0.0;
      uStack_d8 = 0;
      uStack_d0 = 0;
      pcVar7 = DAT_182ec0e88;
      if ((DAT_182ec0e88 == (code *)0x0) &&
         (pcVar7 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Quaternion::Internal_FromEulerRad_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                        ), pcVar7 == (code *)0x0)) {
        uVar12 = FUN_1802ced60(
                              "UnityEngine.Quaternion::Internal_FromEulerRad_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                              );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar12,0);
      }
      DAT_182ec0e88 = pcVar7;
      (*DAT_182ec0e88)(&uStack_108,&uStack_d8);
      auVar2 = *(undefined1 (*) [16])(param_1 + 200);
      fVar16 = auVar2._0_4_;
      fVar19 = auVar2._4_4_;
      fVar18 = auVar2._8_4_;
      fVar4 = auVar2._12_4_;
      uStack_e8 = CONCAT44((fVar4 * uStack_d8._4_4_ + fVar19 * uStack_d0._4_4_ +
                           fVar16 * (float)uStack_d0) - fVar18 * (float)uStack_d8,
                           (fVar4 * (float)uStack_d8 + fVar16 * uStack_d0._4_4_ +
                           fVar18 * uStack_d8._4_4_) - fVar19 * (float)uStack_d0);
      uStack_e0 = CONCAT44(((fVar4 * uStack_d0._4_4_ - fVar16 * (float)uStack_d8) -
                           fVar19 * uStack_d8._4_4_) - fVar18 * (float)uStack_d0,
                           (fVar4 * (float)uStack_d0 + fVar18 * uStack_d0._4_4_ +
                           fVar19 * (float)uStack_d8) - fVar16 * uStack_d8._4_4_);
      if (lVar8 != 0) {
        uStack_f8 = uStack_e8;
        uStack_f0 = uStack_e0;
        pcVar7 = DAT_182ec16d0;
        if ((DAT_182ec16d0 == (code *)0x0) &&
           (pcVar7 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::set_localRotation_Injected(UnityEngine.Quaternion&)"
                                          ), pcVar7 == (code *)0x0)) {
          uVar12 = FUN_1802ced60(
                                "UnityEngine.Transform::set_localRotation_Injected(UnityEngine.Quaternion&)"
                                );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar12,0);
        }
        DAT_182ec16d0 = pcVar7;
        (*DAT_182ec16d0)(lVar8,&uStack_f8);
        if ((*(longlong *)(param_1 + 0x40) != 0) &&
           (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x70), lVar8 != 0)) {
          lVar8 = *(longlong *)(lVar8 + 0xd8);
          uStack_108 = (ulonglong)(uint)(-fVar17 * 0.017453292) << 0x20;
          fStack_100 = 0.0;
          uStack_d8 = 0;
          uStack_d0 = 0;
          pcVar7 = DAT_182ec0e88;
          if ((DAT_182ec0e88 == (code *)0x0) &&
             (pcVar7 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Quaternion::Internal_FromEulerRad_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                            ), pcVar7 == (code *)0x0)) {
            uVar12 = FUN_1802ced60(
                                  "UnityEngine.Quaternion::Internal_FromEulerRad_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                  );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar12,0);
          }
          DAT_182ec0e88 = pcVar7;
          (*DAT_182ec0e88)(&uStack_108,&uStack_d8);
          auVar2 = *(undefined1 (*) [16])(param_1 + 200);
          fVar17 = auVar2._0_4_;
          fVar16 = auVar2._4_4_;
          fVar19 = auVar2._8_4_;
          fVar18 = auVar2._12_4_;
          uStack_e8 = CONCAT44((fVar18 * uStack_d8._4_4_ + fVar16 * uStack_d0._4_4_ +
                               fVar17 * (float)uStack_d0) - fVar19 * (float)uStack_d8,
                               (fVar18 * (float)uStack_d8 + fVar17 * uStack_d0._4_4_ +
                               fVar19 * uStack_d8._4_4_) - fVar16 * (float)uStack_d0);
          uStack_e0 = CONCAT44(((fVar18 * uStack_d0._4_4_ - fVar17 * (float)uStack_d8) -
                               fVar16 * uStack_d8._4_4_) - fVar19 * (float)uStack_d0,
                               (fVar19 * uStack_d0._4_4_ + fVar18 * (float)uStack_d0 +
                               fVar16 * (float)uStack_d8) - fVar17 * uStack_d8._4_4_);
          if (lVar8 != 0) {
            pcVar7 = DAT_182ec16d0;
            if ((DAT_182ec16d0 == (code *)0x0) &&
               (pcVar7 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.Transform::set_localRotation_Injected(UnityEngine.Quaternion&)"
                                              ), pcVar7 == (code *)0x0)) {
              uVar12 = FUN_1802ced60(
                                    "UnityEngine.Transform::set_localRotation_Injected(UnityEngine.Quaternion&)"
                                    );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar12,0);
            }
            DAT_182ec16d0 = pcVar7;
            (*DAT_182ec16d0)(lVar8,&uStack_e8);
            if ((*(longlong *)(param_1 + 0x40) != 0) &&
               (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x138), lVar8 != 0)) {
              ExposureUnnoticed2_Object3D_Player_Scripts_PlayerTitController__OnChangeCostumeCosplayEvent__06000e41
                        (lVar8,0,0);
              lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
              if (lVar8 != 0) {
                if (*(int *)(lVar8 + 0x30) < 0x32) {
                  if (DAT_182eb548b == '\0') {
                    FUN_1802f2810(&DAT_182d522a8);
                    LOCK();
                    UNLOCK();
                    DAT_182eb548b = '\x01';
                  }
                  lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                  if (lVar8 == 0) goto code_r0x000180635022;
                  uStack_d8 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0xc);
                  fVar16 = 1.0 - ((float)(0x32 - *(int *)(lVar8 + 0x30)) / 50.0) * 0.5;
                  fVar17 = fVar16 * (float)uStack_d8;
                  fVar19 = fVar16 * *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x14);
                  fVar16 = fVar16 * (float)((ulonglong)uStack_d8 >> 0x20);
                }
                else {
                  if (DAT_182eb548b == '\0') {
                    FUN_1802f2810(&DAT_182d522a8);
                    LOCK();
                    UNLOCK();
                    DAT_182eb548b = '\x01';
                  }
                  lVar8 = *(longlong *)(DAT_182d522a8 + 0xb8);
                  lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                  if (lVar9 == 0) goto code_r0x000180635022;
                  lVar1 = *(longlong *)(lVar8 + 0xc);
                  fVar18 = (float)(*(int *)(lVar9 + 0x30) + -0x32) / 10.0;
                  if (fVar18 < 0.0) {
                    fVar18 = 0.0;
                  }
                  else if (1.0 < fVar18) {
                    fVar18 = 1.0;
                  }
                  uStack_108._0_4_ = (float)lVar1;
                  uStack_108._4_4_ = (float)((ulonglong)lVar1 >> 0x20);
                  fVar17 = (1.0 - (float)uStack_108) * fVar18 + (float)uStack_108;
                  fVar16 = (0.75 - uStack_108._4_4_) * fVar18 + uStack_108._4_4_;
                  lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                  uStack_108 = lVar1;
                  if (lVar9 == 0) goto code_r0x000180635022;
                  fVar19 = ((float)(*(int *)(lVar9 + 0x30) + -0x32) / 50.0) * 3.0 + 1.0;
                  fVar17 = fVar19 * fVar17;
                  fVar16 = fVar19 * fVar16;
                  fVar19 = fVar19 * ((1.0 - *(float *)(lVar8 + 0x14)) * fVar18 +
                                    *(float *)(lVar8 + 0x14));
                }
                if (((*(longlong *)(param_1 + 0x40) != 0) &&
                    (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x70), lVar8 != 0)) &&
                   (lVar8 = *(longlong *)(lVar8 + 0xe0), lVar8 != 0)) {
                  uStack_108 = CONCAT44(fVar16,fVar17);
                  pcVar7 = DAT_182ec16e0;
                  fStack_100 = fVar19;
                  if ((DAT_182ec16e0 == (code *)0x0) &&
                     (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar7 == (code *)0x0)) {
                    uVar12 = FUN_1802ced60(
                                          "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                          );
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar12,0);
                  }
                  DAT_182ec16e0 = pcVar7;
                  (*DAT_182ec16e0)(lVar8,&uStack_108);
                  if (((*(longlong *)(param_1 + 0x40) != 0) &&
                      (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x70), lVar8 != 0)) &&
                     (lVar8 = *(longlong *)(lVar8 + 0xe8), lVar8 != 0)) {
                    uStack_118 = CONCAT44(fVar16,fVar17);
                    pcVar7 = DAT_182ec16e0;
                    fStack_110 = fVar19;
                    if ((DAT_182ec16e0 == (code *)0x0) &&
                       (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar7 == (code *)0x0)) {
                      uVar12 = FUN_1802ced60(
                                            "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                            );
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar12,0);
                    }
                    DAT_182ec16e0 = pcVar7;
                    (*DAT_182ec16e0)(lVar8,&uStack_118);
                    lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                    if (lVar8 != 0) {
                      fVar17 = ((float)*(int *)(lVar8 + 0x34) / 100.0) * 0.5 + 1.0;
                      if (((*(longlong *)(param_1 + 0x40) != 0) &&
                          (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x70), lVar8 != 0))
                         && (lVar8 = *(longlong *)(lVar8 + 0x138), lVar8 != 0)) {
                        uStack_f8 = CONCAT44(0x3f800000,fVar17);
                        uStack_f0 = CONCAT44(uStack_f0._4_4_,fVar17);
                        pcVar7 = DAT_182ec16e0;
                        if ((DAT_182ec16e0 == (code *)0x0) &&
                           (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar7 == (code *)0x0)) {
                          uVar12 = FUN_1802ced60(
                                                "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                );
                    /* WARNING: Subroutine does not return */
                          FUN_1802cca90(uVar12,0);
                        }
                        DAT_182ec16e0 = pcVar7;
                        (*DAT_182ec16e0)(lVar8,&uStack_f8);
                        lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                        if (lVar8 != 0) {
                          if (*(int *)(lVar8 + 0x3c) < 0x32) {
                            fVar17 = 1.0 - ((float)(0x32 - *(int *)(lVar8 + 0x3c)) / 50.0) * 0.2;
                          }
                          else {
                            fVar17 = ((float)(*(int *)(lVar8 + 0x3c) + -0x32) / 50.0) * 0.4 + 1.0;
                          }
                          lVar8 = *(longlong *)(DAT_182d58398 + 0xb8);
                          if (*(int *)(*(longlong *)(lVar8 + 0x60) + 0x40) < 0x32) {
                            if (*(longlong *)(lVar8 + 0x60) == 0) goto code_r0x000180635022;
                            fVar16 = 1.0 - ((float)(0x32 - *(int *)(*(longlong *)(lVar8 + 0x60) +
                                                                   0x40)) / 50.0) * 0.2;
                          }
                          else {
                            if (*(longlong *)(lVar8 + 0x60) == 0) goto code_r0x000180635022;
                            fVar16 = ((float)(*(int *)(*(longlong *)(lVar8 + 0x60) + 0x40) + -0x32)
                                     / 50.0) * 0.4 + 1.0;
                          }
                          *(float *)(param_1 + 0x30) = fVar16;
                          if (((*(longlong *)(param_1 + 0x40) != 0) &&
                              (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x70),
                              lVar8 != 0)) && (lVar8 = *(longlong *)(lVar8 + 0xa0), lVar8 != 0)) {
                            uStack_108 = CONCAT44(fVar16,fVar17);
                            pcVar7 = DAT_182ec16e0;
                            fStack_100 = fVar17;
                            if ((DAT_182ec16e0 == (code *)0x0) &&
                               (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar7 == (code *)0x0)) {
                              uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                              FUN_1802cca90(uVar12,0);
                            }
                            DAT_182ec16e0 = pcVar7;
                            (*DAT_182ec16e0)(lVar8,&uStack_108);
                            if (((*(longlong *)(param_1 + 0x40) != 0) &&
                                (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x70),
                                lVar8 != 0)) && (lVar8 = *(longlong *)(lVar8 + 0xa8), lVar8 != 0)) {
                              uStack_118 = CONCAT44(fVar16,fVar17);
                              pcVar7 = DAT_182ec16e0;
                              fStack_110 = fVar17;
                              if ((DAT_182ec16e0 == (code *)0x0) &&
                                 (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                FUN_1802cca90(uVar12,0);
                              }
                              DAT_182ec16e0 = pcVar7;
                              (*DAT_182ec16e0)(lVar8,&uStack_118);
                              lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                              if (lVar8 != 0) {
                                fVar17 = (float)*(int *)(lVar8 + 0x40) / 50.0 - 1.0;
                                if (*(int *)(lVar8 + 0x40) < 0x32) {
                                  fVar17 = fVar17 * 0.07;
                                }
                                else {
                                  fVar17 = fVar17 * 0.14;
                                }
                                *(float *)(param_1 + 0x10) = *(float *)(param_1 + 0x10) + fVar17;
                                lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                                if (lVar8 == 0) goto code_r0x000180635022;
                                if (*(int *)(lVar8 + 0x44) < 0x32) {
                                  fVar17 = 1.0 - ((float)(0x32 - *(int *)(lVar8 + 0x44)) / 50.0) *
                                                 0.2;
                                }
                                else {
                                  fVar17 = ((float)(*(int *)(lVar8 + 0x44) + -0x32) / 50.0) * 0.6 +
                                           1.0;
                                }
                                lVar8 = *(longlong *)(DAT_182d58398 + 0xb8);
                                if (*(int *)(*(longlong *)(lVar8 + 0x60) + 0x48) < 0x32) {
                                  if (*(longlong *)(lVar8 + 0x60) == 0) goto code_r0x000180635022;
                                  fVar16 = 1.0 - ((float)(0x32 - *(int *)(*(longlong *)
                                                                           (lVar8 + 0x60) + 0x48)) /
                                                 50.0) * 0.2;
                                }
                                else {
                                  if (*(longlong *)(lVar8 + 0x60) == 0) goto code_r0x000180635022;
                                  fVar16 = ((float)(*(int *)(*(longlong *)(lVar8 + 0x60) + 0x48) +
                                                   -0x32) / 50.0) * 0.4 + 1.0;
                                }
                                *(float *)(param_1 + 0x2c) = fVar16;
                                if (((*(longlong *)(param_1 + 0x40) != 0) &&
                                    (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x70),
                                    lVar8 != 0)) &&
                                   (lVar8 = *(longlong *)(lVar8 + 0xb0), lVar8 != 0)) {
                                  uStack_f8 = CONCAT44(fVar16,fVar17);
                                  uStack_f0 = CONCAT44(uStack_f0._4_4_,fVar17);
                                  pcVar7 = DAT_182ec16e0;
                                  if ((DAT_182ec16e0 == (code *)0x0) &&
                                     (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                    uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                    FUN_1802cca90(uVar12,0);
                                  }
                                  DAT_182ec16e0 = pcVar7;
                                  (*DAT_182ec16e0)(lVar8,&uStack_f8);
                                  if (((*(longlong *)(param_1 + 0x40) != 0) &&
                                      (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x70),
                                      lVar8 != 0)) &&
                                     (lVar8 = *(longlong *)(lVar8 + 0xb8), lVar8 != 0)) {
                                    uStack_e8 = CONCAT44(fVar16,fVar17);
                                    uStack_e0 = CONCAT44(uStack_e0._4_4_,fVar17);
                                    pcVar7 = DAT_182ec16e0;
                                    if ((DAT_182ec16e0 == (code *)0x0) &&
                                       (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                      uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                      FUN_1802cca90(uVar12,0);
                                    }
                                    DAT_182ec16e0 = pcVar7;
                                    (*DAT_182ec16e0)(lVar8,&uStack_e8);
                                    lVar8 = *(longlong *)
                                             (*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                                    if (lVar8 != 0) {
                                      fVar17 = (float)*(int *)(lVar8 + 0x48) / 50.0 - 1.0;
                                      if (*(int *)(lVar8 + 0x48) < 0x32) {
                                        fVar17 = fVar17 * 0.07;
                                      }
                                      else {
                                        fVar17 = fVar17 * 0.14;
                                      }
                                      *(float *)(param_1 + 0x10) =
                                           *(float *)(param_1 + 0x10) + fVar17;
                                      lVar8 = *(longlong *)
                                               (*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                                      if (lVar8 == 0) goto code_r0x000180635022;
                                      if (*(int *)(lVar8 + 0x4c) < 0x32) {
                                        fVar17 = 1.0 - ((float)(0x32 - *(int *)(lVar8 + 0x4c)) /
                                                       50.0) * 0.2;
                                      }
                                      else {
                                        fVar17 = ((float)(*(int *)(lVar8 + 0x4c) + -0x32) / 50.0) *
                                                 0.4 + 1.0;
                                      }
                                      lVar8 = *(longlong *)(DAT_182d58398 + 0xb8);
                                      if (*(int *)(*(longlong *)(lVar8 + 0x60) + 0x54) < 0x32) {
                                        if (*(longlong *)(lVar8 + 0x60) == 0)
                                        goto code_r0x000180635022;
                                        fVar16 = 1.0 - ((float)(0x32 - *(int *)(*(longlong *)
                                                                                 (lVar8 + 0x60) +
                                                                               0x54)) / 50.0) * 0.2;
                                      }
                                      else {
                                        if (*(longlong *)(lVar8 + 0x60) == 0)
                                        goto code_r0x000180635022;
                                        fVar16 = ((float)(*(int *)(*(longlong *)(lVar8 + 0x60) +
                                                                  0x54) + -0x32) / 50.0) * 0.4 + 1.0
                                        ;
                                      }
                                      *(float *)(param_1 + 0x34) = fVar16;
                                      if (((*(longlong *)(param_1 + 0x40) != 0) &&
                                          (lVar8 = *(longlong *)
                                                    (*(longlong *)(param_1 + 0x40) + 0x70),
                                          lVar8 != 0)) &&
                                         (lVar8 = *(longlong *)(lVar8 + 0xf0), lVar8 != 0)) {
                                        uStack_108 = CONCAT44(fVar16,fVar17);
                                        pcVar7 = DAT_182ec16e0;
                                        fStack_100 = fVar17;
                                        if ((DAT_182ec16e0 == (code *)0x0) &&
                                           (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                          uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                          FUN_1802cca90(uVar12,0);
                                        }
                                        DAT_182ec16e0 = pcVar7;
                                        (*DAT_182ec16e0)(lVar8,&uStack_108);
                                        lVar8 = *(longlong *)
                                                 (*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                                        if (lVar8 != 0) {
                                          if (*(int *)(lVar8 + 0x50) < 0x32) {
                                            fVar17 = 1.0 - ((float)(0x32 - *(int *)(lVar8 + 0x50)) /
                                                           50.0) * 0.2;
                                          }
                                          else {
                                            fVar17 = ((float)(*(int *)(lVar8 + 0x50) + -0x32) / 50.0
                                                     ) * 0.4 + 1.0;
                                          }
                                          lVar8 = *(longlong *)(DAT_182d58398 + 0xb8);
                                          if (*(int *)(*(longlong *)(lVar8 + 0x60) + 0x58) < 0x32) {
                                            if (*(longlong *)(lVar8 + 0x60) == 0)
                                            goto code_r0x000180635022;
                                            fVar16 = 1.0 - ((float)(0x32 - *(int *)(*(longlong *)
                                                                                     (lVar8 + 0x60)
                                                                                   + 0x58)) / 50.0)
                                                           * 0.2;
                                          }
                                          else {
                                            if (*(longlong *)(lVar8 + 0x60) == 0)
                                            goto code_r0x000180635022;
                                            fVar16 = ((float)(*(int *)(*(longlong *)(lVar8 + 0x60) +
                                                                      0x58) + -0x32) / 50.0) * 0.4 +
                                                     1.0;
                                          }
                                          *(float *)(param_1 + 0x38) = fVar16;
                                          if (((*(longlong *)(param_1 + 0x40) != 0) &&
                                              (lVar8 = *(longlong *)
                                                        (*(longlong *)(param_1 + 0x40) + 0x70),
                                              lVar8 != 0)) &&
                                             (lVar8 = *(longlong *)(lVar8 + 0xf8), lVar8 != 0)) {
                                            uStack_e8 = CONCAT44(fVar16,fVar17);
                                            uStack_e0 = CONCAT44(uStack_e0._4_4_,fVar17);
                                            pcVar7 = DAT_182ec16e0;
                                            if ((DAT_182ec16e0 == (code *)0x0) &&
                                               (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                              uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                              FUN_1802cca90(uVar12,0);
                                            }
                                            DAT_182ec16e0 = pcVar7;
                                            (*DAT_182ec16e0)(lVar8,&uStack_e8);
                                            lVar8 = *(longlong *)
                                                     (*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                                            if (lVar8 != 0) {
                                              if (*(int *)(lVar8 + 0x5c) < 0x32) {
                                                fVar17 = 1.0 - ((float)(0x32 - *(int *)(lVar8 + 0x5c
                                                                                       )) / 50.0) *
                                                               0.2;
                                              }
                                              else {
                                                fVar17 = ((float)(*(int *)(lVar8 + 0x5c) + -0x32) /
                                                         50.0) * 0.6 + 1.0;
                                              }
                                              if (((*(longlong *)(param_1 + 0x40) != 0) &&
                                                  (lVar8 = *(longlong *)
                                                            (*(longlong *)(param_1 + 0x40) + 0x70),
                                                  lVar8 != 0)) &&
                                                 (lVar8 = *(longlong *)(lVar8 + 0x110), lVar8 != 0))
                                              {
                                                uStack_f8 = CONCAT44(0x3f800000,fVar17);
                                                uStack_f0 = CONCAT44(uStack_f0._4_4_,fVar17);
                                                pcVar7 = DAT_182ec16e0;
                                                if ((DAT_182ec16e0 == (code *)0x0) &&
                                                   (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                  uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar12,0);
                                                }
                                                DAT_182ec16e0 = pcVar7;
                                                (*DAT_182ec16e0)(lVar8,&uStack_f8);
                                                if (((*(longlong *)(param_1 + 0x40) != 0) &&
                                                    (lVar8 = *(longlong *)
                                                              (*(longlong *)(param_1 + 0x40) + 0x70)
                                                    , lVar8 != 0)) &&
                                                   (lVar8 = *(longlong *)(lVar8 + 0x118), lVar8 != 0
                                                   )) {
                                                  uStack_108 = CONCAT44(0x3f800000,fVar17);
                                                  pcVar7 = DAT_182ec16e0;
                                                  fStack_100 = fVar17;
                                                  if ((DAT_182ec16e0 == (code *)0x0) &&
                                                     (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar12,0);
                                                  }
                                                  DAT_182ec16e0 = pcVar7;
                                                  (*DAT_182ec16e0)(lVar8,&uStack_108);
                                                  if (((*(longlong *)(param_1 + 0x40) != 0) &&
                                                      (lVar8 = *(longlong *)
                                                                (*(longlong *)(param_1 + 0x40) +
                                                                0x70), lVar8 != 0)) &&
                                                     (lVar8 = *(longlong *)(lVar8 + 0x120),
                                                     lVar8 != 0)) {
                                                    uStack_118 = CONCAT44(0x3f800000,fVar17);
                                                    pcVar7 = DAT_182ec16e0;
                                                    fStack_110 = fVar17;
                                                    if ((DAT_182ec16e0 == (code *)0x0) &&
                                                       (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar12,0);
                                                  }
                                                  DAT_182ec16e0 = pcVar7;
                                                  (*DAT_182ec16e0)(lVar8,&uStack_118);
                                                  if (((*(longlong *)(param_1 + 0x40) != 0) &&
                                                      (lVar8 = *(longlong *)
                                                                (*(longlong *)(param_1 + 0x40) +
                                                                0x70), lVar8 != 0)) &&
                                                     (lVar8 = *(longlong *)(lVar8 + 0x128),
                                                     lVar8 != 0)) {
                                                    uStack_d8 = CONCAT44(0x3f800000,fVar17);
                                                    uStack_d0 = CONCAT44(uStack_d0._4_4_,fVar17);
                                                    pcVar7 = DAT_182ec16e0;
                                                    if ((DAT_182ec16e0 == (code *)0x0) &&
                                                       (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Transform::set_localScale_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar12,0);
                                                  }
                                                  DAT_182ec16e0 = pcVar7;
                                                  (*DAT_182ec16e0)(lVar8,&uStack_d8);
                                                  lVar8 = 
                                                  ExposureUnnoticed2_Master_Common_MCustomizeColor__get_Instance__06001340
                                                            (0);
                                                  if (((lVar8 != 0) &&
                                                      (lVar9 = *(longlong *)
                                                                (*(longlong *)(DAT_182d58398 + 0xb8)
                                                                + 0x60), lVar9 != 0)) &&
                                                     (lVar8 = *(longlong *)(lVar8 + 0x18),
                                                     lVar8 != 0)) {
                                                    uVar14 = *(uint *)(lVar9 + 0x78);
                                                    if (*(uint *)(lVar8 + 0x18) <= uVar14) {
code_r0x000180635417:
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dae0();
                                                    }
                                                    puVar11 = (undefined8 *)
                                                              (((longlong)(int)uVar14 + 1) * 0x20 +
                                                              lVar8);
                                                    uStack_e8 = *puVar11;
                                                    uStack_e0 = puVar11[1];
                                                    lVar8 = 
                                                  ExposureUnnoticed2_Master_Common_MCustomizeColor__get_Instance__06001340
                                                            (0);
                                                  if (((lVar8 != 0) &&
                                                      (lVar9 = *(longlong *)
                                                                (*(longlong *)(DAT_182d58398 + 0xb8)
                                                                + 0x60), lVar9 != 0)) &&
                                                     (lVar8 = *(longlong *)(lVar8 + 0x18),
                                                     lVar8 != 0)) {
                                                    uVar14 = *(uint *)(lVar9 + 0x78);
                                                    if (*(uint *)(lVar8 + 0x18) <= uVar14)
                                                    goto code_r0x000180635417;
                                                    puVar10 = (undefined4 *)
                                                              ((longlong)(int)uVar14 * 0x20 + 0x30 +
                                                              lVar8);
                                                    uVar21 = *puVar10;
                                                    uVar22 = puVar10[1];
                                                    uVar23 = puVar10[2];
                                                    uVar24 = puVar10[3];
                                                    lVar8 = *(longlong *)
                                                             (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                             0x60);
                                                    if (lVar8 != 0) {
                                                      if (*(char *)(lVar8 + 0x88) == '\0') {
                                                        uVar20 = uStack_e0._4_4_;
                                                        fVar17 = (float)uStack_e8;
                                                        fVar16 = uStack_e8._4_4_;
                                                        fVar19 = (float)uStack_e0;
                                                      }
                                                      else {
                                                        fVar17 = (float)*(int *)(lVar8 + 0x7c) /
                                                                 255.0;
                                                        fVar16 = (float)*(int *)(lVar8 + 0x80) /
                                                                 255.0;
                                                        fVar19 = (float)*(int *)(lVar8 + 0x84) /
                                                                 255.0;
                                                        uStack_e8 = CONCAT44(fVar16,fVar17);
                                                        uStack_e0 = CONCAT44(0x3f800000,fVar19);
                                                        puVar10 = (undefined4 *)
                                                                                                                                    
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyCustomizeAdjuster__Calc1stShadeColor__06000cc2
                                                            (auStack_c8,param_1,&uStack_e8,0);
                                                  uVar21 = *puVar10;
                                                  uVar22 = puVar10[1];
                                                  uVar23 = puVar10[2];
                                                  uVar24 = puVar10[3];
                                                  uVar20 = 0x3f800000;
                                                  }
                                                  lVar8 = *(longlong *)(param_1 + 0x60);
                                                  if (*(int *)(lRam0000000182d3ea68 + 0xe0) == 0) {
                                                    FUN_18035c820(lRam0000000182d3ea68);
                                                  }
                                                  uStack_e8 = CONCAT44(fVar16,fVar17);
                                                  uStack_e0 = CONCAT44(uVar20,fVar19);
                                                  if (lVar8 != 0) {
                                                    uVar3 = **(undefined4 **)
                                                              (lRam0000000182d3ea68 + 0xb8);
                                                    pcVar7 = DAT_182ec0500;
                                                    if ((DAT_182ec0500 == (code *)0x0) &&
                                                       (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar12,0);
                                                  }
                                                  DAT_182ec0500 = pcVar7;
                                                  (*DAT_182ec0500)(lVar8,uVar3,&uStack_e8);
                                                  lVar8 = *(longlong *)(param_1 + 0x60);
                                                  if (lVar8 != 0) {
                                                    uStack_f8 = CONCAT44(uVar22,uVar21);
                                                    uStack_f0 = CONCAT44(uVar24,uVar23);
                                                    uVar3 = *(undefined4 *)
                                                             (*(longlong *)
                                                               (lRam0000000182d3ea68 + 0xb8) + 4);
                                                    pcVar7 = DAT_182ec0500;
                                                    if ((DAT_182ec0500 == (code *)0x0) &&
                                                       (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar12,0);
                                                  }
                                                  DAT_182ec0500 = pcVar7;
                                                  (*DAT_182ec0500)(lVar8,uVar3,&uStack_f8);
                                                  if ((*(longlong *)(param_1 + 0x40) != 0) &&
                                                     (lVar8 = *(longlong *)
                                                               (*(longlong *)(param_1 + 0x40) +
                                                               0x1b0), lVar8 != 0)) {
                                                    lVar8 = *(longlong *)(lVar8 + 0x20);
                                                    uStack_d8 = CONCAT44(fVar16,fVar17);
                                                    uStack_d0 = CONCAT44(uVar20,fVar19);
                                                    if (lVar8 != 0) {
                                                      uVar3 = **(undefined4 **)
                                                                (lRam0000000182d3ea68 + 0xb8);
                                                      pcVar7 = DAT_182ec0500;
                                                      if ((DAT_182ec0500 == (code *)0x0) &&
                                                         (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar12,0);
                                                  }
                                                  DAT_182ec0500 = pcVar7;
                                                  (*DAT_182ec0500)(lVar8,uVar3,&uStack_d8);
                                                  if (((*(longlong *)(param_1 + 0x40) != 0) &&
                                                      (lVar8 = *(longlong *)
                                                                (*(longlong *)(param_1 + 0x40) +
                                                                0x1b0), lVar8 != 0)) &&
                                                     (lVar8 = *(longlong *)(lVar8 + 0x20),
                                                     lVar8 != 0)) {
                                                    uStack_e8 = CONCAT44(uVar22,uVar21);
                                                    uStack_e0 = CONCAT44(uVar24,uVar23);
                                                    uVar3 = *(undefined4 *)
                                                             (*(longlong *)
                                                               (lRam0000000182d3ea68 + 0xb8) + 4);
                                                    pcVar7 = DAT_182ec0500;
                                                    if ((DAT_182ec0500 == (code *)0x0) &&
                                                       (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar12,0);
                                                  }
                                                  DAT_182ec0500 = pcVar7;
                                                  (*DAT_182ec0500)(lVar8,uVar3,&uStack_e8);
                                                  lVar8 = *(longlong *)(param_1 + 0x68);
                                                  uStack_d8 = CONCAT44(fVar16,fVar17);
                                                  uStack_d0 = CONCAT44(uVar20,fVar19);
                                                  if (lVar8 != 0) {
                                                    uVar3 = **(undefined4 **)
                                                              (lRam0000000182d3ea68 + 0xb8);
                                                    pcVar7 = DAT_182ec0500;
                                                    if ((DAT_182ec0500 == (code *)0x0) &&
                                                       (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar12,0);
                                                  }
                                                  DAT_182ec0500 = pcVar7;
                                                  (*DAT_182ec0500)(lVar8,uVar3,&uStack_d8);
                                                  lVar8 = *(longlong *)(param_1 + 0x68);
                                                  if (lVar8 != 0) {
                                                    uStack_e8 = CONCAT44(uVar22,uVar21);
                                                    uStack_e0 = CONCAT44(uVar24,uVar23);
                                                    uVar3 = *(undefined4 *)
                                                             (*(longlong *)
                                                               (lRam0000000182d3ea68 + 0xb8) + 4);
                                                    pcVar7 = DAT_182ec0500;
                                                    if ((DAT_182ec0500 == (code *)0x0) &&
                                                       (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar12,0);
                                                  }
                                                  DAT_182ec0500 = pcVar7;
                                                  (*DAT_182ec0500)(lVar8,uVar3,&uStack_e8);
                                                  lVar8 = *(longlong *)(param_1 + 0x98);
                                                  uStack_d8 = CONCAT44(fVar16,fVar17);
                                                  uStack_d0 = CONCAT44(uVar20,fVar19);
                                                  if (lVar8 != 0) {
                                                    uVar20 = **(undefined4 **)
                                                               (lRam0000000182d3ea68 + 0xb8);
                                                    pcVar7 = DAT_182ec0500;
                                                    if ((DAT_182ec0500 == (code *)0x0) &&
                                                       (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar12,0);
                                                  }
                                                  DAT_182ec0500 = pcVar7;
                                                  (*DAT_182ec0500)(lVar8,uVar20,&uStack_d8);
                                                  lVar8 = *(longlong *)(param_1 + 0x98);
                                                  if (lVar8 != 0) {
                                                    uStack_e8 = CONCAT44(uVar22,uVar21);
                                                    uStack_e0 = CONCAT44(uVar24,uVar23);
                                                    uVar21 = *(undefined4 *)
                                                              (*(longlong *)
                                                                (lRam0000000182d3ea68 + 0xb8) + 4);
                                                    pcVar7 = DAT_182ec0500;
                                                    if ((DAT_182ec0500 == (code *)0x0) &&
                                                       (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar12,0);
                                                  }
                                                  DAT_182ec0500 = pcVar7;
                                                  (*DAT_182ec0500)(lVar8,uVar21,&uStack_e8);
                                                  lVar8 = *(longlong *)(param_1 + 0x78);
                                                  uVar21 = *(undefined4 *)
                                                            (*(longlong *)
                                                              (lRam0000000182d3ea68 + 0xb8) + 8);
                                                  lVar9 = 
                                                  ExposureUnnoticed2_Master_Common_MCustomizeColor__get_Instance__06001340
                                                            (0);
                                                  if (((lVar9 != 0) &&
                                                      (lVar1 = *(longlong *)
                                                                (*(longlong *)(DAT_182d58398 + 0xb8)
                                                                + 0x60), lVar1 != 0)) &&
                                                     (lVar9 = *(longlong *)(lVar9 + 0x20),
                                                     lVar9 != 0)) {
                                                    uVar14 = *(uint *)(lVar1 + 0xf8);
                                                    if (*(uint *)(lVar9 + 0x18) <= uVar14) {
code_r0x000180635411:
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dae0();
                                                    }
                                                    if (lVar8 != 0) {
                                                      uVar12 = *(undefined8 *)
                                                                (lVar9 + 0x20 +
                                                                (longlong)(int)uVar14 * 8);
                                                      pcVar7 = DAT_182ec04e0;
                                                      if ((DAT_182ec04e0 == (code *)0x0) &&
                                                         (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetTextureImpl(System.Int32,UnityEngine.Texture)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Material::SetTextureImpl(System.Int32,UnityEngine.Texture)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar12,0);
                                                  }
                                                  DAT_182ec04e0 = pcVar7;
                                                  (*DAT_182ec04e0)(lVar8,uVar21,uVar12);
                                                  lVar8 = *(longlong *)(param_1 + 0x78);
                                                  if (lVar8 != 0) {
                                                    uStack_d8 = 0x3ecacacb3ecacacb;
                                                    uStack_d0 = 0x3f8000003ecacacb;
                                                    uVar21 = *(undefined4 *)
                                                              (*(longlong *)
                                                                (lRam0000000182d3ea68 + 0xb8) + 0x10
                                                              );
                                                    pcVar7 = DAT_182ec0500;
                                                    if ((DAT_182ec0500 == (code *)0x0) &&
                                                       (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar12,0);
                                                  }
                                                  DAT_182ec0500 = pcVar7;
                                                  (*DAT_182ec0500)(lVar8,uVar21,&uStack_d8);
                                                  lVar8 = *(longlong *)(param_1 + 0x78);
                                                  uVar21 = *(undefined4 *)
                                                            (*(longlong *)
                                                              (lRam0000000182d3ea68 + 0xb8) + 0xc);
                                                  lVar9 = 
                                                  ExposureUnnoticed2_Master_Common_MCustomizeColor__get_Instance__06001340
                                                            (0);
                                                  if (((lVar9 != 0) &&
                                                      (lVar1 = *(longlong *)
                                                                (*(longlong *)(DAT_182d58398 + 0xb8)
                                                                + 0x60), lVar1 != 0)) &&
                                                     (lVar9 = *(longlong *)(lVar9 + 0x28),
                                                     lVar9 != 0)) {
                                                    uVar14 = *(uint *)(lVar1 + 0xf8);
                                                    if (*(uint *)(lVar9 + 0x18) <= uVar14)
                                                    goto code_r0x000180635411;
                                                    if (lVar8 != 0) {
                                                      uVar12 = *(undefined8 *)
                                                                (lVar9 + 0x20 +
                                                                (longlong)(int)uVar14 * 8);
                                                      pcVar7 = DAT_182ec04e0;
                                                      if ((DAT_182ec04e0 == (code *)0x0) &&
                                                         (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetTextureImpl(System.Int32,UnityEngine.Texture)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Material::SetTextureImpl(System.Int32,UnityEngine.Texture)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar12,0);
                                                  }
                                                  DAT_182ec04e0 = pcVar7;
                                                  (*DAT_182ec04e0)(lVar8,uVar21,uVar12);
                                                  lVar8 = *(longlong *)
                                                           (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                           0x60);
                                                  if (lVar8 != 0) {
                                                    if (*(char *)(lVar8 + 0xd9) == '\0') {
                                                      uVar14 = *(uint *)(lVar8 + 0xf8);
                                                    }
                                                    else {
                                                      uVar14 = *(uint *)(lVar8 + 0xfc);
                                                    }
                                                    lVar8 = *(longlong *)(param_1 + 0x80);
                                                    if (*(int *)(lRam0000000182d3ea68 + 0xe0) == 0)
                                                    {
                                                      FUN_18035c820(lRam0000000182d3ea68);
                                                    }
                                                    uVar21 = *(undefined4 *)
                                                              (*(longlong *)
                                                                (lRam0000000182d3ea68 + 0xb8) + 8);
                                                    lVar9 = 
                                                  ExposureUnnoticed2_Master_Common_MCustomizeColor__get_Instance__06001340
                                                            (0);
                                                  if ((lVar9 != 0) &&
                                                     (lVar9 = *(longlong *)(lVar9 + 0x20),
                                                     lVar9 != 0)) {
                                                    if (*(uint *)(lVar9 + 0x18) <= uVar14)
                                                    goto code_r0x000180635411;
                                                    if (lVar8 != 0) {
                                                      uVar12 = *(undefined8 *)
                                                                (lVar9 + 0x20 +
                                                                (longlong)(int)uVar14 * 8);
                                                      pcVar7 = DAT_182ec04e0;
                                                      if ((DAT_182ec04e0 == (code *)0x0) &&
                                                         (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetTextureImpl(System.Int32,UnityEngine.Texture)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Material::SetTextureImpl(System.Int32,UnityEngine.Texture)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar12,0);
                                                  }
                                                  DAT_182ec04e0 = pcVar7;
                                                  (*DAT_182ec04e0)(lVar8,uVar21,uVar12);
                                                  lVar8 = *(longlong *)(param_1 + 0x80);
                                                  if (lVar8 != 0) {
                                                    uStack_d8 = 0x3ecacacb3ecacacb;
                                                    uStack_d0 = 0x3f8000003ecacacb;
                                                    uVar21 = *(undefined4 *)
                                                              (*(longlong *)
                                                                (lRam0000000182d3ea68 + 0xb8) + 0x10
                                                              );
                                                    pcVar7 = DAT_182ec0500;
                                                    if ((DAT_182ec0500 == (code *)0x0) &&
                                                       (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar12,0);
                                                  }
                                                  DAT_182ec0500 = pcVar7;
                                                  (*DAT_182ec0500)(lVar8,uVar21,&uStack_d8);
                                                  lVar8 = *(longlong *)(param_1 + 0x80);
                                                  uVar21 = *(undefined4 *)
                                                            (*(longlong *)
                                                              (lRam0000000182d3ea68 + 0xb8) + 0xc);
                                                  lVar9 = 
                                                  ExposureUnnoticed2_Master_Common_MCustomizeColor__get_Instance__06001340
                                                            (0);
                                                  if ((lVar9 != 0) &&
                                                     (lVar9 = *(longlong *)(lVar9 + 0x28),
                                                     lVar9 != 0)) {
                                                    if (*(uint *)(lVar9 + 0x18) <= uVar14)
                                                    goto code_r0x000180635411;
                                                    if (lVar8 != 0) {
                                                      uVar12 = *(undefined8 *)
                                                                (lVar9 + 0x20 +
                                                                (longlong)(int)uVar14 * 8);
                                                      pcVar7 = DAT_182ec04e0;
                                                      if ((DAT_182ec04e0 == (code *)0x0) &&
                                                         (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetTextureImpl(System.Int32,UnityEngine.Texture)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Material::SetTextureImpl(System.Int32,UnityEngine.Texture)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar12,0);
                                                  }
                                                  DAT_182ec04e0 = pcVar7;
                                                  (*DAT_182ec04e0)(lVar8,uVar21,uVar12);
                                                  lVar8 = *(longlong *)
                                                           (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                           0x60);
                                                  if (lVar8 != 0) {
                                                    lVar9 = *(longlong *)(param_1 + 0x90);
                                                    fVar17 = (float)*(int *)(lVar8 + 0xa4) / 255.0;
                                                    fVar16 = (float)*(int *)(lVar8 + 0xa8) / 255.0;
                                                    uStack_d8 = CONCAT44(fVar16,fVar17);
                                                    fVar19 = (float)*(int *)(lVar8 + 0xac) / 255.0;
                                                    uStack_d0 = CONCAT44(0x3f800000,fVar19);
                                                    if (lVar9 != 0) {
                                                      uVar21 = **(undefined4 **)
                                                                 (lRam0000000182d3ea68 + 0xb8);
                                                      pcVar7 = DAT_182ec0500;
                                                      if ((DAT_182ec0500 == (code *)0x0) &&
                                                         (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar12,0);
                                                  }
                                                  DAT_182ec0500 = pcVar7;
                                                  (*DAT_182ec0500)(lVar9,uVar21,&uStack_d8);
                                                  lVar8 = *(longlong *)(param_1 + 0x90);
                                                  uStack_d8 = CONCAT44(fVar16,fVar17);
                                                  uStack_d0 = CONCAT44(0x3f800000,fVar19);
                                                  uVar21 = *(undefined4 *)
                                                            (*(longlong *)
                                                              (lRam0000000182d3ea68 + 0xb8) + 4);
                                                  puVar11 = (undefined8 *)
                                                                                                                        
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyCustomizeAdjuster__Calc1stShadeColor__06000cc2
                                                            (auStack_c8,param_1,&uStack_d8,0);
                                                  if (lVar8 != 0) {
                                                    uStack_e8 = *puVar11;
                                                    uStack_e0 = puVar11[1];
                                                    pcVar7 = DAT_182ec0500;
                                                    if ((DAT_182ec0500 == (code *)0x0) &&
                                                       (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar12,0);
                                                  }
                                                  DAT_182ec0500 = pcVar7;
                                                  (*DAT_182ec0500)(lVar8,uVar21,&uStack_e8);
                                                  lVar8 = *(longlong *)
                                                           (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                           0x60);
                                                  if (lVar8 != 0) {
                                                    lVar9 = *(longlong *)(param_1 + 0x88);
                                                    fVar17 = (float)*(int *)(lVar8 + 0xb0) / 255.0;
                                                    fVar16 = (float)*(int *)(lVar8 + 0xb4) / 255.0;
                                                    uStack_d8 = CONCAT44(fVar16,fVar17);
                                                    fVar19 = (float)*(int *)(lVar8 + 0xb8) / 255.0;
                                                    uStack_d0 = CONCAT44(0x3f800000,fVar19);
                                                    if (lVar9 != 0) {
                                                      uVar21 = **(undefined4 **)
                                                                 (lRam0000000182d3ea68 + 0xb8);
                                                      pcVar7 = DAT_182ec0500;
                                                      if ((DAT_182ec0500 == (code *)0x0) &&
                                                         (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar12,0);
                                                  }
                                                  DAT_182ec0500 = pcVar7;
                                                  (*DAT_182ec0500)(lVar9,uVar21,&uStack_d8);
                                                  lVar8 = *(longlong *)(param_1 + 0x88);
                                                  uStack_d8 = CONCAT44(fVar16,fVar17);
                                                  uStack_d0 = CONCAT44(0x3f800000,fVar19);
                                                  uVar21 = *(undefined4 *)
                                                            (*(longlong *)
                                                              (lRam0000000182d3ea68 + 0xb8) + 4);
                                                  puVar11 = (undefined8 *)
                                                                                                                        
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyCustomizeAdjuster__Calc1stShadeColor__06000cc2
                                                            (auStack_c8,param_1,&uStack_d8,0);
                                                  if (lVar8 != 0) {
                                                    uStack_d8 = *puVar11;
                                                    uStack_d0 = puVar11[1];
                                                    pcVar7 = DAT_182ec0500;
                                                    if ((DAT_182ec0500 == (code *)0x0) &&
                                                       (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Material::SetColorImpl_Injected(System.Int32,UnityEngine.Color&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar12,0);
                                                  }
                                                  DAT_182ec0500 = pcVar7;
                                                  (*DAT_182ec0500)(lVar8,uVar21,&uStack_d8);
                                                  fVar17 = *(float *)(param_1 + 0x28) - 1.0;
                                                  if (*(float *)(param_1 + 0x28) <= 1.0) {
                                                    fVar17 = fVar17 * 0.6;
                                                  }
                                                  else {
                                                    fVar17 = fVar17 * 0.8;
                                                  }
                                                  *(float *)(param_1 + 0xb0) = 1.0 / (fVar17 + 1.0);
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
                                                  goto code_r0x000180635022;
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
                                          }
                    /* WARNING: Subroutine does not return */
                                          FUN_18031dad0();
                                        }
                                      }
                    /* WARNING: Subroutine does not return */
                                      FUN_18031dad0();
                                    }
                                  }
                                }
                    /* WARNING: Subroutine does not return */
                                FUN_18031dad0();
                              }
                            }
                          }
                    /* WARNING: Subroutine does not return */
                          FUN_18031dad0();
                        }
                      }
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                  }
                }
                    /* WARNING: Subroutine does not return */
                FUN_18031dad0();
              }
            }
          }
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
code_r0x000180635022:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

