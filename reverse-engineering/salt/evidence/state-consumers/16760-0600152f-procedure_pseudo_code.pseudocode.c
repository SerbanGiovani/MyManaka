// Ghidra pseudocode; not original source or compilable C.
// ev_bc0160f7e5339a921d5feba580154d2a6038ff8488a8107c2f2d4e7882eb2dfd

void ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ConsumeRp__0600152f(int param_1)

{
  longlong lVar1;
  
  if (cRam0000000182eb7992 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb7992 = '\x01';
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar1 != 0) {
    *(double *)(lVar1 + 0x1e0) = *(double *)(lVar1 + 0x1e0) - (double)param_1;
    lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar1 != 0) {
      *(double *)(lVar1 + 0x150) = (double)param_1 + *(double *)(lVar1 + 0x150);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

