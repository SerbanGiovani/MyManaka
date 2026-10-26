// Ghidra pseudocode; not original source or compilable C.
// ev_1c2101668bd088b8a571d78f1c3abe4c6b37bfe8b003d8674fb7c65b10fbd581

void ExposureUnnoticed2_Object3D_NPC_Script_NpcLocomotion__SimpleUpdateFromOtherState__0600107a
               (longlong param_1,undefined8 *param_2,float param_3)

{
  float fVar1;
  undefined4 *puVar2;
  longlong lVar3;
  ulonglong uVar4;
  code *pcVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  uint uVar10;
  bool bVar11;
  float fVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  undefined8 local_78;
  float local_70;
  undefined8 local_68;
  float local_60;
  undefined8 local_58;
  float fStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  if (DAT_182eb7767 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    DAT_182eb7767 = '\x01';
  }
  if (((*(longlong *)(param_1 + 0x10) != 0) &&
      (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38), lVar7 != 0)) &&
     (lVar7 = *(longlong *)(lVar7 + 0x10), lVar7 != 0)) {
    local_48 = 0;
    uStack_40 = 0;
    pcVar5 = DAT_182ec16b8;
    if ((DAT_182ec16b8 == (code *)0x0) &&
       (pcVar5 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                      ), pcVar5 == (code *)0x0)) {
      uVar8 = FUN_1802ced60("UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)")
      ;
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar8,0);
    }
    DAT_182ec16b8 = pcVar5;
    (*DAT_182ec16b8)(lVar7,&local_48);
    local_38 = *(undefined8 *)(param_1 + 0x38);
    uStack_30 = *(undefined8 *)(param_1 + 0x40);
    pcVar5 = DAT_182ec14d0;
    if ((DAT_182ec14d0 == (code *)0x0) &&
       (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"), pcVar5 == (code *)0x0))
    {
      uVar8 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar8,0);
    }
    DAT_182ec14d0 = pcVar5;
    local_58 = local_48;
    fStack_50 = (float)uStack_40;
    uStack_4c = uStack_40._4_4_;
    fVar12 = (float)(*DAT_182ec14d0)();
    puVar6 = (undefined8 *)FUN_1804363f0(&local_48,&local_58,&local_38,fVar12 * 90.0);
    local_38 = *puVar6;
    uStack_30 = puVar6[1];
    pcVar5 = DAT_182ec16c0;
    if ((DAT_182ec16c0 == (code *)0x0) &&
       (pcVar5 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                      ), pcVar5 == (code *)0x0)) {
      uVar8 = FUN_1802ced60("UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)")
      ;
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar8,0);
    }
    DAT_182ec16c0 = pcVar5;
    (*DAT_182ec16c0)(lVar7,&local_38);
    if ((*(longlong *)(param_1 + 0x10) == 0) ||
       (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38), lVar7 == 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    uVar8 = *(undefined8 *)(lVar7 + 0x18);
    if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    local_68 = *param_2;
    local_60 = *(float *)(param_2 + 1);
    fVar12 = (float)ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DistSqrt__0600172a
                              (uVar8,&local_68,0);
    if (fVar12 < param_3) {
      return;
    }
    if ((*(longlong *)(param_1 + 0x10) != 0) &&
       (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x28), lVar7 != 0)) {
      local_78 = 0;
      local_70 = 0.0;
      pcVar5 = DAT_182ebeec0;
      if ((DAT_182ebeec0 == (code *)0x0) &&
         (pcVar5 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.AI.NavMeshAgent::get_steeringTarget_Injected(UnityEngine.Vector3&)"
                                        ), pcVar5 == (code *)0x0)) {
        uVar8 = FUN_1802ced60(
                             "UnityEngine.AI.NavMeshAgent::get_steeringTarget_Injected(UnityEngine.Vector3&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar8,0);
      }
      DAT_182ebeec0 = pcVar5;
      (*DAT_182ebeec0)(lVar7,&local_78);
      if (((*(longlong *)(param_1 + 0x10) != 0) &&
          (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38), lVar7 != 0)) &&
         (lVar7 = *(longlong *)(lVar7 + 0x10), lVar7 != 0)) {
        local_68 = 0;
        local_60 = 0.0;
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
        (*DAT_182ec1698)(lVar7,&local_68);
        fVar17 = local_78._4_4_ - local_68._4_4_;
        fVar12 = local_70 - local_60;
        fVar18 = (float)local_78 - (float)local_68;
        uStack_40 = CONCAT44(uStack_40._4_4_,fVar12);
        local_48 = CONCAT44(fVar17,fVar18);
        if (0.001 < fVar17 * fVar17 + fVar18 * fVar18 + fVar12 * fVar12) {
          if (DAT_182eb547c == '\0') {
            FUN_1802f2810(&DAT_182d522a8);
            LOCK();
            UNLOCK();
            DAT_182eb547c = '\x01';
          }
          local_58 = CONCAT44(fVar17,fVar18);
          local_78 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
          local_70 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20);
          local_38 = 0;
          uStack_30 = 0;
          pcVar5 = DAT_182ec0ea8;
          fStack_50 = fVar12;
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
          (*DAT_182ec0ea8)(&local_58,&local_78,&local_38);
          uVar13 = (undefined4)local_38;
          uVar14 = local_38._4_4_;
          uVar15 = (undefined4)uStack_30;
          uVar16 = uStack_30._4_4_;
        }
        else {
          if (DAT_182eb547f == '\0') {
            FUN_1802f2810(&DAT_182d52290);
            LOCK();
            UNLOCK();
            DAT_182eb547f = '\x01';
          }
          puVar2 = *(undefined4 **)(DAT_182d52290 + 0xb8);
          uVar13 = *puVar2;
          uVar14 = puVar2[1];
          uVar15 = puVar2[2];
          uVar16 = puVar2[3];
        }
        *(undefined4 *)(param_1 + 0x38) = uVar13;
        *(undefined4 *)(param_1 + 0x3c) = uVar14;
        *(undefined4 *)(param_1 + 0x40) = uVar15;
        *(undefined4 *)(param_1 + 0x44) = uVar16;
        lVar7 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
        if (lVar7 != 0) {
          fVar19 = *(float *)(lVar7 + 0x58) * 0.9;
          if (((*(longlong *)(param_1 + 0x10) != 0) &&
              (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38), lVar7 != 0)) &&
             (lVar7 = *(longlong *)(lVar7 + 0x10), lVar7 != 0)) {
            puVar6 = (undefined8 *)FUN_181f4c360(&local_68,lVar7,0);
            local_58 = *puVar6;
            fStack_50 = *(float *)(puVar6 + 1);
            local_68 = CONCAT44(fVar17,fVar18);
            local_60 = fVar12;
            fVar12 = (float)FUN_1803fa290(&local_68,&local_58);
            fVar17 = (float)FUN_1803d4630(&local_48);
            if (fVar17 < 4.0) {
              if (30.0 < fVar12) {
                fVar19 = fVar19 * 0.3;
              }
              else if (60.0 < fVar12) {
                fVar19 = fVar19 * 0.2;
              }
              else if (90.0 <= fVar12) {
                fVar19 = fVar19 * 0.1;
              }
            }
            if (((*(longlong *)(param_1 + 0x10) != 0) &&
                (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38), lVar7 != 0)) &&
               (lVar7 = *(longlong *)(lVar7 + 0x10), lVar7 != 0)) {
              puVar6 = (undefined8 *)FUN_181f4c360(&local_58,lVar7,0);
              local_48 = *puVar6;
              fVar17 = (float)local_48;
              uVar9 = (ulonglong)local_48 >> 0x20;
              fVar12 = *(float *)(puVar6 + 1);
              if ((*(longlong *)(param_1 + 0x10) != 0) &&
                 (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40), lVar7 != 0)) {
                fVar18 = *(float *)(lVar7 + 0x2c);
                lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0xa0);
                if ((lVar7 != 0) && (lVar7 = *(longlong *)(lVar7 + 0x20), lVar7 != 0)) {
                  fVar1 = *(float *)(lVar7 + 0x10);
                  local_48 = *param_2;
                  *(ulonglong *)(param_1 + 0x1c) =
                       CONCAT44(fVar18 * (float)uVar9 * fVar19 * fVar1,
                                fVar18 * fVar17 * fVar19 * fVar1);
                  *(float *)(param_1 + 0x24) = fVar18 * fVar12 * fVar19 * fVar1;
                  fVar17 = (float)*(undefined8 *)(param_1 + 0x2c) - (float)local_48;
                  fVar18 = (float)((ulonglong)*(undefined8 *)(param_1 + 0x2c) >> 0x20) -
                           (float)((ulonglong)local_48 >> 0x20);
                  fVar12 = *(float *)(param_1 + 0x34) - *(float *)(param_2 + 1);
                  if (9.9999994e-11 <= fVar18 * fVar18 + fVar17 * fVar17 + fVar12 * fVar12) {
                    if ((*(longlong *)(param_1 + 0x10) == 0) ||
                       (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x28), lVar7 == 0)) {
                    /* WARNING: Subroutine does not return */
                      FUN_18031dad0();
                    }
                    local_48 = *param_2;
                    uStack_40 = CONCAT44(uStack_40._4_4_,*(undefined4 *)(param_2 + 1));
                    pcVar5 = DAT_182ebeeb0;
                    if ((DAT_182ebeeb0 == (code *)0x0) &&
                       (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.AI.NavMeshAgent::SetDestination_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar5 == (code *)0x0)) {
                      uVar8 = FUN_1802ced60(
                                           "UnityEngine.AI.NavMeshAgent::SetDestination_Injected(UnityEngine.Vector3&)"
                                           );
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar8,0);
                    }
                    DAT_182ebeeb0 = pcVar5;
                    (*DAT_182ebeeb0)(lVar7,&local_48);
                    uVar13 = *(undefined4 *)(param_2 + 1);
                    *(undefined8 *)(param_1 + 0x2c) = *param_2;
                    *(undefined4 *)(param_1 + 0x34) = uVar13;
                  }
                  lVar7 = *(longlong *)(param_1 + 0x10);
                  if (lVar7 != 0) {
                    lVar3 = *(longlong *)(lVar7 + 0x28);
                    if ((*(longlong *)(lVar7 + 0x38) != 0) &&
                       (lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x38) + 0x10), lVar7 != 0)) {
                      local_68 = 0;
                      local_60 = 0.0;
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
                      (*DAT_182ec1698)(lVar7,&local_68);
                      if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
                        FUN_18031dad0();
                      }
                      uStack_40 = CONCAT44(uStack_40._4_4_,local_60);
                      local_48 = local_68;
                      pcVar5 = DAT_182ebeeb8;
                      if ((DAT_182ebeeb8 == (code *)0x0) &&
                         (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.AI.NavMeshAgent::set_nextPosition_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar5 == (code *)0x0)) {
                        uVar8 = FUN_1802ced60(
                                             "UnityEngine.AI.NavMeshAgent::set_nextPosition_Injected(UnityEngine.Vector3&)"
                                             );
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar8,0);
                      }
                      DAT_182ebeeb8 = pcVar5;
                      (*DAT_182ebeeb8)(lVar3,&local_48);
                      pcVar5 = DAT_182ec14e0;
                      if ((DAT_182ec14e0 == (code *)0x0) &&
                         (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_unscaledTime()"),
                         pcVar5 == (code *)0x0)) {
                        uVar8 = FUN_1802ced60("UnityEngine.Time::get_unscaledTime()");
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar8,0);
                      }
                      DAT_182ec14e0 = pcVar5;
                      fVar12 = (float)(*DAT_182ec14e0)();
                      if (fVar12 - *(float *)(param_1 + 0x18) <= 0.5) {
                        return;
                      }
                      if (*(longlong *)(param_1 + 0x10) != 0) {
                        lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40);
                        if (DAT_182eb548c == '\0') {
                          FUN_1802f2810(&DAT_182d57a70);
                          LOCK();
                          UNLOCK();
                          DAT_182eb548c = '\x01';
                        }
                        if (((*(longlong *)(param_1 + 0x10) != 0) &&
                            (**(longlong **)(DAT_182d57a70 + 0xb8) != 0)) &&
                           (uVar8 = ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__GetNearOtherNpc__060010a3
                                              (**(longlong **)(DAT_182d57a70 + 0xb8),
                                               *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x38)
                                               ,0), lVar7 != 0)) {
                          bVar11 = DAT_182eb5d50 != 0;
                          *(undefined8 *)(lVar7 + 0x38) = uVar8;
                          if (bVar11) {
                            uVar10 = (uint)(lVar7 + 0x38U >> 0xc);
                            uVar9 = (ulonglong)((uVar10 & 0x1fffff) >> 6);
                            do {
                              uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
                              LOCK();
                              bVar11 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
                              if (bVar11) {
                                *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) =
                                     uVar4 | 1L << (uVar10 & 0x3f);
                              }
                              UNLOCK();
                            } while (!bVar11);
                          }
                          pcVar5 = DAT_182ec14e0;
                          if ((DAT_182ec14e0 == (code *)0x0) &&
                             (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_unscaledTime()")
                             , pcVar5 == (code *)0x0)) {
                            uVar8 = FUN_1802ced60("UnityEngine.Time::get_unscaledTime()");
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar8,0);
                          }
                          DAT_182ec14e0 = pcVar5;
                          fVar12 = (float)(*DAT_182ec14e0)();
                          pcVar5 = DAT_182ec0fd8;
                          if ((DAT_182ec0fd8 == (code *)0x0) &&
                             (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Random::get_value()"),
                             pcVar5 == (code *)0x0)) {
                            uVar8 = FUN_1802ced60("UnityEngine.Random::get_value()");
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar8,0);
                          }
                          DAT_182ec0fd8 = pcVar5;
                          fVar17 = (float)(*DAT_182ec0fd8)();
                          *(float *)(param_1 + 0x18) = fVar17 * 0.1 + fVar12;
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
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

