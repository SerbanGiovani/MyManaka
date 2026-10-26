// Ghidra pseudocode; not original source or compilable C.
// ev_3f19e58bf85154a8e917cef41ddf896a13a869ee91b2053b91d437d30870d19c

float ExposureUnnoticed2_Scripts_Mission_MissionHandcuffsMapExpose__IsRpPerSecScale__0600145a(void)

{
  longlong lVar1;
  
  if (cRam0000000182eb791c == '\0') {
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb791c = '\x01';
  }
  if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
      (lVar1 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar1 != 0)) &&
     (lVar1 = *(longlong *)(lVar1 + 0xf0), lVar1 != 0)) {
    return 1.0 - *(float *)(lVar1 + 0x1c) * 0.5;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

