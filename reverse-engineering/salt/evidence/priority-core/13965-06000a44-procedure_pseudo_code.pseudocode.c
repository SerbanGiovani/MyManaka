// Ghidra pseudocode; not original source or compilable C.
// ev_71bb1125ca1dc02be5248080fac023c3ead9464b4fc2fe7ac754b9dc09f58b53

void ExposureUnnoticed2_Object3D_ScenePlops_WasherMachine_WasherMachineController__OnTimeStopEvent__06000a44
               (longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  
  if (cRam0000000182eb8248 == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb8248 = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar1 != 0)) {
    if (*(char *)(lVar1 + 0x14) == '\0') {
      if (*(longlong *)(param_1 + 0x58) != 0) {
        FUN_181eeaba0(*(longlong *)(param_1 + 0x58),*(undefined4 *)(param_1 + 100),0);
        lVar1 = *(longlong *)(param_1 + 0x38);
        if (lVar1 != 0) {
          pcVar2 = pcRam0000000182ebf6f8;
          if ((pcRam0000000182ebf6f8 == (code *)0x0) &&
             (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.AudioSource::UnPause()"),
             pcVar2 == (code *)0x0)) {
            uVar3 = FUN_1802ced60("UnityEngine.AudioSource::UnPause()");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar3,0);
          }
          pcRam0000000182ebf6f8 = pcVar2;
                    /* WARNING: Could not recover jumptable at 0x0001805f7028. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*pcRam0000000182ebf6f8)(lVar1);
          return;
        }
      }
    }
    else {
      lVar1 = *(longlong *)(param_1 + 0x38);
      if (lVar1 != 0) {
        pcVar2 = pcRam0000000182ebf6f0;
        if ((pcRam0000000182ebf6f0 == (code *)0x0) &&
           (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.AudioSource::Pause()"),
           pcVar2 == (code *)0x0)) {
          uVar3 = FUN_1802ced60("UnityEngine.AudioSource::Pause()");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar3,0);
        }
        pcRam0000000182ebf6f0 = pcVar2;
        (*pcRam0000000182ebf6f0)(lVar1);
        lVar1 = *(longlong *)(param_1 + 0x58);
        if (lVar1 != 0) {
          pcVar2 = pcRam0000000182ebf2e8;
          if ((pcRam0000000182ebf2e8 == (code *)0x0) &&
             (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Animator::get_speed()"),
             pcVar2 == (code *)0x0)) {
            uVar3 = FUN_1802ced60("UnityEngine.Animator::get_speed()");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar3,0);
          }
          pcRam0000000182ebf2e8 = pcVar2;
          uVar4 = (*pcRam0000000182ebf2e8)(lVar1);
          *(undefined4 *)(param_1 + 100) = uVar4;
          lVar1 = *(longlong *)(param_1 + 0x58);
          if (lVar1 != 0) {
            pcVar2 = DAT_182ebf2f0;
            if ((DAT_182ebf2f0 == (code *)0x0) &&
               (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Animator::set_speed(System.Single)"),
               pcVar2 == (code *)0x0)) {
              uVar3 = FUN_1802ced60("UnityEngine.Animator::set_speed(System.Single)");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar3,0);
            }
            DAT_182ebf2f0 = pcVar2;
                    /* WARNING: Could not recover jumptable at 0x0001805f70dd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*DAT_182ebf2f0)(lVar1,0);
            return;
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

