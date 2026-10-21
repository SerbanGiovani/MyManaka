// Ghidra pseudocode; not original source or compilable C.
// ev_0ca44821019e00eae045305065cd669b2ecc7f2b3602a5a7ecc1f8d2144a0e99

ulonglong ExposureUnnoticed2_Scripts_InGame_StageTransController__IsAbleTransStage__06001667(void)

{
  longlong lVar1;
  char cVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  if (cRam0000000182eb7a39 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fee0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5fed8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a39 = '\x01';
  }
  cVar2 = ExposureUnnoticed2_Scripts_InGame_FashionShopManager__IsWearTryClothes__06001612(0);
  uVar3 = uRam0000000182d5fee0;
  if (cVar2 == '\0') {
    lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    uVar3 = uRam0000000182d5fed8;
    if (*(int *)(lVar1 + 0x1a0) != 0) {
      return CONCAT71((int7)((ulonglong)lVar1 >> 8),1);
    }
  }
  uVar3 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar3,0);
  uVar4 = ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
                    (uVar3,0,0);
  return uVar4 & 0xffffffffffffff00;
}

