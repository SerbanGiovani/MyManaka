// Ghidra pseudocode; not original source or compilable C.
// ev_188f64e77dc2259a6074e86e51145910fd3e714f05d6329f6b7143dd6d3bd036

undefined8 ExposureUnnoticed2_Master_Common_MCustomizeColor__get_Instance__06001340(void)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  
  if (cRam0000000182eb7889 == '\0') {
    FUN_1802f2810(0x182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c1c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7889 = '\x01';
  }
  lVar3 = **(longlong **)(lRam0000000182d5c1c8 + 0xb8);
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ec12f3 == '\0') {
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182ec12f3 = '\x01';
  }
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ec129b == '\0') {
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182ec129b = '\x01';
  }
  if (lVar3 != 0) {
    if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar3 + 0x10) != 0) goto code_r0x00018046b911;
  }
  if (**(longlong **)(lRam0000000182d58238 + 0xb8) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  **(undefined8 **)(lRam0000000182d5c1c8 + 0xb8) =
       *(undefined8 *)(**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x30);
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(ulonglong *)(lRam0000000182d5c1c8 + 0xb8) >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8);
    do {
      uVar4 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar4 == uVar2) {
        *puVar1 = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (uVar4 != uVar2);
  }
code_r0x00018046b911:
  return **(undefined8 **)(lRam0000000182d5c1c8 + 0xb8);
}

