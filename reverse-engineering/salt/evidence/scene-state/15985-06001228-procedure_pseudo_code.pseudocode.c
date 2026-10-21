// Ghidra pseudocode; not original source or compilable C.
// ev_39caca6250f723bd6b43dc7e4cddc95e5e58867d0d9c7394e1db8bf8b65a06fc

void ExposureUnnoticed2_Master_Stage_MStage__CheckInitialize__06001228(void)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  uint uVar9;
  longlong *plVar10;
  bool bVar11;
  
  if (DAT_182eb7834 == '\0') {
    FUN_1802f2810(&DAT_182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c758);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c748);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c740);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c738);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c730);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c728);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d594e8);
    LOCK();
    UNLOCK();
    DAT_182eb7834 = '\x01';
  }
  if (*(int *)(DAT_182d594e8 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d594e8);
  }
  if (**(longlong **)(DAT_182d594e8 + 0xb8) != 0) {
    return;
  }
  uVar8 = FUN_1802c43a0(DAT_182d5c740);
  FUN_180e686d0(uVar8,DAT_182d5c748);
  if (*(int *)(DAT_182d594e8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  **(undefined8 **)(DAT_182d594e8 + 0xb8) = uVar8;
  if (DAT_182eb5d50 != 0) {
    uVar9 = (uint)(*(ulonglong *)(DAT_182d594e8 + 0xb8) >> 0xc);
    lVar1 = (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8;
    do {
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar11 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar11) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar3 | 1L << (uVar9 & 0x3f);
      }
      UNLOCK();
    } while (!bVar11);
  }
  uVar8 = FUN_1802c43a0(DAT_182d5c728);
  FUN_1811cf4f0(uVar8,DAT_182d5c730);
  *(undefined8 *)(*(longlong *)(DAT_182d594e8 + 0xb8) + 8) = uVar8;
  if (DAT_182eb5d50 != 0) {
    uVar9 = (uint)(*(longlong *)(DAT_182d594e8 + 0xb8) + 8U >> 0xc);
    lVar1 = (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8;
    do {
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar11 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar11) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar3 | 1L << (uVar9 & 0x3f);
      }
      UNLOCK();
    } while (!bVar11);
  }
  if ((**(longlong **)(DAT_182d58238 + 0xb8) != 0) &&
     (lVar1 = *(longlong *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x20), lVar1 != 0)) {
    lVar1 = *(longlong *)(lVar1 + 0x18);
    uVar9 = 0;
    if (lVar1 != 0) {
      plVar10 = (longlong *)(lVar1 + 0x20);
      while( true ) {
        if (*(int *)(lVar1 + 0x18) <= (int)uVar9) {
          return;
        }
        if (*(uint *)(lVar1 + 0x18) <= uVar9) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dae0();
        }
        lVar4 = *plVar10;
        if (*(int *)(DAT_182d594e8 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d594e8);
        }
        if ((lVar4 == 0) || (**(longlong **)(DAT_182d594e8 + 0xb8) == 0)) break;
        FUN_180e76960(**(longlong **)(DAT_182d594e8 + 0xb8),*(undefined4 *)(lVar4 + 0x18),lVar4,2,
                      *(undefined8 *)
                       (*(longlong *)(*(longlong *)(DAT_182d5c758 + 0x20) + 0xc0) + 0x100));
        lVar7 = DAT_182d5c738;
        lVar5 = *(longlong *)(*(longlong *)(DAT_182d594e8 + 0xb8) + 8);
        if (lVar5 == 0) break;
        *(int *)(lVar5 + 0x1c) = *(int *)(lVar5 + 0x1c) + 1;
        lVar6 = *(longlong *)(lVar5 + 0x10);
        if (lVar6 == 0) break;
        uVar2 = *(uint *)(lVar5 + 0x18);
        if (uVar2 < *(uint *)(lVar6 + 0x18)) {
          *(uint *)(lVar5 + 0x18) = uVar2 + 1;
          FUN_180002cd0(lVar6,(longlong)(int)uVar2,lVar4);
          uVar9 = uVar9 + 1;
          plVar10 = plVar10 + 1;
        }
        else {
          FUN_1812741c0(lVar5,lVar4,
                        *(undefined8 *)(*(longlong *)(*(longlong *)(lVar7 + 0x20) + 0xc0) + 0x70));
          uVar9 = uVar9 + 1;
          plVar10 = plVar10 + 1;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

