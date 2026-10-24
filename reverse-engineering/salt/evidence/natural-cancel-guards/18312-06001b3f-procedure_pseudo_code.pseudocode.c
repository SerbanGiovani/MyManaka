// Ghidra pseudocode; not original source or compilable C.
// ev_afd5aa4f4d766686c9a6fe855175766540dded2465873e535fd4d6fb0c929297

void ExposureUnnoticed2_ObjectUI_FastTravelPanel_FastTravelPanelView___OnClickFastTravel_b__14_0__06001b3f
               (longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  code *pcVar7;
  undefined8 uVar8;
  uint uVar9;
  bool bVar10;
  undefined8 uStack_38;
  undefined *puStack_30;
  undefined8 uStack_28;
  undefined8 uStack_20;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (cRam0000000182eb7d0a == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64618);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64628);
    LOCK();
    UNLOCK();
    cRam0000000182eb7d0a = '\x01';
  }
  if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) && (*(longlong *)(param_1 + 0x90) != 0)) &&
     (lVar6 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x40), lVar6 != 0)) {
    lVar6 = ExposureUnnoticed2_Scripts_InGame_StageController__GetSpawnPoint__0600165a
                      (lVar6,*(undefined4 *)(*(longlong *)(param_1 + 0x90) + 0x24),0);
    if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
        (lVar4 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar4 != 0)) &&
       (lVar4 = *(longlong *)(lVar4 + 0x30), lVar6 != 0)) {
      uStack_38 = 0;
      puStack_30 = (undefined *)((ulonglong)puStack_30 & 0xffffffff00000000);
      pcVar7 = DAT_182ec1698;
      if ((DAT_182ec1698 == (code *)0x0) &&
         (pcVar7 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                        ), pcVar7 == (code *)0x0)) {
        uVar8 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar8,0);
      }
      DAT_182ec1698 = pcVar7;
      (*DAT_182ec1698)(lVar6,&uStack_38);
      uStack_28 = 0;
      uStack_20 = 0;
      pcVar7 = DAT_182ec16b8;
      if ((DAT_182ec16b8 == (code *)0x0) &&
         (pcVar7 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                        ), pcVar7 == (code *)0x0)) {
        uVar8 = FUN_1802ced60(
                             "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar8,0);
      }
      DAT_182ec16b8 = pcVar7;
      (*DAT_182ec16b8)(lVar6,&uStack_28);
      if (lVar4 != 0) {
        uStack_18 = (undefined4)uStack_28;
        uStack_14 = uStack_28._4_4_;
        uStack_10 = (undefined4)uStack_20;
        uStack_c = uStack_20._4_4_;
        uStack_28 = uStack_38;
        uStack_20 = CONCAT44(uStack_20._4_4_,puStack_30._0_4_);
        ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController__Warp__06000d62
                  (lVar4,&uStack_28,&uStack_18,0);
        if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
            (lVar6 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar6 != 0)) &&
           (lVar6 = *(longlong *)(lVar6 + 0x40), lVar6 != 0)) {
          ExposureUnnoticed2_Object3D_Camera_TPCameraController__ResetToPlayerDirect__06001219
                    (lVar6,0);
          Common_Scripts_UI_BasePanelView__Close__06001e15(param_1,0);
          if (*(int *)(lRam0000000182d64628 + 0xe0) == 0) {
            FUN_18035c820();
          }
          lVar6 = *(longlong *)(*(longlong *)(lRam0000000182d64628 + 0xb8) + 8);
          if (lVar6 == 0) {
            if (*(int *)(lRam0000000182d64628 + 0xe0) == 0) {
              FUN_18035c820();
            }
            uVar8 = **(undefined8 **)(lRam0000000182d64628 + 0xb8);
            lVar6 = FUN_1802c43a0(DAT_182d58368);
            FUN_1814df680(lVar6,uVar8,uRam0000000182d64618,0);
            *(longlong *)(*(longlong *)(lRam0000000182d64628 + 0xb8) + 8) = lVar6;
            if (DAT_182eb5d50 != 0) {
              uVar9 = (uint)(*(longlong *)(lRam0000000182d64628 + 0xb8) + 8U >> 0xc);
              puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8);
              do {
                uVar3 = *puVar1;
                LOCK();
                uVar2 = *puVar1;
                if (uVar3 == uVar2) {
                  *puVar1 = uVar3 | 1L << (uVar9 & 0x3f);
                }
                UNLOCK();
              } while (uVar3 != uVar2);
            }
          }
          if (DAT_182eb7aa1 == '\0') {
            puStack_30 = (undefined *)0x1804b3c84;
            FUN_1802f2810(&DAT_182d5f910,1,0);
            LOCK();
            UNLOCK();
            puStack_30 = (undefined *)0x1804b3c95;
            FUN_1802f2810(&DAT_182d5f908);
            LOCK();
            UNLOCK();
            DAT_182eb7aa1 = '\x01';
          }
          puStack_30 = (undefined *)0x1804b3cad;
          lVar4 = ExposureUnnoticed2_Scripts_Base_Scheduler__get_Instance__0600174a(0);
          if (lVar4 != 0) {
            lVar4 = *(longlong *)(lVar4 + 0x20);
            puStack_30 = (undefined *)0x1804b3cc6;
            lVar5 = FUN_1802c43a0(DAT_182d5f910);
            bVar10 = DAT_182eb5d50 != 0;
            *(longlong *)(lVar5 + 0x10) = lVar6;
            if (bVar10) {
              uVar9 = (uint)(lVar5 + 0x10U >> 0xc);
              puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8);
              do {
                uVar3 = *puVar1;
                LOCK();
                uVar2 = *puVar1;
                if (uVar3 == uVar2) {
                  *puVar1 = uVar3 | 1L << (uVar9 & 0x3f);
                }
                UNLOCK();
              } while (uVar3 != uVar2);
            }
            *(undefined4 *)(lVar5 + 0x18) = 1;
            if (lVar4 != 0) {
              FUN_1800068f0(lVar4,lVar5);
              return;
            }
          }
                    /* WARNING: Subroutine does not return */
          puStack_30 = &UNK_1804b3d39;
          FUN_18031dad0();
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

