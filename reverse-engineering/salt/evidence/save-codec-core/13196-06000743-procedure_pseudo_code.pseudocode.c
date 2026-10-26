// Ghidra pseudocode; not original source or compilable C.
// ev_2eca9d9d4cfa02d7ea8622b44b7a21822ad5e2f5962f792dd3fb0807ad1d440f

void ES3Internal_ES3JSONWriter__StartWriteFile__06000743(longlong param_1)

{
  longlong *plVar1;
  
  if (*(char *)(param_1 + 0x20) != '\0') {
    plVar1 = *(longlong **)(param_1 + 0x28);
    if (plVar1 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    (**(code **)(*plVar1 + 0x1f8))(plVar1,0x7b,*(undefined8 *)(*plVar1 + 0x200));
  }
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
  return;
}

