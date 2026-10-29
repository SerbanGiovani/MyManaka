// Ghidra pseudocode; not original source or compilable C.
// ev_245b5ca13f26c102e8186822d28044d9bf73dda76a8483fdf2731e403d575dfa

void ExposureUnnoticed2_Scripts_InGame_GameStateFacade__RiseEarnRp__06001530(float param_1)

{
  longlong lVar1;
  
  if (cRam0000000182eb7993 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb7993 = '\x01';
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar1 != 0) {
    *(double *)(lVar1 + 0x1f0) = (double)param_1 + *(double *)(lVar1 + 0x1f0);
    lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar1 != 0) {
      *(double *)(lVar1 + 0x138) = (double)param_1 + *(double *)(lVar1 + 0x138);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

