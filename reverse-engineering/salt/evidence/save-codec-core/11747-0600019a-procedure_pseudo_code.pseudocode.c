// Ghidra pseudocode; not original source or compilable C.
// ev_fb2e9aaf34c2ab9409d42bb7ef2fca94ead0d4a60568897560df344aee5a9f60

undefined8 ES3Reader__Create__0600019a(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  
  if (DAT_182eb7549 == '\0') {
    FUN_1802f2810(&DAT_182d527e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53408);
    LOCK();
    UNLOCK();
    DAT_182eb7549 = '\x01';
  }
  uVar1 = FUN_1802c43a0(DAT_182d53408);
  System_IO_MemoryStream___ctor__0600297f(uVar1,param_1,1,0);
  lVar2 = ES3Internal_ES3Stream__CreateStream__060006e6(uVar1,param_2,0,0);
  if (lVar2 != 0) {
    if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(int *)(param_2 + 0x34) == 0) {
      uVar1 = FUN_1802c43a0(DAT_182d527e0);
      ES3Internal_ES3JSONReader___ctor__0600069f(uVar1,lVar2,param_2,1,0);
      return uVar1;
    }
  }
  return 0;
}

