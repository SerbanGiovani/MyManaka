// Ghidra pseudocode; not original source or compilable C.
// ev_a6b27fd067394b5c681217e54c6f2fa8b9802ff46eb301fa7d3b8d983b88b209

void ExposureUnnoticed2_Object3D_Player_Scripts_MentalManager__OnUpdate__06000c25(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  code *pcVar4;
  undefined8 uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  if (cRam0000000182eb8366 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6f748);
    LOCK();
    UNLOCK();
    cRam0000000182eb8366 = '\x01';
  }
  if (*(longlong *)(param_1 + 0x18) != 0) {
    if (*(int *)(*(longlong *)(param_1 + 0x18) + 0x5c) == 1) {
      return;
    }
    if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
        (lVar1 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar1 != 0)) &&
       (lVar1 = *(longlong *)(lVar1 + 0x60), lVar1 != 0)) {
      fVar6 = (float)*(int *)(lVar1 + 0xbc) / 100.0 + 1.0;
      fVar8 = 0.5;
      if (0.5 <= fVar6) {
        fVar8 = fVar6;
      }
      cVar2 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525
                        (0x10,0);
      if (cVar2 != '\0') {
        fVar8 = fVar8 * 0.0;
      }
      if (**(longlong **)(DAT_182d58230 + 0xb8) != 0) {
        iVar3 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                          (**(longlong **)(DAT_182d58230 + 0xb8),0);
        if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (iVar3 != 1) {
          if (cRam0000000182eb8369 == '\0') {
            FUN_1802f2810(&DAT_182d58398);
            LOCK();
            UNLOCK();
            cRam0000000182eb8369 = '\x01';
          }
          if (cRam0000000182eb548f == '\0') {
            FUN_1802f2810(&DAT_182d59250);
            LOCK();
            UNLOCK();
            cRam0000000182eb548f = '\x01';
          }
          if (**(char **)(DAT_182d59250 + 0xb8) == '\0') {
            lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar1 == 0) goto code_r0x000180624c5b;
            if (*(int *)(lVar1 + 0x10) != 0) {
              fVar6 = *(float *)(lVar1 + 0x16c);
              pcVar4 = DAT_182ec14d0;
              if ((DAT_182ec14d0 == (code *)0x0) &&
                 (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"),
                 pcVar4 == (code *)0x0)) {
                uVar5 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar5,0);
              }
              DAT_182ec14d0 = pcVar4;
              fVar7 = (float)(*DAT_182ec14d0)();
              *(float *)(lVar1 + 0x16c) = fVar6 - fVar7 * fVar8;
              lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
              if (lVar1 == 0) goto code_r0x000180624c5b;
              fVar8 = *(float *)(lVar1 + 0x16c);
              if (fVar8 < 0.0) {
                fVar8 = 0.0;
              }
              else if (*(float *)(param_1 + 0x10) < fVar8) {
                fVar8 = *(float *)(param_1 + 0x10);
              }
              *(float *)(lVar1 + 0x16c) = fVar8;
            }
          }
        }
        if (*(char *)(param_1 + 0x30) == '\0') {
          lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar1 == 0) goto code_r0x000180624c5b;
          if (*(float *)(lVar1 + 0x16c) / *(float *)(param_1 + 0x10) <= 0.05) {
            *(undefined1 *)(param_1 + 0x14) = 1;
            *(undefined1 *)(param_1 + 0x30) = 1;
            uVar5 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                              (uRam0000000182d6f748,0);
            ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
                      (uVar5,0,0);
            if (**(longlong **)(DAT_182d5aa70 + 0xb8) == 0) goto code_r0x000180624c5b;
            ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
                      (**(longlong **)(DAT_182d5aa70 + 0xb8),0x45,0xbf800000,0,0);
          }
        }
        return;
      }
    }
  }
code_r0x000180624c5b:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

