// Ghidra pseudocode; not original source or compilable C.
// ev_0012a10bbf9d8d3c72e3206d483055dac65a0c6b17cc28b20c6a26a59fcd1cff

void ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelView__RefreshItemCategory__060019f4
               (longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  char cVar5;
  int iVar6;
  longlong lVar7;
  undefined1 *puVar8;
  uint uVar9;
  bool bVar10;
  longlong lStack_70;
  ulonglong uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  longlong lStack_48;
  ulonglong uStack_40;
  ulonglong uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  
  if (cRam0000000182eb7c4f == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dae8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d61498);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dae0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d614c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d61480);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d61478);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62de0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62dd8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62dd0);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c4f = '\x01';
  }
  uVar2 = *(undefined8 *)(param_1 + 0x60);
  if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
    FUN_18035c820();
  }
  ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DestroyChildren__0600172c(uVar2,0);
  lVar3 = *(longlong *)(param_1 + 0x118);
  if (lVar3 != 0) {
    *(int *)(lVar3 + 0x1c) = *(int *)(lVar3 + 0x1c) + 1;
    iVar6 = *(int *)(lVar3 + 0x18);
    *(undefined4 *)(lVar3 + 0x18) = 0;
    if (0 < iVar6) {
      FUN_181646f50(*(undefined8 *)(lVar3 + 0x10),0,iVar6,0);
    }
    if (DAT_182eb7863 == '\0') {
      FUN_1802f2810(&DAT_182d5c400);
      LOCK();
      UNLOCK();
      DAT_182eb7863 = '\x01';
    }
    ExposureUnnoticed2_Master_Item_MItem__CheckInitialize__0600127b(0);
    lVar3 = **(longlong **)(DAT_182d5c400 + 0xb8);
    if (lVar3 != 0) {
      if (DAT_182eb5d50 != 0) {
        uVar9 = (uint)((ulonglong)&lStack_70 >> 0xc);
        lVar7 = (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8;
        do {
          uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar7);
          LOCK();
          bVar10 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar7);
          if (bVar10) {
            *(ulonglong *)(&DAT_182f0c920 + lVar7) = uVar4 | 1L << (uVar9 & 0x3f);
          }
          UNLOCK();
        } while (!bVar10);
      }
      uStack_68 = (ulonglong)*(uint *)(lVar3 + 0x2c);
      uStack_50 = 2;
      uStack_60 = 0;
      uStack_58 = 0;
      uStack_40 = uStack_68;
      uStack_38 = 0;
      uStack_30 = 0;
      uStack_28 = 2;
      lStack_70 = lVar3;
      lStack_48 = lVar3;
      while (cVar5 = FUN_180f89450(&lStack_48,DAT_182d61480), uVar4 = uStack_38, cVar5 != '\0') {
        lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        lVar3 = *(longlong *)(lVar3 + 0x218);
        if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        iVar6 = FUN_180e6c800(lVar3,uStack_38 & 0xffffffff);
        if (-1 < iVar6) {
          lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          lVar3 = *(longlong *)(lVar3 + 0x218);
          if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          iVar6 = FUN_180e71cd0(lVar3,uVar4 & 0xffffffff);
          if (0 < iVar6) {
            lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            lVar3 = *(longlong *)(lVar3 + 0x218);
            if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            FUN_180e71cd0(lVar3,uVar4 & 0xffffffff,DAT_182d5dae0);
            ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelView___RefreshItemCategory_g__Process_39_0__060019ff
                      (param_1,uVar4 & 0xffffffff);
          }
        }
      }
      if (*(longlong *)(param_1 + 200) != 0) {
        HadakaCoat_ObjectsUi_Common_Button_ButtonGroupManager__ReSearchButton__06001de5
                  (*(longlong *)(param_1 + 200),0,0,0);
        lVar7 = FUN_1802c43a0(DAT_182d58368);
        lVar3 = lRam0000000182d62de0;
        *(undefined8 *)(lVar7 + 0x10) = *(undefined8 *)(lRam0000000182d62de0 + 8);
        *(longlong *)(lVar7 + 0x28) = lVar3;
        *(longlong *)(lVar7 + 0x20) = param_1;
        if (DAT_182eb5d50 != 0) {
          uVar9 = (uint)(lVar7 + 0x20U >> 0xc);
          lVar1 = (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8;
          do {
            uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
            LOCK();
            bVar10 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
            if (bVar10) {
              *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar9 & 0x3f);
            }
            UNLOCK();
          } while (!bVar10);
        }
        cVar5 = *(char *)(lVar3 + 0x52);
        *(longlong *)(lVar7 + 0x40) = lVar7;
        if (((*(byte *)(lVar3 + 0x4c) & 0x10) == 0) || (cVar5 != '\0')) {
          *(undefined8 *)(lVar7 + 0x40) = *(undefined8 *)(lVar7 + 0x20);
          puVar8 = *(undefined1 **)(lVar7 + 0x10);
        }
        else {
          puVar8 = &LAB_1800c7840;
        }
        *(undefined1 **)(lVar7 + 0x18) = puVar8;
        *(code **)(lVar7 + 0x38) = FUN_1801e91e0;
        ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b(lVar7,1,0);
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

