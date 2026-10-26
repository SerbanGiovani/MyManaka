// Ghidra pseudocode; not original source or compilable C.
// ev_027d8e428d4891b816547d9d8be41c523a33db1bd54916ef6dd984d3e00cc51c

void System_Security_Cryptography_Rfc2898DeriveBytes__Initialize__06001567(longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint uVar5;
  bool bVar6;
  
  if (cRam0000000182ebae66 == '\0') {
    FUN_1802f2810(&DAT_182d53428);
    LOCK();
    UNLOCK();
    cRam0000000182ebae66 = '\x01';
  }
  if (*(longlong *)(param_1 + 0x38) != 0) {
    FUN_181646f50(*(undefined8 *)(param_1 + 0x38),0,
                  *(undefined4 *)(*(longlong *)(param_1 + 0x38) + 0x18),0);
  }
  uVar4 = FUN_1802c36c0(DAT_182d53428,*(undefined4 *)(param_1 + 0x30));
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x38) = uVar4;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x38U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar3 == uVar2) {
        *puVar1 = uVar3 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (uVar3 != uVar2);
  }
  *(undefined8 *)(param_1 + 0x40) = 1;
  *(undefined4 *)(param_1 + 0x48) = 0;
  return;
}

