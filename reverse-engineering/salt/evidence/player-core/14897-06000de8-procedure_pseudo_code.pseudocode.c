// Ghidra pseudocode; not original source or compilable C.
// ev_437755c9cdcdd30d10aee62a34092a14014655e98bc4c23fc8c0ae87dc29c998

undefined8 *
ExposureUnnoticed2_Object3D_Player_Scripts_PlayerLocomotion__CalcAutoChaseDirect__06000de8
          (undefined8 *param_1,longlong param_2,ulonglong *param_3)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  ulonglong uStack_58;
  float fStack_50;
  ulonglong uStack_48;
  float fStack_40;
  
  if (cRam0000000182eb841f == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    cRam0000000182eb841f = '\x01';
  }
  if ((*(longlong *)(param_2 + 0x78) != 0) &&
     (lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x78) + 0xd8), lVar1 != 0)) {
    fStack_40 = *(float *)(param_3 + 1);
    uStack_48 = *param_3;
    pcVar3 = DAT_182ebeeb0;
    if ((DAT_182ebeeb0 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.AI.NavMeshAgent::SetDestination_Injected(UnityEngine.Vector3&)"
                                      ), pcVar3 == (code *)0x0)) {
      uVar4 = FUN_1802ced60(
                           "UnityEngine.AI.NavMeshAgent::SetDestination_Injected(UnityEngine.Vector3&)"
                           );
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    DAT_182ebeeb0 = pcVar3;
    (*DAT_182ebeeb0)(lVar1,&uStack_48);
    if ((*(longlong *)(param_2 + 0x78) != 0) &&
       (lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x78) + 0xd8), lVar1 != 0)) {
      uStack_58 = 0;
      fStack_50 = 0.0;
      pcVar3 = DAT_182ebeec0;
      if ((DAT_182ebeec0 == (code *)0x0) &&
         (pcVar3 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.AI.NavMeshAgent::get_steeringTarget_Injected(UnityEngine.Vector3&)"
                                        ), pcVar3 == (code *)0x0)) {
        uVar4 = FUN_1802ced60(
                             "UnityEngine.AI.NavMeshAgent::get_steeringTarget_Injected(UnityEngine.Vector3&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar4,0);
      }
      DAT_182ebeec0 = pcVar3;
      (*DAT_182ebeec0)(lVar1,&uStack_58);
      if ((*(longlong *)(param_2 + 0x78) != 0) &&
         (lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x78) + 0x18), lVar1 != 0)) {
        uStack_48 = 0;
        fStack_40 = 0.0;
        pcVar3 = DAT_182ec1698;
        if ((DAT_182ec1698 == (code *)0x0) &&
           (pcVar3 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                          ), pcVar3 == (code *)0x0)) {
          uVar4 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar4,0);
        }
        DAT_182ec1698 = pcVar3;
        (*DAT_182ec1698)(lVar1,&uStack_48);
        fVar6 = (float)uStack_58 - (float)uStack_48;
        fVar7 = fStack_50 - fStack_40;
        if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar1 = *(longlong *)(param_2 + 0x78);
        if (lVar1 != 0) {
          lVar2 = *(longlong *)(lVar1 + 0x18);
          lVar1 = *(longlong *)(lVar1 + 0xd8);
          if (lVar2 != 0) {
            uStack_58 = 0;
            fStack_50 = 0.0;
            pcVar3 = DAT_182ec1698;
            if ((DAT_182ec1698 == (code *)0x0) &&
               (pcVar3 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                              ), pcVar3 == (code *)0x0)) {
              uVar4 = FUN_1802ced60(
                                   "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar4,0);
            }
            DAT_182ec1698 = pcVar3;
            (*DAT_182ec1698)(lVar2,&uStack_58);
            if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            fStack_40 = fStack_50;
            uStack_48 = uStack_58;
            pcVar3 = DAT_182ebeeb8;
            if ((DAT_182ebeeb8 == (code *)0x0) &&
               (pcVar3 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.AI.NavMeshAgent::set_nextPosition_Injected(UnityEngine.Vector3&)"
                                              ), pcVar3 == (code *)0x0)) {
              uVar4 = FUN_1802ced60(
                                   "UnityEngine.AI.NavMeshAgent::set_nextPosition_Injected(UnityEngine.Vector3&)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar4,0);
            }
            DAT_182ebeeb8 = pcVar3;
            (*DAT_182ebeeb8)(lVar1,&uStack_48);
            uStack_48 = (ulonglong)(uint)fVar6;
            fStack_40 = fVar7;
            fVar5 = (float)FUN_1803d4d00(&uStack_48);
            if (1e-05 < fVar5) {
              fVar7 = fVar7 / fVar5;
              uVar4 = CONCAT44(0.0 / fVar5,fVar6 / fVar5);
            }
            else {
              if (DAT_182eb5480 == '\0') {
                FUN_1802f2810(&DAT_182d522a8);
                LOCK();
                UNLOCK();
                DAT_182eb5480 = '\x01';
              }
              uVar4 = **(undefined8 **)(DAT_182d522a8 + 0xb8);
              fVar7 = *(float *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
            }
            *param_1 = uVar4;
            *(float *)(param_1 + 1) = fVar7;
            return param_1;
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

