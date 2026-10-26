// Ghidra pseudocode; not original source or compilable C.
// ev_7beb1ce465b84cf16727992efdb5a5de5f4c1ed5ba0245715b45aad10ec9354c

void ES3Internal_ES3JSONWriter__EndWriteFile__06000744(longlong param_1)

{
  longlong *plVar1;
  
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
  ES3Internal_ES3JSONWriter__WriteNewlineAndTabs__06000754(param_1,0);
  if (*(char *)(param_1 + 0x20) == '\0') {
    return;
  }
  plVar1 = *(longlong **)(param_1 + 0x28);
  if (plVar1 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001805a92ed. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 0x1f8))(plVar1,0x7d,*(undefined8 *)(*plVar1 + 0x200));
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

