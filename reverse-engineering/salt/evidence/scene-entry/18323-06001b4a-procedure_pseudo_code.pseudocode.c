// Ghidra pseudocode; not original source or compilable C.
// ev_d03ed079a72045bb5bba62dcfb03b0f0774d3c812fd9e66462167edea3734b5c

void ExposureUnnoticed2_ObjectUI_FadeOutPanel_FadePanelView__OnPureBlack__06001b4a(longlong param_1)

{
  longlong lVar1;
  
  *(undefined1 *)(param_1 + 0x48) = 1;
  lVar1 = *(longlong *)(param_1 + 0x28);
  if (lVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0001805137d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(lVar1 + 0x18))(*(undefined8 *)(lVar1 + 0x40),*(undefined8 *)(lVar1 + 0x28));
    return;
  }
  return;
}

