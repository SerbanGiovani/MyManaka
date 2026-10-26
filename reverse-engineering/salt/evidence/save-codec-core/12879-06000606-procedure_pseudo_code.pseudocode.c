// Ghidra pseudocode; not original source or compilable C.
// ev_2809a6e427e2ce0238f179aa1872086ba7944fc8bb7476742b94e6427ae36e05

void ES3Internal_AESEncryptionAlgorithm__Encrypt__06000606
               (undefined8 param_1,longlong *param_2,longlong *param_3,undefined8 param_4,
               undefined4 param_5)

{
  int iVar1;
  undefined8 uVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plStackX_10;
  ulonglong uVar6;
  longlong lStack_88;
  longlong *aplStack_80 [4];
  undefined8 uStack_60;
  longlong **pplStack_58;
  undefined8 uStack_50;
  longlong *plStack_48;
  undefined8 uStack_40;
  longlong **pplStack_38;
  
  if (cRam0000000182eb8049 == '\0') {
    FUN_1802f2810(0x182d6ab48);
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
    cRam0000000182eb8049 = '\x01';
  }
  lStack_88 = 0;
  aplStack_80[0] = (longlong *)0x0;
  if (param_2 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  (**(code **)(*param_2 + 0x1f8))(param_2,0,*(undefined8 *)(*param_2 + 0x200));
  if (*(int *)(lRam0000000182d6ab48 + 0xe0) == 0) {
    FUN_18035c820();
  }
  plStackX_10 = (longlong *)FUN_18149d110(0);
  uStack_40 = 0;
  pplStack_38 = &plStackX_10;
  if (plStackX_10 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  (**(code **)(*plStackX_10 + 0x248))(plStackX_10,1,*(undefined8 *)(*plStackX_10 + 0x250));
  if (plStackX_10 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  (**(code **)(*plStackX_10 + 0x268))(plStackX_10,2,*(undefined8 *)(*plStackX_10 + 0x270));
  if (plStackX_10 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  (**(code **)(*plStackX_10 + 0x2c8))(plStackX_10,*(undefined8 *)(*plStackX_10 + 0x2d0));
  if (plStackX_10 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uVar2 = (**(code **)(*plStackX_10 + 0x1c8))(plStackX_10,*(undefined8 *)(*plStackX_10 + 0x1d0));
  plVar3 = (longlong *)FUN_1802c43a0(uRam0000000182d6ab38);
  FUN_181495490(plVar3,param_4,uVar2,100,0);
  plVar5 = plStackX_10;
  if (plVar3 != (longlong *)0x0) {
    uVar2 = (**(code **)(*plVar3 + 0x188))(plVar3,0x10,*(undefined8 *)(*plVar3 + 400));
    if (plVar5 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    (**(code **)(*plVar5 + 0x1f8))(plVar5,uVar2,*(undefined8 *)(*plVar5 + 0x200));
    if (plStackX_10 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    uVar2 = (**(code **)(*plStackX_10 + 0x1c8))(plStackX_10,*(undefined8 *)(*plStackX_10 + 0x1d0));
    if (param_3 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    uVar6 = *(ulonglong *)(*param_3 + 800);
    (**(code **)(*param_3 + 0x318))(param_3,uVar2,0,0x10,uVar6);
    if (plStackX_10 != (longlong *)0x0) {
      lVar4 = (**(code **)(*plStackX_10 + 0x278))(plStackX_10,*(undefined8 *)(*plStackX_10 + 0x280))
      ;
      uStack_50 = 0;
      plStack_48 = &lStack_88;
      lStack_88 = lVar4;
      plVar5 = (longlong *)FUN_1802c43a0(uRam0000000182d6ab40);
      FUN_181496410(plVar5,param_3,lVar4,1,uVar6 & 0xffffffffffffff00,0);
      uStack_60 = 0;
      pplStack_58 = aplStack_80;
      aplStack_80[0] = plVar5;
      if (cRam0000000182eb8046 == '\0') {
        FUN_1802f2810(&DAT_182d53428);
        LOCK();
        UNLOCK();
        cRam0000000182eb8046 = '\x01';
      }
      uVar2 = FUN_1802c36c0(DAT_182d53428,param_5);
      while( true ) {
        iVar1 = (**(code **)(*param_2 + 0x2e8))
                          (param_2,uVar2,0,param_5,*(undefined8 *)(*param_2 + 0x2f0));
        if (iVar1 < 1) {
          if (aplStack_80[0] != (longlong *)0x0) {
            FUN_180002c20(0,DAT_182d53498,aplStack_80[0],iVar1);
          }
          if (lStack_88 != 0) {
            FUN_180002c20(0,DAT_182d53498,lStack_88);
          }
          if (plStackX_10 != (longlong *)0x0) {
            FUN_180002c20(0,DAT_182d53498,plStackX_10);
          }
          return;
        }
        if (plVar5 == (longlong *)0x0) break;
        (**(code **)(*plVar5 + 0x318))(plVar5,uVar2,0,iVar1,*(undefined8 *)(*plVar5 + 800));
      }
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

