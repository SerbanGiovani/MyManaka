// Ghidra pseudocode; not original source or compilable C.
// ev_17f7e11eb328c622dc91abd772c4f48a05c6c689cf6aa84728d8ebdc07efe41c

void ExposureUnnoticed2_ObjectUI_FadeOutPanel_FadePanelView___Update_b__14_0__06001b4f
               (longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  if (cRam0000000182eb7d17 == '\0') {
    FUN_1802f2810(0x182d5aa40);
    LOCK();
    UNLOCK();
    cRam0000000182eb7d17 = '\x01';
  }
  lVar2 = *(longlong *)(param_1 + 0x50);
  if (*(int *)(lRam0000000182d5aa40 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5aa40);
  }
  if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uVar1 = *(undefined4 *)(*(longlong *)(lRam0000000182d5aa40 + 0xb8) + 8);
  pcVar3 = pcRam0000000182ebf368;
  if ((pcRam0000000182ebf368 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Animator::SetTriggerID(System.Int32)"),
     pcVar3 == (code *)0x0)) {
    uVar4 = FUN_1802ced60("UnityEngine.Animator::SetTriggerID(System.Int32)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar4,0);
  }
  pcRam0000000182ebf368 = pcVar3;
  (*pcRam0000000182ebf368)(lVar2,uVar1);
  lVar2 = *(longlong *)(param_1 + 0x30);
  if (lVar2 != 0) {
    (**(code **)(lVar2 + 0x18))(*(undefined8 *)(lVar2 + 0x40),*(undefined8 *)(lVar2 + 0x28));
  }
  return;
}

