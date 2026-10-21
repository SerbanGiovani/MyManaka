// Ghidra pseudocode; not original source or compilable C.
// ev_c3f51723b860e83666d8127b8999eeeb31232ad4b1442f6fc54623cabad0d827

void ExposureUnnoticed2_Scripts_InGame_InGameManager__OnUpdate__06001597(longlong param_1)

{
  int *piVar1;
  float fVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  code *pcVar6;
  undefined8 uVar7;
  float fVar8;
  
  if (*(longlong *)(param_1 + 0x80) != 0) {
    if (cRam0000000182eb7987 == '\0') {
      FUN_1802f2810(&DAT_182d583a0);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d58080);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d58398);
      LOCK();
      UNLOCK();
      FUN_1802f2810(&DAT_182d53c48);
      LOCK();
      UNLOCK();
      cRam0000000182eb7987 = '\x01';
    }
    lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar3 != 0) {
      if ((*(int *)(lVar3 + 0x1bc) < 1) || (*(float *)(lVar3 + 0x16c) <= 0.0)) {
        if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
           (lVar3 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar3 == 0))
        goto code_r0x0001804988ce;
        if ((*(char *)(lVar3 + 0x11) == '\0') &&
           (*(int *)(*(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48) + 0x10) != 0)) {
          *(undefined1 *)(*(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30) + 0x11) = 1;
          if (*(int *)(DAT_182d58080 + 0xe0) == 0) {
            FUN_18035c820(DAT_182d58080);
          }
          uVar7 = *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x20);
          if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
            FUN_18035c820();
          }
          ExposureUnnoticed2_Scripts_Base_EventManager__Broadcast__06001716(uVar7,0);
        }
      }
      if (*(longlong *)(param_1 + 0x48) != 0) {
        ExposureUnnoticed2_Scripts_InGame_VisibilityFogController__OnUpdate__0600168a
                  (*(longlong *)(param_1 + 0x48),0);
        if (*(longlong *)(param_1 + 0x50) != 0) {
          ExposureUnnoticed2_Scripts_InGame_DroneManager__OnUpdate__060014f2
                    (*(longlong *)(param_1 + 0x50),0);
          if (*(longlong *)(param_1 + 0x58) != 0) {
            ExposureUnnoticed2_Scripts_InGame_RandomMissionManager__OnUpdate__060015f1
                      (*(longlong *)(param_1 + 0x58),0);
            if (*(longlong *)(param_1 + 0x98) != 0) {
              ExposureUnnoticed2_Object3D_SpermBullet_SpermDecalManager__OnUpdate__060009fe
                        (*(longlong *)(param_1 + 0x98),0);
              lVar3 = *(longlong *)(param_1 + 0xa0);
              if (lVar3 != 0) {
                if (cRam0000000182eb7a42 == '\0') {
                  FUN_1802f2810(&DAT_182d58288);
                  LOCK();
                  UNLOCK();
                  FUN_1802f2810(&DAT_182d58398);
                  LOCK();
                  UNLOCK();
                  FUN_1802f2810(&DAT_182d58230);
                  LOCK();
                  UNLOCK();
                  cRam0000000182eb7a42 = '\x01';
                }
                fVar2 = *(float *)(lVar3 + 0x10);
                pcVar6 = DAT_182ec14d0;
                if ((DAT_182ec14d0 == (code *)0x0) &&
                   (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"),
                   pcVar6 == (code *)0x0)) {
                  uVar7 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar7,0);
                }
                DAT_182ec14d0 = pcVar6;
                fVar8 = (float)(*DAT_182ec14d0)();
                fVar8 = fVar8 + fVar2;
                *(float *)(lVar3 + 0x10) = fVar8;
                if (1.0 <= fVar8) {
                  lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                  if (lVar4 == 0) goto code_r0x0001804988ce;
                  piVar1 = (int *)(lVar4 + 0x124);
                  *piVar1 = *piVar1 + 1;
                  *(float *)(lVar3 + 0x10) = *(float *)(lVar3 + 0x10) - 1.0;
                }
                if (**(longlong **)(DAT_182d58230 + 0xb8) != 0) {
                  uVar5 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                                    (**(longlong **)(DAT_182d58230 + 0xb8),0);
                  if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
                    FUN_18035c820();
                  }
                  if ((uVar5 & 1) == 0) {
                    fVar2 = *(float *)(lVar3 + 0x14);
                    pcVar6 = DAT_182ec14d0;
                    if ((DAT_182ec14d0 == (code *)0x0) &&
                       (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"),
                       pcVar6 == (code *)0x0)) {
                      uVar7 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar7,0);
                    }
                    DAT_182ec14d0 = pcVar6;
                    fVar8 = (float)(*DAT_182ec14d0)();
                    fVar8 = fVar8 + fVar2;
                    *(float *)(lVar3 + 0x14) = fVar8;
                    if (1.0 <= fVar8) {
                      lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                      if (lVar4 == 0) goto code_r0x0001804988ce;
                      piVar1 = (int *)(lVar4 + 0x128);
                      *piVar1 = *piVar1 + 1;
                      *(float *)(lVar3 + 0x14) = *(float *)(lVar3 + 0x14) - 1.0;
                    }
                  }
                  return;
                }
              }
            }
          }
        }
      }
    }
  }
code_r0x0001804988ce:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

