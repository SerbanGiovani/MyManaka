// Ghidra pseudocode; not original source or compilable C.
// ev_ea503825f2a33ef36989836d7bd89b59bf9aabd18c5ea3cf3358eb826b98887d

void ExposureUnnoticed2_Scripts_InGame_GameOverController__OpenFailedPanel__060014e6(void)

{
  undefined1 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong *plVar4;
  bool bVar5;
  longlong lVar6;
  code *UNRECOVERED_JUMPTABLE;
  longlong lVar7;
  undefined8 uVar8;
  
  if (cRam0000000182eb7bfa == '\0') {
    FUN_1802f2810(&DAT_182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63708);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58380);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d54d90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7bfa = '\x01';
  }
  if (**(longlong **)(DAT_182d58238 + 0xb8) != 0) {
    uVar8 = *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x118);
    if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d58380);
    }
    if (**(longlong **)(DAT_182d58380 + 0xb8) != 0) {
      uVar2 = *(undefined8 *)(**(longlong **)(DAT_182d58380 + 0xb8) + 0xb8);
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar6 = FUN_1809f1050(uVar8,uVar2,DAT_182d54d90);
      if ((lVar6 != 0) && (lVar6 = FUN_1809a08f0(lVar6,uRam0000000182d63708), lVar6 != 0)) {
        if (cRam0000000182eb7bf6 == '\0') {
          FUN_1802f2810(&DAT_182d58398,0);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d53c48);
          LOCK();
          UNLOCK();
          FUN_1802f2810(0x182d63748);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d52e20);
          LOCK();
          UNLOCK();
          FUN_1802f2810(0x182d63740);
          LOCK();
          UNLOCK();
          FUN_1802f2810(0x182d63738);
          LOCK();
          UNLOCK();
          cRam0000000182eb7bf6 = '\x01';
        }
        lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        if (lVar7 != 0) {
          lVar3 = *(longlong *)(lVar6 + 0x30);
          bVar5 = *(float *)(lVar7 + 0x16c) <= 0.0;
          if (lVar3 != 0) {
            UNRECOVERED_JUMPTABLE = DAT_182ec1088;
            if ((DAT_182ec1088 == (code *)0x0) &&
               (UNRECOVERED_JUMPTABLE =
                     (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
               UNRECOVERED_JUMPTABLE == (code *)0x0)) {
              uVar8 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar8,0);
            }
            DAT_182ec1088 = UNRECOVERED_JUMPTABLE;
            lVar7 = (*DAT_182ec1088)(lVar3);
            if (lVar7 != 0) {
              UNRECOVERED_JUMPTABLE = DAT_182ec1138;
              if ((DAT_182ec1138 == (code *)0x0) &&
                 (UNRECOVERED_JUMPTABLE =
                       (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
                 UNRECOVERED_JUMPTABLE == (code *)0x0)) {
                uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar8,0);
              }
              DAT_182ec1138 = UNRECOVERED_JUMPTABLE;
              (*DAT_182ec1138)(lVar7,!bVar5);
              lVar7 = *(longlong *)(lVar6 + 0x38);
              if (lVar7 != 0) {
                UNRECOVERED_JUMPTABLE = DAT_182ec1088;
                if ((DAT_182ec1088 == (code *)0x0) &&
                   (UNRECOVERED_JUMPTABLE =
                         (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
                   UNRECOVERED_JUMPTABLE == (code *)0x0)) {
                  uVar8 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec1088 = UNRECOVERED_JUMPTABLE;
                lVar7 = (*DAT_182ec1088)(lVar7);
                if (lVar7 != 0) {
                  UNRECOVERED_JUMPTABLE = DAT_182ec1138;
                  if ((DAT_182ec1138 == (code *)0x0) &&
                     (UNRECOVERED_JUMPTABLE =
                           (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"
                                                ), UNRECOVERED_JUMPTABLE == (code *)0x0)) {
                    uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar8,0);
                  }
                  DAT_182ec1138 = UNRECOVERED_JUMPTABLE;
                  (*DAT_182ec1138)(lVar7,bVar5);
                  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                     (lVar7 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30),
                     lVar7 != 0)) {
                    lVar3 = *(longlong *)(lVar6 + 0x20);
                    if (*(int *)(lVar7 + 0x20) == 0) {
                      if (lVar3 == 0) goto code_r0x0001804e1d8d;
                      UNRECOVERED_JUMPTABLE = DAT_182ec1088;
                      if ((DAT_182ec1088 == (code *)0x0) &&
                         (UNRECOVERED_JUMPTABLE =
                               (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
                         UNRECOVERED_JUMPTABLE == (code *)0x0)) {
                        uVar8 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar8,0);
                      }
                      DAT_182ec1088 = UNRECOVERED_JUMPTABLE;
                      lVar7 = (*DAT_182ec1088)(lVar3);
                      if (lVar7 == 0) goto code_r0x0001804e1d8d;
                      UNRECOVERED_JUMPTABLE = DAT_182ec1138;
                      if ((DAT_182ec1138 == (code *)0x0) &&
                         (UNRECOVERED_JUMPTABLE =
                               (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), UNRECOVERED_JUMPTABLE == (code *)0x0)) {
                        uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar8,0);
                      }
                      DAT_182ec1138 = UNRECOVERED_JUMPTABLE;
                      (*DAT_182ec1138)(lVar7,0);
                      lVar7 = *(longlong *)(lVar6 + 0x28);
                      if (lVar7 == 0) goto code_r0x0001804e1d8d;
                      UNRECOVERED_JUMPTABLE = DAT_182ec1088;
                      if ((DAT_182ec1088 == (code *)0x0) &&
                         (UNRECOVERED_JUMPTABLE =
                               (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
                         UNRECOVERED_JUMPTABLE == (code *)0x0)) {
                        uVar8 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar8,0);
                      }
                      DAT_182ec1088 = UNRECOVERED_JUMPTABLE;
                      lVar7 = (*DAT_182ec1088)(lVar7);
                      if (lVar7 == 0) goto code_r0x0001804e1d8d;
                      UNRECOVERED_JUMPTABLE = DAT_182ec1138;
                      if ((DAT_182ec1138 == (code *)0x0) &&
                         (UNRECOVERED_JUMPTABLE =
                               (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), UNRECOVERED_JUMPTABLE == (code *)0x0)) {
                        uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar8,0);
                      }
                      DAT_182ec1138 = UNRECOVERED_JUMPTABLE;
                      (*DAT_182ec1138)(lVar7,0);
                    }
                    else {
                      if (lVar3 == 0) goto code_r0x0001804e1d8d;
                      UNRECOVERED_JUMPTABLE = DAT_182ec1088;
                      if ((DAT_182ec1088 == (code *)0x0) &&
                         (UNRECOVERED_JUMPTABLE =
                               (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
                         UNRECOVERED_JUMPTABLE == (code *)0x0)) {
                        uVar8 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar8,0);
                      }
                      DAT_182ec1088 = UNRECOVERED_JUMPTABLE;
                      lVar7 = (*DAT_182ec1088)(lVar3);
                      if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
                          (lVar3 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30),
                          lVar3 == 0)) || (uVar1 = *(undefined1 *)(lVar3 + 0x1c), lVar7 == 0))
                      goto code_r0x0001804e1d8d;
                      UNRECOVERED_JUMPTABLE = DAT_182ec1138;
                      if ((DAT_182ec1138 == (code *)0x0) &&
                         (UNRECOVERED_JUMPTABLE =
                               (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), UNRECOVERED_JUMPTABLE == (code *)0x0)) {
                        uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar8,0);
                      }
                      DAT_182ec1138 = UNRECOVERED_JUMPTABLE;
                      (*DAT_182ec1138)(lVar7,uVar1);
                      plVar4 = *(longlong **)(lVar6 + 0x20);
                      if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
                          (lVar7 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28),
                          lVar7 == 0)) ||
                         ((lVar7 = *(longlong *)(lVar7 + 0x30), lVar7 == 0 ||
                          (((lVar7 = *(longlong *)(lVar7 + 0x40), lVar7 == 0 ||
                            (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 == 0)) ||
                           (lVar7 = *(longlong *)(lVar7 + 0x128), lVar7 == 0))))))
                      goto code_r0x0001804e1d8d;
                      uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                        (*(undefined8 *)(lVar7 + 0x20),0);
                      uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017b0
                                        (uRam0000000182d63740,uVar8,0);
                      if (plVar4 == (longlong *)0x0) goto code_r0x0001804e1d8d;
                      (**(code **)(*plVar4 + 0x558))(plVar4,uVar8,*(undefined8 *)(*plVar4 + 0x560));
                      plVar4 = *(longlong **)(lVar6 + 0x28);
                      if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
                         (lVar7 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30),
                         lVar7 == 0)) goto code_r0x0001804e1d8d;
                      lVar7 = FUN_181618010(lVar7 + 0x20,0);
                      if (lVar7 == 0) {
                        lVar7 = DAT_182d52e20;
                      }
                      uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017b0
                                        (uRam0000000182d63748,lVar7,0);
                      if (plVar4 == (longlong *)0x0) goto code_r0x0001804e1d8d;
                      (**(code **)(*plVar4 + 0x558))(plVar4,uVar8,*(undefined8 *)(*plVar4 + 0x560));
                    }
                    if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                       (lVar7 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30),
                       lVar7 != 0)) {
                      plVar4 = *(longlong **)(lVar6 + 0x40);
                      if (*(int *)(lVar7 + 0x24) == 0) {
                        if (plVar4 != (longlong *)0x0) {
                          UNRECOVERED_JUMPTABLE = DAT_182ec1088;
                          if ((DAT_182ec1088 == (code *)0x0) &&
                             (UNRECOVERED_JUMPTABLE =
                                   (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
                             UNRECOVERED_JUMPTABLE == (code *)0x0)) {
                            uVar8 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar8,0);
                          }
                          DAT_182ec1088 = UNRECOVERED_JUMPTABLE;
                          lVar6 = (*DAT_182ec1088)(plVar4);
                          if (lVar6 != 0) {
                            UNRECOVERED_JUMPTABLE = DAT_182ec1138;
                            if ((DAT_182ec1138 == (code *)0x0) &&
                               (UNRECOVERED_JUMPTABLE =
                                     (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), UNRECOVERED_JUMPTABLE == (code *)0x0)) {
                              uVar8 = FUN_1802ced60(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  );
                    /* WARNING: Subroutine does not return */
                              FUN_1802cca90(uVar8,0);
                            }
                            DAT_182ec1138 = UNRECOVERED_JUMPTABLE;
                    /* WARNING: Could not recover jumptable at 0x0001804e1d8a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                            (*DAT_182ec1138)(lVar6,0);
                            return;
                          }
                        }
                      }
                      else {
                        lVar6 = FUN_181618010(*(longlong *)
                                               (**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30) + 0x24
                                              ,0);
                        if (lVar6 == 0) {
                          lVar6 = DAT_182d52e20;
                        }
                        uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017b0
                                          (uRam0000000182d63738,lVar6,0);
                        if (plVar4 != (longlong *)0x0) {
                          UNRECOVERED_JUMPTABLE = *(code **)(*plVar4 + 0x558);
                    /* WARNING: Could not recover jumptable at 0x0001804e1d11. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                          (*UNRECOVERED_JUMPTABLE)
                                    (plVar4,uVar8,*(undefined8 *)(*plVar4 + 0x560),
                                     UNRECOVERED_JUMPTABLE);
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
code_r0x0001804e1d8d:
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

