// Ghidra pseudocode; not original source or compilable C.
// ev_7a846fd2edd486c6cc2e8f8f00fdcf7db95c6b5201abf901c3dfc4a640b5f4bd

void __c__DisplayClass11_0___OnClickSlot_b__3__06001975(longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  bool bVar8;
  
  if (cRam0000000182eb7c0a == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63670);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c0a = '\x01';
  }
  lVar6 = *(longlong *)(param_1 + 0x20);
  if (lVar6 == 0) {
    lVar6 = FUN_1802c43a0(DAT_182d58368);
    FUN_1814df680(lVar6,param_1,uRam0000000182d63670,0);
    bVar8 = DAT_182eb5d50 != 0;
    *(longlong *)(param_1 + 0x20) = lVar6;
    if (bVar8) {
      uVar7 = (uint)(param_1 + 0x20U >> 0xc);
      puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8);
      do {
        uVar3 = *puVar1;
        LOCK();
        uVar2 = *puVar1;
        if (uVar3 == uVar2) {
          *puVar1 = uVar3 | 1L << (uVar7 & 0x3f);
        }
        UNLOCK();
      } while (uVar3 != uVar2);
    }
  }
  if (DAT_182eb7aa1 == '\0') {
    FUN_1802f2810(&DAT_182d5f910,1,0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f908);
    LOCK();
    UNLOCK();
    DAT_182eb7aa1 = '\x01';
  }
  lVar4 = ExposureUnnoticed2_Scripts_Base_Scheduler__get_Instance__0600174a(0);
  if (lVar4 != 0) {
    lVar4 = *(longlong *)(lVar4 + 0x20);
    lVar5 = FUN_1802c43a0(DAT_182d5f910);
    bVar8 = DAT_182eb5d50 != 0;
    *(longlong *)(lVar5 + 0x10) = lVar6;
    if (bVar8) {
      uVar7 = (uint)(lVar5 + 0x10U >> 0xc);
      puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8);
      do {
        uVar3 = *puVar1;
        LOCK();
        uVar2 = *puVar1;
        if (uVar3 == uVar2) {
          *puVar1 = uVar3 | 1L << (uVar7 & 0x3f);
        }
        UNLOCK();
      } while (uVar3 != uVar2);
    }
    *(undefined4 *)(lVar5 + 0x18) = 1;
    if (lVar4 != 0) {
      FUN_1800068f0(lVar4,lVar5);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

