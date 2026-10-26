// Ghidra pseudocode; not original source or compilable C.
// ev_03d05a1f32d66c96aab7cf7f2d293d882ec4268abccc6531f4e299e50b8f5c60

void ExposureUnnoticed2_Scripts_Base_SaveRapper__Save__060017bc
               (undefined8 param_1,undefined4 param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  longlong *plVar8;
  undefined8 uVar9;
  uint uVar10;
  bool bVar11;
  
  if (cRam0000000182eb7ada == '\0') {
    FUN_1802f2810(0x182d5f488);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    cRam0000000182eb7ada = '\x01';
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d60278);
  }
  lVar7 = lRam0000000182d5f488;
  lVar3 = *(longlong *)(*(longlong *)(DAT_182d60278 + 0xb8) + 0x18);
  if (*(longlong *)(lRam0000000182d5f488 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar7 + 0x38) == 0) {
      FUN_1803204f0(lVar7);
    }
  }
  lVar6 = FUN_1802c43a0(DAT_182d534a8);
  ES3Settings___ctor__060001ba(lVar6,1,0);
  if ((lVar3 != 0) && (bVar11 = DAT_182eb5d50 != 0, *(longlong *)(lVar6 + 0x18) = lVar3, bVar11)) {
    uVar10 = (uint)(lVar6 + 0x18U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8);
    do {
      uVar4 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar4 == uVar2) {
        *puVar1 = uVar4 | 1L << (uVar10 & 0x3f);
      }
      UNLOCK();
    } while (uVar4 != uVar2);
  }
  lVar3 = *(longlong *)(*(longlong *)(lVar7 + 0x38) + 8);
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
  if (lVar6 == 0) {
code_r0x000180748a7d:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  iVar5 = ES3Settings__get_location__060001b2(lVar6,0);
  if (iVar5 == 4) {
    if (*(int *)(DAT_182d53490 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar7 = ES3File__GetOrCreateCachedFile__06000135(lVar6,0);
    if (lVar7 == 0) goto code_r0x000180748a7d;
    FUN_18074f120(lVar7,param_1,param_2,*(undefined8 *)(*(longlong *)(lVar3 + 0x38) + 8));
  }
  else {
    lVar7 = ES3Internal_ES3Stream__CreateStream__060006e5(lVar6,1,0);
    plVar8 = (longlong *)0x0;
    if (lVar7 != 0) {
      plVar8 = (longlong *)ES3Writer__Create__06000280(lVar7,lVar6,1,1,0);
    }
    uVar9 = FUN_1802c3ff0(**(undefined8 **)(lVar3 + 0x38),&stack0x00000018);
    if (plVar8 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    FUN_180007d40(*(undefined8 *)(*(longlong *)(lVar3 + 0x38) + 0x10),plVar8,param_1,uVar9);
    if (plVar8 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    (**(code **)(*plVar8 + 0x478))(plVar8,*(undefined8 *)(*plVar8 + 0x480));
    if (plVar8 != (longlong *)0x0) {
      FUN_180002c20(0,DAT_182d53498);
    }
  }
  return;
}

