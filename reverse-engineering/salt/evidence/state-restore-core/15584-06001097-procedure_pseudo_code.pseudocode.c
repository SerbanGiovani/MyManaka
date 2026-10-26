// Ghidra pseudocode; not original source or compilable C.
// ev_010fc2d1e81da9be58894325fb9170e665c48041dcd7fd2c7eed4207232b1c28

void ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__RemoveNpc__06001097
               (longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  if (cRam0000000182eb776e == '\0') {
    FUN_1802f2810(0x182d59528);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d59520);
    LOCK();
    UNLOCK();
    cRam0000000182eb776e = '\x01';
  }
  if (*(longlong *)(param_1 + 0x38) != 0) {
    FUN_181274e50(*(longlong *)(param_1 + 0x38),param_2,uRam0000000182d59520);
    if ((param_2 != 0) && (*(longlong *)(param_1 + 0x40) != 0)) {
      FUN_180ebb270(*(longlong *)(param_1 + 0x40),*(undefined8 *)(param_2 + 0x18),
                    uRam0000000182d59528);
      if ((*(longlong *)(param_2 + 0x30) != 0) &&
         (lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x40), lVar1 != 0)) {
        if (*(int *)(lVar1 + 0x58) != 0) {
          *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + -1;
        }
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

