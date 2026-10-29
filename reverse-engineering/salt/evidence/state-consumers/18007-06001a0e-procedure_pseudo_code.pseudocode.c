// Ghidra pseudocode; not original source or compilable C.
// ev_40d0c47b90b9f870170d03195589cd1d32d56b2280b6ad89a8bc9a4175d10ea1

void __c__DisplayClass39_0___RefreshItemCategory_g__UseProcess_4__06001a0e(longlong param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
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
  undefined *puStack_30;
  undefined8 uStack_28;
  
  lVar4 = *(longlong *)(param_1 + 0x10);
  if (lVar4 != 0) {
    if ((*(char *)(lVar4 + 0x28) == '\0') && (*(char *)(lVar4 + 0x2a) == '\0')) {
      puStack_30 = &UNK_1804f437e;
      ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ChangeItemNum__06001551
                (*(undefined4 *)(lVar4 + 0x18),0xffffffff,0);
    }
    puStack_30 = &UNK_1804f4389;
    ExposureUnnoticed2_Master_Item_MItem__UseItemProcess__0600127e
              (*(undefined8 *)(param_1 + 0x10),0);
    lVar4 = *(longlong *)(param_1 + 0x18);
    if (lVar4 != 0) {
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
      uVar1 = *(undefined8 *)(lVar4 + 0x60);
      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
        FUN_18035c820();
      }
      ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DestroyChildren__0600172c(uVar1,0);
      lVar2 = *(longlong *)(lVar4 + 0x118);
      if (lVar2 != 0) {
        *(int *)(lVar2 + 0x1c) = *(int *)(lVar2 + 0x1c) + 1;
        iVar6 = *(int *)(lVar2 + 0x18);
        *(undefined4 *)(lVar2 + 0x18) = 0;
        if (0 < iVar6) {
          FUN_181646f50(*(undefined8 *)(lVar2 + 0x10),0,iVar6,0);
        }
        if (DAT_182eb7863 == '\0') {
          FUN_1802f2810(&DAT_182d5c400);
          LOCK();
          UNLOCK();
          DAT_182eb7863 = '\x01';
        }
        ExposureUnnoticed2_Master_Item_MItem__CheckInitialize__0600127b(0);
        lVar2 = **(longlong **)(DAT_182d5c400 + 0xb8);
        if (lVar2 != 0) {
          if (DAT_182eb5d50 != 0) {
            uVar9 = (uint)((ulonglong)&lStack_70 >> 0xc);
            lVar7 = (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8;
            do {
              uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar7);
              LOCK();
              bVar10 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar7);
              if (bVar10) {
                *(ulonglong *)(&DAT_182f0c920 + lVar7) = uVar3 | 1L << (uVar9 & 0x3f);
              }
              UNLOCK();
            } while (!bVar10);
          }
          uStack_68 = (ulonglong)*(uint *)(lVar2 + 0x2c);
          uStack_50 = 2;
          uStack_60 = 0;
          uStack_58 = 0;
          uStack_40 = uStack_68;
          uStack_38 = 0;
          puStack_30 = (undefined *)0x0;
          uStack_28 = 2;
          lStack_70 = lVar2;
          lStack_48 = lVar2;
          while (cVar5 = FUN_180f89450(&lStack_48,DAT_182d61480), uVar3 = uStack_38, cVar5 != '\0')
          {
            lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            lVar2 = *(longlong *)(lVar2 + 0x218);
            if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            iVar6 = FUN_180e6c800(lVar2,uStack_38 & 0xffffffff);
            if (-1 < iVar6) {
              lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
              if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
                FUN_18031dad0();
              }
              lVar2 = *(longlong *)(lVar2 + 0x218);
              if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
                FUN_18031dad0();
              }
              iVar6 = FUN_180e71cd0(lVar2,uVar3 & 0xffffffff);
              if (0 < iVar6) {
                lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                lVar2 = *(longlong *)(lVar2 + 0x218);
                if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                FUN_180e71cd0(lVar2,uVar3 & 0xffffffff,DAT_182d5dae0);
                ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelView___RefreshItemCategory_g__Process_39_0__060019ff
                          (lVar4,uVar3 & 0xffffffff);
              }
            }
          }
          if (*(longlong *)(lVar4 + 200) != 0) {
            HadakaCoat_ObjectsUi_Common_Button_ButtonGroupManager__ReSearchButton__06001de5
                      (*(longlong *)(lVar4 + 200),0,0,0);
            lVar7 = FUN_1802c43a0(DAT_182d58368);
            lVar2 = lRam0000000182d62de0;
            *(undefined8 *)(lVar7 + 0x10) = *(undefined8 *)(lRam0000000182d62de0 + 8);
            *(longlong *)(lVar7 + 0x28) = lVar2;
            *(longlong *)(lVar7 + 0x20) = lVar4;
            if (DAT_182eb5d50 != 0) {
              uVar9 = (uint)(lVar7 + 0x20U >> 0xc);
              lVar4 = (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8;
              do {
                uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
                LOCK();
                bVar10 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
                if (bVar10) {
                  *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar3 | 1L << (uVar9 & 0x3f);
                }
                UNLOCK();
              } while (!bVar10);
            }
            cVar5 = *(char *)(lVar2 + 0x52);
            *(longlong *)(lVar7 + 0x40) = lVar7;
            if (((*(byte *)(lVar2 + 0x4c) & 0x10) == 0) || (cVar5 != '\0')) {
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
  }
                    /* WARNING: Subroutine does not return */
  puStack_30 = &UNK_1804f43a3;
  FUN_18031dad0();
}

