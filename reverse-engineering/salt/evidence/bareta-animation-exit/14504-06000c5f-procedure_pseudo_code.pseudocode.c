// Ghidra pseudocode; not original source or compilable C.
// ev_9d48f2a32535b75d8323271ce932d733f5eb0981c22dc22e598ca71a6aa09f77

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationReceiver__OnEndSad__06000c5f
               (longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  char cVar3;
  code *pcVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uStack_48;
  undefined4 uStack_40;
  undefined8 uStack_38;
  undefined4 uStack_30;
  undefined8 uStack_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  
  if (cRam0000000182eb8383 == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb8383 = '\x01';
  }
  if (DAT_182eb5490 == '\0') {
    FUN_1802f2810(&DAT_182d59260);
    LOCK();
    UNLOCK();
    DAT_182eb5490 = '\x01';
  }
  lVar2 = **(longlong **)(DAT_182d59260 + 0xb8);
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
  if (lVar2 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar2 + 0x10) != 0) {
      if (DAT_182eb5490 == '\0') {
        FUN_1802f2810(&DAT_182d59260);
        LOCK();
        UNLOCK();
        DAT_182eb5490 = '\x01';
      }
      lVar2 = **(longlong **)(DAT_182d59260 + 0xb8);
      if ((*(longlong *)(param_1 + 0x40) == 0) ||
         (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x18), lVar5 == 0))
      goto code_r0x00018062c1a7;
      uStack_48 = 0;
      uStack_40 = 0;
      pcVar4 = DAT_182ec1698;
      if ((DAT_182ec1698 == (code *)0x0) &&
         (pcVar4 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                        ), pcVar4 == (code *)0x0)) {
        uVar6 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar6,0);
      }
      DAT_182ec1698 = pcVar4;
      (*DAT_182ec1698)(lVar5,&uStack_48);
      if (lVar2 == 0) goto code_r0x00018062c1a7;
      uStack_28 = *(undefined8 *)(lVar2 + 0x5c);
      uStack_20 = *(undefined8 *)(lVar2 + 100);
      uStack_18 = *(undefined8 *)(lVar2 + 0x6c);
      uStack_30 = uStack_40;
      uStack_38 = uStack_48;
      pcVar4 = pcRam0000000182ebfdb8;
      if ((pcRam0000000182ebfdb8 == (code *)0x0) &&
         (pcVar4 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                                        ), pcVar4 == (code *)0x0)) {
        uVar6 = FUN_1802ced60(
                             "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar6,0);
      }
      pcRam0000000182ebfdb8 = pcVar4;
      cVar3 = (*pcRam0000000182ebfdb8)(&uStack_28,&uStack_38);
      if (cVar3 != '\0') {
        if ((*(longlong *)(param_1 + 0x40) != 0) &&
           (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x48), lVar2 != 0)) {
          ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__TransAction__06000c7f
                    (lVar2,4,0);
          return;
        }
        goto code_r0x00018062c1a7;
      }
    }
  }
  if (((*(longlong *)(param_1 + 0x40) != 0) &&
      (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60), lVar2 != 0)) &&
     (lVar2 = *(longlong *)(lVar2 + 0x48), lVar2 != 0)) {
    if (*(int *)(lVar2 + 0x18) == 6) {
      return;
    }
    lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x50);
    if (lVar2 != 0) {
      ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController__ChangeState__06000d5e(lVar2,2,0);
      if ((*(longlong *)(param_1 + 0x40) != 0) &&
         (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x48), lVar2 != 0)) {
        if (cRam0000000182eb8392 == '\0') {
          FUN_1802f2810(0x182d6f340);
          LOCK();
          UNLOCK();
          cRam0000000182eb8392 = '\x01';
        }
        lVar2 = *(longlong *)(lVar2 + 0x30);
        if (*(int *)(lRam0000000182d6f340 + 0xe0) == 0) {
          FUN_18035c820(lRam0000000182d6f340);
        }
        if (lVar2 != 0) {
          uVar1 = *(undefined4 *)(*(longlong *)(lRam0000000182d6f340 + 0xb8) + 0x44);
          pcVar4 = DAT_182ebf368;
          if ((DAT_182ebf368 == (code *)0x0) &&
             (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Animator::SetTriggerID(System.Int32)"),
             pcVar4 == (code *)0x0)) {
            uVar6 = FUN_1802ced60("UnityEngine.Animator::SetTriggerID(System.Int32)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar6,0);
          }
          DAT_182ebf368 = pcVar4;
          (*DAT_182ebf368)(lVar2,uVar1);
          if ((*(longlong *)(param_1 + 0x40) != 0) &&
             (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x48), lVar2 != 0)) {
            *(undefined4 *)(lVar2 + 0x10) = 0x40000000;
            if ((*(longlong *)(param_1 + 0x40) != 0) &&
               (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x30), lVar2 != 0)) {
              pcVar4 = DAT_182ec3970;
              if ((DAT_182ec3970 == (code *)0x0) &&
                 (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Collider::set_enabled(System.Boolean)"
                                                ), pcVar4 == (code *)0x0)) {
                uVar6 = FUN_1802ced60("UnityEngine.Collider::set_enabled(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar6,0);
              }
              DAT_182ec3970 = pcVar4;
              (*DAT_182ec3970)(lVar2,0);
              if ((*(longlong *)(param_1 + 0x40) != 0) &&
                 (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0xd8), lVar2 != 0)) {
                pcVar4 = DAT_182ec1060;
                if ((DAT_182ec1060 == (code *)0x0) &&
                   (pcVar4 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Behaviour::set_enabled(System.Boolean)"
                                                  ), pcVar4 == (code *)0x0)) {
                  uVar6 = FUN_1802ced60("UnityEngine.Behaviour::set_enabled(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar6,0);
                }
                DAT_182ec1060 = pcVar4;
                (*DAT_182ec1060)(lVar2,1);
                if ((*(longlong *)(param_1 + 0x40) != 0) &&
                   (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0xd8), lVar2 != 0)) {
                  pcVar4 = DAT_182ebee90;
                  if ((DAT_182ebee90 == (code *)0x0) &&
                     (pcVar4 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.AI.NavMeshAgent::set_updatePosition(System.Boolean)"
                                                  ), pcVar4 == (code *)0x0)) {
                    uVar6 = FUN_1802ced60(
                                         "UnityEngine.AI.NavMeshAgent::set_updatePosition(System.Boolean)"
                                         );
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar6,0);
                  }
                  DAT_182ebee90 = pcVar4;
                  (*DAT_182ebee90)(lVar2,1);
                  if ((*(longlong *)(param_1 + 0x40) != 0) &&
                     (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0xd8), lVar2 != 0)) {
                    pcVar4 = DAT_182ebee98;
                    if ((DAT_182ebee98 == (code *)0x0) &&
                       (pcVar4 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.AI.NavMeshAgent::set_updateRotation(System.Boolean)"
                                                  ), pcVar4 == (code *)0x0)) {
                      uVar6 = FUN_1802ced60(
                                           "UnityEngine.AI.NavMeshAgent::set_updateRotation(System.Boolean)"
                                           );
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar6,0);
                    }
                    DAT_182ebee98 = pcVar4;
                    (*DAT_182ebee98)(lVar2,1);
                    if (*(longlong *)(param_1 + 0x40) != 0) {
                      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0xd8);
                      if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                          (lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x40),
                          lVar5 != 0)) &&
                         (lVar5 = ExposureUnnoticed2_Scripts_InGame_StageController__GetEscapeTarget__0600165b
                                            (lVar5,0), lVar5 != 0)) {
                        uStack_48 = 0;
                        uStack_40 = 0;
                        pcVar4 = DAT_182ec1698;
                        if ((DAT_182ec1698 == (code *)0x0) &&
                           (pcVar4 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar4 == (code *)0x0)) {
                          uVar6 = FUN_1802ced60(
                                               "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                               );
                    /* WARNING: Subroutine does not return */
                          FUN_1802cca90(uVar6,0);
                        }
                        DAT_182ec1698 = pcVar4;
                        (*DAT_182ec1698)(lVar5,&uStack_48);
                        if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
                          FUN_18031dad0();
                        }
                        uStack_30 = uStack_40;
                        uStack_38 = uStack_48;
                        pcVar4 = DAT_182ebeeb0;
                        if ((DAT_182ebeeb0 == (code *)0x0) &&
                           (pcVar4 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.AI.NavMeshAgent::SetDestination_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar4 == (code *)0x0)) {
                          uVar6 = FUN_1802ced60(
                                               "UnityEngine.AI.NavMeshAgent::SetDestination_Injected(UnityEngine.Vector3&)"
                                               );
                    /* WARNING: Subroutine does not return */
                          FUN_1802cca90(uVar6,0);
                        }
                        DAT_182ebeeb0 = pcVar4;
                        (*DAT_182ebeeb0)(lVar2,&uStack_38);
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
code_r0x00018062c1a7:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

