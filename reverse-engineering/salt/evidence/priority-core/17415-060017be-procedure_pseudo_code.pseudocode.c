// Ghidra pseudocode; not original source or compilable C.
// ev_9ddef8f1452696128f672751310e11f4367dfb6b0d50eba92c7efae4ccf1150b

void ExposureUnnoticed2_Scripts_Base_SaveRapper__Save__060017be
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 uVar7;
  undefined8 in_RDX;
  ulonglong uVar8;
  uint uVar9;
  bool bVar10;
  undefined4 unaff_XMM6_Da;
  undefined4 unaff_XMM6_Db;
  undefined4 unaff_XMM6_Dc;
  undefined4 unaff_XMM6_Dd;
  undefined8 uStackX_20;
  
  if (cRam0000000182eb7adc == '\0') {
    FUN_1802f2810(0x182d5f478,in_RDX,param_3,param_4,CONCAT44(unaff_XMM6_Db,unaff_XMM6_Da),
                  CONCAT44(unaff_XMM6_Dd,unaff_XMM6_Dc));
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    cRam0000000182eb7adc = '\x01';
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d60278);
  }
  lVar5 = lRam0000000182d5f478;
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d60278 + 0xb8) + 0x18);
  if (*(longlong *)(lRam0000000182d5f478 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar5 + 0x38) == 0) {
      FUN_1803204f0(lVar5);
    }
  }
  lVar4 = FUN_1802c43a0(DAT_182d534a8);
  ES3Settings___ctor__060001ba(lVar4,1,0);
  if ((lVar1 != 0) && (bVar10 = DAT_182eb5d50 != 0, *(longlong *)(lVar4 + 0x18) = lVar1, bVar10)) {
    uVar9 = (uint)(lVar4 + 0x18U >> 0xc);
    uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
      LOCK();
      bVar10 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
      if (bVar10) {
        *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar2 | 1L << (uVar9 & 0x3f);
      }
      UNLOCK();
    } while (!bVar10);
  }
  lVar1 = *(longlong *)(*(longlong *)(lVar5 + 0x38) + 8);
  if (*(longlong *)(lVar1 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d53490);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53498);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar1 + 0x38) == 0) {
      FUN_1803204f0(lVar1);
    }
  }
  if (lVar4 == 0) {
code_r0x0001807487be:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  iVar3 = ES3Settings__get_location__060001b2(lVar4,0);
  if (iVar3 == 4) {
    if (*(int *)(DAT_182d53490 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar5 = ES3File__GetOrCreateCachedFile__06000135(lVar4,0);
    if (lVar5 == 0) goto code_r0x0001807487be;
    FUN_18074edc0(lVar5,param_1,(int)param_2,*(undefined8 *)(*(longlong *)(lVar1 + 0x38) + 8));
  }
  else {
    lVar5 = ES3Internal_ES3Stream__CreateStream__060006e5(lVar4,1,0);
    plVar6 = (longlong *)0x0;
    if (lVar5 != 0) {
      plVar6 = (longlong *)ES3Writer__Create__06000280(lVar5,lVar4,1,1,0);
    }
    uStackX_20 = param_2;
    uVar7 = FUN_1802c3ff0(**(undefined8 **)(lVar1 + 0x38),&uStackX_20);
    if (plVar6 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    FUN_180007d40(*(undefined8 *)(*(longlong *)(lVar1 + 0x38) + 0x10),plVar6,param_1,uVar7);
    if (plVar6 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    (**(code **)(*plVar6 + 0x478))(plVar6,*(undefined8 *)(*plVar6 + 0x480));
    if (plVar6 != (longlong *)0x0) {
      FUN_180002c20(0,DAT_182d53498);
    }
  }
  return;
}

