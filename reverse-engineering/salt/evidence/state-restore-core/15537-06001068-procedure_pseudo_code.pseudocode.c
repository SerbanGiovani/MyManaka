// Ghidra pseudocode; not original source or compilable C.
// ev_749526a22b773a69c7de5ce9846a3ecf3658b53ae330261a35b928e8bc021b77

void ExposureUnnoticed2_Object3D_NPC_Script_NpcController___Initialize_b__50_0__06001068
               (longlong param_1)

{
  longlong lVar1;
  
  if (((*(longlong *)(param_1 + 0x30) != 0) &&
      (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xa0), lVar1 != 0)) &&
     (lVar1 = *(longlong *)(lVar1 + 0x20), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 0x1c) = 0x3f800000;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

