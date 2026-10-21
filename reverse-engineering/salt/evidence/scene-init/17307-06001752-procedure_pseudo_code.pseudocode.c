// Ghidra pseudocode; not original source or compilable C.
// ev_fbb73846f78bec7da91669caba339988eed782df4e2df69ebd6dd2d5bb2bd1af

undefined8 DelayFrameModel__CountdownAndInvokeIfNeed__06001752(longlong param_1)

{
  longlong lVar1;
  
  if (*(int *)(param_1 + 0x18) != 0) {
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
    return 0;
  }
  lVar1 = *(longlong *)(param_1 + 0x10);
  if (lVar1 != 0) {
    (**(code **)(lVar1 + 0x18))(*(undefined8 *)(lVar1 + 0x40),*(undefined8 *)(lVar1 + 0x28));
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

