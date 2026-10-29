// Ghidra pseudocode; not original source or compilable C.
// ev_00be6ad13efbe301d20329a7a75c9d0ed2ad10e6f1fb29a28d92c4ef64c4d184

bool ExposureUnnoticed2_Scripts_Mission_MissionBase__get_IsCreatePanel__0600140f(longlong param_1)

{
  char cVar1;
  code *pcVar2;
  longlong lVar3;
  undefined8 uVar4;
  float fVar5;
  
  if (cRam0000000182eb78f9 == '\0') {
    FUN_1802f2810(0x182d5e260);
    LOCK();
    UNLOCK();
    cRam0000000182eb78f9 = '\x01';
  }
  pcVar2 = DAT_182ec14c0;
  if ((DAT_182ec14c0 == (code *)0x0) &&
     (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_time()"), pcVar2 == (code *)0x0)) {
    uVar4 = FUN_1802ced60("UnityEngine.Time::get_time()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar4,0);
  }
  DAT_182ec14c0 = pcVar2;
  fVar5 = (float)(*DAT_182ec14c0)();
  if (((0.3 <= fVar5 - *(float *)(param_1 + 0x38)) &&
      (cVar1 = ExposureUnnoticed2_Scripts_Mission_MissionBase__get_IsOverDestroyTime__0600140e
                         (param_1,0), cVar1 == '\0')) &&
     (cVar1 = ExposureUnnoticed2_Scripts_Mission_MissionBase__IsVisiblePanel__06001421(param_1,0),
     cVar1 != '\0')) {
    return true;
  }
  lVar3 = **(longlong **)(lRam0000000182d5e260 + 0xb8);
  if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (*(char *)(lVar3 + 0x10) != '\0') {
    lVar3 = ExposureUnnoticed2_Scripts_InGame_RandomMissionManager__get_CurrentMission__060015ea
                      (lVar3,0);
    return lVar3 == param_1;
  }
  return false;
}

