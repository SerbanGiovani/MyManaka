// Ghidra pseudocode; not original source or compilable C.
// ev_0f704b248a794c3492664478d3d3d481a5d6a77360358d95f0cd63f8eb9c739d

bool ExposureUnnoticed2_Scripts_Mission_MissionBase__get_IsOverDestroyTime__0600140e
               (longlong param_1)

{
  code *pcVar1;
  longlong lVar2;
  undefined8 uVar3;
  float extraout_XMM0_Da;
  
  if (cRam0000000182eb78f8 == '\0') {
    FUN_1802f2810(0x182d5e260);
    LOCK();
    UNLOCK();
    cRam0000000182eb78f8 = '\x01';
  }
  pcVar1 = DAT_182ec14c0;
  if ((DAT_182ec14c0 == (code *)0x0) &&
     (pcVar1 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_time()"), pcVar1 == (code *)0x0)) {
    uVar3 = FUN_1802ced60("UnityEngine.Time::get_time()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar3,0);
  }
  DAT_182ec14c0 = pcVar1;
  (*DAT_182ec14c0)();
  if (extraout_XMM0_Da - *(float *)(param_1 + 0x34) < 1.0) {
    return false;
  }
  lVar2 = **(longlong **)(lRam0000000182d5e260 + 0xb8);
  if (lVar2 != 0) {
    if (*(char *)(lVar2 + 0x10) != '\0') {
      lVar2 = ExposureUnnoticed2_Scripts_InGame_RandomMissionManager__get_CurrentMission__060015ea
                        (lVar2,0);
      return lVar2 != param_1;
    }
    return true;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

