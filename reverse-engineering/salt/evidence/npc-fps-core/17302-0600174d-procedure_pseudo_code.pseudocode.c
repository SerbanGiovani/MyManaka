// Ghidra pseudocode; not original source or compilable C.
// ev_83021781acf0707d2f90650f84a4ba6fd97411a8f151e0966f732704fb12e9dd

void ExposureUnnoticed2_Scripts_Base_Scheduler__DelayScaledTime__0600174d
               (undefined8 param_1,undefined4 param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  if (DAT_182eb7aa3 == '\0') {
    FUN_1802f2810(&DAT_182d5f900);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f8f8);
    LOCK();
    UNLOCK();
    DAT_182eb7aa3 = '\x01';
  }
  lVar1 = ExposureUnnoticed2_Scripts_Base_Scheduler__get_Instance__0600174a(0);
  if (lVar1 != 0) {
    lVar1 = *(longlong *)(lVar1 + 0x38);
    uVar2 = FUN_1802c43a0(DAT_182d5f900);
    DelayTimeModel___ctor__06001753(uVar2,param_1,param_2,0,0);
    if (lVar1 != 0) {
      FUN_180006950(lVar1,uVar2);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

