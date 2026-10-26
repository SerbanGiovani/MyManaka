// Ghidra pseudocode; not original source or compilable C.
// ev_eb4579081a0420ee27586c789119f7216a5c2186ee682d3789cc40b412d67735

/* WARNING: Removing unreachable block (ram,0x0001805a5c2b) */

void ES3Internal_ES3TypeMgr__Init__060006ee(void)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  char cVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  uint uVar9;
  
  if (DAT_182eb80be == '\0') {
    FUN_1802f2810(&DAT_182d6a188);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a1c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a180);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a178);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52ec0);
    LOCK();
    UNLOCK();
    DAT_182eb80be = '\x01';
  }
  if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d52ec0);
  }
  lVar3 = **(longlong **)(DAT_182d52ec0 + 0xb8);
  if (lVar3 == 0) {
    uVar7 = thunk_FUN_1802f2810(&DAT_182d528c8);
    uVar7 = thunk_FUN_1802c43a0(uVar7);
    uVar8 = thunk_FUN_1802f2810(&DAT_182d3c3d0);
    FUN_1815c6a10(uVar7,uVar8,0);
    uVar8 = thunk_FUN_1802f2810(&DAT_182d2acd0);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar7,uVar8);
  }
  cVar6 = FUN_1802f51a0(lVar3,0xffffffff);
  uVar7 = FUN_1802c43a0(DAT_182d6a180);
  FUN_180e95b10(uVar7,DAT_182d6a188);
  if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d52ec0);
  }
  *(undefined8 *)(*(longlong *)(DAT_182d52ec0 + 0xb8) + 8) = uVar7;
  if (DAT_182eb5d50 != 0) {
    uVar9 = (uint)(*(longlong *)(DAT_182d52ec0 + 0xb8) + 8U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8);
    do {
      uVar4 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar4 == uVar2) {
        *puVar1 = uVar4 | 1L << (ulonglong)(uVar9 & 0x3f);
      }
      UNLOCK();
    } while (uVar4 != uVar2);
  }
  if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
    FUN_18035c820();
  }
  FUN_18075b990(DAT_182d6a178);
  if (*(longlong *)(*(longlong *)(DAT_182d52ec0 + 0xb8) + 8) != 0) {
    if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar5 = *(longlong *)(*(longlong *)(DAT_182d52ec0 + 0xb8) + 8);
    if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(int *)(lVar5 + 0x20) != *(int *)(lVar5 + 0x28)) {
      if (cVar6 != '\0') {
        if (lVar3 == 0) {
          uVar7 = FUN_1802cd970(&DAT_1829cffe0);
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar7,0);
        }
        FUN_1802f5480();
      }
      return;
    }
  }
  uVar7 = thunk_FUN_1802f2810(&DAT_182d6a1c0);
  uVar7 = thunk_FUN_1802c43a0(uVar7);
  uVar8 = thunk_FUN_1802f2810(&DAT_182d6a170);
  FUN_18166e8e0(uVar7,uVar8,0);
  uVar8 = thunk_FUN_1802f2810(&DAT_182d6a168);
                    /* WARNING: Subroutine does not return */
  FUN_18031da90(uVar7,uVar8);
}

