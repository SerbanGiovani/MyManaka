// Ghidra pseudocode; not original source or compilable C.
// ev_019a293d9e1d207872b5d53b239f95976eb0ea1d8d73eee38fb0a6c66ff70cf3

void ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryItemView__OnClickUse__060019bc
               (longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x60);
  if (lVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0001804ea4fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(lVar1 + 0x18))
              (*(undefined8 *)(lVar1 + 0x40),*(undefined8 *)(param_1 + 0x70),
               *(undefined8 *)(lVar1 + 0x28));
    return;
  }
  return;
}

