// Ghidra pseudocode; not original source or compilable C.
// ev_00994d08f561742f6eed1f16b23856f0b4f5e10f1724e9b0d0f7768771b96834

void ExposureUnnoticed2_Object3D_Player_Scripts_Other_BodyPaintController__OnUpdate__06000e5b
               (longlong param_1)

{
  float fVar1;
  int iVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 uVar5;
  float fVar6;
  float fVar7;
  
  if (cRam0000000182eb7658 == '\0') {
    FUN_1802f2810(0x182d58330);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d58328);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d58320);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d58318);
    LOCK();
    UNLOCK();
    cRam0000000182eb7658 = '\x01';
  }
  if ((*(longlong *)(param_1 + 0x18) == 0) ||
     (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x60), lVar3 == 0))
  goto code_r0x0001803fd069;
  fVar7 = *(float *)(lVar3 + 0x58);
  if (fVar7 < 0.0) {
    fVar7 = 0.0;
  }
  else if (0.5 < fVar7) {
    fVar7 = 0.5;
  }
  lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar3 == 0) goto code_r0x0001803fd069;
  fVar1 = *(float *)(lVar3 + 0x17c);
  pcVar4 = DAT_182ec14d0;
  if ((DAT_182ec14d0 == (code *)0x0) &&
     (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"), pcVar4 == (code *)0x0)) {
    uVar5 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar5,0);
  }
  DAT_182ec14d0 = pcVar4;
  fVar6 = (float)(*DAT_182ec14d0)();
  *(float *)(lVar3 + 0x17c) = fVar1 - (fVar7 + fVar7) * fVar6;
  lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar3 == 0) goto code_r0x0001803fd069;
  fVar7 = 0.0;
  if (0.0 <= *(float *)(lVar3 + 0x17c)) {
    fVar7 = *(float *)(lVar3 + 0x17c);
  }
  *(float *)(lVar3 + 0x17c) = fVar7;
  iVar2 = *(int *)(param_1 + 0x20);
  if (iVar2 != 0) {
    if (iVar2 == 1) {
      if (*(longlong *)(param_1 + 0x10) == 0) goto code_r0x0001803fd069;
      ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c
                (*(longlong *)(param_1 + 0x10),0xbf800000,0);
      if (*(longlong *)(param_1 + 0x10) == 0) goto code_r0x0001803fd069;
      if (*(float *)(*(longlong *)(param_1 + 0x10) + 0x10) <= -1.0) {
        if ((*(longlong *)(param_1 + 0x18) == 0) ||
           (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x1b0), lVar3 == 0))
        goto code_r0x0001803fd069;
        ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyMaterialController__SetupBodyPaintFromGameState__06000cd7
                  (lVar3,0);
        *(undefined4 *)(param_1 + 0x20) = 0;
      }
    }
    else if (iVar2 == 2) {
      if (*(longlong *)(param_1 + 0x10) == 0) goto code_r0x0001803fd069;
      ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c
                (*(longlong *)(param_1 + 0x10),0x3ecccccd,0);
      lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar3 == 0) goto code_r0x0001803fd069;
      if (*(float *)(lVar3 + 0x17c) <= 60.0) {
        lVar3 = *(longlong *)(param_1 + 0x10);
        *(undefined4 *)(param_1 + 0x20) = 3;
        if (lVar3 == 0) goto code_r0x0001803fd069;
        *(undefined4 *)(lVar3 + 0x24) = 0x3e19999a;
        *(float *)(lVar3 + 0x14) = 0.15 / *(float *)(lVar3 + 0x28);
        *(float *)(lVar3 + 0x18) = 0.15 / *(float *)(lVar3 + 0x2c);
        uVar5 = uRam0000000182d58320;
code_r0x0001803fcdf9:
        uVar5 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar5,0);
        ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
                  (uVar5,0,0);
      }
    }
    else if (iVar2 == 3) {
      if (*(longlong *)(param_1 + 0x10) == 0) goto code_r0x0001803fd069;
      ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c
                (*(longlong *)(param_1 + 0x10),0x3e800000,0);
      lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar3 == 0) goto code_r0x0001803fd069;
      if (*(float *)(lVar3 + 0x17c) <= 24.0) {
        lVar3 = *(longlong *)(param_1 + 0x10);
        if (lVar3 == 0) goto code_r0x0001803fd069;
        *(undefined4 *)(lVar3 + 0x24) = 0x3e800000;
        *(float *)(lVar3 + 0x14) = 0.25 / *(float *)(lVar3 + 0x28);
        *(float *)(lVar3 + 0x18) = 0.25 / *(float *)(lVar3 + 0x2c);
        *(undefined4 *)(param_1 + 0x20) = 4;
        uVar5 = uRam0000000182d58328;
        goto code_r0x0001803fcdf9;
      }
    }
    else if (iVar2 == 4) {
      if (*(longlong *)(param_1 + 0x10) == 0) goto code_r0x0001803fd069;
      ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c
                (*(longlong *)(param_1 + 0x10),0,0);
      lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar3 == 0) goto code_r0x0001803fd069;
      if (*(float *)(lVar3 + 0x17c) <= 0.0) {
        lVar3 = *(longlong *)(param_1 + 0x10);
        if (lVar3 == 0) goto code_r0x0001803fd069;
        *(undefined4 *)(lVar3 + 0x24) = 0x3f800000;
        *(float *)(lVar3 + 0x14) = 1.0 / *(float *)(lVar3 + 0x28);
        *(float *)(lVar3 + 0x18) = 1.0 / *(float *)(lVar3 + 0x2c);
        uVar5 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d58318,0);
        ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
                  (uVar5,0,0);
        *(undefined4 *)(param_1 + 0x20) = 1;
        lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        if (lVar3 == 0) goto code_r0x0001803fd069;
        *(undefined1 *)(lVar3 + 0x1df) = 0;
      }
    }
  }
  if (*(int *)(param_1 + 0x20) == 0) {
    return;
  }
  if ((*(longlong *)(param_1 + 0x18) == 0) ||
     (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x1b0), lVar3 == 0))
  goto code_r0x0001803fd069;
  lVar3 = *(longlong *)(lVar3 + 0x28);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec12f4 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec12f4 = '\x01';
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
  if (lVar3 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar3 + 0x10) != 0) {
      if ((*(longlong *)(param_1 + 0x18) == 0) ||
         (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x1b0), lVar3 == 0))
      goto code_r0x0001803fd069;
      lVar3 = *(longlong *)(lVar3 + 0x28);
      if (*(int *)(lRam0000000182d58330 + 0xe0) == 0) {
        FUN_18035c820(lRam0000000182d58330);
      }
      if ((*(longlong *)(param_1 + 0x10) == 0) || (lVar3 == 0)) goto code_r0x0001803fd069;
      FUN_181f11120(lVar3,**(undefined4 **)(lRam0000000182d58330 + 0xb8),
                    *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x10),0);
    }
  }
  if ((*(longlong *)(param_1 + 0x18) != 0) &&
     (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x1d8), lVar3 != 0)) {
    lVar3 = *(longlong *)(lVar3 + 0xa8);
    if (*(int *)(lRam0000000182d58330 + 0xe0) == 0) {
      FUN_18035c820(lRam0000000182d58330);
    }
    if ((*(longlong *)(param_1 + 0x10) != 0) && (lVar3 != 0)) {
      FUN_181f11120(lVar3,**(undefined4 **)(lRam0000000182d58330 + 0xb8),
                    *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x10),0);
      if ((*(longlong *)(param_1 + 0x18) != 0) &&
         (((lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x1d8), lVar3 != 0 &&
           (*(longlong *)(param_1 + 0x10) != 0)) &&
          (lVar3 = *(longlong *)(lVar3 + 0xa0), lVar3 != 0)))) {
        FUN_181f11120(lVar3,**(undefined4 **)(lRam0000000182d58330 + 0xb8),
                      *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x10),0);
        return;
      }
    }
  }
code_r0x0001803fd069:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

