// Ghidra pseudocode; not original source or compilable C.
// ev_7283b64842f7b8ad98586c98bd15d5b4d487f71cc0a50c1a81b73772d4300e00

void ES3Internal_ES3Reflection__AttributeIsDefined__06000679(longlong *param_1,undefined8 param_2)

{
  if (param_1 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018059d241. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x1e8))(param_1,param_2,1,*(undefined8 *)(*param_1 + 0x1f0));
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

