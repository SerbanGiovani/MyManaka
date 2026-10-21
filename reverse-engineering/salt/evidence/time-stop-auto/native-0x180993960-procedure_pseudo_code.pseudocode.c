// Ghidra pseudocode; not original source or compilable C.
// ev_c67e26ae7925db9dbadd9332856d3cd0d0a62c105c494420a89c73eedd778191

void native_only_180993960__00000000(undefined8 param_1,longlong param_2)

{
  char cVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  longlong *local_res8;
  longlong *local_res10;
  
  if (*(longlong *)(param_2 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d36a90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d36a70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d36a88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d36a80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f9b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d36a78);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(param_2 + 0x38) == 0) {
      FUN_1803204f0(param_2);
    }
  }
  local_res10 = (longlong *)0x0;
  local_res8 = (longlong *)0x0;
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d583a0);
  }
  lVar3 = *(longlong *)(*(longlong *)(DAT_182d583a0 + 0xb8) + 8);
  if (lVar3 == 0) goto LAB_180993d1d;
  cVar1 = FUN_180ebb4c0(lVar3,param_1,&local_res10,DAT_182d36a80);
  if (cVar1 == '\0') {
    return;
  }
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d583a0);
  }
  lVar3 = **(longlong **)(DAT_182d583a0 + 0xb8);
  uVar2 = *(undefined8 *)(*(longlong *)(param_2 + 0x38) + 8);
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar2 = FUN_181638ed0(uVar2,0);
  if (lVar3 == 0) goto LAB_180993d1d;
  cVar1 = FUN_180ebb4c0(lVar3,uVar2,&local_res8,DAT_182d5f9b8);
  plVar6 = local_res10;
  plVar5 = local_res8;
  if (cVar1 != '\0') {
    if (DAT_182ebbb86 == '\0') {
      FUN_1802f2810(&DAT_182d535d8);
      LOCK();
      UNLOCK();
      DAT_182ebbb86 = '\x01';
    }
    if (plVar5 == (longlong *)0x0) {
LAB_180993bab:
      local_res8 = (longlong *)0x0;
      if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d583a0);
      }
      lVar3 = **(longlong **)(DAT_182d583a0 + 0xb8);
      uVar2 = *(undefined8 *)(*(longlong *)(param_2 + 0x38) + 8);
      if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar2 = FUN_181638ed0(uVar2,0);
      if (lVar3 == 0) goto LAB_180993d1d;
      FUN_180ebb270(lVar3,uVar2,DAT_182d36a88);
    }
    else {
      if (plVar6 != (longlong *)0x0) {
        lVar3 = FUN_1802c5ac0(*plVar5 + 0x20);
        lVar4 = FUN_1802c5ac0(*plVar6 + 0x20);
        if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (lVar3 != lVar4) {
          FUN_1800039f0(plVar5);
          uVar2 = FUN_181636e20(plVar5,0);
          FUN_1800039f0(uVar2);
          uVar2 = FUN_180002bf0(0x19,uVar2);
          FUN_1800039f0(plVar6);
          uVar7 = FUN_181636e20(plVar6,0);
          FUN_1800039f0(uVar7);
          uVar7 = FUN_180002bf0(0x19,uVar7);
          uVar8 = thunk_FUN_1802f2810(&DAT_182d29b90);
          uVar2 = System_String__Format__06000220(uVar8,uVar2,uVar7,0);
          uVar7 = thunk_FUN_1802f2810(&DAT_182d53468);
          uVar7 = thunk_FUN_1802c43a0(uVar7);
          FUN_1815c6590(uVar7,uVar2,0);
          uVar2 = thunk_FUN_1802f2810(&DAT_182d29b50);
                    /* WARNING: Subroutine does not return */
          FUN_18031da90(uVar7,uVar2);
        }
        plVar5 = (longlong *)
                 (**(code **)(*plVar5 + 0x1e8))(plVar5,plVar6,*(undefined8 *)(*plVar5 + 0x1f0));
        if (plVar5 == (longlong *)0x0) goto LAB_180993bab;
      }
      uVar2 = DAT_182d36a90;
      plVar6 = (longlong *)FUN_1802c42e0(plVar5,DAT_182d36a90);
      if (plVar6 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031e210(plVar5,uVar2);
      }
      local_res8 = plVar6;
      if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d583a0);
      }
      lVar3 = **(longlong **)(DAT_182d583a0 + 0xb8);
      uVar2 = *(undefined8 *)(*(longlong *)(param_2 + 0x38) + 8);
      if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar2 = FUN_181638ed0(uVar2,0);
      if (lVar3 == 0) goto LAB_180993d1d;
      FUN_180eba640(lVar3,uVar2,local_res8,1,
                    *(undefined8 *)
                     (*(longlong *)(*(longlong *)(DAT_182d36a78 + 0x20) + 0xc0) + 0x100));
    }
  }
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d583a0);
  }
  lVar3 = *(longlong *)(*(longlong *)(DAT_182d583a0 + 0xb8) + 8);
  if (lVar3 != 0) {
    FUN_180ebb270(lVar3,param_1,DAT_182d36a70);
    return;
  }
LAB_180993d1d:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

