// Ghidra pseudocode; not original source or compilable C.
// ev_546ecb0037b371be3bfb76931b0c368fb09f500d9383507d78651fdc538ff646

undefined8 ES3Reader__Create__0600019b(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (cRam0000000182eb754a == '\0') {
    FUN_1802f2810(&DAT_182d527e0);
    LOCK();
    UNLOCK();
    cRam0000000182eb754a = '\x01';
  }
  uVar1 = ES3Internal_ES3Stream__CreateStream__060006e6(param_1,param_2,0,0);
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0x34) != 0) {
      return 0;
    }
    uVar2 = FUN_1802c43a0(DAT_182d527e0);
    ES3Internal_ES3JSONReader___ctor__0600069f(uVar2,uVar1,param_2,1,0);
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

