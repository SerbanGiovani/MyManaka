// Ghidra pseudocode; not original source or compilable C.
// ev_1a98742d3790075a0a87c3a26c7a003e1b12ec5aa4c01d86f06dd3d4eedcfce2

ulonglong ExposureUnnoticed2_Scripts_InGame_RandomMissionManager__Initialize__060015ed
                    (undefined8 param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  bool bVar5;
  
  if (cRam0000000182eb79f2 == '\0') {
    FUN_1802f2810(0x182d5e260);
    LOCK();
    UNLOCK();
    cRam0000000182eb79f2 = '\x01';
  }
  uVar3 = uRam0000000182d5e260;
  **(undefined8 **)(uRam0000000182d5e260 + 0xb8) = param_1;
  if (DAT_182eb5d50 != 0) {
    uVar4 = (uint)(*(ulonglong *)(uRam0000000182d5e260 + 0xb8) >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar4 & 0x1fffff) >> 6) * 8);
    do {
      uVar2 = *puVar1;
      LOCK();
      uVar3 = *puVar1;
      bVar5 = uVar2 == uVar3;
      if (bVar5) {
        *puVar1 = uVar2 | 1L << (uVar4 & 0x3f);
        uVar3 = uVar2;
      }
      UNLOCK();
    } while (!bVar5);
  }
  return uVar3;
}

