// Ghidra pseudocode; not original source or compilable C.
// ev_727c552c7ce07b260fb852667310b648d10d03f3ff2a7f252dcf778e69f35a25

ulonglong ExposureUnnoticed2_Scripts_Base_SaveRapper___cctor__060017cf(void)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  bool bVar6;
  
  if (cRam0000000182eb7ae6 == '\0') {
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5a938);
    LOCK();
    UNLOCK();
    cRam0000000182eb7ae6 = '\x01';
  }
  *(undefined4 *)(*(longlong *)(DAT_182d60278 + 0xb8) + 8) = 0;
  uVar3 = FUN_1802c43a0(DAT_182d5a938);
  uVar4 = FUN_1816c7380(uVar3,0);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(*(longlong *)(DAT_182d60278 + 0xb8) + 0x10) = uVar3;
  if (bVar6) {
    uVar5 = (uint)(*(longlong *)(DAT_182d60278 + 0xb8) + 0x10U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8);
    do {
      uVar2 = *puVar1;
      LOCK();
      uVar4 = *puVar1;
      bVar6 = uVar2 == uVar4;
      if (bVar6) {
        *puVar1 = uVar2 | 1L << (uVar5 & 0x3f);
        uVar4 = uVar2;
      }
      UNLOCK();
    } while (!bVar6);
  }
  return uVar4;
}

