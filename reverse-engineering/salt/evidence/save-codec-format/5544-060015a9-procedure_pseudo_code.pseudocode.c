// Ghidra pseudocode; not original source or compilable C.
// ev_5a8706cc18a663ef6ca7aee6656a86f3342c271a32248c61f000348eaca504b8

undefined8 System_Security_Cryptography_HashAlgorithmName__get_SHA1__060015a9(void)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint uVar5;
  undefined1 auStackX_10 [24];
  
  if (cRam0000000182ebae86 == '\0') {
    FUN_1802f2810(0x182d3b148);
    LOCK();
    UNLOCK();
    cRam0000000182ebae86 = '\x01';
  }
  uVar4 = uRam0000000182d3b148;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)((ulonglong)auStackX_10 >> 0xc);
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
  return uVar4;
}

