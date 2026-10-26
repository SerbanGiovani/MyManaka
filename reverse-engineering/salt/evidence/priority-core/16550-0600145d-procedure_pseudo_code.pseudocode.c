// Ghidra pseudocode; not original source or compilable C.
// ev_c9e1028ee8341039b6b82d9bee7bb5f4db5e0ec8100747641a7159c4721ac4c4

float ExposureUnnoticed2_Scripts_Mission_MissionHandcuffsMoveExpose__GetAddSatisfy__0600145d
                (longlong param_1)

{
  longlong lVar1;
  
  if (cRam0000000182eb791e == '\0') {
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb791e = '\x01';
  }
  if (*(longlong *)(param_1 + 0x28) != 0) {
    lVar1 = **(longlong **)(DAT_182d58378 + 0xb8);
    if (*(float *)(*(longlong *)(param_1 + 0x28) + 0x38) * *(float *)(param_1 + 0x30) < 10.0) {
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

