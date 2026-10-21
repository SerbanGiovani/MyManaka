// Ghidra pseudocode; not original source or compilable C.
// ev_a75c02177ad2ef39892ce7d5c2c6fb13ac7ecb664818e8be55c5f00e436a5766

ulonglong ExposureUnnoticed2_Scripts_Base_InteractManager___cctor__0600179c(void)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  bool bVar7;
  
  if (cRam0000000182eb7ac0 == '\0') {
    FUN_1802f2810(0x182d5ab80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f5e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f5e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f5a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f5a0);
    LOCK();
    UNLOCK();
    cRam0000000182eb7ac0 = '\x01';
  }
  lVar3 = FUN_1802c43a0(uRam0000000182d5f5a0);
  FUN_1811cf4f0(lVar3,uRam0000000182d5f5a8);
  lVar4 = FUN_1802c43a0(uRam0000000182d5f5e8);
  if ((lVar4 != 0) && (*(undefined4 *)(lVar4 + 0x10) = 0, lVar3 != 0)) {
    FUN_180006a10(lVar3,lVar4);
    uVar5 = uRam0000000182d5ab80;
    bVar7 = DAT_182eb5d50 != 0;
    **(longlong **)(uRam0000000182d5ab80 + 0xb8) = lVar3;
    if (bVar7) {
      uVar6 = (uint)(*(ulonglong *)(uRam0000000182d5ab80 + 0xb8) >> 0xc);
      puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8);
      do {
        uVar2 = *puVar1;
        LOCK();
        uVar5 = *puVar1;
        bVar7 = uVar2 == uVar5;
        if (bVar7) {
          *puVar1 = uVar2 | 1L << (uVar6 & 0x3f);
          uVar5 = uVar2;
        }
        UNLOCK();
      } while (!bVar7);
    }
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

