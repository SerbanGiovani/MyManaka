// Ghidra pseudocode; not original source or compilable C.
// ev_acb01c7d7b06bb5fa51b248672f6539d5c20eb962634a21d4a716be867d55bd0

float ExposureUnnoticed2_Scripts_Mission_MissionVibeExposeMove__GetAddSatisfy__06001495
                (longlong param_1)

{
  longlong lVar1;
  
  if (cRam0000000182eb793e == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb793e = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar1 != 0)) {
    lVar1 = *(longlong *)(lVar1 + 0x30);
    if ((*(longlong *)(param_1 + 0x28) != 0) && (lVar1 != 0)) {
      lVar1 = *(longlong *)(lVar1 + 0x40);
      if (*(float *)(*(longlong *)(param_1 + 0x28) + 0x38) * *(float *)(param_1 + 0x30) < 10.0) {
        if ((lVar1 != 0) && (*(longlong *)(lVar1 + 0x1f8) != 0)) {
          return *(float *)(*(longlong *)(lVar1 + 0x1f8) + 0x14) /
                 *(float *)(*(longlong *)(param_1 + 0x28) + 0x38);
        }
      }
      else if ((lVar1 != 0) && (*(longlong *)(lVar1 + 0x1f8) != 0)) {
        return *(float *)(*(longlong *)(lVar1 + 0x1f8) + 0x10) /
               *(float *)(*(longlong *)(param_1 + 0x28) + 0x38);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

