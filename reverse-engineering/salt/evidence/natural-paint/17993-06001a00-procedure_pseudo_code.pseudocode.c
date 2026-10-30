// Ghidra pseudocode; not original source or compilable C.
// ev_d19d45a6cfb44d3c1de146c581faca93d4d3ed56b0ec92f09d5a2eca4dd4fa2d

void ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelView___RefreshItemCategory_b__39_2__06001a00
               (undefined8 param_1,undefined8 param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  char cVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  int iVar9;
  uint uVar10;
  bool bVar11;
  undefined8 uStack_88;
  undefined8 uStack_80;
  longlong lStack_78;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 auStack_58 [2];
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  
  if (cRam0000000182eb7c58 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e258);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62c68);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62c60);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62c58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d62ce8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f250);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f248);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62c50);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f240);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c58 = '\x01';
  }
  lVar4 = FUN_1802c43a0(uRam0000000182d62c58);
  iVar9 = DAT_182eb5d50;
  if (lVar4 == 0) goto DAT_1804f3c11;
  *(undefined8 *)(lVar4 + 0x18) = param_1;
  if (iVar9 != 0) {
    uVar10 = (uint)(lVar4 + 0x18U >> 0xc);
    lVar5 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
      LOCK();
      bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
      if (bVar11) {
        *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar1 | 1L << (uVar10 & 0x3f);
      }
      UNLOCK();
      iVar9 = DAT_182eb5d50;
    } while (!bVar11);
  }
  *(undefined8 *)(lVar4 + 0x10) = param_2;
  if (iVar9 != 0) {
    uVar10 = (uint)(lVar4 + 0x10U >> 0xc);
    lVar5 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
      LOCK();
      bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
      if (bVar11) {
        *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar1 | 1L << (uVar10 & 0x3f);
      }
      UNLOCK();
    } while (!bVar11);
  }
  if (*(longlong *)(lVar4 + 0x10) == 0) goto DAT_1804f3c11;
  if (*(int *)(*(longlong *)(lVar4 + 0x10) + 0x18) == 0x2712) {
    if (**(longlong **)(lRam0000000182d5e258 + 0xb8) == 0) goto DAT_1804f3c11;
    if (cRam0000000182eb7962 == '\0') {
      FUN_1802f2810(&DAT_182d58398);
      LOCK();
      UNLOCK();
      cRam0000000182eb7962 = '\x01';
    }
    lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar5 == 0) goto DAT_1804f3c11;
    if (*(int *)(lVar5 + 0xbc) == -1) goto code_r0x0001804f38a5;
    lVar5 = **(longlong **)(DAT_182d58230 + 0xb8);
    if (lVar5 == 0) goto DAT_1804f3c11;
    if (DAT_182eb83fe == '\0') {
      FUN_1802f2810(&DAT_182d3e668);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d3e660);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d5e118);
      LOCK();
      UNLOCK();
      DAT_182eb83fe = '\x01';
    }
    if ((*(longlong *)(lVar5 + 0x10) == 0) ||
       (lVar2 = *(longlong *)(*(longlong *)(lVar5 + 0x10) + 0x60), lVar2 == 0)) goto DAT_1804f3c11;
    uVar6 = DAT_182d3e668;
    if (*(char *)(lVar2 + 0x1b) == '\0') {
      if (*(longlong *)(lVar2 + 0x48) == 0) goto DAT_1804f3c11;
      uVar6 = DAT_182d5e118;
      if (((*(int *)(*(longlong *)(lVar2 + 0x48) + 0x18) == -1) &&
          (lVar5 = *(longlong *)(*(longlong *)(lVar5 + 0x10) + 0x60), *(int *)(lVar5 + 0x5c) == 0))
         && (*(char *)(lVar5 + 0x50) == '\0')) {
        lVar5 = FUN_180436330();
        if (lVar5 == 0) goto DAT_1804f3c11;
        uVar6 = DAT_182d5e118;
        if (*(char *)(lVar5 + 0x10) == '\0') goto code_r0x0001804f38b3;
      }
    }
    uVar6 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar6,0);
    ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
              (uVar6,0,0);
  }
  else {
code_r0x0001804f38a5:
    cVar3 = ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelView__CheckPossibleAndAddMessageIfNeed__060019f7
                      (param_1,0);
    if (cVar3 == '\0') {
      return;
    }
code_r0x0001804f38b3:
    if (*(longlong *)(lVar4 + 0x10) == 0) {
DAT_1804f3c11:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    iVar9 = *(int *)(*(longlong *)(lVar4 + 0x10) + 0x18);
    if ((iVar9 == 8) || (iVar9 == 7)) {
      uVar6 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d5f250,0);
      uVar7 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d62c50,0);
      uStack_68 = 0;
      auStack_58[0] = 0;
      uStack_60 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d5f248,0)
      ;
      if (DAT_182eb5d50 != 0) {
        uVar10 = (uint)((ulonglong)&uStack_60 >> 0xc);
        lVar5 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
          LOCK();
          bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
          if (bVar11) {
            *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar1 | 1L << (uVar10 & 0x3f);
          }
          UNLOCK();
        } while (!bVar11);
      }
      if (*(int *)(DAT_182d62ce8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar5 = *(longlong *)(*(longlong *)(DAT_182d62ce8 + 0xb8) + 8);
      if (lVar5 == 0) {
        if (*(int *)(DAT_182d62ce8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uVar8 = **(undefined8 **)(DAT_182d62ce8 + 0xb8);
        lVar5 = FUN_1802c43a0(DAT_182d58368);
        FUN_1814df680(lVar5,uVar8,uRam0000000182d62c68,0);
        *(longlong *)(*(longlong *)(DAT_182d62ce8 + 0xb8) + 8) = lVar5;
        if (DAT_182eb5d50 != 0) {
          uVar10 = (uint)(*(longlong *)(DAT_182d62ce8 + 0xb8) + 8U >> 0xc);
          lVar2 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
          do {
            uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
            LOCK();
            bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
            if (bVar11) {
              *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar1 | 1L << (uVar10 & 0x3f);
            }
            UNLOCK();
          } while (!bVar11);
        }
      }
      if (DAT_182eb5d50 != 0) {
        uVar10 = (uint)((ulonglong)auStack_58 >> 0xc);
        lVar2 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
          LOCK();
          bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
          if (bVar11) {
            *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar1 | 1L << (uVar10 & 0x3f);
          }
          UNLOCK();
        } while (!bVar11);
      }
      uStack_88 = uStack_68;
      uStack_80 = uStack_60;
      uStack_68 = 0;
      uStack_60 = 0;
      auStack_58[0] = 0;
      uStack_60 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d5f240,0)
      ;
      if (DAT_182eb5d50 != 0) {
        uVar10 = (uint)((ulonglong)&uStack_60 >> 0xc);
        lVar2 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
          LOCK();
          bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
          if (bVar11) {
            *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar1 | 1L << (uVar10 & 0x3f);
          }
          UNLOCK();
        } while (!bVar11);
      }
      uVar8 = FUN_1802c43a0(DAT_182d58368);
      FUN_1814df680(uVar8,lVar4,uRam0000000182d62c60,0);
      if (DAT_182eb5d50 != 0) {
        uVar10 = (uint)((ulonglong)auStack_58 >> 0xc);
        lVar4 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
        do {
          uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
          LOCK();
          bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
          if (bVar11) {
            *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar1 | 1L << (uVar10 & 0x3f);
          }
          UNLOCK();
        } while (!bVar11);
      }
      uStack_48 = uStack_68;
      uStack_40 = uStack_60;
      lStack_78 = lVar5;
      auStack_58[0] = uVar8;
      uStack_38 = uVar8;
      ExposureUnnoticed2_ObjectUI_CommonPopup_CommonPopupView__Open__06001dc2
                (uVar6,uVar7,&uStack_88,&uStack_48,0,0);
    }
    else {
      __c__DisplayClass39_0___RefreshItemCategory_g__UseProcess_4__06001a0e(lVar4,0);
    }
  }
  return;
}

