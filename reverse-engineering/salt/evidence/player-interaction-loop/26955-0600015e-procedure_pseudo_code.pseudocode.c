// Ghidra pseudocode; not original source or compilable C.
// ev_709b979a970885f66d76cd7eba174db569aef1e9fb4ac12a8e8f57e088a01e64

ulonglong UnityEngine_InputSystem_InputAction__WasReleasedThisFrame__0600015e(longlong param_1)

{
  ulonglong uVar1;
  
  if (cRam0000000182ebcdf7 == '\0') {
    FUN_1802f2810(&DAT_182d418d0);
    LOCK();
    UNLOCK();
    cRam0000000182ebcdf7 = '\x01';
  }
  if (*(longlong *)(param_1 + 200) == 0) {
    FUN_18194cbf0(param_1,0);
  }
  uVar1 = *(ulonglong *)(param_1 + 200);
  if (uVar1 != 0) {
    if (*(longlong *)(uVar1 + 0x60) != 0) {
      uVar1 = *(ulonglong *)(*(longlong *)(uVar1 + 0x60) + 0x60);
      if (*(int *)((longlong)*(int *)(param_1 + 0xc0) * 0x44 + 0x2c + uVar1) ==
          **(int **)(DAT_182d418d0 + 0xb8)) {
        return CONCAT71((int7)(uVar1 >> 8),**(int **)(DAT_182d418d0 + 0xb8) != 0);
      }
    }
    return uVar1 & 0xffffffffffffff00;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

