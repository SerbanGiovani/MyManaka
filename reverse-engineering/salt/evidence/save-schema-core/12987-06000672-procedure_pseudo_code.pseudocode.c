// Ghidra pseudocode; not original source or compilable C.
// ev_a3cb1697e2b97a5d0d5e231e06b4337837933a18c05949cc68627e05dfbf500a

longlong * ES3Internal_ES3Reflection__GetParameterlessConstructor__06000672(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  longlong *plVar5;
  
  if (param_1 != (longlong *)0x0) {
    lVar2 = (**(code **)(*param_1 + 0x658))(param_1,0x34,*(undefined8 *)(*param_1 + 0x660));
    uVar4 = 0;
    if (lVar2 != 0) {
      plVar5 = (longlong *)(lVar2 + 0x20);
      while( true ) {
        if (*(int *)(lVar2 + 0x18) <= (int)uVar4) {
          return (longlong *)0x0;
        }
        if (*(uint *)(lVar2 + 0x18) <= uVar4) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dae0();
        }
        plVar1 = (longlong *)*plVar5;
        if ((plVar1 == (longlong *)0x0) ||
           (lVar3 = (**(code **)(*plVar1 + 0x228))(plVar1,*(undefined8 *)(*plVar1 + 0x230)),
           lVar3 == 0)) break;
        if (*(longlong *)(lVar3 + 0x18) == 0) {
          return plVar1;
        }
        uVar4 = uVar4 + 1;
        plVar5 = plVar5 + 1;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

