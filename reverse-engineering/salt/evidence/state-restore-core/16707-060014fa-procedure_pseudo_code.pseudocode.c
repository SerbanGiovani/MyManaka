// Ghidra pseudocode; not original source or compilable C.
// ev_f1006ca3577129d0753322140f937f5b23a8102fe26e7308114abb406779b3bc

void ExposureUnnoticed2_Scripts_InGame_DroppedItemManager___ctor__060014fa(longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  char cVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint uVar7;
  bool bVar8;
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
  undefined *puStack_30;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (cRam0000000182eb796c == '\0') {
    puStack_30 = &UNK_180488892;
    FUN_1802f2810(0x182d5dfe0);
    LOCK();
    UNLOCK();
    puStack_30 = &UNK_1804888a3;
    FUN_1802f2810(0x182d5dfd8);
    LOCK();
    UNLOCK();
    puStack_30 = &UNK_1804888b4;
    FUN_1802f2810(0x182d5dfd0);
    LOCK();
    UNLOCK();
    cRam0000000182eb796c = '\x01';
  }
  puStack_30 = &UNK_1804888cc;
  uVar5 = FUN_1802c43a0(uRam0000000182d5dfd8);
  puStack_30 = &UNK_1804888de;
  FUN_180e686d0(uVar5,uRam0000000182d5dfe0);
  bVar8 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x10) = uVar5;
  if (bVar8) {
    uVar7 = (uint)(param_1 + 0x10U >> 0xc);
    lVar6 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar6);
      LOCK();
      bVar8 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar6);
      if (bVar8) {
        *(ulonglong *)(&DAT_182f0c920 + lVar6) = uVar2 | 1L << (uVar7 & 0x3f);
      }
      UNLOCK();
    } while (!bVar8);
  }
  puStack_30 = &UNK_18048894a;
  lVar6 = FUN_1802c36c0(uRam0000000182d5dfd0,2);
  if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
    puStack_30 = &UNK_1804889ca;
    FUN_18031dad0();
  }
  if (*(uint *)(lVar6 + 0x18) < 2) {
                    /* WARNING: Subroutine does not return */
    puStack_30 = &UNK_1804889d0;
    FUN_18031dae0();
  }
  bVar8 = DAT_182eb5d50 != 0;
  *(undefined4 *)(lVar6 + 0x24) = 1;
  *(longlong *)(param_1 + 0x18) = lVar6;
  if (bVar8) {
    uVar7 = (uint)(param_1 + 0x18U >> 0xc);
    lVar6 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar6);
      LOCK();
      bVar8 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar6);
      if (bVar8) {
        *(ulonglong *)(&DAT_182f0c920 + lVar6) = uVar2 | 1L << (uVar7 & 0x3f);
      }
      UNLOCK();
    } while (!bVar8);
  }
  puStack_30 = &UNK_1804889b1;
  FUN_180498e50(param_1);
  if (cRam0000000182eb797c == '\0') {
    FUN_1802f2810(&DAT_182d5df60,0);
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
  lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((lVar6 != 0) && (lStack_78 = *(longlong *)(lVar6 + 0x18), lStack_78 != 0)) {
    uStack_68 = 0;
    uStack_60 = 0;
    if (DAT_182eb5d50 != 0) {
      uVar7 = (uint)((ulonglong)&lStack_78 >> 0xc);
      puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8);
      do {
        uVar3 = *puVar1;
        LOCK();
        uVar2 = *puVar1;
        if (uVar3 == uVar2) {
          *puVar1 = uVar3 | 1L << (uVar7 & 0x3f);
        }
        UNLOCK();
      } while (uVar3 != uVar2);
    }
    uStack_70 = (ulonglong)*(uint *)(lStack_78 + 0x2c);
    uStack_58 = 2;
    uStack_48 = uStack_70;
    uStack_40 = 0;
    lStack_38 = 0;
    puStack_30 = (undefined *)0x2;
    uStack_88 = 0;
    plStack_80 = &lStack_50;
    lStack_50 = lStack_78;
    while( true ) {
      cVar4 = FUN_180f89450(&lStack_50,DAT_182d5df58);
      if (cVar4 == '\0') {
        return;
      }
      if (lStack_38 == 0) break;
      if (*(char *)(lStack_38 + 0x10) != '\0') {
        lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        if (*(int *)(lStack_38 + 0x30) == *(int *)(lVar6 + 0x10)) {
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

