// Ghidra pseudocode; not original source or compilable C.
// ev_577bb0ad3f2ee3be18a1422c4aca52fe541a2ece9137782147e9ecc8858b79c5

void ExposureUnnoticed2_Object3D_NPC_Script_PlayerSearcherChild__OnTriggerExit__060010db
               (longlong param_1,longlong param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong lVar7;
  bool bVar8;
  
  if (cRam0000000182eb779c == '\0') {
    FUN_1802f2810(0x182d5add0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5adc8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5adc0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d582a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ade8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb779c = '\x01';
  }
  if (param_2 != 0) {
    pcVar4 = DAT_182ec1088;
    if ((DAT_182ec1088 == (code *)0x0) &&
       (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
       pcVar4 == (code *)0x0)) {
      uVar6 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar6,0);
    }
    DAT_182ec1088 = pcVar4;
    lVar5 = (*DAT_182ec1088)(param_2);
    if ((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
       (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 != 0)) {
      lVar7 = *(longlong *)(lVar7 + 0x28);
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
      if (lVar5 != 0 || lVar7 != 0) {
        if (lVar7 == 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (lVar5 == 0) goto code_r0x000180439e1e;
          bVar8 = *(longlong *)(lVar5 + 0x10) == 0;
        }
        else if (lVar5 == 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          bVar8 = *(longlong *)(lVar7 + 0x10) == 0;
        }
        else {
          bVar8 = lVar5 == lVar7;
        }
        if (!bVar8) {
          pcVar4 = DAT_182ec1088;
          if ((DAT_182ec1088 == (code *)0x0) &&
             (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
             pcVar4 == (code *)0x0)) {
            uVar6 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar6,0);
          }
          DAT_182ec1088 = pcVar4;
          lVar5 = (*DAT_182ec1088)(param_2);
          if (lVar5 != 0) {
            pcVar4 = pcRam0000000182ec1128;
            if ((pcRam0000000182ec1128 == (code *)0x0) &&
               (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_layer()"),
               pcVar4 == (code *)0x0)) {
              uVar6 = FUN_1802ced60("UnityEngine.GameObject::get_layer()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar6,0);
            }
            pcRam0000000182ec1128 = pcVar4;
            iVar2 = (*pcRam0000000182ec1128)(lVar5);
            if (*(int *)(DAT_182d582a0 + 0xe0) == 0) {
              FUN_18035c820();
            }
            iVar3 = ExposureUnnoticed2_Scripts_Base_LayerAccessor__get_ForeignObjectLayer__060017a2
                              (0);
            if (iVar2 != iVar3) {
              return;
            }
            if ((*(longlong *)(param_1 + 0x38) != 0) &&
               (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x40), lVar5 != 0)) {
              lVar5 = *(longlong *)(lVar5 + 0x78);
              pcVar4 = DAT_182ec1088;
              if ((DAT_182ec1088 == (code *)0x0) &&
                 (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
                 pcVar4 == (code *)0x0)) {
                uVar6 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar6,0);
              }
              DAT_182ec1088 = pcVar4;
              uVar6 = (*DAT_182ec1088)(param_2);
              if (lVar5 != 0) {
                cVar1 = FUN_181110610(lVar5,uVar6,uRam0000000182d5adc8);
                if (cVar1 != '\0') {
                  return;
                }
                lVar5 = *(longlong *)(param_1 + 0x30);
                uVar6 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                                  (param_2,0);
                if (lVar5 != 0) {
                  cVar1 = FUN_181110610(lVar5,uVar6,uRam0000000182d5adc8);
                  if (cVar1 == '\0') {
                    return;
                  }
                  lVar5 = *(longlong *)(param_1 + 0x30);
                  uVar6 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                                    (param_2,0);
                  if (lVar5 != 0) {
                    FUN_181110820(lVar5,uVar6,uRam0000000182d5adc0);
                    lVar5 = *(longlong *)(param_1 + 0x28);
                    lVar7 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                                      (param_2,0);
                    if ((lVar7 != 0) &&
                       (uVar6 = FUN_1809a08f0(lVar7,uRam0000000182d5add0), lVar5 != 0)) {
                      FUN_181274e50(lVar5,uVar6,uRam0000000182d5ade8);
                      return;
                    }
                  }
                }
              }
            }
          }
          goto code_r0x000180439e1e;
        }
      }
      *(undefined1 *)(param_1 + 0x20) = 0;
      return;
    }
  }
code_r0x000180439e1e:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

