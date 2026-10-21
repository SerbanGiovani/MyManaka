// Ghidra pseudocode; not original source or compilable C.
// ev_dbd3d7a780a875f7e255a040b24521d6be5c9b9e1f0271b0bfe732dd420006da

void __c__DisplayClass31_0___LoadBundleFromStreamAsync_b__1__060000c0(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  if (lVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00018143fc4d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(lVar1 + 0x18))(*(undefined8 *)(lVar1 + 0x40),*(undefined8 *)(lVar1 + 0x28));
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

