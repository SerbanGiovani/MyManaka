// Ghidra pseudocode; not original source or compilable C.
// ev_3d5a8e4ecc9819969237d4f910f059dd769fdf3911d3d1554d5c68965c5f5798

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBaretaState__Initialize__06000ca0
               (longlong param_1,undefined8 param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  bool bVar5;
  
  bVar5 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x20) = param_2;
  if (bVar5) {
    uVar4 = (uint)(param_1 + 0x20U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar4 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar3 == uVar2) {
        *puVar1 = uVar3 | 1L << (uVar4 & 0x3f);
      }
      UNLOCK();
    } while (uVar3 != uVar2);
  }
  return;
}

