// Ghidra pseudocode; not original source or compilable C.
// ev_736be91d9f1861282e4eb82c936bc27d3390b7ea20d47dcc45d0c6ee06b761c5

void ExposureUnnoticed2_ObjectUI_SelectSexOptionPanel_SelectSexOptionPanelView___OnClickDecide_b__9_0__0600183d
               (longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x78);
  if (lVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0001804c570d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(lVar1 + 0x18))(*(undefined8 *)(lVar1 + 0x40),*(undefined8 *)(lVar1 + 0x28));
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

