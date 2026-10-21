// Ghidra pseudocode; not original source or compilable C.
// ev_4b2097937dad0b0de2a19d203eb361401badf4f93412ce96a9a56081e25a848b

ulonglong ExposureUnnoticed2_ObjectUI_FadeOutPanel_WaitSceneLoadStarter___ctor__06001b56
                    (undefined8 param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  uint uVar9;
  ulonglong *puVar10;
  bool bVar11;
  
  if (cRam0000000182eb7d19 == '\0') {
    FUN_1802f2810(0x182d535b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d645e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d645d8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7d19 = '\x01';
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d645e0);
  FUN_1800078e0(uVar3,param_1,uRam0000000182d645d8);
  if (*(int *)(lRam0000000182d535b8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ec199d == '\0') {
    FUN_1802f2810(0x182d535b8,0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d645e0);
    LOCK();
    UNLOCK();
    cRam0000000182ec199d = '\x01';
  }
  if (*(int *)(lRam0000000182d535b8 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d535b8);
  }
  uVar8 = *(ulonglong *)(*(longlong *)(lRam0000000182d535b8 + 0xb8) + 8);
  do {
    lVar4 = FUN_1816791b0(uVar8,uVar3,0);
    uVar2 = uRam0000000182d645e0;
    if (lVar4 == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_1802c42e0(lVar4,uRam0000000182d645e0);
      if (uVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031e210(lVar4,uVar2);
      }
    }
    if (*(int *)(lRam0000000182d535b8 + 0xe0) == 0) {
      FUN_18035c820(lRam0000000182d535b8);
    }
    puVar10 = (ulonglong *)(*(longlong *)(lRam0000000182d535b8 + 0xb8) + 8);
    LOCK();
    uVar6 = *puVar10;
    bVar11 = uVar8 == uVar6;
    if (bVar11) {
      *puVar10 = uVar5;
      uVar6 = uVar8;
    }
    UNLOCK();
    uVar5 = uVar8;
    if (!bVar11) {
      uVar5 = uVar6;
    }
    if (DAT_182eb5d50 != 0) {
      uVar9 = (uint)((ulonglong)puVar10 >> 0xc);
      uVar7 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
        LOCK();
        uVar6 = *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
        bVar11 = uVar1 == uVar6;
        if (bVar11) {
          *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8) = uVar1 | 1L << (uVar9 & 0x3f);
          uVar6 = uVar1;
        }
        UNLOCK();
      } while (!bVar11);
    }
    bVar11 = uVar5 != uVar8;
    uVar8 = uVar5;
  } while (bVar11);
  return uVar6;
}

