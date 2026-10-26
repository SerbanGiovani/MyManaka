// Ghidra pseudocode; not original source or compilable C.
// ev_cc7fbe104a11050ec88e8977d17901cde360d1f3e1d9f78d74e489b9395a9222

float ExposureUnnoticed2_Scripts_Mission_MissionCrouchMoveNaked__GetAddSatisfy__06001434
                (longlong param_1)

{
  longlong lVar1;
  
  if (cRam0000000182eb7905 == '\0') {
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb7905 = '\x01';
  }
  if (*(longlong *)(param_1 + 0x28) != 0) {
    lVar1 = **(longlong **)(DAT_182d58378 + 0xb8);
    if (*(float *)(*(longlong *)(param_1 + 0x28) + 0x38) * *(float *)(param_1 + 0x30) < 6.0) {
      if (((lVar1 != 0) && (*(longlong *)(lVar1 + 0x40) != 0)) &&
         (lVar1 = *(longlong *)(*(longlong *)(lVar1 + 0x40) + 0x1f8), lVar1 != 0)) {
        return *(float *)(lVar1 + 0x14) / *(float *)(*(longlong *)(param_1 + 0x28) + 0x38);
      }
    }
    else if (((lVar1 != 0) && (*(longlong *)(lVar1 + 0x40) != 0)) &&
            (lVar1 = *(longlong *)(*(longlong *)(lVar1 + 0x40) + 0x1f8), lVar1 != 0)) {
      return *(float *)(lVar1 + 0x10) / *(float *)(*(longlong *)(param_1 + 0x28) + 0x38);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

