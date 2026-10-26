// Ghidra pseudocode; not original source or compilable C.
// ev_bc9105632d44e2ef3af20694254488ca95ea2a5b284cd7c6267516e9cc0479aa

undefined8
ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__SearchNpcController__060010a4
          (longlong param_1,undefined8 param_2)

{
  char cVar1;
  longlong lStackX_8;
  
  if (cRam0000000182eb777a == '\0') {
    FUN_1802f2810(0x182d59458);
    LOCK();
    UNLOCK();
    cRam0000000182eb777a = '\x01';
  }
  lStackX_8 = 0;
  if (*(longlong *)(param_1 + 0x40) != 0) {
    cVar1 = FUN_180ebb4c0(*(longlong *)(param_1 + 0x40),param_2,&lStackX_8,uRam0000000182d59458);
    if (cVar1 == '\0') {
      return 0;
    }
    if (lStackX_8 != 0) {
      return *(undefined8 *)(lStackX_8 + 0x28);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

