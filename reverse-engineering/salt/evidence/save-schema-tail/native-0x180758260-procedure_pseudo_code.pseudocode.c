// Ghidra pseudocode; not original source or compilable C.
// ev_c63a6a7bc83dbd928a5d4d44dcee8842d690491c7aa94960065176a4651cb653

longlong native_only_180758260__00000000(longlong *param_1,longlong param_2,longlong param_3)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
  if (*(longlong *)(param_3 + 0x38) == 0) {
    FUN_1803204f0(param_3);
  }
  cVar1 = (**(code **)(*param_1 + 0x2e8))(param_1,*(undefined8 *)(*param_1 + 0x2f0));
  if (cVar1 == '\0') {
    if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    lVar2 = FUN_1800036a0(*(undefined8 *)(*(longlong *)(param_3 + 0x38) + 8),param_2,param_1);
    (**(code **)(*param_1 + 0x2f8))(param_1,*(undefined8 *)(*param_1 + 0x300));
    lVar3 = **(longlong **)(param_3 + 0x38);
    if ((*(byte *)(lVar3 + 0x135) & 1) == 0) {
      lVar3 = FUN_180320470(lVar3);
    }
    if (lVar2 != 0) {
      lVar4 = FUN_1802c42e0(lVar2,lVar3);
      if (lVar4 != 0) {
        return lVar4;
      }
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(lVar2,lVar3);
    }
  }
  return 0;
}

