// Ghidra pseudocode; not original source or compilable C.
// ev_4de49dbcd47deb249e5b570843fc56659a92c0eafafdc7f69098e530d96d9b75

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController__OnFixedUpdate__06000d5d
               (longlong param_1)

{
  float *pfVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  code *pcVar6;
  longlong lVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  uint uVar10;
  bool bVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
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
  undefined *puStack_30;
  
  if (cRam0000000182eb83e2 == '\0') {
    puStack_30 = &UNK_180644ffe;
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb83e2 = '\x01';
  }
  if ((*(longlong *)(param_1 + 0x40) != 0) &&
     (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60), lVar3 != 0)) {
    if (*(int *)(lVar3 + 0x5c) != 0) {
      return;
    }
    if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
       (lVar3 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar3 != 0)) {
      if (*(char *)(lVar3 + 0x11) != '\0') {
        return;
      }
      lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x58);
      if (lVar3 != 0) {
        if (cRam0000000182eb8421 == '\0') {
          FUN_1802f2810(0x182d3ef78,0);
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
        if ((*(longlong *)(lVar3 + 0x78) != 0) &&
           (lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0x78) + 0x18), lVar7 != 0)) {
          uStack_a8 = 0;
          uStack_a0 = 0;
          pcVar6 = DAT_182ec16b8;
          if ((DAT_182ec16b8 == (code *)0x0) &&
             (pcVar6 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                            ), pcVar6 == (code *)0x0)) {
            uVar8 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar8,0);
          }
          DAT_182ec16b8 = pcVar6;
          (*DAT_182ec16b8)(lVar7,&uStack_a8);
          uStack_b8 = uStack_a8;
          uStack_b0 = uStack_a0;
          lVar7 = FUN_1803fa4b0(&uStack_a8,&uStack_b8);
          fVar18 = *(float *)(lVar7 + 4);
          if (DAT_182eb5480 == '\0') {
            FUN_1802f2810(&DAT_182d522a8);
            LOCK();
            UNLOCK();
            DAT_182eb5480 = '\x01';
          }
          uStack_d8 = **(undefined8 **)(DAT_182d522a8 + 0xb8);
          fVar17 = *(float *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
          fStack_d0 = fVar17;
          if ((*(longlong *)(lVar3 + 0x78) != 0) &&
             (lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0x78) + 0x60), lVar7 != 0)) {
            lVar7 = *(longlong *)(lVar7 + 0x60);
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
            if (lVar7 != 0) {
              if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                FUN_18035c820();
              }
              if (*(longlong *)(lVar7 + 0x10) != 0) {
                if ((*(longlong *)(lVar3 + 0x78) == 0) ||
                   (lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0x78) + 0x18), lVar7 == 0))
                goto code_r0x000180654a2e;
                uStack_b8 = 0;
                uStack_b0 = uStack_b0 & 0xffffffff00000000;
                pcVar6 = DAT_182ec1698;
                if ((DAT_182ec1698 == (code *)0x0) &&
                   (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar6 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60(
                                       "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec1698 = pcVar6;
                (*DAT_182ec1698)(lVar7,&uStack_b8);
                if (((*(longlong *)(lVar3 + 0x78) == 0) ||
                    (lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0x78) + 0x60), lVar7 == 0)) ||
                   (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 == 0)) goto code_r0x000180654a2e;
                uStack_c8 = 0;
                uStack_c0 = uStack_c0 & 0xffffffff00000000;
                pcVar6 = DAT_182ec1698;
                if ((DAT_182ec1698 == (code *)0x0) &&
                   (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar6 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60(
                                       "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec1698 = pcVar6;
                (*DAT_182ec1698)(lVar7,&uStack_c8);
                fVar13 = ((float)uStack_c8 - (float)uStack_b8) * 0.1 + (float)uStack_b8;
                fVar15 = (uStack_c8._4_4_ - uStack_b8._4_4_) * 0.1 + uStack_b8._4_4_;
                fVar17 = ((float)uStack_c0 - (float)uStack_b0) * 0.1 + (float)uStack_b0;
                if ((*(longlong *)(lVar3 + 0x78) == 0) ||
                   (lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0x78) + 0x18), lVar7 == 0))
                goto code_r0x000180654a2e;
                uStack_b8 = 0;
                uStack_b0 = uStack_b0 & 0xffffffff00000000;
                pcVar6 = DAT_182ec1698;
                if ((DAT_182ec1698 == (code *)0x0) &&
                   (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar6 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60(
                                       "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec1698 = pcVar6;
                (*DAT_182ec1698)(lVar7,&uStack_b8);
                fVar17 = (fVar17 - (float)uStack_b0) + fStack_d0;
                uStack_d8 = CONCAT44((fVar15 - uStack_b8._4_4_) + uStack_d8._4_4_,
                                     (fVar13 - (float)uStack_b8) + (float)uStack_d8);
                fStack_d0 = fVar17;
                if ((*(longlong *)(lVar3 + 0x78) == 0) ||
                   (lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0x78) + 0x18), lVar7 == 0))
                goto code_r0x000180654a2e;
                uStack_98 = 0;
                uStack_90 = 0;
                pcVar6 = DAT_182ec16b8;
                if ((DAT_182ec16b8 == (code *)0x0) &&
                   (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar6 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60(
                                       "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec16b8 = pcVar6;
                (*DAT_182ec16b8)(lVar7,&uStack_98);
                if (((*(longlong *)(lVar3 + 0x78) == 0) ||
                    (lVar4 = *(longlong *)(*(longlong *)(lVar3 + 0x78) + 0x60), lVar4 == 0)) ||
                   (lVar4 = *(longlong *)(lVar4 + 0x60), lVar4 == 0)) goto code_r0x000180654a2e;
                uStack_c8 = 0;
                uStack_c0 = 0;
                pcVar6 = DAT_182ec16b8;
                if ((DAT_182ec16b8 == (code *)0x0) &&
                   (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar6 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60(
                                       "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec16b8 = pcVar6;
                (*DAT_182ec16b8)(lVar4,&uStack_c8);
                uStack_88 = uStack_c8;
                uStack_80 = uStack_c0;
                uStack_b8 = 0;
                uStack_b0 = 0;
                pcVar6 = DAT_182ec0e80;
                if ((DAT_182ec0e80 == (code *)0x0) &&
                   (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Quaternion::Lerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                                                  ), pcVar6 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60(
                                       "UnityEngine.Quaternion::Lerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec0e80 = pcVar6;
                (*DAT_182ec0e80)(&uStack_98,&uStack_88,0x3dcccccd,&uStack_b8);
                uStack_78 = uStack_b8;
                uStack_70 = uStack_b0;
                pcVar6 = DAT_182ec16c0;
                if ((DAT_182ec16c0 == (code *)0x0) &&
                   (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar6 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60(
                                       "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec16c0 = pcVar6;
                (*DAT_182ec16c0)(lVar7,&uStack_78);
              }
            }
            lVar7 = *(longlong *)(lVar3 + 0x78);
            if ((lVar7 != 0) && (*(longlong *)(lVar7 + 0x60) != 0)) {
              if (*(char *)(*(longlong *)(lVar7 + 0x60) + 0x1b9) != '\0') {
                lVar7 = *(longlong *)(lVar7 + 0x18);
                if (lVar7 == 0) goto code_r0x000180654a2e;
                uStack_b8 = 0;
                uStack_b0 = uStack_b0 & 0xffffffff00000000;
                pcVar6 = DAT_182ec1698;
                if ((DAT_182ec1698 == (code *)0x0) &&
                   (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar6 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60(
                                       "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec1698 = pcVar6;
                (*DAT_182ec1698)(lVar7,&uStack_b8);
                lVar7 = *(longlong *)(lVar3 + 0x78);
                if ((lVar7 == 0) || (lVar4 = *(longlong *)(lVar7 + 0x60), lVar4 == 0))
                goto code_r0x000180654a2e;
                uStack_c8 = *(undefined8 *)(lVar4 + 0x1bc);
                fVar17 = (*(float *)(lVar4 + 0x1c4) - (float)uStack_b0) * 0.1 + (float)uStack_b0;
                fVar13 = ((float)((ulonglong)uStack_c8 >> 0x20) - uStack_b8._4_4_) * 0.1 +
                         uStack_b8._4_4_;
                fVar15 = ((float)uStack_c8 - (float)uStack_b8) * 0.1 + (float)uStack_b8;
                if ((lVar7 == 0) || (lVar7 = *(longlong *)(lVar7 + 0x18), lVar7 == 0))
                goto code_r0x000180654a2e;
                uStack_c8 = 0;
                uStack_c0 = uStack_c0 & 0xffffffff00000000;
                pcVar6 = DAT_182ec1698;
                if ((DAT_182ec1698 == (code *)0x0) &&
                   (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar6 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60(
                                       "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec1698 = pcVar6;
                (*DAT_182ec1698)(lVar7,&uStack_c8);
                fVar17 = (fVar17 - (float)uStack_c0) + fStack_d0;
                uStack_d8 = CONCAT44((fVar13 - uStack_c8._4_4_) + uStack_d8._4_4_,
                                     (fVar15 - (float)uStack_c8) + (float)uStack_d8);
                if ((*(longlong *)(lVar3 + 0x78) == 0) ||
                   (lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0x78) + 0x18), lVar7 == 0))
                goto code_r0x000180654a2e;
                uStack_88 = 0;
                uStack_80 = 0;
                pcVar6 = DAT_182ec16b8;
                if ((DAT_182ec16b8 == (code *)0x0) &&
                   (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar6 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60(
                                       "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec16b8 = pcVar6;
                (*DAT_182ec16b8)(lVar7,&uStack_88);
                if ((*(longlong *)(lVar3 + 0x78) == 0) ||
                   (lVar4 = *(longlong *)(*(longlong *)(lVar3 + 0x78) + 0x60), lVar4 == 0))
                goto code_r0x000180654a2e;
                uStack_98 = *(undefined8 *)(lVar4 + 0x1c8);
                uStack_90 = *(undefined8 *)(lVar4 + 0x1d0);
                uStack_c8 = uStack_88;
                uStack_c0 = uStack_80;
                uStack_b8 = 0;
                uStack_b0 = 0;
                pcVar6 = DAT_182ec0e80;
                if ((DAT_182ec0e80 == (code *)0x0) &&
                   (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Quaternion::Lerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                                                  ), pcVar6 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60(
                                       "UnityEngine.Quaternion::Lerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec0e80 = pcVar6;
                (*DAT_182ec0e80)(&uStack_c8,&uStack_98,0x3e4ccccd,&uStack_b8);
                uStack_88 = uStack_b8;
                uStack_80 = uStack_b0;
                pcVar6 = DAT_182ec16c0;
                if ((DAT_182ec16c0 == (code *)0x0) &&
                   (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar6 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60(
                                       "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec16c0 = pcVar6;
                (*DAT_182ec16c0)(lVar7,&uStack_88);
              }
              if ((*(longlong *)(lVar3 + 0x78) != 0) &&
                 (lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0x78) + 0x60), lVar7 != 0)) {
                uVar8 = *(undefined8 *)(lVar7 + 0x248);
                uStack_b8 = *(undefined8 *)(lVar7 + 400);
                fVar14 = (float)uStack_b8;
                uVar9 = (ulonglong)uStack_b8 >> 0x20;
                fVar13 = *(float *)(lVar7 + 0x250);
                fVar15 = *(float *)(lVar7 + 0x198);
                pcVar6 = pcRam0000000182ec14f8;
                if ((pcRam0000000182ec14f8 == (code *)0x0) &&
                   (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_fixedDeltaTime()"),
                   pcVar6 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60("UnityEngine.Time::get_fixedDeltaTime()");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                pcRam0000000182ec14f8 = pcVar6;
                fVar12 = (float)(*pcRam0000000182ec14f8)();
                fVar16 = ((float)uVar8 + fVar14) * fVar12 + (float)uStack_d8;
                fVar14 = ((float)((ulonglong)uVar8 >> 0x20) + (float)uVar9) * fVar12 +
                         uStack_d8._4_4_;
                fVar17 = (fVar13 + fVar15) * fVar12 + fVar17;
                if (0.0 < fVar14 * fVar14 + fVar16 * fVar16 + fVar17 * fVar17) {
                  lVar7 = *(longlong *)(lVar3 + 0x30);
                  if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  uStack_d8 = CONCAT44(fVar14,fVar16);
                  pcVar6 = pcRam0000000182ec39e8;
                  fStack_d0 = fVar17;
                  if ((pcRam0000000182ec39e8 == (code *)0x0) &&
                     (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.CharacterController::Move_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar6 == (code *)0x0)) {
                    uVar8 = FUN_1802ced60(
                                         "UnityEngine.CharacterController::Move_Injected(UnityEngine.Vector3&)"
                                         );
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar8,0);
                  }
                  pcRam0000000182ec39e8 = pcVar6;
                  (*pcRam0000000182ec39e8)(lVar7,&uStack_d8);
                }
                if (*(longlong *)(lVar3 + 0x78) != 0) {
                  lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0x78) + 0x60);
                  if (DAT_182eb5480 == '\0') {
                    FUN_1802f2810(&DAT_182d522a8);
                    LOCK();
                    UNLOCK();
                    DAT_182eb5480 = '\x01';
                  }
                  uVar2 = *(undefined4 *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
                  if (lVar7 != 0) {
                    *(undefined8 *)(lVar7 + 0x248) = **(undefined8 **)(DAT_182d522a8 + 0xb8);
                    *(undefined4 *)(lVar7 + 0x250) = uVar2;
                    if ((*(longlong *)(lVar3 + 0x78) != 0) &&
                       (lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0x78) + 0x60), lVar7 != 0)) {
                      lVar7 = *(longlong *)(lVar7 + 0x60);
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
                      if (lVar7 != 0) {
                        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                          FUN_18035c820();
                        }
                        if (*(longlong *)(lVar7 + 0x10) != 0) {
                          if (((*(longlong *)(lVar3 + 0x78) == 0) ||
                              (lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0x78) + 0x60), lVar7 == 0
                              )) || (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 == 0))
                          goto code_r0x000180654a2e;
                          uStack_88 = 0;
                          uStack_80 = 0;
                          pcVar6 = DAT_182ec16b8;
                          if ((DAT_182ec16b8 == (code *)0x0) &&
                             (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar6 == (code *)0x0)) {
                            uVar8 = FUN_1802ced60(
                                                 "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                 );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar8,0);
                          }
                          DAT_182ec16b8 = pcVar6;
                          (*DAT_182ec16b8)(lVar7,&uStack_88);
                          uStack_b8 = uStack_88;
                          uStack_b0 = uStack_80;
                          lVar7 = FUN_1803fa4b0(&uStack_a8,&uStack_b8);
                          fVar17 = ABS(fVar18 - *(float *)(lVar7 + 4));
                          if ((*(longlong *)(lVar3 + 0x78) == 0) ||
                             (lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0x78) + 0x18), lVar7 == 0)
                             ) goto code_r0x000180654a2e;
                          uStack_b8 = 0;
                          uStack_b0 = uStack_b0 & 0xffffffff00000000;
                          pcVar6 = DAT_182ec1698;
                          if ((DAT_182ec1698 == (code *)0x0) &&
                             (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar6 == (code *)0x0)) {
                            uVar8 = FUN_1802ced60(
                                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                 );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar8,0);
                          }
                          DAT_182ec1698 = pcVar6;
                          (*DAT_182ec1698)(lVar7,&uStack_b8);
                          if (((*(longlong *)(lVar3 + 0x78) == 0) ||
                              (lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0x78) + 0x60), lVar7 == 0
                              )) || (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 == 0))
                          goto code_r0x000180654a2e;
                          uStack_c8 = 0;
                          uStack_c0 = uStack_c0 & 0xffffffff00000000;
                          pcVar6 = DAT_182ec1698;
                          if ((DAT_182ec1698 == (code *)0x0) &&
                             (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar6 == (code *)0x0)) {
                            uVar8 = FUN_1802ced60(
                                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                 );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar8,0);
                          }
                          DAT_182ec1698 = pcVar6;
                          (*DAT_182ec1698)(lVar7,&uStack_c8);
                          if (((uStack_b8._4_4_ - uStack_c8._4_4_) *
                               (uStack_b8._4_4_ - uStack_c8._4_4_) +
                               ((float)uStack_b8 - (float)uStack_c8) *
                               ((float)uStack_b8 - (float)uStack_c8) +
                               ((float)uStack_b0 - (float)uStack_c0) *
                               ((float)uStack_b0 - (float)uStack_c0) < 0.001) &&
                             ((fVar17 < 0.1 || (359.9 < fVar17)))) {
                            if ((*(longlong *)(lVar3 + 0x78) == 0) ||
                               (lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0x78) + 0x60),
                               lVar7 == 0)) goto code_r0x000180654a2e;
                            bVar11 = DAT_182eb5d50 != 0;
                            *(undefined8 *)(lVar7 + 0x60) = 0;
                            if (bVar11) {
                              uVar10 = (uint)(lVar7 + 0x60U >> 0xc);
                              uVar9 = (ulonglong)((uVar10 & 0x1fffff) >> 6);
                              do {
                                uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
                                LOCK();
                                bVar11 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
                                if (bVar11) {
                                  *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) =
                                       uVar5 | 1L << (uVar10 & 0x3f);
                                }
                                UNLOCK();
                              } while (!bVar11);
                            }
                          }
                          if ((*(longlong *)(lVar3 + 0x78) == 0) ||
                             (lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0x78) + 0x60), lVar7 == 0)
                             ) goto code_r0x000180654a2e;
                          fVar17 = *(float *)(lVar7 + 0x7c);
                          pcVar6 = pcRam0000000182ec14f8;
                          if ((pcRam0000000182ec14f8 == (code *)0x0) &&
                             (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Time::get_fixedDeltaTime()"),
                             pcVar6 == (code *)0x0)) {
                            uVar8 = FUN_1802ced60("UnityEngine.Time::get_fixedDeltaTime()");
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar8,0);
                          }
                          pcRam0000000182ec14f8 = pcVar6;
                          fVar13 = (float)(*pcRam0000000182ec14f8)();
                          lVar4 = *(longlong *)(lVar3 + 0x78);
                          *(float *)(lVar7 + 0x7c) = fVar17 - fVar13;
                          if ((lVar4 == 0) || (lVar7 = *(longlong *)(lVar4 + 0x60), lVar7 == 0))
                          goto code_r0x000180654a2e;
                          pfVar1 = (float *)(lVar7 + 0x7c);
                          if (*pfVar1 <= 0.0 && *pfVar1 != 0.0) {
                            bVar11 = DAT_182eb5d50 != 0;
                            lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0x78) + 0x60);
                            *(undefined8 *)(lVar7 + 0x60) = 0;
                            if (bVar11) {
                              uVar10 = (uint)(lVar7 + 0x60U >> 0xc);
                              uVar9 = (ulonglong)((uVar10 & 0x1fffff) >> 6);
                              do {
                                uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
                                LOCK();
                                bVar11 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
                                if (bVar11) {
                                  *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) =
                                       uVar5 | 1L << (uVar10 & 0x3f);
                                }
                                UNLOCK();
                              } while (!bVar11);
                            }
                          }
                        }
                      }
                      lVar7 = *(longlong *)(lVar3 + 0x78);
                      if ((lVar7 != 0) && (lVar4 = *(longlong *)(lVar7 + 0x60), lVar4 != 0)) {
                        if (*(char *)(lVar4 + 0x1d8) != '\0') {
                          lVar7 = *(longlong *)(lVar7 + 0x18);
                          if (lVar7 == 0) {
code_r0x000180654c34:
                    /* WARNING: Subroutine does not return */
                            FUN_18031dad0();
                          }
                          uStack_b0 = CONCAT44(uStack_b0._4_4_,*(undefined4 *)(lVar4 + 0x1e4));
                          pcVar6 = DAT_182ec16a0;
                          uStack_b8 = *(undefined8 *)(lVar4 + 0x1dc);
                          if ((DAT_182ec16a0 == (code *)0x0) &&
                             (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar6 == (code *)0x0)) {
                            uVar8 = FUN_1802ced60(
                                                 "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                                 );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar8,0);
                          }
                          DAT_182ec16a0 = pcVar6;
                          (*DAT_182ec16a0)(lVar7,&uStack_b8);
                          lVar7 = *(longlong *)(lVar3 + 0x78);
                          if ((lVar7 == 0) || (lVar4 = *(longlong *)(lVar7 + 0x60), lVar4 == 0))
                          goto code_r0x000180654c34;
                          lVar7 = *(longlong *)(lVar7 + 0x18);
                          if (lVar7 == 0) goto code_r0x000180654c34;
                          pcVar6 = DAT_182ec16c0;
                          uStack_78 = *(undefined8 *)(lVar4 + 0x1e8);
                          uStack_70 = *(ulonglong *)(lVar4 + 0x1f0);
                          if ((DAT_182ec16c0 == (code *)0x0) &&
                             (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar6 == (code *)0x0)) {
                            uVar8 = FUN_1802ced60(
                                                 "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                                 );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar8,0);
                          }
                          DAT_182ec16c0 = pcVar6;
                          (*DAT_182ec16c0)(lVar7,&uStack_78);
                        }
                        lVar7 = *(longlong *)(lVar3 + 0x78);
                        if ((lVar7 != 0) && (*(longlong *)(lVar7 + 0x60) != 0)) {
                          if (*(char *)(*(longlong *)(lVar7 + 0x60) + 0x68) != '\0') {
                            lVar7 = *(longlong *)(lVar7 + 0x18);
                            if (lVar7 == 0) goto code_r0x000180654a2e;
                            uStack_88 = 0;
                            uStack_80 = 0;
                            pcVar6 = DAT_182ec16b8;
                            if ((DAT_182ec16b8 == (code *)0x0) &&
                               (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar6 == (code *)0x0)) {
                              uVar8 = FUN_1802ced60(
                                                  "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                              FUN_1802cca90(uVar8,0);
                            }
                            DAT_182ec16b8 = pcVar6;
                            (*DAT_182ec16b8)(lVar7,&uStack_88);
                            if ((*(longlong *)(lVar3 + 0x78) == 0) ||
                               (lVar4 = *(longlong *)(*(longlong *)(lVar3 + 0x78) + 0x60),
                               lVar4 == 0)) goto code_r0x000180654a2e;
                            if (*(char *)(lVar4 + 0x68) == '\0') {
code_r0x000180654c6e:
                              FUN_181640030(0);
                              pcVar6 = (code *)swi(3);
                              (*pcVar6)();
                              return;
                            }
                            uStack_98 = *(undefined8 *)(lVar4 + 0x6c);
                            uStack_90 = *(undefined8 *)(lVar4 + 0x74);
                            uStack_b8 = uStack_88;
                            uStack_b0 = uStack_80;
                            uStack_a8 = 0;
                            uStack_a0 = 0;
                            pcVar6 = DAT_182ec0e80;
                            if ((DAT_182ec0e80 == (code *)0x0) &&
                               (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Quaternion::Lerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                                                  ), pcVar6 == (code *)0x0)) {
                              uVar8 = FUN_1802ced60(
                                                  "UnityEngine.Quaternion::Lerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                              FUN_1802cca90(uVar8,0);
                            }
                            DAT_182ec0e80 = pcVar6;
                            (*DAT_182ec0e80)(&uStack_b8,&uStack_98,0x3dcccccd,&uStack_a8);
                            uStack_78 = uStack_a8;
                            uStack_70 = uStack_a0;
                            pcVar6 = DAT_182ec16c0;
                            if ((DAT_182ec16c0 == (code *)0x0) &&
                               (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar6 == (code *)0x0)) {
                              uVar8 = FUN_1802ced60(
                                                  "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                              FUN_1802cca90(uVar8,0);
                            }
                            DAT_182ec16c0 = pcVar6;
                            (*DAT_182ec16c0)(lVar7,&uStack_78);
                            if ((*(longlong *)(lVar3 + 0x78) == 0) ||
                               (lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0x78) + 0x60),
                               lVar7 == 0)) {
                    /* WARNING: Subroutine does not return */
                              FUN_18031dad0();
                            }
                            if (*(char *)(lVar7 + 0x68) == '\0') goto code_r0x000180654c6e;
                            uStack_b8 = *(undefined8 *)(lVar7 + 0x6c);
                            uStack_b0 = *(ulonglong *)(lVar7 + 0x74);
                            lVar7 = FUN_1803fa4b0(&uStack_a8,&uStack_b8);
                            fVar18 = ABS(fVar18 - *(float *)(lVar7 + 4));
                            if ((fVar18 < 0.1) || (359.9 < fVar18)) {
                              if ((*(longlong *)(lVar3 + 0x78) == 0) ||
                                 (lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0x78) + 0x60),
                                 lVar7 == 0)) goto code_r0x000180654a2e;
                              *(undefined8 *)(lVar7 + 0x68) = 0;
                              *(undefined8 *)(lVar7 + 0x70) = 0;
                              *(undefined4 *)(lVar7 + 0x78) = 0;
                            }
                          }
                          if ((*(longlong *)(lVar3 + 0x78) != 0) &&
                             (lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0x78) + 0x60), lVar7 != 0)
                             ) {
                            if ((*(longlong *)(lVar7 + 0x20) != 0) &&
                               (*(float *)(lVar7 + 0x84) <= 0.5)) {
                              if (*(longlong *)(lVar3 + 0x88) == 0) goto code_r0x000180654a2e;
                              ExposureUnnoticed2_Object3D_Player_Scripts_Other_PlayerCollisionCorrecter__CollisionCorrect__06000eba
                                        (*(longlong *)(lVar3 + 0x88),0);
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
    }
  }
                    /* WARNING: Subroutine does not return */
  puStack_30 = &UNK_18064506b;
  FUN_18031dad0();
}

