// Ghidra pseudocode; not original source or compilable C.
// ev_ed6ce232cea2f62a06429266cef37575927f60f04da8efd461abc0d751f1d828

void ExposureUnnoticed2_Scripts_InGame_EventMethodManager__LateUpdate__06001519(longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong *plVar5;
  char cVar6;
  undefined8 *puVar7;
  ushort uVar8;
  uint uVar9;
  undefined8 uStack_40;
  undefined4 *puStack_38;
  undefined8 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  longlong *plStack_18;
  
  if (cRam0000000182eb7982 == '\0') {
    FUN_1802f2810(0x182d5dec8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dec0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5deb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5deb0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dea8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7982 = '\x01';
  }
  lVar3 = *(longlong *)(param_1 + 0x30);
  if (lVar3 != 0) {
    if (DAT_182eb5d50 != 0) {
      uVar9 = (uint)((ulonglong)&uStack_40 >> 0xc);
      puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8);
      do {
        uVar4 = *puVar1;
        LOCK();
        uVar2 = *puVar1;
        if (uVar4 == uVar2) {
          *puVar1 = uVar4 | 1L << (uVar9 & 0x3f);
        }
        UNLOCK();
      } while (uVar4 != uVar2);
    }
    uStack_1c = *(undefined4 *)(lVar3 + 0x1c);
    uStack_30 = 0;
    uStack_40._0_4_ = (undefined4)lVar3;
    uStack_40._4_4_ = (undefined4)((ulonglong)lVar3 >> 0x20);
    uStack_28 = (undefined4)uStack_40;
    uStack_24 = uStack_40._4_4_;
    uStack_20 = 0;
    plStack_18 = (longlong *)0x0;
    uStack_40 = 0;
    puStack_38 = &uStack_28;
    while (cVar6 = FUN_180f72b70(&uStack_28,uRam0000000182d5dec0), plVar5 = plStack_18,
          cVar6 != '\0') {
      if (plStack_18 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      lVar3 = *plStack_18;
      uVar8 = 0;
      if (*(ushort *)(lVar3 + 0x12e) != 0) {
        do {
          if (*(longlong *)(*(longlong *)(lVar3 + 0xb0) + (ulonglong)uVar8 * 0x10) ==
              lRam0000000182d5deb0) {
            puVar7 = (undefined8 *)
                     ((longlong)*(int *)(*(longlong *)(lVar3 + 0xb0) + 8 + (ulonglong)uVar8 * 0x10)
                      * 0x10 + 0x138 + lVar3);
            goto code_r0x00018048b8e9;
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < *(ushort *)(lVar3 + 0x12e));
      }
      puVar7 = (undefined8 *)FUN_180320910(plStack_18,lRam0000000182d5deb0,0);
code_r0x00018048b8e9:
      (*(code *)*puVar7)(plVar5,puVar7[1]);
    }
    if ((*(longlong *)(param_1 + 0x38) != 0) &&
       (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x40), lVar3 != 0)) {
      ExposureUnnoticed2_Object3D_Camera_TPCameraController__OnLateUpdate__06001215(lVar3,0);
      if ((*(longlong *)(param_1 + 0x38) != 0) &&
         (((lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x30), lVar3 != 0 &&
           (lVar3 = *(longlong *)(lVar3 + 0x30), lVar3 != 0)) &&
          (lVar3 = *(longlong *)(lVar3 + 0x78), lVar3 != 0)))) {
        ExposureUnnoticed2_Object3D_Camera_FPCameraController__OnLateUpdate__060011ff(lVar3,0);
        if ((*(longlong *)(param_1 + 0x38) != 0) &&
           (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x38), lVar3 != 0)) {
          ExposureUnnoticed2_Object3D_Camera_BaseCameraController__OnLateUpdate__060011e7(lVar3,0);
          return;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

