// Ghidra pseudocode; not original source or compilable C.
// ev_78b2d07b6fa16e3f28c058d79e0ba80da002476357add01a5d7db2ac4ce5cf4b

undefined8 System_Security_Cryptography_Rfc2898DeriveBytes__OpenHmac__06001566(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  char cVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  uint uVar8;
  bool bVar9;
  longlong lStackX_8;
  longlong lStackX_18;
  
  if (cRam0000000182ebae65 == '\0') {
    FUN_1802f2810(0x182d3b3b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3b3a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3b318);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3b310);
    LOCK();
    UNLOCK();
    cRam0000000182ebae65 = '\x01';
  }
  lVar2 = *(longlong *)(param_1 + 0x50);
  lStackX_18 = lVar2;
  if ((lVar2 == 0) || (*(int *)(lVar2 + 0x10) == 0)) {
    uVar7 = thunk_FUN_1802f2810(0x182d6a2e0);
    uVar7 = thunk_FUN_1802c43a0(uVar7);
    uVar6 = thunk_FUN_1802f2810(0x182d3b328);
    FUN_18149d950(uVar7,uVar6,0);
    uVar6 = thunk_FUN_1802f2810(0x182d3b320);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar7,uVar6);
  }
  lVar5 = FUN_18149cc20(0);
  if ((lVar2 == lVar5) ||
     (((lVar5 != 0 && (*(int *)(lVar2 + 0x10) == *(int *)(lVar5 + 0x10))) &&
      (cVar4 = FUN_181630ad0(lVar2 + 0x14,lVar5 + 0x14,(longlong)*(int *)(lVar2 + 0x10) * 2,0),
      cVar4 != '\0')))) {
    uVar7 = *(undefined8 *)(param_1 + 0x10);
    uVar6 = FUN_1802c43a0(uRam0000000182d3b3b0);
    FUN_1814a0e10(uVar6,uVar7,0);
    return uVar6;
  }
  if (cRam0000000182ebae87 == '\0') {
    FUN_1802f2810(0x182d3b150);
    LOCK();
    UNLOCK();
    cRam0000000182ebae87 = '\x01';
  }
  lVar5 = lRam0000000182d3b150;
  lStackX_8 = lRam0000000182d3b150;
  if (DAT_182eb5d50 != 0) {
    uVar8 = (uint)((ulonglong)&lStackX_8 >> 0xc);
    lVar1 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
    do {
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar9 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar9) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar3 | 1L << (uVar8 & 0x3f);
      }
      UNLOCK();
    } while (!bVar9);
  }
  if ((lVar2 != lVar5) &&
     (((lVar5 == 0 || (*(int *)(lVar2 + 0x10) != *(int *)(lVar5 + 0x10))) ||
      (cVar4 = FUN_181630ad0(lVar2 + 0x14,lVar5 + 0x14,(longlong)*(int *)(lVar2 + 0x10) * 2,0),
      cVar4 == '\0')))) {
    if (cRam0000000182ebae88 == '\0') {
      FUN_1802f2810(0x182d3b100);
      LOCK();
      UNLOCK();
      cRam0000000182ebae88 = '\x01';
    }
    lVar5 = lRam0000000182d3b100;
    lStackX_8 = lRam0000000182d3b100;
    if (DAT_182eb5d50 != 0) {
      uVar8 = (uint)((ulonglong)&lStackX_8 >> 0xc);
      lVar1 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
      do {
        uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        LOCK();
        bVar9 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
        if (bVar9) {
          *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar3 | 1L << (uVar8 & 0x3f);
        }
        UNLOCK();
      } while (!bVar9);
    }
    if ((lVar2 != lVar5) &&
       (((lVar5 == 0 || (*(int *)(lVar2 + 0x10) != *(int *)(lVar5 + 0x10))) ||
        (cVar4 = FUN_181630ad0(lVar2 + 0x14,lVar5 + 0x14,(longlong)*(int *)(lVar2 + 0x10) * 2,0),
        cVar4 == '\0')))) {
      if (cRam0000000182ebae89 == '\0') {
        FUN_1802f2810(0x182d3b108);
        LOCK();
        UNLOCK();
        cRam0000000182ebae89 = '\x01';
      }
      lVar5 = lRam0000000182d3b108;
      lStackX_8 = lRam0000000182d3b108;
      if (DAT_182eb5d50 != 0) {
        uVar8 = (uint)((ulonglong)&lStackX_8 >> 0xc);
        lVar1 = (ulonglong)((uVar8 & 0x1fffff) >> 6) * 8;
        do {
          uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
          LOCK();
          bVar9 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
          if (bVar9) {
            *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar3 | 1L << (uVar8 & 0x3f);
          }
          UNLOCK();
        } while (!bVar9);
      }
      if ((lVar2 != lVar5) &&
         (((lVar5 == 0 || (*(int *)(lVar2 + 0x10) != *(int *)(lVar5 + 0x10))) ||
          (cVar4 = FUN_181630ad0(lVar2 + 0x14,lVar5 + 0x14,(longlong)*(int *)(lVar2 + 0x10) * 2,0),
          cVar4 == '\0')))) {
        uVar7 = System_Int64__System_IConvertible_ToInt64__06000745(&lStackX_18);
        uVar6 = thunk_FUN_1802f2810(0x182d3b330);
        uVar7 = FUN_181453970(uVar6,uVar7,0);
        uVar6 = thunk_FUN_1802f2810(0x182d6a2e0);
        uVar6 = thunk_FUN_1802c43a0(uVar6);
        FUN_18149d950(uVar6,uVar7,0);
        uVar7 = thunk_FUN_1802f2810(0x182d3b320);
                    /* WARNING: Subroutine does not return */
        FUN_18031da90(uVar6,uVar7);
      }
      uVar7 = *(undefined8 *)(param_1 + 0x10);
      uVar6 = FUN_1802c43a0(uRam0000000182d3b310);
      FUN_1814a1440(uVar6,uVar7,0);
      return uVar6;
    }
    uVar7 = *(undefined8 *)(param_1 + 0x10);
    uVar6 = FUN_1802c43a0(uRam0000000182d3b318);
    FUN_1814a1210(uVar6,uVar7,0);
    return uVar6;
  }
  uVar7 = *(undefined8 *)(param_1 + 0x10);
  uVar6 = FUN_1802c43a0(uRam0000000182d3b3a8);
  FUN_1814a1010(uVar6,uVar7,0);
  return uVar6;
}

