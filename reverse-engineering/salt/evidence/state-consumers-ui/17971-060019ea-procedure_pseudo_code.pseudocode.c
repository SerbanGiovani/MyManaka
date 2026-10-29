// Ghidra pseudocode; not original source or compilable C.
// ev_7c66becc85d715e7a5fcc2bd0e6a5d7dc260a2d2f0bb2fb85f322a3634750487

void ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelView__Initialize__060019ea
               (longlong param_1,undefined8 param_2,int param_3)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  longlong *plVar9;
  uint uVar10;
  bool bVar11;
  
  if (cRam0000000182eb7c48 == '\0') {
    FUN_1802f2810(&DAT_182d63358);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61940);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d63350);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e108);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62e60);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62e50);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62e48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62e40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aa80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c48 = '\x01';
  }
  *(int *)(param_1 + 0x128) = param_3;
  **(longlong **)(lRam0000000182d5aa80 + 0xb8) = param_1;
  if (DAT_182eb5d50 != 0) {
    uVar10 = (uint)(*(ulonglong *)(lRam0000000182d5aa80 + 0xb8) >> 0xc);
    lVar4 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
    do {
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
      LOCK();
      bVar11 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
      if (bVar11) {
        *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar3 | 1L << (uVar10 & 0x3f);
      }
      UNLOCK();
    } while (!bVar11);
  }
  plVar6 = (longlong *)FUN_1816791b0(*(undefined8 *)(param_1 + 0x30),param_2,0);
  if (plVar6 == (longlong *)0x0) {
    *(undefined8 *)(param_1 + 0x30) = 0;
  }
  else {
    plVar9 = (longlong *)0x0;
    if (*plVar6 == DAT_182d58368) {
      plVar9 = plVar6;
    }
    if (plVar9 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(plVar6,DAT_182d58368);
    }
    *(longlong **)(param_1 + 0x30) = plVar9;
    plVar9 = (longlong *)0x0;
    if (*plVar6 == DAT_182d58368) {
      plVar9 = plVar6;
    }
    if (plVar9 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(plVar6);
    }
  }
  if (DAT_182eb5d50 != 0) {
    uVar10 = (uint)(param_1 + 0x30U >> 0xc);
    lVar4 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
    do {
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
      LOCK();
      bVar11 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
      if (bVar11) {
        *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar3 | 1L << (ulonglong)(uVar10 & 0x3f);
      }
      UNLOCK();
    } while (!bVar11);
  }
  uVar7 = FUN_1802c43a0(DAT_182d63358);
  FUN_180665bb0(uVar7,param_1,uRam0000000182d62e60,0);
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  FUN_180993250(uVar7,0,DAT_182d63350);
  if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
      (lVar4 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar4 != 0)) &&
     (lVar4 = *(longlong *)(lVar4 + 0x60), lVar4 != 0)) {
    if (*(char *)(lVar4 + 0x1a) == '\0') {
      if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
          (lVar4 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar4 == 0)) ||
         (lVar4 = *(longlong *)(lVar4 + 0x38), lVar4 == 0)) goto DAT_1804f00a0;
      ExposureUnnoticed2_Object3D_Camera_BaseCameraController__SetInventoryCamera__060011ec
                (lVar4,1,0,0);
    }
    lVar4 = *(longlong *)(param_1 + 0x98);
    uVar7 = FUN_1802c43a0(uRam0000000182d61940);
    FUN_180006cd0(uVar7,param_1,uRam0000000182d62e50);
    uVar8 = FUN_1802c43a0(uRam0000000182d5e108);
    FUN_180005c40(uVar8,param_1,uRam0000000182d62e48);
    if (lVar4 != 0) {
      ExposureUnnoticed2_ObjectUI_CommonUI_CommonTab_CommonTabView__Initialize__06001da6
                (lVar4,uVar7,uVar8,0);
      if (*(longlong *)(param_1 + 0xa0) != 0) {
        ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelCosplayView__Initialize__060019ca
                  (*(longlong *)(param_1 + 0xa0),*(undefined8 *)(param_1 + 0xb0),param_1,0);
        if (*(longlong *)(param_1 + 0xa0) != 0) {
          ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelCosplayView__Hide__060019d0
                    (*(longlong *)(param_1 + 0xa0),0);
          if (*(longlong *)(param_1 + 0xa8) != 0) {
            ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelLoadoutView__Initialize__060019d9
                      (*(longlong *)(param_1 + 0xa8),param_1,0);
            if (*(longlong *)(param_1 + 0xa8) != 0) {
              ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelLoadoutView__Hide__060019de
                        (*(longlong *)(param_1 + 0xa8),0);
              ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelView__RefreshEquipCount__060019f0
                        (param_1,0);
              if (param_3 < 0) {
                ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelView__OnClickCategory__060019f3
                          (param_1,0,0);
              }
              else {
                if (*(longlong *)(param_1 + 0x98) == 0) goto DAT_1804f00a0;
                ExposureUnnoticed2_ObjectUI_CommonUI_CommonTab_CommonTabView__OnClickTab__06001da7
                          (*(longlong *)(param_1 + 0x98),param_3,0);
              }
              uVar7 = FUN_1802c43a0(DAT_182d58368);
              FUN_1814df680(uVar7,param_1,uRam0000000182d62e40,0);
              if (DAT_182eb7aa1 == '\0') {
                FUN_1802f2810(&DAT_182d5f910,1,0);
                LOCK();
                UNLOCK();
                FUN_1802f2810(&DAT_182d5f908);
                LOCK();
                UNLOCK();
                DAT_182eb7aa1 = '\x01';
              }
              lVar4 = ExposureUnnoticed2_Scripts_Base_Scheduler__get_Instance__0600174a(0);
              if (lVar4 != 0) {
                lVar4 = *(longlong *)(lVar4 + 0x20);
                lVar5 = FUN_1802c43a0(DAT_182d5f910);
                bVar11 = DAT_182eb5d50 != 0;
                *(undefined8 *)(lVar5 + 0x10) = uVar7;
                if (bVar11) {
                  uVar10 = (uint)(lVar5 + 0x10U >> 0xc);
                  puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8)
                  ;
                  do {
                    uVar2 = *puVar1;
                    LOCK();
                    uVar3 = *puVar1;
                    if (uVar2 == uVar3) {
                      *puVar1 = uVar2 | 1L << (uVar10 & 0x3f);
                    }
                    UNLOCK();
                  } while (uVar2 != uVar3);
                }
                *(undefined4 *)(lVar5 + 0x18) = 1;
                if (lVar4 != 0) {
                  FUN_1800068f0(lVar4,lVar5);
                  return;
                }
              }
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
          }
        }
      }
    }
  }
DAT_1804f00a0:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

