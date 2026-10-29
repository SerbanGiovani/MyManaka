// Ghidra pseudocode; not original source or compilable C.
// ev_07fa422b39dc9e2221bccc56e20f2ce62408b2119c2f003d89d751e138913a39

void ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelView__Open__060019fa
               (undefined8 param_1,int param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  uint uVar11;
  bool bVar12;
  
  if (cRam0000000182eb7c55 == '\0') {
    FUN_1802f2810(&DAT_182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58380);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aa80);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c55 = '\x01';
  }
  if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d58380);
  }
  if (((**(longlong **)(DAT_182d58238 + 0xb8) != 0) && (**(longlong **)(DAT_182d58380 + 0xb8) != 0))
     && (plVar8 = (longlong *)
                  ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__Open__060011a0
                            (**(longlong **)(DAT_182d58380 + 0xb8),
                             *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x150),0,0),
        plVar8 != (longlong *)0x0)) {
    if ((*(byte *)(lRam0000000182d5aa80 + 0x130) <= *(byte *)(*plVar8 + 0x130)) &&
       (lVar4 = *(longlong *)(*plVar8 + 200),
       *(longlong *)(lVar4 + -8 + (ulonglong)*(byte *)(lRam0000000182d5aa80 + 0x130) * 8) ==
       lRam0000000182d5aa80)) {
      plVar10 = (longlong *)0x0;
      if (*(longlong *)(lVar4 + -8 + (ulonglong)*(byte *)(lRam0000000182d5aa80 + 0x130) * 8) ==
          lRam0000000182d5aa80) {
        plVar10 = plVar8;
      }
      if (cRam0000000182eb7c48 == '\0') {
        FUN_1802f2810(&DAT_182d63358,param_1,param_2,0);
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
      *(int *)(plVar10 + 0x25) = param_2;
      **(undefined8 **)(lRam0000000182d5aa80 + 0xb8) = plVar10;
      if (DAT_182eb5d50 != 0) {
        uVar11 = (uint)(*(ulonglong *)(lRam0000000182d5aa80 + 0xb8) >> 0xc);
        lVar4 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
        do {
          uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
          LOCK();
          bVar12 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
          if (bVar12) {
            *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar3 | 1L << (uVar11 & 0x3f);
          }
          UNLOCK();
        } while (!bVar12);
      }
      plVar8 = (longlong *)FUN_1816791b0(plVar10[6],param_1,0);
      if (plVar8 == (longlong *)0x0) {
        plVar10[6] = 0;
      }
      else {
        plVar9 = (longlong *)0x0;
        if (*plVar8 == DAT_182d58368) {
          plVar9 = plVar8;
        }
        if (plVar9 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031e210(plVar8,DAT_182d58368);
        }
        plVar10[6] = (longlong)plVar9;
        plVar9 = (longlong *)0x0;
        if (*plVar8 == DAT_182d58368) {
          plVar9 = plVar8;
        }
        if (plVar9 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031e210(plVar8);
        }
      }
      if (DAT_182eb5d50 != 0) {
        uVar11 = (uint)((ulonglong)(plVar10 + 6) >> 0xc);
        lVar4 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
        do {
          uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
          LOCK();
          bVar12 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
          if (bVar12) {
            *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar3 | 1L << (ulonglong)(uVar11 & 0x3f);
          }
          UNLOCK();
        } while (!bVar12);
      }
      uVar6 = FUN_1802c43a0(DAT_182d63358);
      FUN_180665bb0(uVar6,plVar10,uRam0000000182d62e60,0);
      if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      FUN_180993250(uVar6,0,DAT_182d63350);
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
        lVar4 = plVar10[0x13];
        uVar6 = FUN_1802c43a0(uRam0000000182d61940);
        FUN_180006cd0(uVar6,plVar10,uRam0000000182d62e50);
        uVar7 = FUN_1802c43a0(uRam0000000182d5e108);
        FUN_180005c40(uVar7,plVar10,uRam0000000182d62e48);
        if (lVar4 != 0) {
          ExposureUnnoticed2_ObjectUI_CommonUI_CommonTab_CommonTabView__Initialize__06001da6
                    (lVar4,uVar6,uVar7,0);
          if (plVar10[0x14] != 0) {
            ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelCosplayView__Initialize__060019ca
                      (plVar10[0x14],plVar10[0x16],plVar10,0);
            if (plVar10[0x14] != 0) {
              ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelCosplayView__Hide__060019d0
                        (plVar10[0x14],0);
              if (plVar10[0x15] != 0) {
                ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelLoadoutView__Initialize__060019d9
                          (plVar10[0x15],plVar10,0);
                if (plVar10[0x15] != 0) {
                  ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelLoadoutView__Hide__060019de
                            (plVar10[0x15],0);
                  ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelView__RefreshEquipCount__060019f0
                            (plVar10,0);
                  if (param_2 < 0) {
                    ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelView__OnClickCategory__060019f3
                              (plVar10,0,0);
                  }
                  else {
                    if (plVar10[0x13] == 0) goto DAT_1804f00a0;
                    ExposureUnnoticed2_ObjectUI_CommonUI_CommonTab_CommonTabView__OnClickTab__06001da7
                              (plVar10[0x13],param_2,0);
                  }
                  uVar6 = FUN_1802c43a0(DAT_182d58368);
                  FUN_1814df680(uVar6,plVar10,uRam0000000182d62e40,0);
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
                    bVar12 = DAT_182eb5d50 != 0;
                    *(undefined8 *)(lVar5 + 0x10) = uVar6;
                    if (bVar12) {
                      uVar11 = (uint)(lVar5 + 0x10U >> 0xc);
                      puVar1 = (ulonglong *)
                               (&DAT_182f0c920 + (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8);
                      do {
                        uVar2 = *puVar1;
                        LOCK();
                        uVar3 = *puVar1;
                        if (uVar2 == uVar3) {
                          *puVar1 = uVar2 | 1L << (uVar11 & 0x3f);
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
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

