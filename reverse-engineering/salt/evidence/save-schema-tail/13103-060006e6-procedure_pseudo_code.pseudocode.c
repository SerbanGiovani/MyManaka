// Ghidra pseudocode; not original source or compilable C.
// ev_617a9b78b5499be6fda3f80c6d3013c4eda1fb22d831431ffd01eb77498a9997

longlong *
ES3Internal_ES3Stream__CreateStream__060006e6(longlong *param_1,longlong param_2,int param_3)

{
  undefined4 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong *plVar8;
  uint uVar9;
  bool bVar10;
  
  if (DAT_182eb80b9 == '\0') {
    FUN_1802f2810(&DAT_182d53330);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53418);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53410);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a2f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a2f0);
    LOCK();
    UNLOCK();
    DAT_182eb80b9 = '\x01';
  }
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  plVar8 = param_1;
  if (*(int *)(param_2 + 0x20) != 0) {
    if (param_1 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    lVar5 = FUN_1802c5ac0(*param_1 + 0x20);
    uVar3 = DAT_182d6a2f8;
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar6 = FUN_181638ed0(uVar3,0);
    if (lVar5 != lVar6) {
      plVar7 = (longlong *)0x0;
      if (*(int *)(param_2 + 0x20) == 1) {
        plVar7 = (longlong *)FUN_1802c43a0(DAT_182d53330);
      }
      lVar5 = *(longlong *)(param_2 + 0x28);
      uVar1 = *(undefined4 *)(param_2 + 0x3c);
      plVar8 = (longlong *)FUN_1802c43a0(DAT_182d6a2f0);
      System_IO_MemoryStream___ctor__0600297c(plVar8,0);
      plVar8[10] = (longlong)param_1;
      if (DAT_182eb5d50 != 0) {
        uVar9 = (uint)((ulonglong)(plVar8 + 10) >> 0xc);
        lVar6 = (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8;
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar6);
          LOCK();
          bVar10 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar6);
          if (bVar10) {
            *(ulonglong *)(&DAT_182f0c920 + lVar6) = uVar2 | 1L << (uVar9 & 0x3f);
          }
          UNLOCK();
        } while (!bVar10);
      }
      iVar4 = DAT_182eb5d50;
      *(bool *)(plVar8 + 0xb) = param_3 == 0;
      plVar8[0xc] = lVar5;
      if (iVar4 != 0) {
        uVar9 = (uint)((ulonglong)(plVar8 + 0xc) >> 0xc);
        lVar6 = (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8;
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar6);
          LOCK();
          bVar10 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar6);
          if (bVar10) {
            *(ulonglong *)(&DAT_182f0c920 + lVar6) = uVar2 | 1L << (uVar9 & 0x3f);
          }
          UNLOCK();
          iVar4 = DAT_182eb5d50;
        } while (!bVar10);
      }
      *(undefined4 *)(plVar8 + 0xd) = uVar1;
      plVar8[0xe] = (longlong)plVar7;
      if (iVar4 != 0) {
        uVar9 = (uint)((ulonglong)(plVar8 + 0xe) >> 0xc);
        lVar6 = (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8;
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar6);
          LOCK();
          bVar10 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar6);
          if (bVar10) {
            *(ulonglong *)(&DAT_182f0c920 + lVar6) = uVar2 | 1L << (uVar9 & 0x3f);
          }
          UNLOCK();
        } while (!bVar10);
      }
      if (param_3 == 0) {
        if (plVar7 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        (**(code **)(*plVar7 + 0x1a8))
                  (plVar7,param_1,plVar8,lVar5,uVar1,*(undefined8 *)(*plVar7 + 0x1b0));
      }
    }
  }
  plVar7 = plVar8;
  if (*(int *)(param_2 + 0x24) != 0) {
    if (plVar8 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    lVar5 = FUN_1802c5ac0(*plVar8 + 0x20);
    uVar3 = DAT_182d53418;
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar6 = FUN_181638ed0(uVar3,0);
    if ((lVar5 != lVar6) && (*(int *)(param_2 + 0x24) == 1)) {
      plVar7 = (longlong *)FUN_1802c43a0(DAT_182d53410);
      if (param_3 == 0) {
        FUN_1817d4c40(plVar7,plVar8,0,0);
      }
      else {
        FUN_1817d4c40(plVar7,plVar8,1,0);
      }
    }
  }
  return plVar7;
}

