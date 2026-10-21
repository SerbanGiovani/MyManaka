// Ghidra pseudocode; not original source or compilable C.
// ev_a310fd19e5cf4a414ee852592b2e248c31ba8c256e29b58a4e51185a8da3b535

void IKA9nt_Encrypter_EncrypterCore___cctor__060000bc(void)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  bool bVar5;
  
  if (cRam0000000182ebaadc == '\0') {
    FUN_1802f2810(0x182d649c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64990);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64988);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64980);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64978);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d649a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64e78);
    LOCK();
    UNLOCK();
    cRam0000000182ebaadc = '\x01';
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d64978);
  FUN_180e95b10(uVar3,uRam0000000182d649c0);
  **(undefined8 **)(lRam0000000182d5bfb8 + 0xb8) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar4 = (uint)(*(ulonglong *)(lRam0000000182d5bfb8 + 0xb8) >> 0xc);
    lVar1 = (ulonglong)((uVar4 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar5 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar5) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar4 & 0x3f);
      }
      UNLOCK();
    } while (!bVar5);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d649a0);
  FUN_180e95b10(uVar3,uRam0000000182d64988);
  *(undefined8 *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 8) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar4 = (uint)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 8U >> 0xc);
    lVar1 = (ulonglong)((uVar4 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar5 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar5) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar4 & 0x3f);
      }
      UNLOCK();
    } while (!bVar5);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d64980);
  FUN_180e95b10(uVar3,uRam0000000182d64990);
  *(undefined8 *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x10) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar4 = (uint)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x10U >> 0xc);
    lVar1 = (ulonglong)((uVar4 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar5 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar5) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar4 & 0x3f);
      }
      UNLOCK();
    } while (!bVar5);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d64e78);
  PasswordMap___ctor__06000001(uVar3,0);
  bVar5 = DAT_182eb5d50 != 0;
  *(undefined8 *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x20) = uVar3;
  if (bVar5) {
    uVar4 = (uint)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x20U >> 0xc);
    lVar1 = (ulonglong)((uVar4 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar5 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar5) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar4 & 0x3f);
      }
      UNLOCK();
    } while (!bVar5);
  }
  *(undefined4 *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x28) = 0x20;
  *(undefined4 *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x2c) = 2;
  *(undefined4 *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x30) = 0;
  return;
}

