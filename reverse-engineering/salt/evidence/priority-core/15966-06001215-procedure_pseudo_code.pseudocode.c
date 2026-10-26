// Ghidra pseudocode; not original source or compilable C.
// ev_e1acf20e2e1b54f362022d24902cddd4a8461bc1aad9f7058bfa20e7bcc493d8

void ExposureUnnoticed2_Object3D_Camera_TPCameraController__OnLateUpdate__06001215(longlong param_1)

{
  undefined4 uVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  undefined8 uVar5;
  code *pcVar6;
  longlong lVar7;
  longlong lVar8;
  uint uVar9;
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
  undefined8 uStackX_18;
  float fStackX_20;
  undefined8 uStack_f8;
  float fStack_f0;
  undefined8 uStack_e8;
  float fStack_e0;
  undefined8 uStack_d8;
  undefined4 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  
  if (cRam0000000182eb7827 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58380);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb7827 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar5 = ExposureUnnoticed2_Scripts_Base_InputManager__GetVector2__06001704(1,0);
  uStackX_18._0_4_ = (float)uVar5;
  fVar24 = (float)uStackX_18;
  uStackX_18._4_4_ = (float)((ulonglong)uVar5 >> 0x20);
  fVar12 = uStackX_18._4_4_;
  uStackX_18 = uVar5;
  fVar10 = (float)ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetCameraMoveX__06001527(0);
  fVar11 = (float)ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetCameraMoveY__06001528(0);
  uStackX_18 = 0;
  pcVar6 = pcRam0000000182ec2518;
  if ((pcRam0000000182ec2518 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.Input::get_mouseScrollDelta_Injected(UnityEngine.Vector2&)"
                                    ), pcVar6 == (code *)0x0)) {
    uVar5 = FUN_1802ced60("UnityEngine.Input::get_mouseScrollDelta_Injected(UnityEngine.Vector2&)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar5,0);
  }
  pcRam0000000182ec2518 = pcVar6;
  (*pcRam0000000182ec2518)(&uStackX_18);
  fVar21 = uStackX_18._4_4_;
  fVar13 = 0.0;
  if (DAT_182eb54a5 == '\0') {
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    DAT_182eb54a5 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (*(char *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 8) == '\0') {
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
    cVar2 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0x11,0);
    if (cVar2 != '\0') {
      fVar10 = 0.0;
      fVar13 = -fVar11;
      fVar11 = 0.0;
code_r0x0001804613a2:
      fVar13 = fVar13 * 0.02;
    }
  }
  else {
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
    cVar2 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0x22,0);
    if (cVar2 != '\0') {
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      bVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(5,0);
      uVar9 = (uint)bVar3;
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar2 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0xc,0);
      if (cVar2 != '\0') {
        uVar9 = 0xffffffff;
      }
      lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
      if (lVar7 == 0) goto DAT_180461f56;
      uVar4 = -uVar9;
      if (*(char *)(lVar7 + 0x6d) == '\0') {
        uVar4 = uVar9;
      }
      fVar13 = (float)(int)uVar4;
      goto code_r0x0001804613a2;
    }
  }
  if (DAT_182eb5493 == '\0') {
    FUN_1802f2810(&DAT_182d592c0);
    LOCK();
    UNLOCK();
    DAT_182eb5493 = '\x01';
  }
  if (**(longlong **)(DAT_182d592c0 + 0xb8) == 0) goto DAT_180461f56;
  if (*(char *)(**(longlong **)(DAT_182d592c0 + 0xb8) + 0x10) == '\0') {
code_r0x000180461479:
    lVar7 = ExposureUnnoticed2_Scripts_Base_CursorController__get_Instance__06001766(0);
    if (lVar7 == 0) goto DAT_180461f56;
    if (*(char *)(lVar7 + 0x10) == '\0') {
      if (*(longlong *)(param_1 + 0x40) == 0) goto DAT_180461f56;
      if (*(char *)(*(longlong *)(param_1 + 0x40) + 0x28) == '\0') {
        if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d58380);
        }
        lVar7 = **(longlong **)(DAT_182d58380 + 0xb8);
        if (lVar7 == 0) goto DAT_180461f56;
        if ((*(char *)(lVar7 + 0x22) == '\0') && (*(char *)(lVar7 + 0x21) == '\0'))
        goto code_r0x000180461575;
      }
    }
    fVar11 = 0.0;
    fVar10 = 0.0;
    if (DAT_182eb5493 == '\0') {
      FUN_1802f2810(&DAT_182d592c0);
      LOCK();
      UNLOCK();
      DAT_182eb5493 = '\x01';
    }
    if (**(longlong **)(DAT_182d592c0 + 0xb8) == 0) goto DAT_180461f56;
    if (*(char *)(**(longlong **)(DAT_182d592c0 + 0xb8) + 0x10) == '\0') {
      fVar21 = 0.0;
    }
    if (DAT_182eb5482 == '\0') {
      FUN_1802f2810(&DAT_182d549c8);
      LOCK();
      UNLOCK();
      DAT_182eb5482 = '\x01';
    }
    fVar24 = **(float **)(DAT_182d549c8 + 0xb8);
    fVar12 = (*(float **)(DAT_182d549c8 + 0xb8))[1];
    *(undefined4 *)(param_1 + 0x4c) = 4;
    fVar13 = 0.0;
  }
  else {
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
    cVar2 = FUN_180477d40();
    if (cVar2 != '\0') goto code_r0x000180461479;
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
    cVar2 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0x11,0);
    if (cVar2 == '\0') {
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar2 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0xd,0);
      if (cVar2 == '\0') {
        lVar7 = ExposureUnnoticed2_Scripts_Base_CursorController__get_Instance__06001766(0);
        if (lVar7 == 0) goto DAT_180461f56;
        if (*(char *)(lVar7 + 0x10) != '\0') goto code_r0x000180461479;
      }
    }
  }
code_r0x000180461575:
  if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
      (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 != 0)) &&
     (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 != 0)) {
    if (*(char *)(lVar7 + 0x260) != '\0') {
      fVar21 = 0.0;
    }
    if ((0 < *(int *)(param_1 + 0x4c)) && (0.0 < fVar12 * fVar12 + fVar24 * fVar24)) {
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + -1;
      fVar13 = 0.0;
      fVar21 = 0.0;
      fVar11 = 0.0;
      fVar10 = 0.0;
    }
    fVar13 = fVar13 + *(float *)(param_1 + 0x34);
    if (fVar13 < 0.3) {
      fVar13 = 0.3;
    }
    else if (1.1 < fVar13) {
      fVar13 = 1.1;
    }
    *(float *)(param_1 + 0x34) = fVar13;
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
    cVar2 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0x22,0);
    if (cVar2 == '\0') {
      fVar11 = *(float *)(param_1 + 0x30) - fVar11;
      *(float *)(param_1 + 0x2c) = fVar10 + *(float *)(param_1 + 0x2c);
      fVar24 = -80.0;
      if ((fVar11 < -80.0) || (fVar24 = 80.0, 80.0 < fVar11)) {
        fVar11 = fVar24;
      }
      *(float *)(param_1 + 0x30) = fVar11;
    }
    if (((*(longlong *)(param_1 + 0x38) != 0) &&
        (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x40), lVar7 != 0)) &&
       (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 != 0)) {
      if (*(char *)(lVar7 + 0x1a) == '\0') {
        if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
          FUN_18035c820();
        }
        cVar2 = FUN_180477d40();
        if (cVar2 == '\0') {
          lVar7 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
          if (lVar7 == 0) goto DAT_180461f56;
          fVar24 = *(float *)(lVar7 + 0x2c);
          fVar10 = (float)ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetOptionWheelScale__06001557
                                    (0);
          fVar12 = *(float *)(param_1 + 0x28);
          pcVar6 = DAT_182ec1080;
          if ((DAT_182ec1080 == (code *)0x0) &&
             (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
             pcVar6 == (code *)0x0)) {
            uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar5,0);
          }
          DAT_182ec1080 = pcVar6;
          lVar7 = (*DAT_182ec1080)(param_1);
          if (lVar7 == 0) goto DAT_180461f56;
          uStack_f8 = 0;
          fStack_f0 = 0.0;
          pcVar6 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar6 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar6 == (code *)0x0)) {
            uVar5 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar5,0);
          }
          DAT_182ec1698 = pcVar6;
          (*DAT_182ec1698)(lVar7,&uStack_f8);
          lVar7 = *(longlong *)(param_1 + 0x20);
          if (lVar7 == 0) goto DAT_180461f56;
          uStack_e8 = 0;
          fStack_e0 = 0.0;
          pcVar6 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar6 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar6 == (code *)0x0)) {
            uVar5 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar5,0);
          }
          DAT_182ec1698 = pcVar6;
          (*DAT_182ec1698)(lVar7,&uStack_e8);
          fStack_e0 = fStack_f0 - fStack_e0;
          uStack_e8 = CONCAT44(uStack_f8._4_4_ - uStack_e8._4_4_,(float)uStack_f8 - (float)uStack_e8
                              );
          fVar11 = (float)FUN_1803d4630(&uStack_e8);
          *(float *)(param_1 + 0x28) = fVar12 - fVar11 * fVar10 * fVar24 * 3.0 * fVar21;
        }
        else {
          if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
            FUN_18035c820();
          }
          cVar2 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0x22,0);
          if (cVar2 != '\0') {
            *(float *)(param_1 + 0x28) = fVar12 * -0.05 + *(float *)(param_1 + 0x28);
          }
        }
        fVar24 = *(float *)(param_1 + 0x28);
        fVar12 = 0.2;
        if ((fVar24 < 0.2) || (fVar12 = 1.5, 1.5 < fVar24)) {
          fVar24 = fVar12;
        }
        *(float *)(param_1 + 0x28) = fVar24;
      }
      lVar7 = *(longlong *)(param_1 + 0x20);
      if (lVar7 != 0) {
        uStack_e8 = 0;
        fStack_e0 = 0.0;
        pcVar6 = DAT_182ec1698;
        if ((DAT_182ec1698 == (code *)0x0) &&
           (pcVar6 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                          ), pcVar6 == (code *)0x0)) {
          uVar5 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        DAT_182ec1698 = pcVar6;
        (*DAT_182ec1698)(lVar7,&uStack_e8);
        if (((*(longlong *)(param_1 + 0x38) != 0) &&
            (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x40), lVar7 != 0)) &&
           (lVar7 = *(longlong *)(lVar7 + 0x18), lVar7 != 0)) {
          uStack_f8 = 0;
          fStack_f0 = 0.0;
          pcVar6 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar6 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar6 == (code *)0x0)) {
            uVar5 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar5,0);
          }
          DAT_182ec1698 = pcVar6;
          (*DAT_182ec1698)(lVar7,&uStack_f8);
          fVar12 = (uStack_e8._4_4_ - uStack_f8._4_4_) * *(float *)(param_1 + 0x34);
          fVar24 = 0.3;
          if (0.3 <= fVar12) {
            fVar24 = fVar12;
          }
          if (((*(longlong *)(param_1 + 0x38) != 0) &&
              (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x40), lVar7 != 0)) &&
             (lVar7 = *(longlong *)(lVar7 + 0x18), lVar7 != 0)) {
            uStack_e8 = 0;
            fStack_e0 = 0.0;
            pcVar6 = DAT_182ec1698;
            if ((DAT_182ec1698 == (code *)0x0) &&
               (pcVar6 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                              ), pcVar6 == (code *)0x0)) {
              uVar5 = FUN_1802ced60(
                                   "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar5,0);
            }
            DAT_182ec1698 = pcVar6;
            (*DAT_182ec1698)(lVar7,&uStack_e8);
            lVar7 = *(longlong *)(param_1 + 0x20);
            fVar24 = fVar24 + uStack_e8._4_4_;
            if (lVar7 != 0) {
              uStack_f8 = 0;
              fStack_f0 = 0.0;
              pcVar6 = DAT_182ec1698;
              if ((DAT_182ec1698 == (code *)0x0) &&
                 (pcVar6 = (code *)FUN_1802cf0c0(
                                                "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                ), pcVar6 == (code *)0x0)) {
                uVar5 = FUN_1802ced60(
                                     "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                     );
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar5,0);
              }
              DAT_182ec1698 = pcVar6;
              (*DAT_182ec1698)(lVar7,&uStack_f8);
              if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
                FUN_18035c820();
              }
              fVar12 = (float)uStack_f8;
              fStack_e0 = fStack_f0;
              uStack_e8 = CONCAT44(fVar24,(float)uStack_f8);
              fVar10 = (float)ExposureUnnoticed2_Object3D_Camera_TPCameraController__CalcCameraDistance__06001216
                                        (param_1,&uStack_e8,0);
              fStack_e0 = 0.0;
              uStack_e8 = CONCAT44(*(float *)(param_1 + 0x2c) * 0.017453292,
                                   *(float *)(param_1 + 0x30) * 0.017453292);
              uStack_c8 = 0;
              uStack_c0 = 0;
              pcVar6 = DAT_182ec0e88;
              if ((DAT_182ec0e88 == (code *)0x0) &&
                 (pcVar6 = (code *)FUN_1802cf0c0(
                                                "UnityEngine.Quaternion::Internal_FromEulerRad_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                                ), pcVar6 == (code *)0x0)) {
                uVar5 = FUN_1802ced60(
                                     "UnityEngine.Quaternion::Internal_FromEulerRad_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                     );
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar5,0);
              }
              DAT_182ec0e88 = pcVar6;
              (*DAT_182ec0e88)(&uStack_e8,&uStack_c8);
              if (DAT_182eb547b == '\0') {
                FUN_1802f2810(&DAT_182d522a8);
                LOCK();
                UNLOCK();
                DAT_182eb547b = '\x01';
                fVar12 = (float)uStack_f8;
              }
              fVar21 = (float)uStack_c0 + (float)uStack_c0;
              fVar13 = uStack_c8._4_4_ + uStack_c8._4_4_;
              fVar18 = uStack_c0._4_4_ * ((float)uStack_c8 + (float)uStack_c8);
              fVar22 = ((float)uStack_c8 + (float)uStack_c8) * (float)uStack_c8;
              fVar14 = uStack_c0._4_4_ * fVar21;
              uVar5 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x48);
              fVar23 = (float)uVar5;
              fVar20 = fVar13 * uStack_c8._4_4_;
              fStackX_20 = fVar21 * (float)uStack_c8;
              fVar11 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x50);
              fVar17 = fVar21 * uStack_c8._4_4_;
              fVar16 = fVar13 * (float)uStack_c8;
              uStack_d8._4_4_ = (float)((ulonglong)uVar5 >> 0x20);
              uStackX_18 = CONCAT44(uStackX_18._4_4_,
                                    (1.0 - (fVar21 * (float)uStack_c0 + fVar20)) * fVar23 +
                                    (fVar16 - fVar14) * uStack_d8._4_4_ +
                                    (uStack_c0._4_4_ * fVar13 + fStackX_20) * fVar11);
              fVar21 = (1.0 - (fVar21 * (float)uStack_c0 + fVar22)) * uStack_d8._4_4_;
              fVar13 = fStackX_20 - uStack_c0._4_4_ * fVar13;
              fVar19 = (fVar18 + fVar17) * uStack_d8._4_4_;
              pcVar6 = DAT_182ec1080;
              uStack_d8 = uVar5;
              if ((DAT_182ec1080 == (code *)0x0) &&
                 (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
                 pcVar6 == (code *)0x0)) {
                uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar5,0);
              }
              DAT_182ec1080 = pcVar6;
              lVar7 = (*DAT_182ec1080)(param_1);
              fVar15 = fStack_f0;
              fVar10 = fVar10 * -1.0;
              fVar13 = fVar10 * (fVar13 * fVar23 + fVar19 + (1.0 - (fVar20 + fVar22)) * fVar11) +
                       fStack_f0;
              if (lVar7 != 0) {
                uStack_f8 = CONCAT44(fVar10 * (fVar21 + (fVar14 + fVar16) * fVar23 +
                                              (fVar17 - fVar18) * fVar11) + fVar24,
                                     fVar10 * (float)uStackX_18 + fVar12);
                pcVar6 = DAT_182ec16a0;
                fStack_f0 = fVar13;
                if ((DAT_182ec16a0 == (code *)0x0) &&
                   (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar6 == (code *)0x0)) {
                  uVar5 = FUN_1802ced60(
                                       "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar5,0);
                }
                DAT_182ec16a0 = pcVar6;
                (*DAT_182ec16a0)(lVar7,&uStack_f8);
                pcVar6 = DAT_182ec1080;
                if ((DAT_182ec1080 == (code *)0x0) &&
                   (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
                   pcVar6 == (code *)0x0)) {
                  uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar5,0);
                }
                DAT_182ec1080 = pcVar6;
                lVar7 = (*DAT_182ec1080)(param_1);
                pcVar6 = DAT_182ec1080;
                if ((DAT_182ec1080 == (code *)0x0) &&
                   (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
                   pcVar6 == (code *)0x0)) {
                  uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar5,0);
                }
                DAT_182ec1080 = pcVar6;
                lVar8 = (*DAT_182ec1080)(param_1);
                if (lVar8 != 0) {
                  uStack_e8 = 0;
                  fStack_e0 = 0.0;
                  pcVar6 = DAT_182ec1698;
                  if ((DAT_182ec1698 == (code *)0x0) &&
                     (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar6 == (code *)0x0)) {
                    uVar5 = FUN_1802ced60(
                                         "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                         );
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar5,0);
                  }
                  DAT_182ec1698 = pcVar6;
                  (*DAT_182ec1698)(lVar8,&uStack_e8);
                  fVar12 = fVar12 - (float)uStack_e8;
                  fVar24 = fVar24 - uStack_e8._4_4_;
                  fVar15 = fVar15 - fStack_e0;
                  uStack_e8 = CONCAT44(fVar24,fVar12);
                  fStack_e0 = fVar15;
                  fVar10 = (float)FUN_1803d4d00(&uStack_e8);
                  if (1e-05 < fVar10) {
                    fVar15 = fVar15 / fVar10;
                    uStack_e8 = CONCAT44(fVar24 / fVar10,fVar12 / fVar10);
                  }
                  else {
                    if (DAT_182eb5480 == '\0') {
                      FUN_1802f2810(&DAT_182d522a8);
                      LOCK();
                      UNLOCK();
                      DAT_182eb5480 = '\x01';
                    }
                    uStack_e8 = **(undefined8 **)(DAT_182d522a8 + 0xb8);
                    fVar15 = *(float *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
                  }
                  uVar1 = uStack_e8._4_4_;
                  if (DAT_182eb547c == '\0') {
                    FUN_1802f2810(&DAT_182d522a8);
                    LOCK();
                    UNLOCK();
                    DAT_182eb547c = '\x01';
                  }
                  uStack_d8 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
                  uStack_d0 = *(undefined4 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20);
                  uStack_e8 = CONCAT44(uVar1,(float)uStack_e8);
                  uStack_c8 = 0;
                  uStack_c0 = 0;
                  pcVar6 = DAT_182ec0ea8;
                  fStack_e0 = fVar15;
                  if ((DAT_182ec0ea8 == (code *)0x0) &&
                     (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                                  ), pcVar6 == (code *)0x0)) {
                    uVar5 = FUN_1802ced60(
                                         "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                         );
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar5,0);
                  }
                  DAT_182ec0ea8 = pcVar6;
                  (*DAT_182ec0ea8)(&uStack_e8,&uStack_d8,&uStack_c8);
                  if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  uStack_b8 = (float)uStack_c8;
                  uStack_b4 = uStack_c8._4_4_;
                  uStack_b0 = (float)uStack_c0;
                  uStack_ac = uStack_c0._4_4_;
                  pcVar6 = DAT_182ec16c0;
                  if ((DAT_182ec16c0 == (code *)0x0) &&
                     (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar6 == (code *)0x0)) {
                    uVar5 = FUN_1802ced60(
                                         "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                         );
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar5,0);
                  }
                  DAT_182ec16c0 = pcVar6;
                  (*DAT_182ec16c0)(lVar7,&uStack_b8);
                  return;
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
DAT_180461f56:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

