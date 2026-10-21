// Ghidra pseudocode; not original source or compilable C.
// ev_a88284cd6cecc8993fd254ea821914ce9d9b445fe8ac9202415bf843f946fb36

ulonglong ExposureUnnoticed2_Scripts_InGame_SaveManager__LoadSaveDataSlotIndex__06001603
                    (undefined4 param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong uVar10;
  bool bVar11;
  undefined *puStack_30;
  longlong lStack_28;
  undefined8 uStack_20;
  
  if (cRam0000000182eb7a00 == '\0') {
    puStack_30 = &UNK_18049f1ad;
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    puStack_30 = &UNK_18049f1be;
    FUN_1802f2810(0x182d60178);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a00 = '\x01';
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    puStack_30 = &UNK_18049f1df;
    FUN_18035c820();
  }
  puStack_30 = &UNK_18049f1ee;
  ExposureUnnoticed2_Scripts_Base_SaveRapper__PreProcess__060017b8(0,param_1,0,0);
  uVar3 = uRam0000000182d60178;
  if (cRam0000000182eb7ae0 == '\0') {
    puStack_30 = &UNK_1804ba9e4;
    FUN_1802f2810(0x182d5f458,0xffffffff,0);
    LOCK();
    UNLOCK();
    puStack_30 = &UNK_1804ba9f5;
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    cRam0000000182eb7ae0 = '\x01';
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    puStack_30 = &UNK_1804baa19;
    FUN_18035c820(DAT_182d60278);
  }
  lVar9 = lRam0000000182d5f458;
  lVar8 = *(longlong *)(*(longlong *)(DAT_182d60278 + 0xb8) + 0x18);
  if (*(longlong *)(lRam0000000182d5f458 + 0x38) == 0) {
    puStack_30 = &UNK_1804baa45;
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar9 + 0x38) == 0) {
      puStack_30 = &UNK_1804baa59;
      FUN_1803204f0(lVar9);
    }
  }
  puStack_30 = &UNK_1804baa65;
  lVar6 = FUN_1802c43a0(DAT_182d534a8);
  puStack_30 = &UNK_1804baa75;
  ES3Settings___ctor__060001ba(lVar6,1,0);
  if ((lVar8 != 0) && (bVar11 = DAT_182eb5d50 != 0, *(longlong *)(lVar6 + 0x18) = lVar8, bVar11)) {
    uVar5 = (uint)(lVar6 + 0x18U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8);
    do {
      uVar2 = *puVar1;
      LOCK();
      uVar10 = *puVar1;
      if (uVar2 == uVar10) {
        *puVar1 = uVar2 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (uVar2 != uVar10);
  }
  lVar8 = *(longlong *)(*(longlong *)(lVar9 + 0x38) + 8);
  uVar5 = 0xffffffff;
  if (*(longlong *)(lVar8 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d53490);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53498);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar8 + 0x38) == 0) {
      FUN_1803204f0(lVar8);
    }
  }
  lVar9 = 0;
  if (lVar6 == 0) {
code_r0x0001807464f1:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  iVar4 = ES3Settings__get_location__060001b2(lVar6,0);
  if (iVar4 == 4) {
    if (*(int *)(DAT_182d53490 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar9 = ES3File__GetOrCreateCachedFile__06000135(lVar6,0);
    if (lVar9 == 0) goto code_r0x0001807464f1;
    uVar10 = FUN_18074d660(lVar9,uVar3,0xffffffff,*(undefined8 *)(*(longlong *)(lVar8 + 0x38) + 8));
  }
  else {
    plVar7 = (longlong *)ES3Reader__Create__06000198(lVar6,0);
    if (plVar7 != (longlong *)0x0) {
      lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0x38) + 0x10);
      puStack_30 = *(undefined **)(*plVar7 + ((ulonglong)*(ushort *)(lVar8 + 0x50) + 0x14) * 0x10);
      if ((puStack_30[0x53] & 2) != 0) {
        lVar9 = (*(longlong **)(puStack_30 + 0x40))[1];
        puStack_30 = (undefined *)**(longlong **)(puStack_30 + 0x40);
      }
      uStack_20 = *(undefined8 *)(*(longlong *)(lVar8 + 0x40) + 0x10);
      lStack_28 = lVar9;
      lVar8 = FUN_180306310(&puStack_30,CONCAT71((int7)((ulonglong)uStack_20 >> 8),1));
      uVar5 = (**(code **)(lVar8 + 8))(plVar7,uVar3,0xffffffff,lVar8);
      if (plVar7 != (longlong *)0x0) {
        FUN_180002c20(0,DAT_182d53498);
      }
    }
    uVar10 = (ulonglong)uVar5;
  }
  return uVar10;
}

