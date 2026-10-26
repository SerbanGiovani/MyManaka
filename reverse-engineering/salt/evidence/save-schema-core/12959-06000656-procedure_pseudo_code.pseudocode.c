// Ghidra pseudocode; not original source or compilable C.
// ev_18ecb78ca0895e2de88b69fdb311cdc1bc9a2ec94941d02e2532dfa205f8b674

longlong * ES3Internal_ES3Reflection__GetElementTypes__06000656(longlong *param_1)

{
  char cVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  if (DAT_182eb8086 == '\0') {
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d54db0);
    LOCK();
    UNLOCK();
    DAT_182eb8086 = '\x01';
  }
  if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (param_1 != (longlong *)0x0) {
    cVar1 = (**(code **)(*param_1 + 0x3a8))(param_1,*(undefined8 *)(*param_1 + 0x3b0));
    if (cVar1 != '\0') {
      if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
        FUN_18035c820();
      }
                    /* WARNING: Could not recover jumptable at 0x00018059a2b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      plVar2 = (longlong *)
               (**(code **)(*param_1 + 0x458))(param_1,*(undefined8 *)(*param_1 + 0x460));
      return plVar2;
    }
    cVar1 = (**(code **)(*param_1 + 0x328))(param_1,*(undefined8 *)(*param_1 + 0x330));
    if (cVar1 == '\0') {
      return (longlong *)0x0;
    }
    plVar2 = (longlong *)FUN_1802c36c0(DAT_182d54db0,1);
    if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar3 = (**(code **)(*param_1 + 0x418))(param_1,*(undefined8 *)(*param_1 + 0x420));
    if (plVar2 != (longlong *)0x0) {
      if (lVar3 != 0) {
        lVar4 = FUN_1802c42e0(lVar3,*(undefined8 *)(*plVar2 + 0x40));
        if (lVar4 == 0) {
          uVar5 = FUN_18031dca0();
                    /* WARNING: Subroutine does not return */
          FUN_18031da90(uVar5,0);
        }
      }
      FUN_180002cd0(plVar2,0,lVar3);
      return plVar2;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

