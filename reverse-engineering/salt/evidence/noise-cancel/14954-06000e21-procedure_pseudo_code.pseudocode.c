// Ghidra pseudocode; not original source or compilable C.
// ev_94d7de5709979c2e3ae1aef795929c84b90bd316d3a216c927244ad519e459f2

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerSoundManager__PlaySe__06000e21
               (longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  char cVar3;
  longlong lVar4;
  
  if (cRam0000000182eb8440 == '\0') {
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58080);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58078);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb8440 = '\x01';
  }
  cVar3 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerSoundManager__PlayFootSeIfInCondition__06000e22
                    (param_1,param_2,0);
  if (cVar3 != '\0') {
    return;
  }
  if (*(int *)(DAT_182d58080 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d58080);
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x90);
  if (lVar1 == 0) goto code_r0x00018065e454;
  *(undefined4 *)(lVar1 + 0x10) = param_2;
  uVar2 = *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x90);
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  ExposureUnnoticed2_Scripts_Base_EventManager__Broadcast__06001716(uVar2,0);
  if (**(longlong **)(DAT_182d58078 + 0xb8) == 0) goto code_r0x00018065e454;
  cVar3 = ExposureUnnoticed2_Scripts_Sound_InGameSoundManager__IsGroupSe__060013ea
                    (**(longlong **)(DAT_182d58078 + 0xb8),param_2,0);
  if (cVar3 == '\0') {
    if (**(longlong **)(DAT_182d58078 + 0xb8) == 0) goto code_r0x00018065e454;
    lVar4 = ExposureUnnoticed2_Scripts_Sound_InGameSoundManager__GetSound__060013ee
                      (**(longlong **)(DAT_182d58078 + 0xb8),param_2,0);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182ec12f3 == '\0') {
      FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      DAT_182ec12f3 = '\x01';
    }
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182ec129b == '\0') {
      FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      DAT_182ec129b = '\x01';
    }
    if (lVar4 != 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(longlong *)(lVar4 + 0x10) != 0) {
        if (*(longlong *)(param_1 + 0x10) == 0) goto code_r0x00018065e454;
        FUN_181ef43f0(*(longlong *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x48),0);
        lVar1 = *(longlong *)(param_1 + 0x10);
        goto joined_r0x00018065e38b;
      }
    }
    if (**(longlong **)(DAT_182d58078 + 0xb8) != 0) {
      ExposureUnnoticed2_Scripts_Sound_InGameSoundManager__PlayOneShotAudioData__060013ed
                (**(longlong **)(DAT_182d58078 + 0xb8),*(undefined8 *)(param_1 + 0x28),param_2,
                 0xbf800000,0);
      return;
    }
  }
  else {
    if (*(longlong *)(param_1 + 0x10) == 0) goto code_r0x00018065e454;
    FUN_181ef43f0(*(longlong *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x48),0);
    lVar1 = *(longlong *)(param_1 + 0x10);
    if (**(longlong **)(DAT_182d58078 + 0xb8) == 0) goto code_r0x00018065e454;
    lVar4 = ExposureUnnoticed2_Scripts_Sound_InGameSoundManager__GetSound__060013ef
                      (**(longlong **)(DAT_182d58078 + 0xb8),param_2,*(undefined8 *)(param_1 + 0x18)
                       ,0);
joined_r0x00018065e38b:
    if (lVar1 != 0) {
      FUN_181ef4680(lVar1,lVar4,0x3f800000,0);
      return;
    }
  }
code_r0x00018065e454:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

