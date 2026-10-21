// Ghidra pseudocode; not original source or compilable C.
// ev_c78b364b2f5e0c28a018de09f0e7503567cfca27814d847ebb23267e6e8f037c

void ExposureUnnoticed2_Scripts_InGame_InGameEventListener__OnCompleteTransitionStageEvent__06001570
               (longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  ulonglong uVar3;
  char cVar4;
  longlong lVar5;
  code *pcVar6;
  undefined8 uVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong uVar10;
  uint uVar11;
  longlong lVar12;
  bool bVar13;
  undefined8 uStack_38;
  undefined4 uStack_30;
  undefined8 uStack_28;
  undefined8 uStack_20;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (cRam0000000182eb79d0 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e258);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e108);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d594e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d800);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d7f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5d7f0);
    LOCK();
    UNLOCK();
    cRam0000000182eb79d0 = '\x01';
  }
  lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (((param_2 != 0) && (*(longlong *)(param_2 + 0x10) != 0)) && (lVar5 != 0)) {
    *(undefined4 *)(lVar5 + 0x10) = *(undefined4 *)(*(longlong *)(param_2 + 0x10) + 0x20);
    if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
        (lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar5 != 0)) &&
       (*(longlong *)(param_2 + 0x10) != 0)) {
      lVar5 = ExposureUnnoticed2_Scripts_InGame_StageController__GetSpawnPoint__0600165a
                        (*(longlong *)(param_2 + 0x10),*(undefined4 *)(lVar5 + 0x18),0);
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
      if (lVar5 != 0) {
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (*(longlong *)(lVar5 + 0x10) != 0) {
          if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
             (lVar9 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar9 == 0))
          goto code_r0x000180494aae;
          lVar9 = *(longlong *)(lVar9 + 0x30);
          uStack_38 = 0;
          uStack_30 = 0;
          pcVar6 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar6 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar6 == (code *)0x0)) {
            uVar7 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar7,0);
          }
          DAT_182ec1698 = pcVar6;
          (*DAT_182ec1698)(lVar5,&uStack_38);
          uStack_28 = 0;
          uStack_20 = 0;
          pcVar6 = DAT_182ec16b8;
          if ((DAT_182ec16b8 == (code *)0x0) &&
             (pcVar6 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                            ), pcVar6 == (code *)0x0)) {
            uVar7 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar7,0);
          }
          DAT_182ec16b8 = pcVar6;
          (*DAT_182ec16b8)(lVar5,&uStack_28);
          if (lVar9 == 0) goto code_r0x000180494aae;
          uStack_18 = (undefined4)uStack_28;
          uStack_14 = uStack_28._4_4_;
          uStack_10 = (undefined4)uStack_20;
          uStack_c = uStack_20._4_4_;
          uStack_28 = uStack_38;
          uStack_20 = CONCAT44(uStack_20._4_4_,uStack_30);
          ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController__Warp__06000d62
                    (lVar9,&uStack_28,&uStack_18,0);
          if (*(longlong *)(param_1 + 0x10) == 0) goto code_r0x000180494aae;
          ExposureUnnoticed2_Scripts_InGame_GameStateApplier__OnLateUpdate__0600151f
                    (*(longlong *)(param_1 + 0x10),0,0);
        }
      }
      if (*(longlong *)(param_2 + 0x10) != 0) {
        uVar1 = *(undefined4 *)(*(longlong *)(param_2 + 0x10) + 0x20);
        if (*(int *)(DAT_182d594e8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uVar7 = ExposureUnnoticed2_Master_Stage_MStage__Get__06001229(uVar1,0);
        ExposureUnnoticed2_ObjectUI_StageNamePanel_StageNamePanelView__Open__06001a64(uVar7,0);
        if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
            (lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar5 != 0)) &&
           (lVar5 = *(longlong *)(lVar5 + 0x50), lVar5 != 0)) {
          uVar11 = 0;
          *(undefined4 *)(lVar5 + 0x68) = 0;
          ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__RepopNpc__06001098(lVar5,0);
          if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
             (lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x20), lVar5 != 0)) {
            if (cRam0000000182eb796e == '\0') {
              FUN_1802f2810(0x182d5dfa0);
              LOCK();
              UNLOCK();
              FUN_1802f2810(0x182d5df98);
              LOCK();
              UNLOCK();
              FUN_1802f2810(&DAT_182d58288);
              LOCK();
              UNLOCK();
              FUN_1802f2810(0x182d5df90);
              LOCK();
              UNLOCK();
              FUN_1802f2810(&DAT_182d58398);
              LOCK();
              UNLOCK();
              cRam0000000182eb796e = '\x01';
            }
            lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar9 != 0) {
              lVar9 = *(longlong *)(lVar9 + 0x28);
              lVar8 = FUN_1802c43a0(uRam0000000182d5df90);
              FUN_1810d6200(lVar8,lVar5,uRam0000000182d5dfa0,0);
              if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
                FUN_18035c820();
              }
              lVar5 = lRam0000000182d5df98;
              if (*(longlong *)(lRam0000000182d5df98 + 0x38) == 0) {
                FUN_1803204f0(lRam0000000182d5df98);
              }
              if (lVar9 != 0) {
                lVar12 = 0x20;
                while ((int)uVar11 < *(int *)(lVar9 + 0x18)) {
                  if (*(uint *)(lVar9 + 0x18) <= uVar11) {
                    /* WARNING: Subroutine does not return */
                    FUN_181640100(0);
                  }
                  lVar2 = *(longlong *)(lVar9 + 0x10);
                  if (lVar2 == 0) goto code_r0x000180494aae;
                  if (*(uint *)(lVar2 + 0x18) <= uVar11) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dae0();
                  }
                  if (lVar8 == 0) goto code_r0x000180494aae;
                  cVar4 = (**(code **)(lVar8 + 0x18))
                                    (*(undefined8 *)(lVar8 + 0x40),*(undefined8 *)(lVar12 + lVar2),
                                     *(undefined8 *)(lVar8 + 0x28));
                  if (cVar4 == '\0') {
                    uVar11 = uVar11 + 1;
                    lVar12 = lVar12 + 8;
                  }
                  else {
                    uVar7 = FUN_180002d60(lVar9,uVar11);
                    FUN_181274e50(lVar9,uVar7,*(undefined8 *)(*(longlong *)(lVar5 + 0x38) + 0x28));
                  }
                }
                if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                    (lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x20), lVar5 != 0
                    )) && (ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__ActiveDroppedItemIfNeed__0600150e
                                     (lVar5,0), **(longlong **)(lRam0000000182d5e258 + 0xb8) != 0))
                {
                  if (cRam0000000182eb7962 == '\0') {
                    FUN_1802f2810(&DAT_182d58398);
                    LOCK();
                    UNLOCK();
                    cRam0000000182eb7962 = '\x01';
                  }
                  lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                  if (lVar5 != 0) {
                    if (*(int *)(lVar5 + 0xbc) != -1) {
                      if (*(int *)(lRam0000000182d5d7f0 + 0xe0) == 0) {
                        FUN_18035c820();
                      }
                      lVar5 = *(longlong *)(*(longlong *)(lRam0000000182d5d7f0 + 0xb8) + 8);
                      if (lVar5 == 0) {
                        if (*(int *)(lRam0000000182d5d7f0 + 0xe0) == 0) {
                          FUN_18035c820();
                        }
                        uVar7 = **(undefined8 **)(lRam0000000182d5d7f0 + 0xb8);
                        lVar5 = FUN_1802c43a0(DAT_182d58368);
                        FUN_1814df680(lVar5,uVar7,uRam0000000182d5d800,0);
                        *(longlong *)(*(longlong *)(lRam0000000182d5d7f0 + 0xb8) + 8) = lVar5;
                        if (DAT_182eb5d50 != 0) {
                          uVar11 = (uint)(*(longlong *)(lRam0000000182d5d7f0 + 0xb8) + 8U >> 0xc);
                          uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
                          do {
                            uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                            LOCK();
                            bVar13 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                            if (bVar13) {
                              *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) =
                                   uVar3 | 1L << (uVar11 & 0x3f);
                            }
                            UNLOCK();
                          } while (!bVar13);
                        }
                      }
                      if (*(int *)(lRam0000000182d5d7f0 + 0xe0) == 0) {
                        FUN_18035c820();
                      }
                      lVar9 = *(longlong *)(*(longlong *)(lRam0000000182d5d7f0 + 0xb8) + 0x10);
                      if (lVar9 == 0) {
                        if (*(int *)(lRam0000000182d5d7f0 + 0xe0) == 0) {
                          FUN_18035c820();
                        }
                        uVar7 = **(undefined8 **)(lRam0000000182d5d7f0 + 0xb8);
                        lVar9 = FUN_1802c43a0(uRam0000000182d5e108);
                        FUN_180005c40(lVar9,uVar7,uRam0000000182d5d7f8);
                        *(longlong *)(*(longlong *)(lRam0000000182d5d7f0 + 0xb8) + 0x10) = lVar9;
                        if (DAT_182eb5d50 != 0) {
                          uVar11 = (uint)(*(longlong *)(lRam0000000182d5d7f0 + 0xb8) + 0x10U >> 0xc)
                          ;
                          uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
                          do {
                            uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                            LOCK();
                            bVar13 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                            if (bVar13) {
                              *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) =
                                   uVar3 | 1L << (uVar11 & 0x3f);
                            }
                            UNLOCK();
                          } while (!bVar13);
                        }
                      }
                      ExposureUnnoticed2_Scripts_Base_Scheduler__DelayCondition__0600174e
                                (lVar5,lVar9,0x41200000,0);
                    }
                    lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                    if (lVar5 != 0) {
                      if (*(int *)(lVar5 + 0x10) != 0) {
                        return;
                      }
                      if ((((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                           (lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28),
                           lVar5 != 0)) && (lVar5 = *(longlong *)(lVar5 + 0x30), lVar5 != 0)) &&
                         ((lVar5 = *(longlong *)(lVar5 + 0x40), lVar5 != 0 &&
                          (lVar5 = *(longlong *)(lVar5 + 200), lVar5 != 0)))) {
                        if (cRam0000000182eb8367 == '\0') {
                          FUN_1802f2810(&DAT_182d58398);
                          LOCK();
                          UNLOCK();
                          cRam0000000182eb8367 = '\x01';
                        }
                        lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                        if (lVar9 != 0) {
                          *(undefined4 *)(lVar9 + 0x16c) = *(undefined4 *)(lVar5 + 0x10);
                          *(undefined1 *)(lVar5 + 0x30) = 0;
                          *(undefined1 *)(lVar5 + 0x14) = 0;
                          return;
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
    }
  }
code_r0x000180494aae:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

