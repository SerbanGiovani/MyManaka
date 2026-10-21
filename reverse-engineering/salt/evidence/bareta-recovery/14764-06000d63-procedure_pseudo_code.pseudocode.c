// Ghidra pseudocode; not original source or compilable C.
// ev_c69e68c4598aaa42daa7d933c714fc98ae1f5ee3d820c9a3f92bb198e48dedd0

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController__OnEmergencyEscape__06000d63
               (longlong param_1)

{
  longlong lVar1;
  char cVar2;
  
  if ((*(longlong *)(param_1 + 0x40) != 0) &&
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0xf0), lVar1 != 0)) {
    if ((*(char *)(lVar1 + 0x2c) == '\0') && (*(char *)(lVar1 + 0x2d) == '\0')) {
      cVar2 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsAttachSomeHandcuffs__0600155d(0);
      if (cVar2 != '\0') {
        *(undefined4 *)(lVar1 + 0x30) = 1;
      }
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

