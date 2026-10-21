// Ghidra pseudocode; not original source or compilable C.
// ev_89f90e36c6942e7c53012c5fc9d22a2604c08824ec03f7c1181bba3e3b535aec

ulonglong ExposureUnnoticed2_Scripts_Base_InputManager__IsDownLongRepeat__06001705
                    (undefined4 param_1,int param_2,int param_3)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  if (cRam0000000182eb7a8d == '\0') {
    FUN_1802f2810(&DAT_182d5fa90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a8d = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar1 = *(longlong *)(DAT_182d5aa88 + 0xb8);
  fVar4 = ((float)param_2 * 0.016) / *(float *)(lVar1 + 0x38);
  fVar6 = 1.0;
  if (1.0 <= fVar4) {
    fVar6 = fVar4;
  }
  fVar5 = ((float)param_3 * 0.016) / *(float *)(lVar1 + 0x38);
  fVar4 = 1.0;
  if (1.0 <= fVar5) {
    fVar4 = fVar5;
  }
  if (*(longlong *)(lVar1 + 0x28) != 0) {
    uVar3 = FUN_180e71cd0(*(longlong *)(lVar1 + 0x28),param_1,DAT_182d5fa90);
    if ((int)uVar3 < (int)fVar6) {
      uVar3 = uVar3 & 0xffffffffffffff00;
    }
    else {
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d5aa88);
      }
      lVar1 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x28);
      if (lVar1 == 0) goto code_r0x0001804b1526;
      iVar2 = FUN_180e71cd0(lVar1,param_1,DAT_182d5fa90);
      uVar3 = CONCAT71((int7)((ulonglong)((longlong)iVar2 / (longlong)(int)fVar4) >> 8),
                       iVar2 % (int)fVar4 == 0) & 0xffffffff;
    }
    return uVar3;
  }
code_r0x0001804b1526:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

