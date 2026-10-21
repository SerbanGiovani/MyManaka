// Ghidra pseudocode; not original source or compilable C.
// ev_66e58011ce3abd39bbcb9e49ae7568933633d738364ff60977f4fd05bff9c27e

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationReceiver__CommonStartAnim__06000c62
               (longlong param_1)

{
  longlong lVar1;
  int iVar2;
  undefined8 uStack_18;
  undefined4 uStack_10;
  
  if (cRam0000000182eb8385 == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb8385 = '\x01';
  }
  if (((*(longlong *)(param_1 + 0x40) != 0) &&
      (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60), lVar1 != 0)) &&
     (lVar1 = *(longlong *)(lVar1 + 0x48), lVar1 != 0)) {
    iVar2 = *(int *)(lVar1 + 0x18);
    if (iVar2 == 0x271f) {
      if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
         (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x20), lVar1 == 0))
      goto code_r0x00018062c5c6;
      iVar2 = 3;
    }
    else {
      if (iVar2 != 0x2721) {
        return;
      }
      if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
         (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x20), lVar1 == 0))
      goto code_r0x00018062c5c6;
      iVar2 = 4;
    }
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
    ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__Hide__06001504(lVar1,iVar2,0);
    if (iVar2 != 2) {
      lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if ((lVar1 != 0) && (lVar1 = *(longlong *)(lVar1 + 0x18), lVar1 != 0)) {
        lVar1 = FUN_180e75f20(lVar1,iVar2,uRam0000000182d5df80);
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
code_r0x00018062c5c6:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

