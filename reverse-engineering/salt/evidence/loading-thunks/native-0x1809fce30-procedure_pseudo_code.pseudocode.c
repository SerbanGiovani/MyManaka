// Ghidra pseudocode; not original source or compilable C.
// ev_8dfef42f980bce73fef94e7a020cd5de11601e18d17cdd956df7a049016c7b01

longlong native_only_1809fce30__00000000(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (*(longlong *)(param_2 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(param_2 + 0x38) == 0) {
      FUN_1803204f0(param_2);
    }
  }
  lVar1 = **(longlong **)(param_2 + 0x38);
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ebb9aa == '\0') {
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182ebb9aa = '\x01';
  }
  lVar3 = 0;
  lVar2 = lVar3;
  if (lVar1 != 0) {
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar1 = FUN_1803613f0(lVar1,1);
    lVar2 = FUN_1802c5ac0(lVar1 + 0x20);
  }
  lVar2 = UnityEngine_Resources__Load__060008e9(param_1,lVar2,0);
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x38) + 8);
  if ((*(byte *)(lVar1 + 0x135) & 1) == 0) {
    lVar1 = FUN_180320470(lVar1);
  }
  if ((lVar2 != 0) && (lVar3 = FUN_1802c42e0(lVar2,lVar1), lVar3 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_18031e210(lVar2,lVar1);
  }
  return lVar3;
}

