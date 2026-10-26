// Ghidra pseudocode; not original source or compilable C.
// ev_d9cac3f54e3edee70a4a26302bd49ea7177ea36370295a5d09f2a2cae4c3b0a6

void ExposureUnnoticed2_Object3D_NPC_Script_NpcController__OnAnimatorMove__0600105c
               (longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined8 uStack_28;
  undefined4 uStack_20;
  undefined8 uStack_18;
  undefined4 uStack_10;
  
  if (*(longlong *)(param_1 + 0x48) != 0) {
    if (*(int *)(*(longlong *)(param_1 + 0x48) + 0x10) != 4) {
      return;
    }
    lVar1 = *(longlong *)(param_1 + 0x30);
    if (lVar1 != 0) {
      lVar2 = *(longlong *)(lVar1 + 0x90);
      lVar1 = *(longlong *)(lVar1 + 0x10);
      if (lVar2 != 0) {
        uStack_28 = 0;
        uStack_20 = 0;
        pcVar3 = pcRam0000000182ebf388;
        if ((pcRam0000000182ebf388 == (code *)0x0) &&
           (pcVar3 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Animator::get_rootPosition_Injected(UnityEngine.Vector3&)"
                                          ), pcVar3 == (code *)0x0)) {
          uVar4 = FUN_1802ced60(
                               "UnityEngine.Animator::get_rootPosition_Injected(UnityEngine.Vector3&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar4,0);
        }
        pcRam0000000182ebf388 = pcVar3;
        (*pcRam0000000182ebf388)(lVar2,&uStack_28);
        if (lVar1 != 0) {
          uStack_10 = uStack_20;
          uStack_18 = uStack_28;
          pcVar3 = DAT_182ec16a0;
          if ((DAT_182ec16a0 == (code *)0x0) &&
             (pcVar3 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar3 == (code *)0x0)) {
            uVar4 = FUN_1802ced60(
                                 "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar4,0);
          }
          DAT_182ec16a0 = pcVar3;
          (*DAT_182ec16a0)(lVar1,&uStack_18);
          if ((*(longlong *)(param_1 + 0x30) != 0) &&
             (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 200), lVar1 != 0)) {
            ExposureUnnoticed2_Object3D_NPC_Script_NpcCollisionCorrecter__CollisionCorrect__0600100b
                      (lVar1,0);
            return;
          }
        }
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

