// Ghidra pseudocode; not original source or compilable C.
// ev_d437b4d2c30a036d9e4d5bac2d2f3403a05bf4440c16df95576c9f0253fd7a45

undefined8
ExposureUnnoticed2_Scripts_Mission_MissionVibeExposeMove__IsRpPerSecCondition__06001496
          (longlong *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  if (cRam0000000182eb793f == '\0') {
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb793f = '\x01';
  }
  uVar2 = (**(code **)(*param_1 + 0x1d8))(param_1,*(undefined8 *)(*param_1 + 0x1e0));
  if ((char)uVar2 == '\0') {
    return uVar2;
  }
  if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
      (lVar1 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar1 != 0)) &&
     (*(longlong *)(lVar1 + 0x1f8) != 0)) {
    return CONCAT71((int7)((ulonglong)lVar1 >> 8),
                    0.0 < *(float *)(*(longlong *)(lVar1 + 0x1f8) + 0x18));
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

