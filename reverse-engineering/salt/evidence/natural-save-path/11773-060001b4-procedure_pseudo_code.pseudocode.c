// Ghidra pseudocode; not original source or compilable C.
// ev_f79e37def367581c4e244c00d4bbf13d98bd7d2d70ea4185cc8cd51ad4e36814

undefined8 ES3Settings__get_FullPath__060001b4(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  uint uVar9;
  longlong *plVar10;
  undefined1 local_38 [32];
  
  if (DAT_182eb7554 == '\0') {
    FUN_1802f2810(&DAT_182d53a48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53488);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52788);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52780);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52e20);
    LOCK();
    UNLOCK();
    DAT_182eb7554 = '\x01';
  }
  if (*(longlong *)(param_1 + 0x18) == 0) {
    uVar6 = thunk_FUN_1802f2810(&DAT_182d52778);
    uVar6 = thunk_FUN_1802c43a0(uVar6);
    uVar7 = thunk_FUN_1802f2810(&DAT_182d52770);
    FUN_1815c4d30(uVar6,uVar7,0);
    uVar7 = thunk_FUN_1802f2810(&DAT_182d52768);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar6,uVar7);
  }
  lVar5 = *(longlong *)(param_1 + 0x18);
  if (*(int *)(DAT_182d534a8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (((0 < *(int *)(lVar5 + 0x10)) &&
      ((*(short *)(lVar5 + 0x14) == 0x2f || (*(short *)(lVar5 + 0x14) == 0x5c)))) ||
     ((1 < *(int *)(lVar5 + 0x10) && (*(short *)(lVar5 + 0x16) == 0x3a)))) {
    return *(undefined8 *)(param_1 + 0x18);
  }
  iVar4 = ES3Settings__get_location__060001b2(param_1,0);
  if (iVar4 == 0) {
    if (*(int *)(param_1 + 0x30) == 0) {
      if (*(int *)(DAT_182d53488 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar6 = System_String__Concat__0600021c
                        (**(undefined8 **)(DAT_182d53488 + 0xb8),DAT_182d52780,
                         *(undefined8 *)(param_1 + 0x18),0);
      return uVar6;
    }
    if (*(int *)(param_1 + 0x30) == 1) {
      if (*(int *)(DAT_182d53a48 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar6 = UnityEngine_Application__get_dataPath__06000152(0);
      uVar6 = System_String__Concat__0600021c(uVar6,DAT_182d52780,*(undefined8 *)(param_1 + 0x18),0)
      ;
      return uVar6;
    }
    uVar6 = thunk_FUN_1802f2810(&DAT_182d52760);
    FUN_180003680(local_38,uVar6,param_1 + 0x30);
    uVar6 = FUN_1816580e0(local_38,0);
    uVar7 = thunk_FUN_1802f2810(&DAT_182d52758);
    uVar8 = thunk_FUN_1802f2810(&DAT_182d52750);
    uVar6 = System_String__Concat__0600021c(uVar8,uVar6,uVar7,0);
    uVar7 = thunk_FUN_1802f2810(&DAT_182d52748);
    uVar7 = thunk_FUN_1802c43a0(uVar7);
    FUN_18161d380(uVar7,uVar6,0);
    uVar6 = thunk_FUN_1802f2810(&DAT_182d52768);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar7,uVar6);
  }
  iVar4 = ES3Settings__get_location__060001b2(param_1,0);
  uVar6 = *(undefined8 *)(param_1 + 0x18);
  if (iVar4 != 3) {
    return uVar6;
  }
  if (*(int *)(DAT_182d52788 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar5 = System_IO_Path__GetExtension__06002bc4(uVar6,0);
  if (*(int *)(DAT_182d534a8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar9 = 0;
  lVar2 = *(longlong *)(*(longlong *)(DAT_182d534a8 + 0xb8) + 0x18);
  if (lVar2 != 0) {
    uVar1 = *(uint *)(lVar2 + 0x18);
    plVar10 = (longlong *)(lVar2 + 0x20);
    while( true ) {
      if ((int)uVar1 <= (int)uVar9) {
        uVar6 = *(undefined8 *)(param_1 + 0x18);
        uVar7 = thunk_FUN_1802f2810(&DAT_182d52a18);
        uVar8 = thunk_FUN_1802f2810(&DAT_182d52740);
        uVar6 = System_String__Concat__0600021c(uVar8,uVar6,uVar7,0);
        uVar7 = thunk_FUN_1802f2810(&DAT_182d53468);
        uVar7 = thunk_FUN_1802c43a0(uVar7);
        FUN_1815c6590(uVar7,uVar6,0);
        uVar6 = thunk_FUN_1802f2810(&DAT_182d52768);
                    /* WARNING: Subroutine does not return */
        FUN_18031da90(uVar7,uVar6);
      }
      if (uVar1 <= uVar9) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dae0();
      }
      lVar2 = *plVar10;
      if (lVar5 == lVar2) break;
      if (((lVar5 != 0) && (lVar2 != 0)) && (*(int *)(lVar5 + 0x10) == *(int *)(lVar2 + 0x10))) {
        cVar3 = FUN_181630ad0(lVar5 + 0x14,lVar2 + 0x14,(longlong)*(int *)(lVar5 + 0x10) * 2);
        if (cVar3 != '\0') break;
      }
      uVar9 = uVar9 + 1;
      plVar10 = plVar10 + 1;
    }
    if (*(longlong *)(param_1 + 0x18) != 0) {
      uVar6 = System_String__Replace__06000236(*(longlong *)(param_1 + 0x18),lVar5,DAT_182d52e20,0);
      return uVar6;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

