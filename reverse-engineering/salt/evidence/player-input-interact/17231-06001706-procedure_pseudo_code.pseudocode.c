// Ghidra pseudocode; not original source or compilable C.
// ev_7ed438b97fec19464ed54563891f0433a561ab6547bfcfa3974fcf42b67e9cf9

ulonglong ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(undefined4 param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  if (DAT_182eb7a8e == '\0') {
    FUN_1802f2810(&DAT_182d5fa38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    DAT_182eb7a8e = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar3 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x18);
  if (lVar3 != 0) {
    lVar1 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x10);
    lVar3 = *(longlong *)(lVar3 + 0x90);
    if (lVar1 != 0) {
      uVar2 = FUN_180e75f20(lVar1,param_1,DAT_182d5fa38);
      if (lVar3 != 0) {
        lVar3 = FUN_181952d80(lVar3,uVar2,0);
        if (lVar3 != 0) {
          if (DAT_182ebcdf6 == '\0') {
            FUN_1802f2810(&DAT_182d418d0);
            LOCK();
            UNLOCK();
            DAT_182ebcdf6 = '\x01';
          }
          if (*(longlong *)(lVar3 + 200) == 0) {
            FUN_18194cbf0(lVar3,0);
          }
          uVar4 = *(ulonglong *)(lVar3 + 200);
          if (uVar4 != 0) {
            if (*(longlong *)(uVar4 + 0x60) != 0) {
              uVar4 = *(ulonglong *)(*(longlong *)(uVar4 + 0x60) + 0x60);
              if (*(int *)((longlong)*(int *)(lVar3 + 0xc0) * 0x44 + 0x28 + uVar4) ==
                  **(int **)(DAT_182d418d0 + 0xb8)) {
                return CONCAT71((int7)(uVar4 >> 8),**(int **)(DAT_182d418d0 + 0xb8) != 0);
              }
            }
            return uVar4 & 0xffffffffffffff00;
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

