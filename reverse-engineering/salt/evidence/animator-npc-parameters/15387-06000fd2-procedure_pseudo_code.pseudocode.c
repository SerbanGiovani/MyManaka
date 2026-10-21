// Ghidra pseudocode; not original source or compilable C.
// ev_4d3d81dd24d6f68fd81b8f5e0f1ee9a1b46f2a9190387b84412a7b72ddb9da51

void ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimationManager__SetIsSit__06000fd2
               (longlong param_1,undefined1 param_2)

{
  longlong lVar1;
  
  if (DAT_182eb7737 == '\0') {
    FUN_1802f2810(&DAT_182d59ea8);
    LOCK();
    UNLOCK();
    DAT_182eb7737 = '\x01';
  }
  lVar1 = *(longlong *)(param_1 + 0x18);
  if (*(int *)(DAT_182d59ea8 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d59ea8);
  }
  if (lVar1 != 0) {
    FUN_181eea680(lVar1,*(undefined4 *)(*(longlong *)(DAT_182d59ea8 + 0xb8) + 0x38),param_2,0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

