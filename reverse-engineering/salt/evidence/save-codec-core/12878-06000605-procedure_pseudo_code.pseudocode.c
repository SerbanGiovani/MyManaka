// Ghidra pseudocode; not original source or compilable C.
// ev_efc001ded14c9050fe7f9f95b231ef838a1b855363e507fa9f5ea07b3e8e0ba2

undefined8
ES3Internal_AESEncryptionAlgorithm__Decrypt__06000605
          (longlong *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 uVar3;
  longlong *plStackX_10;
  longlong lStack_58;
  undefined8 uStack_50;
  undefined8 uStack_38;
  longlong **pplStack_30;
  undefined8 uStack_28;
  longlong *plStack_20;
  
  if (cRam0000000182eb8048 == '\0') {
    FUN_1802f2810(&DAT_182d53498);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53408);
    LOCK();
    UNLOCK();
    cRam0000000182eb8048 = '\x01';
  }
  plStackX_10 = (longlong *)0x0;
  uStack_50 = 0;
  lVar1 = FUN_1802c43a0(DAT_182d53408);
  System_IO_MemoryStream___ctor__0600297f(lVar1,param_2,1,0);
  uStack_28 = 0;
  plStack_20 = &lStack_58;
  lStack_58 = lVar1;
  plVar2 = (longlong *)FUN_1802c43a0(DAT_182d53408);
  System_IO_MemoryStream___ctor__0600297c(plVar2,0);
  uStack_38 = 0;
  pplStack_30 = &plStackX_10;
  plStackX_10 = plVar2;
  (**(code **)(*param_1 + 0x1a8))
            (param_1,lStack_58,plVar2,param_3,param_4,*(undefined8 *)(*param_1 + 0x1b0));
  if (plStackX_10 != (longlong *)0x0) {
    uVar3 = (**(code **)(*plStackX_10 + 0x378))(plStackX_10,*(undefined8 *)(*plStackX_10 + 0x380));
    uStack_50 = uVar3;
    if (plStackX_10 != (longlong *)0x0) {
      FUN_180002c20(0,DAT_182d53498);
    }
    if (lStack_58 != 0) {
      FUN_180002c20(0,DAT_182d53498);
    }
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

