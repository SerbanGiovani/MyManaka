// Ghidra pseudocode; not original source or compilable C.
// ev_531c7587aa92856c377d999eda30aa308dc3ef0ec9a9bf91f1a0afc331dd33ea

float ExposureUnnoticed2_Scripts_Mission_MissionExposeHandcuffsByNearNpc__IsRpPerSecScale__0600144f
                (void)

{
  longlong lVar1;
  
  if (cRam0000000182eb7915 == '\0') {
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb7915 = '\x01';
  }
  if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
      (lVar1 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar1 != 0)) &&
     (lVar1 = *(longlong *)(lVar1 + 0xf0), lVar1 != 0)) {
    return 1.0 - *(float *)(lVar1 + 0x1c) * 0.5;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

