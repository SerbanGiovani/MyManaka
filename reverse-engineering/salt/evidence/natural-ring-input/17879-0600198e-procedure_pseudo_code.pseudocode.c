// Ghidra pseudocode; not original source or compilable C.
// ev_944bafd521b81e832b16e3d1d7b7fd852fa5926496a9021aa45ed8ee2749feb1

void ExposureUnnoticed2_ObjectUI_SaveDataSelectPanel_SkillPanelView__OnClickItem__0600198e
               (longlong param_1,longlong param_2)

{
  float fVar1;
  int iVar2;
  longlong *plVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 uVar9;
  code *pcVar10;
  
  if (cRam0000000182eb7c1d == '\0') {
    FUN_1802f2810(&DAT_182d52288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d634f0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d634e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d634d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61838);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d634c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52e20);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c1d = '\x01';
  }
  plVar3 = *(longlong **)(param_1 + 0x70);
  if ((param_2 == 0) ||
     (uVar5 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                        (*(undefined8 *)(param_2 + 0x18),0), plVar3 == (longlong *)0x0))
  goto code_r0x0001804e7ab9;
  (**(code **)(*plVar3 + 0x558))(plVar3,uVar5,*(undefined8 *)(*plVar3 + 0x560));
  lVar6 = DAT_182d52e20;
  if (*(char *)(param_2 + 0x38) != '\0') {
    lVar6 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d634d0,0);
  }
  if (*(int *)(param_2 + 0x48) < 1) {
    lVar7 = DAT_182d52e20;
    if (*(int *)(param_2 + 0x48) < 0) {
      lVar7 = FUN_181618010(param_2 + 0x48,0);
      uVar5 = uRam0000000182d634e0;
      goto code_r0x0001804e7797;
    }
  }
  else {
    lVar7 = FUN_181618010(param_2 + 0x48,0);
    uVar5 = uRam0000000182d61838;
code_r0x0001804e7797:
    uVar9 = uRam0000000182d634c0;
    if (lVar7 == 0) {
      lVar7 = DAT_182d52e20;
    }
    uVar5 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017b0(uVar5,lVar7,0);
    lVar7 = System_String__Concat__0600021b(uVar9,uVar5,0);
  }
  uVar5 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                    (*(undefined8 *)(param_2 + 0x20),0);
  if (*(int *)(param_2 + 0x3c) == 1) {
    iVar2 = *(int *)(param_2 + 0x30);
    iVar4 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetSkillLevel__06001529(1,0);
    if (*(int *)(DAT_182d52288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (iVar4 + 1 < iVar2) {
      iVar2 = iVar4 + 1;
    }
    lVar8 = ExposureUnnoticed2_Master_Skill_SkillSlow_MSkillStamina__Get__0600123d(iVar2,0);
    uVar5 = *(undefined8 *)(param_2 + 0x20);
    if (lVar8 == 0) goto code_r0x0001804e7ab9;
    fVar1 = *(float *)(lVar8 + 0x20);
    if (DAT_182ebb948 == '\0') {
      FUN_1802f2810(&DAT_182d24690);
      LOCK();
      UNLOCK();
      DAT_182ebb948 = '\x01';
    }
    uVar9 = FUN_181587040(0);
    if (*(int *)(DAT_182d24690 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar9 = FUN_18161e1f0((fVar1 - 1.0) * 100.0,0,uVar9,0);
    uVar5 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017b0(uVar5,uVar9,0);
  }
  if (*(int *)(param_2 + 0x3c) == 0xb) {
    iVar2 = *(int *)(param_2 + 0x30);
    iVar4 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetSkillLevel__06001529(0xb,0);
    if (*(int *)(DAT_182d52288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (iVar4 + 1 < iVar2) {
      iVar2 = iVar4 + 1;
    }
    lVar8 = ExposureUnnoticed2_Master_Skill_SkillMaxAccessoryNum_MSkillMaxAccessoryNum__Get__06001247
                      (iVar2,0);
    uVar5 = *(undefined8 *)(param_2 + 0x20);
    if (lVar8 == 0) goto code_r0x0001804e7ab9;
    uVar9 = FUN_181618010(lVar8 + 0x1c,0);
    uVar5 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017b0(uVar5,uVar9,0);
  }
  if (*(int *)(param_2 + 0x3c) == 6) {
    iVar2 = *(int *)(param_2 + 0x30);
    iVar4 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetSkillLevel__06001529(6,0);
    if (*(int *)(DAT_182d52288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (iVar4 + 1 < iVar2) {
      iVar2 = iVar4 + 1;
    }
    lVar8 = ExposureUnnoticed2_Master_Skill_SkillSlow_MSkillSlow__Get__06001238(iVar2,0);
    uVar5 = *(undefined8 *)(param_2 + 0x20);
    if (lVar8 == 0) goto code_r0x0001804e7ab9;
    uVar9 = FUN_18162f680(lVar8 + 0x1c,0);
    uVar5 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017b0(uVar5,uVar9,0);
  }
  plVar3 = *(longlong **)(param_1 + 0x78);
  uVar5 = System_String__Concat__0600021c(uVar5,lVar6,lVar7,0);
  if (plVar3 != (longlong *)0x0) {
    (**(code **)(*plVar3 + 0x558))(plVar3,uVar5,*(undefined8 *)(*plVar3 + 0x560));
    if (*(int *)(param_2 + 0x40) == 1) {
      if (*(int *)(lRam0000000182d634f0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar6 = FUN_180503620();
      if (lVar6 != 0) {
        ExposureUnnoticed2_Object3D_UIPlayer_UiPlayerController__ShowPose__060009cf
                  (lVar6,*(undefined4 *)(param_2 + 0x3c),0);
        lVar6 = *(longlong *)(param_1 + 0x80);
        if (lVar6 != 0) {
          pcVar10 = DAT_182ec1138;
          if ((DAT_182ec1138 == (code *)0x0) &&
             (pcVar10 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
             pcVar10 == (code *)0x0)) {
            uVar5 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar5,0);
          }
          DAT_182ec1138 = pcVar10;
          uVar5 = 1;
          goto code_r0x0001804e7a43;
        }
      }
    }
    else {
      if (*(int *)(lRam0000000182d634f0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar6 = FUN_180503620();
      if ((lVar6 != 0) && (lVar6 = *(longlong *)(lVar6 + 0x20), lVar6 != 0)) {
        pcVar10 = DAT_182ec1138;
        if ((DAT_182ec1138 == (code *)0x0) &&
           (pcVar10 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
           pcVar10 == (code *)0x0)) {
          uVar5 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        DAT_182ec1138 = pcVar10;
        (*DAT_182ec1138)(lVar6,0);
        lVar6 = *(longlong *)(param_1 + 0x80);
        if (lVar6 != 0) {
          pcVar10 = DAT_182ec1138;
          if ((DAT_182ec1138 == (code *)0x0) &&
             (pcVar10 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
             pcVar10 == (code *)0x0)) {
            uVar5 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar5,0);
          }
          DAT_182ec1138 = pcVar10;
          uVar5 = 0;
code_r0x0001804e7a43:
                    /* WARNING: Could not recover jumptable at 0x0001804e7a5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*DAT_182ec1138)(lVar6,uVar5);
          return;
        }
      }
    }
  }
code_r0x0001804e7ab9:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

