// Ghidra pseudocode; not original source or compilable C.
// ev_899bac32d10c8fb7b43ac57e7f51fa31a4c56c4e50ac152060462a1976ae5a83

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBaretaEscapeState__OnUpdate__06000c9a
               (longlong param_1)

{
  ulonglong uVar1;
  code *pcVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  undefined8 uStack_88;
  float fStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  float fStack_60;
  undefined4 uStack_5c;
  undefined8 uStack_58;
  undefined8 uStack_50;
  
  if (cRam0000000182eb83a4 == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb83a4 = '\x01';
  }
  if ((*(longlong *)(param_1 + 0x10) != 0) &&
     (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0xd8), lVar4 != 0)) {
    uStack_88 = 0;
    fStack_80 = 0.0;
    pcVar2 = DAT_182ebeec0;
    if ((DAT_182ebeec0 == (code *)0x0) &&
       (pcVar2 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.AI.NavMeshAgent::get_steeringTarget_Injected(UnityEngine.Vector3&)"
                                      ), pcVar2 == (code *)0x0)) {
      uVar6 = FUN_1802ced60(
                           "UnityEngine.AI.NavMeshAgent::get_steeringTarget_Injected(UnityEngine.Vector3&)"
                           );
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar6,0);
    }
    DAT_182ebeec0 = pcVar2;
    (*DAT_182ebeec0)(lVar4,&uStack_88);
    if ((*(longlong *)(param_1 + 0x10) != 0) &&
       (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18), lVar4 != 0)) {
      uStack_78 = 0;
      uStack_70 = uStack_70 & 0xffffffff00000000;
      pcVar2 = DAT_182ec1698;
      if ((DAT_182ec1698 == (code *)0x0) &&
         (pcVar2 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                        ), pcVar2 == (code *)0x0)) {
        uVar6 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar6,0);
      }
      DAT_182ec1698 = pcVar2;
      (*DAT_182ec1698)(lVar4,&uStack_78);
      fVar8 = (float)uStack_88 - (float)uStack_78;
      fVar9 = uStack_88._4_4_ - uStack_78._4_4_;
      fVar10 = fStack_80 - (float)uStack_70;
      if (DAT_182eb547c == '\0') {
        FUN_1802f2810(&DAT_182d522a8);
        LOCK();
        UNLOCK();
        DAT_182eb547c = '\x01';
      }
      uStack_88 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
      fStack_80 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20);
      uStack_68 = CONCAT44(fVar9,fVar8);
      uStack_58 = 0;
      uStack_50 = 0;
      pcVar2 = DAT_182ec0ea8;
      fStack_60 = fVar10;
      if ((DAT_182ec0ea8 == (code *)0x0) &&
         (pcVar2 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                        ), pcVar2 == (code *)0x0)) {
        uVar6 = FUN_1802ced60(
                             "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar6,0);
      }
      DAT_182ec0ea8 = pcVar2;
      (*DAT_182ec0ea8)(&uStack_68,&uStack_88,&uStack_58);
      if ((*(longlong *)(param_1 + 0x10) != 0) &&
         (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18), lVar4 != 0)) {
        uStack_78 = 0;
        uStack_70 = 0;
        pcVar2 = DAT_182ec16b8;
        if ((DAT_182ec16b8 == (code *)0x0) &&
           (pcVar2 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                          ), pcVar2 == (code *)0x0)) {
          uVar6 = FUN_1802ced60(
                               "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar6,0);
        }
        DAT_182ec16b8 = pcVar2;
        (*DAT_182ec16b8)(lVar4,&uStack_78);
        pcVar2 = DAT_182ec14d0;
        if ((DAT_182ec14d0 == (code *)0x0) &&
           (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"),
           pcVar2 == (code *)0x0)) {
          uVar6 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar6,0);
        }
        DAT_182ec14d0 = pcVar2;
        uStack_68 = uStack_78;
        fStack_60 = (float)uStack_70;
        uStack_5c = uStack_70._4_4_;
        fVar7 = (float)(*DAT_182ec14d0)();
        puVar3 = (undefined8 *)FUN_1804363f0(&uStack_78,&uStack_68,&uStack_58,fVar7 * 400.0);
        uStack_58 = *puVar3;
        uStack_50 = puVar3[1];
        pcVar2 = DAT_182ec16c0;
        if ((DAT_182ec16c0 == (code *)0x0) &&
           (pcVar2 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                          ), pcVar2 == (code *)0x0)) {
          uVar6 = FUN_1802ced60(
                               "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar6,0);
        }
        DAT_182ec16c0 = pcVar2;
        (*DAT_182ec16c0)(lVar4,&uStack_58);
        lVar4 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
        if (lVar4 != 0) {
          fVar7 = *(float *)(lVar4 + 0x60);
          if ((*(longlong *)(param_1 + 0x10) != 0) &&
             (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18), lVar4 != 0)) {
            puVar3 = (undefined8 *)FUN_181f4c360(&uStack_78,lVar4,0);
            uStack_68 = *puVar3;
            fStack_60 = *(float *)(puVar3 + 1);
            uStack_78 = CONCAT44(fVar9,fVar8);
            uStack_70 = CONCAT44(uStack_70._4_4_,fVar10);
            fVar8 = (float)FUN_1803fa290(&uStack_78,&uStack_68);
            if (70.0 < fVar8) {
              fVar7 = fVar7 * 0.3;
            }
            if ((*(longlong *)(param_1 + 0x10) != 0) &&
               (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18), lVar4 != 0)) {
              uStack_78 = 0;
              uStack_70 = uStack_70 & 0xffffffff00000000;
              pcVar2 = DAT_182ec1698;
              if ((DAT_182ec1698 == (code *)0x0) &&
                 (pcVar2 = (code *)FUN_1802cf0c0(
                                                "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                ), pcVar2 == (code *)0x0)) {
                uVar6 = FUN_1802ced60(
                                     "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                     );
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar6,0);
              }
              DAT_182ec1698 = pcVar2;
              (*DAT_182ec1698)(lVar4,&uStack_78);
              if ((*(longlong *)(param_1 + 0x10) != 0) &&
                 (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18), lVar5 != 0)) {
                puVar3 = (undefined8 *)FUN_181f4c360(&uStack_68,lVar5,0);
                uStack_88 = *puVar3;
                fVar9 = (float)uStack_88;
                uVar1 = (ulonglong)uStack_88 >> 0x20;
                fVar8 = *(float *)(puVar3 + 1);
                pcVar2 = DAT_182ec14d0;
                if ((DAT_182ec14d0 == (code *)0x0) &&
                   (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"),
                   pcVar2 == (code *)0x0)) {
                  uVar6 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar6,0);
                }
                DAT_182ec14d0 = pcVar2;
                fVar10 = (float)(*DAT_182ec14d0)();
                fStack_60 = fVar8 * fVar7 * fVar10 + (float)uStack_70;
                uStack_68 = CONCAT44((float)uVar1 * fVar7 * fVar10 + uStack_78._4_4_,
                                     fVar9 * fVar7 * fVar10 + (float)uStack_78);
                pcVar2 = DAT_182ec16a0;
                if ((DAT_182ec16a0 == (code *)0x0) &&
                   (pcVar2 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar2 == (code *)0x0)) {
                  uVar6 = FUN_1802ced60(
                                       "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar6,0);
                }
                DAT_182ec16a0 = pcVar2;
                (*DAT_182ec16a0)(lVar4,&uStack_68);
                if (*(longlong *)(param_1 + 0x10) != 0) {
                  lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0xd8);
                  if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                      (lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x40),
                      lVar5 != 0)) &&
                     (lVar5 = ExposureUnnoticed2_Scripts_InGame_StageController__GetEscapeTarget__0600165b
                                        (lVar5,0), lVar5 != 0)) {
                    uStack_78 = 0;
                    uStack_70 = uStack_70 & 0xffffffff00000000;
                    pcVar2 = DAT_182ec1698;
                    if ((DAT_182ec1698 == (code *)0x0) &&
                       (pcVar2 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar2 == (code *)0x0)) {
                      uVar6 = FUN_1802ced60(
                                           "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                           );
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar6,0);
                    }
                    DAT_182ec1698 = pcVar2;
                    (*DAT_182ec1698)(lVar5,&uStack_78);
                    if (lVar4 != 0) {
                      fStack_80 = (float)uStack_70;
                      uStack_88 = uStack_78;
                      pcVar2 = DAT_182ebeeb0;
                      if ((DAT_182ebeeb0 == (code *)0x0) &&
                         (pcVar2 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.AI.NavMeshAgent::SetDestination_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar2 == (code *)0x0)) {
                        uVar6 = FUN_1802ced60(
                                             "UnityEngine.AI.NavMeshAgent::SetDestination_Injected(UnityEngine.Vector3&)"
                                             );
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar6,0);
                      }
                      DAT_182ebeeb0 = pcVar2;
                      (*DAT_182ebeeb0)(lVar4,&uStack_88);
                      if (*(longlong *)(param_1 + 0x10) != 0) {
                        lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0xd8);
                        lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18);
                        if (lVar5 != 0) {
                          uStack_78 = 0;
                          uStack_70 = uStack_70 & 0xffffffff00000000;
                          pcVar2 = DAT_182ec1698;
                          if ((DAT_182ec1698 == (code *)0x0) &&
                             (pcVar2 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar2 == (code *)0x0)) {
                            uVar6 = FUN_1802ced60(
                                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                 );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar6,0);
                          }
                          DAT_182ec1698 = pcVar2;
                          (*DAT_182ec1698)(lVar5,&uStack_78);
                          if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
                            FUN_18031dad0();
                          }
                          fStack_60 = (float)uStack_70;
                          uStack_68 = uStack_78;
                          pcVar2 = DAT_182ebeeb8;
                          if ((DAT_182ebeeb8 == (code *)0x0) &&
                             (pcVar2 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.AI.NavMeshAgent::set_nextPosition_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar2 == (code *)0x0)) {
                            uVar6 = FUN_1802ced60(
                                                 "UnityEngine.AI.NavMeshAgent::set_nextPosition_Injected(UnityEngine.Vector3&)"
                                                 );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar6,0);
                          }
                          DAT_182ebeeb8 = pcVar2;
                          (*DAT_182ebeeb8)(lVar4,&uStack_68);
                          return;
                        }
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
            goto code_r0x000180631173;
          }
        }
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
    }
  }
code_r0x000180631173:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

