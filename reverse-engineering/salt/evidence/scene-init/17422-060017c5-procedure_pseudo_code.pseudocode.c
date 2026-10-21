// Ghidra pseudocode; not original source or compilable C.
// ev_f79476262084c8adedef347519da5d04985f808d17bec80e98de8508333e30d4

ulonglong ExposureUnnoticed2_Scripts_Base_SaveRapper__Load__060017c5
                    (undefined8 param_1,ulonglong param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong lVar8;
  longlong lVar9;
  bool bVar10;
  undefined *puStack_30;
  longlong lStack_28;
  undefined8 uStack_20;
  
  param_2 = param_2 & 0xffffffff;
  if (cRam0000000182eb7ae0 == '\0') {
    puStack_30 = &UNK_1804ba9e4;
    FUN_1802f2810(0x182d5f458);
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
  if ((lVar8 != 0) && (bVar10 = DAT_182eb5d50 != 0, *(longlong *)(lVar6 + 0x18) = lVar8, bVar10)) {
    uVar5 = (uint)(lVar6 + 0x18U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar3 == uVar2) {
        *puVar1 = uVar3 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (uVar3 != uVar2);
  }
  lVar8 = *(longlong *)(*(longlong *)(lVar9 + 0x38) + 8);
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
    param_2 = FUN_18074d660(lVar9,param_1,param_2,*(undefined8 *)(*(longlong *)(lVar8 + 0x38) + 8));
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
      uVar5 = (**(code **)(lVar8 + 8))(plVar7,param_1,param_2,lVar8);
      param_2 = (ulonglong)uVar5;
      if (plVar7 != (longlong *)0x0) {
        FUN_180002c20(0,DAT_182d53498);
      }
    }
  }
  return param_2;
}

