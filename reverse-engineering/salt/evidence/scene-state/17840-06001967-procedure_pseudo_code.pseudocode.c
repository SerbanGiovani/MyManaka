// Ghidra pseudocode; not original source or compilable C.
// ev_e5172a29cee376cfe8e87e4146d2bffa5403e57df19b8f751f161e5e24b88b32

void ExposureUnnoticed2_ObjectUI_SaveDataSelectPanel_ManualSavePanelView__Initialize__06001967
               (longlong param_1,undefined4 param_2,undefined8 param_3)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  bool bVar5;
  
  bVar5 = DAT_182eb5d50 != 0;
  *(undefined4 *)(param_1 + 0x78) = param_2;
  *(undefined8 *)(param_1 + 0x80) = param_3;
  if (bVar5) {
    uVar4 = (uint)(param_1 + 0x80U >> 0xc);
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
  ExposureUnnoticed2_ObjectUI_SaveDataSelectPanel_ManualSavePanelView__RefreshView__0600196a
            (param_1,0);
  return;
}

