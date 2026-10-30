// Ghidra pseudocode; not original source or compilable C.
// ev_10775a69367d2d84e0af67235f7875e94fb27418acdd5e58bc258349bfa97559

void ExposureUnnoticed2_Object3D_Player_Scripts_Other_BodyPaintController__OnUseWashItem__06000e5f
               (longlong param_1)

{
  longlong lVar1;
  
  if (cRam0000000182eb765b == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb765b = '\x01';
  }
  *(undefined4 *)(param_1 + 0x20) = 4;
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar1 != 0) {
    *(undefined4 *)(lVar1 + 0x17c) = 0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

