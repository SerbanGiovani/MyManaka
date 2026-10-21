// Ghidra pseudocode; not original source or compilable C.
// ev_6c2f99bb7ebd72324a0d2591dc4c8c23120100921c8c1abca4f5e165839ed53b

undefined8
ExposureUnnoticed2_Object3D_NPC_Script_NpcComponent__CreateController__06001011(longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint uVar5;
  bool bVar6;
  
  if (DAT_182eb7754 == '\0') {
    FUN_1802f2810(&DAT_182d59a98);
    LOCK();
    UNLOCK();
    DAT_182eb7754 = '\x01';
  }
  uVar4 = FUN_1802c43a0(DAT_182d59a98);
  ExposureUnnoticed2_Object3D_NPC_Script_NpcController___ctor__06001054(uVar4,param_1,0);
  bVar6 = DAT_182eb5d50 == 0;
  *(undefined8 *)(param_1 + 0x98) = uVar4;
  if (bVar6) {
    return uVar4;
  }
  uVar5 = (uint)(param_1 + 0x98U >> 0xc);
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
  return *(undefined8 *)(param_1 + 0x98);
}

