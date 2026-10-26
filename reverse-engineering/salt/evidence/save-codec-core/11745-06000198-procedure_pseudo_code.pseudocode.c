// Ghidra pseudocode; not original source or compilable C.
// ev_8b218037c9326c0f6919c67e76b987eff23984f287b6570461c3c76876ec1a57

undefined8 ES3Reader__Create__06000198(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  if (DAT_182eb7547 == '\0') {
    FUN_1802f2810(&DAT_182d527e0);
    LOCK();
    UNLOCK();
    DAT_182eb7547 = '\x01';
  }
  lVar1 = ES3Internal_ES3Stream__CreateStream__060006e5(param_1,0,0);
  if (lVar1 != 0) {
    if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(int *)(param_1 + 0x34) == 0) {
      uVar2 = FUN_1802c43a0(DAT_182d527e0);
      ES3Internal_ES3JSONReader___ctor__0600069f(uVar2,lVar1,param_1,1,0);
      return uVar2;
    }
  }
  return 0;
}

