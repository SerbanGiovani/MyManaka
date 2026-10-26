// Ghidra pseudocode; not original source or compilable C.
// ev_bec851ea14fc439cae2512f5f94da74493f53f53f2852ee318828505c45b693e

void ES3Internal_AESEncryptionAlgorithm__Decrypt__06000607
               (undefined8 param_1,longlong *param_2,longlong *param_3,undefined8 param_4,
               undefined4 param_5)

{
  int iVar1;
  undefined8 uVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  ulonglong uVar6;
  longlong *plStack_98;
  longlong lStack_90;
  longlong *plStack_88;
  undefined8 uStack_80;
  longlong **pplStack_78;
  undefined8 uStack_70;
  longlong *plStack_68;
  undefined8 uStack_60;
  longlong **pplStack_58;
  longlong *plStack_50;
  
  plStack_50 = param_3;
  if (cRam0000000182eb804a == '\0') {
    FUN_1802f2810(0x182d6ab48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53428);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6ab40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53498);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6ab38);
    LOCK();
    UNLOCK();
    cRam0000000182eb804a = '\x01';
  }
  lStack_90 = 0;
  plStack_88 = (longlong *)0x0;
  if (*(int *)(lRam0000000182d6ab48 + 0xe0) == 0) {
    FUN_18035c820();
  }
  plStack_98 = (longlong *)FUN_18149d110(0);
  uStack_60 = 0;
  pplStack_58 = &plStack_98;
  uVar2 = FUN_1802c36c0(DAT_182d53428,0x10);
  if (param_2 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  (**(code **)(*param_2 + 0x2e8))(param_2,uVar2,0,0x10,*(undefined8 *)(*param_2 + 0x2f0));
  if (plStack_98 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  (**(code **)(*plStack_98 + 0x1d8))(plStack_98,uVar2,*(undefined8 *)(*plStack_98 + 0x1e0));
  if (plStack_98 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uVar2 = (**(code **)(*plStack_98 + 0x1c8))(plStack_98,*(undefined8 *)(*plStack_98 + 0x1d0));
  plVar3 = (longlong *)FUN_1802c43a0(uRam0000000182d6ab38);
  uVar6 = 0;
  FUN_181495490(plVar3,param_4,uVar2,100,0);
  plVar5 = plStack_98;
  if (plVar3 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uVar2 = (**(code **)(*plVar3 + 0x188))(plVar3,0x10,*(undefined8 *)(*plVar3 + 400));
  if (plVar5 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  (**(code **)(*plVar5 + 0x1f8))(plVar5,uVar2,*(undefined8 *)(*plVar5 + 0x200));
  if (plStack_98 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  lVar4 = (**(code **)(*plStack_98 + 0x298))(plStack_98,*(undefined8 *)(*plStack_98 + 0x2a0));
  uStack_70 = 0;
  plStack_68 = &lStack_90;
  lStack_90 = lVar4;
  plVar5 = (longlong *)FUN_1802c43a0(uRam0000000182d6ab40);
  FUN_181496410(plVar5,param_2,lVar4,0,uVar6 & 0xffffffffffffff00,0);
  uStack_80 = 0;
  pplStack_78 = &plStack_88;
  plStack_88 = plVar5;
  if (cRam0000000182eb8046 == '\0') {
    FUN_1802f2810(&DAT_182d53428);
    LOCK();
    UNLOCK();
    cRam0000000182eb8046 = '\x01';
  }
  uVar2 = FUN_1802c36c0(DAT_182d53428,param_5);
  if (plVar5 != (longlong *)0x0) {
    while( true ) {
      iVar1 = (**(code **)(*plVar5 + 0x2e8))
                        (plVar5,uVar2,0,param_5,*(undefined8 *)(*plVar5 + 0x2f0));
      if (iVar1 < 1) break;
      if (param_3 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      (**(code **)(*param_3 + 0x318))(param_3,uVar2,0,iVar1,*(undefined8 *)(*param_3 + 800));
    }
    if (plStack_88 != (longlong *)0x0) {
      FUN_180002c20(0,DAT_182d53498,plStack_88,iVar1);
    }
    if (lStack_90 != 0) {
      FUN_180002c20(0,DAT_182d53498,lStack_90);
    }
    if (plStack_98 != (longlong *)0x0) {
      FUN_180002c20(0,DAT_182d53498,plStack_98);
    }
    if (param_3 != (longlong *)0x0) {
      (**(code **)(*param_3 + 0x1f8))(param_3,0,*(undefined8 *)(*param_3 + 0x200));
      return;
    }
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

