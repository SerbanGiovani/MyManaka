// Ghidra pseudocode; not original source or compilable C.
// ev_e3adc9b6904fe15e2c1e47d0a036696d4db2b8bc8e3a23e9237404a4c1110a10

longlong * System_Security_Cryptography_Aes__Create__060015b5(void)

{
  bool bVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  
  if (cRam0000000182ebae8d == '\0') {
    FUN_1802f2810(0x182d6ab48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3b118);
    LOCK();
    UNLOCK();
    cRam0000000182ebae8d = '\x01';
  }
  if (*(int *)(lRam0000000182d6ab48 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar2 = lRam0000000182d3b118;
  if (cRam0000000182ebae8e == '\0') {
    FUN_1802f2810(0x182d6ab48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d37a98);
    LOCK();
    UNLOCK();
    cRam0000000182ebae8e = '\x01';
  }
  if (lVar2 != 0) {
    if (*(int *)(lRam0000000182d37a98 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (cRam0000000182ebaf10 == '\0') {
      FUN_1802f2810(0x182d37a98);
      LOCK();
      UNLOCK();
      cRam0000000182ebaf10 = '\x01';
    }
    if (*(int *)(lRam0000000182d37a98 + 0xe0) == 0) {
      FUN_18035c820();
    }
    plVar3 = (longlong *)FUN_1814b5000(lVar2,0,0);
    plVar6 = (longlong *)0x0;
    if (plVar3 != (longlong *)0x0) {
      if ((*(byte *)(*plVar3 + 0x130) < *(byte *)(lRam0000000182d6ab48 + 0x130)) ||
         (bVar1 = true,
         *(longlong *)
          (*(longlong *)(*plVar3 + 200) + -8 +
          (ulonglong)*(byte *)(lRam0000000182d6ab48 + 0x130) * 8) != lRam0000000182d6ab48)) {
        bVar1 = false;
      }
      if (bVar1) {
        plVar6 = plVar3;
      }
    }
    return plVar6;
  }
  uVar4 = thunk_FUN_1802f2810(&DAT_182d528c8);
  uVar4 = thunk_FUN_1802c43a0(uVar4);
  uVar5 = thunk_FUN_1802f2810(0x182d3b0d8);
  FUN_1815c6a10(uVar4,uVar5,0);
  uVar5 = thunk_FUN_1802f2810(0x182d3b0d0);
                    /* WARNING: Subroutine does not return */
  FUN_18031da90(uVar4,uVar5);
}

