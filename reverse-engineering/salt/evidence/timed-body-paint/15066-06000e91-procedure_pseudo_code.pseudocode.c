// Ghidra pseudocode; not original source or compilable C.
// ev_c714bcf1d2f069d8eeb7b4aa8c9ae916c1c62a2915901eb0056883b4cbe6b409

ulonglong ExposureUnnoticed2_Object3D_Player_Scripts_Other_FutanariController__SetupPaint__06000e91
                    (longlong param_1)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  char cVar3;
  longlong lVar4;
  undefined4 *puVar5;
  longlong lVar6;
  code *pcVar7;
  ulonglong uVar8;
  longlong lVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  undefined4 uVar13;
  uint uVar14;
  bool bVar15;
  float fVar16;
  undefined8 uVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  float local_res18 [2];
  float local_res20 [2];
  undefined4 local_c8 [4];
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  
  if (DAT_182eb7675 == '\0') {
    FUN_1802f2810(&DAT_182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58248);
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
    FUN_1802f2810(&DAT_182d58210);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58208);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58200);
    LOCK();
    UNLOCK();
    DAT_182eb7675 = '\x01';
  }
  lVar4 = ExposureUnnoticed2_Master_Common_MCustomizeColor__get_Instance__06001340(0);
  if (((lVar4 == 0) ||
      (lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60), lVar9 == 0)) ||
     (lVar4 = *(longlong *)(lVar4 + 0x18), lVar4 == 0)) goto LAB_180401f77;
  uVar14 = *(uint *)(lVar9 + 0x78);
  if (*(uint *)(lVar4 + 0x18) <= uVar14) goto LAB_180402082;
  puVar1 = (undefined8 *)(((longlong)(int)uVar14 + 1) * 0x20 + lVar4);
  local_b8 = *puVar1;
  uStack_b0 = puVar1[1];
  lVar4 = ExposureUnnoticed2_Master_Common_MCustomizeColor__get_Instance__06001340(0);
  if (((lVar4 == 0) ||
      (lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60), lVar9 == 0)) ||
     (lVar4 = *(longlong *)(lVar4 + 0x18), lVar4 == 0)) goto LAB_180401f77;
  uVar14 = *(uint *)(lVar9 + 0x78);
  if (*(uint *)(lVar4 + 0x18) <= uVar14) goto LAB_180402082;
  uVar11 = 0;
  puVar5 = (undefined4 *)((longlong)(int)uVar14 * 0x20 + 0x30 + lVar4);
  uVar24 = *puVar5;
  uVar25 = puVar5[1];
  uVar26 = puVar5[2];
  uVar27 = puVar5[3];
  lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
  uVar13 = 0;
  if (*(char *)(lVar4 + 0x88) == '\0') {
    uVar23 = uStack_b0._4_4_;
    fVar22 = (float)uStack_b0;
    fVar21 = local_b8._4_4_;
    fVar20 = (float)local_b8;
  }
  else {
    local_c8[0] = 0;
    local_res18[0] = 0.0;
    local_res20[0] = 0.0;
    fVar21 = (float)*(int *)(lVar4 + 0x80) / 255.0;
    fVar22 = (float)*(int *)(lVar4 + 0x84) / 255.0;
    fVar20 = (float)*(int *)(lVar4 + 0x7c) / 255.0;
    if (((fVar22 <= fVar21) || (fVar16 = fVar22, fVar19 = fVar20, fVar18 = fVar21, fVar22 <= fVar20)
        ) && (fVar16 = fVar21, fVar19 = fVar22, fVar18 = fVar20, fVar21 <= fVar20)) {
      fVar16 = fVar20;
      fVar19 = fVar21;
      fVar18 = fVar22;
    }
    FUN_181f2bda0(lVar4,fVar16,fVar19,fVar18,local_c8,local_res18,local_res20,0);
    fVar16 = local_res18[0];
    if (0.0 < local_res18[0]) {
      fVar16 = 0.1;
      if (local_res18[0] < 0.1) {
        fVar16 = local_res18[0];
      }
      fVar16 = fVar16 + local_res18[0];
      if (fVar16 < 0.0) {
        fVar16 = 0.0;
      }
      else if (1.0 < fVar16) {
        fVar16 = 1.0;
      }
    }
    fVar19 = local_res20[0] * 0.9;
    if (fVar19 < 0.0) {
      fVar19 = 0.0;
    }
    else if (1.0 < fVar19) {
      fVar19 = 1.0;
    }
    puVar5 = (undefined4 *)FUN_181f2be80(&local_a8,local_c8[0],fVar16,fVar19,1,0);
    uVar24 = *puVar5;
    uVar25 = puVar5[1];
    uVar26 = puVar5[2];
    uVar27 = puVar5[3];
    uVar23 = 0x3f800000;
  }
  if ((*(longlong *)(param_1 + 0x10) == 0) ||
     (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x70), lVar4 == 0)) goto LAB_180401f77;
  lVar4 = *(longlong *)(lVar4 + 0x1b8);
  lVar6 = FUN_1802c43a0(DAT_182d58200);
  FUN_1811cf4f0(lVar6,DAT_182d58218);
  cVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsEquipCosplayParts__06001549(0x272b,0)
  ;
  lVar9 = **(longlong **)(DAT_182d58238 + 0xb8);
  if (cVar3 == '\0') {
    if ((lVar9 == 0) || (lVar6 == 0)) goto LAB_180401f77;
    FUN_1800053a0(lVar6,*(undefined8 *)(lVar9 + 0x2e8));
    if (*(int *)(lVar6 + 0x18) == 0) goto LAB_18040207a;
    lVar9 = *(longlong *)(lVar6 + 0x10);
    if (lVar9 == 0) goto LAB_180401f77;
    if (*(int *)(lVar9 + 0x18) == 0) goto LAB_180402082;
    lVar9 = *(longlong *)(lVar9 + 0x20);
    if (*(int *)(DAT_182d58248 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d58248);
    }
    uVar2 = *(undefined4 *)(*(longlong *)(DAT_182d58248 + 0xb8) + 0x18);
    cVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsEquipBodyPaint__06001537(8,0);
    if (cVar3 == '\0') {
      uVar12 = 0;
      uVar17 = 0x3f80000000000000;
    }
    else {
      uVar12 = 0x3f8000003f800000;
      uVar17 = 0x3f8000003f800000;
    }
    if (lVar9 == 0) goto LAB_180401f77;
    pcVar7 = DAT_182ec0500;
    local_a8 = uVar12;
    uStack_a0 = uVar17;
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
    (*DAT_182ec0500)(lVar9,uVar2,&local_a8);
    if (*(int *)(lVar6 + 0x18) == 0) goto LAB_18040207a;
    lVar9 = *(longlong *)(lVar6 + 0x10);
    if (lVar9 == 0) goto LAB_180401f77;
    if (*(int *)(lVar9 + 0x18) == 0) goto LAB_180402082;
    lVar9 = *(longlong *)(lVar9 + 0x20);
    if (*(int *)(DAT_182d58248 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d58248);
    }
    local_b8 = CONCAT44(fVar21,fVar20);
    uStack_b0 = CONCAT44(uVar23,fVar22);
    if (lVar9 == 0) goto LAB_180401f77;
    uVar2 = *(undefined4 *)(*(longlong *)(DAT_182d58248 + 0xb8) + 0xc);
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
    (*DAT_182ec0500)(lVar9,uVar2,&local_b8);
    if (*(int *)(lVar6 + 0x18) == 0) goto LAB_18040207a;
    lVar9 = *(longlong *)(lVar6 + 0x10);
    if (lVar9 == 0) goto LAB_180401f77;
    if (*(int *)(lVar9 + 0x18) == 0) goto LAB_180402082;
    lVar9 = *(longlong *)(lVar9 + 0x20);
    if (lVar9 == 0) goto LAB_180401f77;
    local_a8 = CONCAT44(uVar25,uVar24);
    uStack_a0 = CONCAT44(uVar27,uVar26);
    uVar2 = *(undefined4 *)(*(longlong *)(DAT_182d58248 + 0xb8) + 0x10);
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
    (*DAT_182ec0500)(lVar9,uVar2,&local_a8);
  }
  else {
    if ((lVar9 == 0) || (lVar6 == 0)) goto LAB_180401f77;
    FUN_1800053a0(lVar6,*(undefined8 *)(lVar9 + 0x2f0));
  }
  lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar9 != 0) {
    if (0.0 < *(float *)(lVar9 + 0x17c)) {
      if (((*(longlong *)(param_1 + 0x10) == 0) ||
          (lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x70), lVar9 == 0)) ||
         (lVar9 = *(longlong *)(lVar9 + 0x188), lVar9 == 0)) goto LAB_180401f77;
      pcVar7 = DAT_182ec1148;
      if ((DAT_182ec1148 == (code *)0x0) &&
         (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_activeInHierarchy()"),
         pcVar7 == (code *)0x0)) {
        uVar12 = FUN_1802ced60("UnityEngine.GameObject::get_activeInHierarchy()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar12,0);
      }
      DAT_182ec1148 = pcVar7;
      cVar3 = (*DAT_182ec1148)(lVar9);
      if (cVar3 == '\0') {
        if (**(longlong **)(DAT_182d58238 + 0xb8) == 0) goto LAB_180401f77;
        FUN_1800053a0(lVar6,*(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x2d8));
      }
    }
    uVar8 = FUN_1811d1d70(lVar6,DAT_182d58220);
    if (lVar4 == 0) goto LAB_180401f77;
    uVar10 = uVar11;
    if (uVar8 != 0) {
      uVar13 = *(undefined4 *)(uVar8 + 0x18);
      uVar10 = uVar8;
    }
    pcVar7 = DAT_182ec01b8;
    if ((DAT_182ec01b8 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Renderer::SetMaterialArray(UnityEngine.Material[],System.Int32)"
                                      ), pcVar7 == (code *)0x0)) {
      uVar12 = FUN_1802ced60(
                            "UnityEngine.Renderer::SetMaterialArray(UnityEngine.Material[],System.Int32)"
                            );
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar12,0);
    }
    DAT_182ec01b8 = pcVar7;
    (*DAT_182ec01b8)(lVar4,uVar10,uVar13);
    if (*(uint *)(lVar6 + 0x18) <= *(int *)(lVar6 + 0x18) - 1U) goto LAB_18040207a;
    lVar4 = *(longlong *)(lVar6 + 0x10);
    if (lVar4 == 0) goto LAB_180401f77;
    lVar9 = (longlong)*(int *)(lVar6 + 0x18) + -1;
    if (*(uint *)(lVar4 + 0x18) <= (uint)lVar9) goto LAB_180402082;
    bVar15 = DAT_182eb5d50 != 0;
    *(undefined8 *)(param_1 + 0xa8) = *(undefined8 *)(lVar4 + 0x20 + lVar9 * 8);
    if (bVar15) {
      uVar14 = (uint)(param_1 + 0xa8U >> 0xc);
      uVar8 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
      do {
        uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
        LOCK();
        bVar15 = uVar10 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
        if (bVar15) {
          *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar10 | 1L << (uVar14 & 0x3f);
        }
        UNLOCK();
      } while (!bVar15);
    }
    if ((*(longlong *)(param_1 + 0x10) == 0) ||
       (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x70), lVar4 == 0))
    goto LAB_180401f77;
    lVar4 = *(longlong *)(lVar4 + 0x1c0);
    lVar9 = FUN_1802c43a0(DAT_182d58200);
    FUN_1811cf4f0(lVar9,DAT_182d58218);
    cVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsEquipCosplayParts__06001549
                      (0x272b,0);
    if (cVar3 == '\0') {
      if ((**(longlong **)(DAT_182d58238 + 0xb8) == 0) || (lVar9 == 0)) goto LAB_180401f77;
      FUN_1800053a0(lVar9,*(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x2e8));
      if (*(int *)(lVar9 + 0x18) == 0) goto LAB_18040207a;
      lVar6 = *(longlong *)(lVar9 + 0x10);
      if (lVar6 == 0) goto LAB_180401f77;
      if (*(int *)(lVar6 + 0x18) == 0) goto LAB_180402082;
      lVar6 = *(longlong *)(lVar6 + 0x20);
      if (*(int *)(DAT_182d58248 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d58248);
      }
      uVar13 = *(undefined4 *)(*(longlong *)(DAT_182d58248 + 0xb8) + 0x18);
      cVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsEquipBodyPaint__06001537(8,0);
      if (cVar3 == '\0') {
        uVar12 = 0;
        uVar17 = 0x3f80000000000000;
      }
      else {
        uVar12 = 0x3f8000003f800000;
        uVar17 = 0x3f8000003f800000;
      }
      if (lVar6 == 0) goto LAB_180401f77;
      pcVar7 = DAT_182ec0500;
      local_a8 = uVar12;
      uStack_a0 = uVar17;
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
      (*DAT_182ec0500)(lVar6,uVar13,&local_a8);
      if (*(int *)(lVar9 + 0x18) == 0) goto LAB_18040207a;
      lVar6 = *(longlong *)(lVar9 + 0x10);
      if (lVar6 == 0) goto LAB_180401f77;
      if (*(int *)(lVar6 + 0x18) == 0) goto LAB_180402082;
      lVar6 = *(longlong *)(lVar6 + 0x20);
      if (*(int *)(DAT_182d58248 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d58248);
      }
      local_b8 = CONCAT44(fVar21,fVar20);
      uStack_b0 = CONCAT44(uVar23,fVar22);
      if (lVar6 == 0) goto LAB_180401f77;
      uVar13 = *(undefined4 *)(*(longlong *)(DAT_182d58248 + 0xb8) + 0xc);
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
      (*DAT_182ec0500)(lVar6,uVar13,&local_b8);
      if (*(int *)(lVar9 + 0x18) == 0) goto LAB_18040207a;
      lVar6 = *(longlong *)(lVar9 + 0x10);
      if (lVar6 == 0) goto LAB_180401f77;
      if (*(int *)(lVar6 + 0x18) == 0) goto LAB_180402082;
      lVar6 = *(longlong *)(lVar6 + 0x20);
      if (lVar6 == 0) goto LAB_180401f77;
      local_a8 = CONCAT44(uVar25,uVar24);
      uStack_a0 = CONCAT44(uVar27,uVar26);
      uVar13 = *(undefined4 *)(*(longlong *)(DAT_182d58248 + 0xb8) + 0x10);
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
      (*DAT_182ec0500)(lVar6,uVar13,&local_a8);
    }
    else {
      if ((**(longlong **)(DAT_182d58238 + 0xb8) == 0) || (lVar9 == 0)) goto LAB_180401f77;
      FUN_1800053a0(lVar9,*(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x2f0));
    }
    if (lVar4 != 0) {
      pcVar7 = DAT_182ec01b0;
      if ((DAT_182ec01b0 == (code *)0x0) &&
         (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Renderer::GetMaterialArray()"),
         pcVar7 == (code *)0x0)) {
        uVar12 = FUN_1802ced60("UnityEngine.Renderer::GetMaterialArray()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar12,0);
      }
      DAT_182ec01b0 = pcVar7;
      lVar6 = (*DAT_182ec01b0)(lVar4);
      if (lVar6 != 0) {
        if (*(uint *)(lVar6 + 0x18) < 2) {
LAB_180402082:
                    /* WARNING: Subroutine does not return */
          FUN_18031dae0();
        }
        FUN_1800053a0(lVar9,*(undefined8 *)(lVar6 + 0x28));
        lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        if (lVar6 != 0) {
          if (0.0 < *(float *)(lVar6 + 0x17c)) {
            if (((*(longlong *)(param_1 + 0x10) == 0) ||
                (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x70), lVar6 == 0)) ||
               (lVar6 = *(longlong *)(lVar6 + 0x188), lVar6 == 0)) goto LAB_180401f77;
            pcVar7 = DAT_182ec1148;
            if ((DAT_182ec1148 == (code *)0x0) &&
               (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_activeInHierarchy()"),
               pcVar7 == (code *)0x0)) {
              uVar12 = FUN_1802ced60("UnityEngine.GameObject::get_activeInHierarchy()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar12,0);
            }
            DAT_182ec1148 = pcVar7;
            cVar3 = (*DAT_182ec1148)(lVar6);
            if (cVar3 == '\0') {
              if (**(longlong **)(DAT_182d58238 + 0xb8) == 0) goto LAB_180401f77;
              FUN_1800053a0(lVar9,*(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x2d8));
            }
          }
          uVar10 = FUN_1811d1d70(lVar9,DAT_182d58220);
          uVar8 = uVar11;
          if (uVar10 != 0) {
            uVar11 = uVar10;
            uVar8 = (ulonglong)*(uint *)(uVar10 + 0x18);
          }
          pcVar7 = DAT_182ec01b8;
          if ((DAT_182ec01b8 == (code *)0x0) &&
             (pcVar7 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Renderer::SetMaterialArray(UnityEngine.Material[],System.Int32)"
                                            ), pcVar7 == (code *)0x0)) {
            uVar12 = FUN_1802ced60(
                                  "UnityEngine.Renderer::SetMaterialArray(UnityEngine.Material[],System.Int32)"
                                  );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar12,0);
          }
          DAT_182ec01b8 = pcVar7;
          (*DAT_182ec01b8)(lVar4,uVar11,uVar8);
          if (*(uint *)(lVar9 + 0x18) <= *(int *)(lVar9 + 0x18) - 1U) {
LAB_18040207a:
                    /* WARNING: Subroutine does not return */
            FUN_181640100(0);
          }
          lVar4 = *(longlong *)(lVar9 + 0x10);
          if (lVar4 != 0) {
            lVar9 = (longlong)*(int *)(lVar9 + 0x18) + -1;
            if ((uint)lVar9 < *(uint *)(lVar4 + 0x18)) {
              bVar15 = DAT_182eb5d50 != 0;
              uVar11 = *(ulonglong *)(lVar4 + 0x20 + lVar9 * 8);
              *(ulonglong *)(param_1 + 0xa0) = uVar11;
              if (bVar15) {
                uVar14 = (uint)(param_1 + 0xa0U >> 0xc);
                uVar8 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
                do {
                  uVar10 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                  LOCK();
                  uVar11 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                  bVar15 = uVar10 == uVar11;
                  if (bVar15) {
                    *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar10 | 1L << (uVar14 & 0x3f);
                    uVar11 = uVar10;
                  }
                  UNLOCK();
                } while (!bVar15);
              }
              return uVar11;
            }
            goto LAB_180402082;
          }
        }
      }
    }
  }
LAB_180401f77:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

