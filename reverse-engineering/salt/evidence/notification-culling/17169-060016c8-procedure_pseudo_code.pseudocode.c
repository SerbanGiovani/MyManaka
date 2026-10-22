// Ghidra pseudocode; not original source or compilable C.
// ev_e3f7e12919b943ccb880e2e4282face63646cbd284ef2ecbde13aedfe04ef58d

byte ExposureUnnoticed2_Scripts_InGame_ObjectCulling_NpcCullArea__IsInArea__060016c8
               (longlong param_1,undefined8 param_2)

{
  byte extraout_var;
  
  if (cRam0000000182eb7a6a == '\0') {
    FUN_1802f2810(0x182d5fca0);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a6a = '\x01';
  }
  if (*(longlong *)(param_1 + 0x20) != 0) {
    FUN_180e9f040(*(longlong *)(param_1 + 0x20),param_2,
                  *(undefined8 *)
                   (*(longlong *)(*(longlong *)(lRam0000000182d5fca0 + 0x20) + 0xc0) + 0xf8));
    return extraout_var >> 7 ^ 1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

