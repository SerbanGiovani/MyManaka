// Ghidra pseudocode; not original source or compilable C.
// ev_b1867fcdfac5edf89d1873aa382eeb63d57f5c7fbc248f92b3e9c0562aea2193

undefined8
ExposureUnnoticed2_Scripts_InGame_DroppedItemManager___ApplyReserveDropIfNeed_b__12_0__06001513
          (undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  code *pcVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uStack_38;
  undefined4 uStack_30;
  undefined8 uStack_28;
  undefined8 uStack_20;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (cRam0000000182eb797d == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb797d = '\x01';
  }
  if ((param_2 != 0) &&
     (lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48), lVar3 != 0)) {
    if (*(int *)(param_2 + 0x30) != *(int *)(lVar3 + 0x10)) {
      return 0;
    }
    *(undefined1 *)(param_2 + 0x11) = 0;
    if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
       (lVar3 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x40), lVar3 != 0)) {
      lVar3 = *(longlong *)(lVar3 + 0xc0);
      if ((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
         ((lVar1 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar1 != 0 &&
          (lVar1 = *(longlong *)(lVar1 + 0x18), lVar1 != 0)))) {
        uStack_38 = 0;
        uStack_30 = 0;
        pcVar2 = DAT_182ec1698;
        if ((DAT_182ec1698 == (code *)0x0) &&
           (pcVar2 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                          ), pcVar2 == (code *)0x0)) {
          uVar4 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar4,0);
        }
        DAT_182ec1698 = pcVar2;
        (*DAT_182ec1698)(lVar1,&uStack_38);
        if (lVar3 != 0) {
          uStack_28 = uStack_38;
          uStack_20 = CONCAT44(uStack_20._4_4_,uStack_30);
          lVar3 = ExposureUnnoticed2_Scripts_InGame_StageRandomPositionManager__GetRandomPosition__06001662
                            (lVar3,&uStack_28,0);
          if (lVar3 != 0) {
            uStack_38 = 0;
            uStack_30 = 0;
            pcVar2 = DAT_182ec1698;
            if ((DAT_182ec1698 == (code *)0x0) &&
               (pcVar2 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                              ), pcVar2 == (code *)0x0)) {
              uVar4 = FUN_1802ced60(
                                   "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar4,0);
            }
            DAT_182ec1698 = pcVar2;
            (*DAT_182ec1698)(lVar3,&uStack_38);
            uStack_28 = 0;
            uStack_20 = 0;
            pcVar2 = DAT_182ec16b8;
            if ((DAT_182ec16b8 == (code *)0x0) &&
               (pcVar2 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                              ), pcVar2 == (code *)0x0)) {
              uVar4 = FUN_1802ced60(
                                   "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar4,0);
            }
            DAT_182ec16b8 = pcVar2;
            (*DAT_182ec16b8)(lVar3,&uStack_28);
            uStack_18 = (undefined4)uStack_28;
            uStack_14 = uStack_28._4_4_;
            uStack_10 = (undefined4)uStack_20;
            uStack_c = uStack_20._4_4_;
            uStack_28 = uStack_38;
            uStack_20 = CONCAT44(uStack_20._4_4_,uStack_30);
            uVar4 = ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__Drop__060014ff
                              (param_1,&uStack_28,&uStack_18,*(undefined4 *)(param_2 + 0x34),0);
            if (cRam0000000182eb54a8 == '\0') {
              FUN_1802f2810(0x182d5d530);
              LOCK();
              UNLOCK();
              cRam0000000182eb54a8 = '\x01';
            }
            if (**(longlong **)(lRam0000000182d5d530 + 0xb8) != 0) {
              ExposureUnnoticed2_ObjectUI_InGame_Compass_CompassView__RegisterTarget__06001b34
                        (**(longlong **)(lRam0000000182d5d530 + 0xb8),uVar4,0);
              return 1;
            }
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

