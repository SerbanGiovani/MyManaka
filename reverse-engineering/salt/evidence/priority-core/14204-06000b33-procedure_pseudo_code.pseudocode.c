// Ghidra pseudocode; not original source or compilable C.
// ev_7d18eef7af80387641d8fdc1278311615f3705ac9302980a0e6dcee5c71956dc

void ExposureUnnoticed2_Object3D_ScenePlops_CommonDoor_CommonDoorController___OpenClose_b__25_1__06000b33
               (longlong param_1)

{
  longlong lVar1;
  
  if (cRam0000000182eb82cb == '\0') {
    FUN_1802f2810(&DAT_182d58078);
    LOCK();
    UNLOCK();
    cRam0000000182eb82cb = '\x01';
  }
  if (**(longlong **)(DAT_182d58078 + 0xb8) != 0) {
    lVar1 = 0x48;
    if (*(char *)(param_1 + 0x59) == '\0') {
      lVar1 = 0x4c;
    }
    ExposureUnnoticed2_Scripts_Sound_InGameSoundManager__PlayOneShotAudioData__060013ed
              (**(longlong **)(DAT_182d58078 + 0xb8),*(undefined8 *)(param_1 + 0x40),
               *(undefined4 *)(lVar1 + param_1),0xbf800000,0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

