// Ghidra pseudocode; not original source or compilable C.
// ev_cf9999edb99bf6bbf62d64628a95d948e02102a728b9998813749a9c02359b44

void ExposureUnnoticed2_ObjectUI_SaveDataSelectPanel_SaveDataSelectPanelView__Initialize__06001978
               (longlong param_1,undefined8 param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  bool bVar5;
  
  bVar5 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x30) = param_2;
  if (bVar5) {
    uVar4 = (uint)(param_1 + 0x30U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar4 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar3 == uVar2) {
        *puVar1 = uVar3 | 1L << (ulonglong)(uVar4 & 0x3f);
      }
      UNLOCK();
    } while (uVar3 != uVar2);
  }
  FUN_1804e52b0(param_1,0);
  return;
}

