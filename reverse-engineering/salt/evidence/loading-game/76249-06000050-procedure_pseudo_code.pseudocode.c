// Ghidra pseudocode; not original source or compilable C.
// ev_56be3b392ffc1d34113c587486aa836c2f033396ddbecdba445db9da239bfeea

void IKA9nt_Encrypter_BridgeAssetBundleRequest__Mode2__06000050
               (undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  uint uVar4;
  bool bVar5;
  undefined1 auStack_68 [32];
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  undefined8 uStack_10;
  
  if (cRam0000000182ebaa8e == '\0') {
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
  uStack_20 = 0;
  uStack_18 = 0;
  uStack_10 = 0;
  puVar3 = (undefined8 *)FUN_181537280(auStack_68,0);
  uStack_40 = *puVar3;
  uStack_38 = puVar3[1];
  uStack_30 = puVar3[2];
  uStack_28 = puVar3[3];
  if (DAT_182eb5d50 != 0) {
    uVar4 = (uint)((ulonglong)&uStack_40 >> 0xc);
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
  if (DAT_182eb5d50 != 0) {
    uVar4 = (uint)((ulonglong)&uStack_20 >> 0xc);
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
  uStack_48 = CONCAT44(uStack_48._4_4_,0xffffffff);
  uStack_20 = param_1;
  uStack_18 = param_2;
  FUN_1807181a0(&uStack_40,&uStack_48,uRam0000000182d64d08);
  return;
}

