// Ghidra pseudocode; not original source or compilable C.
// ev_751d0a49e9ae2ccac0a686ec5f1a0349c9282f1c447dbe5aefe284a65304a8a2

void ExposureUnnoticed2_Object3D_ScenePlops_CommonDoor_CommonDoorController___Awake_b__20_1__06000b31
               (longlong param_1)

{
  undefined8 uVar1;
  
  if (cRam0000000182eb82ca == '\0') {
    FUN_1802f2810(&DAT_182d58078);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6bd78);
    LOCK();
    UNLOCK();
    cRam0000000182eb82ca = '\x01';
  }
  *(undefined1 *)(param_1 + 0x58) = 1;
  uVar1 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d6bd78,0);
  ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14(uVar1,1,0);
  if (**(longlong **)(DAT_182d58078 + 0xb8) != 0) {
    ExposureUnnoticed2_Scripts_Sound_InGameSoundManager__PlayOneShotAudioData__060013ed
              (**(longlong **)(DAT_182d58078 + 0xb8),*(undefined8 *)(param_1 + 0x40),0x52,0xbf800000
               ,0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

