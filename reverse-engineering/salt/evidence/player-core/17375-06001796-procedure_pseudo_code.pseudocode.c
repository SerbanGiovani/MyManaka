// Ghidra pseudocode; not original source or compilable C.
// ev_d9e2d4f928c6f197664bfc10c1c98f44e915e669228ef217870716502e06ffbb

undefined8 ExposureUnnoticed2_Scripts_Base_InteractManager__GetHead__06001796(void)

{
  longlong lVar1;
  longlong lVar2;
  
  if (cRam0000000182eb7abb == '\0') {
    FUN_1802f2810(0x182d5ab80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f600);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f5f0);
    LOCK();
    UNLOCK();
    cRam0000000182eb7abb = '\x01';
  }
  if (*(int *)(lRam0000000182d5ab80 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5ab80);
  }
  lVar1 = **(longlong **)(lRam0000000182d5ab80 + 0xb8);
  if (lVar1 != 0) {
    if (*(uint *)(lVar1 + 0x18) <= *(int *)(lVar1 + 0x18) - 1U) {
                    /* WARNING: Subroutine does not return */
      FUN_181640100(0);
    }
    lVar2 = *(longlong *)(lVar1 + 0x10);
    if (lVar2 != 0) {
      lVar1 = (longlong)*(int *)(lVar1 + 0x18) + -1;
      if ((uint)lVar1 < *(uint *)(lVar2 + 0x18)) {
        return *(undefined8 *)(lVar2 + 0x20 + lVar1 * 8);
      }
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

