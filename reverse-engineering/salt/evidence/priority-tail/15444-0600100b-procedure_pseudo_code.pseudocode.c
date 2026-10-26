// Ghidra pseudocode; not original source or compilable C.
// ev_47aa5ec36fc483c44e450561208e8f37c6707708d993fca222dc2ec3153963aa

void ExposureUnnoticed2_Object3D_NPC_Script_NpcCollisionCorrecter__CollisionCorrect__0600100b
               (longlong param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  char cVar9;
  int iVar10;
  code *pcVar11;
  longlong lVar12;
  undefined8 *puVar13;
  undefined8 uVar14;
  longlong lVar15;
  longlong lVar16;
  uint uVar17;
  bool bVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  undefined8 uVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fStackX_8;
  float afStackX_18 [2];
  longlong lStackX_20;
  undefined8 in_stack_fffffffffffffe88;
  undefined4 uVar29;
  undefined8 uStack_158;
  float fStack_150;
  undefined8 uStack_148;
  float fStack_140;
  undefined8 uStack_138;
  float fStack_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
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
  
  uVar29 = (undefined4)((ulonglong)in_stack_fffffffffffffe88 >> 0x20);
  if (cRam0000000182eb7752 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d55a30);
    LOCK();
    UNLOCK();
    cRam0000000182eb7752 = '\x01';
  }
  uStack_118 = 0;
  fStack_110 = 0.0;
  afStackX_18[0] = 0.0;
  if ((*(longlong *)(param_1 + 0x10) != 0) &&
     (lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x80), lVar15 != 0)) {
    pcVar11 = pcRam0000000182ec3a28;
    if ((pcRam0000000182ec3a28 == (code *)0x0) &&
       (pcVar11 = (code *)FUN_1802cf0c0("UnityEngine.CapsuleCollider::get_height()"),
       pcVar11 == (code *)0x0)) {
      uVar14 = FUN_1802ced60("UnityEngine.CapsuleCollider::get_height()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar14,0);
    }
    pcRam0000000182ec3a28 = pcVar11;
    fVar19 = (float)(*pcRam0000000182ec3a28)(lVar15);
    if ((*(longlong *)(param_1 + 0x10) != 0) &&
       (lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x80), lVar15 != 0)) {
      pcVar11 = pcRam0000000182ec3a18;
      if ((pcRam0000000182ec3a18 == (code *)0x0) &&
         (pcVar11 = (code *)FUN_1802cf0c0("UnityEngine.CapsuleCollider::get_radius()"),
         pcVar11 == (code *)0x0)) {
        uVar14 = FUN_1802ced60("UnityEngine.CapsuleCollider::get_radius()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar14,0);
      }
      pcRam0000000182ec3a18 = pcVar11;
      fVar20 = (float)(*pcRam0000000182ec3a18)(lVar15);
      fVar20 = fVar19 * 0.5 - fVar20;
      if ((*(longlong *)(param_1 + 0x10) != 0) &&
         (lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10), lVar15 != 0)) {
        uStack_148 = 0;
        fStack_140 = 0.0;
        pcVar11 = DAT_182ec1698;
        if ((DAT_182ec1698 == (code *)0x0) &&
           (pcVar11 = (code *)FUN_1802cf0c0(
                                           "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                           ), pcVar11 == (code *)0x0)) {
          uVar14 = FUN_1802ced60(
                                "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar14,0);
        }
        DAT_182ec1698 = pcVar11;
        (*DAT_182ec1698)(lVar15,&uStack_148);
        if ((*(longlong *)(param_1 + 0x10) != 0) &&
           (lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x80), lVar15 != 0)) {
          uStack_158 = 0;
          fStack_150 = 0.0;
          pcVar11 = DAT_182ec3a48;
          if ((DAT_182ec3a48 == (code *)0x0) &&
             (pcVar11 = (code *)FUN_1802cf0c0(
                                             "UnityEngine.CapsuleCollider::get_center_Injected(UnityEngine.Vector3&)"
                                             ), pcVar11 == (code *)0x0)) {
            uVar14 = FUN_1802ced60(
                                  "UnityEngine.CapsuleCollider::get_center_Injected(UnityEngine.Vector3&)"
                                  );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar14,0);
          }
          DAT_182ec3a48 = pcVar11;
          (*DAT_182ec3a48)(lVar15,&uStack_158);
          fVar19 = (float)uStack_148 + (float)uStack_158;
          fVar27 = uStack_148._4_4_ + uStack_158._4_4_;
          fVar28 = fStack_140 + fStack_150;
          if (DAT_182eb547c == '\0') {
            FUN_1802f2810(&DAT_182d522a8);
            LOCK();
            UNLOCK();
            DAT_182eb547c = '\x01';
          }
          uStack_138 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
          fVar22 = (float)uStack_138;
          uVar7 = (ulonglong)uStack_138 >> 0x20;
          fVar1 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20);
          if ((*(longlong *)(param_1 + 0x10) != 0) &&
             (lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10), lVar15 != 0)) {
            uStack_148 = 0;
            fStack_140 = 0.0;
            pcVar11 = DAT_182ec1698;
            if ((DAT_182ec1698 == (code *)0x0) &&
               (pcVar11 = (code *)FUN_1802cf0c0(
                                               "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                               ), pcVar11 == (code *)0x0)) {
              uVar14 = FUN_1802ced60(
                                    "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                    );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar14,0);
            }
            DAT_182ec1698 = pcVar11;
            (*DAT_182ec1698)(lVar15,&uStack_148);
            if ((*(longlong *)(param_1 + 0x10) != 0) &&
               (lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x80), lVar15 != 0)) {
              uStack_158 = 0;
              fStack_150 = 0.0;
              pcVar11 = DAT_182ec3a48;
              if ((DAT_182ec3a48 == (code *)0x0) &&
                 (pcVar11 = (code *)FUN_1802cf0c0(
                                                 "UnityEngine.CapsuleCollider::get_center_Injected(UnityEngine.Vector3&)"
                                                 ), pcVar11 == (code *)0x0)) {
                uVar14 = FUN_1802ced60(
                                      "UnityEngine.CapsuleCollider::get_center_Injected(UnityEngine.Vector3&)"
                                      );
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar14,0);
              }
              DAT_182ec3a48 = pcVar11;
              (*DAT_182ec3a48)(lVar15,&uStack_158);
              fVar24 = (float)uStack_148 + (float)uStack_158;
              fVar25 = uStack_148._4_4_ + uStack_158._4_4_;
              fVar26 = fStack_140 + fStack_150;
              if (DAT_182eb547c == '\0') {
                FUN_1802f2810(&DAT_182d522a8);
                LOCK();
                UNLOCK();
                DAT_182eb547c = '\x01';
              }
              uStack_138 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
              fVar21 = (float)uStack_138;
              uVar8 = (ulonglong)uStack_138 >> 0x20;
              fVar2 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20);
              if ((*(longlong *)(param_1 + 0x10) != 0) &&
                 (lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x80), lVar15 != 0)) {
                pcVar11 = pcRam0000000182ec3a18;
                if ((pcRam0000000182ec3a18 == (code *)0x0) &&
                   (pcVar11 = (code *)FUN_1802cf0c0("UnityEngine.CapsuleCollider::get_radius()"),
                   pcVar11 == (code *)0x0)) {
                  uVar14 = FUN_1802ced60("UnityEngine.CapsuleCollider::get_radius()");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar14,0);
                }
                pcRam0000000182ec3a18 = pcVar11;
                uVar23 = (*pcRam0000000182ec3a18)(lVar15);
                uVar14 = *(undefined8 *)(param_1 + 0x18);
                uVar3 = *(undefined4 *)(param_1 + 0x20);
                if (*(int *)(lRam0000000182d55a30 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                uStack_128 = CONCAT44((float)uVar8 * fVar20 + fVar25,fVar21 * fVar20 + fVar24);
                uStack_158 = CONCAT44(fVar27 - (float)uVar7 * fVar20,fVar19 - fVar22 * fVar20);
                uStack_120 = CONCAT44(uStack_120._4_4_,fVar2 * fVar20 + fVar26);
                fStack_150 = fVar28 - fVar1 * fVar20;
                iVar10 = FUN_181fb5e80(&uStack_158,&uStack_128,uVar23,uVar14,CONCAT44(uVar29,uVar3),
                                       0);
                if (DAT_182eb5480 == '\0') {
                  FUN_1802f2810(&DAT_182d522a8);
                  LOCK();
                  UNLOCK();
                  DAT_182eb5480 = '\x01';
                }
                uVar17 = 0;
                fStackX_8 = *(float *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
                uStack_148 = **(undefined8 **)(DAT_182d522a8 + 0xb8);
                fStack_140 = fStackX_8;
                if (0 < iVar10) {
                  lVar15 = 0;
                  lVar16 = 0x20;
                  lStackX_20 = (longlong)iVar10;
                  do {
                    lVar4 = *(longlong *)(param_1 + 0x18);
                    if (lVar4 == 0) goto code_r0x000180423d81;
                    if (*(uint *)(lVar4 + 0x18) <= uVar17) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031dae0();
                    }
                    lVar4 = *(longlong *)(lVar4 + lVar16);
                    if (*(longlong *)(param_1 + 0x10) == 0) goto code_r0x000180423d81;
                    lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x80);
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
                    if (lVar12 != 0 || lVar4 != 0) {
                      if (lVar12 == 0) {
                        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                          FUN_18035c820();
                        }
                        if (lVar4 == 0) goto code_r0x000180423d81;
                        bVar18 = *(longlong *)(lVar4 + 0x10) == 0;
                      }
                      else if (lVar4 == 0) {
                        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                          FUN_18035c820();
                        }
                        bVar18 = *(longlong *)(lVar12 + 0x10) == 0;
                      }
                      else {
                        bVar18 = lVar4 == lVar12;
                      }
                      if (!bVar18) {
                        if (lVar4 == 0) goto code_r0x000180423d81;
                        cVar9 = FUN_181fb8e60(lVar4,0);
                        if (cVar9 == '\0') {
                          lVar12 = *(longlong *)(param_1 + 0x10);
                          if (lVar12 == 0) goto code_r0x000180423d81;
                          lVar5 = *(longlong *)(lVar12 + 0x10);
                          uVar14 = *(undefined8 *)(lVar12 + 0x80);
                          if (lVar5 == 0) goto code_r0x000180423d81;
                          uStack_128 = 0;
                          uStack_120 = uStack_120 & 0xffffffff00000000;
                          pcVar11 = DAT_182ec1698;
                          if ((DAT_182ec1698 == (code *)0x0) &&
                             (pcVar11 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar11 == (code *)0x0)) {
                            uVar14 = FUN_1802ced60(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar14,0);
                          }
                          DAT_182ec1698 = pcVar11;
                          (*DAT_182ec1698)(lVar5,&uStack_128);
                          if (DAT_182eb547f == '\0') {
                            FUN_1802f2810(&DAT_182d52290);
                            LOCK();
                            UNLOCK();
                            DAT_182eb547f = '\x01';
                          }
                          uVar23 = **(undefined8 **)(DAT_182d52290 + 0xb8);
                          uVar6 = (*(undefined8 **)(DAT_182d52290 + 0xb8))[1];
                          lVar12 = FUN_181d769d0(lVar4,0);
                          if (lVar12 == 0) goto code_r0x000180423d81;
                          uStack_158 = 0;
                          fStack_150 = 0.0;
                          pcVar11 = DAT_182ec1698;
                          if ((DAT_182ec1698 == (code *)0x0) &&
                             (pcVar11 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar11 == (code *)0x0)) {
                            uVar14 = FUN_1802ced60(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar14,0);
                          }
                          DAT_182ec1698 = pcVar11;
                          (*DAT_182ec1698)(lVar12,&uStack_158);
                          lVar12 = FUN_181d769d0(lVar4,0);
                          if (lVar12 == 0) goto code_r0x000180423d81;
                          uStack_f8 = 0;
                          uStack_f0 = 0;
                          pcVar11 = DAT_182ec16b8;
                          if ((DAT_182ec16b8 == (code *)0x0) &&
                             (pcVar11 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar11 == (code *)0x0)) {
                            uVar14 = FUN_1802ced60(
                                                  "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar14,0);
                          }
                          DAT_182ec16b8 = pcVar11;
                          (*DAT_182ec16b8)(lVar12,&uStack_f8);
                          if (*(int *)(lRam0000000182d55a30 + 0xe0) == 0) {
                            FUN_18035c820();
                          }
                          if (cRam0000000182ec3741 == '\0') {
                            FUN_1802f2810(0x182d55a30);
                            LOCK();
                            UNLOCK();
                            cRam0000000182ec3741 = '\x01';
                          }
                          if (DAT_182eb5480 == '\0') {
                            FUN_1802f2810(&DAT_182d522a8);
                            LOCK();
                            UNLOCK();
                            DAT_182eb5480 = '\x01';
                          }
                          uStack_118 = **(undefined8 **)(DAT_182d522a8 + 0xb8);
                          fStack_110 = *(float *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
                          afStackX_18[0] = 0.0;
                          if (*(int *)(lRam0000000182d55a30 + 0xe0) == 0) {
                            FUN_18035c820();
                          }
                          uStack_d8 = uStack_f8;
                          uStack_d0 = uStack_f0;
                          fStack_100 = fStack_150;
                          uStack_138 = uStack_128;
                          uStack_108 = uStack_158;
                          fStack_130 = (float)uStack_120;
                          uStack_e8 = uVar23;
                          uStack_e0 = uVar6;
                          if (cRam0000000182ec3740 == '\0') {
                            FUN_1802f2810(0x182d55a30);
                            LOCK();
                            UNLOCK();
                            cRam0000000182ec3740 = '\x01';
                          }
                          if (*(int *)(lRam0000000182d55a30 + 0xe0) == 0) {
                            FUN_18035c820();
                          }
                          pcVar11 = pcRam0000000182ec3798;
                          if ((pcRam0000000182ec3798 == (code *)0x0) &&
                             (pcVar11 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Physics::Query_ComputePenetration_Injected(UnityEngine.Collider,UnityEngine.Vector3&,UnityEngine.Quaternion&,UnityEngine.Collider,UnityEngine.Vector3&,UnityEngine.Quaternion&,UnityEngine.Vector3&,System.Single&)"
                                                  ), pcVar11 == (code *)0x0)) {
                            uVar14 = FUN_1802ced60(
                                                  "UnityEngine.Physics::Query_ComputePenetration_Injected(UnityEngine.Collider,UnityEngine.Vector3&,UnityEngine.Quaternion&,UnityEngine.Collider,UnityEngine.Vector3&,UnityEngine.Quaternion&,UnityEngine.Vector3&,System.Single&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar14,0);
                          }
                          pcRam0000000182ec3798 = pcVar11;
                          cVar9 = (*pcRam0000000182ec3798)
                                            (uVar14,&uStack_138,&uStack_e8,lVar4,&uStack_108,
                                             &uStack_d8,&uStack_118,afStackX_18);
                          if (cVar9 != '\0') {
                            fStackX_8 = fStack_110 * afStackX_18[0] + fStack_140;
                            uStack_148 = CONCAT44(uStack_118._4_4_ * afStackX_18[0] +
                                                  uStack_148._4_4_,
                                                  (float)uStack_118 * afStackX_18[0] +
                                                  (float)uStack_148);
                            fStack_140 = fStackX_8;
                          }
                        }
                      }
                    }
                    uVar17 = uVar17 + 1;
                    lVar15 = lVar15 + 1;
                    lVar16 = lVar16 + 8;
                  } while (lVar15 < lStackX_20);
                }
                if ((*(longlong *)(param_1 + 0x10) != 0) &&
                   (lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10), lVar15 != 0)) {
                  puVar13 = (undefined8 *)FUN_181f4c360(&uStack_128,lVar15,0);
                  uVar14 = *puVar13;
                  fVar19 = *(float *)(puVar13 + 1);
                  if (DAT_182eb547c == '\0') {
                    FUN_1802f2810(&DAT_182d522a8);
                    LOCK();
                    UNLOCK();
                    DAT_182eb547c = '\x01';
                  }
                  uStack_138 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
                  fStack_130 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20);
                  uStack_f8 = 0;
                  uStack_f0 = 0;
                  pcVar11 = DAT_182ec0ea8;
                  uStack_108 = uVar14;
                  fStack_100 = fVar19;
                  if ((DAT_182ec0ea8 == (code *)0x0) &&
                     (pcVar11 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                                  ), pcVar11 == (code *)0x0)) {
                    uVar14 = FUN_1802ced60(
                                          "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                          );
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar14,0);
                  }
                  DAT_182ec0ea8 = pcVar11;
                  (*DAT_182ec0ea8)(&uStack_108,&uStack_138,&uStack_f8);
                  uStack_e8 = uStack_f8;
                  uStack_e0 = uStack_f0;
                  uStack_128 = 0;
                  uStack_120 = 0;
                  pcVar11 = DAT_182ec0e68;
                  if ((DAT_182ec0e68 == (code *)0x0) &&
                     (pcVar11 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Quaternion::Inverse_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&)"
                                                  ), pcVar11 == (code *)0x0)) {
                    uVar14 = FUN_1802ced60(
                                          "UnityEngine.Quaternion::Inverse_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&)"
                                          );
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar14,0);
                  }
                  DAT_182ec0e68 = pcVar11;
                  (*DAT_182ec0e68)(&uStack_e8,&uStack_128);
                  fVar28 = (float)uStack_120 + (float)uStack_120;
                  fVar19 = (float)uStack_148;
                  fVar20 = uStack_148._4_4_;
                  fVar27 = uStack_128._4_4_ + uStack_128._4_4_;
                  fVar27 = (1.0 - (fVar28 * (float)uStack_120 + fVar27 * uStack_128._4_4_)) *
                           (float)uStack_148 +
                           (fVar27 * (float)uStack_128 - fVar28 * uStack_120._4_4_) *
                           uStack_148._4_4_ +
                           (fVar28 * (float)uStack_128 + fVar27 * uStack_120._4_4_) * fStackX_8;
                  iVar10 = 1;
                  if (fVar27 < 0.0) {
                    iVar10 = -1;
                  }
                  if (fVar27 == 0.0) {
                    iVar10 = 0;
                  }
                  if ((*(longlong *)(param_1 + 0x10) != 0) &&
                     (lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10), lVar15 != 0)) {
                    uStack_158 = 0;
                    fStack_150 = 0.0;
                    pcVar11 = DAT_182ec1698;
                    if ((DAT_182ec1698 == (code *)0x0) &&
                       (pcVar11 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar11 == (code *)0x0)) {
                      uVar14 = FUN_1802ced60(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            );
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar14,0);
                    }
                    DAT_182ec1698 = pcVar11;
                    (*DAT_182ec1698)(lVar15,&uStack_158);
                    if ((*(longlong *)(param_1 + 0x10) != 0) &&
                       (lVar16 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10), lVar16 != 0))
                    {
                      puVar13 = (undefined8 *)FUN_181f4be60(&uStack_108,lVar16,0);
                      fVar27 = (float)iVar10;
                      fStack_130 = *(float *)(puVar13 + 1) * 0.01 * fVar27 + fStackX_8 + fStack_150;
                      uStack_138 = CONCAT44((float)((ulonglong)*puVar13 >> 0x20) * 0.01 * fVar27 +
                                            fVar20 + uStack_158._4_4_,
                                            (float)*puVar13 * 0.01 * fVar27 + fVar19 +
                                            (float)uStack_158);
                      pcVar11 = DAT_182ec16a0;
                      if ((DAT_182ec16a0 == (code *)0x0) &&
                         (pcVar11 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar11 == (code *)0x0)) {
                        uVar14 = FUN_1802ced60(
                                              "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                              );
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar14,0);
                      }
                      DAT_182ec16a0 = pcVar11;
                      (*DAT_182ec16a0)(lVar15,&uStack_138);
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
code_r0x000180423d81:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

