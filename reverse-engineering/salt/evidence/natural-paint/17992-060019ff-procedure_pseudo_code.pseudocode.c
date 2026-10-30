// Ghidra pseudocode; not original source or compilable C.
// ev_a2aef9bed24adbd8252463dd8e5a6311b687ebaf22f2fc67f2c58201efd2bd03

void ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelView___RefreshItemCategory_g__Process_39_0__060019ff
               (longlong param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  if (cRam0000000182eb7c57 == '\0') {
    FUN_1802f2810(0x182d62cb0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62ca0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62c90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62c88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62c80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d54d90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c57 = '\x01';
  }
  if (param_3 == 0) {
    return;
  }
  uVar6 = *(undefined8 *)(param_1 + 0x78);
  uVar7 = *(undefined8 *)(param_1 + 0x60);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar4 = FUN_1809f1050(uVar6,uVar7,DAT_182d54d90);
  if (lVar4 != 0) {
    lVar5 = FUN_1809a08f0(lVar4,uRam0000000182d62ca0);
    lVar3 = lRam0000000182d62c80;
    lVar4 = *(longlong *)(param_1 + 0x118);
    if (lVar4 != 0) {
      *(int *)(lVar4 + 0x1c) = *(int *)(lVar4 + 0x1c) + 1;
      lVar2 = *(longlong *)(lVar4 + 0x10);
      if (lVar2 != 0) {
        uVar1 = *(uint *)(lVar4 + 0x18);
        if (uVar1 < *(uint *)(lVar2 + 0x18)) {
          *(uint *)(lVar4 + 0x18) = uVar1 + 1;
          FUN_180002cd0(lVar2,(longlong)(int)uVar1,lVar5);
        }
        else {
          FUN_1812741c0(lVar4,lVar5,
                        *(undefined8 *)(*(longlong *)(*(longlong *)(lVar3 + 0x20) + 0xc0) + 0x70));
        }
        uVar6 = ExposureUnnoticed2_Master_Item_MItem__Get__0600127c(param_2,0);
        uVar7 = FUN_1802c43a0(uRam0000000182d62cb0);
        FUN_180665bb0(uVar7,param_1,uRam0000000182d62c90,0);
        uVar8 = FUN_1802c43a0(uRam0000000182d62cb0);
        FUN_180665bb0(uVar8,param_1,uRam0000000182d62c88,0);
        if (lVar5 != 0) {
          ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryItemView__Initialize__060019b8
                    (lVar5,uVar6,param_3,uVar7,uVar8,0);
          return;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

