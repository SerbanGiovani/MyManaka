// Ghidra pseudocode; not original source or compilable C.
// ev_ac112a764c3942afbb1bbd5111a616ba4693fa35a291c05602008867a2566f19

void ExposureUnnoticed2_Object3D_NPC_Script_PlayerSearcher__OnUpdate__060010d2(longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  ulonglong uVar3;
  char cVar4;
  code *pcVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  undefined8 uStack_118;
  float fStack_110;
  undefined8 uStack_108;
  undefined4 uStack_100;
  undefined8 uStack_f8;
  float fStack_f0;
  undefined8 uStack_e8;
  float fStack_e0;
  undefined8 uStack_d8;
  float fStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  
  if (cRam0000000182eb7797 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7797 = '\x01';
  }
  lVar6 = *(longlong *)(param_1 + 0x80);
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
  if (lVar6 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar6 + 0x10) != 0) {
      pcVar5 = DAT_182ec1080;
      if ((DAT_182ec1080 == (code *)0x0) &&
         (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
         pcVar5 == (code *)0x0)) {
        uVar8 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar8,0);
      }
      DAT_182ec1080 = pcVar5;
      lVar6 = (*DAT_182ec1080)(param_1);
      if ((*(longlong *)(param_1 + 0x88) != 0) &&
         (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x88) + 0x10), lVar2 != 0)) {
        uStack_118 = 0;
        fStack_110 = 0.0;
        pcVar5 = DAT_182ec1698;
        if ((DAT_182ec1698 == (code *)0x0) &&
           (pcVar5 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                          ), pcVar5 == (code *)0x0)) {
          uVar8 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar8,0);
        }
        DAT_182ec1698 = pcVar5;
        (*DAT_182ec1698)(lVar2,&uStack_118);
        if ((*(longlong *)(param_1 + 0x88) != 0) &&
           (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x88) + 0x10), lVar2 != 0)) {
          puVar7 = (undefined8 *)FUN_181f4c360(&uStack_d8,lVar2,0);
          uStack_f8 = *puVar7;
          fStack_f0 = *(float *)(puVar7 + 1);
          if (DAT_182eb547c == '\0') {
            FUN_1802f2810(&DAT_182d522a8);
            LOCK();
            UNLOCK();
            DAT_182eb547c = '\x01';
          }
          uStack_108 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
          uStack_100 = *(undefined4 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20);
          uStack_c8 = 0;
          uStack_c0 = 0;
          pcVar5 = DAT_182ec0ea8;
          if ((DAT_182ec0ea8 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                            ), pcVar5 == (code *)0x0)) {
            uVar8 = FUN_1802ced60(
                                 "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar8,0);
          }
          DAT_182ec0ea8 = pcVar5;
          (*DAT_182ec0ea8)(&uStack_f8,&uStack_108,&uStack_c8);
          uVar8 = *(undefined8 *)(param_1 + 0x20);
          fVar15 = (float)uVar8;
          fVar11 = (float)uStack_c0 + (float)uStack_c0;
          fVar13 = uStack_c8._4_4_ + uStack_c8._4_4_;
          fVar14 = ((float)uStack_c8 + (float)uStack_c8) * (float)uStack_c8;
          fVar16 = ((float)uStack_c8 + (float)uStack_c8) * uStack_c0._4_4_;
          fVar12 = *(float *)(param_1 + 0x28);
          uStack_d8._4_4_ = (float)((ulonglong)uVar8 >> 0x20);
          fVar9 = (fVar13 * (float)uStack_c8 - fVar11 * uStack_c0._4_4_) * uStack_d8._4_4_;
          fVar10 = (1.0 - (fVar11 * (float)uStack_c0 + fVar14)) * uStack_d8._4_4_;
          fVar14 = (fVar11 * (float)uStack_c8 - fVar13 * uStack_c0._4_4_) * fVar15 +
                   (fVar16 + fVar11 * uStack_c8._4_4_) * uStack_d8._4_4_ +
                   (1.0 - (fVar13 * uStack_c8._4_4_ + fVar14)) * fVar12 + fStack_110;
          uStack_d8 = uVar8;
          if (lVar6 != 0) {
            uStack_e8 = CONCAT44(fVar10 + (fVar11 * uStack_c0._4_4_ + fVar13 * (float)uStack_c8) *
                                          fVar15 + (fVar11 * uStack_c8._4_4_ - fVar16) * fVar12 +
                                 uStack_118._4_4_,
                                 (1.0 - (fVar11 * (float)uStack_c0 + fVar13 * uStack_c8._4_4_)) *
                                 fVar15 + fVar9 +
                                 (fVar13 * uStack_c0._4_4_ + fVar11 * (float)uStack_c8) * fVar12 +
                                 (float)uStack_118);
            pcVar5 = DAT_182ec16a0;
            fStack_e0 = fVar14;
            if ((DAT_182ec16a0 == (code *)0x0) &&
               (pcVar5 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                              ), pcVar5 == (code *)0x0)) {
              uVar8 = FUN_1802ced60(
                                   "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar8,0);
            }
            DAT_182ec16a0 = pcVar5;
            (*DAT_182ec16a0)(lVar6,&uStack_e8);
            if ((*(longlong *)(param_1 + 0x88) != 0) &&
               (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x88) + 0x40), lVar6 != 0)) {
              if (*(char *)(lVar6 + 0x1f) != '\0') {
                lVar6 = *(longlong *)(param_1 + 0x88);
                uStack_d8 = *(undefined8 *)(param_1 + 0x2c);
                lVar2 = *(longlong *)(lVar6 + 0x40);
                fVar12 = *(float *)(lVar2 + 0x5c);
                fVar9 = (float)((ulonglong)uStack_d8 >> 0x20) * fVar12;
                fVar10 = (float)uStack_d8 * fVar12;
                fVar12 = *(float *)(param_1 + 0x34) * fVar12;
                if ((lVar6 == 0) || (lVar2 == 0)) goto code_r0x000180437fc7;
                if (*(char *)(lVar2 + 0x20) != '\0') {
                  uStack_d8 = *(undefined8 *)(param_1 + 0x38);
                  fVar12 = *(float *)(*(longlong *)(lVar6 + 0x40) + 0x5c);
                  fVar9 = (float)((ulonglong)uStack_d8 >> 0x20) * fVar12;
                  fVar10 = (float)uStack_d8 * fVar12;
                  fVar12 = *(float *)(param_1 + 0x40) * fVar12;
                }
                pcVar5 = DAT_182ec1080;
                if ((DAT_182ec1080 == (code *)0x0) &&
                   (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
                   pcVar5 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec1080 = pcVar5;
                lVar6 = (*DAT_182ec1080)(param_1);
                if ((*(longlong *)(param_1 + 0x88) == 0) ||
                   (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x88) + 0x10), lVar2 == 0))
                goto code_r0x000180437fc7;
                uStack_118 = 0;
                fStack_110 = 0.0;
                pcVar5 = DAT_182ec1698;
                if ((DAT_182ec1698 == (code *)0x0) &&
                   (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar5 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60(
                                       "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec1698 = pcVar5;
                (*DAT_182ec1698)(lVar2,&uStack_118);
                if ((*(longlong *)(param_1 + 0x88) == 0) ||
                   (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x88) + 0x10), lVar2 == 0))
                goto code_r0x000180437fc7;
                puVar7 = (undefined8 *)FUN_181f4c360(&uStack_d8,lVar2,0);
                uVar8 = *puVar7;
                uVar1 = *(undefined4 *)(puVar7 + 1);
                if (DAT_182eb547c == '\0') {
                  FUN_1802f2810(&DAT_182d522a8);
                  LOCK();
                  UNLOCK();
                  DAT_182eb547c = '\x01';
                }
                uStack_f8 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
                fStack_f0 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20);
                uStack_c8 = 0;
                uStack_c0 = 0;
                pcVar5 = DAT_182ec0ea8;
                uStack_108 = uVar8;
                uStack_100 = uVar1;
                if ((DAT_182ec0ea8 == (code *)0x0) &&
                   (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                                  ), pcVar5 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60(
                                       "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec0ea8 = pcVar5;
                (*DAT_182ec0ea8)(&uStack_108,&uStack_f8,&uStack_c8);
                uStack_b8 = uStack_c8;
                uStack_b0 = uStack_c0;
                uStack_f8 = CONCAT44(fVar9,fVar10);
                fStack_f0 = fVar12;
                puVar7 = (undefined8 *)FUN_181f31290(&uStack_d8,&uStack_b8,&uStack_f8,0);
                uStack_f8 = *puVar7;
                if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                uStack_f8 = CONCAT44((float)((ulonglong)uStack_f8 >> 0x20) + uStack_118._4_4_,
                                     (float)uStack_f8 + (float)uStack_118);
                pcVar5 = DAT_182ec16a0;
                fStack_f0 = *(float *)(puVar7 + 1) + fStack_110;
                if ((DAT_182ec16a0 == (code *)0x0) &&
                   (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar5 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60(
                                       "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec16a0 = pcVar5;
                (*DAT_182ec16a0)(lVar6,&uStack_f8);
              }
              if ((*(longlong *)(param_1 + 0x88) == 0) ||
                 (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x88) + 0x40), lVar6 == 0))
              goto code_r0x000180437fc7;
              if (*(int *)(lVar6 + 0x58) == 9) {
                fVar12 = *(float *)(lVar6 + 0x5c);
                uStack_d8 = *(undefined8 *)(param_1 + 0x44);
                fVar10 = (float)uStack_d8;
                uVar3 = (ulonglong)uStack_d8 >> 0x20;
                fVar9 = *(float *)(param_1 + 0x4c);
                pcVar5 = DAT_182ec1080;
                if ((DAT_182ec1080 == (code *)0x0) &&
                   (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
                   pcVar5 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec1080 = pcVar5;
                lVar6 = (*DAT_182ec1080)(param_1);
                if (((*(longlong *)(param_1 + 0x88) == 0) ||
                    (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x88) + 0xc0), lVar2 == 0)) ||
                   (lVar2 = *(longlong *)(lVar2 + 0x28), lVar2 == 0)) goto code_r0x000180437fc7;
                uStack_118 = 0;
                fStack_110 = 0.0;
                pcVar5 = DAT_182ec1698;
                if ((DAT_182ec1698 == (code *)0x0) &&
                   (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar5 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60(
                                       "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec1698 = pcVar5;
                (*DAT_182ec1698)(lVar2,&uStack_118);
                if ((*(longlong *)(param_1 + 0x88) == 0) ||
                   (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x88) + 0x10), lVar2 == 0))
                goto code_r0x000180437fc7;
                puVar7 = (undefined8 *)FUN_181f4c360(&uStack_c8,lVar2,0);
                uVar8 = *puVar7;
                fStack_d0 = *(float *)(puVar7 + 1);
                if (DAT_182eb547c == '\0') {
                  FUN_1802f2810(&DAT_182d522a8);
                  LOCK();
                  UNLOCK();
                  DAT_182eb547c = '\x01';
                }
                uStack_108 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
                uStack_100 = *(undefined4 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20);
                uStack_b8 = 0;
                uStack_b0 = 0;
                pcVar5 = DAT_182ec0ea8;
                uStack_d8 = uVar8;
                if ((DAT_182ec0ea8 == (code *)0x0) &&
                   (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                                  ), pcVar5 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60(
                                       "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec0ea8 = pcVar5;
                (*DAT_182ec0ea8)(&uStack_d8,&uStack_108,&uStack_b8);
                uStack_d8 = CONCAT44((float)uVar3 * fVar12,fVar10 * fVar12);
                fStack_d0 = fVar9 * fVar12;
                puVar7 = (undefined8 *)FUN_181f31290(&uStack_c8,&uStack_b8,&uStack_d8,0);
                uStack_d8 = *puVar7;
                if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                uStack_d8 = CONCAT44((float)((ulonglong)uStack_d8 >> 0x20) + uStack_118._4_4_,
                                     (float)uStack_d8 + (float)uStack_118);
                pcVar5 = DAT_182ec16a0;
                fStack_d0 = *(float *)(puVar7 + 1) + fStack_110;
                if ((DAT_182ec16a0 == (code *)0x0) &&
                   (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar5 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60(
                                       "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec16a0 = pcVar5;
                (*DAT_182ec16a0)(lVar6,&uStack_d8);
              }
              if (*(char *)(param_1 + 0x94) == '\0') {
                ExposureUnnoticed2_Object3D_NPC_Script_PlayerSearcher__ForForeignUpdate__060010d4
                          (param_1,0);
                ExposureUnnoticed2_Object3D_NPC_Script_PlayerSearcher__ForPlayerUpdate__060010d3
                          (param_1,0);
                if (*(char *)(param_1 + 0x68) != '\0') {
                  return;
                }
                if (*(char *)(param_1 + 0x95) != '\0') {
                  return;
                }
                *(undefined1 *)(param_1 + 0x94) = 1;
                fVar12 = (float)FUN_181dc1970(0);
                fVar9 = (float)FUN_181f373e0(0);
                lVar6 = *(longlong *)(param_1 + 0x50);
                *(float *)(param_1 + 0x90) = fVar9 * 0.1 + fVar12 + 0.5;
                if (lVar6 != 0) {
                  if (*(int *)(lVar6 + 0x18) == 0) {
code_r0x000180437fbb:
                    /* WARNING: Subroutine does not return */
                    FUN_18031dae0();
                  }
                  if ((*(longlong *)(lVar6 + 0x20) != 0) &&
                     (lVar6 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                                        (*(longlong *)(lVar6 + 0x20),0), lVar6 != 0)) {
                    cVar4 = FUN_181f3eb30(lVar6,0);
                    if (cVar4 == '\0') {
                      return;
                    }
                    lVar6 = *(longlong *)(param_1 + 0x50);
                    if (lVar6 != 0) {
                      if (*(int *)(lVar6 + 0x18) == 0) goto code_r0x000180437fbb;
                      if (*(longlong *)(lVar6 + 0x20) != 0) {
                        ExposureUnnoticed2_Object3D_NPC_Script_PlayerSearcherChild__DeActive__060010d9
                                  (*(longlong *)(lVar6 + 0x20),0);
                        lVar6 = *(longlong *)(param_1 + 0x50);
                        if (lVar6 != 0) {
                          if (*(uint *)(lVar6 + 0x18) < 2) goto code_r0x000180437fbb;
                          if (*(longlong *)(lVar6 + 0x28) != 0) {
                            ExposureUnnoticed2_Object3D_NPC_Script_PlayerSearcherChild__DeActive__060010d9
                                      (*(longlong *)(lVar6 + 0x28),0);
                            if (*(longlong *)(param_1 + 0x58) != 0) {
                              ExposureUnnoticed2_Object3D_NPC_Script_PlayerSearcherChild__DeActive__060010d9
                                        (*(longlong *)(param_1 + 0x58),0);
                              return;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else {
                fVar12 = *(float *)(param_1 + 0x90);
                pcVar5 = DAT_182ec14c0;
                if ((DAT_182ec14c0 == (code *)0x0) &&
                   (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_time()"),
                   pcVar5 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60("UnityEngine.Time::get_time()");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec14c0 = pcVar5;
                fVar9 = (float)(*DAT_182ec14c0)();
                if (fVar9 <= fVar12) {
                  return;
                }
                lVar6 = *(longlong *)(param_1 + 0x50);
                *(undefined1 *)(param_1 + 0x94) = 0;
                if (lVar6 != 0) {
                  if (*(int *)(lVar6 + 0x18) == 0) goto code_r0x000180437fbb;
                  if ((*(longlong *)(lVar6 + 0x20) != 0) &&
                     (lVar6 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                                        (*(longlong *)(lVar6 + 0x20),0), lVar6 != 0)) {
                    FUN_181f3ea80(lVar6,1,0);
                    lVar6 = *(longlong *)(param_1 + 0x50);
                    if (lVar6 != 0) {
                      if (*(uint *)(lVar6 + 0x18) < 2) goto code_r0x000180437fbb;
                      if ((*(longlong *)(lVar6 + 0x28) != 0) &&
                         (lVar6 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                                            (*(longlong *)(lVar6 + 0x28),0), lVar6 != 0)) {
                        FUN_181f3ea80(lVar6,1,0);
                        if ((*(longlong *)(param_1 + 0x58) != 0) &&
                           (lVar6 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                                              (*(longlong *)(param_1 + 0x58),0), lVar6 != 0)) {
                          FUN_181f3ea80(lVar6,1,0);
                          return;
                        }
                      }
                    }
                  }
                }
              }
              goto code_r0x000180437fc7;
            }
          }
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
      }
code_r0x000180437fc7:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
  pcVar5 = DAT_182ec1088;
  if ((DAT_182ec1088 == (code *)0x0) &&
     (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
     pcVar5 == (code *)0x0)) {
    uVar8 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar8,0);
  }
  DAT_182ec1088 = pcVar5;
  uVar8 = (*DAT_182ec1088)(param_1);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  FUN_181f43e80(uVar8,0);
  return;
}

