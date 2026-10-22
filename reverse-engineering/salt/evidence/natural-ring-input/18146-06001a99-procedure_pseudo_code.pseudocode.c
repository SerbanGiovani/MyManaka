// Ghidra pseudocode; not original source or compilable C.
// ev_4d6b5290fde59ac6b0329be448c01821ce05dda43eb4f0361b59f0cc2e825c3a

void ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__LateUpdate__06001a99
               (longlong param_1)

{
  undefined1 uVar1;
  ulonglong uVar2;
  char cVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 *puVar6;
  code *pcVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  int iVar10;
  uint uVar11;
  bool bVar12;
  undefined8 uStack_70;
  longlong *plStack_68;
  undefined8 uStack_60;
  longlong lStack_58;
  longlong lStack_50;
  longlong lStack_48;
  
  if (cRam0000000182eb7ca8 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62258);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62248);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58380);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62228);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62210);
    LOCK();
    UNLOCK();
    cRam0000000182eb7ca8 = '\x01';
  }
  lStack_58 = 0;
  lStack_50 = 0;
  lStack_48 = 0;
  lVar4 = *(longlong *)(param_1 + 0xd0);
  if (*(char *)(param_1 + 0x70) == '\0') {
    if ((lVar4 == 0) ||
       (ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c(lVar4),
       *(longlong *)(param_1 + 200) == 0)) goto code_r0x000180501987;
    ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c();
    if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d58380);
    }
    lVar4 = **(longlong **)(DAT_182d58380 + 0xb8);
    if (lVar4 == 0) goto code_r0x000180501987;
    if ((*(char *)(lVar4 + 0x22) != '\0') || (*(char *)(lVar4 + 0x21) != '\0'))
    goto code_r0x000180500a3c;
    if (DAT_182eb5493 == '\0') {
      FUN_1802f2810(&DAT_182d592c0);
      LOCK();
      UNLOCK();
      DAT_182eb5493 = '\x01';
    }
    if (**(longlong **)(DAT_182d592c0 + 0xb8) == 0) goto code_r0x000180501987;
    if (*(char *)(**(longlong **)(DAT_182d592c0 + 0xb8) + 0x10) == '\0') {
      if (*(char *)(param_1 + 0x71) == '\0') {
        if (*(char *)(param_1 + 0xe0) == '\0') {
          cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                            (param_1,0xe,0);
          if (cVar3 == '\0') {
            cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                              (param_1,0x17,0);
            if (cVar3 == '\0') {
              cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                                (param_1,0x1b,0);
              if (cVar3 == '\0') {
                cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                                  (param_1,0x1c,0);
                if (cVar3 == '\0') {
                  cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                                    (param_1,0x3fa,0);
                  if (cVar3 == '\0') {
                    cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                                      (param_1,0x3fb,0);
                    if (cVar3 == '\0') {
                      cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                                        (param_1,0x3fc,0);
                      if (cVar3 == '\0') {
                        cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                                          (param_1,0x3fd,0);
                        if (cVar3 == '\0') goto code_r0x000180500a3c;
                      }
                    }
                  }
                }
              }
            }
          }
          if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
              (lVar4 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar4 == 0)) ||
             (lVar4 = *(longlong *)(lVar4 + 0x38), lVar4 == 0)) goto code_r0x000180501987;
          *(undefined1 *)(lVar4 + 0x28) = 1;
          *(undefined1 *)(param_1 + 0x70) = 1;
          if (*(longlong *)(param_1 + 0x68) == 0) goto code_r0x000180501987;
          FUN_181f3ea80(*(longlong *)(param_1 + 0x68),1,0);
          cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                            (param_1,0xe,0);
          if (cVar3 == '\0') {
            cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                              (param_1,0x17,0);
            if (cVar3 == '\0') {
              cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                                (param_1,0x1b,0);
              if (cVar3 == '\0') {
                cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                                  (param_1,0x1c,0);
                if (cVar3 == '\0') {
                  cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                                    (param_1,0x3fa,0);
                  if (cVar3 == '\0') {
                    cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                                      (param_1,0x3fb,0);
                    if (cVar3 == '\0') {
                      cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                                        (param_1,0x3fc,0);
                      iVar10 = 7 - (uint)(cVar3 != '\0');
                    }
                    else {
                      iVar10 = 5;
                    }
                  }
                  else {
                    iVar10 = 4;
                  }
                }
                else {
                  iVar10 = 3;
                }
              }
              else {
                iVar10 = 2;
              }
            }
            else {
              iVar10 = 1;
            }
          }
          else {
            iVar10 = 0;
          }
          ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__OpenRingMenu__06001a9c
                    (param_1,iVar10,0);
        }
        goto code_r0x000180500a3c;
      }
    }
    else {
code_r0x000180500a3c:
      if (*(char *)(param_1 + 0x71) == '\0') {
        cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetShortUp__06001a9b
                          (param_1,0xe,0);
        if (((cVar3 != '\0') && (*(longlong *)(param_1 + 0x88) != 0)) &&
           (*(longlong *)(*(longlong *)(param_1 + 0x88) + 0x18) == 0)) {
          *(undefined1 *)(*(longlong *)(lRam0000000182d62238 + 0xb8) + 4) = 0;
          if (*(longlong *)(param_1 + 0x88) == 0) goto code_r0x000180501987;
          **(undefined4 **)(lRam0000000182d62238 + 0xb8) =
               *(undefined4 *)(*(longlong *)(param_1 + 0x88) + 0x14);
        }
        if (*(char *)(param_1 + 0x71) == '\0') {
          cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetShortUp__06001a9b
                            (param_1,0xe,0);
          if (((cVar3 != '\0') && (lVar4 = *(longlong *)(param_1 + 0x88), lVar4 != 0)) &&
             (*(longlong *)(lVar4 + 0x18) != 0)) {
            lVar4 = *(longlong *)(lVar4 + 0x18);
            (**(code **)(lVar4 + 0x18))(*(undefined8 *)(lVar4 + 0x40),*(undefined8 *)(lVar4 + 0x28))
            ;
          }
          if (*(char *)(param_1 + 0x71) == '\0') {
            cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetShortUp__06001a9b
                              (param_1,0x17,0);
            if (((cVar3 != '\0') && (*(longlong *)(param_1 + 0x90) != 0)) &&
               (*(longlong *)(*(longlong *)(param_1 + 0x90) + 0x18) == 0)) {
              *(undefined1 *)(*(longlong *)(lRam0000000182d62238 + 0xb8) + 4) = 0;
              if (*(longlong *)(param_1 + 0x90) == 0) goto code_r0x000180501987;
              **(undefined4 **)(lRam0000000182d62238 + 0xb8) =
                   *(undefined4 *)(*(longlong *)(param_1 + 0x90) + 0x14);
            }
            if (*(char *)(param_1 + 0x71) == '\0') {
              cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetShortUp__06001a9b
                                (param_1,0x1b,0);
              if (((cVar3 != '\0') && (*(longlong *)(param_1 + 0x98) != 0)) &&
                 (*(longlong *)(*(longlong *)(param_1 + 0x98) + 0x18) == 0)) {
                *(undefined1 *)(*(longlong *)(lRam0000000182d62238 + 0xb8) + 4) = 0;
                if (*(longlong *)(param_1 + 0x98) == 0) goto code_r0x000180501987;
                **(undefined4 **)(lRam0000000182d62238 + 0xb8) =
                     *(undefined4 *)(*(longlong *)(param_1 + 0x98) + 0x14);
              }
              if (*(char *)(param_1 + 0x71) == '\0') {
                cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetShortUp__06001a9b
                                  (param_1,0x1c,0);
                if (((cVar3 != '\0') && (*(longlong *)(param_1 + 0xa0) != 0)) &&
                   (*(longlong *)(*(longlong *)(param_1 + 0xa0) + 0x18) == 0)) {
                  *(undefined1 *)(*(longlong *)(lRam0000000182d62238 + 0xb8) + 4) = 0;
                  if (*(longlong *)(param_1 + 0xa0) == 0) goto code_r0x000180501987;
                  **(undefined4 **)(lRam0000000182d62238 + 0xb8) =
                       *(undefined4 *)(*(longlong *)(param_1 + 0xa0) + 0x14);
                }
                if (*(char *)(param_1 + 0x71) == '\0') {
                  cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetShortUp__06001a9b
                                    (param_1,0x3fa,0);
                  if (((cVar3 != '\0') && (*(longlong *)(param_1 + 0xa8) != 0)) &&
                     (*(longlong *)(*(longlong *)(param_1 + 0xa8) + 0x18) == 0)) {
                    *(undefined1 *)(*(longlong *)(lRam0000000182d62238 + 0xb8) + 4) = 1;
                    if (*(longlong *)(param_1 + 0xa8) == 0) goto code_r0x000180501987;
                    **(undefined4 **)(lRam0000000182d62238 + 0xb8) =
                         *(undefined4 *)(*(longlong *)(param_1 + 0xa8) + 0x14);
                  }
                  if (*(char *)(param_1 + 0x71) == '\0') {
                    cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetShortUp__06001a9b
                                      (param_1,0x3fb,0);
                    if (((cVar3 != '\0') && (*(longlong *)(param_1 + 0xb0) != 0)) &&
                       (*(longlong *)(*(longlong *)(param_1 + 0xb0) + 0x18) == 0)) {
                      *(undefined1 *)(*(longlong *)(lRam0000000182d62238 + 0xb8) + 4) = 1;
                      if (*(longlong *)(param_1 + 0xb0) == 0) goto code_r0x000180501987;
                      **(undefined4 **)(lRam0000000182d62238 + 0xb8) =
                           *(undefined4 *)(*(longlong *)(param_1 + 0xb0) + 0x14);
                    }
                    if (*(char *)(param_1 + 0x71) == '\0') {
                      cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetShortUp__06001a9b
                                        (param_1,0x3fc,0);
                      if (((cVar3 != '\0') && (*(longlong *)(param_1 + 0xb8) != 0)) &&
                         (*(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x18) == 0)) {
                        *(undefined1 *)(*(longlong *)(lRam0000000182d62238 + 0xb8) + 4) = 1;
                        if (*(longlong *)(param_1 + 0xb8) == 0) goto code_r0x000180501987;
                        **(undefined4 **)(lRam0000000182d62238 + 0xb8) =
                             *(undefined4 *)(*(longlong *)(param_1 + 0xb8) + 0x14);
                      }
                      if ((((*(char *)(param_1 + 0x71) == '\0') &&
                           (cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetShortUp__06001a9b
                                              (param_1,0x3fd,0), cVar3 != '\0')) &&
                          (*(longlong *)(param_1 + 0xc0) != 0)) &&
                         (*(longlong *)(*(longlong *)(param_1 + 0xc0) + 0x18) == 0)) {
                        *(undefined1 *)(*(longlong *)(lRam0000000182d62238 + 0xb8) + 4) = 1;
                        if (*(longlong *)(param_1 + 0xc0) == 0) goto code_r0x000180501987;
                        **(undefined4 **)(lRam0000000182d62238 + 0xb8) =
                             *(undefined4 *)(*(longlong *)(param_1 + 0xc0) + 0x14);
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
    if (*(char *)(param_1 + 0xe0) != '\0') {
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0xe,0);
      if (cVar3 == '\0') {
        if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
          FUN_18035c820();
        }
        cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0x17,0);
        if (cVar3 == '\0') {
          if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
            FUN_18035c820();
          }
          cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0x1b,0);
          if (cVar3 == '\0') {
            if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
              FUN_18035c820();
            }
            cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0x1c,0);
            if (cVar3 == '\0') {
              if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
                FUN_18035c820();
              }
              cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0x3fa,0);
              if (cVar3 == '\0') {
                if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0x3fb,0);
                if (cVar3 == '\0') {
                  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
                    FUN_18035c820();
                  }
                  cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0x3fc,0);
                  if (cVar3 == '\0') {
                    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
                      FUN_18035c820();
                    }
                    cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0x3fd,0);
                    if (cVar3 == '\0') {
                      *(undefined1 *)(param_1 + 0xe0) = 0;
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
  else {
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
    FUN_180477d40();
    if (lVar4 == 0) goto code_r0x000180501987;
    ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c(lVar4);
    if ((((((((*(int *)(param_1 + 0x78) == 0) &&
             (cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                                (param_1,0xe,0), cVar3 == '\0')) ||
            ((*(int *)(param_1 + 0x78) == 1 &&
             (cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                                (param_1,0x17,0), cVar3 == '\0')))) ||
           ((*(int *)(param_1 + 0x78) == 2 &&
            (cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                               (param_1,0x1b,0), cVar3 == '\0')))) ||
          ((*(int *)(param_1 + 0x78) == 3 &&
           (cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                              (param_1,0x1c,0), cVar3 == '\0')))) ||
         ((((*(int *)(param_1 + 0x78) == 4 &&
            (cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                               (param_1,0x3fa,0), cVar3 == '\0')) ||
           ((*(int *)(param_1 + 0x78) == 5 &&
            (cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                               (param_1,0x3fb,0), cVar3 == '\0')))) ||
          ((*(int *)(param_1 + 0x78) == 6 &&
           (cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                              (param_1,0x3fc,0), cVar3 == '\0')))))) ||
        ((*(int *)(param_1 + 0x78) == 7 &&
         (cVar3 = ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuParentView__GetLongDown__06001a9a
                            (param_1,0x3fd,0), cVar3 == '\0')))) ||
       (*(char *)(param_1 + 0xe0) != '\0')) {
code_r0x00018050108f:
      if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
          (lVar4 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar4 == 0)) ||
         (lVar4 = *(longlong *)(lVar4 + 0x38), lVar4 == 0)) goto code_r0x000180501987;
      *(undefined1 *)(lVar4 + 0x28) = 0;
      *(undefined2 *)(param_1 + 0x70) = 0x100;
      lVar4 = *(longlong *)(param_1 + 0x68);
      lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
      if ((lVar5 == 0) || (uVar1 = *(undefined1 *)(lVar5 + 0x3c), lVar4 == 0))
      goto code_r0x000180501987;
      pcVar7 = DAT_182ec1138;
      if ((DAT_182ec1138 == (code *)0x0) &&
         (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
         pcVar7 == (code *)0x0)) {
        uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar8,0);
      }
      DAT_182ec1138 = pcVar7;
      (*DAT_182ec1138)(lVar4,uVar1);
      lVar4 = *(longlong *)(param_1 + 0x80);
      if (lVar4 == 0) goto code_r0x000180501987;
      if (DAT_182eb5d50 != 0) {
        uVar11 = (uint)((ulonglong)&uStack_70 >> 0xc);
        uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
          LOCK();
          bVar12 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
          if (bVar12) {
            *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar2 | 1L << (uVar11 & 0x3f);
          }
          UNLOCK();
        } while (!bVar12);
      }
      uStack_60 = 0;
      lStack_50 = (ulonglong)*(uint *)(lVar4 + 0x1c) << 0x20;
      lStack_48 = 0;
      uStack_70 = 0;
      plStack_68 = &lStack_58;
      lStack_58 = lVar4;
      while (cVar3 = FUN_180f72b70(&lStack_58,uRam0000000182d62258), cVar3 != '\0') {
        if (lStack_48 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuView__ChangeState__06001ace(lStack_48,1)
        ;
      }
      lVar5 = FUN_1802c43a0(DAT_182d58368);
      lVar4 = lRam0000000182d62210;
      *(undefined8 *)(lVar5 + 0x10) = *(undefined8 *)(lRam0000000182d62210 + 8);
      *(longlong *)(lVar5 + 0x28) = lVar4;
      *(longlong *)(lVar5 + 0x20) = param_1;
      if (DAT_182eb5d50 != 0) {
        uVar11 = (uint)(lVar5 + 0x20U >> 0xc);
        uVar9 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
          LOCK();
          bVar12 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8);
          if (bVar12) {
            *(ulonglong *)(&DAT_182f0c920 + uVar9 * 8) = uVar2 | 1L << (uVar11 & 0x3f);
          }
          UNLOCK();
        } while (!bVar12);
      }
      cVar3 = *(char *)(lVar4 + 0x52);
      *(longlong *)(lVar5 + 0x40) = lVar5;
      if ((*(byte *)(lVar4 + 0x4c) & 0x10) == 0) {
        if (param_1 == 0) {
          uVar8 = FUN_18031daf0();
                    /* WARNING: Subroutine does not return */
          FUN_18031da90(uVar8,0);
        }
code_r0x0001805012d1:
        *(undefined8 *)(lVar5 + 0x40) = *(undefined8 *)(lVar5 + 0x20);
        puVar6 = *(undefined1 **)(lVar5 + 0x10);
      }
      else {
        if (cVar3 != '\0') goto code_r0x0001805012d1;
        puVar6 = &LAB_1800c7840;
      }
      *(undefined1 **)(lVar5 + 0x18) = puVar6;
      *(code **)(lVar5 + 0x38) = FUN_1801e91e0;
      ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b(lVar5,0x12,0);
    }
    else {
      if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d58380);
      }
      lVar4 = **(longlong **)(DAT_182d58380 + 0xb8);
      if (lVar4 == 0) goto code_r0x000180501987;
      if ((*(char *)(lVar4 + 0x22) != '\0') || (*(char *)(lVar4 + 0x21) != '\0'))
      goto code_r0x00018050108f;
      lVar4 = FUN_180436330();
      if (lVar4 == 0) goto code_r0x000180501987;
      if (*(char *)(lVar4 + 0x10) != '\0') goto code_r0x00018050108f;
    }
    lVar4 = 0xd8;
    if (*(int *)(param_1 + 0x78) != 0) {
      lVar4 = 0xdc;
    }
    iVar10 = *(int *)(lVar4 + param_1) + 1;
    if (*(int *)(param_1 + 0x78) == 0) {
      if (*(longlong *)(param_1 + 200) == 0) goto code_r0x000180501987;
      ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c();
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f2,0);
      if (cVar3 != '\0') {
        *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
      }
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f3,0);
      if (cVar3 != '\0') {
        *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
      }
      *(int *)(param_1 + 0x20) = (*(int *)(param_1 + 0x20) + iVar10) % iVar10;
    }
    if (*(int *)(param_1 + 0x78) == 1) {
      if (*(longlong *)(param_1 + 200) == 0) goto code_r0x000180501987;
      ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c();
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f2,0);
      if (cVar3 != '\0') {
        *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
      }
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f3,0);
      if (cVar3 != '\0') {
        *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
      }
      *(int *)(param_1 + 0x24) = (*(int *)(param_1 + 0x24) + iVar10) % iVar10;
    }
    if (*(int *)(param_1 + 0x78) == 2) {
      if (*(longlong *)(param_1 + 200) == 0) goto code_r0x000180501987;
      ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c();
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f2,0);
      if (cVar3 != '\0') {
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + -1;
      }
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f3,0);
      if (cVar3 != '\0') {
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
      }
      *(int *)(param_1 + 0x28) = (*(int *)(param_1 + 0x28) + iVar10) % iVar10;
    }
    if (*(int *)(param_1 + 0x78) == 3) {
      if (*(longlong *)(param_1 + 200) == 0) goto code_r0x000180501987;
      ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c();
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f2,0);
      if (cVar3 != '\0') {
        *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + -1;
      }
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f3,0);
      if (cVar3 != '\0') {
        *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
      }
      *(int *)(param_1 + 0x2c) = (*(int *)(param_1 + 0x2c) + iVar10) % iVar10;
    }
    if (*(int *)(param_1 + 0x78) == 4) {
      if (*(longlong *)(param_1 + 200) == 0) goto code_r0x000180501987;
      ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c();
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f2,0);
      if (cVar3 != '\0') {
        *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;
      }
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f3,0);
      if (cVar3 != '\0') {
        *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
      }
      *(int *)(param_1 + 0x30) = (*(int *)(param_1 + 0x30) + iVar10) % iVar10;
    }
    if (*(int *)(param_1 + 0x78) == 5) {
      if (*(longlong *)(param_1 + 200) == 0) goto code_r0x000180501987;
      ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c();
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f2,0);
      if (cVar3 != '\0') {
        *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + -1;
      }
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f3,0);
      if (cVar3 != '\0') {
        *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
      }
      *(int *)(param_1 + 0x34) = (*(int *)(param_1 + 0x34) + iVar10) % iVar10;
    }
    if (*(int *)(param_1 + 0x78) == 6) {
      if (*(longlong *)(param_1 + 200) == 0) goto code_r0x000180501987;
      ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c();
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f2,0);
      if (cVar3 != '\0') {
        *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;
      }
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f3,0);
      if (cVar3 != '\0') {
        *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
      }
      *(int *)(param_1 + 0x38) = (*(int *)(param_1 + 0x38) + iVar10) % iVar10;
    }
    if (*(int *)(param_1 + 0x78) == 7) {
      if (*(longlong *)(param_1 + 200) == 0) goto code_r0x000180501987;
      ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c();
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f2,0);
      if (cVar3 != '\0') {
        *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + -1;
      }
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar3 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f3,0);
      if (cVar3 != '\0') {
        *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
      }
      *(int *)(param_1 + 0x3c) = (*(int *)(param_1 + 0x3c) + iVar10) % iVar10;
    }
  }
  lVar4 = *(longlong *)(param_1 + 0x50);
  if ((*(longlong *)(param_1 + 200) != 0) && (lVar4 != 0)) {
    pcVar7 = DAT_182ec4fa8;
    if ((DAT_182ec4fa8 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.CanvasGroup::set_alpha(System.Single)"),
       pcVar7 == (code *)0x0)) {
      uVar8 = FUN_1802ced60("UnityEngine.CanvasGroup::set_alpha(System.Single)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar8,0);
    }
    DAT_182ec4fa8 = pcVar7;
    (*DAT_182ec4fa8)(lVar4);
    lVar4 = *(longlong *)(param_1 + 0x58);
    if ((*(longlong *)(param_1 + 0xd0) != 0) && (lVar4 != 0)) {
      pcVar7 = DAT_182ec4fa8;
      if ((DAT_182ec4fa8 == (code *)0x0) &&
         (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.CanvasGroup::set_alpha(System.Single)"),
         pcVar7 == (code *)0x0)) {
        uVar8 = FUN_1802ced60("UnityEngine.CanvasGroup::set_alpha(System.Single)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar8,0);
      }
      DAT_182ec4fa8 = pcVar7;
      (*DAT_182ec4fa8)(lVar4);
      lVar4 = *(longlong *)(param_1 + 0x60);
      if (lVar4 != 0) {
        if (*(int *)(lVar4 + 0x18) == 0) {
code_r0x0001805019ee:
                    /* WARNING: Subroutine does not return */
          FUN_18031dae0();
        }
        if (*(longlong *)(lVar4 + 0x20) != 0) {
          ExposureUnnoticed2_ObjectUI_InGame_RingMenu_ShortcutItemView__OnLateUpdate__06001adc
                    (*(longlong *)(lVar4 + 0x20),0);
          lVar4 = *(longlong *)(param_1 + 0x60);
          if (lVar4 != 0) {
            if (*(uint *)(lVar4 + 0x18) < 2) goto code_r0x0001805019ee;
            if (*(longlong *)(lVar4 + 0x28) != 0) {
              ExposureUnnoticed2_ObjectUI_InGame_RingMenu_ShortcutItemView__OnLateUpdate__06001adc
                        (*(longlong *)(lVar4 + 0x28),0);
              lVar4 = *(longlong *)(param_1 + 0x60);
              if (lVar4 != 0) {
                if (*(uint *)(lVar4 + 0x18) < 3) goto code_r0x0001805019ee;
                if (*(longlong *)(lVar4 + 0x30) != 0) {
                  ExposureUnnoticed2_ObjectUI_InGame_RingMenu_ShortcutItemView__OnLateUpdate__06001adc
                            (*(longlong *)(lVar4 + 0x30),0);
                  lVar4 = *(longlong *)(param_1 + 0x60);
                  if (lVar4 != 0) {
                    if (*(uint *)(lVar4 + 0x18) < 4) goto code_r0x0001805019ee;
                    if (*(longlong *)(lVar4 + 0x38) != 0) {
                      ExposureUnnoticed2_ObjectUI_InGame_RingMenu_ShortcutItemView__OnLateUpdate__06001adc
                                (*(longlong *)(lVar4 + 0x38),0);
                      lVar4 = *(longlong *)(param_1 + 0x60);
                      if (lVar4 != 0) {
                        if (*(uint *)(lVar4 + 0x18) < 5) goto code_r0x0001805019ee;
                        if (*(longlong *)(lVar4 + 0x40) != 0) {
                          ExposureUnnoticed2_ObjectUI_InGame_RingMenu_ShortcutItemView__OnLateUpdate__06001adc
                                    (*(longlong *)(lVar4 + 0x40),0);
                          lVar4 = *(longlong *)(param_1 + 0x60);
                          if (lVar4 != 0) {
                            if (*(uint *)(lVar4 + 0x18) < 6) goto code_r0x0001805019ee;
                            if (*(longlong *)(lVar4 + 0x48) != 0) {
                              ExposureUnnoticed2_ObjectUI_InGame_RingMenu_ShortcutItemView__OnLateUpdate__06001adc
                                        (*(longlong *)(lVar4 + 0x48),0);
                              lVar4 = *(longlong *)(param_1 + 0x60);
                              if (lVar4 != 0) {
                                if (*(uint *)(lVar4 + 0x18) < 7) goto code_r0x0001805019ee;
                                if (*(longlong *)(lVar4 + 0x50) != 0) {
                                  ExposureUnnoticed2_ObjectUI_InGame_RingMenu_ShortcutItemView__OnLateUpdate__06001adc
                                            (*(longlong *)(lVar4 + 0x50),0);
                                  lVar4 = *(longlong *)(param_1 + 0x60);
                                  if (lVar4 != 0) {
                                    if (*(uint *)(lVar4 + 0x18) < 8) goto code_r0x0001805019ee;
                                    if (*(longlong *)(lVar4 + 0x58) != 0) {
                                      ExposureUnnoticed2_ObjectUI_InGame_RingMenu_ShortcutItemView__OnLateUpdate__06001adc
                                                (*(longlong *)(lVar4 + 0x58),0);
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
  }
code_r0x000180501987:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

