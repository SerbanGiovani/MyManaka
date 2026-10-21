// Ghidra pseudocode; not original source or compilable C.
// ev_045adf01bf1f9c7dcd05887d6d4c21eaddb123614b800753c84e78556fa3b917

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __c__DisplayClass35_1___LoadBundleFromMemoryAsync_b__0__060000c4
               (longlong param_1,undefined8 param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint uVar7;
  bool bVar8;
  
  if (cRam0000000182ebaade == '\0') {
    FUN_1802f2810(0x182d64c98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d34308);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d2c730);
    LOCK();
    UNLOCK();
    cRam0000000182ebaade = '\x01';
  }
  pcVar3 = pcRam0000000182ebf5c8;
  if ((pcRam0000000182ebf5c8 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.AssetBundle::LoadFromMemory_Internal(System.Byte[],System.UInt32)"
                                    ), pcVar3 == (code *)0x0)) {
    uVar4 = func_0x0001802ced60(
                               "UnityEngine.AssetBundle::LoadFromMemory_Internal(System.Byte[],System.UInt32)"
                               );
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar4,0);
  }
  pcRam0000000182ebf5c8 = pcVar3;
  uVar4 = (*pcRam0000000182ebf5c8)(param_2,0);
  if (*(longlong *)(param_1 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uVar1 = *(undefined8 *)(*(longlong *)(param_1 + 0x18) + 0x10);
  uVar5 = FUN_1802c43a0(uRam0000000182d64c98);
  IKA9nt_Encrypter_EncryptLabelData___ctor__06000024(uVar5,uVar4,uVar1,0);
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5bfb8);
  }
  if (*(longlong *)(param_1 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (**(longlong **)(lRam0000000182d5bfb8 + 0xb8) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  lVar6 = FUN_180eb45b0(**(longlong **)(lRam0000000182d5bfb8 + 0xb8),
                        *(undefined8 *)(*(longlong *)(param_1 + 0x18) + 0x10),uRam0000000182d34308);
  if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  *(undefined8 *)(lVar6 + 0x10) = uVar5;
  if (DAT_182eb5d50 != 0) {
    uVar7 = (uint)(lVar6 + 0x10U >> 0xc);
    lVar6 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar6);
      LOCK();
      bVar8 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar6);
      if (bVar8) {
        *(ulonglong *)(&DAT_182f0c920 + lVar6) = uVar2 | 1L << (uVar7 & 0x3f);
      }
      UNLOCK();
    } while (!bVar8);
  }
  if (*(longlong *)(param_1 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (**(longlong **)(lRam0000000182d5bfb8 + 0xb8) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  lVar6 = FUN_180eb45b0(**(longlong **)(lRam0000000182d5bfb8 + 0xb8),
                        *(undefined8 *)(*(longlong *)(param_1 + 0x18) + 0x10),uRam0000000182d34308);
  if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  *(undefined8 *)(lVar6 + 0x18) = *(undefined8 *)(param_1 + 0x10);
  if (DAT_182eb5d50 != 0) {
    uVar7 = (uint)(lVar6 + 0x18U >> 0xc);
    lVar6 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar6);
      LOCK();
      bVar8 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar6);
      if (bVar8) {
        *(ulonglong *)(&DAT_182f0c920 + lVar6) = uVar2 | 1L << (uVar7 & 0x3f);
      }
      UNLOCK();
    } while (!bVar8);
  }
  if (*(int *)(_DAT_182d2c730 + 0xe0) == 0) {
    FUN_18035c820();
  }
  FUN_18165e470(0);
  return;
}

