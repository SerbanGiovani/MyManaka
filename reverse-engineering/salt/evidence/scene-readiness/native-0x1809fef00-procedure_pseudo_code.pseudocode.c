// Ghidra pseudocode; not original source or compilable C.
// ev_94b7fefc99cdb89230ffc7a64979b2e4223c1275af3e6c74175814dd6a10b8ff

undefined8 native_only_1809fef00__00000000(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  int iVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  uint uVar9;
  bool bVar10;
  undefined *puStack_30;
  longlong lStack_28;
  undefined8 uStack_20;
  
  if (*(longlong *)(param_3 + 0x38) == 0) {
    puStack_30 = &UNK_1809fef2b;
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    if (*(longlong *)(param_3 + 0x38) == 0) {
      puStack_30 = &UNK_1809fef3f;
      FUN_1803204f0(param_3);
    }
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    puStack_30 = &UNK_1809fef57;
    FUN_18035c820(DAT_182d60278);
  }
  lVar6 = *(longlong *)(*(longlong *)(param_3 + 0x38) + 8);
  lVar7 = *(longlong *)(*(longlong *)(DAT_182d60278 + 0xb8) + 0x18);
  if (*(longlong *)(lVar6 + 0x38) == 0) {
    puStack_30 = &UNK_180746809;
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar6 + 0x38) == 0) {
      puStack_30 = &UNK_18074681d;
      FUN_1803204f0(lVar6);
    }
  }
  puStack_30 = &UNK_180746829;
  lVar8 = FUN_1802c43a0(DAT_182d534a8);
  puStack_30 = &UNK_180746839;
  ES3Settings___ctor__060001ba(lVar8,1,0);
  if ((lVar7 != 0) && (bVar10 = DAT_182eb5d50 != 0, *(longlong *)(lVar8 + 0x18) = lVar7, bVar10)) {
    uVar9 = (uint)(lVar8 + 0x18U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar3 == uVar2) {
        *puVar1 = uVar3 | 1L << (uVar9 & 0x3f);
      }
      UNLOCK();
    } while (uVar3 != uVar2);
  }
  lVar6 = *(longlong *)(*(longlong *)(lVar6 + 0x38) + 8);
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
  lVar7 = 0;
  if (lVar8 == 0) {
LAB_1807467b7:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  iVar4 = ES3Settings__get_location__060001b2(lVar8,0);
  if (iVar4 == 4) {
    if (*(int *)(DAT_182d53490 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar7 = ES3File__GetOrCreateCachedFile__06000135(lVar8,0);
    if (lVar7 == 0) goto LAB_1807467b7;
    param_2 = FUN_18074d940(lVar7,param_1,param_2,*(undefined8 *)(*(longlong *)(lVar6 + 0x38) + 8));
  }
  else {
    plVar5 = (longlong *)ES3Reader__Create__06000198(lVar8,0);
    if (plVar5 != (longlong *)0x0) {
      lVar6 = *(longlong *)(*(longlong *)(lVar6 + 0x38) + 0x10);
      puStack_30 = *(undefined **)(*plVar5 + ((ulonglong)*(ushort *)(lVar6 + 0x50) + 0x14) * 0x10);
      if ((puStack_30[0x53] & 2) != 0) {
        lVar7 = (*(longlong **)(puStack_30 + 0x40))[1];
        puStack_30 = (undefined *)**(longlong **)(puStack_30 + 0x40);
      }
      uStack_20 = *(undefined8 *)(*(longlong *)(lVar6 + 0x40) + 0x10);
      lStack_28 = lVar7;
      lVar6 = FUN_180306310(&puStack_30,CONCAT71((int7)((ulonglong)uStack_20 >> 8),1));
      param_2 = (**(code **)(lVar6 + 8))(plVar5,param_1,param_2,lVar6);
      if (plVar5 != (longlong *)0x0) {
        FUN_180002c20(0,DAT_182d53498);
      }
    }
  }
  return param_2;
}

