// Ghidra pseudocode; not original source or compilable C.
// ev_e0f80814e96755b817e4a81e4a6e2f23b1b38fe6af2e003bb11244eb42b5118a

ulonglong UnityEngine_InputSystem_InputAction__IsPressed__06000159(longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  
  if (*(longlong *)(param_1 + 200) == 0) {
    FUN_18194cbf0(param_1,0);
  }
  uVar1 = *(ulonglong *)(param_1 + 200);
  if (uVar1 != 0) {
    if (*(longlong *)(uVar1 + 0x60) == 0) {
      return uVar1 & 0xffffffffffffff00;
    }
    lVar2 = *(longlong *)(*(longlong *)(uVar1 + 0x60) + 0x60);
    return CONCAT71((int7)((ulonglong)lVar2 >> 8),
                    (*(byte *)((longlong)*(int *)(param_1 + 0xc0) * 0x44 + 1 + lVar2) & 0x40) != 0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

