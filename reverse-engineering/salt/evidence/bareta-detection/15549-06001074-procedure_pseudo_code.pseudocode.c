// Ghidra pseudocode; not original source or compilable C.
// ev_ee1a927ce1baf0ef45b4cb2230c008e26ac4c0e7e83f2f966074ab150b970c70

void ExposureUnnoticed2_Object3D_NPC_Script_NpcFoundStrangerState__OnUpdate__06001074
               (longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  char cVar3;
  int iVar4;
  code *pcVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  int iVar9;
  float fVar10;
  float fVar11;
  undefined8 uStack_78;
  float fStack_70;
  ulonglong uStack_68;
  undefined8 uStack_60;
  ulonglong uStack_58;
  float fStack_50;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  undefined8 uStack_40;
  
  if (cRam0000000182eb7765 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7765 = '\x01';
  }
  fVar11 = *(float *)(param_1 + 0x10);
  pcVar5 = DAT_182ec14d0;
  if ((DAT_182ec14d0 == (code *)0x0) &&
     (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"), pcVar5 == (code *)0x0)) {
    uVar8 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar8,0);
  }
  DAT_182ec14d0 = pcVar5;
  fVar10 = (float)(*DAT_182ec14d0)();
  lVar6 = *(longlong *)(param_1 + 0x20);
  fVar10 = fVar10 + fVar11;
  *(float *)(param_1 + 0x10) = fVar10;
  if (lVar6 == 0) goto code_r0x00018042c75a;
  lVar1 = *(longlong *)(lVar6 + 0x40);
  if (fVar10 <= 3.0) {
    if (lVar1 != 0) {
      if (*(char *)(lVar1 + 0x1f) != '\0') {
        return;
      }
      lVar6 = *(longlong *)(lVar6 + 0x70);
      if (lVar6 != 0) {
        pcVar5 = DAT_182ec1080;
        if ((DAT_182ec1080 == (code *)0x0) &&
           (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
           pcVar5 == (code *)0x0)) {
          uVar8 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar8,0);
        }
        DAT_182ec1080 = pcVar5;
        lVar6 = (*DAT_182ec1080)(lVar6);
        if (lVar6 != 0) {
          uStack_78 = 0;
          fStack_70 = 0.0;
          pcVar5 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar5 == (code *)0x0)) {
            uVar8 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar8,0);
          }
          DAT_182ec1698 = pcVar5;
          (*DAT_182ec1698)(lVar6,&uStack_78);
          if ((*(longlong *)(param_1 + 0x18) != 0) &&
             (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x10), lVar6 != 0)) {
            uStack_68 = 0;
            uStack_60 = uStack_60 & 0xffffffff00000000;
            pcVar5 = DAT_182ec1698;
            if ((DAT_182ec1698 == (code *)0x0) &&
               (pcVar5 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                              ), pcVar5 == (code *)0x0)) {
              uVar8 = FUN_1802ced60(
                                   "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar8,0);
            }
            DAT_182ec1698 = pcVar5;
            (*DAT_182ec1698)(lVar6,&uStack_68);
            fVar11 = (float)uStack_78 - (float)uStack_68;
            fVar10 = fStack_70 - (float)uStack_60;
            if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
              FUN_18035c820();
            }
            if (DAT_182eb547c == '\0') {
              FUN_1802f2810(&DAT_182d522a8);
              LOCK();
              UNLOCK();
              DAT_182eb547c = '\x01';
            }
            uStack_58 = (ulonglong)(uint)fVar11;
            uStack_78 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
            fStack_70 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20);
            uStack_48 = 0;
            uStack_40 = 0;
            pcVar5 = DAT_182ec0ea8;
            fStack_50 = fVar10;
            if ((DAT_182ec0ea8 == (code *)0x0) &&
               (pcVar5 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                              ), pcVar5 == (code *)0x0)) {
              uVar8 = FUN_1802ced60(
                                   "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar8,0);
            }
            DAT_182ec0ea8 = pcVar5;
            (*DAT_182ec0ea8)(&uStack_58,&uStack_78,&uStack_48);
            if ((*(longlong *)(param_1 + 0x18) != 0) &&
               (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x10), lVar6 != 0)) {
              uStack_68 = 0;
              uStack_60 = 0;
              pcVar5 = DAT_182ec16b8;
              if ((DAT_182ec16b8 == (code *)0x0) &&
                 (pcVar5 = (code *)FUN_1802cf0c0(
                                                "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                ), pcVar5 == (code *)0x0)) {
                uVar8 = FUN_1802ced60(
                                     "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                     );
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar8,0);
              }
              DAT_182ec16b8 = pcVar5;
              (*DAT_182ec16b8)(lVar6,&uStack_68);
              pcVar5 = DAT_182ec14d0;
              if ((DAT_182ec14d0 == (code *)0x0) &&
                 (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"),
                 pcVar5 == (code *)0x0)) {
                uVar8 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar8,0);
              }
              DAT_182ec14d0 = pcVar5;
              uStack_58 = uStack_68;
              fStack_50 = (float)uStack_60;
              uStack_4c = uStack_60._4_4_;
              fVar11 = (float)(*DAT_182ec14d0)();
              puVar7 = (undefined8 *)FUN_1804363f0(&uStack_68,&uStack_58,&uStack_48,fVar11 * 200.0);
              uStack_48 = *puVar7;
              uStack_40 = puVar7[1];
              pcVar5 = DAT_182ec16c0;
              if ((DAT_182ec16c0 == (code *)0x0) &&
                 (pcVar5 = (code *)FUN_1802cf0c0(
                                                "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                                ), pcVar5 == (code *)0x0)) {
                uVar8 = FUN_1802ced60(
                                     "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                     );
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar8,0);
              }
              DAT_182ec16c0 = pcVar5;
              (*DAT_182ec16c0)(lVar6,&uStack_48);
              return;
            }
          }
        }
      }
    }
    goto code_r0x00018042c75a;
  }
  if (lVar1 == 0) goto code_r0x00018042c75a;
  if (*(int *)(lVar1 + 0x58) == 0) {
    if ((lVar6 == 0) || (lVar1 == 0)) goto code_r0x00018042c75a;
    if (((*(char *)(lVar1 + 0x1f) == '\0') && (*(int *)(lVar1 + 0x4c) == 1)) &&
       ((*(int *)(lVar1 + 0x14) != 5 || (*(int *)(lVar1 + 0x18) != 2)))) {
      if ((*(int *)(*(longlong *)(lVar6 + 0x40) + 0x14) == 5) &&
         (*(int *)(*(longlong *)(lVar6 + 0x40) + 0x18) == 0xc)) {
        lVar6 = *(longlong *)(lVar6 + 0x100);
        if (lVar6 == 0) goto code_r0x00018042c75a;
        if (*(int *)(lVar6 + 0x1c) == 0) {
          if (*(longlong *)(lVar6 + 0x20) == 0) goto code_r0x00018042c75a;
          if (*(int *)(*(longlong *)(lVar6 + 0x20) + 0x10) == 2) goto DAT_18042c711;
        }
      }
      lVar6 = FUN_180436330();
      if ((*(longlong *)(param_1 + 0x20) == 0) ||
         (uVar8 = *(undefined8 *)(*(longlong *)(param_1 + 0x20) + 0x38), lVar6 == 0))
      goto code_r0x00018042c75a;
      if (cRam0000000182eb7a12 == '\0') {
        FUN_1802f2810(&DAT_182d58398);
        LOCK();
        UNLOCK();
        cRam0000000182eb7a12 = '\x01';
      }
      lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
      if (lVar1 == 0) goto code_r0x00018042c75a;
      if (((*(char *)(lVar1 + 0x12) == '\0') &&
          (cVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525
                             (0x16,0), cVar3 != '\0')) && (*(longlong *)(lVar6 + 0x18) == 0)) {
        AkilliMum_Standard_Mirror_RenderTextureManager__set_LeftOrCenterRT1__0600091f(lVar6,uVar8);
        if ((((*(longlong *)(param_1 + 0x20) == 0) ||
             (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x40), lVar6 == 0)) ||
            (plVar2 = *(longlong **)(lVar6 + 0x40), plVar2 == (longlong *)0x0)) ||
           (lVar6 = (**(code **)(*plVar2 + 0x188))(plVar2,*(undefined8 *)(*plVar2 + 400)),
           lVar6 == 0)) goto code_r0x00018042c75a;
        lVar1 = *(longlong *)(lVar6 + 0x28);
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
        if (lVar1 != 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (*(longlong *)(lVar1 + 0x10) != 0) {
            lVar6 = *(longlong *)(lVar6 + 0x28);
            if (lVar6 == 0) goto code_r0x00018042c75a;
            iVar9 = *(int *)(lVar6 + 0x20) + 1;
            iVar4 = *(int *)(lVar6 + 0x24);
            if (iVar9 <= *(int *)(lVar6 + 0x24)) {
              iVar4 = iVar9;
            }
            *(int *)(lVar6 + 0x20) = iVar4;
          }
        }
        lVar6 = *(longlong *)(param_1 + 0x18);
        if (lVar6 == 0) goto code_r0x00018042c75a;
        uVar8 = 7;
        goto code_r0x00018042c6e3;
      }
    }
  }
DAT_18042c711:
  lVar6 = *(longlong *)(param_1 + 0x20);
  if ((lVar6 != 0) && (lVar1 = *(longlong *)(lVar6 + 0x40), lVar1 != 0)) {
    if (*(int *)(lVar1 + 0x14) == 5) {
      if ((lVar6 != 0) && (lVar1 != 0)) {
        *(undefined1 *)(lVar1 + 0x1c) = 1;
        lVar6 = *(longlong *)(param_1 + 0x18);
        if (lVar6 != 0) {
          uVar8 = 5;
          goto code_r0x00018042c6e3;
        }
      }
    }
    else {
      lVar6 = *(longlong *)(param_1 + 0x18);
      if (lVar6 != 0) {
        uVar8 = 0;
code_r0x00018042c6e3:
        ExposureUnnoticed2_Object3D_NPC_Script_NpcController__ChangeState__0600105f(lVar6,uVar8,0);
        return;
      }
    }
  }
code_r0x00018042c75a:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

