// Ghidra pseudocode; not original source or compilable C.
// ev_5380698d2d505bef27b600992f3bcf0fb54f10db9762fb3f0875a8af853a72c7

void ExposureUnnoticed2_ObjectUI_SkillPanel_SkillItemView__Initialize__0600182b
               (longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  code *pcVar7;
  longlong lVar8;
  longlong *plVar9;
  bool bVar10;
  uint uVar11;
  bool bVar12;
  
  iVar3 = DAT_182eb5d50;
  *(longlong *)(param_1 + 0x80) = param_2;
  if (iVar3 != 0) {
    uVar11 = (uint)(param_1 + 0x80U >> 0xc);
    lVar8 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar8);
      LOCK();
      bVar12 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + lVar8) = uVar1 | 1L << (uVar11 & 0x3f);
      }
      UNLOCK();
      iVar3 = DAT_182eb5d50;
    } while (!bVar12);
  }
  *(undefined8 *)(param_1 + 0x90) = param_3;
  iVar4 = 0;
  if (iVar3 != 0) {
    uVar11 = (uint)(param_1 + 0x90U >> 0xc);
    lVar8 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar8);
      LOCK();
      bVar12 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + lVar8) = uVar1 | 1L << (ulonglong)(uVar11 & 0x3f);
      }
      UNLOCK();
      iVar4 = DAT_182eb5d50;
    } while (!bVar12);
  }
  *(undefined8 *)(param_1 + 0x88) = param_4;
  if (iVar4 != 0) {
    uVar11 = (uint)(param_1 + 0x88U >> 0xc);
    lVar8 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar8);
      LOCK();
      bVar12 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar8);
      if (bVar12) {
        *(ulonglong *)(&DAT_182f0c920 + lVar8) = uVar1 | 1L << (ulonglong)(uVar11 & 0x3f);
      }
      UNLOCK();
    } while (!bVar12);
  }
  plVar9 = *(longlong **)(param_1 + 0x20);
  if ((param_2 == 0) ||
     (uVar6 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                        (*(undefined8 *)(param_2 + 0x18),0), plVar9 == (longlong *)0x0)) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  (**(code **)(*plVar9 + 0x558))(plVar9,uVar6,*(undefined8 *)(*plVar9 + 0x560));
  ExposureUnnoticed2_ObjectUI_SkillPanel_SkillItemView__Refresh__0600182f(param_1,0);
  if (cRam0000000182eb7b37 == '\0') {
    FUN_1802f2810(&DAT_182d58378,0);
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
       (lVar8 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar8 != 0)) &&
      (lVar8 = *(longlong *)(lVar8 + 0x60), lVar8 != 0)) &&
     ((lVar8 = *(longlong *)(lVar8 + 0x128), lVar8 != 0 &&
      (lVar2 = *(longlong *)(param_1 + 0x80), lVar2 != 0)))) {
    iVar3 = *(int *)(lVar2 + 0x34);
    iVar4 = *(int *)(lVar8 + 0x18);
    bVar12 = iVar4 < iVar3;
    if (*(int *)(lVar2 + 0x44) == -1) {
      bVar10 = false;
    }
    else {
      iVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetSkillLevel__06001529
                        (*(undefined4 *)(lVar2 + 0x44),0);
      bVar10 = iVar5 < 1;
    }
    lVar8 = *(longlong *)(param_1 + 0x48);
    *(char *)(param_1 + 0x98) = bVar10 | bVar12;
    if (lVar8 != 0) {
      pcVar7 = DAT_182ec1138;
      if ((DAT_182ec1138 == (code *)0x0) &&
         (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
         pcVar7 == (code *)0x0)) {
        uVar6 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar6,0);
      }
      DAT_182ec1138 = pcVar7;
      (*DAT_182ec1138)(lVar8,bVar10 | bVar12);
      lVar8 = *(longlong *)(param_1 + 0x50);
      if (lVar8 != 0) {
        pcVar7 = DAT_182ec1088;
        if ((DAT_182ec1088 == (code *)0x0) &&
           (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
           pcVar7 == (code *)0x0)) {
          uVar6 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar6,0);
        }
        DAT_182ec1088 = pcVar7;
        lVar8 = (*DAT_182ec1088)(lVar8);
        if (lVar8 != 0) {
          pcVar7 = DAT_182ec1138;
          if ((DAT_182ec1138 == (code *)0x0) &&
             (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
             pcVar7 == (code *)0x0)) {
            uVar6 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar6,0);
          }
          DAT_182ec1138 = pcVar7;
          (*DAT_182ec1138)(lVar8,bVar12);
          lVar8 = *(longlong *)(param_1 + 0x58);
          if (lVar8 != 0) {
            pcVar7 = DAT_182ec1088;
            if ((DAT_182ec1088 == (code *)0x0) &&
               (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
               pcVar7 == (code *)0x0)) {
              uVar6 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar6,0);
            }
            DAT_182ec1088 = pcVar7;
            lVar8 = (*DAT_182ec1088)(lVar8);
            if (lVar8 != 0) {
              pcVar7 = DAT_182ec1138;
              if ((DAT_182ec1138 == (code *)0x0) &&
                 (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"
                                                ), pcVar7 == (code *)0x0)) {
                uVar6 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar6,0);
              }
              DAT_182ec1138 = pcVar7;
              (*DAT_182ec1138)(lVar8,bVar10);
              if (iVar4 < iVar3) {
                plVar9 = *(longlong **)(param_1 + 0x50);
                if (*(longlong *)(param_1 + 0x80) == 0) goto code_r0x0001804c3f98;
                uVar6 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetRankNameAutoHide__06001568
                                  (*(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x34),0);
                uVar6 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017b0
                                  (DAT_182d61ba0,uVar6,0);
                if (plVar9 == (longlong *)0x0) goto code_r0x0001804c3f98;
                (**(code **)(*plVar9 + 0x558))(plVar9,uVar6,*(undefined8 *)(*plVar9 + 0x560));
              }
              if (bVar10 != false) {
                plVar9 = *(longlong **)(param_1 + 0x58);
                if ((*(longlong *)(param_1 + 0x80) == 0) ||
                   (lVar8 = ExposureUnnoticed2_Master_Skill_MSkill__Get__06001232
                                      (*(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x44),0),
                   lVar8 == 0)) goto code_r0x0001804c3f98;
                uVar6 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                  (*(undefined8 *)(lVar8 + 0x18),0);
                uVar6 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017b0
                                  (uRam0000000182d61b98,uVar6,0);
                if (plVar9 == (longlong *)0x0) goto code_r0x0001804c3f98;
                (**(code **)(*plVar9 + 0x558))(plVar9,uVar6,*(undefined8 *)(*plVar9 + 0x560));
              }
              plVar9 = *(longlong **)(param_1 + 0x50);
              if ((bVar12 & bVar10) == 0) {
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

