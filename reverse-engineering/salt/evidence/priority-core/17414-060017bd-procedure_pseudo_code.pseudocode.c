// Ghidra pseudocode; not original source or compilable C.
// ev_6504b9778e7c304711d7697261521eaeab3d7becdd7e0b3a65ff0e8289410c11

void ExposureUnnoticed2_Scripts_Base_SaveRapper__Save__060017bd
               (undefined8 param_1,undefined8 param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  int iVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong lVar8;
  uint uVar9;
  bool bVar10;
  
  if (cRam0000000182eb7adb == '\0') {
    FUN_1802f2810(0x182d5f480);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    cRam0000000182eb7adb = '\x01';
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d60278);
  }
  lVar6 = lRam0000000182d5f480;
  lVar3 = *(longlong *)(*(longlong *)(DAT_182d60278 + 0xb8) + 0x18);
  if (*(longlong *)(lRam0000000182d5f480 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar6 + 0x38) == 0) {
      FUN_1803204f0(lVar6);
    }
  }
  lVar8 = FUN_1802c43a0(DAT_182d534a8);
  ES3Settings___ctor__060001ba(lVar8,1,0);
  if ((lVar3 != 0) && (bVar10 = DAT_182eb5d50 != 0, *(longlong *)(lVar8 + 0x18) = lVar3, bVar10)) {
    uVar9 = (uint)(lVar8 + 0x18U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8);
    do {
      uVar4 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar4 == uVar2) {
        *puVar1 = uVar4 | 1L << (uVar9 & 0x3f);
      }
      UNLOCK();
    } while (uVar4 != uVar2);
  }
  lVar3 = *(longlong *)(*(longlong *)(lVar6 + 0x38) + 8);
  if (*(longlong *)(lVar3 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d53490);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53498);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar3 + 0x38) == 0) {
      FUN_1803204f0(lVar3);
    }
  }
  if (lVar8 == 0) {
LAB_180748d1e:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  iVar5 = ES3Settings__get_location__060001b2(lVar8,0);
  if (iVar5 == 4) {
    if (*(int *)(DAT_182d53490 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar6 = ES3File__GetOrCreateCachedFile__06000135(lVar8,0);
    if (lVar6 == 0) goto LAB_180748d1e;
    FUN_18074f470(lVar6,param_1,param_2,*(undefined8 *)(*(longlong *)(lVar3 + 0x38) + 8));
  }
  else {
    lVar6 = ES3Internal_ES3Stream__CreateStream__060006e5(lVar8,1,0);
    plVar7 = (longlong *)0x0;
    if (lVar6 != 0) {
      plVar7 = (longlong *)ES3Writer__Create__06000280(lVar6,lVar8,1,1,0);
    }
    if (plVar7 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    FUN_180007d40(*(undefined8 *)(*(longlong *)(lVar3 + 0x38) + 0x10),plVar7,param_1,param_2);
    if (plVar7 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    (**(code **)(*plVar7 + 0x478))(plVar7,*(undefined8 *)(*plVar7 + 0x480));
    if (plVar7 != (longlong *)0x0) {
      FUN_180002c20(0,DAT_182d53498);
    }
  }
  return;
}

