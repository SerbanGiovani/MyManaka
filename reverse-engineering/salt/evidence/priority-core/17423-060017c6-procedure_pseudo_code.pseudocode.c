// Ghidra pseudocode; not original source or compilable C.
// ev_171e6401a7f474e1d7ab1c5668a2d87dadda77d69b96fdbf9d890fc414e49b78

undefined8
ExposureUnnoticed2_Scripts_Base_SaveRapper__Load__060017c6(undefined8 param_1,undefined8 param_2)

{
  ulonglong uVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  uint uVar8;
  bool bVar9;
  longlong lStack_30;
  longlong lStack_28;
  undefined8 uStack_20;
  
  if (cRam0000000182eb7ae1 == '\0') {
    FUN_1802f2810(0x182d5f450);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    cRam0000000182eb7ae1 = '\x01';
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d60278);
  }
  lVar6 = lRam0000000182d5f450;
  lVar5 = *(longlong *)(*(longlong *)(DAT_182d60278 + 0xb8) + 0x18);
  if (*(longlong *)(lRam0000000182d5f450 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar6 + 0x38) == 0) {
      FUN_1803204f0(lVar6);
    }
  }
  lVar3 = FUN_1802c43a0(DAT_182d534a8);
  ES3Settings___ctor__060001ba(lVar3,1,0);
  if ((lVar5 != 0) && (bVar9 = DAT_182eb5d50 != 0, *(longlong *)(lVar3 + 0x18) = lVar5, bVar9)) {
    uVar8 = (uint)(lVar3 + 0x18U >> 0xc);
    uVar7 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
      LOCK();
      bVar9 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
      if (bVar9) {
        *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8) = uVar1 | 1L << (uVar8 & 0x3f);
      }
      UNLOCK();
    } while (!bVar9);
  }
  lVar5 = *(longlong *)(*(longlong *)(lVar6 + 0x38) + 8);
  if (*(longlong *)(lVar5 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d53490);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53498);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar5 + 0x38) == 0) {
      FUN_1803204f0(lVar5);
    }
  }
  if (lVar3 == 0) {
code_r0x000180746230:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  iVar2 = ES3Settings__get_location__060001b2(lVar3,0);
  if (iVar2 == 4) {
    if (*(int *)(DAT_182d53490 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar6 = ES3File__GetOrCreateCachedFile__06000135(lVar3,0);
    if (lVar6 == 0) goto code_r0x000180746230;
    param_2 = FUN_18074d370(lVar6,param_1,(int)param_2,
                            *(undefined8 *)(*(longlong *)(lVar5 + 0x38) + 8));
  }
  else {
    plVar4 = (longlong *)ES3Reader__Create__06000198(lVar3,0);
    lStack_28 = 0;
    if (plVar4 != (longlong *)0x0) {
      lVar5 = *(longlong *)(*(longlong *)(lVar5 + 0x38) + 0x10);
      lStack_30 = *(longlong *)(*plVar4 + ((ulonglong)*(ushort *)(lVar5 + 0x50) + 0x14) * 0x10);
      if ((*(byte *)(lStack_30 + 0x53) & 2) != 0) {
        lStack_28 = (*(longlong **)(lStack_30 + 0x40))[1];
        lStack_30 = **(longlong **)(lStack_30 + 0x40);
      }
      uStack_20 = *(undefined8 *)(*(longlong *)(lVar5 + 0x40) + 0x10);
      lVar5 = FUN_180306310(&lStack_30,CONCAT71((int7)((ulonglong)uStack_20 >> 8),1));
      param_2 = (**(code **)(lVar5 + 8))(plVar4,param_1,(int)param_2,lVar5);
      if (plVar4 != (longlong *)0x0) {
        FUN_180002c20(0,DAT_182d53498);
      }
    }
  }
  return param_2;
}

