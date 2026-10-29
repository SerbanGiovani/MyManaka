// Ghidra pseudocode; not original source or compilable C.
// ev_29ac5da0f24e0391bd9b562cf0c34038cc97b8fb31926c458a297fd31b707def

ulonglong ExposureUnnoticed2_Scripts_Base_SaveRapper__PreProcess__060017b8
                    (undefined1 param_1,undefined4 param_2,undefined1 param_3)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  bool bVar5;
  
  if (DAT_182eb7ad8 == '\0') {
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    DAT_182eb7ad8 = '\x01';
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d60278);
  }
  **(undefined1 **)(DAT_182d60278 + 0xb8) = param_1;
  *(undefined4 *)(*(longlong *)(DAT_182d60278 + 0xb8) + 8) = param_2;
  *(undefined1 *)(*(longlong *)(DAT_182d60278 + 0xb8) + 4) = param_3;
  uVar3 = ExposureUnnoticed2_Scripts_Base_SaveRapper__GetSaveDataPath__060017b5(0);
  *(ulonglong *)(*(longlong *)(DAT_182d60278 + 0xb8) + 0x18) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar4 = (uint)(*(longlong *)(DAT_182d60278 + 0xb8) + 0x18U >> 0xc);
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

