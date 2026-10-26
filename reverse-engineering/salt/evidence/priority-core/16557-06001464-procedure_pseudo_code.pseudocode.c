// Ghidra pseudocode; not original source or compilable C.
// ev_cf90c9524237907a4d209776c2f59fd5ca86e4d8ab05419b4257c6598831ddf2

bool ExposureUnnoticed2_Scripts_Mission_MissionMallFloorDistByClothes__IsInCondition__06001464
               (longlong param_1)

{
  longlong lVar1;
  float fVar2;
  char cVar3;
  longlong lVar4;
  code *pcVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined8 uStack_58;
  undefined4 uStack_50;
  undefined8 uStack_48;
  undefined4 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  
  if (cRam0000000182eb7921 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5acd0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5acc8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb7921 = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar1 != 0)) {
    lVar1 = *(longlong *)(lVar1 + 0x30);
    if ((**(longlong **)(DAT_182d58230 + 0xb8) != 0) &&
       ((lVar4 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar4 != 0 &&
        (lVar4 = *(longlong *)(lVar4 + 0x60), lVar4 != 0)))) {
      if (*(int *)(lVar4 + 0x168) == 0) {
        if ((((lVar1 == 0) || (*(longlong *)(lVar1 + 0x40) == 0)) ||
            (lVar4 = *(longlong *)(*(longlong *)(lVar1 + 0x40) + 0x60), lVar4 == 0)) ||
           (lVar4 = *(longlong *)(lVar4 + 0x10), lVar4 == 0)) goto code_r0x00018047d394;
        if (*(int *)(lVar4 + 0x30) != -1) {
          *(undefined1 *)(param_1 + 0x3c) = 0;
        }
      }
      else {
        *(undefined1 *)(param_1 + 0x3c) = 1;
        *(undefined4 *)(param_1 + 0x30) = 0;
      }
      if (*(char *)(param_1 + 0x3c) != '\0') {
        return false;
      }
      if (DAT_182eb5480 == '\0') {
        FUN_1802f2810(&DAT_182d522a8);
        LOCK();
        UNLOCK();
        DAT_182eb5480 = '\x01';
      }
      if (DAT_182eb54a2 == '\0') {
        FUN_1802f2810(&DAT_182d5bcb8);
        LOCK();
        UNLOCK();
        DAT_182eb54a2 = '\x01';
      }
      if (**(longlong **)(DAT_182d5bcb8 + 0xb8) != 0) {
        lVar4 = ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__GetDropClothesInSameArea__0600150d
                          (**(longlong **)(DAT_182d5bcb8 + 0xb8),0);
        if (lVar4 == 0) {
          if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
             (lVar4 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar4 == 0))
          goto code_r0x00018047d394;
          if (*(char *)(lVar4 + 0x54) == '\0') {
            return false;
          }
          lVar4 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30);
          uVar7 = *(undefined8 *)(lVar4 + 0x58);
          uVar8 = (undefined4)uVar7;
          uVar9 = (undefined4)((ulonglong)uVar7 >> 0x20);
          uStack_40 = *(undefined4 *)(lVar4 + 0x60);
        }
        else {
          if (DAT_182eb54a2 == '\0') {
            FUN_1802f2810(&DAT_182d5bcb8);
            LOCK();
            UNLOCK();
            DAT_182eb54a2 = '\x01';
          }
          if ((**(longlong **)(DAT_182d5bcb8 + 0xb8) == 0) ||
             (lVar4 = ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__GetCache__060014fd
                                (**(longlong **)(DAT_182d5bcb8 + 0xb8),*(undefined4 *)(lVar4 + 0x34)
                                 ,0), lVar4 == 0)) goto code_r0x00018047d394;
          pcVar5 = DAT_182ec1080;
          if ((DAT_182ec1080 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
             pcVar5 == (code *)0x0)) {
            uVar7 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar7,0);
          }
          DAT_182ec1080 = pcVar5;
          lVar4 = (*DAT_182ec1080)(lVar4);
          if (lVar4 == 0) goto code_r0x00018047d394;
          uStack_58 = 0;
          uStack_50 = 0;
          pcVar5 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar5 == (code *)0x0)) {
            uVar7 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar7,0);
          }
          DAT_182ec1698 = pcVar5;
          (*DAT_182ec1698)(lVar4,&uStack_58);
          uVar8 = (undefined4)uStack_58;
          uVar9 = (undefined4)((ulonglong)uStack_58 >> 0x20);
          uStack_40 = uStack_50;
        }
        uStack_48 = CONCAT44(uVar9,uVar8);
        if (**(longlong **)(DAT_182d58230 + 0xb8) != 0) {
          uVar6 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                            (**(longlong **)(DAT_182d58230 + 0xb8),0);
          if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if ((uVar6 & 0x20) == 0) {
            return false;
          }
          if (((lVar1 != 0) && (*(longlong *)(lVar1 + 0x40) != 0)) &&
             (lVar4 = *(longlong *)(*(longlong *)(lVar1 + 0x40) + 0x18), lVar4 != 0)) {
            uStack_58 = 0;
            uStack_50 = 0;
            pcVar5 = DAT_182ec1698;
            if ((DAT_182ec1698 == (code *)0x0) &&
               (pcVar5 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                              ), pcVar5 == (code *)0x0)) {
              uVar7 = FUN_1802ced60(
                                   "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar7,0);
            }
            DAT_182ec1698 = pcVar5;
            (*DAT_182ec1698)(lVar4,&uStack_58);
            if (*(longlong *)(param_1 + 0x28) != 0) {
              fVar2 = uStack_48._4_4_;
              if (ABS(uStack_48._4_4_ - uStack_58._4_4_) <
                  *(float *)(*(longlong *)(param_1 + 0x28) + 0x38) * 5.3) {
                return false;
              }
              if ((*(longlong *)(lVar1 + 0x40) != 0) &&
                 (lVar4 = *(longlong *)(*(longlong *)(lVar1 + 0x40) + 0x18), lVar4 != 0)) {
                uStack_48 = 0;
                uStack_40 = 0;
                pcVar5 = DAT_182ec1698;
                if ((DAT_182ec1698 == (code *)0x0) &&
                   (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar5 == (code *)0x0)) {
                  uVar7 = FUN_1802ced60(
                                       "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar7,0);
                }
                DAT_182ec1698 = pcVar5;
                (*DAT_182ec1698)(lVar4,&uStack_48);
                if (*(longlong *)(param_1 + 0x28) != 0) {
                  if ((*(float *)(*(longlong *)(param_1 + 0x28) + 0x38) + 1.0) * 5.3 <=
                      ABS(fVar2 - uStack_48._4_4_)) {
                    return false;
                  }
                  lVar4 = FUN_180436630();
                  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                    FUN_18035c820();
                  }
                  if (DAT_182ec12f4 == '\0') {
                    FUN_1802f2810(&DAT_182d53aa8);
                    LOCK();
                    UNLOCK();
                    DAT_182ec12f4 = '\x01';
                  }
                  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                    FUN_18035c820();
                  }
                  if (DAT_182ec129b == '\0') {
                    FUN_1802f2810(&DAT_182d53aa8);
                    LOCK();
                    UNLOCK();
                    DAT_182ec129b = '\x01';
                  }
                  if (lVar4 == 0) {
                    return false;
                  }
                  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                    FUN_18035c820();
                  }
                  if (*(longlong *)(lVar4 + 0x10) == 0) {
                    return false;
                  }
                  lVar4 = FUN_180436630();
                  if ((*(longlong *)(lVar1 + 0x40) != 0) &&
                     (lVar1 = *(longlong *)(*(longlong *)(lVar1 + 0x40) + 0x18), lVar1 != 0)) {
                    uStack_48 = 0;
                    uStack_40 = 0;
                    pcVar5 = DAT_182ec1698;
                    if ((DAT_182ec1698 == (code *)0x0) &&
                       (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar5 == (code *)0x0)) {
                      uVar7 = FUN_1802ced60(
                                           "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                           );
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar7,0);
                    }
                    DAT_182ec1698 = pcVar5;
                    (*DAT_182ec1698)(lVar1,&uStack_48);
                    if (lVar4 != 0) {
                      uStack_38 = *(undefined8 *)(lVar4 + 0x5c);
                      uStack_30 = *(undefined8 *)(lVar4 + 100);
                      uStack_28 = *(undefined8 *)(lVar4 + 0x6c);
                      uStack_50 = uStack_40;
                      uStack_58 = uStack_48;
                      pcVar5 = pcRam0000000182ebfdb8;
                      if ((pcRam0000000182ebfdb8 == (code *)0x0) &&
                         (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                                                  ), pcVar5 == (code *)0x0)) {
                        uVar7 = FUN_1802ced60(
                                             "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                                             );
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar7,0);
                      }
                      pcRam0000000182ebfdb8 = pcVar5;
                      cVar3 = (*pcRam0000000182ebfdb8)(&uStack_38,&uStack_58);
                      return cVar3 == '\0';
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
code_r0x00018047d394:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

