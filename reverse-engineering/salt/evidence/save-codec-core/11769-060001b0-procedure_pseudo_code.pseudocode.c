// Ghidra pseudocode; not original source or compilable C.
// ev_3cf90f22ff8b22b2e0f1834a386bc4e98432c45f2a5a2da1c147d6cbeb821237

undefined8 ES3Settings__get_defaultSettings__060001b0(void)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint uVar5;
  
  if (DAT_182eb7551 == '\0') {
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182eb7551 = '\x01';
  }
  if (*(int *)(DAT_182d534a8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (**(longlong **)(DAT_182d534a8 + 0xb8) == 0) {
    if (*(int *)(DAT_182d534a8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar4 = ES3Settings__get_defaultSettingsScriptableObject__060001af(0);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182ec12f4 == '\0') {
      FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      DAT_182ec12f4 = '\x01';
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
    if (lVar4 != 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(longlong *)(lVar4 + 0x10) != 0) {
        if (*(int *)(DAT_182d534a8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar4 = ES3Settings__get_defaultSettingsScriptableObject__060001af(0);
        if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        **(undefined8 **)(DAT_182d534a8 + 0xb8) = *(undefined8 *)(lVar4 + 0x18);
        if (DAT_182eb5d50 != 0) {
          uVar5 = (uint)(*(ulonglong *)(DAT_182d534a8 + 0xb8) >> 0xc);
          puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8);
          do {
            uVar3 = *puVar1;
            LOCK();
            uVar2 = *puVar1;
            if (uVar3 == uVar2) {
              *puVar1 = uVar3 | 1L << (uVar5 & 0x3f);
            }
            UNLOCK();
          } while (uVar3 != uVar2);
        }
      }
    }
  }
  if (*(int *)(DAT_182d534a8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  return **(undefined8 **)(DAT_182d534a8 + 0xb8);
}

