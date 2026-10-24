// Ghidra pseudocode; not original source or compilable C.
// ev_93d0ea2bb2454073e8d823d968d07c059238dbc44bc9eac5fbb88256a98956de

undefined8
ExposureUnnoticed2_Object3D_Player_Scripts_PlayerSoundManager__PlayFootSeIfInCondition__06000e22
          (longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  code *pcVar4;
  undefined8 uVar5;
  float extraout_XMM0_Da;
  undefined4 uVar6;
  
  if (cRam0000000182eb8441 == '\0') {
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58080);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58078);
    LOCK();
    UNLOCK();
    cRam0000000182eb8441 = '\x01';
  }
  if (**(longlong **)(DAT_182d58078 + 0xb8) != 0) {
    cVar2 = ExposureUnnoticed2_Scripts_Sound_InGameSoundManager__IsFootSe__060013eb
                      (**(longlong **)(DAT_182d58078 + 0xb8),param_2,0);
    if (cVar2 == '\0') {
      return 0;
    }
    pcVar4 = DAT_182ec14c0;
    if ((DAT_182ec14c0 == (code *)0x0) &&
       (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_time()"), pcVar4 == (code *)0x0)) {
      uVar5 = FUN_1802ced60("UnityEngine.Time::get_time()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
    DAT_182ec14c0 = pcVar4;
    (*DAT_182ec14c0)();
    if (extraout_XMM0_Da - *(float *)(param_1 + 0x20) < 0.2) {
      return 1;
    }
    pcVar4 = DAT_182ec14c0;
    if ((DAT_182ec14c0 == (code *)0x0) &&
       (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_time()"), pcVar4 == (code *)0x0)) {
      uVar5 = FUN_1802ced60("UnityEngine.Time::get_time()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
    DAT_182ec14c0 = pcVar4;
    uVar6 = (*DAT_182ec14c0)();
    *(undefined4 *)(param_1 + 0x20) = uVar6;
    iVar3 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerSoundManager__TransTerrainSeIfNeed__06000e23
                      (param_1,param_2,0);
    if (*(int *)(DAT_182d58080 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar1 = *(longlong *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x90);
    if (lVar1 != 0) {
      *(int *)(lVar1 + 0x10) = iVar3;
      uVar5 = *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x90);
      if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      ExposureUnnoticed2_Scripts_Base_EventManager__Broadcast__06001716(uVar5,0);
      uVar6 = *(undefined4 *)(param_1 + 0x48);
      if (iVar3 == 0x3e) {
        uVar6 = 0x3e99999a;
      }
      else if (iVar3 == 0x3f) {
        uVar6 = 0x3f000000;
      }
      else if ((iVar3 == 0x1f) || (iVar3 == 0x5f)) {
        uVar6 = 0x3f19999a;
      }
      if (*(longlong *)(param_1 + 0x10) != 0) {
        FUN_181ef43f0(*(longlong *)(param_1 + 0x10),uVar6,0);
        lVar1 = *(longlong *)(param_1 + 0x10);
        if ((**(longlong **)(DAT_182d58078 + 0xb8) != 0) &&
           (uVar5 = ExposureUnnoticed2_Scripts_Sound_InGameSoundManager__GetSound__060013ef
                              (**(longlong **)(DAT_182d58078 + 0xb8),iVar3,
                               *(undefined8 *)(param_1 + 0x18),0), lVar1 != 0)) {
          FUN_181ef4680(lVar1,uVar5,0x3f800000,0);
          return 1;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

