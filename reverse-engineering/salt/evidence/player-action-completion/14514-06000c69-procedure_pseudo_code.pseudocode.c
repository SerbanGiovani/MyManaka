// Ghidra pseudocode; not original source or compilable C.
// ev_b7756bb45cfd45a4e7509076be93e5017111b2ecff0561344466f0c6709c1af7

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationReceiver___OnEndSitDown_b__37_0__06000c69
               (longlong param_1)

{
  longlong lVar1;
  
  if ((*(longlong *)(param_1 + 0x40) != 0) &&
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60), lVar1 != 0)) {
    *(undefined1 *)(lVar1 + 0x23a) = 1;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

