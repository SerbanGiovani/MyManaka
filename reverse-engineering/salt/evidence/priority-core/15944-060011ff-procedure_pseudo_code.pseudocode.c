// Ghidra pseudocode; not original source or compilable C.
// ev_83b93cc68513dcf57de3a7544b5397b11eaddbf74bcaf5055a04633e10280530

void ExposureUnnoticed2_Object3D_Camera_FPCameraController__OnLateUpdate__060011ff(longlong param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  char cVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  longlong lVar6;
  code *pcVar7;
  longlong lVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float local_res8;
  float fStackX_c;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  float local_100;
  undefined8 local_f8;
  float local_f0;
  float local_e8;
  float local_e4;
  float local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  
  if (DAT_182eb781f == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    DAT_182eb781f = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(3,0);
  if (cVar3 != '\0') {
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
    puVar4 = (undefined8 *)
             ExposureUnnoticed2_Scripts_Base_InputManager__GetVector3__06001703(&local_128,0,0);
    local_f8 = *puVar4;
    local_f0 = *(float *)(puVar4 + 1);
    FUN_1803d4630(&local_f8);
  }
  if (*(longlong *)(param_1 + 0x60) == 0) goto LAB_18045f24b;
  ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c();
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar5 = ExposureUnnoticed2_Scripts_Base_InputManager__GetVector2__06001704(1,0);
  fVar9 = (float)ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetCameraMoveX__06001527(0);
  fVar10 = (float)ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetCameraMoveY__06001528(0);
  lVar6 = ExposureUnnoticed2_Scripts_Base_CursorController__get_Instance__06001766(0);
  if (lVar6 == 0) goto LAB_18045f24b;
  if (*(char *)(lVar6 + 0x10) == '\0') {
    if (*(longlong *)(param_1 + 0x68) == 0) goto LAB_18045f24b;
    if (*(char *)(*(longlong *)(param_1 + 0x68) + 0x28) != '\0') goto LAB_18045de53;
  }
  else {
LAB_18045de53:
    fVar10 = 0.0;
    *(undefined4 *)(param_1 + 0x70) = 4;
    fVar9 = 0.0;
  }
  fStackX_c = (float)((ulonglong)uVar5 >> 0x20);
  if ((0 < *(int *)(param_1 + 0x70)) &&
     (local_res8 = (float)uVar5, 0.0 < fStackX_c * fStackX_c + local_res8 * local_res8)) {
    *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + -1;
    fVar10 = 0.0;
    fVar9 = 0.0;
  }
  fVar9 = fVar9 + *(float *)(param_1 + 0x44);
  fVar11 = -80.0;
  if ((fVar9 < -80.0) || (fVar11 = 80.0, 80.0 < fVar9)) {
    fVar9 = fVar11;
  }
  fVar10 = *(float *)(param_1 + 0x40) - fVar10;
  *(float *)(param_1 + 0x44) = fVar9;
  fVar9 = -60.0;
  if ((fVar10 < -60.0) || (fVar9 = 60.0, 60.0 < fVar10)) {
    fVar10 = fVar9;
  }
  *(float *)(param_1 + 0x40) = fVar10;
  if ((((*(longlong *)(param_1 + 0x48) != 0) &&
       (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x48) + 0x40), lVar6 != 0)) &&
      (lVar6 = *(longlong *)(lVar6 + 0x60), lVar6 != 0)) &&
     (lVar6 = *(longlong *)(lVar6 + 0x48), lVar6 != 0)) {
    if ((*(int *)(lVar6 + 0x18) == -1) || (*(char *)(lVar6 + 0x1c) != '\0')) {
      *(undefined4 *)(param_1 + 0x44) = 0;
    }
    lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
    if (lVar6 != 0) {
      lVar8 = *(longlong *)(param_1 + 0x48);
      fVar9 = (float)*(int *)(lVar6 + 0x10) / 160.0;
      if (lVar8 != 0) {
        pcVar7 = DAT_182ec1080;
        if ((DAT_182ec1080 == (code *)0x0) &&
           (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
           pcVar7 == (code *)0x0)) {
          uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        DAT_182ec1080 = pcVar7;
        lVar6 = (*DAT_182ec1080)(lVar8);
        if (lVar6 != 0) {
          local_108 = 0;
          local_100 = 0.0;
          pcVar7 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar7 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar7 == (code *)0x0)) {
            uVar5 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar5,0);
          }
          DAT_182ec1698 = pcVar7;
          (*DAT_182ec1698)(lVar6,&local_108);
          lVar6 = *(longlong *)(param_1 + 0x48);
          if (lVar6 != 0) {
            pcVar7 = DAT_182ec1080;
            if ((DAT_182ec1080 == (code *)0x0) &&
               (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
               pcVar7 == (code *)0x0)) {
              uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar5,0);
            }
            DAT_182ec1080 = pcVar7;
            lVar6 = (*DAT_182ec1080)(lVar6);
            if (lVar6 != 0) {
              local_118 = 0;
              uStack_110 = 0;
              pcVar7 = DAT_182ec16b8;
              if ((DAT_182ec16b8 == (code *)0x0) &&
                 (pcVar7 = (code *)FUN_1802cf0c0(
                                                "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                ), pcVar7 == (code *)0x0)) {
                uVar5 = FUN_1802ced60(
                                     "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                     );
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar5,0);
              }
              DAT_182ec16b8 = pcVar7;
              (*DAT_182ec16b8)(lVar6,&local_118);
              uVar5 = *(undefined8 *)(param_1 + 0x20);
              fVar27 = (float)uVar5;
              fVar15 = local_118._4_4_ + local_118._4_4_;
              fVar11 = (float)uStack_110 + (float)uStack_110;
              fVar26 = (float)local_118 * ((float)local_118 + (float)local_118);
              fVar22 = uStack_110._4_4_ * ((float)local_118 + (float)local_118);
              fVar10 = *(float *)(param_1 + 0x28);
              local_128._4_4_ = (float)((ulonglong)uVar5 >> 0x20);
              fVar12 = ((1.0 - ((float)uStack_110 * fVar11 + local_118._4_4_ * fVar15)) * fVar27 +
                        ((float)local_118 * fVar15 - uStack_110._4_4_ * fVar11) * local_128._4_4_ +
                       (uStack_110._4_4_ * fVar15 + (float)local_118 * fVar11) * fVar10) * fVar9 +
                       (float)local_108;
              local_e4 = ((1.0 - ((float)uStack_110 * fVar11 + fVar26)) * local_128._4_4_ +
                          (uStack_110._4_4_ * fVar11 + (float)local_118 * fVar15) * fVar27 +
                         (local_118._4_4_ * fVar11 - fVar22) * fVar10) * fVar9 + local_108._4_4_;
              local_e0 = (((float)local_118 * fVar11 - uStack_110._4_4_ * fVar15) * fVar27 +
                          (fVar22 + local_118._4_4_ * fVar11) * local_128._4_4_ +
                         (1.0 - (local_118._4_4_ * fVar15 + fVar26)) * fVar10) * fVar9 + local_100;
              lVar6 = *(longlong *)(param_1 + 0x48);
              local_128 = uVar5;
              if (lVar6 != 0) {
                pcVar7 = DAT_182ec1080;
                if ((DAT_182ec1080 == (code *)0x0) &&
                   (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
                   pcVar7 == (code *)0x0)) {
                  uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar5,0);
                }
                DAT_182ec1080 = pcVar7;
                lVar6 = (*DAT_182ec1080)(lVar6);
                if (lVar6 != 0) {
                  local_128 = 0;
                  uStack_120 = 0;
                  pcVar7 = DAT_182ec16b8;
                  if ((DAT_182ec16b8 == (code *)0x0) &&
                     (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar7 == (code *)0x0)) {
                    uVar5 = FUN_1802ced60(
                                         "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                         );
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar5,0);
                  }
                  DAT_182ec16b8 = pcVar7;
                  (*DAT_182ec16b8)(lVar6,&local_128);
                  local_f8 = CONCAT44(*(float *)(param_1 + 0x44) * 0.017453292,
                                      (*(float *)(param_1 + 0x40) * 0.5 + 45.0) * 0.017453292);
                  local_f0 = 0.0;
                  local_118 = 0;
                  uStack_110 = 0;
                  pcVar7 = DAT_182ec0e88;
                  if ((DAT_182ec0e88 == (code *)0x0) &&
                     (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Quaternion::Internal_FromEulerRad_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                                  ), pcVar7 == (code *)0x0)) {
                    uVar5 = FUN_1802ced60(
                                         "UnityEngine.Quaternion::Internal_FromEulerRad_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                         );
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar5,0);
                  }
                  DAT_182ec0e88 = pcVar7;
                  (*DAT_182ec0e88)(&local_f8,&local_118);
                  fVar31 = ((float)local_118 * uStack_120._4_4_ +
                            uStack_110._4_4_ * (float)local_128 +
                           (float)uStack_110 * local_128._4_4_) -
                           local_118._4_4_ * (float)uStack_120;
                  fVar27 = (local_118._4_4_ * uStack_120._4_4_ + uStack_110._4_4_ * local_128._4_4_
                           + (float)local_118 * (float)uStack_120) -
                           (float)uStack_110 * (float)local_128;
                  fVar15 = ((float)uStack_110 * uStack_120._4_4_ +
                            uStack_110._4_4_ * (float)uStack_120 +
                           local_118._4_4_ * (float)local_128) - (float)local_118 * local_128._4_4_;
                  fVar35 = ((uStack_110._4_4_ * uStack_120._4_4_ -
                            (float)local_118 * (float)local_128) - local_118._4_4_ * local_128._4_4_
                           ) - (float)uStack_110 * (float)uStack_120;
                  uVar5 = *(undefined8 *)(param_1 + 0x2c);
                  fVar24 = (float)uVar5;
                  fVar22 = fVar15 + fVar15;
                  fVar26 = fVar27 + fVar27;
                  fVar29 = (fVar31 + fVar31) * fVar31;
                  fVar34 = (fVar31 + fVar31) * fVar35;
                  fVar10 = *(float *)(param_1 + 0x34);
                  local_128._4_4_ = (float)((ulonglong)uVar5 >> 0x20);
                  fVar11 = (fVar26 * fVar31 - fVar22 * fVar35) * local_128._4_4_;
                  local_e4 = ((1.0 - (fVar22 * fVar15 + fVar29)) * local_128._4_4_ +
                              (fVar22 * fVar35 + fVar26 * fVar31) * fVar24 +
                             (fVar22 * fVar27 - fVar34) * fVar10) * fVar9 + local_e4;
                  local_e8 = ((fVar22 * fVar31 - fVar26 * fVar35) * fVar24 +
                              (fVar34 + fVar22 * fVar27) * local_128._4_4_ +
                             (1.0 - (fVar26 * fVar27 + fVar29)) * fVar10) * fVar9 + local_e0;
                  local_128 = uVar5;
                  if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
                      (lVar6 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40),
                      lVar6 != 0)) && (lVar6 = *(longlong *)(lVar6 + 0x178), lVar6 != 0)) {
                    lVar8 = *(longlong *)(param_1 + 0x48);
                    fVar29 = -*(float *)(lVar6 + 0x10);
                    if (lVar8 != 0) {
                      pcVar7 = DAT_182ec1080;
                      if ((DAT_182ec1080 == (code *)0x0) &&
                         (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
                         pcVar7 == (code *)0x0)) {
                        uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar5,0);
                      }
                      DAT_182ec1080 = pcVar7;
                      lVar6 = (*DAT_182ec1080)(lVar8);
                      if (lVar6 != 0) {
                        local_118 = 0;
                        uStack_110 = 0;
                        pcVar7 = DAT_182ec16b8;
                        if ((DAT_182ec16b8 == (code *)0x0) &&
                           (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar7 == (code *)0x0)) {
                          uVar5 = FUN_1802ced60(
                                               "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                               );
                    /* WARNING: Subroutine does not return */
                          FUN_1802cca90(uVar5,0);
                        }
                        DAT_182ec16b8 = pcVar7;
                        (*DAT_182ec16b8)(lVar6,&local_118);
                        if (DAT_182eb547b == '\0') {
                          FUN_1802f2810(&DAT_182d522a8);
                          LOCK();
                          UNLOCK();
                          DAT_182eb547b = '\x01';
                        }
                        if (*(longlong *)(param_1 + 0x60) != 0) {
                          fVar34 = *(float *)(*(longlong *)(param_1 + 0x60) + 0x10);
                          local_128 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x48);
                          fVar30 = (float)((ulonglong)local_128 >> 0x20) * fVar34 * fVar9;
                          fVar33 = (float)local_128 * fVar34 * fVar9;
                          fVar32 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x50) * fVar34 *
                                   fVar9;
                          fVar16 = local_118._4_4_ + local_118._4_4_;
                          fVar34 = (float)uStack_110 + (float)uStack_110;
                          fVar19 = uStack_110._4_4_ * ((float)local_118 + (float)local_118);
                          fVar25 = (float)local_118 * ((float)local_118 + (float)local_118);
                          fVar20 = uStack_110._4_4_ * fVar16;
                          fVar23 = local_118._4_4_ * fVar16;
                          fVar21 = (float)uStack_110 * fVar34;
                          fVar16 = (float)local_118 * fVar16;
                          fVar28 = (float)local_118 * fVar34;
                          fVar17 = uStack_110._4_4_ * fVar34;
                          fVar18 = (1.0 - (fVar21 + fVar25)) * fVar30 + (fVar17 + fVar16) * fVar33 +
                                   (local_118._4_4_ * fVar34 - fVar19) * fVar32 + local_e4;
                          fVar34 = (fVar19 + local_118._4_4_ * fVar34) * fVar30 +
                                   (fVar28 - fVar20) * fVar33 + (1.0 - (fVar23 + fVar25)) * fVar32 +
                                   local_e8;
                          if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
                              (lVar6 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40),
                              lVar6 != 0)) && (lVar6 = *(longlong *)(lVar6 + 0x178), lVar6 != 0)) {
                            fVar19 = *(float *)(lVar6 + 0x10);
                            if (DAT_182eb547c == '\0') {
                              FUN_1802f2810(&DAT_182d522a8);
                              LOCK();
                              UNLOCK();
                              DAT_182eb547c = '\x01';
                            }
                            local_128 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
                            fVar25 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20);
                            fVar13 = (float)local_128;
                            uVar1 = (ulonglong)local_128 >> 0x20;
                            if (DAT_182eb547c == '\0') {
                              FUN_1802f2810(&DAT_182d522a8);
                              LOCK();
                              UNLOCK();
                              DAT_182eb547c = '\x01';
                            }
                            local_128 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
                            fVar14 = (float)local_128;
                            uVar2 = (ulonglong)local_128 >> 0x20;
                            fVar34 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20) * fVar29
                                     + fVar25 * fVar19 + fVar34;
                            pcVar7 = DAT_182ec1080;
                            if ((DAT_182ec1080 == (code *)0x0) &&
                               (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Component::get_transform()"),
                               pcVar7 == (code *)0x0)) {
                              uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
                              FUN_1802cca90(uVar5,0);
                            }
                            DAT_182ec1080 = pcVar7;
                            lVar6 = (*DAT_182ec1080)(param_1);
                            if (lVar6 != 0) {
                              local_f8 = CONCAT44((float)uVar2 * fVar29 +
                                                  (float)uVar1 * fVar19 + fVar18,
                                                  fVar14 * fVar29 +
                                                  fVar13 * fVar19 +
                                                  (1.0 - (fVar21 + fVar23)) * fVar33 +
                                                  (fVar16 - fVar17) * fVar30 +
                                                  (fVar20 + fVar28) * fVar32 +
                                                  ((1.0 - (fVar22 * fVar15 + fVar26 * fVar27)) *
                                                   fVar24 + fVar11 +
                                                  (fVar26 * fVar35 + fVar22 * fVar31) * fVar10) *
                                                  fVar9 + fVar12);
                              pcVar7 = DAT_182ec16a0;
                              local_f0 = fVar34;
                              if ((DAT_182ec16a0 == (code *)0x0) &&
                                 (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                uVar5 = FUN_1802ced60(
                                                  "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                FUN_1802cca90(uVar5,0);
                              }
                              DAT_182ec16a0 = pcVar7;
                              (*DAT_182ec16a0)(lVar6,&local_f8);
                              lVar6 = *(longlong *)(param_1 + 0x48);
                              if (lVar6 != 0) {
                                pcVar7 = DAT_182ec1080;
                                if ((DAT_182ec1080 == (code *)0x0) &&
                                   (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Component::get_transform()"),
                                   pcVar7 == (code *)0x0)) {
                                  uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
                                  FUN_1802cca90(uVar5,0);
                                }
                                DAT_182ec1080 = pcVar7;
                                lVar6 = (*DAT_182ec1080)(lVar6);
                                if (lVar6 != 0) {
                                  local_128 = 0;
                                  uStack_120 = 0;
                                  pcVar7 = DAT_182ec16b8;
                                  if ((DAT_182ec16b8 == (code *)0x0) &&
                                     (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                    uVar5 = FUN_1802ced60(
                                                  "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                    FUN_1802cca90(uVar5,0);
                                  }
                                  DAT_182ec16b8 = pcVar7;
                                  (*DAT_182ec16b8)(lVar6,&local_128);
                                  local_f8 = CONCAT44(*(float *)(param_1 + 0x44) * 0.017453292,
                                                      *(float *)(param_1 + 0x40) * 0.017453292);
                                  local_f0 = 0.0;
                                  local_d8 = 0;
                                  uStack_d0 = 0;
                                  pcVar7 = DAT_182ec0e88;
                                  if ((DAT_182ec0e88 == (code *)0x0) &&
                                     (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Quaternion::Internal_FromEulerRad_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                    uVar5 = FUN_1802ced60(
                                                  "UnityEngine.Quaternion::Internal_FromEulerRad_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                    FUN_1802cca90(uVar5,0);
                                  }
                                  DAT_182ec0e88 = pcVar7;
                                  (*DAT_182ec0e88)(&local_f8,&local_d8);
                                  fVar9 = ((float)local_d8 * uStack_120._4_4_ +
                                           uStack_d0._4_4_ * (float)local_128 +
                                          (float)uStack_d0 * local_128._4_4_) -
                                          local_d8._4_4_ * (float)uStack_120;
                                  fVar12 = (local_d8._4_4_ * uStack_120._4_4_ +
                                            uStack_d0._4_4_ * local_128._4_4_ +
                                           (float)local_d8 * (float)uStack_120) -
                                           (float)uStack_d0 * (float)local_128;
                                  fVar11 = ((float)uStack_d0 * uStack_120._4_4_ +
                                            uStack_d0._4_4_ * (float)uStack_120 +
                                           local_d8._4_4_ * (float)local_128) -
                                           (float)local_d8 * local_128._4_4_;
                                  fVar10 = ((uStack_d0._4_4_ * uStack_120._4_4_ -
                                            (float)local_d8 * (float)local_128) -
                                           local_d8._4_4_ * local_128._4_4_) -
                                           (float)uStack_d0 * (float)uStack_120;
                                  if (DAT_182eb547b == '\0') {
                                    FUN_1802f2810(&DAT_182d522a8);
                                    LOCK();
                                    UNLOCK();
                                    DAT_182eb547b = '\x01';
                                  }
                                  fVar26 = fVar12 + fVar12;
                                  fVar27 = fVar11 + fVar11;
                                  fVar24 = fVar9 * (fVar9 + fVar9);
                                  uVar5 = *(undefined8 *)
                                           (*(longlong *)(DAT_182d522a8 + 0xb8) + 0x48);
                                  fVar34 = (float)uVar5;
                                  fVar29 = fVar10 * (fVar9 + fVar9);
                                  fVar15 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x50);
                                  lVar6 = *(longlong *)(param_1 + 0x38);
                                  local_128._4_4_ = (float)((ulonglong)uVar5 >> 0x20);
                                  fVar22 = (fVar9 * fVar26 - fVar10 * fVar27) * local_128._4_4_;
                                  fVar35 = (1.0 - (fVar11 * fVar27 + fVar24)) * local_128._4_4_;
                                  fVar31 = (fVar29 + fVar12 * fVar27) * local_128._4_4_;
                                  if (DAT_182eb547c == '\0') {
                                    local_128 = uVar5;
                                    FUN_1802f2810(&DAT_182d522a8);
                                    LOCK();
                                    UNLOCK();
                                    DAT_182eb547c = '\x01';
                                  }
                                  uStack_110 = CONCAT44(uStack_110._4_4_,
                                                        (fVar9 * fVar27 - fVar10 * fVar26) * fVar34
                                                        + fVar31 +
                                                        (1.0 - (fVar12 * fVar26 + fVar24)) * fVar15)
                                  ;
                                  local_118 = CONCAT44(fVar35 + (fVar10 * fVar27 + fVar9 * fVar26) *
                                                                fVar34 +
                                                       (fVar12 * fVar27 - fVar29) * fVar15,
                                                       (1.0 - (fVar11 * fVar27 + fVar12 * fVar26)) *
                                                       fVar34 + fVar22 +
                                                       (fVar10 * fVar26 + fVar9 * fVar27) * fVar15);
                                  local_108 = *(undefined8 *)
                                               (*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
                                  local_100 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20)
                                  ;
                                  local_128 = 0;
                                  uStack_120 = 0;
                                  pcVar7 = DAT_182ec0ea8;
                                  if ((DAT_182ec0ea8 == (code *)0x0) &&
                                     (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                    uVar5 = FUN_1802ced60(
                                                  "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                    FUN_1802cca90(uVar5,0);
                                  }
                                  DAT_182ec0ea8 = pcVar7;
                                  (*DAT_182ec0ea8)(&local_118,&local_108,&local_128);
                                  if (lVar6 != 0) {
                                    local_d8 = local_128;
                                    uStack_d0 = uStack_120;
                                    pcVar7 = DAT_182ec16c0;
                                    if ((DAT_182ec16c0 == (code *)0x0) &&
                                       (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                      uVar5 = FUN_1802ced60(
                                                  "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                      FUN_1802cca90(uVar5,0);
                                    }
                                    DAT_182ec16c0 = pcVar7;
                                    (*DAT_182ec16c0)(lVar6,&local_d8);
                                    pcVar7 = DAT_182ec1080;
                                    if ((DAT_182ec1080 == (code *)0x0) &&
                                       (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Component::get_transform()"),
                                       pcVar7 == (code *)0x0)) {
                                      uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()"
                                                           );
                    /* WARNING: Subroutine does not return */
                                      FUN_1802cca90(uVar5,0);
                                    }
                                    DAT_182ec1080 = pcVar7;
                                    lVar6 = (*DAT_182ec1080)(param_1);
                                    if (lVar6 != 0) {
                                      local_108 = 0;
                                      local_100 = 0.0;
                                      pcVar7 = DAT_182ec16a8;
                                      if ((DAT_182ec16a8 == (code *)0x0) &&
                                         (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_localPosition_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                        uVar5 = FUN_1802ced60(
                                                  "UnityEngine.Transform::get_localPosition_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                        FUN_1802cca90(uVar5,0);
                                      }
                                      DAT_182ec16a8 = pcVar7;
                                      (*DAT_182ec16a8)(lVar6,&local_108);
                                      *(undefined8 *)(param_1 + 0x74) = local_108;
                                      *(float *)(param_1 + 0x7c) = local_100;
                                      if ((((*(longlong *)(param_1 + 0x48) != 0) &&
                                           (lVar6 = *(longlong *)
                                                     (*(longlong *)(param_1 + 0x48) + 0x40),
                                           lVar6 != 0)) &&
                                          (lVar6 = *(longlong *)(lVar6 + 0x70), lVar6 != 0)) &&
                                         (lVar6 = *(longlong *)(lVar6 + 200), lVar6 != 0)) {
                                        puVar4 = (undefined8 *)FUN_181f4c0e0(&local_128,lVar6,0);
                                        lVar6 = *(longlong *)
                                                 (*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                                        if (lVar6 != 0) {
                                          local_118 = *puVar4;
                                          fVar11 = (float)(*(int *)(lVar6 + 0x18) + -0x32);
                                          fVar10 = (float)local_118;
                                          uVar1 = (ulonglong)local_118 >> 0x20;
                                          fVar9 = *(float *)(puVar4 + 1);
                                          if (((*(longlong *)(param_1 + 0x48) != 0) &&
                                              (lVar6 = *(longlong *)
                                                        (*(longlong *)(param_1 + 0x48) + 0x40),
                                              lVar6 != 0)) &&
                                             ((lVar6 = *(longlong *)(lVar6 + 0x70), lVar6 != 0 &&
                                              (lVar6 = *(longlong *)(lVar6 + 0xf0), lVar6 != 0)))) {
                                            puVar4 = (undefined8 *)FUN_181f4c0e0(&local_128,lVar6,0)
                                            ;
                                            lVar6 = *(longlong *)
                                                     (*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                                            if (lVar6 != 0) {
                                              if (*(int *)(lVar6 + 0x54) < 0x32) {
                                                fVar12 = (float)(*(int *)(*(longlong *)
                                                                           (*(longlong *)
                                                                             (DAT_182d58398 + 0xb8)
                                                                           + 0x60) + 0x54) + -0x32)
                                                         * 0.0004;
                                              }
                                              else {
                                                fVar12 = (float)(*(int *)(lVar6 + 0x54) + -0x32) *
                                                         0.0008;
                                              }
                                              local_118 = *puVar4;
                                              fVar22 = (float)local_118;
                                              uVar2 = (ulonglong)local_118 >> 0x20;
                                              fVar15 = *(float *)(puVar4 + 1);
                                              if (DAT_182eb5480 == '\0') {
                                                FUN_1802f2810(&DAT_182d522a8);
                                                LOCK();
                                                UNLOCK();
                                                DAT_182eb5480 = '\x01';
                                              }
                                              local_f8 = **(undefined8 **)(DAT_182d522a8 + 0xb8);
                                              fVar26 = *(float *)(*(undefined8 **)
                                                                   (DAT_182d522a8 + 0xb8) + 1);
                                              if (((*(longlong *)(param_1 + 0x48) != 0) &&
                                                  (lVar6 = *(longlong *)
                                                            (*(longlong *)(param_1 + 0x48) + 0x40),
                                                  lVar6 != 0)) &&
                                                 ((lVar6 = *(longlong *)(lVar6 + 0x60), lVar6 != 0
                                                  && (lVar6 = *(longlong *)(lVar6 + 0x48),
                                                     lVar6 != 0)))) {
                                                if (*(char *)(lVar6 + 0x24) == '\0') {
                                                  lVar6 = *(longlong *)
                                                           (*(longlong *)
                                                             (*(longlong *)(param_1 + 0x48) + 0x40)
                                                           + 0x178);
                                                  if (lVar6 == 0) goto LAB_18045f24b;
                                                  fVar27 = *(float *)(lVar6 + 0x10);
                                                  if (DAT_182eb547c == '\0') {
                                                    FUN_1802f2810(&DAT_182d522a8);
                                                    LOCK();
                                                    UNLOCK();
                                                    DAT_182eb547c = '\x01';
                                                  }
                                                  local_118 = *(undefined8 *)
                                                               (*(longlong *)(DAT_182d522a8 + 0xb8)
                                                               + 0x18);
                                                  fVar26 = *(float *)(*(longlong *)
                                                                       (DAT_182d522a8 + 0xb8) + 0x20
                                                                     ) * fVar27;
                                                  local_f8 = CONCAT44((float)((ulonglong)local_118
                                                                             >> 0x20) * fVar27,
                                                                      (float)local_118 * fVar27);
                                                }
                                                pcVar7 = DAT_182ec1080;
                                                if ((DAT_182ec1080 == (code *)0x0) &&
                                                   (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Component::get_transform()"),
                                                  pcVar7 == (code *)0x0)) {
                                                  uVar5 = FUN_1802ced60(
                                                  "UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar5,0);
                                                }
                                                DAT_182ec1080 = pcVar7;
                                                lVar6 = (*DAT_182ec1080)(param_1);
                                                local_128 = *(undefined8 *)(param_1 + 0x74);
                                                fVar27 = *(float *)(param_1 + 0x7c);
                                                pcVar7 = DAT_182ec1080;
                                                if ((DAT_182ec1080 == (code *)0x0) &&
                                                   (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Component::get_transform()"),
                                                  pcVar7 == (code *)0x0)) {
                                                  uVar5 = FUN_1802ced60(
                                                  "UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar5,0);
                                                }
                                                DAT_182ec1080 = pcVar7;
                                                lVar8 = (*DAT_182ec1080)(param_1);
                                                if (lVar8 != 0) {
                                                  local_118 = CONCAT44((float)uVar2 * fVar12 +
                                                                       (float)uVar1 * fVar11 *
                                                                       0.0005,fVar22 * fVar12 +
                                                                              fVar10 * fVar11 *
                                                                              0.0005);
                                                  local_108 = 0;
                                                  local_100 = 0.0;
                                                  uStack_110 = CONCAT44(uStack_110._4_4_,
                                                                        fVar15 * fVar12 +
                                                                        fVar9 * fVar11 * 0.0005);
                                                  pcVar7 = DAT_182ec1720;
                                                  if ((DAT_182ec1720 == (code *)0x0) &&
                                                     (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::InverseTransformDirection_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar5 = FUN_1802ced60(
                                                  "UnityEngine.Transform::InverseTransformDirection_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar5,0);
                                                  }
                                                  DAT_182ec1720 = pcVar7;
                                                  (*DAT_182ec1720)(lVar8,&local_118,&local_108);
                                                  fVar27 = fVar27 + local_100;
                                                  fVar9 = (float)local_128 + (float)local_108 +
                                                          (float)local_f8;
                                                  fVar10 = local_128._4_4_ + local_108._4_4_ +
                                                           local_f8._4_4_;
                                                  if (DAT_182eb547c == '\0') {
                                                    FUN_1802f2810(&DAT_182d522a8);
                                                    LOCK();
                                                    UNLOCK();
                                                    DAT_182eb547c = '\x01';
                                                  }
                                                  if (((*(longlong *)(param_1 + 0x48) != 0) &&
                                                      (lVar8 = *(longlong *)
                                                                (*(longlong *)(param_1 + 0x48) +
                                                                0x40), lVar8 != 0)) &&
                                                     (lVar8 = *(longlong *)(lVar8 + 0x198),
                                                     lVar8 != 0)) {
                                                    fVar11 = *(float *)(lVar8 + 0x10);
                                                    local_128 = *(undefined8 *)
                                                                 (*(longlong *)
                                                                   (DAT_182d522a8 + 0xb8) + 0x18);
                                                    if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dad0();
                                                    }
                                                    uStack_120 = CONCAT44(uStack_120._4_4_,
                                                                          *(float *)(*(longlong *)
                                                                                      (DAT_182d522a8
                                                                                      + 0xb8) + 0x20
                                                                                    ) * fVar11 *
                                                                          -1.0 + fVar27 + fVar26);
                                                    local_128 = CONCAT44((float)((ulonglong)
                                                                                 local_128 >> 0x20)
                                                                         * fVar11 * -1.0 + fVar10,
                                                                         (float)local_128 * fVar11 *
                                                                         -1.0 + fVar9);
                                                    pcVar7 = DAT_182ec16b0;
                                                    if ((DAT_182ec16b0 == (code *)0x0) &&
                                                       (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_localPosition_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar7 == (code *)0x0)) {
                                                    uVar5 = FUN_1802ced60(
                                                  "UnityEngine.Transform::set_localPosition_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar5,0);
                                                  }
                                                  DAT_182ec16b0 = pcVar7;
                                                  (*DAT_182ec16b0)(lVar6,&local_128);
                                                  return;
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                      goto LAB_18045f24b;
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
LAB_18045f24b:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

