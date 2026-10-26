// Ghidra pseudocode; not original source or compilable C.
// ev_2f89ff041da2d4b99cf7839fe9b428285672be349af9c3bffd8a55cf3b2580fe

void ExposureUnnoticed2_Object3D_Camera_InventoryCameraController__OnLateUpdate__06001207
               (longlong param_1)

{
  bool bVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  code *pcVar5;
  longlong lVar6;
  float extraout_var;
  undefined8 *puVar7;
  longlong lVar8;
  undefined8 uVar9;
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
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  float fStack_100;
  undefined8 uStack_f8;
  float fStack_f0;
  float fStack_e8;
  float fStack_e4;
  float fStack_e0;
  float fStack_dc;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  
  if (cRam0000000182eb7822 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7822 = '\x01';
  }
  if (cRam0000000182eb54a1 == '\0') {
    FUN_1802f2810(0x182d5bcb0);
    LOCK();
    UNLOCK();
    cRam0000000182eb54a1 = '\x01';
  }
  lVar6 = **(longlong **)(lRam0000000182d5bcb0 + 0xb8);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec12f4 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec12f4 = '\x01';
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
  if (lVar6 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar6 + 0x10) != 0) {
      return;
    }
  }
  pcVar5 = pcRam0000000182ebfee8;
  if ((pcRam0000000182ebfee8 == (code *)0x0) &&
     (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Screen::get_width()"), pcVar5 == (code *)0x0)) {
    uVar9 = FUN_1802ced60("UnityEngine.Screen::get_width()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar9,0);
  }
  pcRam0000000182ebfee8 = pcVar5;
  iVar4 = (*pcRam0000000182ebfee8)();
  uStack_118 = 0;
  uStack_110 = (ulonglong)(uint)uStack_110._4_4_ << 0x20;
  pcVar5 = pcRam0000000182ec2510;
  if ((pcRam0000000182ec2510 == (code *)0x0) &&
     (pcVar5 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.Input::get_mousePosition_Injected(UnityEngine.Vector3&)"
                                    ), pcVar5 == (code *)0x0)) {
    uVar9 = FUN_1802ced60("UnityEngine.Input::get_mousePosition_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar9,0);
  }
  pcRam0000000182ec2510 = pcVar5;
  (*pcRam0000000182ec2510)(&uStack_118);
  uStack_108 = 0;
  fStack_100 = 0.0;
  fVar14 = (float)uStack_118 * (1920.0 / (float)iVar4);
  pcVar5 = pcRam0000000182ec2510;
  if ((pcRam0000000182ec2510 == (code *)0x0) &&
     (pcVar5 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.Input::get_mousePosition_Injected(UnityEngine.Vector3&)"
                                    ), pcVar5 == (code *)0x0)) {
    uVar9 = FUN_1802ced60("UnityEngine.Input::get_mousePosition_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar9,0);
  }
  pcRam0000000182ec2510 = pcVar5;
  (*pcRam0000000182ec2510)(&uStack_108);
  fVar13 = uStack_108._4_4_ * (1920.0 / (float)iVar4);
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  cVar3 = FUN_180477d40();
  if (((cVar3 != '\0') || (fVar14 < 0.0)) || (940.0 <= fVar14)) {
    bVar1 = false;
  }
  else {
    bVar1 = false;
    if (0.0 <= fVar13) {
      bVar1 = fVar13 < 1080.0;
    }
  }
  fVar14 = (float)ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetCameraMoveX__06001527(0);
  fVar13 = (float)ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetCameraMoveY__06001528(0);
  if (0 < *(int *)(param_1 + 0x44)) {
    if ((fVar14 != 0.0) || (fVar13 != 0.0)) {
      lVar6 = ExposureUnnoticed2_Scripts_Base_CursorController__get_Instance__06001766(0);
      if (lVar6 == 0) goto DAT_1804603cb;
      if (*(char *)(lVar6 + 0x10) == '\0') {
        *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + -1;
      }
    }
    fVar13 = 0.0;
    fVar14 = 0.0;
  }
  lVar6 = ExposureUnnoticed2_Scripts_Base_CursorController__get_Instance__06001766(0);
  if (lVar6 == 0) goto DAT_1804603cb;
  if (*(char *)(lVar6 + 0x10) != '\0') {
    *(undefined4 *)(param_1 + 0x44) = 2;
  }
  FUN_181f9d820(0);
  if (bVar1) {
    fVar15 = 0.0;
    fVar13 = 0.0;
    fVar14 = 0.0;
  }
  else {
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
    cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0x11,0);
    if (cVar3 != '\0') {
      fVar14 = fVar13 * 0.02 + *(float *)(param_1 + 0x38);
      if (fVar14 < -1.0) {
        fVar14 = -1.0;
      }
      else if (1.0 < fVar14) {
        fVar14 = 1.0;
      }
      *(float *)(param_1 + 0x38) = fVar14;
      fVar14 = 0.0;
      fVar13 = 0.0;
    }
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
    cVar3 = FUN_180477d40();
    fVar15 = extraout_var;
    if (cVar3 != '\0') {
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      puVar7 = (undefined8 *)
               ExposureUnnoticed2_Scripts_Base_InputManager__GetVector3__06001703(&uStack_f8,0,0);
      uStack_f8 = *puVar7;
      fVar11 = (float)uStack_f8;
      fVar12 = *(float *)(puVar7 + 1);
      if ((fVar11 < 0.5) && (-0.5 < fVar11)) {
        fVar10 = fVar12 * -0.03 + *(float *)(param_1 + 0x38);
        if (fVar10 < -1.0) {
          fVar10 = -1.0;
        }
        else if (1.0 < fVar10) {
          fVar10 = 1.0;
        }
        *(float *)(param_1 + 0x38) = fVar10;
      }
      if ((fVar12 < 0.5) && (-0.5 < fVar12)) {
        fVar15 = fVar11 * 5.0;
      }
    }
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
    cVar3 = FUN_180477d40();
    if (cVar3 == '\0') {
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0x11,0);
      if (cVar3 == '\0') {
        if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
          FUN_18035c820();
        }
        cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0xd,0);
        if (cVar3 == '\0') {
          fVar13 = 0.0;
          fVar14 = 0.0;
          ExposureUnnoticed2_Scripts_Base_CursorController__SetVisible__0600176d(1,0);
          goto code_r0x00018045fc67;
        }
      }
      ExposureUnnoticed2_Scripts_Base_CursorController__SetVisible__0600176d(0,0);
    }
  }
code_r0x00018045fc67:
  fVar12 = *(float *)(param_1 + 0x3c);
  lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
  if (lVar6 != 0) {
    iVar4 = *(int *)(lVar6 + 0x74);
    fVar11 = (float)ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetOptionWheelScale__06001557
                              (0);
    fVar12 = fVar11 * (float)iVar4 * fVar15 * 0.01 * 0.15 + fVar12;
    if (fVar12 < 0.0) {
      fVar12 = 0.0;
    }
    else if (1.0 < fVar12) {
      fVar12 = 1.0;
    }
    *(float *)(param_1 + 0x3c) = fVar12;
    *(float *)(param_1 + 0x40) = 1.6 - fVar12 * 1.3;
    if (*(char *)(param_1 + 0x34) != '\0') {
      fVar13 = 0.0;
      fVar14 = 0.0;
    }
    fVar13 = *(float *)(param_1 + 0x24) - fVar13;
    *(float *)(param_1 + 0x20) = fVar14 + *(float *)(param_1 + 0x20);
    fVar14 = -80.0;
    if ((fVar13 < -80.0) || (fVar14 = 80.0, 80.0 < fVar13)) {
      fVar13 = fVar14;
    }
    lVar6 = *(longlong *)(param_1 + 0x28);
    *(float *)(param_1 + 0x24) = fVar13;
    if (lVar6 != 0) {
      uStack_118 = 0;
      uStack_110 = uStack_110 & 0xffffffff00000000;
      pcVar5 = DAT_182ec1698;
      if ((DAT_182ec1698 == (code *)0x0) &&
         (pcVar5 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                        ), pcVar5 == (code *)0x0)) {
        uVar9 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar9,0);
      }
      DAT_182ec1698 = pcVar5;
      (*DAT_182ec1698)(lVar6,&uStack_118);
      if (DAT_182eb547c == '\0') {
        FUN_1802f2810(&DAT_182d522a8);
        LOCK();
        UNLOCK();
        DAT_182eb547c = '\x01';
      }
      fVar14 = *(float *)(param_1 + 0x38);
      uStack_f8 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
      fStack_e8 = (float)uStack_118 - fVar14 * (float)uStack_f8 * 0.7;
      fStack_e0 = uStack_118._4_4_ - fVar14 * (float)((ulonglong)uStack_f8 >> 0x20) * 0.7;
      fStack_dc = (float)uStack_110 -
                  fVar14 * *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20) * 0.7;
      fVar14 = (float)ExposureUnnoticed2_Object3D_Camera_InventoryCameraController__CalcCameraDistance__0600120b
                                (param_1,0);
      fStack_100 = 0.0;
      uStack_108 = CONCAT44(*(float *)(param_1 + 0x20) * 0.017453292,
                            *(float *)(param_1 + 0x24) * 0.017453292);
      uStack_118 = 0;
      uStack_110 = 0;
      pcVar5 = DAT_182ec0e88;
      if ((DAT_182ec0e88 == (code *)0x0) &&
         (pcVar5 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Quaternion::Internal_FromEulerRad_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                        ), pcVar5 == (code *)0x0)) {
        uVar9 = FUN_1802ced60(
                             "UnityEngine.Quaternion::Internal_FromEulerRad_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar9,0);
      }
      DAT_182ec0e88 = pcVar5;
      (*DAT_182ec0e88)(&uStack_108,&uStack_118);
      if (DAT_182eb547b == '\0') {
        FUN_1802f2810(&DAT_182d522a8);
        LOCK();
        UNLOCK();
        DAT_182eb547b = '\x01';
      }
      fVar10 = (float)uStack_110 + (float)uStack_110;
      fVar16 = uStack_118._4_4_ + uStack_118._4_4_;
      fVar19 = ((float)uStack_118 + (float)uStack_118) * (float)uStack_118;
      uVar9 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x48);
      fVar20 = (float)uVar9;
      fVar11 = fVar10 * (float)uStack_110;
      fVar21 = ((float)uStack_118 + (float)uStack_118) * uStack_110._4_4_;
      fVar17 = fVar16 * uStack_110._4_4_;
      fVar18 = fVar16 * uStack_118._4_4_;
      fVar12 = fVar10 * (float)uStack_118;
      uStack_f8._4_4_ = (float)((ulonglong)uVar9 >> 0x20);
      fVar15 = (fVar16 * (float)uStack_118 - fVar10 * uStack_110._4_4_) * uStack_f8._4_4_;
      fVar13 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x50);
      fVar22 = (fVar21 + fVar10 * uStack_118._4_4_) * uStack_f8._4_4_;
      fStack_e4 = (1.0 - (fVar11 + fVar19)) * uStack_f8._4_4_ +
                  (fVar10 * uStack_110._4_4_ + fVar16 * (float)uStack_118) * fVar20 +
                  (fVar10 * uStack_118._4_4_ - fVar21) * fVar13;
      pcVar5 = DAT_182ec1080;
      uStack_f8 = uVar9;
      if ((DAT_182ec1080 == (code *)0x0) &&
         (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
         pcVar5 == (code *)0x0)) {
        uVar9 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar9,0);
      }
      DAT_182ec1080 = pcVar5;
      lVar6 = (*DAT_182ec1080)(param_1);
      fVar10 = fStack_dc;
      fVar21 = fStack_e0;
      fVar16 = fStack_e8;
      fVar14 = fVar14 * -1.0;
      fVar19 = fVar14 * ((fVar12 - fVar17) * fVar20 + fVar22 + (1.0 - (fVar18 + fVar19)) * fVar13) +
               fStack_dc;
      if (lVar6 != 0) {
        uStack_f8 = CONCAT44(fVar14 * fStack_e4 + fStack_e0,
                             fVar14 * ((1.0 - (fVar11 + fVar18)) * fVar20 + fVar15 +
                                      (fVar17 + fVar12) * fVar13) + fStack_e8);
        pcVar5 = DAT_182ec16a0;
        fStack_f0 = fVar19;
        if ((DAT_182ec16a0 == (code *)0x0) &&
           (pcVar5 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                          ), pcVar5 == (code *)0x0)) {
          uVar9 = FUN_1802ced60("UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar9,0);
        }
        DAT_182ec16a0 = pcVar5;
        (*DAT_182ec16a0)(lVar6,&uStack_f8);
        pcVar5 = DAT_182ec1080;
        if ((DAT_182ec1080 == (code *)0x0) &&
           (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
           pcVar5 == (code *)0x0)) {
          uVar9 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar9,0);
        }
        DAT_182ec1080 = pcVar5;
        lVar6 = (*DAT_182ec1080)(param_1);
        pcVar5 = DAT_182ec1080;
        if ((DAT_182ec1080 == (code *)0x0) &&
           (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
           pcVar5 == (code *)0x0)) {
          uVar9 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar9,0);
        }
        DAT_182ec1080 = pcVar5;
        lVar8 = (*DAT_182ec1080)(param_1);
        if (lVar8 != 0) {
          uStack_118 = 0;
          uStack_110 = uStack_110 & 0xffffffff00000000;
          pcVar5 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar5 == (code *)0x0)) {
            uVar9 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar9,0);
          }
          DAT_182ec1698 = pcVar5;
          (*DAT_182ec1698)(lVar8,&uStack_118);
          fVar16 = fVar16 - (float)uStack_118;
          fVar21 = fVar21 - uStack_118._4_4_;
          fVar10 = fVar10 - (float)uStack_110;
          uStack_108 = CONCAT44(fVar21,fVar16);
          fStack_100 = fVar10;
          fVar14 = (float)FUN_1803d4d00(&uStack_108);
          if (1e-05 < fVar14) {
            fVar10 = fVar10 / fVar14;
            uStack_108 = CONCAT44(fVar21 / fVar14,fVar16 / fVar14);
          }
          else {
            if (DAT_182eb5480 == '\0') {
              FUN_1802f2810(&DAT_182d522a8);
              LOCK();
              UNLOCK();
              DAT_182eb5480 = '\x01';
            }
            uStack_108 = **(undefined8 **)(DAT_182d522a8 + 0xb8);
            fVar10 = *(float *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
          }
          uVar2 = uStack_108._4_4_;
          if (DAT_182eb547c == '\0') {
            FUN_1802f2810(&DAT_182d522a8);
            LOCK();
            UNLOCK();
            DAT_182eb547c = '\x01';
          }
          uStack_118 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
          uStack_108 = CONCAT44(uVar2,(undefined4)uStack_108);
          uStack_110 = CONCAT44(uStack_110._4_4_,
                                *(undefined4 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20));
          uStack_d8 = 0;
          uStack_d0 = 0;
          pcVar5 = DAT_182ec0ea8;
          fStack_100 = fVar10;
          if ((DAT_182ec0ea8 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                            ), pcVar5 == (code *)0x0)) {
            uVar9 = FUN_1802ced60(
                                 "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar9,0);
          }
          DAT_182ec0ea8 = pcVar5;
          (*DAT_182ec0ea8)(&uStack_108,&uStack_118,&uStack_d8);
          if (lVar6 != 0) {
            uStack_c8 = uStack_d8;
            uStack_c0 = uStack_d0;
            pcVar5 = DAT_182ec16c0;
            if ((DAT_182ec16c0 == (code *)0x0) &&
               (pcVar5 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                              ), pcVar5 == (code *)0x0)) {
              uVar9 = FUN_1802ced60(
                                   "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar9,0);
            }
            DAT_182ec16c0 = pcVar5;
            (*DAT_182ec16c0)(lVar6,&uStack_c8);
            pcVar5 = DAT_182ec1080;
            if ((DAT_182ec1080 == (code *)0x0) &&
               (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
               pcVar5 == (code *)0x0)) {
              uVar9 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar9,0);
            }
            DAT_182ec1080 = pcVar5;
            lVar6 = (*DAT_182ec1080)(param_1);
            if (lVar6 != 0) {
              fStack_f0 = 0.0;
              uStack_f8 = 0xc1d8000000000000;
              FUN_181f4d000(lVar6,&uStack_f8,1,0);
              return;
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
DAT_1804603cb:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

