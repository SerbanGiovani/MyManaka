// Ghidra pseudocode; not original source or compilable C.
// ev_1f7d09f425305c5e05e35a484e8618585bbcf809e7ee4218a62c7b97f390573f

undefined8 ExposureUnnoticed2_Master_Action_MAction__Get__06001385(undefined4 param_1)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 auStackX_18 [2];
  
  if (cRam0000000182eb78a2 == '\0') {
    FUN_1802f2810(0x182d5c0c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c0c8);
    LOCK();
    UNLOCK();
    cRam0000000182eb78a2 = '\x01';
  }
  auStackX_18[0] = 0;
  ExposureUnnoticed2_Master_Action_MAction__CheckInitialize__06001384(0);
  if (**(longlong **)(lRam0000000182d5c0c8 + 0xb8) != 0) {
    cVar1 = FUN_180e77740(**(longlong **)(lRam0000000182d5c0c8 + 0xb8),param_1,auStackX_18,
                          uRam0000000182d5c0c0);
    uVar2 = 0;
    if (cVar1 != '\0') {
      uVar2 = auStackX_18[0];
    }
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

