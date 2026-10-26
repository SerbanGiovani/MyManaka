// Ghidra pseudocode; not original source or compilable C.
// ev_d4bf15b749fa587db8a1f3f8da32209601b008c59f33f4a91f0c715b7dcc40fa

void ES3ReflectedMember__GetValue__06000687(longlong *param_1,undefined8 param_2)

{
  longlong *plVar1;
  
  if ((char)param_1[2] == '\0') {
    param_1 = (longlong *)*param_1;
    if (param_1 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018059fb07. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 0x2c8))(param_1,param_2,*(undefined8 *)(*param_1 + 0x2d0));
      return;
    }
  }
  else {
    plVar1 = (longlong *)param_1[1];
    if (plVar1 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018059fb2b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*plVar1 + 0x2d8))(plVar1,param_2,0,*(undefined8 *)(*plVar1 + 0x2e0));
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

