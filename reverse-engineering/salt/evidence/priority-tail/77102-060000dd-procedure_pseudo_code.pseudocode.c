// Ghidra pseudocode; not original source or compilable C.
// ev_e44c2dc8ac7c8758f2690f608bfa88c50b89edd783ab6e0b7d13c7c6e78c76af

void UnityEngine_PhysicsScene__SphereCast__060000dd
               (undefined4 *param_1,undefined8 *param_2,undefined4 param_3,undefined8 *param_4,
               undefined8 *param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined8 uVar3;
  float fVar4;
  undefined4 auStackX_18 [2];
  undefined8 uStack_38;
  float fStack_30;
  undefined8 uStack_28;
  undefined4 uStack_20;
  
  uVar1 = *param_1;
  uStack_38 = *param_4;
  fStack_30 = *(float *)(param_4 + 1);
  fVar4 = (float)FUN_1803d4630(&uStack_38);
  *param_5 = 0;
  param_5[1] = 0;
  param_5[2] = 0;
  param_5[3] = 0;
  param_5[4] = 0;
  *(undefined4 *)(param_5 + 5) = 0;
  if (1.4013e-45 < fVar4) {
    uStack_20 = *(undefined4 *)(param_2 + 1);
    uStack_28 = *param_2;
    fStack_30 = *(float *)(param_4 + 1) / fVar4;
    uStack_38 = CONCAT44((float)((ulonglong)*param_4 >> 0x20) / fVar4,(float)*param_4 / fVar4);
    pcVar2 = pcRam0000000182ec3ac8;
    auStackX_18[0] = uVar1;
    if ((pcRam0000000182ec3ac8 == (code *)0x0) &&
       (pcVar2 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.PhysicsScene::Query_SphereCast_Injected(UnityEngine.PhysicsScene&,UnityEngine.Vector3&,System.Single,UnityEngine.Vector3&,System.Single,UnityEngine.RaycastHit&,System.Int32,UnityEngine.QueryTriggerInteraction)"
                                      ), pcVar2 == (code *)0x0)) {
      uVar3 = FUN_1802ced60(
                           "UnityEngine.PhysicsScene::Query_SphereCast_Injected(UnityEngine.PhysicsScene&,UnityEngine.Vector3&,System.Single,UnityEngine.Vector3&,System.Single,UnityEngine.RaycastHit&,System.Int32,UnityEngine.QueryTriggerInteraction)"
                           );
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar3,0);
    }
    pcRam0000000182ec3ac8 = pcVar2;
    (*pcRam0000000182ec3ac8)
              (auStackX_18,&uStack_28,param_3,&uStack_38,param_6,param_5,param_7,param_8);
  }
  return;
}

