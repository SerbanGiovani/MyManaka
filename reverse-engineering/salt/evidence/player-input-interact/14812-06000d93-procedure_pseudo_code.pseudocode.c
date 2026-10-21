// Ghidra pseudocode; not original source or compilable C.
// ev_a16aab356044af982babe8c5efe46dfe4957b6e3de2f6f7ed5bd6aaea67e4ab0

ulonglong ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__TransActionIfNewNext__06000d93
                    (longlong param_1,int param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  
  if (((*(longlong *)(param_1 + 0x10) != 0) &&
      (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60), lVar1 != 0)) &&
     (uVar2 = *(ulonglong *)(lVar1 + 0x48), uVar2 != 0)) {
    if (*(int *)(uVar2 + 0x18) != param_2) {
      lVar1 = *(longlong *)(param_1 + 0x10);
      *(int *)(*(longlong *)(lVar1 + 0x60) + 0x234) = param_2;
      return CONCAT71((int7)((ulonglong)lVar1 >> 8),1);
    }
    return uVar2 & 0xffffffffffffff00;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

