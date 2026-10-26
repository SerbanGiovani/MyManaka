// Ghidra pseudocode; not original source or compilable C.
// ev_c772e101a2cc06b1458fd2128cc61e6ddebd348d22b4d3209085ef011de0b5af

void native_only_180758b30__00000000
               (longlong *param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  char cVar1;
  
  if (*(longlong *)(param_4 + 0x38) == 0) {
    FUN_1803204f0(param_4);
  }
  cVar1 = (**(code **)(*param_1 + 0x2e8))(param_1,*(undefined8 *)(*param_1 + 0x2f0));
  if (cVar1 == '\0') {
    if (param_3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    FUN_180007d40(**(undefined8 **)(param_4 + 0x38),param_3,param_1,param_2);
    (**(code **)(*param_1 + 0x2f8))(param_1,*(undefined8 *)(*param_1 + 0x300));
  }
  return;
}

