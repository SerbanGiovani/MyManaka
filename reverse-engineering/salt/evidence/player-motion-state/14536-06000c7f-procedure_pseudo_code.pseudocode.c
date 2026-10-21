// Ghidra pseudocode; not original source or compilable C.
// ev_2ec527e91f511d33e0dad0d7a6e4b825b5a32800b2c63e86957b7c1c9a22e7db

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__TransAction__06000c7f
               (longlong param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 uVar5;
  
  if (cRam0000000182eb8391 == '\0') {
    FUN_1802f2810(0x182d6f340);
    LOCK();
    UNLOCK();
    cRam0000000182eb8391 = '\x01';
  }
  lVar3 = *(longlong *)(param_1 + 0x30);
  if (*(int *)(lRam0000000182d6f340 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d6f340);
  }
  if (lVar3 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0xc0);
    uVar2 = *(undefined4 *)(*(longlong *)(lRam0000000182d6f340 + 0xb8) + 0x68);
    pcVar4 = pcRam0000000182ebf358;
    if ((pcRam0000000182ebf358 == (code *)0x0) &&
       (pcVar4 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Animator::SetIntegerID(System.Int32,System.Int32)"
                                      ), pcVar4 == (code *)0x0)) {
      uVar5 = FUN_1802ced60("UnityEngine.Animator::SetIntegerID(System.Int32,System.Int32)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
    pcRam0000000182ebf358 = pcVar4;
    (*pcRam0000000182ebf358)(lVar3,uVar2,uVar1);
    lVar3 = *(longlong *)(param_1 + 0x30);
    if (lVar3 != 0) {
      uVar1 = *(undefined4 *)(*(longlong *)(lRam0000000182d6f340 + 0xb8) + 0x1c);
      pcVar4 = pcRam0000000182ebf358;
      if ((pcRam0000000182ebf358 == (code *)0x0) &&
         (pcVar4 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Animator::SetIntegerID(System.Int32,System.Int32)"
                                        ), pcVar4 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.Animator::SetIntegerID(System.Int32,System.Int32)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      pcRam0000000182ebf358 = pcVar4;
      (*pcRam0000000182ebf358)(lVar3,uVar1,param_2);
      lVar3 = *(longlong *)(param_1 + 0x30);
      if (lVar3 != 0) {
        uVar1 = *(undefined4 *)(*(longlong *)(lRam0000000182d6f340 + 0xb8) + 0x20);
        pcVar4 = DAT_182ebf368;
        if ((DAT_182ebf368 == (code *)0x0) &&
           (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Animator::SetTriggerID(System.Int32)"),
           pcVar4 == (code *)0x0)) {
          uVar5 = FUN_1802ced60("UnityEngine.Animator::SetTriggerID(System.Int32)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        DAT_182ebf368 = pcVar4;
        (*DAT_182ebf368)(lVar3,uVar1);
        *(undefined4 *)(param_1 + 0xc0) = param_2;
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

