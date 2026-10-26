// Ghidra pseudocode; not original source or compilable C.
// ev_89c72caf2fad349e37c4e9faad9814f30b85b4b76da5428fc1615709f62766ba

longlong ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetDefaultDropDataDict__06001543(void)

{
  int iVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  int iVar9;
  
  if (cRam0000000182eb79a6 == '\0') {
    FUN_1802f2810(0x182d5dc38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dc30);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dc28);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5df78);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dc20);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dc18);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59f58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53498);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52f28);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    cRam0000000182eb79a6 = '\x01';
  }
  plVar5 = (longlong *)0x0;
  lVar3 = FUN_1802c43a0(uRam0000000182d5dc28);
  FUN_180e686d0(lVar3,uRam0000000182d5dc30);
  lVar4 = lRam0000000182d5dc20;
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ebb9aa == '\0') {
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182ebb9aa = '\x01';
  }
  if (lVar4 != 0) {
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar4 = FUN_1803613f0(lVar4,1);
    plVar5 = (longlong *)FUN_1802c5ac0(lVar4 + 0x20);
  }
  if (*(int *)(DAT_182d59f58 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ebba98 == '\0') {
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182ebba98 = '\x01';
  }
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (plVar5 == (longlong *)0x0) {
    uVar7 = thunk_FUN_1802f2810(&DAT_182d528c8);
    uVar7 = thunk_FUN_1802c43a0(uVar7);
    uVar8 = thunk_FUN_1802f2810(&DAT_182d27920);
    FUN_1815c6a10(uVar7,uVar8,0);
    uVar8 = thunk_FUN_1802f2810(&DAT_182d28d98);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar7,uVar8);
  }
  lVar4 = (**(code **)(*plVar5 + 0x898))(plVar5,*(undefined8 *)(*plVar5 + 0x8a0));
  if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  lVar4 = FUN_181645880(lVar4,0);
  while( true ) {
    if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    cVar2 = FUN_180002c20(0,DAT_182d52f28);
    if (cVar2 == '\0') {
      lVar4 = FUN_1802c42e0(lVar4,DAT_182d53498);
      if (lVar4 != 0) {
        FUN_180002c20(0,DAT_182d53498,lVar4);
      }
      return lVar3;
    }
    if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    plVar5 = (longlong *)FUN_180002c20(1,DAT_182d52f28);
    if (plVar5 == (longlong *)0x0) break;
    if (*(longlong *)(*plVar5 + 0x40) != *(longlong *)(lRam0000000182d5dc18 + 0x40)) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(plVar5);
    }
    iVar1 = (int)plVar5[2];
    lVar6 = FUN_1802c43a0(uRam0000000182d5df78);
    *(int *)(lVar6 + 0x34) = iVar1;
    if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    FUN_180e76960(lVar3,iVar1,lVar6,2,
                  *(undefined8 *)
                   (*(longlong *)(*(longlong *)(lRam0000000182d5dc38 + 0x20) + 0xc0) + 0x100));
    if (9999 < iVar1) {
      for (iVar9 = 1; iVar9 < 10; iVar9 = iVar9 + 1) {
        lVar6 = FUN_1802c43a0(uRam0000000182d5df78);
        *(int *)(lVar6 + 0x34) = iVar9 + iVar1;
        FUN_180e76960(lVar3,iVar9 + iVar1,lVar6,2,
                      *(undefined8 *)
                       (*(longlong *)(*(longlong *)(lRam0000000182d5dc38 + 0x20) + 0xc0) + 0x100));
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

