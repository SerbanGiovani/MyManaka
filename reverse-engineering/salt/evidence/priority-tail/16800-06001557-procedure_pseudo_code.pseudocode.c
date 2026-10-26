// Ghidra pseudocode; not original source or compilable C.
// ev_eeab4b57a5101533365f5b59cd582efbd56a5d89622b32d2a283c5be2f91306b

float ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetOptionWheelScale__06001557(void)

{
  longlong lVar1;
  int iVar2;
  
  if (cRam0000000182eb79ba == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb79ba = '\x01';
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
  if (lVar1 != 0) {
    iVar2 = -*(int *)(lVar1 + 0x74);
    if (*(char *)(lVar1 + 0x6c) == '\0') {
      iVar2 = *(int *)(lVar1 + 0x74);
    }
    return (float)iVar2 * 0.1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

