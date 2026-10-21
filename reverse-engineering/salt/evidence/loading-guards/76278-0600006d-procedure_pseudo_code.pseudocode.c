// Ghidra pseudocode; not original source or compilable C.
// ev_82b600f3ba9233848a2b2b3390b6b2fd694c51352bb8c565994e7311907fc6ba

ulonglong IKA9nt_Encrypter_EncrypterCore__StaticReset__0600006d(void)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  bool bVar6;
  
  if (cRam0000000182ebaa94 == '\0') {
    FUN_1802f2810(0x182d64ce8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64ce0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64cd8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64e78);
    LOCK();
    UNLOCK();
    cRam0000000182ebaa94 = '\x01';
  }
  if (*(int *)(uRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820(uRam0000000182d5bfb8);
  }
  if (**(longlong **)(uRam0000000182d5bfb8 + 0xb8) != 0) {
    FUN_180e0d9c0(**(longlong **)(uRam0000000182d5bfb8 + 0xb8),uRam0000000182d64cd8);
    lVar1 = *(longlong *)(*(longlong *)(uRam0000000182d5bfb8 + 0xb8) + 8);
    if (lVar1 != 0) {
      FUN_180e0d9c0(lVar1,uRam0000000182d64ce0);
      lVar1 = *(longlong *)(*(longlong *)(uRam0000000182d5bfb8 + 0xb8) + 0x10);
      if (lVar1 != 0) {
        FUN_180e0d9c0(lVar1,uRam0000000182d64ce8);
        *(undefined8 *)(*(longlong *)(uRam0000000182d5bfb8 + 0xb8) + 0x18) = 0;
        if (DAT_182eb5d50 != 0) {
          uVar5 = (uint)(*(longlong *)(uRam0000000182d5bfb8 + 0xb8) + 0x18U >> 0xc);
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
        uVar3 = FUN_1802c43a0(uRam0000000182d64e78);
        PasswordMap___ctor__06000001(uVar3,0);
        bVar6 = DAT_182eb5d50 != 0;
        *(undefined8 *)(*(longlong *)(uRam0000000182d5bfb8 + 0xb8) + 0x20) = uVar3;
        if (bVar6) {
          uVar5 = (uint)(*(longlong *)(uRam0000000182d5bfb8 + 0xb8) + 0x20U >> 0xc);
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
        *(undefined4 *)(*(longlong *)(uRam0000000182d5bfb8 + 0xb8) + 0x28) = 0x20;
        *(undefined4 *)(*(longlong *)(uRam0000000182d5bfb8 + 0xb8) + 0x2c) = 2;
        *(undefined4 *)(*(longlong *)(uRam0000000182d5bfb8 + 0xb8) + 0x30) = 0;
        *(undefined8 *)(*(longlong *)(uRam0000000182d5bfb8 + 0xb8) + 0x38) = 0;
        if (DAT_182eb5d50 != 0) {
          uVar5 = (uint)(*(longlong *)(uRam0000000182d5bfb8 + 0xb8) + 0x38U >> 0xc);
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
        *(undefined8 *)(*(longlong *)(uRam0000000182d5bfb8 + 0xb8) + 0x40) = 0;
        if (DAT_182eb5d50 != 0) {
          uVar5 = (uint)(*(longlong *)(uRam0000000182d5bfb8 + 0xb8) + 0x40U >> 0xc);
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
        *(undefined8 *)(*(longlong *)(uRam0000000182d5bfb8 + 0xb8) + 0x48) = 0;
        if (DAT_182eb5d50 != 0) {
          uVar5 = (uint)(*(longlong *)(uRam0000000182d5bfb8 + 0xb8) + 0x48U >> 0xc);
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
        uVar4 = uRam0000000182d5bfb8;
        *(undefined8 *)(*(longlong *)(uRam0000000182d5bfb8 + 0xb8) + 0x50) = 0;
        if (DAT_182eb5d50 != 0) {
          uVar5 = (uint)(*(longlong *)(uRam0000000182d5bfb8 + 0xb8) + 0x50U >> 0xc);
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
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

