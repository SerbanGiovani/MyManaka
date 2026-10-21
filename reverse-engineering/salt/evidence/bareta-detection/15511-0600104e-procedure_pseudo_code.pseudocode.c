// Ghidra pseudocode; not original source or compilable C.
// ev_12e1e6bf56bcdd78c537f1dbbfa8a7b26fb6acd36828f7ba2adef3438e7bab24

undefined1
ExposureUnnoticed2_Object3D_NPC_Script_NpcController__get_IsPlayerFound__0600104e(longlong param_1)

{
  longlong lVar1;
  
  if ((*(longlong *)(param_1 + 0x30) != 0) &&
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x68), lVar1 != 0)) {
    return *(undefined1 *)(lVar1 + 0x68);
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

