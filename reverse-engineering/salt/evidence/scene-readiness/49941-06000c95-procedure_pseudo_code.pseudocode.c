// Ghidra pseudocode; not original source or compilable C.
// ev_f4a31ddb9fe1b12c517f190e56c3becffa14ffaee062b2f131e763aa80e9aa20

ulonglong UnityEngine_SceneManagement_SceneManagerAPI___cctor__06000c95(void)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  bool bVar5;
  
  if (cRam0000000182ec198a == '\0') {
    FUN_1802f2810(0x182d650f8);
    LOCK();
    UNLOCK();
    cRam0000000182ec198a = '\x01';
  }
  uVar3 = FUN_1802c43a0(lRam0000000182d650f8);
  **(ulonglong **)(lRam0000000182d650f8 + 0xb8) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar4 = (uint)(*(ulonglong *)(lRam0000000182d650f8 + 0xb8) >> 0xc);
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

