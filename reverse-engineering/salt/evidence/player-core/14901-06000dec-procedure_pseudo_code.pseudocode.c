// Ghidra pseudocode; not original source or compilable C.
// ev_10bca1df9bda56b3502e250cbb7d07e180795366593c350c7f31af2a5c8e887e

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerLocomotion__StateUpdate__06000dec
               (longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  byte bVar2;
  char cVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  code *pcVar7;
  ulonglong uVar8;
  uint uVar9;
  bool bVar10;
  
  if (cRam0000000182eb8422 == '\0') {
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    FUN_1802f2810();
    LOCK();
    UNLOCK();
    cRam0000000182eb8422 = '\x01';
  }
  if (*(longlong *)(param_1 + 0x68) == 0) goto code_r0x000180655154;
  *(undefined1 *)(*(longlong *)(param_1 + 0x68) + 0x19) = 0;
  if ((*(longlong *)(param_1 + 0x78) == 0) ||
     (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar5 == 0))
  goto code_r0x000180655154;
  if (*(char *)(lVar5 + 0x50) == '\0') {
    lVar5 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60) + 0x48);
    if (lVar5 == 0) goto code_r0x000180655154;
    bVar10 = *(int *)(lVar5 + 0x18) == -1;
  }
  else {
    bVar10 = false;
  }
  if (param_2 == 0) goto code_r0x000180655154;
  if (*(char *)(param_2 + 0x26) == '\0') {
    bVar2 = 0;
  }
  else {
    bVar2 = 1;
    if (*(float *)(param_2 + 0x14) * *(float *)(param_2 + 0x14) +
        *(float *)(param_2 + 0x10) * *(float *)(param_2 + 0x10) +
        *(float *)(param_2 + 0x18) * *(float *)(param_2 + 0x18) <= 0.0) {
      bVar2 = *(byte *)(param_2 + 0x28);
    }
  }
  if (((bVar10 & bVar2) == 0) || (*(char *)(param_1 + 0x71) != '\0')) {
    if (*(char *)(param_2 + 0x27) != '\0') {
      if (*(char *)(*(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60) + 0x1b) == '\0') {
        lVar5 = **(longlong **)(DAT_182d58230 + 0xb8);
        if (lVar5 == 0) goto code_r0x000180655154;
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
        cVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsAttachSomeHandcuffs__0600155d
                          (0);
        uVar6 = DAT_182d3e660;
        if (cVar3 == '\0') {
          if ((*(longlong *)(lVar5 + 0x10) == 0) ||
             (lVar4 = *(longlong *)(*(longlong *)(lVar5 + 0x10) + 0x60), lVar4 == 0))
          goto code_r0x000180655154;
          uVar6 = DAT_182d3e668;
          if (*(char *)(lVar4 + 0x1b) == '\0') {
            if (*(longlong *)(lVar4 + 0x48) == 0) goto code_r0x000180655154;
            uVar6 = DAT_182d5e118;
            if (((*(int *)(*(longlong *)(lVar4 + 0x48) + 0x18) == -1) &&
                (lVar5 = *(longlong *)(*(longlong *)(lVar5 + 0x10) + 0x60),
                *(int *)(lVar5 + 0x5c) == 0)) && (*(char *)(lVar5 + 0x50) == '\0')) {
              lVar5 = FUN_180436330();
              if (lVar5 == 0) goto code_r0x000180655154;
              uVar6 = DAT_182d5e118;
              if (*(char *)(lVar5 + 0x10) == '\0') goto code_r0x000180654ef7;
            }
          }
        }
        uVar6 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar6,0);
        ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
                  (uVar6,0,0);
      }
      else {
code_r0x000180654ef7:
        lVar5 = *(longlong *)(param_1 + 0x68);
        if (lVar5 == 0) goto code_r0x000180655154;
        *(bool *)(lVar5 + 0x1b) = *(char *)(lVar5 + 0x1b) == '\0';
      }
    }
  }
  else {
    if (*(longlong *)(param_1 + 0x78) == 0) goto code_r0x000180655154;
    lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0xd0);
    lVar4 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
    if ((lVar4 == 0) || (lVar5 == 0)) goto code_r0x000180655154;
    if (0.0 < *(float *)(lVar5 + 0x10)) {
      if (*(longlong *)(param_1 + 0x68) == 0) goto code_r0x000180655154;
      *(undefined1 *)(*(longlong *)(param_1 + 0x68) + 0x19) = 1;
      if (*(longlong *)(param_1 + 0x68) == 0) goto code_r0x000180655154;
      *(undefined1 *)(*(longlong *)(param_1 + 0x68) + 0x1b) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x71) = 1;
      if (*(char *)(param_1 + 0x70) == '\0') {
        *(undefined1 *)(param_1 + 0x70) = 1;
      }
    }
  }
  if (*(char *)(param_2 + 0x26) == '\0') {
    *(undefined2 *)(param_1 + 0x70) = 0;
  }
  lVar5 = *(longlong *)(param_1 + 0x78);
  if ((lVar5 == 0) || (*(longlong *)(lVar5 + 0x60) == 0)) goto code_r0x000180655154;
  if (*(char *)(*(longlong *)(lVar5 + 0x60) + 0x1b0) == '\0') {
    if (*(char *)(param_2 + 0x34) != '\0') {
      if ((*(longlong *)(param_1 + 0x68) == 0) ||
         (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x68) + 0x48), lVar5 == 0))
      goto code_r0x000180655154;
      if ((*(char *)(lVar5 + 0x1c) == '\0') || (*(char *)(lVar5 + 0x1e) != '\0')) {
        uVar6 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(DAT_182d5e118,0);
        ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
                  (uVar6,0,0);
      }
      else {
        lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0xd8);
        if (lVar5 == 0) goto code_r0x000180655154;
        FUN_181f390f0(lVar5,1,0);
        if ((*(longlong *)(param_1 + 0x78) == 0) ||
           (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar5 == 0))
        goto code_r0x000180655154;
        *(undefined1 *)(lVar5 + 0x1b0) = 1;
        if ((*(longlong *)(param_1 + 0x78) == 0) ||
           (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar5 == 0))
        goto code_r0x000180655154;
        *(undefined1 *)(lVar5 + 0x1b1) = 0;
      }
    }
  }
  else if ((((*(char *)(param_2 + 0x2e) != '\0') || (*(char *)(param_2 + 0x26) != '\0')) ||
           (*(char *)(param_2 + 0x34) != '\0')) || (*(char *)(param_2 + 0x30) != '\0')) {
    if ((lVar5 == 0) || (lVar5 = *(longlong *)(lVar5 + 0xd8), lVar5 == 0))
    goto code_r0x000180655154;
    pcVar7 = DAT_182ec1060;
    if ((DAT_182ec1060 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Behaviour::set_enabled(System.Boolean)"),
       pcVar7 == (code *)0x0)) {
      uVar6 = FUN_1802ced60("UnityEngine.Behaviour::set_enabled(System.Boolean)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar6,0);
    }
    DAT_182ec1060 = pcVar7;
    (*DAT_182ec1060)(lVar5,0);
    if ((*(longlong *)(param_1 + 0x78) == 0) ||
       (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar5 == 0))
    goto code_r0x000180655154;
    *(undefined1 *)(lVar5 + 0x1b0) = 0;
    lVar5 = *(longlong *)(param_1 + 0x68);
    if (lVar5 == 0) goto code_r0x000180655154;
    bVar10 = DAT_182eb5d50 != 0;
    *(undefined8 *)(lVar5 + 0x30) = 0;
    if (bVar10) {
      uVar9 = (uint)(lVar5 + 0x30U >> 0xc);
      uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
        LOCK();
        bVar10 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
        if (bVar10) {
          *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar1 | 1L << (uVar9 & 0x3f);
        }
        UNLOCK();
      } while (!bVar10);
    }
  }
  lVar5 = *(longlong *)(param_1 + 0x78);
  if ((lVar5 != 0) && (lVar4 = *(longlong *)(lVar5 + 0x60), lVar4 != 0)) {
    if (*(char *)(lVar4 + 0x1b1) == '\0') {
      if (*(char *)(param_2 + 0x35) != '\0') {
        *(undefined1 *)(lVar4 + 0x1b1) = 1;
        if ((*(longlong *)(param_1 + 0x78) == 0) ||
           (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar5 == 0))
        goto code_r0x000180655154;
        *(undefined1 *)(lVar5 + 0x1b0) = 0;
      }
    }
    else if ((((*(char *)(param_2 + 0x2e) != '\0') || (*(char *)(param_2 + 0x26) != '\0')) ||
             (*(char *)(param_2 + 0x35) != '\0')) || (*(char *)(param_2 + 0x30) != '\0')) {
      if ((lVar5 == 0) || (lVar4 == 0)) goto code_r0x000180655154;
      *(undefined1 *)(lVar4 + 0x1b1) = 0;
    }
    return;
  }
code_r0x000180655154:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

