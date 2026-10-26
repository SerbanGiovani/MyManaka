// Ghidra pseudocode; not original source or compilable C.
// ev_1ceff35a36115d5651c416423a4de4430807e197f597fdb6bcb834088733c762

void native_only_1809ff300__00000000(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  int iVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong lVar8;
  uint uVar9;
  bool bVar10;
  
  if (*(longlong *)(param_3 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    if (*(longlong *)(param_3 + 0x38) == 0) {
      FUN_1803204f0(param_3);
    }
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d60278);
  }
  lVar4 = *(longlong *)(*(longlong *)(param_3 + 0x38) + 8);
  lVar6 = *(longlong *)(*(longlong *)(DAT_182d60278 + 0xb8) + 0x18);
  if (*(longlong *)(lVar4 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar4 + 0x38) == 0) {
      FUN_1803204f0(lVar4);
    }
  }
  lVar8 = FUN_1802c43a0(DAT_182d534a8);
  ES3Settings___ctor__060001ba(lVar8,1,0);
  if ((lVar6 != 0) && (bVar10 = DAT_182eb5d50 != 0, *(longlong *)(lVar8 + 0x18) = lVar6, bVar10)) {
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
  lVar4 = *(longlong *)(*(longlong *)(lVar4 + 0x38) + 8);
  if (*(longlong *)(lVar4 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d53490);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53498);
    LOCK();
    UNLOCK();
    if (*(longlong *)(lVar4 + 0x38) == 0) {
      FUN_1803204f0(lVar4);
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
    FUN_18074f470(lVar6,param_1,param_2,*(undefined8 *)(*(longlong *)(lVar4 + 0x38) + 8));
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
    FUN_180007d40(*(undefined8 *)(*(longlong *)(lVar4 + 0x38) + 0x10),plVar7,param_1,param_2);
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

