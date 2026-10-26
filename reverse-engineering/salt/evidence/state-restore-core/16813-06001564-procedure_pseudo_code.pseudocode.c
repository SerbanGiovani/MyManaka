// Ghidra pseudocode; not original source or compilable C.
// ev_cab8cf6a8ba1158371d779e4d8e78db430d7b38aba7ec910fe0bb06ddba30237

longlong ExposureUnnoticed2_Scripts_InGame_GameStateFacade__CreateDefaultLoadoutData__06001564(void)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  int iVar6;
  
  if (cRam0000000182eb79c7 == '\0') {
    FUN_1802f2810(0x182d5d940);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d938);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d930);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d928);
    LOCK();
    UNLOCK();
    cRam0000000182eb79c7 = '\x01';
  }
  lVar4 = FUN_1802c43a0(uRam0000000182d5d930);
  FUN_1811cf4f0(lVar4,uRam0000000182d5d938);
  iVar6 = 0;
  while( true ) {
    uVar5 = FUN_1802c43a0(uRam0000000182d5d928);
    ExposureUnnoticed2_ObjectUI_InventoryPanel_LoadoutData___ctor__060019e9(uVar5,0);
    lVar3 = lRam0000000182d5d940;
    if (lVar4 == 0) break;
    *(int *)(lVar4 + 0x1c) = *(int *)(lVar4 + 0x1c) + 1;
    lVar2 = *(longlong *)(lVar4 + 0x10);
    if (lVar2 == 0) break;
    uVar1 = *(uint *)(lVar4 + 0x18);
    if (uVar1 < *(uint *)(lVar2 + 0x18)) {
      *(uint *)(lVar4 + 0x18) = uVar1 + 1;
      FUN_180002cd0(lVar2,(longlong)(int)uVar1,uVar5);
    }
    else {
      FUN_1812741c0(lVar4,uVar5,
                    *(undefined8 *)(*(longlong *)(*(longlong *)(lVar3 + 0x20) + 0xc0) + 0x70));
    }
    iVar6 = iVar6 + 1;
    if (0x13 < iVar6) {
      return lVar4;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

