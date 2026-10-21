// Ghidra pseudocode; not original source or compilable C.
// ev_d221fb85fda74857c0dc1a1c708166f05b852d66c218d138b04c70e9d4212686

longlong native_only_1809f1050__00000000(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 unaff_RDI;
  
  if (*(longlong *)(param_3 + 0x38) == 0) {
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(param_3 + 0x38) == 0) {
      FUN_1803204f0(param_3);
    }
  }
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar2 = *(longlong *)(*(longlong *)(param_3 + 0x38) + 8);
  if (*(longlong *)(lVar2 + 0x38) == 0) {
    FUN_1802f2810(0x182d53aa8,param_2,0,lVar2,unaff_RDI);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar2 + 0x38) == 0) {
      FUN_1803204f0(lVar2);
    }
  }
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar1 = FUN_181f439e0(param_1,param_2,0,0);
  lVar2 = **(longlong **)(lVar2 + 0x38);
  if ((*(byte *)(lVar2 + 0x135) & 1) == 0) {
    lVar2 = FUN_180320470(lVar2);
  }
  if (lVar1 == 0) {
    lVar3 = 0;
  }
  else {
    lVar3 = FUN_1802c42e0(lVar1,lVar2);
    if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(lVar1,lVar2);
    }
  }
  return lVar3;
}

