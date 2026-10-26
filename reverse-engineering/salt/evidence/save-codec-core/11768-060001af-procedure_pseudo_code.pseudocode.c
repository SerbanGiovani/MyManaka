// Ghidra pseudocode; not original source or compilable C.
// ev_7c4926d38a283bbefdee36d02da7382e7d966f64e78b06b74e3aeb02c962b622

undefined8 ES3Settings__get_defaultSettingsScriptableObject__060001af(void)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  uint uVar6;
  
  if (DAT_182eb7550 == '\0') {
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d527a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d527a0);
    LOCK();
    UNLOCK();
    DAT_182eb7550 = '\x01';
  }
  if (*(int *)(DAT_182d534a8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar3 = *(longlong *)(*(longlong *)(DAT_182d534a8 + 0xb8) + 8);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec12f3 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec12f3 = '\x01';
  }
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec129b == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec129b = '\x01';
  }
  if (lVar3 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar3 + 0x10) != 0) goto LAB_1803cc011;
  }
  uVar5 = FUN_1809fce30(DAT_182d527a0,DAT_182d527a8);
  if (*(int *)(DAT_182d534a8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  *(undefined8 *)(*(longlong *)(DAT_182d534a8 + 0xb8) + 8) = uVar5;
  if (DAT_182eb5d50 != 0) {
    uVar6 = (uint)(*(longlong *)(DAT_182d534a8 + 0xb8) + 8U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8);
    do {
      uVar4 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar4 == uVar2) {
        *puVar1 = uVar4 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (uVar4 != uVar2);
  }
LAB_1803cc011:
  if (*(int *)(DAT_182d534a8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  return *(undefined8 *)(*(longlong *)(DAT_182d534a8 + 0xb8) + 8);
}

