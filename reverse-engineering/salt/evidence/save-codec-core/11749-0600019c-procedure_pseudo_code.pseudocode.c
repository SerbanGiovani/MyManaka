// Ghidra pseudocode; not original source or compilable C.
// ev_bb89594f314d5689cdfdce633cd1db20930c4a301ca479e32c481c40944fae0e

undefined8 ES3Reader__Create__0600019c(undefined8 param_1,longlong param_2,undefined1 param_3)

{
  undefined8 uVar1;
  
  if (DAT_182eb754b == '\0') {
    FUN_1802f2810(&DAT_182d527e0);
    LOCK();
    UNLOCK();
    DAT_182eb754b = '\x01';
  }
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0x34) != 0) {
      return 0;
    }
    uVar1 = FUN_1802c43a0(DAT_182d527e0);
    ES3Internal_ES3JSONReader___ctor__0600069f(uVar1,param_1,param_2,param_3,0);
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

