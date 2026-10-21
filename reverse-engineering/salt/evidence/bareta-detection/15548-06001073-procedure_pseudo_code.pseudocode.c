// Ghidra pseudocode; not original source or compilable C.
// ev_3232787f8aeff2b4fd100acdf0a00b8c8e714cd273b05256c5e5b8311a2caea5

void ExposureUnnoticed2_Object3D_NPC_Script_NpcFoundStrangerState__OnEnter__06001073
               (longlong param_1)

{
  longlong lVar1;
  
  if ((*(longlong *)(param_1 + 0x20) == 0) ||
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0xa0), lVar1 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (DAT_182eb7732 == '\0') {
    FUN_1802f2810(&DAT_182d59ea8,1,0);
    LOCK();
    UNLOCK();
    DAT_182eb7732 = '\x01';
  }
  lVar1 = *(longlong *)(lVar1 + 0x18);
  if (*(int *)(DAT_182d59ea8 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d59ea8);
  }
  if (lVar1 != 0) {
    FUN_181eea680(lVar1,*(undefined4 *)(*(longlong *)(DAT_182d59ea8 + 0xb8) + 0x24),1,0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

