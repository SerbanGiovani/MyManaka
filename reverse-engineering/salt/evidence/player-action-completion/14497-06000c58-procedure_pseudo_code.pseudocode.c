// Ghidra pseudocode; not original source or compilable C.
// ev_9a2a721c3261d069e8729071cd200550efdd04d5e812780fec838e26f6569568

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationReceiver__EndArmAction__06000c58
               (longlong param_1)

{
  if (*(longlong *)(param_1 + 0x28) != 0) {
    *(undefined1 *)(*(longlong *)(param_1 + 0x28) + 0x18) = 0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

