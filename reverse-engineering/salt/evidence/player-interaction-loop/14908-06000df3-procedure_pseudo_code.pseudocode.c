// Ghidra pseudocode; not original source or compilable C.
// ev_f4ca0655abfdef012f3da572563ea210c8b00ca18a98803ef27c9c9d067ffd9e

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerMiscProcess__OnUpdate__06000df3
               (longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  char cVar3;
  code *pcVar4;
  longlong lVar5;
  undefined8 uVar6;
  float fVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  float fVar10;
  int aiStackX_8 [2];
  
  if (cRam0000000182eb8426 == '\0') {
    FUN_1802f2810(0x182d5c7e8);
    LOCK();
    UNLOCK();
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
    FUN_1802f2810(&DAT_182d55000);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ab80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d594f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5c7b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ef60);
    LOCK();
    UNLOCK();
    cRam0000000182eb8426 = '\x01';
  }
  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerMiscProcess__CalcDokidoki__06000df4(param_1,0);
  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerMiscProcess__CalcHiddenBodyPartsByCostume__06000df5
            (param_1,0);
  if ((*(longlong *)(param_1 + 0x18) == 0) ||
     (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x60), lVar5 == 0))
  goto code_r0x000180655f55;
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x60);
  if (*(char *)(lVar5 + 0x50) == '\0') {
    fVar10 = *(float *)(lVar2 + 0x54);
    pcVar4 = DAT_182ec14d0;
    if ((DAT_182ec14d0 == (code *)0x0) &&
       (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"), pcVar4 == (code *)0x0))
    {
      uVar6 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar6,0);
    }
    DAT_182ec14d0 = pcVar4;
    fVar7 = (float)(*DAT_182ec14d0)();
    *(float *)(lVar2 + 0x54) = fVar10 - fVar7;
  }
  else {
    if (lVar2 == 0) goto code_r0x000180655f55;
    *(undefined4 *)(lVar2 + 0x54) = 0x3e99999a;
  }
  if (param_2 == 0) goto code_r0x000180655f55;
  if (*(char *)(param_2 + 0x30) != '\0') {
    if (*(int *)(lRam0000000182d5ab80 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar5 = ExposureUnnoticed2_Scripts_Base_InteractManager__GetHead__06001796(0);
    if ((lVar5 != 0) && (*(int *)(lVar5 + 0x10) != 0)) {
      lVar2 = *(longlong *)(param_1 + 0x10);
      if (lVar2 == 0) goto code_r0x000180655f55;
      if (*(char *)(lVar2 + 0x50) == '\0') {
        if (*(longlong *)(lVar2 + 0x48) == 0) goto code_r0x000180655f55;
        if (*(int *)(*(longlong *)(lVar2 + 0x48) + 0x18) != -1) {
          if (*(longlong *)(lVar5 + 0x18) == 0) goto code_r0x000180655f55;
          if (*(char *)(*(longlong *)(lVar5 + 0x18) + 0x30) == '\0') goto code_r0x000180655947;
        }
        if (*(int *)(DAT_182d58080 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d58080);
        }
        lVar5 = *(longlong *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x38);
        if (*(int *)(lRam0000000182d5ab80 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uVar6 = ExposureUnnoticed2_Scripts_Base_InteractManager__GetHead__06001796(0);
        if (lVar5 == 0) goto code_r0x000180655f55;
        *(undefined8 *)(lVar5 + 0x10) = uVar6;
        FUN_18031d480(lVar5 + 0x10);
        uVar6 = *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x38);
        if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
          FUN_18035c820();
        }
        ExposureUnnoticed2_Scripts_Base_EventManager__Broadcast__06001716(uVar6,0);
      }
    }
  }
code_r0x000180655947:
  if (*(longlong *)(param_1 + 0x18) == 0) goto code_r0x000180655f55;
  lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x60);
  lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar2 == 0) goto code_r0x000180655f55;
  aiStackX_8[0] = *(int *)(lVar2 + 0x1b8);
  uVar9 = 0x3f800000;
  if (aiStackX_8[0] == 0) goto code_r0x000180655a94;
  if (aiStackX_8[0] == 1) {
code_r0x000180655a8f:
    uVar8 = 0x3f800000;
  }
  else if (aiStackX_8[0] == 2) {
code_r0x000180655a85:
    uVar8 = 0x40000000;
  }
  else {
    if (aiStackX_8[0] != 3) {
      uVar6 = il2cpp_value_box(uRam0000000182d5c7b8,aiStackX_8);
                    /* WARNING: Subroutine does not return */
      _PrivateImplementationDetails___ThrowSwitchExpressionException__06001e66(uVar6,0);
    }
    if (*(int *)(lRam0000000182d5c7e8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar2 = **(longlong **)(lRam0000000182d5c7e8 + 0xb8);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182ec12f3 == '\0') {
      FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      DAT_182ec12f3 = '\x01';
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
    if (lVar2 != 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(longlong *)(lVar2 + 0x10) != 0) {
        if (*(int *)(lRam0000000182d5c7e8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (*(int *)(*(longlong *)(lRam0000000182d5c7e8 + 0xb8) + 8) != 2)
        goto code_r0x000180655a8f;
        goto code_r0x000180655a85;
      }
    }
code_r0x000180655a94:
    uVar8 = 0;
  }
  if (lVar5 != 0) {
    *(undefined4 *)(lVar5 + 0x10c) = uVar8;
    lVar5 = *(longlong *)(param_1 + 0x18);
    if (lVar5 != 0) {
      if (*(longlong *)(lVar5 + 0x1f0) != 0) {
        aiStackX_8[0] = *(int *)(*(longlong *)(lVar5 + 0x1f0) + 0x5c);
        if (aiStackX_8[0] == 0) {
          uVar9 = 0;
        }
        else if (aiStackX_8[0] == 1) {
          uVar9 = 0x3f19999a;
        }
        else if (aiStackX_8[0] == 2) {
          uVar9 = 0x3f4ccccd;
        }
        else if (aiStackX_8[0] != 3) {
          uVar6 = il2cpp_value_box(DAT_182d55000,aiStackX_8);
                    /* WARNING: Subroutine does not return */
          _PrivateImplementationDetails___ThrowSwitchExpressionException__06001e66(uVar6,0);
        }
        if (*(longlong *)(lVar5 + 0x60) != 0) {
          *(undefined4 *)(*(longlong *)(lVar5 + 0x60) + 0x110) = uVar9;
          if ((*(longlong *)(param_1 + 0x18) != 0) &&
             (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x60), lVar5 != 0)) {
            if (*(char *)(param_1 + 0x20) != *(char *)(lVar5 + 0x1a)) {
              *(undefined1 *)(param_1 + 0x20) =
                   *(undefined1 *)(*(longlong *)(*(longlong *)(param_1 + 0x18) + 0x60) + 0x1a);
              if ((*(longlong *)(param_1 + 0x18) == 0) ||
                 (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x60), lVar5 == 0))
              goto code_r0x000180655f55;
              lVar2 = *(longlong *)(param_1 + 0x18);
              if (*(char *)(lVar5 + 0x1a) == '\0') {
                if (*(longlong *)(lVar2 + 0x120) == 0) goto code_r0x000180655f55;
                ExposureUnnoticed2_Object3D_Player_Scripts_LookAtController__DisableLookAt__06000c10
                          (*(longlong *)(lVar2 + 0x120),5,0);
              }
              else {
                if (((lVar2 == 0) || (*(longlong *)(lVar2 + 0x70) == 0)) ||
                   (*(longlong *)(lVar2 + 0x120) == 0)) goto code_r0x000180655f55;
                ExposureUnnoticed2_Object3D_Player_Scripts_LookAtController__EnableLookAt__06000c0f
                          (*(longlong *)(lVar2 + 0x120),5,
                           *(undefined8 *)(*(longlong *)(lVar2 + 0x70) + 0x158),1,0);
              }
            }
            lVar5 = *(longlong *)(param_1 + 0x18);
            if ((lVar5 != 0) && (lVar2 = *(longlong *)(lVar5 + 0x60), lVar2 != 0)) {
              if (*(char *)(lVar2 + 0x120) == '\0') {
                *(undefined4 *)(lVar2 + 0x1b4) = 0xbf800000;
              }
              else {
                if ((lVar2 == 0) || (lVar5 == 0)) goto code_r0x000180655f55;
                if (*(float *)(lVar2 + 0x1b4) <= 0.0 && *(float *)(lVar2 + 0x1b4) != 0.0) {
                  if (lVar2 == 0) goto code_r0x000180655f55;
                  *(undefined4 *)(lVar2 + 0x1b4) = 0x3ecccccd;
                }
                else {
                  if (lVar2 == 0) goto code_r0x000180655f55;
                  fVar10 = *(float *)(lVar2 + 0x1b4);
                  fVar7 = (float)FUN_181f47ce0(0);
                  fVar10 = fVar10 - fVar7;
                  fVar7 = 0.0;
                  if (0.0 <= fVar10) {
                    fVar7 = fVar10;
                  }
                  *(float *)(lVar2 + 0x1b4) = fVar7;
                }
              }
              if (*(longlong *)(param_1 + 0x10) != 0) {
                if (0.0 < *(float *)(*(longlong *)(param_1 + 0x10) + 0x200)) {
                  if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
                     (lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30),
                     lVar5 == 0)) goto code_r0x000180655f55;
                  lVar2 = *(longlong *)(param_1 + 0x10);
                  if (*(char *)(lVar5 + 0x14) == '\0') {
                    fVar10 = *(float *)(lVar2 + 0x200);
                    fVar7 = (float)FUN_181f47ce0(0);
                    *(float *)(lVar2 + 0x200) = fVar10 - fVar7;
                  }
                  else {
                    *(undefined4 *)(lVar2 + 0x200) = 0;
                  }
                  lVar5 = *(longlong *)(param_1 + 0x10);
                  if (lVar5 == 0) goto code_r0x000180655f55;
                  if (*(float *)(lVar5 + 0x200) <= 0.0) {
                    lVar5 = *(longlong *)(lVar5 + 0x1f8);
                    if (lVar5 == 0) goto code_r0x000180655f55;
                    iVar1 = *(int *)(lVar5 + 0x18);
                    *(int *)(lVar5 + 0x1c) = *(int *)(lVar5 + 0x1c) + 1;
                    *(undefined4 *)(lVar5 + 0x18) = 0;
                    if (0 < iVar1) {
                      FUN_181646f50(*(undefined8 *)(lVar5 + 0x10),0,iVar1,0);
                    }
                  }
                }
                if ((((*(longlong *)(param_1 + 0x18) != 0) &&
                     (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x70), lVar5 != 0)) &&
                    (lVar5 = *(longlong *)(lVar5 + 0x250), lVar5 != 0)) &&
                   (lVar5 = *(longlong *)(lVar5 + 0x38), lVar5 != 0)) {
                  if (*(float *)(lVar5 + 0x10) < 100.0) {
                    lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x60);
                    if ((lVar5 == 0) || (*(longlong *)(lVar5 + 0x10) == 0))
                    goto code_r0x000180655f55;
                    lVar5 = *(longlong *)(param_1 + 0x28);
                  }
                  else {
                    lVar5 = *(longlong *)(param_1 + 0x28);
                    if (*(longlong *)(*(longlong *)(param_1 + 0x18) + 0x60) == 0)
                    goto code_r0x000180655f55;
                  }
                  if (lVar5 != 0) {
                    ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c();
                    if (((*(longlong *)(param_1 + 0x18) != 0) &&
                        (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x70), lVar5 != 0))
                       && ((*(longlong *)(param_1 + 0x28) != 0 &&
                           (lVar5 = *(longlong *)(lVar5 + 0x150), lVar5 != 0)))) {
                      *(undefined4 *)(lVar5 + 0xc0) =
                           *(undefined4 *)(*(longlong *)(param_1 + 0x28) + 0x10);
                      lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                      if (lVar5 != 0) {
                        if (*(int *)(lVar5 + 0x10) == 0) {
                          return;
                        }
                        cVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525
                                          (0x11,0);
                        if (((cVar3 == '\0') &&
                            (cVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525
                                               (0x16,0), cVar3 == '\0')) &&
                           (cVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525
                                              (0x15,0), cVar3 == '\0')) {
                          lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                          if (lVar5 == 0) goto code_r0x000180655f55;
                          if ((*(char *)(lVar5 + 0x1de) == '\0') &&
                             (*(char *)(lVar5 + 0x1df) == '\0')) {
                            return;
                          }
                        }
                        if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                           (lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30),
                           lVar5 != 0)) {
                          if (*(char *)(lVar5 + 0x4c) == '\0') {
                            uVar6 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                              (uRam0000000182d3ef60,0);
                            ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
                                      (uVar6,0,0);
                          }
                          if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                             (lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30),
                             lVar5 != 0)) {
                            *(undefined1 *)(lVar5 + 0x4c) = 1;
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
  }
code_r0x000180655f55:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

