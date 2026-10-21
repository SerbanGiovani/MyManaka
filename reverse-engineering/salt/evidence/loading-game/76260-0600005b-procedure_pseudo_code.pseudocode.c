// Ghidra pseudocode; not original source or compilable C.
// ev_cd58089bcee454c4649353e4622123823801ec65a59cb5aab099b7391bfe3b32

ulonglong _Mode2_d__33__MoveNext__0600005b(int *param_1)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  bool bVar8;
  longlong lStackX_18;
  longlong lStackX_20;
  
  if (cRam0000000182ebaa91 == '\0') {
    FUN_1802f2810(0x182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64d18);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d37d90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64d28);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64d20);
    LOCK();
    UNLOCK();
    cRam0000000182ebaa91 = '\x01';
  }
  lVar2 = *(longlong *)(param_1 + 10);
  if (*param_1 == 0) {
    lVar4 = *(longlong *)(param_1 + 0xe);
    param_1[0xe] = 0;
    param_1[0xf] = 0;
    *param_1 = -1;
  }
  else {
    lVar4 = FUN_1802c43a0(uRam0000000182d64d20);
    if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    *(undefined8 *)(lVar4 + 0x10) = *(undefined8 *)(param_1 + 10);
    if (DAT_182eb5d50 != 0) {
      uVar7 = (uint)(lVar4 + 0x10U >> 0xc);
      lVar1 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
      do {
        uVar6 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        LOCK();
        bVar8 = uVar6 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
        if (bVar8) {
          *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar6 | 1L << (uVar7 & 0x3f);
        }
        UNLOCK();
      } while (!bVar8);
    }
    *(undefined8 *)(lVar4 + 0x18) = *(undefined8 *)(param_1 + 0xc);
    if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    *(undefined1 *)(lVar2 + 0x38) = 0;
    uVar5 = FUN_1802c43a0(uRam0000000182d58368);
    FUN_1814df680(uVar5,lVar4,uRam0000000182d64d28,0);
    if (*(int *)(lRam0000000182d37d90 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar4 = FUN_1816b6610(uVar5,0);
    if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (DAT_182eb5d50 != 0) {
      uVar7 = (uint)((ulonglong)&lStackX_18 >> 0xc);
      lVar1 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
      do {
        uVar6 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        LOCK();
        bVar8 = uVar6 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
        if (bVar8) {
          *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar6 | 1L << (uVar7 & 0x3f);
        }
        UNLOCK();
      } while (!bVar8);
    }
    lStackX_18 = lVar4;
    lStackX_20 = lVar4;
    if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (cRam0000000182ebbd69 == '\0') {
      FUN_1802f2810(0x182d37d90);
      LOCK();
      UNLOCK();
      cRam0000000182ebbd69 = '\x01';
    }
    uVar7 = *(uint *)(lStackX_18 + 0x38);
    LOCK();
    UNLOCK();
    if (*(int *)(lRam0000000182d37d90 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if ((uVar7 & 0x1600000) == 0) {
      *param_1 = 0;
      *(longlong *)(param_1 + 0xe) = lStackX_18;
      if (DAT_182eb5d50 != 0) {
        uVar7 = (uint)((ulonglong)(param_1 + 0xe) >> 0xc);
        lVar2 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
        do {
          uVar6 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
          LOCK();
          bVar8 = uVar6 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
          if (bVar8) {
            *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar6 | 1L << (uVar7 & 0x3f);
          }
          UNLOCK();
        } while (!bVar8);
      }
      uVar6 = FUN_180717b90(param_1 + 2,&lStackX_20,param_1,uRam0000000182d64d18);
      return uVar6;
    }
  }
  FUN_1815368d0(lVar4,0);
  if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (cRam0000000182ebaa90 == '\0') {
    FUN_1802f2810(0x182d53428);
    LOCK();
    UNLOCK();
    cRam0000000182ebaa90 = '\x01';
  }
  while (*(char *)(lVar2 + 0x38) == '\0') {
    FUN_1816a4160(*(undefined4 *)(lVar2 + 0x54));
  }
  lVar4 = *(longlong *)(lVar2 + 0x40);
  if (lVar4 != 0) {
    (**(code **)(lVar4 + 0x18))(*(undefined8 *)(lVar4 + 0x40),0,*(undefined8 *)(lVar4 + 0x28));
  }
  lVar4 = *(longlong *)(lVar2 + 0x48);
  if (lVar4 != 0) {
    (**(code **)(lVar4 + 0x18))
              (*(undefined8 *)(lVar4 + 0x40),*(undefined8 *)(lVar2 + 0x58),
               *(undefined8 *)(lVar4 + 0x28));
    uVar6 = FUN_1802c36c0(uRam0000000182d53428,0);
    *(ulonglong *)(lVar2 + 0x58) = uVar6;
    if (DAT_182eb5d50 != 0) {
      uVar7 = (uint)(lVar2 + 0x58U >> 0xc);
      lVar2 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
      do {
        uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
        LOCK();
        uVar6 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
        bVar8 = uVar3 == uVar6;
        if (bVar8) {
          *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar3 | 1L << (uVar7 & 0x3f);
          uVar6 = uVar3;
        }
        UNLOCK();
      } while (!bVar8);
    }
    *param_1 = -2;
    if (*(longlong *)(param_1 + 2) != 0) {
      uVar6 = FUN_1815374e0(param_1 + 2,0);
    }
    return uVar6;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

