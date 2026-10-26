// Ghidra pseudocode; not original source or compilable C.
// ev_1465d4101ec2bbf19eef51f6a0a089024d018acf5e7e65534dd09c6826a35c54

void ES3Internal_ES3JSONWriter__StartWriteDictionaryKey__0600074f(longlong param_1,int param_2)

{
  longlong *plVar1;
  
  if (param_2 == 0) {
    return;
  }
  plVar1 = *(longlong **)(param_1 + 0x28);
  if (plVar1 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001805a960b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 0x1f8))(plVar1,0x2c,*(undefined8 *)(*plVar1 + 0x200));
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

