// Ghidra pseudocode; not original source or compilable C.
// ev_a13ad803026ee6a684dd4031b6d0c277d636e246e95e9cc894dfb46313c849c3

ulonglong ExposureUnnoticed2_ObjectUI_TutorialPanel_TutorialData___ctor__060017f7(longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  bool bVar6;
  
  if (cRam0000000182eb7b04 == '\0') {
    FUN_1802f2810(0x182d5dd90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dd88);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b04 = '\x01';
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5dd88);
  uVar4 = FUN_180005f20(uVar3);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x20) = uVar3;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x20U >> 0xc);
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

