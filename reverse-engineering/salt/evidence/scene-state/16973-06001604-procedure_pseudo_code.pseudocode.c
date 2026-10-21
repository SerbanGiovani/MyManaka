// Ghidra pseudocode; not original source or compilable C.
// ev_798d273512122181d9e5a8aa32b781bee2ca2ab8a4679bd8a7d89ab74e0929ee

ulonglong ExposureUnnoticed2_Scripts_InGame_SaveManager__LoadSaveDataIsTrial__06001604
                    (undefined4 param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  byte bVar4;
  int iVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong uVar10;
  uint uVar11;
  bool bVar12;
  undefined *puStack_30;
  longlong lStack_28;
  undefined8 uStack_20;
  
  if (DAT_182eb7a01 == '\0') {
    puStack_30 = &UNK_18049f23b;
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    puStack_30 = &UNK_18049f24c;
    FUN_1802f2810(&DAT_182d60170);
    LOCK();
    UNLOCK();
    DAT_182eb7a01 = '\x01';
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    puStack_30 = &UNK_18049f26d;
    FUN_18035c820();
  }
  puStack_30 = &UNK_18049f27c;
  ExposureUnnoticed2_Scripts_Base_SaveRapper__PreProcess__060017b8(0,param_1,0,0);
  uVar3 = DAT_182d60170;
  if (DAT_182eb7ae3 == '\0') {
    puStack_30 = &UNK_18049f298;
    FUN_1802f2810(&DAT_182d5f440);
    LOCK();
    UNLOCK();
    puStack_30 = &UNK_18049f2a9;
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    DAT_182eb7ae3 = '\x01';
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    puStack_30 = &UNK_18049f2cd;
    FUN_18035c820(DAT_182d60278);
  }
  lVar9 = DAT_182d5f440;
  lVar8 = *(longlong *)(*(longlong *)(DAT_182d60278 + 0xb8) + 0x18);
  if (*(longlong *)(DAT_182d5f440 + 0x38) == 0) {
    puStack_30 = &UNK_18049f2f9;
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar9 + 0x38) == 0) {
      puStack_30 = &UNK_18049f30d;
      FUN_1803204f0(lVar9);
    }
  }
  puStack_30 = &UNK_18049f319;
  lVar6 = FUN_1802c43a0(DAT_182d534a8);
  puStack_30 = &UNK_18049f329;
  ES3Settings___ctor__060001ba(lVar6,1,0);
  if ((lVar8 != 0) && (bVar12 = DAT_182eb5d50 != 0, *(longlong *)(lVar6 + 0x18) = lVar8, bVar12)) {
    uVar11 = (uint)(lVar6 + 0x18U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8);
    do {
      uVar2 = *puVar1;
      LOCK();
      uVar10 = *puVar1;
      if (uVar2 == uVar10) {
        *puVar1 = uVar2 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
    } while (uVar2 != uVar10);
  }
  lVar8 = *(longlong *)(*(longlong *)(lVar9 + 0x38) + 8);
  bVar4 = 1;
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
  if (lVar6 != 0) {
    iVar5 = ES3Settings__get_location__060001b2(lVar6,0);
    if (iVar5 != 4) {
      plVar7 = (longlong *)ES3Reader__Create__06000198(lVar6,0);
      lStack_28 = 0;
      if (plVar7 != (longlong *)0x0) {
        lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0x38) + 0x10);
        puStack_30 = *(undefined **)(*plVar7 + ((ulonglong)*(ushort *)(lVar8 + 0x50) + 0x14) * 0x10)
        ;
        if ((puStack_30[0x53] & 2) != 0) {
          lStack_28 = (*(longlong **)(puStack_30 + 0x40))[1];
          puStack_30 = (undefined *)**(longlong **)(puStack_30 + 0x40);
        }
        uStack_20 = *(undefined8 *)(*(longlong *)(lVar8 + 0x40) + 0x10);
        lVar8 = FUN_180306310(&puStack_30,CONCAT71((int7)((ulonglong)uStack_20 >> 8),1));
        bVar4 = (**(code **)(lVar8 + 8))(plVar7,uVar3,1,lVar8);
        if (plVar7 != (longlong *)0x0) {
          FUN_180002c20(0,DAT_182d53498);
        }
      }
      return (ulonglong)bVar4;
    }
    if (*(int *)(DAT_182d53490 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar9 = ES3File__GetOrCreateCachedFile__06000135(lVar6,0);
    if (lVar9 != 0) {
      uVar10 = FUN_18074cdb0(lVar9,uVar3,1,*(undefined8 *)(*(longlong *)(lVar8 + 0x38) + 8));
      return uVar10;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

