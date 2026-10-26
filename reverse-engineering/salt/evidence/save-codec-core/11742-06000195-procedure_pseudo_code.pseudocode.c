// Ghidra pseudocode; not original source or compilable C.
// ev_c4685037039c5bed031fa1f0cdbbfc99c034cebb99102c664490e1e168a5a620

undefined8 ES3Reader__Create__06000195(void)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  if (cRam0000000182eb7544 == '\0') {
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7544 = '\x01';
  }
  lVar1 = FUN_1802c43a0(DAT_182d534a8);
  ES3Settings___ctor__060001ba(lVar1,1,0);
  if (DAT_182eb7547 == '\0') {
    FUN_1802f2810(&DAT_182d527e0);
    LOCK();
    UNLOCK();
    DAT_182eb7547 = '\x01';
  }
  lVar2 = ES3Internal_ES3Stream__CreateStream__060006e5(lVar1,0,0);
  if (lVar2 != 0) {
    if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(int *)(lVar1 + 0x34) == 0) {
      uVar3 = FUN_1802c43a0(DAT_182d527e0);
      ES3Internal_ES3JSONReader___ctor__0600069f(uVar3,lVar2,lVar1,1,0);
      return uVar3;
    }
  }
  return 0;
}

