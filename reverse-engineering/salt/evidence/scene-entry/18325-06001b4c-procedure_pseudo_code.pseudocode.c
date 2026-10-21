// Ghidra pseudocode; not original source or compilable C.
// ev_b93a573ee5dfdb61b622e9e618979e667a7b088fe765b491ff625d1e26e3d154

void ExposureUnnoticed2_ObjectUI_FadeOutPanel_FadePanelView__Open__06001b4c
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  if (cRam0000000182eb7d15 == '\0') {
    FUN_1802f2810(&DAT_182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d645f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f428);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7d15 = '\x01';
  }
  if (**(longlong **)(DAT_182d58238 + 0xb8) != 0) {
    uVar4 = *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0xf8);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar1 = FUN_1809f0e30(uVar4,uRam0000000182d5f428);
    if ((lVar1 != 0) && (lVar2 = FUN_1809a0c10(lVar1,uRam0000000182d645f8), lVar2 != 0)) {
      ExposureUnnoticed2_ObjectUI_FadeOutPanel_FadePanelView__Initialize__06001b48
                (lVar2,param_1,param_2,param_3,param_4,param_5,0);
      pcVar3 = DAT_182ec12d8;
      if ((DAT_182ec12d8 == (code *)0x0) &&
         (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Object::DontDestroyOnLoad(UnityEngine.Object)"
                                        ), pcVar3 == (code *)0x0)) {
        uVar4 = FUN_1802ced60("UnityEngine.Object::DontDestroyOnLoad(UnityEngine.Object)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar4,0);
      }
      DAT_182ec12d8 = pcVar3;
                    /* WARNING: Could not recover jumptable at 0x000180513a08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*DAT_182ec12d8)(lVar1);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

