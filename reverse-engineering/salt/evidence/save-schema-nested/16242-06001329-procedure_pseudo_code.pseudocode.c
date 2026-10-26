// Ghidra pseudocode; not original source or compilable C.
// ev_3ff857078d72de1ea29f5b52a23cbb98c15df81ae296c47056bf31ed3d8ce53a

void ExposureUnnoticed2_Master_Cosplay_CosplayPartsOptionData___ctor__06001329
               (longlong param_1,undefined4 param_2,longlong param_3)

{
  *(undefined4 *)(param_1 + 0x28) = param_2;
  if (param_3 != 0) {
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_3 + 0x10);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_3 + 0x14);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_3 + 0x18);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_3 + 0x1c);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_3 + 0x20);
    *(undefined1 *)(param_1 + 0x24) = *(undefined1 *)(param_3 + 0x24);
    *(undefined1 *)(param_1 + 0x25) = *(undefined1 *)(param_3 + 0x25);
    *(undefined1 *)(param_1 + 0x26) = *(undefined1 *)(param_3 + 0x26);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

