// Ghidra pseudocode; not original source or compilable C.
// ev_82f44c259abcc78b88eff2a851f6198b7c7eac98710149763d8f01b10f40c87d

ulonglong ExposureUnnoticed2_Scripts_Base_SaveRapper__Load__060017c8
                    (undefined8 param_1,byte param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint uVar9;
  bool bVar10;
  undefined *puStack_30;
  longlong lStack_28;
  undefined8 uStack_20;
  
  if (DAT_182eb7ae3 == '\0') {
    puStack_30 = &UNK_1804bad05;
    FUN_1802f2810(&DAT_182d5f440);
    LOCK();
    UNLOCK();
    puStack_30 = &UNK_1804bad16;
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    DAT_182eb7ae3 = '\x01';
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    puStack_30 = &UNK_1804bad3a;
    FUN_18035c820(DAT_182d60278);
  }
  lVar7 = DAT_182d5f440;
  lVar6 = *(longlong *)(*(longlong *)(DAT_182d60278 + 0xb8) + 0x18);
  if (*(longlong *)(DAT_182d5f440 + 0x38) == 0) {
    puStack_30 = &UNK_1804bad66;
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar7 + 0x38) == 0) {
      puStack_30 = &UNK_1804bad7a;
      FUN_1803204f0(lVar7);
    }
  }
  puStack_30 = &UNK_1804bad86;
  lVar4 = FUN_1802c43a0(DAT_182d534a8);
  puStack_30 = &UNK_1804bad96;
  ES3Settings___ctor__060001ba(lVar4,1,0);
  if ((lVar6 != 0) && (bVar10 = DAT_182eb5d50 != 0, *(longlong *)(lVar4 + 0x18) = lVar6, bVar10)) {
    uVar9 = (uint)(lVar4 + 0x18U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8);
    do {
      uVar2 = *puVar1;
      LOCK();
      uVar8 = *puVar1;
      if (uVar2 == uVar8) {
        *puVar1 = uVar2 | 1L << (uVar9 & 0x3f);
      }
      UNLOCK();
    } while (uVar2 != uVar8);
  }
  lVar6 = *(longlong *)(*(longlong *)(lVar7 + 0x38) + 8);
  if (*(longlong *)(lVar6 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d53490);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53498);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar6 + 0x38) == 0) {
      FUN_1803204f0(lVar6);
    }
  }
  if (lVar4 != 0) {
    iVar3 = ES3Settings__get_location__060001b2(lVar4,0);
    if (iVar3 != 4) {
      plVar5 = (longlong *)ES3Reader__Create__06000198(lVar4,0);
      lStack_28 = 0;
      if (plVar5 != (longlong *)0x0) {
        lVar6 = *(longlong *)(*(longlong *)(lVar6 + 0x38) + 0x10);
        puStack_30 = *(undefined **)(*plVar5 + ((ulonglong)*(ushort *)(lVar6 + 0x50) + 0x14) * 0x10)
        ;
        if ((puStack_30[0x53] & 2) != 0) {
          lStack_28 = (*(longlong **)(puStack_30 + 0x40))[1];
          puStack_30 = (undefined *)**(longlong **)(puStack_30 + 0x40);
        }
        uStack_20 = *(undefined8 *)(*(longlong *)(lVar6 + 0x40) + 0x10);
        lVar6 = FUN_180306310(&puStack_30,CONCAT71((int7)((ulonglong)uStack_20 >> 8),1));
        param_2 = (**(code **)(lVar6 + 8))(plVar5,param_1,param_2,lVar6);
        if (plVar5 != (longlong *)0x0) {
          FUN_180002c20(0,DAT_182d53498);
        }
      }
      return (ulonglong)param_2;
    }
    if (*(int *)(DAT_182d53490 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar7 = ES3File__GetOrCreateCachedFile__06000135(lVar4,0);
    if (lVar7 != 0) {
      uVar8 = FUN_18074cdb0(lVar7,param_1,param_2,*(undefined8 *)(*(longlong *)(lVar6 + 0x38) + 8));
      return uVar8;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

