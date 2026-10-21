// Ghidra pseudocode; not original source or compilable C.
// ev_e7f295c4d768b9cfcbbe22e77bf93a90f1dd7af208afc0d93a16d49ef29e32bc

void __c___OnFoundStrangerEvent_b__39_3__06000d6d(void)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  
  if (cRam0000000182eb83ea == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb83ea = '\x01';
  }
  lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar2 != 0) {
    piVar1 = (int *)(lVar2 + 0x1bc);
    *piVar1 = *piVar1 + -1;
    lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar2 != 0) {
      iVar3 = *(int *)(lVar2 + 0x1bc);
      if (iVar3 < 1) {
        iVar3 = 0;
      }
      *(int *)(lVar2 + 0x1bc) = iVar3;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

