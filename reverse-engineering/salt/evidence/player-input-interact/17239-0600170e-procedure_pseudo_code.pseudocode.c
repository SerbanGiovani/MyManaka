// Ghidra pseudocode; not original source or compilable C.
// ev_dd0016a740da315120c291889a4fbff69050ce6a8ce315854b4967a19a6baaa9

void ExposureUnnoticed2_Scripts_Base_InputManager___cctor__0600170e(void)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  uint uVar4;
  bool bVar5;
  
  if (cRam0000000182eb7a95 == '\0') {
    FUN_1802f2810(0x182d5f9d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f9d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a95 = '\x01';
  }
  uVar2 = FUN_1802c43a0(uRam0000000182d5f9d0);
  FUN_180e686d0(uVar2,uRam0000000182d5f9d8);
  *(undefined8 *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x10) = uVar2;
  if (DAT_182eb5d50 != 0) {
    uVar4 = (uint)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x10U >> 0xc);
    uVar3 = (ulonglong)((uVar4 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8);
      LOCK();
      bVar5 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8);
      if (bVar5) {
        *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8) = uVar1 | 1L << (uVar4 & 0x3f);
      }
      UNLOCK();
    } while (!bVar5);
  }
  *(undefined4 *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x38) = 0x3c83126f;
  return;
}

