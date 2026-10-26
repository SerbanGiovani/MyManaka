// Ghidra pseudocode; not original source or compilable C.
// ev_895d19043b007d323bcec4526d1185b8141033571ea5868ebbdedf4edf8cda84

ulonglong ExposureUnnoticed2_Scripts_Mission_MissionStopElevatorNaked__Initialize__06001488
                    (longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  bool bVar5;
  
  if (cRam0000000182eb7937 == '\0') {
    FUN_1802f2810(0x182d5e128);
    LOCK();
    UNLOCK();
    cRam0000000182eb7937 = '\x01';
  }
  ExposureUnnoticed2_Scripts_Mission_MissionBase__Initialize__0600141f(param_1,param_2,0);
  if (DAT_182eb54a9 == '\0') {
    FUN_1802f2810(&DAT_182d5e130);
    LOCK();
    UNLOCK();
    DAT_182eb54a9 = '\x01';
  }
  uVar2 = DAT_182d5e130;
  if (**(longlong **)(DAT_182d5e130 + 0xb8) == 0) {
    FUN_180498db0(param_1);
    if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    uVar2 = FUN_1802c36c0(uRam0000000182d5e128,(int)*(float *)(param_2 + 0x38));
    bVar5 = DAT_182eb5d50 != 0;
    *(ulonglong *)(param_1 + 0x58) = uVar2;
    if (bVar5) {
      uVar4 = (uint)(param_1 + 0x58U >> 0xc);
      uVar3 = (ulonglong)((uVar4 & 0x1fffff) >> 6);
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8);
        LOCK();
        uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8);
        bVar5 = uVar1 == uVar2;
        if (bVar5) {
          *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8) = uVar1 | 1L << (uVar4 & 0x3f);
          uVar2 = uVar1;
        }
        UNLOCK();
      } while (!bVar5);
    }
  }
  return uVar2;
}

