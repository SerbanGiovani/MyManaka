// Ghidra pseudocode; not original source or compilable C.
// ev_7eea8ab01043ac94b003af7448fba280b7a09a077b1d05c5e50c6f350e54964b

void ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__OnLateUpdate__0600119b
               (longlong param_1)

{
  undefined4 uVar1;
  undefined1 auVar2 [16];
  undefined1 uVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  char cVar14;
  code *pcVar15;
  longlong *plVar16;
  undefined4 *puVar17;
  float *pfVar18;
  longlong lVar19;
  undefined8 uVar20;
  ulonglong uVar21;
  uint uVar22;
  bool bVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  ulonglong in_stack_ffffffffffffff38;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  
  if (cRam0000000182eb77ed == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aa80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aa78);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aa68);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa60);
    LOCK();
    UNLOCK();
    cRam0000000182eb77ed = '\x01';
  }
  **(undefined1 **)(lRam0000000182d5aa78 + 0xb8) = 0;
  uStack_58 = 0;
  uStack_50 = 0;
  uStack_48 = 0;
  uStack_40 = 0;
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
     (lVar19 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar19 == 0))
  goto code_r0x000180456bef;
  if ((*(char *)(lVar19 + 0x11) != '\0') && (*(char *)(param_1 + 0x180) == '\0')) {
    *(undefined1 *)(param_1 + 0x180) = 1;
    if (*(longlong *)(param_1 + 0x188) == 0) goto code_r0x000180456bef;
    *(undefined4 *)(*(longlong *)(param_1 + 0x188) + 0x1c) = 0;
  }
  if (*(longlong *)(param_1 + 0x188) == 0) goto code_r0x000180456bef;
  ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c();
  lVar19 = *(longlong *)(param_1 + 200);
  if ((*(longlong *)(param_1 + 0x188) == 0) || (lVar19 == 0)) goto code_r0x000180456bef;
  pcVar15 = DAT_182ec4fa8;
  if ((DAT_182ec4fa8 == (code *)0x0) &&
     (pcVar15 = (code *)FUN_1802cf0c0("UnityEngine.CanvasGroup::set_alpha(System.Single)"),
     pcVar15 == (code *)0x0)) {
    uVar20 = FUN_1802ced60("UnityEngine.CanvasGroup::set_alpha(System.Single)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar20,0);
  }
  DAT_182ec4fa8 = pcVar15;
  (*DAT_182ec4fa8)(lVar19);
  if ((((*(longlong *)(param_1 + 0x168) == 0) ||
       (lVar19 = *(longlong *)(*(longlong *)(param_1 + 0x168) + 0x40), lVar19 == 0)) ||
      (lVar19 = *(longlong *)(lVar19 + 0xd0), lVar19 == 0)) || (*(longlong *)(param_1 + 0x28) == 0))
  goto code_r0x000180456bef;
  Common_CommonUI_CommonGauge_GaugeView__SetMax__06001e4c(*(longlong *)(param_1 + 0x28),lVar19,0);
  if ((((*(longlong *)(param_1 + 0x168) == 0) ||
       (lVar19 = *(longlong *)(*(longlong *)(param_1 + 0x168) + 0x40), lVar19 == 0)) ||
      ((lVar19 = *(longlong *)(lVar19 + 0xd0), lVar19 == 0 ||
       ((*(longlong *)(param_1 + 0x28) == 0 ||
        (Common_CommonUI_CommonGauge_GaugeView__Set__06001e4d
                   (*(longlong *)(param_1 + 0x28),lVar19,0),
        *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48) == 0)))))) ||
     (*(longlong *)(param_1 + 0x30) == 0)) goto code_r0x000180456bef;
  Common_CommonUI_CommonGauge_GaugeFillView__Set__06001e47();
  if ((((((*(longlong *)(param_1 + 0x168) == 0) ||
         (lVar19 = *(longlong *)(*(longlong *)(param_1 + 0x168) + 0x40), lVar19 == 0)) ||
        (lVar19 = *(longlong *)(lVar19 + 200), lVar19 == 0)) ||
       ((*(longlong *)(param_1 + 0x38) == 0 ||
        (Common_CommonUI_CommonGauge_GaugeView__SetMax__06001e4c
                   (*(longlong *)(param_1 + 0x38),lVar19,0),
        *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48) == 0)))) ||
      (((*(longlong *)(param_1 + 0x38) == 0 ||
        ((Common_CommonUI_CommonGauge_GaugeView__Set__06001e4d(),
         *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48) == 0 ||
         (*(longlong *)(param_1 + 0x40) == 0)))) ||
       (Common_CommonUI_CommonGauge_GaugeView__Set__06001e4d(),
       *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48) == 0)))) ||
     (*(longlong *)(param_1 + 0x50) == 0)) goto code_r0x000180456bef;
  FUN_182038510();
  if (*(longlong *)(param_1 + 0x58) == 0) goto code_r0x000180456bef;
  ExposureUnnoticed2_ObjectUI_InteractPanel_InteractPanelView__OnLateUpdate__06001a67
            (*(longlong *)(param_1 + 0x58),0);
  if (*(longlong *)(param_1 + 0x60) == 0) goto code_r0x000180456bef;
  ExposureUnnoticed2_ObjectUI_InGame_HeatBeatPanel_HeartRatePanelView__OnLateUpdate__06001b1f
            (*(longlong *)(param_1 + 0x60),0);
  if (*(longlong *)(param_1 + 0x78) == 0) goto code_r0x000180456bef;
  ExposureUnnoticed2_ObjectUI_InGame_TempUnlockPanel_TempUnlockPanelView__OnLateUpdate__06001a75
            (*(longlong *)(param_1 + 0x78),0);
  if (*(longlong *)(param_1 + 0x70) == 0) goto code_r0x000180456bef;
  ExposureUnnoticed2_ObjectUI_InGame_MissionPanel_MissionPanelView__OnLateUpdate__06001b04
            (*(longlong *)(param_1 + 0x70),0);
  if (*(longlong *)(param_1 + 0xe8) == 0) goto code_r0x000180456bef;
  ExposureUnnoticed2_ObjectUI_InGame_MotionSpeedPanel_MotionSpeedPanelView__OnLateUpdate__06001aeb
            (*(longlong *)(param_1 + 0xe8),0);
  if (*(longlong *)(param_1 + 0xf0) == 0) goto code_r0x000180456bef;
  ExposureUnnoticed2_ObjectUI_InGame_MotionSpeedPanel_WalkSpeedPanelView__OnLateUpdate__06001af0
            (*(longlong *)(param_1 + 0xf0),0);
  lVar19 = *(longlong *)(param_1 + 0x118);
  if (lVar19 == 0) goto code_r0x000180456bef;
  if (cRam0000000182eb7c9a == '\0') {
    FUN_1802f2810(0x182d5c7e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c9a = '\x01';
  }
  iVar4 = *(int *)(lVar19 + 0x30);
  if (*(int *)(lRam0000000182d5c7e8 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5c7e8);
  }
  if (iVar4 == *(int *)(*(longlong *)(lRam0000000182d5c7e8 + 0xb8) + 8)) {
    if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
        (lVar5 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar5 == 0)) ||
       (lVar5 = *(longlong *)(lVar5 + 0x1f0), lVar5 == 0)) goto code_r0x000180456bef;
    if (*(int *)(lVar5 + 0x5c) != *(int *)(lVar19 + 0x34)) goto code_r0x000180455c39;
  }
  else {
code_r0x000180455c39:
    ExposureUnnoticed2_ObjectUI_InGame_VIbeStatePanel_VibeStatePanelView__Refresh__06001a71
              (lVar19,0);
  }
  if (*(longlong *)(param_1 + 0x120) == 0) goto code_r0x000180456bef;
  ExposureUnnoticed2_ObjectUI_InGame_IngameUiManualView__OnUpdate__06001a6b
            (*(longlong *)(param_1 + 0x120),0);
  lVar19 = *(longlong *)(param_1 + 0x150);
  if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
      (lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar5 == 0)) ||
     (uVar3 = *(undefined1 *)(lVar5 + 0x4c), lVar19 == 0)) goto code_r0x000180456bef;
  pcVar15 = DAT_182ec1138;
  if ((DAT_182ec1138 == (code *)0x0) &&
     (pcVar15 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
     pcVar15 == (code *)0x0)) {
    uVar20 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar20,0);
  }
  DAT_182ec1138 = pcVar15;
  (*DAT_182ec1138)(lVar19,uVar3);
  if ((((*(longlong *)(param_1 + 0x168) == 0) ||
       (lVar19 = *(longlong *)(*(longlong *)(param_1 + 0x168) + 0x40), lVar19 == 0)) ||
      (*(longlong *)(lVar19 + 0x60) == 0)) || (*(longlong *)(param_1 + 0x98) == 0))
  goto code_r0x000180456bef;
  in_stack_ffffffffffffff38 = in_stack_ffffffffffffff38 & 0xffffffff00000000;
  FUN_181d7c660(*(longlong *)(param_1 + 0x98),DAT_182d5aa60);
  if (((*(longlong *)(param_1 + 0x168) == 0) ||
      (lVar19 = *(longlong *)(*(longlong *)(param_1 + 0x168) + 0x40), lVar19 == 0)) ||
     (*(longlong *)(lVar19 + 0x60) == 0)) goto code_r0x000180456bef;
  plVar16 = (longlong *)
            ExposureUnnoticed2_ObjectUI_Misc_RpBonusColorSelector__GetTextColorSecondary__06001965
                      (&uStack_88);
  lVar19 = *plVar16;
  lVar5 = plVar16[1];
  if (((*(longlong *)(param_1 + 0x168) == 0) ||
      (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x168) + 0x40), lVar6 == 0)) ||
     (*(longlong *)(lVar6 + 0x60) == 0)) goto code_r0x000180456bef;
  puVar17 = (undefined4 *)
            ExposureUnnoticed2_ObjectUI_Misc_RpBonusColorSelector__GetTextColor__06001964
                      (&uStack_88);
  plVar16 = *(longlong **)(param_1 + 0x98);
  uVar1 = *puVar17;
  uVar8 = puVar17[1];
  uVar9 = puVar17[2];
  uVar10 = puVar17[3];
  if (plVar16 == (longlong *)0x0) goto code_r0x000180456bef;
  plVar16[0x2e] = lVar19;
  plVar16[0x2f] = lVar5;
  *(undefined1 *)(plVar16 + 0x6f) = 1;
  plVar16[0x30] = lVar19;
  plVar16[0x31] = lVar5;
  *(undefined4 *)(plVar16 + 0x32) = uVar1;
  *(undefined4 *)((longlong)plVar16 + 0x194) = uVar8;
  *(undefined4 *)(plVar16 + 0x33) = uVar9;
  *(undefined4 *)((longlong)plVar16 + 0x19c) = uVar10;
  *(undefined4 *)(plVar16 + 0x34) = uVar1;
  *(undefined4 *)((longlong)plVar16 + 0x1a4) = uVar8;
  *(undefined4 *)(plVar16 + 0x35) = uVar9;
  *(undefined4 *)((longlong)plVar16 + 0x1ac) = uVar10;
  (**(code **)(*plVar16 + 0x2f8))(plVar16,*(undefined8 *)(*plVar16 + 0x300));
  if (((*(longlong *)(param_1 + 0x168) == 0) ||
      (lVar19 = *(longlong *)(*(longlong *)(param_1 + 0x168) + 0x40), lVar19 == 0)) ||
     (*(longlong *)(lVar19 + 0x60) == 0)) goto code_r0x000180456bef;
  pfVar18 = (float *)ExposureUnnoticed2_ObjectUI_Misc_RpBonusColorSelector__GetTextColorSecondary__06001965
                               (&uStack_88);
  lVar19 = *(longlong *)(param_1 + 0x148);
  fVar24 = *pfVar18;
  fVar11 = pfVar18[1];
  fVar12 = pfVar18[2];
  fVar13 = pfVar18[3];
  if (lVar19 == 0) goto code_r0x000180456bef;
  pcVar15 = DAT_182ec1088;
  if ((DAT_182ec1088 == (code *)0x0) &&
     (pcVar15 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
     pcVar15 == (code *)0x0)) {
    uVar20 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar20,0);
  }
  DAT_182ec1088 = pcVar15;
  lVar19 = (*DAT_182ec1088)(lVar19);
  if (((*(longlong *)(param_1 + 0x168) == 0) ||
      (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x168) + 0x40), lVar5 == 0)) ||
     ((lVar5 = *(longlong *)(lVar5 + 0x60), lVar5 == 0 || (lVar19 == 0))))
  goto code_r0x000180456bef;
  fVar25 = *(float *)(lVar5 + 0xe8);
  pcVar15 = DAT_182ec1138;
  if ((DAT_182ec1138 == (code *)0x0) &&
     (pcVar15 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
     pcVar15 == (code *)0x0)) {
    uVar20 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar20,0);
  }
  DAT_182ec1138 = pcVar15;
  (*DAT_182ec1138)(lVar19,1.5 <= fVar25);
  auVar2 = *(undefined1 (*) [16])(param_1 + 0x1a8);
  fVar26 = auVar2._0_4_ - fVar24;
  fVar27 = auVar2._4_4_ - fVar11;
  fVar25 = auVar2._8_4_ - fVar12;
  fVar28 = auVar2._12_4_ - fVar13;
  if (9.9999994e-11 <= fVar27 * fVar27 + fVar26 * fVar26 + fVar25 * fVar25 + fVar28 * fVar28) {
    lVar19 = *(longlong *)(param_1 + 0x148);
    *(float *)(param_1 + 0x1a8) = fVar24;
    *(float *)(param_1 + 0x1ac) = fVar11;
    *(float *)(param_1 + 0x1b0) = fVar12;
    *(float *)(param_1 + 0x1b4) = fVar13;
    if (((*(longlong *)(param_1 + 0x168) == 0) ||
        (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x168) + 0x40), lVar5 == 0)) ||
       (*(longlong *)(lVar5 + 0x60) == 0)) goto code_r0x000180456bef;
    puVar17 = (undefined4 *)
              ExposureUnnoticed2_ObjectUI_Misc_RpBonusColorSelector__GetTextColor__06001964
                        (&uStack_88);
    uVar1 = puVar17[1];
    uVar8 = puVar17[2];
    uVar9 = puVar17[3];
    if (lVar19 == 0) goto code_r0x000180456bef;
    *(undefined4 *)(lVar19 + 0x28) = *puVar17;
    *(undefined4 *)(lVar19 + 0x2c) = uVar1;
    *(undefined4 *)(lVar19 + 0x30) = uVar8;
    *(undefined4 *)(lVar19 + 0x34) = uVar9;
    lVar19 = *(longlong *)(param_1 + 0x148);
    if (lVar19 == 0) goto code_r0x000180456bef;
    *(float *)(lVar19 + 0x38) = fVar24;
    *(float *)(lVar19 + 0x3c) = fVar11;
    *(float *)(lVar19 + 0x40) = fVar12;
    *(float *)(lVar19 + 0x44) = fVar13;
    lVar19 = *(longlong *)(param_1 + 0x148);
    if (lVar19 == 0) goto code_r0x000180456bef;
    pcVar15 = DAT_182ec1060;
    if ((DAT_182ec1060 == (code *)0x0) &&
       (pcVar15 = (code *)FUN_1802cf0c0("UnityEngine.Behaviour::set_enabled(System.Boolean)"),
       pcVar15 == (code *)0x0)) {
      uVar20 = FUN_1802ced60("UnityEngine.Behaviour::set_enabled(System.Boolean)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar20,0);
    }
    DAT_182ec1060 = pcVar15;
    (*DAT_182ec1060)(lVar19,0);
    lVar19 = *(longlong *)(param_1 + 0x148);
    if (lVar19 == 0) goto code_r0x000180456bef;
    pcVar15 = DAT_182ec1060;
    if ((DAT_182ec1060 == (code *)0x0) &&
       (pcVar15 = (code *)FUN_1802cf0c0("UnityEngine.Behaviour::set_enabled(System.Boolean)"),
       pcVar15 == (code *)0x0)) {
      uVar20 = FUN_1802ced60("UnityEngine.Behaviour::set_enabled(System.Boolean)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar20,0);
    }
    DAT_182ec1060 = pcVar15;
    (*DAT_182ec1060)(lVar19,1);
  }
  lVar19 = *(longlong *)(param_1 + 0xa0);
  if ((((*(longlong *)(param_1 + 0x168) == 0) ||
       (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x168) + 0x40), lVar5 == 0)) ||
      (*(longlong *)(lVar5 + 0x60) == 0)) || (lVar19 == 0)) goto code_r0x000180456bef;
  FUN_181d7c660(lVar19,uRam0000000182d5aa68,lVar19,0,in_stack_ffffffffffffff38 & 0xffffffff00000000,
                0,0,0,0,0,0);
  if (DAT_182eb548c == '\0') {
    FUN_1802f2810(&DAT_182d57a70);
    LOCK();
    UNLOCK();
    DAT_182eb548c = '\x01';
  }
  if (**(longlong **)(DAT_182d57a70 + 0xb8) == 0) goto code_r0x000180456bef;
  if (*(char *)(**(longlong **)(DAT_182d57a70 + 0xb8) + 0x5a) == '\0') {
code_r0x0001804561cd:
    if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
       (lVar19 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar19 == 0))
    goto code_r0x000180456bef;
    if (*(char *)(lVar19 + 0x11) == '\0') {
      if ((*(char *)(param_1 + 0x22) == '\0') && (*(char *)(param_1 + 0x21) == '\0'))
      goto code_r0x0001804562e0;
      if (DAT_182eb5493 == '\0') {
        FUN_1802f2810(&DAT_182d592c0);
        LOCK();
        UNLOCK();
        DAT_182eb5493 = '\x01';
      }
      if (**(longlong **)(DAT_182d592c0 + 0xb8) == 0) goto code_r0x000180456bef;
      if (*(char *)(**(longlong **)(DAT_182d592c0 + 0xb8) + 0x10) != '\0') {
        lVar19 = FUN_180458b60();
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
        if (lVar19 != 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (*(longlong *)(lVar19 + 0x10) != 0) goto code_r0x000180456473;
        }
code_r0x0001804562e0:
        if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
          FUN_18035c820();
        }
        cVar14 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x10,0);
        if (cVar14 != '\0') {
          fVar24 = (float)FUN_181dc1970(0);
          if (*(int *)(DAT_182d5aa90 + 0xe0) == 0) {
            FUN_18035c820(DAT_182d5aa90);
          }
          if (0.5 <= fVar24 - *(float *)(*(longlong *)(DAT_182d5aa90 + 0xb8) + 8)) {
            if (cRam0000000182eb7b16 == '\0') {
              FUN_1802f2810(&DAT_182d58368);
              LOCK();
              UNLOCK();
              FUN_1802f2810(0x182d5f220);
              LOCK();
              UNLOCK();
              FUN_1802f2810(0x182d5f260);
              LOCK();
              UNLOCK();
              cRam0000000182eb7b16 = '\x01';
            }
            if (*(int *)(lRam0000000182d5f260 + 0xe0) == 0) {
              FUN_18035c820();
            }
            lVar19 = *(longlong *)(*(longlong *)(lRam0000000182d5f260 + 0xb8) + 0x40);
            if (lVar19 == 0) {
              if (*(int *)(lRam0000000182d5f260 + 0xe0) == 0) {
                FUN_18035c820();
              }
              uVar20 = **(undefined8 **)(lRam0000000182d5f260 + 0xb8);
              lVar19 = FUN_1802c43a0(DAT_182d58368);
              FUN_1814df680(lVar19,uVar20,uRam0000000182d5f220,0);
              *(longlong *)(*(longlong *)(lRam0000000182d5f260 + 0xb8) + 0x40) = lVar19;
              if (DAT_182eb5d50 != 0) {
                uVar22 = (uint)(*(longlong *)(lRam0000000182d5f260 + 0xb8) + 0x40U >> 0xc);
                uVar21 = (ulonglong)((uVar22 & 0x1fffff) >> 6);
                do {
                  uVar7 = *(ulonglong *)(&DAT_182f0c920 + uVar21 * 8);
                  LOCK();
                  bVar23 = uVar7 == *(ulonglong *)(&DAT_182f0c920 + uVar21 * 8);
                  if (bVar23) {
                    *(ulonglong *)(&DAT_182f0c920 + uVar21 * 8) = uVar7 | 1L << (uVar22 & 0x3f);
                  }
                  UNLOCK();
                } while (!bVar23);
              }
            }
            ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b(lVar19,1,0);
          }
        }
      }
    }
  }
  else {
    if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x000180456bef;
    cVar14 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525
                       (0x15,0);
    if ((cVar14 != '\0') ||
       (cVar14 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525
                           (0x16,0), cVar14 != '\0')) goto code_r0x0001804561cd;
    if (DAT_182eb5493 == '\0') {
      FUN_1802f2810(&DAT_182d592c0);
      LOCK();
      UNLOCK();
      DAT_182eb5493 = '\x01';
    }
    if (**(longlong **)(DAT_182d592c0 + 0xb8) == 0) goto code_r0x000180456bef;
    if (*(char *)(**(longlong **)(DAT_182d592c0 + 0xb8) + 0x10) != '\0') goto code_r0x0001804561cd;
  }
code_r0x000180456473:
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
     (lVar19 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar19 == 0))
  goto code_r0x000180456bef;
  if ((*(char *)(lVar19 + 0x11) == '\0') &&
     ((*(char *)(param_1 + 0x22) == '\0' && (*(char *)(param_1 + 0x21) == '\0')))) {
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
    cVar14 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(2,0);
    if (cVar14 == '\0') {
code_r0x0001804565ac:
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar14 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f1,0);
      if (cVar14 == '\0') {
code_r0x0001804566ce:
        if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
          FUN_18035c820();
        }
        cVar14 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f0,0);
        if (cVar14 == '\0') {
code_r0x0001804567c9:
          if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
            FUN_18035c820();
          }
          cVar14 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f7,0);
          if (cVar14 == '\0') {
code_r0x0001804568c7:
            if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
              FUN_18035c820();
            }
            cVar14 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f5,0);
            if (cVar14 == '\0') {
code_r0x0001804569c5:
              if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
                FUN_18035c820();
              }
              cVar14 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0x3f6,0);
              if (cVar14 == '\0') goto code_r0x000180456ac8;
              lVar19 = **(longlong **)(lRam0000000182d5aa80 + 0xb8);
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
              if (lVar19 != 0) {
                if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                if (*(longlong *)(lVar19 + 0x10) != 0) goto code_r0x000180456ac8;
              }
              if (**(longlong **)(DAT_182d5aa70 + 0xb8) == 0) goto code_r0x000180456bef;
              ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
                        (**(longlong **)(DAT_182d5aa70 + 0xb8),0x31);
              uVar20 = 3;
            }
            else {
              lVar19 = **(longlong **)(lRam0000000182d5aa80 + 0xb8);
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
              if (lVar19 != 0) {
                if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                if (*(longlong *)(lVar19 + 0x10) != 0) goto code_r0x0001804569c5;
              }
              if (**(longlong **)(DAT_182d5aa70 + 0xb8) == 0) goto code_r0x000180456bef;
              ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
                        (**(longlong **)(DAT_182d5aa70 + 0xb8),0x31);
              uVar20 = 2;
            }
          }
          else {
            lVar19 = **(longlong **)(lRam0000000182d5aa80 + 0xb8);
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
            if (lVar19 != 0) {
              if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                FUN_18035c820();
              }
              if (*(longlong *)(lVar19 + 0x10) != 0) goto code_r0x0001804568c7;
            }
            if (**(longlong **)(DAT_182d5aa70 + 0xb8) == 0) goto code_r0x000180456bef;
            ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
                      (**(longlong **)(DAT_182d5aa70 + 0xb8),0x31);
            uVar20 = 1;
          }
        }
        else {
          lVar19 = **(longlong **)(lRam0000000182d5aa80 + 0xb8);
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
          if (lVar19 != 0) {
            if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            if (*(longlong *)(lVar19 + 0x10) != 0) goto code_r0x0001804567c9;
          }
          if (**(longlong **)(DAT_182d5aa70 + 0xb8) == 0) goto code_r0x000180456bef;
          ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
                    (**(longlong **)(DAT_182d5aa70 + 0xb8),0x31);
          uVar20 = 0;
        }
        ExposureUnnoticed2_ObjectUI_InventoryPanel_InventoryPanelView__Open__060019fa(0,uVar20,0);
      }
      else {
        if (cRam0000000182eb77fc == '\0') {
          FUN_1802f2810(&DAT_182d5a8c0);
          LOCK();
          UNLOCK();
          cRam0000000182eb77fc = '\x01';
        }
        lVar19 = **(longlong **)(DAT_182d5a8c0 + 0xb8);
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
        if (lVar19 != 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (*(longlong *)(lVar19 + 0x10) != 0) goto code_r0x0001804566ce;
        }
        if (**(longlong **)(DAT_182d5aa70 + 0xb8) == 0) goto code_r0x000180456bef;
        ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
                  (**(longlong **)(DAT_182d5aa70 + 0xb8),0x31);
        ExposureUnnoticed2_ObjectUI_MissionMenuPanel_MissionMenuPanelView__Open__0600194a(0,0);
      }
    }
    else {
      if (*(int *)(DAT_182d5aa90 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar19 = **(longlong **)(DAT_182d5aa90 + 0xb8);
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
      if (lVar19 != 0) {
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (*(longlong *)(lVar19 + 0x10) != 0) goto code_r0x0001804565ac;
      }
      if (*(int *)(DAT_182d5aa90 + 0xe0) == 0) {
        FUN_18035c820();
      }
      ExposureUnnoticed2_ObjectUI_InGameMenu_InGameMenuView__Open__06001a43(0);
    }
  }
code_r0x000180456ac8:
  if ((*(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48) != 0) &&
     (*(longlong *)(param_1 + 400) != 0)) {
    ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c();
    plVar16 = *(longlong **)(param_1 + 0xf8);
    if (plVar16 != (longlong *)0x0) {
      puVar17 = (undefined4 *)
                (**(code **)(*plVar16 + 0x298))
                          (&uStack_88,plVar16,*(undefined8 *)(*plVar16 + 0x2a0));
      uStack_88 = *puVar17;
      uStack_84 = puVar17[1];
      uStack_80 = puVar17[2];
      if (*(longlong *)(param_1 + 400) != 0) {
        uVar1 = *(undefined4 *)(*(longlong *)(param_1 + 400) + 0x10);
        if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uStack_7c = uVar1;
        (**(code **)(*plVar16 + 0x2a8))(plVar16,&uStack_88,*(undefined8 *)(*plVar16 + 0x2b0));
        return;
      }
    }
  }
code_r0x000180456bef:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

