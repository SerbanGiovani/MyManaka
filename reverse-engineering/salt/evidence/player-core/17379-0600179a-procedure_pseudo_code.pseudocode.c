// Ghidra pseudocode; not original source or compilable C.
// ev_82c0f73519be3875a2adea3b26e305a6dc9b39d224e198bd206cf6fc26287ab9

ulonglong ExposureUnnoticed2_Scripts_Base_InteractManager__OnInteract__0600179a
                    (undefined8 param_1,longlong param_2)

{
  ulonglong *puVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  bool bVar6;
  
  if (cRam0000000182eb7abf == '\0') {
    FUN_1802f2810(0x182d5ab80);
    LOCK();
    UNLOCK();
    cRam0000000182eb7abf = '\x01';
  }
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uVar2 = *(undefined8 *)(param_2 + 0x10);
  if (*(int *)(lRam0000000182d5ab80 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5ab80);
  }
  uVar4 = *(ulonglong *)(lRam0000000182d5ab80 + 0xb8);
  *(undefined8 *)(uVar4 + 8) = uVar2;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(lRam0000000182d5ab80 + 0xb8) + 8U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar4 = *puVar1;
      bVar6 = uVar3 == uVar4;
      if (bVar6) {
        *puVar1 = uVar3 | 1L << (uVar5 & 0x3f);
        uVar4 = uVar3;
      }
      UNLOCK();
    } while (!bVar6);
  }
  return uVar4;
}

