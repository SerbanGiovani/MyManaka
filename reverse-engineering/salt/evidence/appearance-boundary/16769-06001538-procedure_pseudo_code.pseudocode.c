// Ghidra pseudocode; not original source or compilable C.
// ev_ba9d7a693d70bd219b5d33957be38214dd354243ffb51f7d9eaa9845d4638b51

void ExposureUnnoticed2_Scripts_InGame_GameStateFacade__SetActiveBodyPaint__06001538
               (undefined4 param_1,undefined1 param_2)

{
  longlong lVar1;
  
  if (cRam0000000182eb799b == '\0') {
    FUN_1802f2810(0x182d5dca8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb799b = '\x01';
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
  if ((lVar1 != 0) && (lVar1 = *(longlong *)(lVar1 + 0x108), lVar1 != 0)) {
    FUN_180e6cbf0(lVar1,param_1,param_2,1,
                  *(undefined8 *)
                   (*(longlong *)(*(longlong *)(lRam0000000182d5dca8 + 0x20) + 0xc0) + 0x100));
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

