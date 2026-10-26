// Ghidra pseudocode; not original source or compilable C.
// ev_fe089d6fb13028d711547ba0b445684fc1c224a3d90f8c849fcc52c5d31157c3

void ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__Collect__06001507
               (undefined8 param_1,int param_2)

{
  longlong lVar1;
  undefined8 uStack_18;
  undefined4 uStack_10;
  
  if (cRam0000000182eb7976 == '\0') {
    FUN_1802f2810(0x182d5df40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5df80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb7976 = '\x01';
  }
  ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__Hide__06001504(param_1,param_2,0);
  if (param_2 != 2) {
    lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if ((lVar1 != 0) && (lVar1 = *(longlong *)(lVar1 + 0x18), lVar1 != 0)) {
      lVar1 = FUN_180e75f20(lVar1,param_2,uRam0000000182d5df80);
      if (lVar1 != 0) {
        *(undefined1 *)(lVar1 + 0x10) = 0;
        return;
      }
    }
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (*(int *)(lRam0000000182d5df40 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5df40);
  }
  uStack_18 = **(undefined8 **)(lRam0000000182d5df40 + 0xb8);
  uStack_10 = *(undefined4 *)(*(undefined8 **)(lRam0000000182d5df40 + 0xb8) + 1);
  ExposureUnnoticed2_Scripts_InGame_FashionShopManager__SaveDropBasket__06001610(&uStack_18,0);
  return;
}

