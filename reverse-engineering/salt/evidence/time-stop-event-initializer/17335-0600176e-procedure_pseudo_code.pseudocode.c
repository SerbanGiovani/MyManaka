// Ghidra pseudocode; not original source or compilable C.
// ev_34ebb944d68fb8667ded990be63ff0de50f56b829902568d270a8b84bb978bc3

ulonglong ExposureUnnoticed2_Scripts_Base_Events___cctor__0600176e(void)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  bool bVar6;
  
  if (cRam0000000182eb7ab1 == '\0') {
    FUN_1802f2810(0x182d5f778);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f768);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f760);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f758);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f748);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f740);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f738);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f730);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f728);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f720);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f710);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f708);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f700);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f6f0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f6e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f6d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f6c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58080);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f6b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f6a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f690);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f688);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f680);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f678);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f670);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f668);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f660);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f650);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f640);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f638);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f630);
    LOCK();
    UNLOCK();
    cRam0000000182eb7ab1 = '\x01';
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f640);
  **(undefined8 **)(DAT_182d58080 + 0xb8) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(ulonglong *)(DAT_182d58080 + 0xb8) >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f700);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 8) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 8U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f6d0);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x10) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x10U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f6b0);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x18) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x18U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f690);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x20) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x20U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f6a0);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x28) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x28U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f650);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x30) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x30U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f680);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x38) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x38U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f740);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x40) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x40U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f6f0);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x48) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x48U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f778);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x50) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x50U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f710);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x58) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x58U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f760);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x60) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x60U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f720);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x68) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x68U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f730);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x70) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x70U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f748);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x78) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x78U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f768);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x80) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x80U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f728);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x88) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x88U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f660);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x90) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x90U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f670);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x98) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x98U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f638);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0xa0) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0xa0U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f758);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0xa8) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0xa8U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f6e0);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0xb0) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0xb0U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f630);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0xb8) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0xb8U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f6c0);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0xc0) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0xc0U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f688);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 200) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 200U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f668);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0xd0) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0xd0U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f708);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0xd8) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0xd8U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5f678);
  *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0xe0) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0xe0U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar4 = FUN_1802c43a0(uRam0000000182d5f738);
  *(ulonglong *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0xe8) = uVar4;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d58080 + 0xb8) + 0xe8U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      bVar6 = uVar2 == uVar4;
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar5 & 0x3f);
        uVar4 = uVar2;
      }
      UNLOCK();
    } while (!bVar6);
  }
  return uVar4;
}

