// Ghidra pseudocode; not original source or compilable C.
// ev_c9040c1926cbf1ce9de860e04842b5a0a1aa0ef31d90d1ca58099c436b2b97c9

void ExposureUnnoticed2_Object3D_NPC_Script_NpcController__Warp__06001062
               (longlong param_1,undefined8 *param_2,undefined4 *param_3)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined8 local_38;
  undefined4 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if ((*(longlong *)(param_1 + 0x30) != 0) &&
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x10), lVar1 != 0)) {
    local_30 = *(undefined4 *)(param_2 + 1);
    local_38 = *param_2;
    pcVar2 = DAT_182ec16a0;
    if ((DAT_182ec16a0 == (code *)0x0) &&
       (pcVar2 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar2 == (code *)0x0)) {
      uVar3 = FUN_1802ced60("UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar3,0);
    }
    DAT_182ec16a0 = pcVar2;
    (*DAT_182ec16a0)(lVar1,&local_38);
    if ((*(longlong *)(param_1 + 0x30) != 0) &&
       (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x10), lVar1 != 0)) {
      local_18 = *param_3;
      uStack_14 = param_3[1];
      uStack_10 = param_3[2];
      uStack_c = param_3[3];
      pcVar2 = DAT_182ec16c0;
      if ((DAT_182ec16c0 == (code *)0x0) &&
         (pcVar2 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                        ), pcVar2 == (code *)0x0)) {
        uVar3 = FUN_1802ced60(
                             "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar3,0);
      }
      DAT_182ec16c0 = pcVar2;
      (*DAT_182ec16c0)(lVar1,&local_18);
      if ((*(longlong *)(param_1 + 0x30) != 0) &&
         (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x28), lVar1 != 0)) {
        local_20 = *(undefined4 *)(param_2 + 1);
        local_28 = *param_2;
        pcVar2 = DAT_182ebeec8;
        if ((DAT_182ebeec8 == (code *)0x0) &&
           (pcVar2 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.AI.NavMeshAgent::Warp_Injected(UnityEngine.Vector3&)"
                                          ), pcVar2 == (code *)0x0)) {
          uVar3 = FUN_1802ced60("UnityEngine.AI.NavMeshAgent::Warp_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar3,0);
        }
        DAT_182ebeec8 = pcVar2;
        (*DAT_182ebeec8)(lVar1,&local_28);
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

