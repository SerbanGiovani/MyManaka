// Ghidra pseudocode; not original source or compilable C.
// ev_e5951e6c69272dec386b08a165f52a49b6dcc84a9edd693d757555fd8625a58d

void ExposureUnnoticed2_Object3D_NPC_Script_NpcTurnAroundState__OnExit__060010fe(longlong param_1)

{
  longlong lVar1;
  
  if ((*(longlong *)(param_1 + 0x10) != 0) &&
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0xa0), lVar1 != 0)) {
    ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimationManager__SetOverrideIdle__06000fc9(lVar1,0,0)
    ;
    if ((*(longlong *)(param_1 + 0x10) != 0) &&
       (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40), lVar1 != 0)) {
      *(undefined8 *)(lVar1 + 0xb8) = 0;
      *(undefined8 *)(lVar1 + 0xc0) = 0;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

