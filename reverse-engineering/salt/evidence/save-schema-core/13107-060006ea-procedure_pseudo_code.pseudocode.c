// Ghidra pseudocode; not original source or compilable C.
// ev_469f29d28073d1a9b64230caef8129ede24dcc3da8db9a764a216b1780ff786e

undefined8 ES3Internal_ES3TypeMgr__GetOrCreateES3Type__060006ea(longlong param_1,undefined1 param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  char cVar4;
  longlong lVar5;
  undefined8 uVar6;
  uint uVar7;
  
  if (DAT_182eb80ba == '\0') {
    FUN_1802f2810(&DAT_182d6a2c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52ec0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52e58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182eb80ba = '\x01';
  }
  if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d52ec0);
  }
  if (*(longlong *)(*(longlong *)(DAT_182d52ec0 + 0xb8) + 8) == 0) {
    if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d52ec0);
    }
    ES3Internal_ES3TypeMgr__Init__060006ee(0);
  }
  lVar5 = DAT_182d52e58;
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ebb9aa == '\0') {
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182ebb9aa = '\x01';
  }
  if (lVar5 == 0) {
    lVar5 = 0;
  }
  else {
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar5 = FUN_1803613f0(lVar5,1);
    lVar5 = FUN_1802c5ac0(lVar5 + 0x20);
  }
  if (param_1 != lVar5) {
    if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d52ec0);
    }
    if (*(longlong *)(*(longlong *)(DAT_182d52ec0 + 0xb8) + 0x10) != 0) {
      if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d52ec0);
      }
      lVar5 = *(longlong *)(*(longlong *)(DAT_182d52ec0 + 0xb8) + 0x10);
      if (lVar5 == 0) goto LAB_1805a492f;
      lVar5 = *(longlong *)(lVar5 + 0x18);
      if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (lVar5 == param_1) {
        if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d52ec0);
        }
        lVar5 = *(longlong *)(DAT_182d52ec0 + 0xb8);
        goto LAB_1805a4800;
      }
    }
  }
  if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d52ec0);
  }
  lVar5 = *(longlong *)(*(longlong *)(DAT_182d52ec0 + 0xb8) + 8);
  if (lVar5 != 0) {
    cVar4 = FUN_180ebb4c0(lVar5,param_1,*(longlong *)(DAT_182d52ec0 + 0xb8) + 0x10,DAT_182d6a2c8);
    if (cVar4 == '\0') {
      if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar6 = ES3Internal_ES3TypeMgr__CreateES3Type__060006ed(param_1,param_2,0);
      *(undefined8 *)(*(longlong *)(DAT_182d52ec0 + 0xb8) + 0x10) = uVar6;
      if (DAT_182eb5d50 != 0) {
        uVar7 = (uint)(*(longlong *)(DAT_182d52ec0 + 0xb8) + 0x10U >> 0xc);
        puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8);
        do {
          uVar3 = *puVar1;
          LOCK();
          uVar2 = *puVar1;
          if (uVar3 == uVar2) {
            *puVar1 = uVar3 | 1L << (uVar7 & 0x3f);
          }
          UNLOCK();
        } while (uVar3 != uVar2);
      }
      return uVar6;
    }
    if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d52ec0);
    }
    lVar5 = *(longlong *)(DAT_182d52ec0 + 0xb8);
LAB_1805a4800:
    return *(undefined8 *)(lVar5 + 0x10);
  }
LAB_1805a492f:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

