// Ghidra pseudocode; not original source or compilable C.
// ev_6749db51ebbc8bfc603abaca8c7cc00c9e52261c2c065d603ea5f042d344ef9b

void ExposureUnnoticed2_Scripts_Mission_MissionManager__OnLateUpdate__06001469(longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  char cVar5;
  uint uVar6;
  undefined8 uStack_40;
  undefined4 *puStack_38;
  undefined8 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  longlong lStack_18;
  
  if (cRam0000000182eb7925 == '\0') {
    FUN_1802f2810(0x182d5e160);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e158);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e150);
    LOCK();
    UNLOCK();
    FUN_1802f2810();
    LOCK();
    UNLOCK();
    cRam0000000182eb7925 = '\x01';
  }
  lVar3 = *(longlong *)(param_1 + 0x10);
  if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (DAT_182eb5d50 != 0) {
    uVar6 = (uint)((ulonglong)&uStack_40 >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8);
    do {
      uVar4 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar4 == uVar2) {
        *puVar1 = uVar4 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (uVar4 != uVar2);
  }
  uStack_1c = *(undefined4 *)(lVar3 + 0x1c);
  uStack_30 = 0;
  uStack_40._0_4_ = (undefined4)lVar3;
  uStack_40._4_4_ = (undefined4)((ulonglong)lVar3 >> 0x20);
  uStack_28 = (undefined4)uStack_40;
  uStack_24 = uStack_40._4_4_;
  uStack_20 = 0;
  lStack_18 = 0;
  uStack_40 = 0;
  puStack_38 = &uStack_28;
  while( true ) {
    cVar5 = FUN_180f72b70(&uStack_28,uRam0000000182d5e158);
    if (cVar5 == '\0') {
      return;
    }
    if (lStack_18 == 0) break;
    ExposureUnnoticed2_Scripts_Mission_MissionBase__Update__06001422(lStack_18,0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

