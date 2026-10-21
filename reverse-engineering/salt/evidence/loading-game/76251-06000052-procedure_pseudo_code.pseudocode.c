// Ghidra pseudocode; not original source or compilable C.
// ev_72d12ee59e5e3a2425ab64f07db249ff9da57c42ef976dee1ff4556b8d07ecc5

ulonglong IKA9nt_Encrypter_BridgeAssetBundleRequest__Mode2Update__06000052(longlong param_1)

{
  ulonglong *puVar1;
  char cVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  bool bVar7;
  
  if (cRam0000000182ebaa90 == '\0') {
    FUN_1802f2810(0x182d53428);
    LOCK();
    UNLOCK();
    cRam0000000182ebaa90 = '\x01';
  }
  cVar2 = *(char *)(param_1 + 0x38);
  while (cVar2 == '\0') {
    FUN_1816a4160(*(undefined4 *)(param_1 + 0x54),0);
    cVar2 = *(char *)(param_1 + 0x38);
  }
  lVar3 = *(longlong *)(param_1 + 0x40);
  if (lVar3 != 0) {
    (**(code **)(lVar3 + 0x18))(*(undefined8 *)(lVar3 + 0x40),0,*(undefined8 *)(lVar3 + 0x28));
  }
  lVar3 = *(longlong *)(param_1 + 0x48);
  if (lVar3 != 0) {
    (**(code **)(lVar3 + 0x18))
              (*(undefined8 *)(lVar3 + 0x40),*(undefined8 *)(param_1 + 0x58),
               *(undefined8 *)(lVar3 + 0x28));
    uVar5 = FUN_1802c36c0(uRam0000000182d53428,0);
    bVar7 = DAT_182eb5d50 != 0;
    *(ulonglong *)(param_1 + 0x58) = uVar5;
    if (bVar7) {
      uVar6 = (uint)(param_1 + 0x58U >> 0xc);
      puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8);
      do {
        uVar4 = *puVar1;
        LOCK();
        uVar5 = *puVar1;
        bVar7 = uVar4 == uVar5;
        if (bVar7) {
          *puVar1 = uVar4 | 1L << (uVar6 & 0x3f);
          uVar5 = uVar4;
        }
        UNLOCK();
      } while (!bVar7);
    }
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

