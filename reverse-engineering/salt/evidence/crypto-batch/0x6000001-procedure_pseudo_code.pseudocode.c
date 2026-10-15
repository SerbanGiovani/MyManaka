// Ghidra pseudocode; not original source or compilable C.
// ev_bf279891c89f761b34b45f3212594b397232eb5af0ed657410cabe7518be56b6

ulonglong PasswordMap___ctor__06000001(longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  code *pcVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  uint uVar9;
  bool bVar10;
  
  if (cRam0000000182ebaa7b == '\0') {
    FUN_1802f2810(0x182d6aab0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6aaa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6aaa0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d531f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bf78);
    LOCK();
    UNLOCK();
    cRam0000000182ebaa7b = '\x01';
  }
  uVar4 = FUN_1802c43a0(uRam0000000182d6aaa0);
  FUN_180e95b10(uVar4,uRam0000000182d6aaa8);
  bVar10 = iRam0000000182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x10) = uVar4;
  if (bVar10) {
    uVar9 = (uint)(param_1 + 0x10U >> 0xc);
    lVar5 = (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8;
    do {
      uVar7 = *(ulonglong *)(lVar5 + 0x182f0c920);
      puVar1 = (ulonglong *)(lVar5 + 0x182f0c920);
      LOCK();
      bVar10 = uVar7 == *puVar1;
      if (bVar10) {
        *puVar1 = uVar7 | 1L << (uVar9 & 0x3f);
      }
      UNLOCK();
    } while (!bVar10);
  }
  uVar4 = FUN_1802c43a0(uRam0000000182d6aaa0);
  FUN_180e95b10(uVar4,uRam0000000182d6aaa8);
  bVar10 = iRam0000000182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x18) = uVar4;
  if (bVar10) {
    uVar9 = (uint)(param_1 + 0x18U >> 0xc);
    lVar5 = (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8;
    do {
      uVar7 = *(ulonglong *)(lVar5 + 0x182f0c920);
      puVar1 = (ulonglong *)(lVar5 + 0x182f0c920);
      LOCK();
      bVar10 = uVar7 == *puVar1;
      if (bVar10) {
        *puVar1 = uVar7 | 1L << (uVar9 & 0x3f);
      }
      UNLOCK();
    } while (!bVar10);
  }
  lVar5 = FUN_1802c43a0(uRam0000000182d6aaa0);
  FUN_180e95b10(lVar5,uRam0000000182d6aaa8);
  lVar6 = FUN_1802c36c0(uRam0000000182d531f8,0x1a);
  uVar4 = PasswordMap__Substring__06000002(param_1,0x86,0);
  if (lVar6 != 0) {
    FUN_180002cd0(lVar6,0,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0x1f,0);
    FUN_180002cd0(lVar6,1,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0x31,0);
    FUN_180002cd0(lVar6,2,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0xe,0);
    FUN_180002cd0(lVar6,3,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0x6d,0);
    FUN_180002cd0(lVar6,4,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0x93,0);
    FUN_180002cd0(lVar6,5,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0x50,0);
    FUN_180002cd0(lVar6,6,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0x3f,0);
    FUN_180002cd0(lVar6,7,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0xbc,0);
    FUN_180002cd0(lVar6,8,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0xa8,0);
    FUN_180002cd0(lVar6,9,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0x41,0);
    FUN_180002cd0(lVar6,10,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0xc0,0);
    FUN_180002cd0(lVar6,0xb,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0x4e,0);
    FUN_180002cd0(lVar6,0xc,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0x2e,0);
    FUN_180002cd0(lVar6,0xd,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,99,0);
    FUN_180002cd0(lVar6,0xe,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0xab,0);
    FUN_180002cd0(lVar6,0xf,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0x8c,0);
    FUN_180002cd0(lVar6,0x10,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0x18,0);
    FUN_180002cd0(lVar6,0x11,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0x54,0);
    FUN_180002cd0(lVar6,0x12,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0xb5,0);
    FUN_180002cd0(lVar6,0x13,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0x8a,0);
    FUN_180002cd0(lVar6,0x14,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0x2b,0);
    FUN_180002cd0(lVar6,0x15,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0x48,0);
    FUN_180002cd0(lVar6,0x16,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0xca,0);
    FUN_180002cd0(lVar6,0x17,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0x44,0);
    FUN_180002cd0(lVar6,0x18,uVar4);
    uVar4 = PasswordMap__Substring__06000002(param_1,0x91,0);
    FUN_180002cd0(lVar6,0x19,uVar4);
    uVar4 = FUN_181478f10(lVar6,0);
    if (lVar5 != 0) {
      FUN_180eba640(lVar5,uRam0000000182d5bf78,uVar4,2,
                    *(undefined8 *)
                     (*(longlong *)(*(longlong *)(lRam0000000182d6aab0 + 0x20) + 0xc0) + 0x100));
      bVar10 = iRam0000000182eb5d50 != 0;
      *(longlong *)(param_1 + 0x10) = lVar5;
      if (bVar10) {
        uVar9 = (uint)(param_1 + 0x10U >> 0xc);
        lVar5 = (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8;
        do {
          uVar7 = *(ulonglong *)(lVar5 + 0x182f0c920);
          puVar1 = (ulonglong *)(lVar5 + 0x182f0c920);
          LOCK();
          bVar10 = uVar7 == *puVar1;
          if (bVar10) {
            *puVar1 = uVar7 | 1L << (uVar9 & 0x3f);
          }
          UNLOCK();
        } while (!bVar10);
      }
      uVar4 = FUN_1802c43a0(uRam0000000182d6aaa0);
      uVar7 = FUN_180e95b10(uVar4,uRam0000000182d6aaa8);
      bVar10 = iRam0000000182eb5d50 != 0;
      *(undefined8 *)(param_1 + 0x18) = uVar4;
      if (bVar10) {
        uVar9 = (uint)(param_1 + 0x18U >> 0xc);
        uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
        do {
          uVar2 = *(ulonglong *)(uVar8 * 8 + 0x182f0c920);
          puVar1 = (ulonglong *)(uVar8 * 8 + 0x182f0c920);
          LOCK();
          uVar7 = *puVar1;
          bVar10 = uVar2 == uVar7;
          if (bVar10) {
            *puVar1 = uVar2 | 1L << (uVar9 & 0x3f);
            uVar7 = uVar2;
          }
          UNLOCK();
        } while (!bVar10);
      }
      return uVar7;
    }
  }
  FUN_18031dad0();
  pcVar3 = (code *)swi(3);
  uVar7 = (*pcVar3)();
  return uVar7;
}

