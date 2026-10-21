// Ghidra pseudocode; not original source or compilable C.
// ev_9d868a9395c91fc6621f59c8b3ac2523b8c03f487c9d0773905b535c9095f7b5

void ExposureUnnoticed2_Object3D_NPC_Script_NpcController__OnUpdate__0600105b(longlong param_1)

{
  undefined1 uVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  byte bVar5;
  code *pcVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  if (cRam0000000182eb775d == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb775d = '\x01';
  }
  if ((*(longlong *)(param_1 + 0x30) == 0) ||
     (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x40), lVar7 == 0))
  goto code_r0x0001804293f9;
  if (*(char *)(lVar7 + 0x21) != '\0') {
    return;
  }
  *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
  if (cRam0000000182eb778b == '\0') {
    FUN_1802f2810(&DAT_182d59280);
    LOCK();
    UNLOCK();
    cRam0000000182eb778b = '\x01';
  }
  lVar7 = **(longlong **)(DAT_182d59280 + 0xb8);
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
  if (lVar7 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar7 + 0x10) != 0) {
      lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar7 == 0) goto code_r0x0001804293f9;
      if ((*(int *)(lVar7 + 0x10) == 0xb) && (*(char *)(lVar7 + 0x20) != '\0')) {
        if ((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
           (((lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 == 0 ||
             (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 == 0)) ||
            (lVar3 = *(longlong *)(param_1 + 0x48), lVar3 == 0)))) goto code_r0x0001804293f9;
        uStack_58 = *(undefined8 *)(lVar3 + 0xdc);
        fVar11 = (float)*(undefined8 *)(lVar7 + 0x264) - (float)uStack_58;
        fVar10 = *(float *)(lVar7 + 0x26c) - *(float *)(lVar3 + 0xe4);
        fVar12 = (float)((ulonglong)*(undefined8 *)(lVar7 + 0x264) >> 0x20) -
                 (float)((ulonglong)uStack_58 >> 0x20);
        if (1600.0 <= fVar12 * fVar12 + fVar11 * fVar11 + fVar10 * fVar10) {
          *(undefined1 *)(param_1 + 0x7c) = 0;
          goto code_r0x00018042897f;
        }
      }
      pcVar6 = DAT_182ec14e0;
      if ((DAT_182ec14e0 == (code *)0x0) &&
         (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_unscaledTime()"),
         pcVar6 == (code *)0x0)) {
        uVar8 = FUN_1802ced60("UnityEngine.Time::get_unscaledTime()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar8,0);
      }
      DAT_182ec14e0 = pcVar6;
      fVar10 = (float)(*DAT_182ec14e0)();
      if (0.5 < fVar10 - *(float *)(param_1 + 0x80)) {
        uVar9 = FUN_181449130(0);
        *(undefined4 *)(param_1 + 0x80) = uVar9;
        lVar7 = FUN_1804363b0();
        if (lVar7 == 0) goto code_r0x0001804293f9;
        bVar5 = ExposureUnnoticed2_Scripts_InGame_ObjectCulling_ObjectCullerManager__IsCulling__060016d4
                          (lVar7,*(undefined8 *)(param_1 + 0x28),0);
        *(byte *)(param_1 + 0x7c) = bVar5 ^ 1;
      }
    }
  }
code_r0x00018042897f:
  lVar7 = *(longlong *)(param_1 + 0x30);
  if ((lVar7 == 0) || (*(longlong *)(lVar7 + 0x40) == 0)) goto code_r0x0001804293f9;
  if (*(int *)(*(longlong *)(lVar7 + 0x40) + 0x58) == 9) {
    *(bool *)(param_1 + 0x7c) = *(char *)(*(longlong *)(lVar7 + 0x40) + 0x84) == '\0';
  }
  if (DAT_182eb5493 == '\0') {
    FUN_1802f2810(&DAT_182d592c0);
    LOCK();
    UNLOCK();
    DAT_182eb5493 = '\x01';
  }
  if (**(longlong **)(DAT_182d592c0 + 0xb8) == 0) goto code_r0x0001804293f9;
  if (*(char *)(**(longlong **)(DAT_182d592c0 + 0xb8) + 0x10) == '\0') {
code_r0x000180428a31:
    if ((*(longlong *)(param_1 + 0x30) == 0) ||
       (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xc0), lVar7 == 0))
    goto code_r0x0001804293f9;
    lVar7 = *(longlong *)(lVar7 + 0x20);
    uVar1 = *(undefined1 *)(param_1 + 0x7c);
    if (lVar7 == 0) goto code_r0x0001804293f9;
    pcVar6 = DAT_182ec1138;
    if ((DAT_182ec1138 == (code *)0x0) &&
       (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
       pcVar6 == (code *)0x0)) {
      uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar8,0);
    }
    DAT_182ec1138 = pcVar6;
    (*DAT_182ec1138)(lVar7,uVar1);
  }
  else {
    if (DAT_182eb5493 == '\0') {
      FUN_1802f2810(&DAT_182d592c0);
      LOCK();
      UNLOCK();
      DAT_182eb5493 = '\x01';
    }
    if (**(longlong **)(DAT_182d592c0 + 0xb8) == 0) goto code_r0x0001804293f9;
    if (*(longlong *)(**(longlong **)(DAT_182d592c0 + 0xb8) + 0x18) != param_1)
    goto code_r0x000180428a31;
  }
  if ((*(longlong *)(param_1 + 0x30) == 0) ||
     (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x68), lVar7 == 0))
  goto code_r0x0001804293f9;
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
  uVar1 = *(undefined1 *)(param_1 + 0x7c);
  if (lVar7 == 0) goto code_r0x0001804293f9;
  pcVar6 = DAT_182ec1138;
  if ((DAT_182ec1138 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
     pcVar6 == (code *)0x0)) {
    uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar8,0);
  }
  DAT_182ec1138 = pcVar6;
  (*DAT_182ec1138)(lVar7,uVar1);
  if ((*(char *)(param_1 + 0x7c) == '\0') &&
     (iVar2 = *(int *)(param_1 + 0x84),
     iVar2 != (iVar2 / 3 + (iVar2 >> 0x1f) +
              (int)(((longlong)iVar2 / 3 + ((longlong)iVar2 >> 0x3f) & 0xffffffffU) >> 0x1f)) * 3))
  {
    return;
  }
  lVar7 = *(longlong *)(param_1 + 0x48);
  if (*(longlong *)(param_1 + 0x30) == 0) goto code_r0x0001804293f9;
  uVar8 = *(undefined8 *)(*(longlong *)(param_1 + 0x30) + 0x18);
  if ((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
     (lVar3 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar3 == 0))
  goto code_r0x0001804293f9;
  uVar4 = *(undefined8 *)(lVar3 + 0x28);
  if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar9 = ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DistSqrt__06001726(uVar8,uVar4,0);
  if (lVar7 == 0) goto code_r0x0001804293f9;
  *(undefined4 *)(lVar7 + 0xd8) = uVar9;
  if ((*(longlong *)(param_1 + 0x30) == 0) ||
     (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x68), lVar7 == 0))
  goto code_r0x0001804293f9;
  ExposureUnnoticed2_Object3D_NPC_Script_PlayerSearcher__OnUpdate__060010d2(lVar7,0);
  if ((*(longlong *)(param_1 + 0x30) == 0) ||
     (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar7 == 0))
  goto code_r0x0001804293f9;
  ExposureUnnoticed2_Object3D_NPC_Script_NpcStrangenessManager__OnUpdate__060010be(lVar7,0);
  if ((*(longlong *)(param_1 + 0x30) == 0) ||
     (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x58), lVar7 == 0))
  goto code_r0x0001804293f9;
  ExposureUnnoticed2_Object3D_NPC_Script_NpcMiscController__OnUpdate__060010ae(lVar7,0);
  if (*(longlong *)(param_1 + 0x58) == 0) goto code_r0x0001804293f9;
  ExposureUnnoticed2_Object3D_NPC_Script_NpcFadeOutState__UpdateFadeIn__060010ef
            (*(longlong *)(param_1 + 0x58),0);
  if ((*(longlong *)(param_1 + 0x30) == 0) ||
     (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x88), lVar7 == 0))
  goto code_r0x0001804293f9;
  ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimatorFpsController__OnUpdate__06000fe4(lVar7,0);
  if ((*(longlong *)(param_1 + 0x30) == 0) ||
     (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xd8), lVar7 == 0))
  goto code_r0x0001804293f9;
  ExposureUnnoticed2_Object3D_NPC_Script_NpcSoundController__OnUpdate__060010b4(lVar7,0);
  if ((*(longlong *)(param_1 + 0x30) == 0) ||
     (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x70), lVar7 == 0))
  goto code_r0x0001804293f9;
  pcVar6 = DAT_182ec1088;
  if ((DAT_182ec1088 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
     pcVar6 == (code *)0x0)) {
    uVar8 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar8,0);
  }
  DAT_182ec1088 = pcVar6;
  uVar8 = (*DAT_182ec1088)(lVar7);
  uVar9 = ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DistSqrt__06001726
                    (uVar8,*(undefined8 *)(param_1 + 0x18),0);
  *(undefined4 *)(param_1 + 0x24) = uVar9;
  if ((*(longlong *)(param_1 + 0x30) == 0) ||
     (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x40), lVar7 == 0))
  goto code_r0x0001804293f9;
  lVar3 = *(longlong *)(param_1 + 0x30);
  if (*(int *)(lVar7 + 0x58) == 1) {
    if ((*(longlong *)(lVar3 + 0xc0) == 0) ||
       (lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0xc0) + 0x20), lVar7 == 0))
    goto code_r0x0001804293f9;
    FUN_181f3ea80(lVar7,0,0);
    goto code_r0x00018042937e;
  }
  if (*(int *)(*(longlong *)(lVar3 + 0x40) + 0x58) == 5) {
    if (*(longlong *)(lVar3 + 0xf0) == 0) goto code_r0x0001804293f9;
    ExposureUnnoticed2_Object3D_NPC_Script_State_NpcSleepFixState__OnUpdate__06001132
              (*(longlong *)(lVar3 + 0xf0),0,0);
    goto code_r0x00018042937e;
  }
  iVar2 = *(int *)(*(longlong *)(lVar3 + 0x40) + 0x58);
  if (((iVar2 == 2) || (iVar2 - 6U < 2)) || (iVar2 == 9)) {
    if (*(longlong *)(param_1 + 0x48) == 0) goto code_r0x0001804293f9;
    iVar2 = *(int *)(*(longlong *)(param_1 + 0x48) + 0x10);
    if (iVar2 != 0) {
      if (iVar2 == 1) goto code_r0x00018042918d;
      if (iVar2 == 2) goto code_r0x000180429167;
      goto code_r0x000180429388;
    }
    if (((*(longlong *)(param_1 + 0x30) == 0) ||
        (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xa0), lVar7 == 0)) ||
       (lVar7 = *(longlong *)(lVar7 + 0x20), lVar7 == 0)) goto code_r0x0001804293f9;
    *(undefined4 *)(lVar7 + 0x1c) = 0;
    if ((*(longlong *)(param_1 + 0x30) == 0) ||
       (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x40), lVar7 == 0))
    goto code_r0x0001804293f9;
    if (*(int *)(lVar7 + 0x58) == 2) {
      lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xa0);
      if ((lVar7 == 0) || (lVar7 = *(longlong *)(lVar7 + 0x20), lVar7 == 0))
      goto code_r0x0001804293f9;
      *(undefined4 *)(lVar7 + 0x1c) = 0;
      lVar7 = *(longlong *)(param_1 + 0x30);
      if (lVar7 == 0) goto code_r0x0001804293f9;
      lVar3 = *(longlong *)(lVar7 + 0x10);
      uVar8 = *(undefined8 *)(lVar7 + 0x10);
      if (lVar3 == 0) goto code_r0x0001804293f9;
      uStack_58 = 0;
      uStack_50 = 0;
      pcVar6 = DAT_182ec16b8;
      if ((DAT_182ec16b8 == (code *)0x0) &&
         (pcVar6 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                        ), pcVar6 == (code *)0x0)) {
        uVar8 = FUN_1802ced60(
                             "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar8,0);
      }
      DAT_182ec16b8 = pcVar6;
      (*DAT_182ec16b8)(lVar3,&uStack_58);
      if ((*(longlong *)(param_1 + 0x30) == 0) ||
         (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x40), lVar7 == 0))
      goto code_r0x0001804293f9;
      uStack_48 = *(undefined8 *)(lVar7 + 0xa4);
      uStack_40 = *(undefined8 *)(lVar7 + 0xac);
      uStack_38 = (undefined4)uStack_58;
      uStack_34 = uStack_58._4_4_;
      uStack_30 = (undefined4)uStack_50;
      uStack_2c = uStack_50._4_4_;
      uStack_58 = 0;
      uStack_50 = 0;
      fVar10 = (float)FUN_181f47e20(0);
      pcVar6 = DAT_182ec0e80;
      if ((DAT_182ec0e80 == (code *)0x0) &&
         (pcVar6 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Quaternion::Lerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                                        ), pcVar6 == (code *)0x0)) {
        uVar8 = FUN_1802ced60(
                             "UnityEngine.Quaternion::Lerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar8,0);
      }
      DAT_182ec0e80 = pcVar6;
      (*DAT_182ec0e80)(&uStack_38,&uStack_48,fVar10 * 3.0,&uStack_58);
      uStack_28 = (undefined4)uStack_58;
      uStack_24 = uStack_58._4_4_;
      uStack_20 = (undefined4)uStack_50;
      uStack_1c = uStack_50._4_4_;
      pcVar6 = DAT_182ec16c0;
      if ((DAT_182ec16c0 == (code *)0x0) &&
         (pcVar6 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                        ), pcVar6 == (code *)0x0)) {
        uVar8 = FUN_1802ced60(
                             "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar8,0);
      }
      DAT_182ec16c0 = pcVar6;
      (*DAT_182ec16c0)(uVar8,&uStack_28);
    }
    goto code_r0x00018042937e;
  }
  if (*(int *)(*(longlong *)(*(longlong *)(param_1 + 0x30) + 0x40) + 0x58) == 10) {
    lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar7 == 0) goto code_r0x0001804293f9;
    if (*(int *)(lVar7 + 0x10) != 7) {
      lVar7 = *(longlong *)(param_1 + 0x60);
      if (lVar7 == 0) goto code_r0x0001804293f9;
      if (cRam0000000182eb7757 == '\0') {
        FUN_1802f2810(&DAT_182d53aa8);
        LOCK();
        UNLOCK();
        cRam0000000182eb7757 = '\x01';
      }
      if (DAT_182eb5492 == '\0') {
        FUN_1802f2810(&DAT_182d592a0);
        LOCK();
        UNLOCK();
        DAT_182eb5492 = '\x01';
      }
      lVar3 = **(longlong **)(DAT_182d592a0 + 0xb8);
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
      if (lVar3 != 0) {
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (*(longlong *)(lVar3 + 0x10) != 0) {
          iVar2 = *(int *)(lVar7 + 0x18);
          if (iVar2 == 0) {
            ExposureUnnoticed2_Object3D_NPC_Script_NpcConbiniState__UpdateShinadashi__0600103c
                      (lVar7,0);
          }
          else if (iVar2 == 1) {
            ExposureUnnoticed2_Object3D_NPC_Script_NpcConbiniState__UpdateRegiMove__0600103d
                      (lVar7,0);
          }
          else if (iVar2 == 2) {
            ExposureUnnoticed2_Object3D_NPC_Script_NpcConbiniState__UpdateRegiWait__0600103e
                      (lVar7,0);
          }
          else if (iVar2 == 3) {
            ExposureUnnoticed2_Object3D_NPC_Script_NpcConbiniState__UpdateRegiScan__0600103f
                      (lVar7,0);
          }
        }
      }
      if (*(longlong *)(param_1 + 0x48) == 0) goto code_r0x0001804293f9;
      switch(*(undefined4 *)(*(longlong *)(param_1 + 0x48) + 0x10)) {
      case 0:
        if ((*(longlong *)(param_1 + 0x30) == 0) ||
           (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x20), lVar7 == 0))
        goto code_r0x0001804293f9;
        ExposureUnnoticed2_Object3D_NPC_Script_NpcLocomotion__OnUpdate__06001079(lVar7,0);
        break;
      case 1:
        goto code_r0x00018042918d;
      case 2:
        goto code_r0x000180429167;
      default:
        goto code_r0x000180429388;
      case 5:
        if ((*(longlong *)(param_1 + 0x30) == 0) ||
           (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xd0), lVar7 == 0))
        goto code_r0x0001804293f9;
        ExposureUnnoticed2_Object3D_NPC_Script_NpcInteractState__OnUpdate__060010f5(lVar7,0);
        if (*(longlong *)(param_1 + 0x48) == 0) goto code_r0x0001804293f9;
        *(undefined1 *)(*(longlong *)(param_1 + 0x48) + 0xe8) = 0;
      }
      goto code_r0x00018042937e;
    }
    if (*(longlong *)(param_1 + 0x48) == 0) goto code_r0x0001804293f9;
    switch(*(undefined4 *)(*(longlong *)(param_1 + 0x48) + 0x10)) {
    case 0:
      if (*(longlong *)(param_1 + 0x68) == 0) goto code_r0x0001804293f9;
      ExposureUnnoticed2_Object3D_NPC_Script_State_NpcFashionClerkSubState__OnUpdate__06001119
                (*(longlong *)(param_1 + 0x68),0);
      break;
    case 1:
code_r0x00018042918d:
      if (*(longlong *)(param_1 + 0x50) == 0) goto code_r0x0001804293f9;
      ExposureUnnoticed2_Object3D_NPC_Script_NpcFoundStrangerState__OnUpdate__06001074
                (*(longlong *)(param_1 + 0x50),0);
      goto code_r0x000180429388;
    case 2:
code_r0x000180429167:
      if ((*(longlong *)(param_1 + 0x30) == 0) ||
         (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x78), lVar7 == 0))
      goto code_r0x0001804293f9;
      ExposureUnnoticed2_Object3D_NPC_Script_NpcTurnAroundState__OnUpdate__060010fd(lVar7,0);
      break;
    default:
      goto code_r0x000180429388;
    case 5:
      break;
    }
    goto code_r0x00018042937e;
  }
  if (*(int *)(*(longlong *)(*(longlong *)(param_1 + 0x30) + 0x40) + 0x58) != 0)
  goto code_r0x000180429388;
  if (*(longlong *)(param_1 + 0x48) == 0) goto code_r0x0001804293f9;
  switch(*(undefined4 *)(*(longlong *)(param_1 + 0x48) + 0x10)) {
  case 0:
    lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x20);
    if (lVar7 == 0) goto code_r0x0001804293f9;
    ExposureUnnoticed2_Object3D_NPC_Script_NpcLocomotion__OnUpdate__06001079(lVar7,0);
    if ((*(longlong *)(param_1 + 0x30) == 0) ||
       (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x110), lVar7 == 0))
    goto code_r0x0001804293f9;
    ExposureUnnoticed2_Object3D_NPC_Script_NpcForeignObjectLooker__OnUpdate__0600106c(lVar7,0);
    goto code_r0x00018042937e;
  case 1:
    goto code_r0x00018042918d;
  case 2:
    goto code_r0x000180429167;
  case 3:
    if (*(longlong *)(param_1 + 0x58) == 0) goto code_r0x0001804293f9;
    ExposureUnnoticed2_Object3D_NPC_Script_NpcFadeOutState__OnUpdate__060010ee
              (*(longlong *)(param_1 + 0x58),0);
    break;
  case 4:
    if ((*(longlong *)(param_1 + 0x30) == 0) ||
       (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xb8), lVar7 == 0))
    goto code_r0x0001804293f9;
    fVar10 = *(float *)(lVar7 + 0x18);
    pcVar6 = DAT_182ec14d0;
    if ((DAT_182ec14d0 == (code *)0x0) &&
       (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"), pcVar6 == (code *)0x0))
    {
      uVar8 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar8,0);
    }
    DAT_182ec14d0 = pcVar6;
    fVar11 = (float)(*DAT_182ec14d0)();
    fVar10 = fVar10 - fVar11;
    *(float *)(lVar7 + 0x18) = fVar10;
    if (fVar10 <= 0.0) {
      if ((*(longlong *)(lVar7 + 0x10) == 0) ||
         (lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x38), lVar7 == 0))
      goto code_r0x0001804293f9;
      ExposureUnnoticed2_Object3D_NPC_Script_NpcController__ChangeState__0600105f(lVar7,2,0);
    }
    break;
  case 5:
    if ((*(longlong *)(param_1 + 0x30) == 0) ||
       (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xd0), lVar7 == 0))
    goto code_r0x0001804293f9;
    ExposureUnnoticed2_Object3D_NPC_Script_NpcInteractState__OnUpdate__060010f5(lVar7,0);
    if ((*(longlong *)(param_1 + 0x30) == 0) ||
       (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x110), lVar7 == 0))
    goto code_r0x0001804293f9;
    ExposureUnnoticed2_Object3D_NPC_Script_NpcForeignObjectLooker__OnUpdate__0600106c(lVar7,0);
    if (*(longlong *)(param_1 + 0x48) == 0) goto code_r0x0001804293f9;
    *(undefined1 *)(*(longlong *)(param_1 + 0x48) + 0xe8) = 0;
code_r0x00018042937e:
    ExposureUnnoticed2_Object3D_NPC_Script_NpcController__ChangeFoundStrangerIfInCondition__0600105d
              (param_1,0);
    break;
  case 6:
    if ((*(longlong *)(param_1 + 0x30) == 0) ||
       (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xe0), lVar7 == 0))
    goto code_r0x0001804293f9;
    ExposureUnnoticed2_Object3D_NPC_Script_State_NpcWaitTokenState__OnUpdate__06001141(lVar7,0);
    break;
  case 7:
    if ((*(longlong *)(param_1 + 0x30) == 0) ||
       (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x128), lVar7 == 0))
    goto code_r0x0001804293f9;
    ExposureUnnoticed2_Object3D_NPC_Script_State_NpcTraceSexPlayerState__OnUpdate__06001137(lVar7,0)
    ;
  }
code_r0x000180429388:
  if ((*(longlong *)(param_1 + 0x30) != 0) &&
     (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xa0), lVar7 != 0)) {
    ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimationManager__OnUpdate__06000fb7(lVar7,0);
    if ((*(longlong *)(param_1 + 0x30) != 0) &&
       (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xb0), lVar7 != 0)) {
      *(undefined1 *)(lVar7 + 0x20) = 0;
      if ((*(longlong *)(param_1 + 0x30) != 0) &&
         (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x40), lVar7 != 0)) {
        *(undefined1 *)(lVar7 + 0xe9) = 0;
        return;
      }
    }
  }
code_r0x0001804293f9:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

