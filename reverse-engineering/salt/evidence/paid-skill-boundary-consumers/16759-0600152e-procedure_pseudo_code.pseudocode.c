// Ghidra pseudocode; not original source or compilable C.
// ev_fea4d9fc6557eed87c475fc6667aaa76d0eaf18053458c308447cb51d27ee6a5

undefined8 ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsEnoughRp__0600152e(int param_1)

{
  longlong lVar1;
  
  if (cRam0000000182eb7991 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb7991 = '\x01';
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar1 != 0) {
    return CONCAT71((int7)((ulonglong)lVar1 >> 8),(double)param_1 <= *(double *)(lVar1 + 0x1e0));
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

