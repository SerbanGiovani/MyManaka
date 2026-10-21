// Ghidra pseudocode; not original source or compilable C.
// ev_a7435ef383dfa8057be6c05fcc54ca3b2a8228d6f725a1ac2fd625936eb38c1b

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__TransAction__06000d92
               (longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  
  if ((*(longlong *)(param_1 + 0x10) != 0) &&
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 0x234) = param_2;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

