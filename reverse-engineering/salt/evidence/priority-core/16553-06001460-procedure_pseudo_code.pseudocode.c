// Ghidra pseudocode; not original source or compilable C.
// ev_e827cead3cb84dabcc4df064baac891f3ac99c08cde0ad3524cd04c68a4558a1

ulonglong ExposureUnnoticed2_Scripts_Mission_MissionInElevatorWithNpc__IsInCondition__06001460
                    (longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  code *pcVar7;
  undefined8 uVar8;
  undefined8 uStack_48;
  undefined4 uStack_40;
  undefined8 uStack_38;
  undefined4 uStack_30;
  undefined8 uStack_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  
  if (cRam0000000182eb791f == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb791f = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
     (lVar2 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar2 == 0))
  goto code_r0x00018047cbf1;
  lVar2 = *(longlong *)(lVar2 + 0x30);
  if (DAT_182eb5490 == '\0') {
    FUN_1802f2810(&DAT_182d59260);
    LOCK();
    UNLOCK();
    DAT_182eb5490 = '\x01';
  }
  lVar6 = **(longlong **)(DAT_182d59260 + 0xb8);
  uVar4 = DAT_182d59260;
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    uVar4 = FUN_18035c820();
  }
  if (DAT_182ec12f3 == '\0') {
    uVar4 = FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec12f3 = '\x01';
  }
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    uVar4 = FUN_18035c820();
  }
  if (DAT_182ec129b == '\0') {
    uVar4 = FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec129b = '\x01';
  }
  if (lVar6 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      uVar4 = FUN_18035c820();
    }
    if (*(longlong *)(lVar6 + 0x10) != 0) {
      if (((lVar2 == 0) || (uVar4 = *(ulonglong *)(lVar2 + 0x40), uVar4 == 0)) ||
         (lVar6 = *(longlong *)(uVar4 + 0x60), lVar6 == 0)) {
code_r0x00018047cbf1:
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      if (*(longlong *)(lVar6 + 0x20) != 0) {
        uVar4 = *(ulonglong *)(lVar6 + 0x20);
        if (*(longlong *)(uVar4 + 0x30) == 0) goto code_r0x00018047cbf1;
        lVar6 = *(longlong *)(*(longlong *)(uVar4 + 0x30) + 0x10);
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          uVar4 = FUN_18035c820();
        }
        if (DAT_182ec12f3 == '\0') {
          uVar4 = FUN_1802f2810(&DAT_182d53aa8);
          LOCK();
          UNLOCK();
          DAT_182ec12f3 = '\x01';
        }
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          uVar4 = FUN_18035c820();
        }
        if (DAT_182ec129b == '\0') {
          uVar4 = FUN_1802f2810(&DAT_182d53aa8);
          LOCK();
          UNLOCK();
          DAT_182ec129b = '\x01';
        }
        if (lVar6 != 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            uVar4 = FUN_18035c820();
          }
          if (*(longlong *)(lVar6 + 0x10) != 0) {
            if (**(longlong **)(DAT_182d58230 + 0xb8) != 0) {
              uVar5 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                                (**(longlong **)(DAT_182d58230 + 0xb8),0);
              if ((*(longlong *)(param_1 + 0x28) != 0) &&
                 (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x20), lVar6 != 0)) {
                uVar1 = *(uint *)(lVar6 + 0x34);
                uVar4 = uVar5;
                if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
                  uVar4 = FUN_18035c820();
                }
                if (((uint)uVar5 & uVar1) == 0) goto code_r0x00018047cbed;
                lVar6 = FUN_180436630();
                if ((*(longlong *)(lVar2 + 0x40) != 0) &&
                   (lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0x40) + 0x18), lVar3 != 0)) {
                  uStack_48 = 0;
                  uStack_40 = 0;
                  pcVar7 = DAT_182ec1698;
                  if ((DAT_182ec1698 == (code *)0x0) &&
                     (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar7 == (code *)0x0)) {
                    uVar8 = FUN_1802ced60(
                                         "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                         );
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar8,0);
                  }
                  DAT_182ec1698 = pcVar7;
                  (*DAT_182ec1698)(lVar3,&uStack_48);
                  if (lVar6 != 0) {
                    uStack_28 = *(undefined8 *)(lVar6 + 0x5c);
                    uStack_20 = *(undefined8 *)(lVar6 + 100);
                    uStack_18 = *(undefined8 *)(lVar6 + 0x6c);
                    uStack_30 = uStack_40;
                    uStack_38 = uStack_48;
                    pcVar7 = pcRam0000000182ebfdb8;
                    if ((pcRam0000000182ebfdb8 == (code *)0x0) &&
                       (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                                                  ), pcVar7 == (code *)0x0)) {
                      uVar8 = FUN_1802ced60(
                                           "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                                           );
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar8,0);
                    }
                    pcRam0000000182ebfdb8 = pcVar7;
                    uVar4 = (*pcRam0000000182ebfdb8)(&uStack_28,&uStack_38);
                    if ((char)uVar4 == '\0') goto code_r0x00018047cbed;
                    lVar6 = FUN_180436630();
                    if ((((*(longlong *)(lVar2 + 0x40) != 0) &&
                         (lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x40) + 0x60), lVar2 != 0)) &&
                        (lVar2 = *(longlong *)(lVar2 + 0x20), lVar2 != 0)) &&
                       ((lVar2 = *(longlong *)(lVar2 + 0x30), lVar2 != 0 &&
                        (lVar2 = *(longlong *)(lVar2 + 0x10), lVar2 != 0)))) {
                      uStack_48 = 0;
                      uStack_40 = 0;
                      pcVar7 = DAT_182ec1698;
                      if ((DAT_182ec1698 == (code *)0x0) &&
                         (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar7 == (code *)0x0)) {
                        uVar8 = FUN_1802ced60(
                                             "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                             );
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar8,0);
                      }
                      DAT_182ec1698 = pcVar7;
                      (*DAT_182ec1698)(lVar2,&uStack_48);
                      if (lVar6 != 0) {
                        uStack_28 = *(undefined8 *)(lVar6 + 0x5c);
                        uStack_20 = *(undefined8 *)(lVar6 + 100);
                        uStack_18 = *(undefined8 *)(lVar6 + 0x6c);
                        uStack_30 = uStack_40;
                        uStack_38 = uStack_48;
                        pcVar7 = pcRam0000000182ebfdb8;
                        if ((pcRam0000000182ebfdb8 == (code *)0x0) &&
                           (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                                                  ), pcVar7 == (code *)0x0)) {
                          uVar8 = FUN_1802ced60(
                                               "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                                               );
                    /* WARNING: Subroutine does not return */
                          FUN_1802cca90(uVar8,0);
                        }
                        pcRam0000000182ebfdb8 = pcVar7;
                        uVar4 = (*pcRam0000000182ebfdb8)(&uStack_28,&uStack_38);
                        return uVar4;
                      }
                    }
                  }
                }
              }
            }
            goto code_r0x00018047cbf1;
          }
        }
      }
    }
  }
code_r0x00018047cbed:
  return uVar4 & 0xffffffffffffff00;
}

