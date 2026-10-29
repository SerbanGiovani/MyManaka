// Ghidra pseudocode; not original source or compilable C.
// ev_54b3d68b89c66a7d8c1c43dcaf389eae655183f21af76d006672dc7edda99ef1

void ExposureUnnoticed2_Scripts_Mission_MissionBase__Reset__06001426(longlong param_1)

{
  longlong lVar1;
  
  if (cRam0000000182eb78fd == '\0') {
    FUN_1802f2810(0x182d5e230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb78fd = '\x01';
  }
  *(undefined1 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(param_1 + 0x1c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x14) = 0x3f000000;
  *(undefined4 *)(param_1 + 0x18) = 0x42480000;
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (((lVar1 != 0) && (*(longlong *)(param_1 + 0x28) != 0)) &&
     (lVar1 = *(longlong *)(lVar1 + 0x100), lVar1 != 0)) {
    FUN_180e59ff0(lVar1,*(undefined4 *)(*(longlong *)(param_1 + 0x28) + 0x50),0,1,
                  *(undefined8 *)
                   (*(longlong *)(*(longlong *)(lRam0000000182d5e230 + 0x20) + 0xc0) + 0x100));
    lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (((lVar1 != 0) && (*(longlong *)(param_1 + 0x28) != 0)) &&
       (lVar1 = *(longlong *)(lVar1 + 0x110), lVar1 != 0)) {
      FUN_180e59ff0(lVar1,*(undefined4 *)(*(longlong *)(param_1 + 0x28) + 0x50),0,1,
                    *(undefined8 *)
                     (*(longlong *)(*(longlong *)(lRam0000000182d5e230 + 0x20) + 0xc0) + 0x100));
      *(undefined4 *)(param_1 + 0x34) = 0xc479c000;
      *(undefined4 *)(param_1 + 0x38) = 0xc479c000;
      *(undefined1 *)(param_1 + 0x3d) = 0;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

