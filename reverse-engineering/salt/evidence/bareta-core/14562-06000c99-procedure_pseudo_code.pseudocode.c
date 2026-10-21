// Ghidra pseudocode; not original source or compilable C.
// ev_228495b5cdfad8546fd13d9294087873aa58181854544dfc9a6ab10fc0a6b5dc

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBaretaEscapeState__Initialize__06000c99
               (longlong param_1,undefined8 param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  bool bVar5;
  
  bVar5 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x10) = param_2;
  if (bVar5) {
    uVar4 = (uint)(param_1 + 0x10U >> 0xc);
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

