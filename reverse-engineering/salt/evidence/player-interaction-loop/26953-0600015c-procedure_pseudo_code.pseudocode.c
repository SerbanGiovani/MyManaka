// Ghidra pseudocode; not original source or compilable C.
// ev_f2b58c1e494d6fb30fce5fa15797e28a59b12b2e13d8d337b49e45fafe825995

ulonglong UnityEngine_InputSystem_InputAction__WasPressedThisFrame__0600015c(longlong param_1)

{
  ulonglong uVar1;
  
  if (DAT_182ebcdf6 == '\0') {
    FUN_1802f2810(&DAT_182d418d0);
    LOCK();
    UNLOCK();
    DAT_182ebcdf6 = '\x01';
  }
  if (*(longlong *)(param_1 + 200) == 0) {
    FUN_18194cbf0(param_1,0);
  }
  uVar1 = *(ulonglong *)(param_1 + 200);
  if (uVar1 != 0) {
    if (*(longlong *)(uVar1 + 0x60) != 0) {
      uVar1 = *(ulonglong *)(*(longlong *)(uVar1 + 0x60) + 0x60);
      if (*(int *)((longlong)*(int *)(param_1 + 0xc0) * 0x44 + 0x28 + uVar1) ==
          **(int **)(DAT_182d418d0 + 0xb8)) {
        return CONCAT71((int7)(uVar1 >> 8),**(int **)(DAT_182d418d0 + 0xb8) != 0);
      }
    }
    return uVar1 & 0xffffffffffffff00;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

