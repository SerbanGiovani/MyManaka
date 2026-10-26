// Ghidra pseudocode; not original source or compilable C.
// ev_d8372de6d08e3ab80f94f2f65b70eaa2f2c06bd083b0275fd3c8c25a7acae8ec

void ES3Internal_ES3JSONWriter__EndWriteDictionaryKey__06000750(longlong param_1)

{
  longlong *plVar1;
  
  plVar1 = *(longlong **)(param_1 + 0x28);
  if (plVar1 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001805a9687. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 0x1f8))(plVar1,0x3a,*(undefined8 *)(*plVar1 + 0x200));
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

