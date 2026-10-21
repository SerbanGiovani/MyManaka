// Ghidra pseudocode; not original source or compilable C.
// ev_48ba966e74c39680728c93ef03e2cc5f9ecef989525c23ad99c926d0339f17b9

void IKA9nt_Encrypter_BridgeAssetBundleRequest___ctor__0600004e
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined4 param_6)

{
  longlong lVar1;
  ulonglong uVar2;
  int iVar3;
  undefined8 *puVar4;
  uint uVar5;
  bool bVar6;
  undefined1 auStack_68 [32];
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  longlong lStack_20;
  undefined8 uStack_18;
  undefined8 uStack_10;
  
  iVar3 = DAT_182eb5d50;
  *(undefined8 *)(param_1 + 0x28) = param_3;
  if (iVar3 != 0) {
    uVar5 = (uint)(param_1 + 0x28U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (ulonglong)(uVar5 & 0x3f);
      }
      UNLOCK();
      iVar3 = DAT_182eb5d50;
    } while (!bVar6);
  }
  *(undefined8 *)(param_1 + 0x20) = param_2;
  if (iVar3 != 0) {
    uVar5 = (uint)(param_1 + 0x20U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (ulonglong)(uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  bVar6 = cRam0000000182ebaa8e == '\0';
  *(undefined4 *)(param_1 + 0x50) = param_5;
  *(undefined4 *)(param_1 + 0x54) = param_6;
  if (bVar6) {
    FUN_1802f2810(0x182d64d08);
    LOCK();
    UNLOCK();
    cRam0000000182ebaa8e = '\x01';
  }
  uStack_48 = 0;
  uStack_40 = 0;
  uStack_38 = 0;
  uStack_30 = 0;
  uStack_28 = 0;
  lStack_20 = 0;
  uStack_18 = 0;
  uStack_10 = 0;
  puVar4 = (undefined8 *)FUN_181537280(auStack_68,0);
  uStack_40 = *puVar4;
  uStack_38 = puVar4[1];
  uStack_30 = puVar4[2];
  uStack_28 = puVar4[3];
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)((ulonglong)&uStack_40 >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)((ulonglong)&lStack_20 >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uStack_48 = CONCAT44(uStack_48._4_4_,0xffffffff);
  lStack_20 = param_1;
  uStack_18 = param_4;
  FUN_1807181a0(&uStack_40,&uStack_48,uRam0000000182d64d08);
  return;
}

