// Ghidra pseudocode; not original source or compilable C.
// ev_363fc9814d49b297a0c97e26b7179bf1bbd6d812e6d78de7e7458abf3747e72f

void ExposureUnnoticed2_Object3D_NPC_Script_NpcLocomotion__SetActiveNavAgent__0600107d
               (longlong param_1,char param_2)

{
  longlong lVar1;
  code *pcVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 local_28;
  undefined4 local_20;
  undefined8 local_18;
  undefined4 local_10;
  
  if (DAT_182eb7769 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182eb7769 = '\x01';
  }
  if (*(longlong *)(param_1 + 0x10) == 0) goto LAB_18042eef7;
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x28);
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
      if ((*(longlong *)(param_1 + 0x10) == 0) ||
         (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x28), lVar3 == 0))
      goto LAB_18042eef7;
      pcVar2 = DAT_182ec1088;
      if ((DAT_182ec1088 == (code *)0x0) &&
         (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
         pcVar2 == (code *)0x0)) {
        uVar4 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar4,0);
      }
      DAT_182ec1088 = pcVar2;
      lVar3 = (*DAT_182ec1088)(lVar3);
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
          lVar3 = *(longlong *)(param_1 + 0x10);
          if (lVar3 == 0) goto LAB_18042eef7;
          if (param_2 == '\0') {
            if (*(longlong *)(lVar3 + 0x28) == 0) {
LAB_18042eef7:
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            FUN_181ed9520(*(longlong *)(lVar3 + 0x28),0,0);
            if ((*(longlong *)(param_1 + 0x10) == 0) ||
               (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x28), lVar3 == 0))
            goto LAB_18042eef7;
            FUN_181ed9520(lVar3,0,0);
            if ((*(longlong *)(param_1 + 0x10) == 0) ||
               (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x28), lVar3 == 0))
            goto LAB_18042eef7;
            FUN_181ed95e0(lVar3,0,0);
            if ((*(longlong *)(param_1 + 0x10) == 0) ||
               (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x28), lVar3 == 0))
            goto LAB_18042eef7;
            uVar4 = 1;
          }
          else {
            lVar1 = *(longlong *)(lVar3 + 0x28);
            if (((lVar3 == 0) || (*(longlong *)(lVar3 + 0x38) == 0)) ||
               (lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x38) + 0x10), lVar3 == 0))
            goto LAB_18042eef7;
            local_28 = 0;
            local_20 = 0;
            pcVar2 = DAT_182ec1698;
            if ((DAT_182ec1698 == (code *)0x0) &&
               (pcVar2 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                              ), pcVar2 == (code *)0x0)) {
              uVar4 = FUN_1802ced60(
                                   "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar4,0);
            }
            DAT_182ec1698 = pcVar2;
            (*DAT_182ec1698)(lVar3,&local_28);
            if (lVar1 == 0) {
LAB_18042ef42:
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            local_10 = local_20;
            local_18 = local_28;
            pcVar2 = DAT_182ebeec8;
            if ((DAT_182ebeec8 == (code *)0x0) &&
               (pcVar2 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.AI.NavMeshAgent::Warp_Injected(UnityEngine.Vector3&)"
                                              ), pcVar2 == (code *)0x0)) {
              uVar4 = FUN_1802ced60(
                                   "UnityEngine.AI.NavMeshAgent::Warp_Injected(UnityEngine.Vector3&)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar4,0);
            }
            DAT_182ebeec8 = pcVar2;
            (*DAT_182ebeec8)(lVar1,&local_18);
            if ((*(longlong *)(param_1 + 0x10) == 0) ||
               (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x28), lVar3 == 0))
            goto LAB_18042ef42;
            FUN_181ed9520(lVar3,1,0);
            if ((*(longlong *)(param_1 + 0x10) == 0) ||
               (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x28), lVar3 == 0))
            goto LAB_18042ef42;
            FUN_181ed9580(lVar3,1,0);
            if ((*(longlong *)(param_1 + 0x10) == 0) ||
               (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x28), lVar3 == 0))
            goto LAB_18042ef42;
            FUN_181ed95e0(lVar3,1,0);
            if ((*(longlong *)(param_1 + 0x10) == 0) ||
               (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x28), lVar3 == 0))
            goto LAB_18042ef42;
            uVar4 = 0;
          }
          FUN_181ed9410(lVar3,uVar4,0);
        }
      }
    }
  }
  return;
}

