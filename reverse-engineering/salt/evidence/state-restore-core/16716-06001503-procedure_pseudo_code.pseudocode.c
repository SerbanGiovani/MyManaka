// Ghidra pseudocode; not original source or compilable C.
// ev_f08a2be6b71929bc2838bbdfa22bb97f08522781a52a44c82a94c6df9d944f04

void ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__SendToHome__06001503
               (undefined8 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (cRam0000000182eb7973 == '\0') {
    FUN_1802f2810(0x182d5df80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb7973 = '\x01';
  }
  ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__GetCache__060014fd(param_1,param_2,0);
  lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((lVar2 != 0) && (lVar2 = *(longlong *)(lVar2 + 0x18), lVar2 != 0)) {
    lVar2 = FUN_180e75f20(lVar2,param_2,uRam0000000182d5df80);
    if (lVar2 != 0) {
      *(undefined1 *)(lVar2 + 0x10) = 1;
      lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if ((lVar2 != 0) && (lVar2 = *(longlong *)(lVar2 + 0x18), lVar2 != 0)) {
        lVar2 = FUN_180e75f20(lVar2,param_2,uRam0000000182d5df80);
        lVar3 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
        if ((lVar3 != 0) && (uVar1 = *(undefined4 *)(lVar3 + 0x1b8), lVar2 != 0)) {
          *(undefined8 *)(lVar2 + 0x14) = *(undefined8 *)(lVar3 + 0x1b0);
          *(undefined4 *)(lVar2 + 0x1c) = uVar1;
          lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if ((lVar2 != 0) && (lVar2 = *(longlong *)(lVar2 + 0x18), lVar2 != 0)) {
            lVar2 = FUN_180e75f20(lVar2,param_2,uRam0000000182d5df80);
            if (lVar2 != 0) {
              *(undefined4 *)(lVar2 + 0x30) = 0;
              return;
            }
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

