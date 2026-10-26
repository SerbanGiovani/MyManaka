// Ghidra pseudocode; not original source or compilable C.
// ev_c65e1a1b7084558f876bd2b76df96b53abad171e11d5cec6657357017a383486

undefined8 ES3Reader__Create__06000199(undefined8 param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  if (cRam0000000182eb7548 == '\0') {
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7548 = '\x01';
  }
  lVar1 = FUN_1802c43a0(DAT_182d534a8);
  ES3Settings___ctor__060001ba(lVar1,1,0);
  if (DAT_182eb7549 == '\0') {
    FUN_1802f2810(&DAT_182d527e0,lVar1,0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53408);
    LOCK();
    UNLOCK();
    DAT_182eb7549 = '\x01';
  }
  uVar2 = FUN_1802c43a0(DAT_182d53408);
  System_IO_MemoryStream___ctor__0600297f(uVar2,param_1,1,0);
  lVar3 = ES3Internal_ES3Stream__CreateStream__060006e6(uVar2,lVar1,0,0);
  if (lVar3 != 0) {
    if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(int *)(lVar1 + 0x34) == 0) {
      uVar2 = FUN_1802c43a0(DAT_182d527e0);
      ES3Internal_ES3JSONReader___ctor__0600069f(uVar2,lVar3,lVar1,1,0);
      return uVar2;
    }
  }
  return 0;
}

