// Ghidra pseudocode; not original source or compilable C.
// ev_0cd591d675a7c1575025a6d76df0b5ec7b82ddf183de6ea695fb88907e76d7e2

void ExposureUnnoticed2_Object3D_NPC_Script_NpcTurnAroundState__OnEnter__060010fc(longlong param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uStack_18;
  undefined4 uStack_10;
  
  lVar3 = *(longlong *)(param_1 + 0x10);
  if (((lVar3 != 0) && (*(longlong *)(lVar3 + 0x40) != 0)) &&
     (lVar3 = *(longlong *)(lVar3 + 0x20), lVar3 != 0)) {
    if (DAT_182eb5480 == '\0') {
      FUN_1802f2810(&DAT_182d522a8);
      LOCK();
      UNLOCK();
      DAT_182eb5480 = '\x01';
    }
    uVar1 = *(undefined4 *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
    *(undefined8 *)(lVar3 + 0x1c) = **(undefined8 **)(DAT_182d522a8 + 0xb8);
    *(undefined4 *)(lVar3 + 0x24) = uVar1;
    if ((*(longlong *)(param_1 + 0x10) != 0) &&
       (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0xa0), lVar3 != 0)) {
      ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimationManager__SetOverrideIdle__06000fc9
                (lVar3,1,0);
      if ((*(longlong *)(param_1 + 0x10) != 0) &&
         ((lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0xa0), lVar3 != 0 &&
          (lVar3 = *(longlong *)(lVar3 + 0x20), lVar3 != 0)))) {
        *(undefined4 *)(lVar3 + 0x1c) = 0;
        if ((*(longlong *)(param_1 + 0x10) != 0) &&
           (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x20), lVar3 != 0)) {
          ExposureUnnoticed2_Object3D_NPC_Script_NpcLocomotion__SetActiveNavAgent__0600107d
                    (lVar3,0,0);
          if ((*(longlong *)(param_1 + 0x10) != 0) &&
             (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x70), lVar3 != 0)) {
            pcVar2 = DAT_182ec1080;
            if ((DAT_182ec1080 == (code *)0x0) &&
               (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
               pcVar2 == (code *)0x0)) {
              uVar4 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar4,0);
            }
            DAT_182ec1080 = pcVar2;
            lVar3 = (*DAT_182ec1080)(lVar3);
            if (lVar3 != 0) {
              uStack_18 = 0;
              uStack_10 = 0;
              pcVar2 = DAT_182ec1698;
              if ((DAT_182ec1698 == (code *)0x0) &&
                 (pcVar2 = (code *)FUN_1802cf0c0(
                                                "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                ), pcVar2 == (code *)0x0)) {
                uVar4 = FUN_1802ced60(
                                     "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                     );
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar4,0);
              }
              DAT_182ec1698 = pcVar2;
              (*DAT_182ec1698)(lVar3,&uStack_18);
              *(undefined8 *)(param_1 + 0x18) = uStack_18;
              *(undefined4 *)(param_1 + 0x20) = uStack_10;
              return;
            }
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

