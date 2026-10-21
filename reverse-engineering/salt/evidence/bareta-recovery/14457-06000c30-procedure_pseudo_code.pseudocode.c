// Ghidra pseudocode; not original source or compilable C.
// ev_80674f67b896b534f2b4b4b6861482ae426e78c85cb4c161c226941b42c41c75

void __c___ReduceByFound_b__21_0__06000c30(void)

{
  float fVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (cRam0000000182eb836d == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb836d = '\x01';
  }
  lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar2 != 0) {
    fVar1 = *(float *)(lVar2 + 0x16c);
    lVar3 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
    if (lVar3 != 0) {
      *(float *)(lVar2 + 0x16c) = fVar1 - *(float *)(lVar3 + 0x74);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

