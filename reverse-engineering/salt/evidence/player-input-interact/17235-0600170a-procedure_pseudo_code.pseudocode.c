// Ghidra pseudocode; not original source or compilable C.
// ev_77f2e30094d9ac02da00e914bc2e0f3d7b4b180998e63b01f4fc1415a0e5c221

bool ExposureUnnoticed2_Scripts_Base_InputManager__GetShortUp__0600170a
               (undefined4 param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  
  if (cRam0000000182eb7a92 == '\0') {
    FUN_1802f2810(&DAT_182d5fa90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a92 = '\x01';
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
  if (lVar1 != 0) {
    iVar2 = *(int *)(lVar1 + 0x7c);
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
    fVar3 = ((float)iVar2 * 0.1 * (float)param_2 * 0.016) /
            *(float *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x38);
    fVar4 = 1.0;
    if (1.0 <= fVar3) {
      fVar4 = fVar3;
    }
    lVar1 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x30);
    if (lVar1 != 0) {
      iVar2 = FUN_180e71cd0(lVar1,param_1,DAT_182d5fa90);
      if (iVar2 < 1) {
        return false;
      }
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d5aa88);
      }
      lVar1 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x30);
      if (lVar1 != 0) {
        iVar2 = FUN_180e71cd0(lVar1,param_1,DAT_182d5fa90);
        if ((int)fVar4 <= iVar2) {
          return false;
        }
        if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d5aa88);
        }
        lVar1 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x28);
        if (lVar1 != 0) {
          iVar2 = FUN_180e71cd0(lVar1,param_1,DAT_182d5fa90);
          return iVar2 == -1;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

