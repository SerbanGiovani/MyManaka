// Ghidra pseudocode; not original source or compilable C.
// ev_2ec79f1cbfeae720ba13dcb73b4ac36dc6ba014e39629017fbd2b25bf64f51b8

undefined8 ES3Internal_ES3JSONReader__ReadKeyPrefix__060006a1(longlong *param_1,char param_2)

{
  char cVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  if (cRam0000000182eb80a6 == '\0') {
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d56288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d55f40);
    LOCK();
    UNLOCK();
    cRam0000000182eb80a6 = '\x01';
  }
  (**(code **)(*param_1 + 0x2e8))(param_1,*(undefined8 *)(*param_1 + 0x2f0));
  uVar4 = 0;
  lVar2 = (**(code **)(*param_1 + 0x288))(param_1,*(undefined8 *)(*param_1 + 0x290));
  if ((lVar2 == lRam0000000182d55f40) ||
     ((((uVar3 = uVar4, lVar2 != 0 && (lRam0000000182d55f40 != 0)) &&
       (*(int *)(lVar2 + 0x10) == *(int *)(lRam0000000182d55f40 + 0x10))) &&
      (cVar1 = FUN_181630ad0(lVar2 + 0x14,lRam0000000182d55f40 + 0x14,
                             (longlong)*(int *)(lVar2 + 0x10) * 2,0), uVar3 = 0, cVar1 != '\0')))) {
    uVar3 = (**(code **)(*param_1 + 600))(param_1,*(undefined8 *)(*param_1 + 0x260));
    if (param_2 == '\0') {
      if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar4 = ES3Internal_ES3Reflection__GetType__0600067c(uVar3,0);
    }
    lVar2 = (**(code **)(*param_1 + 0x288))(param_1,*(undefined8 *)(*param_1 + 0x290));
    uVar3 = uVar4;
  }
  if (lVar2 == DAT_182d56288) {
    return uVar3;
  }
  if (((lVar2 != 0) && (DAT_182d56288 != 0)) &&
     ((*(int *)(lVar2 + 0x10) == *(int *)(DAT_182d56288 + 0x10) &&
      (cVar1 = FUN_181630ad0(lVar2 + 0x14,DAT_182d56288 + 0x14,(longlong)*(int *)(lVar2 + 0x10) * 2,
                             0), cVar1 != '\0')))) {
    return uVar3;
  }
  uVar4 = thunk_FUN_1802f2810(0x182d6a530);
  uVar3 = thunk_FUN_1802f2810(0x182d6a528);
  uVar4 = System_String__Concat__0600021c(uVar3,lVar2,uVar4,0);
  uVar3 = thunk_FUN_1802f2810(&DAT_182d52678);
  uVar3 = thunk_FUN_1802c43a0(uVar3);
  FUN_1815df2d0(uVar3,uVar4,0);
  uVar4 = thunk_FUN_1802f2810(0x182d6a520);
                    /* WARNING: Subroutine does not return */
  FUN_18031da90(uVar3,uVar4);
}

