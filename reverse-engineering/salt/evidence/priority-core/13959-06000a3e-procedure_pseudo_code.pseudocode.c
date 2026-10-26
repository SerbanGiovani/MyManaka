// Ghidra pseudocode; not original source or compilable C.
// ev_85cb6fc3242260767991b7e3a7a2662365021b8f7ae62d887664c7d0ef400b21

void ExposureUnnoticed2_Object3D_ScenePlops_WasherMachine_WasherMachineController__TakeClothes__06000a3e
               (longlong param_1,char param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 uVar5;
  
  if (cRam0000000182eb8245 == '\0') {
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6c188);
    LOCK();
    UNLOCK();
    cRam0000000182eb8245 = '\x01';
  }
  lVar2 = *(longlong *)(param_1 + 0x58);
  if (*(int *)(DAT_182d6c188 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d6c188);
  }
  if (lVar2 != 0) {
    uVar1 = *(undefined4 *)(*(longlong *)(DAT_182d6c188 + 0xb8) + 4);
    pcVar4 = DAT_182ebf368;
    if ((DAT_182ebf368 == (code *)0x0) &&
       (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Animator::SetTriggerID(System.Int32)"),
       pcVar4 == (code *)0x0)) {
      uVar5 = FUN_1802ced60("UnityEngine.Animator::SetTriggerID(System.Int32)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
    DAT_182ebf368 = pcVar4;
    (*DAT_182ebf368)(lVar2,uVar1);
    if (param_2 != '\0') {
      return;
    }
    lVar2 = *(longlong *)(param_1 + 0x20);
    lVar3 = **(longlong **)(DAT_182d58230 + 0xb8);
    if (lVar2 != 0) {
      pcVar4 = DAT_182ec1080;
      if ((DAT_182ec1080 == (code *)0x0) &&
         (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
         pcVar4 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec1080 = pcVar4;
      uVar5 = (*DAT_182ec1080)(lVar2);
      if (lVar3 != 0) {
        ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__SmoothMoveTo__06000d95
                  (lVar3,uVar5,0);
        if (((**(longlong **)(DAT_182d58230 + 0xb8) != 0) &&
            (lVar2 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar2 != 0)) &&
           (lVar2 = *(longlong *)(lVar2 + 0x60), lVar2 != 0)) {
          *(undefined4 *)(lVar2 + 0x234) = 0x271a;
          return;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

