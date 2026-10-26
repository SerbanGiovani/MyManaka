// Ghidra pseudocode; not original source or compilable C.
// ev_604854b6f590c419c907ff2c864874660aad94e2605ca9a9a62f2d503f715743

void ES3Types_ES3Type__WriteProperties__06000444
               (longlong param_1,undefined8 param_2,longlong *param_3)

{
  undefined8 uVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  longlong lVar7;
  
  if (DAT_182eb7ed0 == '\0') {
    FUN_1802f2810(&DAT_182d52ec0);
    LOCK();
    UNLOCK();
    DAT_182eb7ed0 = '\x01';
  }
  if (*(longlong *)(param_1 + 0x10) == 0) {
    if ((param_3 == (longlong *)0x0) || (param_3[2] == 0)) goto LAB_18055247f;
    ES3Types_ES3Type__GetMembers__06000447(param_1,*(undefined1 *)(param_3[2] + 0x4b),0,0);
  }
  lVar3 = *(longlong *)(param_1 + 0x10);
  uVar6 = 0;
  if (lVar3 != 0) {
    lVar7 = 0x20;
    while( true ) {
      if (*(int *)(lVar3 + 0x18) <= (int)uVar6) {
        return;
      }
      lVar3 = *(longlong *)(param_1 + 0x10);
      if (lVar3 == 0) break;
      if (*(uint *)(lVar3 + 0x18) <= uVar6) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dae0();
      }
      lVar3 = *(longlong *)(lVar7 + lVar3);
      if (lVar3 == 0) break;
      uVar1 = *(undefined8 *)(lVar3 + 0x10);
      if (*(char *)(lVar3 + 0x38) == '\0') {
        plVar2 = *(longlong **)(lVar3 + 0x28);
        if (plVar2 == (longlong *)0x0) break;
        uVar4 = (**(code **)(*plVar2 + 0x2c8))(plVar2,param_2,*(undefined8 *)(*plVar2 + 0x2d0));
      }
      else {
        plVar2 = *(longlong **)(lVar3 + 0x30);
        if (plVar2 == (longlong *)0x0) break;
        uVar4 = (**(code **)(*plVar2 + 0x2d8))(plVar2,param_2,0,*(undefined8 *)(*plVar2 + 0x2e0));
      }
      uVar5 = *(undefined8 *)(lVar3 + 0x18);
      if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar5 = ES3Internal_ES3TypeMgr__GetOrCreateES3Type__060006ea(uVar5,1,0);
      if ((param_3 == (longlong *)0x0) || (param_3[2] == 0)) break;
      (**(code **)(*param_3 + 0x448))
                (param_3,uVar1,uVar4,uVar5,*(undefined4 *)(param_3[2] + 0x4c),
                 *(undefined8 *)(*param_3 + 0x450));
      lVar3 = *(longlong *)(param_1 + 0x10);
      uVar6 = uVar6 + 1;
      lVar7 = lVar7 + 8;
      if (lVar3 == 0) break;
    }
  }
LAB_18055247f:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

