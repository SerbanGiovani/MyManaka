// Ghidra pseudocode; not original source or compilable C.
// ev_58753be1bd13f64b0ec58049d6166a90acac048a782ce764c550b0e26db163c5

void ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__OnLateUpdate__0600109e(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  char cVar4;
  ulonglong uVar5;
  uint uVar6;
  bool bVar7;
  undefined8 uStack_50;
  undefined4 *puStack_48;
  undefined8 uStack_40;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  longlong lStack_28;
  
  if (cRam0000000182eb7774 == '\0') {
    FUN_1802f2810(&DAT_182d595a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59598);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59590);
    LOCK();
    UNLOCK();
    FUN_1802f2810();
    LOCK();
    UNLOCK();
    cRam0000000182eb7774 = '\x01';
  }
  lVar1 = *(longlong *)(param_1 + 0x38);
  if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (DAT_182eb5d50 != 0) {
    uVar6 = (uint)((ulonglong)&uStack_50 >> 0xc);
    uVar5 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8);
      LOCK();
      bVar7 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8) = uVar2 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  uStack_2c = *(undefined4 *)(lVar1 + 0x1c);
  uStack_40 = 0;
  uStack_50._0_4_ = (undefined4)lVar1;
  uStack_50._4_4_ = (undefined4)((ulonglong)lVar1 >> 0x20);
  uStack_38 = (undefined4)uStack_50;
  uStack_34 = uStack_50._4_4_;
  uStack_30 = 0;
  lStack_28 = 0;
  uStack_50 = 0;
  puStack_48 = &uStack_38;
  while( true ) {
    do {
      cVar4 = FUN_180f72b70(&uStack_38,DAT_182d59598);
      lVar1 = lStack_28;
      if (cVar4 == '\0') {
        return;
      }
      if (lStack_28 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      if (*(longlong *)(lStack_28 + 0x48) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
    } while (15.0 < *(float *)(*(longlong *)(lStack_28 + 0x48) + 0xd8));
    if (*(longlong *)(lStack_28 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    lVar3 = *(longlong *)(*(longlong *)(lStack_28 + 0x30) + 0x48);
    if (lVar3 == 0) break;
    ExposureUnnoticed2_Object3D_Player_Scripts_LookAtController__OnLateUpdate__06000c16(lVar3,0);
    if (*(longlong *)(lVar1 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    lVar1 = *(longlong *)(*(longlong *)(lVar1 + 0x30) + 0x68);
    if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    ExposureUnnoticed2_Object3D_NPC_Script_PlayerSearcher__OnLateUpdate__060010d5(lVar1,0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

