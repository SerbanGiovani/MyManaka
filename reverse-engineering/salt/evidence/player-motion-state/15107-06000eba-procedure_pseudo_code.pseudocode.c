// Ghidra pseudocode; not original source or compilable C.
// ev_5e42e111819b12c1785c75100b0219a2edaea4a164d34a90bcb98878ebd6c6c5

void ExposureUnnoticed2_Object3D_Player_Scripts_Other_PlayerCollisionCorrecter__CollisionCorrect__06000eba
               (longlong param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  char cVar7;
  int iVar8;
  code *pcVar9;
  longlong lVar10;
  undefined8 *puVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  longlong lVar14;
  ulonglong uVar15;
  bool bVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  undefined8 uVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fStackX_8;
  float afStackX_18 [2];
  longlong lStackX_20;
  undefined8 in_stack_fffffffffffffe98;
  undefined4 uVar27;
  undefined8 uStack_148;
  float fStack_140;
  undefined8 uStack_138;
  float fStack_130;
  undefined8 uStack_128;
  float fStack_120;
  undefined8 uStack_118;
  float fStack_110;
  undefined8 uStack_108;
  float fStack_100;
  undefined8 uStack_f8;
  float fStack_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  
  uVar27 = (undefined4)((ulonglong)in_stack_fffffffffffffe98 >> 0x20);
  if (cRam0000000182eb768b == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d55a30);
    LOCK();
    UNLOCK();
    cRam0000000182eb768b = '\x01';
  }
  uStack_108 = 0;
  fStack_100 = 0.0;
  afStackX_18[0] = 0.0;
  if ((*(longlong *)(param_1 + 0x10) != 0) &&
     (lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x88), lVar14 != 0)) {
    pcVar9 = pcRam0000000182ec3a28;
    if ((pcRam0000000182ec3a28 == (code *)0x0) &&
       (pcVar9 = (code *)FUN_1802cf0c0("UnityEngine.CapsuleCollider::get_height()"),
       pcVar9 == (code *)0x0)) {
      uVar12 = FUN_1802ced60("UnityEngine.CapsuleCollider::get_height()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar12,0);
    }
    pcRam0000000182ec3a28 = pcVar9;
    fVar17 = (float)(*pcRam0000000182ec3a28)(lVar14);
    if ((*(longlong *)(param_1 + 0x10) != 0) &&
       (lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x88), lVar14 != 0)) {
      pcVar9 = pcRam0000000182ec3a18;
      if ((pcRam0000000182ec3a18 == (code *)0x0) &&
         (pcVar9 = (code *)FUN_1802cf0c0("UnityEngine.CapsuleCollider::get_radius()"),
         pcVar9 == (code *)0x0)) {
        uVar12 = FUN_1802ced60("UnityEngine.CapsuleCollider::get_radius()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar12,0);
      }
      pcRam0000000182ec3a18 = pcVar9;
      fVar18 = (float)(*pcRam0000000182ec3a18)(lVar14);
      fVar18 = fVar17 * 0.5 - fVar18;
      if ((*(longlong *)(param_1 + 0x10) != 0) &&
         (lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18), lVar14 != 0)) {
        uStack_138 = 0;
        fStack_130 = 0.0;
        pcVar9 = DAT_182ec1698;
        if ((DAT_182ec1698 == (code *)0x0) &&
           (pcVar9 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                          ), pcVar9 == (code *)0x0)) {
          uVar12 = FUN_1802ced60(
                                "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar12,0);
        }
        DAT_182ec1698 = pcVar9;
        (*DAT_182ec1698)(lVar14,&uStack_138);
        if ((*(longlong *)(param_1 + 0x10) != 0) &&
           (lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x88), lVar14 != 0)) {
          uStack_148 = 0;
          fStack_140 = 0.0;
          pcVar9 = DAT_182ec3a48;
          if ((DAT_182ec3a48 == (code *)0x0) &&
             (pcVar9 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.CapsuleCollider::get_center_Injected(UnityEngine.Vector3&)"
                                            ), pcVar9 == (code *)0x0)) {
            uVar12 = FUN_1802ced60(
                                  "UnityEngine.CapsuleCollider::get_center_Injected(UnityEngine.Vector3&)"
                                  );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar12,0);
          }
          DAT_182ec3a48 = pcVar9;
          (*DAT_182ec3a48)(lVar14,&uStack_148);
          fVar17 = (float)uStack_138 + (float)uStack_148;
          fVar25 = uStack_138._4_4_ + uStack_148._4_4_;
          fVar26 = fStack_130 + fStack_140;
          if (DAT_182eb547c == '\0') {
            FUN_1802f2810(&DAT_182d522a8);
            LOCK();
            UNLOCK();
            DAT_182eb547c = '\x01';
          }
          uStack_128 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
          fVar21 = (float)uStack_128;
          uVar13 = (ulonglong)uStack_128 >> 0x20;
          fVar1 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20);
          if ((*(longlong *)(param_1 + 0x10) != 0) &&
             (lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18), lVar14 != 0)) {
            uStack_138 = 0;
            fStack_130 = 0.0;
            pcVar9 = DAT_182ec1698;
            if ((DAT_182ec1698 == (code *)0x0) &&
               (pcVar9 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                              ), pcVar9 == (code *)0x0)) {
              uVar12 = FUN_1802ced60(
                                    "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                    );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar12,0);
            }
            DAT_182ec1698 = pcVar9;
            (*DAT_182ec1698)(lVar14,&uStack_138);
            if ((*(longlong *)(param_1 + 0x10) != 0) &&
               (lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x88), lVar14 != 0)) {
              uStack_148 = 0;
              fStack_140 = 0.0;
              pcVar9 = DAT_182ec3a48;
              if ((DAT_182ec3a48 == (code *)0x0) &&
                 (pcVar9 = (code *)FUN_1802cf0c0(
                                                "UnityEngine.CapsuleCollider::get_center_Injected(UnityEngine.Vector3&)"
                                                ), pcVar9 == (code *)0x0)) {
                uVar12 = FUN_1802ced60(
                                      "UnityEngine.CapsuleCollider::get_center_Injected(UnityEngine.Vector3&)"
                                      );
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar12,0);
              }
              DAT_182ec3a48 = pcVar9;
              (*DAT_182ec3a48)(lVar14,&uStack_148);
              fVar22 = (float)uStack_138 + (float)uStack_148;
              fVar23 = uStack_138._4_4_ + uStack_148._4_4_;
              fVar24 = fStack_130 + fStack_140;
              if (DAT_182eb547c == '\0') {
                FUN_1802f2810(&DAT_182d522a8);
                LOCK();
                UNLOCK();
                DAT_182eb547c = '\x01';
              }
              uStack_128 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
              fVar19 = (float)uStack_128;
              uVar15 = (ulonglong)uStack_128 >> 0x20;
              fVar2 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20);
              if ((*(longlong *)(param_1 + 0x10) != 0) &&
                 (lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x88), lVar14 != 0)) {
                pcVar9 = pcRam0000000182ec3a18;
                if ((pcRam0000000182ec3a18 == (code *)0x0) &&
                   (pcVar9 = (code *)FUN_1802cf0c0("UnityEngine.CapsuleCollider::get_radius()"),
                   pcVar9 == (code *)0x0)) {
                  uVar12 = FUN_1802ced60("UnityEngine.CapsuleCollider::get_radius()");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar12,0);
                }
                pcRam0000000182ec3a18 = pcVar9;
                uVar20 = (*pcRam0000000182ec3a18)(lVar14);
                uVar12 = *(undefined8 *)(param_1 + 0x18);
                uVar3 = *(undefined4 *)(param_1 + 0x20);
                if (*(int *)(lRam0000000182d55a30 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                uStack_148 = CONCAT44(fVar25 - (float)uVar13 * fVar18,fVar17 - fVar21 * fVar18);
                uVar13 = 0;
                uStack_118 = CONCAT44((float)uVar15 * fVar18 + fVar23,fVar19 * fVar18 + fVar22);
                fStack_140 = fVar26 - fVar1 * fVar18;
                fStack_110 = fVar2 * fVar18 + fVar24;
                iVar8 = FUN_181fb5e80(&uStack_148,&uStack_118,uVar20,uVar12,CONCAT44(uVar27,uVar3),0
                                     );
                if (DAT_182eb5480 == '\0') {
                  FUN_1802f2810(&DAT_182d522a8);
                  LOCK();
                  UNLOCK();
                  DAT_182eb5480 = '\x01';
                }
                fStackX_8 = *(float *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
                uStack_138 = **(undefined8 **)(DAT_182d522a8 + 0xb8);
                fStack_130 = fStackX_8;
                if (0 < iVar8) {
                  lVar14 = 0x20;
                  uVar15 = uVar13;
                  lStackX_20 = (longlong)iVar8;
                  do {
                    lVar4 = *(longlong *)(param_1 + 0x18);
                    if (lVar4 == 0) goto code_r0x0001804065ac;
                    if (*(uint *)(lVar4 + 0x18) <= (uint)uVar15) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031dae0();
                    }
                    lVar4 = *(longlong *)(lVar4 + lVar14);
                    if (*(longlong *)(param_1 + 0x10) == 0) goto code_r0x0001804065ac;
                    lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x88);
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
                    if (lVar10 != 0 || lVar4 != 0) {
                      if (lVar10 == 0) {
                        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                          FUN_18035c820();
                        }
                        if (lVar4 == 0) goto code_r0x0001804065ac;
                        bVar16 = *(longlong *)(lVar4 + 0x10) == 0;
                      }
                      else if (lVar4 == 0) {
                        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                          FUN_18035c820();
                        }
                        bVar16 = *(longlong *)(lVar10 + 0x10) == 0;
                      }
                      else {
                        bVar16 = lVar4 == lVar10;
                      }
                      if (!bVar16) {
                        if (lVar4 == 0) goto code_r0x0001804065ac;
                        cVar7 = FUN_181fb8e60(lVar4,0);
                        if (cVar7 == '\0') {
                          lVar10 = *(longlong *)(param_1 + 0x10);
                          if (lVar10 == 0) goto code_r0x0001804065ac;
                          lVar5 = *(longlong *)(lVar10 + 0x18);
                          uVar12 = *(undefined8 *)(lVar10 + 0x88);
                          if (lVar5 == 0) goto code_r0x0001804065ac;
                          uStack_118 = 0;
                          fStack_110 = 0.0;
                          pcVar9 = DAT_182ec1698;
                          if ((DAT_182ec1698 == (code *)0x0) &&
                             (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar9 == (code *)0x0)) {
                            uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar12,0);
                          }
                          DAT_182ec1698 = pcVar9;
                          (*DAT_182ec1698)(lVar5,&uStack_118);
                          if (DAT_182eb547f == '\0') {
                            FUN_1802f2810(&DAT_182d52290);
                            LOCK();
                            UNLOCK();
                            DAT_182eb547f = '\x01';
                          }
                          uVar20 = **(undefined8 **)(DAT_182d52290 + 0xb8);
                          uVar6 = (*(undefined8 **)(DAT_182d52290 + 0xb8))[1];
                          lVar10 = FUN_181d769d0(lVar4,0);
                          if (lVar10 == 0) goto code_r0x0001804065ac;
                          uStack_148 = 0;
                          fStack_140 = 0.0;
                          pcVar9 = DAT_182ec1698;
                          if ((DAT_182ec1698 == (code *)0x0) &&
                             (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar9 == (code *)0x0)) {
                            uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar12,0);
                          }
                          DAT_182ec1698 = pcVar9;
                          (*DAT_182ec1698)(lVar10,&uStack_148);
                          lVar10 = FUN_181d769d0(lVar4,0);
                          if (lVar10 == 0) goto code_r0x0001804065ac;
                          uStack_e8 = 0;
                          uStack_e0 = 0;
                          pcVar9 = DAT_182ec16b8;
                          if ((DAT_182ec16b8 == (code *)0x0) &&
                             (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar9 == (code *)0x0)) {
                            uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar12,0);
                          }
                          DAT_182ec16b8 = pcVar9;
                          (*DAT_182ec16b8)(lVar10,&uStack_e8);
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
                          uStack_108 = **(undefined8 **)(DAT_182d522a8 + 0xb8);
                          fStack_100 = *(float *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
                          afStackX_18[0] = 0.0;
                          if (*(int *)(lRam0000000182d55a30 + 0xe0) == 0) {
                            FUN_18035c820();
                          }
                          uStack_d8 = uStack_e8;
                          uStack_d0 = uStack_e0;
                          fStack_f0 = fStack_140;
                          uStack_128 = uStack_118;
                          uStack_f8 = uStack_148;
                          fStack_120 = fStack_110;
                          uStack_c8 = uVar20;
                          uStack_c0 = uVar6;
                          if (cRam0000000182ec3740 == '\0') {
                            FUN_1802f2810(0x182d55a30);
                            LOCK();
                            UNLOCK();
                            cRam0000000182ec3740 = '\x01';
                          }
                          if (*(int *)(lRam0000000182d55a30 + 0xe0) == 0) {
                            FUN_18035c820();
                          }
                          pcVar9 = pcRam0000000182ec3798;
                          if ((pcRam0000000182ec3798 == (code *)0x0) &&
                             (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Physics::Query_ComputePenetration_Injected(UnityEngine.Collider,UnityEngine.Vector3&,UnityEngine.Quaternion&,UnityEngine.Collider,UnityEngine.Vector3&,UnityEngine.Quaternion&,UnityEngine.Vector3&,System.Single&)"
                                                  ), pcVar9 == (code *)0x0)) {
                            uVar12 = FUN_1802ced60(
                                                  "UnityEngine.Physics::Query_ComputePenetration_Injected(UnityEngine.Collider,UnityEngine.Vector3&,UnityEngine.Quaternion&,UnityEngine.Collider,UnityEngine.Vector3&,UnityEngine.Quaternion&,UnityEngine.Vector3&,System.Single&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar12,0);
                          }
                          pcRam0000000182ec3798 = pcVar9;
                          cVar7 = (*pcRam0000000182ec3798)
                                            (uVar12,&uStack_128,&uStack_c8,lVar4,&uStack_f8,
                                             &uStack_d8,&uStack_108,afStackX_18);
                          if (cVar7 != '\0') {
                            fStackX_8 = fStack_100 * afStackX_18[0] + fStack_130;
                            uStack_138 = CONCAT44(uStack_108._4_4_ * afStackX_18[0] +
                                                  uStack_138._4_4_,
                                                  (float)uStack_108 * afStackX_18[0] +
                                                  (float)uStack_138);
                            fStack_130 = fStackX_8;
                          }
                        }
                      }
                    }
                    uVar15 = (ulonglong)((uint)uVar15 + 1);
                    uVar13 = uVar13 + 1;
                    lVar14 = lVar14 + 8;
                  } while ((longlong)uVar13 < lStackX_20);
                }
                if ((*(longlong *)(param_1 + 0x10) != 0) &&
                   (lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18), lVar14 != 0)) {
                  puVar11 = (undefined8 *)FUN_181f4c360(&uStack_118,lVar14,0);
                  uVar12 = *puVar11;
                  fVar17 = *(float *)(puVar11 + 1);
                  if (DAT_182eb547c == '\0') {
                    FUN_1802f2810(&DAT_182d522a8);
                    LOCK();
                    UNLOCK();
                    DAT_182eb547c = '\x01';
                  }
                  uStack_128 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
                  fStack_120 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20);
                  uStack_e8 = 0;
                  uStack_e0 = 0;
                  pcVar9 = DAT_182ec0ea8;
                  uStack_f8 = uVar12;
                  fStack_f0 = fVar17;
                  if ((DAT_182ec0ea8 == (code *)0x0) &&
                     (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                                  ), pcVar9 == (code *)0x0)) {
                    uVar12 = FUN_1802ced60(
                                          "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                          );
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar12,0);
                  }
                  DAT_182ec0ea8 = pcVar9;
                  (*DAT_182ec0ea8)(&uStack_f8,&uStack_128,&uStack_e8);
                  uStack_d8 = uStack_e8;
                  uStack_d0 = uStack_e0;
                  uStack_c8 = 0;
                  uStack_c0 = 0;
                  pcVar9 = DAT_182ec0e68;
                  if ((DAT_182ec0e68 == (code *)0x0) &&
                     (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Quaternion::Inverse_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&)"
                                                  ), pcVar9 == (code *)0x0)) {
                    uVar12 = FUN_1802ced60(
                                          "UnityEngine.Quaternion::Inverse_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&)"
                                          );
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar12,0);
                  }
                  DAT_182ec0e68 = pcVar9;
                  (*DAT_182ec0e68)(&uStack_d8,&uStack_c8);
                  if ((*(longlong *)(param_1 + 0x10) != 0) &&
                     (lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18), lVar14 != 0)) {
                    uStack_148 = 0;
                    fStack_140 = 0.0;
                    pcVar9 = DAT_182ec1698;
                    if ((DAT_182ec1698 == (code *)0x0) &&
                       (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar9 == (code *)0x0)) {
                      uVar12 = FUN_1802ced60(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            );
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar12,0);
                    }
                    DAT_182ec1698 = pcVar9;
                    (*DAT_182ec1698)(lVar14,&uStack_148);
                    fStack_120 = fStack_140 + fStackX_8;
                    uStack_128 = CONCAT44(uStack_148._4_4_ + uStack_138._4_4_,
                                          (float)uStack_148 + (float)uStack_138);
                    pcVar9 = DAT_182ec16a0;
                    if ((DAT_182ec16a0 == (code *)0x0) &&
                       (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar9 == (code *)0x0)) {
                      uVar12 = FUN_1802ced60(
                                            "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                            );
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar12,0);
                    }
                    DAT_182ec16a0 = pcVar9;
                    (*DAT_182ec16a0)(lVar14,&uStack_128);
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
code_r0x0001804065ac:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

