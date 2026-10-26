// Ghidra pseudocode; not original source or compilable C.
// ev_1d6180f9cd5aabdbd1efad673d2b0db11d601c67b6e473c569732b6495ac597e

bool ES3Internal_ES3Reflection__HasParameterlessConstructor__06000671(longlong *param_1)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  longlong *plVar5;
  longlong *plVar6;
  bool bVar7;
  
  if (DAT_182eb8093 == '\0') {
    FUN_1802f2810(&DAT_182d6a6e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    DAT_182eb8093 = '\x01';
  }
  if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (param_1 != (longlong *)0x0) {
    cVar1 = (**(code **)(*param_1 + 0x5f8))(param_1,*(undefined8 *)(*param_1 + 0x600));
    if (cVar1 == '\0') {
      if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar2 = (**(code **)(*param_1 + 0x658))(param_1,0x34,*(undefined8 *)(*param_1 + 0x660));
      uVar4 = 0;
      if (lVar2 == 0) goto LAB_18059ca72;
      plVar5 = (longlong *)(lVar2 + 0x20);
      for (; (int)uVar4 < *(int *)(lVar2 + 0x18); uVar4 = uVar4 + 1) {
        if (*(uint *)(lVar2 + 0x18) <= uVar4) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dae0();
        }
        plVar6 = (longlong *)*plVar5;
        if (plVar6 == (longlong *)0x0) goto LAB_18059ca72;
        lVar3 = (**(code **)(*plVar6 + 0x228))(plVar6,*(undefined8 *)(*plVar6 + 0x230));
        if (lVar3 == 0) goto LAB_18059ca72;
        if (*(longlong *)(lVar3 + 0x18) == 0) goto LAB_18059ca08;
        plVar5 = plVar5 + 1;
      }
      plVar6 = (longlong *)0x0;
LAB_18059ca08:
      if (*(int *)(DAT_182d6a6e8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (DAT_182ebb260 == '\0') {
        FUN_1802f2810(&DAT_182d6a6e8);
        LOCK();
        UNLOCK();
        DAT_182ebb260 = '\x01';
      }
      if (*(int *)(DAT_182d6a6e8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      bVar7 = plVar6 != (longlong *)0x0;
    }
    else {
      bVar7 = true;
    }
    return bVar7;
  }
LAB_18059ca72:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

