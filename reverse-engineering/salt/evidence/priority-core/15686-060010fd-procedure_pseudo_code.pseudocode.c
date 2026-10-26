// Ghidra pseudocode; not original source or compilable C.
// ev_4b899e946d7333c4bc77816bc122167aa72e7183a631554763a5cb8b65c22fe6

void ExposureUnnoticed2_Object3D_NPC_Script_NpcTurnAroundState__OnUpdate__060010fd(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  char cVar5;
  undefined4 uVar6;
  float fVar7;
  undefined4 uVar8;
  float fVar9;
  float fVar10;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  float fStack_90;
  ulonglong uStack_88;
  float fStack_80;
  undefined8 uStack_78;
  ulonglong uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  
  if (cRam0000000182eb77b1 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5acd0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5acc8);
    LOCK();
    UNLOCK();
    cRam0000000182eb77b1 = '\x01';
  }
  lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar2 == 0) goto code_r0x00018043f394;
  cVar5 = *(char *)(lVar2 + 0x1dd);
  if (cVar5 == '\0') {
    if ((*(longlong *)(param_1 + 0x10) == 0) ||
       (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x70), lVar2 == 0))
    goto code_r0x00018043f394;
    pcVar3 = DAT_182ec1080;
    if ((DAT_182ec1080 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
       pcVar3 == (code *)0x0)) {
      uVar4 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    DAT_182ec1080 = pcVar3;
    lVar2 = (*DAT_182ec1080)(lVar2);
    if (lVar2 == 0) goto code_r0x00018043f394;
    uStack_a8 = 0;
    uStack_a0 = uStack_a0 & 0xffffffff00000000;
    pcVar3 = DAT_182ec1698;
    if ((DAT_182ec1698 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar3 == (code *)0x0)) {
      uVar4 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    DAT_182ec1698 = pcVar3;
    (*DAT_182ec1698)(lVar2,&uStack_a8);
    uVar6 = (undefined4)uStack_a8;
    uVar8 = (undefined4)((ulonglong)uStack_a8 >> 0x20);
    fVar10 = (float)uStack_a0;
  }
  else {
    uVar6 = (undefined4)*(undefined8 *)(param_1 + 0x18);
    uVar8 = (undefined4)((ulonglong)*(undefined8 *)(param_1 + 0x18) >> 0x20);
    fVar10 = *(float *)(param_1 + 0x20);
  }
  uStack_88 = CONCAT44(uVar8,uVar6);
  if ((*(longlong *)(param_1 + 0x10) != 0) &&
     (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40), lVar2 != 0)) {
    if (*(char *)(lVar2 + 0xb8) != '\0') {
      cVar5 = '\x01';
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40);
      uStack_88 = *(ulonglong *)(lVar2 + 0xbc);
      fVar10 = *(float *)(lVar2 + 0xc4);
    }
    if ((*(longlong *)(param_1 + 0x10) != 0) &&
       (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10), lVar2 != 0)) {
      uStack_98 = 0;
      fStack_90 = 0.0;
      pcVar3 = DAT_182ec1698;
      if ((DAT_182ec1698 == (code *)0x0) &&
         (pcVar3 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                        ), pcVar3 == (code *)0x0)) {
        uVar4 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar4,0);
      }
      DAT_182ec1698 = pcVar3;
      (*DAT_182ec1698)(lVar2,&uStack_98);
      fVar9 = (float)uStack_88 - (float)uStack_98;
      fVar10 = fVar10 - fStack_90;
      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uStack_88 = (ulonglong)(uint)fVar9;
      fStack_80 = fVar10;
      fVar7 = (float)FUN_1803d4d00(&uStack_88);
      if (1e-05 < fVar7) {
        fVar10 = fVar10 / fVar7;
        uStack_98 = CONCAT44(0.0 / fVar7,fVar9 / fVar7);
      }
      else {
        if (DAT_182eb5480 == '\0') {
          FUN_1802f2810(&DAT_182d522a8);
          LOCK();
          UNLOCK();
          DAT_182eb5480 = '\x01';
        }
        uStack_98 = **(undefined8 **)(DAT_182d522a8 + 0xb8);
        fVar10 = *(float *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
      }
      if ((*(longlong *)(param_1 + 0x10) != 0) &&
         (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10), lVar2 != 0)) {
        uStack_a8 = 0;
        uStack_a0 = 0;
        pcVar3 = DAT_182ec16b8;
        if ((DAT_182ec16b8 == (code *)0x0) &&
           (pcVar3 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                          ), pcVar3 == (code *)0x0)) {
          uVar4 = FUN_1802ced60(
                               "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar4,0);
        }
        DAT_182ec16b8 = pcVar3;
        (*DAT_182ec16b8)(lVar2,&uStack_a8);
        uVar6 = uStack_98._4_4_;
        if (DAT_182eb547c == '\0') {
          FUN_1802f2810(&DAT_182d522a8);
          LOCK();
          UNLOCK();
          DAT_182eb547c = '\x01';
        }
        uStack_88 = *(ulonglong *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
        fStack_80 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20);
        uStack_98 = CONCAT44(uVar6,(float)uStack_98);
        uStack_78 = 0;
        uStack_70 = 0;
        pcVar3 = DAT_182ec0ea8;
        fStack_90 = fVar10;
        if ((DAT_182ec0ea8 == (code *)0x0) &&
           (pcVar3 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                          ), pcVar3 == (code *)0x0)) {
          uVar4 = FUN_1802ced60(
                               "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar4,0);
        }
        DAT_182ec0ea8 = pcVar3;
        (*DAT_182ec0ea8)(&uStack_98,&uStack_88,&uStack_78);
        pcVar3 = pcRam0000000182ec14f8;
        if ((pcRam0000000182ec14f8 == (code *)0x0) &&
           (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_fixedDeltaTime()"),
           pcVar3 == (code *)0x0)) {
          uVar4 = FUN_1802ced60("UnityEngine.Time::get_fixedDeltaTime()");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar4,0);
        }
        pcRam0000000182ec14f8 = pcVar3;
        uStack_58 = (undefined4)uStack_a8;
        uStack_54 = uStack_a8._4_4_;
        uStack_50 = (float)uStack_a0;
        uStack_4c = uStack_a0._4_4_;
        uStack_68 = uStack_78;
        uStack_60 = uStack_70;
        uStack_a8 = 0;
        uStack_a0 = 0;
        fVar10 = (float)(*pcRam0000000182ec14f8)();
        pcVar3 = DAT_182ec0e80;
        if ((DAT_182ec0e80 == (code *)0x0) &&
           (pcVar3 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Quaternion::Lerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                                          ), pcVar3 == (code *)0x0)) {
          uVar4 = FUN_1802ced60(
                               "UnityEngine.Quaternion::Lerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar4,0);
        }
        DAT_182ec0e80 = pcVar3;
        (*DAT_182ec0e80)(&uStack_58,&uStack_68,fVar10 * 3.0,&uStack_a8);
        uStack_78 = uStack_a8;
        uStack_70 = uStack_a0;
        pcVar3 = DAT_182ec16c0;
        if ((DAT_182ec16c0 == (code *)0x0) &&
           (pcVar3 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                          ), pcVar3 == (code *)0x0)) {
          uVar4 = FUN_1802ced60(
                               "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar4,0);
        }
        DAT_182ec16c0 = pcVar3;
        (*DAT_182ec16c0)(lVar2,&uStack_78);
        lVar2 = *(longlong *)(param_1 + 0x10);
        if (lVar2 != 0) {
          if (cVar5 == '\0') {
            if (((*(longlong *)(lVar2 + 0x70) == 0) ||
                (lVar1 = *(longlong *)(*(longlong *)(lVar2 + 0x70) + 0x30), lVar1 == 0)) ||
               (*(longlong *)(lVar2 + 0x48) == 0)) goto code_r0x00018043f394;
            ExposureUnnoticed2_Object3D_Player_Scripts_LookAtController__EnableLookAt__06000c0f
                      (*(longlong *)(lVar2 + 0x48),3,*(undefined8 *)(lVar1 + 0xc0),0,0);
          }
          else {
            if (*(longlong *)(lVar2 + 0x48) == 0) goto code_r0x00018043f394;
            ExposureUnnoticed2_Object3D_Player_Scripts_LookAtController__DisableLookAt__06000c10
                      (*(longlong *)(lVar2 + 0x48),3,0);
          }
          pcVar3 = DAT_182ec14c0;
          if ((DAT_182ec14c0 == (code *)0x0) &&
             (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_time()"), pcVar3 == (code *)0x0)
             ) {
            uVar4 = FUN_1802ced60("UnityEngine.Time::get_time()");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar4,0);
          }
          DAT_182ec14c0 = pcVar3;
          fVar10 = (float)(*DAT_182ec14c0)();
          if ((*(longlong *)(param_1 + 0x10) != 0) &&
             (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40), lVar2 != 0)) {
            if (fVar10 - *(float *)(lVar2 + 0x28) < 2.8) {
              return;
            }
            lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x48);
            if (lVar2 != 0) {
              ExposureUnnoticed2_Object3D_Player_Scripts_LookAtController__DisableLookAt__06000c10
                        (lVar2,3,0);
              if ((*(longlong *)(param_1 + 0x10) != 0) &&
                 (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40), lVar2 != 0)) {
                lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40);
                if (*(int *)(lVar2 + 0x14) == 5) {
                  if (lVar1 == 0) goto code_r0x00018043f394;
                  *(undefined1 *)(lVar1 + 0x1c) = 1;
                  if ((*(longlong *)(param_1 + 0x10) == 0) ||
                     (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38), lVar2 == 0))
                  goto code_r0x00018043f394;
                  uVar4 = 5;
                }
                else {
                  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38);
                  if (*(int *)(lVar1 + 0x14) == 6) {
                    if (lVar2 == 0) goto code_r0x00018043f394;
                    uVar4 = 6;
                  }
                  else {
                    if (lVar2 == 0) goto code_r0x00018043f394;
                    uVar4 = 0;
                  }
                }
                ExposureUnnoticed2_Object3D_NPC_Script_NpcController__ChangeState__0600105f
                          (lVar2,uVar4,0);
                if ((*(longlong *)(param_1 + 0x10) != 0) &&
                   (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40), lVar2 != 0)) {
                  *(undefined4 *)(lVar2 + 0x24) = 0x41200000;
                  return;
                }
              }
            }
          }
        }
      }
    }
  }
code_r0x00018043f394:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

