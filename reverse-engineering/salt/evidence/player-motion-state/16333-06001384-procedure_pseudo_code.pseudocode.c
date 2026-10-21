// Ghidra pseudocode; not original source or compilable C.
// ev_28da2d6264f09f659bb705cbcbd4cfe5ab39228aa4969a94a16e367d59aa6e5a

void ExposureUnnoticed2_Master_Action_MAction__CheckInitialize__06001384(void)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong *plVar7;
  uint uVar8;
  
  if (cRam0000000182eb78a1 == '\0') {
    FUN_1802f2810(&DAT_182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c0e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c0d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c0d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c0c8);
    LOCK();
    UNLOCK();
    cRam0000000182eb78a1 = '\x01';
  }
  if (**(longlong **)(lRam0000000182d5c0c8 + 0xb8) != 0) {
    return;
  }
  uVar6 = FUN_1802c43a0(uRam0000000182d5c0d0);
  FUN_180e686d0(uVar6,uRam0000000182d5c0d8);
  **(undefined8 **)(lRam0000000182d5c0c8 + 0xb8) = uVar6;
  if (DAT_182eb5d50 != 0) {
    uVar8 = (uint)(*(ulonglong *)(lRam0000000182d5c0c8 + 0xb8) >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar3 == uVar2) {
        *puVar1 = uVar3 | 1L << (uVar8 & 0x3f);
      }
      UNLOCK();
    } while (uVar3 != uVar2);
  }
  if ((**(longlong **)(DAT_182d58238 + 0xb8) != 0) &&
     (lVar4 = *(longlong *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x50), lVar4 != 0)) {
    lVar4 = *(longlong *)(lVar4 + 0x18);
    uVar8 = 0;
    if (lVar4 != 0) {
      plVar7 = (longlong *)(lVar4 + 0x20);
      while( true ) {
        if (*(int *)(lVar4 + 0x18) <= (int)uVar8) {
          return;
        }
        if (*(uint *)(lVar4 + 0x18) <= uVar8) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dae0();
        }
        lVar5 = *plVar7;
        if ((lVar5 == 0) || (**(longlong **)(lRam0000000182d5c0c8 + 0xb8) == 0)) break;
        FUN_180e76960(**(longlong **)(lRam0000000182d5c0c8 + 0xb8),*(undefined4 *)(lVar5 + 0x18),
                      lVar5,2,*(undefined8 *)
                               (*(longlong *)(*(longlong *)(lRam0000000182d5c0e0 + 0x20) + 0xc0) +
                               0x100));
        uVar8 = uVar8 + 1;
        plVar7 = plVar7 + 1;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

