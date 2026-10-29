// Ghidra pseudocode; not original source or compilable C.
// ev_0b0f65da953d5f86a9aedac71be6243eceb3ca749e74f21bc6e1ee2c641ef627

void ExposureUnnoticed2_Scripts_InGame_GameStateFacade__RiseRp__06001531(float param_1)

{
  longlong lVar1;
  
  if (cRam0000000182eb7994 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dcd8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dcd0);
    LOCK();
    UNLOCK();
    cRam0000000182eb7994 = '\x01';
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar1 != 0) {
    *(double *)(lVar1 + 0x1e0) = (double)param_1 + *(double *)(lVar1 + 0x1e0);
    lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar1 != 0) {
      *(double *)(lVar1 + 0x1f0) = (double)param_1 + *(double *)(lVar1 + 0x1f0);
      lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar1 != 0) {
        *(double *)(lVar1 + 0x138) = (double)param_1 + *(double *)(lVar1 + 0x138);
        if (*(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48) != 0) {
          return;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

