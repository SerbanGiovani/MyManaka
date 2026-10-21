// Ghidra pseudocode; not original source or compilable C.
// ev_8b19f90980415a559fdba657c59d05792c67e1ca8ed51c8cfe1b58c05f04e001

void ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimationManager__SetSpeed__06000fbe
               (longlong param_1,undefined4 param_2)

{
  if (*(longlong *)(param_1 + 0x20) != 0) {
    *(undefined4 *)(*(longlong *)(param_1 + 0x20) + 0x1c) = param_2;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

