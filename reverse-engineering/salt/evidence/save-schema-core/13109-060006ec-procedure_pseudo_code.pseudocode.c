// Ghidra pseudocode; not original source or compilable C.
// ev_c91be5170b3fb894bd2e3d95242c336ce3da6eb5600db26d62fa6fb93455bdaa

/* WARNING: Removing unreachable block (ram,0x0001805a4c82) */

void ES3Internal_ES3TypeMgr__Add__060006ec(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  char cVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  if (DAT_182eb80bc == '\0') {
    FUN_1802f2810(&DAT_182d6a2c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52ec0);
    LOCK();
    UNLOCK();
    DAT_182eb80bc = '\x01';
  }
  if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (*(longlong *)(*(longlong *)(DAT_182d52ec0 + 0xb8) + 8) == 0) {
    if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
      FUN_18035c820();
    }
    ES3Internal_ES3TypeMgr__Init__060006ee(0);
  }
  if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar3 = ES3Internal_ES3TypeMgr__GetES3Type__060006eb(param_1,0);
  if (lVar3 != 0) {
    if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(int *)(param_2 + 0x2c) < *(int *)(lVar3 + 0x2c)) {
      return;
    }
  }
  if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d52ec0);
  }
  lVar3 = **(longlong **)(DAT_182d52ec0 + 0xb8);
  if (lVar3 == 0) {
    uVar4 = thunk_FUN_1802f2810(&DAT_182d528c8);
    uVar4 = thunk_FUN_1802c43a0(uVar4);
    uVar5 = thunk_FUN_1802f2810(&DAT_182d3c3d0);
    FUN_1815c6a10(uVar4,uVar5,0);
    uVar5 = thunk_FUN_1802f2810(&DAT_182d2acd0);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar4,uVar5);
  }
  cVar2 = FUN_1802f51a0(lVar3,0xffffffff);
  if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d52ec0);
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d52ec0 + 0xb8) + 8);
  if (lVar1 != 0) {
    FUN_180eba640(lVar1,param_1,param_2,1,
                  *(undefined8 *)(*(longlong *)(*(longlong *)(DAT_182d6a2c0 + 0x20) + 0xc0) + 0x100)
                 );
    if (cVar2 != '\0') {
      if (lVar3 == 0) {
        uVar4 = FUN_1802cd970(&DAT_1829cffe0);
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar4,0);
      }
      FUN_1802f5480();
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

