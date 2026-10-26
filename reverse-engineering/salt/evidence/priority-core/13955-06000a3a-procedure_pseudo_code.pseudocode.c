// Ghidra pseudocode; not original source or compilable C.
// ev_a1e7a0c7db5913df316eaebd2fa4520e9a88706954dc2c13b33da1c8e9465a9c

void ExposureUnnoticed2_Object3D_ScenePlops_WasherMachine_WasherMachineController__OnChangeTime__06000a3a
               (longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  if (cRam0000000182eb8242 == '\0') {
    FUN_1802f2810(&DAT_182d6c188);
    LOCK();
    UNLOCK();
    cRam0000000182eb8242 = '\x01';
  }
  if ((*(char *)(param_1 + 0x49) != '\0') && (*(int *)(param_1 + 0x4c) == 1)) {
    lVar2 = *(longlong *)(param_1 + 0x58);
    *(undefined4 *)(param_1 + 0x4c) = 2;
    if (*(int *)(DAT_182d6c188 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d6c188);
    }
    if (lVar2 == 0) goto code_r0x0001805f5e41;
    FUN_181eea680(lVar2,**(undefined4 **)(DAT_182d6c188 + 0xb8),0,0);
  }
  if (*(char *)(param_1 + 0x48) != '\0') {
    lVar2 = *(longlong *)(param_1 + 0x58);
    *(undefined4 *)(param_1 + 0x4c) = 0;
    if (*(int *)(DAT_182d6c188 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d6c188);
    }
    if (lVar2 == 0) goto code_r0x0001805f5e41;
    uVar1 = **(undefined4 **)(DAT_182d6c188 + 0xb8);
    pcVar3 = DAT_182ebf348;
    if ((DAT_182ebf348 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Animator::SetBoolID(System.Int32,System.Boolean)"
                                      ), pcVar3 == (code *)0x0)) {
      uVar4 = FUN_1802ced60("UnityEngine.Animator::SetBoolID(System.Int32,System.Boolean)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    DAT_182ebf348 = pcVar3;
    (*DAT_182ebf348)(lVar2,uVar1,0);
  }
  lVar2 = *(longlong *)(param_1 + 0x30);
  *(undefined1 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  if ((lVar2 != 0) && (*(longlong *)(lVar2 + 0x40) != 0)) {
    ExposureUnnoticed2_Scripts_Base_SmoothFloat__SetSecond__0600175e
              (*(longlong *)(lVar2 + 0x40),0x3f800000,0);
    if (*(longlong *)(lVar2 + 0x40) != 0) {
      *(undefined4 *)(*(longlong *)(lVar2 + 0x40) + 0x1c) = 0;
      lVar2 = *(longlong *)(param_1 + 0x38);
      if (lVar2 != 0) {
        pcVar3 = pcRam0000000182ebf6a8;
        if ((pcRam0000000182ebf6a8 == (code *)0x0) &&
           (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.AudioSource::Stop(System.Boolean)"),
           pcVar3 == (code *)0x0)) {
          uVar4 = FUN_1802ced60("UnityEngine.AudioSource::Stop(System.Boolean)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar4,0);
        }
        pcRam0000000182ebf6a8 = pcVar3;
        (*pcRam0000000182ebf6a8)(lVar2,1);
        *(undefined4 *)(param_1 + 0x78) = 0;
        return;
      }
    }
  }
code_r0x0001805f5e41:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

