// Ghidra pseudocode; not original source or compilable C.
// ev_813b3285759c7f133cd5fc117b5828b581adfb95c07f4d16bca357868aaec98e

void ExposureUnnoticed2_ObjectUI_FadeOutPanel_FadePanelView__Update__06001b49(longlong param_1)

{
  char cVar1;
  undefined8 uVar2;
  
  if (cRam0000000182eb7d13 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64608);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64600);
    LOCK();
    UNLOCK();
    cRam0000000182eb7d13 = '\x01';
  }
  if (*(char *)(param_1 + 0x48) != '\0') {
    if (*(longlong *)(param_1 + 0x40) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    cVar1 = FUN_180002c20(0,uRam0000000182d64600);
    if ((cVar1 != '\0') && (*(char *)(param_1 + 0x49) == '\0')) {
      uVar2 = FUN_1802c43a0(DAT_182d58368);
      FUN_1814df680(uVar2,param_1,uRam0000000182d64608,0);
      FUN_1804b3c60(uVar2,1,0);
      *(undefined1 *)(param_1 + 0x49) = 1;
    }
  }
  return;
}

