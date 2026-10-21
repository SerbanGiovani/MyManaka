// Ghidra pseudocode; not original source or compilable C.
// ev_868c1da48fd8d97540f66ce4dc4b1bb494bbe5a69924cc186ce299d4d99c8b70

void ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimationEventReceiver__OnAnimBaretaSound__06000fad
               (longlong param_1)

{
  longlong lVar1;
  char cVar2;
  undefined8 uVar3;
  longlong lVar4;
  
  if (cRam0000000182eb771b == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d59f88);
    LOCK();
    UNLOCK();
    cRam0000000182eb771b = '\x01';
  }
  uVar3 = FUN_1802c43a0(DAT_182d58368);
  FUN_1814df680(uVar3,param_1,uRam0000000182d59f88,0);
  ExposureUnnoticed2_Scripts_Base_Scheduler__DelayScaledTime__0600174d(uVar3,0x3f19999a,0);
  if ((*(longlong *)(param_1 + 0x20) == 0) ||
     (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0xd8), lVar4 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (DAT_182eb7783 == '\0') {
    FUN_1802f2810(&DAT_182d58078);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182eb7783 = '\x01';
  }
  if ((*(longlong *)(lVar4 + 0x10) != 0) &&
     (lVar1 = *(longlong *)(*(longlong *)(lVar4 + 0x10) + 0x50), lVar1 != 0)) {
    lVar1 = *(longlong *)(lVar1 + 0x20);
    if (**(longlong **)(DAT_182d58078 + 0xb8) == 0) goto LAB_18043476b;
    cVar2 = ExposureUnnoticed2_Scripts_Sound_InGameSoundManager__IsFootSe__060013eb
                      (**(longlong **)(DAT_182d58078 + 0xb8),10,0);
    if (cVar2 == '\0') {
      if (**(longlong **)(DAT_182d58078 + 0xb8) == 0) goto LAB_18043476b;
      cVar2 = ExposureUnnoticed2_Scripts_Sound_InGameSoundManager__IsGroupSe__060013ea
                        (**(longlong **)(DAT_182d58078 + 0xb8),10,0);
      if (cVar2 == '\0') {
        if (**(longlong **)(DAT_182d58078 + 0xb8) == 0) goto LAB_18043476b;
        lVar4 = ExposureUnnoticed2_Scripts_Sound_InGameSoundManager__GetSound__060013ee
                          (**(longlong **)(DAT_182d58078 + 0xb8),10,0);
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (DAT_182ec12f4 == '\0') {
          FUN_1802f2810(&DAT_182d53aa8);
          LOCK();
          UNLOCK();
          DAT_182ec12f4 = '\x01';
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
            if (lVar1 == 0) goto LAB_18043476b;
            goto LAB_1804346c4;
          }
        }
        if (**(longlong **)(DAT_182d58078 + 0xb8) != 0) {
          ExposureUnnoticed2_Scripts_Sound_InGameSoundManager__PlayOneShotAudioData__060013ed
                    (**(longlong **)(DAT_182d58078 + 0xb8),lVar1,10,0xbf800000,0);
          return;
        }
        goto LAB_18043476b;
      }
    }
    if ((((*(longlong *)(lVar4 + 0x10) != 0) &&
         (lVar4 = *(longlong *)(*(longlong *)(lVar4 + 0x10) + 0x38), lVar4 != 0)) &&
        (**(longlong **)(DAT_182d58078 + 0xb8) != 0)) &&
       (lVar4 = ExposureUnnoticed2_Scripts_Sound_InGameSoundManager__GetSound__060013ef
                          (**(longlong **)(DAT_182d58078 + 0xb8),10,*(undefined8 *)(lVar4 + 0x18),0)
       , lVar1 != 0)) {
LAB_1804346c4:
      FUN_181ef4680(lVar1,lVar4,0x3f800000,0);
      return;
    }
  }
LAB_18043476b:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

