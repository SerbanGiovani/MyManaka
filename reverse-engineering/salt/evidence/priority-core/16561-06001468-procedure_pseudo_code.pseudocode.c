// Ghidra pseudocode; not original source or compilable C.
// ev_4d5bbb32ab37958ebe38c3a9fdbbbe892a6ccb2b9ed9cf1afbfff47aa261cf8c

void ExposureUnnoticed2_Scripts_Mission_MissionManager__Dispose__06001468(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  char cVar4;
  uint uVar5;
  bool bVar6;
  undefined8 uStack_40;
  undefined4 *puStack_38;
  undefined8 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  longlong *plStack_18;
  
  if (cRam0000000182eb7924 == '\0') {
    FUN_1802f2810(0x182d5e160);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e158);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e150);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e148);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e190);
    LOCK();
    UNLOCK();
    cRam0000000182eb7924 = '\x01';
  }
  if (**(longlong **)(lRam0000000182d5e190 + 0xb8) == param_1) {
    **(longlong **)(lRam0000000182d5e190 + 0xb8) = 0;
    if (DAT_182eb5d50 != 0) {
      uVar5 = (uint)(*(ulonglong *)(lRam0000000182d5e190 + 0xb8) >> 0xc);
      lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
      do {
        uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        LOCK();
        bVar6 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
        if (bVar6) {
          *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar3 | 1L << (ulonglong)(uVar5 & 0x3f);
        }
        UNLOCK();
      } while (!bVar6);
    }
    lVar1 = *(longlong *)(param_1 + 0x10);
    if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (DAT_182eb5d50 != 0) {
      uVar5 = (uint)((ulonglong)&uStack_40 >> 0xc);
      lVar2 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
      do {
        uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
        LOCK();
        bVar6 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
        if (bVar6) {
          *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar3 | 1L << (uVar5 & 0x3f);
        }
        UNLOCK();
      } while (!bVar6);
    }
    uStack_1c = *(undefined4 *)(lVar1 + 0x1c);
    uStack_30 = 0;
    uStack_40._0_4_ = (undefined4)lVar1;
    uStack_40._4_4_ = (undefined4)((ulonglong)lVar1 >> 0x20);
    uStack_28 = (undefined4)uStack_40;
    uStack_24 = uStack_40._4_4_;
    uStack_20 = 0;
    plStack_18 = (longlong *)0x0;
    uStack_40 = 0;
    puStack_38 = &uStack_28;
    while (cVar4 = FUN_180f72b70(&uStack_28,uRam0000000182d5e158), cVar4 != '\0') {
      if (plStack_18 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      (**(code **)(*plStack_18 + 0x208))(plStack_18,*(undefined8 *)(*plStack_18 + 0x210));
    }
  }
  return;
}

