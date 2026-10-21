// Ghidra pseudocode; not original source or compilable C.
// ev_c3dff568e7b51c6d5a7f3c5158c245082e1a9217c591b9e6561747545c716463

void ExposureUnnoticed2_Master_Hair_MHair__CheckInitialize__0600128e(void)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong *plVar7;
  uint uVar8;
  
  if (cRam0000000182eb7869 == '\0') {
    FUN_1802f2810(0x182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c388);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c380);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c370);
    LOCK();
    UNLOCK();
    cRam0000000182eb7869 = '\x01';
  }
  if (**(longlong **)(lRam0000000182d5c370 + 0xb8) != 0) {
    return;
  }
  uVar6 = FUN_1802c43a0(uRam0000000182d5c378);
  FUN_180e686d0(uVar6,uRam0000000182d5c380);
  **(undefined8 **)(lRam0000000182d5c370 + 0xb8) = uVar6;
  if (DAT_182eb5d50 != 0) {
    uVar8 = (uint)(*(ulonglong *)(lRam0000000182d5c370 + 0xb8) >> 0xc);
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
  if ((**(longlong **)(lRam0000000182d58238 + 0xb8) != 0) &&
     (lVar4 = *(longlong *)(**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x68), lVar4 != 0)) {
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
        if ((lVar5 == 0) || (**(longlong **)(lRam0000000182d5c370 + 0xb8) == 0)) break;
        FUN_180e76960(**(longlong **)(lRam0000000182d5c370 + 0xb8),*(undefined4 *)(lVar5 + 0x18),
                      lVar5,2,*(undefined8 *)
                               (*(longlong *)(*(longlong *)(lRam0000000182d5c388 + 0x20) + 0xc0) +
                               0x100));
        uVar8 = uVar8 + 1;
        plVar7 = plVar7 + 1;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

