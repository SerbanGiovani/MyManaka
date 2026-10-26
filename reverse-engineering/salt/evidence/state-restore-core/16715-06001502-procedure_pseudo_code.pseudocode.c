// Ghidra pseudocode; not original source or compilable C.
// ev_6a581d3757bf27b88c1843182c9134668b8fb95794b49951002a3a193eaeae4b

longlong ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__ReserveDrop__06001502
                   (undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  
  if (cRam0000000182eb7972 == '\0') {
    FUN_1802f2810(0x182d5df78);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5df70);
    LOCK();
    UNLOCK();
    cRam0000000182eb7972 = '\x01';
  }
  lVar5 = FUN_1802c43a0(uRam0000000182d5df78);
  *(undefined4 *)(lVar5 + 0x34) = param_2;
  *(undefined4 *)(lVar5 + 0x30) = param_3;
  *(undefined1 *)(lVar5 + 0x11) = 1;
  lVar4 = lRam0000000182d5df70;
  lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((lVar2 != 0) && (lVar2 = *(longlong *)(lVar2 + 0x28), lVar2 != 0)) {
    *(int *)(lVar2 + 0x1c) = *(int *)(lVar2 + 0x1c) + 1;
    lVar3 = *(longlong *)(lVar2 + 0x10);
    if (lVar3 != 0) {
      uVar1 = *(uint *)(lVar2 + 0x18);
      if (*(uint *)(lVar3 + 0x18) <= uVar1) {
        FUN_1812741c0(lVar2,lVar5,
                      *(undefined8 *)(*(longlong *)(*(longlong *)(lVar4 + 0x20) + 0xc0) + 0x70));
        return lVar5;
      }
      *(uint *)(lVar2 + 0x18) = uVar1 + 1;
      FUN_180002cd0(lVar3,(longlong)(int)uVar1,lVar5);
      return lVar5;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

