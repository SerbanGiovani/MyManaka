// Ghidra pseudocode; not original source or compilable C.
// ev_84abb2a4c4437a11f72be849b9d026facb126060407e75394410cbeae2492e19

bool ExposureUnnoticed2_Scripts_Base_InteractManager__IsRegister__06001799
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  int iVar2;
  
  if (cRam0000000182eb7abe == '\0') {
    FUN_1802f2810(0x182d5ab80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f5b0);
    LOCK();
    UNLOCK();
    cRam0000000182eb7abe = '\x01';
  }
  if (*(int *)(lRam0000000182d5ab80 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5ab80);
  }
  lVar1 = **(longlong **)(lRam0000000182d5ab80 + 0xb8);
  if (lVar1 != 0) {
    if (*(int *)(lVar1 + 0x18) == 0) {
      return false;
    }
    iVar2 = FUN_180112740(*(undefined8 *)(lVar1 + 0x10),param_1,param_3,
                          *(undefined4 *)(lVar1 + 0x18),
                          *(undefined8 *)
                           (*(longlong *)
                             (*(longlong *)
                               (*(longlong *)
                                 (*(longlong *)(*(longlong *)(lRam0000000182d5f5b0 + 0x20) + 0xc0) +
                                 0xd0) + 0x20) + 0xc0) + 0x148));
    return iVar2 != -1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

