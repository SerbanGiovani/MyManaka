// Ghidra pseudocode; not original source or compilable C.
// ev_1c7ec785952a76f83162d704eb2aaa7afbb70387dbd084db1c66116d526470a9

void ExposureUnnoticed2_Scripts_UI_TitleSceneView__Awake__060013a1(longlong param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  longlong lVar4;
  code *pcVar5;
  char cVar6;
  code *pcVar7;
  longlong lVar8;
  undefined8 uVar9;
  longlong *plVar10;
  longlong *plVar11;
  
  if (cRam0000000182eb78ae == '\0') {
    FUN_1802f2810(0x182d5bfc8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfc0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d53a48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aab0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfb0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfa0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bf98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bf90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bf88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfd0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bf80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bf78);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52e20);
    LOCK();
    UNLOCK();
    cRam0000000182eb78ae = '\x01';
  }
  lVar8 = *(longlong *)(param_1 + 0x50);
  if (lVar8 == 0) goto code_r0x00018046f0a3;
  pcVar7 = pcRam0000000182ec1088;
  if ((pcRam0000000182ec1088 == (code *)0x0) &&
     (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
     pcVar7 == (code *)0x0)) {
    uVar9 = func_0x0001802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar9,0);
  }
  pcRam0000000182ec1088 = pcVar7;
  lVar8 = (*pcRam0000000182ec1088)(lVar8);
  if (lVar8 == 0) goto code_r0x00018046f0a3;
  pcVar7 = pcRam0000000182ec1138;
  if ((pcRam0000000182ec1138 == (code *)0x0) &&
     (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
     pcVar7 == (code *)0x0)) {
    uVar9 = func_0x0001802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar9,0);
  }
  pcRam0000000182ec1138 = pcVar7;
  (*pcRam0000000182ec1138)(lVar8,1);
  uVar9 = FUN_1802c43a0(uRam0000000182d5bfc8);
  FUN_180665bb0(uVar9,param_1,uRam0000000182d5bf90,0);
  if (*(int *)(lRam0000000182d583a0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  FUN_180993250(uVar9,0,uRam0000000182d5bfb0);
  uVar9 = FUN_1802c43a0(uRam0000000182d5bfc0);
  FUN_180665bb0(uVar9,param_1,uRam0000000182d5bf98,0);
  FUN_180993250(uVar9,0,uRam0000000182d5bfa8);
  FUN_180477f00(param_1);
  if (*(int *)(lRam0000000182d53a48 + 0xe0) == 0) {
    FUN_18035c820();
  }
  pcVar7 = pcRam0000000182ebf9e0;
  if ((pcRam0000000182ebf9e0 == (code *)0x0) &&
     (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Application::set_targetFrameRate(System.Int32)"),
     pcVar7 == (code *)0x0)) {
    uVar9 = func_0x0001802ced60("UnityEngine.Application::set_targetFrameRate(System.Int32)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar9,0);
  }
  pcRam0000000182ebf9e0 = pcVar7;
  (*pcRam0000000182ebf9e0)(0x3c);
  if (*(int *)(lRam0000000182d5bfa0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182eb7ae7 == '\0') {
    FUN_1802f2810(0x182d55b08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f428);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfa0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f420);
    LOCK();
    UNLOCK();
    cRam0000000182eb7ae7 = '\x01';
  }
  if (*(int *)(lRam0000000182d5bfa0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar8 = *(longlong *)(*(longlong *)(lRam0000000182d5bfa0 + 0xb8) + 8);
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ec12f4 == '\0') {
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182ec12f4 = '\x01';
  }
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ec129b == '\0') {
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182ec129b = '\x01';
  }
  if (lVar8 == 0) {
code_r0x00018046e8a6:
    plVar10 = (longlong *)UnityEngine_Resources__Load__060008e7(uRam0000000182d5f420,0);
    if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    plVar11 = (longlong *)0x0;
    if (plVar10 != (longlong *)0x0) {
      if (*plVar10 == lRam0000000182d55b08) {
        plVar11 = plVar10;
      }
      if (plVar11 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031e210(plVar10);
      }
    }
    FUN_1809f0e30(plVar11,uRam0000000182d5f428);
  }
  else {
    if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar8 + 0x10) == 0) goto code_r0x00018046e8a6;
  }
  FUN_18049d380(4,0xffffffff,0);
  cVar6 = FUN_18049bf10(2,0xffffffff,0);
  if (cVar6 == '\0') {
    cVar6 = FUN_18049bf10(3,0,0);
    if (cVar6 != '\0') goto code_r0x00018046eb57;
    cVar6 = FUN_18049bf10(3,1,0);
    if (cVar6 != '\0') goto code_r0x00018046eb57;
    cVar6 = FUN_18049bf10(3,2,0);
    if (cVar6 != '\0') goto code_r0x00018046eb57;
    cVar6 = FUN_18049bf10(3,3,0);
    if (cVar6 != '\0') goto code_r0x00018046eb57;
    cVar6 = FUN_18049bf10(3,4,0);
    if (cVar6 != '\0') goto code_r0x00018046eb57;
    cVar6 = FUN_18049bf10(3,5,0);
    if (cVar6 != '\0') goto code_r0x00018046eb57;
    cVar6 = FUN_18049bf10(3,6,0);
    if (cVar6 != '\0') goto code_r0x00018046eb57;
    cVar6 = FUN_18049bf10(3,7,0);
    if (cVar6 != '\0') goto code_r0x00018046eb57;
    cVar6 = FUN_18049bf10(3,8,0);
    if (cVar6 != '\0') goto code_r0x00018046eb57;
    cVar6 = FUN_18049bf10(3,9,0);
    if (cVar6 != '\0') goto code_r0x00018046eb57;
    cVar6 = FUN_18049bf10(3,10,0);
    if (cVar6 != '\0') goto code_r0x00018046eb57;
    cVar6 = FUN_18049bf10(3,0xb,0);
    if (cVar6 != '\0') goto code_r0x00018046eb57;
    cVar6 = FUN_18049bf10(3,0xc,0);
    if (cVar6 != '\0') goto code_r0x00018046eb57;
    cVar6 = FUN_18049bf10(3,0xd,0);
    if (cVar6 != '\0') goto code_r0x00018046eb57;
    cVar6 = FUN_18049bf10(3,0xe,0);
    if (cVar6 != '\0') goto code_r0x00018046eb57;
    cVar6 = FUN_18049bf10(3,0xf,0);
    if (cVar6 != '\0') goto code_r0x00018046eb57;
    cVar6 = FUN_18049bf10(3,0x10,0);
    if (cVar6 != '\0') goto code_r0x00018046eb57;
    cVar6 = FUN_18049bf10(3,0x11,0);
    if (cVar6 != '\0') goto code_r0x00018046eb57;
    cVar6 = FUN_18049bf10(3,0x12,0);
    if (cVar6 != '\0') goto code_r0x00018046eb57;
    cVar6 = FUN_18049bf10(3,0x13,0);
    if (cVar6 != '\0') goto code_r0x00018046eb57;
    cVar6 = FUN_18049bf10(1,1,0);
    if (cVar6 != '\0') goto code_r0x00018046eb57;
    cVar6 = FUN_18049bf10(0,0xffffffff,0);
    if (cVar6 != '\0') goto code_r0x00018046eb57;
    if (*(longlong *)(param_1 + 0x30) == 0) goto code_r0x00018046f0a3;
    FUN_181f3ea80(*(longlong *)(param_1 + 0x30),0,0);
  }
  else {
code_r0x00018046eb57:
    lVar8 = *(longlong *)(param_1 + 0x30);
    if (lVar8 == 0) goto code_r0x00018046f0a3;
    pcVar7 = pcRam0000000182ec1138;
    if ((pcRam0000000182ec1138 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
       pcVar7 == (code *)0x0)) {
      uVar9 = func_0x0001802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    pcRam0000000182ec1138 = pcVar7;
    (*pcRam0000000182ec1138)(lVar8,1);
  }
  if (*(int *)(lRam0000000182d5bf80 + 0xe0) == 0) {
    FUN_18035c820();
  }
  FUN_1804bc500(0);
  lVar8 = *(longlong *)(*(longlong *)(lRam0000000182d58398 + 0xb8) + 0x38);
  if (lVar8 != 0) {
    uVar2 = *(undefined4 *)(lVar8 + 0x90);
    if (*(int *)(lRam0000000182d53a48 + 0xe0) == 0) {
      FUN_18035c820();
    }
    pcVar7 = pcRam0000000182ebf9e0;
    if ((pcRam0000000182ebf9e0 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Application::set_targetFrameRate(System.Int32)")
       , pcVar7 == (code *)0x0)) {
      uVar9 = func_0x0001802ced60("UnityEngine.Application::set_targetFrameRate(System.Int32)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    pcRam0000000182ebf9e0 = pcVar7;
    (*pcRam0000000182ebf9e0)(uVar2);
    lVar8 = FUN_180735660(param_1,uRam0000000182d5aab0);
    if (lVar8 != 0) {
      FUN_1804b5750(lVar8,0);
      if (*(longlong *)(param_1 + 0x48) != 0) {
        FUN_1804b5750(*(longlong *)(param_1 + 0x48),0);
        if (cRam0000000182eb7ab0 == '\0') {
          FUN_1802f2810(0x182d5f7a0);
          LOCK();
          UNLOCK();
          cRam0000000182eb7ab0 = '\x01';
        }
        if (**(longlong **)(lRam0000000182d5f7a0 + 0xb8) != 0) {
          FUN_1804b5ea0(**(longlong **)(lRam0000000182d5f7a0 + 0xb8),1,0);
        }
        lVar8 = *(longlong *)(*(longlong *)(lRam0000000182d58398 + 0xb8) + 0x38);
        if (lVar8 != 0) {
          lVar4 = *(longlong *)(param_1 + 0x20);
          iVar3 = *(int *)(lVar8 + 0x1c);
          if (lVar4 != 0) {
            pcVar7 = pcRam0000000182ec1138;
            if ((pcRam0000000182ec1138 == (code *)0x0) &&
               (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
               pcVar7 == (code *)0x0)) {
              uVar9 = func_0x0001802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar9,0);
            }
            pcRam0000000182ec1138 = pcVar7;
            (*pcRam0000000182ec1138)(lVar4,iVar3 == 0);
            lVar8 = *(longlong *)(*(longlong *)(lRam0000000182d58398 + 0xb8) + 0x38);
            if (lVar8 != 0) {
              lVar4 = *(longlong *)(param_1 + 0x28);
              iVar3 = *(int *)(lVar8 + 0x1c);
              if (lVar4 != 0) {
                pcVar7 = pcRam0000000182ec1138;
                if ((pcRam0000000182ec1138 == (code *)0x0) &&
                   (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar7 == (code *)0x0)) {
                  uVar9 = func_0x0001802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar9,0);
                }
                pcRam0000000182ec1138 = pcVar7;
                (*pcRam0000000182ec1138)(lVar4,iVar3 != 0);
                if (*(longlong *)(param_1 + 0x58) != 0) {
                  FUN_180494dc0(*(longlong *)(param_1 + 0x58),0);
                  pcVar7 = pcRam0000000182ec1088;
                  if (*(char *)(*(longlong *)(lRam0000000182d5bfd0 + 0xb8) + 8) != '\0') {
                    lVar8 = *(longlong *)(param_1 + 0x50);
                    if (lVar8 == 0) goto code_r0x00018046f0a3;
                    *(undefined1 *)(lVar8 + 0x20) = 1;
                    pcVar5 = pcRam0000000182ec1088;
                    if ((pcVar7 == (code *)0x0) &&
                       (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
                       pcVar5 = pcVar7, pcVar7 == (code *)0x0)) {
                      uVar9 = func_0x0001802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar9,0);
                    }
                    pcRam0000000182ec1088 = pcVar5;
                    lVar8 = (*pcVar7)(lVar8);
                    if (lVar8 == 0) goto code_r0x00018046f0a3;
                    pcVar7 = pcRam0000000182ec1138;
                    if ((pcRam0000000182ec1138 == (code *)0x0) &&
                       (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar7 == (code *)0x0)) {
                      uVar9 = func_0x0001802ced60(
                                                 "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                 );
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar9,0);
                    }
                    pcRam0000000182ec1138 = pcVar7;
                    (*pcRam0000000182ec1138)(lVar8,0);
                  }
                  *(undefined1 *)(*(longlong *)(lRam0000000182d5bfd0 + 0xb8) + 8) = 1;
                  if (cRam0000000182eb78b2 == '\0') {
                    FUN_1802f2810(0x182d58398);
                    LOCK();
                    UNLOCK();
                    cRam0000000182eb78b2 = '\x01';
                  }
                  lVar8 = *(longlong *)(*(longlong *)(lRam0000000182d58398 + 0xb8) + 0x38);
                  if (lVar8 != 0) {
                    lVar4 = *(longlong *)(param_1 + 0x60);
                    iVar3 = *(int *)(lVar8 + 0x80);
                    if (lVar4 != 0) {
                      pcVar7 = pcRam0000000182ec1138;
                      if ((pcRam0000000182ec1138 == (code *)0x0) &&
                         (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar7 == (code *)0x0)) {
                        uVar9 = func_0x0001802ced60(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  );
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar9,0);
                      }
                      pcRam0000000182ec1138 = pcVar7;
                      (*pcRam0000000182ec1138)(lVar4,iVar3 == 0);
                      lVar8 = *(longlong *)(*(longlong *)(lRam0000000182d58398 + 0xb8) + 0x38);
                      if (lVar8 != 0) {
                        lVar4 = *(longlong *)(param_1 + 0x68);
                        iVar3 = *(int *)(lVar8 + 0x80);
                        if (lVar4 != 0) {
                          pcVar7 = pcRam0000000182ec1138;
                          if ((pcRam0000000182ec1138 == (code *)0x0) &&
                             (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar7 == (code *)0x0)) {
                            uVar9 = func_0x0001802ced60(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar9,0);
                          }
                          pcRam0000000182ec1138 = pcVar7;
                          (*pcRam0000000182ec1138)(lVar4,iVar3 == 1);
                          lVar8 = *(longlong *)(*(longlong *)(lRam0000000182d58398 + 0xb8) + 0x38);
                          if (lVar8 != 0) {
                            lVar4 = *(longlong *)(param_1 + 0x70);
                            uVar1 = *(undefined1 *)(lVar8 + 0x20);
                            if (lVar4 != 0) {
                              pcVar7 = pcRam0000000182ec1138;
                              if ((pcRam0000000182ec1138 == (code *)0x0) &&
                                 (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar7 == (code *)0x0)) {
                                uVar9 = func_0x0001802ced60(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                FUN_1802cca90(uVar9,0);
                              }
                              pcRam0000000182ec1138 = pcVar7;
                              (*pcRam0000000182ec1138)(lVar4,uVar1);
                              lVar8 = *(longlong *)
                                       (*(longlong *)(lRam0000000182d58398 + 0xb8) + 0x38);
                              if (lVar8 != 0) {
                                lVar4 = *(longlong *)(param_1 + 0x78);
                                uVar1 = *(undefined1 *)(lVar8 + 0x20);
                                if (lVar4 != 0) {
                                  pcVar7 = pcRam0000000182ec1138;
                                  if ((pcRam0000000182ec1138 == (code *)0x0) &&
                                     (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar7 == (code *)0x0)) {
                                    uVar9 = func_0x0001802ced60(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                    FUN_1802cca90(uVar9,0);
                                  }
                                  pcRam0000000182ec1138 = pcVar7;
                                  (*pcRam0000000182ec1138)(lVar4,uVar1);
                                  FUN_18046f2c0(param_1,0);
                                  lVar8 = *(longlong *)(param_1 + 0x90);
                                  if (*(int *)(lRam0000000182d5bfa0 + 0xe0) == 0) {
                                    FUN_18035c820(lRam0000000182d5bfa0);
                                  }
                                  uVar1 = **(undefined1 **)(lRam0000000182d5bfa0 + 0xb8);
                                  if (lVar8 != 0) {
                                    pcVar7 = pcRam0000000182ec1138;
                                    if ((pcRam0000000182ec1138 == (code *)0x0) &&
                                       (pcVar7 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar7 == (code *)0x0)) {
                                      uVar9 = func_0x0001802ced60(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                      FUN_1802cca90(uVar9,0);
                                    }
                                    pcRam0000000182ec1138 = pcVar7;
                                    (*pcRam0000000182ec1138)(lVar8,uVar1);
                                    if (*(char *)(*(longlong *)(lRam0000000182d5bfa0 + 0xb8) + 2) !=
                                        '\0') {
                                      uVar9 = FUN_1802c43a0(uRam0000000182d58368);
                                      FUN_1814df680(uVar9,param_1,uRam0000000182d5bf88,0);
                                      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
                                        FUN_18035c820();
                                      }
                                      IKA9nt_Encrypter_EncrypterCore__LoadBundleFromStreamAsync__06000079
                                                (uRam0000000182d5bf78,uVar9,DAT_182d52e20,0,0);
                                      return;
                                    }
                                    *(undefined4 *)(param_1 + 0xb4) = 500;
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
        }
      }
    }
  }
code_r0x00018046f0a3:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

