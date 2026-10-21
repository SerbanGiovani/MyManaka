// Ghidra pseudocode; not original source or compilable C.
// ev_d565ebc5e0068f79fd4b549a68b1ccee5d8016032ea9dcf6e4308b2eda8d94e7

undefined8 native_only_1809a08f0__00000000(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uStack_10;
  
  if (*(longlong *)(param_2 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(param_2 + 0x38) == 0) {
      FUN_1803204f0(param_2);
    }
  }
  uStack_10 = 0;
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x38) + 8);
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ebb9aa == '\0') {
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182ebb9aa = '\x01';
  }
  if (lVar1 == 0) {
    uVar2 = 0;
  }
  else {
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar1 = FUN_1803613f0(lVar1,1);
    uVar2 = FUN_1802c5ac0(lVar1 + 0x20);
  }
  FUN_181f3e150(param_1,uVar2,&uStack_10,0);
  return 0;
}

