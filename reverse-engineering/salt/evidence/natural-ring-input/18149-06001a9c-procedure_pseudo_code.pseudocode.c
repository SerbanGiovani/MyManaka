// Ghidra pseudocode; not original source or compilable C.
// ev_f736ae1781556742f751731fce4a8fadb9e7777f23151a7b6fca04fa3d7c26e3

ulonglong ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__OpenRingMenu__06001a9c
                    (longlong param_1,undefined4 param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong lVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined8 uVar11;
  int iVar12;
  int iVar13;
  bool bVar14;
  undefined4 auStackX_20 [2];
  
  if (cRam0000000182eb7cab == '\0') {
    FUN_1802f2810(0x182d621e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d621d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d621c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d54d90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d621b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d621a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d621a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62190);
    LOCK();
    UNLOCK();
    cRam0000000182eb7cab = '\x01';
  }
  uVar6 = FUN_1802c43a0(uRam0000000182d62190);
  if (uVar6 == 0) {
code_r0x0001805022bf:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  bVar14 = DAT_182eb5d50 != 0;
  *(longlong *)(uVar6 + 0x10) = param_1;
  uVar9 = uVar6;
  if (bVar14) {
    uVar5 = (uint)(uVar6 + 0x10 >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8);
    do {
      uVar2 = *puVar1;
      LOCK();
      uVar9 = *puVar1;
      bVar14 = uVar2 == uVar9;
      if (bVar14) {
        *puVar1 = uVar2 | 1L << (uVar5 & 0x3f);
        uVar9 = uVar2;
      }
      UNLOCK();
    } while (!bVar14);
  }
  *(undefined4 *)(uVar6 + 0x18) = param_2;
  *(undefined4 *)(param_1 + 0x78) = param_2;
  if (*(int *)(uVar6 + 0x18) == 0) {
    auStackX_20[0] = *(undefined4 *)(param_1 + 0x110);
    switch(auStackX_20[0]) {
    case 0:
    case 2:
    case 3:
    case 5:
    case 6:
      lVar7 = *(longlong *)(param_1 + 0xe8);
      break;
    case 1:
      lVar7 = *(longlong *)(param_1 + 0xf8);
      break;
    case 4:
      lVar7 = *(longlong *)(param_1 + 0x100);
      break;
    case 7:
      lVar7 = *(longlong *)(param_1 + 0x108);
      break;
    default:
      uVar11 = il2cpp_value_box(uRam0000000182d621b0,auStackX_20);
                    /* WARNING: Subroutine does not return */
      _PrivateImplementationDetails___ThrowSwitchExpressionException__06001e66(uVar11,0);
    }
    if (lVar7 == 0) goto code_r0x0001805022bf;
    iVar13 = 0;
    iVar12 = *(int *)(lVar7 + 0x18) + -1;
    uVar5 = (int)(iVar12 + (iVar12 >> 0x1f & 7U)) >> 3;
    uVar9 = (ulonglong)uVar5;
    *(uint *)(param_1 + 0xd8) = uVar5;
    if (-1 < (int)uVar5) {
      do {
        lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        if (lVar8 == 0) goto code_r0x0001805022bf;
        iVar12 = *(int *)(lVar8 + 0x50);
        iVar4 = (int)(iVar12 + (iVar12 >> 0x1f & 7U)) >> 3;
        uVar11 = *(undefined8 *)(param_1 + 0x40);
        uVar3 = *(undefined8 *)(param_1 + 0x48);
        iVar12 = 0;
        if (-1 < iVar4) {
          iVar12 = iVar4;
        }
        *(int *)(param_1 + 0x20) = iVar12;
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar8 = FUN_1809f1050(uVar11,uVar3,DAT_182d54d90);
        if (lVar8 == 0) goto code_r0x0001805022bf;
        lVar10 = FUN_1809a08f0(lVar8,uRam0000000182d621d0);
        lVar8 = *(longlong *)(uVar6 + 0x20);
        if (lVar8 == 0) {
          lVar8 = FUN_1802c43a0(uRam0000000182d621e0);
          FUN_180665bb0(lVar8,uVar6,uRam0000000182d621a8,0);
          *(longlong *)(uVar6 + 0x20) = lVar8;
          FUN_18031d480(uVar6 + 0x20);
        }
        if (lVar10 == 0) goto code_r0x0001805022bf;
        ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuView__Initialize__06001acc
                  (lVar10,param_1,lVar7,lVar8,iVar13,0);
        if (*(longlong *)(param_1 + 0x80) == 0) goto code_r0x0001805022bf;
        uVar9 = FUN_180007500(*(longlong *)(param_1 + 0x80),lVar10);
        iVar13 = iVar13 + 1;
      } while (iVar13 <= *(int *)(param_1 + 0xd8));
    }
  }
  else {
    iVar12 = 0;
    if (-1 < *(int *)(param_1 + 0xdc)) {
      do {
        iVar13 = 0;
        switch(*(undefined4 *)(uVar6 + 0x18)) {
        case 1:
          lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar7 == 0) goto code_r0x0001805022bf;
          iVar13 = *(int *)(lVar7 + 0x54);
          iVar4 = (int)(iVar13 + (iVar13 >> 0x1f & 7U)) >> 3;
          iVar13 = 0;
          if (-1 < iVar4) {
            iVar13 = iVar4;
          }
          *(int *)(param_1 + 0x24) = iVar13;
          break;
        case 2:
          lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar7 == 0) goto code_r0x0001805022bf;
          iVar4 = *(int *)(lVar7 + 0x58);
          iVar4 = (int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3;
          if (-1 < iVar4) {
            iVar13 = iVar4;
          }
          *(int *)(param_1 + 0x28) = iVar13;
          break;
        case 3:
          lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar7 == 0) goto code_r0x0001805022bf;
          iVar4 = *(int *)(lVar7 + 0x5c);
          iVar4 = (int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3;
          if (-1 < iVar4) {
            iVar13 = iVar4;
          }
          *(int *)(param_1 + 0x2c) = iVar13;
          break;
        case 4:
          lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar7 == 0) goto code_r0x0001805022bf;
          iVar4 = *(int *)(lVar7 + 0x60);
          iVar4 = (int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3;
          if (-1 < iVar4) {
            iVar13 = iVar4;
          }
          *(int *)(param_1 + 0x30) = iVar13;
          break;
        case 5:
          lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar7 == 0) goto code_r0x0001805022bf;
          iVar4 = *(int *)(lVar7 + 100);
          iVar4 = (int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3;
          if (-1 < iVar4) {
            iVar13 = iVar4;
          }
          *(int *)(param_1 + 0x34) = iVar13;
          break;
        case 6:
          lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar7 == 0) goto code_r0x0001805022bf;
          iVar13 = *(int *)(lVar7 + 0x68);
          iVar4 = (int)(iVar13 + (iVar13 >> 0x1f & 7U)) >> 3;
          iVar13 = 0;
          if (-1 < iVar4) {
            iVar13 = iVar4;
          }
          *(int *)(param_1 + 0x38) = iVar13;
          break;
        case 7:
          lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar7 == 0) goto code_r0x0001805022bf;
          iVar13 = *(int *)(lVar7 + 0x6c);
          iVar4 = (int)(iVar13 + (iVar13 >> 0x1f & 7U)) >> 3;
          iVar13 = 0;
          if (-1 < iVar4) {
            iVar13 = iVar4;
          }
          *(int *)(param_1 + 0x3c) = iVar13;
        }
        uVar11 = *(undefined8 *)(param_1 + 0x40);
        uVar3 = *(undefined8 *)(param_1 + 0x48);
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar7 = FUN_1809f1050(uVar11,uVar3,DAT_182d54d90);
        if (lVar7 == 0) goto code_r0x0001805022bf;
        lVar8 = FUN_1809a08f0(lVar7,uRam0000000182d621d0);
        lVar7 = *(longlong *)(uVar6 + 0x28);
        uVar11 = *(undefined8 *)(param_1 + 0xe8);
        if (lVar7 == 0) {
          lVar7 = FUN_1802c43a0(uRam0000000182d621e0);
          FUN_180665bb0(lVar7,uVar6,uRam0000000182d621a0,0);
          *(longlong *)(uVar6 + 0x28) = lVar7;
          FUN_18031d480(uVar6 + 0x28);
        }
        if (lVar8 == 0) goto code_r0x0001805022bf;
        ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuView__Initialize__06001acc
                  (lVar8,param_1,uVar11,lVar7,iVar12,0);
        if (*(longlong *)(param_1 + 0x80) == 0) goto code_r0x0001805022bf;
        uVar9 = FUN_180007500(*(longlong *)(param_1 + 0x80),lVar8);
        iVar12 = iVar12 + 1;
      } while (iVar12 <= *(int *)(param_1 + 0xdc));
    }
  }
  return uVar9;
}

