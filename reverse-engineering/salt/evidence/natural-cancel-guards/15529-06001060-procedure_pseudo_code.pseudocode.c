// Ghidra pseudocode; not original source or compilable C.
// ev_d2d394db9a6a5114f7b4add3325501cf9a41fe225c5479d85b8fd9496ec2e495

void ExposureUnnoticed2_Object3D_NPC_Script_NpcController__FirePinponAction__06001060
               (longlong param_1,byte param_2,undefined4 param_3,undefined1 param_4)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  
  if (((*(longlong *)(param_1 + 0x30) != 0) &&
      (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xa0), lVar1 != 0)) &&
     (lVar1 = *(longlong *)(lVar1 + 0x20), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 0x1c) = 0;
    if ((*(longlong *)(param_1 + 0x30) != 0) &&
       (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xa0), lVar1 != 0)) {
      if (cRam0000000182eb773a == '\0') {
        FUN_1802f2810(&DAT_182d59ea8);
        LOCK();
        UNLOCK();
        cRam0000000182eb773a = '\x01';
      }
      lVar2 = *(longlong *)(lVar1 + 0x18);
      if (lVar2 != 0) {
        pcVar3 = DAT_182ebf2f0;
        if ((DAT_182ebf2f0 == (code *)0x0) &&
           (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Animator::set_speed(System.Single)"),
           pcVar3 == (code *)0x0)) {
          uVar4 = FUN_1802ced60("UnityEngine.Animator::set_speed(System.Single)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar4,0);
        }
        DAT_182ebf2f0 = pcVar3;
        (*DAT_182ebf2f0)(lVar2,param_3);
        lVar2 = *(longlong *)(lVar1 + 0x18);
        if (*(int *)(DAT_182d59ea8 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d59ea8);
        }
        if (lVar2 != 0) {
          FUN_181eea680(lVar2,*(undefined4 *)(*(longlong *)(DAT_182d59ea8 + 0xb8) + 0x58),param_4,0)
          ;
          lVar2 = *(longlong *)(lVar1 + 0x18);
          if (param_2 == 0) {
            if (*(int *)(DAT_182d59ea8 + 0xe0) == 0) {
              FUN_18035c820(DAT_182d59ea8);
            }
            uVar5 = *(undefined4 *)(*(longlong *)(DAT_182d59ea8 + 0xb8) + 0x54);
          }
          else {
            if (*(int *)(DAT_182d59ea8 + 0xe0) == 0) {
              FUN_18035c820(DAT_182d59ea8);
            }
            uVar5 = *(undefined4 *)(*(longlong *)(DAT_182d59ea8 + 0xb8) + 0x50);
          }
          if (lVar2 != 0) {
            pcVar3 = DAT_182ebf368;
            if ((DAT_182ebf368 == (code *)0x0) &&
               (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Animator::SetTriggerID(System.Int32)"),
               pcVar3 == (code *)0x0)) {
              uVar4 = FUN_1802ced60("UnityEngine.Animator::SetTriggerID(System.Int32)");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar4,0);
            }
            DAT_182ebf368 = pcVar3;
            (*DAT_182ebf368)(lVar2,uVar5);
            if ((*(longlong *)(lVar1 + 0x10) != 0) &&
               (lVar1 = *(longlong *)(*(longlong *)(lVar1 + 0x10) + 0x40), lVar1 != 0)) {
              *(byte *)(lVar1 + 0x85) = param_2 ^ 1;
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

