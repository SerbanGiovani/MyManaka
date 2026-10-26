// Ghidra pseudocode; not original source or compilable C.
// ev_6d5a9a04cde8fba408aa68997640cd68720801505c80490ba4e4f09dd6a6f5ad

undefined1
ES3Types_ES3Type__WriteUsingDerivedType__06000441
          (longlong param_1,longlong *param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  
  if (cRam0000000182eb7ecf == '\0') {
    FUN_1802f2810(&DAT_182d52ec0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7ecf = '\x01';
  }
  if (param_2 != (longlong *)0x0) {
    lVar2 = FUN_1802c5ac0(*param_2 + 0x20);
    lVar1 = *(longlong *)(param_1 + 0x18);
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (lVar2 == lVar1) {
      return 0;
    }
    if (param_3 != 0) {
      ES3Writer__WriteType__0600027c(param_3,lVar2,0);
      if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      plVar3 = (longlong *)ES3Internal_ES3TypeMgr__GetOrCreateES3Type__060006ea(lVar2,1,0);
      if (plVar3 != (longlong *)0x0) {
        (**(code **)(*plVar3 + 0x178))(plVar3,param_2,param_3,*(undefined8 *)(*plVar3 + 0x180));
        return 1;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

