// Ghidra pseudocode; not original source or compilable C.
// ev_54370ed76ff81171deca86d8244b73b2b212845b626493f82f6b407ee962e901

void ExposureUnnoticed2_ObjectUI_SkillPanel_SkillItemView__UpdateMask__0600182e(longlong param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  bool bVar4;
  int iVar5;
  code *pcVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong *plVar9;
  bool bVar10;
  
  if (cRam0000000182eb7b37 == '\0') {
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d61ba0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61b98);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b37 = '\x01';
  }
  if ((((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
       (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 != 0)) &&
      (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 != 0)) &&
     ((lVar7 = *(longlong *)(lVar7 + 0x128), lVar7 != 0 &&
      (lVar3 = *(longlong *)(param_1 + 0x80), lVar3 != 0)))) {
    iVar1 = *(int *)(lVar3 + 0x34);
    iVar2 = *(int *)(lVar7 + 0x18);
    bVar4 = iVar2 < iVar1;
    if (*(int *)(lVar3 + 0x44) == -1) {
      bVar10 = false;
    }
    else {
      iVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetSkillLevel__06001529
                        (*(undefined4 *)(lVar3 + 0x44),0);
      bVar10 = iVar5 < 1;
    }
    lVar7 = *(longlong *)(param_1 + 0x48);
    *(char *)(param_1 + 0x98) = bVar10 | bVar4;
    if (lVar7 != 0) {
      pcVar6 = DAT_182ec1138;
      if ((DAT_182ec1138 == (code *)0x0) &&
         (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
         pcVar6 == (code *)0x0)) {
        uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar8,0);
      }
      DAT_182ec1138 = pcVar6;
      (*DAT_182ec1138)(lVar7,bVar10 | bVar4);
      lVar7 = *(longlong *)(param_1 + 0x50);
      if (lVar7 != 0) {
        pcVar6 = DAT_182ec1088;
        if ((DAT_182ec1088 == (code *)0x0) &&
           (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
           pcVar6 == (code *)0x0)) {
          uVar8 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar8,0);
        }
        DAT_182ec1088 = pcVar6;
        lVar7 = (*DAT_182ec1088)(lVar7);
        if (lVar7 != 0) {
          pcVar6 = DAT_182ec1138;
          if ((DAT_182ec1138 == (code *)0x0) &&
             (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
             pcVar6 == (code *)0x0)) {
            uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar8,0);
          }
          DAT_182ec1138 = pcVar6;
          (*DAT_182ec1138)(lVar7,bVar4);
          lVar7 = *(longlong *)(param_1 + 0x58);
          if (lVar7 != 0) {
            pcVar6 = DAT_182ec1088;
            if ((DAT_182ec1088 == (code *)0x0) &&
               (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
               pcVar6 == (code *)0x0)) {
              uVar8 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar8,0);
            }
            DAT_182ec1088 = pcVar6;
            lVar7 = (*DAT_182ec1088)(lVar7);
            if (lVar7 != 0) {
              pcVar6 = DAT_182ec1138;
              if ((DAT_182ec1138 == (code *)0x0) &&
                 (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"
                                                ), pcVar6 == (code *)0x0)) {
                uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar8,0);
              }
              DAT_182ec1138 = pcVar6;
              (*DAT_182ec1138)(lVar7,bVar10);
              if (iVar2 < iVar1) {
                plVar9 = *(longlong **)(param_1 + 0x50);
                if (*(longlong *)(param_1 + 0x80) == 0) goto code_r0x0001804c3f98;
                uVar8 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetRankNameAutoHide__06001568
                                  (*(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x34),0);
                uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017b0
                                  (DAT_182d61ba0,uVar8,0);
                if (plVar9 == (longlong *)0x0) goto code_r0x0001804c3f98;
                (**(code **)(*plVar9 + 0x558))(plVar9,uVar8,*(undefined8 *)(*plVar9 + 0x560));
              }
              if (bVar10 != false) {
                plVar9 = *(longlong **)(param_1 + 0x58);
                if ((*(longlong *)(param_1 + 0x80) == 0) ||
                   (lVar7 = ExposureUnnoticed2_Master_Skill_MSkill__Get__06001232
                                      (*(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x44),0),
                   lVar7 == 0)) goto code_r0x0001804c3f98;
                uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                  (*(undefined8 *)(lVar7 + 0x18),0);
                uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017b0
                                  (uRam0000000182d61b98,uVar8,0);
                if (plVar9 == (longlong *)0x0) goto code_r0x0001804c3f98;
                (**(code **)(*plVar9 + 0x558))(plVar9,uVar8,*(undefined8 *)(*plVar9 + 0x560));
              }
              plVar9 = *(longlong **)(param_1 + 0x50);
              if ((bVar4 & bVar10) == 0) {
                if (plVar9 != (longlong *)0x0) {
                  if ((*(int *)((longlong)plVar9 + 0x274) != 2) || ((int)plVar9[0x4f] != 0x200)) {
                    *(undefined4 *)((longlong)plVar9 + 0x274) = 2;
                    *(undefined4 *)(plVar9 + 0x4f) = 0x200;
                    *(undefined1 *)(plVar9 + 0x6f) = 1;
                    (**(code **)(*plVar9 + 0x2f8))(plVar9,*(undefined8 *)(*plVar9 + 0x300));
                  }
                  plVar9 = *(longlong **)(param_1 + 0x58);
                  if (plVar9 != (longlong *)0x0) {
                    if ((*(int *)((longlong)plVar9 + 0x274) == 2) && ((int)plVar9[0x4f] == 0x200)) {
                      return;
                    }
                    *(undefined4 *)(plVar9 + 0x4f) = 0x200;
code_r0x0001804c3f50:
                    *(undefined4 *)((longlong)plVar9 + 0x274) = 2;
                    *(undefined1 *)(plVar9 + 0x6f) = 1;
                    (**(code **)(*plVar9 + 0x2f8))(plVar9,*(undefined8 *)(*plVar9 + 0x300));
                    return;
                  }
                }
              }
              else if (plVar9 != (longlong *)0x0) {
                if ((*(int *)((longlong)plVar9 + 0x274) != 2) || ((int)plVar9[0x4f] != 0x100)) {
                  *(undefined4 *)((longlong)plVar9 + 0x274) = 2;
                  *(undefined4 *)(plVar9 + 0x4f) = 0x100;
                  *(undefined1 *)(plVar9 + 0x6f) = 1;
                  (**(code **)(*plVar9 + 0x2f8))(plVar9,*(undefined8 *)(*plVar9 + 0x300));
                }
                plVar9 = *(longlong **)(param_1 + 0x58);
                if (plVar9 != (longlong *)0x0) {
                  if ((*(int *)((longlong)plVar9 + 0x274) == 2) && ((int)plVar9[0x4f] == 0x400)) {
                    return;
                  }
                  *(undefined4 *)(plVar9 + 0x4f) = 0x400;
                  goto code_r0x0001804c3f50;
                }
              }
            }
          }
        }
      }
    }
  }
code_r0x0001804c3f98:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

