// Ghidra pseudocode; not original source or compilable C.
// ev_889ca20ce018ec5c7bde9ffaf8b473aa41866e3317c9a824badd9807717d2041

void ExposureUnnoticed2_Object3D_NPC_Script_NpcStrangenessManager__ForceSetStrangeness__060010c2
               (longlong param_1,float param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (param_2 < 0.0) {
    param_2 = 0.0;
  }
  else if (1.0 < param_2) {
    *(undefined4 *)(lVar1 + 0x18) = 0x78;
    *(undefined4 *)(lVar1 + 0x14) = 0x3f800000;
    return;
  }
  *(float *)(lVar1 + 0x14) = param_2;
  *(undefined4 *)(lVar1 + 0x18) = 0x78;
  return;
}

