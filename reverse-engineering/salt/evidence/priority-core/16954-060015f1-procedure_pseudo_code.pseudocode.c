// Ghidra pseudocode; not original source or compilable C.
// ev_95f4b12e036b067bd81ae9f707b54bdcf0e9ded0fed6220d4e803673be918784

void ExposureUnnoticed2_Scripts_InGame_RandomMissionManager__OnUpdate__060015f1(longlong param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  if (cRam0000000182eb79f6 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5e240);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e228);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58380);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60310);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60298);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60290);
    LOCK();
    UNLOCK();
    cRam0000000182eb79f6 = '\x01';
  }
  if (*(char *)(param_1 + 0x10) == '\0') {
    return;
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar5 != 0)) {
    if (*(char *)(lVar5 + 0x11) != '\0') {
      return;
    }
    lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar5 != 0) {
      if (*(int *)(lVar5 + 0x10) == 0) {
        return;
      }
      if (*(char *)(*(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30) + 0x13) != '\0') {
        return;
      }
      if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d58380);
      }
      if (**(longlong **)(DAT_182d58380 + 0xb8) != 0) {
        if (*(char *)(**(longlong **)(DAT_182d58380 + 0xb8) + 0x20) != '\0') {
          return;
        }
        cVar2 = FUN_180436670();
        if (cVar2 != '\0') {
          return;
        }
        lVar5 = ExposureUnnoticed2_Scripts_InGame_RandomMissionManager__get_CurrentMission__060015ea
                          (param_1,0);
        if (lVar5 != 0) {
          lVar5 = ExposureUnnoticed2_Scripts_InGame_RandomMissionManager__get_CurrentMission__060015ea
                            (param_1,0);
          if (lVar5 == 0) goto DAT_18049b53a;
          if (*(char *)(lVar5 + 0x3d) != '\0') {
            iVar3 = *(int *)(param_1 + 0x20) + 1;
            *(int *)(param_1 + 0x20) = iVar3;
            if (*(longlong *)(param_1 + 0x18) == 0) goto DAT_18049b53a;
            if (*(int *)(*(longlong *)(param_1 + 0x18) + 0x18) <= iVar3) {
              lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
              if (lVar5 == 0) goto DAT_18049b53a;
              lVar5 = *(longlong *)(lVar5 + 0xe8);
              uVar1 = *(undefined4 *)(param_1 + 0x30);
              if (lVar5 == 0) goto DAT_18049b53a;
              iVar4 = FUN_180e71cd0(lVar5,uVar1,DAT_182d5e240);
              iVar3 = *(int *)(param_1 + 0x34);
              if (*(int *)(param_1 + 0x34) < iVar4) {
                iVar3 = iVar4;
              }
              uVar6 = *(undefined8 *)
                       (*(longlong *)(*(longlong *)(lRam0000000182d5e228 + 0x20) + 0xc0) + 0x100);
              FUN_180e72490(lVar5,uVar1,iVar3,CONCAT71((int7)((ulonglong)uVar6 >> 8),1),uVar6);
              uVar6 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                (uRam0000000182d60290,0);
              ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
                        (uVar6,3,0);
              if (**(longlong **)(DAT_182d5aa70 + 0xb8) == 0) goto DAT_18049b53a;
              ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
                        (**(longlong **)(DAT_182d5aa70 + 0xb8),0x17,0xbf800000,0,0);
              uVar6 = FUN_1802c43a0(DAT_182d58368);
              FUN_1814df680(uVar6,param_1,uRam0000000182d60298,0);
              ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b(uVar6,1,0);
            }
          }
        }
        if ((*(longlong *)(param_1 + 0x18) != 0) && (*(longlong *)(param_1 + 0x28) != 0)) {
          *(float *)(*(longlong *)(param_1 + 0x28) + 0x14) =
               (float)*(int *)(param_1 + 0x20) /
               (float)*(int *)(*(longlong *)(param_1 + 0x18) + 0x18);
          return;
        }
      }
    }
  }
DAT_18049b53a:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

