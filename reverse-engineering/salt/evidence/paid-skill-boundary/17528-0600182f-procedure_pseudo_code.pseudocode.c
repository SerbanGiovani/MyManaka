// Ghidra pseudocode; not original source or compilable C.
// ev_95d37eac1581ac804bf54b7bacf9c15ab2763a8a392d58e56f4f130ebe5cefd2

void ExposureUnnoticed2_ObjectUI_SkillPanel_SkillItemView__Refresh__0600182f(longlong param_1)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 uVar6;
  longlong lVar7;
  undefined8 uVar8;
  code *pcVar9;
  longlong *plVar10;
  int aiStackX_8 [2];
  undefined8 uStack_28;
  undefined8 uStack_20;
  
  if (cRam0000000182eb7b38 == '\0') {
    FUN_1802f2810(0x182d5dc40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61b90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61b88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61b80);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b38 = '\x01';
  }
  if (*(longlong *)(param_1 + 0x80) != 0) {
    iVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetSkillLevel__06001529
                      (*(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x3c),0);
    lVar7 = *(longlong *)(param_1 + 0x80);
    if ((lVar7 != 0) &&
       (*(int *)(param_1 + 0x78) = iVar5 * *(int *)(lVar7 + 0x2c) + *(int *)(lVar7 + 0x28),
       lVar7 != 0)) {
      if (*(int *)(lVar7 + 0x30) != 1) {
        aiStackX_8[0] = *(int *)(lVar7 + 0x3c);
        if (aiStackX_8[0] < 2) {
          if (aiStackX_8[0] == 0) {
            lVar7 = ExposureUnnoticed2_Master_Skill_SkillMental_MSkillMental__Get__06001242(iVar5,0)
            ;
          }
          else {
            if (aiStackX_8[0] != 1) goto code_r0x0001804c462c;
            lVar7 = ExposureUnnoticed2_Master_Skill_SkillSlow_MSkillStamina__Get__0600123d(iVar5,0);
          }
          if (lVar7 == 0) goto code_r0x0001804c460f;
          uVar6 = *(undefined4 *)(lVar7 + 0x1c);
        }
        else if (aiStackX_8[0] == 6) {
          lVar7 = ExposureUnnoticed2_Master_Skill_SkillSlow_MSkillSlow__Get__06001238(iVar5,0);
          if (lVar7 == 0) goto code_r0x0001804c460f;
          uVar6 = *(undefined4 *)(lVar7 + 0x20);
        }
        else {
          if (aiStackX_8[0] != 0xb) {
code_r0x0001804c462c:
            uVar8 = il2cpp_value_box(uRam0000000182d5dc40,aiStackX_8);
                    /* WARNING: Subroutine does not return */
            _PrivateImplementationDetails___ThrowSwitchExpressionException__06001e66(uVar8,0);
          }
          lVar7 = ExposureUnnoticed2_Master_Skill_SkillMaxAccessoryNum_MSkillMaxAccessoryNum__Get__06001247
                            (iVar5,0);
          if (lVar7 == 0) goto code_r0x0001804c460f;
          uVar6 = *(undefined4 *)(lVar7 + 0x20);
        }
        *(undefined4 *)(param_1 + 0x78) = uVar6;
      }
      plVar10 = *(longlong **)(param_1 + 0x30);
      uVar8 = FUN_181618010(param_1 + 0x78,0);
      if (plVar10 != (longlong *)0x0) {
        (**(code **)(*plVar10 + 0x558))(plVar10,uVar8,*(undefined8 *)(*plVar10 + 0x560));
        if (*(longlong *)(param_1 + 0x80) != 0) {
          plVar10 = *(longlong **)(param_1 + 0x20);
          if (*(int *)(*(longlong *)(param_1 + 0x80) + 0x30) == 1) {
            if (plVar10 == (longlong *)0x0) goto code_r0x0001804c460f;
            if ((*(int *)((longlong)plVar10 + 0x274) != 1) || ((int)plVar10[0x4f] != 0x200)) {
              *(undefined4 *)((longlong)plVar10 + 0x274) = 1;
              *(undefined4 *)(plVar10 + 0x4f) = 0x200;
              *(undefined1 *)(plVar10 + 0x6f) = 1;
              (**(code **)(*plVar10 + 0x2f8))(plVar10,*(undefined8 *)(*plVar10 + 0x300));
            }
            lVar7 = *(longlong *)(param_1 + 0x28);
            if (lVar7 == 0) goto code_r0x0001804c460f;
            pcVar9 = DAT_182ec1088;
            if ((DAT_182ec1088 == (code *)0x0) &&
               (pcVar9 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
               pcVar9 == (code *)0x0)) {
              uVar8 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar8,0);
            }
            DAT_182ec1088 = pcVar9;
            lVar7 = (*DAT_182ec1088)(lVar7);
            if (lVar7 == 0) goto code_r0x0001804c460f;
            pcVar9 = DAT_182ec1138;
            if ((DAT_182ec1138 == (code *)0x0) &&
               (pcVar9 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
               pcVar9 == (code *)0x0)) {
              uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar8,0);
            }
            DAT_182ec1138 = pcVar9;
            uVar8 = 0;
          }
          else {
            if (plVar10 == (longlong *)0x0) goto code_r0x0001804c460f;
            if ((*(int *)((longlong)plVar10 + 0x274) != 1) || ((int)plVar10[0x4f] != 0x100)) {
              *(undefined4 *)((longlong)plVar10 + 0x274) = 1;
              *(undefined4 *)(plVar10 + 0x4f) = 0x100;
              *(undefined1 *)(plVar10 + 0x6f) = 1;
              (**(code **)(*plVar10 + 0x2f8))(plVar10,*(undefined8 *)(*plVar10 + 0x300));
            }
            lVar7 = *(longlong *)(param_1 + 0x28);
            if (lVar7 == 0) goto code_r0x0001804c460f;
            pcVar9 = DAT_182ec1088;
            if ((DAT_182ec1088 == (code *)0x0) &&
               (pcVar9 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
               pcVar9 == (code *)0x0)) {
              uVar8 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar8,0);
            }
            DAT_182ec1088 = pcVar9;
            lVar7 = (*DAT_182ec1088)(lVar7);
            if (lVar7 == 0) goto code_r0x0001804c460f;
            pcVar9 = DAT_182ec1138;
            if ((DAT_182ec1138 == (code *)0x0) &&
               (pcVar9 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
               pcVar9 == (code *)0x0)) {
              uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar8,0);
            }
            DAT_182ec1138 = pcVar9;
            uVar8 = 1;
          }
          (*DAT_182ec1138)(lVar7,uVar8);
          plVar10 = *(longlong **)(param_1 + 0x38);
          uVar8 = uRam0000000182d61b90;
          if (iVar5 == 0) {
            uVar8 = uRam0000000182d61b80;
          }
          uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar8,0);
          if (plVar10 != (longlong *)0x0) {
            (**(code **)(*plVar10 + 0x558))(plVar10,uVar8,*(undefined8 *)(*plVar10 + 0x560));
            if (*(longlong *)(param_1 + 0x80) != 0) {
              if (iVar5 < *(int *)(*(longlong *)(param_1 + 0x80) + 0x30)) {
                plVar10 = *(longlong **)(param_1 + 0x28);
                if (DAT_182ebb869 == '\0') {
                  FUN_1802f2810(&DAT_182d24690);
                  LOCK();
                  UNLOCK();
                  FUN_1802f2810(&DAT_182d39ea8);
                  LOCK();
                  UNLOCK();
                  DAT_182ebb869 = '\x01';
                }
                if ((*(byte *)(*(longlong *)(DAT_182d39ea8 + 0x20) + 0x135) & 1) == 0) {
                  FUN_180320470();
                }
                if (*(int *)(DAT_182d24690 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                iVar3 = iVar5 + 1;
              }
              else {
                lVar7 = *(longlong *)(param_1 + 0x40);
                if (lVar7 == 0) goto code_r0x0001804c460f;
                pcVar9 = DAT_182ec1138;
                if ((DAT_182ec1138 == (code *)0x0) &&
                   (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar9 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec1138 = pcVar9;
                (*DAT_182ec1138)(lVar7,0);
                lVar7 = *(longlong *)(param_1 + 0x30);
                if (lVar7 == 0) goto code_r0x0001804c460f;
                pcVar9 = DAT_182ec1088;
                if ((DAT_182ec1088 == (code *)0x0) &&
                   (pcVar9 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
                   pcVar9 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec1088 = pcVar9;
                lVar7 = (*DAT_182ec1088)(lVar7);
                if (lVar7 == 0) goto code_r0x0001804c460f;
                pcVar9 = DAT_182ec1138;
                if ((DAT_182ec1138 == (code *)0x0) &&
                   (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar9 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec1138 = pcVar9;
                (*DAT_182ec1138)(lVar7,0);
                plVar10 = *(longlong **)(param_1 + 0x28);
                if (DAT_182ebb869 == '\0') {
                  FUN_1802f2810(&DAT_182d24690);
                  LOCK();
                  UNLOCK();
                  FUN_1802f2810(&DAT_182d39ea8);
                  LOCK();
                  UNLOCK();
                  DAT_182ebb869 = '\x01';
                }
                if ((*(byte *)(*(longlong *)(DAT_182d39ea8 + 0x20) + 0x135) & 1) == 0) {
                  FUN_180320470();
                }
                iVar3 = iVar5;
                if (*(int *)(DAT_182d24690 + 0xe0) == 0) {
                  FUN_18035c820();
                }
              }
              uStack_28 = 0;
              uStack_20 = 0;
              uVar8 = FUN_18161e8f0(iVar3,&uStack_28,0,0);
              uVar8 = System_String__Concat__0600021b(uRam0000000182d61b88,uVar8,0);
              if (plVar10 != (longlong *)0x0) {
                (**(code **)(*plVar10 + 0x558))(plVar10,uVar8,*(undefined8 *)(*plVar10 + 0x560));
                if (*(longlong *)(param_1 + 0x80) != 0) {
                  lVar7 = *(longlong *)(param_1 + 0x60);
                  bVar2 = *(int *)(*(longlong *)(param_1 + 0x80) + 0x30) <= iVar5;
                  *(bool *)(param_1 + 0x99) = bVar2;
                  if (lVar7 != 0) {
                    pcVar9 = DAT_182ec1138;
                    if ((DAT_182ec1138 == (code *)0x0) &&
                       (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar9 == (code *)0x0)) {
                      uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar8,0);
                    }
                    DAT_182ec1138 = pcVar9;
                    (*DAT_182ec1138)(lVar7,bVar2);
                    lVar7 = *(longlong *)(param_1 + 0x80);
                    lVar1 = *(longlong *)(param_1 + 0x68);
                    if (lVar7 != 0) {
                      if (*(char *)(lVar7 + 0x38) == '\0') {
                        uVar4 = 0;
                      }
                      else {
                        uVar4 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525
                                          (*(undefined4 *)(lVar7 + 0x3c),0);
                      }
                      if (lVar1 != 0) {
                        pcVar9 = DAT_182ec1138;
                        if ((DAT_182ec1138 == (code *)0x0) &&
                           (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar9 == (code *)0x0)) {
                          uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)")
                          ;
                    /* WARNING: Subroutine does not return */
                          FUN_1802cca90(uVar8,0);
                        }
                        DAT_182ec1138 = pcVar9;
                    /* WARNING: Could not recover jumptable at 0x0001804c460c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                        (*DAT_182ec1138)(lVar1,uVar4);
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
code_r0x0001804c460f:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

