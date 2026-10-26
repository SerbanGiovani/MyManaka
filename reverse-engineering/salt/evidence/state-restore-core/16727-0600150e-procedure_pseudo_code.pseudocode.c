// Ghidra pseudocode; not original source or compilable C.
// ev_adc564466307e57cf216a145185c47f38871d5aee738fb60107b7f68bbc743ac

void ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__ActiveDroppedItemIfNeed__0600150e
               (undefined8 param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  char cVar5;
  uint uVar6;
  undefined8 uStack_98;
  undefined4 uStack_90;
  undefined8 uStack_88;
  longlong *plStack_80;
  longlong lStack_78;
  ulonglong uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  longlong lStack_50;
  ulonglong uStack_48;
  undefined8 uStack_40;
  longlong lStack_38;
  undefined8 uStack_30;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (cRam0000000182eb797c == '\0') {
    FUN_1802f2810(&DAT_182d5df60);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5df68);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5df58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5df50);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5df48);
    LOCK();
    UNLOCK();
    cRam0000000182eb797c = '\x01';
  }
  lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((lVar3 != 0) && (lStack_78 = *(longlong *)(lVar3 + 0x18), lStack_78 != 0)) {
    uStack_68 = 0;
    uStack_60 = 0;
    if (DAT_182eb5d50 != 0) {
      uVar6 = (uint)((ulonglong)&lStack_78 >> 0xc);
      puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8);
      do {
        uVar4 = *puVar1;
        LOCK();
        uVar2 = *puVar1;
        if (uVar4 == uVar2) {
          *puVar1 = uVar4 | 1L << (uVar6 & 0x3f);
        }
        UNLOCK();
      } while (uVar4 != uVar2);
    }
    uStack_70 = (ulonglong)*(uint *)(lStack_78 + 0x2c);
    uStack_58 = 2;
    uStack_48 = uStack_70;
    uStack_40 = 0;
    lStack_38 = 0;
    uStack_30 = 2;
    uStack_88 = 0;
    plStack_80 = &lStack_50;
    lStack_50 = lStack_78;
    while( true ) {
      cVar5 = FUN_180f89450(&lStack_50,DAT_182d5df58);
      if (cVar5 == '\0') {
        return;
      }
      if (lStack_38 == 0) break;
      if (*(char *)(lStack_38 + 0x10) != '\0') {
        lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        if (*(int *)(lStack_38 + 0x30) == *(int *)(lVar3 + 0x10)) {
          uStack_18 = *(undefined4 *)(lStack_38 + 0x20);
          uStack_14 = *(undefined4 *)(lStack_38 + 0x24);
          uStack_10 = *(undefined4 *)(lStack_38 + 0x28);
          uStack_c = *(undefined4 *)(lStack_38 + 0x2c);
          uStack_98 = *(undefined8 *)(lStack_38 + 0x14);
          uStack_90 = *(undefined4 *)(lStack_38 + 0x1c);
          ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__Drop__060014ff
                    (param_1,&uStack_98,&uStack_18,*(undefined4 *)(lStack_38 + 0x34),0);
        }
        else if (*(char *)(lStack_38 + 0x10) != '\0') {
          ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__Hide__06001504
                    (param_1,*(undefined4 *)(lStack_38 + 0x34),0);
        }
      }
    }
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

