// Ghidra pseudocode; not original source or compilable C.
// ev_c1c084dffb5ffdaa7a9c9333db251b0a6ba6f9f87954733ebae53b8353febc58

longlong native_only_180759550__00000000(longlong *param_1,longlong param_2)

{
  code *pcVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  longlong lVar8;
  
  if (*(longlong *)(param_2 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d52e58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(param_2 + 0x38) == 0) {
      FUN_1803204f0(param_2);
    }
  }
  lVar2 = **(longlong **)(param_2 + 0x38);
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ebb9aa == '\0') {
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182ebb9aa = '\x01';
  }
  lVar8 = 0;
  lVar3 = lVar8;
  if (lVar2 != 0) {
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar2 = FUN_1803613f0(lVar2,1);
    lVar3 = FUN_1802c5ac0(lVar2 + 0x20);
  }
  lVar2 = DAT_182d52e58;
  if (DAT_182ebb9aa == '\0') {
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182ebb9aa = '\x01';
  }
  lVar4 = lVar8;
  if (lVar2 != 0) {
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar2 = FUN_1803613f0(lVar2,1);
    lVar4 = FUN_1802c5ac0(lVar2 + 0x20);
  }
  if (lVar3 == lVar4) {
    lVar2 = (**(code **)(*param_1 + 0x298))(param_1,0,*(undefined8 *)(*param_1 + 0x2a0));
  }
  else {
    if (param_1[2] == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    pcVar1 = *(code **)(*param_1 + 0x298);
    if (*(char *)(param_1[2] + 0x4a) == '\0') {
      (*pcVar1)(param_1,1);
      uVar5 = **(undefined8 **)(param_2 + 0x38);
      if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar2 = FUN_181638ed0(uVar5,0);
    }
    else {
      lVar2 = (*pcVar1)(param_1,0,*(undefined8 *)(*param_1 + 0x2a0));
      uVar5 = **(undefined8 **)(param_2 + 0x38);
      if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar3 = FUN_181638ed0(uVar5,0);
      if (lVar2 != lVar3) {
        uVar5 = thunk_FUN_1802f2810(&DAT_182d531f8);
        uVar5 = FUN_18031d8c0(uVar5,5);
        FUN_1800039f0(uVar5);
        uVar6 = thunk_FUN_1802f2810(0x182d31dc0);
        FUN_180002cd0(uVar5,0,uVar6);
        uVar6 = FUN_180003850(*(undefined8 *)(param_2 + 0x38),0);
        uVar7 = thunk_FUN_1802f2810(&DAT_182d535d8);
        FUN_1800039e0(uVar7);
        lVar4 = FUN_181638ed0(uVar6,0);
        lVar3 = lVar8;
        if (lVar4 != 0) {
          FUN_1800039f0(lVar4);
          lVar3 = FUN_180002bf0(3,lVar4);
        }
        FUN_1800039f0(uVar5);
        FUN_180002cd0(uVar5,1,lVar3);
        FUN_1800039f0(uVar5);
        uVar6 = thunk_FUN_1802f2810(0x182d31dd8);
        FUN_180002cd0(uVar5,2,uVar6);
        if (lVar2 != 0) {
          FUN_1800039f0(lVar2);
          lVar8 = FUN_180002bf0(3,lVar2);
        }
        FUN_1800039f0(uVar5);
        FUN_180002cd0(uVar5,3,lVar8);
        FUN_1800039f0(uVar5);
        uVar6 = thunk_FUN_1802f2810(&DAT_182d31dd0);
        FUN_180002cd0(uVar5,4,uVar6);
        uVar5 = System_String__Concat__0600021e(uVar5,0);
        uVar6 = thunk_FUN_1802f2810(&DAT_182d533c8);
        uVar6 = thunk_FUN_1802c43a0(uVar6);
        FUN_18161a330(uVar6,uVar5,0);
                    /* WARNING: Subroutine does not return */
        FUN_18031da90(uVar6,param_2);
      }
    }
  }
  return lVar2;
}

