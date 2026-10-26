// Ghidra pseudocode; not original source or compilable C.
// ev_96e8ffb981d9d0d18d9b1e5732c8678c74318359ed8066c974cae28ce8559739

void ExposureUnnoticed2_Object3D_ScenePlops_CommonDoor_CommonDoorController__OnInteract__06000b28
               (longlong param_1)

{
  longlong lVar1;
  char cVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  float fVar7;
  float fVar8;
  undefined8 uStack_48;
  float fStack_40;
  undefined8 uStack_38;
  float fStack_30;
  
  if (cRam0000000182eb82c5 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58078);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6bda0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6bd98);
    LOCK();
    UNLOCK();
    cRam0000000182eb82c5 = '\x01';
  }
  if (*(char *)(param_1 + 0x5a) != '\0') {
    return;
  }
  lVar3 = **(longlong **)(DAT_182d58230 + 0xb8);
  if (lVar3 == 0) {
code_r0x00018060860f:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (DAT_182eb83fe == '\0') {
    FUN_1802f2810(&DAT_182d3e668);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d3e660);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5e118);
    LOCK();
    UNLOCK();
    DAT_182eb83fe = '\x01';
  }
  cVar2 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsAttachSomeHandcuffs__0600155d(0);
  if (cVar2 != '\0') {
    return;
  }
  if ((*(longlong *)(lVar3 + 0x10) == 0) ||
     (lVar1 = *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x60), lVar1 == 0))
  goto code_r0x00018060860f;
  if (*(char *)(lVar1 + 0x1b) != '\0') {
    return;
  }
  if (*(longlong *)(lVar1 + 0x48) == 0) goto code_r0x00018060860f;
  if (*(int *)(*(longlong *)(lVar1 + 0x48) + 0x18) != -1) {
    return;
  }
  lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x60);
  if (*(int *)(lVar3 + 0x5c) != 0) {
    return;
  }
  if (*(char *)(lVar3 + 0x50) != '\0') {
    return;
  }
  lVar3 = FUN_180436330();
  if (lVar3 == 0) goto code_r0x00018060860f;
  if (*(char *)(lVar3 + 0x10) != '\0') {
    return;
  }
  if (cRam0000000182eb82c6 == '\0') {
    FUN_1802f2810(&DAT_182d5e118);
    LOCK();
    UNLOCK();
    cRam0000000182eb82c6 = '\x01';
  }
  uVar6 = DAT_182d5e118;
  if (*(char *)(param_1 + 0x5b) == '\0') {
code_r0x00018060858e:
    uVar6 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar6,0);
    ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
              (uVar6,1,0);
  }
  else {
    if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
        (lVar3 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar3 == 0)) ||
       (lVar3 = *(longlong *)(lVar3 + 0x18), lVar3 == 0)) goto code_r0x00018060860f;
    uStack_48 = 0;
    fStack_40 = 0.0;
    pcVar4 = DAT_182ec1698;
    if ((DAT_182ec1698 == (code *)0x0) &&
       (pcVar4 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar4 == (code *)0x0)) {
      uVar6 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar6,0);
    }
    DAT_182ec1698 = pcVar4;
    (*DAT_182ec1698)(lVar3,&uStack_48);
    lVar3 = FUN_181d769d0(param_1,0);
    if (lVar3 == 0) goto code_r0x00018060860f;
    uStack_38 = 0;
    fStack_30 = 0.0;
    pcVar4 = DAT_182ec1698;
    if ((DAT_182ec1698 == (code *)0x0) &&
       (pcVar4 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar4 == (code *)0x0)) {
      uVar6 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar6,0);
    }
    DAT_182ec1698 = pcVar4;
    (*DAT_182ec1698)(lVar3,&uStack_38);
    fVar7 = (float)uStack_48 - (float)uStack_38;
    fVar8 = fStack_40 - fStack_30;
    if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar3 = FUN_181d769d0(param_1,0);
    if (lVar3 == 0) goto code_r0x00018060860f;
    puVar5 = (undefined8 *)FUN_181f4c360(&uStack_38,lVar3,0);
    fVar7 = (float)*puVar5 * fVar7 + *(float *)((longlong)puVar5 + 4) * 0.0 +
            *(float *)(puVar5 + 1) * fVar8;
    if (*(char *)(param_1 + 0x59) == '\0') {
      if (*(char *)(param_1 + 0x58) != '\0') {
        uVar6 = uRam0000000182d6bd98;
        if (fVar7 < 0.0) {
          *(undefined1 *)(param_1 + 0x58) = 0;
          uVar6 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d6bda0,0)
          ;
          ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
                    (uVar6,1,0);
          if (**(longlong **)(DAT_182d58078 + 0xb8) != 0) {
            ExposureUnnoticed2_Scripts_Sound_InGameSoundManager__PlayOneShotAudioData__060013ed
                      (**(longlong **)(DAT_182d58078 + 0xb8),*(undefined8 *)(param_1 + 0x40),0x53,
                       0xbf800000,0);
            return;
          }
          goto code_r0x00018060860f;
        }
        goto code_r0x00018060858e;
      }
      if (fVar7 < 0.0) {
        ExposureUnnoticed2_ObjectUI_InteractMenuPanel_InteractMenuPanelView__Open__06001a39(0);
        return;
      }
    }
    ExposureUnnoticed2_Object3D_ScenePlops_CommonDoor_CommonDoorController__OpenClose__06000b2c
              (param_1,0);
  }
  return;
}

