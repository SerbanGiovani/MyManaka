// Ghidra pseudocode; not original source or compilable C.
// ev_0a1de86955a4bdf6564f25d088967f02d693e26cef7fadbb701f031667db31d7

void ExposureUnnoticed2_Object3D_NPC_Script_NpcController__ChangeFoundStrangerIfInCondition__0600105d
               (longlong param_1)

{
  longlong lVar1;
  
  if (((*(longlong *)(param_1 + 0x30) != 0) &&
      (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar1 != 0)) &&
     (lVar1 = *(longlong *)(lVar1 + 0x10), lVar1 != 0)) {
    if (1.0 <= *(float *)(lVar1 + 0x14)) {
      if (*(longlong *)(param_1 + 0x48) == 0) goto code_r0x0001804296c4;
      if (*(char *)(*(longlong *)(param_1 + 0x48) + 0x1d) == '\0') {
        ExposureUnnoticed2_Object3D_NPC_Script_NpcController__ChangeState__0600105f(param_1,1,0);
        if (*(longlong *)(param_1 + 0x48) == 0) goto code_r0x0001804296c4;
        *(undefined1 *)(*(longlong *)(param_1 + 0x48) + 0x1d) = 1;
      }
    }
    return;
  }
code_r0x0001804296c4:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

