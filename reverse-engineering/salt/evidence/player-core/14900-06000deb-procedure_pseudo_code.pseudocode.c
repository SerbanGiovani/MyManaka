// Ghidra pseudocode; not original source or compilable C.
// ev_a30419a7fbb63ba9ec5617f57f1b076991f713fd99434dd9681f2ee8deef130a

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerLocomotion__OnFixedUpdate__06000deb
               (longlong param_1)

{
  float *pfVar1;
  undefined4 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  code *pcVar5;
  longlong lVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  uint uVar9;
  bool bVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  undefined8 uStack_d8;
  float fStack_d0;
  undefined8 uStack_c8;
  ulonglong uStack_c0;
  undefined8 uStack_b8;
  ulonglong uStack_b0;
  undefined8 uStack_a8;
  ulonglong uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  ulonglong uStack_80;
  undefined8 uStack_78;
  ulonglong uStack_70;
  
  if (cRam0000000182eb8421 == '\0') {
    FUN_1802f2810(0x182d3ef78);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ef70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb8421 = '\x01';
  }
  if ((*(longlong *)(param_1 + 0x78) != 0) &&
     (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x18), lVar6 != 0)) {
    uStack_a8 = 0;
    uStack_a0 = 0;
    pcVar5 = DAT_182ec16b8;
    if ((DAT_182ec16b8 == (code *)0x0) &&
       (pcVar5 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                      ), pcVar5 == (code *)0x0)) {
      uVar7 = FUN_1802ced60("UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)")
      ;
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar7,0);
    }
    DAT_182ec16b8 = pcVar5;
    (*DAT_182ec16b8)(lVar6,&uStack_a8);
    uStack_b8 = uStack_a8;
    uStack_b0 = uStack_a0;
    lVar6 = FUN_1803fa4b0(&uStack_a8,&uStack_b8);
    fVar17 = *(float *)(lVar6 + 4);
    if (DAT_182eb5480 == '\0') {
      FUN_1802f2810(&DAT_182d522a8);
      LOCK();
      UNLOCK();
      DAT_182eb5480 = '\x01';
    }
    uStack_d8 = **(undefined8 **)(DAT_182d522a8 + 0xb8);
    fVar16 = *(float *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
    fStack_d0 = fVar16;
    if ((*(longlong *)(param_1 + 0x78) != 0) &&
       (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar6 != 0)) {
      lVar6 = *(longlong *)(lVar6 + 0x60);
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
          if ((*(longlong *)(param_1 + 0x78) == 0) ||
             (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x18), lVar6 == 0))
          goto code_r0x000180654a2e;
          uStack_b8 = 0;
          uStack_b0 = uStack_b0 & 0xffffffff00000000;
          pcVar5 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar5 == (code *)0x0)) {
            uVar7 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar7,0);
          }
          DAT_182ec1698 = pcVar5;
          (*DAT_182ec1698)(lVar6,&uStack_b8);
          if (((*(longlong *)(param_1 + 0x78) == 0) ||
              (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar6 == 0)) ||
             (lVar6 = *(longlong *)(lVar6 + 0x60), lVar6 == 0)) goto code_r0x000180654a2e;
          uStack_c8 = 0;
          uStack_c0 = uStack_c0 & 0xffffffff00000000;
          pcVar5 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar5 == (code *)0x0)) {
            uVar7 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar7,0);
          }
          DAT_182ec1698 = pcVar5;
          (*DAT_182ec1698)(lVar6,&uStack_c8);
          fVar12 = ((float)uStack_c8 - (float)uStack_b8) * 0.1 + (float)uStack_b8;
          fVar14 = (uStack_c8._4_4_ - uStack_b8._4_4_) * 0.1 + uStack_b8._4_4_;
          fVar16 = ((float)uStack_c0 - (float)uStack_b0) * 0.1 + (float)uStack_b0;
          if ((*(longlong *)(param_1 + 0x78) == 0) ||
             (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x18), lVar6 == 0))
          goto code_r0x000180654a2e;
          uStack_b8 = 0;
          uStack_b0 = uStack_b0 & 0xffffffff00000000;
          pcVar5 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar5 == (code *)0x0)) {
            uVar7 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar7,0);
          }
          DAT_182ec1698 = pcVar5;
          (*DAT_182ec1698)(lVar6,&uStack_b8);
          fVar16 = (fVar16 - (float)uStack_b0) + fStack_d0;
          uStack_d8 = CONCAT44((fVar14 - uStack_b8._4_4_) + uStack_d8._4_4_,
                               (fVar12 - (float)uStack_b8) + (float)uStack_d8);
          fStack_d0 = fVar16;
          if ((*(longlong *)(param_1 + 0x78) == 0) ||
             (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x18), lVar6 == 0))
          goto code_r0x000180654a2e;
          uStack_98 = 0;
          uStack_90 = 0;
          pcVar5 = DAT_182ec16b8;
          if ((DAT_182ec16b8 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                            ), pcVar5 == (code *)0x0)) {
            uVar7 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar7,0);
          }
          DAT_182ec16b8 = pcVar5;
          (*DAT_182ec16b8)(lVar6,&uStack_98);
          if (((*(longlong *)(param_1 + 0x78) == 0) ||
              (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar3 == 0)) ||
             (lVar3 = *(longlong *)(lVar3 + 0x60), lVar3 == 0)) goto code_r0x000180654a2e;
          uStack_c8 = 0;
          uStack_c0 = 0;
          pcVar5 = DAT_182ec16b8;
          if ((DAT_182ec16b8 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                            ), pcVar5 == (code *)0x0)) {
            uVar7 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar7,0);
          }
          DAT_182ec16b8 = pcVar5;
          (*DAT_182ec16b8)(lVar3,&uStack_c8);
          uStack_88 = uStack_c8;
          uStack_80 = uStack_c0;
          uStack_b8 = 0;
          uStack_b0 = 0;
          pcVar5 = DAT_182ec0e80;
          if ((DAT_182ec0e80 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Quaternion::Lerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                                            ), pcVar5 == (code *)0x0)) {
            uVar7 = FUN_1802ced60(
                                 "UnityEngine.Quaternion::Lerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar7,0);
          }
          DAT_182ec0e80 = pcVar5;
          (*DAT_182ec0e80)(&uStack_98,&uStack_88,0x3dcccccd,&uStack_b8);
          uStack_78 = uStack_b8;
          uStack_70 = uStack_b0;
          pcVar5 = DAT_182ec16c0;
          if ((DAT_182ec16c0 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                            ), pcVar5 == (code *)0x0)) {
            uVar7 = FUN_1802ced60(
                                 "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar7,0);
          }
          DAT_182ec16c0 = pcVar5;
          (*DAT_182ec16c0)(lVar6,&uStack_78);
        }
      }
      lVar6 = *(longlong *)(param_1 + 0x78);
      if ((lVar6 != 0) && (*(longlong *)(lVar6 + 0x60) != 0)) {
        if (*(char *)(*(longlong *)(lVar6 + 0x60) + 0x1b9) != '\0') {
          lVar6 = *(longlong *)(lVar6 + 0x18);
          if (lVar6 == 0) goto code_r0x000180654a2e;
          uStack_b8 = 0;
          uStack_b0 = uStack_b0 & 0xffffffff00000000;
          pcVar5 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar5 == (code *)0x0)) {
            uVar7 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar7,0);
          }
          DAT_182ec1698 = pcVar5;
          (*DAT_182ec1698)(lVar6,&uStack_b8);
          lVar6 = *(longlong *)(param_1 + 0x78);
          if ((lVar6 == 0) || (lVar3 = *(longlong *)(lVar6 + 0x60), lVar3 == 0))
          goto code_r0x000180654a2e;
          uStack_c8 = *(undefined8 *)(lVar3 + 0x1bc);
          fVar16 = (*(float *)(lVar3 + 0x1c4) - (float)uStack_b0) * 0.1 + (float)uStack_b0;
          fVar12 = ((float)((ulonglong)uStack_c8 >> 0x20) - uStack_b8._4_4_) * 0.1 + uStack_b8._4_4_
          ;
          fVar14 = ((float)uStack_c8 - (float)uStack_b8) * 0.1 + (float)uStack_b8;
          if ((lVar6 == 0) || (lVar6 = *(longlong *)(lVar6 + 0x18), lVar6 == 0))
          goto code_r0x000180654a2e;
          uStack_c8 = 0;
          uStack_c0 = uStack_c0 & 0xffffffff00000000;
          pcVar5 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar5 == (code *)0x0)) {
            uVar7 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar7,0);
          }
          DAT_182ec1698 = pcVar5;
          (*DAT_182ec1698)(lVar6,&uStack_c8);
          fVar16 = (fVar16 - (float)uStack_c0) + fStack_d0;
          uStack_d8 = CONCAT44((fVar12 - uStack_c8._4_4_) + uStack_d8._4_4_,
                               (fVar14 - (float)uStack_c8) + (float)uStack_d8);
          if ((*(longlong *)(param_1 + 0x78) == 0) ||
             (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x18), lVar6 == 0))
          goto code_r0x000180654a2e;
          uStack_88 = 0;
          uStack_80 = 0;
          pcVar5 = DAT_182ec16b8;
          if ((DAT_182ec16b8 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                            ), pcVar5 == (code *)0x0)) {
            uVar7 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar7,0);
          }
          DAT_182ec16b8 = pcVar5;
          (*DAT_182ec16b8)(lVar6,&uStack_88);
          if ((*(longlong *)(param_1 + 0x78) == 0) ||
             (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar3 == 0))
          goto code_r0x000180654a2e;
          uStack_98 = *(undefined8 *)(lVar3 + 0x1c8);
          uStack_90 = *(undefined8 *)(lVar3 + 0x1d0);
          uStack_c8 = uStack_88;
          uStack_c0 = uStack_80;
          uStack_b8 = 0;
          uStack_b0 = 0;
          pcVar5 = DAT_182ec0e80;
          if ((DAT_182ec0e80 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Quaternion::Lerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                                            ), pcVar5 == (code *)0x0)) {
            uVar7 = FUN_1802ced60(
                                 "UnityEngine.Quaternion::Lerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar7,0);
          }
          DAT_182ec0e80 = pcVar5;
          (*DAT_182ec0e80)(&uStack_c8,&uStack_98,0x3e4ccccd,&uStack_b8);
          uStack_88 = uStack_b8;
          uStack_80 = uStack_b0;
          pcVar5 = DAT_182ec16c0;
          if ((DAT_182ec16c0 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                            ), pcVar5 == (code *)0x0)) {
            uVar7 = FUN_1802ced60(
                                 "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar7,0);
          }
          DAT_182ec16c0 = pcVar5;
          (*DAT_182ec16c0)(lVar6,&uStack_88);
        }
        if ((*(longlong *)(param_1 + 0x78) != 0) &&
           (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar6 != 0)) {
          uVar7 = *(undefined8 *)(lVar6 + 0x248);
          uStack_b8 = *(undefined8 *)(lVar6 + 400);
          fVar13 = (float)uStack_b8;
          uVar8 = (ulonglong)uStack_b8 >> 0x20;
          fVar12 = *(float *)(lVar6 + 0x250);
          fVar14 = *(float *)(lVar6 + 0x198);
          pcVar5 = pcRam0000000182ec14f8;
          if ((pcRam0000000182ec14f8 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_fixedDeltaTime()"),
             pcVar5 == (code *)0x0)) {
            uVar7 = FUN_1802ced60("UnityEngine.Time::get_fixedDeltaTime()");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar7,0);
          }
          pcRam0000000182ec14f8 = pcVar5;
          fVar11 = (float)(*pcRam0000000182ec14f8)();
          fVar15 = ((float)uVar7 + fVar13) * fVar11 + (float)uStack_d8;
          fVar13 = ((float)((ulonglong)uVar7 >> 0x20) + (float)uVar8) * fVar11 + uStack_d8._4_4_;
          fVar16 = (fVar12 + fVar14) * fVar11 + fVar16;
          if (0.0 < fVar13 * fVar13 + fVar15 * fVar15 + fVar16 * fVar16) {
            lVar6 = *(longlong *)(param_1 + 0x30);
            if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            uStack_d8 = CONCAT44(fVar13,fVar15);
            pcVar5 = pcRam0000000182ec39e8;
            fStack_d0 = fVar16;
            if ((pcRam0000000182ec39e8 == (code *)0x0) &&
               (pcVar5 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.CharacterController::Move_Injected(UnityEngine.Vector3&)"
                                              ), pcVar5 == (code *)0x0)) {
              uVar7 = FUN_1802ced60(
                                   "UnityEngine.CharacterController::Move_Injected(UnityEngine.Vector3&)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar7,0);
            }
            pcRam0000000182ec39e8 = pcVar5;
            (*pcRam0000000182ec39e8)(lVar6,&uStack_d8);
          }
          if (*(longlong *)(param_1 + 0x78) != 0) {
            lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60);
            if (DAT_182eb5480 == '\0') {
              FUN_1802f2810(&DAT_182d522a8);
              LOCK();
              UNLOCK();
              DAT_182eb5480 = '\x01';
            }
            uVar2 = *(undefined4 *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
            if (lVar6 != 0) {
              *(undefined8 *)(lVar6 + 0x248) = **(undefined8 **)(DAT_182d522a8 + 0xb8);
              *(undefined4 *)(lVar6 + 0x250) = uVar2;
              if ((*(longlong *)(param_1 + 0x78) != 0) &&
                 (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar6 != 0)) {
                lVar6 = *(longlong *)(lVar6 + 0x60);
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
                    if (((*(longlong *)(param_1 + 0x78) == 0) ||
                        (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar6 == 0))
                       || (lVar6 = *(longlong *)(lVar6 + 0x60), lVar6 == 0))
                    goto code_r0x000180654a2e;
                    uStack_88 = 0;
                    uStack_80 = 0;
                    pcVar5 = DAT_182ec16b8;
                    if ((DAT_182ec16b8 == (code *)0x0) &&
                       (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar5 == (code *)0x0)) {
                      uVar7 = FUN_1802ced60(
                                           "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                           );
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar7,0);
                    }
                    DAT_182ec16b8 = pcVar5;
                    (*DAT_182ec16b8)(lVar6,&uStack_88);
                    uStack_b8 = uStack_88;
                    uStack_b0 = uStack_80;
                    lVar6 = FUN_1803fa4b0(&uStack_a8,&uStack_b8);
                    fVar16 = ABS(fVar17 - *(float *)(lVar6 + 4));
                    if ((*(longlong *)(param_1 + 0x78) == 0) ||
                       (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x18), lVar6 == 0))
                    goto code_r0x000180654a2e;
                    uStack_b8 = 0;
                    uStack_b0 = uStack_b0 & 0xffffffff00000000;
                    pcVar5 = DAT_182ec1698;
                    if ((DAT_182ec1698 == (code *)0x0) &&
                       (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar5 == (code *)0x0)) {
                      uVar7 = FUN_1802ced60(
                                           "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                           );
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar7,0);
                    }
                    DAT_182ec1698 = pcVar5;
                    (*DAT_182ec1698)(lVar6,&uStack_b8);
                    if (((*(longlong *)(param_1 + 0x78) == 0) ||
                        (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar6 == 0))
                       || (lVar6 = *(longlong *)(lVar6 + 0x60), lVar6 == 0))
                    goto code_r0x000180654a2e;
                    uStack_c8 = 0;
                    uStack_c0 = uStack_c0 & 0xffffffff00000000;
                    pcVar5 = DAT_182ec1698;
                    if ((DAT_182ec1698 == (code *)0x0) &&
                       (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar5 == (code *)0x0)) {
                      uVar7 = FUN_1802ced60(
                                           "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                           );
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar7,0);
                    }
                    DAT_182ec1698 = pcVar5;
                    (*DAT_182ec1698)(lVar6,&uStack_c8);
                    if (((uStack_b8._4_4_ - uStack_c8._4_4_) * (uStack_b8._4_4_ - uStack_c8._4_4_) +
                         ((float)uStack_b8 - (float)uStack_c8) *
                         ((float)uStack_b8 - (float)uStack_c8) +
                         ((float)uStack_b0 - (float)uStack_c0) *
                         ((float)uStack_b0 - (float)uStack_c0) < 0.001) &&
                       ((fVar16 < 0.1 || (359.9 < fVar16)))) {
                      if ((*(longlong *)(param_1 + 0x78) == 0) ||
                         (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar6 == 0))
                      goto code_r0x000180654a2e;
                      bVar10 = DAT_182eb5d50 != 0;
                      *(undefined8 *)(lVar6 + 0x60) = 0;
                      if (bVar10) {
                        uVar9 = (uint)(lVar6 + 0x60U >> 0xc);
                        uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                        do {
                          uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                          LOCK();
                          bVar10 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                          if (bVar10) {
                            *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                 uVar4 | 1L << (uVar9 & 0x3f);
                          }
                          UNLOCK();
                        } while (!bVar10);
                      }
                    }
                    if ((*(longlong *)(param_1 + 0x78) == 0) ||
                       (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar6 == 0))
                    goto code_r0x000180654a2e;
                    fVar16 = *(float *)(lVar6 + 0x7c);
                    pcVar5 = pcRam0000000182ec14f8;
                    if ((pcRam0000000182ec14f8 == (code *)0x0) &&
                       (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_fixedDeltaTime()"),
                       pcVar5 == (code *)0x0)) {
                      uVar7 = FUN_1802ced60("UnityEngine.Time::get_fixedDeltaTime()");
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar7,0);
                    }
                    pcRam0000000182ec14f8 = pcVar5;
                    fVar12 = (float)(*pcRam0000000182ec14f8)();
                    lVar3 = *(longlong *)(param_1 + 0x78);
                    *(float *)(lVar6 + 0x7c) = fVar16 - fVar12;
                    if ((lVar3 == 0) || (lVar6 = *(longlong *)(lVar3 + 0x60), lVar6 == 0))
                    goto code_r0x000180654a2e;
                    pfVar1 = (float *)(lVar6 + 0x7c);
                    if (*pfVar1 <= 0.0 && *pfVar1 != 0.0) {
                      bVar10 = DAT_182eb5d50 != 0;
                      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60);
                      *(undefined8 *)(lVar6 + 0x60) = 0;
                      if (bVar10) {
                        uVar9 = (uint)(lVar6 + 0x60U >> 0xc);
                        uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                        do {
                          uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                          LOCK();
                          bVar10 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                          if (bVar10) {
                            *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                 uVar4 | 1L << (uVar9 & 0x3f);
                          }
                          UNLOCK();
                        } while (!bVar10);
                      }
                    }
                  }
                }
                lVar6 = *(longlong *)(param_1 + 0x78);
                if ((lVar6 != 0) && (lVar3 = *(longlong *)(lVar6 + 0x60), lVar3 != 0)) {
                  if (*(char *)(lVar3 + 0x1d8) != '\0') {
                    lVar6 = *(longlong *)(lVar6 + 0x18);
                    if (lVar6 == 0) {
code_r0x000180654c34:
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                    uStack_b0 = CONCAT44(uStack_b0._4_4_,*(undefined4 *)(lVar3 + 0x1e4));
                    pcVar5 = DAT_182ec16a0;
                    uStack_b8 = *(undefined8 *)(lVar3 + 0x1dc);
                    if ((DAT_182ec16a0 == (code *)0x0) &&
                       (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar5 == (code *)0x0)) {
                      uVar7 = FUN_1802ced60(
                                           "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                           );
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar7,0);
                    }
                    DAT_182ec16a0 = pcVar5;
                    (*DAT_182ec16a0)(lVar6,&uStack_b8);
                    lVar6 = *(longlong *)(param_1 + 0x78);
                    if ((lVar6 == 0) || (lVar3 = *(longlong *)(lVar6 + 0x60), lVar3 == 0))
                    goto code_r0x000180654c34;
                    lVar6 = *(longlong *)(lVar6 + 0x18);
                    if (lVar6 == 0) goto code_r0x000180654c34;
                    pcVar5 = DAT_182ec16c0;
                    uStack_78 = *(undefined8 *)(lVar3 + 0x1e8);
                    uStack_70 = *(ulonglong *)(lVar3 + 0x1f0);
                    if ((DAT_182ec16c0 == (code *)0x0) &&
                       (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar5 == (code *)0x0)) {
                      uVar7 = FUN_1802ced60(
                                           "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                           );
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar7,0);
                    }
                    DAT_182ec16c0 = pcVar5;
                    (*DAT_182ec16c0)(lVar6,&uStack_78);
                  }
                  lVar6 = *(longlong *)(param_1 + 0x78);
                  if ((lVar6 != 0) && (*(longlong *)(lVar6 + 0x60) != 0)) {
                    if (*(char *)(*(longlong *)(lVar6 + 0x60) + 0x68) != '\0') {
                      lVar6 = *(longlong *)(lVar6 + 0x18);
                      if (lVar6 == 0) goto code_r0x000180654a2e;
                      uStack_88 = 0;
                      uStack_80 = 0;
                      pcVar5 = DAT_182ec16b8;
                      if ((DAT_182ec16b8 == (code *)0x0) &&
                         (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar5 == (code *)0x0)) {
                        uVar7 = FUN_1802ced60(
                                             "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                             );
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar7,0);
                      }
                      DAT_182ec16b8 = pcVar5;
                      (*DAT_182ec16b8)(lVar6,&uStack_88);
                      if ((*(longlong *)(param_1 + 0x78) == 0) ||
                         (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar3 == 0))
                      goto code_r0x000180654a2e;
                      if (*(char *)(lVar3 + 0x68) == '\0') {
code_r0x000180654c6e:
                        FUN_181640030(0);
                        pcVar5 = (code *)swi(3);
                        (*pcVar5)();
                        return;
                      }
                      uStack_98 = *(undefined8 *)(lVar3 + 0x6c);
                      uStack_90 = *(undefined8 *)(lVar3 + 0x74);
                      uStack_b8 = uStack_88;
                      uStack_b0 = uStack_80;
                      uStack_a8 = 0;
                      uStack_a0 = 0;
                      pcVar5 = DAT_182ec0e80;
                      if ((DAT_182ec0e80 == (code *)0x0) &&
                         (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Quaternion::Lerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                                                  ), pcVar5 == (code *)0x0)) {
                        uVar7 = FUN_1802ced60(
                                             "UnityEngine.Quaternion::Lerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                                             );
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar7,0);
                      }
                      DAT_182ec0e80 = pcVar5;
                      (*DAT_182ec0e80)(&uStack_b8,&uStack_98,0x3dcccccd,&uStack_a8);
                      uStack_78 = uStack_a8;
                      uStack_70 = uStack_a0;
                      pcVar5 = DAT_182ec16c0;
                      if ((DAT_182ec16c0 == (code *)0x0) &&
                         (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar5 == (code *)0x0)) {
                        uVar7 = FUN_1802ced60(
                                             "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                             );
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar7,0);
                      }
                      DAT_182ec16c0 = pcVar5;
                      (*DAT_182ec16c0)(lVar6,&uStack_78);
                      if ((*(longlong *)(param_1 + 0x78) == 0) ||
                         (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar6 == 0))
                      {
                    /* WARNING: Subroutine does not return */
                        FUN_18031dad0();
                      }
                      if (*(char *)(lVar6 + 0x68) == '\0') goto code_r0x000180654c6e;
                      uStack_b8 = *(undefined8 *)(lVar6 + 0x6c);
                      uStack_b0 = *(ulonglong *)(lVar6 + 0x74);
                      lVar6 = FUN_1803fa4b0(&uStack_a8,&uStack_b8);
                      fVar17 = ABS(fVar17 - *(float *)(lVar6 + 4));
                      if ((fVar17 < 0.1) || (359.9 < fVar17)) {
                        if ((*(longlong *)(param_1 + 0x78) == 0) ||
                           (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar6 == 0)
                           ) goto code_r0x000180654a2e;
                        *(undefined8 *)(lVar6 + 0x68) = 0;
                        *(undefined8 *)(lVar6 + 0x70) = 0;
                        *(undefined4 *)(lVar6 + 0x78) = 0;
                      }
                    }
                    if ((*(longlong *)(param_1 + 0x78) != 0) &&
                       (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar6 != 0)) {
                      if ((*(longlong *)(lVar6 + 0x20) != 0) && (*(float *)(lVar6 + 0x84) <= 0.5)) {
                        if (*(longlong *)(param_1 + 0x88) == 0) goto code_r0x000180654a2e;
                        ExposureUnnoticed2_Object3D_Player_Scripts_Other_PlayerCollisionCorrecter__CollisionCorrect__06000eba
                                  (*(longlong *)(param_1 + 0x88),0);
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
code_r0x000180654a2e:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

