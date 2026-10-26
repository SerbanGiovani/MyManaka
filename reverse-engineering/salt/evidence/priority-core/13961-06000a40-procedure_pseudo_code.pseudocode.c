// Ghidra pseudocode; not original source or compilable C.
// ev_7c8082505f209aa047fd83e9fadfc8b44ed9d46878e347ef158c94723296f9d7

void ExposureUnnoticed2_Object3D_ScenePlops_WasherMachine_WasherMachineController__OnPlaySe__06000a40
               (longlong param_1,int param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  if (cRam0000000182eb8247 == '\0') {
    FUN_1802f2810(&DAT_182d58078);
    LOCK();
    UNLOCK();
    cRam0000000182eb8247 = '\x01';
  }
  if (param_2 == 0x5a) {
    if (*(char *)(param_1 + 0x49) != '\0') {
      if (DAT_182eb5498 == '\0') {
        FUN_1802f2810(&DAT_182d5a900);
        LOCK();
        UNLOCK();
        DAT_182eb5498 = '\x01';
      }
      if (**(longlong **)(DAT_182d5a900 + 0xb8) == 0) goto code_r0x0001805f6efd;
      ExposureUnnoticed2_Scripts_InGame_SceneProcessManager_LaundryManager__SetRpBonus__060016ba
                (**(longlong **)(DAT_182d5a900 + 0xb8),param_1,*(undefined4 *)(param_1 + 0x7c),0);
    }
    *(undefined4 *)(param_1 + 0x4c) = 1;
    *(undefined4 *)(param_1 + 0x50) = 1;
    *(float *)(param_1 + 0x78) = (float)(*(int *)(param_1 + 0x7c) * 0x3c);
    lVar1 = **(longlong **)(DAT_182d58078 + 0xb8);
    if (lVar1 != 0) {
      if (cRam0000000182eb78e4 == '\0') {
        FUN_1802f2810(&DAT_182d5bd18);
        LOCK();
        UNLOCK();
        cRam0000000182eb78e4 = '\x01';
      }
      uVar4 = *(undefined8 *)(lVar1 + 0x300);
      uVar2 = (undefined4)*(undefined8 *)(lVar1 + 0x308);
      lVar1 = *(longlong *)(param_1 + 0x38);
      if (lVar1 != 0) {
        pcVar3 = pcRam0000000182ebf6d8;
        if ((pcRam0000000182ebf6d8 == (code *)0x0) &&
           (pcVar3 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.AudioSource::set_clip(UnityEngine.AudioClip)"
                                          ), pcVar3 == (code *)0x0)) {
          uVar4 = FUN_1802ced60("UnityEngine.AudioSource::set_clip(UnityEngine.AudioClip)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar4,0);
        }
        pcRam0000000182ebf6d8 = pcVar3;
        (*pcRam0000000182ebf6d8)(lVar1,uVar4);
        if (*(longlong *)(param_1 + 0x38) != 0) {
          FUN_181ef43f0(*(longlong *)(param_1 + 0x38),uVar2,0);
          *(undefined4 *)(param_1 + 0x60) = uVar2;
          lVar1 = *(longlong *)(param_1 + 0x38);
          if (lVar1 != 0) {
            pcVar3 = DAT_182ebf698;
            if ((DAT_182ebf698 == (code *)0x0) &&
               (pcVar3 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.AudioSource::PlayHelper(UnityEngine.AudioSource,System.UInt64)"
                                              ), pcVar3 == (code *)0x0)) {
              uVar4 = FUN_1802ced60(
                                   "UnityEngine.AudioSource::PlayHelper(UnityEngine.AudioSource,System.UInt64)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar4,0);
            }
            DAT_182ebf698 = pcVar3;
                    /* WARNING: Could not recover jumptable at 0x0001805f6efa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*DAT_182ebf698)(lVar1,0);
            return;
          }
        }
      }
    }
  }
  else if (**(longlong **)(DAT_182d58078 + 0xb8) != 0) {
    ExposureUnnoticed2_Scripts_Sound_InGameSoundManager__PlayOneShotAudioData__060013ed
              (**(longlong **)(DAT_182d58078 + 0xb8),*(undefined8 *)(param_1 + 0x38),param_2,
               0xbf800000,0);
    return;
  }
code_r0x0001805f6efd:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

